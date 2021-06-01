/*
   Copyright 2019-2021 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/MessageBus/MessageBus.h"

namespace OpcUaStackCore
{

	MessageBus::MessageBus(void)
	{
	}

	MessageBus::MessageBus(MessageBusConfig& messageBusConfig)
	{
		messageBusConfig_ = messageBusConfig;
	}

	MessageBus::~MessageBus(void)
	{
		boost::mutex::scoped_lock g(mutex_);

		messageBusMemberMap_.clear();
	}

	void
	MessageBus::debugLogging(bool debugLogging)
	{
		debugLogging_ = debugLogging;
	}

	bool
	MessageBus::existMember(const std::string& name)
	{
		boost::mutex::scoped_lock g(mutex_);

		// check if member name already exist
		auto it = messageBusMemberMap_.find(name);
		if (it != messageBusMemberMap_.end()) {
			return true;
		}

		return false;
	}

	MessageBusMember::WPtr
	MessageBus::registerMember(const std::string& name)
	{
		Log(Debug, "register message bus member")
			.parameter("MessageBusMember", name);

		boost::mutex::scoped_lock g(mutex_);

		// check if member name already exist
		auto it = messageBusMemberMap_.find(name);
		if (it != messageBusMemberMap_.end()) {
			return it->second;
		}

		// create new member
		MessageBusMemberConfig messageBusMemberConfig;
		messageBusMemberConfig.maxReceiveQueueSize(messageBusConfig_.maxReceiveQueueSize());
		messageBusMemberConfig.ioThread(messageBusConfig_.ioThread());
		messageBusMemberConfig.strand(messageBusConfig_.strand());

		auto messageBusMember = boost::make_shared<MessageBusMember>(messageBusMemberConfig);
		messageBusMember->name(name);
		messageBusMember->debugLogging(debugLogging_);

		// add new member to list
		messageBusMemberMap_.insert(std::make_pair(name, messageBusMember));

		return messageBusMember;
	}

	MessageBusMember::WPtr
	MessageBus::registerMember(const std::string& name, MessageBusMemberConfig& messageBusMemberConfig)
	{
		Log(Debug, "register message bus member")
			.parameter("MessageBusMember", name);

		boost::mutex::scoped_lock g(mutex_);

		// check if member name already exist
		auto it = messageBusMemberMap_.find(name);
		if (it != messageBusMemberMap_.end()) {
			return it->second;
		}

		// create new member
		auto defaultMaxReceiveQueueSize = messageBusConfig_.calcMaxReceiveQueueSize(messageBusMemberConfig.maxReceiveQueueSize());
		messageBusMemberConfig.maxReceiveQueueSize(defaultMaxReceiveQueueSize);
		if (!messageBusMemberConfig.ioThread() && !messageBusMemberConfig.strand()) {
			messageBusMemberConfig.ioThread(messageBusConfig_.ioThread());
			messageBusMemberConfig.strand(messageBusConfig_.strand());
		}

		auto messageBusMember = boost::make_shared<MessageBusMember>(messageBusMemberConfig);
		messageBusMember->name(name);
		messageBusMember->debugLogging(debugLogging_);

		// add new member to list
		messageBusMemberMap_.insert(std::make_pair(name, messageBusMember));

		return messageBusMember;
	}

	void
	MessageBus::deregisterMember(MessageBusMember::WPtr& messageBusHandle)
	{
		boost::mutex::scoped_lock g(mutex_);

		// check member
		auto messageBusMember = messageBusHandle.lock();
		if (!messageBusMember) {
			return;
		}

		Log(Debug, "deregister message bus member")
			.parameter("MessageBusMember", messageBusMember->name());

		// check if member exist
		auto it = messageBusMemberMap_.find(messageBusMember->name());
		if (it == messageBusMemberMap_.end()) {
			return;
		}

		// remove member from list
		messageBusMemberMap_.erase(it);
	}

	MessageBusMember::WPtr
	MessageBus::getMember(const std::string& name)
	{
		boost::mutex::scoped_lock g(mutex_);

		// check if member name already exist
		auto it = messageBusMemberMap_.find(name);
		if (it != messageBusMemberMap_.end()) {
			return it->second;
		}

		// member not exist
		return MessageBusMember::WPtr();
	}

	void
	MessageBus::getMemberNames(std::vector<std::string>& names)
	{
		boost::mutex::scoped_lock g(mutex_);

		for (auto it : messageBusMemberMap_) {
			names.push_back(it.first);
		}
	}

	void
	MessageBus::cancelReceiver(
		MessageBusMember::WPtr& receiver,
		bool immediately
	)
	{
		auto messageBusReceiver = receiver.lock();
		if (!messageBusReceiver) {
			return;
		}

		messageBusReceiver->cancelReceiver(immediately);
	}

	void
	MessageBus::messageReceive(
		MessageBusMember::WPtr& receiver,
		const MessageBusMember::ReceiveCallback& receiveCallback
	)
	{
		// check receiver
		auto messageBusReceiver = receiver.lock();
		if (!messageBusReceiver) {
			if (!messageBusConfig_.ioThread()) {
				return;
			}

			messageBusConfig_.ioThread()->run(
				[this, receiveCallback](void) {
					Message::SPtr message;
					receiveCallback(MessageBusError::ReceiverUnknown, MessageBusMember::WPtr(), message);
				}
			);
			return;
		}

		// receive message
		messageBusReceiver->messageReceive(receiveCallback);
	}

	void
	MessageBus::messageReceive(
		MessageBusMember::WPtr& receiver,
		const IOThread::SPtr& ioThread,
		const MessageBusMember::ReceiveCallback& receiveCallback
	)
	{
		// check receiver
		auto messageBusReceiver = receiver.lock();
		if (!messageBusReceiver) {
			ioThread->run(
				[this, receiveCallback](void) {
					Message::SPtr message;
					receiveCallback(MessageBusError::ReceiverUnknown, MessageBusMember::WPtr(), message);
				}
			);
			return;
		}

		// receive message
		messageBusReceiver->messageReceive(ioThread, receiveCallback);
	}

	void
	MessageBus::messageReceive(
		MessageBusMember::WPtr& receiver,
		const boost::shared_ptr<boost::asio::io_service::strand>& strand,
		const MessageBusMember::ReceiveCallback& receiveCallback
	)
	{
		// check receiver
		auto messageBusReceiver = receiver.lock();
		if (!messageBusReceiver) {
			strand->post(
				[this, receiveCallback](void) {
					Message::SPtr message;
					receiveCallback(MessageBusError::ReceiverUnknown, MessageBusMember::WPtr(), message);
				}
			);
			return;
		}

		// receive message
		messageBusReceiver->messageReceive(strand, receiveCallback);
	}

	void
	MessageBus::messageSend(
		const MessageBusMember::WPtr& sender,
		const MessageBusMember::WPtr& receiver,
		const Message::SPtr& message
	)
	{
		// check sender
		auto messageBusSender = sender.lock();
		if (!messageBusSender) {
			Log(Error, "message bus sender not exist");
			return;
		}

		// check receiver
		auto messageBusReceiver = receiver.lock();
		if (!messageBusReceiver) {
			Log(Error, "message bus receiver not exist");
			return;
		}

		if (debugLogging_) {
			Log(Debug, "send message")
				.parameter("Sender", messageBusSender->name())
				.parameter("Receiver", messageBusReceiver->name());
		}

		// send message
		messageBusReceiver->messageSend(sender, message);
	}

	void
	MessageBus::messageSend(
		const MessageBusMember::WPtr& sender,
		const MessageBusMember::WPtr& receiver,
		const Message::SPtr& message,
		const MessageBusMember::SendCompleteCallback& sendCompleteCallback
	)
	{
		auto messageBusSender = sender.lock();
		auto messageBusReceiver = receiver.lock();

		// get sender strand and ioThread
		auto strandSender = messageBusConfig_.strand();
		auto ioThreadSender = messageBusConfig_.ioThread();
		if (messageBusSender) {
			strandSender = messageBusSender->messageBusMemberConfig().strand();
			ioThreadSender = messageBusSender->messageBusMemberConfig().ioThread();
		}

		// check sender
		if (!messageBusSender) {
			if (strandSender) {
				strandSender->post(
				    [this, sendCompleteCallback](void) {
					    Message::SPtr message;
					    sendCompleteCallback(MessageBusError::SenderUnknown);
				    }
			    );
			}
			else if (ioThreadSender) {
				ioThreadSender->run(
				    [this, sendCompleteCallback](void) {
					    Message::SPtr message;
					    sendCompleteCallback(MessageBusError::SenderUnknown);
				    }
			    );
			}
			return;
		}

		// check receiver
		if (!messageBusReceiver) {
			if (strandSender) {
			    strandSender->post(
				    [this, sendCompleteCallback](void) {
					    Message::SPtr message;
					    sendCompleteCallback(MessageBusError::ReceiverUnknown);
				    }
			    );
			}
			else if (ioThreadSender) {
				ioThreadSender->run(
				    [this, sendCompleteCallback](void) {
					    Message::SPtr message;
					    sendCompleteCallback(MessageBusError::ReceiverUnknown);
				    }
			    );
			}
			return;
		}

		if (debugLogging_) {
			Log(Debug, "send message")
				.parameter("Sender", messageBusSender->name())
				.parameter("Receiver", messageBusReceiver->name());
		}

		// send message
		if (strandSender) {
			messageBusReceiver->messageSend(sender, message, strandSender, sendCompleteCallback);
		}
		else if (ioThreadSender) {
			messageBusReceiver->messageSend(sender, message, ioThreadSender, sendCompleteCallback);
		}
		else {
		    messageBusReceiver->messageSend(sender, message);
		}
	}

	void
	MessageBus::messageSend(
		const MessageBusMember::WPtr& sender,
		const MessageBusMember::WPtr& receiver,
		const Message::SPtr& message,
		const IOThread::SPtr& ioThreadSender,
		const MessageBusMember::SendCompleteCallback& sendCompleteCallback
	)
	{
		auto messageBusSender = sender.lock();
		auto messageBusReceiver = receiver.lock();

		// check sender
		if (!messageBusSender) {
			ioThreadSender->run(
				[this, sendCompleteCallback](void) {
					Message::SPtr message;
					sendCompleteCallback(MessageBusError::SenderUnknown);
				}
			);
			return;
		}

		// check receiver
		if (!messageBusReceiver) {
			ioThreadSender->run(
				[this, sendCompleteCallback](void) {
					Message::SPtr message;
					sendCompleteCallback(MessageBusError::ReceiverUnknown);
				}
			);
			return;
		}

		if (debugLogging_) {
			Log(Debug, "send message")
				.parameter("Sender", messageBusSender->name())
				.parameter("Receiver", messageBusReceiver->name());
		}

		// send message
		messageBusReceiver->messageSend(sender, message, ioThreadSender, sendCompleteCallback);
	}

	void
	MessageBus::messageSend(
		const MessageBusMember::WPtr& sender,
		const MessageBusMember::WPtr& receiver,
		const Message::SPtr& message,
		const boost::shared_ptr<boost::asio::io_service::strand>& strandSender,
		const MessageBusMember::SendCompleteCallback& sendCompleteCallback
	)
	{
		auto messageBusSender = sender.lock();
		auto messageBusReceiver = receiver.lock();

		// check sende
		if (!messageBusSender) {
			strandSender->post(
				[this, sendCompleteCallback](void) {
					sendCompleteCallback(MessageBusError::SenderUnknown);
				}
			);
			return;
		}

		// check receiver
		if (!messageBusReceiver) {
			strandSender->post(
				[this, sendCompleteCallback](void) {
					sendCompleteCallback(MessageBusError::ReceiverUnknown);
				}
			);
			return;
		}

		if (debugLogging_) {
			Log(Debug, "send message")
				.parameter("Sender", messageBusSender->name())
				.parameter("Receiver", messageBusReceiver->name());
		}

		// send message
		messageBusReceiver->messageSend(sender, message, strandSender, sendCompleteCallback);
	}

	void
	MessageBus::log(void)
	{
		for (auto it : messageBusMemberMap_) {
			Log(Debug, "MessageBusMember")
			    .parameter("Name", it.first);
		}
	}

}
