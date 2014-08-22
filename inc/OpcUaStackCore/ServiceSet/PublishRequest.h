#ifndef __OpcUaStackCore_PublishRequest_h__
#define __OpcUaStackCore_PublishRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/ServiceSet/SubscriptionAcknowledgement.h"

namespace OpcUaStackCore
{

	class DLLEXPORT PublishRequest : public  ObjectPool<PublishRequest>
	{
	  public:
		PublishRequest(void);
		virtual ~PublishRequest(void);

		void requestHeader(const RequestHeader::SPtr requestHeader);
		RequestHeader::SPtr requestHeader(void) const;
		void subscriptionAcknowledgements(const SubscriptionAcknowledgementArray::SPtr subscriptionAcknowledgements);
		SubscriptionAcknowledgementArray::SPtr subscriptionAcknowledgements(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		RequestHeader::SPtr requestHeaderSPtr_;
		SubscriptionAcknowledgementArray::SPtr subscriptionAcknowledgementArraySPtr_;
	};

}

#endif