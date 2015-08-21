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

}
