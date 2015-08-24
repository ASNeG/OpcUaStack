#ifndef __OpcUaStackCore_Json_h__
#define __OpcUaStackCore_Json_h__

#include <boost/property_tree/ptree.hpp>
#include <stdint.h>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumberTypes.h"

namespace OpcUaStackCore
{

	class DLLEXPORT Json
	{
	  public:
		static bool toDocumentString(boost::property_tree::ptree& pt, std::string& string);
		static bool toString(boost::property_tree::ptree& pt, std::string& string);
		static bool fromString(const std::string& string, boost::property_tree::ptree& pt);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaBoolean& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaBoolean& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaSByte& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaSByte& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaByte& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaByte& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaInt16& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaInt16& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaUInt16& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaUInt16& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaInt32& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaInt32& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaUInt32& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaUInt32& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaInt64& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaInt64& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaUInt64& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaUInt64& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaFloat& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaFloat& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaDouble& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaDouble& value);
	};

}

#endif
