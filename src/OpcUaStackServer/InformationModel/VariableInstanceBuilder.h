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

#ifndef __OpcUaStackServer_VariableInstanceBuilder_h__
#define __OpcUaStackServer_VariableInstanceBuilder_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"
#include "OpcUaStackServer/VariableType/VariableBase.h"

namespace OpcUaStackServer
{

	class DLLEXPORT VariableInstanceBuilder
	{
	  public:
		typedef boost::shared_ptr<VariableInstanceBuilder> SPtr;

		VariableInstanceBuilder(void);
		~VariableInstanceBuilder(void);

		OpcUaStatusCode createVariableInstance(
			InformationModel::SPtr& informationModel,
			OpcUaNodeId& parentNodeId,
			OpcUaNodeId& referenceTypeNodeId,
			VariableBase::SPtr& variableBase
		);

	  private:
		bool readValues(const OpcUaNodeId& variableTypeNodeId);
		bool readChilds(const BaseNodeClass::SPtr& baseNode, BrowseName& browseName);
		bool readNodeInfo(const BaseNodeClass::SPtr& baseNode, BrowseName& browseName);

		InformationModel::SPtr informationModel_;
		BaseNodeClass::SPtr parentNode_;
		BaseNodeClass::SPtr variableTypeNode_;
	};

}

#endif
