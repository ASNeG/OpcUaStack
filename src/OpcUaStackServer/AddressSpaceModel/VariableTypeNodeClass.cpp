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

}