/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSetApplication/GetNodeReferenceRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa GetNodeReferenceRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	GetNodeReferenceRequest::GetNodeReferenceRequest(void)
	: Object()
	, nodes_(boost::make_shared<OpcUaNodeIdArray>())
	{
	}

	GetNodeReferenceRequest::~GetNodeReferenceRequest(void)
	{
	}

	void 
	GetNodeReferenceRequest::nodes(const OpcUaNodeIdArray::SPtr nodes)
	{
		nodes_ = nodes;
	}
	
	OpcUaNodeIdArray::SPtr&
	GetNodeReferenceRequest::nodes(void)
	{
		return nodes_;
	}

	bool
	GetNodeReferenceRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		return nodes_->opcUaBinaryEncode(os);
	}
	
	bool
	GetNodeReferenceRequest::opcUaBinaryDecode(std::istream& is)
	{
		return nodes_->opcUaBinaryDecode(is);
	}


}
