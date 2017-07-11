/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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
		if (!xmlEncode(pt, value)) return false;
		pt.push_back(std::make_pair(element, elementTree));
		return true;
	}

	bool
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaByte& value, const std::string& element)
	{
		boost::property_tree::ptree elementTree;
		if (!xmlEncode(pt, value)) return false;
		pt.push_back(std::make_pair(element, elementTree));
		return true;
	}

	bool
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaSByte& value, const std::string& element)
	{
		boost::property_tree::ptree elementTree;
		if (!xmlEncode(pt, value)) return false;
		pt.push_back(std::make_pair(element, elementTree));
		return true;
	}

	bool
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaUInt16& value, const std::string& element)
	{
		boost::property_tree::ptree elementTree;
		if (!xmlEncode(pt, value)) return false;
		pt.push_back(std::make_pair(element, elementTree));
		return true;
	}

	bool
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaInt16& value, const std::string& element)
	{
		boost::property_tree::ptree elementTree;
		if (!xmlEncode(pt, value)) return false;
		pt.push_back(std::make_pair(element, elementTree));
		return true;
	}

	bool
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaUInt32& value, const std::string& element)
	{
		boost::property_tree::ptree elementTree;
		if (!xmlEncode(pt, value)) return false;
		pt.push_back(std::make_pair(element, elementTree));
		return true;
	}

	bool
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaInt32& value, const std::string& element)
	{
		boost::property_tree::ptree elementTree;
		if (!xmlEncode(pt, value)) return false;
		pt.push_back(std::make_pair(element, elementTree));
		return true;
	}

	bool
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaUInt64& value, const std::string& element)
	{
		boost::property_tree::ptree elementTree;
		if (!xmlEncode(pt, value)) return false;
		pt.push_back(std::make_pair(element, elementTree));
		return true;
	}

	bool
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaInt64& value, const std::string& element)
	{
		boost::property_tree::ptree elementTree;
		if (!xmlEncode(pt, value)) return false;
		pt.push_back(std::make_pair(element, elementTree));
		return true;
	}

	bool
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaFloat& value, const std::string& element)
	{
		boost::property_tree::ptree elementTree;
		if (!xmlEncode(pt, value)) return false;
		pt.push_back(std::make_pair(element, elementTree));
		return true;
	}

	bool
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaDouble& value, const std::string& element)
	{
		boost::property_tree::ptree elementTree;
		if (!xmlEncode(pt, value)) return false;
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
		// FIXME: todo
		return true;
	}

	bool
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaSByte& value)
	{
		// FIXME: todo
		return true;
	}

	bool
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaUInt16& value)
	{
		// FIXME: todo
		return true;
	}

	bool
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaInt16& value)
	{
		// FIXME: todo
		return true;
	}

	bool
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaUInt32& value)
	{
		// FIXME: todo
		return true;
	}

	bool
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaInt32& value)
	{
		// FIXME: todo
		return true;
	}

	bool
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaUInt64& value)
	{
		// FIXME: todo
		return true;
	}

	bool
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaInt64& value)
	{
		// FIXME: todo
		return true;
	}

	bool
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaFloat& value)
	{
		// FIXME: todo
		return true;
	}

	bool
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaDouble& value)
	{
		// FIXME: todo
		return true;
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
		// FIXME: todo
		return true;
	}

	bool
	XmlNumber::xmlDecode(boost::property_tree::ptree& pt, OpcUaByte& value)
	{
		// FIXME: todo
		return true;
	}

	bool
	XmlNumber::xmlDecode(boost::property_tree::ptree& pt, OpcUaSByte& value)
	{
		// FIXME: todo
		return true;
	}

	bool
	XmlNumber::xmlDecode(boost::property_tree::ptree& pt, OpcUaUInt16& value)
	{
		// FIXME: todo
		return true;
	}

	bool
	XmlNumber::xmlDecode(boost::property_tree::ptree& pt, OpcUaInt16& value)
	{
		// FIXME: todo
		return true;
	}

	bool
	XmlNumber::xmlDecode(boost::property_tree::ptree& pt, OpcUaUInt32& value)
	{
		// FIXME: todo
		return true;
	}

	bool
	XmlNumber::xmlDecode(boost::property_tree::ptree& pt, OpcUaInt32& value)
	{
		// FIXME: todo
		return true;
	}

	bool
	XmlNumber::xmlDecode(boost::property_tree::ptree& pt, OpcUaUInt64& value)
	{
		// FIXME: todo
		return true;
	}

	bool
	XmlNumber::xmlDecode(boost::property_tree::ptree& pt, OpcUaInt64& value)
	{
		// FIXME: todo
		return true;
	}

	bool
	XmlNumber::xmlDecode(boost::property_tree::ptree& pt, OpcUaFloat& value)
	{
		// FIXME: todo
		return true;
	}

	bool
	XmlNumber::xmlDecode(boost::property_tree::ptree& pt, OpcUaDouble& value)
	{
		// FIXME: todo
		return true;
	}

}
