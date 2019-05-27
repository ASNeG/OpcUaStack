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

	void 
	MonitoredItemCreateRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		itemToMonitor_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)monitoringMode_);
		requestedParameters_.opcUaBinaryEncode(os);
	}
	
	void 
	MonitoredItemCreateRequest::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaUInt32 tmp;
		itemToMonitor_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		monitoringMode_ = (MonitoringMode)tmp;
		requestedParameters_.opcUaBinaryDecode(is);
	}

	bool
	MonitoredItemCreateRequest::jsonEncodeImpl(boost::property_tree::ptree &pt) const
	{
		// encode item to monitor
		if (!itemToMonitor_.jsonEncode(pt, "ItemToMonitor")) {
			Log(Error, "MonitoredItemCreateRequest json encode error")
				.parameter("Element", "ItemToMonitor");
			return false;
		}

		// encode  monitoring mode
		if (monitoringMode_ != MonitoringMode::MonitoringMode_Sampling) {
			auto monitoringMode = (uint32_t) monitoringMode_;
			if (!JsonNumber::jsonEncode(pt, monitoringMode, "MonitoringMode")) {
				Log(Error, "MonitoredItemCreateRequest json encode error")
					.parameter("Element", "MonitoringMode");
				return false;
			}
		}

		// encode requested parameters
		if (!requestedParameters_.jsonEncode(pt, "RequestedParameters")) {
			Log(Error, "MonitoredItemCreateRequest json encode error")
				.parameter("Element", "RequestedParameters");
			return false;
		}

		return true;
	}

	bool
	MonitoredItemCreateRequest::jsonDecodeImpl(const boost::property_tree::ptree &pt)
	{
		boost::optional<const boost::property_tree::ptree&> tmpTree;

		// decode item to monitor
		if (!itemToMonitor_.jsonDecode(pt, "ItemToMonitor")) {
			Log(Error, "MonitoredItemCreateRequest json decode error")
				.parameter("MonitoredItemCreateRequest", "ItemToMonitor");
			return false;
		}

		// decode  monitoring mode
		monitoringMode_ = MonitoringMode::MonitoringMode_Sampling;
		tmpTree = pt.get_child_optional("MonitoringMode");
		if (tmpTree) {
			uint32_t monitoringMode;
			if (!JsonNumber::jsonDecode(pt, monitoringMode, "MonitoringMode")) {
				Log(Error, "MonitoredItemCreateRequest json decode error")
					.parameter("Element", "MonitoringMode");
				return false;
			}
			monitoringMode_ = (MonitoringMode)monitoringMode;
		}

		// decode requested parameters
		if (!requestedParameters_.jsonDecode(pt, "RequestedParameters")) {
			Log(Error, "MonitoredItemCreateRequest json decode error")
				.parameter("Element", "RequestedParameters");
			return false;
		}

		return true;
	}
}
