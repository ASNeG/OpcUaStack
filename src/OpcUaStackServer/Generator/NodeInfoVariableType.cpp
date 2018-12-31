/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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

#include <boost/algorithm/string.hpp>

#include "OpcUaStackServer/Generator/NodeInfoVariableType.h"
#include "OpcUaStackServer/InformationModel/InformationModelAccess.h"

namespace OpcUaStackServer
{

	NodeInfoVariableType::NodeInfoVariableType(void)
	: numberNamespaceMap_()
	, informationModel_()
	, variableTypeNodeId_()
	, parentVariableTypeNodeId_()
	, baseNode_()
	, parentBaseNode_()
	, namespaceName_("")
	, parentNamespaceName_("")
	, className_("")
	, parentClassName_("")
	, directory_("")
	, parentDirectory_("")
	{
	}

	NodeInfoVariableType::~NodeInfoVariableType(void)
	{
	}

	bool
	NodeInfoVariableType::init(
		const OpcUaNodeId& variableTypeNodeId,
		InformationModel::SPtr& informationModel
	)
	{
		variableTypeNodeId_ = variableTypeNodeId;
		informationModel_ = informationModel;

		InformationModelAccess ima;
		ima.informationModel(informationModel_);

		//
		// find node in opc ua information model
		//
		baseNode_ = informationModel_->find(variableTypeNodeId);
		if (baseNode_.get() == nullptr) {
			Log(Error, "variable type node identifier not exist in information model")
				.parameter("VariableTypeNode", variableTypeNodeId);
			return false;
		}

		//
		// find parent node in opc ua information model
		//
		if (!ima.getSubType(baseNode_, parentVariableTypeNodeId_)) {
			Log(Error, "parent variable type node identifier do not not exist in information model")
				.parameter("VariableTypeNodeId", variableTypeNodeId_);
			return false;
		}
		parentBaseNode_ = informationModel_->find(parentVariableTypeNodeId_);
		if (!parentBaseNode_) {
			Log(Error, "parent data type node instance do not not exist in information model")
				.parameter("VariableTypeNodeId", variableTypeNodeId_)
				.parameter("ParentVariableTypeNodeId", parentVariableTypeNodeId_);
			return false;
		}

		//
		// set namespace name
		//
		namespaceName_ = numberNamespaceMap_.getNamespaceName(variableTypeNodeId_.namespaceIndex());

		//
		// set namespace name of parent
		//
		parentNamespaceName_ = numberNamespaceMap_.getNamespaceName(parentVariableTypeNodeId_.namespaceIndex());

		//
		// set class name
		//
		boost::optional<OpcUaLocalizedText&> displayName = baseNode_->getDisplayName();
		if (!displayName) {
			Log(Error, "display name not found")
			    .parameter("VariableTypeNode", variableTypeNodeId_);
		}
		className_ = displayName->text();
		className_ = boost::to_upper_copy(className_.substr(0,1)) + className_.substr(1);

		//
		// set class name of parent
		//
		boost::optional<OpcUaLocalizedText&> parentDisplayName = parentBaseNode_->getDisplayName();
		if (!parentDisplayName) {
			Log(Error, "display name not found")
			    .parameter("ParentVariableTypeNode", parentVariableTypeNodeId_);
		}
		parentClassName_ = parentDisplayName->text();
		parentClassName_ = boost::to_upper_copy(parentClassName_.substr(0,1)) + parentClassName_.substr(1);

		//
		// set directory
		//
		if (variableTypeNodeId_.namespaceIndex() == 0) {
			directory_ = "StandardVariableTypes";
		}
		else {
			directory_ = "CustomerVariableTypes";
		}

		//
		// set directory of parent
		//
		if (parentVariableTypeNodeId_.namespaceIndex() == 0) {
			parentDirectory_ = "StandardVariableTypes";
		}
		else {
			parentDirectory_ = "CustomerVariableTypes";
		}


		// FIXME: todo
		return true;
	}

	std::string&
	NodeInfoVariableType::className(void)
	{
		return className_;
	}

	std::string&
	NodeInfoVariableType::namespaceName(void)
	{
		return namespaceName_;
	}

}
