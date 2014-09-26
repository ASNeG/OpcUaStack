#ifndef __OpcUaStackCore_RepublishRequest_h__
#define __OpcUaStackCore_RepublishRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/ServiceSet/SubscriptionAcknowledgement.h"

namespace OpcUaStackCore
{

	class DLLEXPORT RepublishRequest : public  ObjectPool<RepublishRequest>
	{
	  public:
		RepublishRequest(void);
		virtual ~RepublishRequest(void);

		void subscriptionId(const OpcUaUInt32 subscriptionId);
		OpcUaUInt32 subscriptionId(void) const;
		void retransmitSequenceNumber(const OpcUaUInt32 retransmitSequenceNumber);
		OpcUaUInt32 retransmitSequenceNumber(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaUInt32 subscriptionId_;
		OpcUaUInt32 retransmitSequenceNumber_;
	};

}

#endif