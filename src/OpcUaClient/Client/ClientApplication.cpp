
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
#include "OpcUaClient/ClientService/ClientServiceExecute.h"

// commands
#include "OpcUaClient/ClientCommand/CommandConnect.h"
#include "OpcUaClient/ClientCommand/CommandDisconnect.h"
#include "OpcUaClient/ClientCommand/CommandRead.h"
#include "OpcUaClient/ClientCommand/CommandReadH.h"
#include "OpcUaClient/ClientCommand/CommandWrite.h"
#include "OpcUaClient/ClientCommand/CommandDelay.h"
#include "OpcUaClient/ClientCommand/CommandNodeSetServer.h"
#include "OpcUaClient/ClientCommand/CommandNodeSetFilter.h"
#include "OpcUaClient/ClientCommand/CommandBrowse.h"
#include "OpcUaClient/ClientCommand/CommandFunction.h"
#include "OpcUaClient/ClientCommand/CommandBrowsePathToNodeId.h"

// services
#include "OpcUaClient/ClientService/ClientServiceConnect.h"
#include "OpcUaClient/ClientService/ClientServiceDisconnect.h"
#include "OpcUaClient/ClientService/ClientServiceRead.h"
#include "OpcUaClient/ClientService/ClientServiceReadH.h"
#include "OpcUaClient/ClientService/ClientServiceWrite.h"
#include "OpcUaClient/ClientService/ClientServiceDelay.h"
#include "OpcUaClient/ClientService/ClientServiceNodeSetServer.h"
#include "OpcUaClient/ClientService/ClientServiceNodeSetFilter.h"
#include "OpcUaClient/ClientService/ClientServiceBrowse.h"
#include "OpcUaClient/ClientService/ClientServiceFunction.h"
#include "OpcUaClient/ClientService/ClientServiceBrowsePathToNodeId.h"

namespace OpcUaClient
{

	ClientApplication::ClientApplication(void)
	: core_()
	{
		core_.init();
	}

	ClientApplication::~ClientApplication(void)
	{
		core_.cleanup();
	}

	int
	ClientApplication::run(uint32_t argc, char** argv)
	{
		// register command in command factory
		CommandParser::addCommand("CONNECT", constructSPtr<CommandConnect>());
		CommandParser::addCommand("DISCONNECT", constructSPtr<CommandDisconnect>());
		CommandParser::addCommand("READ", constructSPtr<CommandRead>());
		CommandParser::addCommand("WRITE", constructSPtr<CommandWrite>());
		CommandParser::addCommand("READH", constructSPtr<CommandReadH>());
		CommandParser::addCommand("DELAY", constructSPtr<CommandDelay>());
		CommandParser::addCommand("NODESETSERVER", constructSPtr<CommandNodeSetServer>());
		CommandParser::addCommand("NODESETFILTER", constructSPtr<CommandNodeSetFilter>());
		CommandParser::addCommand("BROWSE", constructSPtr<CommandBrowse>());
		CommandParser::addCommand("FUNCTION", constructSPtr<CommandFunction>());
		CommandParser::addCommand("BROWSEPATHTONODEID", constructSPtr<CommandBrowsePathToNodeId>());

		// register service in service factory
		ClientServiceExecute::addClientService(CommandBase::Cmd_Connect, constructSPtr<ClientServiceConnect>());
		ClientServiceExecute::addClientService(CommandBase::Cmd_Disconnect, constructSPtr<ClientServiceDisconnect>());
		ClientServiceExecute::addClientService(CommandBase::Cmd_Read, constructSPtr<ClientServiceRead>());
		ClientServiceExecute::addClientService(CommandBase::Cmd_ReadH, constructSPtr<ClientServiceReadH>());
		ClientServiceExecute::addClientService(CommandBase::Cmd_Write, constructSPtr<ClientServiceWrite>());
		ClientServiceExecute::addClientService(CommandBase::Cmd_Delay, constructSPtr<ClientServiceDelay>());
		ClientServiceExecute::addClientService(CommandBase::Cmd_NodeSetServer, constructSPtr<ClientServiceNodeSetServer>());
		ClientServiceExecute::addClientService(CommandBase::Cmd_NodeSetFilter, constructSPtr<ClientServiceNodeSetFilter>());
		ClientServiceExecute::addClientService(CommandBase::Cmd_Browse, constructSPtr<ClientServiceBrowse>());
		ClientServiceExecute::addClientService(CommandBase::Cmd_Function, constructSPtr<ClientServiceFunction>());
		ClientServiceExecute::addClientService(CommandBase::Cmd_BrowsePathToNodeId, constructSPtr<ClientServiceBrowsePathToNodeId>());

		// parse command line
		CommandParser commandParser;
		CommandBase::Vec commandBaseVec;
		if (!commandParser.parse(argc, argv, commandBaseVec)) {
			std::cerr << commandParser.errorString() << std::endl;
			return -1;
		}

		// execute commands from command line line
		ClientServiceExecute clientServiceExecute;
		if (!clientServiceExecute.run(commandBaseVec)) {
			std::cerr << clientServiceExecute.errorString() << std::endl;
			return -1;
		}

		std::cout << "OK" << std::endl;
		return 0;
	}

}
