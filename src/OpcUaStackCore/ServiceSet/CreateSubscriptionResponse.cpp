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

#include "OpcUaStackCore/ServiceSet/CreateSubscriptionResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa CreateSubscriptionResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	CreateSubscriptionResponse::CreateSubscriptionResponse(void)
	: Object()
	, subscriptionId_()
	, revisedPublishingInterval_()
	, revisedLifetimeCount_()
	, revisedMaxKeepAliveCount_()
	{
	}

	CreateSubscriptionResponse::~CreateSubscriptionResponse(void)
	{
	}

	void 
	CreateSubscriptionResponse::subscriptionId(const OpcUaUInt32& subscriptionId)
	{
		subscriptionId_ = subscriptionId;
	}

	OpcUaUInt32 
	CreateSubscriptionResponse::subscriptionId(void) const
	{
		return subscriptionId_;
	}
	
	void 
	CreateSubscriptionResponse::revisedPublishingInterval(const OpcUaDouble& revisedPublishingInterval)
	{
		revisedPublishingInterval_ = revisedPublishingInterval;
	}
	
	OpcUaDouble 
	CreateSubscriptionResponse::revisedPublishingInterval(void) const
	{
		return revisedPublishingInterval_;
	}

	void 
	CreateSubscriptionResponse::revisedLifetimeCount(const OpcUaUInt32& revisedLifetimeCount)
	{
		revisedLifetimeCount_ = revisedLifetimeCount;
	}
	
	OpcUaUInt32 
	CreateSubscriptionResponse::revisedLifetimeCount(void) const
	{
		return revisedLifetimeCount_;
	}
	
	void 
	CreateSubscriptionResponse::revisedMaxKeepAliveCount(const OpcUaUInt32& revisedMaxKeepAliveCount)
	{
		revisedMaxKeepAliveCount_ = revisedMaxKeepAliveCount;
	}
	
	OpcUaUInt32 
	CreateSubscriptionResponse::revisedMaxKeepAliveCount(void) const
	{
		return revisedMaxKeepAliveCount_;
	}

	bool
	CreateSubscriptionResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= OpcUaNumber::opcUaBinaryEncode(os, subscriptionId_);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, revisedPublishingInterval_);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, revisedLifetimeCount_);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, revisedMaxKeepAliveCount_);

		return rc;
	}
	
	bool
	CreateSubscriptionResponse::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= OpcUaNumber::opcUaBinaryDecode(is, subscriptionId_);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, revisedPublishingInterval_);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, revisedLifetimeCount_);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, revisedMaxKeepAliveCount_);

		return rc;
	}

	bool
	CreateSubscriptionResponse::jsonEncodeImpl(boost::property_tree::ptree& pt) const
	{
		bool rc = true;
		rc = rc & jsonNumberEncode(pt, subscriptionId_, "SubscriptionId");
		rc = rc & jsonNumberEncode(pt, revisedPublishingInterval_, "RevisedPublishingInterval");
		rc = rc & jsonNumberEncode(pt, revisedLifetimeCount_, "RevisedLifetimeCount");
		rc = rc & jsonNumberEncode(pt, revisedMaxKeepAliveCount_, "RevisedMaxKeepAliveCount");
		return rc;
	}

	bool
	CreateSubscriptionResponse::jsonDecodeImpl(const boost::property_tree::ptree& pt)
	{
		bool rc = true;
		rc = rc & jsonNumberDecode(pt, subscriptionId_, "SubscriptionId");
		rc = rc & jsonNumberDecode(pt, revisedPublishingInterval_, "RevisedPublishingInterval");
		rc = rc & jsonNumberDecode(pt, revisedLifetimeCount_, "RevisedLifetimeCount");
		rc = rc & jsonNumberDecode(pt, revisedMaxKeepAliveCount_, "RevisedMaxKeepAliveCount");
		return rc;
	}
}
