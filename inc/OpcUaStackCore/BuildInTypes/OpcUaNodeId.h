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

	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const OpcUaNodeId& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, OpcUaNodeId& value);
}

#endif