#ifndef __OpcUaStackServer_BaseNodeClass_h__
#define __OpcUaStackServer_BaseNodeClass_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackServer/AddressSpaceModel/Attribute.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT BaseNodeClass
	{
	  public: 
		BaseNodeClass(void);
		BaseNodeClass(NodeClass nodeClass);
		~BaseNodeClass(void);

		NodeIdAttribute& nodeId(void);
		NodeClassAttribute& nodeClass(void);
		BrowseNameAttribute& browseName(void);
		DisplayNameAttribute& displayName(void);
		DescriptionAttribute& description(void);
		WriteMaskAttribute& writeMask(void);
		UserWriteMaskAttribute& userWriteMask(void);

	  private:
		NodeIdAttribute nodeId_;
		NodeClassAttribute nodeClass_;
		BrowseNameAttribute browseName_;
		DisplayNameAttribute displayName_;
		DescriptionAttribute description_;
		WriteMaskAttribute writeMask_;
		UserWriteMaskAttribute userWriteMask_;
	};

}

#endif