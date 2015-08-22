#include "OpcUaStackCore/BuildInTypes/Json.h"

namespace OpcUaStackCore
{

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
