/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#ifndef __OpcUaStackCore_Utility_h__
#define __OpcUaStackCore_Utility_h__

#include "OpcUaStackCore/Base/os.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/Base/MemoryBuffer.h"
#include <ostream>
#include <iostream>
#include <stdint.h>

namespace OpcUaStackCore
{
	DLLEXPORT void duplicate(std::iostream& ios1, std::iostream& ios2);
	DLLEXPORT uint32_t count(boost::asio::streambuf& sb);
	DLLEXPORT uint32_t count(std::iostream& ios);
	DLLEXPORT uint32_t count(std::istream& is);
	DLLEXPORT uint32_t count(std::ostream& os);
	DLLEXPORT void clear(std::iostream& ios);

	DLLEXPORT void dumpHex(std::istream& is, std::ostream& os = std::cout);
	DLLEXPORT void dumpHex(std::streambuf& sb, std::ostream& os = std::cout);
	DLLEXPORT void dumpHex(std::iostream& ios, std::ostream& os = std::cout);
	DLLEXPORT void dumpHex(MemoryBuffer& memoryBuffer, std::ostream& os = std::cout);
	DLLEXPORT void dumpHex(const char* buf, const uint32_t bufLen, std::ostream& os = std::cout);

	DLLEXPORT void hexStringToByteSequence(const std::string& hexString, uint8_t* byteSequence);
	DLLEXPORT void hexStringToStream(const std::string& hexString, std::iostream& ios);
	DLLEXPORT void byteSequenceToHexString(const uint8_t* byteSequence, uint32_t byteSequenceLength, std::string& hexString);
	DLLEXPORT void byteSequenceToHexString(const uint8_t* byteSequence, uint32_t byteSequenceLength, std::iostream& ios);

	DLLEXPORT bool compare(std::iostream& ios, const std::string& string, uint32_t& pos);
}

#endif
