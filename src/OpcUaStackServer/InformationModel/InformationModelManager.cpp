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

	AddNodeRule::AddNodeRule(AddNodeRule& addNodeRule)
	: informationModel_(addNodeRule.informationModel())
	, nodeIdMode_(addNodeRule.nodeIdMode())
	, displayPath_(addNodeRule.displayPath())
	{
	}

	AddNodeRule::AddNodeRule(AddNodeRule& addNodeRule, OpcUaLocalizedText& displayName)
	: informationModel_(addNodeRule.informationModel())
	, nodeIdMode_(addNodeRule.nodeIdMode())
	, displayPath_(addNodeRule.displayPath())
	{
		this->displayName(displayName);
	}

	AddNodeRule::~AddNodeRule(void)
	{
	}

	void
	AddNodeRule::informationModel(InformationModel::SPtr& informationModel)
	{
		informationModel_ = informationModel;
	}

	InformationModel::SPtr&
	AddNodeRule::informationModel(void)
	{
		return informationModel_;
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
	AddNodeRule::displayPath(const std::string& displayPath)
	{
		displayPath_ = displayPath;
	}

	void
	AddNodeRule::displayPath(OpcUaNodeId& nodeId)
	{
		uint16_t namespaceIndex;
		switch (nodeId.nodeIdType())
		{
			case OpcUaBuildInType_OpcUaUInt32:
			{
				uint32_t id;
				nodeId.get(id, namespaceIndex);

				std::stringstream ss;
				ss << id;

				displayPath_ = ss.str();
				break;
			}
			case OpcUaBuildInType_OpcUaString:
			{
				displayPath_ = nodeId.nodeId<OpcUaString::SPtr>()->value();
				break;
			}
			case OpcUaBuildInType_OpcUaGuid:
			{
				displayPath_ = *nodeId.nodeId<OpcUaGuid::SPtr>();
				break;
			}
			case OpcUaBuildInType_OpcUaByteString:
			{
				char *buf;
				OpcUaInt32 bufLen;
				nodeId.nodeId<OpcUaByteString::SPtr>()->value(&buf, &bufLen);
				displayPath_ = std::string(buf, bufLen);
				break;
			}
			default:
			{
				displayPath_ = "Unknown";
				break;
			}
		}

		std::cout << "DisplayPath=" << displayPath_ << std::endl;
	}

	std::string&
	AddNodeRule::displayPath(void)
	{
		return displayPath_;
	}

	void
	AddNodeRule::displayName(OpcUaLocalizedText& displayName)
	{
		std::string text = displayName.text().value();
		displayPath_ += "." + text;
	}

	OpcUaNodeId
	AddNodeRule::createUniqueNodeId(uint16_t namespaceIndex)
	{
		OpcUaNodeId nodeId;

		if (nodeIdMode_ == UniqueString) {
			InformationModelAccess ima(informationModel_);
			nodeId = ima.createUniqueNodeId(displayPath_, namespaceIndex);
		}
		else {
			InformationModelAccess ima(informationModel_);
			nodeId = ima.createUniqueNodeId(namespaceIndex);
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
		Log(Debug, "added object node")
			.parameter("NodeId", nodeId)
			.parameter("TypeNodeId", typeNodeId);

		addNodeRule.informationModel(informationModel_);

		//
		// check, if node already exist
		//
		BaseNodeClass::SPtr baseNodeClass;
		baseNodeClass = informationModel_->find(nodeId);
		if (baseNodeClass.get() != NULL) {
			Log(Error, "add object node error, because node id already exist in information model")
				.parameter("NodeId", nodeId);
			return false;
		}

		//
		// get parent node class
		//
		BaseNodeClass::SPtr parentNodeClass;
		parentNodeClass = informationModel_->find(parentNodeId);
		if (parentNodeClass.get() == nullptr) {
			Log(Error, "add object node error, because parent node id not exist in information model")
				.parameter("ParentNodeId", parentNodeId);
			return false;
		}

		//
		// get type node class
		//
		BaseNodeClass::SPtr typeNodeClass;
		typeNodeClass = informationModel_->find(typeNodeId);
		if (typeNodeClass.get() == nullptr) {
			Log(Error, "add object node error, because type node id not exist in information model")
				.parameter("TypeNodeId", typeNodeId);
			return false;
		}

		//
		// get reference node class
		//
		BaseNodeClass::SPtr referenceNodeClass;
		referenceNodeClass = informationModel_->find(referenceNodeId);
		if (referenceNodeClass.get() == nullptr) {
			Log(Error, "add object node error, because reference node id not exist in information model")
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
			Log(Error, "add object node error, because create childs error")
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
				Log(Error, "add object node error, because create childs error")
					.parameter("NodeId", nodeId)
					.parameter("TypeNodeId", typeNodeId);
				return false;
			}
			typeNodeClass = subtypeNodeClass;
		}

		//
		// added node to information model
		//
		if (!informationModel_->insert(objectNodeClass)) {
			Log(Error, "add object node error")
				.parameter("NodeId", nodeId);
			return false;
		}

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
		Log(Debug, "added variable node")
			.parameter("NodeId", nodeId)
			.parameter("TypeNodeId", typeNodeId);

		addNodeRule.informationModel(informationModel_);

		//
		// check, if node already exist
		//
		BaseNodeClass::SPtr baseNodeClass;
		baseNodeClass = informationModel_->find(nodeId);
		if (baseNodeClass.get() != NULL) {
			Log(Error, "add variable node error, because node id already exist in information model")
				.parameter("NodeId", nodeId);
			return false;
		}

		//
		// get parent node class
		//
		BaseNodeClass::SPtr parentNodeClass;
		parentNodeClass = informationModel_->find(parentNodeId);
		if (parentNodeClass.get() == nullptr) {
			Log(Error, "add variable node error, because parent node id not exist in information model")
				.parameter("ParentNodeId", parentNodeId);
			return false;
		}

		//
		// get type node class
		//
		BaseNodeClass::SPtr typeNodeClass;
		typeNodeClass = informationModel_->find(typeNodeId);
		if (typeNodeClass.get() == nullptr) {
			Log(Error, "add variable node error, because type node id not exist in information model")
				.parameter("TypeNodeId", typeNodeId);
			return false;
		}

		//
		// get reference node class
		//
		BaseNodeClass::SPtr referenceNodeClass;
		referenceNodeClass = informationModel_->find(referenceNodeId);
		if (referenceNodeClass.get() == nullptr) {
			Log(Error, "add variable node error, because reference node id not exist in information model")
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
			Log(Error, "add variable node error, because create childs error")
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
				Log(Error, "add variable node error, because create childs error")
					.parameter("NodeId", nodeId)
					.parameter("TypeNodeId", typeNodeId);
				return false;
			}
			typeNodeClass = subtypeNodeClass;
		}

		//
		// added node to information model
		//
		if (!informationModel_->insert(variableNodeClass)) {
			Log(Error, "add variable node error")
			    .parameter("NodeId", nodeId);
			return false;
		}

		return true;
	}

	bool
	InformationModelManager::addObjectTypeNode(
		OpcUaNodeId& parentNodeId,
		OpcUaNodeId& nodeId,
		OpcUaLocalizedText& displayName,
		OpcUaQualifiedName& browseName
	)
	{
		// FIXME: todo
		return true;
	}

	bool
	InformationModelManager::addVariableTypeNode(
		OpcUaNodeId& parentNodeId,
		OpcUaNodeId& nodeId,
		OpcUaLocalizedText& displayName,
		OpcUaQualifiedName& browseName
	)
	{
		// FIXME: todo
		return true;
	}

	bool
	InformationModelManager::addReferenceTypeNode(
		OpcUaNodeId& parentNodeId,
		OpcUaNodeId& nodeId,
		OpcUaLocalizedText& displayName,
		OpcUaQualifiedName& browseName
	)
	{
		// FIXME: todo
		return true;
	}

	bool
	InformationModelManager::delNode(
		OpcUaNodeId& nodeId
	)
	{
		//
		// get node class
		//
		BaseNodeClass::SPtr nodeClass;
		nodeClass = informationModel_->find(nodeId);
		if (nodeClass.get() == nullptr) {
			Log(Error, "remove node error, because node id not exist in information model")
				.parameter("NodeId", nodeId);
			return false;
		}

		// find all children of the node
		BaseNodeClass::Vec childNodeClassVec;
		InformationModelAccess ima(informationModel_);
		ima.getChildHierarchically(nodeClass, childNodeClassVec);

		for (uint32_t idx=0; idx<childNodeClassVec.size(); idx++) {
			BaseNodeClass::SPtr childNodeClass = childNodeClassVec[idx];

			OpcUaNodeId childNodeId;
			childNodeClass->getNodeId(childNodeId);
			if (!delNode(childNodeId)) {
				return false;
			}
		}

		// remove all references from node class
		ReferenceItemMultiMap::iterator it;
		for (
			it = nodeClass->referenceItemMap().referenceItemMultiMap().begin();
			it != nodeClass->referenceItemMap().referenceItemMultiMap().end();
			it++
		) {
			OpcUaNodeId referenceTypeId = it->first;
			ReferenceItem::SPtr referenceItem = it->second;
			OpcUaNodeId targetNodeId = referenceItem->nodeId_;

			delReference(nodeId, referenceTypeId, targetNodeId);
		}
		nodeClass->referenceItemMap().clear();

		// delete node
		if (!informationModel_->remove(nodeId)) {
			Log(Error, "remove node error, because node id not exist in information model")
				.parameter("NodeId", nodeId);
			return false;
		}

		return true;
	}

	bool
	InformationModelManager::delReference(
		OpcUaNodeId& sourceNodeId,
		OpcUaNodeId& referenceTypeNodeId,
		OpcUaNodeId& targetNodeId
	)
	{
		// FIXME: todo
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

			if (nodeClassType != NodeClassType_Object && nodeClassType != NodeClassType_Variable) {
				continue;
			}

			OpcUaNodeId childNodeId;
			OpcUaNodeId parentNodeId;
			OpcUaNodeId cloneNodeId;
			OpcUaLocalizedText childDisplayName;
			OpcUaLocalizedText parentDisplayName;
			OpcUaLocalizedText cloneDisplayName;

			childBaseNodeClass->getNodeId(childNodeId);
			parentNodeClass->getNodeId(parentNodeId);
			cloneNodeClass->getNodeId(cloneNodeId);
			childBaseNodeClass->getDisplayName(childDisplayName);
			parentNodeClass->getDisplayName(parentDisplayName);
			cloneNodeClass->getDisplayName(cloneDisplayName);

			Log(Debug, "added childs")
				.parameter("NodeClassType", (uint32_t)nodeClassType)
				.parameter("ChildNodeId", childNodeId)
				.parameter("ChildDisplayName", childDisplayName.text().value())
				.parameter("ParentNodeId", parentNodeId)
				.parameter("ParentDisplayName", parentDisplayName.text().value())
				.parameter("CloneNodeId", cloneNodeId)
				.parameter("CloneDisplayName", cloneDisplayName.text().value());

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
				default:
				{
					Log(Error, "invalid node class type found in add type childs")
						.parameter("NodeClassType", (uint32_t)nodeClassType)
						.parameter("ChildNodeId", childNodeId)
						.parameter("ChildDisplayName", childDisplayName.text().value())
						.parameter("ParentNodeId", parentNodeId)
						.parameter("ParentDisplayName", parentDisplayName.text().value())
						.parameter("CloneNodeId", cloneNodeId)
						.parameter("CloneDisplayName", cloneDisplayName.text().value());
					return false;
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
		OpcUaLocalizedText displayName;
		objectNodeClass->getDisplayName(displayName);
		AddNodeRule actAddNodeRule(addNodeRule, displayName);


		OpcUaNodeId nodeId = actAddNodeRule.createUniqueNodeId(parentNodeId.namespaceIndex());
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
			Log(Error, "add object node error, because type node id not exist in information model")
				.parameter("TypeNodeId", typeNodeId);
			return false;
		}

		//
		// added childs
		//
		BaseNodeClass::SPtr tmpVariableNodeClass = objectNodeClass;
		bool success = addTypeChilds(actAddNodeRule, tmpVariableNodeClass, cloneBaseNodeClass);
		if (!success) {
			Log(Error, "add object node error, because create childs error")
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
		if (!informationModel_->insert(objectNodeClass)) {
			Log(Error, "add object node error")
				.parameter("NodeId", nodeId);
			return false;
		}
		Log(Debug, "add object node success")
			.parameter("NodeId", nodeId);

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
		OpcUaLocalizedText displayName;
		variableNodeClass->getDisplayName(displayName);
		AddNodeRule actAddNodeRule(addNodeRule, displayName);

		OpcUaNodeId nodeId = actAddNodeRule.createUniqueNodeId(parentNodeId.namespaceIndex());
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
			Log(Error, "add variable node error, because type node id not exist in information model")
				.parameter("TypeNodeId", typeNodeId);
			return false;
		}

		//
		// added childs
		//
		BaseNodeClass::SPtr tmpVariableNodeClass = variableNodeClass;
		bool success = addTypeChilds(actAddNodeRule, tmpVariableNodeClass, cloneBaseNodeClass);
		if (!success) {
			Log(Error, "add variable node error, because create childs error")
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
		if (!informationModel_->insert(variableNodeClass)) {
			Log(Error, "add variable node error")
				.parameter("NodeId", nodeId);
			return false;
		}
		Log(Debug, "add variable node success")
			.parameter("NodeId", nodeId);

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
		OpcUaLocalizedText displayName;
		methodNodeClass->getDisplayName(displayName);
		AddNodeRule actAddNodeRule(addNodeRule, displayName);

		OpcUaNodeId nodeId = actAddNodeRule.createUniqueNodeId(parentNodeId.namespaceIndex());
		methodNodeClass->setNodeId(nodeId);

		//
		// added childs
		//
		BaseNodeClass::SPtr tmpMethodNodeClass = methodNodeClass;
		bool success = addTypeChilds(actAddNodeRule, tmpMethodNodeClass, cloneBaseNodeClass);
		if (!success) {
			Log(Error, "add method node error, because create childs error")
				.parameter("NodeId", nodeId);
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
		if (!informationModel_->insert(methodNodeClass)) {
			Log(Error, "add method node error")
				.parameter("NodeId", nodeId);
			return false;
		}
		Log(Debug, "add method node success")
			.parameter("NodeId", nodeId);

		return true;
	}

}

