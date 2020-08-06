#include "unittest.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

//
// Certificate configuration (Cert -> Ca)
//
// 		Client Config		Server Config						Result
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
	// delete asneg demo certificate and ca certificate
	//

	//
	// add certificates to asneg demo
	//

	// add asneg demo certificate
	if (certState == Trust) {

	}
	else if (certState == Untrust) {

	}

	// add ca certificate
	if (caState == Trust) {

	}
	else if (caState == Untrust) {

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
	auto statusCode = connectToServer(true, true, Trust, Trust);
	BOOST_REQUIRE(statusCode == Success);
}

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

BOOST_AUTO_TEST_SUITE_END()

#endif
