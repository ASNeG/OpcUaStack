#include "OpcUaStackCore/BuildInTypes/OpcUaString.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"

namespace OpcUaStackCore
{

	#define MAX_STREAMBUF_SIZE	1000000

	OpcUaString::OpcUaString(void)
	: ObjectPool<OpcUaString>()
	, exist_(false)
	, value_()
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
	OpcUaString::opcUaBinaryEncode(std::ostream& os) const
	{
		if (!exist_) {
			OpcUaStackCore::opcUaBinaryEncode(os, (const OpcUaInt32)-1);
			return;
		}

		OpcUaStackCore::opcUaBinaryEncode(os, (const OpcUaInt32)value_.size());
		os.write(value_.c_str(), value_.size());
	}
		
	void 
	OpcUaString::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaInt32 length = 0;
		OpcUaStackCore::opcUaBinaryDecode(is, length);

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

	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaString& value) 
	{
		value.opcUaBinaryEncode(os);
	}

	void 
	opcUaBinaryDecode(std::istream& is, OpcUaString& value)
	{	
		value.opcUaBinaryDecode(is);
	}

}