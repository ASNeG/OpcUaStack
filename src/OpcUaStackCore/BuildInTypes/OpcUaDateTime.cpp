#include "OpcUaStackCore/BuildInTypes/OpcUaDateTime.h"

namespace OpcUaStackCore
{

	 boost::posix_time::ptime OpcUaDateTime::nullTime_ = boost::posix_time::from_iso_string("16010101T120000.000000000");

	OpcUaDateTime::OpcUaDateTime(void)
	: dateTime_(0)
	{
	}

	OpcUaDateTime::~OpcUaDateTime(void)
	{
	}

	void 
	OpcUaDateTime::dateTime(const boost::posix_time::ptime& dateTime)
	{
		boost::posix_time::time_duration td = dateTime - nullTime_;
		if (td.is_negative()) {
			dateTime_ = 0;
		}
		else {
			dateTime_ = td.total_microseconds() * 10;
		}
	}

	boost::posix_time::ptime
	OpcUaDateTime::dateTime(void) const
	{
		boost::posix_time::time_duration td = boost::posix_time::microseconds(dateTime_/10);
		boost::posix_time::ptime ptime = nullTime_ + td;
		return ptime;
	}

	bool 
	OpcUaDateTime::exist(void) const
	{
		if (dateTime_ == 0) {
			return false;
		}
		return true;
	}

	OpcUaDateTime& 
	OpcUaDateTime::operator=(const OpcUaUInt64& dateTime)
	{
		dateTime_ = dateTime;
		return *this;
	}
		
	OpcUaDateTime::operator OpcUaUInt64 const (void)
	{
		return dateTime_;
	}

	void 
	OpcUaDateTime::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaStackCore::opcUaBinaryEncode(os, dateTime_);
	}

	void 
	OpcUaDateTime::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaStackCore::opcUaBinaryDecode(is, dateTime_);
	}

	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaDateTime& value)
	{
		value.opcUaBinaryEncode(os);
	}

	void 
	opcUaBinaryDecode(std::istream& is, OpcUaDateTime& value)
	{
		value.opcUaBinaryDecode(is);
	}

}