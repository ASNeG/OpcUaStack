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

#include "OpcUaStackCore/ServiceSet/SetMonitoringModeRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa SetMonitoringModeRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	SetMonitoringModeRequest::SetMonitoringModeRequest(void)
	: Object()
	, subscriptionId_()
	, monitoringMode_()
	, monitoredItemIdArraySPtr_(boost::make_shared<OpcUaUInt32Array>())
	{
	}

	SetMonitoringModeRequest::~SetMonitoringModeRequest(void)
	{
	}
	
	void 
	SetMonitoringModeRequest::subscriptionId(const OpcUaUInt32& subscriptionId)
	{
		subscriptionId_ = subscriptionId;
	}
	
	OpcUaUInt32
	SetMonitoringModeRequest::subscriptionId(void) const
	{
		return subscriptionId_;
	}

	void 
	SetMonitoringModeRequest::monitoringMode(const MonitoringMode monitoringMode)
	{
		monitoringMode_ = monitoringMode;
	}
	
	MonitoringMode 
	SetMonitoringModeRequest::monitoringMode(void) const
	{
		return monitoringMode_;
	}
	
	void 
	SetMonitoringModeRequest::monitoredItemIds(const OpcUaUInt32Array::SPtr monitoredItemIds)
	{
		monitoredItemIdArraySPtr_ = monitoredItemIds;
	}

	OpcUaUInt32Array::SPtr 
	SetMonitoringModeRequest::monitoredItemIds(void) const
	{
		return monitoredItemIdArraySPtr_;
	}
	
	void 
	SetMonitoringModeRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, subscriptionId_);
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaInt32)monitoringMode_);
		monitoredItemIdArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	SetMonitoringModeRequest::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaInt32 tmp;
		OpcUaNumber::opcUaBinaryDecode(is, subscriptionId_);
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		monitoringMode_ = (MonitoringMode)tmp;
		monitoredItemIdArraySPtr_->opcUaBinaryDecode(is);
	}
}
