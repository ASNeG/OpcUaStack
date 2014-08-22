#include "OpcUaStackCore/ServiceSet/RelativePathElement.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa RelativePathElement
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	RelativePathElement::RelativePathElement(void)
	: ObjectPool<RelativePathElement>()
	, referenceTypeIdSPtr_(OpcUaNodeId::construct())
	, isInverse_()
	, includeSubtypes_()
	, targetName_()
	{
	}

	RelativePathElement::~RelativePathElement(void)
	{
	}

	void 
	RelativePathElement::referenceTypeId(const OpcUaNodeId::SPtr referenceTypeId)
	{
		referenceTypeIdSPtr_ = referenceTypeId;
	}
	
	OpcUaNodeId::SPtr 
	RelativePathElement::referenceTypeId(void) const
	{
		return referenceTypeIdSPtr_;
	}
	
	void 
	RelativePathElement::isInverse(const OpcUaBoolean& isInverse)
	{
		isInverse_ = isInverse;
	}
	
	OpcUaBoolean 
	RelativePathElement::isInverse(void) const
	{
		return isInverse_;
	}
	
	void 
	RelativePathElement::includeSubtypes(const OpcUaBoolean& includeSubtypes)
	{
		includeSubtypes_ = includeSubtypes;
	}

	OpcUaBoolean 
	RelativePathElement::includeSubtypes(void) const
	{
		return includeSubtypes_;
	}
	
	void 
	RelativePathElement::targetName(const OpcUaQualifiedName& targetName)
	{
		targetName_ = targetName;
	}
		
	OpcUaQualifiedName& 
	RelativePathElement::targetName(void)
	{
		return targetName_;
	}

	void 
	RelativePathElement::opcUaBinaryEncode(std::ostream& os) const
	{
		referenceTypeIdSPtr_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, isInverse_);
		OpcUaNumber::opcUaBinaryEncode(os, includeSubtypes_);
		targetName_.opcUaBinaryEncode(os);
	}
	
	void 
	RelativePathElement::opcUaBinaryDecode(std::istream& is)
	{
		referenceTypeIdSPtr_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, isInverse_);
		OpcUaNumber::opcUaBinaryDecode(is, includeSubtypes_);
		targetName_.opcUaBinaryDecode(is);
	}
}