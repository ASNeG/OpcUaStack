#include "OpcUaStackServer/AddressSpaceModel/ViewNodeClass.h"

namespace OpcUaStackServer
{

	ViewNodeClass::ViewNodeClass(void)
	: BaseNodeClass(NodeClassType_View)
	, containsNoLoops_()
	, eventNotifier_()
	, hierarchicalReferences_()
	, hasProperty_()
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
	ViewNodeClass::addReference(ReferenceType referenceType, ReferenceItem::SPtr referenceItem)
	{
		switch (referenceType)
		{
			case ReferenceType_HasProperty:
				hasProperty_.referenceItemList_.push_back(referenceItem);
				break;
			case ReferenceType_HierarchicalReferences:
				hierarchicalReferences_.referenceItemList_.push_back(referenceItem);
				break;
		}
	}

	void
	ViewNodeClass::getReference(ReferenceList& list, ReferenceType referenceType)
	{
		switch (referenceType)
		{
			case ReferenceType_HasProperty:
				list = hasProperty_;
				break;
			case ReferenceType_HierarchicalReferences:
				list = hierarchicalReferences_;
				break;
		}
	}

}