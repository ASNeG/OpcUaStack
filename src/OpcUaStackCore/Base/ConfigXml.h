#ifndef __OpcUaStackCore_ConfigXml_h__
#define __OpcUaStackCore_ConfigXml_h__

#include <boost/property_tree/ptree.hpp>
#include "OpcUaStackCore/Base/os.h"
#include <string>

namespace OpcUaStackCore
{

	class DLLEXPORT ConfigXml
	{
	  public:
		ConfigXml(void);
		~ConfigXml(void);

		bool write(const std::string& configFileName);
		bool read(const std::string& configFileName);
		bool parse(const std::string& configFileName, bool writeToConfig = false);
		std::string errorMessage(void);
		boost::property_tree::ptree& ptree(void);
		void ptree(boost::property_tree::ptree& ptree);
		void writeToConfig(void);

	  private:
		std::string configFileName_;
		boost::property_tree::ptree ptree_;
		std::string errorMessage_;
	};

}

#endif
