/*
   Copyright 2019 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackServer/InformationModel/ObjectInstanceBuilder.h"
#include "OpcUaStackServer/InformationModel/InformationModelAccess.h"
#include "OpcUaStackServer/InformationModel/NamespaceArray.h"
#include "OpcUaStackServer/NodeSet/NodeSetNamespace.h"
#include "OpcUaStackServer/AddressSpaceModel/VariableTypeNodeClass.h"


using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	ObjectInstanceBuilder::ObjectInstanceBuilder(void)
	: informationModel_()
	, namespaceIndex_(0)
	, objectBase_()
	{
	}

	ObjectInstanceBuilder::~ObjectInstanceBuilder(void)
	{
	}

	OpcUaStatusCode
	ObjectInstanceBuilder::createObjectInstance(
		InformationModel::SPtr& informationModel,
		const std::string& namespaceName,
		const OpcUaLocalizedText& displayName,
		OpcUaNodeId& parentNodeId,
		OpcUaNodeId& referenceTypeNodeId,
		ObjectBase::SPtr& objectBase
	)
	{
		informationModel_ = informationModel;
		objectBase_ = objectBase;

		// get namespace index
		if (!getNamespaceIndex(namespaceName)) {
			Log(Error, "get namesapce index error")
				.parameter("NamespaceName", namespaceName);
			return BadInternalError;
		}

		// find object type namespace index from namespace name
		NodeSetNamespace nodeSetNamespace;
		uint16_t namespaceIndex = nodeSetNamespace.mapToGlobalNamespaceIndex(objectBase->objectTypeNamespaceName());
		if (namespaceIndex == 0xFFFF) {
			Log(Error, "object type namespace name do not exist")
				.parameter("NamespaceName", objectBase->objectTypeNamespaceName());
			return BadInternalError;
		}
		objectBase->objectTypeNodeId().namespaceIndex(namespaceIndex);

		// get parent node class
		BaseNodeClass::SPtr parentBaseNode = informationModel_->find(parentNodeId);
		if (parentBaseNode.get() == nullptr) {
			Log(Error, "parent node id do not exist")
				.parameter("ParentNodeId", parentNodeId);
			return BadInternalError;
		}

		ObjectNodeClass::SPtr objectNodeClass = readObjects(objectBase->objectTypeNodeId());
		if (objectNodeClass.get() == nullptr) {
			Log(Error, "create object type error")
				.parameter("ObjectTypeNodeId", objectBase->objectTypeNodeId());
			return BadInternalError;
		}
		objectNodeClass->setDisplayName(displayName);

		// added reference
		parentBaseNode->referenceItemMap().add(referenceTypeNodeId, true, *objectNodeClass->getNodeId());
		objectNodeClass->referenceItemMap().add(referenceTypeNodeId, false, parentNodeId);

		return Success;
	}

	bool
	ObjectInstanceBuilder::getNamespaceIndex(const std::string& namespaceName)
	{
		// get namespace index from namespace name
		NodeSetNamespace nodeSetNamespace;
		namespaceIndex_ = nodeSetNamespace.mapToGlobalNamespaceIndex(namespaceName);
		if (namespaceIndex_ != 0xFFFF) return true;

		// the namespace name do not exist in the information model
		nodeSetNamespace.addNewGlobalNamespace(namespaceName);

		NamespaceArray nsa;
		nsa.informationModel(informationModel_);
		nsa.addNamespaceName(namespaceName);

		return true;
	}

	ObjectNodeClass::SPtr
	ObjectInstanceBuilder::readObjects(
		const OpcUaNodeId& objectTypeNodeId
	)
	{
		InformationModelAccess ima;
		ima.informationModel(informationModel_);

		//
		// find node in opc ua information model
		//
		BaseNodeClass::SPtr baseNodeTemplate = informationModel_->find(objectTypeNodeId);
		if (baseNodeTemplate.get() == nullptr) {
			Log(Error, "object type node identifier not exist in information model")
				.parameter("ObjectTypeNode", objectTypeNodeId);
			ObjectNodeClass::SPtr objectNodeClass;
			return objectNodeClass;
		}

		BrowseName browseName(objectTypeNodeId);
		browseName.pathNames()->resize(10);
		ObjectNodeClass::SPtr objectNodeClass = readChilds(baseNodeTemplate, browseName);
		if (objectNodeClass.get() == nullptr) {
			Log(Error, "read childs error")
				.parameter("ObjectTypeNodeId", objectTypeNodeId);
			ObjectNodeClass::SPtr objectNodeClass;
			return objectNodeClass;
		}

		if (objectTypeNodeId == OpcUaNodeId(58)) {
			return objectNodeClass;
		}

		// find parent node identifier
		OpcUaNodeId parentObjectTypeNodeId;
		if (!ima.getSubType(baseNodeTemplate, parentObjectTypeNodeId)) {
			Log(Error, "parent object type node identifier do not not exist in information model")
				.parameter("ObjectTypeNodeId", objectTypeNodeId)
				.parameter("DisplayName", *baseNodeTemplate->getDisplayName());
			ObjectNodeClass::SPtr objectNodeClass;
			return objectNodeClass;
		}

		return readObjects(parentObjectTypeNodeId);
	}

	ObjectNodeClass::SPtr
	ObjectInstanceBuilder::readChilds(
		const BaseNodeClass::SPtr& baseNodeTemplate,
		BrowseName& browseName
	)
	{
		ObjectNodeClass::SPtr x;
		return x;
	}

}

