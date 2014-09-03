#include "OpcUaStackCore/ServiceSet/BrowseDescription.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa BrowseDescription
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	BrowseDescription::BrowseDescription(void)
	: ObjectPool<BrowseDescription>()
	, nodeIdSPtr_(OpcUaNodeId::construct())
	, browseDirection_()
	, referenceTypeIdSPtr_(OpcUaNodeId::construct())
	, includeSubtypes_()
	, nodeClassMask_()
	, resultMask_()
	{
	}

	BrowseDescription::~BrowseDescription(void)
	{
	}

	void 
	BrowseDescription::nodeId(const OpcUaNodeId::SPtr nodeId)
	{
		nodeIdSPtr_ = nodeId;
	}
	
	OpcUaNodeId::SPtr 
	BrowseDescription::nodeId(void) const
	{
		return nodeIdSPtr_;
	}
	
	void 
	BrowseDescription::browseDirection(const BrowseDirectionEnum browseDirection)
	{
		browseDirection_ = browseDirection;
	}
	
	BrowseDirectionEnum 
	BrowseDescription::browseDirection(void)
	{
		return browseDirection_;
	}

	void 
	BrowseDescription::referenceTypeId(const OpcUaNodeId::SPtr referenceTypeId)
	{
		referenceTypeIdSPtr_ = referenceTypeId;
	}
	
	OpcUaNodeId::SPtr 
	BrowseDescription::referenceTypeId(void) const
	{
		return referenceTypeIdSPtr_;
	}
	
	void 
	BrowseDescription::includeSubtypes(const OpcUaBoolean includeSubtypes)
	{
		includeSubtypes_ = includeSubtypes;
	}
	
	OpcUaBoolean 
	BrowseDescription::includeSubtypes(void)
	{
		return includeSubtypes_;
	}
	
	void 
	BrowseDescription::nodeClassMask(const OpcUaUInt32 nodeClassMask)
	{
		nodeClassMask_ = nodeClassMask;
	}
	
	OpcUaUInt32 
	BrowseDescription::nodeClassMask(void)
	{
		return nodeClassMask_;
	}
	
	void 
	BrowseDescription::resultMask(const OpcUaUInt32 resultMask)
	{
		resultMask_ = resultMask;
	}
	
	OpcUaUInt32 
	BrowseDescription::resultMask(void)
	{
		return resultMask_;
	}

	void 
	BrowseDescription::opcUaBinaryEncode(std::ostream& os) const
	{
		nodeIdSPtr_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)browseDirection_);
		referenceTypeIdSPtr_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, includeSubtypes_);
		OpcUaNumber::opcUaBinaryEncode(os, nodeClassMask_);
		OpcUaNumber::opcUaBinaryEncode(os, resultMask_);
	}
	
	void 
	BrowseDescription::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaUInt32 tmp;
		nodeIdSPtr_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		browseDirection_ = (BrowseDirectionEnum)tmp;
		referenceTypeIdSPtr_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, includeSubtypes_);
		OpcUaNumber::opcUaBinaryDecode(is, nodeClassMask_);
		OpcUaNumber::opcUaBinaryDecode(is, resultMask_);
	}

}