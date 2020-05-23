/*
   Copyright 2015-2020 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de), , Aleksey Timin (atimin@gmail.com)
 */

#ifndef __OpcUaStackServer_AttributeService_h__
#define __OpcUaStackServer_AttributeService_h__

#include "OpcUaStackCore/ServiceSet/ServiceTransactionIf.h"
#include "OpcUaStackCore/ServiceSet/AttributeServiceTransaction.h"
#include "OpcUaStackCore/StandardDataTypes/UpdateStructureDataDetails.h"
#include "OpcUaStackServer/ServiceSet/ServiceSetBase.h"
#include "OpcUaStackServer/ServiceSet/ServerServiceBase.h"

namespace OpcUaStackServer
{

	class DLLEXPORT AttributeService 
	: public ServiceSetBase
	, public OpcUaStackCore::Object
	, public OpcUaStackServer::ServerServiceBase
	{
	  public:
		typedef boost::shared_ptr<AttributeService> SPtr;

		AttributeService(
			const std::string& serviceName,
			OpcUaStackCore::IOThread::SPtr& ioThread,
			OpcUaStackCore::MessageBus::SPtr& messageBus
		);
		~AttributeService(void);

	  private:
		void receive(
			const OpcUaStackCore::MessageBusMember::WPtr& handleFrom,
			OpcUaStackCore::Message::SPtr& message
		);

		void sendAnswer(OpcUaStackCore::ServiceTransaction::SPtr& serviceTransaction);
		void receiveReadRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void forwardRead(
			OpcUaStackCore::UserContext::SPtr& userContext,
			BaseNodeClass::SPtr baseNodeClass,
			OpcUaStackCore::ReadRequest::SPtr readRequest,
			OpcUaStackCore::ReadValueId::SPtr readValueId
		);
		OpcUaStackCore::OpcUaStatusCode forwardAuthorizationRead(OpcUaStackCore::UserContext::SPtr& userContext, OpcUaStackCore::ReadValueId::SPtr& readValueId);
		void receiveWriteRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		OpcUaStackCore::OpcUaStatusCode forwardWrite(
			OpcUaStackCore::UserContext::SPtr& userContext,
			BaseNodeClass::SPtr baseNodeClass,
			OpcUaStackCore::WriteRequest::SPtr writeRequest,
			OpcUaStackCore::WriteValue::SPtr writeValue
		);
		OpcUaStackCore::OpcUaStatusCode forwardAuthorizationWrite(OpcUaStackCore::UserContext::SPtr& userContext, OpcUaStackCore::WriteValue::SPtr& writeValue);
		void receiveHistoryReadRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveHistoryReadRawRequest(
			OpcUaStackCore::ServiceTransaction::SPtr& serviceTransaction,
			OpcUaStackCore::ServiceTransactionHistoryRead::SPtr& trx,
			OpcUaStackCore::HistoryReadRequest::SPtr readRequest,
			OpcUaStackCore::HistoryReadResponse::SPtr readResponse
		);
		void receiveHistoryReadEventRequest(
			OpcUaStackCore::ServiceTransaction::SPtr& serviceTransaction,
			OpcUaStackCore::ServiceTransactionHistoryRead::SPtr& trx,
			OpcUaStackCore::HistoryReadRequest::SPtr readRequest,
			OpcUaStackCore::HistoryReadResponse::SPtr readResponse
		);
		OpcUaStackCore::OpcUaStatusCode forwardAuthorizationHistoricalRead(OpcUaStackCore::UserContext::SPtr& userContext, OpcUaStackCore::HistoryReadValueId::SPtr& readValueId);
		void receiveHistoryUpdateRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		OpcUaStackCore::OpcUaStatusCode forwardAuthorizationHistoricalWrite(OpcUaStackCore::UserContext::SPtr& userContext, OpcUaStackCore::UpdateStructureDataDetails::SPtr& updateStructureDataDetails);
	};

}

#endif
