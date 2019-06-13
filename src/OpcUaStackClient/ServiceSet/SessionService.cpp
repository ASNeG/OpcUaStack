/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/ServiceSet/ActivateSessionRequest.h"
#include "OpcUaStackCore/ServiceSet/ActivateSessionResponse.h"
#include "OpcUaStackCore/ServiceSet/CloseSessionRequest.h"
#include "OpcUaStackClient/ServiceSet/SessionService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	SessionService::SessionService(IOThread* ioThread)
	: sm_()
	, ctx_(new SessionServiceContext(ioThread))
	{
		Component::ioThread(ioThread);
		ctx_->slotTimerElement_ = boost::make_shared<SlotTimerElement>();
		ctx_->ioThread_ = ioThread;
		ctx_->sessionService_ = this;

		// init pending queue callback
		ctx_->pendingQueue_.ioService(*ioThread->ioService().get());
		ctx_->pendingQueue_.timeoutCallback().reset(
			boost::bind(&SessionService::pendingQueueTimeout, this, _1)
		);

		// init state machine
		sm_.setCtx(ctx_);
		sm_.setStateId(SessionServiceStateId::Disconnected);
	}

	SessionService::~SessionService(void)
	{
		// stop timer element
		if (ctx_->slotTimerElement_.get() != nullptr) {
			ctx_->ioThread_->slotTimer()->stop(ctx_->slotTimerElement_);
			ctx_->slotTimerElement_.reset();
		}

		delete ctx_;
		ctx_ = nullptr;
	}

	void
	SessionService::setConfiguration(
		SessionMode sessionMode,
		SessionServiceChangeHandler& sessionServiceChangeHandler,
		SecureChannelClientConfig::SPtr& secureChannelClientConfig,
		SessionConfig::SPtr& sessionConfig
	)
	{
		ctx_->sessionMode_ = sessionMode;
		ctx_->sessionServiceChangeHandler_ = sessionServiceChangeHandler;
		ctx_->secureChannelClientConfig_ = secureChannelClientConfig;
		ctx_->secureChannelClientConfigBackup_ = secureChannelClientConfig;
		ctx_->sessionConfig_ = sessionConfig;

		sm_.setSessionServiceName(sessionConfig->sessionName());
		sm_.setUpdateCallback(
			[this](SessionServiceStateId state) {
				if (ctx_->sessionServiceChangeHandler_) {
					ctx_->sessionServiceChangeHandler_(*ctx_->sessionService_, state);
				}
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
		ctx_->ioThread_->run(
			boost::bind(&SessionService::asyncConnectInternal, this)
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

		ctx_->ioThread_->run(
			boost::bind(&SessionService::asyncConnectInternal, this)
		);

		future.wait();
		return future.get();
	}

	void
	SessionService::asyncDisconnect(bool deleteSubscriptions)
	{
		ctx_->ioThread_->run(
			boost::bind(&SessionService::asyncDisconnectInternal, this, deleteSubscriptions)
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


		ctx_->ioThread_->run(
			boost::bind(&SessionService::asyncDisconnectInternal, this, deleteSubscriptions)
		);

		future.wait();
		return future.get();
	}

	void
	SessionService::asyncCancel(uint32_t requestHandle)
	{
		ctx_->ioThread_->run(
			boost::bind(&SessionService::asyncCancelInternal, this, requestHandle)
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
	SessionService::receive(Message::SPtr message)
	{
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
