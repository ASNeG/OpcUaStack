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
#include <fstream>
#include "OpcUaCtrl/CaCertCtrlCommand.h"

namespace OpcUaCtrl
{


	CaCertCtrlCommand::CaCertCtrlCommand(void)
	: CtrlCommand()
	{
	}

	CaCertCtrlCommand::~CaCertCtrlCommand(void)
	{
	}

	uint32_t
	CaCertCtrlCommand::start(const std::vector<std::string>& commandLine)
	{
		// check command parameter
		if (commandLine[2] == "show") {
			return show(commandLine);
		}
		else if (commandLine[2] == "add") {
			return add(commandLine);
		}
		else if (commandLine[2] == "del") {
			return del(commandLine);
		}
		else {
			usageMessage(std::string("command ") + commandLine[2] + " unknown");
			return 1;
		}
	}

	void
	CaCertCtrlCommand::usage(void)
	{
		std::cout << "    Commands:" << std::endl;
		std::cout << "    show <Application-Name>:" << std::endl;
		std::cout << "        shows all ca certificates" << std::endl;
		std::cout << "    add <Application-Name> <Ca-Cert-File>:" << std::endl;
		std::cout << "        add a new ca certificate" << std::endl;
		std::cout << "    del <Application-Name> <xx>:" << std::endl;
		std::cout << "        delete a ca certificate" << std::endl;
	}

	void
	CaCertCtrlCommand::usageMessage(const std::string& message)
	{
		std::cout << "usage: " << name_ << " self_signed_cert <Command> [<Parameter>, ...]" << std::endl;
		std::cout << std::endl;
		std::cout << "ERROR: " << message << std::endl;
		usage();
	}

	uint32_t
	CaCertCtrlCommand::show(const std::vector<std::string>& commandLine)
	{
		// Should be provided information about all existing applications
		if (commandLine.size() == 3) {
			Application application(applBlackList_, installPathList_);

			for (auto applicationInfo : application) {
				std::vector<std::string> tmpCommandLine(commandLine);
				tmpCommandLine.push_back(applicationInfo.second->applName_);
				auto result = show(tmpCommandLine);
				if (result != 0) return result;
			}

			return 0;
		}

		// check command line parameter
		if (commandLine.size() < 4) {
			usageMessage("parameter invalid");
			return 1;
		}
		std::string applicationName = commandLine[3];

		// get application info
		Application application(applBlackList_, installPathList_);
		auto it = application.find(applicationName);
		if (it == application.end()) {
			std::cout << "ERROR: application " << applicationName << " not exist" << std::endl;
			return 1;
		}
		auto applicationInfo = it->second;

		return 0;
	}

	uint32_t
	CaCertCtrlCommand::add(const std::vector<std::string>& commandLine)
	{
		return 0;
	}

	uint32_t
	CaCertCtrlCommand::del(const std::vector<std::string>& commandLine)
	{
		return 0;
	}

}



