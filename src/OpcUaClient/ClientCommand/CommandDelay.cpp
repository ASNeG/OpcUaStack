
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

#include <boost/lexical_cast.hpp>
#include <sstream>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaClient/ClientCommand/CommandDelay.h"

using namespace OpcUaStackCore;

namespace OpcUaClient
{

	CommandDelay::CommandDelay(void)
	: CommandBase(CommandBase::Cmd_Delay)
	, timeout_(0)
	{
	}

	CommandDelay::~CommandDelay(void)
	{
	}

	CommandBase::SPtr
	CommandDelay::createCommand(void)
	{
		CommandBase::SPtr commandBase = constructSPtr<CommandDelay>();
		return commandBase;
	}

	bool
	CommandDelay::validateCommand(void)
	{
		if (timeout_ == 0) {
			std::stringstream ss;
			ss << "need timeout parameter";
			errorMessage(ss.str());
			return false;
		}
		return true;
	}

	bool
	CommandDelay::addParameter(const std::string& parameterName, const std::string& parameterValue)
	{
		if (parameterName == "-TIMEOUT") {
			try {
				timeout_ = boost::lexical_cast<uint32_t>(parameterValue);
			}
			catch (...)
			{
				std::stringstream ss;
				ss << "timeout parameter invalid (" << parameterValue << ")";
				errorMessage(ss.str());
				return false;
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
	CommandDelay::help(void)
	{
		std::stringstream ss;
		ss << "  -Delay: Stops the application for a defined period\n"
		   << "    -Timeout (1): Time in milli seconds\n";
		return ss.str();
	}

	uint32_t
	CommandDelay::timeout(void)
	{
		return timeout_;
	}

}
