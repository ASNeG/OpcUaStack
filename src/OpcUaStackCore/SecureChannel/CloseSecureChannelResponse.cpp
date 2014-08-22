#include "OpcUaStackCore/SecureChannel/CloseSecureChannelResponse.h"

namespace OpcUaStackCore
{

	CloseSecureChannelResponse::CloseSecureChannelResponse(void)
	: responseHeaderSPtr_(ResponseHeader::construct())
	{
	}
		
	CloseSecureChannelResponse::~CloseSecureChannelResponse(void)
	{
	}

	void 
	CloseSecureChannelResponse::responseHeader(const ResponseHeader::SPtr responseHeaderSPtr)
	{
		responseHeaderSPtr_ = responseHeaderSPtr;
	}

	ResponseHeader::SPtr  
	CloseSecureChannelResponse::responseHeader(void) const
	{
		return responseHeaderSPtr_;
	}

	void 
	CloseSecureChannelResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		responseHeaderSPtr_->opcUaBinaryEncode(os);
	}

	void 
	CloseSecureChannelResponse::opcUaBinaryDecode(std::istream& is)
	{
		responseHeaderSPtr_->opcUaBinaryDecode(is);
	}

}