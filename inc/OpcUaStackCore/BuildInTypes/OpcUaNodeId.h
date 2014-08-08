#ifndef __OpcUaStackCore_OpcUaNodeId_h__
#define __OpcUaStackCore_OpcUaNodeId_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNodeIdBase.h"
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT OpcUaNodeId : public ObjectPool<OpcUaNodeId>, public OpcUaNodeIdBase
	{
	  public:
	    OpcUaNodeId(void);
		virtual ~OpcUaNodeId(void);
	};

	class OpcUaNodeIdArray : public OpcUaArray<OpcUaNodeId::SPtr, SPtrTypeCoder<OpcUaNodeId> >, public ObjectPool<OpcUaNodeIdArray> {};

}

#endif
