#include "OpcUaStackServer/AddressSpaceModel/ObjectNodeClass.h"

namespace OpcUaStackServer
{

	ObjectNodeClass::ObjectNodeClass(void)
	: BaseNodeClass()
	, eventNotifier_(false)
	, nodeVersion_()
	{
		nodeClass_ = NodeClass_Object;
	}

	ObjectNodeClass::~ObjectNodeClass(void)
	{
	}

}