/*
   Copyright 2019 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   CertificateSettingsrmationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include "OpcUaStackCore/Certificate/CertificateSettings.h"

namespace OpcUaStackCore
{

	CertificateSettings::CertificateSettings(void)
	: enable_(false)
	, generateCertificate_(true)
	, serverUri_("")
	, serverName_("")
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
	{
	}

	CertificateSettings::~CertificateSettings(void)
	{
	}

	void
	CertificateSettings::enable(bool enable)
	{
		enable_ = enable;
	}

	bool
	CertificateSettings::enable(void)
	{
		return enable_;
	}


	void
	CertificateSettings::generateCertificate(bool generateCertificate)
	{
		generateCertificate_ = generateCertificate;
	}

	bool
	CertificateSettings::generateCertificate(void)
	{
		return generateCertificate_;
	}

	void
	CertificateSettings::serverUri(const std::string& serverUri)
	{
		serverUri_ = serverUri;
	}

	std::string&
	CertificateSettings::serverUri(void)
	{
		return serverUri_;
	}

	void
	CertificateSettings::serverName(const std::string& serverName)
	{
		serverName_ = serverName;
	}

	std::string&
	CertificateSettings::serverName(void)
	{
		return serverName_;
	}

	void
	CertificateSettings::commonName(const std::string& commonName)
	{
		commonName_ = commonName;
	}

	std::string&
	CertificateSettings::commonName(void)
	{
		return commonName_;
	}

	void
	CertificateSettings::domainComponent(const std::string& domainComponent)
	{
		domainComponent_ = domainComponent;
	}

	std::string&
	CertificateSettings::domainComponent(void)
	{
		return domainComponent_;
	}

	void
	CertificateSettings::organization(const std::string& organization)
	{
		organization_ = organization;
	}

	std::string&
	CertificateSettings::organization(void)
	{
		return organization_;
	}

	void
	CertificateSettings::organizationUnit(const std::string& organizationUnit)
	{
		organizationUnit_ = organizationUnit;
	}

	std::string&
	CertificateSettings::organizationUnit(void)
	{
		return organizationUnit_;
	}

	void
	CertificateSettings::locality(const std::string& locality)
	{
		locality_ = locality;
	}

	std::string&
	CertificateSettings::locality(void)
	{
		return locality_;
	}

	void
	CertificateSettings::state(const std::string& state)
	{
		state_ = state;
	}

	std::string&
	CertificateSettings::state(void)
	{
		return state_;
	}

	void
	CertificateSettings::country(const std::string& country)
	{
		country_ = country;
	}

	std::string&
	CertificateSettings::country(void)
	{
		return country_;
	}

	void
	CertificateSettings::yearsValidFor(uint32_t yearsValidFor)
	{
		yearsValidFor_ = yearsValidFor;
	}

	uint32_t
	CertificateSettings::yearsValidFor(void)
	{
		return yearsValidFor_;
	}

	void
	CertificateSettings::keyLength(uint32_t keyLength)
	{
		keyLength_ = keyLength;
	}

	uint32_t
	CertificateSettings::keyLength(void)
	{
		return keyLength_;
	}

	void
	CertificateSettings::certificateType(const std::string& certificateType)
	{
		certificateType_ = certificateType;
	}

	std::string&
	CertificateSettings::certificateType(void)
	{
		return certificateType_;
	}

	std::vector<std::string>&
	CertificateSettings::ipAddress(void)
	{
		return ipAddress_;
	}

	std::vector<std::string>&
	CertificateSettings::dnsName(void)
	{
		return dnsName_;
	}

	void
	CertificateSettings::email(const std::string& email)
	{
		email_ = email;
	}

	std::string&
	CertificateSettings::email(void)
	{
		return email_;
	}


}
