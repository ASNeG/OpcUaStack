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

#include "OpcUaStackCore/Base/MemoryBuffer.h"

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
		if (memLen_ > 0) {
			memBuf_ = new char[memLen_];
		}
	}

	MemoryBuffer::MemoryBuffer(const char* memBuf, uint32_t memLen)
	: memBuf_(nullptr)
	, memLen_(-1)
	{
		memLen_ = memLen;
		if (memLen_ > 0) {
			memBuf_ = new char[memLen_];
		}
	}

	MemoryBuffer::~MemoryBuffer(void)
	{
		clear();
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
		if (memLen_ > 0) {
			memBuf_ = new char[memLen_];
		}
		memcpy(memBuf_, memBuf, memLen_);
	}

}
