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

#ifndef __OpcUaStackServer_ApplicationService_h__
#define __OpcUaStackServer_ApplicationService_h__

#include "OpcUaStackCore/ServiceSet/ServiceTransactionIf.h"
#include "OpcUaStackServer/ServiceSetApplication/ApplicationServiceTransaction.h"
#include "OpcUaStackServer/ServiceSet/ServiceSetBase.h"
#include "OpcUaStackServer/ServiceSet/ServerServiceBase.h"

namespace OpcUaStackServer
{

	class DLLEXPORT ApplicationService
	: public ServiceSetBase
	, public OpcUaStackCore::Object
	, public OpcUaStackServer::ServerServiceBase
	{
	  public:
		typedef boost::shared_ptr<ApplicationService> SPtr;

		ApplicationService(
			const std::string& serviceName,
			OpcUaStackCore::IOThread::SPtr& ioThread,
			OpcUaStackCore::MessageBus::SPtr& messageBus
		);
		~ApplicationService(void);

	  private:
		void receive(
			const OpcUaStackCore::MessageBusMember::WPtr& handleFrom,
			OpcUaStackCore::Message::SPtr& message
		);
		void sendAnswer(OpcUaStackCore::ServiceTransaction::SPtr& serviceTransaction);
		void receiveRegisterForwardNodeRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveRegisterForwardNodeAsyncRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveRegisterForwardMethodRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveRegisterForwardMethodAsyncRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveRegisterForwardGlobalRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveGetNodeReferenceRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveNamespaceInfoRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveCreateNodeInstanceRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveDelNodeInstanceRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveFireEventRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveBrowsePathToNodeIdRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveCreateVariableRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveCreateObjectRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void getNodeIdFromBrowsePath(OpcUaStackCore::BrowseName::SPtr& browseName, NodeIdResult::SPtr& nodeIdResult);
	};

}

#endif
