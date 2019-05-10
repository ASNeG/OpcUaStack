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

#include "OpcUaStackCore/BuildInTypes/OpcUaDateTime.h"

namespace OpcUaStackCore
{


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaDateTime
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	boost::posix_time::ptime OpcUaDateTime::nullTime_ = boost::posix_time::from_iso_string("16010101T000000.000000000");

	OpcUaDateTime::OpcUaDateTime(void)
	: dateTime_(0)
	{
	}

	OpcUaDateTime::OpcUaDateTime(const OpcUaDateTime& value)
	: dateTime_(0)
	{
		dateTime_ = value.dateTime_;
	}

	OpcUaDateTime::OpcUaDateTime(const boost::posix_time::ptime& ptime)
	: dateTime_(0)
	{
		dateTime(ptime);
	}

	OpcUaDateTime::OpcUaDateTime(const std::string& dateTimeString)
	: dateTime_(0)
	{
		fromISO8601(dateTimeString);
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

	OpcUaUInt64
	OpcUaDateTime::rawDateTime(void) const
	{
		return dateTime_;
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

	bool
	OpcUaDateTime::operator!=(const OpcUaDateTime& dateTime) const
	{
		return !this->operator==(dateTime);
	}

	bool
	OpcUaDateTime::operator==(const OpcUaDateTime& dateTime) const
	{
		return this->rawDateTime() == dateTime.rawDateTime();
	}
		
	OpcUaDateTime::operator OpcUaUInt64 const (void)
	{
		return dateTime_;
	}

	bool 
	OpcUaDateTime::fromISOString(const std::string& dateTimeString)
	{
		boost::posix_time::ptime timeFromString;
		try {
		    timeFromString = boost::posix_time::from_iso_string(dateTimeString);
		}
		catch (...)
		{
			std::string str = dateTimeString;
			boost::to_upper(str);
			if (str == "NOW") {
				timeFromString = boost::posix_time::microsec_clock::local_time();
			}
			else {
				return false;
			}
		}

		dateTime(timeFromString);
		return true;
	}

	bool
	OpcUaDateTime::fromISO8601(const std::string& dateTimeString)
	{
		// All DateTime values shall be encoded as UTC times or with the time zone explicitly specified.
		// 2002-10-10T00:00:00+05:00
		// 2002-10-10T00:00:00+0500
		// 2002-10-10T00:00:00+05
		// 2002-10-09T19:00:00Z

		// ISO 8601
		// <time>Z
		// <time>±hh:mm
		// <time>±hhmm
		// <time>±hh
		std::string dateString = dateTimeString;
		std::string zoneString = "";
		uint32_t offset = 0;
		bool negOffset = false;
		std::size_t found = dateTimeString.find_last_of("Z+-");
		if (found < 10) found = std::string::npos;
		if (found != std::string::npos) {
			dateString = dateTimeString.substr(0, found);
			zoneString = dateTimeString.substr(found, dateTimeString.size()-found);

			switch (zoneString.size())
			{
			    case 1:
			    	break;
			    case 3:
			    	offset = ((uint32_t)(zoneString[1]-'0')*10 + (uint32_t)(zoneString[2]-'0')) * 3600;
			    	break;
			    case 5:
			    	offset = ((uint32_t)(zoneString[1]-'0')*10 + (uint32_t)(zoneString[2]-'0')) * 3600 +
					         ((uint32_t)(zoneString[3]-'0')*10 + (uint32_t)(zoneString[4]-'0')) * 60;
			    	break;
			    case 6:
			    	offset = ((uint32_t)(zoneString[1]-'0')*10 + (uint32_t)(zoneString[2]-'0')) * 3600 +
					         ((uint32_t)(zoneString[4]-'0')*10 + (uint32_t)(zoneString[5]-'0')) * 60;
			    	break;
				default:
					return false;
			}

			if (zoneString[0] == '+') {
				offset *= -1;
			}

		}

		try {
			boost::posix_time::ptime ptime;
			std::stringstream ss;
			ss << dateString;
			boost::posix_time::time_input_facet* facet = new boost::posix_time::time_input_facet("%Y-%m-%dT%H:%M:%S");
			ss.imbue(std::locale(ss.getloc(), facet));
			ss >> ptime;
			ptime += boost::posix_time::seconds(offset);
			dateTime(ptime);
		} catch(...)
		{
			return false;
		}

		return true;
	}

	std::string
	OpcUaDateTime::toISO8601(void) const
	{
		try {
			boost::posix_time::ptime ptime = dateTime();
			std::stringstream ss;
			boost::posix_time::time_facet* facet = new boost::posix_time::time_facet("%Y-%m-%dT%H:%M:%S");
			ss.imbue(std::locale(ss.getloc(), facet));
			ss << ptime;
			return ss.str() + "Z";
		} catch(...)
		{
			return "ERROR";
		}

		return "ERROR";
	}

	std::string
	OpcUaDateTime::toISOString(void) const
	{
		std::string str;
		try 
		{
			str = boost::posix_time::to_iso_string(dateTime());
		} catch(std::exception&) {
			return "unknown";
		}
		return str;
	}

	void 
	OpcUaDateTime::out(std::ostream& os) const
	{
		std::string str;
		try 
		{
			str = boost::posix_time::to_iso_string(dateTime());
		} catch(std::exception&) {
			str = "unknown";
		}
		os << str;
	}

	void 
	OpcUaDateTime::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, dateTime_);
	}

	void 
	OpcUaDateTime::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, dateTime_);
	}

	void 
	OpcUaDateTime::copyTo(OpcUaDateTime& opcUaDataTime)
	{
		opcUaDataTime = dateTime_;
	}

	bool
	OpcUaDateTime::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
	{
		boost::property_tree::ptree elementTree;
		if (!xmlEncode(elementTree, xmlns)) {
			Log(Error, "OpcUaDateTime xml encoder error")
				.parameter("Element", element);
			return false;
		}
		pt.push_back(std::make_pair(xmlns.addPrefix(element), elementTree));
		return true;
	}

	bool
	OpcUaDateTime::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		pt.put_value(toISO8601());
		return true;
	}

	bool
	OpcUaDateTime::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
	{
		boost::optional<boost::property_tree::ptree&> tmpTree;

		tmpTree = pt.get_child_optional(xmlns.addPrefix(element));
		if (!tmpTree) {
			Log(Error, "OpcDateTime xml decoder error")
				.parameter("Element", element);
				return false;
		}
		return xmlDecode(*tmpTree, xmlns);
	}

	bool
	OpcUaDateTime::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		std::string sourceValue = pt.get_value<std::string>();
		if (sourceValue.empty()) {
			Log(Error, "OpcUaDateTime xml decoder error - value not exist in xml document");
			return false;
		}

		if (!fromISO8601(sourceValue)) {
			Log(Error, "OpcUaDateTime xml decoder error - value format error")
				.parameter("Value", sourceValue);
			return false;
		}

		return true;
	}

    bool
    OpcUaDateTime::jsonEncodeImpl(boost::property_tree::ptree &pt) const {
        pt.put_value(toISO8601());
        return true;
    }

    bool
    OpcUaDateTime::jsonDecodeImpl(const boost::property_tree::ptree &pt) {
        std::string sourceValue = pt.get_value<std::string>();
        if (sourceValue.empty()) {
            Log(Error, "OpcUaDateTime json decoder error - value not exist in json document");
            return false;
        }

        if (!fromISO8601(sourceValue)) {
            Log(Error, "OpcUaDateTime json decoder error - value format error")
                    .parameter("Value", sourceValue);
            return false;
        }

        return true;
    }
}
