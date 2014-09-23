#include "OpcUaStackServer/AddressSpaceModel/ObjectTypeNodeClass.h"

namespace OpcUaStackServer
{

	ObjectTypeNodeClass::ObjectTypeNodeClass(void)
	: BaseNodeClass(NodeClass_ObjectType)
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

	void 
	ObjectTypeNodeClass::addReference(ReferenceType referenceType, OpcUaNodeId& opcUaNodeId)
	{
		switch (referenceType)
		{
			case ReferenceType_HasComponent:
				hasComponent_.push_back(opcUaNodeId);
				break;
			case ReferenceType_HasProperty:
				hasProperty_.push_back(opcUaNodeId);
				break;
			case ReferenceType_HasSubtype:
				hasSubtypes_.push_back(opcUaNodeId);
				break;
			case ReferenceType_GenerateEvents:
				generatesEvents_.push_back(opcUaNodeId);
				break;
		}
	}

	void
	ObjectTypeNodeClass::getReference(OpcUaNodeIdList& list, ReferenceType referenceType)
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