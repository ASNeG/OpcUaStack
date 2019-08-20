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

BOOST_AUTO_TEST_CASE(Nodeset_clear)
{
	NodeSetNamespace nodeSetNamespace;

	nodeSetNamespace.clear();
	nodeSetNamespace.clearGlobal();
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

	InformationModel::SPtr informationModelRead1 = boost::make_shared<InformationModel>();
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

		baseNodeClass = boost::make_shared<VariableNodeClass>();
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

	InformationModel::SPtr informationModelRead1 = boost::make_shared<InformationModel>();
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

	InformationModel::SPtr informationModelRead2 = boost::make_shared<InformationModel>();
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

	InformationModel::SPtr informationModelRead1 = boost::make_shared<InformationModel>();
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

	InformationModel::SPtr informationModelRead2 = boost::make_shared<InformationModel>();
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

	InformationModel::SPtr informationModelRead = boost::make_shared<InformationModel>();
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

	InformationModel::SPtr informationModelRead = boost::make_shared<InformationModel>();
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


