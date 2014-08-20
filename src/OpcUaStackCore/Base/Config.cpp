#include "OpcUaStackCore/Base/Config.h"

namespace OpcUaStackCore
{

	Config::Config(void)
	: child_()
	{
	}

	Config::Config(boost::property_tree::ptree& child)
	: child_(child)
	{
	}

	Config::~Config(void)
	{
	}

	void 
	Config::child(boost::property_tree::ptree& child)
	{
		child_ = child;
	}

	boost::property_tree::ptree& 
	Config::child(void)
	{
		return child_;
	}

	bool 
	Config::setValue(const std::string& path, const std::string& value)
	{
		boost::optional<std::string> val = getValue(path);
		if (val) return false;
		child_.put(path, value);
		return true;
	}

	bool 
	Config::setChild(const std::string& path, Config& config)
	{
		boost::optional<std::string> val = getValue(path);
		if (val) return false;

		child_.add_child(path, config.child());
		return true;
	}

	std::string 
	Config::getValue(void)
	{
		return child_.data();
	}

	boost::optional<std::string>
	Config::getValue(const std::string& path)
	{
		return child_.get_optional<std::string>(path);
	}
		
	std::string 
	Config::getValue(const std::string& path, const std::string& defaultValue)
	{
		boost::optional<std::string> value = getValue(path);
		if (value) return *value;
		return defaultValue;
	}

	boost::optional<Config>
	Config::getChild(const std::string& path)
	{
		boost::optional<boost::property_tree::ptree&> child = child_.get_child_optional(path);
		if (!child) return boost::none;
		Config config(*child);
		return config;
	}

	bool 
	Config::exist(const std::string& path)
	{
		boost::optional<std::string> value = getValue(path);
		if (!value) return false;
		return true;
	}

	bool 
	Config::erase(const std::string& path)
	{
		boost::optional<boost::property_tree::ptree&> child = child_.get_child_optional(path);
		if (!child) return false;
		child_.erase(path);
		return true;
	}

}