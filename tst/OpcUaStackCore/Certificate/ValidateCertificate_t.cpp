#include "unittest.h"
#include <boost/filesystem.hpp>
#include "OpcUaStackCore/Certificate/ValidateCertificate.h"
#include "OpcUaStackCore/Certificate/CertificateManager.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(ValidateCertificate_)


/*
 * This test uses the following certifcates
 *
 * 1. SelfSigned
 * 		Self signed certificate
 * 		Save in "./pkitest/trusted/certs/"
 * 2. CA (Root CA)
 *      Self signed certificate
 * 		Root CA
 * 		Save in "./pkitest/issuers/certs/"
 * 3. DEP (Department)
 * 		Signed with CA
 * 4. SRV (Server)
 * 		Signed with DEP
 */


struct GCertificateFixture {
	GCertificateFixture(void)
	: certificateManager_()

	, keySelfSigned_(2048)
	, keyCA_(2048)
	, keyDEP_(2048)
	, keySRV_(2048)

	, certificateSelfSigned_()
	, certificateCA_()
	, certificateDEP_()
	, certificateSRV_()
    {}
    ~GCertificateFixture(void)
    {}

    CertificateManager::SPtr certificateManager_;

    RSAKey keySelfSigned_;
    RSAKey keyCA_;
    RSAKey keyDEP_;
    RSAKey keySRV_;

    Certificate certificateSelfSigned_;
    Certificate certificateCA_;
    Certificate certificateDEP_;
    Certificate certificateSRV_;
};

BOOST_AUTO_TEST_CASE(ValidateCertificate_)
{
	std::cout << "ValidateCertificate_t" << std::endl;
}

BOOST_FIXTURE_TEST_CASE(ValidateCertificate_Build_Test_Certs, GCertificateFixture)
{
	CertificateInfo info;
	std::string fileName;
	CertificateManager cm;

	// create certificate manager
	boost::filesystem::remove_all("pkitest");
	certificateManager_ = constructSPtr<CertificateManager>();
	certificateManager_->certificateTrustListLocation("./pkitest/trusted/certs/");
	certificateManager_->certificateRejectListLocation("./pkitest/reject/certs/.");
	certificateManager_->certificateRevocationListLocation("./pkitest/trusted/crl/");
	certificateManager_->issuersCertificatesLocation("./pkitest/issuers/certs/");
	certificateManager_->issuersRevocationListLocation("./pkitest/issuers/crl/");
	certificateManager_->ownCertificateFile("./pkitest/own/certs/XXX.der");
	certificateManager_->ownPrivateKeyFile("./pkitest/own/private/XXX.pem");
	BOOST_REQUIRE(certificateManager_->init() == true);

	//
	// create self signed certificate
	//
	Identity identity;
	identity.organization("ASNeG");
	identity.organizationUnit("OPC UA Service Department");
	identity.commonName("ASNeG-Self-Signed");
	identity.locality("Neukirchen");
	identity.state("Hessen");
	identity.country("DE");
	identity.domainComponent("devel");

	info.dnsNames().clear();
	info.eMail().clear();
	info.uri("urn:devel:ASNeG:ASNeG-Server");
	info.ipAddresses().push_back("127.0.0.1");
	info.dnsNames().push_back("devel");
	info.eMail("info@ASNeG.de");
	info.validTime(
		boost::posix_time::microsec_clock::local_time() +
		boost::posix_time::seconds(3600*24*365*5)
	);
	info.serialNumber(time(0));
	info.validFrom(boost::posix_time::microsec_clock::local_time());

	BOOST_REQUIRE(certificateSelfSigned_.createCertificate(info, identity, keySelfSigned_, false, SignatureAlgorithm_Sha256) == true);
	BOOST_REQUIRE(certificateSelfSigned_.isError() == false);

	fileName = certificateManager_->issuersCertificatesLocation() +
		certificateSelfSigned_.thumbPrint().toHexString() + ".der";
	BOOST_REQUIRE(certificateManager_->writeCertificate(fileName, certificateSelfSigned_) == true);
	BOOST_REQUIRE(certificateSelfSigned_.isError() == false);


	//
	// create root CA certificate
	//
	identity.organization("ASNeG");
	identity.organizationUnit("OPC UA Service Department");
	identity.commonName("ASNeG-CA");
	identity.locality("Neukirchen");
	identity.state("Hessen");
	identity.country("DE");
	identity.domainComponent("devel");

	info.dnsNames().clear();
	info.eMail().clear();
	info.uri("urn:devel:ASNeG:ASNeG-CA");
	info.ipAddresses().push_back("127.0.0.1");
	info.dnsNames().push_back("devel");
	info.eMail("info@ASNeG.de");
	info.validTime(
		boost::posix_time::microsec_clock::local_time() +
		boost::posix_time::seconds(3600*24*365*5)
	);
	info.serialNumber(time(0));
	info.validFrom(boost::posix_time::microsec_clock::local_time());

	BOOST_REQUIRE(
		certificateCA_.createCertificate(
			info, identity, keyCA_, true, SignatureAlgorithm_Sha256
		) == true
	);
	BOOST_REQUIRE(certificateCA_.isError() == false);

	fileName = certificateManager_->certificateTrustListLocation() +
		certificateCA_.thumbPrint().toHexString() + ".der";
	BOOST_REQUIRE(certificateManager_->writeCertificate(fileName, certificateCA_) == true);
	BOOST_REQUIRE(certificateCA_.isError() == false);


	//
	// create department certificate
	//
	identity.organization("ASNeG");
	identity.organizationUnit("OPC UA Service Department");
	identity.commonName("ASNeG-DEP");
	identity.locality("Neukirchen");
	identity.state("Hessen");
	identity.country("DE");
	identity.domainComponent("devel");

	info.dnsNames().clear();
	info.eMail().clear();
	info.uri("urn:devel:ASNeG:ASNeG-DEP");
	info.ipAddresses().push_back("127.0.0.1");
	info.dnsNames().push_back("devel");
	info.eMail("info@ASNeG.de");
	info.validTime(
		boost::posix_time::microsec_clock::local_time() +
		boost::posix_time::seconds(3600*24*365*5)
	);
	info.serialNumber(time(0));
	info.validFrom(boost::posix_time::microsec_clock::local_time());

	PublicKey publicKeyDEP = keyDEP_.publicKey();
	PrivateKey privateKeyCA = keyCA_.privateKey();
	BOOST_REQUIRE(
		certificateDEP_.createCertificate(
			info, identity, publicKeyDEP,
			certificateCA_, privateKeyCA,
			true, SignatureAlgorithm_Sha256
		) == true
	);
	BOOST_REQUIRE(certificateDEP_.isError() == false);


	//
	// create server certificate
	//
	RSAKey keySRV(2048);
	BOOST_REQUIRE(keySRV.isError() == false);

	identity.organization("ASNeG");
	identity.organizationUnit("OPC UA Service Department");
	identity.commonName("ASNeG-SRV");
	identity.locality("Neukirchen");
	identity.state("Hessen");
	identity.country("DE");
	identity.domainComponent("devel");

	info.dnsNames().clear();
	info.eMail().clear();
	info.uri("urn:devel:ASNeG:ASNeG-SRV");
	info.ipAddresses().push_back("127.0.0.1");
	info.dnsNames().push_back("devel");
	info.eMail("info@ASNeG.de");
	info.validTime(
		boost::posix_time::microsec_clock::local_time() +
		boost::posix_time::seconds(3600*24*365*5)
	);
	info.serialNumber(time(0));
	info.validFrom(boost::posix_time::microsec_clock::local_time());

	PublicKey publicKeySRV = keySRV_.publicKey();
	PrivateKey privateKeyDEP = keyDEP_.privateKey();
	BOOST_REQUIRE(
		certificateSRV_.createCertificate(
			info, identity, publicKeySRV,
			certificateDEP_, privateKeyDEP,
			true, SignatureAlgorithm_Sha256
		) == true
	);
	BOOST_REQUIRE(certificateDEP_.isError() == false);

}

BOOST_AUTO_TEST_SUITE_END()
