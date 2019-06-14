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
	
	void 
	CreateSubscriptionRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, requestedPublishingInterval_);
		OpcUaNumber::opcUaBinaryEncode(os, requestedLifetimeCount_);
		OpcUaNumber::opcUaBinaryEncode(os, requestedMaxKeepAliveCount_);
		OpcUaNumber::opcUaBinaryEncode(os, maxNotificationsPerPublish_);
		OpcUaNumber::opcUaBinaryEncode(os, publishingEnabled_);
		OpcUaNumber::opcUaBinaryEncode(os, priority_);
	}
	
	void 
	CreateSubscriptionRequest::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, requestedPublishingInterval_);
		OpcUaNumber::opcUaBinaryDecode(is, requestedLifetimeCount_);
		OpcUaNumber::opcUaBinaryDecode(is, requestedMaxKeepAliveCount_);
		OpcUaNumber::opcUaBinaryDecode(is, maxNotificationsPerPublish_);
		OpcUaNumber::opcUaBinaryDecode(is, publishingEnabled_);
		OpcUaNumber::opcUaBinaryDecode(is, priority_);
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
