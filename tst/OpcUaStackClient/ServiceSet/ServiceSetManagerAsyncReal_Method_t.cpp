#include "unittest.h"
#include "OpcUaStackClient/CryptoManagerTest.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"

using namespace OpcUaStackClient;

#ifdef REAL_SERVER

BOOST_AUTO_TEST_SUITE(ServiceSetManagerAsyncReal_Method_)

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

BOOST_AUTO_TEST_CASE(ServiceSetManagerAsyncReal_Method_)
{
	std::cout << "ServiceSetManagerAsyncReal_Method_t" << std::endl;
}

BOOST_FIXTURE_TEST_CASE(ServiceSetManagerAsyncReal_Method_discovery_GetEndpoints, GValueFixture)
{
	ServiceSetManager serviceSetManager;
	MethodServiceIfTestHandler methodServiceIfTestHandler;
	SessionServiceIfTestHandler sessionIfTestHandler;

	//
	// init certificate and crypto manager
	//
	CryptoManager::SPtr cryptoManager = CryptoManagerTest::getInstance();
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
	SessionService::SPtr sessionService;
	sessionService = serviceSetManager.sessionService(sessionServiceConfig);
	BOOST_REQUIRE(sessionService.get() != nullptr);

	// connect secure channel
	cond_.condition(1,0);
	sessionService->asyncConnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Established);

	// create method service
	MethodService::SPtr methodService;
	MethodServiceConfig methodServiceConfig;
	methodServiceConfig.methodServiceIf_ = &methodServiceIfTestHandler;
	methodService = serviceSetManager.methodService(sessionService, methodServiceConfig);
	BOOST_REQUIRE(methodService.get() != nullptr);

	// call method
	OpcUaVariant::SPtr inArgument1 = constructSPtr<OpcUaVariant>();
	inArgument1->set((uint32_t)1);
	OpcUaVariant::SPtr inArgument2 = constructSPtr<OpcUaVariant>();
	inArgument2->set((uint32_t)2);

	CallMethodRequest::SPtr callMethodRequest = constructSPtr<CallMethodRequest>();
	callMethodRequest->objectId()->set("Function" ,6);
	callMethodRequest->methodId()->set("funcMult" ,6);
	callMethodRequest->inputArguments()->resize(2);
	callMethodRequest->inputArguments()->set(0, inArgument1);
	callMethodRequest->inputArguments()->set(1, inArgument2);

	ServiceTransactionCall::SPtr trx;
	trx = constructSPtr<ServiceTransactionCall>();
	CallRequest::SPtr req = trx->request();
	req->methodsToCall()->resize(1);
	req->methodsToCall()->set(0, callMethodRequest);

	methodServiceIfTestHandler.methodServiceCallResponse_.condition(1,0);
	methodService->asyncSend(trx);
	BOOST_REQUIRE(methodServiceIfTestHandler.methodServiceCallResponse_.waitForCondition(1000) == true);
	BOOST_REQUIRE(trx->responseHeader()->serviceResult() == Success);

	CallResponse::SPtr res = trx->response();
	BOOST_REQUIRE(res->results()->size() == 1);

	CallMethodResult::SPtr callMethodResult;
	res->results()->get(0, callMethodResult);

	BOOST_REQUIRE(callMethodResult->outputArguments()->size() == 1);
	OpcUaVariant::SPtr outArgument1;
	callMethodResult->outputArguments()->get(0, outArgument1);
	BOOST_REQUIRE(outArgument1->variantType() == OpcUaId_UInt32);

	uint32_t number = outArgument1->get<uint32_t>();

	// disconnect secure channel
	cond_.condition(1,0);
	sessionService->asyncDisconnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Disconnected);
}


BOOST_AUTO_TEST_SUITE_END()

#endif
