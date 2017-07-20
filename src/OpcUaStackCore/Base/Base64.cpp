/*
   Copyright 2016-2017 Kai Huebl (kai@huebl-sgh.de)

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

#include <iostream>
#include <cstring>
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

	uint32_t
	Base64::asciiLen2base64Len(uint32_t asciiLen)
	{
		uint32_t rest = asciiLen % 3;
		if (rest != 0) {
			asciiLen += (3 - rest);
		}
		return (4*ceil((double)asciiLen/3.0));
	}

	uint32_t
	Base64::base64Len2asciiLen(uint32_t base64Len)
	{
		return ((6 * base64Len) / 8);
	}

	bool
	Base64::encode(const char* asciiBuf, uint32_t asciiLen, char* base64Buf, uint32_t& base64Len)
	{
		BIO *bio, *b64;
		BUF_MEM *bufferPtr;

		uint32_t length = asciiLen2base64Len(asciiLen);
		if (length > base64Len) return false;
		base64Len = length;

		b64 = BIO_new(BIO_f_base64());
		bio = BIO_new(BIO_s_mem());
		bio = BIO_push(b64, bio);

		BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL); //Ignore newlines - write everything in one line
		BIO_write(bio, asciiBuf, asciiLen);
		BIO_flush(bio);
		BIO_get_mem_ptr(bio, &bufferPtr);
		BIO_set_close(bio, BIO_NOCLOSE);
		BIO_free_all(bio);

		memcpy(base64Buf, bufferPtr->data, base64Len);
		return true;
	}

	bool
	Base64::decode(const char* base64Buf, uint32_t base64Len, char* asciiBuf, uint32_t& asciiLen)
	{
		uint32_t length = base64Len2asciiLen(base64Len);
		if (length > asciiLen) return false;

		BIO *b64, *bio;
		b64 = BIO_new(BIO_f_base64());
		BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);
		bio = BIO_new_mem_buf((char*)base64Buf, base64Len);
		bio = BIO_push(b64, bio);

		length = BIO_read(bio, asciiBuf, length);
		asciiLen = length;

		BIO_free_all(b64);

		return true;
	}

}
