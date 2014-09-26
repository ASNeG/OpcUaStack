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
	, notificationMessageSPtr_(NotificationMessage::construct())
	{
	}

	RepublishResponse::~RepublishResponse(void)
	{
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
		notificationMessageSPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	RepublishResponse::opcUaBinaryDecode(std::istream& is)
	{
		notificationMessageSPtr_->opcUaBinaryDecode(is);
	}
}