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
	{
	}

	BaseNodeClass::BaseNodeClass(NodeClass nodeClass)
	: nodeId_()
	, nodeClass_(nodeClass)
	, browseName_()
	, displayName_()
	, description_()
	, writeMask_()
	, userWriteMask_()
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

}