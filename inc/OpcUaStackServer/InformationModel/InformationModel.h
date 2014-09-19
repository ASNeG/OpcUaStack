#ifndef __OpcUaStackServer_InformationModel_h__
#define __OpcUaStackServer_InformationModel_h__

#include <boost/thread/mutex.hpp>
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"
#include <map>

namespace OpcUaStackServer
{

	typedef std::map<OpcUaNodeId, BaseNodeClass::SPtr> InformationModelMap;

	class InformationModel
	{
	  public:
		InformationModel(void);
		~InformationModel(void);

		bool insert(BaseNodeClass::SPtr baseNodeClass);
		BaseNodeClass::SPtr find(OpcUaNodeId& opcUaNodeId);
		BaseNodeClass::SPtr find(OpcUaNodeId::SPtr opcUaNodeId);

	  private:
		boost::mutex mutex_;
		InformationModelMap informationModelMap_;

	};

}

#endif