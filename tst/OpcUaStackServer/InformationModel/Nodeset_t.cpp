#include "unittest.h"

#include "OpcUaStackCore/Base/ConfigXml.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/ObjectTypeNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/ObjectNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/VariableTypeNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/VariableNodeClass.h"
#include "OpcUaStackServer/InformationModel/InformationModelAccess.h"
#include "OpcUaStackServer/InformationModel/InformationModelNodeSet.h"
#include "OpcUaStackServer/NodeSet/NodeSetXmlParser.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackServer;

BOOST_AUTO_TEST_SUITE(Nodeset_)

BOOST_AUTO_TEST_CASE(Nodeset_)
{
	std::cout << "Nodeset_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(Nodeset_NodeSet_Decode_Endode)
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

BOOST_AUTO_TEST_CASE(Nodeset_New_Node_And_New_Namespace)
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

BOOST_AUTO_TEST_CASE(Nodeset_MergeNamespace_with_parent_node)
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

BOOST_AUTO_TEST_CASE(Nodeset_MergeNamespace_without_parent_node)
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

BOOST_AUTO_TEST_CASE(Nodeset_Remove)
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

BOOST_AUTO_TEST_CASE(Nodeset_ParentChange)
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

BOOST_AUTO_TEST_SUITE_END()


