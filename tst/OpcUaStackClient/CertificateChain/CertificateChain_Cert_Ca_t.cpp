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
// 		Client Config			Server Config										Test Result
// ---------------------------------------------------------------------------------------------
// 	001	Cert	Im	Ca			Cert Trust		Im Trust	Ca Trust				OK
//	002	Cert	Im 				Cert Trust		Im Trust	Ca Trust				OK
// 	003	Cert	Im	Ca			Cert Trust		Im Trust							OK
//	004	Cert	Im				Cert Trust		Im Trust							ERROR		(Rule 1)
// 	005	Cert	Im	Ca							Im Trust	Ca Trust				OK
//	006	Cert	Im								Im Trust	Ca Trust				OK
// 	007	Cert	Im	Ca			Cert UnTrust	Im Trust	Ca Trust				ERROR		(Rule 3)
//	008	Cert	Im 				Cert UnTrust	Im Trust	Ca Trust				ERROR		(Rule 3)
// 	009	Cert	Im	Ca			Cert Trust		Im Trust	Ca UnTrust				ERROR		(Rule 3)
//	010	Cert	Im				Cert Trust		Im Trust	Ca UnTrust				ERROR		(Rule 3)
// 	011	Cert	Im	Ca			Cert UnTrust	Im Trust	Ca UnTrust				ERROR		(Rule 3)
//	012	Cert	Im				Cert UnTrust	Im Trust	Ca UnTrust				ERROR		(Rule 3)
// 	013	Cert	Im	Ca			Cert Reject		Im Trust	Ca Trust				ERROR		(Rule 3)
//	014	Cert	Im				Cert Reject		Im Trust	Ca Trust				ERROR		(Rule 3)

// 	015	Cert	Im	Ca			Cert Trust					Ca Trust				OK
//	016	Cert	Im 				Cert Trust					Ca Trust				OK
// 	017	Cert	Im	Ca			Cert Trust											OK
//	018	Cert	Im				Cert Trust											ERROR		(Rule 1)
// 	019	Cert	Im	Ca										Ca Trust				OK
//	020	Cert	Im											Ca Trust				OK
// 	021	Cert	Im	Ca			Cert UnTrust				Ca Trust				ERROR		(Rule 3)
//	022	Cert	Im 				Cert UnTrust				Ca Trust				ERROR		(Rule 3)
// 	023	Cert	Im	Ca			Cert Trust					Ca UnTrust				ERROR		(Rule 3)
//	024	Cert	Im				Cert Trust					Ca UnTrust				ERROR		(Rule 3)
// 	025	Cert	Im	Ca			Cert UnTrust				Ca UnTrust				ERROR		(Rule 3)
//	026	Cert	Im				Cert UnTrust				Ca UnTrust				ERROR		(Rule 3)
// 	027	Cert	Im	Ca			Cert Reject					Ca Trust				ERROR		(Rule 3)
//	028	Cert	Im				Cert Reject					Ca Trust				ERROR		(Rule 3)
//
//  029 Cert									Im Trust	Ca Trust				OK
//  030 Cert									Im Untrust	Ca Trust				ERROR		(Rule3)
//  031 Cert												Ca Trust				ERROR		(Rule1)
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
	bool imInChain,
	bool caInChain,
	CertState_t certState,
	CertState_t imState,
	CertState_t caState,
	const std::string& sessionName
)
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
		BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 cert add ASNeG-Demo ../tst/data/test_app2_cert.der") == 0);
	}
	else if (certState == Untrust || certState == Reject) {
		BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 cert add ASNeG-Demo ../tst/data/test_app2_cert.der untrust") == 0);
	}

	//
	// add intermediate certificate to asneg demo
	//
	if (imState == Trust) {
		BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 im_cert add ASNeG-Demo ../tst/data/test_im_cert.der") == 0);
	}
	else if (imState == Untrust) {
		BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 im_cert add ASNeG-Demo ../tst/data/test_im_cert.der untrust") == 0);
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
		BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 appl_cert add TestApp ../tst/data/test_app2_cert.der ../tst/data/test_app2_key.pem") == 0);
	}

	//
	// add intermediate certificate and key to TestApp
	//
	if (imInChain) {
		BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 im_cert add TestApp ../tst/data/test_im_cert.der") == 0);
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

	std::cout << "OpcUaCtrl4 im_cert show ASNeG-Demo all" << std::endl;
	boost::process::system("OpcUaCtrl4 im_cert show ASNeG-Demo all");

	std::cout << "OpcUaCtrl4 ca_cert show ASNeG-Demo all" << std::endl;
	boost::process::system("OpcUaCtrl4 ca_cert show ASNeG-Demo all");

	std::cout << "OpcUaCtrl4 appl_cert show TestApp all" << std::endl;
	boost::process::system("OpcUaCtrl4 appl_cert show TestApp all");

	std::cout << "OpcUaCtrl4 cert show TestApp all" << std::endl;
	boost::process::system("OpcUaCtrl4 cert show TestApp all");

	std::cout << "OpcUaCtrl4 im_cert show TestApp all" << std::endl;
	boost::process::system("OpcUaCtrl4 im_cert show TestApp all");

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

BOOST_AUTO_TEST_SUITE(CertificateChain_CertImCa_)

BOOST_AUTO_TEST_CASE(CertificateChain_CertImCa_)
{
	std::cout << "CertificateChain_CertImCa_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertImCa_001)
{
	auto statusCode = connectToServer(true, true, true, Trust, Trust, Trust, "CertificateChain_CertImCa_001");
	BOOST_REQUIRE(statusCode == Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertImCa_002)
{
	auto statusCode = connectToServer(true, true, false, Trust, Trust, Trust, "CertificateChain_CertImCa_002");
	BOOST_REQUIRE(statusCode == Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertImCa_003)
{
	auto statusCode = connectToServer(true, true, true, Trust, Trust, None, "CertificateChain_CertImCa_003");
	BOOST_REQUIRE(statusCode == Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertImCa_004)
{
	auto statusCode = connectToServer(true, true, false, Trust, Trust, None, "CertificateChain_CertImCa_004");
	BOOST_REQUIRE(statusCode != Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertImCa_005)
{
	auto statusCode = connectToServer(true, true, true, None, Trust, Trust, "CertificateChain_CertImCa_005");
	BOOST_REQUIRE(statusCode == Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertImCa_006)
{
	auto statusCode = connectToServer(true, true, false, None, Trust, Trust, "CertificateChain_CertImCa_006");
	BOOST_REQUIRE(statusCode == Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertImCa_007)
{
	auto statusCode = connectToServer(true, true, true, Untrust, Trust, Trust, "CertificateChain_CertImCa_007");
	BOOST_REQUIRE(statusCode != Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertImCa_008)
{
	auto statusCode = connectToServer(true, true, false, Untrust, Trust, Trust, "CertificateChain_CertImCa_008");
	BOOST_REQUIRE(statusCode != Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertImCa_009)
{
	auto statusCode = connectToServer(true, true, true, Trust, Trust, Untrust, "CertificateChain_CertImCa_009");
	BOOST_REQUIRE(statusCode != Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertImCa_010)
{
	auto statusCode = connectToServer(true, true, false, Trust, Trust, Untrust, "CertificateChain_CertImCa_010");
	BOOST_REQUIRE(statusCode != Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertImCa_011)
{
	auto statusCode = connectToServer(true, true, true, Untrust, Trust, Untrust, "CertificateChain_CertImCa_011");
	BOOST_REQUIRE(statusCode != Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertImCa_012)
{
	auto statusCode = connectToServer(true, true, false, Untrust, Trust, Untrust, "CertificateChain_CertImCa_012");
	BOOST_REQUIRE(statusCode != Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertImCa_013)
{
	auto statusCode = connectToServer(true, true, true, Reject, Trust, Trust, "CertificateChain_CertImCa_013");
	BOOST_REQUIRE(statusCode != Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertImCa_014)
{
	auto statusCode = connectToServer(true, true, false, Reject, Trust, Trust, "CertificateChain_CertImCa_014");
	BOOST_REQUIRE(statusCode != Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertImCa_015)
{
	auto statusCode = connectToServer(true, true, true, Trust, None, Trust, "CertificateChain_CertImCa_015");
	BOOST_REQUIRE(statusCode == Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertImCa_016)
{
	auto statusCode = connectToServer(true, true, false, Trust, None, Trust, "CertificateChain_CertImCa_016");
	BOOST_REQUIRE(statusCode == Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertImCa_017)
{
	auto statusCode = connectToServer(true, true, true, Trust, None, None, "CertificateChain_CertImCa_017");
	BOOST_REQUIRE(statusCode == Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertImCa_018)
{
	auto statusCode = connectToServer(true, true, false, Trust, None, None, "CertificateChain_CertImCa_018");
	BOOST_REQUIRE(statusCode != Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertImCa_019)
{
	auto statusCode = connectToServer(true, true, true, None, None, Trust, "CertificateChain_CertImCa_019");
	BOOST_REQUIRE(statusCode == Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertImCa_020)
{
	auto statusCode = connectToServer(true, true, false, None, None, Trust, "CertificateChain_CertImCa_020");
	BOOST_REQUIRE(statusCode == Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertImCa_021)
{
	auto statusCode = connectToServer(true, true, true, Untrust, None, Trust, "CertificateChain_CertImCa_021");
	BOOST_REQUIRE(statusCode != Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertImCa_022)
{
	auto statusCode = connectToServer(true, true, false, Untrust, None, Trust, "CertificateChain_CertImCa_022");
	BOOST_REQUIRE(statusCode != Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertImCa_023)
{
	auto statusCode = connectToServer(true, true, true, Trust, None, Untrust, "CertificateChain_CertImCa_023");
	BOOST_REQUIRE(statusCode != Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertImCa_024)
{
	auto statusCode = connectToServer(true, true, false, Trust, None, Untrust, "CertificateChain_CertImCa_024");
	BOOST_REQUIRE(statusCode != Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertImCa_025)
{
	auto statusCode = connectToServer(true, true, true, Untrust, None, Untrust, "CertificateChain_CertImCa_025");
	BOOST_REQUIRE(statusCode != Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertImCa_026)
{
	auto statusCode = connectToServer(true, true, false, Untrust, None, Untrust, "CertificateChain_CertImCa_026");
	BOOST_REQUIRE(statusCode != Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertImCa_027)
{
	auto statusCode = connectToServer(true, true, true, Reject, None, Trust, "CertificateChain_CertImCa_027");
	BOOST_REQUIRE(statusCode != Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertImCa_028)
{
	auto statusCode = connectToServer(true, true, false, Reject, None, Trust, "CertificateChain_CertImCa_028");
	BOOST_REQUIRE(statusCode != Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertImCa_029)
{
	auto statusCode = connectToServer(true, false, false, None, Trust, Trust, "CertificateChain_CertImCa_029");
	BOOST_REQUIRE(statusCode == Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertImCa_030)
{
	auto statusCode = connectToServer(true, false, false, None, Untrust, Trust, "CertificateChain_CertImCa_030");
	BOOST_REQUIRE(statusCode != Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertImCa_031)
{
	auto statusCode = connectToServer(true, false, false, None, None, Trust, "CertificateChain_CertImCa_031");
	BOOST_REQUIRE(statusCode != Success);
}

BOOST_AUTO_TEST_SUITE_END()

#endif
