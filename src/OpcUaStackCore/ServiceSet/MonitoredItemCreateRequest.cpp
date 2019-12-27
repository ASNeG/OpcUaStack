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

#include "OpcUaStackCore/ServiceSet/MonitoredItemCreateRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa MonitoredItemCreateRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	MonitoredItemCreateRequest::MonitoredItemCreateRequest(void)
	: Object()
	, itemToMonitor_()
	, monitoringMode_(MonitoringMode_Reporting)
	, requestedParameters_()
	{
	}

	MonitoredItemCreateRequest::~MonitoredItemCreateRequest(void)
	{
	}

	void 
	MonitoredItemCreateRequest::itemToMonitor(const ReadValueId& itemToMonitor)
	{
		itemToMonitor_ = itemToMonitor;
	}
	
	ReadValueId& 
	MonitoredItemCreateRequest::itemToMonitor(void)
	{
		return itemToMonitor_;
	}
	
	void 
	MonitoredItemCreateRequest::monitoringMode(const MonitoringMode& monitoringMode)
	{
		monitoringMode_ = monitoringMode;
	}
	
	MonitoringMode& 
	MonitoredItemCreateRequest::monitoringMode(void)
	{
		return monitoringMode_;
	}
	
	void
	MonitoredItemCreateRequest::requestedParameters(const MonitoringParameters& requestedParameters)
	{
		requestedParameters_ = requestedParameters;
	}
	
	MonitoringParameters& 
	MonitoredItemCreateRequest::requestedParameters(void)
	{
		return requestedParameters_;
	}

	bool
	MonitoredItemCreateRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= itemToMonitor_.opcUaBinaryEncode(os);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)monitoringMode_);
		rc &= requestedParameters_.opcUaBinaryEncode(os);

		return rc;
	}
	
	bool
	MonitoredItemCreateRequest::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		OpcUaUInt32 tmp;
		rc &= itemToMonitor_.opcUaBinaryDecode(is);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, tmp);
		monitoringMode_ = (MonitoringMode)tmp;
		rc &= requestedParameters_.opcUaBinaryDecode(is);

		return rc;
	}

	bool
	MonitoredItemCreateRequest::jsonEncodeImpl(boost::property_tree::ptree &pt) const
	{
		bool rc = true;
		rc = rc & jsonObjectEncode(pt, itemToMonitor_, "ItemToMonitor");
		rc = rc & jsonNumberEncode(pt, (uint32_t)monitoringMode_, "MonitoringMode", true, (uint32_t)MonitoringMode::MonitoringMode_Sampling);
		rc = rc & jsonObjectEncode(pt, requestedParameters_, "RequestedParameters");
		return true;
	}

	bool
	MonitoredItemCreateRequest::jsonDecodeImpl(const boost::property_tree::ptree &pt)
	{
		bool rc = true;
		rc = rc & jsonObjectDecode(pt, itemToMonitor_, "ItemToMonitor");
		rc = rc & jsonNumberDecode(pt, *(uint32_t*)&monitoringMode_, "MonitoringMode", true, (uint32_t)MonitoringMode::MonitoringMode_Sampling);
		rc = rc & jsonObjectDecode(pt, requestedParameters_, "RequestedParameters");
		return true;
	}
}
