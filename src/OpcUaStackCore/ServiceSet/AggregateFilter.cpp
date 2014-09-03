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
	: ObjectPool<AggregateFilter>()
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
	
	ExtensibleParameterBase::BSPtr 
	AggregateFilter::factory(void)
	{
		return AggregateFilter::construct();
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