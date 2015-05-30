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
		// node functions
		// --------------------------------------------------------------------
		bool rootNode(BaseNodeClass::SPtr& baseNodeClass);
		bool getNode(const OpcUaNodeId& nodeId, BaseNodeClass::SPtr& baseNodeClass);

		// --------------------------------------------------------------------
		// child functions
		// --------------------------------------------------------------------
		bool getChild(BaseNodeClass::SPtr baseNodeClass, BaseNodeClass::Vec& childBaseNodeClassVec);
		bool getChildHierarchically(BaseNodeClass::SPtr baseNodeClass, BaseNodeClass::Vec& childBaseNodeClassVec);
		bool getChildNonHierarchically(BaseNodeClass::SPtr baseNodeClass, BaseNodeClass::Vec& childBaseNodeClassVec);

		// --------------------------------------------------------------------
		// parent functions
		// --------------------------------------------------------------------
		bool getParentReference(BaseNodeClass::SPtr baseNodeClass, std::vector<OpcUaNodeId>& referenceTypeNodeIdVec, ReferenceItem::Vec& referenceItemVec);
		bool getParent(BaseNodeClass::SPtr baseNodeClass, std::vector<OpcUaNodeId>& nodeIdVec);
		bool getParent(BaseNodeClass::SPtr baseNodeClass, ReferenceItem::Vec& referenceItemVec);
		bool getParent(BaseNodeClass::SPtr baseNodeClass, BaseNodeClass::Vec& childBaseNodeClassVec);
		bool getParentHierarchically(BaseNodeClass::SPtr baseNodeClass, BaseNodeClass::Vec& childBaseNodeClassVec);
		bool getParentHierarchically(BaseNodeClass::SPtr baseNodeClass, std::vector<OpcUaNodeId>& nodeIdVec);
		bool getParentNonHierarchically(BaseNodeClass::SPtr baseNodeClass, BaseNodeClass::Vec& childBaseNodeClassVec);
		bool getParentNonHierarchically(BaseNodeClass::SPtr baseNodeClass, std::vector<OpcUaNodeId>& nodeIdVec);

		// --------------------------------------------------------------------
		// reference functions
		// --------------------------------------------------------------------
		bool isReferenceHierarchically(BaseNodeClass::SPtr baseNodeClass);
		bool isReferenceHierarchically(const OpcUaNodeId& nodeId);

		// --------------------------------------------------------------------
		// type functions
		// --------------------------------------------------------------------
		bool getType(BaseNodeClass::SPtr baseNodeClass, BaseNodeClass::SPtr& typeBaseNodeClass);
		bool getType(BaseNodeClass::SPtr baseNodeClass, OpcUaNodeId& typeNodeId);
		bool getSubType(BaseNodeClass::SPtr baseNodeClass, BaseNodeClass::SPtr& subTypeBaseNodeClass);
		bool getSubType(BaseNodeClass::SPtr baseNodeClass, OpcUaNodeId& subTypeNodeId);

		// --------------------------------------------------------------------
		// merge function
		// --------------------------------------------------------------------
		bool add(InformationModel::SPtr informationModel, uint16_t namespaceIndex, MergeIf* mergeIf = NULL, uint32_t step = 10);


	  private:
		InformationModel::SPtr informationModel_;
	};

}

#endif
