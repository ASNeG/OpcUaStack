
/*
   Copyright 2017-2019 Kai Huebl (kai@huebl-sgh.de)

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

#include <boost/lexical_cast.hpp>
#include <sstream>
#include "OpcUaClient/ClientCommand/CommandFindServer.h"

using namespace OpcUaStackCore;

namespace OpcUaClient
{

	CommandFindServer::CommandFindServer(void)
	: CommandBase(CommandBase::Cmd_FindServer)
	{
	}

	CommandFindServer::~CommandFindServer(void)
	{
	}

	CommandBase::SPtr
	CommandFindServer::createCommand(void)
	{
		CommandBase::SPtr commandBase = boost::make_shared<CommandFindServer>();
		return commandBase;
	}

	bool
	CommandFindServer::validateCommand(void)
	{
		return true;
	}

	bool
	CommandFindServer::addParameter(const std::string& parameterName, const std::string& parameterValue)
	{
		return true;
	}

	std::string
	CommandFindServer::help(void)
	{
		std::stringstream ss;
		ss << "  -FindServer: Read server info from an opc ua discovery server\n";
		return ss.str();
	}

}
