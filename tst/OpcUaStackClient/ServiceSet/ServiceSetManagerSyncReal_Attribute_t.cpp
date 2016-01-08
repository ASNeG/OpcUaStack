#include "unittest.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"

using namespace OpcUaStackClient;

#ifdef REAL_SERVER

BOOST_AUTO_TEST_SUITE()

BOOST_AUTO_TEST_CASE(ServiceSetManagerSyncReal_Attribute_)
{
	std::cout << "ServiceSetManagerSyncReal_Attribute_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(ServiceSetManagerSyncReal_Attribute_discovery_GetEndpoints)
{
	SessionServiceIfTestHandler sessionIfTestHandler;
	AttributeServiceIfTestHandler attributeServiceIfTestHandler;
	ServiceSetManager serviceSetManager;

	// set secure channel configuration
	SessionServiceConfig sessionServiceConfig;
	sessionServiceConfig.sessionServiceIf_ = &sessionIfTestHandler;
	sessionServiceConfig.secureChannelClient_->endpointUrl(REAL_SERVER_URI);
	sessionServiceConfig.session_->sessionName(REAL_SESSION_NAME);

	// create session service
	SessionService::SPtr sessionService;
	sessionService = serviceSetManager.sessionService(sessionServiceConfig);
	BOOST_REQUIRE(sessionService.get() != nullptr);

	// connect secure channel
	BOOST_REQUIRE(sessionService->syncConnect() == Success);

	// create attribute service
	AttributeService::SPtr attributeService;
	AttributeServiceConfig attributeServiceConfig;
	attributeServiceConfig.attributeServiceIf_ = &attributeServiceIfTestHandler;
	attributeService = serviceSetManager.attributeService(sessionService, attributeServiceConfig);
	BOOST_REQUIRE(attributeService.get() != nullptr);

	// create and send GetEndpointsRequest
	ServiceTransactionRead::SPtr trx;
	trx = constructSPtr<ServiceTransactionRead>();
	ReadRequest::SPtr req = trx->request();
	ReadValueId::SPtr readValueIdSPtr = ReadValueId::construct();
	readValueIdSPtr->nodeId((OpcUaInt16)0, (OpcUaInt32)2259);
	readValueIdSPtr->attributeId((OpcUaInt32) 13);
	readValueIdSPtr->dataEncoding().namespaceIndex((OpcUaInt16) 0);
	req->readValueIdArray()->set(readValueIdSPtr);

	attributeService->syncSend(trx);
	ReadResponse::SPtr res = trx->response();
	BOOST_REQUIRE(trx->statusCode() == Success);
	BOOST_REQUIRE(res->dataValueArray()->size() == 1);

	// disconnect secure channel
	BOOST_REQUIRE(sessionService->syncDisconnect() == Success);
}


BOOST_AUTO_TEST_SUITE_END()

#endif
