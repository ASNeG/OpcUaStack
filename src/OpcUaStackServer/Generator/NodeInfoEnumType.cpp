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

#include "OpcUaStackServer/Generator/NodeInfoEnumType.h"
#include "OpcUaStackServer/AddressSpaceModel/DataTypeNodeClass.h"

namespace OpcUaStackServer
{

	NodeInfoEnumType::NodeInfoEnumType(void)
	: NodeInfo()
	, structureDefinition_()
	, EnumTypeFieldVec_()
	{
	}

	NodeInfoEnumType::~NodeInfoEnumType(void)
	{
	}

	EnumTypeField::Vec&
	NodeInfoEnumType::fields(void)
	{
		return EnumTypeFieldVec_;
	}

	bool
	NodeInfoEnumType::init(const OpcUaNodeId& enumTypeNodeId, InformationModel::SPtr& informationModel)
	{
		// init node info
		if (!NodeInfo::init(enumTypeNodeId, informationModel)) {
			return false;
		}


		// cast base node class to enum type node class
		if (dynamic_cast<DataTypeNodeClass*>(baseNode().get()) == nullptr) {
			Log(Error, "node is not from type enum type node")
				.parameter("EnumTypeNodeId", enumTypeNodeId);
			return false;
		}
		DataTypeNodeClass::SPtr dataTypeNodeClass = boost::static_pointer_cast<DataTypeNodeClass>(baseNode());


		// get enum type definition from node class
		Object::SPtr definitionObject = dataTypeNodeClass->dataTypeDefinition();
		if (definitionObject.get() == nullptr) {
			return true;
		}

		if (dynamic_cast<StructureDefinition*>(definitionObject.get()) == nullptr) {
			Log(Error, "node definiton object is not from type StructureDefinition")
				.parameter("EnumTypeNodeId", enumTypeNodeId);
			return false;
		}
		structureDefinition_ = boost::static_pointer_cast<StructureDefinition>(definitionObject);

#if 0

		// create field information
		uint32_t size = structureDefinition_->fields()->size();
		for (uint32_t idx=0; idx<size; idx++) {
			StructureField::SPtr structureField;
			structureDefinition_->fields()->get(idx, structureField);


			EnumTypeField::SPtr EnumTypeField = constructSPtr<EnumTypeField>();

			// added name
			EnumTypeField->name(structureField->name().toStdString());

			// added variable name
			std::string variableName = structureField->name().toStdString();
			variableName = boost::to_lower_copy(variableName.substr(0,1)) + variableName.substr(1) + "_";
			EnumTypeField->variableName(variableName);

			// added parameter name
			std::string parameterName = structureField->name().toStdString();
			parameterName = boost::to_lower_copy(parameterName.substr(0,1)) + parameterName.substr(1);
			EnumTypeField->parameterName(parameterName);

			// added variable type
			// added smartpointer flag
			// added number flag
			// added boolean flag
			// added byte flag
			bool smartpointer = false;
			bool number = false;
			bool boolean = false;
			bool byte = false;
			std::string variableType = getVariableType(
				structureField,
				informationModel,
				smartpointer,
				number,
				boolean,
				byte
			);
			if (variableType == "") {
				Log(Error, "variable type unknown in StructureDefinition")
					.parameter("DataTypeNodeId", dataTypeNodeId)
					.parameter("VariableTypeNodeId", structureField->dataType());
				return false;
			}

			EnumTypeField->variableType(variableType);
			EnumTypeField->smartpointer(smartpointer);
			EnumTypeField->number(number);
			EnumTypeField->boolean(boolean);
			EnumTypeField->byte(byte);

			// added description
			EnumTypeField->description(structureField->description().text().toStdString());

			// added value rank flag
			if (structureField->valueRank() > -1) {
				EnumTypeField->array(true);
			}

			EnumTypeFieldVec_.push_back(EnumTypeField);
		}
#endif

		return true;
	}

	std::string
	NodeInfoEnumType::getVariableType(
		StructureField::SPtr& structureField,
		InformationModel::SPtr& informationModel
	)
	{
#if 0
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

				// set smartpointer flag
				if (typeNodeId.nodeIdType() == OpcUaBuildInType_OpcUaExtensionObject) {
					smartpointer = true;
					buildInType = buildInType + "::SPtr";
				}

				// set number flag
				if (OpcUaBuildInTypeClass::isNumber((OpcUaBuildInType)type) == true) {
					number = true;
				}

				// set boolean flag
				if (OpcUaBuildInTypeClass::isBoolean((OpcUaBuildInType)type) == true) {
					boolean = true;
				}

				// set byte flag
				if (OpcUaBuildInTypeClass::isByte((OpcUaBuildInType)type) == true) {
					byte = true;
				}

				return buildInType;
			}
		}
#endif

		// enum type possible
		// FIXME: todo

		// structure type possible
		// FIXME: todo

		return "";
	}

}
