#ifndef __OpcUaStackCore_CreateSubscriptionRequest_h__
#define __OpcUaStackCore_CreateSubscriptionRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"

namespace OpcUaStackCore
{

	class DLLEXPORT CreateSubscriptionRequest : public  ObjectPool<CreateSubscriptionRequest>
	{
	  public:
		CreateSubscriptionRequest(void);
		virtual ~CreateSubscriptionRequest(void);

		void requestHeader(const RequestHeader::SPtr requestHeader);
		RequestHeader::SPtr requestHeader(void) const;
		void requestedPublishingInterval(const OpcUaInt64& requestedPublishingInterval);
		OpcUaInt64 requestedPublishingInterval(void) const;
		void requestedLifetimeCount(const OpcUaInt32& requestedLifetimeCount);
		OpcUaInt32 requestedLifetimeCount(void) const;
		void requestedMaxKeepAliveCount(const OpcUaInt32& requestedMaxKeepAliveCount);
		OpcUaInt32 requestedMaxKeepAliveCount(void) const;
		void maxNotificationsPerPublish(const OpcUaInt32& maxNotificationsPerPublish);
		OpcUaInt32 maxNotificationsPerPublish(void) const;
		void publishingEnabled(const OpcUaBoolean& publishingEnabled);
		OpcUaBoolean publishingEnabled(void) const;
		void priority(const OpcUaByte& priority);
		OpcUaByte priority(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		RequestHeader::SPtr requestHeaderSPtr_;
		OpcUaInt64 requestedPublishingInterval_;
		OpcUaInt32 requestedLifetimeCount_;
		OpcUaInt32 requestedMaxKeepAliveCount_;
		OpcUaInt32 maxNotificationsPerPublish_;
		OpcUaBoolean publishingEnabled_;
		OpcUaByte priority_;
	};

}

#endif