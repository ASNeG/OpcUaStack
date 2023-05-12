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

#ifndef __OpcUaStackPubSub_NetworkMessageProcessor_h__
#define __OpcUaStackPubSub_NetworkMessageProcessor_h__

#include <boost/asio.hpp>

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/ServiceSet/ServerServiceBase.h"
#include "OpcUaStackPubSub/DataSetReader/DataSetReaderBase.h"
#include "OpcUaStackPubSub/Events/NetworkSendEvent.h"
#include "OpcUaStackPubSub/Events/NetworkRecvEvent.h"

namespace OpcUaStackPubSub
{

	class DLLEXPORT NetworkMessageProcessor
	: public OpcUaStackCore::Object
	, public OpcUaStackServer::ServerServiceBase
	{
	  public:
		using SPtr = boost::shared_ptr<NetworkMessageProcessor>;

		NetworkMessageProcessor(
			const std::string& messageProcessorName,
			const std::string& messageTransportName,
			OpcUaStackCore::IOThread::SPtr& ioThread,
			OpcUaStackCore::MessageBus::SPtr& messageBus
		);
		virtual ~NetworkMessageProcessor(void);

		void readerGroupId(uint16_t readerGroupId);
		bool registerDataSetReaderSync(uint16_t dataSetReaderId, DataSetReaderBase::SPtr& dataSetReader);
		bool deregisterDataSetReaderSync(uint16_t dataSetReaderId);

		bool startupSync(void);
		bool shutdownSync(void);

	  private:
		uint16_t readerGroupId_ = 0;
		std::string messageTransportName_ = "";
		OpcUaStackCore::MessageBusMember::WPtr messageTransportBusMember_;
		
		DataSetReaderBase::Map dataSetReaderMap_;

		bool startup();
		bool shutdown();
		
		bool registerDataSetReader(uint16_t dataSetReaderId, DataSetReaderBase::SPtr& dataSetReader);
		bool deregisterDataSetReader(uint16_t dataSetReaderId);
	};

}

#endif
