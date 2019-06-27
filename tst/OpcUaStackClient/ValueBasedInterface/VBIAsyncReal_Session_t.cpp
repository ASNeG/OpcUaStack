#include "unittest.h"
#include "OpcUaStackClient/ValueBasedInterface/VBIClient.h"
#include "OpcUaStackClient/ValueBasedInterface/VBIClientHandlerTest.h"

using namespace OpcUaStackClient;

#ifdef REAL_SERVER

BOOST_AUTO_TEST_SUITE(VBIAsyncReal_Session_)

BOOST_AUTO_TEST_CASE(VBIAsyncReal_Session_)
{
	std::cout << "VBIAsyncReal_Session_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(VBIAsyncReal_Session_session_connect_disconnect)
{
	VBIClientHandlerTest vbiClientHandlerTest;
	VBIClient client;

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

	// set session change callback
	client.setSessionChangeCallback(
		boost::bind(&VBIClientHandlerTest::sessionStateUpdate, &vbiClientHandlerTest, (uint32_t)1234, _1, _2)
	);

	// connect session
	ConnectContext connectContext;
	connectContext.endpointUrl_ = REAL_SERVER_URI;
	connectContext.sessionName_ = REAL_SESSION_NAME;
	connectContext.applicationCertificate_ = applicationCertificate;
	connectContext.cryptoManager_ = cryptoManager;
	connectContext.secureChannelLog_ = true;
	vbiClientHandlerTest.sessionStateUpdate_.condition(1,0);
	client.asyncConnect(connectContext);
	BOOST_REQUIRE(vbiClientHandlerTest.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.sessionState_ == SS_Connect);
	BOOST_REQUIRE(vbiClientHandlerTest.clientHandle_ == 1234);

	// disconnect session
	vbiClientHandlerTest.sessionStateUpdate_.condition(1,0);
	client.asyncDisconnect();
	BOOST_REQUIRE(vbiClientHandlerTest.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.sessionState_ == SS_Disconnect);
	BOOST_REQUIRE(vbiClientHandlerTest.clientHandle_ == 1234);
}

BOOST_AUTO_TEST_CASE(VBIAsyncReal_Session_session_connect_disconnect_two_times)
{
	VBIClientHandlerTest vbiClientHandlerTest;
	VBIClient client;

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

	// set session change callback
	client.setSessionChangeCallback(
		boost::bind(&VBIClientHandlerTest::sessionStateUpdate, &vbiClientHandlerTest, (uint32_t)1234, _1, _2)
	);

	// connect session
	ConnectContext connectContext;
	connectContext.endpointUrl_ = REAL_SERVER_URI;
	connectContext.sessionName_ = REAL_SESSION_NAME;
	connectContext.applicationCertificate_ = applicationCertificate;
	connectContext.cryptoManager_ = cryptoManager;
	connectContext.secureChannelLog_ = true;
	vbiClientHandlerTest.sessionStateUpdate_.condition(1,0);
	client.asyncConnect(connectContext);
	BOOST_REQUIRE(vbiClientHandlerTest.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.sessionState_ == SS_Connect);
	BOOST_REQUIRE(vbiClientHandlerTest.clientHandle_ == 1234);

	// disconnect session
	vbiClientHandlerTest.sessionStateUpdate_.condition(1,0);
	client.asyncDisconnect();
	BOOST_REQUIRE(vbiClientHandlerTest.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.sessionState_ == SS_Disconnect);
	BOOST_REQUIRE(vbiClientHandlerTest.clientHandle_ == 1234);

	// connect session
	vbiClientHandlerTest.sessionStateUpdate_.condition(1,0);
	client.asyncConnect(connectContext);
	BOOST_REQUIRE(vbiClientHandlerTest.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.sessionState_ == SS_Connect);
	BOOST_REQUIRE(vbiClientHandlerTest.clientHandle_ == 1234);

	// disconnect session
	vbiClientHandlerTest.sessionStateUpdate_.condition(1,0);
	client.asyncDisconnect();
	BOOST_REQUIRE(vbiClientHandlerTest.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.sessionState_ == SS_Disconnect);
	BOOST_REQUIRE(vbiClientHandlerTest.clientHandle_ == 1234);
}


BOOST_AUTO_TEST_SUITE_END()

#endif
