#ifndef __OpcUaStackServer_NodeSetValueParser_h__
#define __OpcUaStackServer_NodeSetValueParser_h__

#include <boost/property_tree/ptree.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaDataValue.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT NodeSetValueParser
	{
	  public:
		NodeSetValueParser(void);
		~NodeSetValueParser(void);

		bool parseValue(boost::property_tree::ptree& ptree, OpcUaDataValue& dataValue);
	};

}

#endif