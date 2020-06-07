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
#include "OpcUaCtrl/Application.h"

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
	ApplCtrlCommand::start(const std::vector<std::string>& commandLine)
	{
		// check command parameter
		if (commandLine[2] != "show") {
			usageCommand(commandLine[2]);
			return 1;
		}

		return show(commandLine);
	}

	void
	ApplCtrlCommand::usage(void)
	{
		std::cout << "    Commands:" << std::endl;
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
	ApplCtrlCommand::show(const std::vector<std::string>& commandLine)
	{
		Application application(applBlackList_, installPathList_);
		for ( auto& applicationInfoIt : application.map() ) {
			// display application name
			std::cout << applicationInfoIt.first << std::endl;
		}
		return 0;
	}

}



