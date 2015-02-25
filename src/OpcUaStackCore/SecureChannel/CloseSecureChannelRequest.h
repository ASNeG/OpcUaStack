#ifndef __OpcUaStackCore_CloseSecureChannelRequest_h__
#define __OpcUaStackCore_CloseSecureChannelRequest_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaByteString.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"


namespace OpcUaStackCore
{

	class DLLEXPORT CloseSecureChannelRequest : public  ObjectPool<CloseSecureChannelRequest>
	{
	  public:
		CloseSecureChannelRequest(void);
		virtual ~CloseSecureChannelRequest(void);

		void requestHeader(const RequestHeader::SPtr requestHeaderSPtr);
		RequestHeader::SPtr requestHeader(void) const;
		void secureChannelId(const OpcUaByte *buf, OpcUaInt32 bufLen);
		void secureChannelId(OpcUaByte **buf, OpcUaInt32* bufLen) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		RequestHeader::SPtr requestHeaderSPtr_;
		OpcUaByteString secureChannelId_;
		
	};

}

#endif