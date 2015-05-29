#ifndef __OpcUaStackServer_Parent_h__
#define __OpcUaStackServer_Parent_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"

namespace OpcUaStackServer
{

	class DLLEXPORT Parent
	{
	  public:
		typedef boost::shared_ptr<Parent> SPtr;

		Parent(void);
		Parent(InformationModel::SPtr informationModel);
		~Parent(void);

		void informationModel(InformationModel::SPtr informationModel);
		bool getParent(BaseNodeClass::SPtr baseNodeClass, BaseNodeClass::Vec& parentBaseNodeClassVec);
		bool getParentHierarchically(BaseNodeClass::SPtr baseNodeClass, BaseNodeClass::SPtr& parentBaseNodeClass);
		bool getParentHierarchically(BaseNodeClass::SPtr baseNodeClass, BaseNodeClass::Vec& parentBaseNodeClassVec);
		bool getParentNonHierarchically(BaseNodeClass::SPtr baseNodeClass, BaseNodeClass::SPtr& parentBaseNodeClass);
		bool getParentNonHierarchically(BaseNodeClass::SPtr baseNodeClass, BaseNodeClass::Vec& parentBaseNodeClassVec);

	  private:
		InformationModel::SPtr informationModel_;
	};

}

#endif
