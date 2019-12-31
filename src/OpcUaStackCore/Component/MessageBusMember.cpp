/*
   Copyright 2019 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/Component/MessageBusMember.h"

namespace OpcUaStackCore
{

	MessageBusMember::MessageBusMember(void)
	{
	}

	MessageBusMember::~MessageBusMember(void)
	{
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

	void
	MessageBusMember::ioThread(IOThread::SPtr& ioThread)
	{
		ioThread_ = ioThread;
	}

	IOThread::SPtr&
	MessageBusMember::ioThread(void)
	{
		return ioThread_;
	}

	void
	MessageBusMember::cancelReceiver(
		void
	)
	{
		boost::mutex::scoped_lock g(mutex_);

		// check if receiver is active
		if (!receiverWait_) {
			return;
		}

		ReceiveCallback receiveCallback = receiveCallback_;

		if (strand_) {
			strand_->post(
				[this, receiveCallback](void) {
					Message::SPtr message;
					receiveCallback(MessageBusError::Cancel, MessageBusMember::WPtr(), message);
				}
			);
		}
		else {
			ioThread()->run(
				[this, receiveCallback](void) {
					Message::SPtr message;
					receiveCallback(MessageBusError::Cancel, MessageBusMember::WPtr(), message);
				}
			);
		}

		receiverWait_ = false;
	}

	void
	MessageBusMember::handleReceiveMessage(
		ReceiveCallback& receiveCallback,
		const boost::shared_ptr<boost::asio::io_service::strand>& strand
	)
	{
		// receive message
		WPtr sender = msgList_.front().sender_;
		Message::SPtr message = msgList_.front().message_;
		msgList_.pop_front();

		if (strand) {
			strand_->post(
			    [this, receiveCallback, sender, message](void) mutable {
					receiveCallback(MessageBusError::Ok, sender, message);
				}
			);
		}
		else {
			ioThread()->run(
			    [this, receiveCallback, sender, message](void) mutable {
					receiveCallback(MessageBusError::Ok, sender, message);
				}
			);
		}

		receiverWait_ = false;
	}

	void
	MessageBusMember::messageReceive(
		ReceiveCallback& receiveCallback
	)
	{
		boost::mutex::scoped_lock g(mutex_);

		// check parameter
		if (receiverWait_) {
			// ignore receiver
			return;
		}

		// check message list
		if (msgList_.empty()) {
			receiveCallback_ = receiveCallback;
			strand_ = nullptr;
			receiverWait_ = true;
			return;
		}

		// handle first message from list
		handleReceiveMessage(receiveCallback, nullptr);
	}

	void
	MessageBusMember::messageReceive(
		const boost::shared_ptr<boost::asio::io_service::strand>& strand,
		MessageBusMember::ReceiveCallback& receiveCallback
	)
	{
		boost::mutex::scoped_lock g(mutex_);

		// check parameter
		if (receiverWait_) {
			// ignore receiver
			return;
		}

		// check message list
		if (msgList_.empty()) {
			receiveCallback_ = receiveCallback;
			strand_ = nullptr;
			receiverWait_ = true;
			return;
		}

		// handle first message from list
		handleReceiveMessage(receiveCallback, strand);
	}

	void
	MessageBusMember::messageSend(
		WPtr& sender,
		Message::SPtr& message
	)
	{
		boost::mutex::scoped_lock g(mutex_);

		// check if receiver is waiting for a message
		if (receiverWait_) {
			ReceiveCallback receiveCallback = receiveCallback_;

			// handle first message from list
			handleReceiveMessage(receiveCallback, strand_);
			return;
		}

		// save message in list
		Msg msg;
		msg.sender_ = sender;
		msg.message_ = message;
		msgList_.push_back(msg);
	}

	void
	MessageBusMember::messageSend(
		WPtr& sender,
		Message::SPtr& message,
		SendCompleteCallback& sendCompleteCallback
	)
	{
		boost::mutex::scoped_lock g(mutex_);

		// check if receiver is waiting for a message
		if (receiverWait_) {
			ReceiveCallback receiveCallback = receiveCallback_;

			// handle first message from list
			handleReceiveMessage(receiveCallback, strand_);

			// call send complete callback
			ioThread()->run(
				[this, sendCompleteCallback](void) {
					sendCompleteCallback(MessageBusError::Ok);
				}
			);

			return;
		}

		// save message in list
		Msg msg;
		msg.sender_ = sender;
		msg.message_ = message;
		msgList_.push_back(msg);

		// call send complete callback
		ioThread()->run(
			[this, sendCompleteCallback](void) {
				sendCompleteCallback(MessageBusError::Ok);
			}
		);
	}

	void
	MessageBusMember::messageSend(
		WPtr& sender,
		Message::SPtr& message,
		const boost::shared_ptr<boost::asio::io_service::strand>& strand,
		SendCompleteCallback& sendCompleteCallback
	)
	{
		boost::mutex::scoped_lock g(mutex_);

		// check if receiver is waiting for a message
		if (receiverWait_) {
			ReceiveCallback receiveCallback = receiveCallback_;

			// handle first message from list
			handleReceiveMessage(receiveCallback, strand_);

			// call send complete callback
			strand->post(
				[this, sendCompleteCallback](void) {
					sendCompleteCallback(MessageBusError::Ok);
				}
			);

			return;
		}

		// save message in list
		Msg msg;
		msg.sender_ = sender;
		msg.message_ = message;
		msgList_.push_back(msg);

		// call send complete callback
		strand->post(
			[this, sendCompleteCallback](void) {
				sendCompleteCallback(MessageBusError::Ok);
			}
		);
	}

}
