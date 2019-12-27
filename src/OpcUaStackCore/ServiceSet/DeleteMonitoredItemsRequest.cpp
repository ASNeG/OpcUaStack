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
	, monitoredItemIdArraySPtr_(boost::make_shared<OpcUaUInt32Array>())
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
	
	bool
	DeleteMonitoredItemsRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= OpcUaNumber::opcUaBinaryEncode(os, subscriptionId_);
		rc &= monitoredItemIdArraySPtr_->opcUaBinaryEncode(os);

		return rc;
	}
	
	bool
	DeleteMonitoredItemsRequest::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= OpcUaNumber::opcUaBinaryDecode(is, subscriptionId_);
		rc &= monitoredItemIdArraySPtr_->opcUaBinaryDecode(is);

		return rc;
	}

	bool
	DeleteMonitoredItemsRequest::jsonEncodeImpl(boost::property_tree::ptree& pt) const
	{
		bool rc = true;
		rc = rc & jsonNumberEncode(pt, subscriptionId_, "SubscriptionId");
		rc = rc & jsonArraySPtrEncode(pt, monitoredItemIdArraySPtr_, "MonitoredItemIds");
		return rc;
	}

	bool
	DeleteMonitoredItemsRequest::jsonDecodeImpl(const boost::property_tree::ptree& pt)
	{
		bool rc = true;
		rc = rc & jsonNumberDecode(pt, subscriptionId_, "SubscriptionId");
		rc = rc & jsonArraySPtrDecode(pt, monitoredItemIdArraySPtr_, "MonitoredItemIds");
		return rc;
	}

}
