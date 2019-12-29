/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

	bool
	PublishResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= OpcUaNumber::opcUaBinaryEncode(os, subscriptionId_);
		rc &= availableSequenceNumberArraySPtr_->opcUaBinaryEncode(os);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, moreNotifications_);
		rc &= notficiationMessageSPtr_->opcUaBinaryEncode(os);
		rc &= statusCodeArraySPtr_->opcUaBinaryEncode(os);
		rc &= diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);

		return rc;
	}
	
	bool
	PublishResponse::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= OpcUaNumber::opcUaBinaryDecode(is, subscriptionId_);
		rc &= availableSequenceNumberArraySPtr_->opcUaBinaryDecode(is);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, moreNotifications_);
		rc &= notficiationMessageSPtr_->opcUaBinaryDecode(is);
		rc &= statusCodeArraySPtr_->opcUaBinaryDecode(is);
		rc &= diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);

		return rc;
	}
}
