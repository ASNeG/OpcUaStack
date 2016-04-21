/*
   Copyright 2016 Kai Huebl (kai@huebl-sgh.de)

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

#include <cmath>
#include <openssl/evp.h>
#include <openssl/buffer.h>
#include "OpcUaStackCore/Base/Base64.h"

namespace OpcUaStackCore
{

	Base64::Base64(void)
	{
	}

	Base64::~Base64(void)
	{
	}

	bool
	Base64::encode(const char* asciiBuf, uint32_t asciiLen, char* base64Buf, uint32_t& base64Len)
	{
		BIO* b64, *bio;
		BUF_MEM *bptr;

		b64 = BIO_new(BIO_f_base64());
		BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);
		bio = BIO_new(BIO_s_mem());
		BIO_push(b64, bio);
		BIO_get_mem_ptr(b64, &bptr);

		// write directly to base64 buffer to avoid copy operation
		uint32_t length = round(4*ceil((double)asciiLen/3.0));
		if (length > base64Len) return false;
		base64Len = length;

		bptr->length = 0;
		bptr->max = length + 1;
		bptr->data = base64Buf;

		BIO_write(b64, asciiBuf, asciiLen);
		BIO_flush(b64);

		bptr->length = 0;
		bptr->max = 0;
		bptr->data = nullptr;

		BIO_free_all(b64);

		return true;
	}

	bool
	Base64::decode(void)
	{
		return true;
	}

}
