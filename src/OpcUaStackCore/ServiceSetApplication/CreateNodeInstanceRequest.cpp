/*
   Copyright 2017-2018 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSetApplication/CreateNodeInstanceRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa CreateNodeInstanceRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	CreateNodeInstanceRequest::CreateNodeInstanceRequest(void)
	: Object()
	, name_("")
	, nodeClassType_()
	, parentNodeId_()
	, nodeId_()
	, displayName_()
	, browseName_()
	, referenceNodeId_()
	, typeNodeId_()
	{
	}

	CreateNodeInstanceRequest::~CreateNodeInstanceRequest(void)
	{
	}

	std::string&
	CreateNodeInstanceRequest::name(void)
	{
		return name_;
	}

	NodeClass::Enum&
	CreateNodeInstanceRequest::nodeClassType(void)
	{
		return nodeClassType_;
	}

	OpcUaNodeId&
	CreateNodeInstanceRequest::parentNodeId(void)
	{
		return parentNodeId_;
	}

	OpcUaNodeId&
	CreateNodeInstanceRequest::nodeId(void)
	{
		return nodeId_;
	}

	OpcUaLocalizedText&
	CreateNodeInstanceRequest::displayName(void)
	{
		return displayName_;
	}

	OpcUaQualifiedName&
	CreateNodeInstanceRequest::browseName(void)
	{
		return browseName_;
	}

	OpcUaNodeId&
	CreateNodeInstanceRequest::referenceNodeId(void)
	{
		return referenceNodeId_;
	}

	OpcUaNodeId&
	CreateNodeInstanceRequest::typeNodeId(void)
	{
		return typeNodeId_;
	}

	void 
	CreateNodeInstanceRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, (uint32_t)nodeClassType_);
		parentNodeId_.opcUaBinaryEncode(os);
		nodeId_.opcUaBinaryEncode(os);
		displayName_.opcUaBinaryEncode(os);
		browseName_.opcUaBinaryEncode(os);
		referenceNodeId_.opcUaBinaryEncode(os);
		typeNodeId_.opcUaBinaryEncode(os);
	}
	
	void 
	CreateNodeInstanceRequest::opcUaBinaryDecode(std::istream& is)
	{
		uint32_t tmp;
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		nodeClassType_ = (NodeClass::Enum)tmp;
		parentNodeId_.opcUaBinaryDecode(is);
		nodeId_.opcUaBinaryDecode(is);
		displayName_.opcUaBinaryDecode(is);
		browseName_.opcUaBinaryDecode(is);
		referenceNodeId_.opcUaBinaryDecode(is);
		typeNodeId_.opcUaBinaryDecode(is);
	}


}
