/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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
	VariableNodeClass::copyTo(VariableNodeClass::SPtr variableNodeClass)
	{
		copyTo(*variableNodeClass);
	}

	void
	VariableNodeClass::copyTo(VariableNodeClass& variableNodeClass)
	{
		BaseNodeClass::copyTo(variableNodeClass);
		valueAttribute()->copyTo(variableNodeClass.valueAttribute());
		dataTypeAttribute()->copyTo(variableNodeClass.dataTypeAttribute());
		valueRankAttribute()->copyTo(variableNodeClass.valueRankAttribute());
		accessLevelAttribute()->copyTo(variableNodeClass.accessLevelAttribute());
		userAccessLevelAttribute()->copyTo(variableNodeClass.userAccessLevelAttribute());
		historizingAttribute()->copyTo(variableNodeClass.historizingAttribute());
		arrayDimensionsAttribute()->copyTo(variableNodeClass.arrayDimensionsAttribute());
		minimumSamplingIntervalAttribute()->copyTo(variableNodeClass.minimumSamplingIntervalAttribute());
	}

	BaseNodeClass::SPtr
	VariableNodeClass::clone(void)
	{
		VariableNodeClass::SPtr variableNodeClass = constructSPtr<VariableNodeClass>();
		copyTo(variableNodeClass);
		return variableNodeClass;
	}

}
