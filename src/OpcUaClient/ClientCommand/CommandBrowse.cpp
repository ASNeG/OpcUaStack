
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
#include "OpcUaClient/ClientCommand/CommandBrowse.h"

using namespace OpcUaStackCore;

namespace OpcUaClient
{

	CommandBrowse::CommandBrowse(void)
	: CommandBase(CommandBase::Cmd_Browse)
	, nodeIdVec_()
	, direction_(BrowseDirection_Both)
	, recursive_(false)
	{
	}

	CommandBrowse::~CommandBrowse(void)
	{
	}

	CommandBase::SPtr
	CommandBrowse::createCommand(void)
	{
		CommandBase::SPtr commandBase = boost::make_shared<CommandBrowse>();
		return commandBase;
	}

	bool
	CommandBrowse::validateCommand(void)
	{
		if (nodeIdVec_.size() == 0) {
			OpcUaNodeId::SPtr nodeId = boost::make_shared<OpcUaNodeId>();
			nodeId->set((OpcUaUInt32)84, (OpcUaUInt16)0);
			nodeIdVec_.push_back(nodeId);
		}
		return true;
	}

	bool
	CommandBrowse::addParameter(const std::string& parameterName, const std::string& parameterValue)
	{
		if (parameterName == "-NODEID") {
			OpcUaNodeId::SPtr nodeId = boost::make_shared<OpcUaNodeId>();
			if (!nodeId->fromString(parameterValue)) {
				std::stringstream ss;
				ss << "node id parameter invalid (" << parameterValue << ")";
				errorMessage(ss.str());
				return false;
			}
			nodeIdVec_.push_back(nodeId);
		}
		else if (parameterName == "-DIRECTION") {
			std::string value = parameterValue;
			boost::to_upper(value);
			if (value == "FORWARD") {
				direction_ = BrowseDirection_Forward;
			}
			else if (value == "INVERSE") {
				direction_ = BrowseDirection_Inverse;
			}
			else if (value == "BOTH") {
				direction_ = BrowseDirection_Both;
			}
			else {
				std::stringstream ss;
				ss << "node id parameter invalid (" << parameterValue << ")";
				errorMessage(ss.str());
				return false;
			}
		}
		else if (parameterName == "-RECURSIVE") {
			std::string value = parameterValue;
			boost::to_upper(value);
			if (value == "ON") {
				recursive_ = true;
			}
			else if (value == "OFF") {
				recursive_ = false;
			}
			else {
				std::stringstream ss;
				ss << "node id parameter invalid (" << parameterValue << ")";
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
	CommandBrowse::help(void)
	{
		std::stringstream ss;
		ss << "  -Browse: Browse nodes from a opc ua server\n"
		   << "    -Session (0..1): Name of the session.\n"
		   << "    -NodeId (0..N): Start node id\n"
		   << "    -Direction (0..1): Direction type filter of reference. (Default Both)\n"
		   << "       Forward - Get only forward references\n"
		   << "       Inverse - Get only inverse references\n"
		   << "       Both    - Get forward and inverse references\n"
		   << "    - Recursive (0..1): Browse recursive\n"
		   << "       On  - browse recursive is on\n"
		   << "       Off - browse recursive is off\n";
		return ss.str();
	}

	OpcUaNodeId::Vec&
	CommandBrowse::nodeIdVec(void)
	{
		return nodeIdVec_;
	}

	BrowseDirectionEnum
	CommandBrowse::direction(void)
	{
		return direction_;
	}

	bool
	CommandBrowse::recursive(void)
	{
		return recursive_;
	}

}
