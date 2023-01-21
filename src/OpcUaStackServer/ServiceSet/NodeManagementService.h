/*
   Copyright 2015-2023 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_NodeManagementService_h__
#define __OpcUaStackServer_NodeManagementService_h__

#include "OpcUaStackCore/ServiceSet/ServiceTransactionIf.h"
#include "OpcUaStackCore/ServiceSet/NodeManagementServiceTransaction.h"
#include "OpcUaStackServer/ServiceSet/ServiceSetBase.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"
#include "OpcUaStackServer/ServiceSet/ServerServiceBase.h"

namespace OpcUaStackServer
{

	class DLLEXPORT NodeManagementService 
	: public ServiceSetBase
	, public OpcUaStackCore::Object
	, public OpcUaStackServer::ServerServiceBase
	{
	  public:
		typedef boost::shared_ptr<NodeManagementService> SPtr;

		NodeManagementService(
			const std::string& serviceName,
			OpcUaStackCore::IOThread::SPtr& ioThread,
			OpcUaStackCore::MessageBus::SPtr& messageBus
		);
		~NodeManagementService(void);

	  private:
		void receive(
			const OpcUaStackCore::MessageBusMember::WPtr& handleFrom,
			OpcUaStackCore::Message::SPtr& message
		);
		void sendAnswer(OpcUaStackCore::ServiceTransaction::SPtr& serviceTransaction);
		void receiveAddNodesRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveAddReferencesRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveDeleteNodesRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveDeleteReferencesRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);

		OpcUaStackCore::OpcUaStatusCode addNodeAndReference(
			uint32_t pos,
			BaseNodeClass::SPtr baseNodeClass,
			OpcUaStackCore::AddNodesItem::SPtr& addNodesItem
		);
		OpcUaStackCore::OpcUaStatusCode addNode(
			uint32_t,
			BaseNodeClass::SPtr baseNodeClass
		);
		OpcUaStackCore::OpcUaStatusCode addNode(
			uint32_t pos,
			OpcUaStackCore::AddNodesItem::SPtr addNodesItem,
			OpcUaStackCore::AddNodesResult::SPtr addNodesResult
		);
		
		OpcUaStackCore::OpcUaStatusCode deleteNode(
			uint32_t pos,
			OpcUaStackCore::DeleteNodesItem::SPtr deleteNodesItem,
			OpcUaStackCore::DeleteNodesResult::SPtr deleteNodesResult
		);
		OpcUaStackCore::OpcUaStatusCode addBaseNodeClass(
			uint32_t pos,
			BaseNodeClass::SPtr baseNodeClass,
			OpcUaStackCore::AddNodesItem::SPtr addNodesItem,
			OpcUaStackCore::AddNodesResult::SPtr addNodesResult
		);
		OpcUaStackCore::OpcUaStatusCode addNodeObject(
			uint32_t pos,
			OpcUaStackCore::AddNodesItem::SPtr addNodesItem,
			OpcUaStackCore::AddNodesResult::SPtr addNodesResult
		);
		OpcUaStackCore::OpcUaStatusCode addNodeVariable(
			uint32_t pos,
			OpcUaStackCore::AddNodesItem::SPtr addNodesItem,
			OpcUaStackCore::AddNodesResult::SPtr addNodesResult
		);
		OpcUaStackCore::OpcUaStatusCode addNodeMethod(
			uint32_t pos,
			OpcUaStackCore::AddNodesItem::SPtr addNodesItem,
			OpcUaStackCore::AddNodesResult::SPtr addNodesResult
		);
		OpcUaStackCore::OpcUaStatusCode addNodeObjectType(
			uint32_t pos,
			OpcUaStackCore::AddNodesItem::SPtr addNodesItem,
			OpcUaStackCore::AddNodesResult::SPtr addNodesResult
		);
		OpcUaStackCore::OpcUaStatusCode addNodeVariableType(
			uint32_t pos,
			OpcUaStackCore::AddNodesItem::SPtr addNodesItem,
			OpcUaStackCore::AddNodesResult::SPtr addNodesResult
		);
		OpcUaStackCore::OpcUaStatusCode addNodeReferenceType(
			uint32_t pos,
			OpcUaStackCore::AddNodesItem::SPtr addNodesItem,
			OpcUaStackCore::AddNodesResult::SPtr addNodesResult
		);
		OpcUaStackCore::OpcUaStatusCode addNodeDataType(
			uint32_t pos,
			OpcUaStackCore::AddNodesItem::SPtr addNodesItem,
			OpcUaStackCore::AddNodesResult::SPtr addNodesResult
		);
		OpcUaStackCore::OpcUaStatusCode	deleteReference(
			uint32_t pos,
			OpcUaStackCore::DeleteReferencesItem::SPtr deleteReferencesItem,
			OpcUaStackCore::DeleteReferencesResult::SPtr deleteReferencesResult
		);
	};

}

#endif
