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

#include "OpcUaStackCore/ServiceSet/RegisterNodesRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa RegisterNodesRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	RegisterNodesRequest::RegisterNodesRequest(void)
	: Object()
	, nodesToRegisterArraySPtr_(boost::make_shared<OpcUaNodeIdArray>())
	{
	}

	RegisterNodesRequest::~RegisterNodesRequest(void)
	{
	}

	void 
	RegisterNodesRequest::nodesToRegister(const OpcUaNodeIdArray::SPtr nodesToRegister)
	{
		nodesToRegisterArraySPtr_ = nodesToRegister;
	}
	
	OpcUaNodeIdArray::SPtr 
	RegisterNodesRequest::nodesToRegister(void) const
	{
		return nodesToRegisterArraySPtr_;
	}

	bool
	RegisterNodesRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		return nodesToRegisterArraySPtr_->opcUaBinaryEncode(os);
	}
	
	bool
	RegisterNodesRequest::opcUaBinaryDecode(std::istream& is)
	{
		return nodesToRegisterArraySPtr_->opcUaBinaryDecode(is);
	}

	bool
	RegisterNodesRequest::jsonEncodeImpl(boost::property_tree::ptree &pt) const {
		return jsonObjectSPtrEncode(pt, nodesToRegisterArraySPtr_, "NodesToRegister");
	}

	bool
	RegisterNodesRequest::jsonDecodeImpl(const boost::property_tree::ptree &pt) {
		return jsonObjectSPtrDecode(pt, nodesToRegisterArraySPtr_, "NodesToRegister");;
	}

}
