#include <iostream>

#include "unittest.h"
#include "OpcUaStackCore/Certificate/Certificate.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(TestCertificate_)

BOOST_AUTO_TEST_CASE(TestCertificate_)
{
	std::cout << "TestCertificate_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(TestCertificate__FTestClient)
{
	RSAKey key(2048);
	CertificateInfo info;
	Identity identity;

	info.uri("urn:127.0.0.1:ASNeG:FTestClient");
	info.ipAddresses().push_back("127.0.0.1");
	info.dnsNames().push_back("ASNeG.de");
	info.eMail("info@ASNeG.de");
	info.validTime(boost::posix_time::microsec_clock::local_time() + boost::posix_time::seconds(3600*24*365*5));
	info.serialNumber(123);
	info.validFrom(boost::posix_time::microsec_clock::local_time());

	identity.organization("ASNeG");
	identity.organizationUnit("OPC UA Service Department");
	identity.commonName("FTestClient");
	identity.locality("Neukirchen");
	identity.state("Hessen");
	identity.country("DE");
	identity.domainComponent("asneg.de");

	Certificate certificate(info, identity, key);
	BOOST_REQUIRE(certificate.isError() == false);
	BOOST_REQUIRE(certificate.isSelfSigned() == true);
	BOOST_REQUIRE(certificate.toDERFile("FTestClient.der") == true);
	BOOST_REQUIRE(key.privateKey().toPEMFile("FTestClient.pem", nullptr) == true);
}

BOOST_AUTO_TEST_SUITE_END()
