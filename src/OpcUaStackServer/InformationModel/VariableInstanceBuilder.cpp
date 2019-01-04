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
#include "OpcUaStackServer/InformationModel/VariableInstanceBuilder.h"
#include "OpcUaStackServer/NodeSet/NodeSetNamespace.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	VariableInstanceBuilder::VariableInstanceBuilder(void)
	: informationModel_()
	, parentNode_()
	, variableTypeNode_()
	{
	}

	VariableInstanceBuilder::~VariableInstanceBuilder(void)
	{
	}

	OpcUaStatusCode
	VariableInstanceBuilder::createVariableInstance(
		InformationModel::SPtr& informationModel,
		OpcUaNodeId& parentNodeId,
		OpcUaNodeId& referenceTypeNodeId,
		VariableBase::SPtr& variableBase
	)
	{
		informationModel_ = informationModel;

		// find variable type namespace index from namespace name
		NodeSetNamespace nodeSetNamespace;
		uint16_t namespaceIndex = nodeSetNamespace.mapToGlobalNamespaceIndex(variableBase->variableTypeNamespaceName());
		if (namespaceIndex == 0xFFFF) {
			Log(Error, "variable type namespace name do not exist")
				.parameter("NamespaceName", variableBase->variableTypeNamespaceName());
			return BadInternalError;
		}
		variableBase->variableTypeNodeId().namespaceIndex(namespaceIndex);

		// find parent node
		//boost::mutex::scoped_lock g(informationModel_->mutex());
		parentNode_ = informationModel_->find(parentNodeId);
		if (parentNode_.get() == nullptr) {
			Log(Error, "parent node do not exist in information model")
				.parameter("ParentNodeId", parentNodeId);
			return BadInternalError;
		}

		// find variable type node
		BaseNodeClass::SPtr variableTypeNode = informationModel_->find(variableBase->variableTypeNodeId());
		variableTypeNode_ = informationModel_->find(parentNodeId);
		if (variableTypeNode_.get() == nullptr) {
			Log(Error, "variable type node do not exist in information model")
				.parameter("VariableTypeNodeId", variableBase->variableTypeNodeId());
			return BadInternalError;
		}

		std::cout << "VARIABLE INSTANCE SUCCESS..." << std::endl;
		return Success;
	}

	bool
	VariableInstanceBuilder::readValues(const BaseNodeClass::SPtr& baseNode)
	{
		// FIXME: todo
		return true;
	}

	bool
	VariableInstanceBuilder::readChilds(const BaseNodeClass::SPtr& baseNode, BrowseName& browseName)
	{
		// FIXME: todo
		return true;
	}

	bool
	VariableInstanceBuilder::readNodeInfo(const BaseNodeClass::SPtr& baseNode, BrowseName& browseName)
	{
		// FIXME: todo
		return true;
	}

}

