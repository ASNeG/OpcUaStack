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

#include "OpcUaStackCore/ServiceSet/CreateSubscriptionRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa CreateSubscriptionRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	CreateSubscriptionRequest::CreateSubscriptionRequest(void)
	: Object()
	, requestedPublishingInterval_(100)
	, requestedLifetimeCount_(2400)
	, requestedMaxKeepAliveCount_(10)
	, maxNotificationsPerPublish_(65536)
	, publishingEnabled_(true)
	, priority_(0)
	{
	}

	CreateSubscriptionRequest::~CreateSubscriptionRequest(void)
	{
	}

	void 
	CreateSubscriptionRequest::requestedPublishingInterval(const OpcUaDouble& requestedPublishingInterval)
	{
		requestedPublishingInterval_ = requestedPublishingInterval;
	}
	
	OpcUaDouble 
	CreateSubscriptionRequest::requestedPublishingInterval(void) const
	{
		return requestedPublishingInterval_;
	}

	void 
	CreateSubscriptionRequest::requestedLifetimeCount(const OpcUaUInt32& requestedLifetimeCount)
	{
		requestedLifetimeCount_ = requestedLifetimeCount;
	}

	OpcUaUInt32 
	CreateSubscriptionRequest::requestedLifetimeCount(void) const
	{
		return requestedLifetimeCount_;
	}

	void 
	CreateSubscriptionRequest::requestedMaxKeepAliveCount(const OpcUaUInt32& requestedMaxKeepAliveCount)
	{
		requestedMaxKeepAliveCount_ = requestedMaxKeepAliveCount;
	}

	OpcUaUInt32 
	CreateSubscriptionRequest::requestedMaxKeepAliveCount(void) const
	{
		return requestedMaxKeepAliveCount_;
	}

	void 
	CreateSubscriptionRequest::maxNotificationsPerPublish(const OpcUaUInt32& maxNotificationsPerPublish)
	{
		maxNotificationsPerPublish_ = maxNotificationsPerPublish;
	}
	
	OpcUaUInt32 
	CreateSubscriptionRequest::maxNotificationsPerPublish(void) const
	{
		return maxNotificationsPerPublish_;
	}
	
	void 
	CreateSubscriptionRequest::publishingEnabled(const OpcUaBoolean& publishingEnabled)
	{
		publishingEnabled_ = publishingEnabled;
	}

	OpcUaBoolean 
	CreateSubscriptionRequest::publishingEnabled(void) const
	{
		return publishingEnabled_;
	}
	
	void 
	CreateSubscriptionRequest::priority(const OpcUaByte& priority)
	{
		priority_ = priority;
	}

	OpcUaByte 
	CreateSubscriptionRequest::priority(void) const
	{
		return priority_;
	}
	
	bool
	CreateSubscriptionRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= OpcUaNumber::opcUaBinaryEncode(os, requestedPublishingInterval_);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, requestedLifetimeCount_);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, requestedMaxKeepAliveCount_);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, maxNotificationsPerPublish_);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, publishingEnabled_);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, priority_);

		return rc;
	}
	
	bool
	CreateSubscriptionRequest::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= OpcUaNumber::opcUaBinaryDecode(is, requestedPublishingInterval_);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, requestedLifetimeCount_);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, requestedMaxKeepAliveCount_);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, maxNotificationsPerPublish_);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, publishingEnabled_);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, priority_);

		return rc;
	}

	bool
	CreateSubscriptionRequest::jsonEncodeImpl(boost::property_tree::ptree& pt) const
	{
		bool rc = true;
		rc = rc & jsonNumberEncode(pt, requestedPublishingInterval_, "RequestedPublishingInterval");
		rc = rc & jsonNumberEncode(pt, requestedLifetimeCount_, "RequestedLifetimeCount");
		rc = rc & jsonNumberEncode(pt, requestedMaxKeepAliveCount_, "RequestedMaxKeepAliveCount");
		rc = rc & jsonNumberEncode(pt, maxNotificationsPerPublish_, "MaxNotificationsPerPublish");
		rc = rc & jsonNumberEncode(pt, publishingEnabled_, "PublishingEnabled");
		rc = rc & jsonNumberEncode(pt, priority_, "Priority");
		return rc;
	}

	bool
	CreateSubscriptionRequest::jsonDecodeImpl(const boost::property_tree::ptree& pt)
	{
		bool rc = true;
		rc = rc & jsonNumberDecode(pt, requestedPublishingInterval_, "RequestedPublishingInterval", true, (OpcUaDouble)100);
		rc = rc & jsonNumberDecode(pt, requestedLifetimeCount_, "RequestedLifetimeCount", true, (OpcUaUInt32)2400);
		rc = rc & jsonNumberDecode(pt, requestedMaxKeepAliveCount_, "RequestedMaxKeepAliveCount", true, (OpcUaUInt32)10);
		rc = rc & jsonNumberDecode(pt, maxNotificationsPerPublish_, "MaxNotificationsPerPublish", true, (OpcUaUInt32)65536);
		rc = rc & jsonNumberDecode(pt, publishingEnabled_, "PublishingEnabled", true, (OpcUaBoolean)true);
		rc = rc & jsonNumberDecode(pt, priority_, "Priority", true, (OpcUaByte)0);
		return rc;
	}

}
