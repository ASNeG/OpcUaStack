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

#include "OpcUaStackCore/ServiceSet/RepublishRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa RepublishRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	RepublishRequest::RepublishRequest(void)
	: Object()
	, subscriptionId_()
	, retransmitSequenceNumber_()
	{
	}

	RepublishRequest::~RepublishRequest(void)
	{
	}

	void 
	RepublishRequest::subscriptionId(const OpcUaUInt32 subscriptionId)
	{
		subscriptionId_ = subscriptionId;
	}

	OpcUaUInt32 
	RepublishRequest::subscriptionId(void) const
	{
		return subscriptionId_;
	}
	
	void 
	RepublishRequest::retransmitSequenceNumber(const OpcUaUInt32 retransmitSequenceNumber)
	{
		retransmitSequenceNumber_ = retransmitSequenceNumber;
	}
	
	OpcUaUInt32 
	RepublishRequest::retransmitSequenceNumber(void) const
	{
		return retransmitSequenceNumber_;
	}

	bool
	RepublishRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= OpcUaNumber::opcUaBinaryEncode(os, subscriptionId_);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, retransmitSequenceNumber_);

		return rc;
	}
	
	bool
	RepublishRequest::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= OpcUaNumber::opcUaBinaryDecode(is, subscriptionId_);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, retransmitSequenceNumber_);

		return rc;
	}
}
