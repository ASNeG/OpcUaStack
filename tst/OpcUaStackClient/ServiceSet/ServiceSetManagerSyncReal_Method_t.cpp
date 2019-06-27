#include "unittest.h"
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
	MethodServiceIfTestHandler methodServiceIfTestHandler;
	SessionServiceIfTestHandler sessionIfTestHandler;

	//
	// init certificate and crypto manager
	//
	ApplicationCertificate::SPtr applicationCertificate = constructSPtr<ApplicationCertificate>();
	applicationCertificate->enable(true);

	applicationCertificate->certificateTrustListLocation("./pki/trusted/certs/");
	applicationCertificate->certificateRejectListLocation("./pki/reject/certs/.");
	applicationCertificate->certificateRevocationListLocation("./pki/trusted/crl/");
	applicationCertificate->issuersCertificatesLocation("./pki/issuers/certs/");
	applicationCertificate->issuersRevocationListLocation("./pki/issuers/crl/");

	applicationCertificate->serverCertificateFile("./pki/own/certs/ASNeG-Demo.der");
	applicationCertificate->privateKeyFile("./pki/own/private/ASNeG-Demo.pem");

	applicationCertificate->generateCertificate(true);
	applicationCertificate->uri("urn:asneg.de:ASNeG:ASNeG-Demo");
	applicationCertificate->commonName("ASNeG-Demo");
	applicationCertificate->domainComponent("127.0.0.1");
	applicationCertificate->organization("ASNeG");
	applicationCertificate->organizationUnit("OPC UA Service Department");
	applicationCertificate->locality("Neukirchen");
	applicationCertificate->state("Hessen");
	applicationCertificate->country("DE");
	applicationCertificate->yearsValidFor(5);
	applicationCertificate->keyLength(2048);
	applicationCertificate->certificateType("RsaSha256");
	applicationCertificate->ipAddress().push_back("127.0.0.1");
	applicationCertificate->dnsName().push_back("ASNeG.de");
	applicationCertificate->email("info@ASNeG.de");

	BOOST_REQUIRE(applicationCertificate->init() == true);
	CryptoManager::SPtr cryptoManager = constructSPtr<CryptoManager>();

	// set secure channel configuration
	SessionServiceConfig sessionServiceConfig;
	sessionServiceConfig.sessionServiceIf_ = &sessionIfTestHandler;
	sessionServiceConfig.secureChannelClient_->endpointUrl(REAL_SERVER_URI);
	sessionServiceConfig.secureChannelClient_->applicationCertificate(applicationCertificate);
	sessionServiceConfig.secureChannelClient_->cryptoManager(cryptoManager);
	sessionServiceConfig.session_->sessionName(REAL_SESSION_NAME);

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

	methodService->syncSend(trx);
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
	BOOST_REQUIRE(sessionService->syncDisconnect() == Success);
}


BOOST_AUTO_TEST_SUITE_END()

#endif
