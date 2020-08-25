#include <boost/process/system.hpp>
#include "unittest.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"
#include "OpcUaStackClient/ValueBasedInterface/VBIClient.h"
#include "OpcUaStackClient/CryptoManagerTest.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

#ifdef REAL_SERVER

BOOST_AUTO_TEST_SUITE(Certificate_RejectFolder_)

OpcUaStatusCode Certificate_RejectFolder_ConnectToServer(
	const std::string& sessionName
)
{
	//
	// create certificate manager for opc ua client (TestApp)
	//
	auto certificateManager = boost::make_shared<CertificateManager>();
	certificateManager->certificateTrustListLocation("./pki1/trusted/certs/");
	certificateManager->certificateRejectListLocation("./pki1/reject/certs/.");
	certificateManager->certificateRevocationListLocation("./pki1/trusted/crl/");
	certificateManager->issuersCertificatesLocation("./pki1/issuers/certs/");
	certificateManager->issuersRevocationListLocation("./pki1/issuers/crl/");
	certificateManager->ownCertificateFile("./pki1/own/certs/TestApp.der");
	certificateManager->ownPrivateKeyFile("./pki1/own/private/TestApp.pem");
	certificateManager->init();

	//
	// load application certificate
	//
	auto& certificateSettings = certificateManager->certificateSettings();
	certificateSettings.enable(true);
	certificateSettings.generateCertificate(false);

	auto applicationCertificate = boost::make_shared<ApplicationCertificate>();
	BOOST_REQUIRE(applicationCertificate->init(certificateManager) == true);

	//
	// init crypto manager
	//
	auto cryptoManager = boost::make_shared<CryptoManager>();
	cryptoManager->certificateManager(certificateManager);
	cryptoManager->applicationCertificate(applicationCertificate);

	//
	// connect session
	//
	VBIClient client;

	// set session change callback
	Condition cond;
	SessionServiceStateId sessionStateId;
	client.setSessionChangeHandler(
		[&cond, &sessionStateId] (SessionBase& session, SessionServiceStateId sessionState) {
			if (sessionState == SessionServiceStateId::Established ||
				sessionState == SessionServiceStateId::Disconnected) {
				sessionStateId = sessionState;
				cond.sendEvent();
			}
		}
	);

	// connect to server
	std::string applicationUri = std::string("urn:") + CryptoManagerTest::getServerHostName() + std::string(":ASNeG:ASNeG-Demo");
	ConnectContext connectContext;
	connectContext.discoveryUrl_ = REAL_SERVER_URI;
	connectContext.sessionName_ = sessionName;
	connectContext.applicationUri_ = applicationUri;					// needed to detect right certificate
	connectContext.securityMode_ = MessageSecurityMode::EnumSignAndEncrypt;	// security mode
	connectContext.securityPolicy_ = SecurityPolicy::EnumBasic128Rsa15;		// security policy
	connectContext.cryptoManager_ = cryptoManager;
	connectContext.secureChannelLog_ = true;
	cond.initEvent();
	client.asyncConnect(connectContext);
	BOOST_REQUIRE(cond.waitForEvent(3000) == true);
	if (sessionStateId == SessionServiceStateId::Disconnected) {
		return BadCommunicationError;
	}

	//
	// disconnect session
	//
	if (sessionStateId == SessionServiceStateId::Established) {
		cond.initEvent();
		client.asyncDisconnect();
		BOOST_REQUIRE(cond.waitForEvent(3000) == true);
		BOOST_REQUIRE(sessionStateId == SessionServiceStateId::Disconnected);
	}

	return Success;
}

BOOST_AUTO_TEST_CASE(Certificate_RejectFolder_)
{
	std::cout << "Certificate_RejectFolder_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(Certificate_RejectFolder_clean_certs)
{
	//
	// set PKI environment
	//
	// Path: /tmp/etc/OpcUaStack/ASNeG-Demo/pki
	//       If this directory exist we assume that we run the test with docker
	//
	if (boost::filesystem::exists(boost::filesystem::path("/tmp/etc/OpcUaStack/ASNeG-Demo/pki"))) {
		setenv("OPC_UA_PKI_DIR", "TestApp:./pki1:ASNeG-Demo:/tmp/etc/OpcUaStack/ASNeG-Demo/pki", 1); // FIXME: todo
	}
	else {
		setenv("OPC_UA_PKI_DIR", "TestApp:./pki1", 1);
	}
	boost::process::system("mkdir -p ./pki1");

	// remove all trusted certificates from TestApp
	BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 cert del TestApp all") == 0);
	BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 im_cert del TestApp all") == 0);
	BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 ca_cert del TestApp all") == 0);
	BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 appl_cert del TestApp") == 0);

	// remove all trusted certificates from ASNeG-Demo
	BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 cert del ASNeG-Demo all") == 0);
	BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 im_cert del ASNeG-Demo all") == 0);
	BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 ca_cert del ASNeG-Demo all") == 0);

	// add application certificate to TestApp
	BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 appl_cert add TestApp ../tst/data/test_app1_cert.der ../tst/data/test_app1_key.pem") == 0);

	// get server certificate
	BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 appl_cert get ASNeG-Demo server_cert.der server_key.pem") == 0);
}

BOOST_AUTO_TEST_CASE(Certificate_RejectFolder_NoTrustedCerts)
{
	// opc ua client connects to opc ua server. The server certificate dosn't exist
	// in the client pki and the opc ua client stores the server certificate in the
	// reject folder.
	auto status = Certificate_RejectFolder_ConnectToServer("Certificate_RejectFolder_NoTrustedCerts");
	BOOST_REQUIRE(status != Success);

	// The server certificate in the client pki is in unstrusted state
	BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 cert show TestApp") == 0);
}

BOOST_AUTO_TEST_CASE(Certificate_RejectFolder_ClientTrustServerCert)
{
	// The opc ua client trust the server certificate
	BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 cert del TestApp all") == 0);
	BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 cert add TestApp server_cert.der") == 0);
	BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 cert show TestApp") == 0);

	// opc ua client connects to opc ua server.
	auto status = Certificate_RejectFolder_ConnectToServer("Certificate_RejectFolder_ClientTrustServerCert");
	BOOST_REQUIRE(status != Success);

	// The Client certificate in the server pki is in unstrusted state
	BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 cert show ASNeG-Demo") == 0);
}

BOOST_AUTO_TEST_CASE(Certificate_RejectFolder_ServerTrustClientCert)
{
	// The opc ua server trust the client certificate
	BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 cert del ASNeG-Demo all") == 0);
	BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 cert add ASNeG-Demo ../tst/data/test_app1_cert.der") == 0);
	BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 cert show ASNeG-Demo") == 0);

	// Add CA certificate to opc ua server
	BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 ca_cert add ASNeG-Demo ../tst/data/test_ca_cert.der") == 0);
	BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 ca_cert show ASNeG-Demo") == 0);

	// opc ua client connects to opc ua server.
	auto status = Certificate_RejectFolder_ConnectToServer("Certificate_RejectFolder_ServerTrustClientCert");
	BOOST_REQUIRE(status == Success);
}

BOOST_AUTO_TEST_SUITE_END()

#endif
