#include "unittest.h"
#include "OpcUaStackClient/ValueBasedInterface/VBIClient.h"
#include "OpcUaStackClient/ValueBasedInterface/VBIClientHandlerTest.h"

using namespace OpcUaStackClient;

#ifdef REAL_SERVER

BOOST_AUTO_TEST_SUITE(VBIAsyncReal_MonitoredItem_)

BOOST_AUTO_TEST_CASE(VBIAsyncReal_MonitoredItem_)
{
	std::cout << "VBIAsyncReal_MonitoredItem_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(VBIAsyncReal_MonitoredItem_create_delete)
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
	vbiClientHandlerTest.sessionStateUpdate_.initEvent();
	client.asyncConnect(connectContext);
	BOOST_REQUIRE(vbiClientHandlerTest.sessionStateUpdate_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.sessionState_ == SS_Connect);
	BOOST_REQUIRE(vbiClientHandlerTest.clientHandle_ == 1234);

	// create subscription
	vbiClientHandlerTest.createSubscriptionComplete_.initEvent();
	client.asyncCreateSubscription(
		boost::bind(&VBIClientHandlerTest::createSubscriptionComplete, &vbiClientHandlerTest, _1, _2)
	);
	BOOST_REQUIRE(vbiClientHandlerTest.createSubscriptionComplete_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.statusCode_ == Success);
	uint32_t subscriptionId = vbiClientHandlerTest.subscriptionId_;

	// create monitored item
	uint32_t clientHandle = 334455;
	OpcUaNodeId nodeId;
	nodeId.set((OpcUaUInt32)2258);
	vbiClientHandlerTest.createMonitoredItemComplete_.initEvent();
	client.asyncCreateMonitoredItem(
		nodeId,
		subscriptionId,
		clientHandle,
		boost::bind(&VBIClientHandlerTest::createMonitoredItemComplete, &vbiClientHandlerTest, _1, _2, _3)
	);
	BOOST_REQUIRE(vbiClientHandlerTest.createMonitoredItemComplete_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.statusCode_ == Success);
	uint32_t monitoredItemId = vbiClientHandlerTest.monitoredItemId_;

	// delete monitored item
	vbiClientHandlerTest.deleteMonitoredItemComplete_.initEvent();
	client.asyncDeleteMonitoredItem(
		subscriptionId,
		monitoredItemId,
		boost::bind(&VBIClientHandlerTest::deleteMonitoredItemComplete, &vbiClientHandlerTest, _1, _2, _3)
	);
	BOOST_REQUIRE(vbiClientHandlerTest.deleteMonitoredItemComplete_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.statusCode_ == Success);
	BOOST_REQUIRE(monitoredItemId == vbiClientHandlerTest.monitoredItemId_);
	BOOST_REQUIRE(subscriptionId == vbiClientHandlerTest.subscriptionId_);

	// delete subscription
	vbiClientHandlerTest.deleteSubscriptionComplete_.initEvent();
	client.asyncDeleteSubscription(
		subscriptionId,
		boost::bind(&VBIClientHandlerTest::deleteSubscriptionComplete, &vbiClientHandlerTest, _1, _2)
	);
	BOOST_REQUIRE(vbiClientHandlerTest.deleteSubscriptionComplete_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.statusCode_ == Success);
	BOOST_REQUIRE(vbiClientHandlerTest.subscriptionId_ == subscriptionId);

	// disconnect session
	vbiClientHandlerTest.sessionStateUpdate_.initEvent();
	client.asyncDisconnect();
	BOOST_REQUIRE(vbiClientHandlerTest.sessionStateUpdate_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.sessionState_ == SS_Disconnect);
	BOOST_REQUIRE(vbiClientHandlerTest.clientHandle_ == 1234);
}

BOOST_AUTO_TEST_CASE(VBIAsyncReal_MonitoredItem_create_delete_callback)
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
	vbiClientHandlerTest.sessionStateUpdate_.initEvent();
	client.asyncConnect(connectContext);
	BOOST_REQUIRE(vbiClientHandlerTest.sessionStateUpdate_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.sessionState_ == SS_Connect);
	BOOST_REQUIRE(vbiClientHandlerTest.clientHandle_ == 1234);

	// set data change callback
	client.setDataChangeCallback(
		boost::bind(&VBIClientHandlerTest::dataChangeCallback, &vbiClientHandlerTest, _1, _2)
	);

	// create subscription
	vbiClientHandlerTest.createSubscriptionComplete_.initEvent();
	client.asyncCreateSubscription(
		boost::bind(&VBIClientHandlerTest::createSubscriptionComplete, &vbiClientHandlerTest, _1, _2)
	);
	BOOST_REQUIRE(vbiClientHandlerTest.createSubscriptionComplete_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.statusCode_ == Success);
	uint32_t subscriptionId = vbiClientHandlerTest.subscriptionId_;

	// create monitored item
	uint32_t clientHandle = 332201;
	OpcUaNodeId nodeId;
	nodeId.set((OpcUaUInt32)2258);
	vbiClientHandlerTest.dataChangeCallback_.initEvent();
	vbiClientHandlerTest.createMonitoredItemComplete_.initEvent();
	client.asyncCreateMonitoredItem(
		nodeId,
		subscriptionId,
		clientHandle,
		boost::bind(&VBIClientHandlerTest::createMonitoredItemComplete, &vbiClientHandlerTest, _1, _2, _3)
	);
	BOOST_REQUIRE(vbiClientHandlerTest.createMonitoredItemComplete_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.statusCode_ == Success);
	uint32_t monitoredItemId = vbiClientHandlerTest.monitoredItemId_;
	BOOST_REQUIRE(vbiClientHandlerTest.dataChangeCallback_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.clientHandle_ == clientHandle);

#if 0
	while (true) {
		vbiClientHandlerTest.dataChangeCallback_.initEvent();
		vbiClientHandlerTest.dataChangeCallback_.waitForEvent(1000);
	}
#endif

	// delete monitored item
	vbiClientHandlerTest.deleteMonitoredItemComplete_.initEvent();
	client.asyncDeleteMonitoredItem(
		subscriptionId,
		monitoredItemId,
		boost::bind(&VBIClientHandlerTest::deleteMonitoredItemComplete, &vbiClientHandlerTest, _1, _2, _3)
	);
	BOOST_REQUIRE(vbiClientHandlerTest.deleteMonitoredItemComplete_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.statusCode_ == Success);
	BOOST_REQUIRE(monitoredItemId == vbiClientHandlerTest.monitoredItemId_);
	BOOST_REQUIRE(subscriptionId == vbiClientHandlerTest.subscriptionId_);

	// delete subscription
	vbiClientHandlerTest.deleteSubscriptionComplete_.initEvent();
	client.asyncDeleteSubscription(
		subscriptionId,
		boost::bind(&VBIClientHandlerTest::deleteSubscriptionComplete, &vbiClientHandlerTest, _1, _2)
	);
	BOOST_REQUIRE(vbiClientHandlerTest.deleteSubscriptionComplete_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.statusCode_ == Success);
	BOOST_REQUIRE(vbiClientHandlerTest.subscriptionId_ == subscriptionId);

	// disconnect session
	vbiClientHandlerTest.sessionStateUpdate_.initEvent();
	client.asyncDisconnect();
	BOOST_REQUIRE(vbiClientHandlerTest.sessionStateUpdate_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.sessionState_ == SS_Disconnect);
	BOOST_REQUIRE(vbiClientHandlerTest.clientHandle_ == 1234);
}

BOOST_AUTO_TEST_CASE(VBIAsyncReal_MonitoredItem_data_change)
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
	vbiClientHandlerTest.sessionStateUpdate_.initEvent();
	client.asyncConnect(connectContext);
	BOOST_REQUIRE(vbiClientHandlerTest.sessionStateUpdate_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.sessionState_ == SS_Connect);
	BOOST_REQUIRE(vbiClientHandlerTest.clientHandle_ == 1234);

	// set data change callback
	client.setDataChangeCallback(
		boost::bind(&VBIClientHandlerTest::dataChangeCallback, &vbiClientHandlerTest, _1, _2)
	);

	// create subscription
	vbiClientHandlerTest.createSubscriptionComplete_.initEvent();
	client.asyncCreateSubscription(
		boost::bind(&VBIClientHandlerTest::createSubscriptionComplete, &vbiClientHandlerTest, _1, _2)
	);
	BOOST_REQUIRE(vbiClientHandlerTest.createSubscriptionComplete_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.statusCode_ == Success);
	uint32_t subscriptionId = vbiClientHandlerTest.subscriptionId_;

	// create monitored item
	uint32_t clientHandle = 332201;
	OpcUaNodeId nodeId;
	nodeId.set((OpcUaUInt32)2258);
	vbiClientHandlerTest.dataChangeCallback_.initEvent();
	vbiClientHandlerTest.createMonitoredItemComplete_.initEvent();
	client.asyncCreateMonitoredItem(
		nodeId,
		subscriptionId,
		clientHandle,
		boost::bind(&VBIClientHandlerTest::createMonitoredItemComplete, &vbiClientHandlerTest, _1, _2, _3)
	);
	BOOST_REQUIRE(vbiClientHandlerTest.createMonitoredItemComplete_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.statusCode_ == Success);
	uint32_t monitoredItemId = vbiClientHandlerTest.monitoredItemId_;
	BOOST_REQUIRE(vbiClientHandlerTest.dataChangeCallback_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.clientHandle_ == clientHandle);

	for (uint32_t idx=0; idx<2; idx++) {
		vbiClientHandlerTest.dataChangeCallback_.initEvent();
		vbiClientHandlerTest.dataChangeCallback_.waitForEvent(3000);
	}

	// delete monitored item
	vbiClientHandlerTest.deleteMonitoredItemComplete_.initEvent();
	client.asyncDeleteMonitoredItem(
		subscriptionId,
		monitoredItemId,
		boost::bind(&VBIClientHandlerTest::deleteMonitoredItemComplete, &vbiClientHandlerTest, _1, _2, _3)
	);
	BOOST_REQUIRE(vbiClientHandlerTest.deleteMonitoredItemComplete_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.statusCode_ == Success);
	BOOST_REQUIRE(monitoredItemId == vbiClientHandlerTest.monitoredItemId_);
	BOOST_REQUIRE(subscriptionId == vbiClientHandlerTest.subscriptionId_);

	// delete subscription
	vbiClientHandlerTest.deleteSubscriptionComplete_.initEvent();
	client.asyncDeleteSubscription(
		subscriptionId,
		boost::bind(&VBIClientHandlerTest::deleteSubscriptionComplete, &vbiClientHandlerTest, _1, _2)
	);
	BOOST_REQUIRE(vbiClientHandlerTest.deleteSubscriptionComplete_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.statusCode_ == Success);
	BOOST_REQUIRE(vbiClientHandlerTest.subscriptionId_ == subscriptionId);

	// disconnect session
	vbiClientHandlerTest.sessionStateUpdate_.initEvent();
	client.asyncDisconnect();
	BOOST_REQUIRE(vbiClientHandlerTest.sessionStateUpdate_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.sessionState_ == SS_Disconnect);
	BOOST_REQUIRE(vbiClientHandlerTest.clientHandle_ == 1234);
}

BOOST_AUTO_TEST_SUITE_END()

#endif
