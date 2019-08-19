
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

#include "OpcUaClient/ClientCommand/CommandBrowsePathToNodeId.h"

using namespace OpcUaStackCore;

namespace OpcUaClient
{

	CommandBrowsePathToNodeId::CommandBrowsePathToNodeId(void)
	: CommandBase(CommandBase::Cmd_BrowsePathToNodeId)
	, nodeId_()
	, browseNameVec_()
	{
	}

	CommandBrowsePathToNodeId::~CommandBrowsePathToNodeId(void)
	{
	}

	CommandBase::SPtr
	CommandBrowsePathToNodeId::createCommand(void)
	{
		CommandBase::SPtr commandBase = boost::make_shared<CommandBrowsePathToNodeId>();
		return commandBase;
	}

	bool
	CommandBrowsePathToNodeId::validateCommand(void)
	{
		if (browseNameVec_.size() == 0) {
			std::stringstream ss;
			ss << "need at least one browse name parameter";
			errorMessage(ss.str());
			return false;
		}

		if (nodeId_.get() == nullptr) {
			std::stringstream ss;
			ss << "need node id parameter";
			errorMessage(ss.str());
			return false;
		}
		return true;
	}

	bool
	CommandBrowsePathToNodeId::addParameter(const std::string& parameterName, const std::string& parameterValue)
	{
		if (parameterName == "-NODEID") {
			OpcUaNodeId::SPtr nodeId = boost::make_shared<OpcUaNodeId>();
			if (!nodeId->fromString(parameterValue)) {
				std::stringstream ss;
				ss << "node id parameter invalid (" << parameterValue << ")";
				errorMessage(ss.str());
				return false;
			}
			nodeId_ = nodeId;
		}
		else if (parameterName == "-BROWSENAME") {
			OpcUaQualifiedName browseName;

			if (!browseName.fromString(parameterValue)) {
				std::stringstream ss;
				ss << "BROWSENAME parameter invalid (" << parameterValue << ")";
				errorMessage(ss.str());
				return false;
			}
			browseNameVec_.push_back(browseName);
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
	CommandBrowsePathToNodeId::help(void)
	{
		std::stringstream ss;
		ss << "  -BrowsePathToNodeId: Determined from the browsename the associated node id\n"
		   << "    -Session (0..1): Name of the session.\n"
		   << "    -NodeId (1..N): Starting node id\n"
		   << "    -BrowseName (1..N): BrowseName\n";
		return ss.str();
	}

	OpcUaNodeId::SPtr&
	CommandBrowsePathToNodeId::nodeId(void)
	{
		return nodeId_;
	}

	std::vector<OpcUaQualifiedName>&
	CommandBrowsePathToNodeId::browseNameVec(void)
	{
		return browseNameVec_;
	}

}
