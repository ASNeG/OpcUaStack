/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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

#include <boost/algorithm/string.hpp>

#include "OpcUaStackServer/Generator/NodeInfoDataType.h"
#include "OpcUaStackServer/AddressSpaceModel/DataTypeNodeClass.h"

namespace OpcUaStackServer
{

	NodeInfoDataType::NodeInfoDataType(void)
	: NodeInfo()
	, structureDefinition_()
	, dataTypeFieldVec_()
	{
	}

	NodeInfoDataType::~NodeInfoDataType(void)
	{
	}

	DataTypeField::Vec&
	NodeInfoDataType::fields(void)
	{
		return dataTypeFieldVec_;
	}

	bool
	NodeInfoDataType::init(const OpcUaNodeId& dataTypeNodeId, InformationModel::SPtr& informationModel)
	{
		// init node info
		if (!NodeInfo::init(dataTypeNodeId, informationModel)) {
			return false;
		}


		// cast base node class to data type node class
		if (dynamic_cast<DataTypeNodeClass*>(baseNode().get()) == nullptr) {
			Log(Error, "node is not from type data type node")
				.parameter("DataTypeNodeId", dataTypeNodeId);
			return false;
		}
		DataTypeNodeClass::SPtr dataTypeNodeClass = boost::static_pointer_cast<DataTypeNodeClass>(baseNode());


		// get data type definition from node class
		Object::SPtr definitionObject = dataTypeNodeClass->dataTypeDefinition();
		if (definitionObject.get() == nullptr) {
			return true;
		}

		if (dynamic_cast<StructureDefinition*>(definitionObject.get()) == nullptr) {
			Log(Error, "node definiton object is not from type StructureDefinition")
				.parameter("DataTypeNodeId", dataTypeNodeId);
			return false;
		}
		structureDefinition_ = boost::static_pointer_cast<StructureDefinition>(definitionObject);


		// create field information
		uint32_t size = structureDefinition_->fields()->size();
		for (uint32_t idx=0; idx<size; idx++) {
			StructureField::SPtr structureField;
			structureDefinition_->fields()->get(idx, structureField);


			DataTypeField::SPtr dataTypeField = constructSPtr<DataTypeField>();

			// added name
			dataTypeField->name(structureField->name().toStdString());

			// added variable name
			std::string variableName = structureField->name().toStdString();
			variableName = boost::to_lower_copy(variableName.substr(0,1)) + variableName.substr(1) + "_";
			dataTypeField->variableName(variableName);

			// added parameter name
			std::string parameterName = structureField->name().toStdString();
			parameterName = boost::to_lower_copy(parameterName.substr(0,1)) + parameterName.substr(1);
			dataTypeField->parameterName(parameterName);

			// added variable type
			bool smartpointer;
			std::string variableType = getVariableType(structureField, informationModel, smartpointer);
			if (variableType == "") {
				Log(Error, "variable type unknown in StructureDefinition")
					.parameter("DataTypeNodeId", dataTypeNodeId)
					.parameter("VariableTypeNodeId", structureField->dataType());
				return false;
			}
			dataTypeField->variableType(variableType);
			dataTypeField->smartpointer(smartpointer);

			// added description
			dataTypeField->description(structureField->description().text().toStdString());

			// added array flag
			if (structureField->valueRank() > -1) {
				dataTypeField->array(true);
			}

			dataTypeFieldVec_.push_back(dataTypeField);
		}

		return true;
	}

	std::string
	NodeInfoDataType::getVariableType(
		StructureField::SPtr& structureField,
		InformationModel::SPtr& informationModel,
		bool &smartpointer
	)
	{
		smartpointer = false;

		OpcUaNodeId typeNodeId = structureField->dataType();
		int32_t valueRank = structureField->valueRank();

		// build in type possible
		if (typeNodeId.namespaceIndex() == 0 && typeNodeId.nodeIdType() == OpcUaBuildInType_OpcUaUInt32) {
			uint32_t type;
			uint16_t namespaceIndex;
			typeNodeId.get(type, namespaceIndex);
			std::string buildInType = OpcUaBuildInTypeMap::buildInType2String((OpcUaBuildInType)type);
			if (buildInType != "Unknown") {
				buildInType = "OpcUa" + buildInType;

				if (typeNodeId.nodeIdType() == OpcUaBuildInType_OpcUaExtensionObject) {
					smartpointer = true;
					buildInType = buildInType + "::SPtr";
				}

				return buildInType;
			}
		}

		// enum type possible
		// FIXME: todo

		// structure type possible
		// FIXME: todo

		return "";
	}

}
