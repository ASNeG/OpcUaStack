/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_Config_h__
#define __OpcUaStackCore_Config_h__

#include <boost/shared_ptr.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/lexical_cast.hpp>
#include <vector>
#include <map>
#include "OpcUaStackCore/Base/ConfigIf.h"

namespace OpcUaStackCore
{

	class DLLEXPORT Config 
	: public ConfigIf
	{
	  public:
		typedef boost::shared_ptr<Config> SPtr;
		typedef std::map<std::string, Config::SPtr> Map;
		typedef std::map<std::string, std::string> AliasMap;

		static Config* instance_;
		static Config* instance(void);
		static void destroy(void);

		Config(void);
		Config(boost::property_tree::ptree& child);
		~Config(void);

		void child(boost::property_tree::ptree& child);
		boost::property_tree::ptree& child(void);

		bool setValue(const std::string& value);
		bool setValue(const std::string& path, const std::string& value);
		bool setChild(const std::string& path, Config& config);

		bool addValue(const std::string& path, const std::string& value);
		bool addChild(const std::string& path, Config& config);

		std::string getValue(void);
		boost::optional<std::string> getValue(const std::string& path);
		std::string getValue(const std::string& path, const std::string& defaultValue);
		void getValues(const std::string& path, std::vector<std::string>& valueVec);
		boost::optional<Config> getChild(const std::string& path);
		void getChilds(const std::string& path, std::vector<Config>& configVec);

		template<typename T>
		  bool getConfigParameter(T& value)
		  {
			  std::string sourceValue = getValue();
			  try {
				  value = boost::lexical_cast<T>(sourceValue);
			  } catch(boost::bad_lexical_cast&) {
				  return false;
			  }
			  return true;
		  }

		template<typename T>
		  bool getConfigParameter(const std::string& path, T& value)
		  {
			  boost::optional<std::string> sourceValue = getValue(path);
			  if (!sourceValue) return false;
			  try {
				  value = boost::lexical_cast<T>(*sourceValue);
			  } catch(boost::bad_lexical_cast&) {
				  return false;
			  }
			  return true;
		  }

		template<typename T>
		  bool getConfigParameter(const std::string& path, T&value, const std::string& defaultValue)
		  {
			  bool cast = true;

			  boost::optional<std::string> sourceValue = getValue(path);
			  if (!sourceValue) sourceValue = defaultValue;
			  try {
				  value = boost::lexical_cast<T>(*sourceValue);
			  } catch(boost::bad_lexical_cast&) {
				  cast = false;
			  }

			  if (cast == false) {
				  sourceValue = defaultValue;
				  try {
				      value = boost::lexical_cast<T>(*sourceValue);
				  } catch(boost::bad_lexical_cast&) {
				      return false;
			      }
			  }

			  return true;
		  }

		template<typename T>
		  bool isConfigParameterFromType(void)
		  {
			  std::string sourceValue = getValue();
			  try {
				  T value = boost::lexical_cast<T>(sourceValue);
			  } catch(boost::bad_lexical_cast&) {
				  return false;
			  }
			  return true;
		  }

		template<typename T>
		  bool isConfigParameterFromType(const std::string& path)
		  {
			  boost::optional<std::string> sourceValue = getValue(path);
			  if (!sourceValue) return false;
			  try {
				  T value = boost::lexical_cast<T>(*sourceValue);
			  } catch(boost::bad_lexical_cast&) {
				  return false;
			  }
			  return true;
		  }
		  
		bool exist(const std::string& path);
		bool erase(const std::string& path);
		void clear(void);

		std::string configFileName(void);

		bool aliasExist(const std::string& aliasName);
		void alias(const std::string& aliasName, const std::string& aliasValue);
		std::string alias(const std::string& aliasName);
		void aliasMap(AliasMap& aliasMap);
		AliasMap& aliasMap(void);
		void out(std::ostream& os);

	  private:
		void out(std::ostream& os, boost::property_tree::ptree& ptree, uint32_t depth = 0);
		void getValuesFromName(const std::string& valueName, std::vector<std::string>& valueVec);
		void getChildFromName(const std::string& valueName, std::vector<Config>& valueVec);
		static void substAlias(std::string& value);

		boost::property_tree::ptree child_;
		static AliasMap aliasMap_;
	};

}

#endif
