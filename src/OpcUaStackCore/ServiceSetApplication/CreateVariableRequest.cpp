/*
   Copyright 2019 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSetApplication/CreateVariableRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa CreateVariableRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	CreateVariableRequest::CreateVariableRequest(void)
	: Object()
	, namespaceName_("")
	, displayName_()
	, parentNodeId_()
	, referenceTypeNodeId_()
	, variableInstance_()
	{
	}

	CreateVariableRequest::~CreateVariableRequest(void)
	{
	}

	void
	CreateVariableRequest::namespaceName(const std::string& namespaceName)
	{
		namespaceName_ = namespaceName;
	}

	std::string&
	CreateVariableRequest::namespaceName(void)
	{
		return namespaceName_;
	}

	void
	CreateVariableRequest::displayName(const OpcUaLocalizedText& displayName)
	{
		displayName_ = displayName;
	}

	OpcUaLocalizedText&
	CreateVariableRequest::displayName(void)
	{
		return displayName_;
	}

	void
	CreateVariableRequest::parentNodeId(const OpcUaNodeId& parentNodeId)
	{
		parentNodeId_ = parentNodeId;
	}

	OpcUaNodeId&
	CreateVariableRequest::parentNodeId(void)
	{
		return parentNodeId_;
	}

	void
	CreateVariableRequest::referenceTypeNodeId(const OpcUaNodeId& referenceTypeNodeId)
	{
		referenceTypeNodeId_ = referenceTypeNodeId;
	}

	OpcUaNodeId&
	CreateVariableRequest::referenceTypeNodeId(void)
	{
		return referenceTypeNodeId_;
	}

    void
	CreateVariableRequest::variableInstance(Object::SPtr& variableInstance)
    {
    	variableInstance_ = variableInstance;
    }

    Object::SPtr&
	CreateVariableRequest::variableInstance(void)
    {
    	return variableInstance_;
    }

	void
	CreateVariableRequest::opcUaBinaryEncode(std::ostream& os) const
	{
	}

	void
	CreateVariableRequest::opcUaBinaryDecode(std::istream& is)
	{
	}

}
