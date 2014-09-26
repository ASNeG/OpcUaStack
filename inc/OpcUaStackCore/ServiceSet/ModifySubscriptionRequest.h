#ifndef __OpcUaStackCore_ModifySubscriptionRequest_h__
#define __OpcUaStackCore_ModifySubscriptionRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ModifySubscriptionRequest : public  ObjectPool<ModifySubscriptionRequest>
	{
	  public:
		ModifySubscriptionRequest(void);
		virtual ~ModifySubscriptionRequest(void);

		void subscriptionId(const OpcUaUInt32& subscriptionId);
		OpcUaUInt32 subscriptionId(void) const;
		void requestedPublishingInterval(const OpcUaDouble& requestedPublishingInterval);
		OpcUaDouble requestedPublishingInterval(void) const;
		void requestedLifetimeCount(const OpcUaUInt32& requestedLifetimeCount);
		OpcUaUInt32 requestedLifetimeCount(void) const;
		void requestedMaxKeepAliveCount(const OpcUaUInt32& requestedMaxKeepAliveCount);
		OpcUaUInt32 requestedMaxKeepAliveCount(void) const;
		void maxNotificationsPerPublish(const OpcUaUInt32& maxNotificationsPerPublish);
		OpcUaUInt32 maxNotificationsPerPublish(void) const;
		void priority(const OpcUaByte& priority);
		OpcUaByte priority(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaUInt32 subscriptionId_;
		OpcUaDouble requestedPublishingInterval_;
		OpcUaUInt32 requestedLifetimeCount_;
		OpcUaUInt32 requestedMaxKeepAliveCount_;
		OpcUaUInt32 maxNotificationsPerPublish_;
		OpcUaByte priority_;
	};

}

#endif