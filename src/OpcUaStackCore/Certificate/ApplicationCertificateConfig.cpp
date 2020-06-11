/*
   Copyright 2018-2020 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   ApplicationCertificateConfigrmationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include <boost/asio.hpp>
#include <boost/algorithm/string.hpp>
#include <OpcUaStackCore/Certificate/ApplicationCertificateConfig.h>
#include <iostream>
#include "OpcUaStackCore/Base/Log.h"

namespace OpcUaStackCore
{

	ApplicationCertificateConfig::ApplicationCertificateConfig(void)
	{
	}

	ApplicationCertificateConfig::~ApplicationCertificateConfig(void)
	{
	}

	bool
	ApplicationCertificateConfig::parse(
		CertificateManager::SPtr& certificateManager,
		const std::string& configPrefixServerInfo,
		const std::string& configPrefixApplicationCertificate,
		Config* childConfig,
		const std::string& configurationFileName
	)
	{
		boost::optional<Config> child;

		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		//
		// server info
		//
		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		// --------------------------------------------------------------------

		// check if server info configuration exists
		child = childConfig->getChild(configPrefixServerInfo);
		if (!child) {
			Log(Info, "server info element not exist in configuration")
				.parameter("FileName", configurationFileName);
			return false;
		}

		// get server uri
		std::string serverUri;
		if (!child->getConfigParameter("ServerUri", serverUri) == true) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", configPrefixServerInfo + std::string(".ServerUri"));
			return false;
		}
		certificateManager->certificateSettings().serverUri(serverUri);

		// get server name
		std::string serverName;
		if (!child->getConfigParameter("ServerName", serverName) == true) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", configPrefixServerInfo + std::string(".ServerName"));
			return false;
		}
		certificateManager->certificateSettings().serverName(serverName);

		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		//
		// certificate settings
		//
		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		// --------------------------------------------------------------------

		// checks if server certificate configuration exists
		child = childConfig->getChild(configPrefixApplicationCertificate);
		if (!child) {
			Log(Info, "application certificate is disabled");
			return true;
		}

		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		//
		// Folder
		//
		// --------------------------------------------------------------------
		// --------------------------------------------------------------------

		// get certificate trust list location
		std::string certificateTrustListLocation;
		if (!child->getConfigParameter("Folder.CertificateTrustListLocation", certificateTrustListLocation) == true) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", configPrefixApplicationCertificate + std::string(".Folder.CertificateTrustListLocation"));
			return false;
		}
		certificateManager->certificateTrustListLocation(certificateTrustListLocation);

		// get certificate revocation list location
		std::string certificateRevocationListLocation;
		if (!child->getConfigParameter("Folder.CertificateRevocationListLocation", certificateRevocationListLocation) == true) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", configPrefixApplicationCertificate + std::string(".Folder.CertificateRevocationListLocation"));
			return false;
		}
		certificateManager->certificateRevocationListLocation(certificateRevocationListLocation);

		// get issuer certificates location
		std::string issuersCertificatesLocation;
		if (!child->getConfigParameter("Folder.IssuersCertificatesLocation", issuersCertificatesLocation) == true) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", configPrefixApplicationCertificate + std::string(".Folder.IssuersCertificatesLocation"));
			return false;
		}
		certificateManager->issuersCertificatesLocation(issuersCertificatesLocation);

		// get issuer revocation list location
		std::string issuersRevocationListLocation;
		if (!child->getConfigParameter("Folder.IssuersRevocationListLocation", issuersRevocationListLocation) == true) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", configPrefixApplicationCertificate + std::string(".Folder.IssuersRevocationListLocation"));
			return false;
		}
		certificateManager->issuersRevocationListLocation(issuersRevocationListLocation);

		// get certificate reject list location
		std::string certificateRejectListLocation;
		if (!child->getConfigParameter("Folder.CertificateRejectListLocation", certificateRejectListLocation) == true) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", configPrefixApplicationCertificate + std::string(".Folder.CertificateRejectListLocation"));
			return false;
		}
		certificateManager->certificateRejectListLocation(certificateRejectListLocation);


		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		//
		// Files
		//
		// --------------------------------------------------------------------
		// --------------------------------------------------------------------

		// get server certificate file
		std::string ownCertificateFile;
		if (!child->getConfigParameter("Files.ApplicationCertificateFile", ownCertificateFile) == true) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", configPrefixApplicationCertificate + std::string(".Files.ServerCertificateFile"));
			return false;
		}
		certificateManager->ownCertificateFile(ownCertificateFile);

		// get private key file
		std::string ownPrivateKeyFile;
		if (!child->getConfigParameter("Files.PrivateKeyFile", ownPrivateKeyFile) == true) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", configPrefixApplicationCertificate + std::string(".Files.PrivateKeyFile"));
			return false;
		}
		certificateManager->ownPrivateKeyFile(ownPrivateKeyFile);

		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		//
		// CertificateSettings
		//
		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		CertificateSettings& certificateSettings = certificateManager->certificateSettings();
		certificateSettings.enable(false);

		// get generate certificate flag
		std::string generateCertificate;
		if (!child->getConfigParameter("CertificateSettings.GenerateCertificate", generateCertificate) == true) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", configPrefixApplicationCertificate + std::string(".CertificateSettings.GenerateCertificate"));
			return false;
		}
		boost::to_upper(generateCertificate);
		if (generateCertificate == "TRUE") {
			certificateSettings.generateCertificate(true);
		}
		else {
			certificateSettings.generateCertificate(false);
		}

		// get common name
		std::string commonName;
		if (!child->getConfigParameter("CertificateSettings.CommonName", commonName) == true) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", configPrefixApplicationCertificate + std::string(".CertificateSettings.CommonName"));
			return false;
		}
		certificateSettings.commonName(commonName);

		// get domain component
		std::string domainComponent;
		if (!child->getConfigParameter("CertificateSettings.DomainComponent", domainComponent) == true) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", configPrefixApplicationCertificate + std::string(".CertificateSettings.DomainComponent"));
			return false;
		}
		certificateSettings.domainComponent(domainComponent);

		// get organization
		std::string organization;
		if (!child->getConfigParameter("CertificateSettings.Organization", organization) == true) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", configPrefixApplicationCertificate + std::string(".CertificateSettings.Organization"));
			return false;
		}
		certificateSettings.organization(organization);

		// get organization unit
		std::string organizationUnit;
		if (!child->getConfigParameter("CertificateSettings.OrganizationUnit", organizationUnit) == true) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", configPrefixApplicationCertificate + std::string(".CertificateSettings.OrganizationUnit"));
			return false;
		}
		certificateSettings.organizationUnit(organizationUnit);

		// get locality
		std::string locality;
		if (!child->getConfigParameter("CertificateSettings.Locality", locality) == true) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", configPrefixApplicationCertificate + std::string(".CertificateSettings.Locality"));
			return false;
		}
		certificateSettings.locality(locality);

		// get state
		std::string state;
		if (!child->getConfigParameter("CertificateSettings.State", state) == true) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", configPrefixApplicationCertificate + std::string(".CertificateSettings.State"));
			return false;
		}
		certificateSettings.state(state);

		// get country
		std::string country;
		if (!child->getConfigParameter("CertificateSettings.Country", country) == true) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", configPrefixApplicationCertificate + std::string(".CertificateSettings.Country"));
			return false;
		}
		certificateSettings.country(country);

		// get years valid for
		uint32_t yearsValidFor;
		if (!child->getConfigParameter("CertificateSettings.YearsValidFor", yearsValidFor) == true) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", configPrefixApplicationCertificate + std::string(".CertificateSettings.YearsValidFor"));
			return false;
		}
		certificateSettings.yearsValidFor(yearsValidFor);

		// get key length
		uint32_t keyLength;
		if (!child->getConfigParameter("CertificateSettings.KeyLength", keyLength) == true) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", configPrefixApplicationCertificate + std::string(".CertificateSettings.KeyLength"));
			return false;
		}

		// get certificate type
		std::string certificateType;
		if (!child->getConfigParameter("CertificateSettings.CertificateType", certificateType) == true) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", configPrefixApplicationCertificate + std::string(".CertificateSettings.CertificateType"));
			return false;
		}

		if (certificateType == "RsaMin") {
			if (keyLength != 1024 && keyLength != 2048) {
				Log(Error, "parameter invalid in configuration file")
					.parameter("ConfigurationFileName", configurationFileName)
					.parameter("ParameterPath", configPrefixApplicationCertificate + std::string(".CertificateSettings.KeyLength"))
					.parameter("KeyLength", keyLength)
					.parameter("CertificateType", certificateType);
				return false;
			}
		}
		else if (certificateType == "RsaSha256") {
			if (keyLength != 2048 && keyLength != 3072 && keyLength != 4096) {
				Log(Error, "parameter invalid in configuration file")
					.parameter("ConfigurationFileName", configurationFileName)
					.parameter("ParameterPath", configPrefixApplicationCertificate + std::string(".CertificateSettings.KeyLength"))
					.parameter("KeyLength", keyLength)
					.parameter("CertificateType", certificateType);
				return false;
			}
		}
		else {
			Log(Error, "parameter invalid in configuration file")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", configPrefixApplicationCertificate + std::string(".CertificateSettings.CertificateType"))
				.parameter("CertificateType", certificateType);
			return false;
		}

		certificateSettings.keyLength(keyLength);
		certificateSettings.certificateType(certificateType);

		// get ip address
		std::vector<std::string> ipAddresses;
		child->getValues("CertificateSettings.IPAddress", ipAddresses);
		if (ipAddresses.size() == 0) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", configPrefixApplicationCertificate + std::string(".CertificateSettings.IPAddress"));
			return false;
		}
		for ( auto ipAddress : ipAddresses ) {
			// check the format of the ip address
			boost::system::error_code ec;
			boost::asio::ip::address::from_string(ipAddress, ec);
			if (ec != boost::system::errc::success) {
				Log(Error, "invalid address format found in configuration")
					.parameter("ParameterName", configPrefixApplicationCertificate + std::string(".CertificateSettings.IPAddress"))
					.parameter("ParameterValue", ipAddress);
				return false;
			}

			// add the ip address to the address list
			certificateSettings.ipAddress().push_back(ipAddress);
		}

		// get dns name
		std::vector<std::string>::iterator itDnsName;
		std::vector<std::string> dnsNames;
		child->getValues("CertificateSettings.DNSName", dnsNames);
		if (ipAddresses.size() == 0) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", configPrefixApplicationCertificate + std::string(".CertificateSettings.DNSName"));
			return false;
		}
		for (itDnsName = dnsNames.begin(); itDnsName != dnsNames.end(); itDnsName++) {
			certificateSettings.dnsName().push_back(*itDnsName);
		}

		// get email
		std::string email;
		if (!child->getConfigParameter("CertificateSettings.EMail", email) == true) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", configPrefixApplicationCertificate + std::string(".CertificateSettings.EMail"));
			return false;
		}
		certificateSettings.email(email);

		certificateSettings.enable(true);
		return true;
	}

}
