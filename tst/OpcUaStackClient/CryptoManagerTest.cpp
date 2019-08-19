#include <stdlib.h>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include "OpcUaStackCore/Utility/Environment.h"
#include "OpcUaStackClient/CryptoManagerTest.h"

using namespace OpcUaStackCore;

CryptoManager::SPtr CryptoManagerTest::cryptoManager_ = nullptr;
const std::string CryptoManagerTest::clientCertificateName_ = "./pki/own/certs/ASNeG-Test.der";
const std::string CryptoManagerTest::serverCertificateName_ = CryptoManagerTest::getServerPkiRootDir() + "/etc/OpcUaStack/ASNeG-Demo/pki/own/certs/ASNeG-Demo.der";

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
	certificateManager->init();

	CertificateSettings& certificateSettings = certificateManager->certificateSettings();
	certificateSettings.enable(true);
	certificateSettings.serverUri(std::string("urn:") + Environment::hostname() + std::string(":ASNeG:ASNeG-Test"));
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
	certificateSettings.dnsName().push_back(Environment::hostname());
	certificateSettings.dnsName().push_back("asneg-demo");			// test server
	certificateSettings.dnsName().push_back("asneg-test");			// test test
	certificateSettings.email("info@ASNeG.de");

	// create application certificate
	ApplicationCertificate::SPtr applicationCertificate = constructSPtr<ApplicationCertificate>();
	if (!applicationCertificate->init(certificateManager)) {
		cryptoManager_.reset();
		return cryptoManager_;
	}

	// init crypto manager
	cryptoManager_->certificateManager(certificateManager);
	cryptoManager_->applicationCertificate(applicationCertificate);

	// for testing we must trust the client certificate and the server certificate
	trustedClientServerCertificates();

	return cryptoManager_;
}

void
CryptoManagerTest::delInstance(void)
{
	if (cryptoManager_) {
		cryptoManager_.reset();
	}
}

void
CryptoManagerTest::trustedClientServerCertificates(void)
{
	trustedClientCertificate();
	trustedServerCertificate();
}

void
CryptoManagerTest::trustedClientCertificate(void)
{
	// check if certificate exists on client
	if (!cryptoManager_->certificateManager()->existCertificate(clientCertificateName_)) {
		Log(Error, "client certificate not exist")
			.parameter("ClientCertificate", clientCertificateName_);
		return;
	}

	// load server certificate
	Certificate::SPtr certificate;
	certificate = cryptoManager_->certificateManager()->readCertificate(clientCertificateName_);
	if (!certificate) {
		Log(Error, "load client certificate failed")
			.parameter("ClientCertificate", clientCertificateName_);
		return;
	}
	OpcUaByteString thumbPrint = certificate->thumbPrint();

	// remove certificate from reject folder on server
	boost::filesystem::path rejectFile(serverCertificateName_);
	rejectFile = rejectFile.parent_path().parent_path().parent_path();
	rejectFile /= boost::filesystem::path("/reject/certs/" + thumbPrint.toHexString() + ".der");
	if (cryptoManager_->certificateManager()->existCertificate(rejectFile.string())) {
		cryptoManager_->certificateManager()->removeCertificate(rejectFile.string());
	}

	// added certificate to trust folder on server
	boost::filesystem::path trustedFile(serverCertificateName_);
	trustedFile = rejectFile.parent_path().parent_path().parent_path();
	trustedFile /= boost::filesystem::path("/trusted/certs/" + thumbPrint.toHexString() + ".der");
	if (!cryptoManager_->certificateManager()->existCertificate(trustedFile.string())) {
		if (!cryptoManager_->certificateManager()->writeCertificate(trustedFile.string(), certificate)) {
			Log(Error, "write client certificate error")
				.parameter("ClientCertificate", trustedFile.string());
			return;
		}
	}
}

void
CryptoManagerTest::trustedServerCertificate(void)
{
	// check if certificate exists on server
	if (!cryptoManager_->certificateManager()->existCertificate(serverCertificateName_)) {
		Log(Error, "server certificate not exist")
			.parameter("ServerCertificate", serverCertificateName_);
		return;
	}

	// load server certificate
	Certificate::SPtr certificate;
	certificate = cryptoManager_->certificateManager()->readCertificate(serverCertificateName_);
	if (!certificate) {
		Log(Error, "load server certificate failed")
			.parameter("ServerCertificate", serverCertificateName_);
		return;
	}
	OpcUaByteString thumbPrint = certificate->thumbPrint();

	// remove certificate from reject folder on client
	boost::filesystem::path rejectFile(clientCertificateName_);
	rejectFile = rejectFile.parent_path().parent_path().parent_path();
	rejectFile /= boost::filesystem::path("/reject/certs/" + thumbPrint.toHexString() + ".der");
	if (cryptoManager_->certificateManager()->existCertificate(rejectFile.string())) {
		cryptoManager_->certificateManager()->removeCertificate(rejectFile.string());
	}

	// added certificate to trust folder on client
	boost::filesystem::path trustedFile(clientCertificateName_);
	trustedFile = rejectFile.parent_path().parent_path().parent_path();
	trustedFile /= boost::filesystem::path("/trusted/certs/" + thumbPrint.toHexString() + ".der");
	if (!cryptoManager_->certificateManager()->existCertificate(trustedFile.string())) {
		if (!cryptoManager_->certificateManager()->writeCertificate(trustedFile.string(), certificate)) {
			Log(Error, "write server certificate error")
				.parameter("ServerCertificate", trustedFile.string());
			return;
		}
	}
}

void
CryptoManagerTest::untrustedClientServerCertificates(void)
{
	untrusteClientCertificate();
	untrusteServerCertificate();
}

void
CryptoManagerTest::untrusteClientCertificate(void)
{
	// check if certificate exists on client
	if (!cryptoManager_->certificateManager()->existCertificate(clientCertificateName_)) {
		Log(Error, "client certificate not exist")
			.parameter("ClientCertificate", clientCertificateName_);
		return;
	}

	// load server certificate
	Certificate::SPtr certificate;
	certificate = cryptoManager_->certificateManager()->readCertificate(clientCertificateName_);
	if (!certificate) {
		Log(Error, "load client certificate failed")
			.parameter("ClientCertificate", clientCertificateName_);
		return;
	}
	OpcUaByteString thumbPrint = certificate->thumbPrint();

	// remove certificate from trusted folder on server
	boost::filesystem::path rejectFile(serverCertificateName_);
	rejectFile = rejectFile.parent_path().parent_path().parent_path();
	rejectFile /= boost::filesystem::path("/trusted/certs/" + thumbPrint.toHexString() + ".der");
	if (cryptoManager_->certificateManager()->existCertificate(rejectFile.string())) {
		cryptoManager_->certificateManager()->removeCertificate(rejectFile.string());
	}
}

void
CryptoManagerTest::untrusteServerCertificate(void)
{
	// check if certificate exists on server
	if (!cryptoManager_->certificateManager()->existCertificate(serverCertificateName_)) {
		Log(Error, "server certificate not exist")
			.parameter("ServerCertificate", serverCertificateName_);
		return;
	}

	// load server certificate
	Certificate::SPtr certificate;
	certificate = cryptoManager_->certificateManager()->readCertificate(serverCertificateName_);
	if (!certificate) {
		Log(Error, "load server certificate failed")
			.parameter("ServerCertificate", serverCertificateName_);
		return;
	}
	OpcUaByteString thumbPrint = certificate->thumbPrint();

	// remove certificate from reject folder on client
	boost::filesystem::path rejectFile(clientCertificateName_);
	rejectFile = rejectFile.parent_path().parent_path().parent_path();
	rejectFile /= boost::filesystem::path("/reject/certs/" + thumbPrint.toHexString() + ".der");
	if (cryptoManager_->certificateManager()->existCertificate(rejectFile.string())) {
		cryptoManager_->certificateManager()->removeCertificate(rejectFile.string());
	}
}

std::string
CryptoManagerTest::getServerHostName(void)
{
	char* var = std::getenv("SERVER_HOST_NAME");
	if (var == nullptr) {
		return Environment::hostname();
	}
	return std::string(var);
}

std::string
CryptoManagerTest::getServerPkiRootDir(void)
{
	char* var = std::getenv("SERVER_PKI_ROOT_DIR");
	if (var == nullptr) {

		char* var = std::getenv("HOME");
		if (var == nullptr) {
			return std::string("/");
		}

		return std::string(var) + std::string("/.ASNeG");
	}
	return std::string(var);
}
