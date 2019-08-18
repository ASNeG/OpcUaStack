/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSet/PublishResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa PublishResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	PublishResponse::PublishResponse(void)
	: Object()
	, subscriptionId_()
	, availableSequenceNumberArraySPtr_(boost::make_shared<OpcUaUInt32Array>())
	, moreNotifications_()
	, notficiationMessageSPtr_(boost::make_shared<NotificationMessage>())
	, statusCodeArraySPtr_(boost::make_shared<OpcUaStatusCodeArray>())
	, diagnosticInfoArraySPtr_(boost::make_shared<OpcUaDiagnosticInfoArray>())
	{
	}

	PublishResponse::~PublishResponse(void)
	{
	}

	void 
	PublishResponse::subscriptionId(const OpcUaUInt32& subscriptionId)
	{
		subscriptionId_ = subscriptionId;
	}
	
	OpcUaUInt32 
	PublishResponse::subscriptionId(void) const
	{
		return subscriptionId_;
	}
	
	void 
	PublishResponse::availableSequenceNumbers(const OpcUaUInt32Array::SPtr availableSequenceNumbers)
	{
		availableSequenceNumberArraySPtr_ = availableSequenceNumbers;
	}

	OpcUaUInt32Array::SPtr&
	PublishResponse::availableSequenceNumbers(void)
	{
		return availableSequenceNumberArraySPtr_;
	}
	
	void 
	PublishResponse::moreNotifications(const OpcUaBoolean& moreNotifications)
	{
		moreNotifications_ = moreNotifications;
	}
	
	OpcUaBoolean 
	PublishResponse::moreNotifications(void) const
	{
		return moreNotifications_;
	}
	
	void 
	PublishResponse::notificationMessage(const NotificationMessage::SPtr notificationMessage)
	{
		notficiationMessageSPtr_ = notificationMessage;
	}
	
	NotificationMessage::SPtr
	PublishResponse::notificationMessage(void)
	{
		return notficiationMessageSPtr_;
	}

	void 
	PublishResponse::results(const OpcUaStatusCodeArray::SPtr results)
	{
		statusCodeArraySPtr_ = results;
	}
	
	OpcUaStatusCodeArray::SPtr 
	PublishResponse::results(void) const
	{
		return statusCodeArraySPtr_;
	}
	
	void 
	PublishResponse::diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfos;
	}

	OpcUaDiagnosticInfoArray::SPtr 
	PublishResponse::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}

	void 
	PublishResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, subscriptionId_);
		availableSequenceNumberArraySPtr_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, moreNotifications_);
		notficiationMessageSPtr_->opcUaBinaryEncode(os);
		statusCodeArraySPtr_->opcUaBinaryEncode(os);
		diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	PublishResponse::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, subscriptionId_);
		availableSequenceNumberArraySPtr_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, moreNotifications_);
		notficiationMessageSPtr_->opcUaBinaryDecode(is);
		statusCodeArraySPtr_->opcUaBinaryDecode(is);
		diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
	}
}
