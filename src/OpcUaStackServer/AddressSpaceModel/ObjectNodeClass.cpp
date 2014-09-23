#include "OpcUaStackServer/AddressSpaceModel/ObjectNodeClass.h"

namespace OpcUaStackServer
{

	ObjectNodeClass::ObjectNodeClass(void)
	: BaseNodeClass(NodeClass_Object)
	, eventNotifier_()
	, nodeVersion_()
	, hasComponent_()
	, hasProperty_()
	, hasModellingRule_()
	, hasTypeDefinition_()
	, hasModelParent_()
	, hasEventSource_()
	, hasNotifier_()
	, organizes_()
	, hasDescription_()
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

	void 
	ObjectNodeClass::getReference(OpcUaNodeIdList& list, ReferenceType referenceType)
	{
		switch (referenceType)
		{
			case ReferenceType_HasComponent:
				list = hasComponent_;
				break;
			case ReferenceType_HasProperty:
				list = hasProperty_;
				break;
			case ReferenceType_HasModellingRule:
				list = hasModellingRule_;
				break;
			case ReferenceType_HasTypeDefinition:
				list = hasTypeDefinition_;
				break;
			case ReferenceType_HasModelParent:
				list = hasModelParent_;
				break;
			case ReferenceType_HasEventSource:
				list = hasEventSource_;
				break;
			case ReferenceType_HasNotifier:
				list = hasNotifier_;
				break;
			case ReferenceType_Organizes:
				list = organizes_;
				break;
			case ReferenceType_HasDescription:
				list = hasDescription_;
				break;
		}
	}
}