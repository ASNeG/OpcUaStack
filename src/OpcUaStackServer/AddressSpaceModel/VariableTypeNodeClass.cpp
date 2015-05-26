#include "OpcUaStackServer/AddressSpaceModel/VariableTypeNodeClass.h"

namespace OpcUaStackServer
{

	VariableTypeNodeClass::VariableTypeNodeClass(void)
	: BaseNodeClass(NodeClassType_VariableType)
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
	VariableTypeNodeClass::copyTo(VariableTypeNodeClass::SPtr variableTypeNodeClass)
	{
		copyTo(*variableTypeNodeClass);
	}

	void
	VariableTypeNodeClass::copyTo(VariableTypeNodeClass& variableTypeNodeClass)
	{
		BaseNodeClass::copyTo(variableTypeNodeClass);
		dataTypeAttribute()->copyTo(variableTypeNodeClass.dataTypeAttribute());
		valueRankAttribute()->copyTo(variableTypeNodeClass.valueRankAttribute());
		isAbstractAttribute()->copyTo(variableTypeNodeClass.isAbstractAttribute());
		valueAttribute()->copyTo(variableTypeNodeClass.valueRankAttribute());
		arrayDimensionsAttribute()->copyTo(variableTypeNodeClass.arrayDimensionsAttribute());
	}

	BaseNodeClass::SPtr
	VariableTypeNodeClass::clone(void)
	{
		VariableTypeNodeClass::SPtr variableTypeNodeClass = VariableTypeNodeClass::construct();
		copyTo(variableTypeNodeClass);
		return variableTypeNodeClass;
	}

}

