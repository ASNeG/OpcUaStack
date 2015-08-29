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

#include "OpcUaStackCore/ServiceSet/BrowseRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa BrowseRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	BrowseRequest::BrowseRequest(void)
	: ObjectPool<BrowseRequest>()
	, view_()
	, requestMaxReferencesPerNode_()
	, nodesToBrowseArraySPtr_(BrowseDescriptionArray::construct())
	{
	}

	BrowseRequest::~BrowseRequest(void)
	{
	}

	void 
	BrowseRequest::view(const ViewDescription& view)
	{
		view_ = view;
	}
	
	ViewDescription& 
	BrowseRequest::view(void)
	{
		return view_;
	}
	
	void 
	BrowseRequest::requestMaxReferencesPerNode(const OpcUaUInt32& requestMaxReferencesPerNode)
	{
		requestMaxReferencesPerNode_ = requestMaxReferencesPerNode;
	}
	
	OpcUaUInt32 
	BrowseRequest::requestMaxReferencesPerNode(void)
	{
		return requestMaxReferencesPerNode_;
	}
	
	void 
	BrowseRequest::nodesToBrowse(const BrowseDescriptionArray::SPtr nodesToBrowse)
	{
		nodesToBrowseArraySPtr_ = nodesToBrowse;
	}
	
	BrowseDescriptionArray::SPtr 
	BrowseRequest::nodesToBrowse(void) const
	{
		return nodesToBrowseArraySPtr_;
	}

	void 
	BrowseRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		view_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, requestMaxReferencesPerNode_);
		nodesToBrowseArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	BrowseRequest::opcUaBinaryDecode(std::istream& is)
	{
		view_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, requestMaxReferencesPerNode_);
		nodesToBrowseArraySPtr_->opcUaBinaryDecode(is);
	}
}
