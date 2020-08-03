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

#include <boost/make_shared.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>
#include <iostream>
#include "OpcUaStackCore/Utility/Environment.h"
#include "OpcUaCtrl/OpcUaCtrl.h"
#include "OpcUaCtrl/ApplCtrlCommand.h"
#include "OpcUaCtrl/SelfSignedCertCtrlCommand.h"
#include "OpcUaCtrl/CaCertCtrlCommand.h"
#include "OpcUaCtrl/IssuerCertCtrlCommand.h"
#include "OpcUaCtrl/ApplCertCtrlCommand.h"
#include "OpcUaCtrl/CertCtrlCommand.h"


using namespace OpcUaStackCore;

namespace OpcUaCtrl
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaCtrl
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaCtrl::OpcUaCtrl(void)
	{
	}

	OpcUaCtrl::~OpcUaCtrl(void)
	{
	}

	uint32_t
	OpcUaCtrl::start(const std::vector<std::string>& commandLine)
	{
		// init application black list
		applBlackList_.insert("ssl");

		// init
		boost::filesystem::path p = commandLine[0];
		name_ = p.stem().string();
		initInstallPathList();

		// add commands
		addCtrlCommand("appl", boost::make_shared<ApplCtrlCommand>());
		addCtrlCommand("self_signed_cert", boost::make_shared<SelfSignedCertCtrlCommand>());
		addCtrlCommand("ca_cert", boost::make_shared<CaCertCtrlCommand>());
		addCtrlCommand("im_cert", boost::make_shared<IssuerCertCtrlCommand>());
		addCtrlCommand("appl_cert", boost::make_shared<ApplCertCtrlCommand>());
		addCtrlCommand("cert", boost::make_shared<CertCtrlCommand>());


		// check number of parameter command line
		if (commandLine.size() < 3) {
			usage();
			return 1;
		}

		// check type parameter of command line
		auto ctrlCommandIt = ctrlCommandMap_.find(commandLine[1]);
		if (ctrlCommandIt == ctrlCommandMap_.end()) {
			usageType(std::string(commandLine[1]));
			return 1;
		}
		auto ctrlCommand = ctrlCommandIt->second;

		// call command
		ctrlCommand->applBlackList_ = applBlackList_;
		ctrlCommand->name_ = name_;
		ctrlCommand->installPathList_ = installPathList_;
		ctrlCommand->start(commandLine);
		return 0;
	}

	void
	OpcUaCtrl::usage(void)
	{
		std::cout << "usage: " << name_ << " <Type> <Command> [<Parameter>, ...]" << std::endl;

		for ( auto ctrlCommand : ctrlCommandMap_ ) {
			std::cout << std::endl;
			std::cout << "Type: "   << ctrlCommand.first << std::endl;
			ctrlCommand.second->usage();
		}
	}

	void
	OpcUaCtrl::usageType(const std::string& type)
	{
		std::cout << "usage: " << name_ << " <Type> <Command> [<Parameter>, ...]" << std::endl;
		std::cout << std::endl;
		std::cout << "ERROR: type " << type << " unknown" << std::endl;
		std::cout << "    KnownTypes:" << std::endl;

		for ( auto ctrlCommandIt : ctrlCommandMap_ ) {
			std::cout << "        " << ctrlCommandIt.first << std::endl;
		}
	}

	void
	OpcUaCtrl::initInstallPathList(void)
	{
		std::set<std::string> installPathSet;

		// get installation path of OpcUaCtrl tool
		auto binInstallPath = Environment::getApplicationPathAbsolute();
		auto pos = binInstallPath.find("usr/bin/OpcUaCtrl");
		if (pos) {
			binInstallPath = binInstallPath.substr(0, pos);
			installPathSet.insert(binInstallPath);
		}

		// get installation paths string from environment variable
		std::vector<std::string> opcUaInstallPathVec;
		auto env = getenv("OPC_UA_INSTALL_PATH");
		if (env) {
			std::string opcUaInstallPathString(env);
			boost::split(opcUaInstallPathVec, opcUaInstallPathString, boost::is_any_of(":;"));
			for ( auto opcUaInstallPath : opcUaInstallPathVec ) {
				installPathSet.insert(opcUaInstallPath);
			}
		}

		// add installation paths to installation path list
		for ( auto installPath : installPathSet ) {
			// check if path exist
			boost::filesystem::path tmpInstallPath(installPath);
			if (!boost::filesystem::is_directory(tmpInstallPath)) {
				continue;
			}

			// add installtion path to installation list
			installPathList_.push_back(installPath);
		}
	}

	void
	OpcUaCtrl::addCtrlCommand(const std::string& name, const CtrlCommand::SPtr& ctrlCommand)
	{
		ctrlCommandMap_.insert(std::make_pair(name, ctrlCommand));
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
	std::vector<std::string> commandLine;
	for (uint32_t idx = 0; idx < argc; idx++) {
		commandLine.push_back(argv[idx]);
	}

	OpcUaCtrl::OpcUaCtrl opcuaCtrl;
	return opcuaCtrl.start(commandLine);
}



