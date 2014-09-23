#include "OpcUaStackServer/AddressSpaceModel/ObjectTypeNodeClass.h"

namespace OpcUaStackServer
{

	ObjectTypeNodeClass::ObjectTypeNodeClass(void)
	: BaseNodeClass(NodeClass_ObjectType)
	, isAbstract_()
	{
	}

	ObjectTypeNodeClass::~ObjectTypeNodeClass(void)
	{
	}

	IsAbstractAttribute& 
	ObjectTypeNodeClass::isAbstract(void)
	{
		return isAbstract_;
	}

	Attribute* 
	ObjectTypeNodeClass::isAbstractAttribute(void)
	{
		return &isAbstract_;
	}

	OpcUaNodeIdList& 
	ObjectTypeNodeClass::hasComponent(void)
	{
		return hasComponent_;
	}
		
	OpcUaNodeIdList& 
	ObjectTypeNodeClass::hasProperty(void)
	{
		return hasProperty_;
	}
		
	OpcUaNodeIdList& 
	ObjectTypeNodeClass::hasSubtypes(void)
	{
		return hasSubtypes_;
	}
		
	OpcUaNodeIdList& 
	ObjectTypeNodeClass::generatesEvents(void)
	{
		return generatesEvents_;
	}

}