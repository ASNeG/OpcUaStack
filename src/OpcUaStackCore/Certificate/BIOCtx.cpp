/*
   Copyright 2023 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   BIOCtxrmationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Certificate/BIOCtx.h"

namespace OpcUaStackCore
{

	BIOCtx::BIOCtx(void)
	{
		bio_ = BIO_new(BIO_s_mem());
	}

	BIOCtx::BIOCtx(MemoryBuffer& memoryBuffer)
	{
		bio_ = BIO_new_mem_buf((void*)memoryBuffer.memBuf(), memoryBuffer.memLen());
	}

	BIOCtx::~BIOCtx(void)
	{
		if (bio_ != nullptr) {
			BIO_free(bio_);
		}
	}

	bool
	BIOCtx::getMemoryBuffer(MemoryBuffer& memoryBuffer)
	{
		if (bio_ == nullptr) return false;

		// Create memory buffer from BIO context
	    char* data = nullptr;
	    uint32_t length = BIO_get_mem_data(bio_, &data);

		// Create certificate data buffer
		memoryBuffer.resize(length);
		if (memoryBuffer.memLen() <= 0) {
			Log(Error, "cannot write bio context to memory buffer, because create memory buffer error");
			return false;
		}
	    memcpy(memoryBuffer.memBuf(), data, memoryBuffer.memLen());

		return true;
	}

	bool
	BIOCtx::setMemoryBuffer(MemoryBuffer& memoryBuffer)
	{
		if (bio_ != nullptr) {
			BIO_free(bio_);
		}
		bio_ = BIO_new_mem_buf((void*)memoryBuffer.memBuf(), memoryBuffer.memLen());
		return true;
	}

	BIO*
	BIOCtx::bio(void)
	{
		return bio_;
	}

}
