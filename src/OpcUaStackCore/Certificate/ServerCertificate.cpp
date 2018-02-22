/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   ServerCertificatermationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include <OpcUaStackCore/Certificate/ServerCertificate.h>

namespace OpcUaStackCore
{

	ServerCertificate::ServerCertificate(void)
	: enable_(false)
	, certificateTrustListLocation_("")
	, certificateRejectListLocation_("")
	, certificateRevocationListLocation_("")
	, issuersCertificatesLocation_("")
	, issuersRevocationListLocation_("")
	, rejectListLocation_("")

	, serverCertificateFile_("")
	, privateKeyFile_("")

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
	{
	}

	ServerCertificate::~ServerCertificate(void)
	{
	}

	bool
	ServerCertificate::init(void)
	{
		// FIXME: todo
		return true;
	}

	bool
	ServerCertificate::cleanup(void)
	{
		// FIXME: todo
		return true;
	}

	void
	ServerCertificate::enable(bool enable)
	{
		enable_ = enable;
	}

	bool
	ServerCertificate::enable(void)
	{
		return enable_;
	}

	void
	ServerCertificate::certificateTrustListLocation(const std::string& certificateTrustListLocation)
	{
		certificateTrustListLocation_ = certificateTrustListLocation;
	}

	std::string&
	ServerCertificate::certificateTrustListLocation(void)
	{
		return certificateTrustListLocation_;
	}

	void
	ServerCertificate::certificateRejectListLocation(const std::string& certificateRejectListLocation)
	{
		certificateRejectListLocation_ = certificateRejectListLocation;
	}

	std::string&
	ServerCertificate::certificateRejectListLocation(void)
	{
		return certificateRejectListLocation_;
	}

	void
	ServerCertificate::certificateRevocationListLocation(const std::string& certificateRevocationListLocation)
	{
		certificateRevocationListLocation_ = certificateRevocationListLocation;
	}

	std::string&
	ServerCertificate::certificateRevocationListLocation(void)
	{
		return certificateRevocationListLocation_;
	}

	void
	ServerCertificate::issuersCertificatesLocation(const std::string& issuersCertificatesLocation)
	{
		issuersCertificatesLocation_ = issuersCertificatesLocation;
	}

	std::string&
	ServerCertificate::issuersCertificatesLocation(void)
	{
		return issuersCertificatesLocation_;
	}

	void
	ServerCertificate::issuersRevocationListLocation(const std::string& issuersRevocationListLocation)
	{
		issuersRevocationListLocation_ = issuersRevocationListLocation;
	}

	std::string&
	ServerCertificate::issuersRevocationListLocation(void)
	{
		return issuersRevocationListLocation_;
	}

	void
	ServerCertificate::rejectListLocation(const std::string& rejectListLocation)
	{
		rejectListLocation_ = rejectListLocation;
	}

	std::string&
	ServerCertificate::rejectListLocation(void)
	{
		return rejectListLocation_;
	}

	void
	ServerCertificate::serverCertificateFile(const std::string& serverCertificateFile)
	{
		serverCertificateFile_ = serverCertificateFile;
	}

	std::string&
	ServerCertificate::serverCertificateFile(void)
	{
		return serverCertificateFile_;
	}

	void
	ServerCertificate::privateKeyFile(const std::string& privateKeyFile)
	{
		privateKeyFile_ = privateKeyFile;
	}

	std::string&
	ServerCertificate::privateKeyFile(void)
	{
		return privateKeyFile_;
	}

	void
	ServerCertificate::commonName(const std::string& commonName)
	{
		commonName_ = commonName;
	}

	std::string&
	ServerCertificate::commonName(void)
	{
		return commonName_;
	}

	void
	ServerCertificate::domainComponent(const std::string& domainComponent)
	{
		domainComponent_ = domainComponent;
	}

	std::string&
	ServerCertificate::domainComponent(void)
	{
		return domainComponent_;
	}

	void
	ServerCertificate::organization(const std::string& organization)
	{
		organization_ = organization;
	}

	std::string&
	ServerCertificate::organization(void)
	{
		return organization_;
	}

	void
	ServerCertificate::organizationUinit(const std::string& organizationUnit)
	{
		organizationUnit_ = organizationUnit;
	}

	std::string&
	ServerCertificate::organizationUnit(void)
	{
		return organizationUnit_;
	}

	void
	ServerCertificate::locality(const std::string& locality)
	{
		locality_ = locality;
	}

	std::string&
	ServerCertificate::locality(void)
	{
		return locality_;
	}

	void
	ServerCertificate::state(const std::string& state)
	{
		state_ = state;
	}

	std::string&
	ServerCertificate::state(void)
	{
		return state_;
	}

	void
	ServerCertificate::country(const std::string& country)
	{
		country_ = country;
	}

	std::string&
	ServerCertificate::country(void)
	{
		return country_;
	}

	void
	ServerCertificate::yearsValidFor(uint32_t yearsValidFor)
	{
		yearsValidFor_ = yearsValidFor;
	}

	uint32_t
	ServerCertificate::yearsValidFor(void)
	{
		return yearsValidFor_;
	}

	void
	ServerCertificate::keyLength(uint32_t keyLength)
	{
		keyLength_ = keyLength;
	}

	uint32_t
	ServerCertificate::keyLength(void)
	{
		return keyLength_;
	}

	void
	ServerCertificate::certificateType(const std::string& certificateType)
	{
		certificateType_ = certificateType;
	}

	std::string&
	ServerCertificate::certificateType(void)
	{
		return certificateType_;
	}

	std::vector<std::string>&
	ServerCertificate::ipAddress(void)
	{
		return ipAddress_;
	}

	std::vector<std::string>&
	ServerCertificate::dnsName(void)
	{
		return dnsName_;
	}

}
