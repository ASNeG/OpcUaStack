#include "OpcUaStackServer/AddressSpaceModel/ObjectTypeNodeClass.h"

namespace OpcUaStackServer
{

	ObjectTypeNodeClass::ObjectTypeNodeClass(void)
	: BaseNodeClass(NodeClassType_ObjectType)
	, isAbstract_()
	, hasComponent_()
	, hasProperty_()
	, hasSubtypes_()
	, generatesEvents_()
	{
	}

	ObjectTypeNodeClass::~ObjectTypeNodeClass(void)
	{
	}

	IsAbstractAttribute& 
	ObjectTypeNodeClass::isAbstract(void)
	{
		return isAbstract_;
	}

	Attribute* 
	ObjectTypeNodeClass::isAbstractAttribute(void)
	{
		return &isAbstract_;
	}

	void 
	ObjectTypeNodeClass::addReference(ReferenceType referenceType, ReferenceItem::SPtr referenceItem)
	{
		switch (referenceType)
		{
			case ReferenceType_HasComponent:
				hasComponent_.referenceItemList_.push_back(referenceItem);
				break;
			case ReferenceType_HasProperty:
				hasProperty_.referenceItemList_.push_back(referenceItem);
				break;
			case ReferenceType_HasSubtype:
				hasSubtypes_.referenceItemList_.push_back(referenceItem);
				break;
			case ReferenceType_GenerateEvents:
				generatesEvents_.referenceItemList_.push_back(referenceItem);
				break;
		}
	}

	void
	ObjectTypeNodeClass::getReference(ReferenceList& list, ReferenceType referenceType)
	{
		switch (referenceType)
		{
			case ReferenceType_HasComponent:
				list = hasComponent_;
				break;
			case ReferenceType_HasProperty:
				list = hasProperty_;
				break;
			case ReferenceType_HasSubtype:
				list = hasSubtypes_;
				break;
			case ReferenceType_GenerateEvents:
				list = generatesEvents_;
				break;
		}
	}

}