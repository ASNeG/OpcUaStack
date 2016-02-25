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
	: Object()
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

	bool
	OpcUaByteString::encode(boost::property_tree::ptree& pt) const
	{
		std::string hexString  = "";

		if (length_ > 1) {
			OpcUaStackCore::byteSequenceToHexString(value_, length_, hexString);
		}

		pt.put_value<std::string>(hexString);

		return true;
	}

	bool
	OpcUaByteString::decode(boost::property_tree::ptree& pt)
	{
		std::string hexString;
		hexString = pt.get_value<std::string>();

		if (hexString.length() < 1) return true;
		if (hexString.length() % 2 != 0) return false;

		length_ = hexString.length()/2;
		value_ = (OpcUaByte*)malloc(length_);
		OpcUaStackCore::hexStringToByteSequence(hexString, value_);

		return true;
	}

	bool
	OpcUaByteString::fromHexString(const std::string& hexString)
	{
		if (hexString.length() < 1) return true;
		if (hexString.length() % 2 != 0) return false;

		length_ = hexString.length()/2;
		value_ = (OpcUaByte*)malloc(length_);
		OpcUaStackCore::hexStringToByteSequence(hexString, value_);
		return true;
	}

	std::string 
	OpcUaByteString::toHexString(void) const
	{
		std::stringstream ss;
		if (length_ > 0) {
		    OpcUaStackCore::byteSequenceToHexString((const uint8_t *)value_, (const uint32_t)length_, ss);
			//OpcUaStackCore::dumpHex((const char *)value_, (const uint32_t)length_, ss);
		}
		return ss.str();
	}

};
