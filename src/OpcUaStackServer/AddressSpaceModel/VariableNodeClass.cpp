#include "OpcUaStackServer/AddressSpaceModel/VariableNodeClass.h"

namespace OpcUaStackServer
{

	VariableNodeClass::VariableNodeClass(void)
	: BaseNodeClass(NodeClassType_Variable)
	, value_()
	, dataType_()
	, valueRank_()
	, accessLevel_()
	, historizing_()
	, arrayDimensions_()
	, minimumSamplingInterval_()
	, hasModellingRule_() 
	, hasProperty_()
	, hasComponent_()
	, hasTypeDefinition_()
	, hasModelParent_()
	{
	}

	VariableNodeClass::~VariableNodeClass(void)
	{
	}

	ValueAttribute& 
	VariableNodeClass::value(void)
	{
		return value_;
	}

	DataTypeAttribute& 
	VariableNodeClass::dataType(void)
	{
		return dataType_;
	}

	ValueRankAttribute& 
	VariableNodeClass::valueRank(void)
	{
		return valueRank_;
	}

	AccessLevelAttribute& 
	VariableNodeClass::accessLevel(void)
	{
		return accessLevel_;
	}

	UserAccessLevelAttribute& 
	VariableNodeClass::userAccessLevel(void)
	{
		return userAccessLevel_;
	}

	HistorizingAttribute& 
	VariableNodeClass::historizing(void)
	{
		return historizing_;
	}

	ArrayDimensionsAttribute& 
	VariableNodeClass::arrayDimensions(void)
	{
		return arrayDimensions_;
	}

	MinimumSamplingIntervalAttribute& 
	VariableNodeClass::minimumSamplingInterval(void)
	{
		return minimumSamplingInterval_;
	}

	Attribute* 
	VariableNodeClass::valueAttribute(void)
	{
		return &value_;
	}

	Attribute* 
	VariableNodeClass::dataTypeAttribute(void)
	{
		return &dataType_;
	}

	Attribute* 
	VariableNodeClass::valueRankAttribute(void)
	{
		return &valueRank_;
	}

	Attribute* 
	VariableNodeClass::accessLevelAttribute(void)
	{
		return &accessLevel_;
	}

	Attribute* 
	VariableNodeClass::userAccessLevelAttribute(void)
	{
		return &userAccessLevel_;
	}

	Attribute* 
	VariableNodeClass::historizingAttribute(void)
	{
		return &historizing_;
	}

	Attribute* 
	VariableNodeClass::arrayDimensionsAttribute(void)
	{
		return &arrayDimensions_;
	}

	Attribute* 
	VariableNodeClass::minimumSamplingIntervalAttribute(void)
	{
		return &minimumSamplingInterval_;
	}

	void 
	VariableNodeClass::addReference(ReferenceType referenceType, ReferenceItem::SPtr& referenceItem)
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
		}
	}

	void
	VariableNodeClass::getReference(ReferenceList& list, ReferenceType referenceType)
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
		}
	}

}