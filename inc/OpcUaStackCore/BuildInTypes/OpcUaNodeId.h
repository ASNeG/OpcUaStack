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


	class OpcUaNodeIdArray : public OpcUaArray<OpcUaNodeId::SPtr>, public ObjectPool<OpcUaNodeIdArray> {};

	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const OpcUaNodeIdArray& value);
	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const OpcUaNodeIdArray::SPtr& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, OpcUaNodeIdArray& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, OpcUaNodeIdArray::SPtr& value);

}

#endif