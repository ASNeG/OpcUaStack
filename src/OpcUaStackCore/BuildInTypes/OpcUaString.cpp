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
	: Object()
	, exist_(false)
	, value_()
	{
	}

	OpcUaString::OpcUaString(const OpcUaString& value)
	: Object()
	, exist_(false)
	, value_()
	{
		const_cast<OpcUaString*>(&value)->copyTo(*this);
	}

	OpcUaString::OpcUaString(const std::string& value)
	: exist_(true)
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

	std::string
	OpcUaString::toStdString(void) const
	{
		return value_;
	}

	void 
	OpcUaString::value(const std::string& value)
	{
		if (value == "---") {
			reset();
		}
		else {
		    exist_ = true;
		    value_ = value;
		}
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
	OpcUaString::copyTo(OpcUaString& opcUaString) const
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

	bool
	OpcUaString::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
	{
		boost::property_tree::ptree elementTree;
		if (!xmlEncode(elementTree, xmlns)) {
			Log(Error, "OpcString xml encoder error")
				.parameter("Element", element);
			return false;
		}
		pt.push_back(std::make_pair(xmlns.addPrefix(element), elementTree));
		return true;
	}

	bool
	OpcUaString::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		pt.put_value(value());
		return true;
	}

	bool
	OpcUaString::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		std::string sourceValue = pt.get_value<std::string>();
		value(sourceValue);
		return true;
	}


	bool
	OpcUaString::jsonEncodeImpl(boost::property_tree::ptree& pt) const
	{
		pt.put_value(value());
		return true;
	}



	bool
	OpcUaString::jsonDecodeImpl(const boost::property_tree::ptree& pt)
	{
		std::string sourceValue = pt.get_value<std::string>();
		value(sourceValue);
		return true;
	}

}
