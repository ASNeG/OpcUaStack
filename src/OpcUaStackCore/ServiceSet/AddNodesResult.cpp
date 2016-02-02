/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSet/AddNodesResult.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// AddNodesResult
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	AddNodesResult::AddNodesResult(void)
	: statusCode_()
	, addedNodeIdSPtr_()
	{
		addedNodeIdSPtr_ = constructSPtr<OpcUaNodeId>();
	}

	AddNodesResult::~AddNodesResult(void)
	{
	}

	void
	AddNodesResult::statusCode(OpcUaStatusCode statusCode)
	{
		statusCode_ = statusCode;
	}

	OpcUaStatusCode
	AddNodesResult::statusCode(void) const
	{
		return statusCode_;
	}


	void
	AddNodesResult::addedNodeId(const OpcUaNodeId::SPtr addedNodeIdSPtr)
	{
		addedNodeIdSPtr_ = addedNodeIdSPtr;
	}

	OpcUaNodeId::SPtr
	AddNodesResult::addedNodeId(void) const
	{
		return addedNodeIdSPtr_;
	}
	
	void 
	AddNodesResult::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)statusCode_);
		addedNodeIdSPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	AddNodesResult::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaUInt32 tmp;
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		statusCode_ = (OpcUaStatusCode)tmp;
		addedNodeIdSPtr_->opcUaBinaryDecode(is);
	}

}
