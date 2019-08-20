#include "unittest.h"

#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/ObjectTypeNodeClass.h"
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
	InformationModel::SPtr informationModel = boost::make_shared<InformationModel>();
	InformationModelAccess informationModelAccess;
	informationModelAccess.informationModel(informationModel);

	// root node do not exist
	success = informationModelAccess.getNode(nodeId, baseNodeClass);
	BOOST_REQUIRE(success == false);

	// add root node to information model
	baseNodeClass = boost::make_shared<ObjectNodeClass>();
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
	InformationModel::SPtr informationModel = boost::make_shared<InformationModel>();
	InformationModelAccess informationModelAccess;
	informationModelAccess.informationModel(informationModel);

	// add root node to information model
	rootNodeClass = boost::make_shared<ObjectNodeClass>();
	nodeId.set(OpcUaId_RootFolder);
	rootNodeClass->setNodeId(nodeId);
	informationModel->insert(rootNodeClass);

	// add variable type node to information model
	typeNodeClass = boost::make_shared<VariableTypeNodeClass>();
	nodeId.set("MyType");
	typeNodeClass->setNodeId(nodeId);
	informationModel->insert(typeNodeClass);

	// add variable nodes to information model
	for (uint32_t idx=0; idx<10; idx++) {
		std::stringstream nodeName;
		nodeName << "MyVariable" << idx;
		baseNodeClass = boost::make_shared<VariableNodeClass>();
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
	InformationModel::SPtr informationModel = boost::make_shared<InformationModel>();
	InformationModelAccess informationModelAccess;
	informationModelAccess.informationModel(informationModel);

	// add root node to information model
	rootNodeClass = boost::make_shared<ObjectNodeClass>();
	nodeId.set(OpcUaId_RootFolder);
	rootNodeClass->setNodeId(nodeId);
	informationModel->insert(rootNodeClass);

	// add variable type node to information model
	typeNodeClass = boost::make_shared<VariableTypeNodeClass>();
	nodeId.set("MyType");
	typeNodeClass->setNodeId(nodeId);
	informationModel->insert(typeNodeClass);

	// add variable nodes to information model
	for (uint32_t idx=0; idx<10; idx++) {
		std::stringstream nodeName;
		nodeName << "MyVariable" << idx;
		baseNodeClass = boost::make_shared<VariableNodeClass>();
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

	InformationModel::SPtr informationModel = boost::make_shared<InformationModel>();
	InformationModelAccess informationModelAccess;
	informationModelAccess.informationModel(informationModel);

	// add objects node to information model
	objectsNodeClass = boost::make_shared<ObjectNodeClass>();
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

BOOST_AUTO_TEST_CASE(InformationModelAccess_getType)
{
	bool success;
	OpcUaNodeId nodeId;
	OpcUaNodeId subTypeNodeId;
	OpcUaNodeId typeNodeId;
	BaseNodeClass::SPtr objectsNodeClass;
	BaseNodeClass::SPtr objectTypeNodeClass;
	BaseNodeClass::SPtr baseObjectTypeNodeClass;

	InformationModel::SPtr informationModel = boost::make_shared<InformationModel>();
	InformationModelAccess informationModelAccess;
	informationModelAccess.informationModel(informationModel);


	// add base object type node
	baseObjectTypeNodeClass = boost::make_shared<ObjectNodeClass>();
	subTypeNodeId.set(OpcUaId_BaseObjectType);
	baseObjectTypeNodeClass->setNodeId(subTypeNodeId);
	informationModel->insert(baseObjectTypeNodeClass);

	// add object type node
	objectTypeNodeClass = boost::make_shared<ObjectNodeClass>();
	typeNodeId.set(OpcUaId_ObjectTypesFolder);
	objectTypeNodeClass->setNodeId(typeNodeId);
	objectTypeNodeClass->referenceItemMap().add(ReferenceType_HasSubtype, false, subTypeNodeId);
	informationModel->insert(objectTypeNodeClass);

	// add objects node to information model
	objectsNodeClass = boost::make_shared<ObjectNodeClass>();
	nodeId.set(OpcUaId_ObjectsFolder);
	objectsNodeClass->setNodeId(nodeId);
	objectsNodeClass->referenceItemMap().add(ReferenceType_HasTypeDefinition, true, typeNodeId);
	informationModel->insert(objectsNodeClass);

	// get type information from objects node
	success = informationModelAccess.getType(objectsNodeClass, nodeId);
	BOOST_REQUIRE(success == true);
	BOOST_REQUIRE(nodeId == typeNodeId);
}

BOOST_AUTO_TEST_CASE(InformationModelAccess_getSubType)
{
	bool success;
	OpcUaNodeId nodeId;
	OpcUaNodeId subTypeNodeId;
	OpcUaNodeId typeNodeId;
	BaseNodeClass::SPtr objectsNodeClass;
	BaseNodeClass::SPtr objectTypeNodeClass;
	BaseNodeClass::SPtr baseObjectTypeNodeClass;

	InformationModel::SPtr informationModel = boost::make_shared<InformationModel>();
	InformationModelAccess informationModelAccess;
	informationModelAccess.informationModel(informationModel);


	// add base object type node
	baseObjectTypeNodeClass = boost::make_shared<ObjectNodeClass>();
	subTypeNodeId.set(OpcUaId_BaseObjectType);
	baseObjectTypeNodeClass->setNodeId(subTypeNodeId);
	informationModel->insert(baseObjectTypeNodeClass);

	// add object type node
	objectTypeNodeClass = boost::make_shared<ObjectNodeClass>();
	typeNodeId.set(OpcUaId_ObjectTypesFolder);
	objectTypeNodeClass->setNodeId(typeNodeId);
	objectTypeNodeClass->referenceItemMap().add(ReferenceType_HasSubtype, false, subTypeNodeId);
	informationModel->insert(objectTypeNodeClass);

	// add objects node to information model
	objectsNodeClass = boost::make_shared<ObjectNodeClass>();
	nodeId.set(OpcUaId_ObjectsFolder);
	objectsNodeClass->setNodeId(nodeId);
	objectsNodeClass->referenceItemMap().add(ReferenceType_HasTypeDefinition, true, typeNodeId);
	informationModel->insert(objectsNodeClass);

	// get sub type information from objects node
	success = informationModelAccess.getSubType(objectTypeNodeClass, nodeId);
	BOOST_REQUIRE(success == true);
	BOOST_REQUIRE(nodeId == subTypeNodeId);
}

BOOST_AUTO_TEST_CASE(InformationModelAccess_merge)
{
	bool success;
	OpcUaNodeId nodeId;
	OpcUaNodeId typeNodeId;
	OpcUaNodeId objectsNodeId;
	BaseNodeClass::SPtr objectsNodeClass;
	BaseNodeClass::SPtr baseNodeClass;

	InformationModel::SPtr informationModel1 = boost::make_shared<InformationModel>();
	InformationModelAccess informationModelAccess1;
	informationModelAccess1.informationModel(informationModel1);

	InformationModel::SPtr informationModel2 = boost::make_shared<InformationModel>();
	InformationModelAccess informationModelAccess2;
	informationModelAccess2.informationModel(informationModel2);

	// add object type node
	baseNodeClass = boost::make_shared<ObjectNodeClass>();
	objectsNodeId.set(OpcUaId_ObjectTypesFolder);
	baseNodeClass->setNodeId(objectsNodeId);
	informationModel2->insert(baseNodeClass);

	baseNodeClass = boost::make_shared<ObjectNodeClass>();
	objectsNodeId.set(OpcUaId_ObjectTypesFolder);
	baseNodeClass->setNodeId(objectsNodeId);
	informationModel1->insert(baseNodeClass);

	objectsNodeClass = boost::make_shared<ObjectNodeClass>();
	objectsNodeId.set(OpcUaId_ObjectsFolder);
	objectsNodeClass->setNodeId(objectsNodeId);
	informationModel2->insert(objectsNodeClass);

	objectsNodeClass = boost::make_shared<ObjectNodeClass>();
	objectsNodeId.set(OpcUaId_ObjectsFolder);
	objectsNodeClass->setNodeId(objectsNodeId);
	informationModel1->insert(objectsNodeClass);

	// add variable type node to information model 1
	baseNodeClass = boost::make_shared<VariableTypeNodeClass>();
	typeNodeId.set("MyType", 1);
	baseNodeClass->setNodeId(typeNodeId);
	baseNodeClass->referenceItemMap().add(ReferenceType_HasSubtype, false, objectsNodeId);
	informationModel1->insert(baseNodeClass);

	// add nodes to information model 1
	for (uint32_t idx=0; idx<20; idx++) {
		std::stringstream nodeName;
		nodeName << "MyVariable" << idx;
		baseNodeClass = boost::make_shared<VariableNodeClass>();
		nodeId.set(nodeName.str(), 1);
		baseNodeClass->setNodeId(nodeId);
		baseNodeClass->referenceItemMap().add(ReferenceType_HasTypeDefinition, true, typeNodeId);
		baseNodeClass->referenceItemMap().add(ReferenceType_HasComponent, false, objectsNodeId);
		objectsNodeClass->referenceItemMap().add(ReferenceType_HasComponent, true, nodeId);
		informationModel1->insert(baseNodeClass);
	}

	BOOST_REQUIRE(informationModel1->size() == 23);
	BOOST_REQUIRE(informationModel2->size() == 2);

	BOOST_REQUIRE(informationModelAccess2.containsNodeIds(informationModel1, 0) == true);
	BOOST_REQUIRE(informationModelAccess2.containsNodeIds(informationModel1, 1) == false);

	success = informationModelAccess2.add(informationModel1, 1);
	BOOST_REQUIRE(success == true);

	BOOST_REQUIRE(informationModel1->size() == 23);
	BOOST_REQUIRE(informationModel2->size() == 23);

	BOOST_REQUIRE(informationModelAccess2.containsNodeIds(informationModel1, 0) == true);
	BOOST_REQUIRE(informationModelAccess2.containsNodeIds(informationModel1, 1) == true);
}

BOOST_AUTO_TEST_CASE(InformationModelAccess_merge_with_surrogate_parent)
{
	bool success;
	OpcUaNodeId nodeId;
	OpcUaNodeId typeNodeId;
	OpcUaNodeId objectsNodeId;
	BaseNodeClass::SPtr objectsNodeClass;
	BaseNodeClass::SPtr baseNodeClass;

	InformationModel::SPtr informationModel1 = boost::make_shared<InformationModel>();
	InformationModelAccess informationModelAccess1;
	informationModelAccess1.informationModel(informationModel1);

	InformationModel::SPtr informationModel2 = boost::make_shared<InformationModel>();
	InformationModelAccess informationModelAccess2;
	informationModelAccess2.informationModel(informationModel2);

	// add object type node
	baseNodeClass = boost::make_shared<ObjectNodeClass>();
	objectsNodeId.set(OpcUaId_ObjectTypesFolder);
	baseNodeClass->setNodeId(objectsNodeId);
	informationModel2->insert(baseNodeClass);

	baseNodeClass = boost::make_shared<ObjectNodeClass>();
	objectsNodeId.set(OpcUaId_ObjectTypesFolder);
	baseNodeClass->setNodeId(objectsNodeId);
	informationModel1->insert(baseNodeClass);

	objectsNodeClass = boost::make_shared<ObjectNodeClass>();
	objectsNodeId.set(OpcUaId_ObjectsFolder);
	objectsNodeClass->setNodeId(objectsNodeId);
	informationModel2->insert(objectsNodeClass);

	objectsNodeClass = boost::make_shared<ObjectNodeClass>();
	objectsNodeId.set(OpcUaId_ObjectsFolder);
	objectsNodeClass->setNodeId(objectsNodeId);
	informationModel1->insert(objectsNodeClass);

	// add variable type node to information model 1
	baseNodeClass = boost::make_shared<VariableTypeNodeClass>();
	typeNodeId.set("MyType", 1);
	baseNodeClass->setNodeId(typeNodeId);
	baseNodeClass->referenceItemMap().add(ReferenceType_HasSubtype, false, objectsNodeId);
	informationModel1->insert(baseNodeClass);

	// add nodes to information model 1
	for (uint32_t idx=0; idx<20; idx++) {
		std::stringstream nodeName;
		nodeName << "MyVariable" << idx;
		baseNodeClass = boost::make_shared<VariableNodeClass>();
		nodeId.set(nodeName.str(), 1);
		baseNodeClass->setNodeId(nodeId);
		baseNodeClass->referenceItemMap().add(ReferenceType_HasTypeDefinition, true, typeNodeId);
		baseNodeClass->referenceItemMap().add(ReferenceType_HasComponent, false, objectsNodeId);
		objectsNodeClass->referenceItemMap().add(ReferenceType_HasComponent, true, nodeId);
		informationModel1->insert(baseNodeClass);
	}

	// add nodes to information model 1
	for (uint32_t idx=0; idx<20; idx++) {
		OpcUaNodeId ownNodeId;
		ownNodeId.set(33,33);

		std::stringstream nodeName;
		nodeName << "MyVariableWithoutParent" << idx;
		baseNodeClass = boost::make_shared<VariableNodeClass>();
		nodeId.set(nodeName.str(), 1);
		baseNodeClass->setNodeId(nodeId);
		baseNodeClass->referenceItemMap().add(ReferenceType_HasTypeDefinition, true, typeNodeId);
		baseNodeClass->referenceItemMap().add(ReferenceType_HasComponent, false, ownNodeId);
		informationModel1->insert(baseNodeClass);
	}

	BOOST_REQUIRE(informationModel1->size() == 43);
	BOOST_REQUIRE(informationModel2->size() == 2);

	BOOST_REQUIRE(informationModelAccess2.containsNodeIds(informationModel1, 0) == true);
	BOOST_REQUIRE(informationModelAccess2.containsNodeIds(informationModel1, 1) == false);

	success = informationModelAccess2.add(informationModel1, 1);
	BOOST_REQUIRE(success == true);

	BOOST_REQUIRE(informationModel1->size() == 43);
	BOOST_REQUIRE(informationModel2->size() == 44);

	BOOST_REQUIRE(informationModelAccess2.containsNodeIds(informationModel1, 0) == true);
	BOOST_REQUIRE(informationModelAccess2.containsNodeIds(informationModel1, 1) == true);
}

BOOST_AUTO_TEST_SUITE_END()
