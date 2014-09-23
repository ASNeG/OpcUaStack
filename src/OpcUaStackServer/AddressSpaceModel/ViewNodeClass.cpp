#include "OpcUaStackServer/AddressSpaceModel/ViewNodeClass.h"

namespace OpcUaStackServer
{

	ViewNodeClass::ViewNodeClass(void)
	: BaseNodeClass(NodeClass_View)
	, containsNoLoops_()
	, eventNotifier_()
	{
	}

	ViewNodeClass::~ViewNodeClass(void)
	{
	}

	ContainsNoLoopsAttribute& 
	ViewNodeClass::containsNoLoops(void)
	{
		return containsNoLoops_;
	}
		
	EventNotifierAttribute& 
	ViewNodeClass::eventNotifier(void)
	{
		return eventNotifier_;
	}

	Attribute* 
	ViewNodeClass::containsNoLoopsAttribute(void)
	{
		return &containsNoLoops_;
	}
		
	Attribute* 
	ViewNodeClass::eventNotifierAttribute(void)
	{
		return &eventNotifier_;
	}

}