#ifndef __OpcUaStackCore_ModifySubscriptionResponse_h__
#define __OpcUaStackCore_ModifySubscriptionResponse_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ModifySubscriptionResponse : public  ObjectPool<ModifySubscriptionResponse>
	{
	  public:
		ModifySubscriptionResponse(void);
		virtual ~ModifySubscriptionResponse(void);

		void revisedPublishingInterval(const OpcUaDouble& revisedPublishingInterval);
		OpcUaDouble revisedPublishingInterval(void) const;
		void revisedLifetimeCount(const OpcUaUInt32& revisedLifetimeCount);
		OpcUaUInt32 revisedLifetimeCount(void) const;
		void revisedMaxKeepAliveCount(const OpcUaUInt32& revisedMaxKeepAliveCount);
		OpcUaUInt32 revisedMaxKeepAliveCount(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaDouble revisedPublishingInterval_;
		OpcUaUInt32 revisedLifetimeCount_;
		OpcUaUInt32 revisedMaxKeepAliveCount_;
	};

}

#endif