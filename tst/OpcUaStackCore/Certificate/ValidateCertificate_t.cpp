#include "unittest.h"
#include <boost/make_shared.hpp>
#include <boost/filesystem.hpp>
#include "OpcUaStackCore/Certificate/ValidateCertificate.h"
#include "OpcUaStackCore/Certificate/CertificateManager.h"

using namespace OpcUaStackCore;

//BOOST_AUTO_TEST_SUITE(ValidateCertificate_)


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

//BOOST_AUTO_TEST_SUITE(ValidateCertificate_)

struct GCertificateFixture {
	GCertificateFixture(void)
	: certificateManager_(boost::make_shared<CertificateManager>())

	, keySelfSigned_(2048)
	, keyCA_(2048)
	, keyDEP_(2048)
	, keySRV_(2048)

	, certificateSelfSigned_(boost::make_shared<Certificate>())
	, certificateCA_(boost::make_shared<Certificate>())
	, certificateDEP_(boost::make_shared<Certificate>())
	, certificateSRV_(boost::make_shared<Certificate>())
    {
		std::cout << "ctor GCertificateFixture" << std::endl;
    }

    ~GCertificateFixture(void)
    {
    	std::cout << "dtor GCertificateFixture" << std::endl;
    }

    static GCertificateFixture* instance_;
    static GCertificateFixture* instance(void)
    {
    	if (instance_ == nullptr) {
    		instance_ = new GCertificateFixture();
    	}
    	return instance_;
    }

    CertificateManager::SPtr certificateManager_;

    RSAKey keySelfSigned_;
    RSAKey keyCA_;
    RSAKey keyDEP_;
    RSAKey keySRV_;

    Certificate::SPtr certificateSelfSigned_;
    Certificate::SPtr certificateCA_;
    Certificate::SPtr certificateDEP_;
    Certificate::SPtr certificateSRV_;
};

GCertificateFixture* GCertificateFixture::instance_ = nullptr;

BOOST_AUTO_TEST_SUITE(ValidateCertificate_)

BOOST_GLOBAL_FIXTURE( GCertificateFixture );

BOOST_AUTO_TEST_CASE(ValidateCertificate_)
{
	std::cout << "ValidateCertificate_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(ValidateCertificate_Build_Test_Certs)
{
	auto* gf = GCertificateFixture::instance();

	CertificateInfo info;
	std::string fileName;

	// create certificate manager
	boost::filesystem::remove_all("pkitest");
	gf->certificateManager_->certificateTrustListLocation("./pkitest/trusted/certs/");
	gf->certificateManager_->certificateRejectListLocation("./pkitest/reject/certs/.");
	gf->certificateManager_->certificateRevocationListLocation("./pkitest/trusted/crl/");
	gf->certificateManager_->issuersCertificatesLocation("./pkitest/issuers/certs/");
	gf->certificateManager_->issuersRevocationListLocation("./pkitest/issuers/crl/");
	gf->certificateManager_->ownCertificateFile("./pkitest/own/certs/XXX.der");
	gf->certificateManager_->ownPrivateKeyFile("./pkitest/own/private/XXX.pem");
	BOOST_REQUIRE(gf->certificateManager_->init() == true);

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

	info.clear();
	info.uri("urn:devel:ASNeG:ASNeG-Server");
	info.ipAddresses().push_back("127.0.0.1");
	info.dnsNames().push_back("devel");
	info.eMail("info@ASNeG.de");
	info.validTime(
		boost::posix_time::microsec_clock::universal_time() +
		boost::posix_time::seconds(3600*24*365*5)
	);
	info.serialNumber(time(0));
	info.validFrom(boost::posix_time::microsec_clock::universal_time());

	BOOST_REQUIRE(gf->certificateSelfSigned_->createCertificate(
		info, identity,
		gf->keySelfSigned_,
		false,
		SignatureAlgorithm_Sha256) == true
	);
	BOOST_REQUIRE(gf->certificateSelfSigned_->isError() == false);

	fileName = gf->certificateManager_->issuersCertificatesLocation() +
		gf->certificateSelfSigned_->thumbPrint().toHexString() + ".der";
	BOOST_REQUIRE(gf->certificateManager_->writeCertificate(fileName, gf->certificateSelfSigned_) == true);
	BOOST_REQUIRE(gf->certificateSelfSigned_->isError() == false);

	BOOST_REQUIRE(gf->certificateManager_->writeCertificate("SelfSigned.der", gf->certificateSelfSigned_) == true);

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

	info.clear();
	info.uri("urn:devel:ASNeG:ASNeG-CA");
	info.ipAddresses().push_back("127.0.0.1");
	info.dnsNames().push_back("devel");
	info.eMail("info@ASNeG.de");
	info.validTime(
		boost::posix_time::microsec_clock::universal_time() +
		boost::posix_time::seconds(3600*24*365*5)
	);
	info.serialNumber(time(0));
	info.validFrom(boost::posix_time::microsec_clock::universal_time());

	BOOST_REQUIRE(
		gf->certificateCA_->createCertificate(
			info, identity, gf->keyCA_, true, SignatureAlgorithm_Sha256
		) == true
	);
	BOOST_REQUIRE(gf->certificateCA_->isError() == false);

	fileName = gf->certificateManager_->certificateTrustListLocation() +
		gf->certificateCA_->thumbPrint().toHexString() + ".der";
	BOOST_REQUIRE(gf->certificateManager_->writeCertificate(fileName, gf->certificateCA_) == true);
	BOOST_REQUIRE(gf->certificateCA_->isError() == false);

	BOOST_REQUIRE(gf->certificateManager_->writeCertificate("CA.der", gf->certificateCA_) == true);


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

	info.clear();
	info.uri("urn:devel:ASNeG:ASNeG-DEP");
	info.ipAddresses().push_back("127.0.0.1");
	info.dnsNames().push_back("devel");
	info.eMail("info@ASNeG.de");
	info.validTime(
		boost::posix_time::microsec_clock::universal_time() +
		boost::posix_time::seconds(3600*24*365*5)
	);
	info.serialNumber(time(0));
	info.validFrom(boost::posix_time::microsec_clock::universal_time());

	auto publicKeyDEP = gf->keyDEP_.publicKey();
	auto privateKeyCA = gf->keyCA_.privateKey();
	BOOST_REQUIRE(
		gf->certificateDEP_->createCertificate(
			info, identity, publicKeyDEP,
			*gf->certificateCA_.get(), privateKeyCA,
			true, SignatureAlgorithm_Sha256
		) == true
	);
	BOOST_REQUIRE(gf->certificateDEP_->isError() == false);

	BOOST_REQUIRE(gf->certificateManager_->writeCertificate("DEP.der", gf->certificateDEP_) == true);



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

	info.clear();
	info.uri("urn:devel:ASNeG:ASNeG-SRV");
	info.ipAddresses().push_back("127.0.0.1");
	info.dnsNames().push_back("devel");
	info.eMail("info@ASNeG.de");
	info.validTime(
		boost::posix_time::microsec_clock::universal_time() +
		boost::posix_time::seconds(3600*24*365*5)
	);
	info.serialNumber(time(0));
	info.validFrom(boost::posix_time::microsec_clock::universal_time());

	auto publicKeySRV = gf->keySRV_.publicKey();
	auto privateKeyDEP = gf->keyDEP_.privateKey();
	BOOST_REQUIRE(
		gf->certificateSRV_->createCertificate(
			info, identity, publicKeySRV,
			*gf->certificateDEP_.get(), privateKeyDEP,
			false, SignatureAlgorithm_Sha256
		) == true
	);
	BOOST_REQUIRE(gf->certificateDEP_->isError() == false);

	BOOST_REQUIRE(gf->certificateManager_->writeCertificate("SRV.der", gf->certificateSRV_) == true);


}

BOOST_AUTO_TEST_CASE(ValidateCertificate_Validate_SelfSigned)
{
	auto* gf = GCertificateFixture::instance();

	// create certificate chain
	OpcUaByteString byteString;
	CertificateChain certificateChain;
	certificateChain.addCertificate(gf->certificateSelfSigned_);
	BOOST_REQUIRE(certificateChain.toByteString(byteString) == true);

	// validate certificate
	ValidateCertificate vc;
	vc.certificateManager(gf->certificateManager_);
	BOOST_REQUIRE(vc.validateCertificate(byteString) == Success);
}

BOOST_AUTO_TEST_CASE(ValidateCertificate_Validate_DEP)
{
	auto* gf = GCertificateFixture::instance();

	// create certificate chain
	OpcUaByteString byteString;
	CertificateChain certificateChain;
	certificateChain.addCertificate(gf->certificateDEP_);
	certificateChain.addCertificate(gf->certificateCA_);
	BOOST_REQUIRE(certificateChain.toByteString(byteString) == true);

	// validate certificate
	ValidateCertificate vc;
	vc.certificateManager(gf->certificateManager_);
	BOOST_REQUIRE(vc.validateCertificate(byteString) == Success);
}

BOOST_AUTO_TEST_CASE(ValidateCertificate_Validate_SRV)
{
	auto* gf = GCertificateFixture::instance();

	// create certificate chain
	OpcUaByteString byteString;
	CertificateChain certificateChain;
	certificateChain.addCertificate(gf->certificateSRV_);
	certificateChain.addCertificate(gf->certificateDEP_);
	certificateChain.addCertificate(gf->certificateCA_);
	BOOST_REQUIRE(certificateChain.toByteString(byteString) == true);

	// validate certificate
	ValidateCertificate vc;
	vc.certificateManager(gf->certificateManager_);
	BOOST_REQUIRE(vc.validateCertificate(byteString) == Success);
}

BOOST_AUTO_TEST_CASE(ValidateCertificate_Validate_SRV_without_CA)
{
	auto* gf = GCertificateFixture::instance();

	// create certificate chain
	OpcUaByteString byteString;
	CertificateChain certificateChain;
	certificateChain.addCertificate(gf->certificateSRV_);
	certificateChain.addCertificate(gf->certificateDEP_);
	BOOST_REQUIRE(certificateChain.toByteString(byteString) == true);

	// validate certificate
	ValidateCertificate vc;
	vc.certificateManager(gf->certificateManager_);
	BOOST_REQUIRE(vc.validateCertificate(byteString) == Success);
}

BOOST_AUTO_TEST_SUITE_END()
