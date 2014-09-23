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
		
	ValueRanklAttribute& 
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

}