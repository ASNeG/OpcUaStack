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
	BOOST_REQUIRE(certificate.isSelfSigned() == true);
}

BOOST_AUTO_TEST_CASE(Certificate__writeFile)
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
	BOOST_REQUIRE(certificate.isSelfSigned() == true);
	BOOST_REQUIRE(certificate.toDERFile("selfSignedCertificate.DER") == true);
}

BOOST_AUTO_TEST_CASE(Certificate__readFile)
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

	Certificate certificate1(info, identity, key);
	BOOST_REQUIRE(certificate1.isError() == false);
	BOOST_REQUIRE(certificate1.isSelfSigned() == true);
	BOOST_REQUIRE(certificate1.toDERFile("selfSignedCertificate.DER") == true);

	Identity issuer;
	Identity subject;
	Certificate certificate2;
	BOOST_REQUIRE(certificate2.fromDERFile("selfSignedCertificate.DER") == true);
	BOOST_REQUIRE(certificate2.getIssuer(issuer) == true);
	BOOST_REQUIRE(certificate2.getSubject(subject) == true);

	BOOST_REQUIRE(issuer.organization() == identity.organization());
	BOOST_REQUIRE(issuer.organizationUnit() == identity.organizationUnit());
	BOOST_REQUIRE(issuer.commonName() == identity.commonName());
	BOOST_REQUIRE(issuer.locality() == identity.locality());
	BOOST_REQUIRE(issuer.state() == identity.state());
	BOOST_REQUIRE(issuer.country() == identity.country());
	BOOST_REQUIRE(issuer.domainComponent() == identity.domainComponent());

	BOOST_REQUIRE(subject.organization() == identity.organization());
	BOOST_REQUIRE(subject.organizationUnit() == identity.organizationUnit());
	BOOST_REQUIRE(subject.commonName() == identity.commonName());
	BOOST_REQUIRE(subject.locality() == identity.locality());
	BOOST_REQUIRE(subject.state() == identity.state());
	BOOST_REQUIRE(subject.country() == identity.country());
	BOOST_REQUIRE(subject.domainComponent() == identity.domainComponent());
}

BOOST_AUTO_TEST_SUITE_END()
