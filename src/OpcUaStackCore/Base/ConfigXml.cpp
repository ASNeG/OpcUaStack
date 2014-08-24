#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include "OpcUaStackCore/Base/ConfigXml.h"

namespace OpcUaStackCore
{

	ConfigXml::ConfigXml(void)
	{
	}

	ConfigXml::~ConfigXml(void)
	{
	}

	bool 
	ConfigXml::parse(const std::string& configFileName)
	{
		boost::property_tree::ptree ptree;

		boost::property_tree::read_xml(configFileName, ptree);



		return true;
	}

}