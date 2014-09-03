#include "OpcUaStackCore/ServiceSet/ReadEventDetails.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa ReadEventDetails
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	ReadEventDetails::ReadEventDetails(void)
	: ObjectPool<ReadEventDetails>()
	, numValuesPerNode_()
	, startTime_()
	, endTime_()
	, filterSPtr_(ExtensibleParameter::construct())
	{
	}

	ReadEventDetails::~ReadEventDetails(void)
	{
	}

	void 
	ReadEventDetails::numValuesPerNode(const OpcUaUInt32& numValuesPerNode)
	{
		numValuesPerNode_ = numValuesPerNode;
	}
	
	OpcUaUInt32 
	ReadEventDetails::numValuesPerNode(void) const
	{
		return numValuesPerNode_;
	}
	
	void 
	ReadEventDetails::startTime(const UtcTime& startTime)
	{
		startTime_ = startTime;
	}
	
	void 
	ReadEventDetails::startTime(const boost::posix_time::ptime& startTime)
	{
		startTime_.dateTime(startTime);
	}
	
	UtcTime& 
	ReadEventDetails::startTime(void)
	{
		return startTime_;
	}
	
	void 
	ReadEventDetails::endTime(const UtcTime& endTime)
	{
		endTime_ = endTime;
	}

	void 
	ReadEventDetails::endTime(const boost::posix_time::ptime& endTime)
	{
		endTime_.dateTime(endTime);
	}
	
	UtcTime& 
	ReadEventDetails::endTime(void)
	{
		return endTime_;
	}

	void 
	ReadEventDetails::filter(const ExtensibleParameter::SPtr filter)
	{
		filterSPtr_ = filter;
	}
	
	ExtensibleParameter::SPtr 
	ReadEventDetails::filter(void)
	{
		return filterSPtr_;
	}

	ExtensibleParameterBase::BSPtr 
	ReadEventDetails::factory(void)
	{
		return ReadEventDetails::construct();
	}

	void 
	ReadEventDetails::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, numValuesPerNode_);
		startTime_.opcUaBinaryEncode(os);
		endTime_.opcUaBinaryEncode(os);
		filterSPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	ReadEventDetails::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, numValuesPerNode_);
		startTime_.opcUaBinaryDecode(is);
		endTime_.opcUaBinaryDecode(is);
		filterSPtr_->opcUaBinaryDecode(is);
	}
}