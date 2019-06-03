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

#include "OpcUaStackCore/ServiceSet/CreateMonitoredItemsRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa CreateMonitoredItemsRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	CreateMonitoredItemsRequest::CreateMonitoredItemsRequest(void)
	: Object()
	, subscriptionId_()
	, timestampsToReturn_(TimestampsToReturn_Both)
	, itemsToCreateArraySPtr_(constructSPtr<MonitoredItemCreateRequestArray>())
	{
	}

	CreateMonitoredItemsRequest::~CreateMonitoredItemsRequest(void)
	{
	}
		
	void 
	CreateMonitoredItemsRequest::subscriptionId(const OpcUaUInt32& subscriptionId)
	{
		subscriptionId_ = subscriptionId;
	}
	
	OpcUaUInt32
	CreateMonitoredItemsRequest::subscriptionId(void) const
	{
		return subscriptionId_;
	}

	void
	CreateMonitoredItemsRequest::timestampsToReturn(const TimestampsToReturn timestampsToReturn)
	{
		timestampsToReturn_ = timestampsToReturn;
	}
	
	TimestampsToReturn 
	CreateMonitoredItemsRequest::timestampsToReturn(void)
	{
		return timestampsToReturn_;
	}
	
	void 
	CreateMonitoredItemsRequest::itemsToCreate(const MonitoredItemCreateRequestArray::SPtr itemsToCreate)
	{
		itemsToCreateArraySPtr_ = itemsToCreate;
	}
	
	MonitoredItemCreateRequestArray::SPtr
	CreateMonitoredItemsRequest::itemsToCreate(void) const
	{
		return itemsToCreateArraySPtr_;
	}
	
	void 
	CreateMonitoredItemsRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, subscriptionId_);
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)timestampsToReturn_);
		itemsToCreateArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	CreateMonitoredItemsRequest::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaUInt32 tmp;
		OpcUaNumber::opcUaBinaryDecode(is, subscriptionId_);
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		timestampsToReturn_ = (TimestampsToReturn)tmp;
		itemsToCreateArraySPtr_->opcUaBinaryDecode(is);
	}

	bool
	CreateMonitoredItemsRequest::jsonEncodeImpl(boost::property_tree::ptree& pt) const
	{
		// encode subscription id
		if (!JsonNumber::jsonEncode(pt, subscriptionId_, "SubscriptionId")) {
			Log(Error, "CreateMonitoredItemsRequest json encode error")
				.parameter("Element", "SubscriptionId");
			return false;
		}

		// encode timestamps to return
		uint32_t timestampsToReturn = timestampsToReturn_;
		if (!JsonNumber::jsonEncode(pt, timestampsToReturn, "TimestampsToReturn")) {
			Log(Error, "CreateMonitoredItemsRequest json encode error")
				.parameter("Element", "TimestampsToReturn");
			return false;
		}

		// encode items to create array
		if (!itemsToCreateArraySPtr_->jsonEncode(pt, "ItemsToCreate")) {
			Log(Error, "CreateMonitoredItemsRequest json encode error")
				.parameter("Element", "ItemsToCreate");
			return false;
		}

		return true;
	}

	bool
	CreateMonitoredItemsRequest::jsonDecodeImpl(const boost::property_tree::ptree& pt)
	{
		// decode subscription id
		if (!JsonNumber::jsonDecode(pt, subscriptionId_, "SubscriptionId")) {
			Log(Error, "CreateMonitoredItemsRequest json decode error")
				.parameter("Element", "SubscriptionId");
			return false;
		}

		// decode timestamps to return
		timestampsToReturn_ = TimestampsToReturn_Source;
		auto timestampsToReturn = pt.get_child_optional("TimestampsToReturn");
		if (timestampsToReturn) {
			uint32_t ttr;
			if (!JsonNumber::jsonDecode(pt, ttr, "TimestampsToReturn")) {
				Log(Error, "CreateMonitoredItemsRequest json decode error")
					.parameter("Element", "TimestampsToReturn");
				return false;
			}
			timestampsToReturn_ = (TimestampsToReturn)ttr;
		}

		// decode items to create array
		if (!itemsToCreateArraySPtr_->jsonDecode(pt, "ItemsToCreate")) {
			Log(Error, "CreateMonitoredItemsRequest json decode error")
				.parameter("Element", "ItemsToCreate");
			return false;
		}

		return true;
	}
}
