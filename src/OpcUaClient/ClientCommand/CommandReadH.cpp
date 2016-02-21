
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
#include "OpcUaClient/ClientCommand/CommandReadH.h"

using namespace OpcUaStackCore;

namespace OpcUaClient
{

	CommandReadH::CommandReadH(void)
	: CommandBase(CommandBase::Cmd_ReadH)
	, nodeIdVec_()
	, attributeIdVec_()
	{
	}

	CommandReadH::~CommandReadH(void)
	{
	}

	CommandBase::SPtr
	CommandReadH::createCommand(void)
	{
		CommandBase::SPtr commandBase = constructSPtr<CommandReadH>();
		return commandBase;
	}

	bool
	CommandReadH::validateCommand(void)
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
	CommandReadH::addParameter(const std::string& parameterName, const std::string& parameterValue)
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
			attributeIdVec_.push_back(13);
		}
		else if (parameterName == "-ATTRIBUTEID") {
			uint32_t attributeId;
			try {
				attributeId = boost::lexical_cast<uint32_t>(parameterValue);
			}
			catch (...)
			{
				std::stringstream ss;
				ss << "AttributeID parameter invalid (" << parameterValue << ")";
				errorMessage(ss.str());
				return false;
		    }

			if (attributeIdVec_.size() == 0) {
				std::stringstream ss;
				ss << "cannot add AttributeId, because NodeId not exist";
				errorMessage(ss.str());
				return false;
			}

			attributeIdVec_[attributeIdVec_.size()-1] = attributeId;
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
	CommandReadH::help(void)
	{
		std::stringstream ss;
		ss << "  -ReadH: Read one ore more historical data values from a opc ua server\n"
		   << "    -Session (0..1): Name of the session.\n"
		   << "    -NodeId (1..N): NodeId of the value to read from opc ua server\n"
		   << "      -StartTime (1) start time of data\n"
		   << "      -StopTime (1) stop time of data\n"
		   << "      -AttributeId (0..1): Attribute Identifier to read. (Default: 13)\n";
		return ss.str();
	}

	OpcUaNodeId::Vec&
	CommandReadH::nodeIdVec(void)
	{
		return nodeIdVec_;
	}

	std::vector<uint32_t>&
	CommandReadH::attributeIdVec(void)
	{
		return attributeIdVec_;
	}

}
