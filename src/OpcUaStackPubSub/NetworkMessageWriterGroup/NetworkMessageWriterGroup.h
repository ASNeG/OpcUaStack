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

#ifndef __OpcUaStackPubSub_NetworkMessageWriterGroup_h__
#define __OpcUaStackPubSub_NetworkMessageWriterGroup_h__

#include <boost/asio.hpp>

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/ServiceSet/ServerServiceBase.h"
#include "OpcUaStackPubSub/DataSetWriter/DataSetWriterBase.h"

namespace OpcUaStackPubSub
{

	class DLLEXPORT NetworkMessageWriterGroup
	: public OpcUaStackCore::Object
	, public OpcUaStackServer::ServerServiceBase
	{
	  public:
		typedef boost::shared_ptr<NetworkMessageWriterGroup> SPtr;

		NetworkMessageWriterGroup(
			const std::string& writerGroupName,
			const std::string& messageTransportName,
			OpcUaStackCore::IOThread::SPtr& ioThread,
			OpcUaStackCore::MessageBus::SPtr& messageBus
		);
		virtual ~NetworkMessageWriterGroup(void);

		void writerGroupId(uint16_t writerGroupId);
		bool registerDataSetWriterSync(uint16_t dataSetWriterId, DataSetWriterBase::SPtr& dataSetWriter);
		bool deregisterDataSetWriterSync(uint16_t dataSetWriterId);

		bool startupSync(void);
		bool shutdownSync(void);

	  public:
		uint16_t writerGroupId_ = 0;
		std::string messageTransportName_ = "";
		OpcUaStackCore::MessageBusMember::WPtr messageTransportBusMember_;

		DataSetWriterBase::Map dataSetWriterMap_;

		bool registerDataSetWriter(uint16_t dataSetWriterId, DataSetWriterBase::SPtr& dataSetWriter);
		bool deregisterDataSetWriter(uint16_t dataSetWriterId);
		void publishLoop(void);
	};

}

#endif
