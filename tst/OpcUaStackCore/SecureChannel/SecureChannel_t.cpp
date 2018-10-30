
#include "unittest.h"
#include "OpcUaStackCore/Base/Condition.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelClient.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelServer.h"
#include "OpcUaStackCore/ServiceSet/GetEndpointsRequest.h"

using namespace OpcUaStackCore;

class SecureChannelClientTest
: public SecureChannelClientIf
{
  public:
	Condition handleConnect_;
	void handleConnect(SecureChannel* secureChannel)
	{
		std::cout << "handleConnect client" << std::endl;
		handleConnect_.conditionValueDec();
	}

	Condition handleDisconnect_;
	void handleDisconnect(SecureChannel* secureChannel)
	{
		std::cout << "handleDisconnect client" << std::endl;
		handleDisconnect_.conditionValueDec();
	}

	Condition handleMessageResponse_;
	void handleMessageResponse(SecureChannel* secureChannel)
	{
		std::cout << "handleMessageResponse client" << std::endl;
		handleMessageResponse_.conditionValueDec();
	}
};

class SecureChannelServerTest
: public SecureChannelServerIf
{
  public:
	SecureChannelServerTest(void)
    : secureChannelServer_(nullptr)
  	{
    }

	Condition handleConnect_;
	void handleConnect(SecureChannel* secureChannel)
	{
		std::cout << "handleConnect server" << std::endl;
		handleConnect_.conditionValueDec();
	}

	Condition handleDisconnect_;
	void handleDisconnect(SecureChannel* secureChannel)
	{
		std::cout << "handleDisconnect server" << std::endl;
		handleDisconnect_.conditionValueDec();
	}

	Condition handleMessageRequest_;
	void handleMessageRequest(SecureChannel* secureChannel)
	{
		std::cout << "handleMessageRequest server" << std::endl;
		handleMessageRequest_.conditionValueDec();

		if (secureChannelServer_ == nullptr) return;

		// send request
		boost::asio::streambuf sb;
		std::iostream os(&sb);
		GetEndpointsRequest getEndpointsRequest;
		getEndpointsRequest.endpointUrl("opc.tcp://127.0.0.1:48012");
		getEndpointsRequest.opcUaBinaryEncode(os);

		SecureChannelTransaction::SPtr secureChannelTransaction = secureChannel->secureChannelTransaction_;
		secureChannelTransaction->responseTypeNodeId_. nodeId((uint32_t)OpcUaId_GetEndpointsResponse_Encoding_DefaultBinary);
		secureChannelTransaction->osAppend(sb);

		secureChannelServer_->asyncWriteMessageResponse(secureChannel, secureChannelTransaction);
	}

	Condition handleEndpointOpen_;
	void handleEndpointOpen(const std::string& endpointUrl)
	{
		std::cout << "handleEndpointOpen server" << std::endl;
		handleEndpointOpen_.conditionValueDec();
	}

	Condition handleEndpointClose_;
	void handleEndpointClose(const std::string& endpointUrl)
	{
		std::cout << "handleEndpointClose server" << std::endl;
		handleEndpointClose_.conditionValueDec();
	}

	SecureChannelServer* secureChannelServer_;
};

BOOST_AUTO_TEST_SUITE(SecureChannel_)

BOOST_AUTO_TEST_CASE(SecureChannel)
{
	std::cout << "SecureChannel_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(SecureChannel_Connect_Disconnect)
{
	//
	// init certificate
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

	//
	// secure channel connect / disconnect
	//
	OpcUaStackCore::SecureChannel* secureChannel;
	SecureChannelServerTest secureChannelServerTest;
	SecureChannelClientTest secureChannelClientTest;

	IOThread ioThread;
	ioThread.startup();

	SecureChannelServer secureChannelServer(&ioThread);
	SecureChannelClient secureChannelClient(&ioThread);
	secureChannelServer.secureChannelServerIf(&secureChannelServerTest);
	secureChannelClient.secureChannelClientIf(&secureChannelClientTest);
	secureChannelServer.applicationCertificate(applicationCertificate);
	secureChannelClient.applicationCertificate(applicationCertificate);

	// server open endpoint
	EndpointDescription::SPtr endpointDescription = constructSPtr<EndpointDescription>();
	endpointDescription->endpointUrl("opt.tcp://127.0.0.1:48010");
	EndpointDescriptionArray::SPtr endpointDescriptionArray = constructSPtr<EndpointDescriptionArray>();
	endpointDescriptionArray->resize(1);
	endpointDescriptionArray->push_back(endpointDescription);

	secureChannelServerTest.handleEndpointOpen_.condition(1,0);
	SecureChannelServerConfig::SPtr secureChannelServerConfig = constructSPtr<SecureChannelServerConfig>();
	secureChannelServerConfig->endpointUrl("opt.tcp://127.0.0.1:48010");
	secureChannelServerConfig->endpointDescriptionArray(endpointDescriptionArray);
	secureChannelServer.accept(secureChannelServerConfig);
	BOOST_REQUIRE(secureChannelServerTest.handleEndpointOpen_.waitForCondition(1000) == true);

	// client connect to server
	secureChannelClientTest.handleConnect_.condition(1,0);
	secureChannelServerTest.handleConnect_.condition(1,0);
	SecureChannelClientConfig::SPtr secureChannelClientConfig = constructSPtr<SecureChannelClientConfig>();
	secureChannelClientConfig->endpointUrl("opt.tcp://127.0.0.1:48010");
	secureChannel = secureChannelClient.connect(secureChannelClientConfig);
	BOOST_REQUIRE(secureChannel != nullptr);
	BOOST_REQUIRE(secureChannelClientTest.handleConnect_.waitForCondition(2000) == true);
	BOOST_REQUIRE(secureChannelServerTest.handleConnect_.waitForCondition(2000) == true);

	// disconnect
	secureChannelClientTest.handleDisconnect_.condition(1,0);
	secureChannelServerTest.handleDisconnect_.condition(1,0);
	secureChannelClient.disconnect(secureChannel);
	BOOST_REQUIRE(secureChannelClientTest.handleDisconnect_.waitForCondition(2000) == true);
	BOOST_REQUIRE(secureChannelServerTest.handleDisconnect_.waitForCondition(2000) == true);

	// disconnect server socket
	secureChannelServerTest.handleEndpointClose_.condition(1,0);
	secureChannelServer.disconnect();
	BOOST_REQUIRE(secureChannelServerTest.handleEndpointClose_.waitForCondition(2000) == true);

	ioThread.shutdown();
}

BOOST_AUTO_TEST_CASE(SecureChannel_Connect_Disconnect_with_a_second_channel)
{
	//
	// init certificate
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

	//
	// connect/disconnect with a second secure channel
	//
	OpcUaStackCore::SecureChannel* secureChannel1;
	OpcUaStackCore::SecureChannel* secureChannel2;
	SecureChannelClientTest secureChannelClientTest;
	SecureChannelServerTest secureChannelServerTest;

	IOThread ioThread;
	ioThread.startup();

	SecureChannelServer secureChannelServer(&ioThread);
	SecureChannelClient secureChannelClient(&ioThread);
	secureChannelServer.secureChannelServerIf(&secureChannelServerTest);
	secureChannelClient.secureChannelClientIf(&secureChannelClientTest);
	secureChannelServer.applicationCertificate(applicationCertificate);
	secureChannelClient.applicationCertificate(applicationCertificate);

	// server open endpoint
	EndpointDescription::SPtr endpointDescription = constructSPtr<EndpointDescription>();
	endpointDescription->endpointUrl("opt.tcp://127.0.0.1:48011");
	EndpointDescriptionArray::SPtr endpointDescriptionArray = constructSPtr<EndpointDescriptionArray>();
	endpointDescriptionArray->resize(1);
	endpointDescriptionArray->push_back(endpointDescription);

	secureChannelServerTest.handleEndpointOpen_.condition(1,0);
	SecureChannelServerConfig::SPtr secureChannelServerConfig = constructSPtr<SecureChannelServerConfig>();
	secureChannelServerConfig->endpointUrl("opt.tcp://127.0.0.1:48011");
	secureChannelServerConfig->endpointDescriptionArray(endpointDescriptionArray);
	secureChannelServer.accept(secureChannelServerConfig);
	BOOST_REQUIRE(secureChannelServerTest.handleEndpointOpen_.waitForCondition(2000) == true);

	// set client endpoint
	SecureChannelClientConfig::SPtr secureChannelClientConfig = constructSPtr<SecureChannelClientConfig>();
	secureChannelClientConfig->endpointUrl("opt.tcp://127.0.0.1:48011");

	// client connect to server
	secureChannelClientTest.handleConnect_.condition(1,0);
	secureChannelServerTest.handleConnect_.condition(1,0);
	secureChannel1 = secureChannelClient.connect(secureChannelClientConfig);
	BOOST_REQUIRE(secureChannel1 != nullptr);
	BOOST_REQUIRE(secureChannelClientTest.handleConnect_.waitForCondition(2000) == true);
	BOOST_REQUIRE(secureChannelServerTest.handleConnect_.waitForCondition(2000) == true);

	// client connect to server
	secureChannelClientTest.handleConnect_.condition(1,0);
	secureChannelServerTest.handleConnect_.condition(1,0);
	secureChannel2 = secureChannelClient.connect(secureChannelClientConfig);
	BOOST_REQUIRE(secureChannel2 != nullptr);
	BOOST_REQUIRE(secureChannelClientTest.handleConnect_.waitForCondition(2000) == true);
	BOOST_REQUIRE(secureChannelServerTest.handleConnect_.waitForCondition(2000) == true);

	// diconnect
	secureChannelClientTest.handleDisconnect_.condition(1,0);
	secureChannelServerTest.handleDisconnect_.condition(1,0);
	secureChannelClient.disconnect(secureChannel1);
	BOOST_REQUIRE(secureChannelClientTest.handleDisconnect_.waitForCondition(2000) == true);
	BOOST_REQUIRE(secureChannelServerTest.handleDisconnect_.waitForCondition(2000) == true);

	// diconnect
	secureChannelClientTest.handleDisconnect_.condition(1,0);
	secureChannelServerTest.handleDisconnect_.condition(1,0);
	secureChannelClient.disconnect(secureChannel2);
	BOOST_REQUIRE(secureChannelClientTest.handleDisconnect_.waitForCondition(2000) == true);
	BOOST_REQUIRE(secureChannelServerTest.handleDisconnect_.waitForCondition(2000) == true);

	// disconnect server socket
	secureChannelServerTest.handleEndpointClose_.condition(1,0);
	secureChannelServer.disconnect();
	BOOST_REQUIRE(secureChannelServerTest.handleEndpointClose_.waitForCondition(2000) == true);

	ioThread.shutdown();
}

BOOST_AUTO_TEST_CASE(SecureChannel_Connect_SendRequest_ReceiveResponse_Disconnect)
{
	//
	// init certificate
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

	//
	// send request, receive response and disconnect
	//
	OpcUaStackCore::SecureChannel* secureChannel;
	SecureChannelClientTest secureChannelClientTest;
	SecureChannelServerTest secureChannelServerTest;

	IOThread ioThread;
	ioThread.startup();

	SecureChannelServer secureChannelServer(&ioThread);
	SecureChannelClient secureChannelClient(&ioThread);
	secureChannelServer.secureChannelServerIf(&secureChannelServerTest);
	secureChannelClient.secureChannelClientIf(&secureChannelClientTest);
	secureChannelServer.applicationCertificate(applicationCertificate);
	secureChannelClient.applicationCertificate(applicationCertificate);

	secureChannelServerTest.secureChannelServer_ = &secureChannelServer;

	// server open endpoint
	EndpointDescription::SPtr endpointDescription = constructSPtr<EndpointDescription>();
	endpointDescription->endpointUrl("opt.tcp://127.0.0.1:48011");
	EndpointDescriptionArray::SPtr endpointDescriptionArray = constructSPtr<EndpointDescriptionArray>();
	endpointDescriptionArray->resize(1);
	endpointDescriptionArray->push_back(endpointDescription);

	secureChannelServerTest.handleEndpointOpen_.condition(1,0);
	SecureChannelServerConfig::SPtr secureChannelServerConfig = constructSPtr<SecureChannelServerConfig>();
	secureChannelServerConfig->endpointUrl("opt.tcp://127.0.0.1:48012");
	secureChannelServerConfig->endpointDescriptionArray(endpointDescriptionArray);
	secureChannelServer.accept(secureChannelServerConfig);
	BOOST_REQUIRE(secureChannelServerTest.handleEndpointOpen_.waitForCondition(2000) == true);

	// client connect to server
	secureChannelClientTest.handleConnect_.condition(1,0);
	secureChannelServerTest.handleConnect_.condition(1,0);
	SecureChannelClientConfig::SPtr secureChannelClientConfig = constructSPtr<SecureChannelClientConfig>();
	secureChannelClientConfig->endpointUrl("opc.tcp://127.0.0.1:48012");
	secureChannel = secureChannelClient.connect(secureChannelClientConfig);
	BOOST_REQUIRE(secureChannel != nullptr);
	BOOST_REQUIRE(secureChannelClientTest.handleConnect_.waitForCondition(2000) == true);
	BOOST_REQUIRE(secureChannelServerTest.handleConnect_.waitForCondition(2000) == true);

	// send request
	boost::asio::streambuf sb;
	std::iostream os(&sb);
	GetEndpointsRequest getEndpointsRequest;
	getEndpointsRequest.endpointUrl("opc.tcp://127.0.0.1:48012");
	getEndpointsRequest.opcUaBinaryEncode(os);

	SecureChannelTransaction::SPtr secureChannelTransaction = constructSPtr<SecureChannelTransaction>();
	secureChannelTransaction->requestTypeNodeId_. nodeId((uint32_t)OpcUaId_GetEndpointsRequest_Encoding_DefaultBinary);
	secureChannelTransaction->requestId_ = 123;
	secureChannelTransaction->osAppend(sb);

	secureChannelClientTest.handleMessageResponse_.condition(1,0);
	secureChannelServerTest.handleMessageRequest_.condition(1,0);
	secureChannelClient.asyncWriteMessageRequest(secureChannel, secureChannelTransaction);
	BOOST_REQUIRE(secureChannelServerTest.handleMessageRequest_.waitForCondition(2000) == true);
	BOOST_REQUIRE(secureChannelClientTest.handleMessageResponse_.waitForCondition(2000) == true);

	// diconnect
	secureChannelClientTest.handleDisconnect_.condition(1,0);
	secureChannelServerTest.handleDisconnect_.condition(1,0);
	secureChannelClient.disconnect(secureChannel);
	BOOST_REQUIRE(secureChannelClientTest.handleDisconnect_.waitForCondition(2000) == true);
	BOOST_REQUIRE(secureChannelServerTest.handleDisconnect_.waitForCondition(2000) == true);

	// disconnect server socket
	secureChannelServerTest.handleEndpointClose_.condition(1,0);
	secureChannelServer.disconnect();
	BOOST_REQUIRE(secureChannelServerTest.handleEndpointClose_.waitForCondition(2000) == true);

	ioThread.shutdown();
}

BOOST_AUTO_TEST_SUITE_END()
