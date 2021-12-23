#include "unittest.h"
#include "OpcUaStackCore/StandardDataTypes/ObjectAttributes.h"
#include "OpcUaStackCore/StandardDataTypes/VariableAttributes.h"
#include "OpcUaStackClient/CryptoManagerTest.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

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

	~NodeManagementFixture(){
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

BOOST_AUTO_TEST_CASE(ServiceSetManagerSyncReal_NodeManagement_DeleteNodes)
{
	
	// delete node
	auto trx = boost::make_shared<ServiceTransactionDeleteNodes>();
	auto req = trx->request();

	auto deleteNodesItem1 = boost::make_shared<DeleteNodesItem>();
	deleteNodesItem1->nodeId().set("VariableNode", 1);
	deleteNodesItem1->deleteTargetReferences() = true;

	auto deleteNodesItem2 = boost::make_shared<DeleteNodesItem>();
	deleteNodesItem2->nodeId().set("NodeManagementFolder", 1);
	deleteNodesItem2->deleteTargetReferences() = true;

	req->nodesToDelete()->resize(2);
	req->nodesToDelete()->set(0, deleteNodesItem1);
	req->nodesToDelete()->set(1, deleteNodesItem2);

	nodeManagementService->syncSend(trx);
	DeleteNodesResponse::SPtr res = trx->response();
	BOOST_REQUIRE(trx->statusCode() == Success);
	BOOST_REQUIRE(res->results()->size() == 2);
	BOOST_REQUIRE((*res->results().get())[0]->statusCode() == Success);
	BOOST_REQUIRE((*res->results().get())[1]->statusCode() == Success);
}

BOOST_FIXTURE_TEST_SUITE_END()

#endif
