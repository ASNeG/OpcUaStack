
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

#include <sstream>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaClient/ClientCommand/CommandRead.h"

using namespace OpcUaStackCore;

namespace OpcUaClient
{

	CommandRead::CommandRead(void)
	: CommandBase(CommandBase::Cmd_Read)
	, nodeIdVec_()
	{
	}

	CommandRead::~CommandRead(void)
	{
	}

	CommandBase::SPtr
	CommandRead::createCommand(void)
	{
		CommandBase::SPtr commandBase = constructSPtr<CommandRead>();
		return commandBase;
	}

	bool
	CommandRead::validateCommand(void)
	{
		if (nodeIdVec_.size() == 0) {
			std::stringstream ss;
			ss << "neeed at least one node id parameter";
			errorMessage(ss.str());
			return false;
		}
		return true;
	}

	bool
	CommandRead::addParameter(const std::string& parameterName, const std::string& parameterValue)
	{
		if (parameterName == "-NODEID") {
			OpcUaNodeId::SPtr nodeId = constructSPtr<OpcUaNodeId>();
			if (!nodeId->fromString(parameterValue)) {
				std::stringstream ss;
				ss << "node id parameter invalid (" << parameterValue << ")";
				errorMessage(ss.str());
				return false;
			}
			nodeIdVec_.push_back(nodeId);
		}
		else {
			std::stringstream ss;
			ss << "invalid parameter " << parameterName;
			errorMessage(ss.str());
			return false;
		}
		return true;
	}

	OpcUaNodeId::Vec&
	CommandRead::nodeIdVec(void)
	{
		return nodeIdVec_;
	}

}
