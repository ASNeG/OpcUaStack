#include "unittest.h"

#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/ObjectNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/VariableTypeNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/VariableNodeClass.h"
#include "OpcUaStackServer/InformationModel/InformationModelAccess.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackServer;

BOOST_AUTO_TEST_SUITE(InformationModelAccess_)

BOOST_AUTO_TEST_CASE(InformationModelAccess_)
{
	std::cout << "InformationModelAccess_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(InformationModelAccess_getRootNode)
{
	bool success;
	OpcUaNodeId nodeId;
	BaseNodeClass::SPtr baseNodeClass;
	InformationModel::SPtr informationModel = InformationModel::construct();
	InformationModelAccess informationModelAccess;
	informationModelAccess.informationModel(informationModel);

	// root node do not exist
	success = informationModelAccess.getNode(nodeId, baseNodeClass);
	BOOST_REQUIRE(success == false);

	// add root node to information model
	baseNodeClass = ObjectNodeClass::construct();
	nodeId.set(OpcUaId_RootFolder);
	baseNodeClass->setNodeId(nodeId);
	informationModel->insert(baseNodeClass);

	// root node do exist
	success = informationModelAccess.getNode(nodeId, baseNodeClass);
	BOOST_REQUIRE(success == true);
	BOOST_REQUIRE(*baseNodeClass->getNodeId() == nodeId);
}

BOOST_AUTO_TEST_CASE(InformationModelAccess_getChild)
{
	bool success;
	OpcUaNodeId nodeId;
	BaseNodeClass::SPtr rootNodeClass;
	BaseNodeClass::SPtr typeNodeClass;
	BaseNodeClass::SPtr baseNodeClass;
	BaseNodeClass::Vec baseNodeClassVec;
	InformationModel::SPtr informationModel = InformationModel::construct();
	InformationModelAccess informationModelAccess;
	informationModelAccess.informationModel(informationModel);

	// add root node to information model
	rootNodeClass = ObjectNodeClass::construct();
	nodeId.set(OpcUaId_RootFolder);
	rootNodeClass->setNodeId(nodeId);
	informationModel->insert(rootNodeClass);

	// add variable type node to information model
	typeNodeClass = VariableTypeNodeClass::construct();
	nodeId.set("MyType");
	typeNodeClass->setNodeId(nodeId);
	informationModel->insert(typeNodeClass);

	// add variable nodes to information model
	for (uint32_t idx=0; idx<10; idx++) {
		std::stringstream nodeName;
		nodeName << "MyVariable" << idx;
		baseNodeClass = VariableNodeClass::construct();
		nodeId.set(nodeName.str());
		baseNodeClass->setNodeId(nodeId);
		baseNodeClass->referenceItemMap().add(ReferenceType_HasTypeDefinition, true, *typeNodeClass->getNodeId());
		baseNodeClass->referenceItemMap().add(ReferenceType_HasComponent, false, *rootNodeClass->getNodeId());
		rootNodeClass->referenceItemMap().add(ReferenceType_HasComponent, true, nodeId);
		informationModel->insert(baseNodeClass);
	}

	// get childs from root node
	success = informationModelAccess.getChild(rootNodeClass, baseNodeClassVec);
	BOOST_REQUIRE(success == true);
	BOOST_REQUIRE(baseNodeClassVec.size() == 10);

	success = informationModelAccess.getChildHierarchically(rootNodeClass, baseNodeClassVec);
	BOOST_REQUIRE(success == true);
	BOOST_REQUIRE(baseNodeClassVec.size() == 10);

	success = informationModelAccess.getChildNonHierarchically(rootNodeClass, baseNodeClassVec);
	BOOST_REQUIRE(success == true);
	BOOST_REQUIRE(baseNodeClassVec.size() == 0);

	// get childs from variable type node
	success = informationModelAccess.getChild(typeNodeClass, baseNodeClassVec);
	BOOST_REQUIRE(success == true);
	BOOST_REQUIRE(baseNodeClassVec.size() == 0);

	success = informationModelAccess.getChildHierarchically(typeNodeClass, baseNodeClassVec);
	BOOST_REQUIRE(success == true);
	BOOST_REQUIRE(baseNodeClassVec.size() == 0);

	success = informationModelAccess.getChildNonHierarchically(typeNodeClass, baseNodeClassVec);
	BOOST_REQUIRE(success == true);
	BOOST_REQUIRE(baseNodeClassVec.size() == 0);

	// get childs from variable n
	success = informationModelAccess.getChild(baseNodeClass, baseNodeClassVec);
	BOOST_REQUIRE(success == true);
	BOOST_REQUIRE(baseNodeClassVec.size() == 1);

	success = informationModelAccess.getChildHierarchically(baseNodeClass, baseNodeClassVec);
	BOOST_REQUIRE(success == true);
	BOOST_REQUIRE(baseNodeClassVec.size() == 0);

	success = informationModelAccess.getChildNonHierarchically(baseNodeClass, baseNodeClassVec);
	BOOST_REQUIRE(success == true);
	BOOST_REQUIRE(baseNodeClassVec.size() == 1);
}

BOOST_AUTO_TEST_CASE(InformationModelAccess_getParent)
{
	bool success;
	OpcUaNodeId nodeId;
	BaseNodeClass::SPtr rootNodeClass;
	BaseNodeClass::SPtr typeNodeClass;
	BaseNodeClass::SPtr baseNodeClass;
	BaseNodeClass::Vec baseNodeClassVec;
	InformationModel::SPtr informationModel = InformationModel::construct();
	InformationModelAccess informationModelAccess;
	informationModelAccess.informationModel(informationModel);

	// add root node to information model
	rootNodeClass = ObjectNodeClass::construct();
	nodeId.set(OpcUaId_RootFolder);
	rootNodeClass->setNodeId(nodeId);
	informationModel->insert(rootNodeClass);

	// add variable type node to information model
	typeNodeClass = VariableTypeNodeClass::construct();
	nodeId.set("MyType");
	typeNodeClass->setNodeId(nodeId);
	informationModel->insert(typeNodeClass);

	// add variable nodes to information model
	for (uint32_t idx=0; idx<10; idx++) {
		std::stringstream nodeName;
		nodeName << "MyVariable" << idx;
		baseNodeClass = VariableNodeClass::construct();
		nodeId.set(nodeName.str());
		baseNodeClass->setNodeId(nodeId);
		baseNodeClass->referenceItemMap().add(ReferenceType_HasTypeDefinition, true, *typeNodeClass->getNodeId());
		baseNodeClass->referenceItemMap().add(ReferenceType_HasComponent, false, *rootNodeClass->getNodeId());
		rootNodeClass->referenceItemMap().add(ReferenceType_HasComponent, true, nodeId);
		informationModel->insert(baseNodeClass);
	}

	// get parent from root node
	success = informationModelAccess.getParent(rootNodeClass, baseNodeClassVec);
	BOOST_REQUIRE(success == true);
	BOOST_REQUIRE(baseNodeClassVec.size() == 0);

	// get parent from variable type node
	success = informationModelAccess.getParent(typeNodeClass, baseNodeClassVec);
	BOOST_REQUIRE(success == true);
	BOOST_REQUIRE(baseNodeClassVec.size() == 0);

	// get parent from variable n
	success = informationModelAccess.getParent(baseNodeClass, baseNodeClassVec);
	BOOST_REQUIRE(success == true);
	BOOST_REQUIRE(baseNodeClassVec.size() == 1);
}

BOOST_AUTO_TEST_CASE(InformationModelAccess_getSurrogateParentNode)
{
	bool success;
	OpcUaNodeId nodeId;
	BaseNodeClass::SPtr objectsNodeClass;
	BaseNodeClass::SPtr surrogateParentNode1;
	BaseNodeClass::SPtr surrogateParentNode2;
	std::vector<OpcUaNodeId> referenceTypeNodeIdVec;
	ReferenceItem::Vec referenceItemVec;

	InformationModel::SPtr informationModel = InformationModel::construct();
	InformationModelAccess informationModelAccess;
	informationModelAccess.informationModel(informationModel);

	// add root node to information model
	objectsNodeClass = ObjectNodeClass::construct();
	nodeId.set(OpcUaId_ObjectsFolder);
	objectsNodeClass->setNodeId(nodeId);
	informationModel->insert(objectsNodeClass);

	// get surrogate parent
	BOOST_REQUIRE(informationModel->size() == 1);
	surrogateParentNode1 = informationModelAccess.getSurrogateParentNode();
	BOOST_REQUIRE(informationModel->size() == 2);

	surrogateParentNode2 = informationModelAccess.getSurrogateParentNode();
	BOOST_REQUIRE(informationModel->size() == 2);
	BOOST_REQUIRE(surrogateParentNode1.get() == surrogateParentNode1.get());

	success = informationModelAccess.getParentReference(surrogateParentNode1, referenceTypeNodeIdVec, referenceItemVec);
	BOOST_REQUIRE(success == true);
	BOOST_REQUIRE(referenceTypeNodeIdVec.size() == 1);
	BOOST_REQUIRE(referenceItemVec.size() == 1);
	BOOST_REQUIRE(referenceItemVec[0]->nodeId_ == nodeId);
}

BOOST_AUTO_TEST_SUITE_END()
