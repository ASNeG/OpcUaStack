/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include "OpcUaStackServer/AddressSpaceModel/VariableTypeNodeClass.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	VariableTypeNodeClass::VariableTypeNodeClass(void)
	: BaseNodeClass(NodeClass::EnumVariableType)
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
		VariableTypeNodeClass::SPtr variableTypeNodeClass = boost::make_shared<VariableTypeNodeClass>();
		copyTo(variableTypeNodeClass);
		return variableTypeNodeClass;
	}

}

