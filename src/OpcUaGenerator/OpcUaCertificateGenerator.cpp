/*
   Copyright 2019 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include <boost/program_options.hpp>
#include <iostream>
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/Base/ConfigXml.h"
#include "OpcUaGenerator/OpcUaCertificateGenerator.h"
#include "OpcUaStackCore/Certificate/Certificate.h"
#include "OpcUaStackCore/Certificate/RSAKey.h"
#include "OpcUaStackCore/Certificate/Identity.h"
#include "OpcUaStackCore/Certificate/CertificateInfo.h"
#include "BuildConfig.h"

using namespace OpcUaStackCore;

namespace OpcUaCertificateGenerator
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaCertificateGenerator
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaCertificateGenerator::OpcUaCertificateGenerator(void)
	{
	}

	OpcUaCertificateGenerator::~OpcUaCertificateGenerator(void)
	{
	}

	uint32_t
	OpcUaCertificateGenerator::start(int argc, char** argv)
	{
		boost::program_options::options_description desc("Allowed options");
		desc.add_options()
		    (
		    	"help",
				"produce help message"
		    )
			(
				"version",
				"print version string"
			)
			(
				"command",
				boost::program_options::value<std::string>()->default_value("create"),
			    "command: create"
			)
		    (
		    	"descFile",
				boost::program_options::value<std::string>()->default_value("CertDesc.xml"),
				"set certificate description file name"
			)
			(
				"ca",
				boost::program_options::value<bool>()->default_value(false),
			    "create ca certificate and keys"
			)
			(
				"issuer",
				boost::program_options::value<std::string>()->default_value(""),
			    "issuer name"
			)
		;

		boost::program_options::variables_map vm;
		boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
		boost::program_options::notify(vm);

		if (vm.count("help")) {
		    std::cout << desc << std::endl;
		    return 1;
		}

		if (vm.count("version")) {
		    std::cout << VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_PATCH <<  std::endl;
		    return 1;
		}

		command_ = vm["command"].as<std::string>();
		descFile_ = vm["descFile"].as<std::string>();
		ca_ = vm["ca"].as<bool>();
		issuer_ = vm["issuer"].as<std::string>();

		if (command_ == "create") {
			return createCertificate();
		}
		else {
			std::cout << "unknown command " << command_ << std::endl;
			return 1;
		}

		return 0;
	}

	uint32_t
	OpcUaCertificateGenerator::createCertificate(void)
	{
		if (!readCertificateSettings(descFile_)) {
			return 1;
		}

		if (!readIssuer(issuer_)) {
			return 1;
		}

		Log(Info, "create ca certificate");

		bool rc;

		// create new key
		RSAKey key(keyLength_);

		// create issuer
		Identity identity;
		identity.organization(organization_);
		identity.organizationUnit(organizationUnit_);
		identity.commonName(commonName_);
		identity.locality(locality_);
		identity.state(state_);
		identity.country(country_);
		identity.domainComponent(domainComponent_);

		// create certificate info
		CertificateInfo info;
		info.clear();
		info.uri(uri_);
		info.ipAddresses(ipAddresses_);
		info.dnsNames(dnsNames_);
		info.eMail(email_);
		info.validTime(
			boost::posix_time::microsec_clock::universal_time() +
			boost::posix_time::seconds(3600*24*365*yearsValidFor_)
		);
		info.serialNumber(time(0));
		info.validFrom(boost::posix_time::microsec_clock::universal_time());

		// create certificate
		Certificate certificate;
		if (issuer_.empty()) {
			rc = certificate.createCertificate(
				info,
				identity,
				key,
				ca_,
				SignatureAlgorithm_Sha256
			);
		}
		else {
			auto subjectPublicKey = key.publicKey();
			rc = certificate.createCertificate(
				info,
				identity,
				subjectPublicKey,
				issuerCertificate_,
				issuerPrivateKey_,
				false,
				SignatureAlgorithm_Sha256
			);
		}
		if (!rc || certificate.isError()) {
			std::cout << "generate certificate error" << std::endl;
			return 1;
		}

		// write certificate to file
		std::string certFileName = identity.commonName() + ".der";
		rc = certificate.toDERFile(certFileName);
		if (!rc || certificate.isError()) {
			std::cout << "save certificate file error: " << certFileName << std::endl;
			return 1;
		}

		// write private key
		std::string privKeyFileName = identity.commonName()+ ".pem";
		rc = key.privateKey().toPEMFile(privKeyFileName, nullptr);
		if (!rc || key.isError()) {
			std::cout << "save private key file error: " << privKeyFileName << std::endl;
			return 1;
		}

		std::cout << "success" << std::endl;
		return 0;
	}

	bool
	OpcUaCertificateGenerator::readIssuer(const std::string& issuer)
	{
		if (issuer.empty()) {
			return true;
		}

		// read issuer certificate
		std::string issuerCertificateName = issuer + ".der";
		if (!issuerCertificate_.fromDERFile(issuerCertificateName)) {
			std::cout << "read issuer certificate error" << std::endl;
			return false;
		}

		// read issuer private key
		std::string issuerPrivateKeyName = issuer + ".pem";
		if (!issuerPrivateKey_.fromPEMFile(issuerPrivateKeyName, nullptr)) {
			std::cout << "read issuer private key error" << std::endl;
			return false;
		}

		return true;
	}

	bool
	OpcUaCertificateGenerator::readCertificateSettings(const std::string& fileName)
	{
		// read configuration
		Config config;
		ConfigXml configXml;
		if (!configXml.parse(fileName, &config)) {
			std::cout << "read description file error: " << fileName << std::endl;
			std::cout << "error: " << configXml.errorMessage() << std::endl;
			return false;
		}

		// get organization
		if (!config.getConfigParameter("CertificateSettings.Organization", organization_) == true) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", fileName)
				.parameter("ParameterPath", "CertificateSettings.Organization");
			return false;
		}

		// get organization unit
		std::string organizationUnit;
		if (!config.getConfigParameter("CertificateSettings.OrganizationUnit", organizationUnit_)) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", fileName)
				.parameter("ParameterPath", "CertificateSettings.OrganizationUnit");
			return false;
		}

		// get common name;
		if (!config.getConfigParameter("CertificateSettings.CommonName", commonName_)) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", fileName)
				.parameter("ParameterPath", "CertificateSettings.CommonName");
			return false;
		}

		// get locality
		if (!config.getConfigParameter("CertificateSettings.Locality", locality_)) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", fileName)
				.parameter("ParameterPath", "CertificateSettings.Locality");
			return false;
		}

		// get state
		if (!config.getConfigParameter("CertificateSettings.State", state_)) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", fileName)
				.parameter("ParameterPath", "CertificateSettings.State");
			return false;
		}

		// get country
		std::string country;
		if (!config.getConfigParameter("CertificateSettings.Country", country_)) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", fileName)
				.parameter("ParameterPath", "CertificateSettings.Country");
			return false;
		}

		// get domain component
		if (!config.getConfigParameter("CertificateSettings.DomainComponent", domainComponent_)) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", fileName)
				.parameter("ParameterPath", "CertificateSettings.DomainComponent");
			return false;
		}

		// get uri
		if (!config.getConfigParameter("CertificateSettings.Uri", uri_)) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", fileName)
				.parameter("ParameterPath", "CertificateSettings.Uri");
			return false;
		}

		// get ip address
		config.getValues("CertificateSettings.IPAddress", ipAddresses_);
		if (ipAddresses_.empty()) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", fileName)
				.parameter("ParameterPath", "CertificateSettings.IPAddress");
			return false;
		}

		// get dns name
		config.getValues("CertificateSettings.DNSName", dnsNames_);
		if (dnsNames_.empty()) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", fileName)
				.parameter("ParameterPath", "CertificateSettings.DNSName");
			return false;
		}

		// get email
		if (!config.getConfigParameter("CertificateSettings.EMail", email_)) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", fileName)
				.parameter("ParameterPath", "CertificateSettings.EMail");
			return false;
		}

		// get years valid for
		if (!config.getConfigParameter("CertificateSettings.YearsValidFor", yearsValidFor_)) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", fileName)
				.parameter("ParameterPath", "CertificateSettings.YearsValidFor");
			return false;
		}

		// get key length
		if (!config.getConfigParameter("CertificateSettings.KeyLength", keyLength_)) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", fileName)
				.parameter("ParameterPath", "CertificateSettings.KeyLength");
			return false;
		}

		// get certificate type
		if (!config.getConfigParameter("CertificateSettings.CertificateType", certificateType_) == true) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", fileName)
				.parameter("ParameterPath", "CertificateSettings.CertificateType");
			return false;
		}

		if (certificateType_ == "RsaMin") {
			if (keyLength_ != 1024 && keyLength_ != 2048) {
				Log(Error, "parameter invalid in configuration file")
					.parameter("ConfigurationFileName", fileName)
					.parameter("ParameterPath", "CertificateSettings.KeyLength")
					.parameter("KeyLength", keyLength_)
					.parameter("CertificateType", certificateType_);
				return false;
			}
		}
		else if (certificateType_ == "RsaSha256") {
			if (keyLength_ != 2048 && keyLength_ != 3072 && keyLength_ != 4096) {
				Log(Error, "parameter invalid in configuration file")
					.parameter("ConfigurationFileName", fileName)
					.parameter("ParameterPath", "CertificateSettings.KeyLength")
					.parameter("KeyLength", keyLength_)
					.parameter("CertificateType", certificateType_);
				return false;
			}
		}
		else {
			Log(Error, "parameter invalid in configuration file")
				.parameter("ConfigurationFileName", fileName)
				.parameter("ParameterPath", "CertificateSettings.CertificateType")
				.parameter("CertificateType", certificateType_);
			return false;
		}

		return true;
	}

}

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
//
// main application
//
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
int main(int argc, char** argv)
{
	OpcUaCertificateGenerator::OpcUaCertificateGenerator certificateGenerator;
	return certificateGenerator.start(argc, argv);
}


