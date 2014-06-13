#ifndef __OpcUaStackCore_OpcUaNumber_h__
#define __OpcUaStackCore_OpcUaNumber_h__

#include "OpcUaStackCore/Base/os.h"
#include <iostream>
#include <stdint.h>

namespace OpcUaStackCore
{
	typedef bool OpcUaBoolean;
	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const OpcUaBoolean& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, OpcUaBoolean& value);


	typedef int8_t OpcUaSByte;
	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const OpcUaSByte& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, OpcUaSByte& value);


	typedef uint8_t OpcUaByte;
	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const OpcUaByte& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, OpcUaByte& value);


	typedef int16_t OpcUaInt16;
	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const OpcUaInt16& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, OpcUaInt16& value);


	typedef uint16_t OpcUaUInt16;
	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const OpcUaUInt16& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, OpcUaUInt16& value);


	typedef int32_t OpcUaInt32;
	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const OpcUaInt32& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, OpcUaInt32& value);


	typedef uint32_t OpcUaUInt32;
	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const OpcUaUInt32& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, OpcUaUInt32& value);


	typedef int64_t OpcUaInt64;
	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const OpcUaInt64& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, OpcUaInt64& value);


	typedef uint64_t OpcUaUInt64;
	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const OpcUaUInt64& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, OpcUaUInt64& value);


	typedef float OpcUaFloat;
	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const OpcUaFloat& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, OpcUaFloat& value);


	typedef double OpcUaDouble;
	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const OpcUaDouble& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, OpcUaDouble& value);
};

#endif