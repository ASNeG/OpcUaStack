/*
   Copyright 2015-2020 Kai Huebl (kai@huebl-sgh.de)

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
#include <iostream>
#include <typeinfo>
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
		bool existChild(const std::string& path);
		boost::optional<Config> getChild(const std::string& path);
		void getChilds(const std::string& path, std::vector<Config>& configVec);

		template<typename T>
		  std::string convertToBaseType(const std::string& value) {
				if (typeid(T) == typeid(uint8_t) || typeid(T) == typeid(uint16_t) ||
					typeid(T) == typeid(uint32_t) || typeid(T) == typeid(uint64_t)) {
					if (value.substr(0,2) == std::string("0x")) {
						uint64_t val;
						std::stringstream ss0;
						ss0 << std::hex << value.substr(2);
						ss0 >> val;

						std::stringstream ss1;
						ss1 << val;
						return ss1.str();
					}
				}
				return value;
		  }

		template<typename T>
		  bool getConfigParameter(T& value)
		  {
			  std::string sourceValue = getValue();
			  sourceValue = convertToBaseType<T>(sourceValue);
			  try {
				  value = boost::lexical_cast<T>(sourceValue);
			  } catch(boost::bad_lexical_cast&) {
				  return false;
			  }
			  return true;
		  }
		bool getConfigParameter(uint8_t& value);
		bool getConfigParameter(int8_t& value);

		template<typename T>
		  bool getConfigParameter(const std::string& path, T& value)
		  {
			  boost::optional<std::string> sourceValue = getValue(path);
			  if (!sourceValue) return false;
			  auto sourceValueTmp = convertToBaseType<T>(*sourceValue);
			  try {
				  value = boost::lexical_cast<T>(sourceValueTmp);
			  } catch(boost::bad_lexical_cast&) {
				  return false;
			  }
			  return true;
		  }
		bool getConfigParameter(const std::string& path, uint8_t& value);
		bool getConfigParameter(const std::string& path, int8_t& value);

		template<typename T>
		  bool getConfigParameter(const std::string& path, T&value, const std::string& defaultValue)
		  {
			  bool cast = true;

			  boost::optional<std::string> sourceValue = getValue(path);
			  if (!sourceValue) sourceValue = defaultValue;
			  auto sourceValueTmp = convertToBaseType<T>(*sourceValue);
			  try {
				  value = boost::lexical_cast<T>(sourceValueTmp);
			  } catch(boost::bad_lexical_cast&) {
				  cast = false;
			  }

			  if (cast == false) {
				  sourceValueTmp = convertToBaseType<T>(defaultValue);
				  try {
				      value = boost::lexical_cast<T>(sourceValueTmp);
				  } catch(boost::bad_lexical_cast&) {
				      return false;
			      }
			  }

			  return true;
		  }
		bool getConfigParameter(const std::string& path, uint8_t& value, const std::string& defaultValue);
		bool getConfigParameter(const std::string& path, int8_t& value, const std::string& defaultValue);

		template<typename T>
		  bool isConfigParameterFromType(void)
		  {
			  std::string sourceValue = convertToBaseType<T>(getValue());
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
			  auto sourceValueTmp = convertToBaseType<T>(*sourceValue);
			  try {
				  T value = boost::lexical_cast<T>(sourceValueTmp);
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
		void outAliasMap(std::ostream& os);
		void outAll(std::ostream& os);

	  private:
		void out(std::ostream& os, boost::property_tree::ptree& ptree, uint32_t depth = 0);
		void out(std::ostream& os, AliasMap& aliasMap);
		void getValuesFromName(const std::string& valueName, std::vector<std::string>& valueVec);
		void getChildFromName(const std::string& valueName, std::vector<Config>& valueVec);
		static void substAlias(std::string& value);

		boost::property_tree::ptree child_;
		static AliasMap aliasMap_;
	};

}

#endif
