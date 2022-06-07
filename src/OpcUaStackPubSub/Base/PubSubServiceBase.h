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

#ifndef __OpcUaStackServer_PubSubServiceBase_h__
#define __OpcUaStackServer_PubSubServiceBase_h__

#include <OpcUaStackCore/MessageBus/MessageBus.h>
#include <functional>
#include "OpcUaStackCore/Utility/IOThread.h"

namespace OpcUaStackServer
{

	class DLLEXPORT PubSubServiceBase
	: public boost::enable_shared_from_this<PubSubServiceBase>
	{
	  public:
		using SPtr = boost::shared_ptr<PubSubServiceBase>;
		using ReceiverCallback = std::function<
			void
			(const OpcUaStackCore::MessageBusMember::WPtr&, OpcUaStackCore::Message::SPtr&)
		>;

		PubSubServiceBase(void);
		virtual ~PubSubServiceBase(void);

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
