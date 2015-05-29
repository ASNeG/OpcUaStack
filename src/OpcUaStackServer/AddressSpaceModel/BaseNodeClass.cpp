#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"

namespace OpcUaStackServer
{

	BaseNodeClass::BaseNodeClass(void)
	: nodeId_()
	, nodeClass_()
	, browseName_()
	, displayName_()
	, description_()
	, writeMask_()
	, userWriteMask_()
	, forwardInfoAsync_()
	, forwardInfoSync_()
	{
	}

	BaseNodeClass::BaseNodeClass(NodeClassType nodeClass)
	: nodeId_()
	, nodeClass_(nodeClass)
	, browseName_()
	, displayName_()
	, description_()
	, writeMask_()
	, userWriteMask_()
	, forwardInfoAsync_()
	, forwardInfoSync_()
	{
	}

	BaseNodeClass::~BaseNodeClass(void)
	{
	}

	NodeIdAttribute& 
	BaseNodeClass::nodeId(void)
	{
		return nodeId_;
	}

	NodeClassAttribute& 
	BaseNodeClass::nodeClass(void)
	{
		return nodeClass_;
	}
		
	BrowseNameAttribute& 
	BaseNodeClass::browseName(void)
	{
		return browseName_;
	}
		
	DisplayNameAttribute& 
	BaseNodeClass::displayName(void)
	{
		return displayName_;
	}
		
	DescriptionAttribute& 
	BaseNodeClass::description(void)
	{
		return description_;
	}
		
	WriteMaskAttribute& 
	BaseNodeClass::writeMask(void)
	{
		return writeMask_;
	}
		
	UserWriteMaskAttribute& 
	BaseNodeClass::userWriteMask(void)
	{
		return userWriteMask_;
	}

	Attribute* 
	BaseNodeClass::nodeIdAttribute(void)
	{
		return &nodeId_;
	}

	Attribute* 
	BaseNodeClass::nodeClassAttribute(void)
	{
		return &nodeClass_;
	}

	Attribute* 
	BaseNodeClass::browseNameAttribute(void)
	{
		return &browseName_;
	}

	Attribute* 
	BaseNodeClass::displayNameAttribute(void)
	{
		return &displayName_;
	}

	Attribute* 
	BaseNodeClass::descriptionAttribute(void)
	{
		return &description_;
	}

	Attribute* 
	BaseNodeClass::writeMaskAttribute(void)
	{
		return &writeMask_;
	}

	Attribute* 
	BaseNodeClass::userWriteMaskAttribute(void)
	{
		return &userWriteMask_;
	}

	ReferenceItemMap& 
	BaseNodeClass::referenceItemMap(void)
	{
		return referenceItemMap_;
	}

	void
	BaseNodeClass::copyTo(BaseNodeClass::SPtr baseNodeClass)
	{
		copyTo(*baseNodeClass);
	}
	void
	BaseNodeClass::copyTo(BaseNodeClass& baseNodeClass)
	{
		nodeIdAttribute()->copyTo(baseNodeClass.nodeIdAttribute());
		nodeClassAttribute()->copyTo(baseNodeClass.nodeClassAttribute());
		browseNameAttribute()->copyTo(baseNodeClass.browseNameAttribute());
		displayNameAttribute()->copyTo(baseNodeClass.displayNameAttribute());
		descriptionAttribute()->copyTo(baseNodeClass.descriptionAttribute());
		writeMaskAttribute()->copyTo(baseNodeClass.writeMaskAttribute());
		userWriteMaskAttribute()->copyTo(baseNodeClass.userWriteMaskAttribute());

		referenceItemMap_.copyTo(baseNodeClass.referenceItemMap());
	}

	void
	BaseNodeClass::forwardInfoAsync(ForwardInfoAsync::SPtr forwardInfoAsync)
	{
		forwardInfoAsync_ = forwardInfoAsync;
	}

	ForwardInfoAsync::SPtr
	BaseNodeClass::forwardInfoAsync(void)
	{
		return forwardInfoAsync_;
	}

	void
	BaseNodeClass::forwardInfoSync(ForwardInfoSync::SPtr forwardInfoSync)
	{
		forwardInfoSync_ = forwardInfoSync;
	}

	ForwardInfoSync::SPtr
	BaseNodeClass::forwardInfoSync(void)
	{
		return forwardInfoSync_;
	}

}
