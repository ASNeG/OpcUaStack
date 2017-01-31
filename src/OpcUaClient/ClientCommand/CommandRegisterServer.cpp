
/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaClient/ClientCommand/CommandRegisterServer.h"

using namespace OpcUaStackCore;

namespace OpcUaClient
{

	CommandRegisterServer::CommandRegisterServer(void)
	: CommandBase(CommandBase::Cmd_RegisterServer)
	{
	}

	CommandRegisterServer::~CommandRegisterServer(void)
	{
	}

	CommandBase::SPtr
	CommandRegisterServer::createCommand(void)
	{
		CommandBase::SPtr commandBase = constructSPtr<CommandRegisterServer>();
		return commandBase;
	}

	bool
	CommandRegisterServer::validateCommand(void)
	{
		return true;
	}

	bool
	CommandRegisterServer::addParameter(const std::string& parameterName, const std::string& parameterValue)
	{
		return true;
	}

	std::string
	CommandRegisterServer::help(void)
	{
		std::stringstream ss;
		ss << "  -RegisterServer: register application description on opc ua discovery server\n";
		return ss.str();
	}

}
