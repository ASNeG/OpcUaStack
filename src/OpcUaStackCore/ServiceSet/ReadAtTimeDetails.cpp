#include "OpcUaStackCore/ServiceSet/ReadAtTimeDetails.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa ReadAtTimeDetails
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	ReadAtTimeDetails::ReadAtTimeDetails(void)
	: ObjectPool<ReadAtTimeDetails>()
	, reqTimeArraySPtr_(UtcTimeArray::construct())
	{
	}

	ReadAtTimeDetails::~ReadAtTimeDetails(void)
	{
	}

	void 
	ReadAtTimeDetails::reqTimes(const UtcTimeArray::SPtr reqTimes)
	{
		reqTimeArraySPtr_ = reqTimes;
	}
	
	UtcTimeArray::SPtr 
	ReadAtTimeDetails::reqTimes(void) const
	{
		return reqTimeArraySPtr_;
	}

	ExtensibleParameterBase::BSPtr 
	ReadAtTimeDetails::factory(void)
	{
		return ReadAtTimeDetails::construct();
	}

	void 
	ReadAtTimeDetails::opcUaBinaryEncode(std::ostream& os) const
	{
		reqTimeArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	ReadAtTimeDetails::opcUaBinaryDecode(std::istream& is)
	{
		reqTimeArraySPtr_->opcUaBinaryDecode(is);
	}
}