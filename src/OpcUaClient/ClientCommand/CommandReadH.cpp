
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

#include "OpcUaClient/ClientCommand/CommandReadH.h"

using namespace OpcUaStackCore;

namespace OpcUaClient
{

	CommandReadH::CommandReadH(void)
	: CommandBase(CommandBase::Cmd_ReadH)
	, nodeIdVec_()
	, startTime_()
	, endTime_()
	, timestampsToReturn_(TimestampsToReturn_Both)
	, maxNumResultValuesPerNode_(2000)
	, maxNumRequests_(-1)
	, csvFileName_("")
	, outputType_(T_Stdout)
	{
		startTime_ = boost::posix_time::from_iso_string("16010101T000000.000000000");
		endTime_ = boost::posix_time::microsec_clock::universal_time();
	}

	CommandReadH::~CommandReadH(void)
	{
	}

	CommandBase::SPtr
	CommandReadH::createCommand(void)
	{
		CommandBase::SPtr commandBase = boost::make_shared<CommandReadH>();
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
			OpcUaNodeId::SPtr nodeId = boost::make_shared<OpcUaNodeId>();
			if (!nodeId->fromString(parameterValue)) {
				std::stringstream ss;
				ss << "node id parameter invalid (" << parameterValue << ")";
				errorMessage(ss.str());
				return false;
			}
			nodeIdVec_.push_back(nodeId);
		}
		else if (parameterName == "-STARTTIME") {
			std::string value = parameterValue;
			boost::algorithm::to_upper(value);
			if (value == "NOW") {
				startTime_ = boost::posix_time::microsec_clock::universal_time();
			}
			else {
				try {
					startTime_ = boost::posix_time::from_iso_string(parameterValue);
				} catch (...)
				{
					std::stringstream ss;
					ss << "start time parameter invalid (" << parameterValue << ")";
					errorMessage(ss.str());
					return false;
				}
			}
		}
		else if (parameterName == "-ENDTIME") {
			std::string value = parameterValue;
			boost::algorithm::to_upper(value);
			if (value == "NOW") {
				endTime_ = boost::posix_time::microsec_clock::universal_time();
			}
			else {
				try {
					endTime_ = boost::posix_time::from_iso_string(parameterValue);
				} catch (...)
				{
					std::stringstream ss;
					ss << "end time parameter invalid (" << parameterValue << ")";
					errorMessage(ss.str());
					return false;
				}
			}
		}
		else if (parameterName == "-TIMESTAMPSTORETURN") {
			std::string value = parameterValue;
			boost::algorithm::to_upper(value);
			if (value == "BOTH") {
				timestampsToReturn_ = TimestampsToReturn_Both;
			}
			else if (value == "SERVER") {
				timestampsToReturn_ = TimestampsToReturn_Server;
			}
			else if (value == "SOURCE") {
				timestampsToReturn_ = TimestampsToReturn_Source;
			}
			else {
				std::stringstream ss;
				ss << "timestamp to return parameter invalid (" << parameterValue << ")";
				errorMessage(ss.str());
				return false;
			}
		}
		else if (parameterName == "-MAXNUMRESULTVALUESPERNODE") {
			try {
				maxNumResultValuesPerNode_ = boost::lexical_cast<uint32_t>(parameterValue);
			}
			catch (...)
			{
				std::stringstream ss;
				ss << "MaxNumResultValuesPerNode parameter invalid (" << parameterValue << ")";
				errorMessage(ss.str());
				return false;
		    }
		}
		else if (parameterName == "-MAXNUMREQUESTS") {
			try {
				maxNumRequests_ = boost::lexical_cast<uint32_t>(parameterValue);
			}
			catch (...)
			{
				std::stringstream ss;
				ss << "MaxNumRequests parameter invalid (" << parameterValue << ")";
				errorMessage(ss.str());
				return false;
		    }
		}
		else if (parameterName == "-CSV") {
			csvFileName_ = parameterValue;
			outputType_ = T_CSVFile;
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
		   << "    -StartTime (0..1) start time of data (Default: 16010101T000000)\n"
		   << "     Format:\n"
		   << "       ISO Format (Example: 16010101T000000.0)\n"
		   << "       Now (Example: Now)\n"
		   << "    -EndTime (0..1) end time of data ISO Format (Default: Now)\n"
		   << "     Format:\n"
		   << "       ISO Format (Example: 16010101T120000.0)\n"
		   << "       Now (Example: Now)\n"
		   << "    -NodeId (1..N): NodeId of the value to read from opc ua server\n"
		   << "    -TimestampsToReturn (0..1): Selection of the timestamps to be returned\n"
		   << "       Both - Return source timestamp and server timestamp\n"
		   << "       Server - Return only server timestamp\n"
		   << "       Source - Return only source timestamp\n"
		   << "    -MaxNumResultValuesPerNode (0..1)\n"
		   << "       Maximum number of results per node\n"
		   << "    -MaxNumRequests (0..1)\n"
		   << "       Maximum number of requests to the opc ua server\n"
		   << "    -CSV (0..1)\n"
		   << "       Name of a CSV file in which the variables are to be stored\n"
		   << "     ";

		return ss.str();
	}

	OpcUaNodeId::Vec&
	CommandReadH::nodeIdVec(void)
	{
		return nodeIdVec_;
	}

	boost::posix_time::ptime&
	CommandReadH::startTime(void)
	{
		return startTime_;
	}

	boost::posix_time::ptime&
	CommandReadH::endTime(void)
	{
		return endTime_;
	}

	TimestampsToReturn
	CommandReadH::timestampsToReturn(void)
	{
		return timestampsToReturn_;
	}

	uint32_t
	CommandReadH::maxNumResultValuesPerNode(void)
	{
		return maxNumResultValuesPerNode_;
	}

	uint32_t
	CommandReadH::maxNumRequests(void)
	{
		return maxNumRequests_;
	}

	void
	CommandReadH::maxNumRequestsDec(void)
	{
		maxNumRequests_--;
	}

	std::string&
	CommandReadH::csvFileName(void)
	{
		return csvFileName_;
	}

	CommandReadH::OutputType
	CommandReadH::outputType(void)
	{
		return outputType_;
	}

	void
	CommandReadH::outputType(OutputType outputType)
	{
		outputType_ = outputType;
	}

}
