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
#include <iostream>
#include "OpcUaCtrl/ApplCtrlCommand.h"

namespace OpcUaCtrl
{


	ApplCtrlCommand::ApplCtrlCommand(void)
	: CtrlCommand()
	{
	}

	ApplCtrlCommand::~ApplCtrlCommand(void)
	{
	}

	uint32_t
	ApplCtrlCommand::start(int argc, char** argv)
	{
		// check command parameter
		if (std::string(argv[2]) != "show") {
			usageCommand(std::string(argv[2]));
			return 1;
		}

		return show(argc, argv);
	}

	void
	ApplCtrlCommand::usage(void)
	{
		std::cout << "    show: show the names of all applications found" << std::endl;
	}

	void
	ApplCtrlCommand::usageCommand(const std::string& command)
	{
		std::cout << "usage: " << name_ << " appl <Command> [<Parameter>, ...]" << std::endl;
		std::cout << std::endl;
		std::cout << "ERROR: command " << command << " unknown" << std::endl;
		usage();
	}

	uint32_t
	ApplCtrlCommand::show(int argc, char** argv)
	{
		// We search for applications in all installation locations
		for ( auto installPath : installPathList_ ) {
			boost::filesystem::path applPath(installPath + std::string("/etc/OpcUaStack"));

			for ( auto applName : boost::filesystem::directory_iterator(applPath)) {
				// appl name must be a direcory
				if (!boost::filesystem::is_directory(applName.path())) {
					continue;
				}

				// ignore applications from black list
				if (applBlackList_.find(applName.path().filename().string()) != applBlackList_.end()) {
					continue;
				}

				// the configuration file OpcUaServer.xml must be exist
				boost::filesystem::path serverConfigFileName(
					installPath +
					std::string("/etc/OpcUaStack/") +
					applName.path().filename().string() +
					"/OpcUaServer.xml"
				);
				if (!boost::filesystem::exists(serverConfigFileName)) {
					continue;
				}

				// display application name
				std::cout << applName.path().filename().string() << std::endl;
			}
		}
		return 0;
	}

}



