#include "OpcUaStackServer/AddressSpaceModel/ObjectNodeClass.h"

namespace OpcUaStackServer
{

	ObjectNodeClass::ObjectNodeClass(void)
	: BaseNodeClass(NodeClass_Object)
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

}