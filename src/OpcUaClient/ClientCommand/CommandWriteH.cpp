
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
#include "OpcUaClient/ClientCommand/CommandWriteH.h"

using namespace OpcUaStackCore;

namespace OpcUaClient
{

	CommandWriteH::CommandWriteH(void)
	: CommandBase(CommandBase::Cmd_WriteH)
	, nodeId_()
	, dataValueVec_()
	, actDataValue_()
	{
	}

	CommandWriteH::~CommandWriteH(void)
	{
	}

	CommandBase::SPtr
	CommandWriteH::createCommand(void)
	{
		CommandBase::SPtr commandBase = constructSPtr<CommandWriteH>();
		return commandBase;
	}

	bool
	CommandWriteH::validateCommand(void)
	{
		if (dataValueVec_.size() == 0) {
			std::stringstream ss;
			ss << "need at least one data value parameter";
			errorMessage(ss.str());
			return false;
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

			actDataValue_ = constructSPtr<OpcUaDataValue>();
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
		   << "    -Value (1..N): NodeId of the value to write to opc ua server\n"
		   << "      -SourceTimestamp (1..N): source timestamp of the variable\n"
		   << "       Format:\n"
		   << "         ISO Format (Example: 16010101T000000.0)\n"
		   << "         Now (Example: Now)\n"
		   << "      -ServerTimestamp (1..N): server timestamp of the variable\n"
		   << "       Format:\n"
		   << "         ISO Format (Example: 16010101T000000.0)\n"
		   << "         Now (Example: Now)\n"
		   << "      -StatusCode (1..N): status code of the variable.\n"
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

}
