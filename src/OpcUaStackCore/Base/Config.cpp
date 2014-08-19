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
	Config::set(const std::string& path, const std::string& value)
	{
		boost::optional<std::string> val = get(path);
		if (val) return false;
		cfg_.put(path, value);
		return true;
	}

	boost::optional<std::string>
	Config::get(const std::string& path)
	{
		return cfg_.get_optional<std::string>(path);
	}
		
	std::string 
	Config::get(const std::string& path, const std::string& defaultValue)
	{
		boost::optional<std::string> val;
		val = get(path);
		if (val) return *val;
		return defaultValue;
	}
}