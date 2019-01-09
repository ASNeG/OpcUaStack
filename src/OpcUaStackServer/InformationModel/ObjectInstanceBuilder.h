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

#ifndef __OpcUaStackServer_ObjectInstanceBuilder_h__
#define __OpcUaStackServer_ObjectInstanceBuilder_h__

#include "OpcUaStackCore/ServiceSetApplication/BrowseName.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/VariableNodeClass.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{

	class DLLEXPORT ObjectInstanceBuilder
	{
	  public:
		typedef boost::shared_ptr<ObjectInstanceBuilder> SPtr;

		ObjectInstanceBuilder(void);
		~ObjectInstanceBuilder(void);

		OpcUaStatusCode createObjectInstance(
			InformationModel::SPtr& informationModel,
			const std::string& namespaceName,
			const OpcUaLocalizedText& displayName,
			OpcUaNodeId& parentNodeId,
			OpcUaNodeId& referenceTypeNodeId,
			ObjectBase::SPtr& objectBase
		);

	  private:
		bool getNamespaceIndex(const std::string& namespaceName);

		InformationModel::SPtr informationModel_;
		uint16_t namespaceIndex_;
		ObjectBase::SPtr objectBase_;
	};

}

#endif
