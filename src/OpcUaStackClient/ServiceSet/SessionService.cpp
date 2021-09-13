/*
   Copyright 2015-2021 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include <boost/make_shared.hpp>
#include <future>
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransaction.h"
#include "OpcUaStackCore/ServiceSet/ActivateSessionRequest.h"
#include "OpcUaStackCore/ServiceSet/ActivateSessionResponse.h"
#include "OpcUaStackCore/ServiceSet/CloseSessionRequest.h"
#include "OpcUaStackClient/ServiceSet/SessionService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	SessionService::SessionService(
		const std::string& serviceName,
		IOThread* ioThread,
		MessageBus::SPtr& messageBus
	)
	: ClientServiceBase()
	, sm_()
	, ctx_(nullptr)
	{
		// set parameter in client service base
		serviceName_ = serviceName;
		ClientServiceBase::ioThread_ = ioThread;
		strand_ = ioThread->createStrand();
		messageBus_ = messageBus;

		// create session service context
		ctx_ = new SessionServiceContext(ioThread, messageBus, strand_);

		// init threads and timer
		ctx_->slotTimerElement_ = boost::make_shared<SlotTimerElement>();
		ctx_->ioThread_ = ioThread;
		ctx_->sessionService_ = this;
		ctx_->strand_ = strand_;

		// register message bus receiver
		MessageBusMemberConfig messageBusMemberConfig;
		messageBusMemberConfig.strand(ctx_->strand_);
		messageBusMember_ = messageBus_->registerMember(serviceName_, messageBusMemberConfig);
		ctx_->messageBusMember_ = messageBusMember_;

		// create pending queue
		AsyncPendingQueueConfig pendingQueueConfig;
		pendingQueueConfig.slotTimer(ioThread->slotTimer());
		pendingQueueConfig.strand(strand_);
		ctx_->pendingQueue_ = boost::make_shared<AsyncPendingQueue>(pendingQueueConfig);

		// start pending queue loop
		pendingQueueTimeoutLoop();

		// init state machine
		sm_.setCtx(ctx_);
		sm_.setUpdateCallback( // prevent warn log messages
			[this](SessionServiceStateId state) {}
		);
		sm_.setStateId(SessionServiceStateId::Disconnected);
	}

	SessionService::~SessionService(void)
	{
		// stop pending queue loop
		ctx_->pendingQueue_->syncCancel();

		// delete pending queue
		ctx_->pendingQueue_.reset();

		// stop timer element
		if (ctx_->slotTimerElement_.get() != nullptr) {
			ctx_->ioThread_->slotTimer()->stop(ctx_->slotTimerElement_);
			ctx_->slotTimerElement_.reset();
		}

		delete ctx_;
		ctx_ = nullptr;

		// deactivate receiver
		deactivateReceiver();
		messageBus_->deregisterMember(messageBusMember_);
	}

	void
	SessionService::setConfiguration(
		SessionMode sessionMode,
		SessionServiceChangeHandler& sessionServiceChangeHandler,
		boost::shared_ptr<boost::asio::io_service::strand>& sessionServiceChangeHandlerStrand,
		SecureChannelClientConfig::SPtr& secureChannelClientConfig,
		SessionConfig::SPtr& sessionConfig
	)
	{
		ctx_->sessionMode_ = sessionMode;
		ctx_->sessionServiceChangeHandler_ = sessionServiceChangeHandler;
		ctx_->sessionServiceChangeHandlerStrand_ = sessionServiceChangeHandlerStrand;
		ctx_->secureChannelClientConfig_ = secureChannelClientConfig;
		ctx_->secureChannelClientConfigBackup_ = secureChannelClientConfig;
		ctx_->sessionConfig_ = sessionConfig;

		if (ctx_->sessionMode_ == SessionMode::SecureChannelAndSession) {
			// Either the session timer or the open secure channel timer is used. Never both.
			if (ctx_->sessionConfig_->reconnectTimeout() > 0) {
				ctx_->secureChannelClientConfig_->reconnectTimeout(0);
			}
		}

		sm_.setSessionServiceName(sessionConfig->sessionName());
		sm_.setUpdateCallback(
			[this](SessionServiceStateId state) {
				if (ctx_->sessionServiceChangeHandler_) {
					if (ctx_->sessionServiceChangeHandlerStrand_) {
						ctx_->sessionServiceChangeHandlerStrand_->dispatch(
							[this, state]() {
							    ctx_->sessionServiceChangeHandler_(*ctx_->sessionService_, state);
						    }
						);
					}
					else {
					    ctx_->sessionServiceChangeHandler_(*ctx_->sessionService_, state);
				    }
				}
			}
		);

		// activate receiver
		activateReceiver(
			[this](const OpcUaStackCore::MessageBusMember::WPtr& handleFrom, Message::SPtr& message) {
				receive(handleFrom, message);
			}
		);
	}

	void
	SessionService::updateEndpointUrl(const std::string& endpointUrl)
	{
		ctx_->secureChannelClientConfig_->endpointUrl(endpointUrl);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// handle pending queue timeout
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	SessionService::pendingQueueTimeoutLoop(void)
	{
		ctx_->pendingQueue_->asyncTimeout(
			[this](bool error, uint32_t key, Object::SPtr& object) {
			    // check error
			    if (error) {
			    	Log(Debug, "stop pending queue loop");
			    }

			    // handle pending queue timeout
			    pendingQueueTimeout(object);

			    // call pending queue loop
			    pendingQueueTimeoutLoop();
		    }
		);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// manage secure channel and session
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	void
	SessionService::reconnectTimeout(void)
	{
		asyncConnectInternal();
	}

	void
	SessionService::asyncConnect(void)
	{
		strand_->dispatch(
			[this](void) {
			    asyncConnectInternal();
		    }
		);
	}

	void
	SessionService::asyncConnectInternal(void)
	{
		sm_.event(
			[this](SessionServiceStateIf* sssif) {
				return sssif->asyncConnect();
			}
		);
	}

	OpcUaStatusCode
	SessionService::syncConnect(void)
	{
		if (sm_.stateId() != SessionServiceStateId::Disconnected) {
			return BadResourceUnavailable;
		}

		std::promise<OpcUaStatusCode> prom;
		auto future = prom.get_future();

		auto updateCallback = [&prom](SessionServiceStateId state) {
			if (state == SessionServiceStateId::Disconnected) {
				prom.set_value(BadResourceUnavailable);
			}

			else if (state == SessionServiceStateId::Established) {
				prom.set_value(Success);
			}
		};
		sm_.setUpdateCallback(updateCallback);

		strand_->dispatch(
			[this](void) {
			    asyncConnectInternal();
		    }
		);

		future.wait();
		auto statusCode = future.get();

		sm_.setUpdateCallback(nullptr);
		return statusCode;
	}

	void
	SessionService::asyncDisconnect(bool deleteSubscriptions)
	{
		strand_->dispatch(
			[this, deleteSubscriptions](void) {
			    asyncDisconnectInternal(deleteSubscriptions);
		    }
		);
	}

	void
	SessionService::asyncDisconnectInternal(bool deleteSubscriptions)
	{
		sm_.event(
			[this, deleteSubscriptions] (SessionServiceStateIf* sssif) {
				return sssif->asyncDisconnect(deleteSubscriptions);
			}
		);
	}

	OpcUaStatusCode
	SessionService::syncDisconnect(bool deleteSubscriptions)
	{
		if (sm_.stateId() == SessionServiceStateId::Disconnected) {
			return Success;
		}

		std::promise<OpcUaStatusCode> prom;
		auto future = prom.get_future();

		auto updateCallback = [&prom](SessionServiceStateId state) {
			if (state == SessionServiceStateId::Disconnected) {
				prom.set_value(Success);
			}
		};
		sm_.setUpdateCallback(updateCallback);


		strand_->dispatch(
			[this, deleteSubscriptions](void) {
			    asyncDisconnectInternal(deleteSubscriptions);
		    }
		);

		
		future.wait();
		return future.get();
	}

	void
	SessionService::asyncCancel(uint32_t requestHandle)
	{
		strand_->dispatch(
			[this, requestHandle](void) {
			    asyncCancelInternal(requestHandle);
		    }
		);
	}

	void
	SessionService::asyncCancelInternal(uint32_t requestHandle)
	{
		ctx_->sendCancelRequest(ctx_->secureChannel_, requestHandle);
	}

	EndpointDescriptionCache&
	SessionService::getEndpointDescriptionCache(void)
	{
		assert(ctx_ != nullptr);
		return ctx_->endpointDescriptionCache_;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SecureChannelClientIf
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	SessionService::handleConnect(SecureChannel* secureChannel)
	{
		ctx_->secureChannel_ = secureChannel;
		sm_.event(
			[this, secureChannel](SessionServiceStateIf* sssif) {
				return sssif->handleConnect(secureChannel);
			}
		);
	}

	void
	SessionService::handleDisconnect(SecureChannel* secureChannel)
	{
		sm_.event(
			[this, secureChannel](SessionServiceStateIf* sssif) {
				return sssif->handleDisconnect(secureChannel);
			}
		);
	}

	void
	SessionService::handleMessageResponse(SecureChannel* secureChannel)
	{
		// decode response header
		std::iostream ios(&secureChannel->secureChannelTransaction_->is_);
		ResponseHeader::SPtr responseHeader = boost::make_shared<ResponseHeader>();
		responseHeader->opcUaBinaryDecode(ios);

		switch (secureChannel->secureChannelTransaction_->responseTypeNodeId_.nodeId<OpcUaUInt32>())
		{
			case OpcUaId_CreateSessionResponse_Encoding_DefaultBinary:
			{
				sm_.event(
					[this, secureChannel, responseHeader](SessionServiceStateIf* sssif) {
						return sssif->recvCreateSessionResponse(secureChannel, responseHeader);
					}
				);

				return;
			}
			case OpcUaId_ActivateSessionResponse_Encoding_DefaultBinary:
			{
				sm_.event(
					[this, secureChannel, responseHeader](SessionServiceStateIf* sssif) {
						return sssif->recvActivateSessionResponse(secureChannel, responseHeader);
					}
				);

				return;
			}
			case OpcUaId_GetEndpointsResponse_Encoding_DefaultBinary:
			{
				sm_.event(
					[this, secureChannel, responseHeader](SessionServiceStateIf* sssif) {
						return sssif->recvGetEndpointsResponse(secureChannel, responseHeader);
					}
				);

				return;
			}
			case OpcUaId_CloseSessionResponse_Encoding_DefaultBinary:
			{
				sm_.event(
					[this, secureChannel, responseHeader](SessionServiceStateIf* sssif) {
						return sssif->recvCloseSessionResponse(secureChannel, responseHeader);
					}
				);

				return;
			}
		}

		sm_.event(
			[this, secureChannel, responseHeader](SessionServiceStateIf* sssif) {
				return sssif->recvMessageResponse(secureChannel, responseHeader);
			}
		);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// message handling
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	SessionService::receive(
		const OpcUaStackCore::MessageBusMember::WPtr& handleFrom,
		Message::SPtr message
	)
	{
		// We have to remeber the sender of the message. This enables us to
		// send a reply for the received message later
		auto serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);
		serviceTransaction->memberService(handleFrom);

		sm_.event(
			[this, message](SessionServiceStateIf* sssif) {
				return sssif->sendMessageRequest(message);
			}
		);
	}

	void
	SessionService::pendingQueueTimeout(Object::SPtr object)
	{
		sm_.event(
			[this, object](SessionServiceStateIf* sssif) {
				return sssif->pendingQueueTimeout(object);
			}
		);

	}

}
