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
		~Config(void);

		bool set(const std::string& path, const std::string& value);
		boost::optional<std::string> get(const std::string& path);
		std::string get(const std::string& path, const std::string& defaultValue);

	  private:
		boost::property_tree::ptree cfg_;
	};

}

#endif