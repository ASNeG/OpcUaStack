#ifndef __OpcUaStackServer_Child_h__
#define __OpcUaStackServer_Child_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"

namespace OpcUaStackServer
{

	class DLLEXPORT Child
	{
	  public:
		typedef boost::shared_ptr<Child> SPtr;

		Child(void);
		Child(InformationModel::SPtr informationModel);
		~Child(void);

		void informationModel(InformationModel::SPtr informationModel);
		bool getChild(BaseNodeClass::SPtr baseNodeClass, BaseNodeClass::Vec& childBaseNodeClassVec);
		bool getChildHierarchically(BaseNodeClass::SPtr baseNodeClass, BaseNodeClass::Vec& childBaseNodeClassVec);
		bool getChildNonHierarchically(BaseNodeClass::SPtr baseNodeClass, BaseNodeClass::Vec& childBaseNodeClassVec);

	  private:
		InformationModel::SPtr informationModel_;
	};

}

#endif
