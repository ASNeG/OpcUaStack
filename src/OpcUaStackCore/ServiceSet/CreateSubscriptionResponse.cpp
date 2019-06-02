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

	void 
	CreateSubscriptionResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, subscriptionId_);
		OpcUaNumber::opcUaBinaryEncode(os, revisedPublishingInterval_);
		OpcUaNumber::opcUaBinaryEncode(os, revisedLifetimeCount_);
		OpcUaNumber::opcUaBinaryEncode(os, revisedMaxKeepAliveCount_);
	}
	
	void 
	CreateSubscriptionResponse::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, subscriptionId_);
		OpcUaNumber::opcUaBinaryDecode(is, revisedPublishingInterval_);
		OpcUaNumber::opcUaBinaryDecode(is, revisedLifetimeCount_);
		OpcUaNumber::opcUaBinaryDecode(is, revisedMaxKeepAliveCount_);
	}

	bool
	CreateSubscriptionResponse::jsonEncodeImpl(boost::property_tree::ptree& pt) const
	{
		// encode subscription id
		if (!JsonNumber::jsonEncode(pt, subscriptionId_, "SubscriptionId")) {
			Log(Error, "CreateSubscriptionResponse json encode error")
				.parameter("Element", "SubscriptionId");
			return false;
		}

		// encode revised publishing interval
		if (!JsonNumber::jsonEncode(pt, revisedPublishingInterval_, "RevisedPublishingInterval")) {
			Log(Error, "CreateSubscriptionResponse json encode error")
				.parameter("Element", "RevisedPublishingInterval");
			return false;
		}

		// encode revised life time count
		if (!JsonNumber::jsonEncode(pt, revisedLifetimeCount_, "RevisedLifetimeCount")) {
			Log(Error, "CreateSubscriptionResponse json encode error")
				.parameter("Element", "RevisedLifetimeCount");
			return false;
		}

		// encode revised max keepalive count
		if (!JsonNumber::jsonEncode(pt, revisedMaxKeepAliveCount_, "RevisedMaxKeepAliveCount")) {
			Log(Error, "CreateSubscriptionResponse json encode error")
				.parameter("Element", "RevisedMaxKeepAliveCount");
			return false;
		}

		return true;
	}

	bool
	CreateSubscriptionResponse::jsonDecodeImpl(const boost::property_tree::ptree& pt)
	{
		// decode subscription id
		if (!JsonNumber::jsonDecode(pt, subscriptionId_, "SubscriptionId")) {
			Log(Error, "CreateSubscriptionResponse json decode error")
				.parameter("Element", "SubscriptionId");
			return false;
		}

		// decode revised publishing interval
		if (!JsonNumber::jsonDecode(pt, revisedPublishingInterval_, "RevisedPublishingInterval")) {
			Log(Error, "CreateSubscriptionResponse json decode error")
				.parameter("Element", "RevisedPublishingInterval");
			return false;
		}

		// decode revised life time count
		if (!JsonNumber::jsonDecode(pt, revisedLifetimeCount_, "RevisedLifetimeCount")) {
			Log(Error, "CreateSubscriptionResponse json decode error")
				.parameter("Element", "RevisedLifetimeCount");
			return false;
		}

		// decode revised max keepalive count
		if (!JsonNumber::jsonDecode(pt, revisedMaxKeepAliveCount_, "RevisedMaxKeepAliveCount")) {
			Log(Error, "CreateSubscriptionResponse json decode error")
				.parameter("Element", "RevisedMaxKeepAliveCount");
			return false;
		}

		return true;
	}
}
