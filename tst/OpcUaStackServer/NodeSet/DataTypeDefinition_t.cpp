#include "unittest.h"

#include "OpcUaStackCore/Base/ConfigXml.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackServer/NodeSet/DataTypeDefinition.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackServer;

BOOST_AUTO_TEST_SUITE(DataTypeDefinition_)

BOOST_AUTO_TEST_CASE(DataTypeDefinition_)
{
	std::cout << "DataTypeDefinition_t" << std::endl;
}


BOOST_AUTO_TEST_CASE(DataTypeDefinition_read_Enum_Simple)
{
	bool success;

	// read opc ua nodeset
	ConfigXml configXml;
    success = configXml.parse("../tst/data/DataTypeDefinition.Enum.Simple.xml");
    BOOST_REQUIRE(success == true);

    // decode simple enum type
    DataTypeDefinition::SPtr definition = constructSPtr<DataTypeDefinition>();
    definition->dataSubType(Enumeration);
    success = definition->decode(configXml.ptree().get_child("Definition"));

    BOOST_REQUIRE(success == true);
    BOOST_REQUIRE(definition->name() == OpcUaQualifiedName("EnumSimpleType",1));
    BOOST_REQUIRE(definition->dataFields().size() == 3);
    BOOST_REQUIRE(definition->dataFields()[0]->name().value() == "Enum1");
    BOOST_REQUIRE(definition->dataFields()[1]->name().value() == "Enum2");
    BOOST_REQUIRE(definition->dataFields()[2]->name().value() == "Enum3");
    BOOST_REQUIRE(definition->dataFields()[0]->value() == 0);
    BOOST_REQUIRE(definition->dataFields()[1]->value() == 1);
    BOOST_REQUIRE(definition->dataFields()[2]->value() == 2);
}

BOOST_AUTO_TEST_CASE(DataTypeDefinition_write_Enum_Simple)
{
	bool success;
	DataTypeDefinition::SPtr definition;
	DataTypeField::SPtr field;
	OpcUaQualifiedName dataTypeName;
	OpcUaString fieldName;

	//
	// create simple enumeration
	//
	definition = constructSPtr<DataTypeDefinition>();
	definition->dataSubType(Enumeration);
	dataTypeName.set("EnumSimpleType",1);
	definition->name(dataTypeName);

	field = constructSPtr<DataTypeField>();
	fieldName.value("Enum1");
	field->name(fieldName);
	field->value(0);
	definition->dataField(field);

	field = constructSPtr<DataTypeField>();
	fieldName.value("Enum2");
	field->name(fieldName);
	field->value(1);
	definition->dataField(field);

	field = constructSPtr<DataTypeField>();
	fieldName.value("Enum3");
	field->name(fieldName);
	field->value(2);
	definition->dataField(field);

	// encode and write eimple enum to file
	ConfigXml configXmlWrite;
	success = definition->encode(configXmlWrite.ptree());
	BOOST_REQUIRE(success == true);

	success = configXmlWrite.write("test.xml");
	BOOST_REQUIRE(success == true);

	//
	// read opc ua nodeset
	//
	ConfigXml configXmlRead;
    success = configXmlRead.parse("test.xml");
    BOOST_REQUIRE(success == true);

    // decode simple enum type
    definition = constructSPtr<DataTypeDefinition>();
    definition->dataSubType(Enumeration);
    success = definition->decode(configXmlRead.ptree().get_child("Definition"));

    BOOST_REQUIRE(success == true);
    BOOST_REQUIRE(definition->name() == OpcUaQualifiedName("EnumSimpleType",1));
    BOOST_REQUIRE(definition->dataFields().size() == 3);
    BOOST_REQUIRE(definition->dataFields()[0]->name().value() == "Enum1");
    BOOST_REQUIRE(definition->dataFields()[1]->name().value() == "Enum2");
    BOOST_REQUIRE(definition->dataFields()[2]->name().value() == "Enum3");
    BOOST_REQUIRE(definition->dataFields()[0]->value() == 0);
    BOOST_REQUIRE(definition->dataFields()[1]->value() == 1);
    BOOST_REQUIRE(definition->dataFields()[2]->value() == 2);

}


#if 0
BOOST_AUTO_TEST_CASE(DataTypeDefinition_NodeSet_Decode_Endode)
{
	bool success;

	// read opc ua nodeset
	ConfigXml configXml;
    success = configXml.parse("../tst/data/opc.ua.roby.xml");
    BOOST_REQUIRE(success == true);

    NodeSetXmlParser nodeSetXmlParser;
    success = nodeSetXmlParser.decode(configXml.ptree());
    BOOST_REQUIRE(success == true);

    NodeSetNamespace& nodeSetNamespace = nodeSetXmlParser.nodeSetNamespace();
    NamespaceVec& namespaceVec = nodeSetNamespace.localNamespaceVec();
    NamespaceVec::iterator it;

    for (it = namespaceVec.begin(); it != namespaceVec.end(); it++) {
        uint16_t namespaceIndex = nodeSetNamespace.mapToGlobalNamespaceIndex(*it);

        std::cout << "NamespaceUri: " << *it << std::endl;
        std::cout << "mapToGlobalNamespaceIndex: " << namespaceIndex << std::endl;
    }

	InformationModel::SPtr informationModel = constructSPtr<InformationModel>();
	success = InformationModelNodeSet::initial(informationModel, nodeSetXmlParser);
	BOOST_REQUIRE(success == true);

	informationModel->checkForwardReferences();

	// get parent node
	OpcUaNodeId nodeId;
	nodeId.set(31556, 1);
	OpcUaStackServer::BaseNodeClass::SPtr parentNodeSPtr = informationModel->find(nodeId);
	BOOST_REQUIRE(parentNodeSPtr.get() != nullptr);


    OpcUaStackServer::VariableNodeClass::SPtr variableSPtr = constructSPtr<OpcUaStackServer::VariableNodeClass>();

    OpcUaNodeId varNodeId;
    OpcUaNodeId dataTypeNodeId;
    OpcUaNodeId modellingRuleMandatoryNodeId;
    OpcUaNodeId typeDefinitionNodeId;
    OpcUaNodeId parentReferenceTypeNodeId;

    varNodeId.set(31558, 1);
    dataTypeNodeId.set(256, 0);
    modellingRuleMandatoryNodeId.set(OpcUaId_ModellingRule_Mandatory, 0);
    typeDefinitionNodeId.set(68, 0);
    parentReferenceTypeNodeId.set(79, 0);

    OpcUaQualifiedName browseName("variable from roby", 1);
    OpcUaLocalizedText displayName("", "variable from roby");

    OpcUaStackServer::BaseNodeClass::SPtr foundNodeSPtr = informationModel->find(varNodeId);
    BOOST_REQUIRE(foundNodeSPtr.get() == nullptr);

    variableSPtr->setNodeId(varNodeId);
    variableSPtr->setBrowseName(browseName);
    variableSPtr->setDisplayName(displayName);

    OpcUaUInt32 writeMask = 0;
    variableSPtr->setWriteMask(writeMask);

    OpcUaUInt32 userWriteMask = 0;
    variableSPtr->setUserWriteMask(userWriteMask);

    variableSPtr->setDataType(dataTypeNodeId);

/*
      {
          OpcUaDataValue dataValue;
          dataValue.statusCode(BadNoData);
          variableSPtr->setValue(dataValue);
      }
*/


    OpcUaInt32 valueRank = 0;
    variableSPtr->setValueRank(valueRank);

    OpcUaByte accessLevel = 1;
    variableSPtr->setAccessLevel(accessLevel);

    OpcUaByte userAccessLevel = 1;
    variableSPtr->setUserAccessLevel(userAccessLevel);

    OpcUaBoolean historizing = false;
    variableSPtr->setHistorizing(historizing);

    variableSPtr->referenceItemMap().add(OpcUaStackServer::ReferenceType_HasTypeDefinition, true, typeDefinitionNodeId);
    variableSPtr->referenceItemMap().add(OpcUaStackServer::ReferenceType_HasModellingRule, true, modellingRuleMandatoryNodeId);

    {
        OpcUaStackServer::ReferenceItem::SPtr referenceItem = constructSPtr<OpcUaStackServer::ReferenceItem>();
        referenceItem->isForward_ = false;
        referenceItem->nodeId_ = parentNodeSPtr->nodeId().data();
        variableSPtr->referenceItemMap().add(parentReferenceTypeNodeId, referenceItem);
    }

    {
        OpcUaStackServer::ReferenceItem::SPtr referenceItem = constructSPtr<OpcUaStackServer::ReferenceItem>();
        referenceItem->isForward_ = true;
        referenceItem->nodeId_ = varNodeId;
        parentNodeSPtr->referenceItemMap().add(parentReferenceTypeNodeId, referenceItem);
    }

    success = informationModel->insert(variableSPtr);
    BOOST_REQUIRE(success == true);

    foundNodeSPtr = informationModel->find(varNodeId);
    BOOST_REQUIRE(foundNodeSPtr.get() != nullptr);


	// write nodes from information model into node set file
	NodeSetXmlParser nodeSetXmlParserWrite;

	namespaceVec.clear();
	namespaceVec.push_back("http://yourorganisation.org/Namespace/");
	success = InformationModelNodeSet::initial(nodeSetXmlParserWrite, informationModel, namespaceVec);
	BOOST_REQUIRE(success == true);

	ConfigXml configXmlWrite;
	success = nodeSetXmlParserWrite.encode(configXmlWrite.ptree());
	BOOST_REQUIRE(success == true);

	success = configXmlWrite.write("../tst/data/opc.ua.roby_save.xml");
	BOOST_REQUIRE(success == true);


    nodeSetXmlParser.nodeSetNamespace().clearGlobal();
}

BOOST_AUTO_TEST_CASE(DataTypeDefinition_New_Node_And_New_Namespace)
{
	OpcUaNodeId nodeId;
	bool success;

	// read opc ua nodeset
	ConfigXml configXmlRead1;
	success = configXmlRead1.read("../tst/data/Opc.Ua.NodeSet.xml");
	BOOST_REQUIRE(success == true);

	NodeSetXmlParser nodeSetXmlParserRead1;
	success = nodeSetXmlParserRead1.decode(configXmlRead1.ptree());
	BOOST_REQUIRE(success == true);

	InformationModel::SPtr informationModelRead1 = constructSPtr<InformationModel>();
	success = InformationModelNodeSet::initial(informationModelRead1, nodeSetXmlParserRead1);
	BOOST_REQUIRE(success == true);

	informationModelRead1->checkForwardReferences();

	// add new namespace to nodeset
	NodeSetNamespace nodeSetNamespace;
	uint32_t namespaceIndex = nodeSetNamespace.addNewGlobalNamespace("http://yourorganisation.org/Opc.Ua.Raspberry/");

	// create a new node
	for (uint32_t idx=0; idx<10; idx++) {

		BaseNodeClass::SPtr baseNodeClass;

		OpcUaNodeId rootNodeId;
		BaseNodeClass::SPtr rootNodeClass;
		rootNodeId.set(OpcUaId_RootFolder);
		rootNodeClass = informationModelRead1->find(rootNodeId);

		OpcUaNodeId nodeId;
		std::stringstream nodeName;
		nodeName << "MyVariable" << idx;

		baseNodeClass = constructSPtr<VariableNodeClass>();
		nodeId.set(nodeName.str(), namespaceIndex);
		baseNodeClass->setNodeId(nodeId);

		OpcUaUInt32Array arrayDimensions;
		arrayDimensions.resize(2);
		arrayDimensions.set(0, (uint32_t)1);
		arrayDimensions.set(1, (uint32_t)2);
		baseNodeClass->setArrayDimensions(arrayDimensions);

		baseNodeClass->referenceItemMap().add(ReferenceType_HasComponent, false, rootNodeId);
		rootNodeClass->referenceItemMap().add(ReferenceType_HasComponent, true, nodeId);
		informationModelRead1->insert(baseNodeClass);
	}

	// write nodes from information model into node set file
	NodeSetXmlParser nodeSetXmlParserWrite;
	NamespaceVec namespaceVec;

	namespaceVec.push_back("http://yourorganisation.org/Opc.Ua.Raspberry/");
	success = InformationModelNodeSet::initial(nodeSetXmlParserWrite, informationModelRead1, namespaceVec);
	BOOST_REQUIRE(success == true);

	ConfigXml configXmlWrite;
	success = nodeSetXmlParserWrite.encode(configXmlWrite.ptree());
	BOOST_REQUIRE(success == true);

	success = configXmlWrite.write("test-nodeset-new-node.xml");
	BOOST_REQUIRE(success == true);

	nodeSetXmlParserWrite.nodeSetNamespace().clearGlobal();
}

BOOST_AUTO_TEST_CASE(DataTypeDefinition_MergeNamespace_with_parent_node)
{
	bool success;

	// read opc ua nodeset
	ConfigXml configXmlRead1;
	success = configXmlRead1.read("../tst/data/Opc.Ua.NodeSet.xml");
	BOOST_REQUIRE(success == true);

	NodeSetXmlParser nodeSetXmlParserRead1;
	success = nodeSetXmlParserRead1.decode(configXmlRead1.ptree());
	BOOST_REQUIRE(success == true);

	InformationModel::SPtr informationModelRead1 = constructSPtr<InformationModel>();
	success = InformationModelNodeSet::initial(informationModelRead1, nodeSetXmlParserRead1);
	BOOST_REQUIRE(success == true);

	informationModelRead1->checkForwardReferences();


	// read raspberry nodeset
	ConfigXml configXmlRead2;
	success = configXmlRead2.read("../tst/data/Opc.Ua.NodeSetRaspberry.xml");
	BOOST_REQUIRE(success == true);

	NodeSetXmlParser nodeSetXmlParserRead2;
	success = nodeSetXmlParserRead2.decode(configXmlRead2.ptree());
	BOOST_REQUIRE(success == true);

	InformationModel::SPtr informationModelRead2 = constructSPtr<InformationModel>();
	success = InformationModelNodeSet::initial(informationModelRead2, nodeSetXmlParserRead2);
	BOOST_REQUIRE(success == true);

	informationModelRead2->checkForwardReferences();

	// merge namespace 0 and namespace 1
	InformationModelAccess informationModelAccess;
	informationModelAccess.informationModel(informationModelRead1);
	success = informationModelAccess.add(informationModelRead2, 1);
	BOOST_REQUIRE(success == true);

	// write nodes from information model into node set file
	NodeSetXmlParser nodeSetXmlParserWrite;
	NamespaceVec namespaceVec;

	namespaceVec.push_back("http://yourorganisation.org/Opc.Ua.Raspberry/");
	success = InformationModelNodeSet::initial(nodeSetXmlParserWrite, informationModelRead1, namespaceVec);
	BOOST_REQUIRE(success == true);

	ConfigXml configXmlWrite;
	success = nodeSetXmlParserWrite.encode(configXmlWrite.ptree());
	BOOST_REQUIRE(success == true);

	success = configXmlWrite.write("test-nodeset-merge.xml");
	BOOST_REQUIRE(success == true);

	nodeSetXmlParserWrite.nodeSetNamespace().clearGlobal();
}

BOOST_AUTO_TEST_CASE(DataTypeDefinition_MergeNamespace_without_parent_node)
{
	bool success;

	// read opc ua nodeset
	ConfigXml configXmlRead1;
	success = configXmlRead1.read("../tst/data/Opc.Ua.NodeSet.xml");
	BOOST_REQUIRE(success == true);

	NodeSetXmlParser nodeSetXmlParserRead1;
	success = nodeSetXmlParserRead1.decode(configXmlRead1.ptree());
	BOOST_REQUIRE(success == true);

	InformationModel::SPtr informationModelRead1 = constructSPtr<InformationModel>();
	success = InformationModelNodeSet::initial(informationModelRead1, nodeSetXmlParserRead1);
	BOOST_REQUIRE(success == true);

	informationModelRead1->checkForwardReferences();


	// read raspberry nodeset
	ConfigXml configXmlRead2;
	success = configXmlRead2.read("../tst/data/Opc.Ua.NodeSetRaspberry1.xml");
	BOOST_REQUIRE(success == true);

	NodeSetXmlParser nodeSetXmlParserRead2;
	success = nodeSetXmlParserRead2.decode(configXmlRead2.ptree());
	BOOST_REQUIRE(success == true);

	InformationModel::SPtr informationModelRead2 = constructSPtr<InformationModel>();
	success = InformationModelNodeSet::initial(informationModelRead2, nodeSetXmlParserRead2);
	BOOST_REQUIRE(success == true);

	informationModelRead2->checkForwardReferences();

	// merge namespace 0 and namespace 1
	InformationModelAccess informationModelAccess;
	informationModelAccess.informationModel(informationModelRead1);
	success = informationModelAccess.add(informationModelRead2, 1);
	BOOST_REQUIRE(success == true);

	// write nodes from information model into node set file
	NodeSetXmlParser nodeSetXmlParserWrite;
	NamespaceVec namespaceVec;

	namespaceVec.push_back("http://yourorganisation.org/Opc.Ua.Raspberry/");
	namespaceVec.push_back("http://yourorganisation.org/Opc.Ua.Raspberry1/");
	success = InformationModelNodeSet::initial(nodeSetXmlParserWrite, informationModelRead1, namespaceVec);
	BOOST_REQUIRE(success == true);

	ConfigXml configXmlWrite;
	success = nodeSetXmlParserWrite.encode(configXmlWrite.ptree());
	BOOST_REQUIRE(success == true);

	success = configXmlWrite.write("test-nodeset-merge1.xml");
	BOOST_REQUIRE(success == true);

	nodeSetXmlParserWrite.nodeSetNamespace().clearGlobal();
}

BOOST_AUTO_TEST_CASE(DataTypeDefinition_Remove)
{
	bool success;

	// read raspberry nodeset
	ConfigXml configXmlRead;
	success = configXmlRead.read("../tst/data/Opc.Ua.NodeSetRaspberry.xml");
	BOOST_REQUIRE(success == true);

	NodeSetXmlParser nodeSetXmlParserRead;
	success = nodeSetXmlParserRead.decode(configXmlRead.ptree());
	BOOST_REQUIRE(success == true);

	InformationModel::SPtr informationModelRead = constructSPtr<InformationModel>();
	success = InformationModelNodeSet::initial(informationModelRead, nodeSetXmlParserRead);
	BOOST_REQUIRE(success == true);

	informationModelRead->checkForwardReferences();

	// remove node from information model (ns=1;s=Raspberry.BinaryOutput.Pin7)
	BaseNodeClass::SPtr baseNodeClass;
	InformationModelAccess informationModelAccess;
	informationModelAccess.informationModel(informationModelRead);
	OpcUaNodeId nodeId;
	nodeId.set("Raspberry.BinaryOutput.Pin7", 1);
	BOOST_REQUIRE(informationModelAccess.getNode(nodeId, baseNodeClass) == true);

	BOOST_REQUIRE(informationModelAccess.remove(nodeId) == true);

	BOOST_REQUIRE(informationModelAccess.getNode(nodeId, baseNodeClass) == false);

	// write nodes from information model into node set file
	NodeSetXmlParser nodeSetXmlParserWrite;
	NamespaceVec namespaceVec;

	namespaceVec.push_back("http://yourorganisation.org/Opc.Ua.Raspberry/");
	namespaceVec.push_back("http://yourorganisation.org/Opc.Ua.Raspberry1/");
	success = InformationModelNodeSet::initial(nodeSetXmlParserWrite, informationModelRead, namespaceVec);
	BOOST_REQUIRE(success == true);

	ConfigXml configXmlWrite;
	success = nodeSetXmlParserWrite.encode(configXmlWrite.ptree());
	BOOST_REQUIRE(success == true);

	success = configXmlWrite.write("test-nodeset2.xml");
	BOOST_REQUIRE(success == true);

	nodeSetXmlParserWrite.nodeSetNamespace().clearGlobal();
}

BOOST_AUTO_TEST_CASE(DataTypeDefinition_ParentChange)
{
	bool success;

	// read raspberry nodeset
	ConfigXml configXmlRead;
	success = configXmlRead.read("../tst/data/Opc.Ua.NodeSetRaspberry.xml");
	BOOST_REQUIRE(success == true);

	NodeSetXmlParser nodeSetXmlParserRead;
	success = nodeSetXmlParserRead.decode(configXmlRead.ptree());
	BOOST_REQUIRE(success == true);

	InformationModel::SPtr informationModelRead = constructSPtr<InformationModel>();
	success = InformationModelNodeSet::initial(informationModelRead, nodeSetXmlParserRead);
	BOOST_REQUIRE(success == true);

	informationModelRead->checkForwardReferences();

	// change parent (ns=1;s=Raspberry.BinaryOutput1) : (ns=1;s=Raspberry.BinaryOutput) -> (ns=1;s=Raspberry)
	BaseNodeClass::SPtr baseNodeClass;
	InformationModelAccess informationModelAccess;
	informationModelAccess.informationModel(informationModelRead);

	OpcUaNodeId nodeId;
	nodeId.set("Raspberry.BinaryOutput1", 1);

	OpcUaNodeId oldParentNodeId;
	oldParentNodeId.set("Raspberry.BinaryOutput", 1);

	OpcUaNodeId newParentNodeId;
	newParentNodeId.set("Raspberry", 1);

	BOOST_REQUIRE(informationModelAccess.getNode(nodeId, baseNodeClass) == true);
	BOOST_REQUIRE(informationModelAccess.parentChange(baseNodeClass, oldParentNodeId, newParentNodeId) == true);

	// write nodes from information model into node set file
	NodeSetXmlParser nodeSetXmlParserWrite;
	NamespaceVec namespaceVec;

	namespaceVec.push_back("http://yourorganisation.org/Opc.Ua.Raspberry/");
	namespaceVec.push_back("http://yourorganisation.org/Opc.Ua.Raspberry1/");
	success = InformationModelNodeSet::initial(nodeSetXmlParserWrite, informationModelRead, namespaceVec);
	BOOST_REQUIRE(success == true);

	ConfigXml configXmlWrite;
	success = nodeSetXmlParserWrite.encode(configXmlWrite.ptree());
	BOOST_REQUIRE(success == true);

	success = configXmlWrite.write("test-nodeset3.xml");
	BOOST_REQUIRE(success == true);

	nodeSetXmlParserWrite.nodeSetNamespace().clearGlobal();
}

#endif

BOOST_AUTO_TEST_SUITE_END()


