#include "OpcUaStackServer/AddressSpaceModel/ViewNodeClass.h"

namespace OpcUaStackServer
{

	ViewNodeClass::ViewNodeClass(void)
	: BaseNodeClass(NodeClass_View)
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
	ViewNodeClass::addReference(ReferenceType referenceType, OpcUaNodeId& opcUaNodeId)
	{
		switch (referenceType)
		{
			case ReferenceType_HasProperty:
				hasProperty_.push_back(opcUaNodeId);
				break;
			case ReferenceType_HierarchicalReferences:
				hierarchicalReferences_.push_back(opcUaNodeId);
				break;
		}
	}

	void
	ViewNodeClass::getReference(OpcUaNodeIdList& list, ReferenceType referenceType)
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