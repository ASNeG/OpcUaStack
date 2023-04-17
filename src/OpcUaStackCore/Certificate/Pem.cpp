/*
   Copyright 2023 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Pemrmationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (atimin@gmail.com)
 */

#include <openssl/bio.h>
#include <openssl/pem.h>

#include "OpcUaStackCore/Certificate/Pem.h"

namespace OpcUaStackCore
{

	Pem::Pem(void)
	: OpenSSLError()
	{
	}

	Pem::~Pem(void)
	{
	}

	bool
	Pem::toText(
		MemoryBuffer& memoryBuffer,
		std::string& str,
		const std::string& textName
	)
	{
		BIO *bio = BIO_new(BIO_s_mem());

		int result = PEM_write_bio(bio, textName.c_str(), "", (const unsigned char*)memoryBuffer.memBuf(), memoryBuffer.memLen());
	    if (result == 0) {
	        addOpenSSLError();
	        addError("call PEM_write_bio error");
	        return false;
	    }

		BIO_set_close(bio, BIO_CLOSE);

	    char* data = nullptr;
	    uint32_t length = BIO_get_mem_data(bio, &data);

	    str = std::string(data, length);

		return true;
	}

	bool
	Pem::toBIO(
		MemoryBuffer& memoryBuffer,
		BIOCtx& bioCtx,
		const std::string& textName
	)
	{
		int result = PEM_write_bio(bioCtx.bio(), textName.c_str(), "", (const unsigned char*)memoryBuffer.memBuf(), memoryBuffer.memLen());
	    if (result == 0) {
	        addOpenSSLError();
	        addError("call PEM_write_bio error");
	        return false;
	    }

		return true;
	}

	bool
	Pem::fromText(
		std::string& str,
		MemoryBuffer& memoryBuffer,
		std::string& textName
	)
	{
		BIO* bio = BIO_new_mem_buf((void*)str.c_str(), str.size());

		char* name = nullptr;
		char* header = nullptr;
		unsigned char* data = nullptr;
		long len;
		int result = PEM_read_bio(bio, &name, &header, &data, &len);
	    if (result == 0) {
	        addOpenSSLError();
	        addError("call PEM_read_bio error");
	        return false;
	    }
	    textName = name;


		BIO_set_close(bio, BIO_CLOSE);

		memoryBuffer.resize(len);
		memoryBuffer.set((const char*)data, len);

		return true;
	}

	bool
	Pem::fromBIO(
		BIOCtx bioCtx,
		MemoryBuffer& memoryBuffer,
		std::string& textName
	)
	{
		char* name = nullptr;
		char* header = nullptr;
		unsigned char* data = nullptr;
		long len;
		int result = PEM_read_bio(bioCtx.bio(), &name, &header, &data, &len);
	    if (result == 0) {
	        addOpenSSLError();
	        addError("call PEM_read_bio error");
	        return false;
	    }
	    textName = name;

		memoryBuffer.resize(len);
		memoryBuffer.set((const char*)data, len);

		return true;
	}

}
