/*
   Copyright 2018-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_MemoryBuffer_h__
#define __OpcUaStackCore_MemoryBuffer_h__

#include <boost/shared_ptr.hpp>
#include <boost/asio/streambuf.hpp>

#include <string>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaByteString.h"

namespace OpcUaStackCore
{

	class DLLEXPORT MemoryBuffer
	{
	  public:
		typedef boost::shared_ptr<MemoryBuffer> SPtr;

		MemoryBuffer(void);
		MemoryBuffer(const std::string& value);
		MemoryBuffer(const char* memBuf, uint32_t memLen);
		MemoryBuffer(const OpcUaByteString& byteString);
		MemoryBuffer(uint32_t memLen);
		MemoryBuffer(boost::asio::streambuf& sb);
		MemoryBuffer(boost::asio::streambuf& sb1, boost::asio::streambuf& sb2);
		MemoryBuffer(boost::asio::streambuf& sb1, boost::asio::streambuf& sb2, boost::asio::streambuf& sb3);
		~MemoryBuffer(void);

		bool operator ==(const MemoryBuffer &b) const;
		friend std::ostream& operator<<(std::ostream& os, const MemoryBuffer& memoryBuffer);

		void clear(void);
		void resize(uint32_t newMemLen);
		bool isNull(void);
		char* memBuf(void);
		int32_t memLen(void);
		bool get(boost::asio::streambuf& sb);

		void set(const std::string& value);
		void set(const char* value);
		void set(const char* memBuf, uint32_t memLen);
		void set(const OpcUaByteString& byteString);
		void set(MemoryBuffer& memoryBuffer);
		void set(boost::asio::streambuf& sb);
		void set(boost::asio::streambuf& sb1, boost::asio::streambuf& sb2);
		void set(boost::asio::streambuf& sb1, boost::asio::streambuf& sb2, boost::asio::streambuf& sb3);

		void swap(char* inMemBuf, int32_t inBufLen, char** outMemBuf = nullptr, int32_t*outMemLen = nullptr);
		void swap(MemoryBuffer& memoryBuffer);

		void toHexString(std::string& hexString);

	  private:
		char *memBuf_;
		int32_t memLen_;
	};

}

#endif
