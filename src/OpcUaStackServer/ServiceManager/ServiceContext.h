#ifndef __OpcUaStackServer_ServiceContext_h__
#define __OpcUaStackServer_ServiceContext_h__

#include "OpcUaStackCore/InformationModel/InformationModel.h"

namespace OpcUaStackServer
{

	class ServiceContect
	{
	  public:
		InformationModel::SPtr informationModel_;
	};

}

#endif