#ifndef __OpcUaStackServer_AttributeAccess_h__
#define __OpcUaStackServer_AttributeAccess_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/AddressSPaceModel/Attribute.h"

namespace OpcUaStackServer
{

	class DLLEXPORT AttributeAccess
	{
	  public:
		static bool copy(Attribute& attribute, OpcUaVariant& variant);
		static bool copy(OpcUaVariant& variant, Attribute& attribute);
	};

}

#endif