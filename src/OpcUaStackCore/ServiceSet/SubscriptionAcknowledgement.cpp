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

#include "OpcUaStackCore/ServiceSet/SubscriptionAcknowledgement.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa SubscriptionAcknowledgement
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	SubscriptionAcknowledgement::SubscriptionAcknowledgement(void)
	: Object()
	, subscriptionId_()
	, sequenceNumber_()
	{
	}

	SubscriptionAcknowledgement::~SubscriptionAcknowledgement(void)
	{
	}

	void 
	SubscriptionAcknowledgement::subscriptionId(const OpcUaUInt32& subscriptionId)
	{
		subscriptionId_ = subscriptionId;
	}
	
	OpcUaUInt32 
	SubscriptionAcknowledgement::subscriptionId(void) const
	{
		return subscriptionId_;
	}
	
	void 
	SubscriptionAcknowledgement::sequenceNumber(const OpcUaUInt32& sequenceNumber)
	{
		sequenceNumber_ = sequenceNumber;
	}
	
	OpcUaUInt32 
	SubscriptionAcknowledgement::sequenceNumber(void) const
	{
		return sequenceNumber_;
	}
	
	bool
	SubscriptionAcknowledgement::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= OpcUaNumber::opcUaBinaryEncode(os, subscriptionId_);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, sequenceNumber_);

		return rc;
	}
	
	bool
	SubscriptionAcknowledgement::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= OpcUaNumber::opcUaBinaryDecode(is, subscriptionId_);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, sequenceNumber_);

		return rc;
	}
}
