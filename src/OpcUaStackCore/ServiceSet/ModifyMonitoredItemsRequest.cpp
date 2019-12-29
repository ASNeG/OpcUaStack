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

#include "OpcUaStackCore/ServiceSet/ModifyMonitoredItemsRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa ModifyMonitoredItemsRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	ModifyMonitoredItemsRequest::ModifyMonitoredItemsRequest(void)
	: Object()
	, subscriptionId_()
	, timestampsToReturn_()
	, itemsToModifyArraySPtr_(boost::make_shared<MonitoredItemModifyRequestArray>())
	{
	}

	ModifyMonitoredItemsRequest::~ModifyMonitoredItemsRequest(void)
	{
	}
	
	void 
	ModifyMonitoredItemsRequest::subscriptionId(const OpcUaUInt32& subscriptionId)
	{
		subscriptionId_ = subscriptionId;
	}
	
	OpcUaUInt32
	ModifyMonitoredItemsRequest::subscriptionId(void) const
	{
		return subscriptionId_;
	}

	void
	ModifyMonitoredItemsRequest::timestampsToReturn(const TimestampsToReturn timestampsToReturn)
	{
		timestampsToReturn_ = timestampsToReturn;
	}
	
	TimestampsToReturn 
	ModifyMonitoredItemsRequest::timestampsToReturn(void)
	{
		return timestampsToReturn_;
	}
	
	void 
	ModifyMonitoredItemsRequest::itemsToModify(const MonitoredItemModifyRequestArray::SPtr itemsToModify)
	{
		itemsToModifyArraySPtr_ = itemsToModify;
	}
	
	MonitoredItemModifyRequestArray::SPtr
	ModifyMonitoredItemsRequest::itemsToModify(void) const
	{
		return itemsToModifyArraySPtr_;
	}
	
	bool
	ModifyMonitoredItemsRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= OpcUaNumber::opcUaBinaryEncode(os, subscriptionId_);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)timestampsToReturn_);
		rc &= itemsToModifyArraySPtr_->opcUaBinaryEncode(os);

		return rc;
	}
	
	bool
	ModifyMonitoredItemsRequest::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		OpcUaUInt32 tmp;
		rc &= OpcUaNumber::opcUaBinaryDecode(is, subscriptionId_);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, tmp);
		timestampsToReturn_ = (TimestampsToReturn)tmp;
		rc &= itemsToModifyArraySPtr_->opcUaBinaryDecode(is);

		return rc;
	}
}
