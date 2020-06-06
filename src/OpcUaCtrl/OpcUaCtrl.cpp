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

#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>
#include <iostream>
#include "OpcUaStackCore/Utility/Environment.h"
#include "OpcUaCtrl/OpcUaCtrl.h"

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
	OpcUaCtrl::start(int argc, char** argv)
	{
		// init
		boost::filesystem::path p = argv[0];
		std::string name_ = p.stem().string();
		initInstallPathList();

		// check command line
		if (argc < 3) {
			usage();
			return 1;
		}

		return 0;
	}

	void
	OpcUaCtrl::usage(void)
	{
		std::cout << "usage: " << name_ << " <Type> <Command> [<Parameter>, ...]" << std::endl;
		std::cout << std::endl;
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
			installPathList_.push_back(installPath);
		}
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
	OpcUaCtrl::OpcUaCtrl opcuaCtrl;
	return opcuaCtrl.start(argc, argv);
}



