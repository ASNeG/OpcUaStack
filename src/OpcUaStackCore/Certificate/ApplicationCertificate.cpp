/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   ApplicationCertificatermationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */


#include <boost/filesystem.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/system/error_code.hpp>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <iostream>
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Certificate/ApplicationCertificate.h"

namespace OpcUaStackCore
{

	ApplicationCertificate::ApplicationCertificate(void)
	: enable_(false)
	, certificateTrustListLocation_("")
	, certificateRejectListLocation_("")
	, certificateRevocationListLocation_("")
	, issuersCertificatesLocation_("")
	, issuersRevocationListLocation_("")

	, serverCertificateFile_("")
	, privateKeyFile_("")

	, generateCertificate_(true)
	, uri_("")
	, commonName_("")
	, domainComponent_("")
	, organization_("")
	, organizationUnit_("")
	, locality_("")
	, state_("")
	, country_("")
	, yearsValidFor_(5)
	, keyLength_(2048)
	, certificateType_("RsaSha256")
	, ipAddress_()
	, dnsName_()
	, email_("")

	, certificate_()
	, privateKey_()
	{
	}

	ApplicationCertificate::~ApplicationCertificate(void)
	{
	}

	bool
	ApplicationCertificate::init(void)
	{
		Log(Info, "init certificate")
			.parameter("Enable", enable_);

		if (!enable_) {
			// do nothing
			return true;
		}

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
		boost::filesystem::path serverCertificateFile(serverCertificateFile_);
		if (!checkAndCreateDirectory(serverCertificateFile.parent_path().string())) {
			return false;
		}
		boost::filesystem::path privateKeyFile(privateKeyFile_);
		if (!checkAndCreateDirectory(privateKeyFile.parent_path().string())) {
			return false;
		}
		if (!setReadOnly(privateKeyFile.parent_path().string())) {
			return false;
		}

		// create self signed certificate
		if (!createSelfSignedCertificate()) {
			return false;
		}

		// read own certificate and private key
		if (!readCertificateAndPrivateKey()) {
			return false;
		}

		return true;
	}

	bool
	ApplicationCertificate::cleanup(void)
	{
		certificate_.reset();
		privateKey_.reset();
		return true;
	}

	void
	ApplicationCertificate::enable(bool enable)
	{
		enable_ = enable;
	}

	bool
	ApplicationCertificate::enable(void)
	{
		return enable_;
	}

	void
	ApplicationCertificate::certificateTrustListLocation(const std::string& certificateTrustListLocation)
	{
		certificateTrustListLocation_ = certificateTrustListLocation;
	}

	std::string&
	ApplicationCertificate::certificateTrustListLocation(void)
	{
		return certificateTrustListLocation_;
	}

	void
	ApplicationCertificate::certificateRejectListLocation(const std::string& certificateRejectListLocation)
	{
		certificateRejectListLocation_ = certificateRejectListLocation;
	}

	std::string&
	ApplicationCertificate::certificateRejectListLocation(void)
	{
		return certificateRejectListLocation_;
	}

	void
	ApplicationCertificate::certificateRevocationListLocation(const std::string& certificateRevocationListLocation)
	{
		certificateRevocationListLocation_ = certificateRevocationListLocation;
	}

	std::string&
	ApplicationCertificate::certificateRevocationListLocation(void)
	{
		return certificateRevocationListLocation_;
	}

	void
	ApplicationCertificate::issuersCertificatesLocation(const std::string& issuersCertificatesLocation)
	{
		issuersCertificatesLocation_ = issuersCertificatesLocation;
	}

	std::string&
	ApplicationCertificate::issuersCertificatesLocation(void)
	{
		return issuersCertificatesLocation_;
	}

	void
	ApplicationCertificate::issuersRevocationListLocation(const std::string& issuersRevocationListLocation)
	{
		issuersRevocationListLocation_ = issuersRevocationListLocation;
	}

	std::string&
	ApplicationCertificate::issuersRevocationListLocation(void)
	{
		return issuersRevocationListLocation_;
	}

	void
	ApplicationCertificate::serverCertificateFile(const std::string& serverCertificateFile)
	{
		serverCertificateFile_ = serverCertificateFile;
	}

	std::string&
	ApplicationCertificate::serverCertificateFile(void)
	{
		return serverCertificateFile_;
	}

	void
	ApplicationCertificate::privateKeyFile(const std::string& privateKeyFile)
	{
		privateKeyFile_ = privateKeyFile;
	}

	std::string&
	ApplicationCertificate::privateKeyFile(void)
	{
		return privateKeyFile_;
	}

	void
	ApplicationCertificate::generateCertificate(bool generateCertificate)
	{
		generateCertificate_ = generateCertificate;
	}

	bool
	ApplicationCertificate::generateCertificate(void)
	{
		return generateCertificate_;
	}

	void
	ApplicationCertificate::uri(const std::string& uri)
	{
		uri_ = uri;
	}

	std::string&
	ApplicationCertificate::uri(void)
	{
		return uri_;
	}

	void
	ApplicationCertificate::commonName(const std::string& commonName)
	{
		commonName_ = commonName;
	}

	std::string&
	ApplicationCertificate::commonName(void)
	{
		return commonName_;
	}

	void
	ApplicationCertificate::domainComponent(const std::string& domainComponent)
	{
		domainComponent_ = domainComponent;
	}

	std::string&
	ApplicationCertificate::domainComponent(void)
	{
		return domainComponent_;
	}

	void
	ApplicationCertificate::organization(const std::string& organization)
	{
		organization_ = organization;
	}

	std::string&
	ApplicationCertificate::organization(void)
	{
		return organization_;
	}

	void
	ApplicationCertificate::organizationUnit(const std::string& organizationUnit)
	{
		organizationUnit_ = organizationUnit;
	}

	std::string&
	ApplicationCertificate::organizationUnit(void)
	{
		return organizationUnit_;
	}

	void
	ApplicationCertificate::locality(const std::string& locality)
	{
		locality_ = locality;
	}

	std::string&
	ApplicationCertificate::locality(void)
	{
		return locality_;
	}

	void
	ApplicationCertificate::state(const std::string& state)
	{
		state_ = state;
	}

	std::string&
	ApplicationCertificate::state(void)
	{
		return state_;
	}

	void
	ApplicationCertificate::country(const std::string& country)
	{
		country_ = country;
	}

	std::string&
	ApplicationCertificate::country(void)
	{
		return country_;
	}

	void
	ApplicationCertificate::yearsValidFor(uint32_t yearsValidFor)
	{
		yearsValidFor_ = yearsValidFor;
	}

	uint32_t
	ApplicationCertificate::yearsValidFor(void)
	{
		return yearsValidFor_;
	}

	void
	ApplicationCertificate::keyLength(uint32_t keyLength)
	{
		keyLength_ = keyLength;
	}

	uint32_t
	ApplicationCertificate::keyLength(void)
	{
		return keyLength_;
	}

	void
	ApplicationCertificate::certificateType(const std::string& certificateType)
	{
		certificateType_ = certificateType;
	}

	std::string&
	ApplicationCertificate::certificateType(void)
	{
		return certificateType_;
	}

	std::vector<std::string>&
	ApplicationCertificate::ipAddress(void)
	{
		return ipAddress_;
	}

	std::vector<std::string>&
	ApplicationCertificate::dnsName(void)
	{
		return dnsName_;
	}

	void
	ApplicationCertificate::email(const std::string& email)
	{
		email_ = email;
	}

	std::string&
	ApplicationCertificate::email(void)
	{
		return email_;
	}

	Certificate::SPtr&
	ApplicationCertificate::certificate(void)
	{
		return certificate_;
	}

	PrivateKey::SPtr&
	ApplicationCertificate::privateKey(void)
	{
		return privateKey_;
	}

	bool
	ApplicationCertificate::checkAndCreateDirectory(const std::string& directory)
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
	ApplicationCertificate::setReadOnly(const std::string& directory)
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

	bool
	ApplicationCertificate::createSelfSignedCertificate(void)
	{
		// check if certificate is enabled
		if (!enable_) {
			return true;
		}

		// check if self signed certificate is enables
		if (!generateCertificate()) {
			return true;
		}

		// check if private key and certificate exist
		if (boost::filesystem::exists(serverCertificateFile_) && boost::filesystem::exists(privateKeyFile_)) {
			return true;
		}

		// remove certificate file and private key file
		boost::filesystem::remove(serverCertificateFile_);
		boost::filesystem::remove(privateKeyFile_);

		// --------------------------------------------------------------------
		// create self signed certificate
		// --------------------------------------------------------------------
		RSAKey key(keyLength_);
		if (key.isError()) {
			key.log(Error, "create RSA key error");
			return false;
		}

		Identity identity;
		identity.organization(organization_);
		identity.organizationUnit(organizationUnit_);
		identity.commonName(commonName_);
		identity.locality(locality_);
		identity.state(state_);
		identity.country(country_);
		identity.domainComponent(domainComponent_);

		CertificateInfo info;
		info.uri(uri_);
		info.ipAddresses() = ipAddress_;
		info.dnsNames() = dnsName_;
		info.eMail(email_);
		info.validTime(boost::posix_time::microsec_clock::local_time() + boost::posix_time::seconds(3600*24*365*yearsValidFor_));
		info.serialNumber(time(0));
		info.validFrom(boost::posix_time::microsec_clock::local_time());

		SignatureAlgorithm signatureAlgorithm;
		if (certificateType_ == "RsaMin") {
			signatureAlgorithm = SignatureAlgorithm_Sha1;
		}
		else {
			signatureAlgorithm = SignatureAlgorithm_Sha256;
		}

		// create self signed certificate
		Certificate certificate(info, identity, key, false, signatureAlgorithm);
		if (certificate.isError()) {
			certificate.log(Error, "create self signed certificate error");
			return false;
		}

		// save self signed cerificate
		certificate.toDERFile(serverCertificateFile_);
		if (certificate.isError()) {
			certificate.log(Error, "save self signed certificate error");
			return false;
		}

		// create private key
		if (!key.privateKey().toPEMFile(privateKeyFile_, nullptr)) {
			certificate.log(Error, "save private key error");
			return false;
		}

		return true;
	}

	bool
	ApplicationCertificate::readCertificateAndPrivateKey(void)
	{
		// read certificate from file
		certificate_ = constructSPtr<Certificate>();
		if (!certificate_->fromDERFile(serverCertificateFile_)) {
			certificate_->log(Error, "read certificate error");
			certificate_.reset();
			return false;
		}

		// read private key from file
		privateKey_ = constructSPtr<PrivateKey>();
		if (!privateKey_->fromPEMFile(privateKeyFile_, nullptr)) {
			privateKey_->log(Error, "read private key error");
			privateKey_.reset();
			certificate_.reset();
			return false;
		}

		return true;
	}

}
