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

#include "OpcUaStackCore/ServiceSet/PublishRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa PublishRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	PublishRequest::PublishRequest(void)
	: Object()
	, subscriptionAcknowledgementArraySPtr_(boost::make_shared<SubscriptionAcknowledgementArray>())
	{
	}

	PublishRequest::~PublishRequest(void)
	{
	}

	void 
	PublishRequest::subscriptionAcknowledgements(const SubscriptionAcknowledgementArray::SPtr subscriptionAcknowledgements)
	{
		subscriptionAcknowledgementArraySPtr_ = subscriptionAcknowledgements;
	}
	
	SubscriptionAcknowledgementArray::SPtr 
	PublishRequest::subscriptionAcknowledgements(void) const
	{
		return subscriptionAcknowledgementArraySPtr_;
	}

	void 
	PublishRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		subscriptionAcknowledgementArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	PublishRequest::opcUaBinaryDecode(std::istream& is)
	{
		subscriptionAcknowledgementArraySPtr_->opcUaBinaryDecode(is);
	}
}
