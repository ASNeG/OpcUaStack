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

		// create certificate manager
		CertificateManager::SPtr certificateManager = boost::make_shared<CertificateManager>();
		certificateManager->certificateTrustListLocation("./pki/trusted/certs/");
		certificateManager->certificateRejectListLocation("./pki/reject/certs/.");
		certificateManager->certificateRevocationListLocation("./pki/trusted/crl/");
		certificateManager->issuersCertificatesLocation("./pki/issuers/certs/");
		certificateManager->issuersRevocationListLocation("./pki/issuers/crl/");
		certificateManager->ownCertificateFile("./pki/own/certs/ASNeG-Test.der");
		certificateManager->ownPrivateKeyFile("./pki/own/private/ASNeG-Test.pem");
		BOOST_REQUIRE(certificateManager->init() == true);

		CertificateSettings& certificateSettings = certificateManager->certificateSettings();
		certificateSettings.enable(true);
		certificateSettings.serverUri("urn:asneg.de:ASNeG:ASNeG-Test");
		certificateSettings.commonName("ASNeG-Test");
		certificateSettings.domainComponent("127.0.0.1");
		certificateSettings.organization("ASNeG");
		certificateSettings.organizationUnit("OPC UA Service Department");
		certificateSettings.locality("Neukirchen");
		certificateSettings.state("Hessen");
		certificateSettings.country("DE");
		certificateSettings.yearsValidFor(5);
		certificateSettings.keyLength(2048);
		certificateSettings.certificateType("RsaSha256");
		certificateSettings.ipAddress().push_back("127.0.0.1");
		certificateSettings.dnsName().push_back("ASNeG.de");
		certificateSettings.email("info@ASNeG.de");

		// init and cleanup
		ApplicationCertificate::SPtr applicationCertificate = boost::make_shared<ApplicationCertificate>();
		BOOST_REQUIRE(applicationCertificate->init(certificateManager) == true);
		BOOST_REQUIRE(applicationCertificate->cleanup() == true);

	}
}

BOOST_AUTO_TEST_SUITE_END()
