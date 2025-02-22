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

#include <boost/make_shared.hpp>
#include <OpcUaStackCore/MessageBus/MessageBusMember.h>
#include "OpcUaStackCore/Base/Log.h"

namespace OpcUaStackCore
{

	MessageBusMember::MessageBusMember(MessageBusMemberConfig& messageBusMemberConfig)
	: messageBusMemberConfig_(messageBusMemberConfig)
	{
	}

	MessageBusMember::~MessageBusMember(void)
	{
		while (msgList_.size() > 0) msgList_.pop_front();
	}

	void
	MessageBusMember::name(const std::string& name)
	{
		name_ = name;
	}

	std::string&
	MessageBusMember::name(void)
	{
		return name_;
	}

	MessageBusMemberConfig&
	MessageBusMember::messageBusMemberConfig(void)
	{
		return messageBusMemberConfig_;
	}

	void
	MessageBusMember::debugLogging(bool debugLogging)
	{
		debugLogging_ = debugLogging;
	}

	void
	MessageBusMember::receiveCancelDebug(
		const std::string& message
	)
	{
		if (!debugLogging_) {
			return;
		}

		Log(Debug, message)
			.parameter("Receiver", name());

	}

	void
	MessageBusMember::cancelReceiver(
		bool immediately
	)
	{
		boost::mutex::scoped_lock g(mutex_);

		if (immediately) {
		    strand_ = nullptr;
		    ioThread_ = nullptr;
		    receiverWait_ = false;
		    return;
		}

		// check if receiver is not active. In this case, calling the function
		// has no effect.
		if (!receiverWait_) {
			return;
		}

		receiveCancelDebug("plan on receive cancel");

		// call receiver callback with error code cancel
		ReceiveCallback receiveCallback = receiveCallback_;
		if (strand_) {
			strand_->post(
				[this, receiveCallback](void) {
					Message::SPtr message;
					receiveCancelDebug("execute receive cancel (strand)");
					receiveCallback(MessageBusError::Cancel, MessageBusMember::WPtr(), message);
				}
			);
		}
		else if (ioThread_) {
			ioThread_->run(
				[this, receiveCallback](void) {
					Message::SPtr message;
					receiveCancelDebug("execute receive cancel (ioThread)");
					receiveCallback(MessageBusError::Cancel, MessageBusMember::WPtr(), message);
				}
			);
		}
		else if (messageBusMemberConfig_.strand()) {
			messageBusMemberConfig_.strand()->post(
				[this, receiveCallback](void) {
					Message::SPtr message;
					receiveCancelDebug("execute receive cancel (strand config)");
					receiveCallback(MessageBusError::Cancel, MessageBusMember::WPtr(), message);
				}
			);
		}
		else if (messageBusMemberConfig_.ioThread()) {
			messageBusMemberConfig_.ioThread()->run(
				[this, receiveCallback](void) {
					Message::SPtr message;
					receiveCancelDebug("execute receive cancel (ioThread config)");
					receiveCallback(MessageBusError::Cancel, MessageBusMember::WPtr(), message);
				}
			);
		}
		else {
			return;
		}

		strand_ = nullptr;
		ioThread_ = nullptr;
		receiverWait_ = false;
	}

	void
	MessageBusMember::receiveMessageDebug(
		const std::string& message,
		const MessageBusMember::WPtr& sender,
		uint32_t sequence
	)
	{
		if (!debugLogging_) {
			return;
		}

		auto senderLock = sender.lock();
		if (!senderLock) {
			return;
		}

		Log(Debug, message)
			.parameter("Sender", senderLock->name())
			.parameter("Receiver", name())
			.parameter("Sequence", sequence);

	}

	void
	MessageBusMember::sendFirstMessageToReceiver(void)
	{
		// This function must be called inside the mutex_.

		// get message from message list
		auto sender = msgList_.front().sender_;
	    auto message = msgList_.front().message_;
		msgList_.pop_front();

		receiveMessageDebug("plan on receive message", sender, message->sequence_);

		// call receiver callback with message
		if (strand_) {
			strand_->post(
			    [this, sender, message](void) mutable {
				    receiveMessageDebug("execute receive message (strand)", sender, message->sequence_);
					receiveCallback_(MessageBusError::Ok, sender, message);
				}
			);
		}
		else if (ioThread_) {
			ioThread_->run(
			    [this, sender, message](void) mutable {
				receiveMessageDebug("execute receive message (ioThread)", sender, message->sequence_);
					receiveCallback_(MessageBusError::Ok, sender, message);
				}
			);
		}
		else if (messageBusMemberConfig_.strand()) {
			messageBusMemberConfig_.strand()->post(
			    [this, sender, message](void) mutable {
				    receiveMessageDebug("execute receive message (strand config)", sender, message->sequence_);
					receiveCallback_(MessageBusError::Ok, sender, message);
				}
			);
		}
		else if (messageBusMemberConfig_.ioThread()) {
			messageBusMemberConfig_.ioThread()->run(
			    [this, sender, message](void) mutable {
					receiveMessageDebug("execute receive message (ioThread config)", sender, message->sequence_);
					receiveCallback_(MessageBusError::Ok, sender, message);
				}
			);
		}
		else {
			return;
		}

		strand_ = nullptr;
		ioThread_ = nullptr;
		receiverWait_ = false;
	}

	void
	MessageBusMember::messageReceive(
		const ReceiveCallback& receiveCallback
	)
	{
		boost::mutex::scoped_lock g(mutex_);

		// check parameter
		if (receiverWait_) {
			// ignore receiver
			return;
		}

		strand_ = nullptr;
		ioThread_ = nullptr;
		receiveCallback_ = receiveCallback;

		// check message list
		if (msgList_.empty()) {
			receiverWait_ = true;
			return;
		}

		// handle first message from list
		sendFirstMessageToReceiver();
	}

	void
	MessageBusMember::messageReceive(
		const IOThread::SPtr& ioThread,
		const ReceiveCallback& receiveCallback
	)
	{
		boost::mutex::scoped_lock g(mutex_);

		// check parameter
		if (receiverWait_) {
			// ignore receiver
			return;
		}

		strand_ = nullptr;
		ioThread_ = ioThread;
		receiveCallback_ = receiveCallback;

		// check message list
		if (msgList_.empty()) {
			receiverWait_ = true;
			return;
		}

		// handle first message from list
		sendFirstMessageToReceiver();
	}

	void
	MessageBusMember::messageReceive(
		const boost::shared_ptr<boost::asio::io_service::strand>& strand,
		const MessageBusMember::ReceiveCallback& receiveCallback
	)
	{
		boost::mutex::scoped_lock g(mutex_);

		// check parameter
		if (receiverWait_) {
			// ignore receiver
			return;
		}

		strand_ = strand;
		ioThread_ = nullptr;
		receiveCallback_ = receiveCallback;

		// check message list
		if (msgList_.empty()) {
			receiverWait_ = true;
			return;
		}

		// handle first message from list
		sendFirstMessageToReceiver();
	}

	void
	MessageBusMember::messageSend(
		const WPtr& sender,
		const Message::SPtr& message
	)
	{
		// This function transfers a message to the message bus member

		boost::mutex::scoped_lock g(mutex_);
		message->sequence_ = sequence_++;

		// check number of entries in list
		auto maxReceiveQueueSize = messageBusMemberConfig_.maxReceiveQueueSize();
		if (maxReceiveQueueSize != 0 && msgList_.size() >= maxReceiveQueueSize) {
			return;
		}

		// save message in list
		Msg msg;
		msg.sender_ = sender;
		msg.message_ = message;
		msgList_.push_back(msg);

		// check if receiver is waiting for a message
		if (receiverWait_) {
			sendFirstMessageToReceiver();
		}
	}

	void
	MessageBusMember::messageSend(
		const WPtr& sender,
		const Message::SPtr& message,
		const IOThread::SPtr& ioThreadSender,
		const SendCompleteCallback& sendCompleteCallback
	)
	{
		// This function transfers a message to the message bus member

		boost::mutex::scoped_lock g(mutex_);
		message->sequence_ = sequence_++;
		sendCompleteCallback_ = sendCompleteCallback;

		// check number of entries in list
		auto maxReceiveQueueSize = messageBusMemberConfig_.maxReceiveQueueSize();
		if (maxReceiveQueueSize != 0 && msgList_.size() >= maxReceiveQueueSize) {
			ioThreadSender->run(
				[this](void) {
					sendCompleteCallback_(MessageBusError::Overflow);
				}
			);
			return;
		}

		// save message in list
		Msg msg;
		msg.sender_ = sender;
		msg.message_ = message;
		msgList_.push_back(msg);

		// check if receiver is waiting for a message
		if (receiverWait_) {
			sendFirstMessageToReceiver();
		}

		// call send complete callback
		ioThreadSender->run(
			[this](void) {
				sendCompleteCallback_(MessageBusError::Ok);
			}
		);
	}

	void
	MessageBusMember::messageSend(
		const WPtr& sender,
		const Message::SPtr& message,
		const boost::shared_ptr<boost::asio::io_service::strand>& strandSender,
		const SendCompleteCallback& sendCompleteCallback
	)
	{
		// This function transfers a message to the message bus member

		boost::mutex::scoped_lock g(mutex_);
		message->sequence_ = sequence_++;
		sendCompleteCallback_ = sendCompleteCallback;

		// check number of entries in list
		auto maxReceiveQueueSize = messageBusMemberConfig_.maxReceiveQueueSize();
		if (maxReceiveQueueSize != 0 && msgList_.size() >= maxReceiveQueueSize) {
			strandSender->post(
				[this](void) {
					sendCompleteCallback_(MessageBusError::Overflow);
				}
			);
			return;
		}

		// save message in list
		Msg msg;
		msg.sender_ = sender;
		msg.message_ = message;
		msgList_.push_back(msg);

		// check if receiver is waiting for a message
		if (receiverWait_) {
			sendFirstMessageToReceiver();
		}

		// call send complete callback
		strandSender->post(
			[this](void) {
				sendCompleteCallback_(MessageBusError::Ok);
			}
		);
	}

}
