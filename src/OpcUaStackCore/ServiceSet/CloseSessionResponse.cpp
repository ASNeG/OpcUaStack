#include "OpcUaStackCore/ServiceSet/CloseSessionResponse.h"

namespace OpcUaStackCore
{

	CloseSessionResponse::CloseSessionResponse(void)
	: responseHeader_(ResponseHeader::construct())
	{
	}

	CloseSessionResponse::~CloseSessionResponse(void)
	{
	}

	void 
	CloseSessionResponse::responseHeader(const ResponseHeader::SPtr requestHeader)
	{
		responseHeader_ = requestHeader;
	}

	ResponseHeader::SPtr 
	CloseSessionResponse::responseHeader(void) const
	{
		return responseHeader_;
	}

	void 
	CloseSessionResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		responseHeader_->opcUaBinaryEncode(os);
	}

	void 
	CloseSessionResponse::opcUaBinaryDecode(std::istream& is)
	{
		responseHeader_->opcUaBinaryDecode(is);
	}

}