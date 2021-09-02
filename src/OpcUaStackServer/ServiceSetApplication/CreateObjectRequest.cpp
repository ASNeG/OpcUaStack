/*
   Copyright 2019-2021 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackServer/ServiceSetApplication/CreateObjectRequest.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
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

    bool
	CreateObjectRequest::addNodeId(const std::string& nodeName, const OpcUaStackCore::OpcUaNodeId& nodeId)
    {
    	// check if entry already exist in node id map
    	if (nodeIdMap_.find(nodeName) != nodeIdMap_.end()) {
    		return false;
    	}

    	// add entry to node id map
    	nodeIdMap_.insert(std::make_pair(nodeName, nodeId));

    	return true;
    }

    bool
	CreateObjectRequest::getNodeId(const std::string& nodeName, OpcUaStackCore::OpcUaNodeId& nodeId)
    {
    	auto it = nodeIdMap_.find(nodeName);
    	if (it == nodeIdMap_.end()) {
    		return false;
    	}

    	nodeId = it->second;
    	return true;
    }

    CreateObjectRequest::NodeIdMap&
	CreateObjectRequest::nodeIdMap(void)
    {
    	return nodeIdMap_;
    }

	bool
	CreateObjectRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		return false;
	}

	bool
	CreateObjectRequest::opcUaBinaryDecode(std::istream& is)
	{
		return false;
	}

}
