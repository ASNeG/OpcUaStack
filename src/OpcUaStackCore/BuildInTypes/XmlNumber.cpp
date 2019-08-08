/*
   Copyright 2017-2018 Kai Huebl (kai@huebl-sgh.de)

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

#include <boost/algorithm/string/case_conv.hpp>
#include <boost/lexical_cast.hpp>
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/BuildInTypes/XmlNumber.h"

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
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaBoolean& value, const std::string& element)
	{
		boost::property_tree::ptree elementTree;
		if (!xmlEncode(elementTree, value)) {
			Log(Error, "OpcUaBoolean xml encode error")
				.parameter("Element", element);
			return false;
		}
		pt.push_back(std::make_pair(element, elementTree));
		return true;
	}

	bool
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaByte& value, const std::string& element)
	{
		boost::property_tree::ptree elementTree;
		if (!xmlEncode(elementTree, value)) {
			Log(Error, "OpcUaByte xml encode error")
				.parameter("Element", element);
			return false;
		}
		pt.push_back(std::make_pair(element, elementTree));
		return true;
	}

	bool
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaSByte& value, const std::string& element)
	{
		boost::property_tree::ptree elementTree;
		if (!xmlEncode(elementTree, value)) {
			Log(Error, "OpcUaSByte xml encode error")
				.parameter("Element", element);
			return false;
		}
		pt.push_back(std::make_pair(element, elementTree));
		return true;
	}

	bool
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaUInt16& value, const std::string& element)
	{
		boost::property_tree::ptree elementTree;
		if (!xmlEncode(elementTree, value)) {
			Log(Error, "OpcUaUInt16 xml encode error")
				.parameter("Element", element);
			return false;
		}
		pt.push_back(std::make_pair(element, elementTree));
		return true;
	}

	bool
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaInt16& value, const std::string& element)
	{
		boost::property_tree::ptree elementTree;
		if (!xmlEncode(elementTree, value)) {
			Log(Error, "OpcUaInt16 xml encode error")
				.parameter("Element", element);
			return false;
		}
		pt.push_back(std::make_pair(element, elementTree));
		return true;
	}

	bool
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaUInt32& value, const std::string& element)
	{
		boost::property_tree::ptree elementTree;
		if (!xmlEncode(elementTree, value)) {
			Log(Error, "OpcUaUInt32 xml encode error")
				.parameter("Element", element);
			return false;
		}
		pt.push_back(std::make_pair(element, elementTree));
		return true;
	}

	bool
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaInt32& value, const std::string& element)
	{
		boost::property_tree::ptree elementTree;
		if (!xmlEncode(elementTree, value)) {
			Log(Error, "OpcUaInt32 xml encode error")
				.parameter("Element", element);
			return false;
		}
		pt.push_back(std::make_pair(element, elementTree));
		return true;
	}

	bool
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaUInt64& value, const std::string& element)
	{
		boost::property_tree::ptree elementTree;
		if (!xmlEncode(elementTree, value)) {
			Log(Error, "OpcUaUInt64 xml encode error")
				.parameter("Element", element);
			return false;
		}
		pt.push_back(std::make_pair(element, elementTree));
		return true;
	}

	bool
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaInt64& value, const std::string& element)
	{
		boost::property_tree::ptree elementTree;
		if (!xmlEncode(elementTree, value)) {
			Log(Error, "OpcUaInt64 xml encode error")
				.parameter("Element", element);
			return false;
		}
		pt.push_back(std::make_pair(element, elementTree));
		return true;
	}

	bool
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaFloat& value, const std::string& element)
	{
		boost::property_tree::ptree elementTree;
		if (!xmlEncode(elementTree, value)) {
			Log(Error, "Float xml encode error")
				.parameter("Element", element);
			return false;
		}
		pt.push_back(std::make_pair(element, elementTree));
		return true;
	}

	bool
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaDouble& value, const std::string& element)
	{
		boost::property_tree::ptree elementTree;
		if (!xmlEncode(elementTree, value)) {
			Log(Error, "OpcUaDouble xml encode error")
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
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaBoolean& value)
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
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaByte& value)
	{
		std::stringstream ss;
		ss << (int16_t)value;
		pt.put_value(ss.str());
		return true;
	}

	bool
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaSByte& value)
	{
		std::stringstream ss;
		ss << (int16_t)value;
		pt.put_value(ss.str());
		return true;
	}

	bool
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaUInt16& value)
	{
		std::stringstream ss;
		ss << value;
		pt.put_value(ss.str());
		return true;
	}

	bool
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaInt16& value)
	{
		std::stringstream ss;
		ss << value;
		pt.put_value(ss.str());
		return true;
	}

	bool
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaUInt32& value)
	{
		std::stringstream ss;
		ss << value;
		pt.put_value(ss.str());
		return true;
	}

	bool
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaInt32& value)
	{
		std::stringstream ss;
		ss << value;
		pt.put_value(ss.str());
		return true;
	}

	bool
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaUInt64& value)
	{
		std::stringstream ss;
		ss << value;
		pt.put_value(ss.str());
		return true;
	}

	bool
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaInt64& value)
	{
		std::stringstream ss;
		ss << value;
		pt.put_value(ss.str());
		return true;
	}

	bool
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaFloat& value)
	{
		std::stringstream ss;
		ss << value;
		pt.put_value(ss.str());
		return true;
	}

	bool
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaDouble& value)
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
	XmlNumber::xmlDecode(boost::property_tree::ptree& pt, OpcUaBoolean& value, const std::string& element)
	{
		boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
		if (!tree) return false;
		return XmlNumber::xmlDecode(*tree, value);
	}

	bool
	XmlNumber::xmlDecode(boost::property_tree::ptree& pt, OpcUaByte& value, const std::string& element)
	{
		boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
		if (!tree) return false;
		return XmlNumber::xmlDecode(*tree, value);
	}

	bool
	XmlNumber::xmlDecode(boost::property_tree::ptree& pt, OpcUaSByte& value, const std::string& element)
	{
		boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
		if (!tree) return false;
		return XmlNumber::xmlDecode(*tree, value);
	}

	bool
	XmlNumber::xmlDecode(boost::property_tree::ptree& pt, OpcUaUInt16& value, const std::string& element)
	{
		boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
		if (!tree) return false;
		return XmlNumber::xmlDecode(*tree, value);
	}

	bool
	XmlNumber::xmlDecode(boost::property_tree::ptree& pt, OpcUaInt16& value, const std::string& element)
	{
		boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
		if (!tree) return false;
		return XmlNumber::xmlDecode(*tree, value);
	}

	bool
	XmlNumber::xmlDecode(boost::property_tree::ptree& pt, OpcUaUInt32& value, const std::string& element)
	{
		boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
		if (!tree) return false;
		return XmlNumber::xmlDecode(*tree, value);
	}

	bool
	XmlNumber::xmlDecode(boost::property_tree::ptree& pt, OpcUaInt32& value, const std::string& element)
	{
		boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
		if (!tree) return false;
		return XmlNumber::xmlDecode(*tree, value);
	}

	bool
	XmlNumber::xmlDecode(boost::property_tree::ptree& pt, OpcUaUInt64& value, const std::string& element)
	{
		boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
		if (!tree) return false;
		return XmlNumber::xmlDecode(*tree, value);
	}

	bool
	XmlNumber::xmlDecode(boost::property_tree::ptree& pt, OpcUaInt64& value, const std::string& element)
	{
		boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
		if (!tree) return false;
		return XmlNumber::xmlDecode(*tree, value);
	}

	bool
	XmlNumber::xmlDecode(boost::property_tree::ptree& pt, OpcUaFloat& value, const std::string& element)
	{
		boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
		if (!tree) return false;
		return XmlNumber::xmlDecode(*tree, value);
	}

	bool
	XmlNumber::xmlDecode(boost::property_tree::ptree& pt, OpcUaDouble& value, const std::string& element)
	{
		boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
		if (!tree) return false;
		return XmlNumber::xmlDecode(*tree, value);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// decoder
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	XmlNumber::xmlDecode(boost::property_tree::ptree& pt, OpcUaBoolean& value)
	{
		std::string sourceValue = pt.get_value<std::string>();
		boost::to_upper(sourceValue);
		if (sourceValue == "TRUE") value = true;
		else value = false;
		return true;
	}

	bool
	XmlNumber::xmlDecode(boost::property_tree::ptree& pt, OpcUaByte& value)
	{
		std::string sourceValue = pt.get_value<std::string>();
		try {
			value = (OpcUaByte)boost::lexical_cast<OpcUaUInt16>(sourceValue);
		} catch(boost::bad_lexical_cast& /*e*/) {
			Log(Error, "OpcUaByte xml decoder error - value format error")
				.parameter("Value", sourceValue);
			return false;
		}
		return true;
	}

	bool
	XmlNumber::xmlDecode(boost::property_tree::ptree& pt, OpcUaSByte& value)
	{
		std::string sourceValue = pt.get_value<std::string>();
		try {
			value = (OpcUaSByte)boost::lexical_cast<OpcUaInt16>(sourceValue);
		} catch(boost::bad_lexical_cast& /*e*/) {
			Log(Error, "OpcUaSByte xml decoder error - value format error")
				.parameter("Value", sourceValue);
			return false;
		}
		return true;
	}

	bool
	XmlNumber::xmlDecode(boost::property_tree::ptree& pt, OpcUaUInt16& value)
	{
		std::string sourceValue = pt.get_value<std::string>();
		try {
			value = boost::lexical_cast<uint16_t>(sourceValue);
		} catch(boost::bad_lexical_cast& /*e*/) {
			Log(Error, "OpcUaUInt16 xml decoder error - value format error")
				.parameter("Value", sourceValue);
			return false;
		}
		return true;
	}

	bool
	XmlNumber::xmlDecode(boost::property_tree::ptree& pt, OpcUaInt16& value)
	{
		std::string sourceValue = pt.get_value<std::string>();
		try {
			value = boost::lexical_cast<int16_t>(sourceValue);
		} catch(boost::bad_lexical_cast& /*e*/) {
			Log(Error, "OpcUaInt16 xml decoder error - value format error")
				.parameter("Value", sourceValue);
			return false;
		}
		return true;
	}

	bool
	XmlNumber::xmlDecode(boost::property_tree::ptree& pt, OpcUaUInt32& value)
	{
		std::string sourceValue = pt.get_value<std::string>();
		try {
			value = boost::lexical_cast<uint32_t>(sourceValue);
		} catch(boost::bad_lexical_cast& /*e*/) {
			Log(Error, "OpcUaUInt32 xml decoder error - value format error")
				.parameter("Value", sourceValue);
			return false;
		}
		return true;
	}

	bool
	XmlNumber::xmlDecode(boost::property_tree::ptree& pt, OpcUaInt32& value)
	{
		std::string sourceValue = pt.get_value<std::string>();
		try {
			value = boost::lexical_cast<int32_t>(sourceValue);
		} catch(boost::bad_lexical_cast& /*e*/) {
			Log(Error, "OpcUaInt32 xml decoder error - value format error")
				.parameter("Value", sourceValue);
			return false;
		}
		return true;
	}

	bool
	XmlNumber::xmlDecode(boost::property_tree::ptree& pt, OpcUaUInt64& value)
	{
		std::string sourceValue = pt.get_value<std::string>();
		try {
			value = boost::lexical_cast<uint64_t>(sourceValue);
		} catch(boost::bad_lexical_cast& /*e*/) {
			Log(Error, "OpcUaUInt64 xml decoder error - value format error")
				.parameter("Value", sourceValue);
			return false;
		}
		return true;
	}

	bool
	XmlNumber::xmlDecode(boost::property_tree::ptree& pt, OpcUaInt64& value)
	{
		std::string sourceValue = pt.get_value<std::string>();
		try {
			value = boost::lexical_cast<int64_t>(sourceValue);
		} catch(boost::bad_lexical_cast& /*e*/) {
			Log(Error, "OpcUaInt64 xml decoder error - value format error")
				.parameter("Value", sourceValue);
			return false;
		}
		return true;
	}

	bool
	XmlNumber::xmlDecode(boost::property_tree::ptree& pt, OpcUaFloat& value)
	{
		std::string sourceValue = pt.get_value<std::string>();
		try {
			value = boost::lexical_cast<float>(sourceValue);
		} catch(boost::bad_lexical_cast& /*e*/) {
			Log(Error, "OpcUaFloat xml decoder error - value format error")
				.parameter("Value", sourceValue);
			return false;
		}
		return true;
	}

	bool
	XmlNumber::xmlDecode(boost::property_tree::ptree& pt, OpcUaDouble& value)
	{
		std::string sourceValue = pt.get_value<std::string>();
		try {
			value = boost::lexical_cast<double>(sourceValue);
		} catch(boost::bad_lexical_cast& /*e*/) {
			Log(Error, "OpcUaDouble xml decoder error - value format error")
				.parameter("Value", sourceValue);
			return false;
		}
		return true;
	}

}
