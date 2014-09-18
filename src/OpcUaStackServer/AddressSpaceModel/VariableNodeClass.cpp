#include "OpcUaStackServer/AddressSpaceModel/VariableNodeClass.h"

namespace OpcUaStackServer
{

	VariableNodeClass::VariableNodeClass(void)
	: BaseNodeClass(NodeClass_Variable)
	, value_()
	, dataType_()
	, valueRank_()
	, accessLevel_()
	, historizing_()
	, arrayDimensions_()
	, minimumSamplingInterval_()
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

	ValueRanklAttribute& 
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

	void 
	VariableNodeClass::addReference(ReferenceType referenceType, OpcUaNodeId& opcUaNodeId)
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
		}
	}

}