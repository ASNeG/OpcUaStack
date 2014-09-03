#include "OpcUaStackCore/ServiceSet/RegisterServerResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa RegisterServerResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	RegisterServerResponse::RegisterServerResponse(void)
	: ObjectPool<RegisterServerResponse>()
	, responseHeaderSPtr_(ResponseHeader::construct())
	{
	}

	RegisterServerResponse::~RegisterServerResponse(void)
	{
	}

	void 
	RegisterServerResponse::responseHeader(const ResponseHeader::SPtr responseHeaderSPtr)
	{
		responseHeaderSPtr_ = responseHeaderSPtr;
	}

	ResponseHeader::SPtr 
	RegisterServerResponse::responseHeader(void) const
	{
		return responseHeaderSPtr_;
	}

	void 
	RegisterServerResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		responseHeaderSPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	RegisterServerResponse::opcUaBinaryDecode(std::istream& is)
	{
		responseHeaderSPtr_->opcUaBinaryDecode(is);
	}

}