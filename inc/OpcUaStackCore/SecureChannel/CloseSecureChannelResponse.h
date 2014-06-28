#ifndef __OpcUaStackCore_CloseSecureChannelResponse_h__
#define __OpcUaStackCore_CloseSecureChannelResponse_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"
#include "OpcUaStackCore/SecureChannel/SecurityToken.h"


namespace OpcUaStackCore
{
	
	class DLLEXPORT CloseSecureChannelResponse : public  ObjectPool<CloseSecureChannelResponse>
	{
	  public:
		CloseSecureChannelResponse(void);
		virtual ~CloseSecureChannelResponse(void);

		void responseHeader(const ResponseHeader::SPtr responseHeader);
		ResponseHeader::SPtr responseHeader(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		ResponseHeader::SPtr responseHeaderSPtr_;
	};

}

#endif