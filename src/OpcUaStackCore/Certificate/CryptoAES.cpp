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

#include "OpcUaStackCore/Certificate/CryptoAES.h"

namespace OpcUaStackCore
{

	CryptoAES::CryptoAES(void)
	: OpenSSLError()
	,isLogging_(false)
	{
	}

	CryptoAES::~CryptoAES(void)
	{
	}

	void
	CryptoAES::isLogging(bool isLogging)
	{
		isLogging_ = isLogging;
	}

	bool
	CryptoAES::isLogging(void)
	{
		return isLogging_;
	}

	OpcUaStatusCode
	CryptoAES::encryptCBC128(
	    char*      plainTextBuf,
	    uint32_t   plainTextLen,
	    AESKey&	   aesKey,
	    char*      encryptedTextBuf,
	    int32_t*   encryptedTextLen
	)
	{
		if (aesKey.memLen() != 16) {
			if (isLogging_) {
				Log(Error, "encryptCBC128 error: key length invalid");
			}
			return BadInvalidArgument;
		}

		return encryptCBC(
			plainTextBuf,
			plainTextLen,
			aesKey,
			encryptedTextBuf,
			encryptedTextLen
		);
	}

	OpcUaStatusCode
	CryptoAES::encryptCBC256(
	    char*      plainTextBuf,
	    uint32_t   plainTextLen,
	    AESKey&	   aesKey,
	    char*      encryptedTextBuf,
	    int32_t*   encryptedTextLen
	)
	{
		if (aesKey.memLen() != 32) {
			if (isLogging_) {
				Log(Error, "encryptCBC256 error: key length invalid");
			}
			return BadInvalidArgument;
		}

		return encryptCBC(
			plainTextBuf,
			plainTextLen,
			aesKey,
			encryptedTextBuf,
			encryptedTextLen
		);
	}

	OpcUaStatusCode
	CryptoAES::encryptCBC(
	    char*      plainTextBuf,
	    uint32_t   plainTextLen,
		AESKey&	   aesKey,
	    char*      encryptedTextBuf,
	    int32_t*   encryptedTextLen
	)
	{
		// FIXME: todo
		return Success;
	}

	OpcUaStatusCode
	CryptoAES::decryptCBC128(
		char*      encryptedTextBuf,
		uint32_t   encryptedTextLen,
		AESKey&	   aesKey,
	    char*      plainTextBuf,
	    int32_t*   plainTextLen
	)
	{
		if (aesKey.memLen() != 16) {
			if (isLogging_) {
				Log(Error, "decryptCBC128 error: key length invalid");
			}
			return BadInvalidArgument;
		}

		return decryptCBC(
			encryptedTextBuf,
			encryptedTextLen,
			aesKey,
			plainTextBuf,
			plainTextLen
		);
	}

	OpcUaStatusCode
	CryptoAES::decryptCBC256(
		char*      encryptedTextBuf,
		uint32_t   encryptedTextLen,
		AESKey&	   aesKey,
	    char*      plainTextBuf,
	    int32_t*   plainTextLen
	)
	{
		if (aesKey.memLen() != 32) {
			if (isLogging_) {
				Log(Error, "decryptCBC256 error: key length invalid");
			}
			return BadInvalidArgument;
		}

		return decryptCBC(
			encryptedTextBuf,
			encryptedTextLen,
			aesKey,
			plainTextBuf,
			plainTextLen
		);
	}

	OpcUaStatusCode
	CryptoAES::decryptCBC(
		char*      encryptedTextBuf,
		uint32_t   encryptedTextLen,
		AESKey&	   aesKey,
	    char*      plainTextBuf,
	    int32_t*   plainTextLen
	)
	{
		// FIXME: todo
		return Success;
	}

}
