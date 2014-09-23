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

	Attribute* 
	ObjectNodeClass::eventNotifierAttribute(void)
	{
		return &eventNotifier_;
	}

	void 
	ObjectNodeClass::addReference(ReferenceType referenceType, OpcUaNodeId& opcUaNodeId)
	{
		switch (referenceType)
		{
			case ReferenceType_HasComponent:
				hasComponent_.push_back(opcUaNodeId);
				break;
			case ReferenceType_HasProperty:
				hasProperty_.push_back(opcUaNodeId);
				break;
			case ReferenceType_HasModellingRule:
				hasModellingRule_.push_back(opcUaNodeId);
				break;
			case ReferenceType_HasTypeDefinition:
				hasTypeDefinition_.push_back(opcUaNodeId);
				break;
			case ReferenceType_HasModelParent:
				hasModelParent_.push_back(opcUaNodeId);
				break;
			case ReferenceType_HasEventSource:
				hasEventSource_.push_back(opcUaNodeId);
				break;
			case ReferenceType_HasNotifier:
				hasNotifier_.push_back(opcUaNodeId);
				break;
			case ReferenceType_Organizes:
				organizes_.push_back(opcUaNodeId);
				break;
			case ReferenceType_HasDescription:
				hasDescription_.push_back(opcUaNodeId);
				break;
		}
	}

}