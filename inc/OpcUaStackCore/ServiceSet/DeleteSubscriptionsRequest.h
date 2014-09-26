#ifndef __OpcUaStackCore_DeleteSubscriptionsRequest_h__
#define __OpcUaStackCore_DeleteSubscriptionsRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"

namespace OpcUaStackCore
{

	class DLLEXPORT DeleteSubscriptionsRequest : public  ObjectPool<DeleteSubscriptionsRequest>
	{
	  public:
		DeleteSubscriptionsRequest(void);
		virtual ~DeleteSubscriptionsRequest(void);

		void subscriptionIds(const OpcUaUInt32Array::SPtr subscriptionIds);
		OpcUaUInt32Array::SPtr subscriptionIds(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaUInt32Array::SPtr subscriptionIdArraySPtr_;
	};

}

#endif