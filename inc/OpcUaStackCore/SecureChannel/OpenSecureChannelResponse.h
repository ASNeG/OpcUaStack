#ifndef __OpcUaStackCore_OpenSecureChannelResponse_h__
#define __OpcUaStackCore_OpenSecureChannelResponse_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"
#include "OpcUaStackCore/SecureChannel/SecurityToken.h"


namespace OpcUaStackCore
{
	
	class DLLEXPORT OpenSecureChannelResponse : public  ObjectPool<OpenSecureChannelResponse>
	{
	  public:
		OpenSecureChannelResponse(void);
		virtual ~OpenSecureChannelResponse(void);

		void responseHeader(const ResponseHeader::SPtr responseHeader);
		ResponseHeader::SPtr responseHeader(void) const;
		void securityToken(const SecurityToken::SPtr securityToken);
		SecurityToken::SPtr securityToken(void);
		void serverNonce(const OpcUaByte* buf, OpcUaInt32 bufLen);
		void serverNonce(OpcUaByte** buf, OpcUaInt32 *bufLen) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		ResponseHeader::SPtr responseHeaderSPtr_;
		SecurityToken::SPtr securityTokenSPtr_;	
		OpcUaByteString serverNonce_;
	};

}

#endif