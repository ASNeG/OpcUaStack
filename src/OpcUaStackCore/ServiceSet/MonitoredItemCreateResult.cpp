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

#include "OpcUaStackCore/ServiceSet/MonitoredItemCreateResult.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa MonitoredItemCreateResult 
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	MonitoredItemCreateResult::MonitoredItemCreateResult(void)
	: Object()
	, statusCode_()
	, monitoredItemId_()
	, revisedSamplingInterval_()
	, revisedQueueSize_()
	, filterResult_()
	{
	}

	MonitoredItemCreateResult::~MonitoredItemCreateResult(void)
	{
	}

	void 
	MonitoredItemCreateResult::statusCode(const OpcUaStatusCode& statusCode)
	{
		statusCode_ = statusCode;
	}
	
	OpcUaStatusCode 
	MonitoredItemCreateResult::statusCode(void) const
	{
		return statusCode_;
	}
	
	void 
	MonitoredItemCreateResult::monitoredItemId(const OpcUaUInt32& monitoredItemId)
	{
		monitoredItemId_ = monitoredItemId;
	}
	
	OpcUaUInt32 
	MonitoredItemCreateResult::monitoredItemId(void) const
	{
		return monitoredItemId_;
	}
	
	void 
	MonitoredItemCreateResult::revisedSamplingInterval(const OpcUaDouble& revisedSamplingInterval)
	{
		revisedSamplingInterval_ = revisedSamplingInterval;
	}
	
	OpcUaDouble 
	MonitoredItemCreateResult::revisedSamplingInterval(void) const
	{
		return revisedSamplingInterval_;
	}
	
	void 
	MonitoredItemCreateResult::revisedQueueSize(const OpcUaUInt32& revisedQueueSize)
	{
		revisedQueueSize_ = revisedQueueSize;
	}
	
	OpcUaUInt32 
	MonitoredItemCreateResult::revisedQueueSize(void) const
	{
		return revisedQueueSize_;
	}
	
	void 
	MonitoredItemCreateResult::filterResult(const ExtensibleParameter& filterResult)
	{
		filterResult_ = filterResult;
	}
	
	ExtensibleParameter& 
	MonitoredItemCreateResult::filterResult(void)
	{
		return filterResult_;
	}

	void 
	MonitoredItemCreateResult::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, statusCode_);
		OpcUaNumber::opcUaBinaryEncode(os, monitoredItemId_);
		OpcUaNumber::opcUaBinaryEncode(os, revisedSamplingInterval_);
		OpcUaNumber::opcUaBinaryEncode(os, revisedQueueSize_);
		filterResult_.opcUaBinaryEncode(os);
	}
	
	void 
	MonitoredItemCreateResult::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaInt32 tmp;
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		statusCode_ = (OpcUaStatusCode)tmp;
		OpcUaNumber::opcUaBinaryDecode(is, monitoredItemId_);
		OpcUaNumber::opcUaBinaryDecode(is, revisedSamplingInterval_);
		OpcUaNumber::opcUaBinaryDecode(is, revisedQueueSize_);
		filterResult_.opcUaBinaryDecode(is);
	}
}
