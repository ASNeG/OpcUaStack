#ifndef __OpcUaStackCore_DeleteMonitoredItemsRequest_h__
#define __OpcUaStackCore_DeleteMonitoredItemsRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"

namespace OpcUaStackCore
{

	class DLLEXPORT DeleteMonitoredItemsRequest : public  ObjectPool<DeleteMonitoredItemsRequest>
	{
	  public:
		DeleteMonitoredItemsRequest(void);
		virtual ~DeleteMonitoredItemsRequest(void);

		void subscriptionId(const OpcUaUInt32& subscriptionId);
		OpcUaUInt32 subscriptionId(void) const;
		void monitoredItemIds(const OpcUaUInt32Array::SPtr monitoredItemIds);
		OpcUaUInt32Array::SPtr monitoredItemIds(void) const;
		
		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaUInt32 subscriptionId_;
		OpcUaUInt32Array::SPtr monitoredItemIdArraySPtr_;
	};

}

#endif