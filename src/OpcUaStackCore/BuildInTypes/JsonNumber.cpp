/*
   Copyright 2018-2019 Kai Huebl (kai@huebl-sgh.de)

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

#include <boost/algorithm/string/case_conv.hpp>
#include <boost/lexical_cast.hpp>
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/BuildInTypes/JsonNumber.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// encoder - element
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	JsonNumber::jsonEncode(boost::property_tree::ptree& pt, OpcUaBoolean value, const std::string& element)
	{
		boost::property_tree::ptree elementTree;
		if (!jsonEncode(elementTree, value)) {
			Log(Error, "OpcUaBoolean json encode error")
				.parameter("Element", element);
			return false;
		}
		pt.push_back(std::make_pair(element, elementTree));
		return true;
	}

	bool
	JsonNumber::jsonEncode(boost::property_tree::ptree& pt, OpcUaByte value, const std::string& element)
	{
		boost::property_tree::ptree elementTree;
		if (!jsonEncode(elementTree, value)) {
			Log(Error, "OpcUaByte json encode error")
				.parameter("Element", element);
			return false;
		}
		pt.push_back(std::make_pair(element, elementTree));
		return true;
	}

	bool
	JsonNumber::jsonEncode(boost::property_tree::ptree& pt, OpcUaSByte value, const std::string& element)
	{
		boost::property_tree::ptree elementTree;
		if (!jsonEncode(elementTree, value)) {
			Log(Error, "OpcUaSByte json encode error")
				.parameter("Element", element);
			return false;
		}
		pt.push_back(std::make_pair(element, elementTree));
		return true;
	}

	bool
	JsonNumber::jsonEncode(boost::property_tree::ptree& pt, OpcUaUInt16 value, const std::string& element)
	{
		boost::property_tree::ptree elementTree;
		if (!jsonEncode(elementTree, value)) {
			Log(Error, "OpcUaUInt16 json encode error")
				.parameter("Element", element);
			return false;
		}
		pt.push_back(std::make_pair(element, elementTree));
		return true;
	}

	bool
	JsonNumber::jsonEncode(boost::property_tree::ptree& pt, OpcUaInt16 value, const std::string& element)
	{
		boost::property_tree::ptree elementTree;
		if (!jsonEncode(elementTree, value)) {
			Log(Error, "OpcUaInt16 json encode error")
				.parameter("Element", element);
			return false;
		}
		pt.push_back(std::make_pair(element, elementTree));
		return true;
	}

	bool
	JsonNumber::jsonEncode(boost::property_tree::ptree& pt, OpcUaUInt32 value, const std::string& element)
	{
		boost::property_tree::ptree elementTree;
		if (!jsonEncode(elementTree, value)) {
			Log(Error, "OpcUaUInt32 json encode error")
				.parameter("Element", element);
			return false;
		}
		pt.push_back(std::make_pair(element, elementTree));
		return true;
	}

	bool
	JsonNumber::jsonEncode(boost::property_tree::ptree& pt, OpcUaInt32 value, const std::string& element)
	{
		boost::property_tree::ptree elementTree;
		if (!jsonEncode(elementTree, value)) {
			Log(Error, "OpcUaInt32 json encode error")
				.parameter("Element", element);
			return false;
		}
		pt.push_back(std::make_pair(element, elementTree));
		return true;
	}

	bool
	JsonNumber::jsonEncode(boost::property_tree::ptree& pt, OpcUaUInt64 value, const std::string& element)
	{
		boost::property_tree::ptree elementTree;
		if (!jsonEncode(elementTree, value)) {
			Log(Error, "OpcUaUInt64 json encode error")
				.parameter("Element", element);
			return false;
		}
		pt.push_back(std::make_pair(element, elementTree));
		return true;
	}

	bool
	JsonNumber::jsonEncode(boost::property_tree::ptree& pt, OpcUaInt64 value, const std::string& element)
	{
		boost::property_tree::ptree elementTree;
		if (!jsonEncode(elementTree, value)) {
			Log(Error, "OpcUaInt64 json encode error")
				.parameter("Element", element);
			return false;
		}
		pt.push_back(std::make_pair(element, elementTree));
		return true;
	}

	bool
	JsonNumber::jsonEncode(boost::property_tree::ptree& pt, OpcUaFloat value, const std::string& element)
	{
		boost::property_tree::ptree elementTree;
		if (!jsonEncode(elementTree, value)) {
			Log(Error, "Float json encode error")
				.parameter("Element", element);
			return false;
		}
		pt.push_back(std::make_pair(element, elementTree));
		return true;
	}

	bool
	JsonNumber::jsonEncode(boost::property_tree::ptree& pt, OpcUaDouble value, const std::string& element)
	{
		boost::property_tree::ptree elementTree;
		if (!jsonEncode(elementTree, value)) {
			Log(Error, "OpcUaDouble json encode error")
				.parameter("Element", element);
			return false;
		}
		pt.push_back(std::make_pair(element, elementTree));
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// encoder
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	JsonNumber::jsonEncode(boost::property_tree::ptree& pt, OpcUaBoolean value)
	{
		if (value) {
			pt.put_value("true");
		}
		else {
			pt.put_value("false");
		}
		return true;
	}

	bool
	JsonNumber::jsonEncode(boost::property_tree::ptree& pt, OpcUaByte value)
	{
		std::stringstream ss;
		ss << (int16_t)value;
		pt.put_value(ss.str());
		return true;
	}

	bool
	JsonNumber::jsonEncode(boost::property_tree::ptree& pt, OpcUaSByte value)
	{
		std::stringstream ss;
		ss << (int16_t)value;
		pt.put_value(ss.str());
		return true;
	}

	bool
	JsonNumber::jsonEncode(boost::property_tree::ptree& pt, OpcUaUInt16 value)
	{
		std::stringstream ss;
		ss << value;
		pt.put_value(ss.str());
		return true;
	}

	bool
	JsonNumber::jsonEncode(boost::property_tree::ptree& pt, OpcUaInt16 value)
	{
		std::stringstream ss;
		ss << value;
		pt.put_value(ss.str());
		return true;
	}

	bool
	JsonNumber::jsonEncode(boost::property_tree::ptree& pt, OpcUaUInt32 value)
	{
		std::stringstream ss;
		ss << value;
		pt.put_value(ss.str());
		return true;
	}

	bool
	JsonNumber::jsonEncode(boost::property_tree::ptree& pt, OpcUaInt32 value)
	{
		std::stringstream ss;
		ss << value;
		pt.put_value(ss.str());
		return true;
	}

	bool
	JsonNumber::jsonEncode(boost::property_tree::ptree& pt, OpcUaUInt64 value)
	{
		std::stringstream ss;
		ss << value;
		pt.put_value(ss.str());
		return true;
	}

	bool
	JsonNumber::jsonEncode(boost::property_tree::ptree& pt, OpcUaInt64 value)
	{
		std::stringstream ss;
		ss << value;
		pt.put_value(ss.str());
		return true;
	}

	bool
	JsonNumber::jsonEncode(boost::property_tree::ptree& pt, OpcUaFloat value)
	{
		std::stringstream ss;
		ss << value;
		pt.put_value(ss.str());
		return true;
	}

	bool
	JsonNumber::jsonEncode(boost::property_tree::ptree& pt, OpcUaDouble value)
	{
		std::stringstream ss;
		ss << value;
		pt.put_value(ss.str());
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// decoder - element
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	JsonNumber::jsonDecode(const boost::property_tree::ptree& pt, OpcUaBoolean& value, const std::string& element)
	{
		boost::optional<const boost::property_tree::ptree&> tree = pt.get_child_optional(element);
		if (!tree) return false;
		return JsonNumber::jsonDecode(*tree, value);
	}

	bool
	JsonNumber::jsonDecode(const boost::property_tree::ptree& pt, OpcUaByte& value, const std::string& element)
	{
		boost::optional<const boost::property_tree::ptree&> tree = pt.get_child_optional(element);
		if (!tree) return false;
		return JsonNumber::jsonDecode(*tree, value);
	}

	bool
	JsonNumber::jsonDecode(const boost::property_tree::ptree& pt, OpcUaSByte& value, const std::string& element)
	{
		boost::optional<const boost::property_tree::ptree&> tree = pt.get_child_optional(element);
		if (!tree) return false;
		return JsonNumber::jsonDecode(*tree, value);
	}

	bool
	JsonNumber::jsonDecode(const boost::property_tree::ptree& pt, OpcUaUInt16& value, const std::string& element)
	{
		boost::optional<const boost::property_tree::ptree&> tree = pt.get_child_optional(element);
		if (!tree) return false;
		return JsonNumber::jsonDecode(*tree, value);
	}

	bool
	JsonNumber::jsonDecode(const boost::property_tree::ptree& pt, OpcUaInt16& value, const std::string& element)
	{
		boost::optional<const boost::property_tree::ptree&> tree = pt.get_child_optional(element);
		if (!tree) return false;
		return JsonNumber::jsonDecode(*tree, value);
	}

	bool
	JsonNumber::jsonDecode(const boost::property_tree::ptree& pt, OpcUaUInt32& value, const std::string& element)
	{
		boost::optional<const boost::property_tree::ptree&> tree = pt.get_child_optional(element);
		if (!tree) return false;
		return JsonNumber::jsonDecode(*tree, value);
	}

	bool
	JsonNumber::jsonDecode(const boost::property_tree::ptree& pt, OpcUaInt32& value, const std::string& element)
	{
		boost::optional<const boost::property_tree::ptree&> tree = pt.get_child_optional(element);
		if (!tree) return false;
		return JsonNumber::jsonDecode(*tree, value);
	}

	bool
	JsonNumber::jsonDecode(const boost::property_tree::ptree& pt, OpcUaUInt64& value, const std::string& element)
	{
		boost::optional<const boost::property_tree::ptree&> tree = pt.get_child_optional(element);
		if (!tree) return false;
		return JsonNumber::jsonDecode(*tree, value);
	}

	bool
	JsonNumber::jsonDecode(const boost::property_tree::ptree& pt, OpcUaInt64& value, const std::string& element)
	{
		boost::optional<const boost::property_tree::ptree&> tree = pt.get_child_optional(element);
		if (!tree) return false;
		return JsonNumber::jsonDecode(*tree, value);
	}

	bool
	JsonNumber::jsonDecode(const boost::property_tree::ptree& pt, OpcUaFloat& value, const std::string& element)
	{
		boost::optional<const boost::property_tree::ptree&> tree = pt.get_child_optional(element);
		if (!tree) return false;
		return JsonNumber::jsonDecode(*tree, value);
	}

	bool
	JsonNumber::jsonDecode(const boost::property_tree::ptree& pt, OpcUaDouble& value, const std::string& element)
	{
		boost::optional<const boost::property_tree::ptree&> tree = pt.get_child_optional(element);
		if (!tree) return false;
		return JsonNumber::jsonDecode(*tree, value);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// decoder
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	JsonNumber::jsonDecode(const boost::property_tree::ptree& pt, OpcUaBoolean& value)
	{
		std::string sourceValue = pt.get_value<std::string>();
		boost::to_upper(sourceValue);
		if (sourceValue == "TRUE") value = true;
		else value = false;
		return true;
	}

	bool
	JsonNumber::jsonDecode(const boost::property_tree::ptree& pt, OpcUaByte& value)
	{
		std::string sourceValue = pt.get_value<std::string>();
		try {
			value = (OpcUaByte)boost::lexical_cast<OpcUaUInt16>(sourceValue);
		} catch(boost::bad_lexical_cast& /*e*/) {
			Log(Error, "OpcUaByte json decoder error - value format error")
				.parameter("Value", sourceValue);
			return false;
		}
		return true;
	}

	bool
	JsonNumber::jsonDecode(const boost::property_tree::ptree& pt, OpcUaSByte& value)
	{
		std::string sourceValue = pt.get_value<std::string>();
		try {
			value = (OpcUaSByte)boost::lexical_cast<OpcUaInt16>(sourceValue);
		} catch(boost::bad_lexical_cast& /*e*/) {
			Log(Error, "OpcUaSByte json decoder error - value format error")
				.parameter("Value", sourceValue);
			return false;
		}
		return true;
	}

	bool
	JsonNumber::jsonDecode(const boost::property_tree::ptree& pt, OpcUaUInt16& value)
	{
		std::string sourceValue = pt.get_value<std::string>();
		try {
			value = boost::lexical_cast<uint16_t>(sourceValue);
		} catch(boost::bad_lexical_cast& /*e*/) {
			Log(Error, "OpcUaUInt16 json decoder error - value format error")
				.parameter("Value", sourceValue);
			return false;
		}
		return true;
	}

	bool
	JsonNumber::jsonDecode(const boost::property_tree::ptree& pt, OpcUaInt16& value)
	{
		std::string sourceValue = pt.get_value<std::string>();
		try {
			value = boost::lexical_cast<int16_t>(sourceValue);
		} catch(boost::bad_lexical_cast& /*e*/) {
			Log(Error, "OpcUaInt16 json decoder error - value format error")
				.parameter("Value", sourceValue);
			return false;
		}
		return true;
	}

	bool
	JsonNumber::jsonDecode(const boost::property_tree::ptree& pt, OpcUaUInt32& value)
	{
		std::string sourceValue = pt.get_value<std::string>();
		try {
			value = boost::lexical_cast<uint32_t>(sourceValue);
		} catch(boost::bad_lexical_cast& /*e*/) {
			Log(Error, "OpcUaUInt32 json decoder error - value format error")
				.parameter("Value", sourceValue);
			return false;
		}
		return true;
	}

	bool
	JsonNumber::jsonDecode(const boost::property_tree::ptree& pt, OpcUaInt32& value)
	{
		std::string sourceValue = pt.get_value<std::string>();
		try {
			value = boost::lexical_cast<int32_t>(sourceValue);
		} catch(boost::bad_lexical_cast& /*e*/) {
			Log(Error, "OpcUaInt32 json decoder error - value format error")
				.parameter("Value", sourceValue);
			return false;
		}
		return true;
	}

	bool
	JsonNumber::jsonDecode(const boost::property_tree::ptree& pt, OpcUaUInt64& value)
	{
		std::string sourceValue = pt.get_value<std::string>();
		try {
			value = boost::lexical_cast<uint64_t>(sourceValue);
		} catch(boost::bad_lexical_cast& /*e*/) {
			Log(Error, "OpcUaUInt64 json decoder error - value format error")
				.parameter("Value", sourceValue);
			return false;
		}
		return true;
	}

	bool
	JsonNumber::jsonDecode(const boost::property_tree::ptree& pt, OpcUaInt64& value)
	{
		std::string sourceValue = pt.get_value<std::string>();
		try {
			value = boost::lexical_cast<int64_t>(sourceValue);
		} catch(boost::bad_lexical_cast& /*e*/) {
			Log(Error, "OpcUaInt64 json decoder error - value format error")
				.parameter("Value", sourceValue);
			return false;
		}
		return true;
	}

	bool
	JsonNumber::jsonDecode(const boost::property_tree::ptree& pt, OpcUaFloat& value)
	{
		std::string sourceValue = pt.get_value<std::string>();
		try {
			value = boost::lexical_cast<float>(sourceValue);
		} catch(boost::bad_lexical_cast& /*e*/) {
			Log(Error, "OpcUaFloat json decoder error - value format error")
				.parameter("Value", sourceValue);
			return false;
		}
		return true;
	}

	bool
	JsonNumber::jsonDecode(const boost::property_tree::ptree& pt, OpcUaDouble& value)
	{
		std::string sourceValue = pt.get_value<std::string>();
		try {
			value = boost::lexical_cast<double>(sourceValue);
		} catch(boost::bad_lexical_cast& /*e*/) {
			Log(Error, "OpcUaDouble json decoder error - value format error")
				.parameter("Value", sourceValue);
			return false;
		}
		return true;
	}

}
