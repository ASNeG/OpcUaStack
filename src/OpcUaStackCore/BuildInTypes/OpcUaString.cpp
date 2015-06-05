#include "OpcUaStackCore/BuildInTypes/OpcUaString.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"

namespace OpcUaStackCore
{

	#define MAX_STREAMBUF_SIZE	1000000

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaString
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaString::OpcUaString(void)
	: ObjectPool<OpcUaString>()
	, exist_(false)
	, value_()
	{
	}

	OpcUaString::OpcUaString(const std::string& value)
	: ObjectPool<OpcUaString>()
	, exist_(true)
	, value_(value)
	{
	}

	OpcUaString::~OpcUaString(void)
	{
	}

	std::string
	OpcUaString::value(void) const
	{
		return value_;
	}

	void 
	OpcUaString::value(const std::string& value)
	{
		exist_ = true;
		value_ = value;
	}

	uint32_t
	OpcUaString::size(void) const
	{
		return value_.size();
	}
		
	void 
	OpcUaString::reset(void)
	{
		exist_ = false;
		value_ = "";
	}
		
	bool 
	OpcUaString::exist(void) const
	{
		return exist_;
	}


	OpcUaString& 
	OpcUaString::operator=(const std::string& string)
	{
		value(string);
		return *this;
	}

	OpcUaString::operator std::string const (void)
	{
		return value();
	}

	void 
	OpcUaString::copyTo(OpcUaString& opcUaString)
	{
		opcUaString.value(value());
	}

	bool 
	OpcUaString::operator<(const OpcUaString& opcUaString) const
	{
		if (!exist_ && !opcUaString.exist()) return false;
		if (exist_ && !opcUaString.exist()) return false;
		if (!exist_ && opcUaString.exist()) return true;
		return value_  < opcUaString.value();
	}

	bool 
	OpcUaString::operator!=(const OpcUaString& opcUaString) const
	{
		return !operator==(opcUaString);	
	}
	
	bool 
	OpcUaString::operator==(const OpcUaString& opcUaString) const
	{
		if (exist() != opcUaString.exist()) return false;
		if (!exist() && !opcUaString.exist()) return true;
		return value_ == opcUaString.value();
	}

	void 
	OpcUaString::out(std::ostream& os) const
	{
		if (!exist_) {
			os << "---";
		}
		else {
			os << value_;
		}
	}

	void 
	OpcUaString::opcUaBinaryEncode(std::ostream& os) const
	{
		if (!exist_) {
			OpcUaNumber::opcUaBinaryEncode(os, (const OpcUaInt32)-1);
			return;
		}

		OpcUaNumber::opcUaBinaryEncode(os, (const OpcUaInt32)value_.size());
		os.write(value_.c_str(), value_.size());
	}
		
	void 
	OpcUaString::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaInt32 length = 0;
		OpcUaNumber::opcUaBinaryDecode(is, length);

		if (length < 0) {
			value_ = "";
			exist_ = false;
			return;
		}

		if (length == 0) {
			value_ = "";
			exist_ = true;
			return;
		}

		value_ = "";
		exist_ = true;

		char buf[MAX_STREAMBUF_SIZE];
		uint32_t sizeToRead;
		do 
		{
			sizeToRead = MAX_STREAMBUF_SIZE;
			if (length < MAX_STREAMBUF_SIZE) {
				sizeToRead = length;
			}

			is.read(buf, sizeToRead);
			value_.append(buf, sizeToRead);

			length -= sizeToRead;
		} while (length > 0);
	}

}
