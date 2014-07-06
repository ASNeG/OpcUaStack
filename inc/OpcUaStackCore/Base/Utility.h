#ifndef __OpcUaStackCore_Utility_h__
#define __OpcUaStackCore_Utility_h__

#include "boost/asio.hpp"
#include "OpcUaStackCore/Base/os.h"
#include <ostream>
#include <iostream>
#include <stdint.h>

namespace OpcUaStackCore
{
	DLLEXPORT void duplicate(std::iostream& ios1, std::iostream& ios2);
	DLLEXPORT uint32_t count(boost::asio::streambuf& sb);
	DLLEXPORT uint32_t count(std::iostream& ios);

	DLLEXPORT void dumpHex(std::streambuf& sb, std::ostream& os = std::cout);
	DLLEXPORT void dumpHex(std::iostream& ios, std::ostream& os = std::cout);
	DLLEXPORT void dumpHex(const char* buf, const uint32_t bufLen, std::ostream& os = std::cout);

	DLLEXPORT void hexStringToByteSequence(const std::string& hexString, uint8_t* byteSequence);
	DLLEXPORT void byteSequenceToHexString(const uint8_t* byteSequence, uint32_t byteSequenceLength, std::string& hexString);
}

#endif