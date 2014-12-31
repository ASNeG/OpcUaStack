#ifndef __OpcUaStackCore_CreateSubscriptionResponse_h__
#define __OpcUaStackCore_CreateSubscriptionResponse_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"

namespace OpcUaStackCore
{

	class DLLEXPORT CreateSubscriptionResponse : public  ObjectPool<CreateSubscriptionResponse>
	{
	  public:
		typedef boost::shared_ptr<CreateSubscriptionResponse> SPtr;

		CreateSubscriptionResponse(void);
		virtual ~CreateSubscriptionResponse(void);

		void subscriptionId(const OpcUaUInt32& subscriptionId);
		OpcUaUInt32 subscriptionId(void) const;
		void revisedPublishingInterval(const OpcUaDouble& revisedPublishingInterval);
		OpcUaDouble revisedPublishingInterval(void) const;
		void revisedLifetimeCount(const OpcUaUInt32& revisedLifetimeCount);
		OpcUaUInt32 revisedLifetimeCount(void) const;
		void revisedMaxKeepAliveCount(const OpcUaUInt32& revisedMaxKeepAliveCount);
		OpcUaUInt32 revisedMaxKeepAliveCount(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaUInt32 subscriptionId_;
		OpcUaDouble revisedPublishingInterval_;
		OpcUaUInt32 revisedLifetimeCount_;
		OpcUaUInt32 revisedMaxKeepAliveCount_;
	};

}

#endif