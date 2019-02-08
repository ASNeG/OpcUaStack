
#include "OpcUaStackClient/CryptoManagerTest.h"

CryptoManager::SPtr CryptoManagerTest::cryptoManager_ = nullptr;

const CryptoManager::SPtr&
CryptoManagerTest::getInstance(void)
{
	// create new crypto manager if necessary
	if (!cryptoManager_) {
		cryptoManager_ = constructSPtr<CryptoManager>();
	}
	else {
		return cryptoManager_;
	}

	// create certificate manager
	CertificateManager::SPtr certificateManager = constructSPtr<CertificateManager>();
	certificateManager->certificateTrustListLocation("./pki/trusted/certs/");
	certificateManager->certificateRejectListLocation("./pki/reject/certs/.");
	certificateManager->certificateRevocationListLocation("./pki/trusted/crl/");
	certificateManager->issuersCertificatesLocation("./pki/issuers/certs/");
	certificateManager->issuersRevocationListLocation("./pki/issuers/crl/");
	certificateManager->ownCertificateFile("./pki/own/certs/ASNeG-Test.der");
	certificateManager->ownPrivateKeyFile("./pki/own/private/ASNeG-Test.pem");

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

	// create application certificate
	ApplicationCertificate::SPtr applicationCertificate = constructSPtr<ApplicationCertificate>();
	if (!applicationCertificate->init(certificateManager)) {
		cryptoManager_.reset();
		return nullptr;
	}

	// init crypto manager
	cryptoManager_->certificateManager(certificateManager);
	cryptoManager_->applicationCertificate(applicationCertificate);

	return cryptoManager_;
}

void
CryptoManagerTest::delInstance(void)
{
	if (cryptoManager_) {
		cryptoManager_.reset();
	}
}
