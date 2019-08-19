
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

#include "OpcUaClient/ClientCommand/CommandFunction.h"

using namespace OpcUaStackCore;

namespace OpcUaClient
{

	CommandFunction::CommandFunction(void)
	: CommandBase(CommandBase::Cmd_Function)
	, functionNodeId_()
	, objectNodeId_()
	, inputVariantVec_()
	{
	}

	CommandFunction::~CommandFunction(void)
	{
	}

	CommandBase::SPtr
	CommandFunction::createCommand(void)
	{
		CommandBase::SPtr commandBase = boost::make_shared<CommandFunction>();
		return commandBase;
	}

	bool
	CommandFunction::validateCommand(void)
	{
		if (functionNodeId_.nodeIdType() == OpcUaBuildInType_Unknown) {
			std::stringstream ss;
			ss << "neeed at least one function node id parameter";
			errorMessage(ss.str());
			return false;
		}

		if (objectNodeId_.nodeIdType() == OpcUaBuildInType_Unknown) {
			std::stringstream ss;
			ss << "neeed at least one object node id parameter";
			errorMessage(ss.str());
			return false;
		}

		return true;
	}

	bool
	CommandFunction::addParameter(const std::string& parameterName, const std::string& parameterValue)
	{
		if (parameterName == "-FUNCTIONNODEID") {
			if (!functionNodeId_.fromString(parameterValue)) {
				std::stringstream ss;
				ss << "function node id parameter invalid (" << parameterValue << ")";
				errorMessage(ss.str());
				return false;
			}
		}
		else if (parameterName == "-OBJECTNODEID") {
			if (!objectNodeId_.fromString(parameterValue)) {
				std::stringstream ss;
				ss << "function node id parameter invalid (" << parameterValue << ")";
				errorMessage(ss.str());
				return false;
			}
		}
		else if (parameterName == "-INPUTVALUE") {
			OpcUaVariant::SPtr variant = boost::make_shared<OpcUaVariant>();
			if (!variant->fromString(parameterValue)) {
				std::stringstream ss;
				ss << "input value parameter invalid (" << parameterValue << ")";
				errorMessage(ss.str());
				return false;
			}

			inputVariantVec_.push_back(variant);
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
	CommandFunction::help(void)
	{
		std::stringstream ss;
		ss << "  -Function: call a opc ua server function\n"
		   << "    -Session (0..1): Name of the session.\n"
		   << "    -FunctionNodeId (1): Function node id\n"
		   << "    -ObjectNodeId (1): Object node id\n"
		   << "    -InputValue (0..N): Input values of the function\n";
		return ss.str();
	}

	OpcUaNodeId&
	CommandFunction::functionNodeId(void)
	{
		return functionNodeId_;
	}

	OpcUaNodeId&
	CommandFunction::objectNodeId(void)
	{
		return objectNodeId_;
	}

	OpcUaVariant::Vec&
	CommandFunction::inputVariantVec(void)
	{
		return inputVariantVec_;
	}

}
