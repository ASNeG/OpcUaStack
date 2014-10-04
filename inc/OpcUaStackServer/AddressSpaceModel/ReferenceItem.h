#ifndef __OpcUaStackServer_ReferenceItem_h__
#define __OpcUaStackServer_ReferenceItem_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT ReferenceItem : public ObjectPool<ReferenceItem>
	{
	  public:
		ReferenceItem(void);
		~ReferenceItem(void);

		bool operator==(const ReferenceItem& referenceItem);

		OpcUaNodeId nodeId_;
		bool isForward_;
	};

}

#endif