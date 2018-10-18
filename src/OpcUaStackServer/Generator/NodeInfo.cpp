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

#include <OpcUaStackServer/Generator/NodeInfo.h>

namespace OpcUaStackServer
{

	NodeInfo::NodeInfo(void)
	: numberNamespaceMap_()
	, dataTypeNodeId_()
	, informationModel_()

	, baseNode_()
	, namespaceName_("")
	, className_("")
	{
	}

	NodeInfo::~NodeInfo(void)
	{
	}

	bool
	NodeInfo::setNamespaceEntry(const std::string& namespaceEntry)
	{
		return numberNamespaceMap_.addNamespace(namespaceEntry);
	}

	OpcUaNodeId
	NodeInfo::dataTypeNodeId(void)
	{
		return dataTypeNodeId_;
	}

	InformationModel::SPtr&
	NodeInfo::informationModel(void)
	{
		return informationModel_;
	}

	BaseNodeClass::SPtr&
	NodeInfo::baseNode(void)
	{
		return baseNode_;
	}

	std::string&
	NodeInfo::namespaceName(void)
	{
		return namespaceName_;
	}

	std::string&
	NodeInfo::className(void)
	{
		return className_;
	}

	bool
	NodeInfo::init(const OpcUaNodeId& dataTypeNodeId, InformationModel::SPtr& informationModel)
	{
		dataTypeNodeId_ = dataTypeNodeId;
		informationModel_ = informationModel;

		// find node in opc ua information model
		baseNode_ = informationModel_->find(dataTypeNodeId);
		if (baseNode_.get() == nullptr) {
			Log(Error, "data type node not exist in information model")
				.parameter("DataTypeNode", dataTypeNodeId);
			return false;
		}

		// set namesapce name
		namespaceName_ = numberNamespaceMap_.getNamespaceName(dataTypeNodeId_.namespaceIndex());

		// set class name
		className_ = baseNode_->displayName().name();
		className_ = boost::to_upper_copy(className_.substr(0,1)) + boost::to_lower_copy(className_.substr(1));

		return true;
	}

}
