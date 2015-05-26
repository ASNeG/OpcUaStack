#include "OpcUaStackServer/AddressSpaceModel/ObjectTypeNodeClass.h"

namespace OpcUaStackServer
{

	ObjectTypeNodeClass::ObjectTypeNodeClass(void)
	: BaseNodeClass(NodeClassType_ObjectType)
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

	void
	ObjectTypeNodeClass::copyTo(ObjectTypeNodeClass::SPtr objectTypeNodeClass)
	{
		copyTo(*objectTypeNodeClass);
	}

	void
	ObjectTypeNodeClass::copyTo(ObjectTypeNodeClass& objectTypeNodeClass)
	{
		BaseNodeClass::copyTo(objectTypeNodeClass);
		isAbstractAttribute()->copyTo(objectTypeNodeClass.isAbstractAttribute());
	}

}
