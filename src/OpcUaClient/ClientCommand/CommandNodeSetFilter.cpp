
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

#include "OpcUaClient/ClientCommand/CommandNodeSetFilter.h"

using namespace OpcUaStackCore;

namespace OpcUaClient
{

	CommandNodeSetFilter::CommandNodeSetFilter(void)
	: CommandBase(CommandBase::Cmd_NodeSetFilter)
	, namespaceUriVec_()
	, srcNodeSetName_("")
	, dstNodeSetName_("NodeSet.xml")
	{
	}

	CommandNodeSetFilter::~CommandNodeSetFilter(void)
	{
	}

	CommandBase::SPtr
	CommandNodeSetFilter::createCommand(void)
	{
		CommandBase::SPtr commandBase = boost::make_shared<CommandNodeSetFilter>();
		return commandBase;
	}

	bool
	CommandNodeSetFilter::validateCommand(void)
	{
		if (srcNodeSetName_.empty()) {
			std::stringstream ss;
			ss << "need source node set name parameter";
			errorMessage(ss.str());
			return false;
		}

		return true;
	}

	bool
	CommandNodeSetFilter::addParameter(const std::string& parameterName, const std::string& parameterValue)
	{
		if (parameterName == "-NAMESPACEURI") {
			namespaceUriVec_.push_back(parameterValue);
		}
		else if (parameterName == "-SRCNODESETNAME") {
			srcNodeSetName_ = parameterValue;
		}
		else if (parameterName == "-DSTNODESETNAME") {
			dstNodeSetName_ = parameterValue;
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
	CommandNodeSetFilter::help(void)
	{
		std::stringstream ss;
		ss << "  -NodeSetFilter: Reads nodes from a node set file and writes a subset of\n"
		   << "                  namespaces to a destionation node set file\n"
		   << "    -Session (0..1): Name of the session.\n"
		   << "    -NamespaceUri (0..N): Namespaces to write into node set file.\n"
		   << "    -SrcNodeSetName (1): Name of source node set file\n"
		   << "    -DstNodeSetName (0..1): Name of destionation node set file (Default: NodeSet.xml)\n";
		return ss.str();
	}

	std::vector<std::string>&
	CommandNodeSetFilter::namespaceUriVec(void)
	{
		return namespaceUriVec_;
	}

	std::string&
	CommandNodeSetFilter::srcNodeSetName(void)
	{
		return srcNodeSetName_;
	}

	std::string&
	CommandNodeSetFilter::dstNodeSetName(void)
	{
		return dstNodeSetName_;
	}

}
