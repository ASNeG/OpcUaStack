/*
   Copyright 2016-2019 Kai Huebl (kai@huebl-sgh.de)

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

#include <boost/make_shared.hpp>
#include "OpcUaStackCore/Base/ConfigXmlManager.h"
#include "OpcUaStackCore/Base/ConfigXml.h"

namespace OpcUaStackCore
{

	ConfigXmlManager::ConfigXmlManager(void)
	: configMap_()
	, errorMessage_("")
	{
	}

	ConfigXmlManager::~ConfigXmlManager(void)
	{
		while (configMap_.size() > 0) {
			deregisterConfiguration(configMap_.begin()->first);
		}
	}

	bool
	ConfigXmlManager::registerConfiguration(const std::string& configurationFileName, Config::SPtr& config)
	{
		errorMessage_ = "";

		Config::Map::iterator it;
		it = configMap_.find(configurationFileName);
		if (it != configMap_.end()) {
			config = it->second;
			return true;
		}

		// read configuration file
		config = boost::make_shared<Config>();
		ConfigXml configXml;
		if (!configXml.parse(configurationFileName, config.get())) {
			errorMessage_ = configXml.errorMessage();
			return false;
		}
		return true;
	}

	bool
	ConfigXmlManager::deregisterConfiguration(const std::string& configurationFileName)
	{
		errorMessage_ = "";

		Config::Map::iterator it;
		it = configMap_.find(configurationFileName);
		if (it == configMap_.end()) return false;
		configMap_.erase(it);
		return false;
	}

	bool
	ConfigXmlManager::existConfiguration(const std::string& configurationFileName)
	{
		errorMessage_ = "";

		Config::Map::iterator it;
		it = configMap_.find(configurationFileName);
		if (it != configMap_.end()) return false;
		return false;
	}

	std::string&
	ConfigXmlManager::errorMessage(void)
	{
		return errorMessage_;
	}


}
