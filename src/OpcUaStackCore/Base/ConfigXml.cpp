#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/filesystem.hpp>
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
	ConfigXml::write(const std::string& configFileName)
	{
		try 
		{
			boost::property_tree::xml_writer_settings<char> settings('\t', 1);
			boost::property_tree::write_xml(configFileName, ptree_, std::locale(), settings);
		}
		catch(const boost::property_tree::xml_parser_error& e)
		{
			errorMessage_ = std::string(e.what());
			return false;
		}
		return true;
	}

	bool 
	ConfigXml::parse(const std::string& configFileName, bool writeToConfig)
	{
		configFileName_ = configFileName;
		errorMessage_ = "";

		// read configuration from xml file
		try
		{
			boost::property_tree::read_xml(configFileName, ptree_, boost::property_tree::xml_parser::trim_whitespace);
		}
		catch (const boost::property_tree::xml_parser_error& e)
		{
			errorMessage_ = std::string(e.what());
			return false;
		}

		// write property tree to configuration
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
	ConfigXml::ptree(boost::property_tree::ptree& ptree)
	{
		ptree_ = ptree;
	}

	void 
	ConfigXml::writeToConfig(void)
	{
		// write property tree into configuration
		Config* config = Config::instance();
		config->child(ptree_);
		config->addValue("Global.ConfigurationFileName", configFileName_);
	}

}
