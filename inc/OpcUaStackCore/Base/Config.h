#ifndef __OpcUaStackCore_Config_h__
#define __OpcUaStackCore_Config_h__

#include <boost/property_tree/ptree.hpp>
#include <boost/lexical_cast.hpp>
#include <vector>
#include <map>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT Config 
	{
	  public:
		typedef std::map<std::string, std::string> AliasMap;

		static Config* instance_;
		static Config* instance(void);
		static void destroy(void);

		Config(void);
		Config(boost::property_tree::ptree& child);
		~Config(void);

		void child(boost::property_tree::ptree& child);
		boost::property_tree::ptree& child(void);

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

	  private:
		void getValuesFromName(const std::string& valueName, std::vector<std::string>& valueVec);
		void getChildFromName(const std::string& valueName, std::vector<Config>& valueVec);
		static void substAlias(std::string& value);

		boost::property_tree::ptree child_;
		static AliasMap aliasMap_;
	};

}

#endif
