#include <boost/process/environment.hpp>
#include <boost/process/system.hpp>
#include "unittest.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

//
// Certificate configuration (Cert -> Ca)
//
// 		Client Config		Server Config							Test Result
// ----------------------------------------------------------------------------
// 	001	Cert	Ca			Cert Trust		Ca Trust				OK
//	002	Cert				Cert Trust		Ca Trust				OK
// 	003	Cert	Ca			Cert Trust								ERROR
//	004	Cert				Cert Trust								ERROR
// 	005	Cert	Ca							Ca Trust				ERROR
//	006	Cert								Ca Trust				ERROR
// 	007	Cert	Ca			Cert UnTrust	Ca Trust				ERROR
//	008	Cert				Cert UnTrust	Ca Trust				ERROR
// 	009	Cert	Ca			Cert Trust		Ca UnTrust				ERROR
//	010	Cert				Cert Trust		Ca UnTrust				ERROR
// 	011	Cert	Ca			Cert UnTrust	Ca UnTrust				ERROR
//	012	Cert				Cert UnTrust	Ca UnTrust				ERROR
// 	013	Cert	Ca			Cert Reject		Ca Trust				ERROR
//	014	Cert				Cert Reject		Ca Trust				ERROR
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
	CertState_t caState
)
{
	//
	// set PKI environment
	//
	auto e = boost::this_process::environment();
	e["OPC_UA_PKI_DIR"] = "TestApp:./pki1";
	boost::process::system("mkdir -p ./pki1");

	//
	// delete all test certificates
	//
	BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 cert del TestApp all") == 0);
	BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 im_cert del TestApp all") == 0);
	BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 ca_cert del TestApp all") == 0);

	BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 cert del ASNeG-Demo all") == 0);
	BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 im_cert del ASNeG-Demo all") == 0);
	BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 ca_cert del ASNeG-Demo all") == 0);

	//
	// add certificate to asneg demo
	//
	if (certState == Trust) {
		BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 cert add ASNeG-Demo ../tst/data/test_app1_cert.der") == 0);
	}
	else if (certState == Untrust) {
		BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 cert add ASNeG-Demo ../tst/data/test_app1_cert.der untrust") == 0);
	}
	boost::process::system("OpcUaCtrl4 cert show ASNeG-Demo all");

	//
	// add ca certificate to asneg demo
	//
	if (caState == Trust) {
		BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 ca_cert add ASNeG-Demo ../tst/data/test_ca_cert.der") == 0);
	}
	else if (caState == Untrust) {
		BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 ca_cert add ASNeG-Demo ../tst/data/test_ca_cert.der untrust") == 0);
	}
	boost::process::system("OpcUaCtrl4 ca_cert show ASNeG-Demo all");

	//
	// add cert certificate and key to TestApp
	//
	if (certInChain) {
		BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 appl_cert add TestApp ../tst/data/test_app1_cert.der ../tst/data/test_app1_key.pem") == 0);
	}
	boost::process::system("OpcUaCtrl4 appl_cert show TestApp all");

	//
	// add ca certificate to TestApp
	//
	if (caInChain) {
		BOOST_REQUIRE(boost::process::system("OpcUaCtrl4 ca_cert add TestApp ../tst/data/test_ca_cert.der") == 0);
	}
	boost::process::system("OpcUaCtrl4 ca_cert show TestApp all");

	return Success;
}

BOOST_AUTO_TEST_SUITE(CertificateChain_CertCa_)

BOOST_AUTO_TEST_CASE(CertificateChain_CertCa_)
{
	std::cout << "CertificateChain_CertCa_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertCa_001)
{
	auto statusCode = connectToServer(true, true, Trust, Trust);
	BOOST_REQUIRE(statusCode == Success);
}

#if 0
BOOST_AUTO_TEST_CASE(CertificateChain_CertCa_002)
{
	auto statusCode = connectToServer(true, false, Trust, Trust);
	BOOST_REQUIRE(statusCode == Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertCa_003)
{
	auto statusCode = connectToServer(true, true, Trust, None);
	BOOST_REQUIRE(statusCode != Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertCa_004)
{
	auto statusCode = connectToServer(true, false, Trust, None);
	BOOST_REQUIRE(statusCode != Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertCa_005)
{
	auto statusCode = connectToServer(true, true, None, Trust);
	BOOST_REQUIRE(statusCode != Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertCa_006)
{
	auto statusCode = connectToServer(true, false, None, Trust);
	BOOST_REQUIRE(statusCode != Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertCa_007)
{
	auto statusCode = connectToServer(true, true, Untrust, Trust);
	BOOST_REQUIRE(statusCode != Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertCa_008)
{
	auto statusCode = connectToServer(true, false, Untrust, Trust);
	BOOST_REQUIRE(statusCode != Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertCa_009)
{
	auto statusCode = connectToServer(true, true, Trust, Untrust);
	BOOST_REQUIRE(statusCode != Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertCa_010)
{
	auto statusCode = connectToServer(true, false, Trust, Untrust);
	BOOST_REQUIRE(statusCode != Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertCa_011)
{
	auto statusCode = connectToServer(true, true, Untrust, Untrust);
	BOOST_REQUIRE(statusCode != Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertCa_012)
{
	auto statusCode = connectToServer(true, false, Untrust, Untrust);
	BOOST_REQUIRE(statusCode != Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertCa_013)
{
	auto statusCode = connectToServer(true, true, Reject, Trust);
	BOOST_REQUIRE(statusCode != Success);
}

BOOST_AUTO_TEST_CASE(CertificateChain_CertCa_014)
{
	auto statusCode = connectToServer(true, false, Reject, Trust);
	BOOST_REQUIRE(statusCode != Success);
}
#endif

BOOST_AUTO_TEST_SUITE_END()

#endif
