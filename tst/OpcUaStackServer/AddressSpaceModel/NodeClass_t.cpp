#include "unittest.h"
#include "OpcUaStackServer/AddressSpaceModel/VariableNodeClass.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackServer;

BOOST_AUTO_TEST_SUITE(NodeClass_)

BOOST_AUTO_TEST_CASE(NodeClass_)
{
	std::cout << "NodeClass_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(NodeClass_NodeId)
{
	VariableNodeClass::SPtr variableNodeClass = VariableNodeClass::construct();
	OpcUaNodeId nodeId1;
	OpcUaNodeId nodeId2;
	boost::optional<OpcUaNodeId&> nodeId3;

	BOOST_REQUIRE(variableNodeClass->isPartNodeId() == true);
	BOOST_REQUIRE(variableNodeClass->isNullNodeId() == true);
	BOOST_REQUIRE(variableNodeClass->getNodeId(nodeId1) == false);
	nodeId3 = variableNodeClass->getNodeId();
	BOOST_REQUIRE(!nodeId3 == true);

	nodeId1.namespaceIndex(1);
	nodeId1.nodeId(1234);
	BOOST_REQUIRE(variableNodeClass->setNodeId(nodeId1) == true);
	BOOST_REQUIRE(variableNodeClass->isNullNodeId() == false);
	BOOST_REQUIRE(variableNodeClass->getNodeId(nodeId2) == true);
	BOOST_REQUIRE(nodeId1 == nodeId2);
	nodeId3 = variableNodeClass->getNodeId();
	BOOST_REQUIRE(!nodeId3 == false);
	BOOST_REQUIRE(nodeId1 == *nodeId3);

	BOOST_REQUIRE(variableNodeClass->unsetNodeId() == true);
	BOOST_REQUIRE(variableNodeClass->isPartNodeId() == true);
	BOOST_REQUIRE(variableNodeClass->isNullNodeId() == true);
	BOOST_REQUIRE(variableNodeClass->getNodeId(nodeId1) == false);
	nodeId3 = variableNodeClass->getNodeId();
	BOOST_REQUIRE(!nodeId3 == true);
};

BOOST_AUTO_TEST_CASE(NodeClass_NodeClass)
{
	VariableNodeClass::SPtr variableNodeClass = VariableNodeClass::construct();
	NodeClassType nodeClass1;
	NodeClassType nodeClass2;
	boost::optional<NodeClassType&> nodeClass3;

	BOOST_REQUIRE(variableNodeClass->unsetNodeClass() == true);
	BOOST_REQUIRE(variableNodeClass->isPartNodeClass() == true);
	BOOST_REQUIRE(variableNodeClass->isNullNodeClass() == true);
	BOOST_REQUIRE(variableNodeClass->getNodeClass(nodeClass1) == false);
	nodeClass3 = variableNodeClass->getNodeClass();
	BOOST_REQUIRE(!nodeClass3 == true);

	nodeClass1 = NodeClassType_Object;
	BOOST_REQUIRE(variableNodeClass->setNodeClass(nodeClass1) == true);
	BOOST_REQUIRE(variableNodeClass->isNullNodeClass() == false);
	BOOST_REQUIRE(variableNodeClass->getNodeClass(nodeClass2) == true);
	BOOST_REQUIRE(nodeClass1 == nodeClass2);
	nodeClass3 = variableNodeClass->getNodeClass();
	BOOST_REQUIRE(!nodeClass3 == false);
	BOOST_REQUIRE(nodeClass1 == *nodeClass3);

	BOOST_REQUIRE(variableNodeClass->unsetNodeClass() == true);
	BOOST_REQUIRE(variableNodeClass->isPartNodeClass() == true);
	BOOST_REQUIRE(variableNodeClass->isNullNodeClass() == true);
	BOOST_REQUIRE(variableNodeClass->getNodeClass(nodeClass1) == false);
	nodeClass3 = variableNodeClass->getNodeClass();
	BOOST_REQUIRE(!nodeClass3 == true);
};

BOOST_AUTO_TEST_CASE(NodeClass_BrowseName)
{
	VariableNodeClass::SPtr variableNodeClass = VariableNodeClass::construct();
	OpcUaQualifiedName browseName1;
	OpcUaQualifiedName browseName2;
	boost::optional<OpcUaQualifiedName&> browseName3;

	BOOST_REQUIRE(variableNodeClass->isPartNodeId() == true);
	BOOST_REQUIRE(variableNodeClass->isNullNodeId() == true);
	BOOST_REQUIRE(variableNodeClass->getBrowseName(browseName1) == false);
	browseName3 = variableNodeClass->getBrowseName();
	BOOST_REQUIRE(!browseName3 == true);

	browseName1.namespaceIndex(1);
	browseName1.name("BrowseName");
	BOOST_REQUIRE(variableNodeClass->setBrowseName(browseName1) == true);
	BOOST_REQUIRE(variableNodeClass->isNullBrowseName() == false);
	BOOST_REQUIRE(variableNodeClass->getBrowseName(browseName2) == true);
	BOOST_REQUIRE(browseName1 == browseName2);
	browseName3 = variableNodeClass->getBrowseName();
	BOOST_REQUIRE(!browseName3 == false);
	BOOST_REQUIRE(browseName1 == *browseName3);

	BOOST_REQUIRE(variableNodeClass->unsetBrowseName() == true);
	BOOST_REQUIRE(variableNodeClass->isPartBrowseName() == true);
	BOOST_REQUIRE(variableNodeClass->isNullBrowseName() == true);
	BOOST_REQUIRE(variableNodeClass->getBrowseName(browseName1) == false);
	browseName3 = variableNodeClass->getBrowseName();
	BOOST_REQUIRE(!browseName3 == true);
};

BOOST_AUTO_TEST_SUITE_END()
