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
		xxxx = 0
	} SecurityMode;

	class DLLEXPORT OpenSecureChannelRequest : public  ObjectPool<OpenSecureChannelRequest>
	{
	  public:
		OpenSecureChannelRequest(void);
		virtual ~OpenSecureChannelRequest(void);

		void requestHeader(const RequestHeader::SPtr requestHeaderSPtr);
		RequestHeader::SPtr requestHeader(void) const;
		void clientCertificate(const ApplicationInstanceCertificate::SPtr clientCertificate);
		ApplicationInstanceCertificate::SPtr clientCertificate(void) const;
		void requestType(const RequestType& requestType);
		RequestType requestType(void);
		void secureChannelId(const OpcUaByte *buf, OpcUaInt32 bufLen);
		void secureChannelId(OpcUaByte **buf, OpcUaInt32* bufLen) const;
		void securityMode(const SecurityMode& securityMode);
		SecurityMode securityMode(void) const;
		void securityPolicyUri(const std::string& securityPolicyUri);
		std::string securityPolicyUri(void) const;
		void clientNonce(OpcUaByte *buf, OpcUaInt32 bufLen);
		void clientNonce(OpcUaByte **buf, OpcUaInt32* bufLen) const;
		void requestedLifetime(const Duration& requestedLifetime);
		Duration requestedLifetime(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		RequestHeader::SPtr requestHeaderSPtr_;
		ApplicationInstanceCertificate::SPtr clientCertificate_;
		RequestType requestType_;
		OpcUaByteString secureChannelId_;
		SecurityMode securityMode_;
		OpcUaString securityPolicyUri_;
		OpcUaByteString clientNonce_;
		Duration requestedLifetime_;
	};

}

#endif