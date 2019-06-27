/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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

#include <boost/version.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/filesystem.hpp>

#include <iostream>

#include "OpcUaStackCore/Base/ConfigXml.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/Base/Log.h"

namespace OpcUaStackCore
{

	ConfigXml::ConfigXml(void)
	: configFileName_("")
	, errorMessage_("")
	, ptree_()
	{
	}

	ConfigXml::~ConfigXml(void)
	{
	}

	void
	ConfigXml::clear(void)
	{
		configFileName_ = "";
		errorMessage_ = "";
		ptree_.clear();
	}

	bool 
	ConfigXml::write(const std::string& configFileName)
	{
		try 
		{
#if BOOST_VERSION >= 105800
			boost::property_tree::xml_writer_settings<std::string> settings('\t', 1);
#else
			boost::property_tree::xml_writer_settings<char> settings('\t', 1);
#endif
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
	ConfigXml::write(std::ostream& os)
	{
		try
		{
#if BOOST_VERSION >= 105800
			boost::property_tree::xml_writer_settings<std::string> settings('\t', 1);
#else
			boost::property_tree::xml_writer_settings<char> settings('\t', 1);
#endif
			boost::property_tree::write_xml(os, ptree_);
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
	ConfigXml::read(std::istream& is)
	{
		return parse(is);
	}

	bool
	ConfigXml::parse(std::istream& is)
	{
		errorMessage_ = "";

		// read configuration from xml file
		try
		{
			boost::property_tree::read_xml(is, ptree_, boost::property_tree::xml_parser::trim_whitespace);
		}
		catch (const boost::property_tree::xml_parser_error& e)
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

	bool
	ConfigXml::parse(const std::string& configFileName, ConfigIf* configIf)
	{
		configFileName_ = configFileName;
		errorMessage_ = "";

		// check if xml file exist
		boost::filesystem::path fileName(configFileName);
		if (!boost::filesystem::exists(fileName)) {
			errorMessage_ = "file do not exist";
			return false;
		}

		// check if file is readable
#if 0
		boost::filesystem::file_status stat;
		stat = boost::filesystem::status(fileName);
		boost::filesystem::perms perms = stat.permissions();
		if ((perms & boost::filesystem::perms::owner_read) != boost::filesystem::perms::owner_read) {
			errorMessage_ = "file is not readable";
			return false;
		}
#endif

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
		catch (...)
		{
			errorMessage_ = std::string("unknown exception in read xml");
			return false;
		}

		// write property tree to configuration
		this->writeToConfig(configIf);

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

	void
	ConfigXml::writeToConfig(ConfigIf* configIf)
	{
		// write property tree into configuration
		configIf->child(ptree_);
		configIf->addValue("Global.ConfigurationFileName", configFileName_);
	}

	void
	ConfigXml::find(const std::string& elementName, std::vector<boost::property_tree::ptree>& ptrees)
	{
		find(elementName, ptree_, ptrees);
	}

	void
	ConfigXml::find(
		const std::string& elementName,
		boost::property_tree::ptree& ptree,
		std::vector<boost::property_tree::ptree>& ptrees
	)
	{
		boost::property_tree::ptree::iterator it;
		for (it = ptree.begin(); it != ptree.end(); it++) {
			if (it->first == elementName) {
				ptrees.push_back(it->second);
			}
			else {
				find(elementName, it->second, ptrees);
			}
		}
	}

	void
	ConfigXml::createElementNameSet(boost::property_tree::ptree& ptree, std::set<std::string>& elementNameSet)
	{
		boost::property_tree::ptree::iterator it;
		for (it = ptree.begin(); it != ptree.end(); it++) {
			if (it->first != "<xmlattr>") {
				elementNameSet.insert(it->first);
				createElementNameSet(it->second, elementNameSet);
			}
		}
	}

	void
	ConfigXml::createAttributeNameSet(boost::property_tree::ptree& ptree, std::set<std::string>& attributeNameSet)
	{
		boost::property_tree::ptree::iterator it1, it2;
		for (it1 = ptree.begin(); it1 != ptree.end(); it1++) {
			if (it1->first != "<xmlattr>") {
				createAttributeNameSet(it1->second, attributeNameSet);
			}
			else {
				for (it2 = it1->second.begin(); it2 != it1->second.end(); it2++) {
					attributeNameSet.insert(it2->first);
				}
			}

		}
	}

}
