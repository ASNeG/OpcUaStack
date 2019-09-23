
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
#include <boost/lexical_cast.hpp>
#include <sstream>

#include "OpcUaClient/ClientCommand/CommandSubscriptionStart.h"

namespace OpcUaClient
{

	CommandSubscriptionStart::CommandSubscriptionStart(void)
	: CommandBase(CommandBase::Cmd_SubscriptionStart)
	{
	}

	CommandSubscriptionStart::~CommandSubscriptionStart(void)
	{
	}

	CommandBase::SPtr
	CommandSubscriptionStart::createCommand(void)
	{
		CommandBase::SPtr commandBase = boost::make_shared<CommandSubscriptionStart>();
		return commandBase;
	}

	bool
	CommandSubscriptionStart::validateCommand(void)
	{
		return true;
	}

	bool
	CommandSubscriptionStart::addParameter(const std::string& parameterName, const std::string& parameterValue)
	{
		if (parameterName == "-SubscriptionId") {
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
	CommandSubscriptionStart::help(void)
	{
		std::stringstream ss;
		ss << "  -SubscriptionStart: Starts a subscription\n"
		   << "    -SubscriptionId (1): Identifier of the subscription\n";
		return ss.str();
	}

}
