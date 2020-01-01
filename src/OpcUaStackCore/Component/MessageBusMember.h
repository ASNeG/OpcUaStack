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

#ifndef __OpcUaStackCore_MessageBusMember_h__
#define __OpcUaStackCore_MessageBusMember_h__

#include <boost/shared_ptr.hpp>
#include <map>
#include <list>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Utility/IOThread.h"
#include "OpcUaStackCore/Component/Message.h"
#include "OpcUaStackCore/Component/MessageBusError.h"

namespace OpcUaStackCore
{

	class DLLEXPORT MessageBusMember
	{
	  public:
		using SPtr = boost::shared_ptr<MessageBusMember>;
		using WPtr = boost::weak_ptr<MessageBusMember>;
		using Map = std::map<std::string, SPtr>;
		using ReceiveCallback = std::function<void (MessageBusError error, const WPtr& handleFrom, Message::SPtr& message)>;
		using SendCompleteCallback = std::function<void (MessageBusError error)>;

		MessageBusMember(void);
		~MessageBusMember(void);

		void name(const std::string& name);
		std::string& name(void);
		void ioThread(IOThread::SPtr& ioThread);
		IOThread::SPtr& ioThread(void);

		void cancelReceiver(
			void
		);

		void messageReceive(
			const ReceiveCallback& receiveCallback
		);
		void messageReceive(
			const boost::shared_ptr<boost::asio::io_service::strand>& strand,
			const ReceiveCallback& receiveCallback
		);

		void messageSend(
			WPtr& sender,
			Message::SPtr& message
		);
		void messageSend(
			WPtr& sender,
			Message::SPtr& message,
			const SendCompleteCallback& sendCompleteCallback
		);
		void messageSend(
			WPtr& sender,
			Message::SPtr& message,
			const boost::shared_ptr<boost::asio::io_service::strand>& strand,
			const SendCompleteCallback& sendCompleteCallback
		);

	  private:
		class Msg
		{
		  public:
			Message::SPtr message_;
			WPtr sender_;
		};
		using MsgList = std::list<Msg>;

		void sendFirstMessageToReceiver(
			const ReceiveCallback& receiveCallback,
			const boost::shared_ptr<boost::asio::io_service::strand>& strand
		);

		std::string name_ = "";
		IOThread::SPtr ioThread_ = nullptr;

		boost::mutex mutex_;
		MsgList msgList_;

		bool receiverWait_ = false;
		boost::shared_ptr<boost::asio::io_service::strand> strand_ = nullptr;
		ReceiveCallback receiveCallback_;
	};

}

#endif
