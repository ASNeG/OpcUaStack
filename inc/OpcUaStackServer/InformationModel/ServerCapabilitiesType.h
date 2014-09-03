#ifndef __OpcUaStacServer_ServerCapabilitiesType_h__
#define __OpcUaStacServer_ServerCapabilitiesType_h__

#include "OpcUaStackServer/AddressSpaceModel/ObjectTypeNodeClass.h"

namespace OpcUaStackServer
{

	class ServerCapabilitiesType : public ObjectTypeNodeClass
	{
	  public:
		ServerCapabilitiesType(void);
		~ServerCapabilitiesType(void);
	};

}

#endif