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

#include "OpcUaStackCore/ServiceSet/MonitoringParameters.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa MonitoringParameters
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	MonitoringParameters::MonitoringParameters(void)
	: Object()
	, clientHandle_()
	, samplingInterval_(500)
	, filter_()
	, queueSize_(1)
	, discardOldest_(true)
	{
	}

	MonitoringParameters::~MonitoringParameters(void)
	{
	}

	void 
	MonitoringParameters::clientHandle(const OpcUaUInt32& clientHandle)
	{
		clientHandle_ = clientHandle;
	}
	
	OpcUaUInt32 
	MonitoringParameters::clientHandle(void) const
	{
		return clientHandle_;
	}
	
	void 
	MonitoringParameters::samplingInterval(const OpcUaDouble& samplingInterval)
	{
		samplingInterval_ = samplingInterval;
	}
	
	OpcUaDouble 
	MonitoringParameters::samplingInterval(void) const
	{
		return samplingInterval_;
	}

	void 
	MonitoringParameters::filter(OpcUaExtensibleParameter& filter)
	{
		filter_ = filter;
	}
	
	OpcUaExtensibleParameter&
	MonitoringParameters::filter(void)
	{
		return filter_;
	}
	
	void 
	MonitoringParameters::queueSize(const OpcUaUInt32 queueSize)
	{
		queueSize_ = queueSize;
	}
	
	OpcUaUInt32 
	MonitoringParameters::queueSize(void) const
	{
		return queueSize_;
	}
	
	void 
	MonitoringParameters::discardOldest(const OpcUaBoolean discardOldest)
	{
		discardOldest_ = discardOldest;
	}
	
	OpcUaBoolean 
	MonitoringParameters::discardOldest(void) const
	{
		return discardOldest_;
	}
		
	void 
	MonitoringParameters::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, clientHandle_);
		OpcUaNumber::opcUaBinaryEncode(os, samplingInterval_);
		filter_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, queueSize_);
		OpcUaNumber::opcUaBinaryEncode(os, discardOldest_);
	}
	
	void 
	MonitoringParameters::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, clientHandle_);
		OpcUaNumber::opcUaBinaryDecode(is, samplingInterval_);
		filter_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, queueSize_);
		OpcUaNumber::opcUaBinaryDecode(is, discardOldest_);
	}

	bool
	MonitoringParameters::jsonEncodeImpl(boost::property_tree::ptree &pt) const
	{
		// encode client handle
		if (!JsonNumber::jsonEncode(pt, clientHandle_, "ClientHandle")) {
			Log(Error, "MonitoringParameters json encode error")
				.parameter("Element", "ClientHandle");
			return false;
		}

		// encode sampling interval
		if (!JsonNumber::jsonEncode(pt, samplingInterval_, "SamplingInterval")) {
			Log(Error, "MonitoringParameters json encode error")
				.parameter("Element", "SamplingInterval");
			return false;
		}

		// encode filter
		if (filter_.exist()) {
			if (!filter_.jsonEncode(pt, "Filter")) {
				Log(Error, "MonitoringParameters json encode error")
					.parameter("Element", "Filter");
				return false;
			}
		}

		// encode queue size
		if (!JsonNumber::jsonEncode(pt, queueSize_, "QueueSize")) {
			Log(Error, "MonitoringParameters json encode error")
				.parameter("Element", "QueueSize");
			return false;
		}

		// encode discard oldest
		if (!JsonNumber::jsonEncode(pt, discardOldest_, "DiscardOldest")) {
			Log(Error, "MonitoringParameters json encode error")
				.parameter("Element", "DiscardOldest");
			return false;
		}

		return true;
	}

	bool
	MonitoringParameters::jsonDecodeImpl(const boost::property_tree::ptree &pt)
	{
		boost::optional<const boost::property_tree::ptree&> tmpTree;

		// decode client handle
		if (!JsonNumber::jsonDecode(pt, clientHandle_, "ClientHandle")) {
			Log(Error, "MonitoringParameters json decode error")
				.parameter("Element", "ClientHandle");
			return false;
		}

		// decode sampling interval
		if (!JsonNumber::jsonDecode(pt, samplingInterval_, "SamplingInterval")) {
			Log(Error, "MonitoringParameters json decode error")
				.parameter("Element", "SamplingInterval");
			return false;
		}

		// decode filter
		auto filter = pt.get_child_optional("Filter");
		if (filter) {
			if (!filter_.jsonDecode(pt, "Filter")) {
				Log(Error, "MonitoringParameters json decode error")
					.parameter("Element", "Filter");
				return false;
			}
		}

		// decode queue size
		queueSize_ = 0;
		auto queueSize =  pt.get_child_optional("QueueSize");
		if (queueSize) {
			if (!JsonNumber::jsonDecode(pt, queueSize_, "QueueSize")) {
				Log(Error, "MonitoringParameters json decode error")
					.parameter("Element", "QueueSize");
				return false;
			}
		}

		// decode discard oldest
		discardOldest_ = true;
		auto discardOldest =  pt.get_child_optional("DiscardOldest");
		if (discardOldest) {
			if (!JsonNumber::jsonDecode(pt, discardOldest_, "DiscardOldest")) {
				Log(Error, "MonitoringParameters json decode error")
					.parameter("Element", "DiscardOldest");
				return false;
			}
		}

		return true;
	}
}
