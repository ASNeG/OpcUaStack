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

	Certificate::SPtr
	CertificateManager::readOwnCertificate(void)
	{
		auto certificate = constructSPtr<Certificate>();
		if (!certificate->fromDERFile(ownCertificateFile_)) {
			certificate->log(Error, "read certificate from file error");
			return nullptr;
		}
		return certificate;
	}

	bool
	CertificateManager::writeOwnCertificate(Certificate::SPtr& certificate)
	{
		certificate->toDERFile(ownCertificateFile_);
		if (certificate->isError()) {
			certificate->log(Error, "save self signed certificate error");
			return false;
		}
		return false;
	}

	bool
	CertificateManager::existOwnPrivateKey(void)
	{
		return boost::filesystem::exists(ownPrivateKeyFile_);
	}

	PrivateKey::SPtr
	CertificateManager::readOwnPrivateKey(void)
	{
		auto privateKey = constructSPtr<PrivateKey>();
		if (!privateKey->fromPEMFile(ownPrivateKeyFile_, nullptr)) {
			privateKey->log(Error, "read private key from file error");
			return nullptr;
		}
		return privateKey;
	}

	bool
	CertificateManager::writeOwnPrivateKey(PrivateKey::SPtr& privateKey)
	{
		if (!privateKey->toPEMFile(ownPrivateKeyFile_, nullptr)) {
			privateKey->log(Error, "save private key error");
			return false;
		}
		return true;
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
		boost::filesystem::path::iterator it;
		for (it = path.begin(); it != path.end(); it++) {
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
