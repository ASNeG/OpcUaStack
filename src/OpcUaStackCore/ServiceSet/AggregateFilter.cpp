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

#include "OpcUaStackCore/ServiceSet/AggregateFilter.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa AggregateFilter
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	AggregateFilter::AggregateFilter(void)
	: Object()
	, ExtensibleParameterBase()
	, startTime_()
	, aggregateType_()
	, processingInterval_()
	, aggregateConfiguration_()
	{
	}

	AggregateFilter::~AggregateFilter(void)
	{
	}

	void 
	AggregateFilter::startTime(const UtcTime& startTime)
	{
		startTime_ = startTime;
	}
	
	void 
	AggregateFilter::startTime(const boost::posix_time::ptime& startTime)
	{
		startTime_.dateTime(startTime);
	}
	
	UtcTime 
	AggregateFilter::startTime(void) const
	{
		return startTime_;
	}
	void 
	AggregateFilter::aggregateType(const OpcUaNodeId& aggregateType)
	{
		aggregateType_ = aggregateType;
	}
	
	OpcUaNodeId& 
	AggregateFilter::aggregateType(void)
	{
		return aggregateType_;
	}
	
	void 
	AggregateFilter::processingInterval(const OpcUaDouble& processingInterval)
	{
		processingInterval_ = processingInterval;
	}
	
	OpcUaDouble 
	AggregateFilter::processingInterval(void)
	{
		return processingInterval_;
	}
	
	void 
	AggregateFilter::aggregateConfiguration(const AggregateConfiguration& aggregateConfiguration)
	{
		aggregateConfiguration_ = aggregateConfiguration;
	}
	
	AggregateConfiguration& 
	AggregateFilter::aggregateConfiguration(void)
	{
		return aggregateConfiguration_;
	}
	
	ExtensibleParameterBase::SPtr
	AggregateFilter::factory(void)
	{
		return constructSPtr<AggregateFilter>();
	}

	void 
	AggregateFilter::opcUaBinaryEncode(std::ostream& os) const
	{
		startTime_.opcUaBinaryEncode(os);
		aggregateType_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, processingInterval_);
		aggregateConfiguration_.opcUaBinaryEncode(os);
	}
	
	void 
	AggregateFilter::opcUaBinaryDecode(std::istream& is)
	{
		startTime_.opcUaBinaryDecode(is);
		aggregateType_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, processingInterval_);
		aggregateConfiguration_.opcUaBinaryDecode(is);
	}
}
