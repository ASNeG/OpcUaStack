#ifndef __OpcUaStackCore_UnregisterNodesRequest_h__
#define __OpcUaStackCore_UnregisterNodesRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"

namespace OpcUaStackCore
{

	class DLLEXPORT UnregisterNodesRequest : public  ObjectPool<UnregisterNodesRequest>
	{
	  public:
		UnregisterNodesRequest(void);
		virtual ~UnregisterNodesRequest(void);

		void nodesToUnregister(const OpcUaNodeIdArray::SPtr nodesToUnregister);
		OpcUaNodeIdArray::SPtr nodesToUnregister(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaNodeIdArray::SPtr nodesToUnregisterArraySPtr_;
	};

}

#endif