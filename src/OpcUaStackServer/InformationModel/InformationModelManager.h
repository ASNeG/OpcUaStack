/*
   Copyright 2015-2020 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (atimin@gmail.com)
 */

#ifndef __OpcUaStackServer_InformationModelManager_h__
#define __OpcUaStackServer_InformationModelManager_h__

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
    	AddNodeRule(AddNodeRule& addNodeRule, OpcUaStackCore::OpcUaLocalizedText& displayName);
    	~AddNodeRule(void);

    	void informationModel(InformationModel::SPtr& informationModel);
    	InformationModel::SPtr& informationModel(void);
    	void nodeIdMode(NodeIdMode nodeIdMode);
    	NodeIdMode nodeIdMode(void);
    	void displayPath(const std::string& displayPath);
    	void displayPath(OpcUaStackCore::OpcUaNodeId& nodeId);
    	std::string& displayPath(void);
    	void displayName(OpcUaStackCore::OpcUaLocalizedText& displayName);
    	void delemiter(const std::string& delemiter);
    	std::string& delemiter(void);
    	void createOptionalPlaceholder(bool createOptionalPlaceholder);
    	bool createOptionalPlaceholder(void);

    	OpcUaStackCore::OpcUaNodeId createUniqueNodeId(uint16_t namespaceIndex);

      private:
    	std::string displayPath_;
    	InformationModel::SPtr informationModel_;
    	NodeIdMode nodeIdMode_;
    	std::string delemiter_;
    	bool createOptionalPlaceholder_;
    };


	class DLLEXPORT InformationModelManager
	{
	  public:
		typedef boost::shared_ptr<InformationModelManager> SPtr;

		InformationModelManager(void);
		InformationModelManager(InformationModel::SPtr& informationModel);
		~InformationModelManager(void);

		void informationModel(InformationModel::SPtr& informationModel);

		bool addNode(
			OpcUaStackCore::NodeClass::Enum nodeClassType,
			AddNodeRule& addNodeRule,
			OpcUaStackCore::OpcUaNodeId& parentNodeId,
			OpcUaStackCore::OpcUaNodeId& nodeId,
			OpcUaStackCore::OpcUaLocalizedText& displayName,
			OpcUaStackCore::OpcUaQualifiedName& browseName,
			OpcUaStackCore::OpcUaNodeId& referenceNodeId,
			OpcUaStackCore::OpcUaNodeId& typeNodeId
		);

		bool addObjectNode(
			AddNodeRule& addNodeRule,
			OpcUaStackCore::OpcUaNodeId& parentNodeId,
			OpcUaStackCore::OpcUaNodeId& nodeId,
			OpcUaStackCore::OpcUaLocalizedText& displayName,
			OpcUaStackCore::OpcUaQualifiedName& browseName,
			OpcUaStackCore::OpcUaNodeId& referenceNodeId,
			OpcUaStackCore::OpcUaNodeId& typeNodeId
		);

		bool addVariableNode(
			AddNodeRule& addNodeRule,
			OpcUaStackCore::OpcUaNodeId& parentNodeId,
			OpcUaStackCore::OpcUaNodeId& nodeId,
			OpcUaStackCore::OpcUaLocalizedText& displayName,
			OpcUaStackCore::OpcUaQualifiedName& browseName,
			OpcUaStackCore::OpcUaNodeId& referenceNodeId,
			OpcUaStackCore::OpcUaNodeId& typeNodeId
		);

		bool addMethodNode(
		    OpcUaStackCore::OpcUaNodeId& parentNodeId,
			OpcUaStackCore::OpcUaNodeId& nodeId,
			OpcUaStackCore::OpcUaLocalizedText& displayName,
			OpcUaStackCore::OpcUaQualifiedName& browseName
		);

		bool addObjectTypeNode(
			OpcUaStackCore::OpcUaNodeId& parentNodeId,
			OpcUaStackCore::OpcUaNodeId& nodeId,
			OpcUaStackCore::OpcUaLocalizedText& displayName,
			OpcUaStackCore::OpcUaQualifiedName& browseName
		);

		bool addVariableTypeNode(
			OpcUaStackCore::OpcUaNodeId& parentNodeId,
			OpcUaStackCore::OpcUaNodeId& nodeId,
			OpcUaStackCore::OpcUaLocalizedText& displayName,
			OpcUaStackCore::OpcUaQualifiedName& browseName
		);

		bool addDataTypeNode(
			OpcUaStackCore::OpcUaNodeId& parentNodeId,
			OpcUaStackCore::OpcUaNodeId& nodeId,
			OpcUaStackCore::OpcUaLocalizedText& displayName,
			OpcUaStackCore::OpcUaQualifiedName& browseName
		);

		bool addReferenceTypeNode(
			OpcUaStackCore::OpcUaNodeId& parentNodeId,
			OpcUaStackCore::OpcUaNodeId& nodeId,
			OpcUaStackCore::OpcUaLocalizedText& displayName,
			OpcUaStackCore::OpcUaQualifiedName& browseName
		);

		bool delNode(
			const OpcUaStackCore::OpcUaNodeId& nodeId
		);

		bool delReference(
			const OpcUaStackCore::OpcUaNodeId& sourceNodeId,
			const OpcUaStackCore::OpcUaNodeId& referenceTypeNodeId,
			const OpcUaStackCore::OpcUaNodeId& targetNodeId
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
			OpcUaStackCore::OpcUaNodeId& referenceTypeNodeId
		);
		bool addVariableNode(
			AddNodeRule& addNodeRule,
			BaseNodeClass::SPtr& parentNodeClass,
			BaseNodeClass::SPtr& cloneBaseNodeClass,
			OpcUaStackCore::OpcUaNodeId& referenceTypeNodeId
		);
		bool addMethodNode(
			AddNodeRule& addNodeRule,
			BaseNodeClass::SPtr& parentNodeClass,
			BaseNodeClass::SPtr& cloneBaseNodeClass,
			OpcUaStackCore::OpcUaNodeId& referenceTypeNodeId
		);

		bool isOptionalPlaceholder(
			BaseNodeClass::SPtr& nodeClass
		);

		InformationModel::SPtr informationModel_;
	};

}

#endif
