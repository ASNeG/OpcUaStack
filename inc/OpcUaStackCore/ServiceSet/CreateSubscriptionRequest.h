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
		void requestedPublishingInterval(const OpcUaDouble& requestedPublishingInterval);
		OpcUaDouble requestedPublishingInterval(void) const;
		void requestedLifetimeCount(const OpcUaUInt32& requestedLifetimeCount);
		OpcUaUInt32 requestedLifetimeCount(void) const;
		void requestedMaxKeepAliveCount(const OpcUaUInt32& requestedMaxKeepAliveCount);
		OpcUaUInt32 requestedMaxKeepAliveCount(void) const;
		void maxNotificationsPerPublish(const OpcUaUInt32& maxNotificationsPerPublish);
		OpcUaUInt32 maxNotificationsPerPublish(void) const;
		void publishingEnabled(const OpcUaBoolean& publishingEnabled);
		OpcUaBoolean publishingEnabled(void) const;
		void priority(const OpcUaByte& priority);
		OpcUaByte priority(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		RequestHeader::SPtr requestHeaderSPtr_;
		OpcUaDouble requestedPublishingInterval_;
		OpcUaUInt32 requestedLifetimeCount_;
		OpcUaUInt32 requestedMaxKeepAliveCount_;
		OpcUaUInt32 maxNotificationsPerPublish_;
		OpcUaBoolean publishingEnabled_;
		OpcUaByte priority_;
	};

}

#endif