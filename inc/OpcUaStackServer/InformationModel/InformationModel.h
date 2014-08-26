#ifndef __OpcUaStackServer_InformationModel_h__
#define __OpcUaStackServer_InformationModel_h__

#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"
#include <set>

namespace OpcUaStackServer
{

	//typedef std::set<BaseNodeClass::SPtr> InformationModelMap;

	class InformationModel
	{
	  public:
		InformationModel(void);
		~InformationModel(void);

	  private:
		//InformationModelMap informationModelMap_;

	};

}

#endif