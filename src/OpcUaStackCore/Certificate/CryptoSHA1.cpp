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

#include <openssl/sha.h>
#include "OpcUaStackCore/Certificate/CryptoSHA1.h"

namespace OpcUaStackCore
{

	CryptoSHA1::CryptoSHA1(void)
	: OpenSSLError()
	, isLogging_(false)
	{
	}

	CryptoSHA1::~CryptoSHA1(void)
	{
	}

	void
	CryptoSHA1::isLogging(bool isLogging)
	{
		isLogging_ = isLogging;
	}

	bool
	CryptoSHA1::isLogging(void)
	{
		return isLogging_;
	}

	OpcUaStatusCode
	CryptoSHA1::sha1(
	    char*      plainTextBuf,
	    uint32_t   plainTextLen,
	    char*      digestTextBuf,
	    uint32_t   digestTextLen
	)
	{
		// check parameter
		if (plainTextBuf == nullptr || plainTextLen == 0) {
			if (isLogging_) {
				Log(Error, "sha1: plain text invalid");
			}
			return BadInvalidArgument;
		}

		if (digestTextBuf == nullptr || digestTextLen != 20) {
			if (isLogging_) {
				Log(Error, "sha1: digest text invalid");
			}
			return BadInvalidArgument;
		}

		if (SHA1((const unsigned char*)plainTextBuf, (unsigned long int)plainTextLen, (unsigned char *)digestTextBuf) == nullptr) {
			if (isLogging_) {
				Log(Error, "sha1: SHA1");
			}
			return BadUnexpectedError;
		}

		return Success;
	}

	OpcUaStatusCode
	CryptoSHA1::sha160(
		char*      plainTextBuf,
		uint32_t   plainTextLen,
		char*      digestTextBuf,
		uint32_t   digestTextLen
	)
	{
		return sha1(plainTextBuf, plainTextLen, digestTextBuf, digestTextLen);
	}

	OpcUaStatusCode
	CryptoSHA1::sha224(
	    char*      plainTextBuf,
	    uint32_t   plainTextLen,
	    char*      digestTextBuf,
	    uint32_t   digestTextLen
	)
	{
		// check parameter
		if (plainTextBuf == nullptr || plainTextLen == 0) {
			if (isLogging_) {
				Log(Error, "sha1: plain text invalid");
			}
			return BadInvalidArgument;
		}

		if (digestTextBuf == nullptr || digestTextLen != 28) {
			if (isLogging_) {
				Log(Error, "sha1: digest text invalid");
			}
			return BadInvalidArgument;
		}

		if (SHA224((const unsigned char*)plainTextBuf, (unsigned long int)plainTextLen, (unsigned char *)digestTextBuf) == nullptr) {
			if (isLogging_) {
				Log(Error, "sha1: SHA224");
			}
			return BadUnexpectedError;
		}

		return Success;
	}

	OpcUaStatusCode
	CryptoSHA1::sha256(
	    char*      plainTextBuf,
	    uint32_t   plainTextLen,
	    char*      digestTextBuf,
	    uint32_t   digestTextLen
	)
	{
		// check parameter
		if (plainTextBuf == nullptr || plainTextLen == 0) {
			if (isLogging_) {
				Log(Error, "sha1: plain text invalid");
			}
			return BadInvalidArgument;
		}

		if (digestTextBuf == nullptr || digestTextLen != 32) {
			if (isLogging_) {
				Log(Error, "sha1: digest text invalid");
			}
			return BadInvalidArgument;
		}

		if (SHA256((const unsigned char*)plainTextBuf, (unsigned long int)plainTextLen, (unsigned char *)digestTextBuf) == nullptr) {
			if (isLogging_) {
				Log(Error, "sha1: SHA256");
			}
			return BadUnexpectedError;
		}

		return Success;
	}

	OpcUaStatusCode
	CryptoSHA1::sha384(
	    char*      plainTextBuf,
	    uint32_t   plainTextLen,
	    char*      digestTextBuf,
	    uint32_t   digestTextLen
	)
	{
		// check parameter
		if (plainTextBuf == nullptr || plainTextLen == 0) {
			if (isLogging_) {
				Log(Error, "sha1: plain text invalid");
			}
			return BadInvalidArgument;
		}

		if (digestTextBuf == nullptr || digestTextLen != 48) {
			if (isLogging_) {
				Log(Error, "sha1: digest text invalid");
			}
			return BadInvalidArgument;
		}

		if (SHA384((const unsigned char*)plainTextBuf, (unsigned long int)plainTextLen, (unsigned char *)digestTextBuf) == nullptr) {
			if (isLogging_) {
				Log(Error, "sha1: SHA384");
			}
			return BadUnexpectedError;
		}

		return Success;
	}

	OpcUaStatusCode
	CryptoSHA1::sha512(
	    char*      plainTextBuf,
	    uint32_t   plainTextLen,
	    char*      digestTextBuf,
	    uint32_t   digestTextLen
	)
	{
		// check parameter
		if (plainTextBuf == nullptr || plainTextLen == 0) {
			if (isLogging_) {
				Log(Error, "sha1: plain text invalid");
			}
			return BadInvalidArgument;
		}

		if (digestTextBuf == nullptr || digestTextLen != 64) {
			if (isLogging_) {
				Log(Error, "sha1: digest text invalid");
			}
			return BadInvalidArgument;
		}

		if (SHA512((const unsigned char*)plainTextBuf, (unsigned long int)plainTextLen, (unsigned char *)digestTextBuf) == nullptr) {
			if (isLogging_) {
				Log(Error, "sha1: SHA512");
			}
			return BadUnexpectedError;
		}

		return Success;
	}

}
