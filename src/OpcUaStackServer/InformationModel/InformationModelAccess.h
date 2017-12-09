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

#ifndef __OpcUaStackServer_InformationModelAccess_h__
#define __OpcUaStackServer_InformationModelAccess_h__

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


	class DLLEXPORT InformationModelAccess
	{
	  public:
		typedef boost::shared_ptr<InformationModelAccess> SPtr;

		InformationModelAccess(void);
		InformationModelAccess(InformationModel::SPtr informationModel);
		~InformationModelAccess(void);

		void informationModel(InformationModel::SPtr informationModel);

		// --------------------------------------------------------------------
		// helper function
		// --------------------------------------------------------------------
		OpcUaNodeId createUniqueNodeId(uint16_t namespaceIndex);
		OpcUaNodeId createUniqueNodeId(const std::string& namespaceName, uint16_t namespaceIndex);

		// --------------------------------------------------------------------
		// node functions
		// --------------------------------------------------------------------
		bool rootNode(BaseNodeClass::SPtr& baseNodeClass, bool logOnError = true);
		bool getNode(const OpcUaNodeId& nodeId, BaseNodeClass::SPtr& baseNodeClass, bool logOnError = true);

		// --------------------------------------------------------------------
		// child functions
		// --------------------------------------------------------------------
		bool getChild(
			BaseNodeClass::SPtr baseNodeClass,
			BaseNodeClass::Vec& childBaseNodeClassVec
		);
		bool getChildHierarchically(
			BaseNodeClass::SPtr baseNodeClass,
			BaseNodeClass::Vec& childBaseNodeClassVec
		);
		bool getChildHierarchically(
			BaseNodeClass::SPtr baseNodeClass,
			BaseNodeClass::Vec& childBaseNodeClassVec,
			ReferenceItem::Vec& referenceItemVec
		);
		bool getChildHierarchically(
			BaseNodeClass::SPtr baseNodeClass,
			BaseNodeClass::Vec& childBaseNodeClassVec,
			std::vector<OpcUaNodeId>& referenceTypeNodeIdVec
		);
		bool getChildNonHierarchically(
			BaseNodeClass::SPtr baseNodeClass,
			BaseNodeClass::Vec& childBaseNodeClassVec
		);
		bool getChildHierarchically(
			BaseNodeClass::SPtr baseNodeClass,
			OpcUaNodeId& referenceTypeNodeId,
			std::vector<OpcUaNodeId>& childNodeIdVec
		);
		bool getChildHierarchically(
			BaseNodeClass::SPtr baseNodeClass,
			std::vector<OpcUaNodeId>& referenceTypeNodeIdVec,
			std::vector<OpcUaNodeId>& childNodeIdVec
		);

		// --------------------------------------------------------------------
		// parent functions
		// --------------------------------------------------------------------
		bool getParentReference(BaseNodeClass::SPtr baseNodeClass, std::vector<OpcUaNodeId>& referenceTypeNodeIdVec, ReferenceItem::Vec& referenceItemVec);
		bool getParent(BaseNodeClass::SPtr baseNodeClass, std::vector<OpcUaNodeId>& nodeIdVec);
		bool getParent(BaseNodeClass::SPtr baseNodeClass, ReferenceItem::Vec& referenceItemVec);
		bool getParent(BaseNodeClass::SPtr baseNodeClass, BaseNodeClass::Vec& childBaseNodeClassVec);
		bool getParentHierarchically(
			BaseNodeClass::SPtr baseNodeClass,
			OpcUaNodeId& referenceTypeNodeId,
			std::vector<OpcUaNodeId>& parentNodeIdVec
		);
		bool getParentHierarchically(BaseNodeClass::SPtr baseNodeClass, BaseNodeClass::Vec& childBaseNodeClassVec);
		bool getParentHierarchically(BaseNodeClass::SPtr baseNodeClass, std::vector<OpcUaNodeId>& nodeIdVec);
		bool getParentNonHierarchically(BaseNodeClass::SPtr baseNodeClass, BaseNodeClass::Vec& childBaseNodeClassVec);
		bool getParentNonHierarchically(BaseNodeClass::SPtr baseNodeClass, std::vector<OpcUaNodeId>& nodeIdVec);
		BaseNodeClass::SPtr getSurrogateParentNode();
		BaseNodeClass::SPtr getSurrogateParentNode(OpcUaNodeId& nodeId);
		bool parentChange(BaseNodeClass::SPtr baseNodeClass, const OpcUaNodeId& oldParentNodeId, const OpcUaNodeId& newParentNodeId);

		// --------------------------------------------------------------------
		// reference functions
		// --------------------------------------------------------------------
		bool isReferenceHierarchically0(const OpcUaNodeId& nodeId);
		bool isReferenceHierarchically(BaseNodeClass::SPtr referenceBaseNodeClass);
		bool isReferenceHierarchically(const OpcUaNodeId& nodeId);

		// --------------------------------------------------------------------
		// type functions
		// --------------------------------------------------------------------
		bool getType(BaseNodeClass::SPtr baseNodeClass, BaseNodeClass::SPtr& typeBaseNodeClass);
		bool getType(BaseNodeClass::SPtr baseNodeClass, OpcUaNodeId& typeNodeId);
		bool getSubType(BaseNodeClass::SPtr baseNodeClass, BaseNodeClass::SPtr& subTypeBaseNodeClass);
		bool getSubType(BaseNodeClass::SPtr baseNodeClass, OpcUaNodeId& subTypeNodeId);

		// --------------------------------------------------------------------
		// data type functions
		// --------------------------------------------------------------------
		bool isDataType(BaseNodeClass::SPtr baseNodeClass);
		bool isDataType(OpcUaNodeId& nodeId);
		bool isDataTypeStructure(BaseNodeClass::SPtr baseNodeClass);
		bool isDataTypeStructure(OpcUaNodeId& nodeId);
		bool isDataTypeEnum(BaseNodeClass::SPtr baseNodeClass);
		bool isDataTypeEnum(OpcUaNodeId& nodeId);
		bool isObjectType(BaseNodeClass::SPtr baseNodeClass);
		bool isObjectType(OpcUaNodeId& nodeId);
		bool isVariableType(BaseNodeClass::SPtr baseNodeClass);
		bool isVariableType(OpcUaNodeId& nodeId);
		bool isReferences(BaseNodeClass::SPtr baseNodeClass);
		bool isReferences(OpcUaNodeId& nodeId);
		bool isBaseEventType(BaseNodeClass::SPtr baseNodeClass);
		bool isBaseEventType(OpcUaNodeId& nodeId);

		// --------------------------------------------------------------------
		// event function
		// --------------------------------------------------------------------
		bool isEventProperty(BaseNodeClass::SPtr baseNodeClass);
		bool isEventProperty(OpcUaNodeId& nodeId);

		// --------------------------------------------------------------------
		// merge function
		// --------------------------------------------------------------------
		bool add(InformationModel::SPtr informationModel, uint16_t namespaceIndex, MergeIf* mergeIf = NULL, uint32_t step = 10);
		bool remove(BaseNodeClass::SPtr baseNodeClass);
		bool remove(OpcUaNodeId& nodeId);
		bool containsNodeIds(InformationModel::SPtr informationModel, uint16_t namespaceIndex);

	  private:
		static uint32_t counter_;
		InformationModel::SPtr informationModel_;
	};

}

#endif
