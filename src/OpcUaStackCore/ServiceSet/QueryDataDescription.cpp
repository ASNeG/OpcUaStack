#include "OpcUaStackCore/ServiceSet/QueryDataDescription.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa QueryDataDescription
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	QueryDataDescription::QueryDataDescription(void)
	: ObjectPool<QueryDataDescription>()
	, relativePath_()
	, attributeId_()
	, indexRange_()
	{
	}

	QueryDataDescription::~QueryDataDescription(void)
	{
	}

	void 
	QueryDataDescription::relativePath(const RelativePath& relativePath)
	{
		relativePath_ = relativePath;
	}
	
	RelativePath& 
	QueryDataDescription::relativePath(void)
	{
		return relativePath_;
	}
	
	void 
	QueryDataDescription::attributeId(const OpcUaUInt32& attributeId)
	{
		attributeId_ = attributeId;
	}
	
	OpcUaUInt32 
	QueryDataDescription::attributeId(void)
	{
		return attributeId_;
	}
	
	void 
	QueryDataDescription::indexRange(const OpcUaString& indexRange)
	{
		indexRange_ = indexRange;
	}
	
	void 
	QueryDataDescription::indexRange(const std::string& indexRange)
	{
		indexRange_.value(indexRange);
	}
	
	OpcUaString& 
	QueryDataDescription::indexRange(void)
	{
		return indexRange_;
	}

	void 
	QueryDataDescription::opcUaBinaryEncode(std::ostream& os) const
	{
		relativePath_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, attributeId_);
		indexRange_.opcUaBinaryEncode(os);
	}
	
	void 
	QueryDataDescription::opcUaBinaryDecode(std::istream& is)
	{
		relativePath_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, attributeId_);
		indexRange_.opcUaBinaryDecode(is);
	}

}