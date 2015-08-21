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
		static bool encode(boost::property_tree::ptree& pt, const OpcUaBoolean& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaBoolean& value);
	};

#if 0
	typedef int8_t OpcUaSByte;
	typedef uint8_t OpcUaByte;
	typedef int16_t OpcUaInt16;
	typedef uint16_t OpcUaUInt16;
	typedef int32_t OpcUaInt32;
	typedef uint32_t OpcUaUInt32;
	typedef int64_t OpcUaInt64;
	typedef uint64_t OpcUaUInt64;
	typedef float OpcUaFloat;
	typedef double OpcUaDouble;
#endif

}

#endif
