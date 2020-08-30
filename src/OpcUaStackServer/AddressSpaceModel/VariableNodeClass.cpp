/*
   Copyright 2015-2020 Kai Huebl (kai@huebl-sgh.de)

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

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	VariableNodeClass::VariableNodeClass(void)
	: BaseNodeClass(NodeClass::EnumVariable)
	, value_()
	, dataType_()
	, valueRank_()
	, accessLevel_()
	, historizing_()
	, arrayDimensions_()
	, minimumSamplingInterval_()
	, accessLevelEx_()
	{
	}

	VariableNodeClass::VariableNodeClass(
		OpcUaNodeId& nodeId,
		VariableNodeClass& variableNodeClass
	)
	: BaseNodeClass(NodeClass::EnumVariable, nodeId, &variableNodeClass)
	, value_()
	, dataType_()
	, valueRank_()
	, accessLevel_()
	, historizing_()
	, arrayDimensions_()
	, minimumSamplingInterval_()
	, accessLevelEx_()
	{
		OpcUaDataValue dataValue;
		if (variableNodeClass.getValue(dataValue)) setValue(dataValue);

		OpcUaNodeId dataType;
		if (variableNodeClass.getDataType(dataType)) setDataType(dataType);

		int32_t valueRank;
		if (variableNodeClass.getValueRank(valueRank)) setValueRank(valueRank);

		OpcUaByte accessLevel;
		if (variableNodeClass.getAccessLevel(accessLevel)) setAccessLevel(accessLevel);

		OpcUaByte userAccessLevel;
		if (variableNodeClass.getUserAccessLevel(userAccessLevel)) setUserAccessLevel(userAccessLevel);

		OpcUaBoolean historizing;
		if (variableNodeClass.getHistorizing(historizing)) setHistorizing(historizing);

		OpcUaUInt32Array arrayDimensions;
		if (variableNodeClass.getArrayDimensions(arrayDimensions)) setArrayDimensions(arrayDimensions);

		OpcUaDouble minimumSamplingInterval;
		if (variableNodeClass.getMinimumSamplingInterval(minimumSamplingInterval)) setMinimumSamplingInterval(minimumSamplingInterval);

		AccessLevelExType accessLevelEx;
		if (variableNodeClass.getAccessLevelEx(accessLevelEx)) setAccessLevelEx(accessLevelEx);
	}

	VariableNodeClass::VariableNodeClass(
		OpcUaNodeId& nodeId,
		VariableTypeNodeClass& variableTypeNodeClass
	)
	: BaseNodeClass(NodeClass::EnumVariable, nodeId, &variableTypeNodeClass)
	, value_()
	, dataType_()
	, valueRank_()
	, accessLevel_()
	, historizing_()
	, arrayDimensions_()
	, minimumSamplingInterval_()
	, accessLevelEx_()
	{
		OpcUaDataValue dataValue;
		if (variableTypeNodeClass.getValue(dataValue)) setValue(dataValue);

		OpcUaNodeId dataType;
		if (variableTypeNodeClass.getDataType(dataType)) setDataType(dataType);

		int32_t valueRank;
		if (variableTypeNodeClass.getValueRank(valueRank)) setValueRank(valueRank);

		OpcUaByte accessLevel = 3;
		setAccessLevel(accessLevel);

		OpcUaByte userAccessLevel = 3;
		setUserAccessLevel(userAccessLevel);

		OpcUaBoolean historizing = false;
		setHistorizing(historizing);

		OpcUaUInt32Array arrayDimensions;
		if (variableTypeNodeClass.getArrayDimensions(arrayDimensions)) setArrayDimensions(arrayDimensions);

		OpcUaDouble minimumSamplingInterval = 0;
		setMinimumSamplingInterval(minimumSamplingInterval);

		AccessLevelExType accessLevelEx = 0;
		setAccessLevelEx(accessLevelEx);
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

	AccessLevelExAttribute&
	VariableNodeClass::accessLevelEx()
	{
		return accessLevelEx_;
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

	Attribute*
	VariableNodeClass::accessLevelExAttribute(void)
	{
		return &accessLevelEx_;
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
		accessLevelExAttribute()->copyTo(variableNodeClass.accessLevelExAttribute());
	}

	BaseNodeClass::SPtr
	VariableNodeClass::clone(void)
	{
		VariableNodeClass::SPtr variableNodeClass = boost::make_shared<VariableNodeClass>();
		copyTo(variableNodeClass);
		return variableNodeClass;
	}

}
