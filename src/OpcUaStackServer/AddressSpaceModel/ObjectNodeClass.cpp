#include "OpcUaStackServer/AddressSpaceModel/ObjectNodeClass.h"

namespace OpcUaStackServer
{

	ObjectNodeClass::ObjectNodeClass(void)
	: BaseNodeClass(NodeClassType_Object)
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

	Attribute* 
	ObjectNodeClass::eventNotifierAttribute(void)
	{
		return &eventNotifier_;
	}

	void 
	ObjectNodeClass::addReference(ReferenceType referenceType, ReferenceItem::SPtr referenceItem)
	{
		switch (referenceType)
		{
			case ReferenceType_HasComponent:
				hasComponent_.referenceItemList_.push_back(referenceItem);
				break;
			case ReferenceType_HasProperty:
				hasProperty_.referenceItemList_.push_back(referenceItem);
				break;
			case ReferenceType_HasModellingRule:
				hasModellingRule_.referenceItemList_.push_back(referenceItem);
				break;
			case ReferenceType_HasTypeDefinition:
				hasTypeDefinition_.referenceItemList_.push_back(referenceItem);
				break;
			case ReferenceType_HasModelParent:
				hasModelParent_.referenceItemList_.push_back(referenceItem);
				break;
			case ReferenceType_HasEventSource:
				hasEventSource_.referenceItemList_.push_back(referenceItem);
				break;
			case ReferenceType_HasNotifier:
				hasNotifier_.referenceItemList_.push_back(referenceItem);
				break;
			case ReferenceType_Organizes:
				organizes_.referenceItemList_.push_back(referenceItem);
				break;
			case ReferenceType_HasDescription:
				hasDescription_.referenceItemList_.push_back(referenceItem);
				break;
		}
	}

	void 
	ObjectNodeClass::getReference(ReferenceList& list, ReferenceType referenceType)
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