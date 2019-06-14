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
		bool rc = true;
		rc = rc & jsonNumberEncode(pt, subscriptionId_, "SubscriptionId");
		rc = rc & jsonNumberEncode(pt, (uint32_t)timestampsToReturn_, "TimestampsToReturn");
		rc = rc & jsonArraySPtrEncode(pt, itemsToCreateArraySPtr_, "ItemsToCreate");
		return true;
	}

	bool
	CreateMonitoredItemsRequest::jsonDecodeImpl(const boost::property_tree::ptree& pt)
	{
		bool rc = true;
		rc = rc & jsonNumberDecode(pt, subscriptionId_, "SubscriptionId");
		rc = rc & jsonNumberDecode(pt, *(uint32_t*)&timestampsToReturn_, "TimestampsToReturn");
		rc = rc & jsonArraySPtrDecode(pt, itemsToCreateArraySPtr_, "ItemsToCreate");
		return true;
	}
}
