#include "OpcUaStackCore/BuildInTypes/OpcUaByteString.h"
#include "OpcUaStackCore/Base/Utility.h"
#include <string.h>

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	// 
	// OPcUaByteString
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaByteString::OpcUaByteString(void)
	:  ObjectPool<OpcUaByteString>()
	, length_(-1)
	, value_(NULL)
	{
	}
		
	OpcUaByteString::~OpcUaByteString(void)
	{
		reset();
	}

	void 
	OpcUaByteString::value(OpcUaByte** value, OpcUaInt32* length) const
	{
		*value = value_;
		*length = length_;
	}

	void 
	OpcUaByteString::value(char** value, OpcUaInt32* length) const
	{
		this->value((OpcUaByte**)value, length);
	}
		
	void 
	OpcUaByteString::value(const OpcUaByte* value, OpcUaInt32 length)
	{
		reset();
		value_ = (OpcUaByte*)malloc(length);
		memcpy(value_, value, length);
		length_ = length;
	}

	void 
	OpcUaByteString::value(const char* value, OpcUaInt32 length)
	{
		this->value((const OpcUaByte*)value, length);
	}
		
	void 
	OpcUaByteString::value(const std::string& value)
	{
		this->value((const OpcUaByte*)(value.c_str()), (OpcUaInt32)value.length());
	}

	OpcUaInt32 
	OpcUaByteString::size(void) const
	{
		return length_;
	}
		
	void 
	OpcUaByteString::reset(void) 
	{
		if (value_ != NULL) {
			free((char*)value_);
			value_ = NULL;
			length_ = -1;
		}
	}

	bool 
	OpcUaByteString::exist(void) const
	{
		return length_ != -1;
	}

	OpcUaByteString& 
	OpcUaByteString::operator=(const std::string& string)
	{
		value(string);
		return *this;
	}
		
	OpcUaByteString::operator std::string const (void)
	{
		if (length_ < 1) {
			return std::string();
		}
		return std::string((char*)value_, length_);
	}

	void 
	OpcUaByteString::copyTo(OpcUaByteString& opcUaByteString)
	{
		OpcUaByte* buf;
		OpcUaInt32 bufLen;
		value(&buf, &bufLen);
		opcUaByteString.value(buf, bufLen);
	}

	bool 
	OpcUaByteString::operator<(const OpcUaByteString& opcUaByteString) const
	{
		if (!exist() && !opcUaByteString.exist()) return false;
		if (exist() && !opcUaByteString.exist()) return false;
		if (!exist() && opcUaByteString.exist()) return true;


		if (size() < opcUaByteString.size()) return true;
		if ( opcUaByteString.size() < size()) return false;

		OpcUaByte* buf;
		OpcUaInt32 bufLen;
		opcUaByteString.value(&buf, &bufLen);

		if (strncmp((char*)value_, (char*)buf, bufLen) < 0) {
			return true;
		}
		return false;
	}

	bool 
	OpcUaByteString::operator!=(const OpcUaByteString& opcUaByteString) const
	{
		return !operator==(opcUaByteString);
	}

	bool 
	OpcUaByteString::operator==(const OpcUaByteString& opcUaByteString) const
	{
		if (exist() != opcUaByteString.exist()) return false;
		if (!exist() && !opcUaByteString.exist()) return true;

		if (size() != opcUaByteString.size()) return false;
		if (size() == 0 && opcUaByteString.size() == 0) return true;

		OpcUaByte* buf;
		OpcUaInt32 bufLen;
		opcUaByteString.value(&buf, &bufLen);

		return (strncmp((char*)value_, (char*)buf, bufLen) == 0);
	}

	void 
	OpcUaByteString::out(std::ostream& os) const
	{
		os << length_ << "-";
		uint32_t length = length_;
		if (length_ > 15) length = 15;

		if (length > 0) {
			std::string str;
			byteSequenceToHexString((const uint8_t*) value_, length, str);
			os << str;
			if (length_ != length) os << "..."; 
		}
	}

	void 
	OpcUaByteString::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, length_);
		if (length_ < 1) {
			return;
		}
		os.write((char*)value_, length_);
	}
		
	void 
	OpcUaByteString::opcUaBinaryDecode(std::istream& is)
	{
		reset();
		OpcUaNumber::opcUaBinaryDecode(is, length_);
		if (length_ < 1) {
			return;
		}
		
		value_ = (OpcUaByte*)malloc(length_);
		is.read((char*)value_, length_);
	}

	std::string 
	OpcUaByteString::toHexString(void) const
	{
		std::stringstream ss;
		if (length_ > 0) {
			OpcUaStackCore::dumpHex((const char *)value_, (const uint32_t)length_, ss);
		}
		return ss.str();
	}

};
