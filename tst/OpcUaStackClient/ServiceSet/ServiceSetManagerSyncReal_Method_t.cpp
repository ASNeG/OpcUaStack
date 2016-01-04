#include "unittest.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"

using namespace OpcUaStackClient;

#ifdef REAL_SERVER

BOOST_AUTO_TEST_SUITE()

BOOST_AUTO_TEST_CASE(ServiceSetManagerSyncReal_Method_)
{
	std::cout << "ServiceSetManagerSyncReal_Method_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(ServiceSetManagerSyncReal_Method_discovery_GetEndpoints)
{
	ServiceSetManager serviceSetManager;
	MethodServiceIfTestHandler methodServiceIfTestHandler;
	SessionServiceIfTestHandler sessionIfTestHandler;

	// set secure channel configuration
	SessionServiceConfig sessionServiceConfig;
	sessionServiceConfig.sessionServiceIf_ = &sessionIfTestHandler;
	sessionServiceConfig.secureChannelClient_->endpointUrl(REAL_SERVER_URI);

	// create session
	SessionService::SPtr sessionService;
	sessionService = serviceSetManager.sessionService(sessionServiceConfig);
	BOOST_REQUIRE(sessionService.get() != nullptr);

	// connect secure channel
	BOOST_REQUIRE(sessionService->syncConnect() == Success);

	// create method service
	MethodService::SPtr methodService;
	MethodServiceConfig methodServiceConfig;
	methodServiceConfig.methodServiceIf_ = &methodServiceIfTestHandler;
	methodService = serviceSetManager.methodService(sessionService, methodServiceConfig);
	BOOST_REQUIRE(methodService.get() != nullptr);

	// call method
	OpcUaVariant::SPtr inArgument1 = constructSPtr<OpcUaVariant>();
	inArgument1->set((OpcUaDouble)1.1);
	OpcUaVariant::SPtr inArgument2 = constructSPtr<OpcUaVariant>();
	inArgument2->set((OpcUaDouble)2.2);

	CallMethodRequest::SPtr callMethodRequest = constructSPtr<CallMethodRequest>();
	callMethodRequest->objectId()->set("Demo.Method" ,2);
	callMethodRequest->methodId()->set("Demo.Method.Multiply" ,2);
	callMethodRequest->inputArguments()->resize(2);
	callMethodRequest->inputArguments()->set(0, inArgument1);
	callMethodRequest->inputArguments()->set(1, inArgument2);

	ServiceTransactionCall::SPtr trx;
	trx = constructSPtr<ServiceTransactionCall>();
	CallRequest::SPtr req = trx->request();
	req->methodsToCall()->resize(1);
	req->methodsToCall()->set(0, callMethodRequest);

	methodService->syncSend(trx);
	BOOST_REQUIRE(trx->responseHeader()->serviceResult() == Success);

	CallResponse::SPtr res = trx->response();
	BOOST_REQUIRE(res->results()->size() == 1);

	CallMethodResult::SPtr callMethodResult;
	res->results()->get(0, callMethodResult);

	BOOST_REQUIRE(callMethodResult->outputArguments()->size() == 1);
	OpcUaVariant::SPtr outArgument1;
	callMethodResult->outputArguments()->get(0, outArgument1);
	BOOST_REQUIRE(outArgument1->variantType() == OpcUaId_Double);

	OpcUaDouble doubleNumber = outArgument1->get<OpcUaDouble>();

	// disconnect secure channel
	BOOST_REQUIRE(sessionService->syncDisconnect() == Success);
}


BOOST_AUTO_TEST_SUITE_END()

#endif
