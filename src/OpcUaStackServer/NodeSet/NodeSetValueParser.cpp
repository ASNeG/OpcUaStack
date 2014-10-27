#include "OpcUaStackServer/NodeSet/NodeSetValueParser.h"

namespace OpcUaStackServer
{

	NodeSetValueParser::NodeSetValueParser(void)
	{
	}

	NodeSetValueParser::~NodeSetValueParser(void)
	{
	}

	bool 
	NodeSetValueParser::parseValue(boost::property_tree::ptree& ptree, OpcUaDataValue& dataValue)
	{
		return false;
	}

}

#if 0
	<Value>
      <uax:UInt32>123</uax:UInt32>
    </Value>
#endif