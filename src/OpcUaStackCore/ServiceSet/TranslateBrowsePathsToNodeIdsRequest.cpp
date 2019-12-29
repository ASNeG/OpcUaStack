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

#include "OpcUaStackCore/ServiceSet/TranslateBrowsePathsToNodeIdsRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa TranslateBrowsePathsToNodeIdsRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	TranslateBrowsePathsToNodeIdsRequest::TranslateBrowsePathsToNodeIdsRequest(void)
	: Object()
	, browsePathArraySPtr_(boost::make_shared<BrowsePathArray>())
	{
	}

	TranslateBrowsePathsToNodeIdsRequest::~TranslateBrowsePathsToNodeIdsRequest(void)
	{
	}

	void 
	TranslateBrowsePathsToNodeIdsRequest::browsePaths(const BrowsePathArray::SPtr browsePaths) 
	{
		browsePathArraySPtr_ = browsePaths;
	}
	
	BrowsePathArray::SPtr 
	TranslateBrowsePathsToNodeIdsRequest::browsePaths(void) const
	{
		return browsePathArraySPtr_;
	}

	bool
	TranslateBrowsePathsToNodeIdsRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		return browsePathArraySPtr_->opcUaBinaryEncode(os);
	}
	
	bool
	TranslateBrowsePathsToNodeIdsRequest::opcUaBinaryDecode(std::istream& is)
	{
		return browsePathArraySPtr_->opcUaBinaryDecode(is);
	}

	bool
	TranslateBrowsePathsToNodeIdsRequest::jsonEncodeImpl(boost::property_tree::ptree &pt) const {
		return jsonObjectSPtrEncode(pt, browsePathArraySPtr_, "BrowsePaths");
	}

	bool
	TranslateBrowsePathsToNodeIdsRequest::jsonDecodeImpl(const boost::property_tree::ptree &pt) {
		return jsonObjectSPtrDecode(pt, browsePathArraySPtr_, "BrowsePaths");
	}

}
