#include "unittest.h"
#include "OpcUaStackCore/StandardDataTypes/ObjectAttributes.h"
#include "OpcUaStackCore/StandardDataTypes/VariableAttributes.h"
#include "OpcUaStackCore/StandardDataTypes/MethodAttributes.h"
#include "OpcUaStackCore/StandardDataTypes/ObjectTypeAttributes.h"
#include "OpcUaStackCore/StandardDataTypes/VariableTypeAttributes.h"
#include "OpcUaStackCore/StandardDataTypes/DataTypeAttributes.h"
#include "OpcUaStackCore/StandardDataTypes/ReferenceTypeAttributes.h"
#include "OpcUaStackClient/CryptoManagerTest.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;
namespace utf = boost::unit_test;

#ifdef REAL_SERVER

struct NodeManagementFixture {

	NodeManagementFixture(){
		
		CryptoManager::SPtr cryptoManager = CryptoManagerTest::getInstance();
		BOOST_REQUIRE(cryptoManager.get() != nullptr);

		// set secure channel configuration
		SessionServiceConfig sessionServiceConfig;
		sessionServiceConfig.secureChannelClient_->endpointUrl(REAL_SERVER_URI);
		sessionServiceConfig.secureChannelClient_->cryptoManager(cryptoManager);
		sessionServiceConfig.session_->sessionName(REAL_SESSION_NAME);

		// create session
		sessionService = serviceSetManager.sessionService(sessionServiceConfig);
		BOOST_REQUIRE(sessionService.get() != nullptr);

		// connect secure channel
		BOOST_REQUIRE(sessionService->syncConnect() == Success);

		// create nodeManagement service
		NodeManagementServiceConfig nodeManagementServiceConfig;
		nodeManagementService = serviceSetManager.nodeManagementService(sessionService, nodeManagementServiceConfig);
		BOOST_REQUIRE(nodeManagementService.get() != nullptr);
	}

	~NodeManagementFixture() {
		// disconnect secure channel
		BOOST_REQUIRE(sessionService->syncDisconnect() == Success);
	}

	ServiceSetManager serviceSetManager;
	SessionService::SPtr sessionService;
	NodeManagementService::SPtr nodeManagementService;

};

//create fixture and build the code and run these tests first and then write one by one
BOOST_FIXTURE_TEST_SUITE(ServiceSetManagerSyncReal_NodeManagement_, NodeManagementFixture)

BOOST_AUTO_TEST_CASE(ServiceSetManagerSyncReal_NodeManagement_)
{
	std::cout << "ServiceSetManagerSyncReal_NodeManagement_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(ServiceSetManagerSyncReal_NodeManagement_AddObjectNode)
{
	std::cout << "AddObjectNode Test Case" << std::endl;
	// create object node
	auto trx = boost::make_shared<ServiceTransactionAddNodes>();
	auto req = trx->request();

	auto addNodesItem = boost::make_shared<AddNodesItem>();
	addNodesItem->parentNodeId().set(OpcUaId_ObjectsFolder);
	addNodesItem->referenceTypeId().set(OpcUaId_Organizes);
	addNodesItem->requestedNewNodeId().set("NodeManagementFolder", 1);
	addNodesItem->browseName().set("NodeManagementFolder", 1);
	addNodesItem->nodeClass() = NodeClass::EnumObject;
	addNodesItem->typeDefinition().set(OpcUaId_BaseObjectType);

	auto objectAttributes = addNodesItem->nodeAttributes().parameter<ObjectAttributes>(OpcUaNodeId(OpcUaId_ObjectAttributes));
	BOOST_REQUIRE(objectAttributes.get() != nullptr);
	// base attributes
	objectAttributes->displayName().set("de", "NodeManagementFolder");
	objectAttributes->description().set("de", "test folder");
	objectAttributes->writeMask() = 0;
	objectAttributes->userWriteMask() = 0;
	// object specific attributes
	objectAttributes->eventNotifier() = false;

	req->nodesToAdd()->set(addNodesItem);

	nodeManagementService->syncSend(trx);
	AddNodesResponse::SPtr res = trx->response();
	BOOST_REQUIRE(trx->statusCode() == Success);
	BOOST_REQUIRE(res->results()->size() == 1);
	BOOST_REQUIRE((*res->results().get())[0]->statusCode() == Success);

}

BOOST_AUTO_TEST_CASE(ServiceSetManagerSyncReal_NodeManagement_AddVariableNode)
{

	std::cout << "AddVariableNode Test Case" << std::endl;

	// create variable node
	auto trx = boost::make_shared<ServiceTransactionAddNodes>();
	auto req = trx->request();

	auto addNodesItem = boost::make_shared<AddNodesItem>();
	addNodesItem->parentNodeId().set("NodeManagementFolder", 1);
	addNodesItem->referenceTypeId().set(OpcUaId_HasComponent);
	addNodesItem->requestedNewNodeId().set("VariableNode", 1);
	addNodesItem->browseName().set("VariableNode", 1);
	addNodesItem->nodeClass() = NodeClass::EnumVariable;
	addNodesItem->typeDefinition().set(OpcUaId_BaseVariableType);

	auto variableAttributes = addNodesItem->nodeAttributes().parameter<VariableAttributes>(OpcUaNodeId(OpcUaId_VariableAttributes));
	BOOST_REQUIRE(variableAttributes.get() != nullptr);
	// base attributes
	variableAttributes->displayName().set("de", "VariableNode");
	variableAttributes->description().set("de", "test variable");
	variableAttributes->writeMask() = 0;
	variableAttributes->userWriteMask() = 0;
	// object specific attributes
	variableAttributes->value().set((uint32_t)1234);
	variableAttributes->dataType().set(OpcUaId_UInt32);
	variableAttributes->valueRank() = 0;
	variableAttributes->arrayDimensions();
	variableAttributes->accessLevel() = 3;
	variableAttributes->userAccessLevel() = 3;
	variableAttributes->minimumSamplingInterval() = 1000;
	variableAttributes->historizing() = false;

	req->nodesToAdd()->set(addNodesItem);

	nodeManagementService->syncSend(trx);
	AddNodesResponse::SPtr res = trx->response();
	BOOST_REQUIRE(trx->statusCode() == Success);
	BOOST_REQUIRE(res->results()->size() == 1);
	BOOST_REQUIRE((*res->results().get())[0]->statusCode() == Success);

}

BOOST_AUTO_TEST_CASE(ServiceSetManagerSyncReal_NodeManagement_AddMethodNode)
{
	std::cout << "AddMethodNode Test Case" << std::endl;
	// create  node
	auto trx = boost::make_shared<ServiceTransactionAddNodes>();
	auto req = trx->request();

	auto addNodesItem = boost::make_shared<AddNodesItem>();
	addNodesItem->parentNodeId().set("NodeManagementFolder", 1);
	addNodesItem->referenceTypeId().set(OpcUaId_HasComponent);
	addNodesItem->requestedNewNodeId().set("MethodNode", 1);
	addNodesItem->browseName().set("MethodNode", 1);
	addNodesItem->nodeClass() = NodeClass::EnumMethod;
	addNodesItem->typeDefinition().setNull();

	auto methodAttributes = addNodesItem->nodeAttributes().parameter<MethodAttributes>(OpcUaNodeId(OpcUaId_MethodAttributes));
	BOOST_REQUIRE(methodAttributes.get() != nullptr);
	// base attributes
	methodAttributes->displayName().set("de", "MethodNode");
	methodAttributes->description().set("de", "test method");
	methodAttributes->writeMask() = 0;
	methodAttributes->userWriteMask() = 0;
	
	// object specific attributes
	methodAttributes->executable() = false;
	methodAttributes->userExecutable() = false;
	

	req->nodesToAdd()->set(addNodesItem);

	nodeManagementService->syncSend(trx);
	AddNodesResponse::SPtr res = trx->response();
	BOOST_REQUIRE(trx->statusCode() == Success);
	BOOST_REQUIRE(res->results()->size() == 1);
	BOOST_REQUIRE((*res->results().get())[0]->statusCode() == Success);

}

BOOST_AUTO_TEST_CASE(ServiceSetManagerSyncReal_NodeManagement_AddObjectTypeNode)
{

	std::cout << "AddObjectTypeNode Test Case" << std::endl;
	// create  node
	auto trx = boost::make_shared<ServiceTransactionAddNodes>();
	auto req = trx->request();

	auto addNodesItem = boost::make_shared<AddNodesItem>();
	addNodesItem->parentNodeId().set("NodeManagementFolder", 1);
	addNodesItem->referenceTypeId().set(OpcUaId_HasSubtype);
	addNodesItem->requestedNewNodeId().set("ObjectTypeNode", 1);
	addNodesItem->browseName().set("ObjectTypeNode", 1);
	addNodesItem->nodeClass() = NodeClass::EnumObjectType;
	addNodesItem->typeDefinition().setNull();

	auto objectTypeAttributes = addNodesItem->nodeAttributes().parameter<ObjectTypeAttributes>(OpcUaNodeId(OpcUaId_ObjectTypeAttributes));
	BOOST_REQUIRE(objectTypeAttributes.get() != nullptr);
	// base attributes
	objectTypeAttributes->displayName().set("de", "ObjectTypeNode");
	objectTypeAttributes->description().set("de", "test object type");
	objectTypeAttributes->writeMask() = 0;
	objectTypeAttributes->userWriteMask() = 0;
	
	// object specific attributes
	objectTypeAttributes->isAbstract() = false;
	

	req->nodesToAdd()->set(addNodesItem);

	nodeManagementService->syncSend(trx);
	AddNodesResponse::SPtr res = trx->response();
	BOOST_REQUIRE(trx->statusCode() == Success);
	BOOST_REQUIRE(res->results()->size() == 1);
	BOOST_REQUIRE((*res->results().get())[0]->statusCode() == Success);

}

BOOST_AUTO_TEST_CASE(ServiceSetManagerSyncReal_NodeManagement_AddVariableTypeNode)
{

	std::cout << "AddVariableTypeNode Test Case" << std::endl;

	// create  node
	auto trx = boost::make_shared<ServiceTransactionAddNodes>();
	auto req = trx->request();

	auto addNodesItem = boost::make_shared<AddNodesItem>();
	addNodesItem->parentNodeId().set("NodeManagementFolder", 1);
	addNodesItem->referenceTypeId().set(OpcUaId_HasSubtype);
	addNodesItem->requestedNewNodeId().set("VariableTypeNode", 1);
	addNodesItem->browseName().set("VariableTypeNode", 1);
	addNodesItem->nodeClass() = NodeClass::EnumVariableType;
	addNodesItem->typeDefinition().setNull();

	auto variableTypeAttributes = addNodesItem->nodeAttributes().parameter<VariableTypeAttributes>(OpcUaNodeId(OpcUaId_VariableTypeAttributes));
	BOOST_REQUIRE(variableTypeAttributes.get() != nullptr);
	// base attributes
	variableTypeAttributes->displayName().set("de", "VariableTypeNode");
	variableTypeAttributes->description().set("de", "test vatiable type");
	variableTypeAttributes->writeMask() = 0;
	variableTypeAttributes->userWriteMask() = 0;
	
	// object specific attributes
	variableTypeAttributes->value().set((uint32_t)1234);
	variableTypeAttributes->dataType().set(OpcUaId_UInt32);
	variableTypeAttributes->valueRank() = -1;
	variableTypeAttributes->isAbstract() = false;

	req->nodesToAdd()->set(addNodesItem);

	nodeManagementService->syncSend(trx);
	AddNodesResponse::SPtr res = trx->response();
	BOOST_REQUIRE(trx->statusCode() == Success);
	BOOST_REQUIRE(res->results()->size() == 1);
	BOOST_REQUIRE((*res->results().get())[0]->statusCode() == Success);
}

BOOST_AUTO_TEST_CASE(ServiceSetManagerSyncReal_NodeManagement_AddDataTypeNode)
{

	std::cout << "AddDataTypeNode Test Case" << std::endl;

	// create  node
	auto trx = boost::make_shared<ServiceTransactionAddNodes>();
	auto req = trx->request();

	auto addNodesItem = boost::make_shared<AddNodesItem>();
	addNodesItem->parentNodeId().set("NodeManagementFolder", 1);
	addNodesItem->referenceTypeId().set(OpcUaId_HasSubtype);
	addNodesItem->requestedNewNodeId().set("DataTypeNode", 1);
	addNodesItem->browseName().set("DataTypeNode", 1);
	addNodesItem->nodeClass() = NodeClass::EnumDataType;
	addNodesItem->typeDefinition().setNull();

	auto dataTypeAttributes = addNodesItem->nodeAttributes().parameter<DataTypeAttributes>(OpcUaNodeId(OpcUaId_DataTypeAttributes));
	BOOST_REQUIRE(dataTypeAttributes.get() != nullptr);
	// base attributes
	dataTypeAttributes->displayName().set("de", "DataTypeNode");
	dataTypeAttributes->description().set("de", "test data type");
	dataTypeAttributes->writeMask() = 0;
	dataTypeAttributes->userWriteMask() = 0;

	// object specific attributes
	dataTypeAttributes->isAbstract() = false;

	req->nodesToAdd()->set(addNodesItem);

	nodeManagementService->syncSend(trx);
	AddNodesResponse::SPtr res = trx->response();
	BOOST_REQUIRE(trx->statusCode() == Success);
	BOOST_REQUIRE(res->results()->size() == 1);
	BOOST_REQUIRE((*res->results().get())[0]->statusCode() == Success);

}

BOOST_AUTO_TEST_CASE(ServiceSetManagerSyncReal_NodeManagement_AddReferenceTypeNode)
{
	std::cout << "AddReferenceTypeNode Test Case" << std::endl;
	// create  node
	auto trx = boost::make_shared<ServiceTransactionAddNodes>();
	auto req = trx->request();

	auto addNodesItem = boost::make_shared<AddNodesItem>();
	addNodesItem->parentNodeId().set("NodeManagementFolder", 1);
	addNodesItem->referenceTypeId().set(OpcUaId_HasSubtype);
	addNodesItem->requestedNewNodeId().set("ReferenceTypeNode", 1);
	addNodesItem->browseName().set("ReferenceTypeNode", 1);
	addNodesItem->nodeClass() = NodeClass::EnumReferenceType;
	addNodesItem->typeDefinition().setNull();

	auto referenceTypeAttributes = addNodesItem->nodeAttributes().parameter<ReferenceTypeAttributes>(OpcUaNodeId(OpcUaId_ReferenceTypeAttributes));
	BOOST_REQUIRE(referenceTypeAttributes.get() != nullptr);
	// base attributes
	referenceTypeAttributes->displayName().set("de", "ReferenceTypeNode");
	referenceTypeAttributes->description().set("de", "test reference type");
	referenceTypeAttributes->writeMask() = 0;
	referenceTypeAttributes->userWriteMask() = 0;
	
	// object specific attributes
	referenceTypeAttributes->isAbstract() = false;
	referenceTypeAttributes->symmetric() = true;
	
	req->nodesToAdd()->set(addNodesItem);

	nodeManagementService->syncSend(trx);
	AddNodesResponse::SPtr res = trx->response();
	BOOST_REQUIRE(trx->statusCode() == Success);
	BOOST_REQUIRE(res->results()->size() == 1);
	BOOST_REQUIRE((*res->results().get())[0]->statusCode() == Success);
}

BOOST_AUTO_TEST_CASE(ServiceSetManagerSyncReal_NodeManagement_AddReferences)
{
	std::cout << "AddReferences Test Case" << std::endl;
	// create  node
	auto trx = boost::make_shared<ServiceTransactionAddReferences>();
	auto req = trx->request();

	auto addReferencesItem = boost::make_shared<AddReferencesItem>();
	addReferencesItem->sourceNodeId().set("VariableNode", 1);
	addReferencesItem->targetNodeId().set("NodeManagementFolder", 1);
	addReferencesItem->referenceTypeId().set(OpcUaId_HasEventSource);
	addReferencesItem->isForward() == true;
	addReferencesItem->targetNodeClass() = NodeClass::EnumObject;

	req->referencesToAdd()->set(addReferencesItem);

	nodeManagementService->syncSend(trx);
	AddReferencesResponse::SPtr res = trx->response();
	BOOST_REQUIRE(trx->statusCode() == Success);
	BOOST_REQUIRE(res->results()->size() == 1);
	BOOST_REQUIRE((*res->results().get())[0]->statusCode() == Success);
}

BOOST_AUTO_TEST_CASE(ServiceSetManagerSyncReal_NodeManagement_DeleteReferences)
{
	std::cout << "DeleteReferences Test Case" << std::endl;

	//delete reference request
	auto trx = boost::make_shared<ServiceTransactionDeleteReferences>();
	auto req = trx->request();

	auto deleteReferemcesItem = boost::make_shared<DeleteReferencesItem>();
	deleteReferemcesItem->sourceNodeId().set("VariableNode", 1);
	deleteReferemcesItem->referenceTypeId().set(OpcUaId_HasEventSource);
	deleteReferemcesItem->isForward() = true;
	deleteReferemcesItem->targetNodeId().set("NodeManagementFolder", 1);
	deleteReferemcesItem->deleteBidirectional() = true;

	req->referencesToDelete()->set(deleteReferemcesItem);

	nodeManagementService->syncSend(trx);
	DeleteReferencesResponse::SPtr res = trx->response();
	BOOST_REQUIRE(trx->statusCode() == Success);
	BOOST_REQUIRE(res->results()->size() == 1);
	BOOST_REQUIRE((*res->results().get())[0]->statusCode() == Success);
}

BOOST_AUTO_TEST_CASE(ServiceSetManagerSyncReal_NodeManagement_Add_Delete_ReferenceRequest)
{
	
	// create  forward Reference
	auto trx = boost::make_shared<ServiceTransactionAddReferences>();
	auto req = trx->request();

	auto addReferencesItem = boost::make_shared<AddReferencesItem>();
	addReferencesItem->sourceNodeId().set("NodeManagementFolder", 1);
	addReferencesItem->referenceTypeId().set(OpcUaId_HasComponent);
	addReferencesItem->isForward() = true;
	addReferencesItem->targetNodeId().set("VariableNode", 1);
	addReferencesItem->targetNodeClass().enumeration(NodeClass::EnumVariable);


	req->referencesToAdd()->set(addReferencesItem);

	nodeManagementService->syncSend(trx);
	AddReferencesResponse::SPtr res = trx->response();
	BOOST_REQUIRE(trx->statusCode() == Success);
	BOOST_REQUIRE(res->results()->size() == 1);
	BOOST_REQUIRE((*res->results().get())[0]->statusCode() == Success);


	// create  inverse Reference
	auto trx_1 = boost::make_shared<ServiceTransactionAddReferences>();
	auto req_1 = trx_1->request();

	auto addReferencesItem_1= boost::make_shared<AddReferencesItem>();
	addReferencesItem_1->sourceNodeId().set("NodeManagementFolder", 1);
	addReferencesItem_1->referenceTypeId().set(OpcUaId_HasComponent);
	addReferencesItem_1->isForward() = false;
	addReferencesItem_1->targetNodeId().set("VariableNode", 1);
	addReferencesItem_1->targetNodeClass().enumeration(NodeClass::EnumVariable);


	req_1->referencesToAdd()->set(addReferencesItem_1);

	nodeManagementService->syncSend(trx_1);
	AddReferencesResponse::SPtr res_1 = trx_1->response();
	BOOST_REQUIRE(trx_1->statusCode() == Success);
	BOOST_REQUIRE(res_1->results()->size() == 1);
	BOOST_REQUIRE((*res_1->results().get())[0]->statusCode() == Success);


	// create  forward Reference with invalid target Node Class
	auto trx_2 = boost::make_shared<ServiceTransactionAddReferences>();
	auto req_2 = trx_2->request();

	auto addReferencesItem_2= boost::make_shared<AddReferencesItem>();
	addReferencesItem_2->sourceNodeId().set("NodeManagementFolder", 1);
	addReferencesItem_2->referenceTypeId().set(OpcUaId_HasComponent);
	addReferencesItem_2->isForward() = true;
	addReferencesItem_2->targetNodeId().set("VariableNode", 1);
	addReferencesItem_2->targetNodeClass().enumeration(NodeClass::EnumObject);


	req_2->referencesToAdd()->set(addReferencesItem_2);

	nodeManagementService->syncSend(trx_2);
	AddReferencesResponse::SPtr res_2 = trx_2->response();
	BOOST_REQUIRE(trx_2->statusCode() == Success);
	BOOST_REQUIRE(res_2->results()->size() == 1);
	BOOST_REQUIRE((*res_2->results().get())[0]->statusCode() == BadNodeClassInvalid);

	//delete reference request
	auto trx_3 = boost::make_shared<ServiceTransactionDeleteReferences>();
	auto req_3 = trx_3->request();

	auto deleteReferemcesItem = boost::make_shared<DeleteReferencesItem>();
	deleteReferemcesItem->sourceNodeId().set("NodeManagementFolder", 1);
	deleteReferemcesItem->referenceTypeId().set(OpcUaId_HasComponent);
	deleteReferemcesItem->isForward() = true;
	deleteReferemcesItem->targetNodeId().set("VariableNode", 1);
	deleteReferemcesItem->deleteBidirectional() = true;
	
	req_3->referencesToDelete()->set(deleteReferemcesItem);

	nodeManagementService->syncSend(trx_3);
	DeleteReferencesResponse::SPtr res_3 = trx_3->response();
	BOOST_REQUIRE(trx_3->statusCode() == Success);
	BOOST_REQUIRE(res_3->results()->size() == 1);
	BOOST_REQUIRE((*res_3->results().get())[0]->statusCode() == Success);
}


BOOST_AUTO_TEST_CASE(ServiceSetManagerSyncReal_NodeManagement_DeleteNodes)
{
	std::cout << "Running 8 DeleteNodes Test Case" << std::endl;
	// delete node
	auto trx = boost::make_shared<ServiceTransactionDeleteNodes>();
	auto req = trx->request();

	auto deleteNodesItem1 = boost::make_shared<DeleteNodesItem>();
	deleteNodesItem1->nodeId().set("VariableNode", 1);
	deleteNodesItem1->deleteTargetReferences() = true;

	auto deleteNodesItem2 = boost::make_shared<DeleteNodesItem>();
	deleteNodesItem2->nodeId().set("MethodNode", 1);
	deleteNodesItem2->deleteTargetReferences() = true;

	auto deleteNodesItem3 = boost::make_shared<DeleteNodesItem>();
	deleteNodesItem3->nodeId().set("ObjectTypeNode", 1);
	deleteNodesItem3->deleteTargetReferences() = true;

	auto deleteNodesItem4 = boost::make_shared<DeleteNodesItem>();
	deleteNodesItem4->nodeId().set("VariableTypeNode", 1);
	deleteNodesItem4->deleteTargetReferences() = true;

	auto deleteNodesItem5 = boost::make_shared<DeleteNodesItem>();
	deleteNodesItem5->nodeId().set("ReferenceTypeNode", 1);
	deleteNodesItem5->deleteTargetReferences() = true;

	auto deleteNodesItem6 = boost::make_shared<DeleteNodesItem>();
	deleteNodesItem6->nodeId().set("NodeManagementFolder", 1);
	deleteNodesItem6->deleteTargetReferences() = true;

	auto deleteNodesItem7 = boost::make_shared<DeleteNodesItem>();
	deleteNodesItem7->nodeId().set("DataTypeNode", 1);
	deleteNodesItem7->deleteTargetReferences() = true;

	req->nodesToDelete()->resize(7);
	req->nodesToDelete()->set(0, deleteNodesItem1);
	req->nodesToDelete()->set(1, deleteNodesItem2);
	req->nodesToDelete()->set(2, deleteNodesItem3);
	req->nodesToDelete()->set(3, deleteNodesItem4);
	req->nodesToDelete()->set(4, deleteNodesItem5);
	req->nodesToDelete()->set(5, deleteNodesItem6);
	req->nodesToDelete()->set(6, deleteNodesItem7);

	nodeManagementService->syncSend(trx);
	DeleteNodesResponse::SPtr res = trx->response();
	BOOST_REQUIRE(trx->statusCode() == Success);
	BOOST_REQUIRE(res->results()->size() == 7);

	for (uint8_t i = 0; i < 7; ++i) {
		BOOST_REQUIRE((*res->results().get())[i]->statusCode() == Success);
	}
}

BOOST_AUTO_TEST_SUITE_END()

#endif
