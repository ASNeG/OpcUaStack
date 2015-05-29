#include "OpcUaStackServer/AddressSpaceModel/ViewNodeClass.h"

namespace OpcUaStackServer
{

	ViewNodeClass::ViewNodeClass(void)
	: BaseNodeClass(NodeClassType_View)
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

	void
	ViewNodeClass::copyTo(ViewNodeClass::SPtr viewNodeClass)
	{
		copyTo(*viewNodeClass);
	}

	void
	ViewNodeClass::copyTo(ViewNodeClass& viewNodeClass)
	{
		BaseNodeClass::copyTo(viewNodeClass);
		containsNoLoopsAttribute()->copyTo(viewNodeClass.containsNoLoopsAttribute());
		eventNotifierAttribute()->copyTo(viewNodeClass.eventNotifierAttribute());
	}

	BaseNodeClass::SPtr
	ViewNodeClass::clone(void)
	{
		ViewNodeClass::SPtr viewNodeClass = ViewNodeClass::construct();
		copyTo(viewNodeClass);
		return viewNodeClass;
	}

}
