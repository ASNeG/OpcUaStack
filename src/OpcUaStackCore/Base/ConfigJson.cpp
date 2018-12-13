/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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
#include <boost/property_tree/json_parser.hpp>
#include <boost/filesystem.hpp>

#include <iostream>

#include "OpcUaStackCore/Base/ConfigJson.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/Base/Log.h"

namespace OpcUaStackCore
{

	ConfigJson::ConfigJson(void)
	: configFileName_("")
	, errorMessage_("")
	, ptree_()
	{
	}

	ConfigJson::~ConfigJson(void)
	{
	}

	void
	ConfigJson::clear(void)
	{
		configFileName_ = "";
		errorMessage_ = "";
		ptree_.clear();
	}

	bool 
	ConfigJson::write(const std::string& configFileName)
	{
		try 
		{
			boost::property_tree::write_json(configFileName, ptree_);
		}
		catch(const boost::property_tree::json_parser_error& e)
		{
			errorMessage_ = std::string(e.what());
			return false;
		}
		return true;
	}

	bool
	ConfigJson::write(std::ostream& os)
	{
		try
		{
			boost::property_tree::write_json(os, ptree_);
		}
		catch(const boost::property_tree::json_parser_error& e)
		{
			errorMessage_ = std::string(e.what());
			return false;
		}
		return true;
	}

	bool
	ConfigJson::read(const std::string& configFileName)
	{
		return parse(configFileName);
	}

	bool
	ConfigJson::read(std::istream& is)
	{
		return parse(is);
	}

	bool
	ConfigJson::parse(std::istream& is)
	{
		errorMessage_ = "";

		// read configuration from xml file
		try
		{
			boost::property_tree::read_json(is, ptree_);
		}
		catch (const boost::property_tree::json_parser_error& e)
		{
			errorMessage_ = std::string(e.what());
			return false;
		}

		return true;
	}

	bool 
	ConfigJson::parse(const std::string& configFileName, bool writeToConfig)
	{
		configFileName_ = configFileName;
		errorMessage_ = "";

		// read configuration from xml file
		try
		{
			boost::property_tree::read_json(configFileName, ptree_);
		}
		catch (const boost::property_tree::json_parser_error& e)
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
	ConfigJson::parse(const std::string& configFileName, ConfigIf* configIf)
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
			boost::property_tree::read_json(configFileName, ptree_);
		}
		catch (const boost::property_tree::json_parser_error& e)
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
	ConfigJson::errorMessage(void)
	{
		return errorMessage_;
	}

	boost::property_tree::ptree& 
	ConfigJson::ptree(void)
	{
		return ptree_;
	}

	void 
	ConfigJson::ptree(boost::property_tree::ptree& ptree)
	{
		ptree_ = ptree;
	}

	void 
	ConfigJson::writeToConfig(void)
	{
		// write property tree into configuration
		Config* config = Config::instance();
		config->child(ptree_);
		config->addValue("Global.ConfigurationFileName", configFileName_);
	}

	void
	ConfigJson::writeToConfig(ConfigIf* configIf)
	{
		// write property tree into configuration
		configIf->child(ptree_);
		configIf->addValue("Global.ConfigurationFileName", configFileName_);
	}

	void
	ConfigJson::find(const std::string& elementName, std::vector<boost::property_tree::ptree>& ptrees)
	{
		find(elementName, ptree_, ptrees);
	}

	void
	ConfigJson::find(
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
	ConfigJson::createElementNameSet(boost::property_tree::ptree& ptree, std::set<std::string>& elementNameSet)
	{
		boost::property_tree::ptree::iterator it;
		for (it = ptree.begin(); it != ptree.end(); it++) {
			elementNameSet.insert(it->first);
			createElementNameSet(it->second, elementNameSet);
		}
	}

}
