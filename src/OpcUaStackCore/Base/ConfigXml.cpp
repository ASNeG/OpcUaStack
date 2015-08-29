/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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
	ConfigXml::read(const std::string& configFileName)
	{
		return parse(configFileName);
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
