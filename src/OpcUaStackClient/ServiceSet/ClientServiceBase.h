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

#ifndef __OpcUaStackClient_ClientServiceBase_h__
#define __OpcUaStackClient_ClientServiceBase_h__

#include <functional>
#include "OpcUaStackCore/Component/MessageBus.h"
#include "OpcUaStackCore/Utility/IOThread.h"

namespace OpcUaStackClient 
{

	class DLLEXPORT ClientServiceBase
	: public boost::enable_shared_from_this<ClientServiceBase>
	{
	  public:
		using SPtr = boost::shared_ptr<ClientServiceBase>;
		using ReceiverCallback = std::function<void (OpcUaStackCore::Message::SPtr&)>;

		ClientServiceBase(void);
		virtual ~ClientServiceBase(void);

		OpcUaStackCore::MessageBusMember::WPtr& messageBusMember(void);
		boost::shared_ptr<boost::asio::io_service::strand>& strand(void);

		void activateReceiver(const ReceiverCallback& receiverCallback);
		void deactivateReceiver(void);

	  protected:
		void receiveCallback(void);

		// configuration data
		std::string serviceName_ = "";
		OpcUaStackCore::IOThread* ioThread_ = nullptr;
		boost::shared_ptr<boost::asio::io_service::strand> strand_ = nullptr;
		OpcUaStackCore::MessageBus::SPtr messageBus_ = nullptr;
		OpcUaStackCore::MessageBusMember::WPtr messageBusMember_;

		// runtime data
		class ReceiverContext
		{
		  public:
			using SPtr = boost::shared_ptr<ReceiverContext>;
			ReceiverCallback receiverCallback_ = nullptr;
			bool receiverCallbackRunning_ = false;
			bool shutdown_ = false;
		};
		ReceiverContext::SPtr receiverContext_;
	};

}

#endif
