#ifndef __OpcUaStackCore_Config_h__
#define __OpcUaStackCore_Config_h_

#include <boost/property_tree/ptree.hpp>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT Config 
	{
	  public:
		Config(void);
		Config(boost::property_tree::ptree& child);
		~Config(void);

		void child(boost::property_tree::ptree& child);
		boost::property_tree::ptree& child(void);

		bool setValue(const std::string& path, const std::string& value);
		bool setChild(const std::string& path, Config& config);

		std::string get(void);
		boost::optional<std::string> getValue(const std::string& path);
		std::string getValue(const std::string& path, const std::string& defaultValue);
		boost::optional<Config> getChild(const std::string& path);

		bool exist(const std::string& path);
		bool erase(const std::string& path);

	  private:
		boost::property_tree::ptree child_;
	};

}

#endif