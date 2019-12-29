/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

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
	: Object()
	, notificationMessageSPtr_(boost::make_shared<NotificationMessage>())
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

	bool
	RepublishResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		return notificationMessageSPtr_->opcUaBinaryEncode(os);
	}
	
	bool
	RepublishResponse::opcUaBinaryDecode(std::istream& is)
	{
		return notificationMessageSPtr_->opcUaBinaryDecode(is);
	}
}
