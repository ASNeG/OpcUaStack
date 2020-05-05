/*
   Copyright 2019-2020 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_MessageBus_h__
#define __OpcUaStackCore_MessageBus_h__

#include <boost/thread/mutex.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/asio/strand.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Component/MessageBusConfig.h"
#include "OpcUaStackCore/Component/MessageBusMember.h"

namespace OpcUaStackCore
{

	class DLLEXPORT MessageBus
	{
	  public:
		using SPtr = boost::shared_ptr<MessageBus>;

		MessageBus(void);
		MessageBus(MessageBusConfig& messageBusConfig);
		virtual ~MessageBus(void);

		void debugLogging(bool debugLogging);
		bool existMember(const std::string& name);
		MessageBusMember::WPtr registerMember(const std::string& name);
		MessageBusMember::WPtr registerMember(const std::string& name, MessageBusMemberConfig& messageBusMemberConfig);
		void deregisterMember(MessageBusMember::WPtr& messageBusHandle);
		MessageBusMember::WPtr getMember(const std::string& name);
		void getMemberNames(std::vector<std::string>& names);

		void cancelReceiver(
			MessageBusMember::WPtr& receiver,
			bool immediately = false
		);

		void messageReceive(
			MessageBusMember::WPtr& receiver,
			const MessageBusMember::ReceiveCallback& receiveCallback
		);
		void messageReceive(
			MessageBusMember::WPtr& receiver,
			const IOThread::SPtr& ioThread,
			const MessageBusMember::ReceiveCallback& receiveCallback
		);
		void messageReceive(
			MessageBusMember::WPtr& receiver,
			const boost::shared_ptr<boost::asio::io_service::strand>& strand,
			const MessageBusMember::ReceiveCallback& receiveCallback
		);

		void messageSend(
			MessageBusMember::WPtr& sender,
			MessageBusMember::WPtr& receiver,
			const Message::SPtr& message
		);
		void messageSend(
			MessageBusMember::WPtr& sender,
			MessageBusMember::WPtr& receiver,
			const Message::SPtr& message,
			const MessageBusMember::SendCompleteCallback& sendCompleteCallback
		);
		void messageSend(
			MessageBusMember::WPtr& sender,
			MessageBusMember::WPtr& receiver,
			const Message::SPtr& message,
			const IOThread::SPtr& ioThreadSender,
			const MessageBusMember::SendCompleteCallback& sendCompleteCallback
		);
		void messageSend(
			MessageBusMember::WPtr& sender,
			MessageBusMember::WPtr& receiver,
			const Message::SPtr& message,
			const boost::shared_ptr<boost::asio::io_service::strand>& strandSender,
			const MessageBusMember::SendCompleteCallback& sendCompleteCallback
		);

	  private:
		bool debugLogging_ = false;
		boost::mutex mutex_;
		MessageBusConfig messageBusConfig_;
		MessageBusMember::Map messageBusMemberMap_;

	};

}

#endif
