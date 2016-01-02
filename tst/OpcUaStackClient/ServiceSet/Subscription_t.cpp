#include "unittest.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackClient/Client/Client.h"
#include "OpcUaStackClient/ServiceSet/SessionTestHandler.h"
#include "OpcUaStackClient/ServiceSet/SubscriptionService.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
//
// SubscriptionServiceIf
//
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
class SubscriptionServiceHandler
: public SubscriptionServiceIf
{
  public:
	void subscriptionServiceCreateSubscriptionResponse(ServiceTransactionCreateSubscription::SPtr serviceTransactionCreateSubscription)
	{
		createSubscriptionCondition_.conditionValueDec();
	}
	void subscriptionServiceModifySubscriptionResponse(ServiceTransactionModifySubscription::SPtr serviceTransactionModifySubscription)
	{
		modifySubscriptionCondition_.conditionValueDec();
	}

	void subscriptionServiceTransferSubscriptionsResponse(ServiceTransactionTransferSubscriptions::SPtr serviceTransactionTransferSubscriptions)
	{
		transferSubscriptionCondition_.conditionValueDec();
	}

	void subscriptionServiceDeleteSubscriptionsResponse(ServiceTransactionDeleteSubscriptions::SPtr serviceTransactionDeleteSubscriptions)
	{
		deleteSubscriptionCondition_.conditionValueDec();
	}

	Condition createSubscriptionCondition_;
	Condition modifySubscriptionCondition_;
	Condition transferSubscriptionCondition_;
	Condition deleteSubscriptionCondition_;
};

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
//
// SubscriptionManagerIf
//
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
BOOST_AUTO_TEST_SUITE(Subscription_)

BOOST_AUTO_TEST_CASE(Subscription_)
{
	std::cout << "Subscription_t" << std::endl;
}

#if 0
BOOST_AUTO_TEST_CASE(Subscription_create_delete_sync)
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

	SessionOld::SPtr session = client.sessionManager().getNewSession(
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

	ServiceTransactionCreateSubscription::SPtr subCreateTrx = ServiceTransactionCreateSubscription::construct();
	CreateSubscriptionRequest::SPtr subCreateReq = subCreateTrx->request();
	CreateSubscriptionResponse::SPtr subCreateRes = subCreateTrx->response();
	subscriptionManager.sendSync(subCreateTrx);
	BOOST_REQUIRE(subCreateTrx->responseHeader()->serviceResult() == Success);

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

#if 0
BOOST_AUTO_TEST_CASE(Subscription_create_delete_async)
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

	// open session
	sessionTestHandler.sessionUpdateCondition_.condition(1, 0);
	session->open();
	BOOST_REQUIRE(sessionTestHandler.sessionUpdateCondition_.waitForCondition(1000) == true);

#if 0
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// create subscription
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	SubscriptionServiceHandler ssh;

	SubscriptionManager subscriptionManager;
	subscriptionManager.componentSession(session->component());
	subscriptionManager.subscriptionServiceIf(&ssh);

	ServiceTransactionCreateSubscription::SPtr subCreateTrx = ServiceTransactionCreateSubscription::construct();
	CreateSubscriptionRequest::SPtr subCreateReq = subCreateTrx->request();
	CreateSubscriptionResponse::SPtr subCreateRes = subCreateTrx->response();

	ssh.createSubscriptionCondition_.condition(1, 0);
	subscriptionManager.sendAsync(subCreateTrx);
	BOOST_REQUIRE(ssh.createSubscriptionCondition_.waitForCondition(1000) == true);

	BOOST_REQUIRE(subCreateTrx->responseHeader()->serviceResult() == Success);

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

	ssh.deleteSubscriptionCondition_.condition(1, 0);
	subscriptionManager.sendAsync(subDeleteTrx);
	BOOST_REQUIRE(ssh.deleteSubscriptionCondition_.waitForCondition(1000) == true);

	BOOST_REQUIRE(subDeleteTrx->responseHeader()->serviceResult() == Success);
	std::cout << subDeleteRes->results()->size() << std::endl;
	BOOST_REQUIRE(subDeleteRes->results()->size() == 1);
	OpcUaStatusCode statusCode;
	subDeleteRes->results()->get(0, statusCode);
	BOOST_REQUIRE(statusCode == Success);
#endif

	//IOService::secSleep(10000);
	client.stop();
	client.cleanup();
}
#endif
#endif

BOOST_AUTO_TEST_SUITE_END()
