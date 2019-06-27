/*
   Copyright 2019 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   CertificateManagerrmationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include <boost/filesystem/operations.hpp>
#include <boost/system/error_code.hpp>
#include <sys/types.h>
#include <sys/stat.h>
#include "OpcUaStackCore/Certificate/CertificateManager.h"

namespace OpcUaStackCore
{

	CertificateManager::CertificateManager(void)
	: certificateTrustListLocation_("")
	, certificateRejectListLocation_("")
	, certificateRevocationListLocation_("")
	, issuersCertificatesLocation_("")
	, issuersRevocationListLocation_("")

	, ownCertificateFile_("")
    , ownPrivateKeyFile_("")

	, certificateSettings_()
	{
	}

	CertificateManager::~CertificateManager(void)
	{
	}

	bool
	CertificateManager::init(void)
	{
		// check directories. If they not exist create them
		if (!checkAndCreateDirectory(certificateTrustListLocation_)) {
			return false;
		}
		if (!checkAndCreateDirectory(certificateRejectListLocation_)) {
			return false;
		}
		if (!checkAndCreateDirectory(certificateRevocationListLocation_)) {
			return false;
		}
		if (!checkAndCreateDirectory(issuersCertificatesLocation_)) {
			return false;
		}
		if (!checkAndCreateDirectory(issuersRevocationListLocation_)) {
			return false;
		}
		boost::filesystem::path serverCertificateFile(ownCertificateFile_);
		if (!checkAndCreateDirectory(serverCertificateFile.parent_path().string())) {
			return false;
		}
		boost::filesystem::path privateKeyFile(ownPrivateKeyFile_);
		if (!checkAndCreateDirectory(privateKeyFile.parent_path().string())) {
			return false;
		}
		if (!setReadOnly(privateKeyFile.parent_path().string())) {
			return false;
		}

		return true;
	}

	void
	CertificateManager::certificateTrustListLocation(const std::string& certificateTrustListLocation)
	{
		certificateTrustListLocation_ = certificateTrustListLocation;
	}

	std::string&
	CertificateManager::certificateTrustListLocation(void)
	{
		return certificateTrustListLocation_;
	}

	void
	CertificateManager::certificateRejectListLocation(const std::string& certificateRejectListLocation)
	{
		certificateRejectListLocation_ = certificateRejectListLocation;
	}

	std::string&
	CertificateManager::certificateRejectListLocation(void)
	{
		return certificateRejectListLocation_;
	}

	void
	CertificateManager::certificateRevocationListLocation(const std::string& certificateRevocationListLocation)
	{
		certificateRevocationListLocation_ = certificateRevocationListLocation;
	}

	std::string&
	CertificateManager::certificateRevocationListLocation(void)
	{
		return certificateRevocationListLocation_;
	}

	void
	CertificateManager::issuersCertificatesLocation(const std::string& issuersCertificatesLocation)
	{
		issuersCertificatesLocation_ = issuersCertificatesLocation;
	}

	std::string&
	CertificateManager::issuersCertificatesLocation(void)
	{
		return issuersCertificatesLocation_;
	}

	void
	CertificateManager::issuersRevocationListLocation(const std::string& issuersRevocationListLocation)
	{
		issuersRevocationListLocation_ = issuersRevocationListLocation;
	}

	std::string&
	CertificateManager::issuersRevocationListLocation(void)
	{
		return issuersRevocationListLocation_;
	}

	void
	CertificateManager::ownCertificateFile(const std::string& ownCertificateFile)
	{
		ownCertificateFile_ = ownCertificateFile;
	}

	std::string&
	CertificateManager::ownCertificateFile(void)
	{
		return ownCertificateFile_;
	}

	void
	CertificateManager::ownPrivateKeyFile(const std::string& ownPrivateKeyFile)
	{
		ownPrivateKeyFile_ = ownPrivateKeyFile;
	}

	std::string&
	CertificateManager::ownPrivateKeyFile(void)
	{
		return ownPrivateKeyFile_;
	}

	bool
	CertificateManager::existOwnCertificate(void)
	{
		return boost::filesystem::exists(ownCertificateFile_);
	}

	bool
	CertificateManager::removeOwnCertificate(void)
	{
		return boost::filesystem::remove(ownCertificateFile_);
	}

	Certificate::SPtr
	CertificateManager::readOwnCertificate(void)
	{
		auto certificate = constructSPtr<Certificate>();
		if (!certificate->fromDERFile(ownCertificateFile_)) {
			certificate->log(Error, "read certificate from file error: " + ownCertificateFile_);
			return nullptr;
		}
		return certificate;
	}

	bool
	CertificateManager::writeOwnCertificate(Certificate::SPtr& certificate)
	{
		return writeOwnCertificate(*certificate.get());
	}

	bool
	CertificateManager::writeOwnCertificate(Certificate& certificate)
	{
		certificate.toDERFile(ownCertificateFile_);
		if (certificate.isError()) {
			certificate.log(Error, "save self signed certificate error: " + ownCertificateFile_);
			return false;
		}
		return true;
	}

	bool
	CertificateManager::existOwnPrivateKey(void)
	{
		return boost::filesystem::exists(ownPrivateKeyFile_);
	}

	bool
	CertificateManager::removeOwnPrivateKey(void)
	{
		return boost::filesystem::remove(ownPrivateKeyFile_);
	}

	PrivateKey::SPtr
	CertificateManager::readOwnPrivateKey(void)
	{
		auto privateKey = constructSPtr<PrivateKey>();
		if (!privateKey->fromPEMFile(ownPrivateKeyFile_, nullptr)) {
			privateKey->log(Error, "read private key from file error: " + ownCertificateFile_);
			return nullptr;
		}
		return privateKey;
	}

	bool
	CertificateManager::writeOwnPrivateKey(PrivateKey::SPtr& privateKey)
	{
		return writeOwnPrivateKey(*privateKey.get());
	}

	bool
	CertificateManager::writeOwnPrivateKey(PrivateKey& privateKey)
	{
		if (!privateKey.toPEMFile(ownPrivateKeyFile_, nullptr)) {
			privateKey.log(Error, "save private key error: " + ownPrivateKeyFile_);
			return false;
		}
		return true;
	}

	CertificateSettings&
	CertificateManager::certificateSettings(void)
	{
		return certificateSettings_;
	}

	bool
	CertificateManager::writePartnerCertificate(const std::string& fileName, Certificate& certificate)
	{
		certificate.toDERFile(fileName);
		if (certificate.isError()) {
			certificate.log(Error, "save partner certificate error: " + ownCertificateFile_);
			return false;
		}
		return true;
	}

	bool
	CertificateManager::isPartnerCertificateTrusted(CertificateChain& partnerCertificateChain)
	{
		auto certificate = partnerCertificateChain.getCertificate();
		std::string certFileName = certificate->thumbPrint().toHexString() + ".der";

		// check if certificate is in reject list location
		boost::filesystem::path rejectFilePath(certificateRejectListLocation_ + "/" + certFileName);
		if (boost::filesystem::exists(rejectFilePath)) {
			return false;
		}

		// check if certificate is in trust list location
		boost::filesystem::path trustFilePath(certificateTrustListLocation_ + "/" + certFileName);
		if (boost::filesystem::exists(trustFilePath)) {
			return true;
		}

		if (writePartnerCertificate(rejectFilePath.string(), *certificate.get())) {
			Log(Info, "write partner certificate to reject folder")
		    	.parameter("CertFileName", rejectFilePath.string());
		}
		else {
			Log(Error, "write partner certificate to reject folder failed")
		    	.parameter("CertFileName", rejectFilePath.string());
		}
		return false;
	}

	bool
	CertificateManager::isPartnerCertificateTrusted(
		const std::string& applicationUri,
		CertificateChain& partnerCertificateChain
	)
	{
		// check if certificate is in reject list location
		boost::filesystem::path rejectFilePath(certificateRejectListLocation_);
		for (auto file : boost::filesystem::directory_iterator(rejectFilePath)) {
			if (boost::filesystem::is_directory(file)) {
				continue;
			}
			if (file.path().extension().string() != ".der") {
				continue;
			}

			auto certificate = constructSPtr<Certificate>();
			if (!certificate->fromDERFile(file.path().string())) {
				certificate->log(Error, "read certificate from file error: " + file.path().string());
				continue;
			}

			CertificateInfo info;
			certificate->getInfo(info);
			if (info.uri() == applicationUri) {
				partnerCertificateChain.addCertificate(certificate);
				Log(Debug, "found certificate in reject folder")
				    .parameter("Uri", applicationUri);
				return false;
			}
		}

		// check if certificate is in trust list location
		std::vector<std::string> uris;
		boost::filesystem::path trustFilePath(certificateTrustListLocation_);
		for (auto file : boost::filesystem::directory_iterator(trustFilePath)) {
			if (boost::filesystem::is_directory(file)) {
				continue;
			}
			if (file.path().extension().string() != ".der") {
				continue;
			}

			auto certificate = constructSPtr<Certificate>();
			if (!certificate->fromDERFile(file.path().string())) {
				certificate->log(Error, "read certificate from file error: " + file.path().string());
				continue;
			}

			CertificateInfo info;
			certificate->getInfo(info);
			uris.push_back(info.uri());
			if (info.uri() == applicationUri) {
				partnerCertificateChain.addCertificate(certificate);
				return true;
			}
		}

		Log log(Debug, "certificate not found in trusted folder");
		log.parameter("Uri", applicationUri);
		for (auto uri : uris) {
			log.parameter("TrustedUri", uri);
		}
		return false;
	}

	bool
	CertificateManager::existCertificate(const std::string& fileName)
	{
		return boost::filesystem::exists(fileName);
	}

	bool
	CertificateManager::removeCertificate(const std::string& fileName)
	{
		return boost::filesystem::remove(fileName);
	}

	Certificate::SPtr
	CertificateManager::readCertificate(const std::string& fileName)
	{
		auto certificate = constructSPtr<Certificate>();
		if (!certificate->fromDERFile(fileName)) {
			certificate->log(Error, "read certificate from file error: " + fileName);
				return nullptr;
			}
		return certificate;
	}

	bool
	CertificateManager::writeCertificate(const std::string& fileName, Certificate::SPtr& certificate)
	{
		return writeCertificate(fileName, *certificate.get());
	}

	bool
	CertificateManager::writeCertificate(const std::string& fileName, Certificate& certificate)
	{
		certificate.toDERFile(fileName);
		if (certificate.isError()) {
			certificate.log(Error, "save certificate error: " + fileName);
			return false;
		}
		return true;
	}

	Certificate::SPtr
	CertificateManager::getTrustedCertificate(Identity& issuer)
	{
		return getCertificate(certificateTrustListLocation_, issuer);
	}

	Certificate::SPtr
	CertificateManager::getCACertificate(Identity& issuer)
	{
		return getCertificate(issuersCertificatesLocation_, issuer);
	}

	bool
	CertificateManager::isCertificateInTrustedList(Certificate::SPtr& certificate)
	{
		std::string certFileName = certificate->thumbPrint().toHexString() + ".der";
		boost::filesystem::path trustFilePath(certificateTrustListLocation_ + "/" + certFileName);
		if (boost::filesystem::exists(trustFilePath)) {
			return true;
		}
		return false;
	}

	bool
	CertificateManager::isCertificateInIssuerList(Certificate::SPtr& certificate)
	{
		std::string certFileName = certificate->thumbPrint().toHexString() + ".der";
		boost::filesystem::path issuerFilePath(issuersCertificatesLocation_ + "/" + certFileName);
		if (boost::filesystem::exists(issuerFilePath)) {
			return true;
		}
		return false;
	}

	bool
	CertificateManager::isCertificateInRevocationList(Certificate::SPtr& certificate)
	{
		std::string certFileName = certificate->thumbPrint().toHexString() + ".der";

		boost::filesystem::path certificateRevocationPath(certificateRevocationListLocation_ + "/" + certFileName);
		if (boost::filesystem::exists(certificateRevocationPath)) {
			return true;
		}

		boost::filesystem::path issuerRevocationPath(issuersRevocationListLocation_ + "/" + certFileName);
		if (boost::filesystem::exists(issuerRevocationPath)) {
			return true;
		}

		return false;
	}

	Certificate::SPtr
	CertificateManager::getCertificate(const std::string& directory, Identity& issuer)
	{
		boost::filesystem::path trustFilePath(certificateTrustListLocation_);
		for (auto file : boost::filesystem::directory_iterator(trustFilePath)) {
			if (boost::filesystem::is_directory(file)) {
				continue;
			}
			if (file.path().extension().string() != ".der") {
				continue;
			}

			auto certificate = constructSPtr<Certificate>();
			if (!certificate->fromDERFile(file.path().string())) {
				certificate->log(Error, "read certificate from file error: " + file.path().string());
				continue;
			}

			Identity subject;
			if (!certificate->getSubject(subject)) {
				certificate->log(Error, "read subject from certificate error: " + file.path().string());
				continue;
			}

			if (issuer == subject) {
				return certificate;
			}
		}


		Certificate::SPtr certificate;
		return certificate;
	}

	bool
	CertificateManager::checkAndCreateDirectory(const std::string& directory)
	{
		boost::filesystem::path path(directory);

		// check if directory exist
		if (boost::filesystem::exists(path)) {
			return true;
		}

		// create directory
		Log(Info, "create certificate directory")
			.parameter("Directory", directory);

		boost::filesystem::path createPath;
		for (auto it = path.begin(); it != path.end(); it++) {
			std::string str = it->string();

			//createPath.append(str);
			createPath /= str;

			if (boost::filesystem::exists(createPath)) {
				continue;
			}

			boost::system::error_code ec;
			if (!boost::filesystem::create_directory(createPath, ec)) {
				Log(Error, "create certificate directory error")
					.parameter("Directory", createPath.string())
					.parameter("ErrorCode", ec.message());
				return false;
			}
		}

		return true;
	}

	bool
	CertificateManager::setReadOnly(const std::string& directory)
	{
		boost::filesystem::path path(directory);

		// check if directory exist
		if (!boost::filesystem::exists(path)) {
			Log(Error, "directory not exist")
				.parameter("Directory", directory);
			return false;
		}

#if defined (__linux__)
		// set permissions
		if (chmod(directory.c_str(), S_IRUSR|S_IWUSR|S_IXUSR) != 0) {
			Log(Error, "change permission directory error")
				.parameter("Directory", directory)
				.parameter("ErrorCode", strerror(errno));
			return false;
		}
#endif

		return true;
	}

}
