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
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"

namespace OpcUaStackServer
{

    class DLLEXPORT AddNodeRule
    {
      public:
    	typedef enum {
    		UniqueNumber,
    		UniqueString
    	} NodeIdMode;

    	AddNodeRule(void);
    	AddNodeRule(AddNodeRule& addNodeRule);
    	AddNodeRule(AddNodeRule& addNodeRule, OpcUaLocalizedText& displayName);
    	~AddNodeRule(void);

    	void informationModel(InformationModel::SPtr& informationModel);
    	InformationModel::SPtr& informationModel(void);
    	void nodeIdMode(NodeIdMode nodeIdMode);
    	NodeIdMode nodeIdMode(void);
    	void displayPath(const std::string& displayPath);
    	void displayPath(OpcUaNodeId& nodeId);
    	std::string& displayPath(void);
    	void displayName(OpcUaLocalizedText& displayName);

    	OpcUaNodeId createUniqueNodeId(uint16_t namespaceIndex);

      private:
    	std::string displayPath_;
    	InformationModel::SPtr informationModel_;
    	NodeIdMode nodeIdMode_;
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
			AddNodeRule& addNodeRule,
			OpcUaNodeId& parentNodeId,
			OpcUaNodeId& nodeId,
			OpcUaLocalizedText& displayName,
			OpcUaQualifiedName& browseName,
			OpcUaNodeId& referenceNodeId,
			OpcUaNodeId& typeNodeId
		);

		bool addVariableNode(
			AddNodeRule& addNodeRule,
			OpcUaNodeId& parentNodeId,
			OpcUaNodeId& nodeId,
			OpcUaLocalizedText& displayName,
			OpcUaQualifiedName& browseName,
			OpcUaNodeId& referenceNodeId,
			OpcUaNodeId& typeNodeId
		);

		bool addObjectTypeNode(
			OpcUaNodeId& parentNodeId,
			OpcUaNodeId& nodeId,
			OpcUaLocalizedText& displayName,
			OpcUaQualifiedName& browseName
		);

		bool addVariableTypeNode(
			OpcUaNodeId& parentNodeId,
			OpcUaNodeId& nodeId,
			OpcUaLocalizedText& displayName,
			OpcUaQualifiedName& browseName
		);

		bool addDataTypeNode(
			OpcUaNodeId& parentNodeId,
			OpcUaNodeId& nodeId,
			OpcUaLocalizedText& displayName,
			OpcUaQualifiedName& browseName
		);

		bool addReferenceTypeNode(
			OpcUaNodeId& parentNodeId,
			OpcUaNodeId& nodeId,
			OpcUaLocalizedText& displayName,
			OpcUaQualifiedName& browseName
		);

		bool delNode(
			OpcUaNodeId& nodeId
		);

		bool delReference(
			OpcUaNodeId& sourceNodeId,
			OpcUaNodeId& referenceTypeNodeId,
			OpcUaNodeId& targetNodeId
		);

	  private:
		bool addTypeChilds(
			AddNodeRule& addNodeRule,
			BaseNodeClass::SPtr& parentNodeClass,
			BaseNodeClass::SPtr& cloneNodeClass
		);
		bool addObjectNode(
			AddNodeRule& addNodeRule,
			BaseNodeClass::SPtr& parentNodeClass,
			BaseNodeClass::SPtr& cloneBaseNodeClass,
			OpcUaNodeId& referenceTypeNodeId
		);
		bool addVariableNode(
			AddNodeRule& addNodeRule,
			BaseNodeClass::SPtr& parentNodeClass,
			BaseNodeClass::SPtr& cloneBaseNodeClass,
			OpcUaNodeId& referenceTypeNodeId
		);
		bool addMethodNode(
			AddNodeRule& addNodeRule,
			BaseNodeClass::SPtr& parentNodeClass,
			BaseNodeClass::SPtr& cloneBaseNodeClass,
			OpcUaNodeId& referenceTypeNodeId
		);

		InformationModel::SPtr informationModel_;
	};

}

#endif
