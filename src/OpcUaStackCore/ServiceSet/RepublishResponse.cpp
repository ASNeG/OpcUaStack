#include "OpcUaStackCore/ServiceSet/RepublishResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa RepublishResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	RepublishResponse::RepublishResponse(void)
	: ObjectPool<RepublishResponse>()
	, responseHeaderSPtr_(ResponseHeader::construct())
	, notificationMessageSPtr_(NotificationMessage::construct())
	{
	}

	RepublishResponse::~RepublishResponse(void)
	{
	}

	void 
	RepublishResponse::responseHeader(const ResponseHeader::SPtr responseHeader)
	{
		responseHeaderSPtr_ = responseHeader;
	}

	ResponseHeader::SPtr 
	RepublishResponse::responseHeader(void) const
	{
		return responseHeaderSPtr_;
	}

	void 
	RepublishResponse::notificationMessage(const NotificationMessage::SPtr notificationMessage)
	{
		notificationMessageSPtr_ = notificationMessage;
	}
	
	NotificationMessage::SPtr 
	RepublishResponse::notificationMessage(void) const
	{
		return notificationMessageSPtr_;
	}

	void 
	RepublishResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		responseHeaderSPtr_->opcUaBinaryEncode(os);
		notificationMessageSPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	RepublishResponse::opcUaBinaryDecode(std::istream& is)
	{
		responseHeaderSPtr_->opcUaBinaryDecode(is);
		notificationMessageSPtr_->opcUaBinaryDecode(is);
	}
}