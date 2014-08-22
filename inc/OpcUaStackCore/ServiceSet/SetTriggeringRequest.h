#ifndef __OpcUaStackCore_SetTriggeringRequest_h__
#define __OpcUaStackCore_SetTriggeringRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"

namespace OpcUaStackCore
{

	class DLLEXPORT SetTriggeringRequest : public  ObjectPool<SetTriggeringRequest>
	{
	  public:
		SetTriggeringRequest(void);
		virtual ~SetTriggeringRequest(void);

		void requestHeader(const RequestHeader::SPtr requestHeader);
		RequestHeader::SPtr requestHeader(void) const;
		void subscriptionId(const OpcUaUInt32& subscriptionId);
		OpcUaUInt32 subscriptionId(void) const;
		void triggeringItemId(const OpcUaUInt32& triggeringItemId);
		OpcUaUInt32 triggeringItemId(void) const;
		void linksToAdd(const OpcUaUInt32Array::SPtr linksToAdd);
		OpcUaUInt32Array::SPtr linksToAdd(void) const;
		void linksToRemove(const OpcUaUInt32Array::SPtr linksToRemove);
		OpcUaUInt32Array::SPtr linksToRemove(void) const;
		
		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		RequestHeader::SPtr requestHeaderSPtr_;
		OpcUaUInt32 subscriptionId_;
		OpcUaUInt32 triggeringItemId_;
		OpcUaUInt32Array::SPtr linksToAddArraySPtr_;
		OpcUaUInt32Array::SPtr linksToRemoveArraySPtr_;
	};

}

#endif