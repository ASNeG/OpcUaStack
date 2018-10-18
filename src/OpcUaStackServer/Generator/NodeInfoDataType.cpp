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

#include "OpcUaStackServer/Generator/NodeInfoDataType.h"
#include "OpcUaStackServer/AddressSpaceModel/DataTypeNodeClass.h"

namespace OpcUaStackServer
{

	NodeInfoDataType::NodeInfoDataType(void)
	: NodeInfo()
	, structureDefinition_()
	{
	}

	NodeInfoDataType::~NodeInfoDataType(void)
	{
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

		return true;
	}

}
