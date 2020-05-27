/*
   Copyright 2015-2020 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (atimin@gmail.com)
 */

#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackServer/InformationModel/InformationModelManager.h"
#include "OpcUaStackServer/InformationModel/InformationModelAccess.h"
#include "OpcUaStackServer/AddressSpaceModel/DataTypeNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/ObjectNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/MethodNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/VariableNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/ObjectTypeNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/VariableTypeNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/DataTypeNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/ReferenceTypeNodeClass.h"

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
	, delemiter_(".")
	, createOptionalPlaceholder_(false)
	{
	}

	AddNodeRule::AddNodeRule(AddNodeRule& addNodeRule)
	: informationModel_(addNodeRule.informationModel())
	, nodeIdMode_(addNodeRule.nodeIdMode())
	, displayPath_(addNodeRule.displayPath())
	, delemiter_(addNodeRule.delemiter())
	, createOptionalPlaceholder_(addNodeRule.createOptionalPlaceholder())
	{
	}

	AddNodeRule::AddNodeRule(AddNodeRule& addNodeRule, OpcUaLocalizedText& displayName)
	: informationModel_(addNodeRule.informationModel())
	, nodeIdMode_(addNodeRule.nodeIdMode())
	, displayPath_(addNodeRule.displayPath())
	, delemiter_(addNodeRule.delemiter())
	, createOptionalPlaceholder_(addNodeRule.createOptionalPlaceholder())
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
				displayPath_ = nodeId.nodeId<OpcUaGuid::SPtr>()->value();
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
		displayPath_ += delemiter_ + text;
	}

   	void
   	AddNodeRule::delemiter(const std::string& delemiter)
   	{
   		delemiter_ = delemiter;
   	}

   	std::string&
   	AddNodeRule::delemiter(void)
   	{
   		return delemiter_;
   	}

	void
	AddNodeRule::createOptionalPlaceholder(bool createOptionalPlaceholder)
	{
		createOptionalPlaceholder_ = createOptionalPlaceholder;
	}

	bool
	AddNodeRule::createOptionalPlaceholder(void)
	{
		return createOptionalPlaceholder_;
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

	InformationModelManager::InformationModelManager(InformationModel::SPtr& informationModel)
	{
		informationModel_ = informationModel;
	}

	InformationModelManager::~InformationModelManager(void)
	{
	}

	void
	InformationModelManager::informationModel(InformationModel::SPtr& informationModel)
	{
		informationModel_ = informationModel;
	}

	bool
	InformationModelManager::addNode(
		NodeClass::Enum nodeClassType,
		AddNodeRule& addNodeRule,
		OpcUaNodeId& parentNodeId,
		OpcUaNodeId& nodeId,
		OpcUaLocalizedText& displayName,
		OpcUaQualifiedName& browseName,
		OpcUaNodeId& referenceNodeId,
		OpcUaNodeId& typeNodeId
	)
	{
		switch (nodeClassType)
		{
			case NodeClass::EnumObject:
			{
				return addObjectNode(
					addNodeRule,
					parentNodeId,
					nodeId,
					displayName,
					browseName,
					referenceNodeId,
					typeNodeId
				);
				break;
			}
			case NodeClass::EnumVariable:
			{
				return addVariableNode(
					addNodeRule,
					parentNodeId,
					nodeId,
					displayName,
					browseName,
					referenceNodeId,
					typeNodeId
				);
				break;
			}
			case NodeClass::EnumMethod:
			{
				return addMethodNode(
					parentNodeId,
					nodeId,
					displayName,
					browseName
				);
				break;
			}
			case NodeClass::EnumObjectType:
			{
				return addObjectTypeNode(
					parentNodeId,
					nodeId,
					displayName,
					browseName
				);
				break;
			}
			case NodeClass::EnumVariableType:
			{
				return addVariableTypeNode(
					parentNodeId,
					nodeId,
					displayName,
					browseName
				);
				break;
			}
			case NodeClass::EnumDataType:
			{
				return addDataTypeNode(
					parentNodeId,
					nodeId,
					displayName,
					browseName
				);
				break;
			}
			case NodeClass::EnumReferenceType:
			{
				return addReferenceTypeNode(
					parentNodeId,
					nodeId,
					displayName,
					browseName
				);
				break;
			}
			default:
				Log(Error, "Node class type isn't supported").parameter("NodeClassType", nodeClassType);
		}

		return false;
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
		ObjectNodeClass::SPtr objectNodeClass = boost::make_shared<ObjectNodeClass>();
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
		VariableNodeClass::SPtr variableNodeClass = boost::make_shared<VariableNodeClass>();
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
	InformationModelManager::addMethodNode(
		OpcUaNodeId& parentNodeId,
		OpcUaNodeId& nodeId,
		OpcUaLocalizedText& displayName,
		OpcUaQualifiedName& browseName
	)
	{
		OpcUaLocalizedText description("en", "");
		bool isAbstract = true;

		//
		// find parent node class
		//
		BaseNodeClass::SPtr parentNodeClass = informationModel_->find(parentNodeId);
		if (parentNodeClass.get() == nullptr) {
			Log(Error, "add method node error, because parent node id not exist")
				.parameter("NodeId", nodeId)
				.parameter("ParentNodeId", parentNodeId);
			return false;
		}

    	//
    	// create method node
    	//
       	MethodNodeClass::SPtr methodNodeClass = boost::make_shared<MethodNodeClass>();
       	methodNodeClass->setNodeId(nodeId);
       	methodNodeClass->setBrowseName(browseName);
       	methodNodeClass->setDisplayName(displayName);
       	methodNodeClass->setDescription(description);
       	methodNodeClass->setWriteMask(0);
       	methodNodeClass->setUserWriteMask(0);
       	methodNodeClass->setIsAbstract(isAbstract);

    	//
    	// create subtype reference
    	//
       	methodNodeClass->referenceItemMap().add(ReferenceType_HasComponent, false, parentNodeId);
        parentNodeClass->referenceItemMap().add(ReferenceType_HasComponent, true, nodeId);

        //
        // insert node into information model
        //
        if (!informationModel_->insert(methodNodeClass)) {
			Log(Error, "add method node error")
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
		OpcUaLocalizedText description("en", "");
		bool isAbstract = true;

		//
		// find parent node class
		//
		BaseNodeClass::SPtr parentNodeClass = informationModel_->find(parentNodeId);
		if (parentNodeClass.get() == nullptr) {
			Log(Error, "add object type node error, because parent node id not exist")
				.parameter("NodeId", nodeId)
				.parameter("ParentNodeId", parentNodeId);
			return false;
		}

    	//
    	// create object type node
    	//
       	ObjectTypeNodeClass::SPtr objectTypeNodeClass = boost::make_shared<ObjectTypeNodeClass>();
       	objectTypeNodeClass->setNodeId(nodeId);
       	objectTypeNodeClass->setBrowseName(browseName);
       	objectTypeNodeClass->setDisplayName(displayName);
       	objectTypeNodeClass->setDescription(description);
       	objectTypeNodeClass->setWriteMask(0);
       	objectTypeNodeClass->setUserWriteMask(0);
    	objectTypeNodeClass->setIsAbstract(isAbstract);

    	//
    	// create subtype reference
    	//
        objectTypeNodeClass->referenceItemMap().add(ReferenceType_HasSubtype, false, parentNodeId);
        parentNodeClass->referenceItemMap().add(ReferenceType_HasSubtype, true, nodeId);

        //
        // insert node into information model
        //
        if (!informationModel_->insert(objectTypeNodeClass)) {
			Log(Error, "add object type node error")
				.parameter("NodeId", nodeId);
        	return false;
        }

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
		OpcUaLocalizedText description("en", "");
		bool isAbstract = true;
		OpcUaNodeId dataType(OpcUaId_Double);

		//
		// find parent node class
		//
		BaseNodeClass::SPtr parentNodeClass = informationModel_->find(parentNodeId);
		if (parentNodeClass.get() == nullptr) {
			Log(Error, "add variable type node error, because parent node id not exist")
				.parameter("NodeId", nodeId)
				.parameter("ParentNodeId", parentNodeId);
			return false;
		}

	    //
	    // create variable type node
	    //
	    VariableTypeNodeClass::SPtr variableTypeNodeClass = boost::make_shared<VariableTypeNodeClass>();
	    variableTypeNodeClass->setNodeId(nodeId);
	    variableTypeNodeClass->setBrowseName(browseName);
	    variableTypeNodeClass->setDisplayName(displayName);
	    variableTypeNodeClass->setDescription(description);
	    variableTypeNodeClass->setWriteMask(0);
	    variableTypeNodeClass->setUserWriteMask(0);
	    variableTypeNodeClass->setIsAbstract(isAbstract);
	    variableTypeNodeClass->setDataType(dataType);
	    //variableTypeNodeClass->setValueRank();

	   	//
	    // create subtype reference
	    //
	    variableTypeNodeClass->referenceItemMap().add(ReferenceType_HasSubtype, false, parentNodeId);
	    parentNodeClass->referenceItemMap().add(ReferenceType_HasSubtype, true, nodeId);

	    //
	    // insert node into information model
	    //
	    if (!informationModel_->insert(variableTypeNodeClass)) {
			Log(Error, "add variable type node error")
				.parameter("NodeId", nodeId);
	        return false;
	    }

		return true;
	}


	bool
	InformationModelManager::addDataTypeNode(
		OpcUaNodeId& parentNodeId,
		OpcUaNodeId& nodeId,
		OpcUaLocalizedText& displayName,
		OpcUaQualifiedName& browseName
	)
	{
		OpcUaLocalizedText description("en", "");
		bool isAbstract = true;

		//
		// find parent node class
		//
		BaseNodeClass::SPtr parentNodeClass = informationModel_->find(parentNodeId);
		if (parentNodeClass.get() == nullptr) {
			Log(Error, "add data type node error, because parent node id not exist")
				.parameter("NodeId", nodeId)
				.parameter("ParentNodeId", parentNodeId);
			return false;
		}

	    //
	    // create data type node
	    //
	    DataTypeNodeClass::SPtr dataTypeNodeClass = boost::make_shared<DataTypeNodeClass>();
	    dataTypeNodeClass->setNodeId(nodeId);
	    dataTypeNodeClass->setBrowseName(browseName);
	    dataTypeNodeClass->setDisplayName(displayName);
	    dataTypeNodeClass->setDescription(description);
	    dataTypeNodeClass->setWriteMask(0);
	    dataTypeNodeClass->setUserWriteMask(0);
	    dataTypeNodeClass->setIsAbstract(isAbstract);

	   	//
	    // create subtype reference
	    //
	    dataTypeNodeClass->referenceItemMap().add(ReferenceType_HasSubtype, false, parentNodeId);
	    parentNodeClass->referenceItemMap().add(ReferenceType_HasSubtype, true, nodeId);

	    //
	    // insert node into information model
	    //
	    if (!informationModel_->insert(dataTypeNodeClass)) {
			Log(Error, "add data type node error")
				.parameter("NodeId", nodeId);
	        return false;
	    }

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
		OpcUaLocalizedText description("en", "");
		bool isAbstract = true;
		bool symmetric = true;

		//
		// find parent node class
		//
		BaseNodeClass::SPtr parentNodeClass = informationModel_->find(parentNodeId);
		if (parentNodeClass.get() == nullptr) {
			Log(Error, "add reference type node error, because parent node id not exist")
				.parameter("NodeId", nodeId)
				.parameter("ParentNodeId", parentNodeId);
			return false;
		}

	    //
	    // create reference type node
	    //
	    ReferenceTypeNodeClass::SPtr referenceTypeNodeClass = boost::make_shared<ReferenceTypeNodeClass>();
	    referenceTypeNodeClass->setNodeId(nodeId);
	    referenceTypeNodeClass->setBrowseName(browseName);
	    referenceTypeNodeClass->setDisplayName(displayName);
	    referenceTypeNodeClass->setDescription(description);
	    referenceTypeNodeClass->setWriteMask(0);
	    referenceTypeNodeClass->setUserWriteMask(0);
	    referenceTypeNodeClass->setIsAbstract(isAbstract);
	    referenceTypeNodeClass->setSymmetric(symmetric);

	   	//
	    // create subtype reference
	    //
	    referenceTypeNodeClass->referenceItemMap().add(ReferenceType_HasSubtype, false, parentNodeId);
	    parentNodeClass->referenceItemMap().add(ReferenceType_HasSubtype, true, nodeId);

	    //
	    // insert node into information model
	    //
	    if (!informationModel_->insert(referenceTypeNodeClass)) {
			Log(Error, "add reference type node error")
				.parameter("NodeId", nodeId);
	        return false;
	    }

		return true;
	}

	bool
	InformationModelManager::delNode(
		const OpcUaNodeId& nodeId
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
		for (auto it = nodeClass->referenceItemMap().begin();
			it != nodeClass->referenceItemMap().end();
			++it
		) {

			ReferenceItem::SPtr referenceItem = *it;
			OpcUaNodeId targetNodeId = referenceItem->nodeId_;
			OpcUaNodeId referenceTypeId = referenceItem->typeId_;

			delReference(targetNodeId, referenceTypeId, nodeId);
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
		const OpcUaNodeId& sourceNodeId,
		const OpcUaNodeId& referenceTypeNodeId,
		const OpcUaNodeId& targetNodeId
	)
	{
		//
		// get node class
		//
		BaseNodeClass::SPtr nodeClass;
		nodeClass = informationModel_->find(sourceNodeId);
		if (nodeClass.get() == nullptr) {
			Log(Error, "remove node error, because source node id not exist in information model")
				.parameter("SourceNodeId", sourceNodeId)
				.parameter("ReferenceTypeNodeId", referenceTypeNodeId)
				.parameter("TargetNodeId", targetNodeId);
			return false;
		}

		// remove reference
		if (!nodeClass->referenceItemMap().remove(referenceTypeNodeId, targetNodeId)) {
			Log(Error, "remove node error, because reference not exist in information model")
				.parameter("SourceNodeId", sourceNodeId)
				.parameter("ReferenceTypeNodeId", referenceTypeNodeId)
				.parameter("TargetNodeId", targetNodeId);
			return false;
		}

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

			NodeClass::Enum nodeClassType;
			childBaseNodeClass->getNodeClass(nodeClassType);

			if (nodeClassType != NodeClass::EnumObject &&
				nodeClassType != NodeClass::EnumVariable &&
				nodeClassType != NodeClass::EnumMethod) {
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
				case NodeClass::EnumObject:
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
				case NodeClass::EnumVariable:
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
				case NodeClass::EnumMethod:
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
		// Optional Placeholder nodes are not inserted
		if (!addNodeRule.createOptionalPlaceholder() && isOptionalPlaceholder(cloneBaseNodeClass)) {
			return true;
		}

		//
		// clone node class
		//
		BaseNodeClass::SPtr objectNodeClass = cloneBaseNodeClass->clone();
		objectNodeClass->referenceItemMap().clear();

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
		// Optional Placeholder nodes are not inserted
		if (!addNodeRule.createOptionalPlaceholder() && isOptionalPlaceholder(cloneBaseNodeClass)) {
			return true;
		}

		//
		// clone node class
		//
		BaseNodeClass::SPtr variableNodeClass = cloneBaseNodeClass->clone();
		variableNodeClass->referenceItemMap().clear();

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
		// Optional Placeholder nodes are not inserted
		if (!addNodeRule.createOptionalPlaceholder() && isOptionalPlaceholder(cloneBaseNodeClass)) {
			return true;
		}

		//
		// clone node class
		//
		BaseNodeClass::SPtr methodNodeClass = cloneBaseNodeClass->clone();
		methodNodeClass->referenceItemMap().clear();

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

	bool
	InformationModelManager::isOptionalPlaceholder(
		BaseNodeClass::SPtr& nodeClass
	)
	{
		std::vector<OpcUaNodeId>::iterator it;
		std::vector<OpcUaNodeId> childNodeIdVec;
		OpcUaNodeId referenceTypeNodeId(OpcUaId_HasModellingRule);

		// get HasModelling rule
		InformationModelAccess ima(informationModel_);
		ima.getChildHierarchically(nodeClass, referenceTypeNodeId, childNodeIdVec);

		// check result
		for (it = childNodeIdVec.begin(); it != childNodeIdVec.end(); it++) {
			if (*it == OpcUaNodeId(OpcUaId_ModellingRule_OptionalPlaceholder)) return true;
		}

		return false;
	}


}

