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

#include "OpcUaStackCore/ServiceSet/QueryFirstRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa QueryFirstRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	QueryFirstRequest::QueryFirstRequest(void)
	: Object()
	, view_()
	, nodeTypeArraySPtr_(boost::make_shared<NodeTypeDescriptionArray>())
	, filter_()
	, maxDataSetsToReturn_()
	, maxReferencesToReturn_()
	{
	}


	QueryFirstRequest::~QueryFirstRequest(void)
	{
	}

	void 
	QueryFirstRequest::view(const ViewDescription& view)
	{
		view_ = view;
	}
	
	ViewDescription& 
	QueryFirstRequest::view(void)
	{
		return view_;
	}
	
	void 
	QueryFirstRequest::nodeTypes(const NodeTypeDescriptionArray::SPtr nodeTypes)
	{
		nodeTypeArraySPtr_ = nodeTypes;
	}
	
	NodeTypeDescriptionArray::SPtr 
	QueryFirstRequest::nodeTypes(void) const
	{
		return nodeTypeArraySPtr_;
	}
	
	void 
	QueryFirstRequest::filter(const ContentFilter& filter)
	{
		filter_ = filter;
	}
	
	ContentFilter& 
	QueryFirstRequest::filter(void)
	{
		return filter_;
	}
	
	void 
	QueryFirstRequest::maxDataSetsToReturn(const OpcUaUInt32& maxDataSetsToReturn)
	{
		maxDataSetsToReturn_ = maxDataSetsToReturn;
	}
	
	OpcUaUInt32 
	QueryFirstRequest::maxDataSetsToReturn(void)
	{
		return maxDataSetsToReturn_;
	}
	
	void 
	QueryFirstRequest::maxReferencesToReturn(const OpcUaUInt32& maxReferencesToReturn)
	{
		maxReferencesToReturn_ = maxReferencesToReturn;
	}
	
	OpcUaUInt32 
	QueryFirstRequest::maxReferencesToReturn(void)
	{
		return maxReferencesToReturn_;
	}

	bool
	QueryFirstRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= view_.opcUaBinaryEncode(os);
		rc &= nodeTypeArraySPtr_->opcUaBinaryEncode(os);
		rc &= filter_.opcUaBinaryEncode(os);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, maxDataSetsToReturn_);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, maxReferencesToReturn_);

		return rc;
	}
	
	bool
	QueryFirstRequest::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= view_.opcUaBinaryDecode(is);
		rc &= nodeTypeArraySPtr_->opcUaBinaryDecode(is);
		rc &= filter_.opcUaBinaryDecode(is);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, maxDataSetsToReturn_);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, maxReferencesToReturn_);

		return rc;
	}
}
