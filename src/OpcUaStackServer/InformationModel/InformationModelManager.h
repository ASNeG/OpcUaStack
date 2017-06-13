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

#ifndef __OpcUaStackServer_InformationModelManager_h__
#define __OpcUaStackServer_InformationModelManager_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"

namespace OpcUaStackServer
{

	class MergeIf
	{
	  public:
		MergeIf(void) {}
		virtual ~MergeIf(void) {}

		virtual void handleMerge(uint32_t maxCount, uint32_t actCount) = 0;
	};


	class DLLEXPORT InformationModelManager
	{
	  public:
		typedef boost::shared_ptr<InformationModelManager> SPtr;

		InformationModelManager(void);
		InformationModelManager(InformationModel::SPtr informationModel);
		~InformationModelManager(void);

		void informationModel(InformationModel::SPtr informationModel);

		bool addObjectNode(
			OpcUaNodeId& parentNodeId,
			OpcUaNodeId& nodeId,
			OpcUaLocalizedText& displayName,
			OpcUaQualifiedName& browseName,
			OpcUaNodeId& referenceType,
			OpcUaNodeId& objectType
		);
		bool addVariableNode(
			OpcUaNodeId& parentNodeId,
			OpcUaNodeId& nodeId,
			OpcUaLocalizedText& displayName,
			OpcUaQualifiedName& browseName,
			OpcUaNodeId& referenceType,
			OpcUaNodeId& variableType
		);
		bool addNode(
			OpcUaNodeId& parentNodeId,
			OpcUaNodeId& nodeId,
			OpcUaLocalizedText& displayName,
			OpcUaQualifiedName& browseName,
			OpcUaNodeId& referenceNodeId,
			OpcUaNodeId& typeNodeId
		);

	  private:
		InformationModel::SPtr informationModel_;
	};

}

#endif
