#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include "OpcUaStackCore/Base/ConfigXml.h"
#include "OpcUaStackCore/Base/Config.h"

namespace OpcUaStackCore
{

	ConfigXml::ConfigXml(void)
	: configFileName_("")
	, errorMessage_("")
	{
	}

	ConfigXml::~ConfigXml(void)
	{
	}

	bool 
	ConfigXml::parse(const std::string& configFileName, bool writeToConfig)
	{
		configFileName_ = configFileName;
		errorMessage_ = "";

		try
		{
		    boost::property_tree::read_xml(configFileName, ptree_);
		}
		catch (const boost::property_tree::xml_parser_error& e)
		{
			errorMessage_ = std::string(e.what());
			return false;
		}

		if (writeToConfig) {
			this->writeToConfig();
		}

		return true;
	}

	std::string
	ConfigXml::errorMessage(void)
	{
		return errorMessage_;
	}

	boost::property_tree::ptree& 
	ConfigXml::ptree(void)
	{
		return ptree_;
	}

	void 
	ConfigXml::writeToConfig(void)
	{
		Config* config = Config::instance();
		config->child(ptree_);
		config->addValue("Global.ConfigurationFileName", configFileName_);
	}

}