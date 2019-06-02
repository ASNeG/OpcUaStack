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
		// encode requested publishing interval
		if (!JsonNumber::jsonEncode(pt, requestedPublishingInterval_, "RequestedPublishingInterval")) {
			Log(Error, "CreateSubscriptionRequest json encode error")
				.parameter("Element", "RequestedPublishingInterval");
			return false;
		}

		// encode requested lifetime count
		if (!JsonNumber::jsonEncode(pt, requestedPublishingInterval_, "RequestedPublishingInterval")) {
			Log(Error, "CreateSubscriptionRequest json encode error")
				.parameter("Element", "RequestedPublishingInterval");
			return false;
		}

		// encode requested max keepalive count
		if (!JsonNumber::jsonEncode(pt, requestedMaxKeepAliveCount_, "RequestedMaxKeepAliveCount")) {
			Log(Error, "CreateSubscriptionRequest json encode error")
				.parameter("Element", "RequestedMaxKeepAliveCount");
			return false;
		}

		// encode max notifications per publish
		if (!JsonNumber::jsonEncode(pt, maxNotificationsPerPublish_, "MaxNotificationsPerPublish")) {
			Log(Error, "CreateSubscriptionRequest json encode error")
				.parameter("Element", "MaxNotificationsPerPublish");
			return false;
		}

		// encode publishing enabled
		if (!JsonNumber::jsonEncode(pt, publishingEnabled_, "PublishingEnabled")) {
			Log(Error, "CreateSubscriptionRequest json encode error")
				.parameter("Element", "PublishingEnabled");
			return false;
		}

		// encode priority
		if (!JsonNumber::jsonEncode(pt, priority_, "Priority")) {
			Log(Error, "CreateSubscriptionRequest json encode error")
				.parameter("Element", "Priority");
			return false;
		}

		return true;
	}

	bool
	CreateSubscriptionRequest::jsonDecodeImpl(const boost::property_tree::ptree& pt)
	{
		boost::optional<const boost::property_tree::ptree&> tmpTree;

		// decode requested publishing interval
		tmpTree = pt.get_child_optional("RequestedPublishingInterval");
		if (tmpTree) {
			if (!JsonNumber::jsonDecode(pt, requestedPublishingInterval_, "RequestedPublishingInterval")) {
				Log(Error, "CreateSubscriptionRequest json decode error")
					.parameter("Element", "RequestedPublishingInterval");
				return false;
			}
		}

		// decode requested lifetime count
		tmpTree = pt.get_child_optional("RequestedPublishingInterval");
		if (tmpTree) {
			if (!JsonNumber::jsonDecode(pt, requestedPublishingInterval_, "RequestedPublishingInterval")) {
				Log(Error, "CreateSubscriptionRequest json decode error")
					.parameter("Element", "RequestedPublishingInterval");
				return false;
			}
		}

		// decode requested max keepalive count
		tmpTree = pt.get_child_optional("RequestedMaxKeepAliveCount");
		if (tmpTree) {
			if (!JsonNumber::jsonDecode(pt, requestedMaxKeepAliveCount_, "RequestedMaxKeepAliveCount")) {
				Log(Error, "CreateSubscriptionRequest json decode error")
					.parameter("Element", "RequestedMaxKeepAliveCount");
				return false;
			}
		}

		// decode max notifications per publish
		tmpTree = pt.get_child_optional("MaxNotificationsPerPublish");
		if (tmpTree) {
			if (!JsonNumber::jsonDecode(pt, maxNotificationsPerPublish_, "MaxNotificationsPerPublish")) {
				Log(Error, "CreateSubscriptionRequest json decode error")
					.parameter("Element", "MaxNotificationsPerPublish");
				return false;
			}
		}

		// decode publishing enabled
		tmpTree = pt.get_child_optional("PublishingEnabled");
		if (tmpTree) {
			if (!JsonNumber::jsonDecode(pt, publishingEnabled_, "PublishingEnabled")) {
				Log(Error, "CreateSubscriptionRequest json decode error")
					.parameter("Element", "PublishingEnabled");
				return false;
			}
		}

		// decode priority
		tmpTree = pt.get_child_optional("Priority");
		if (tmpTree) {
			if (!JsonNumber::jsonDecode(pt, priority_, "Priority")) {
				Log(Error, "CreateSubscriptionRequest json decode error")
					.parameter("Element", "Priority");
				return false;
			}
		}

		return true;
	}

}
