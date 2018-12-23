/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSetApplication/GetNodeReferenceResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa GetNodeReferenceResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	GetNodeReferenceResponse::GetNodeReferenceResponse(void)
	: Object()
	, nodeReferenceArray_(constructSPtr<NodeReferenceArray>())
	{
	}

	GetNodeReferenceResponse::~GetNodeReferenceResponse(void)
	{
	}

	void 
	GetNodeReferenceResponse::nodeReferenceArray(const NodeReferenceArray::SPtr& nodeReferenceArray)
	{
		nodeReferenceArray_ = nodeReferenceArray;
	}
	
	NodeReferenceArray::SPtr&
	GetNodeReferenceResponse::nodeReferenceArray(void)
	{
		return nodeReferenceArray_;
	}

	void 
	GetNodeReferenceResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		//nodeReferenceArray_->opcUaBinaryEncode(os);
	}
	
	void 
	GetNodeReferenceResponse::opcUaBinaryDecode(std::istream& is)
	{
		//nodeReferenceArray_->opcUaBinaryDecode(is);
	}
}
