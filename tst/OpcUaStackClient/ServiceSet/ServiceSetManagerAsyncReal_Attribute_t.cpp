#include "unittest.h"
#include "OpcUaStackClient/CryptoManagerTest.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"

using namespace OpcUaStackClient;

#ifdef REAL_SERVER

BOOST_AUTO_TEST_SUITE(ServiceSetManagerAsyncReal_Attribute_)

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

BOOST_AUTO_TEST_CASE(ServiceSetManagerAsyncReal_Attribute_)
{
	std::cout << "ServiceSetManagerAsyncReal_Attribute_t" << std::endl;
}

BOOST_FIXTURE_TEST_CASE(ServiceSetManagerAsyncReal_Attribute_read, GValueFixture)
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

	// create attribute servic
	AttributeServiceConfig attributeServiceConfig;
	auto attributeService = serviceSetManager.attributeService(sessionService, attributeServiceConfig);
	BOOST_REQUIRE(attributeService.get() != nullptr);

	// create and send WriteRequest
	auto trx = constructSPtr<ServiceTransactionWrite>();
	auto req = trx->request();
	auto writeValue = constructSPtr<WriteValue>();
	OpcUaBoolean value = 1;
	writeValue->nodeId()->set("Demo.Static.Scalar.Boolean", 2);
	writeValue->attributeId((OpcUaInt32) 13);
	writeValue->dataValue().variant()->set(value);
	req->writeValueArray()->resize(1);
	req->writeValueArray()->set(writeValue);

	cond_.condition(1,0);
	trx->resultHandler(
		[this](ServiceTransactionWrite::SPtr& trx) {
			cond_.conditionValueDec();
		}
	);
	attributeService->asyncSend(trx);
	cond_.waitForCondition(1000);
	auto res = trx->response();
	BOOST_REQUIRE(trx->statusCode() == Success);
	BOOST_REQUIRE(res->results()->size() == 1);

	// disconnect secure channel
	cond_.condition(1,0);
	sessionService->asyncDisconnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Disconnected);
}


BOOST_FIXTURE_TEST_CASE(ServiceSetManagerAsyncReal_Attribute_write, GValueFixture)
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

	// create attribute service
	AttributeServiceConfig attributeServiceConfig;
	auto attributeService = serviceSetManager.attributeService(sessionService, attributeServiceConfig);
	BOOST_REQUIRE(attributeService.get() != nullptr);

	// create and send ReadRequest
	auto trx = constructSPtr<ServiceTransactionRead>();
	auto req = trx->request();
	auto readValueIdSPtr = constructSPtr<ReadValueId>();
	readValueIdSPtr->nodeId((OpcUaInt16)0, (OpcUaInt32)2259);
	readValueIdSPtr->attributeId((OpcUaInt32) 13);
	readValueIdSPtr->dataEncoding().namespaceIndex((OpcUaInt16) 0);
	req->readValueIdArray()->set(readValueIdSPtr);

	cond_.condition(1,0);
	trx->resultHandler(
		[this](ServiceTransactionRead::SPtr& trx) {
			cond_.conditionValueDec();
		}
	);
	attributeService->asyncSend(trx);
	cond_.waitForCondition(1000);
	ReadResponse::SPtr res = trx->response();
	BOOST_REQUIRE(trx->statusCode() == Success);
	BOOST_REQUIRE(res->dataValueArray()->size() == 1);

	// disconnect secure channel
	cond_.condition(1,0);
	sessionService->asyncDisconnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Disconnected);
}


BOOST_AUTO_TEST_SUITE_END()

#endif
