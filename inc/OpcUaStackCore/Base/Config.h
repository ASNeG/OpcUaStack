#ifndef __OpcUaStackCore_Config_h__
#define __OpcUaStackCore_Config_h__

#include <boost/property_tree/ptree.hpp>
#include <boost/lexical_cast.hpp>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT Config 
	{
	  public:
		static Config* instance_;
		static Config* instance(void);

		Config(void);
		Config(boost::property_tree::ptree& child);
		~Config(void);

		void child(boost::property_tree::ptree& child);
		boost::property_tree::ptree& child(void);

		bool setValue(const std::string& path, const std::string& value);
		bool setChild(const std::string& path, Config& config);

		std::string getValue(void);
		boost::optional<std::string> getValue(const std::string& path);
		std::string getValue(const std::string& path, const std::string& defaultValue);
		boost::optional<Config> getChild(const std::string& path);

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

	  private:
		boost::property_tree::ptree child_;
	};

}

#endif