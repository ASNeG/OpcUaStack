#ifndef __OpcUaStackServer_BaseNodeClass_h__
#define __OpcUaStackServer_BaseNodeClass_h__

#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackServer/AddressSpaceModel/NodeClass.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class BaseNodeClass
	{
	  public: 
		BaseNodeClass(void);
		~BaseNodeClass(void);

		OpcUaNodeId& nodeId(void);
		NodeClass& nodeClass(void);
		OpcUaQualifiedName& browseName(void);
		OpcUaLocalizedText& displayName(void);

	  protected:
		NodeClass nodeClass_;

	  private:
		// attributes mandatorry
		OpcUaNodeId nodeId_;
		OpcUaQualifiedName browseName_;
		OpcUaLocalizedText displayName_;

		// attributes optional
		OpcUaLocalizedText::SPtr description_;
		OpcUaUInt32 writeMask_;
		OpcUaUInt32 UserWriteMask_;
	};

}

#endif