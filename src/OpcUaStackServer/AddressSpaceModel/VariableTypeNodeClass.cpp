#include "OpcUaStackServer/AddressSpaceModel/VariableTypeNodeClass.h"

namespace OpcUaStackServer
{

	VariableTypeNodeClass::VariableTypeNodeClass(void)
	: BaseNodeClass(NodeClass_VariableType)
	, dataType_()
	, valueRank_()
	, isAbstract_()
	, value_()
	, arrayDimensions_()
	, hasProperty_()
	, hasComponent_()
	, hasSubtype_()
	, generatesEvent_()
	{
	}

	VariableTypeNodeClass::~VariableTypeNodeClass(void)
	{
	}

	DataTypeAttribute& 
	VariableTypeNodeClass::dataType(void)
	{
		return dataType_;
	}
		
	ValueRankAttribute& 
	VariableTypeNodeClass::valueRank(void)
	{
		return valueRank_;
	}
		
	IsAbstractAttribute& 
	VariableTypeNodeClass::isAbstract(void)
	{
		return isAbstract_;
	}
	
	ValueAttribute& 
	VariableTypeNodeClass::value(void)
	{
		return value_;
	}
		
	ArrayDimensionsAttribute& 
	VariableTypeNodeClass::arrayDimensions(void)
	{
		return arrayDimensions_;
	}

	Attribute* 
	VariableTypeNodeClass::dataTypeAttribute(void)
	{
		return &dataType_;
	}

	Attribute* 
	VariableTypeNodeClass::valueRankAttribute(void)
	{
		return &valueRank_;
	}

	Attribute* 
	VariableTypeNodeClass::isAbstractAttribute(void)
	{
		return &isAbstract_;
	}

	Attribute* 
	VariableTypeNodeClass::valueAttribute(void)
	{
		return &value_;
	}

	Attribute* 
	VariableTypeNodeClass::arrayDimensionsAttribute(void)
	{
		return &arrayDimensions_;
	}

	void 
	VariableTypeNodeClass::addReference(ReferenceType referenceType, OpcUaNodeId& opcUaNodeId)
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
				hasSubtype_.push_back(opcUaNodeId);
				break;
			case ReferenceType_GenerateEvents:
				generatesEvent_.push_back(opcUaNodeId);
				break;
		}
	}

	void 
	VariableTypeNodeClass::getReference(OpcUaNodeIdList& list, ReferenceType referenceType)
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
				list = hasSubtype_;
				break;
			case ReferenceType_GenerateEvents:
				list = generatesEvent_;
				break;
		}
	}
}

