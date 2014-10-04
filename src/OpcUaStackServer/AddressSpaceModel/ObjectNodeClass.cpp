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

}