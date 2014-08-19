#include "OpcUaStackCore/Base/Config.h"

namespace OpcUaStackCore
{

	Config::Config(void)
	: cfg_()
	{
	}

	Config::~Config(void)
	{
	}

	bool 
	Config::setValue(const std::string& path, const std::string& value)
	{
		boost::optional<std::string> val = getValue(path);
		if (val) return false;
		cfg_.put(path, value);
		return true;
	}

	boost::optional<std::string>
	Config::getValue(const std::string& path)
	{
		return cfg_.get_optional<std::string>(path);
	}
		
	std::string 
	Config::getValue(const std::string& path, const std::string& defaultValue)
	{
		boost::optional<std::string> val;
		val = getValue(path);
		if (val) return *val;
		return defaultValue;
	}
}