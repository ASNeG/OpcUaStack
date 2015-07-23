#include "unittest.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackClient/Client/Client.h"
#include "OpcUaStackClient/ServiceSet/SessionTestHandler.h"
#include "OpcUaStackClient/ServiceSet/SubscriptionManager.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

BOOST_AUTO_TEST_SUITE(MonitoredItem_)

BOOST_AUTO_TEST_CASE(MonitoredItem_)
{
	std::cout << "MonitoredItem_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(MonitoredItem_create_delete_sync)
{
	SessionTestHandler sessionTestHandler;

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

	// createSession
	sessionTestHandler.createSessionCompleteCondition_.condition(1, 0);
	session->createSession();
	BOOST_REQUIRE(sessionTestHandler.createSessionCompleteCondition_.waitForCondition(1000) == true);

	// activateSession
	sessionTestHandler.activateSessionCompleteCondition_.condition(1, 0);
	session->activateSession();
	BOOST_REQUIRE(sessionTestHandler.activateSessionCompleteCondition_.waitForCondition(1000) == true);

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// create subscription
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	SubscriptionManager subscriptionManager;
	subscriptionManager.componentSession(session->component());

	ServiceTransactionCreateSubscription::SPtr subCreateTrx = ServiceTransactionCreateSubscription::construct();
	CreateSubscriptionRequest::SPtr subCreateReq = subCreateTrx->request();
	CreateSubscriptionResponse::SPtr subCreateRes = subCreateTrx->response();
	subscriptionManager.sendSync(subCreateTrx);
	BOOST_REQUIRE(subCreateTrx->responseHeader()->serviceResult() == Success);

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// create monitored item
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	IOService::secSleep(10000);

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
	BOOST_REQUIRE(subDeleteTrx->responseHeader()->serviceResult() == Success);
	std::cout << subDeleteRes->results()->size() << std::endl;
	BOOST_REQUIRE(subDeleteRes->results()->size() == 1);
	OpcUaStatusCode statusCode;
	subDeleteRes->results()->get(0, statusCode);
	BOOST_REQUIRE(statusCode == Success);

	//IOService::secSleep(10000);
	client.stop();
	client.cleanup();
}

BOOST_AUTO_TEST_SUITE_END()
