
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

#include <boost/make_shared.hpp>
#include <sstream>

#include "OpcUaClient/ClientCommand/CommandConnect.h"

namespace OpcUaClient
{

	CommandConnect::CommandConnect(void)
	: CommandBase(CommandBase::Cmd_Connect)
	, endpointUrl_("opc.tcp://127.0.0.1:4841")
	, activateSession_(true)
	{
	}

	CommandConnect::~CommandConnect(void)
	{
	}

	CommandBase::SPtr
	CommandConnect::createCommand(void)
	{
		CommandBase::SPtr commandBase = boost::make_shared<CommandConnect>();
		return commandBase;
	}

	bool
	CommandConnect::validateCommand(void)
	{
		return true;
	}

	bool
	CommandConnect::addParameter(const std::string& parameterName, const std::string& parameterValue)
	{
		if (parameterName == "-ENDPOINTURL") {
			endpointUrl_ = parameterValue;
		}
		else if (parameterName == "-ACTIVATESESSION") {
			if (parameterValue == "0") {
				activateSession_ = false;
			}
		}
		else {
			std::stringstream ss;
			ss << "invalid parameter " << parameterName;
			errorMessage(ss.str());
			return false;
		}
		return true;
	}

	std::string
	CommandConnect::help(void)
	{
		std::stringstream ss;
		ss << "  -Connect: Open a new connection to a opc ua server\n"
		   << "    -Session (0..1): Name of the session. (Default: Main)\n"
		   << "    -EndpointUrl (0..1): Endpoint Url of the server. (Default: opt.tcp://127.0.0.1:4841)\n"
		   << "    -ActivateSession (0..1): Activate session or not. (Default: 1)\n";
		return ss.str();
	}

	std::string&
	CommandConnect::endpointUrl(void)
	{
		return endpointUrl_;
	}

	bool
	CommandConnect::activateSession(void)
	{
		return activateSession_;
	}

}
