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

#include "OpcUaStackCore/ServiceSet/DeleteMonitoredItemsRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa DeleteMonitoredItemsRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	DeleteMonitoredItemsRequest::DeleteMonitoredItemsRequest(void)
	: Object()
	, subscriptionId_()
	, monitoredItemIdArraySPtr_(constructSPtr<OpcUaUInt32Array>())
	{
	}

	DeleteMonitoredItemsRequest::~DeleteMonitoredItemsRequest(void)
	{
	}
	
	void 
	DeleteMonitoredItemsRequest::subscriptionId(const OpcUaUInt32& subscriptionId)
	{
		subscriptionId_ = subscriptionId;
	}
	
	OpcUaUInt32
	DeleteMonitoredItemsRequest::subscriptionId(void) const
	{
		return subscriptionId_;
	}
	
	void 
	DeleteMonitoredItemsRequest::monitoredItemIds(const OpcUaUInt32Array::SPtr monitoredItemIds)
	{
		monitoredItemIdArraySPtr_ = monitoredItemIds;
	}
	
	OpcUaUInt32Array::SPtr 
	DeleteMonitoredItemsRequest::monitoredItemIds(void) const
	{
		return monitoredItemIdArraySPtr_;
	}
	
	void 
	DeleteMonitoredItemsRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, subscriptionId_);
		monitoredItemIdArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	DeleteMonitoredItemsRequest::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, subscriptionId_);
		monitoredItemIdArraySPtr_->opcUaBinaryDecode(is);
	}

	bool
	DeleteMonitoredItemsRequest::jsonEncodeImpl(boost::property_tree::ptree& pt) const
	{
		// encode subscription id
		if (!JsonNumber::jsonEncode(pt, subscriptionId_, "SubscriptionId")) {
			Log(Error, "DeleteMonitoredItemsRequest json encode error")
				.parameter("Element", "SubscriptionId");
			return false;
		}

		// encode monitored item id array
		if (!monitoredItemIdArraySPtr_->jsonEncode(pt, "MonitoredItemIds", "")) {
			Log(Error, "DeleteMonitoredItemsRequest json encode error")
				.parameter("Element", "MonitoredItemIds");
			return false;
		}

		return true;
	}

	bool
	DeleteMonitoredItemsRequest::jsonDecodeImpl(const boost::property_tree::ptree& pt)
	{
		// decode subscription id
		if (!JsonNumber::jsonDecode(pt, subscriptionId_, "SubscriptionId")) {
			Log(Error, "DeleteMonitoredItemsRequest json decode error")
				.parameter("Element", "SubscriptionId");
			return false;
		}

		// decode monitored item id array
		if (!monitoredItemIdArraySPtr_->jsonDecode(pt, "MonitoredItemIds", "")) {
			Log(Error, "DeleteMonitoredItemsRequest json decode error")
				.parameter("Element", "MonitoredItemIds");
			return false;
		}

		return true;
	}

}
