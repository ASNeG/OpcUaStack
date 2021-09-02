/*
   Copyright 2019-2021 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_VariableInstanceBuilder_h__
#define __OpcUaStackServer_VariableInstanceBuilder_h__

#include "OpcUaStackCore/Application/BrowseName.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/VariableNodeClass.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"
#include "OpcUaStackServer/StandardVariableType/VariableBase.h"

namespace OpcUaStackServer
{

	class DLLEXPORT VariableInstanceBuilder
	{
	  public:
		using SPtr = boost::shared_ptr<VariableInstanceBuilder>;
		using NodeIdMap = std::map<std::string, OpcUaStackCore::OpcUaNodeId>;

		VariableInstanceBuilder(void);
		~VariableInstanceBuilder(void);

		OpcUaStackCore::OpcUaStatusCode createVariableInstance(
			InformationModel::SPtr& informationModel,
			const std::string& namespaceName,
			const OpcUaStackCore::OpcUaLocalizedText& displayName,
			OpcUaStackCore::OpcUaNodeId& parentNodeId,
			OpcUaStackCore::OpcUaNodeId& referenceTypeNodeId,
			VariableBase::SPtr& variableBase,
			NodeIdMap* nodeIdMap = nullptr
		);

	  private:
		bool getNamespaceIndex(const std::string& namespaceName);
		VariableNodeClass::SPtr readValues(
			const OpcUaStackCore::OpcUaNodeId& variableTypeNodeId
		);
		VariableNodeClass::SPtr readChilds(
			const BaseNodeClass::SPtr& baseNodeTemplate,
			OpcUaStackCore::BrowseName& browseName
		);
		VariableNodeClass::SPtr createVariableInstance(
			const BaseNodeClass::SPtr& baseNodeTemplate,
			OpcUaStackCore::BrowseName& browseName
		);

		InformationModel::SPtr informationModel_;
		std::set<std::string> variableNameSet_;
		uint16_t namespaceIndex_;
		VariableBase::SPtr variableBase_;
		NodeIdMap* nodeIdMap_ = nullptr;
	};

}

#endif
