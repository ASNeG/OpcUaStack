
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

#include "OpcUaClient/ClientCommand/CommandGetEndpoint.h"

using namespace OpcUaStackCore;

namespace OpcUaClient
{

	CommandGetEndpoint::CommandGetEndpoint(void)
	: CommandBase(CommandBase::Cmd_GetEndpoint)
	{
	}

	CommandGetEndpoint::~CommandGetEndpoint(void)
	{
	}

	CommandBase::SPtr
	CommandGetEndpoint::createCommand(void)
	{
		CommandBase::SPtr commandBase = boost::make_shared<CommandGetEndpoint>();
		return commandBase;
	}

	bool
	CommandGetEndpoint::validateCommand(void)
	{
		return true;
	}

	bool
	CommandGetEndpoint::addParameter(const std::string& parameterName, const std::string& parameterValue)
	{
		return true;
	}

	std::string
	CommandGetEndpoint::help(void)
	{
		std::stringstream ss;
		ss << "  -GetEndpoint: Read endpoints from an opc ua server\n";
		return ss.str();
	}

}
