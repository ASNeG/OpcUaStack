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
	MonitoringParameters::filter(const ExtensibleParameter filter)
	{
		filter_ = filter;
	}
	
	ExtensibleParameter 
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
}
