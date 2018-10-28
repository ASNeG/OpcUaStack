#include <boost/filesystem.hpp>

#include <iostream>

#include "unittest.h"
#include "OpcUaStackCore/Certificate/ApplicationCertificate.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(ApplicationCertificate_)

BOOST_AUTO_TEST_CASE(ApplicationCertificate_)
{
	std::cout << "ApplicationCertificate_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(ApplicationCertificate_init)
{
	if(boost::filesystem::exists("./pki"))
	{
		boost::filesystem::remove_all("./pki");
	}

	for (uint32_t idx=0; idx<2; idx++) {

		ApplicationCertificate applicationCertificate;
		applicationCertificate.enable(true);

		applicationCertificate.certificateTrustListLocation("./pki/trusted/certs/");
		applicationCertificate.certificateRejectListLocation("./pki/reject/certs/.");
		applicationCertificate.certificateRevocationListLocation("./pki/trusted/crl/");
		applicationCertificate.issuersCertificatesLocation("./pki/issuers/certs/");
		applicationCertificate.issuersRevocationListLocation("./pki/issuers/crl/");

		applicationCertificate.serverCertificateFile("./pki/own/certs/ASNeG-Demo.der");
		applicationCertificate.privateKeyFile("./pki/own/private/ASNeG-Demo.pem");

		applicationCertificate.generateCertificate(true);
		applicationCertificate.uri("urn:asneg.de:ASNeG:ASNeG-Demo");
		applicationCertificate.commonName("ASNeG-Demo");
		applicationCertificate.domainComponent("127.0.0.1");
		applicationCertificate.organization("ASNeG");
		applicationCertificate.organizationUnit("OPC UA Service Department");
		applicationCertificate.locality("Neukirchen");
		applicationCertificate.state("Hessen");
		applicationCertificate.country("DE");
		applicationCertificate.yearsValidFor(5);
		applicationCertificate.keyLength(2048);
		applicationCertificate.certificateType("RsaSha256");
		applicationCertificate.ipAddress().push_back("127.0.0.1");
		applicationCertificate.dnsName().push_back("ASNeG.de");
		applicationCertificate.email("info@ASNeG.de");

		// init and cleanup
		BOOST_REQUIRE(applicationCertificate.init() == true);
		BOOST_REQUIRE(applicationCertificate.cleanup() == true);

	}
}

BOOST_AUTO_TEST_SUITE_END()
