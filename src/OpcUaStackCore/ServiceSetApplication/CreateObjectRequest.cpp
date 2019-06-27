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

#include "OpcUaStackCore/ServiceSetApplication/CreateObjectRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa CreateObjectRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	CreateObjectRequest::CreateObjectRequest(void)
	: Object()
	{
	}

	CreateObjectRequest::~CreateObjectRequest(void)
	{
	}

	void
	CreateObjectRequest::namespaceName(const std::string& namespaceName)
	{
		namespaceName_ = namespaceName;
	}

	std::string&
	CreateObjectRequest::namespaceName(void)
	{
		return namespaceName_;
	}

	OpcUaLocalizedText&
	CreateObjectRequest::displayName(void)
	{
		return displayName_;
	}

	void
	CreateObjectRequest::displayName(const OpcUaLocalizedText& displayName)
	{
		displayName_ = displayName;
	}

	void
	CreateObjectRequest::parentNodeId(const OpcUaNodeId& parentNodeId)
	{
		parentNodeId_ = parentNodeId;
	}

	OpcUaNodeId&
	CreateObjectRequest::parentNodeId(void)
	{
		return parentNodeId_;
	}

	void
	CreateObjectRequest::referenceTypeNodeId(const OpcUaNodeId& referenceTypeNodeId)
	{
		referenceTypeNodeId_ = referenceTypeNodeId;
	}

	OpcUaNodeId&
	CreateObjectRequest::referenceTypeNodeId(void)
	{
		return referenceTypeNodeId_;
	}

    void
	CreateObjectRequest::objectInstance(Object::SPtr& objectInstance)
    {
    	objectInstance_ = objectInstance;
    }

    Object::SPtr&
	CreateObjectRequest::objectInstance(void)
    {
    	return objectInstance_;
    }

	void
	CreateObjectRequest::opcUaBinaryEncode(std::ostream& os) const
	{
	}

	void
	CreateObjectRequest::opcUaBinaryDecode(std::istream& is)
	{
	}

}
