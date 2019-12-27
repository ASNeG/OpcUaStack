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

#include "OpcUaStackCore/ServiceSet/ModifySubscriptionResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa ModifySubscriptionResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	ModifySubscriptionResponse::ModifySubscriptionResponse(void)
	: Object()
	, revisedPublishingInterval_()
	, revisedLifetimeCount_()
	, revisedMaxKeepAliveCount_()
	{
	}

	ModifySubscriptionResponse::~ModifySubscriptionResponse(void)
	{
	}

	void 
	ModifySubscriptionResponse::revisedPublishingInterval(const OpcUaDouble& revisedPublishingInterval)
	{
		revisedPublishingInterval_ = revisedPublishingInterval;
	}
	
	OpcUaDouble 
	ModifySubscriptionResponse::revisedPublishingInterval(void) const
	{
		return revisedPublishingInterval_;
	}

	void 
	ModifySubscriptionResponse::revisedLifetimeCount(const OpcUaUInt32& revisedLifetimeCount)
	{
		revisedLifetimeCount_ = revisedLifetimeCount;
	}
	
	OpcUaUInt32 
	ModifySubscriptionResponse::revisedLifetimeCount(void) const
	{
		return revisedLifetimeCount_;
	}
	
	void 
	ModifySubscriptionResponse::revisedMaxKeepAliveCount(const OpcUaUInt32& revisedMaxKeepAliveCount)
	{
		revisedMaxKeepAliveCount_ = revisedMaxKeepAliveCount;
	}
	
	OpcUaUInt32 
	ModifySubscriptionResponse::revisedMaxKeepAliveCount(void) const
	{
		return revisedMaxKeepAliveCount_;
	}

	bool
	ModifySubscriptionResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= OpcUaNumber::opcUaBinaryEncode(os, revisedPublishingInterval_);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, revisedLifetimeCount_);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, revisedMaxKeepAliveCount_);

		return rc;
	}
	
	bool
	ModifySubscriptionResponse::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= OpcUaNumber::opcUaBinaryDecode(is, revisedPublishingInterval_);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, revisedLifetimeCount_);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, revisedMaxKeepAliveCount_);

		return rc;
	}
}
