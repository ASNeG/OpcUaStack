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

   Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (atimin@gmail.com)
 */

#include "OpcUaStackCore/ServiceSet/RegisterNodesResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa RegisterNodesResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	RegisterNodesResponse::RegisterNodesResponse(void)
	: Object()
	, registeredNodeIdArraySPtr_(boost::make_shared<OpcUaNodeIdArray>())
	{
	}

	RegisterNodesResponse::~RegisterNodesResponse(void)
	{
	}

	void 
	RegisterNodesResponse::registeredNodeIds(const OpcUaNodeIdArray::SPtr registeredNodeIds)
	{
		registeredNodeIdArraySPtr_ = registeredNodeIds;
	}
	
	OpcUaNodeIdArray::SPtr 
	RegisterNodesResponse::registeredNodeIds(void) const
	{
		return registeredNodeIdArraySPtr_;
	}

	bool
	RegisterNodesResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		return registeredNodeIdArraySPtr_->opcUaBinaryEncode(os);
	}
	
	bool
	RegisterNodesResponse::opcUaBinaryDecode(std::istream& is)
	{
		return registeredNodeIdArraySPtr_->opcUaBinaryDecode(is);
	}

	bool
	RegisterNodesResponse::jsonEncodeImpl(boost::property_tree::ptree &pt) const {
		return jsonObjectSPtrEncode(pt, registeredNodeIdArraySPtr_, "RegisteredNodeIds");
	}

	bool
	RegisterNodesResponse::jsonDecodeImpl(const boost::property_tree::ptree &pt) {
		return jsonObjectSPtrDecode(pt, registeredNodeIdArraySPtr_, "RegisteredNodeIds");
	}
}
