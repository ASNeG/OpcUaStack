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

}