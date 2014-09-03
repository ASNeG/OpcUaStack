#include "OpcUaStackCore/ServiceSet/BrowseResult.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa BrowseResult
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	BrowseResult::BrowseResult(void)
	: ObjectPool<BrowseResult>()
	, statusCode_()
	, continuationPoint_()
	, referenceArraySPtr_(ReferenceDescriptionArray::construct())
	{
	}

	BrowseResult::~BrowseResult(void)
	{
	}

	void 
	BrowseResult::statusCode(const OpcUaStatusCode& statusCode)
	{
		statusCode_ = statusCode;
	}
	
	OpcUaStatusCode& 
	BrowseResult::statusCode(void)
	{
		return statusCode_;
	}
	
	void 
	BrowseResult::continuationPoint(const OpcUaByteString& continuationPoint)
	{
		continuationPoint_ = continuationPoint;
	}
	
	OpcUaByteString& 
	BrowseResult::continuationPoint(void)
	{
		return continuationPoint_;
	}
	
	void 
	BrowseResult::references(const ReferenceDescriptionArray::SPtr references)
	{
		referenceArraySPtr_ = references;
	}
	
	ReferenceDescriptionArray::SPtr 
	BrowseResult::references(void) const
	{
		return referenceArraySPtr_;
	}

	void 
	BrowseResult::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, statusCode_);
		continuationPoint_.opcUaBinaryEncode(os);
		referenceArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	BrowseResult::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaUInt32 tmp;
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		statusCode_ = (OpcUaStatusCode)tmp;
		continuationPoint_.opcUaBinaryDecode(is);
		referenceArraySPtr_->opcUaBinaryDecode(is);
	}
}