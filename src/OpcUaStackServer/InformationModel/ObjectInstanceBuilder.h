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

#ifndef __OpcUaStackServer_ObjectInstanceBuilder_h__
#define __OpcUaStackServer_ObjectInstanceBuilder_h__

#include "OpcUaStackCore/Application/BrowseName.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/VariableNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/ObjectNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/MethodNodeClass.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{

	class DLLEXPORT ObjectInstanceBuilder
	{
	  public:
		using SPtr = boost::shared_ptr<ObjectInstanceBuilder>;
		using ObjectNodeClassMap = std::map<std::string, ObjectNodeClass::SPtr>;
		using NodeIdMap = std::map<std::string, OpcUaStackCore::OpcUaNodeId>;

		ObjectInstanceBuilder(void);
		~ObjectInstanceBuilder(void);

		OpcUaStackCore::OpcUaStatusCode createObjectInstance(
			InformationModel::SPtr& informationModel,
			const std::string& namespaceName,
			const OpcUaStackCore::OpcUaLocalizedText& displayName,
			const OpcUaStackCore::OpcUaNodeId& parentNodeId,
			const OpcUaStackCore::OpcUaNodeId& referenceTypeNodeId,
			const ObjectBase::SPtr& objectBase,
			NodeIdMap* nodeIdMap = nullptr
		);

	  private:
		bool getNamespaceIndex(const std::string& namespaceName);
		ObjectNodeClass::SPtr createObject(
			const OpcUaStackCore::OpcUaNodeId& parentNodeId,
			const OpcUaStackCore::OpcUaNodeId& objectTypeNodeId
		);
		BaseNodeClass::SPtr createNodeAndClilds(
			const OpcUaStackCore::OpcUaNodeId& parentNodeId,
			const BaseNodeClass::SPtr& baseNodeTemplate,
			OpcUaStackCore::BrowseName& browseName
		);
		ObjectNodeClass::SPtr createObjectInstance(
			const BaseNodeClass::SPtr& baseNodeTemplate,
			OpcUaStackCore::BrowseName& browseName
		);
		VariableNodeClass::SPtr createVariableInstance(
			const BaseNodeClass::SPtr& baseNodeTemplate,
			OpcUaStackCore::BrowseName& browseName
		);
		MethodNodeClass::SPtr createMethodInstance(
			const OpcUaStackCore::OpcUaNodeId& parentNodeId,
			const BaseNodeClass::SPtr& baseNodeTemplate,
			OpcUaStackCore::BrowseName& browseName
		);

		InformationModel::SPtr informationModel_;
		uint16_t namespaceIndex_;
		ObjectBase::SPtr objectBase_;

		ObjectNodeClassMap objectNodeClassMap_;
		NodeIdMap* nodeIdMap_ = nullptr;
	};

}

#endif
