/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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

#include <OpcUaStackServer/Generator/NodeElement.h>

namespace OpcUaStackServer
{

	NodeElement::NodeElement(void)
	: prefix_("")
	, nodeId_()
	, browseName_()
	, fullName_("")
	, globalVariableName_("")
	, localVariableName_("")
	, functionName_("")
	, dataTypeName_("")
	{
	}

	NodeElement::~NodeElement(void)
	{
	}

	void
	NodeElement::log(void)
	{
		Log(Debug, "Create new node element")
	    	.parameter("NodeId", nodeId_)
			.parameter("Prefix", prefix_)
			.parameter("BrowseName", browseName_)
			.parameter("FullName", fullName_)
			.parameter("GlobalVariableName", globalVariableName_)
			.parameter("LocalVariableName", localVariableName_)
			.parameter("FunctionName", functionName_)
			.parameter("DataTypeName", dataTypeName_);
	}

	void
	NodeElement::prefix(const std::string& prefix)
	{
		prefix_ = prefix;
	}

	std::string
	NodeElement::prefix(void)
	{
		return prefix_;
	}

	void
	NodeElement::nodeId(const OpcUaNodeId& nodeId)
	{
		nodeId_ = nodeId;
	}

	OpcUaNodeId&
	NodeElement::nodeId(void)
	{
		return nodeId_;
	}

	void
	NodeElement::browseName(const OpcUaQualifiedName& browseName)
	{
		browseName_ = browseName;
	}

	OpcUaQualifiedName&
	NodeElement::browseName(void)
	{
		return browseName_;
	}

	void
	NodeElement::fullName(const std::string& fullName)
	{
		fullName_ = fullName;
	}

	std::string&
	NodeElement::fullName(void)
	{
		return fullName_;
	}

	void
	NodeElement::globalVariableName(const std::string& globalVariableName)
	{
		globalVariableName_ = globalVariableName;
	}

	std::string&
	NodeElement::globalVariableName(void)
	{
		return globalVariableName_;
	}

	void
	NodeElement::localVariableName(const std::string& localVariableName)
	{
		localVariableName_ = localVariableName;
	}

	std::string&
	NodeElement::localVariableName(void)
	{
		return localVariableName_;
	}

	void
	NodeElement::functionName(const std::string& functionName)
	{
		functionName_ = functionName;
	}

	std::string&
	NodeElement::functionName(void)
	{
		return functionName_;
	}

	void
	NodeElement::dataTypeName(const std::string& dataTypeName)
	{
		dataTypeName_ = dataTypeName;
	}

	std::string&
	NodeElement::dataTypeName(void)
	{
		return dataTypeName_;
	}

}
