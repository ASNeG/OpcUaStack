
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

#include "OpcUaClient/ClientCommand/CommandWriteH.h"

using namespace OpcUaStackCore;

namespace OpcUaClient
{

	CommandWriteH::CommandWriteH(void)
	: CommandBase(CommandBase::Cmd_WriteH)
	, nodeId_()
	, dataValueVec_()
	, actDataValue_()
	, csvFileName_("")
	, inputType_(T_CommandLine)
	, valueType_(OpcUaBuildInType_Unknown)
	{
	}

	CommandWriteH::~CommandWriteH(void)
	{
	}

	CommandBase::SPtr
	CommandWriteH::createCommand(void)
	{
		CommandBase::SPtr commandBase = boost::make_shared<CommandWriteH>();
		return commandBase;
	}

	bool
	CommandWriteH::validateCommand(void)
	{
		if (nodeId_.nodeIdType() == OpcUaBuildInType_Unknown) {
			std::stringstream ss;
			ss << "need node id parameter";
			errorMessage(ss.str());
			return false;
		}

		if (inputType_ == T_CSVFile) {
			if (csvFileName_.empty()) {
				std::stringstream ss;
				ss << "need csv parameter";
				errorMessage(ss.str());
				return false;
			}

			if (valueType_ == OpcUaBuildInType_Unknown) {
				std::stringstream ss;
				ss << "need value type parameter";
				errorMessage(ss.str());
				return false;
			}
		}
		else {
			if (dataValueVec_.size() == 0) {
				std::stringstream ss;
				ss << "need at least one data value parameter";
				errorMessage(ss.str());
				return false;
			}
		}

		return true;
	}

	bool
	CommandWriteH::addParameter(const std::string& parameterName, const std::string& parameterValue)
	{
		if (parameterName == "-NODEID") {
			if (!nodeId_.fromString(parameterValue)) {
				std::stringstream ss;
				ss << "node id parameter invalid (" << parameterValue << ")";
				errorMessage(ss.str());
				return false;
			}
		}
		else if (parameterName == "-VALUE") {
			OpcUaVariant variant;
			if (!variant.fromString(parameterValue)) {
				std::stringstream ss;
				ss << "value parameter invalid (" << parameterValue << ")";
				errorMessage(ss.str());
				return false;
			}

			actDataValue_ = boost::make_shared<OpcUaDataValue>();
			OpcUaDateTime dateTime(boost::posix_time::microsec_clock::universal_time());
			actDataValue_->variant()->copyFrom(variant);
			actDataValue_->sourceTimestamp(dateTime);
			actDataValue_->serverTimestamp(dateTime);
			actDataValue_->statusCode(Success);
			dataValueVec_.push_back(actDataValue_);
		}
		else if (parameterName == "-SOURCETIMESTAMP") {
			if (actDataValue_.get() == nullptr) {
				std::stringstream ss;
				ss << "a variable must exist before the source timestamp (" << parameterValue << ")";
				errorMessage(ss.str());
				return false;
			}

			std::string value = parameterValue;
			boost::algorithm::to_upper(value);
			if (value == "NOW") {
				OpcUaDateTime time(boost::posix_time::microsec_clock::universal_time());
				actDataValue_->sourceTimestamp(time);
			}
			else {
				boost::posix_time::ptime time;
				try {
					time = boost::posix_time::from_iso_string(parameterValue);
					actDataValue_->sourceTimestamp(time);
				} catch (...)
				{
					std::stringstream ss;
					ss << "start time parameter invalid (" << parameterValue << ")";
					errorMessage(ss.str());
					return false;
				}
			}
		}
		else if (parameterName == "-SERVERTIMESTAMP") {
			if (actDataValue_.get() == nullptr) {
				std::stringstream ss;
				ss << "a variable must exist before the server timestamp (" << parameterValue << ")";
				errorMessage(ss.str());
				return false;
			}

			std::string value = parameterValue;
			boost::algorithm::to_upper(value);
			if (value == "NOW") {
				OpcUaDateTime time(boost::posix_time::microsec_clock::universal_time());
				actDataValue_->serverTimestamp(time);
			}
			else {
				boost::posix_time::ptime time;
				try {
					time = boost::posix_time::from_iso_string(parameterValue);
					actDataValue_->serverTimestamp(time);
				} catch (...)
				{
					std::stringstream ss;
					ss << "start time parameter invalid (" << parameterValue << ")";
					errorMessage(ss.str());
					return false;
				}
			}
		}
		else if (parameterName == "-STATUSCODE") {
			try {
				uint32_t statusCode = boost::lexical_cast<uint32_t>(parameterValue);
				actDataValue_->statusCode((OpcUaStatusCode)statusCode);
			}
			catch (...)
			{
				std::stringstream ss;
				ss << "status code parameter invalid (" << parameterValue << ")";
				errorMessage(ss.str());
				return false;
		    }
		}
		else if (parameterName == "-VALUETYPE") {
			valueType_ = OpcUaBuildInTypeMap::string2BuildInType(parameterValue);
			if (valueType_ == OpcUaBuildInType_Unknown) {
				std::stringstream ss;
				ss << "value type parameter invalid (" << parameterValue << ")";
				errorMessage(ss.str());
				return false;
			}
		}
		else if (parameterName == "-CSV") {
			csvFileName_ = parameterValue;
			inputType_ = T_CSVFile;
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
	CommandWriteH::help(void)
	{
		std::stringstream ss;
		ss << "  -WriteH: Write one ore more historical data values to the opc ua server\n"
		   << "    -Session (0..1): Name of the session.\n"
		   << "     **** case 1 **** read values from command line\n"
		   << "    -NodeId (1..1): NodeId of the value to write to opc ua server\n"
		   << "      -Value (1..N): value.\n"
		   << "       The value or the status code must be available\n"
		   << "      -StatusCode (1..N): status code of the variable.\n"
		   << "       The variable or the status code must be available\n"
		   << "      -SourceTimestamp (1..N): source timestamp of the variable\n"
		   << "       The source timestamp is optinal\n"
		   << "       Format:\n"
		   << "         ISO Format (Example: 16010101T000000.0)\n"
		   << "         Now (Example: Now)\n"
		   << "      -ServerTimestamp (1..N): server timestamp of the variable\n"
		   << "       The server timestamp is optinal\n"
		   << "       Format:\n"
		   << "         ISO Format (Example: 16010101T000000.0)\n"
		   << "         Now (Example: Now)\n"
		   << "     **** case 2 **** read values from csv file\n"
		   << "    -NodeId (1..1): NodeId of the value to write to opc ua server\n"
		   << "    -ValueType (1..1): Data type of the variable\n"
		   << "    -CSV (1..1): Name of the CSV file\n"
		   << "       ";

		return ss.str();
	}

	OpcUaNodeId&
	CommandWriteH::nodeId(void)
	{
		return nodeId_;
	}

	OpcUaDataValue::Vec&
	CommandWriteH::dataValueVec(void)
	{
		return dataValueVec_;
	}

	std::string&
	CommandWriteH::csvFileName(void)
	{
		return csvFileName_;
	}

	CommandWriteH::InputType
	CommandWriteH::inputType(void)
	{
		return inputType_;
	}

	OpcUaBuildInType
	CommandWriteH::valueType(void)
	{
		return valueType_;
	}

}
