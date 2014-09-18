#ifndef __OpcUaStackCore_CreateMonitoredItemsRequest_h__
#define __OpcUaStackCore_CreateMonitoredItemsRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/ServiceSet/MonitoredItemCreateRequest.h"
#include "OpcUaStackCore/ServiceSet/TimestampsToReturn.h"

namespace OpcUaStackCore
{

	class DLLEXPORT CreateMonitoredItemsRequest : public  ObjectPool<CreateMonitoredItemsRequest>
	{
	  public:
		CreateMonitoredItemsRequest(void);
		virtual ~CreateMonitoredItemsRequest(void);

		void requestHeader(const RequestHeader::SPtr requestHeader);
		RequestHeader::SPtr requestHeader(void) const;
		void subscriptionId(const OpcUaUInt32& subscriptionId);
		OpcUaUInt32 subscriptionId(void) const;
		void timestampsToReturn(const TimestampsToReturn timestampsToReturn);
		TimestampsToReturn timestampsToReturn(void);
		void itemsToCreate(const MonitoredItemCreateRequestArray::SPtr itemsToCreate);
		MonitoredItemCreateRequestArray::SPtr itemsToCreate(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		RequestHeader::SPtr requestHeaderSPtr_;
		OpcUaUInt32 subscriptionId_;
		TimestampsToReturn timestampsToReturn_;
		MonitoredItemCreateRequestArray::SPtr itemsToCreateArraySPtr_;
	};

}

#endif