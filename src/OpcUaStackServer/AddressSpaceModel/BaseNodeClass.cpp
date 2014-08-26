#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"

namespace OpcUaStackServer
{

	BaseNodeClass::BaseNodeClass(void)
	: nodeId_()
	, nodeClass_()
	, browseName_()
	, displayName_()
	, description_()
	, writeMask_(0)
	, UserWriteMask_(0)
	{
	}

	BaseNodeClass::~BaseNodeClass(void)
	{
	}

	OpcUaNodeId& 
	BaseNodeClass::nodeId(void)
	{
		return nodeId_;
	}

	NodeClass&
	BaseNodeClass::nodeClass(void)
	{
		return nodeClass_;
	}
	
	OpcUaQualifiedName& 
	BaseNodeClass::browseName(void)
	{
		return browseName_;
	}
	
	OpcUaLocalizedText& 
	BaseNodeClass::displayName(void)
	{
		return displayName_;
	}

}