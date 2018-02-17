#include <iostream>

#include "unittest.h"
#include "OpcUaStackCore/Certificate/Certificate.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(Certificate_)

BOOST_AUTO_TEST_CASE(Certificate_)
{
	std::cout << "Certificate_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(Certificate__createSelfSignedCertificate)
{
	RSAKey key(2048);
	Info info;
	Identity identity;

	info.uri("urn:localhost:ASNeG:MyServiceApplication");
	info.ipAddresses().push_back("127.0.0.1");
	info.dnsNames().push_back("ASNeG.de");
	info.eMail("info@ASNeG.de");
	info.validTime(3600*24*5);
	info.serialNumber(123);
	info.validFrom(0);

	identity.organization("ASNeG");
	identity.organizationUnit("OPC UA Service Department");
	identity.commonName("MyServiceApplication");
	identity.locality("Neukirchen");
	identity.state("Hessen");
	identity.country("DE");
	identity.domainComponent("asneg.de");

	Certificate certificate(info, identity, key);
	BOOST_REQUIRE(certificate.isError() == false);

}

BOOST_AUTO_TEST_SUITE_END()
