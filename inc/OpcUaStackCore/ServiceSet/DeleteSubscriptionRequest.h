#ifndef __OpcUaStackCore_DeleteSubscriptionRequest_h__
#define __OpcUaStackCore_DeleteSubscriptionRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"

namespace OpcUaStackCore
{

	class DLLEXPORT DeleteSubscriptionRequest : public  ObjectPool<DeleteSubscriptionRequest>
	{
	  public:
		DeleteSubscriptionRequest(void);
		virtual ~DeleteSubscriptionRequest(void);

		void requestHeader(const RequestHeader::SPtr requestHeader);
		RequestHeader::SPtr requestHeader(void) const;
		void subscriptionIds(const OpcUaUInt32Array::SPtr subscriptionIds);
		OpcUaUInt32Array::SPtr subscriptionIds(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		RequestHeader::SPtr requestHeaderSPtr_;
		OpcUaUInt32Array::SPtr subscriptionIdArraySPtr_;
	};

}

#endif