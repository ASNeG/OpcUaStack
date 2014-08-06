#ifndef __OpcUaStackCore_OpenSecureChannelRequest_h__
#define __OpcUaStackCore_OpenSecureChannelRequest_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaByteString.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaString.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/SecureChannel/ApplicationInstanceCertificate.h"

namespace OpcUaStackCore
{
	typedef enum 
	{
		ISSUE = 0,
		RENEW = 1
	} RequestType;

	typedef enum
	{
		None = 1
	} SecurityMode;

	class DLLEXPORT OpenSecureChannelRequest : public  ObjectPool<OpenSecureChannelRequest>
	{
	  public:
		OpenSecureChannelRequest(void);
		virtual ~OpenSecureChannelRequest(void);

		void requestHeader(const RequestHeader::SPtr requestHeaderSPtr);
		RequestHeader::SPtr requestHeader(void) const;
		void clientProtocolVersion(const OpcUaInt32& clientProtocolVersion);
		OpcUaInt32 clientProtocolVersion(void);
		void requestType(const RequestType& requestType);
		RequestType requestType(void);
		void securityMode(const SecurityMode& securityMode);
		SecurityMode securityMode(void) const;
		void clientNonce(OpcUaByte **buf, OpcUaInt32* bufLen) const;
		void clientNonce(OpcUaByte *buf, OpcUaInt32 bufLen);
		void requestedLifetime(const OpcUaInt32& requestedLifetime);
		OpcUaInt32 requestedLifetime(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		RequestHeader::SPtr requestHeaderSPtr_;
		OpcUaInt32 clientProtocolVersion_;
		RequestType requestType_;
		SecurityMode securityMode_;
		OpcUaByteString clientNonce_;
		OpcUaInt32 requestedLifetime_;
	};

}

#endif