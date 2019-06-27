/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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

#include <string.h>
#include <iostream>
#include "OpcUaStackCore/Base/MemoryBuffer.h"
#include "OpcUaStackCore/Base/Utility.h"

namespace OpcUaStackCore
{

	MemoryBuffer::MemoryBuffer(void)
	: memBuf_(nullptr)
	, memLen_(-1)
	{
	}

	MemoryBuffer::MemoryBuffer(const std::string& value)
	: memBuf_(nullptr)
	, memLen_(-1)
	{
		memLen_ = value.length();
		if (memLen_ <= 0) return;
		memBuf_ = new char[memLen_];
		memcpy(memBuf_, value.c_str(), memLen_);
	}

	MemoryBuffer::MemoryBuffer(const char* memBuf, uint32_t memLen)
	: memBuf_(nullptr)
	, memLen_(-1)
	{
		memLen_ = memLen;
		if (memLen_ <= 0) return;
		memBuf_ = new char[memLen_];
		memcpy(memBuf_, memBuf, memLen_);
	}

	MemoryBuffer::MemoryBuffer(const OpcUaByteString& byteString)
	: memBuf_(nullptr)
	, memLen_(-1)
	{
		memLen_ = byteString.size();
		if (memLen_ <= 0) return;
		memBuf_ = new char[memLen_];
		memcpy(memBuf_, const_cast<OpcUaByteString*>(&byteString)->memBuf(), memLen_);
	}

	MemoryBuffer::MemoryBuffer(uint32_t memLen)
	: memBuf_(nullptr)
	, memLen_(-1)
	{
		memLen_ = memLen;
		if (memLen_ <= 0) return;
		memBuf_ = new char[memLen_];
		memset(memBuf_, 0x00, memLen_);
	}

	MemoryBuffer::MemoryBuffer(boost::asio::streambuf& sb)
	: memBuf_(nullptr)
	, memLen_(-1)
	{
		memLen_ = sb.size();
		if (memLen_ <= 0) return;
		memBuf_ = new char[memLen_];
		std::iostream ios(&sb);
		ios.read(memBuf_, memLen_);
	}

	MemoryBuffer::MemoryBuffer(boost::asio::streambuf& sb1, boost::asio::streambuf& sb2)
	: memBuf_(nullptr)
	, memLen_(-1)
	{
		uint32_t size1 = sb1.size();
		uint32_t size2 = sb2.size();
		uint32_t size = size1 + size2;

		memLen_ = size;
		if (memLen_ <= 0) return;
		memBuf_ = new char[memLen_];

		std::iostream ios1(&sb1);
		std::iostream ios2(&sb2);

		ios1.read(memBuf_, size1);
		ios2.read(memBuf_ + size1, size2);
	}

	MemoryBuffer::MemoryBuffer(boost::asio::streambuf& sb1, boost::asio::streambuf& sb2, boost::asio::streambuf& sb3)
	: memBuf_(nullptr)
	, memLen_(-1)
	{
		uint32_t size1 = sb1.size();
		uint32_t size2 = sb2.size();
		uint32_t size3 = sb3.size();
		uint32_t size = size1 + size2 + size3;

		memLen_ = size;
		if (memLen_ <= 0) return;
		memBuf_ = new char[memLen_];

		std::iostream ios1(&sb1);
		std::iostream ios2(&sb2);
		std::iostream ios3(&sb3);

		ios1.read(memBuf_, size1);
		ios2.read(memBuf_ + size1, size2);
		ios3.read(memBuf_ + size1 + size2, size3);
	}

	MemoryBuffer::~MemoryBuffer(void)
	{
		clear();
	}

	bool
	MemoryBuffer::operator ==(const MemoryBuffer &b) const
	{
		if (memLen_ != b.memLen_) return false;
		if (memLen_ < 1) return true;
		return (memcmp(memBuf_, b.memBuf_, memLen_) == 0);
	}

	std::ostream&
	operator<<(std::ostream& os, const MemoryBuffer& memoryBuffer)
	{
		MemoryBuffer* mb = const_cast<MemoryBuffer*>(&memoryBuffer);
		if (mb->memLen() == -1) {
			os << "null";
		}
		else if (mb->memLen() == 0) {
			os << "[]";
		}
		else {
			os << mb->memLen() << "[";
			for (uint32_t idx=0; idx<mb->memLen(); idx++) {
				char c = mb->memBuf()[idx];
				if(!isprint(c)) {
					c = '.';
				}
				os << c;
			}
			os << "]";
		}
		return os;
	}

	void
	MemoryBuffer::clear(void)
	{
		memLen_ = -1;
		if (memBuf_ != nullptr) {
			delete [] memBuf_;
			memBuf_ = nullptr;
		}
	}

	void
	MemoryBuffer::resize(uint32_t newMemLen)
	{
		// save current buffer
		char* memBuf = memBuf_;
		int32_t memLen = memLen_;
		memBuf_ = nullptr;
		memLen_ = -1;

		// allocate new memory
		memLen_ = newMemLen;
		if (memLen_ <= 0) return;
		memBuf_ = new char[memLen_];
		memset(memBuf_, 0x00, memLen_);

		// copy old memory to new memory
		if (memBuf == nullptr) {
			return;
		}

		if (memLen > memLen_) memLen = memLen_;
		memcpy(memBuf_, memBuf, memLen);

		// delete old memory
		delete [] memBuf;
	}

	bool
	MemoryBuffer::isNull(void)
	{
		return memLen_ == -1;
	}

	char*
	MemoryBuffer::memBuf(void)
	{
		return memBuf_;
	}

	int32_t
	MemoryBuffer::memLen(void)
	{
		return memLen_;
	}

	bool
	MemoryBuffer::get(boost::asio::streambuf& sb)
	{
		if (memLen_ <= 0) {
			return false;
		}

		std::iostream ios(&sb);
		ios.write(memBuf_, memLen_);

		return true;
	}

	void
	MemoryBuffer::set(const std::string& value)
	{
		set(value.c_str(), value.length());
	}

	void
	MemoryBuffer::set(const char* value)
	{
		set(value, strlen(value));
	}

	void
	MemoryBuffer::set(const char* memBuf, uint32_t memLen)
	{
		clear();

		memLen_ = memLen;
		if (memLen_ <= 0) return;
		memBuf_ = new char[memLen_];
		memcpy(memBuf_, memBuf, memLen_);
	}

	void
	MemoryBuffer::set(const OpcUaByteString& byteString)
	{
		clear();

		memLen_ = byteString.size();
		if (memLen_ <= 0) return;
		memBuf_ = new char[memLen_];
		memcpy(memBuf_, const_cast<OpcUaByteString*>(&byteString)->memBuf(), memLen_);
	}

	void
	MemoryBuffer::set(MemoryBuffer& memoryBuffer)
	{
		set(memoryBuffer.memBuf(), memoryBuffer.memLen());
	}

	void
	MemoryBuffer::set(boost::asio::streambuf& sb)
	{
		clear();

		uint32_t size = sb.size();

		memLen_ = size;
		if (memLen_ <= 0) return;
		memBuf_ = new char[memLen_];

		std::iostream ios(&sb);
		ios.read(memBuf_, size);
	}

	void
	MemoryBuffer::set(boost::asio::streambuf& sb1, boost::asio::streambuf& sb2)
	{
		clear();

		uint32_t size1 = sb1.size();
		uint32_t size2 = sb2.size();
		uint32_t size = size1 + size2;

		memLen_ = size;
		if (memLen_ <= 0) return;
		memBuf_ = new char[memLen_];

		std::iostream ios1(&sb1);
		std::iostream ios2(&sb2);

		ios1.read(memBuf_, size1);
		ios2.read(memBuf_ + size1, size2);
	}

	void
	MemoryBuffer::set(boost::asio::streambuf& sb1, boost::asio::streambuf& sb2, boost::asio::streambuf& sb3)
	{
		clear();

		uint32_t size1 = sb1.size();
		uint32_t size2 = sb2.size();
		uint32_t size3 = sb3.size();
		uint32_t size = size1 + size2 + size3;

		memLen_ = size;
		if (memLen_ <= 0) return;
		memBuf_ = new char[memLen_];

		std::iostream ios1(&sb1);
		std::iostream ios2(&sb2);
		std::iostream ios3(&sb3);

		ios1.read(memBuf_, size1);
		ios2.read(memBuf_ + size1, size2);
		ios2.read(memBuf_ + size1 + size2, size3);
	}

	void
	MemoryBuffer::swap(char* memBuf, int32_t memLen, char** outMemBuf, int32_t* outMemLen)
	{
		if (outMemBuf != nullptr) *outMemBuf = memBuf_;
		if (outMemLen != nullptr) *outMemLen = memLen_;

		memBuf_ = memBuf;
		memLen_ = memLen;
	}

	void
	MemoryBuffer::swap(MemoryBuffer& memoryBuffer)
	{
		char* memBuf = memBuf_;
		uint32_t memLen = memLen_;

		memBuf_ = memoryBuffer.memBuf();
		memLen_ = memoryBuffer.memLen();

		memoryBuffer.swap(memBuf, memLen);
	}

	void
	MemoryBuffer::toHexString(std::string& hexString)
	{
		hexString = "";
		if (memLen_ <= 0) {
			return;
		}

		byteSequenceToHexString((uint8_t*)memBuf_, memLen_, hexString);
	}

}
