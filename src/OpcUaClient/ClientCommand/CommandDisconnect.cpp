/*
   Copyright 2016-2019 Kai Huebl (kai@huebl-sgh.de)

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

#include <boost/make_shared.hpp>
#include <sstream>

#include "OpcUaClient/ClientCommand/CommandDisconnect.h"

namespace OpcUaClient
{

	CommandDisconnect::CommandDisconnect(void)
	: CommandBase(CommandBase::Cmd_Disconnect)
	{
	}

	CommandDisconnect::~CommandDisconnect(void)
	{
	}

	CommandBase::SPtr
	CommandDisconnect::createCommand(void)
	{
		CommandBase::SPtr commandBase = boost::make_shared<CommandDisconnect>();
		return commandBase;
	}

	bool
	CommandDisconnect::validateCommand(void)
	{
		return true;
	}

	bool
	CommandDisconnect::addParameter(const std::string& parameterName, const std::string& parameterValue)
	{
		std::stringstream ss;
		ss << "invalid parameter " << parameterName;
		errorMessage(ss.str());
		return false;
	}

	std::string
	CommandDisconnect::help(void)
	{
		std::stringstream ss;
		ss << "  -Disconnect: Close a existing connection to a opc ua server\n"
		   << "    -Session (0..1): Name of the session.\n";
		return ss.str();
	}

}
