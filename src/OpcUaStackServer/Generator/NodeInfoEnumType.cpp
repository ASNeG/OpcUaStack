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

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	NodeInfoEnumType::NodeInfoEnumType(void)
	: NodeInfo()
	, enumDefinition_()
	, enumTypeFieldVec_()
	{
	}

	NodeInfoEnumType::~NodeInfoEnumType(void)
	{
	}

	EnumTypeField::Vec&
	NodeInfoEnumType::fields(void)
	{
		return enumTypeFieldVec_;
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

		if (dynamic_cast<EnumDefinitionExpand*>(definitionObject.get()) == nullptr) {
			Log(Error, "node definiton object is not from type EnumDefinition")
				.parameter("EnumTypeNodeId", enumTypeNodeId);
			return false;
		}
		enumDefinition_ = boost::static_pointer_cast<EnumDefinitionExpand>(definitionObject);

		// create field information
		uint32_t size = enumDefinition_->enumFields()->size();
		for (uint32_t idx=0; idx<size; idx++) {
			EnumField::SPtr enumField;
			enumDefinition_->enumFields()->get(idx, enumField);

			EnumTypeField::SPtr enumTypeField = boost::make_shared<EnumTypeField>();

			// added name
			enumTypeField->name(enumField->name().toStdString());

			// added value
			enumTypeField->value(enumField->value());

			// added description
			enumTypeField->description(enumField->description().text().toStdString());

			enumTypeFieldVec_.push_back(enumTypeField);
		}

		return true;
	}

}
