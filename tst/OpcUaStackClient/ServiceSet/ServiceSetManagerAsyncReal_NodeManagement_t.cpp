#include "unittest.h"
#include "OpcUaStackCore/Core/Core.h"
#include "OpcUaStackCore/StandardDataTypes/ObjectAttributes.h"
#include "OpcUaStackClient/CryptoManagerTest.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

#ifdef REAL_SERVER

BOOST_AUTO_TEST_SUITE(ServiceSetManagerAsyncReal_NodeManagement_)

struct GValueFixture {
	GValueFixture(void)
    : cond_()
	, sessionState_(SessionServiceStateId::None)
    {}
    ~GValueFixture(void)
    {}

    Condition cond_;
    SessionServiceStateId sessionState_;
};

BOOST_AUTO_TEST_CASE(ServiceSetManagerAsyncReal_NodeManagement_)
{
	std::cout << "ServiceSetManagerAsyncReal_NodeManagement_t" << std::endl;
}

BOOST_FIXTURE_TEST_CASE(ServiceSetManagerAsyncReal_NodeManagement_AddObjectNode, GValueFixture)
{
	Core core;
	ServiceSetManager serviceSetManager;

	core.init();

	//
	// init certificate and crypto manager
	//
	auto cryptoManager = CryptoManagerTest::getInstance();
	BOOST_REQUIRE(cryptoManager.get() != nullptr);

	// set secure channel configuration
	SessionServiceConfig sessionServiceConfig;
	sessionServiceConfig.secureChannelClient_->endpointUrl(REAL_SERVER_URI);
	sessionServiceConfig.secureChannelClient_->cryptoManager(cryptoManager);
	sessionServiceConfig.session_->sessionName(REAL_SESSION_NAME);
	sessionServiceConfig.sessionServiceChangeHandler_ =
		[this] (SessionBase& session, SessionServiceStateId sessionState) {
			if (sessionState == SessionServiceStateId::Established ||
				sessionState == SessionServiceStateId::Disconnected) {
				sessionState_ = sessionState;
				cond_.sendEvent();
			}
		};

	// create session
	auto sessionService = serviceSetManager.sessionService(sessionServiceConfig);
	BOOST_REQUIRE(sessionService.get() != nullptr);

	// connect secure channel
	cond_.condition(1,0);
	sessionService->asyncConnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Established);

	// create nodeManagement service
	NodeManagementServiceConfig nodeManagementServiceConfig;
	auto nodeManagementService = serviceSetManager.nodeManagementService(sessionService, nodeManagementServiceConfig);
	BOOST_REQUIRE(nodeManagementService.get() != nullptr);

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
	objectAttributes->writeMask() = 3;
	objectAttributes->userWriteMask() = 3;
	// object specific attributes
	objectAttributes->eventNotifier() = false;

	req->nodesToAdd()->set(addNodesItem);

	cond_.condition(1,0);
	trx->resultHandler(
		[this](ServiceTransactionAddNodes::SPtr& trx) {
			cond_.conditionValueDec();
		}
	);
	nodeManagementService->asyncSend(trx);
	cond_.waitForCondition(1000);
	AddNodesResponse::SPtr res = trx->response();
	BOOST_REQUIRE(trx->statusCode() == Success);
	BOOST_REQUIRE(res->results()->size() == 1);

	// disconnect secure channel
	cond_.condition(1,0);
	sessionService->asyncDisconnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Disconnected);
}


BOOST_AUTO_TEST_SUITE_END()

#endif
