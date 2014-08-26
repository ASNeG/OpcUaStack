#ifndef __OpcUaStacServer_BaseObjectType_h__
#define __OpcUaStacServer_BaseObjectType_h__

#include "OpcUaStackServer/AddressSpaceModel/ObjectTypeNodeClass.h"

namespace OpcUaStackServer
{

	class BaseObjectType : public ObjectTypeNodeClass
	{
	  public:
		BaseObjectType(void);
		~BaseObjectType(void);
	};

}

#endif