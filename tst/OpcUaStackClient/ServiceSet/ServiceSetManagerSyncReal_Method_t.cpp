#include "unittest.h"
#include "OpcUaStackClient/CryptoManagerTest.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"

using namespace OpcUaStackClient;

#ifdef REAL_SERVER

BOOST_AUTO_TEST_SUITE(ServiceSetManagerSyncReal_Method_)

BOOST_AUTO_TEST_CASE(ServiceSetManagerSyncReal_Method_)
{
	std::cout << "ServiceSetManagerSyncReal_Method_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(ServiceSetManagerSyncReal_Method_discovery_GetEndpoints)
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

	// create method service
	MethodServiceConfig methodServiceConfig;
	auto methodService = serviceSetManager.methodService(sessionService, methodServiceConfig);
	BOOST_REQUIRE(methodService.get() != nullptr);

	// call method
	auto inArgument1 = constructSPtr<OpcUaVariant>();
	inArgument1->set((uint32_t)1);
	auto inArgument2 = constructSPtr<OpcUaVariant>();
	inArgument2->set((uint32_t)2);

	auto callMethodRequest = constructSPtr<CallMethodRequest>();
	callMethodRequest->objectId()->set("Function" ,6);
	callMethodRequest->methodId()->set("funcMult" ,6);
	callMethodRequest->inputArguments()->resize(2);
	callMethodRequest->inputArguments()->set(0, inArgument1);
	callMethodRequest->inputArguments()->set(1, inArgument2);

	auto trx = constructSPtr<ServiceTransactionCall>();
	auto req = trx->request();
	req->methodsToCall()->resize(1);
	req->methodsToCall()->set(0, callMethodRequest);

	methodService->syncSend(trx);
	BOOST_REQUIRE(trx->responseHeader()->serviceResult() == Success);

	auto res = trx->response();
	BOOST_REQUIRE(res->results()->size() == 1);

	CallMethodResult::SPtr callMethodResult;
	res->results()->get(0, callMethodResult);

	BOOST_REQUIRE(callMethodResult->outputArguments()->size() == 1);
	OpcUaVariant::SPtr outArgument1;
	callMethodResult->outputArguments()->get(0, outArgument1);
	BOOST_REQUIRE(outArgument1->variantType() == OpcUaId_UInt32);

	uint32_t number = outArgument1->get<uint32_t>();

	// disconnect secure channel
	BOOST_REQUIRE(sessionService->syncDisconnect() == Success);
}


BOOST_AUTO_TEST_SUITE_END()

#endif
