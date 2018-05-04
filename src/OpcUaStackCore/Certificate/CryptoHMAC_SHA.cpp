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

#include <openssl/hmac.h>
#include "OpcUaStackCore/Certificate/CryptoHMAC_SHA.h"

namespace OpcUaStackCore
{

	CryptoHMAC_SHA::CryptoHMAC_SHA(void)
	: OpenSSLError()
	, isLogging_(false)
	{
	}

	CryptoHMAC_SHA::~CryptoHMAC_SHA(void)
	{
	}

	void
	CryptoHMAC_SHA::isLogging(bool isLogging)
	{
		isLogging_ = isLogging;
	}

	bool
	CryptoHMAC_SHA::isLogging(void)
	{
		return isLogging_;
	}

	OpcUaStatusCode
	CryptoHMAC_SHA::generate_HMAC_SHA1(
		char*       	plainTextBuf,	 	// [in]  plain text to sign
		uint32_t    	plainTextLen,  	 	// [in]  length of plain text to sign
		MemoryBuffer& 	key,		 		// [in]  key
	    char*       	signTextBuf,	 	// [out] sign text
	    uint32_t*   	signTextLen   	 	// [out] length of sign text
	)
	{
		if (key.memLen() < 1) {
			if (isLogging_) {
				Log(Error, "generate_HMAC_SHA1 - invalid key length");
			}
			return BadInvalidArgument;
		}
		if (plainTextLen < 1) {
			if (isLogging_) {
				Log(Error, "generate_HMAC_SHA1 - invalid plain text length");
			}
			return BadInvalidArgument;
		}

		unsigned int length = *signTextLen;
		HMAC(
		    EVP_sha1(),
			key.memBuf(), key.memLen(),
			(const unsigned char*)plainTextBuf, plainTextLen,
			(unsigned char*)signTextBuf, &length
		);

		if (length <= 0) {
			if (isLogging_) {
				Log(Error, "generate_HMAC_SHA1 - HMAC");
			}
			return BadUnexpectedError;
		}

		return Success;
	}

	OpcUaStatusCode
	CryptoHMAC_SHA::generate_HMAC_SHA1_160(
		char*       	plainTextBuf,	 	// [in]  plain text to sign
		uint32_t    	plainTextLen,  	 	// [in]  length of plain text to sign
		MemoryBuffer& 	key,		 		// [in]  key
	    char*       	signTextBuf,	 	// [out] sign text
	    uint32_t*   	signTextLen   	 	// [out] length of sign text
	)
	{
		if (key.memLen() < 1) {
			if (isLogging_) {
				Log(Error, "generate_HMAC_SHA1_160 - invalid key length");
			}
			return BadInvalidArgument;
		}
		if (plainTextLen < 1) {
			if (isLogging_) {
				Log(Error, "generate_HMAC_SHA1_160 - invalid plain text length");
			}
			return BadInvalidArgument;
		}

		unsigned int length = *signTextLen;
		HMAC(
		    EVP_sha1(),
			key.memBuf(), key.memLen(),
			(const unsigned char*)plainTextBuf, plainTextLen,
			(unsigned char*)signTextBuf, &length
		);

		if (length <= 0) {
			if (isLogging_) {
				Log(Error, "generate_HMAC_SHA1_160 - HMAC");
			}
			return BadUnexpectedError;
		}

		return Success;
	}

	OpcUaStatusCode
	CryptoHMAC_SHA::generate_HMAC_SHA2_224(
		char*       	plainTextBuf,	 	// [in]  plain text to sign
		uint32_t    	plainTextLen,  	 	// [in]  length of plain text to sign
		MemoryBuffer& 	key,		 		// [in]  key
	    char*       	signTextBuf,	 	// [out] sign text
	    uint32_t*   	signTextLen   	 	// [out] length of sign text
	)
	{
		if (key.memLen() < 1) {
			if (isLogging_) {
				Log(Error, "generate_HMAC_SHA2_224 - invalid key length");
			}
			return BadInvalidArgument;
		}
		if (plainTextLen < 1) {
			if (isLogging_) {
				Log(Error, "generate_HMAC_SHA2_224 - invalid plain text length");
			}
			return BadInvalidArgument;
		}

		unsigned int length = *signTextLen;
		HMAC(
		    EVP_sha224(),
			key.memBuf(), key.memLen(),
			(const unsigned char*)plainTextBuf, plainTextLen,
			(unsigned char*)signTextBuf, &length
		);

		if (length <= 0) {
			if (isLogging_) {
				Log(Error, "generate_HMAC_SHA2_224 - HMAC");
			}
			return BadUnexpectedError;
		}

		return Success;
	}

	OpcUaStatusCode
	CryptoHMAC_SHA::generate_HMAC_SHA2_256(
		char*       	plainTextBuf,	 	// [in]  plain text to sign
		uint32_t    	plainTextLen,  	 	// [in]  length of plain text to sign
		MemoryBuffer& 	key,		 		// [in]  key
	    char*       	signTextBuf,	 	// [out] sign text
	    uint32_t*   	signTextLen   	 	// [out] length of sign text
	)
	{
		if (key.memLen() < 1) {
			if (isLogging_) {
				Log(Error, "generate_HMAC_SHA2_256 - invalid key length");
			}
			return BadInvalidArgument;
		}
		if (plainTextLen < 1) {
			if (isLogging_) {
				Log(Error, "generate_HMAC_SHA2_256 - invalid plain text length");
			}
			return BadInvalidArgument;
		}

		unsigned int length = *signTextLen;
		HMAC(
		    EVP_sha256(),
			key.memBuf(), key.memLen(),
			(const unsigned char*)plainTextBuf, plainTextLen,
			(unsigned char*)signTextBuf, &length
		);

		if (length <= 0) {
			if (isLogging_) {
				Log(Error, "generate_HMAC_SHA2_256 - HMAC");
			}
			return BadUnexpectedError;
		}

		return Success;
	}

	OpcUaStatusCode
	CryptoHMAC_SHA::generate_HMAC_SHA2_384(
		char*       	plainTextBuf,	 	// [in]  plain text to sign
		uint32_t    	plainTextLen,  	 	// [in]  length of plain text to sign
		MemoryBuffer& 	key,		 		// [in]  key
	    char*       	signTextBuf,	 	// [out] sign text
	    uint32_t*   	signTextLen   	 	// [out] length of sign text
	)
	{
		if (key.memLen() < 1) {
			if (isLogging_) {
				Log(Error, "generate_HMAC_SHA2_384 - invalid key length");
			}
			return BadInvalidArgument;
		}
		if (plainTextLen < 1) {
			if (isLogging_) {
				Log(Error, "generate_HMAC_SHA2_384 - invalid plain text length");
			}
			return BadInvalidArgument;
		}

		unsigned int length = *signTextLen;
		HMAC(
		    EVP_sha384(),
			key.memBuf(), key.memLen(),
			(const unsigned char*)plainTextBuf, plainTextLen,
			(unsigned char*)signTextBuf, &length
		);

		if (length <= 0) {
			if (isLogging_) {
				Log(Error, "generate_HMAC_SHA2_384 - HMAC");
			}
			return BadUnexpectedError;
		}

		return Success;
	}

	OpcUaStatusCode
	CryptoHMAC_SHA::generate_HMAC_SHA2_512(
		char*       	plainTextBuf,	 	// [in]  plain text to sign
		uint32_t    	plainTextLen,  	 	// [in]  length of plain text to sign
		MemoryBuffer& 	key,		 		// [in]  key
	    char*       	signTextBuf,	 	// [out] sign text
	    uint32_t*   	signTextLen   	 	// [out] length of sign text
	)
	{
		if (key.memLen() < 1) {
			if (isLogging_) {
				Log(Error, "generate_HMAC_SHA2_512 - invalid key length");
			}
			return BadInvalidArgument;
		}
		if (plainTextLen < 1) {
			if (isLogging_) {
				Log(Error, "generate_HMAC_SHA2_512 - invalid plain text length");
			}
			return BadInvalidArgument;
		}

		unsigned int length = *signTextLen;
		HMAC(
		    EVP_sha512(),
			key.memBuf(), key.memLen(),
			(const unsigned char*)plainTextBuf, plainTextLen,
			(unsigned char*)signTextBuf, &length
		);

		if (length <= 0) {
			if (isLogging_) {
				Log(Error, "generate_HMAC_SHA2_512 - HMAC");
			}
			return BadUnexpectedError;
		}

		return Success;
	}

}
