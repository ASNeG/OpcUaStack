#include "OpcUaStackCore/BuildInTypes/OpcUaByteString.h"
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

	OpcUaUInt32 
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
	OpcUaByteString::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaStackCore::opcUaBinaryEncode(os, length_);
		if (length_ < 1) {
			return;
		}
		os.write((char*)value_, length_);
	}
		
	void 
	OpcUaByteString::opcUaBinaryDecode(std::istream& is)
	{
		reset();
		OpcUaStackCore::opcUaBinaryDecode(is, length_);
		if (length_ < 1) {
			return;
		}
		
		value_ = (OpcUaByte*)malloc(length_);
		is.read((char*)value_, length_);
	}

	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaByteString& value)
	{
		value.opcUaBinaryEncode(os);
	}

	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaByteString::SPtr& value)
	{
		value->opcUaBinaryEncode(os);
	}

	void 
	opcUaBinaryDecode(std::istream& is, OpcUaByteString& value)
	{
		value.opcUaBinaryDecode(is);
	}

	void 
	opcUaBinaryDecode(std::istream& is, OpcUaByteString::SPtr& value)
	{
		value->opcUaBinaryDecode(is);
	}


	// ---------------------------------------------------------------------------
	// ---------------------------------------------------------------------------
	//
	// OpcUaByteStringArray
	//
	// ---------------------------------------------------------------------------
	// ---------------------------------------------------------------------------
	OpcUaByteStringArray::OpcUaByteStringArray(void)
	{
	}

	OpcUaByteStringArray::~OpcUaByteStringArray(void)
	{
	}

	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaByteStringArray& value)
	{
		value.opcUaBinaryEncode(os);
	}

	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaByteStringArray::SPtr& value)
	{
		value->opcUaBinaryEncode(os);
	}

	void 
	opcUaBinaryDecode(std::istream& is, OpcUaByteStringArray& value)
	{
		value.opcUaBinaryDecode(is);
	}

	void 
	opcUaBinaryDecode(std::istream& is, OpcUaByteStringArray::SPtr& value)
	{
		value->opcUaBinaryDecode(is);
	}

};
