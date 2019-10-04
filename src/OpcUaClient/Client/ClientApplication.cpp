
/*
   Copyright 2016-2017 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/Logging/Logging.h"
#include "OpcUaClient/Client/ClientApplication.h"
#include "OpcUaClient/ClientCommand/CommandParser.h"
#include "OpcUaClient/ClientService/ClientServiceExecute.h"

// commands
#include "OpcUaClient/ClientCommand/CommandConnect.h"
#include "OpcUaClient/ClientCommand/CommandDisconnect.h"
#include "OpcUaClient/ClientCommand/CommandRead.h"
#include "OpcUaClient/ClientCommand/CommandReadH.h"
#include "OpcUaClient/ClientCommand/CommandWrite.h"
#include "OpcUaClient/ClientCommand/CommandWriteH.h"
#include "OpcUaClient/ClientCommand/CommandDelay.h"
#include "OpcUaClient/ClientCommand/CommandNodeSetServer.h"
#include "OpcUaClient/ClientCommand/CommandNodeSetFilter.h"
#include "OpcUaClient/ClientCommand/CommandBrowse.h"
#include "OpcUaClient/ClientCommand/CommandFunction.h"
#include "OpcUaClient/ClientCommand/CommandBrowsePathToNodeId.h"
#include "OpcUaClient/ClientCommand/CommandGetEndpoint.h"
#include "OpcUaClient/ClientCommand/CommandFindServer.h"
#include "OpcUaClient/ClientCommand/CommandRegisterServer.h"

// services
#include "OpcUaClient/ClientService/ClientServiceConnect.h"
#include "OpcUaClient/ClientService/ClientServiceDisconnect.h"
#include "OpcUaClient/ClientService/ClientServiceRead.h"
#include "OpcUaClient/ClientService/ClientServiceReadH.h"
#include "OpcUaClient/ClientService/ClientServiceWrite.h"
#include "OpcUaClient/ClientService/ClientServiceWriteH.h"
#include "OpcUaClient/ClientService/ClientServiceDelay.h"
#include "OpcUaClient/ClientService/ClientServiceNodeSetServer.h"
#include "OpcUaClient/ClientService/ClientServiceNodeSetFilter.h"
#include "OpcUaClient/ClientService/ClientServiceBrowse.h"
#include "OpcUaClient/ClientService/ClientServiceFunction.h"
#include "OpcUaClient/ClientService/ClientServiceBrowsePathToNodeId.h"
#include "OpcUaClient/ClientService/ClientServiceGetEndpoint.h"
#include "OpcUaClient/ClientService/ClientServiceFindServer.h"
#include "OpcUaClient/ClientService/ClientServiceRegisterServer.h"

using namespace OpcUaStackCore;

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
		CommandParser::addCommand("CONNECT", boost::make_shared<CommandConnect>());
		CommandParser::addCommand("DISCONNECT", boost::make_shared<CommandDisconnect>());
		CommandParser::addCommand("READ", boost::make_shared<CommandRead>());
		CommandParser::addCommand("WRITE", boost::make_shared<CommandWrite>());
		CommandParser::addCommand("READH", boost::make_shared<CommandReadH>());
		CommandParser::addCommand("WRITEH", boost::make_shared<CommandWriteH>());
		CommandParser::addCommand("DELAY", boost::make_shared<CommandDelay>());
		CommandParser::addCommand("NODESETSERVER", boost::make_shared<CommandNodeSetServer>());
		CommandParser::addCommand("NODESETFILTER", boost::make_shared<CommandNodeSetFilter>());
		CommandParser::addCommand("BROWSE", boost::make_shared<CommandBrowse>());
		CommandParser::addCommand("FUNCTION", boost::make_shared<CommandFunction>());
		CommandParser::addCommand("BROWSEPATHTONODEID", boost::make_shared<CommandBrowsePathToNodeId>());
		CommandParser::addCommand("GETENDPOINT", boost::make_shared<CommandGetEndpoint>());
		CommandParser::addCommand("FINDSERVER", boost::make_shared<CommandFindServer>());
		CommandParser::addCommand("REGISTERSERVER", boost::make_shared<CommandRegisterServer>());


		// register service in service factory
		ClientServiceExecute::addClientService(CommandBase::Cmd_Connect, boost::make_shared<ClientServiceConnect>());
		ClientServiceExecute::addClientService(CommandBase::Cmd_Disconnect, boost::make_shared<ClientServiceDisconnect>());
		ClientServiceExecute::addClientService(CommandBase::Cmd_Read, boost::make_shared<ClientServiceRead>());
		ClientServiceExecute::addClientService(CommandBase::Cmd_ReadH, boost::make_shared<ClientServiceReadH>());
		ClientServiceExecute::addClientService(CommandBase::Cmd_Write, boost::make_shared<ClientServiceWrite>());
		ClientServiceExecute::addClientService(CommandBase::Cmd_WriteH, boost::make_shared<ClientServiceWriteH>());
		ClientServiceExecute::addClientService(CommandBase::Cmd_Delay, boost::make_shared<ClientServiceDelay>());
		ClientServiceExecute::addClientService(CommandBase::Cmd_NodeSetServer, boost::make_shared<ClientServiceNodeSetServer>());
		ClientServiceExecute::addClientService(CommandBase::Cmd_NodeSetFilter, boost::make_shared<ClientServiceNodeSetFilter>());
		ClientServiceExecute::addClientService(CommandBase::Cmd_Browse, boost::make_shared<ClientServiceBrowse>());
		ClientServiceExecute::addClientService(CommandBase::Cmd_Function, boost::make_shared<ClientServiceFunction>());
		ClientServiceExecute::addClientService(CommandBase::Cmd_BrowsePathToNodeId, boost::make_shared<ClientServiceBrowsePathToNodeId>());
		ClientServiceExecute::addClientService(CommandBase::Cmd_GetEndpoint, boost::make_shared<ClientServiceGetEndpoint>());
		ClientServiceExecute::addClientService(CommandBase::Cmd_FindServer, boost::make_shared<ClientServiceFindServer>());
		ClientServiceExecute::addClientService(CommandBase::Cmd_RegisterServer, boost::make_shared<ClientServiceRegisterServer>());

		// parse command line
		CommandParser commandParser;
		CommandBase::Vec commandBaseVec;
		if (!commandParser.parse(argc, argv, commandBaseVec)) {
			std::cerr << commandParser.errorString() << std::endl;
			return -1;
		}

		// init logging
		Logging::defaultLogFile("OpcUaClient.log");
		auto *logIf = Logging::startupLogging(commandParser.config(), "OpcUaClient.Logging");
		OpcUaStackCore::Log::logIf(logIf);

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
