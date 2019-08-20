#include <iostream>

#include "unittest.h"
#include "OpcUaStackCore/Certificate/CertificateChain.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(CertificateChain_)

Certificate::SPtr createCertificate(void)
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

	return boost::make_shared<Certificate>(info, identity, key);
}

BOOST_AUTO_TEST_CASE(CertificateChain_)
{
	std::cout << "CertificateChain_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(CertificateChain_encode_decode)
{
	// create certificate chain
	CertificateChain certificateChain1;
	for (uint32_t idx=0; idx<10; idx++) {
		Certificate::SPtr certificate = createCertificate();
		certificateChain1.addCertificate(certificate);
	}

	// encode certificate chain
	OpcUaByteString byteString;
	BOOST_REQUIRE(certificateChain1.toByteString(byteString) == true);

	// decode certificate chain
	CertificateChain certificateChain2;
	BOOST_REQUIRE(certificateChain2.fromByteString(byteString) == true);
	BOOST_REQUIRE(certificateChain2.size() == 10);
}

BOOST_AUTO_TEST_SUITE_END()
