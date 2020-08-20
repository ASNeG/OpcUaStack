#include <boost/process/system.hpp>
#include "unittest.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"
#include "OpcUaStackClient/ValueBasedInterface/VBIClient.h"
#include "OpcUaStackClient/CryptoManagerTest.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

//
// Certificate configuration (Cert -> Ca)
//
// 		Client Config		Server Config							Test Result
// ----------------------------------------------------------------------------
// 	001	Cert	Ca			Cert Trust		Ca Trust				OK
//	002	Cert				Cert Trust		Ca Trust				OK
// 	003	Cert	Ca			Cert Trust								OK
//	004	Cert				Cert Trust								ERROR		(Rule 1)
// 	005	Cert	Ca							Ca Trust				OK
//	006	Cert								Ca Trust				OK
// 	007	Cert	Ca			Cert UnTrust	Ca Trust				ERROR		(Rule 3)
//	008	Cert				Cert UnTrust	Ca Trust				ERROR		(Rule 3)
// 	009	Cert	Ca			Cert Trust		Ca UnTrust				ERROR		(Rule 3)
//	010	Cert				Cert Trust		Ca UnTrust				ERROR		(Rule 3)
// 	011	Cert	Ca			Cert UnTrust	Ca UnTrust				ERROR		(Rule 3)
//	012	Cert				Cert UnTrust	Ca UnTrust				ERROR		(Rule 3)
// 	013	Cert	Ca			Cert Reject		Ca Trust				ERROR		(Rule 3)
//	014	Cert				Cert Reject		Ca Trust				ERROR		(Rule 3)
//
// Rules:
// 1. The opc ua server must be create a completely certificate chain.
// 2. At least one certificate in the certificate chain must be trusted.
// 3. No certificate may be untrusted or rejected.
//

typedef enum {
	None,
	Trust,
	Untrust,
	Reject
} CertState_t;

#ifdef REAL_SERVER

OpcUaStatusCode
connectToServer(
	bool certInChain,
	bool caInChain,
	CertState_t certState,
	CertState_t caState,
	const std::string& sessionName
)
{
	//
	// set PKI environment
	//
	setenv("OPC_UA_PKI_DIR", "TestApp:./pki1", 1);
	boost::process::system("mkdir -p ./pki1");

	//
	// delete all test certificates
	//
	BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 cert del TestApp all") == 0);
	BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 im_cert del TestApp all") == 0);
	BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 ca_cert del TestApp all") == 0);
	BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 appl_cert del TestApp") == 0);

	BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 cert del ASNeG-Demo all") == 0);
	BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 im_cert del ASNeG-Demo all") == 0);
	BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 ca_cert del ASNeG-Demo all") == 0);

	//
	// add certificate to asneg demo
	//
	if (certState == Trust) {
		BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 cert add ASNeG-Demo ../tst/data/test_app1_cert.der") == 0);
	}
	else if (certState == Untrust || certState == Reject) {
		BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 cert add ASNeG-Demo ../tst/data/test_app1_cert.der untrust") == 0);
	}

	//
	// add ca certificate to asneg demo
	//
	if (caState == Trust) {
		BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 ca_cert add ASNeG-Demo ../tst/data/test_ca_cert.der") == 0);
	}
	else if (caState == Untrust) {
		BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 ca_cert add ASNeG-Demo ../tst/data/test_ca_cert.der untrust") == 0);
	}

	//
	// add cert certificate and key to TestApp
	//
	if (certInChain) {
		BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 appl_cert add TestApp ../tst/data/test_app1_cert.der ../tst/data/test_app1_key.pem") == 0);
	}

	//
	// add ca certificate to TestApp
	//
	if (caInChain) {
		BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 ca_cert add TestApp ../tst/data/test_ca_cert.der") == 0);
	}

	//
	// get certificate from ASNeG-Demo server and save it in local trusted folder
	//
	BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 appl_cert get ASNeG-Demo ./asneg_demo_cert.der ./asneg_demo_key.pem") == 0);
	BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 cert add TestApp ./asneg_demo_cert.der") == 0);


	//
	// display some infos about the certificates
	//
	std::cout << "OpcUaCtrl4 appl_cert show ASNeG-Demo all" << std::endl;
	boost::process::system("OpcUaCtrl4 appl_cert show ASNeG-Demo all");

	std::cout << "OpcUaCtrl4 cert show ASNeG-Demo all" << std::endl;
	boost::process::system("OpcUaCtrl4 cert show ASNeG-Demo all");

	std::cout << "OpcUaCtrl4 ca_cert show ASNeG-Demo all" << std::endl;
	boost::process::system("OpcUaCtrl4 ca_cert show ASNeG-Demo all");

	std::cout << "OpcUaCtrl4 appl_cert show TestApp all" << std::endl;
	boost::process::system("OpcUaCtrl4 appl_cert show TestApp all");

	std::cout << "OpcUaCtrl4 cert show TestApp all" << std::endl;
	boost::process::system("OpcUaCtrl4 cert show TestApp all");

	std::cout << "OpcUaCtrl4 ca_cert show TestApp all" << std::endl;
	boost::process::system("OpcUaCtrl4 ca_cert show TestApp all");

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
	connectContext.endpointUrl_ = REAL_SERVER_URI;
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

BOOST_AUTO_TEST_SUITE(CertificateChain_CertCa_)

BOOST_AUTO_TEST_CASE(CertificateChain_CertCa_)
{
	std::cout << "CertificateChain_CertCa_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertCa_001)
{
	auto statusCode = connectToServer(true, true, Trust, Trust, "CertificateChain_CertCa_001");
	BOOST_REQUIRE(statusCode == Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertCa_002)
{
	auto statusCode = connectToServer(true, false, Trust, Trust, "CertificateChain_CertCa_002");
	BOOST_REQUIRE(statusCode == Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertCa_003)
{
	auto statusCode = connectToServer(true, true, Trust, None, "CertificateChain_CertCa_003");
	BOOST_REQUIRE(statusCode == Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertCa_004)
{
	auto statusCode = connectToServer(true, false, Trust, None, "CertificateChain_CertCa_004");
	BOOST_REQUIRE(statusCode != Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertCa_005)
{
	auto statusCode = connectToServer(true, true, None, Trust, "CertificateChain_CertCa_005");
	BOOST_REQUIRE(statusCode == Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertCa_006)
{
	auto statusCode = connectToServer(true, false, None, Trust, "CertificateChain_CertCa_006");
	BOOST_REQUIRE(statusCode == Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertCa_007)
{
	auto statusCode = connectToServer(true, true, Untrust, Trust, "CertificateChain_CertCa_007");
	BOOST_REQUIRE(statusCode != Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertCa_008)
{
	auto statusCode = connectToServer(true, false, Untrust, Trust, "CertificateChain_CertCa_008");
	BOOST_REQUIRE(statusCode != Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertCa_009)
{
	auto statusCode = connectToServer(true, true, Trust, Untrust, "CertificateChain_CertCa_009");
	BOOST_REQUIRE(statusCode != Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertCa_010)
{
	auto statusCode = connectToServer(true, false, Trust, Untrust, "CertificateChain_CertCa_010");
	BOOST_REQUIRE(statusCode != Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertCa_011)
{
	auto statusCode = connectToServer(true, true, Untrust, Untrust, "CertificateChain_CertCa_011");
	BOOST_REQUIRE(statusCode != Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertCa_012)
{
	auto statusCode = connectToServer(true, false, Untrust, Untrust, "CertificateChain_CertCa_012");
	BOOST_REQUIRE(statusCode != Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertCa_013)
{
	auto statusCode = connectToServer(true, true, Reject, Trust, "CertificateChain_CertCa_013");
	BOOST_REQUIRE(statusCode != Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertCa_014)
{
	auto statusCode = connectToServer(true, false, Reject, Trust, "CertificateChain_CertCa_014");
	BOOST_REQUIRE(statusCode != Success);
}

BOOST_AUTO_TEST_SUITE_END()

#endif
