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

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#ifndef __OpcUaStackServer_MethodService_h__
#define __OpcUaStackServer_MethodService_h__

#include "OpcUaStackCore/ServiceSet/MethodServiceTransaction.h"
#include "OpcUaStackServer/ServiceSet/ServiceSetBase.h"
#include "OpcUaStackServer/ServiceSet/ServerServiceBase.h"
#include "OpcUaStackServer/Forward/ForwardManager.h"

namespace OpcUaStackServer
{

	class DLLEXPORT MethodService 
	: public ServiceSetBase
	, public OpcUaStackCore::Object
	, public OpcUaStackServer::ServerServiceBase
	{
	  public:
		typedef boost::shared_ptr<MethodService> SPtr;

		MethodService(
			const std::string& serviceName,
			OpcUaStackCore::IOThread::SPtr& ioThread,
			OpcUaStackCore::MessageBus::SPtr& messageBus
		);
		~MethodService(void);

	  private:
		void receive(
			const OpcUaStackCore::MessageBusMember::WPtr& handleFrom,
			OpcUaStackCore::ServiceTransaction::SPtr& serviceTransaction
		);
		void receive(
			const OpcUaStackCore::MessageBusMember::WPtr& handleFrom,
			OpcUaStackServer::ForwardTransaction::SPtr& forwardTransaction
		);
		void receive(
			const OpcUaStackCore::MessageBusMember::WPtr& handleFrom,
			OpcUaStackCore::Message::SPtr& message
		);
		void sendAnswer(
			OpcUaStackCore::ServiceTransaction::SPtr& serviceTransaction
		);

		// --------------------------------------------------------------------
		//
		// The following functions are used for asynchronously communication
		// with the application.
		//
		// --------------------------------------------------------------------
		void sendTrxForwardAsync(
			ForwardTransaction::SPtr& forwardTransaction
		);
		void recvTrxForwardAsync(
			OpcUaStackCore::OpcUaStatusCode statusCode,
			OpcUaStackCore::ServiceTransaction::SPtr& serviceTransaction,
			ForwardTransaction::SPtr& forwardTransaction
		);
		void finishTrxForwardAsync(
			OpcUaStackCore::ServiceTransaction::SPtr& serviceTransaction
		);

		// --------------------------------------------------------------------
		//
		// read service
		//
		// --------------------------------------------------------------------
		void receiveCallRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		OpcUaStackCore::OpcUaStatusCode forwardAuthorizationMethod(
			OpcUaStackCore::UserContext::SPtr& userContext,
			OpcUaStackCore::OpcUaNodeId& objectNodeId,
			OpcUaStackCore::OpcUaNodeId& funcNodeId
		);
		void forwardCallAsyncResponse(
			OpcUaStackCore::OpcUaStatusCode statusCode,
			OpcUaStackCore::ServiceTransaction::SPtr& serviceTransaction,
			ForwardTransaction::SPtr& forwardTransaction
		);
		bool forwardCallAsync(
			ForwardJob::SPtr& forwardJob,
			OpcUaStackCore::UserContext::SPtr& userContext,
			BaseNodeClass::SPtr baseNodeClass,
			uint32_t idx,
			OpcUaStackCore::ServiceTransactionCall::SPtr& readTrx
		);

		ForwardManager::SPtr forwardManager_;
	};

}

#endif
