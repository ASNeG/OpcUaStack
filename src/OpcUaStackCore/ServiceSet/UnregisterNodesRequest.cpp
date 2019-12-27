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

#include "OpcUaStackCore/ServiceSet/UnregisterNodesRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa UnregisterNodesRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	UnregisterNodesRequest::UnregisterNodesRequest(void)
	: Object()
	, nodesToUnregisterArraySPtr_(boost::make_shared<OpcUaNodeIdArray>())
	{
	}

	UnregisterNodesRequest::~UnregisterNodesRequest(void)
	{
	}

	void 
	UnregisterNodesRequest::nodesToUnregister(const OpcUaNodeIdArray::SPtr nodesToUnregister)
	{
		nodesToUnregisterArraySPtr_ = nodesToUnregister;
	}
	
	OpcUaNodeIdArray::SPtr 
	UnregisterNodesRequest::nodesToUnregister(void) const
	{
		return nodesToUnregisterArraySPtr_;
	}

	bool
	UnregisterNodesRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		return nodesToUnregisterArraySPtr_->opcUaBinaryEncode(os);
	}
	
	bool
	UnregisterNodesRequest::opcUaBinaryDecode(std::istream& is)
	{
		return nodesToUnregisterArraySPtr_->opcUaBinaryDecode(is);
	}

	bool
	UnregisterNodesRequest::jsonEncodeImpl(boost::property_tree::ptree &pt) const {
		return jsonObjectSPtrEncode(pt, nodesToUnregisterArraySPtr_, "NodesToUnregister");
	}

	bool
	UnregisterNodesRequest::jsonDecodeImpl(const boost::property_tree::ptree &pt) {
		return jsonObjectSPtrDecode(pt, nodesToUnregisterArraySPtr_, "NodesToUnregister");
	}

}
