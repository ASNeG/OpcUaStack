/*
   Copyright 2020 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (atimin@gmail.com)
 */

#include <boost/filesystem.hpp>
#include <boost/regex.hpp>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include "OpcUaCtrl/SelfSignedCertCtrlCommand.h"

namespace OpcUaCtrl
{


	SelfSignedCertCtrlCommand::SelfSignedCertCtrlCommand(void)
	: CtrlCommand()
	{
	}

	SelfSignedCertCtrlCommand::~SelfSignedCertCtrlCommand(void)
	{
	}

	uint32_t
	SelfSignedCertCtrlCommand::start(int argc, char** argv)
	{
		// check command parameter
		if (std::string(argv[2]) == "status") {
			return status(argc, argv);
		}
		else if (std::string(argv[2]) == "activate") {
			return activate(argc, argv);
		}
		else if (std::string(argv[2]) == "deactivate") {
			return deactivate(argc, argv);
		}
		else {
			usageMessage(std::string("command ") + std::string(argv[2]) + " unknown");
			return 1;
		}
	}

	void
	SelfSignedCertCtrlCommand::usage(void)
	{
		std::cout << "    Commands:" << std::endl;
		std::cout << "    status <Application-Name>:" << std::endl;
		std::cout << "        shows whether the self signed certificate generation is active" << std::endl;
		std::cout << "    activate <Application-Name>:" << std::endl;
		std::cout << "        activates the self signed certificate generation" << std::endl;
		std::cout << "    deactivate <Application-Name>:" << std::endl;
		std::cout << "        deactivates the seld signed certificate generation" << std::endl;
	}

	void
	SelfSignedCertCtrlCommand::usageMessage(const std::string& message)
	{
		std::cout << "usage: " << name_ << " self_signed_cert <Command> [<Parameter>, ...]" << std::endl;
		std::cout << std::endl;
		std::cout << "ERROR: " << message << std::endl;
		usage();
	}

	uint32_t
	SelfSignedCertCtrlCommand::status(int argc, char** argv)
	{
		// check command line parameter
		if (argc < 4) {
			usageMessage("parameter invalid");
			return 1;
		}
		std::string applicationName = std::string(argv[3]);

		// get application info
		Application application(applBlackList_, installPathList_);
		auto it = application.find(applicationName);
		if (it == application.end()) {
			std::cout << "ERROR: application " << applicationName << " not exist" << std::endl;
			return 1;
		}
		auto applicationInfo = it->second;

		// read configuration file of application
		std::string applicationConfiguration = "";
		if (!readApplicationConfiguration(applicationInfo, applicationConfiguration)) {
			return 1;
		}

		// find <GenerateCertificate>true</GenerateCertificate>
		std::string status = "deactive";
		boost::regex expr{"<GenerateCertificate>\\s*(\\w+)\\s*</GenerateCertificate>"};
		boost::smatch what;
		if (boost::regex_search(applicationConfiguration, what, expr)) {
			std::string flag = what[1];
			boost::to_upper(flag);
			if (flag == "TRUE") {
				status = "active";
			}
		}

		// display state
		std::cout << applicationName << " " << status << std::endl;

		return 0;
	}

	uint32_t
	SelfSignedCertCtrlCommand::activate(int argc, char** argv)
	{
		// check command line parameter
		if (argc < 4) {
			usageMessage("parameter invalid");
			return 1;
		}
		std::string applicationName = std::string(argv[3]);

		// get application info
		Application application(applBlackList_, installPathList_);
		auto it = application.find(applicationName);
		if (it == application.end()) {
			std::cout << "ERROR: application " << applicationName << " not exist" << std::endl;
			return 1;
		}
		auto applicationInfo = it->second;

		// read configuration file of application
		std::string applicationConfiguration = "";
		if (!readApplicationConfiguration(applicationInfo, applicationConfiguration)) {
			return 1;
		}

		// find <GenerateCertificate>true</GenerateCertificate>
		boost::regex expr{"<GenerateCertificate>\\s*(\\w+)\\s*</GenerateCertificate>"};
		boost::smatch what;
		if (!boost::regex_search(applicationConfiguration, what, expr)) {
			std::cout << "ERROR: self signed configuration not exist for application " << applicationName << std::endl;
			return 1;
		}

		// replace self signed certificate configuration flag
		std::string flag = what[1];
		boost::to_upper(flag);
		if (flag == "TRUE") {
			// nothing to do
			return 0;
		}
		std::string fmt = "<GenerateCertificate>true</GenerateCertificate>";
		applicationConfiguration = boost::regex_replace(applicationConfiguration, expr, fmt);

		// write configuration file of application
		if (!writeApplicationConfiguration(applicationInfo, applicationConfiguration)) {
			return 1;
		}

		return 0;
	}

	uint32_t
	SelfSignedCertCtrlCommand::deactivate(int argc, char** argv)
	{
		// check command line parameter
		if (argc < 4) {
			usageMessage("parameter invalid");
			return 1;
		}
		std::string applicationName = std::string(argv[3]);

		// get application info
		Application application(applBlackList_, installPathList_);
		auto it = application.find(applicationName);
		if (it == application.end()) {
			std::cout << "ERROR: application " << applicationName << " not exist" << std::endl;
			return 1;
		}
		auto applicationInfo = it->second;

		// read configuration file of application
		std::string applicationConfiguration = "";
		if (!readApplicationConfiguration(applicationInfo, applicationConfiguration)) {
			return 1;
		}

		// find <GenerateCertificate>true</GenerateCertificate>
		boost::regex expr{"<GenerateCertificate>\\s*(\\w+)\\s*</GenerateCertificate>"};
		boost::smatch what;
		if (!boost::regex_search(applicationConfiguration, what, expr)) {
			std::cout << "ERROR: self signed configuration not exist for application " << applicationName << std::endl;
			return 1;
		}

		// replace self signed certificate configuration flag
		std::string flag = what[1];
		boost::to_upper(flag);
		if (flag != "TRUE") {
			// nothing to do
			return 0;
		}
		std::string fmt = "<GenerateCertificate>false</GenerateCertificate>";
		applicationConfiguration = boost::regex_replace(applicationConfiguration, expr, fmt);

		// write configuration file of application
		if (!writeApplicationConfiguration(applicationInfo, applicationConfiguration)) {
			return 1;
		}

		return 0;
	}

	bool
	SelfSignedCertCtrlCommand::readApplicationConfiguration(
		const ApplicationInfo::SPtr& applicationInfo,
		std::string& applicationConfiguration
	)
	{
		// open file stream
		std::ifstream file(applicationInfo->serverConfigFile_, std::ifstream::binary);
		if (!file) {
			std::cout << "ERROR: cannot read configuration file " << applicationInfo->serverConfigFile_ << std::endl;
			return false;
		}

		// obtain size of file and create string buffer
		const auto fileSize = boost::filesystem::file_size(applicationInfo->serverConfigFile_);
		applicationConfiguration.resize(fileSize, '\0');

		// read configuration file into the buffer
		file.read(&applicationConfiguration[0], fileSize);

		return true;
	}

	bool
	SelfSignedCertCtrlCommand::writeApplicationConfiguration(
		const ApplicationInfo::SPtr& applicationInfo,
		std::string& applicationConfiguration
	)
	{
		// open file stream
		std::ofstream file(applicationInfo->serverConfigFile_, std::ofstream::binary | std::ofstream::trunc);
		if (!file) {
			std::cout << "ERROR: cannot write configuration file " << applicationInfo->serverConfigFile_ << std::endl;
			return false;
		}

		// write configuration into file
		file.write(&applicationConfiguration[0], applicationConfiguration.size());

		return true;
	}

}



