#include "unittest.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"

using namespace OpcUaStackClient;

#ifdef REAL_SERVER

BOOST_AUTO_TEST_SUITE(ServiceSetManagerAsyncReal_View_)

BOOST_AUTO_TEST_CASE(ServiceSetManagerAsyncReal_View_)
{
	std::cout << "ServiceSetManagerAsyncReal_View_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(ServiceSetManagerAsyncReal_View_discovery_GetEndpoints)
{
	ServiceSetManager serviceSetManager;
	ViewServiceIfTestHandler viewServiceIfTestHandler;
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
	sessionIfTestHandler.sessionStateUpdate_.condition(1,0);
	sessionService->asyncConnect();
	BOOST_REQUIRE(sessionIfTestHandler.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionIfTestHandler.sessionState_ == SS_Connect);

	// create view service
	ViewService::SPtr viewService;
	ViewServiceConfig viewServiceConfig;
	viewServiceConfig.viewServiceIf_ = &viewServiceIfTestHandler;
	viewService = serviceSetManager.viewService(sessionService, viewServiceConfig);
	BOOST_REQUIRE(viewService.get() != nullptr);

	// call view
	ServiceTransactionBrowse::SPtr trx = constructSPtr<ServiceTransactionBrowse>();
	BrowseRequest::SPtr req = trx->request();
	req->nodesToBrowse()->resize(1);

	BrowseDescription::SPtr browseDescription = constructSPtr<BrowseDescription>();
	browseDescription->nodeId()->set(84, 0);
	browseDescription->browseDirection(BrowseDirection_Both);
	browseDescription->nodeClassMask(0xFFFFFFFF);
	browseDescription->resultMask(0xFFFFFFFF);
	req->nodesToBrowse()->push_back(browseDescription);

	viewServiceIfTestHandler.viewServiceBrowseResponse_.condition(1,0);
	viewService->asyncSend(trx);
	BOOST_REQUIRE(viewServiceIfTestHandler.viewServiceBrowseResponse_.waitForCondition(1000) == true);
	BOOST_REQUIRE(trx->responseHeader()->serviceResult() == Success);

	BrowseResponse::SPtr res = trx->response();
	BOOST_REQUIRE(res->results()->size() == 1);

	BrowseResult::SPtr browseResult;
	res->results()->get(0, browseResult);
	BOOST_REQUIRE(browseResult->statusCode() == Success);
	BOOST_REQUIRE(browseResult->references()->size() > 0);

	// disconnect secure channel
	sessionIfTestHandler.sessionStateUpdate_.condition(1,0);
	sessionService->asyncDisconnect();
	BOOST_REQUIRE(sessionIfTestHandler.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionIfTestHandler.sessionState_ == SS_Disconnect);
}


BOOST_AUTO_TEST_SUITE_END()

#endif
