#include "unittest.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"

using namespace OpcUaStackClient;

#ifdef REAL_SERVER

BOOST_AUTO_TEST_SUITE(ServiceSetManagerSyncReal_Attribute_)

BOOST_AUTO_TEST_CASE(ServiceSetManagerSyncReal_Attribute_)
{
	std::cout << "ServiceSetManagerSyncReal_Attribute_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(ServiceSetManagerSyncReal_Attribute_read)
{
	SessionServiceIfTestHandler sessionIfTestHandler;
	AttributeServiceIfTestHandler attributeServiceIfTestHandler;
	ServiceSetManager serviceSetManager;

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

	// create and send ReadRequest
	ServiceTransactionRead::SPtr trx;
	trx = constructSPtr<ServiceTransactionRead>();
	ReadRequest::SPtr req = trx->request();
	ReadValueId::SPtr readValueIdSPtr = constructSPtr<ReadValueId>();
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


BOOST_AUTO_TEST_CASE(ServiceSetManagerSyncReal_Attribute_write)
{
	SessionServiceIfTestHandler sessionIfTestHandler;
	AttributeServiceIfTestHandler attributeServiceIfTestHandler;
	ServiceSetManager serviceSetManager;

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

	// create and send WriteRequest
	ServiceTransactionWrite::SPtr trx;
	trx = constructSPtr<ServiceTransactionWrite>();
	WriteRequest::SPtr req = trx->request();

	OpcUaBoolean value = 1;
	WriteValue::SPtr writeValue = constructSPtr<WriteValue>();
	writeValue->nodeId()->set("Demo.Static.Scalar.Boolean", 2);
	writeValue->attributeId((OpcUaInt32) 13);
	writeValue->dataValue().variant()->set(value);
	req->writeValueArray()->resize(1);
	req->writeValueArray()->set(writeValue);

	attributeService->syncSend(trx);
	WriteResponse::SPtr res = trx->response();
	BOOST_REQUIRE(trx->statusCode() == Success);
	BOOST_REQUIRE(res->results()->size() == 1);

	// disconnect secure channel
	BOOST_REQUIRE(sessionService->syncDisconnect() == Success);
}


BOOST_AUTO_TEST_SUITE_END()

#endif
