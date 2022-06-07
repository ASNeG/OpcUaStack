/*
   Copyright 2022 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackPubSub/Base/PubSubServiceBase.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	PubSubServiceBase::PubSubServiceBase(void)
	: boost::enable_shared_from_this<PubSubServiceBase>()
	{
	}

	PubSubServiceBase::~PubSubServiceBase(void)
	{
	}

	MessageBusMember::WPtr&
	PubSubServiceBase::messageBusMember(void)
	{
		return messageBusMember_;
	}

	boost::shared_ptr<boost::asio::io_service::strand>&
	PubSubServiceBase::strand(void)
	{
		return strand_;
	}

	void
	PubSubServiceBase::activateReceiver(const ReceiverCallback& receiverCallback)
	{
		Log(Info, "activate receiver")
			.parameter("ServiceName", serviceName_);

		receiverContext_ = boost::make_shared<ReceiverContext>();
		receiverContext_->receiverCallback_ = receiverCallback;

		// call the receiver for the first time
		receiveCallback();
	}

	void
	PubSubServiceBase::deactivateReceiver(void)
	{
		if (!receiverContext_ || !receiverContext_->receiverCallback_) {
			return;
		}

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

		Log(Info, "deactivate receiver")
			.parameter("ServiceName", serviceName_);

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
	PubSubServiceBase::receiveCallback(void)
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

				// execute callback
				ReceiverContext::SPtr receiverContext = receiverContext_;
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
