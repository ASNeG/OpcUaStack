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
	CertificateInfo info;
	Identity identity;

	info.uri("urn:localhost:ASNeG:MyServiceApplication");
	info.ipAddresses().push_back("127.0.0.1");
	info.dnsNames().push_back("ASNeG.de");
	info.eMail("info@ASNeG.de");
	info.validTime(boost::posix_time::microsec_clock::local_time() + boost::posix_time::seconds(3600*24*365*5));
	info.serialNumber(123);
	info.validFrom(boost::posix_time::microsec_clock::local_time());

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

BOOST_AUTO_TEST_CASE(Certificate__get_public_key_from_certificate)
{
	RSAKey key(2048);
	CertificateInfo info;
	Identity identity;

	info.uri("urn:localhost:ASNeG:MyServiceApplication");
	info.ipAddresses().push_back("127.0.0.1");
	info.dnsNames().push_back("ASNeG.de");
	info.eMail("info@ASNeG.de");
	info.validTime(boost::posix_time::microsec_clock::local_time() + boost::posix_time::seconds(3600*24*365*5));
	info.serialNumber(123);
	info.validFrom(boost::posix_time::microsec_clock::local_time());

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

	PublicKey p1 = certificate.publicKey();
	PublicKey p2 = certificate.publicKey();
	PublicKey p3 = certificate.publicKey();
	PublicKey p4 = certificate.publicKey();
	PublicKey p5 = certificate.publicKey();
}

BOOST_AUTO_TEST_CASE(Certificate__multiple_certificates)
{
	RSAKey key(2048);
	CertificateInfo info;
	Identity identity;

	info.uri("urn:localhost:ASNeG:MyServiceApplication");
	info.ipAddresses().push_back("127.0.0.1");
	info.dnsNames().push_back("ASNeG.de");
	info.eMail("info@ASNeG.de");
	info.validTime(boost::posix_time::microsec_clock::local_time() + boost::posix_time::seconds(3600*24*365*5));
	info.serialNumber(123);
	info.validFrom(boost::posix_time::microsec_clock::local_time());

	identity.organization("ASNeG");
	identity.organizationUnit("OPC UA Service Department");
	identity.commonName("MyServiceApplication");
	identity.locality("Neukirchen");
	identity.state("Hessen");
	identity.country("DE");
	identity.domainComponent("asneg.de");

	Certificate::SPtr certificate1 = boost::make_shared<Certificate>(info, identity, key);
	BOOST_REQUIRE(certificate1->isError() == false);
	BOOST_REQUIRE(certificate1->isSelfSigned() == true);

	Certificate::SPtr certificate2 = boost::make_shared<Certificate>(info, identity, key);
	BOOST_REQUIRE(certificate2->isError() == false);
	BOOST_REQUIRE(certificate2->isSelfSigned() == true);

	Certificate::SPtr certificate3 = boost::make_shared<Certificate>(info, identity, key);
	BOOST_REQUIRE(certificate3->isError() == false);
	BOOST_REQUIRE(certificate3->isSelfSigned() == true);
}

BOOST_AUTO_TEST_CASE(Certificate__writeFile)
{
	RSAKey key(2048);
	CertificateInfo info;
	Identity identity;

	info.uri("urn:localhost:ASNeG:MyServiceApplication");
	info.ipAddresses().push_back("127.0.0.1");
	info.dnsNames().push_back("ASNeG.de");
	info.eMail("info@ASNeG.de");
	info.validTime(boost::posix_time::microsec_clock::local_time() + boost::posix_time::seconds(3600*24*365*5));
	info.serialNumber(123);
	info.validFrom(boost::posix_time::microsec_clock::local_time());

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
	boost::posix_time::ptime from = boost::posix_time::microsec_clock::local_time();
	boost::posix_time::ptime to = boost::posix_time::microsec_clock::local_time() + boost::posix_time::seconds(3600*24*365*5);

	RSAKey key(2048);
	CertificateInfo info1, info2;
	Identity identity;

	info1.uri("urn:localhost:ASNeG:MyServiceApplication");
	info1.ipAddresses().push_back("127.0.0.1");
	info1.dnsNames().push_back("ASNeG.de");
	info1.eMail("info@ASNeG.de");
	info1.validTime(to);
	info1.serialNumber(123);
	info1.validFrom(from);

	identity.organization("ASNeG");
	identity.organizationUnit("OPC UA Service Department");
	identity.commonName("MyServiceApplication");
	identity.locality("Neukirchen");
	identity.state("Hessen");
	identity.country("DE");
	identity.domainComponent("asneg.de");

	Certificate certificate1(info1, identity, key);
	BOOST_REQUIRE(certificate1.isError() == false);
	BOOST_REQUIRE(certificate1.isSelfSigned() == true);
	BOOST_REQUIRE(certificate1.toDERFile("selfSignedCertificate.DER") == true);

	Identity issuer;
	Identity subject;
	Certificate certificate2;
	BOOST_REQUIRE(certificate2.fromDERFile("selfSignedCertificate.DER") == true);
	BOOST_REQUIRE(certificate2.getIssuer(issuer) == true);
	BOOST_REQUIRE(certificate2.getSubject(subject) == true);
	BOOST_REQUIRE(certificate2.getInfo(info2) == true);

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

	BOOST_REQUIRE(info2.uri() == "urn:localhost:ASNeG:MyServiceApplication");
	BOOST_REQUIRE(info2.ipAddresses().size() == 1);
	BOOST_REQUIRE(info2.ipAddresses().front() == "127.0.0.1");
	BOOST_REQUIRE(info2.dnsNames().size() == 1);
	BOOST_REQUIRE(info2.dnsNames().front() == "ASNeG.de");
	BOOST_REQUIRE(info2.eMail() == "info@ASNeG.de");
	BOOST_REQUIRE(info2.serialNumber() == 123);
	//BOOST_REQUIRE(info2.validFrom() == from);
	//BOOST_REQUIRE(info2.validTime() == to);

	//std::cout << info2.validFrom() << " " << from << std::endl;
	//std::cout << info2.validTime() << " " << to << std::endl;

	CertificateExtension ce(certificate2.isSelfSigned());
	BOOST_REQUIRE(certificate2.getExtension(ce) == true);
	std::cout << ce.subjectKeyIdentifier() << std::endl;
}

BOOST_AUTO_TEST_CASE(Certificate__certificate_to_OpcUaByteString)
{
	RSAKey key(2048);
	CertificateInfo info;
	Identity identity;

	info.uri("urn:localhost:ASNeG:MyServiceApplication");
	info.ipAddresses().push_back("127.0.0.1");
	info.dnsNames().push_back("ASNeG.de");
	info.eMail("info@ASNeG.de");
	info.validTime(boost::posix_time::microsec_clock::local_time() + boost::posix_time::seconds(3600*24*365*5));
	info.serialNumber(123);
	info.validFrom(boost::posix_time::microsec_clock::local_time());

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

	OpcUaByteString derBuf1;
	BOOST_REQUIRE(certificate.toDERBuf(derBuf1) == true);

	OpcUaByteString derBuf2;
	BOOST_REQUIRE(certificate.toDERBuf(derBuf2) == true);

	BOOST_REQUIRE(derBuf1 == derBuf2);
}

BOOST_AUTO_TEST_SUITE_END()
