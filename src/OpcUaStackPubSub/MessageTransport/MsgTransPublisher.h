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

   DESCRIPTION:

   The message transport publisher module receives a message from one ore more
   network message writer groups via the internal message bus. The received message
   is  forwarded to the assigned communication module via the internal message bus.

 */

#ifndef __OpcUaStackPubSub_MsgTransPublisher_h__
#define __OpcUaStackPubSub_MsgTransPublisher_h__

#include "OpcUaStackServer/ServiceSet/ServerServiceBase.h"

namespace OpcUaStackPubSub
{

	class DLLEXPORT MsgTransPublisher
	: public OpcUaStackCore::Object
	, public OpcUaStackServer::ServerServiceBase
	{
	  public:
		using SPtr = boost::shared_ptr<MsgTransPublisher>;

		MsgTransPublisher(
			const std::string& connectionName,			// message bus member name
			const std::string& serviceName,
			OpcUaStackCore::IOThread::SPtr& ioThread,
			OpcUaStackCore::MessageBus::SPtr& messageBus
		);
		~MsgTransPublisher(void);

		bool startup(void);
		bool shutdown(void);

	  private:
		OpcUaStackCore::IOThread::SPtr ioThread_;	// smart pointer to io thread
	};

}

#endif
