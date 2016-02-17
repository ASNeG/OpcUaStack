
/*
   Copyright 2016 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaClient/Client/ClientApplication.h"
#include "OpcUaClient/ClientCommand/CommandParser.h"
#include "OpcUaClient/ClientService/CommandExecute.h"

// commands
#include "OpcUaClient/ClientCommand/CommandConnect.h"
#include "OpcUaClient/ClientCommand/CommandDisconnect.h"
#include "OpcUaClient/ClientCommand/CommandRead.h"
#include "OpcUaClient/ClientCommand/CommandDelay.h"

// services
#include "OpcUaClient/ClientService/ClientServiceConnect.h"

namespace OpcUaClient
{

	ClientApplication::ClientApplication(void)
	{
	}

	ClientApplication::~ClientApplication(void)
	{
	}

	int
	ClientApplication::run(uint32_t argc, char** argv)
	{
		// register command in command factory
		CommandParser::addCommand("CONNECT", constructSPtr<CommandConnect>());
		CommandParser::addCommand("DISCONNECT", constructSPtr<CommandDisconnect>());
		CommandParser::addCommand("READ", constructSPtr<CommandRead>());
		CommandParser::addCommand("DELAY", constructSPtr<CommandDelay>());

		// register service in service factory
		CommandExecute::addClientService(CommandBase::Cmd_Connect, constructSPtr<ClientServiceConnect>());

		// parse command line
		CommandParser commandParser;
		CommandBase::Vec commandBaseVec;
		if (!commandParser.parse(argc, argv, commandBaseVec)) {
			std::cerr << commandParser.errorString() << std::endl;
			return -1;
		}

		// execute command line
		CommandExecute commandExecute;
		if (commandExecute.run(commandBaseVec)) {
			std::cerr << commandExecute.errorString() << std::endl;
			return -1;
		}

		return 0;
	}

}
