#include "OpcUaStackCore/ServiceSet/AggregateFilterResult.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa AggregateFilterResult
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	AggregateFilterResult::AggregateFilterResult(void)
	: ObjectPool<AggregateFilterResult>()
	, revisedStartTime_()
	, revisedProcessingInterval_()
	{
	}

	AggregateFilterResult::~AggregateFilterResult(void)
	{
	}

	void 
	AggregateFilterResult::revisedStartTime(const UtcTime& time)
	{
		revisedStartTime_ = time;
	}
	
	void 
	AggregateFilterResult::revisedStartTime(const boost::posix_time::ptime& time)
	{
		revisedStartTime_.dateTime(time);
	}
	
	UtcTime 
	AggregateFilterResult::revisedStartTime(void) const
	{
		return revisedStartTime_;
	}
	
	void 
	AggregateFilterResult::revisedProcessingInterval(const OpcUaDouble& revisedProcessingInterval)
	{
		revisedProcessingInterval_ = revisedProcessingInterval;
	}
	
	OpcUaDouble 
	AggregateFilterResult::revisedProcessingInterval(void) const
	{
		return revisedProcessingInterval_;
	}

	ExtensibleParameterBase::BSPtr 
	AggregateFilterResult::factory(void)
	{
		return AggregateFilterResult::construct();
	}

	void 
	AggregateFilterResult::opcUaBinaryEncode(std::ostream& os) const
	{
		revisedStartTime_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, revisedProcessingInterval_);
	}
	
	void 
	AggregateFilterResult::opcUaBinaryDecode(std::istream& is)
	{
		revisedStartTime_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, revisedProcessingInterval_);
	}
}