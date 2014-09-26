#ifndef __OpcUaStackCore_UnregisterNodesResponse_h__
#define __OpcUaStackCore_UnregisterNodesResponse_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/ServiceSet/BrowseResult.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"

namespace OpcUaStackCore
{

	class DLLEXPORT UnregisterNodesResponse : public ObjectPool<UnregisterNodesResponse>
	{
	  public:
	    UnregisterNodesResponse(void);
		virtual ~UnregisterNodesResponse(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
	};
}

#endif