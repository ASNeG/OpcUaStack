
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

#include "OpcUaClient/ClientCommand/CommandWrite.h"

using namespace OpcUaStackCore;

namespace OpcUaClient
{

	CommandWrite::CommandWrite(void)
	: CommandBase(CommandBase::Cmd_Write)
	, nodeIdVec_()
	, dataValueVec_()
	, attributeIdVec_()
	{
	}

	CommandWrite::~CommandWrite(void)
	{
	}

	CommandBase::SPtr
	CommandWrite::createCommand(void)
	{
		CommandBase::SPtr commandBase = boost::make_shared<CommandWrite>();
		return commandBase;
	}

	bool
	CommandWrite::validateCommand(void)
	{
		if (nodeIdVec_.size() == 0) {
			std::stringstream ss;
			ss << "neeed at least one node id parameter";
			errorMessage(ss.str());
			return false;
		}

		if (nodeIdVec_.size() != dataValueVec_.size()) {
			std::stringstream ss;
			ss << "data value missing";
			errorMessage(ss.str());
			return false;
		}

		return true;
	}

	bool
	CommandWrite::addParameter(const std::string& parameterName, const std::string& parameterValue)
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
			attributeIdVec_.push_back(13);
		}
		else if (parameterName == "-VALUE") {
			OpcUaVariant variant;
			if (!variant.fromString(parameterValue)) {
				std::stringstream ss;
				ss << "value parameter invalid (" << parameterValue << ")";
				errorMessage(ss.str());
				return false;
			}

			OpcUaDataValue::SPtr dataValue = boost::make_shared<OpcUaDataValue>();
			OpcUaDateTime dateTime(boost::posix_time::microsec_clock::universal_time());
			dataValue->variant()->copyFrom(variant);
			dataValue->sourceTimestamp(dateTime);
			dataValue->serverTimestamp(dateTime);
			dataValue->statusCode(Success);
			dataValueVec_.push_back(dataValue);
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
	CommandWrite::help(void)
	{
		std::stringstream ss;
		ss << "  -Write: Write one ore more data values to a opc ua server\n"
		   << "    -Session (0..1): Name of the session.\n"
		   << "    -NodeId (1..N): NodeId of the value to write to opc ua server\n"
		   << "      -Value (1): Value to write to the opc ua server\n"
		   << "      -AttributeId (0..1): Attribute Identifier to read. (Default: 13)\n";
		return ss.str();
	}

	OpcUaNodeId::Vec&
	CommandWrite::nodeIdVec(void)
	{
		return nodeIdVec_;
	}

	OpcUaDataValue::Vec&
	CommandWrite::dataValueVec(void)
	{
		return dataValueVec_;
	}

	std::vector<uint32_t>&
	CommandWrite::attributeIdVec(void)
	{
		return attributeIdVec_;
	}

}
