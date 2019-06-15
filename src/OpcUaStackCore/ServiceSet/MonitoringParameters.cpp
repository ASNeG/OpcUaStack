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
		bool rc = true;
		rc = rc & jsonNumberEncode(pt, clientHandle_, "ClientHandle");
		rc = rc & jsonNumberEncode(pt, samplingInterval_, "SamplingInterval");
		rc = rc & jsonObjectEncode(pt, filter_, "Filter", true);
		rc = rc & jsonNumberEncode(pt, queueSize_, "QueueSize", true, (OpcUaUInt32)0);
		rc = rc & jsonNumberEncode(pt, discardOldest_, "DiscardOldest", true, (OpcUaBoolean)true);
		return rc;
	}

	bool
	MonitoringParameters::jsonDecodeImpl(const boost::property_tree::ptree &pt)
	{
		bool rc = true;
		rc = rc & jsonNumberDecode(pt, clientHandle_, "ClientHandle");
		rc = rc & jsonNumberDecode(pt, samplingInterval_, "SamplingInterval");
		rc = rc & jsonObjectDecode(pt, filter_, "Filter", true);
		rc = rc & jsonNumberDecode(pt, queueSize_, "QueueSize", true, (OpcUaUInt32)0);
		rc = rc & jsonNumberDecode(pt, discardOldest_, "DiscardOldest", true, (OpcUaBoolean)true);
		return rc;
	}
}
