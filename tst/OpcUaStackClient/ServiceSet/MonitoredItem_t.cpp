#include "unittest.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackClient/Client/Client.h"
#include "OpcUaStackClient/ServiceSet/SessionTestHandler.h"
#include "OpcUaStackClient/ServiceSet/SubscriptionService.h"
#include "OpcUaStackClient/ServiceSet/MonitoredItemService.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

BOOST_AUTO_TEST_SUITE(MonitoredItem_)

BOOST_AUTO_TEST_CASE(MonitoredItem_)
{
	std::cout << "MonitoredItem_t" << std::endl;
}

#if 0
BOOST_AUTO_TEST_CASE(MonitoredItem_create_delete_sync)
{
	SessionTestHandler sessionTestHandler;
	MonitoredItemHandler monitoredItemHandler;

	Client client;
	client.init();
	client.start();

	Config sessionConfig;
	sessionConfig.setValue("TestConfig.EndpointUrl", "opc.tcp://127.0.0.1:8888");
	sessionConfig.setValue("TestConfig.SessionName", "urn:127.0.0.1:Company:MyAppl");
	sessionConfig.setValue("TestConfig.ApplicationDescription.ApplicationUri", "urn:127.0.0.1:Company:MyAppl");
	sessionConfig.setValue("TestConfig.ApplicationDescription.ProductUri", "urn:Company:MyAppl");
	sessionConfig.setValue("TestConfig.ApplicationDescription.ApplicationName.Locale", "en");
	sessionConfig.setValue("TestConfig.ApplicationDescription.ApplicationName.Text", "MyAppl");

	Config secureChannelConfig;
	secureChannelConfig.setValue("TestConfig.EndpointUrl", "opc.tcp://127.0.0.1:8888");
	secureChannelConfig.setValue("TestConfig.SecurityPolicyUri", "http://opcfoundation.org/UA/SecurityPolicy#None");

	Session::SPtr session = client.sessionManager().getNewSession(
		"TestConfig", sessionConfig,
		"TestConfig", secureChannelConfig,
		&sessionTestHandler
	);

	// open session
	sessionTestHandler.sessionUpdateCondition_.condition(1, 0);
	session->open();
	BOOST_REQUIRE(sessionTestHandler.sessionUpdateCondition_.waitForCondition(1000) == true);

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// create subscription
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	SubscriptionManager subscriptionManager;
	subscriptionManager.componentSession(session->component());
	subscriptionManager.subscriptionManagerIf(&monitoredItemHandler);

	ServiceTransactionCreateSubscription::SPtr subCreateTrx = ServiceTransactionCreateSubscription::construct();
	CreateSubscriptionRequest::SPtr subCreateReq = subCreateTrx->request();
	CreateSubscriptionResponse::SPtr subCreateRes = subCreateTrx->response();
	subscriptionManager.sendSync(subCreateTrx);
	BOOST_REQUIRE(subCreateTrx->statusCode() == Success);

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// create monitored item
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	MonitoredItemService monitoredItemService;
	monitoredItemService.componentSession(session->component());

	ServiceTransactionCreateMonitoredItems::SPtr monCreateTrx = ServiceTransactionCreateMonitoredItems::construct();
	CreateMonitoredItemsRequest::SPtr monCreateReq = monCreateTrx->request();
	CreateMonitoredItemsResponse::SPtr monCreateRes = monCreateTrx->response();
	monCreateReq->subscriptionId(subCreateRes->subscriptionId());

	MonitoredItemCreateRequest::SPtr monitoredItemCreateRequest = MonitoredItemCreateRequest::construct();
	monitoredItemCreateRequest->itemToMonitor().nodeId()->set(218,1);
	monitoredItemCreateRequest->requestedParameters().clientHandle(218);

	monCreateReq->itemsToCreate()->resize(1);
	monCreateReq->itemsToCreate()->set(0, monitoredItemCreateRequest);
	monitoredItemHandler.dataChangeNotificationCondition_.condition(1, 0);
	monitoredItemService.sendSync(monCreateTrx);
	BOOST_REQUIRE(monCreateTrx->statusCode() == Success);
	BOOST_REQUIRE(monCreateRes->results()->size() == 1);

	MonitoredItemCreateResult::SPtr createMonResult;
	monCreateRes->results()->get(0, createMonResult);

	BOOST_REQUIRE(monitoredItemHandler.dataChangeNotificationCondition_.waitForCondition(1000) == true);

	IOService::secSleep(1000000);

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// delete monitored item
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ServiceTransactionDeleteMonitoredItems::SPtr monDeleteTrx = ServiceTransactionDeleteMonitoredItems::construct();
	DeleteMonitoredItemsRequest::SPtr monDeleteReq = monDeleteTrx->request();
	DeleteMonitoredItemsResponse::SPtr monDeleteRes = monDeleteTrx->response();
	monDeleteReq->subscriptionId(subCreateRes->subscriptionId());

	monDeleteReq->monitoredItemIds()->resize(1);
	monDeleteReq->monitoredItemIds()->set(0, createMonResult->monitoredItemId());


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// delete subscription
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ServiceTransactionDeleteSubscriptions::SPtr subDeleteTrx = ServiceTransactionDeleteSubscriptions::construct();
	DeleteSubscriptionsRequest::SPtr subDeleteReq = subDeleteTrx->request();
	DeleteSubscriptionsResponse::SPtr subDeleteRes = subDeleteTrx->response();
	subDeleteReq->subscriptionIds()->resize(1);
	subDeleteReq->subscriptionIds()->set(0, subCreateRes->subscriptionId());
	subscriptionManager.sendSync(subDeleteTrx);
	BOOST_REQUIRE(subDeleteTrx->statusCode() == Success);
	std::cout << subDeleteRes->results()->size() << std::endl;
	BOOST_REQUIRE(subDeleteRes->results()->size() == 1);
	OpcUaStatusCode statusCode;
	subDeleteRes->results()->get(0, statusCode);
	BOOST_REQUIRE(statusCode == Success);

	//IOService::secSleep(10000);
	client.stop();
	client.cleanup();
}

#endif

BOOST_AUTO_TEST_SUITE_END()
