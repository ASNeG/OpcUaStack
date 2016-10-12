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

#include "OpcUaStackCore/ServiceSet/MonitoredItemModifyResult.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa MonitoredItemModifyResult 
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	MonitoredItemModifyResult::MonitoredItemModifyResult(void)
	: Object()
	, statusCode_()
	, revisedSamplingInterval_()
	, revisedQueueSize_()
	, filterResult_()
	{
	}

	MonitoredItemModifyResult::~MonitoredItemModifyResult(void)
	{
	}

	void 
	MonitoredItemModifyResult::statusCode(const OpcUaStatusCode& statusCode)
	{
		statusCode_ = statusCode;
	}
	
	OpcUaStatusCode 
	MonitoredItemModifyResult::statusCode(void) const
	{
		return statusCode_;
	}
	
	void 
	MonitoredItemModifyResult::revisedSamplingInterval(const OpcUaDouble& revisedSamplingInterval)
	{
		revisedSamplingInterval_ = revisedSamplingInterval;
	}
	
	OpcUaDouble 
	MonitoredItemModifyResult::revisedSamplingInterval(void) const
	{
		return revisedSamplingInterval_;
	}
	
	void 
	MonitoredItemModifyResult::revisedQueueSize(const OpcUaUInt32& revisedQueueSize)
	{
		revisedQueueSize_ = revisedQueueSize;
	}
	
	OpcUaUInt32 
	MonitoredItemModifyResult::revisedQueueSize(void) const
	{
		return revisedQueueSize_;
	}
	
	void 
	MonitoredItemModifyResult::filterResult(const ExtensibleParameter& filterResult)
	{
		filterResult_ = filterResult;
	}
	
	ExtensibleParameter& 
	MonitoredItemModifyResult::filterResult(void)
	{
		return filterResult_;
	}

	void 
	MonitoredItemModifyResult::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, statusCode_);
		OpcUaNumber::opcUaBinaryEncode(os, revisedSamplingInterval_);
		OpcUaNumber::opcUaBinaryEncode(os, revisedQueueSize_);
		filterResult_.opcUaBinaryEncode(os);
	}
	
	void 
	MonitoredItemModifyResult::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaInt32 tmp;
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		statusCode_ = (OpcUaStatusCode)tmp;
		OpcUaNumber::opcUaBinaryDecode(is, revisedSamplingInterval_);
		OpcUaNumber::opcUaBinaryDecode(is, revisedQueueSize_);
		filterResult_.opcUaBinaryDecode(is);
	}
}
