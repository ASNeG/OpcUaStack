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
#include "OpcUaStackServer/InformationModel/InformationModelAccess.h"

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
	NodeInfoDataType::init(
		const OpcUaNodeId& dataTypeNodeId,
		InformationModel::SPtr& informationModel
	)
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
			OpcUaNodeId dataTypeNodeId = structureField->dataType();

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

			// added array flag
			if (structureField->valueRank() > -1) {
				dataTypeField->array(true);
			}

			// added optional flag
			if (structureField->isOptional()) {
				dataTypeField->optional(true);
			}

			// added description
			dataTypeField->description(structureField->description().text().toStdString());

			// handle build in type
			bool buildInType = false;
			if (dataTypeNodeId.namespaceIndex() == 0 && dataTypeNodeId.nodeIdType() == OpcUaBuildInType_OpcUaUInt32) {
				uint32_t type;
				uint16_t namespaceIndex;
				dataTypeNodeId.get(type, namespaceIndex);
				std::string buildInType = OpcUaBuildInTypeMap::buildInType2String((OpcUaBuildInType)type);
				if (buildInType != "Unknown") {
					// set number flag
					if (OpcUaBuildInTypeClass::isNumber((OpcUaBuildInType)type) == true) {
						dataTypeField->number(true);
					}

					// set boolean flag
					if (OpcUaBuildInTypeClass::isBoolean((OpcUaBuildInType)type) == true) {
						dataTypeField->boolean(true);
					}

					// set byte flag
					if (OpcUaBuildInTypeClass::isByte((OpcUaBuildInType)type) == true) {
						dataTypeField->byte(true);
					}

					if (dataTypeField->array() == true) {
						dataTypeField->smartpointer(true);
						dataTypeField->variableType("OpcUa" + buildInType + "Array::SPtr");
						dataTypeField->type(DataTypeField::BuildInArrayType);
					}
					else if ((dataTypeField->number() == true) ||
							 (dataTypeField->byte() == true) ||
							 (dataTypeField->boolean() == true)) {
						dataTypeField->variableType("OpcUa" + buildInType);
						dataTypeField->type(DataTypeField::NumberType);
					}
					else {
						dataTypeField->variableType("OpcUa" + buildInType);
						dataTypeField->type(DataTypeField::BuildInType);
					}
					buildInType = true;
				}
			}

			if (buildInType == false) {
				// get type name
				BaseNodeClass::SPtr baseNode = informationModel->find(dataTypeNodeId);
				if (baseNode.get() == nullptr) {
					Log(Error, "data type node identifier not exist in information model")
						.parameter("DataTypeNode", dataTypeNodeId);
					return "";
				}
				OpcUaLocalizedText displayName;
				baseNode->getDisplayName(displayName);
				std::string dataTypeName = displayName.text().toStdString();

				// set include
				setIncludePath(dataTypeNodeId, dataTypeName, numberNamespaceMap(), dataTypeField);

				// enum type possible
				InformationModelAccess ima(informationModel);
				dataTypeField->enumeration(ima.isDataTypeEnum(dataTypeNodeId));

				// structure type possible
				dataTypeField->structure(ima.isDataTypeStructure(dataTypeNodeId));

				// set build in type name
				if (dataTypeField->enumeration() == true) {
					if (dataTypeField->array()) {
						dataTypeField->smartpointer(true);
						dataTypeField->variableType(dataTypeName + "Array::SPtr");
						dataTypeField->type(DataTypeField::EnumerationArrayType);
					}
					else {
						dataTypeField->variableType(dataTypeName);
						dataTypeField->type(DataTypeField::EnumerationType);
					}
				}
				else if (dataTypeField->structure() == true) {
					if (dataTypeField->array()) {
						dataTypeField->smartpointer(true);
						dataTypeField->variableType(dataTypeName + "Array::SPtr");
						dataTypeField->type(DataTypeField::StructureArrayType);
					}
					else {
						dataTypeField->variableType(dataTypeName);
						dataTypeField->type(DataTypeField::StructureType);
					}
				}
				else {
					Log(Error, "data type node invalid")
						.parameter("DataTypeNodeId", dataTypeNodeId);
					return false;
				}
			}

			dataTypeFieldVec_.push_back(dataTypeField);
		}

		return true;
	}

	void
	NodeInfoDataType::setIncludePath(
		OpcUaNodeId& dataTypeNodeId,
		const std::string& dataTypeName,
		NumberNamespaceMap& numberNamespaceMap,
		DataTypeField::SPtr& dataTypeField
	)
	{
		std::string directory = "StandardDataType";
		if (dataTypeNodeId.namespaceIndex() != 0) directory = "CustomerDataType";

		std::string includePath =
				numberNamespaceMap.getNamespaceName(dataTypeNodeId.namespaceIndex()) +
				"/" + directory +
				"/" + dataTypeName + ".h";
	}

}
