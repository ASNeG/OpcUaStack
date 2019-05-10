/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (atimin@gmail.com)
 */

#include "OpcUaStackCore/BuildInTypes/OpcUaByteString.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/Base/Base64.h"
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
	, value_(nullptr)
	{
	}

	OpcUaByteString::OpcUaByteString(const OpcUaByteString& byteString)
	: Object()
	, length_(-1)
	, value_(nullptr)
	{
		char* memBuf;
		int32_t memLen;

		byteString.value(&memBuf, &memLen);
		value(memBuf, memLen);
	}

	OpcUaByteString::OpcUaByteString(const std::string& value)
	: Object()
	, length_(-1)
	, value_(nullptr)
	{
		this->value(value);
	}

	OpcUaByteString::OpcUaByteString(const OpcUaByte* value, OpcUaInt32 length)
	: Object()
	, length_(-1)
	, value_(nullptr)
	{
		this->value(value, length);
	}
		
	OpcUaByteString::~OpcUaByteString(void)
	{
		reset();
	}

	void 
	OpcUaByteString::value(OpcUaByte** value, OpcUaInt32* length) const
	{
		(*value) = value_;
		(*length) = length_;
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
		if (value == nullptr || length < 0) {
			return;
		}

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

	char*
	OpcUaByteString::memBuf(void)
	{
		return (char*)value_;
	}

	bool
	OpcUaByteString::resize(uint32_t size)
	{
		reset();
		if (size <= 0) return true;
		value_ = (OpcUaByte*)malloc(size);
		memset(value_, 0x00, size);
		length_ = size;

		return true;
	}
		
	void 
	OpcUaByteString::reset(void) 
	{
		if (value_ != nullptr) {
			free((char*)value_);
			value_ = nullptr;
			length_ = -1;
		}
	}

	bool 
	OpcUaByteString::exist(void) const
	{
		return length_ != -1;
	}

	bool
	OpcUaByteString::isNull(void) const
	{
		return length_ == -1;
	}

	OpcUaByteString& 
	OpcUaByteString::operator=(const std::string& string)
	{
		value(string);
		return *this;
	}

	OpcUaByteString&
	OpcUaByteString::operator=(const OpcUaByteString& byteString)
	{
		char* memBuf;
		int32_t memLen;

		byteString.value(&memBuf, &memLen);
		value(memBuf, memLen);
		return *this;
	}
		
	OpcUaByteString::operator std::string const (void)
	{
		if (length_ < 1 || value_ == nullptr) {
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

		return (memcmp((char*)value_, (char*)buf, bufLen) == 0);
	}

	void 
	OpcUaByteString::out(std::ostream& os) const
	{
		os << length_;
		int32_t length = length_;
		if (length_ > 15) length = 15;

		if (length > 0) {
			std::string str;
			byteSequenceToHexString((const uint8_t*) value_, length, str);
			os << "-" << str;
			if (length_ != length) os << "..."; 
		}
	}

	void 
	OpcUaByteString::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, length_);
		if (length_ < 1) return;
		os.write((char*)value_, length_);
	}
		
	void 
	OpcUaByteString::opcUaBinaryDecode(std::istream& is)
	{
		reset();
		OpcUaNumber::opcUaBinaryDecode(is, length_);
		if (length_ < 1) return;
		
		value_ = (OpcUaByte*)malloc(length_);
		is.read((char*)value_, length_);
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

	std::string
	OpcUaByteString::toString(void) const
	{
		if (length_ < 1) {
			return std::string();
		}
		return std::string((char*)value_, length_);
	}

	void
	OpcUaByteString::fromString(const std::string& string)
	{
		value(string);
	}

	bool
	OpcUaByteString::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
	{
		boost::property_tree::ptree elementTree;
		if (!xmlEncode(elementTree, xmlns)) {
			Log(Error, "OpcUaByteString xml encoder error")
				.parameter("Element", element);
			return false;
		}
		pt.push_back(std::make_pair(xmlns.addPrefix(element), elementTree));
		return true;
	}

	bool
	OpcUaByteString::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		OpcUaByte* valueBuf = nullptr;
		OpcUaInt32 valueLen = 0;
		value(&valueBuf, &valueLen);

		if (valueLen == 0) {
			pt.put_value("");
		}
		else {
			uint32_t bufLen = Base64::asciiLen2base64Len(valueLen);
			if (bufLen == 0) {
				Log(Error, "OpcUaByteString xml encoder error - base64 length error");
				pt.put_value("");
				return false;
			}

			char* buf = (char*) new char[bufLen+1];
			if (!Base64::encode((const char*)valueBuf, valueLen, buf, bufLen)) {
				Log(Error, "OpcUaByteString xml encoder error - base64 encoder error");
				delete buf;
				return false;
			}

			std::string str(buf, bufLen);
			pt.put_value(str);
			delete buf;
		}
		return true;
	}

	bool
	OpcUaByteString::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		std::string sourceValue = pt.get_value<std::string>();

		if (sourceValue.size() == 0) {
			value("", 0);
			return true;
		}

		uint32_t valueLen = Base64::base64Len2asciiLen(sourceValue.length());
		if (valueLen == 0) {
			Log(Error, "OpcUaByteString xml encoder error - ascii length error");
			return false;
		}
		char* valueBuf = (char*)malloc(valueLen+1);
		memset(valueBuf, 0x00, valueLen+1);

		if (!Base64::decode(sourceValue.c_str(), sourceValue.length(), valueBuf, valueLen)) {
			Log(Error, "OpcUaByteString xml encoder error - base64 decoder error");
			delete valueBuf;
			return false;
		}

		value(valueBuf, valueLen);
		delete valueBuf;
		return true;
	}



	bool
	OpcUaByteString::jsonEncodeImpl(boost::property_tree::ptree& pt) const
	{
		OpcUaByte* valueBuf = nullptr;
		OpcUaInt32 valueLen = 0;
		value(&valueBuf, &valueLen);

		if (valueLen == 0) {
			pt.put_value("");
		}
		else {
			uint32_t bufLen = Base64::asciiLen2base64Len(valueLen);
			if (bufLen == 0) {
				Log(Error, "OpcUaByteString json encoder error - base64 length error");
				pt.put_value("");
				return false;
			}

			char* buf = (char*) new char[bufLen+1];
			if (!Base64::encode((const char*)valueBuf, valueLen, buf, bufLen)) {
				Log(Error, "OpcUaByteString json encoder error - base64 encoder error");
				delete buf;
				return false;
			}

			std::string str(buf, bufLen);
			pt.put_value(str);
			delete buf;
		}
		return true;
	}

	bool
	OpcUaByteString::jsonDecodeImpl(const boost::property_tree::ptree& pt)
	{
		std::string sourceValue = pt.get_value<std::string>();

		if (sourceValue.size() == 0) {
			value("", 0);
			return true;
		}

		uint32_t valueLen = Base64::base64Len2asciiLen(sourceValue.length());
		if (valueLen == 0) {
			Log(Error, "OpcUaByteString json encoder error - ascii length error");
			return false;
		}
		char* valueBuf = (char*)malloc(valueLen+1);
		memset(valueBuf, 0x00, valueLen+1);

		if (!Base64::decode(sourceValue.c_str(), sourceValue.length(), valueBuf, valueLen)) {
			Log(Error, "OpcUaByteString json encoder error - base64 decoder error");
			delete valueBuf;
			return false;
		}

		value(valueBuf, valueLen);
		delete valueBuf;
		return true;
	}

};
