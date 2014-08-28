#ifndef __OpcUaStacServer_ServerType_h__
#define __OpcUaStacServer_ServerType_h__

#include "OpcUaStackServer/AddressSpaceModel/ObjectTypeNodeClass.h"

namespace OpcUaStackServer
{

	class ServerType : public ObjectTypeNodeClass
	{
	  public:
		ServerType(void);
		~ServerType(void);
	};

}

#endif