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
				"selfSigned",
				boost::program_options::value<bool>()->default_value(true),
			    "create self signed certificate and keys"
			)
			(
				"ca",
				boost::program_options::value<bool>()->default_value(false),
			    "create ca certificate and keys"
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
		selfSigned_ = vm["selfSigned"].as<bool>();
		ca_ = vm["ca"].as<bool>();

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
		bool rc;

		// create new key
		RSAKey key(2048);

		// create issuer
		Identity identity;
		identity.organization("ASNeG");
		identity.organizationUnit("OPC UA Service Department");
		identity.commonName("ASNeG-CA");
		identity.locality("Neukirchen");
		identity.state("Hessen");
		identity.country("DE");
		identity.domainComponent("devel");

		// create certificate info
		CertificateInfo info;
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

		// create certificate
		Certificate certificate;
		rc = certificate.createCertificate(
		     info,
			 identity,
			 key,
			 true,
			 SignatureAlgorithm_Sha256
		);
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
		return 0;
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


