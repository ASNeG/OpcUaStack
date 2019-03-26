#include "unittest.h"
#include "OpcUaStackClient/CryptoManagerTest.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"

using namespace OpcUaStackClient;

#ifdef REAL_SERVER

BOOST_AUTO_TEST_SUITE(ServiceSetManagerSyncReal_Subscription)

BOOST_AUTO_TEST_CASE(ServiceSetManagerSyncReal_Subscription)
{
	std::cout << "ServiceSetManagerSyncReal_Subscription_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(ServiceSetManagerSyncReal_Subscriptionsubscription_create_delete)
{
	ServiceSetManager serviceSetManager;

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

	// create session
	auto sessionService = serviceSetManager.sessionService(sessionServiceConfig);
	BOOST_REQUIRE(sessionService.get() != nullptr);

	// connect secure channel
	BOOST_REQUIRE(sessionService->syncConnect() == Success);

	// create subscription service
	SubscriptionService::SPtr subscriptionService;
	SubscriptionServiceConfig subscriptionServiceConfig;
	subscriptionServiceConfig.subscriptionStateUpdateHandler_ =
		[this](SubscriptionState subscriptionState, uint32_t subscriptionId) {
		};
	subscriptionServiceConfig.dataChangeNotificationHandler_ =
		[this](const MonitoredItemNotification::SPtr& monitoredItem) {
		};
	subscriptionService = serviceSetManager.subscriptionService(sessionService, subscriptionServiceConfig);

	// create subscription
	auto subCreateTrx = constructSPtr<ServiceTransactionCreateSubscription>();
	auto subCreateReq = subCreateTrx->request();
	auto subCreateRes = subCreateTrx->response();
	subscriptionService->syncSend(subCreateTrx);
	BOOST_REQUIRE(subCreateTrx->responseHeader()->serviceResult() == Success);
	uint32_t subscriptionId = subCreateRes->subscriptionId();

	// delete subscription
	auto subDeleteTrx = constructSPtr<ServiceTransactionDeleteSubscriptions>();
	auto subDeleteReq = subDeleteTrx->request();
	auto subDeleteRes = subDeleteTrx->response();
	subDeleteReq->subscriptionIds()->resize(1);
	subDeleteReq->subscriptionIds()->set(0, subscriptionId);
	subscriptionService->syncSend(subDeleteTrx);
	BOOST_REQUIRE(subDeleteTrx->responseHeader()->serviceResult() == Success);
	BOOST_REQUIRE(subDeleteRes->results()->size() == 1);
	OpcUaStatusCode statusCode;
	subDeleteRes->results()->get(0, statusCode);
	BOOST_REQUIRE(statusCode == Success);

	// disconnect secure channel
	BOOST_REQUIRE(sessionService->syncDisconnect() == Success);
}


BOOST_AUTO_TEST_SUITE_END()

#endif
