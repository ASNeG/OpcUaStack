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

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include <boost/property_tree/json_parser.hpp>
#include <boost/algorithm/string/replace.hpp>
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/BuildInTypes/Json.h"

namespace OpcUaStackCore
{

	bool
	Json::toDocumentString(boost::property_tree::ptree& pt, std::string& string)
	{
		std::stringstream ss;

		boost::property_tree::ptree document;
		document.add_child("Document", pt);
		boost::property_tree::json_parser::write_json(ss, document);
		string = ss.str();

		// replace dummy string
		boost::replace_all(string, "\"__EmptyArray__\"", "[]");

		return true;
	}

	bool
	Json::toString(boost::property_tree::ptree& pt, std::string& string, bool logEnable)
	{
		std::stringstream ss;

		try {
		    boost::property_tree::json_parser::write_json(ss, pt);
		}
		catch (const boost::property_tree::json_parser_error& e)
		{
			if (logEnable) {
				auto errorMessage = std::string(e.what());
				Log(Error, "json encode error")
			    	.parameter("ErrorMessage", errorMessage);
			}
			return false;
		}
		string = ss.str();

		// replace dummy string
		boost::replace_all(string, "\"__EmptyArray__\"", "[]");

		return true;
	}

	bool
	Json::fromString(const std::string& string, boost::property_tree::ptree& pt, bool logEnable)
	{
		std::stringstream ss;
		ss.str(string);

		try {
			boost::property_tree::json_parser::read_json(ss, pt);
		}
		catch (const boost::property_tree::json_parser_error& e)
		{
			if (logEnable) {
				auto errorMessage = std::string(e.what());
				Log(Error, "json swcode error")
			    	.parameter("ErrorMessage", errorMessage);
			}
			return false;
		}

		return true;
	}

	bool
	Json::encode(boost::property_tree::ptree& pt, const OpcUaBoolean& value)
	{
		if (value) pt.put_value<bool>(true);
		else pt.put_value(false);
		return true;
	}

	bool
	Json::decode(boost::property_tree::ptree& pt, OpcUaBoolean& value)
	{
		value = pt.get_value<bool>();
		return true;
	}

	bool
	Json::encode(boost::property_tree::ptree& pt, const OpcUaSByte& value)
	{
		pt.put_value<int8_t>(value);
		return true;
	}

	bool
	Json::decode(boost::property_tree::ptree& pt, OpcUaSByte& value)
	{
		value = pt.get_value<int8_t>();
		return true;
	}

	bool
	Json::encode(boost::property_tree::ptree& pt, const OpcUaByte& value)
	{
		pt.put_value<uint8_t>(value);
		return true;
	}

	bool
	Json::decode(boost::property_tree::ptree& pt, OpcUaByte& value)
	{
		value = pt.get_value<uint8_t>();
		return true;
	}

	bool
	Json::encode(boost::property_tree::ptree& pt, const OpcUaInt16& value)
	{
		pt.put_value<int16_t>(value);
		return true;
	}

	bool
	Json::decode(boost::property_tree::ptree& pt, OpcUaInt16& value)
	{
		value = pt.get_value<int16_t>();
		return true;
	}

	bool
	Json::encode(boost::property_tree::ptree& pt, const OpcUaUInt16& value)
	{
		pt.put_value<uint16_t>(value);
		return true;
	}

	bool
	Json::decode(boost::property_tree::ptree& pt, OpcUaUInt16& value)
	{
		value = pt.get_value<uint16_t>();
		return true;
	}

	bool
	Json::encode(boost::property_tree::ptree& pt, const OpcUaInt32& value)
	{
		pt.put_value<int32_t>(value);
		return true;
	}

	bool
	Json::decode(boost::property_tree::ptree& pt, OpcUaInt32& value)
	{
		value = pt.get_value<int32_t>();
		return true;
	}

	bool
	Json::encode(boost::property_tree::ptree& pt, const OpcUaUInt32& value)
	{
		pt.put_value<uint32_t>(value);
		return true;
	}

	bool
	Json::decode(boost::property_tree::ptree& pt, OpcUaUInt32& value)
	{
		value = pt.get_value<uint32_t>();
		return true;
	}

	bool
	Json::encode(boost::property_tree::ptree& pt, const OpcUaInt64& value)
	{
		pt.put_value<int64_t>(value);
		return true;
	}

	bool
	Json::decode(boost::property_tree::ptree& pt, OpcUaInt64& value)
	{
		value = pt.get_value<int64_t>();
		return true;
	}

	bool
	Json::encode(boost::property_tree::ptree& pt, const OpcUaUInt64& value)
	{
		pt.put_value<uint64_t>(value);
		return true;
	}

	bool
	Json::decode(boost::property_tree::ptree& pt, OpcUaUInt64& value)
	{
		value = pt.get_value<uint64_t>();
		return true;
	}

	bool
	Json::encode(boost::property_tree::ptree& pt, const OpcUaFloat& value)
	{
		pt.put_value<float>(value);
		return true;
	}

	bool
	Json::decode(boost::property_tree::ptree& pt, OpcUaFloat& value)
	{
		value = pt.get_value<float>();
		return true;
	}

	bool
	Json::encode(boost::property_tree::ptree& pt, const OpcUaDouble& value)
	{
		pt.put_value<double>(value);
		return true;
	}

	bool
	Json::decode(boost::property_tree::ptree& pt, OpcUaDouble& value)
	{
		value = pt.get_value<double>();
		return true;
	}

}
