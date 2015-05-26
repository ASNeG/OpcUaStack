#include "OpcUaStackServer/AddressSpaceModel/ObjectNodeClass.h"

namespace OpcUaStackServer
{

	ObjectNodeClass::ObjectNodeClass(void)
	: BaseNodeClass(NodeClassType_Object)
	, eventNotifier_()
	, nodeVersion_()
	{
	}

	ObjectNodeClass::~ObjectNodeClass(void)
	{
	}

	EventNotifierAttribute& 
	ObjectNodeClass::eventNotifier(void)
	{
		return eventNotifier_;
	}

	Attribute* 
	ObjectNodeClass::eventNotifierAttribute(void)
	{
		return &eventNotifier_;
	}

	void
	ObjectNodeClass::copyTo(ObjectNodeClass::SPtr objectNodeClass)
	{
		copyTo(*objectNodeClass);
	}

	void
	ObjectNodeClass::copyTo(ObjectNodeClass& objectNodeClass)
	{
		BaseNodeClass::copyTo(objectNodeClass);
		eventNotifierAttribute()->copyTo(objectNodeClass.eventNotifierAttribute());
	}

}
