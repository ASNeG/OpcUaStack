/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackServer/InformationModel/InformationModelManager.h"
#include "OpcUaStackServer/InformationModel/InformationModelAccess.h"
#include "OpcUaStackServer/AddressSpaceModel/DataTypeNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/ObjectNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/VariableNodeClass.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// AddNodeRule
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	AddNodeRule::AddNodeRule(void)
	: informationModel_()
	, nodeIdMode_(UniqueString)
	, displayPath_("")
	{
	}

	AddNodeRule::~AddNodeRule(void)
	{
	}

	void
	AddNodeRule::informationModel(InformationModel::SPtr& informationModel)
	{
		informationModel_ = informationModel;
	}

	void
	AddNodeRule::nodeIdMode(NodeIdMode nodeIdMode)
	{
		nodeIdMode_ = nodeIdMode;
	}

	AddNodeRule::NodeIdMode
	AddNodeRule::nodeIdMode(void)
	{
		return nodeIdMode_;
	}

	void
	AddNodeRule::displayName(OpcUaLocalizedText& displayName)
	{
		std::string text;
		displayName.text().value(text);
		displayPath_ = displayPath_ + "." + text;
	}

	OpcUaNodeId
	AddNodeRule::createUniqueNodeId(uint16_t namespaceIndex)
	{
		OpcUaNodeId nodeId;

		if (nodeIdMode_ == UniqueString) {
			InformationModelAccess ima(informationModel_);
			OpcUaNodeId nodeId = ima.createUniqueNodeId(displayPath_, namespaceIndex);
		}
		else {
			InformationModelAccess ima(informationModel_);
			OpcUaNodeId nodeId = ima.createUniqueNodeId(namespaceIndex);
		}

		return nodeId;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// InformationModelManager
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	InformationModelManager::InformationModelManager(void)
	: informationModel_()
	{
	}

	InformationModelManager::InformationModelManager(InformationModel::SPtr informationModel)
	{
		informationModel_ = informationModel;
	}

	InformationModelManager::~InformationModelManager(void)
	{
	}

	void
	InformationModelManager::informationModel(InformationModel::SPtr informationModel)
	{
		informationModel_ = informationModel;
	}

	bool
	InformationModelManager::addObjectNode(
		AddNodeRule& addNodeRule,
		OpcUaNodeId& parentNodeId,
		OpcUaNodeId& nodeId,
		OpcUaLocalizedText& displayName,
		OpcUaQualifiedName& browseName,
		OpcUaNodeId& referenceNodeId,
		OpcUaNodeId& typeNodeId
	)
	{
		addNodeRule.informationModel(informationModel_);

		//
		// check, if node already exist
		//
		BaseNodeClass::SPtr baseNodeClass;
		baseNodeClass = informationModel_->find(nodeId);
		if (baseNodeClass.get() != NULL) {
			Log(Error, "node id already exist in information model")
				.parameter("NodeId", nodeId);
			return false;
		}

		//
		// get parent node class
		//
		BaseNodeClass::SPtr parentNodeClass;
		parentNodeClass = informationModel_->find(parentNodeId);
		if (parentNodeClass.get() == nullptr) {
			Log(Error, "parent node id not exist in information model")
				.parameter("ParentNodeId", parentNodeId);
			return false;
		}

		//
		// get type node class
		//
		BaseNodeClass::SPtr typeNodeClass;
		typeNodeClass = informationModel_->find(typeNodeId);
		if (typeNodeClass.get() == nullptr) {
			Log(Error, "type node id not exist in information model")
				.parameter("TypeNodeId", typeNodeId);
			return false;
		}

		//
		// get reference node class
		//
		BaseNodeClass::SPtr referenceNodeClass;
		referenceNodeClass = informationModel_->find(referenceNodeId);
		if (referenceNodeClass.get() == nullptr) {
			Log(Error, "reference node id not exist in information model")
				.parameter("ReferenceNodeId", referenceNodeId);
			return false;
		}

		//
		// create new object node and add the attributes
		//
		ObjectNodeClass::SPtr objectNodeClass = constructSPtr<ObjectNodeClass>();
		objectNodeClass->setNodeId(nodeId);
		objectNodeClass->setBrowseName(browseName);
		objectNodeClass->setDisplayName(displayName);

		OpcUaLocalizedText description;
		typeNodeClass->getDescription(description);
		objectNodeClass->setDescription(description);

		OpcUaUInt32 writeMask;
		typeNodeClass->getWriteMask(writeMask);
		objectNodeClass->setWriteMask(writeMask);

		OpcUaUInt32 userWriteMask;
		typeNodeClass->getWriteMask(userWriteMask);
		objectNodeClass->setWriteMask(userWriteMask);

		OpcUaByte eventNotifier;
		typeNodeClass->getEventNotifier(eventNotifier);
		objectNodeClass->setEventNotifier(eventNotifier);

		//
		// added childs
		//
		BaseNodeClass::SPtr tmpObjectNodeClass = objectNodeClass;
		bool success = addTypeChilds(addNodeRule, tmpObjectNodeClass, typeNodeClass);
		if (!success) {
			Log(Error, "create childs error")
				.parameter("NodeId", nodeId)
				.parameter("TypeNodeId", typeNodeId);
			return false;
		}

		//
		// added type definition
		//
		objectNodeClass->referenceItemMap().add(ReferenceType_HasTypeDefinition, true, typeNodeId);
		typeNodeClass->referenceItemMap().add(ReferenceType_HasTypeDefinition, false, nodeId);

		//
		// added reference to parent
		//
		parentNodeClass->referenceItemMap().add(referenceNodeId, true, nodeId);
		objectNodeClass->referenceItemMap().add(referenceNodeId, false, parentNodeId);

		//
		// check subtype reference
		//
		baseNodeClass = objectNodeClass;
		InformationModelAccess ima(informationModel_);
		BaseNodeClass::SPtr subtypeNodeClass;
		while (ima.getSubType(typeNodeClass, subtypeNodeClass)) {

			OpcUaNodeId nodeId;
			subtypeNodeClass->getNodeId(nodeId);

			bool success = addTypeChilds(addNodeRule, baseNodeClass, subtypeNodeClass);
			if (!success) {
				Log(Error, "create childs error")
					.parameter("NodeId", nodeId)
					.parameter("TypeNodeId", typeNodeId);
				return false;
			}
			typeNodeClass = subtypeNodeClass;
		}

		//
		// added node to information model
		//
		informationModel_->insert(objectNodeClass);

		return true;
	}

	bool
	InformationModelManager::addVariableNode(
		AddNodeRule& addNodeRule,
		OpcUaNodeId& parentNodeId,
		OpcUaNodeId& nodeId,
		OpcUaLocalizedText& displayName,
		OpcUaQualifiedName& browseName,
		OpcUaNodeId& referenceNodeId,
		OpcUaNodeId& typeNodeId
	)
	{
		addNodeRule.informationModel(informationModel_);

		//
		// check, if node already exist
		//
		BaseNodeClass::SPtr baseNodeClass;
		baseNodeClass = informationModel_->find(nodeId);
		if (baseNodeClass.get() != NULL) {
			Log(Error, "node id already exist in information model")
				.parameter("NodeId", nodeId);
			return false;
		}

		//
		// get parent node class
		//
		BaseNodeClass::SPtr parentNodeClass;
		parentNodeClass = informationModel_->find(parentNodeId);
		if (parentNodeClass.get() == nullptr) {
			Log(Error, "parent node id not exist in information model")
				.parameter("ParentNodeId", parentNodeId);
			return false;
		}

		//
		// get type node class
		//
		BaseNodeClass::SPtr typeNodeClass;
		typeNodeClass = informationModel_->find(typeNodeId);
		if (typeNodeClass.get() == nullptr) {
			Log(Error, "type node id not exist in information model")
				.parameter("TypeNodeId", typeNodeId);
			return false;
		}

		//
		// get reference node class
		//
		BaseNodeClass::SPtr referenceNodeClass;
		referenceNodeClass = informationModel_->find(referenceNodeId);
		if (referenceNodeClass.get() == nullptr) {
			Log(Error, "reference node id not exist in information model")
				.parameter("ReferenceNodeId", referenceNodeId);
			return false;
		}

		//
		// create new variable node and add the attributes
		//
		VariableNodeClass::SPtr variableNodeClass = constructSPtr<VariableNodeClass>();
		variableNodeClass->setNodeId(nodeId);
		variableNodeClass->setBrowseName(browseName);
		variableNodeClass->setDisplayName(displayName);

		OpcUaLocalizedText description;
		typeNodeClass->getDescription(description);
		variableNodeClass->setDescription(description);

		OpcUaUInt32 writeMask;
		typeNodeClass->getWriteMask(writeMask);
		variableNodeClass->setWriteMask(writeMask);

		OpcUaUInt32 userWriteMask;
		typeNodeClass->getWriteMask(userWriteMask);
		variableNodeClass->setWriteMask(userWriteMask);

		if (!typeNodeClass->isNullValue()) {
			OpcUaDataValue value;
			typeNodeClass->getValue(value);
			variableNodeClass->setValue(value);
		}

		if (!typeNodeClass->isNullArrayDimensions()) {
			OpcUaUInt32Array arrayDimensions;
			typeNodeClass->getArrayDimensions(arrayDimensions);
			variableNodeClass->setArrayDimensions(arrayDimensions);
		}

		OpcUaNodeId dataType;
		typeNodeClass->getDataType(dataType);
		variableNodeClass->setDataType(dataType);

		OpcUaInt32 valueRank;
		typeNodeClass->getValueRank(valueRank);
		variableNodeClass->setValueRank(valueRank);

		OpcUaByte accessLevel = 0;
		variableNodeClass->setAccessLevel(accessLevel);

		OpcUaByte userAccessLevel = 0;
		variableNodeClass->setUserAccessLevel(userAccessLevel);

		OpcUaBoolean historizing = false;;
		variableNodeClass->setHistorizing(historizing);

		//
		// added childs
		//
		BaseNodeClass::SPtr tmpVariableNodeClass = variableNodeClass;
		bool success = addTypeChilds(addNodeRule, tmpVariableNodeClass, typeNodeClass);
		if (!success) {
			Log(Error, "create childs error")
				.parameter("NodeId", nodeId)
				.parameter("TypeNodeId", typeNodeId);
			return false;
		}

		//
		// added type definition
		//
		variableNodeClass->referenceItemMap().add(ReferenceType_HasTypeDefinition, true, typeNodeId);
		typeNodeClass->referenceItemMap().add(ReferenceType_HasTypeDefinition, false, nodeId);

		//
		// added reference to parent
		//
		parentNodeClass->referenceItemMap().add(referenceNodeId, true, nodeId);
		variableNodeClass->referenceItemMap().add(referenceNodeId, false, parentNodeId);

		//
		// check subtype reference
		//
		baseNodeClass = variableNodeClass;
		InformationModelAccess ima(informationModel_);
		BaseNodeClass::SPtr subtypeNodeClass;
		while (ima.getSubType(typeNodeClass, subtypeNodeClass)) {

			OpcUaNodeId nodeId;
			subtypeNodeClass->getNodeId(nodeId);

			bool success = addTypeChilds(addNodeRule, baseNodeClass, subtypeNodeClass);
			if (!success) {
				Log(Error, "create childs error")
					.parameter("NodeId", nodeId)
					.parameter("TypeNodeId", typeNodeId);
				return false;
			}
			typeNodeClass = subtypeNodeClass;
		}

		//
		// added node to information model
		//
		informationModel_->insert(variableNodeClass);

		return true;
	}

	bool
	InformationModelManager::addTypeChilds(
		AddNodeRule& addNodeRule,
		BaseNodeClass::SPtr& parentNodeClass,
		BaseNodeClass::SPtr& cloneNodeClass
	)
	{
		BaseNodeClass::Vec childBaseNodeClassVec;
		std::vector<OpcUaNodeId> referenceTypeNodeIdVec;
		InformationModelAccess ima(informationModel_);
		ima.getChildHierarchically(cloneNodeClass, childBaseNodeClassVec, referenceTypeNodeIdVec);
		for (uint32_t idx=0; idx<childBaseNodeClassVec.size(); idx++) {
			BaseNodeClass::SPtr childBaseNodeClass = childBaseNodeClassVec[idx];

			NodeClassType nodeClassType;
			childBaseNodeClass->getNodeClass(nodeClassType);

			switch (nodeClassType)
			{
				case NodeClassType_Object:
				{
					bool success = addObjectNode(
						addNodeRule,
						parentNodeClass,
						childBaseNodeClass,
						referenceTypeNodeIdVec[idx]
					);
					if (!success) return false;
					break;
				}
				case NodeClassType_Variable:
				{
					bool success = addVariableNode(
						addNodeRule,
						parentNodeClass,
						childBaseNodeClass,
						referenceTypeNodeIdVec[idx]
					);
					if (!success) return false;
					break;
				}
				case NodeClassType_Method:
				{
					bool success = addMethodNode(
						addNodeRule,
						parentNodeClass,
						childBaseNodeClass,
						referenceTypeNodeIdVec[idx]
					);
					if (!success) return false;
					break;
				}
			}
		}

		return true;
	}

	bool
	InformationModelManager::addObjectNode(
		AddNodeRule& addNodeRule,
		BaseNodeClass::SPtr& parentNodeClass,
		BaseNodeClass::SPtr& cloneBaseNodeClass,
		OpcUaNodeId& referenceTypeNodeId
	)
	{
		//
		// clone node class
		//
		BaseNodeClass::SPtr objectNodeClass = cloneBaseNodeClass->clone();
		objectNodeClass->referenceItemMap().referenceItemMultiMap().clear();

		//
		// get parent node id
		//
		OpcUaNodeId parentNodeId;
		parentNodeClass->getNodeId(parentNodeId);

		//
		// create unique node id
		//
		OpcUaNodeId nodeId = addNodeRule.createUniqueNodeId(parentNodeId.namespaceIndex());
		objectNodeClass->setNodeId(nodeId);

		//
		// get type node id
		//
		OpcUaNodeId typeNodeId;
		InformationModelAccess ima(informationModel_);
		ima.getType(cloneBaseNodeClass, typeNodeId);

		//
		// get type node class
		//
		BaseNodeClass::SPtr typeNodeClass;
		typeNodeClass = informationModel_->find(typeNodeId);
		if (typeNodeClass.get() == nullptr) {
			Log(Error, "type node id not exist in information model")
				.parameter("TypeNodeId", typeNodeId);
			return false;
		}

		//
		// added childs
		//
		BaseNodeClass::SPtr tmpVariableNodeClass = objectNodeClass;
		bool success = addTypeChilds(addNodeRule, tmpVariableNodeClass, cloneBaseNodeClass);
		if (!success) {
			Log(Error, "create childs error")
				.parameter("NodeId", nodeId)
				.parameter("TypeNodeId", typeNodeId);
			return false;
		}

		//
		// added type definition
		//
		objectNodeClass->referenceItemMap().add(ReferenceType_HasTypeDefinition, true, typeNodeId);
		typeNodeClass->referenceItemMap().add(ReferenceType_HasTypeDefinition, false, nodeId);

		//
		// added reference to parent
		//
		parentNodeClass->referenceItemMap().add(referenceTypeNodeId, true, nodeId);
		objectNodeClass->referenceItemMap().add(referenceTypeNodeId, false, parentNodeId);

		//
		// added node to information model
		//
		informationModel_->insert(objectNodeClass);

		return true;
	}

	bool
	InformationModelManager::addVariableNode(
		AddNodeRule& addNodeRule,
		BaseNodeClass::SPtr& parentNodeClass,
		BaseNodeClass::SPtr& cloneBaseNodeClass,
		OpcUaNodeId& referenceTypeNodeId
	)
	{
		//
		// clone node class
		//
		BaseNodeClass::SPtr variableNodeClass = cloneBaseNodeClass->clone();
		variableNodeClass->referenceItemMap().referenceItemMultiMap().clear();

		//
		// get parent node id
		//
		OpcUaNodeId parentNodeId;
		parentNodeClass->getNodeId(parentNodeId);

		//
		// create unique node id
		//
		OpcUaNodeId nodeId = addNodeRule.createUniqueNodeId(parentNodeId.namespaceIndex());
		variableNodeClass->setNodeId(nodeId);

		//
		// get type node id
		//
		OpcUaNodeId typeNodeId;
		InformationModelAccess ima(informationModel_);
		ima.getType(cloneBaseNodeClass, typeNodeId);

		//
		// get type node class
		//
		BaseNodeClass::SPtr typeNodeClass;
		typeNodeClass = informationModel_->find(typeNodeId);
		if (typeNodeClass.get() == nullptr) {
			Log(Error, "type node id not exist in information model")
				.parameter("TypeNodeId", typeNodeId);
			return false;
		}

		//
		// added childs
		//
		BaseNodeClass::SPtr tmpVariableNodeClass = variableNodeClass;
		bool success = addTypeChilds(addNodeRule, tmpVariableNodeClass, cloneBaseNodeClass);
		if (!success) {
			Log(Error, "create childs error")
				.parameter("NodeId", nodeId)
				.parameter("TypeNodeId", typeNodeId);
			return false;
		}

		//
		// added type definition
		//
		variableNodeClass->referenceItemMap().add(ReferenceType_HasTypeDefinition, true, typeNodeId);
		typeNodeClass->referenceItemMap().add(ReferenceType_HasTypeDefinition, false, nodeId);

		//
		// added reference to parent
		//
		parentNodeClass->referenceItemMap().add(referenceTypeNodeId, true, nodeId);
		variableNodeClass->referenceItemMap().add(referenceTypeNodeId, false, parentNodeId);

		//
		// added node to information model
		//
		informationModel_->insert(variableNodeClass);

		return true;
	}

	bool
	InformationModelManager::addMethodNode(
		AddNodeRule& addNodeRule,
		BaseNodeClass::SPtr& parentNodeClass,
		BaseNodeClass::SPtr& cloneBaseNodeClass,
		OpcUaNodeId& referenceTypeNodeId
	)
	{
		//
		// clone node class
		//
		BaseNodeClass::SPtr methodNodeClass = cloneBaseNodeClass->clone();
		methodNodeClass->referenceItemMap().referenceItemMultiMap().clear();

		//
		// get parent node id
		//
		OpcUaNodeId parentNodeId;
		parentNodeClass->getNodeId(parentNodeId);

		//
		// create unique node id
		//

		OpcUaNodeId nodeId = addNodeRule.createUniqueNodeId(parentNodeId.namespaceIndex());
		methodNodeClass->setNodeId(nodeId);

		//
		// added childs
		//
		BaseNodeClass::SPtr tmpMethodNodeClass = methodNodeClass;
		bool success = addTypeChilds(addNodeRule, tmpMethodNodeClass, cloneBaseNodeClass);
		if (!success) {
			Log(Error, "create childs error")
				.parameter("NodeId", nodeId)
				.parameter("FunctionNodeId", "");
			return false;
		}

		//
		// added reference to parent
		//
		parentNodeClass->referenceItemMap().add(referenceTypeNodeId, true, nodeId);
		methodNodeClass->referenceItemMap().add(referenceTypeNodeId, false, parentNodeId);

		//
		// added node to information model
		//
		informationModel_->insert(methodNodeClass);

		return true;
	}

}

