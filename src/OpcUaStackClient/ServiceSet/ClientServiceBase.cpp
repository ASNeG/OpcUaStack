/*
   Copyright 2020 Kai Huebl (kai@huebl-sgh.de)

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

#include <future>
#include <boost/make_shared.hpp>
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackClient/ServiceSet/ClientServiceBase.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	ClientServiceBase::ClientServiceBase(void)
	: boost::enable_shared_from_this<ClientServiceBase>()
	{
	}

	ClientServiceBase::~ClientServiceBase(void)
	{
	}

	MessageBusMember::WPtr&
	ClientServiceBase::messageBusMember(void)
	{
		return messageBusMember_;
	}

	boost::shared_ptr<boost::asio::io_service::strand>&
	ClientServiceBase::strand(void)
	{
		return strand_;
	}

	void
	ClientServiceBase::activateReceiver(const ReceiverCallback& receiverCallback)
	{
		Log(Info, "activate receiver")
			.parameter("ServiceName", serviceName_);

		receiverContext_ = boost::make_shared<ReceiverContext>();
		receiverContext_->receiverCallback_ = receiverCallback;

		// call the receiver for the first time
		receiveCallback();
	}

	void
	ClientServiceBase::deactivateReceiver(void)
	{
		if (!receiverContext_ || !receiverContext_->receiverCallback_) {
			return;
		}
/* FIXME: FOUND ENDLESS LOOP on windows!!!
 * FIXME: Problem: The opcua webgateway cannot open a new session after closing a old one.
		if (!strand_->running_in_this_thread()) {
			// the function was not called by the strand

			std::promise<void> promise;
			std::future<void> future = promise.get_future();

			strand_->dispatch(
				[this, &promise]() {
				    deactivateReceiver();
				    promise.set_value();
			    }
			);

			future.wait();
			return;
		}
*/
		Log(Info, "deactivate receiver")
			.parameter("ServiceName", serviceName_)
			.parameter("ServiceRunning", receiverContext_->receiverCallbackRunning_);

		//
		// the function was called by the strand
		//

		if (receiverContext_->receiverCallbackRunning_) {
			// The receiver callback is currently running
			receiverContext_->shutdown_ = true;
			receiverContext_.reset();
			return;
		}

		// the receiver is currently not running
		messageBus_->cancelReceiver(messageBusMember_, true);
		receiverContext_->shutdown_ = true;
		receiverContext_.reset();
	}

	void
	ClientServiceBase::syncSend(
		const MessageBusMember::WPtr& targetMember,
		const ServiceTransaction::SPtr& serviceTransaction
	)
	{
		serviceTransaction->sync(true);
		auto future = serviceTransaction->promise().get_future();
		asyncSend(targetMember, serviceTransaction);
		future.wait();
	}

	void
	ClientServiceBase::asyncSend(
		const MessageBusMember::WPtr& targetMember,
		const ServiceTransaction::SPtr& serviceTransaction
	)
	{
		messageBus_->messageSend(
			messageBusMember_,
			targetMember,
			serviceTransaction
		);
	}

	void
	ClientServiceBase::receiveCallback(void)
	{
		ReceiverContext::SPtr receiverContext = receiverContext_;
		receiverContext->shutdown_ = false;

		messageBus_->messageReceive(
			messageBusMember_,
			strand_,
			[this, receiverContext](MessageBusError error, const MessageBusMember::WPtr& handleFrom, Message::SPtr& message) {
				// check receiver context
				if (receiverContext->shutdown_) {
					return;
				}

			    // check error
				if (error != MessageBusError::Ok) {
					if (error != MessageBusError::Cancel) {
						Log(Error, "message receiver error")
							.parameter("ServiceName", serviceName_)
							.parameter("Error", int(error));
					}
					return;
				}

				// check if transaction is synchronously called
#if 0
				auto serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);
				if (serviceTransaction->sync()) {
					serviceTransaction->promise().set_value(true);

					receiveCallback();
					return;
				}
#endif

				// execute callback
				auto receiverContext = receiverContext_;
				if (receiverContext->receiverCallback_) {
					receiverContext->receiverCallbackRunning_ = true;
					receiverContext->receiverCallback_(handleFrom, message);
					receiverContext->receiverCallbackRunning_ = false;

					if (receiverContext->shutdown_) {
						return;
					}
				}

				receiveCallback();
		    }
		);
	}

}
