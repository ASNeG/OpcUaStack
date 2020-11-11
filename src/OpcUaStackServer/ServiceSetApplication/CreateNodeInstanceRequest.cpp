/*
   Copyright 2017-2020 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackServer/ServiceSetApplication/CreateNodeInstanceRequest.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
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

	bool
	CreateNodeInstanceRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= OpcUaNumber::opcUaBinaryEncode(os, (uint32_t)nodeClassType_);
		rc &= parentNodeId_.opcUaBinaryEncode(os);
		rc &= nodeId_.opcUaBinaryEncode(os);
		rc &= displayName_.opcUaBinaryEncode(os);
		rc &= browseName_.opcUaBinaryEncode(os);
		rc &= referenceNodeId_.opcUaBinaryEncode(os);
		rc &= typeNodeId_.opcUaBinaryEncode(os);

		return rc;
	}
	
	bool
	CreateNodeInstanceRequest::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		uint32_t tmp;
		rc &= OpcUaNumber::opcUaBinaryDecode(is, tmp);
		rc &= nodeClassType_ = (NodeClass::Enum)tmp;
		rc &= parentNodeId_.opcUaBinaryDecode(is);
		rc &= nodeId_.opcUaBinaryDecode(is);
		rc &= displayName_.opcUaBinaryDecode(is);
		rc &= browseName_.opcUaBinaryDecode(is);
		rc &= referenceNodeId_.opcUaBinaryDecode(is);
		rc &= typeNodeId_.opcUaBinaryDecode(is);

		return rc;
	}


}
