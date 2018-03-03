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

#include <openssl/aes.h>
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
		IV&		   iv,
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
			iv,
			encryptedTextBuf,
			encryptedTextLen
		);
	}

	OpcUaStatusCode
	CryptoAES::encryptCBC256(
	    char*      plainTextBuf,
	    uint32_t   plainTextLen,
	    AESKey&	   aesKey,
		IV&		   iv,
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
			iv,
			encryptedTextBuf,
			encryptedTextLen
		);
	}

	OpcUaStatusCode
	CryptoAES::encryptCBC(
	    char*      plainTextBuf,
	    uint32_t   plainTextLen,
		AESKey&	   aesKey,
		IV&		   iv,
	    char*      encryptedTextBuf,
	    int32_t*   encryptedTextLen
	)
	{
		// check plain text
		if ((plainTextLen % 16) != 0 || plainTextLen == 0) {
			if (isLogging_) {
				Log(Error, "encryptCBC error: plain text length invalid");
			}
			return BadInvalidArgument;
		}

		if (plainTextLen != *encryptedTextLen) {
			if (isLogging_) {
				Log(Error, "encryptCBC error: plain/encrypted text length invalid");
			}
			return BadInvalidArgument;
		}

		// create AES key
		AES_KEY key;
	    if(AES_set_encrypt_key((const unsigned char*)aesKey.memBuf(), aesKey.memLen()*8, &key) < 0) {
			if (isLogging_) {
				Log(Error, "encryptCBC error: AES_set_encrypt_key");
			}
	    	return BadUnexpectedError;
	    }


		return Success;
	}

#if 0


	    /* copy the IV because the AES_cbc_encrypt function overwrites it. */
	    pInitalVector = (OpcUa_Byte*)OpcUa_P_Memory_Alloc(a_key->Key.Length);
	    OpcUa_ReturnErrorIfAllocFailed(pInitalVector);
	    OpcUa_P_Memory_MemCpy(pInitalVector, a_key->Key.Length, a_pInitalVector, a_key->Key.Length);

	    /* encrypt data */
	    AES_cbc_encrypt(    a_pPlainText,
	                        a_pCipherText,
	                        *a_pCipherTextLen,
	                        &key,
	                        pInitalVector,
	                        AES_ENCRYPT);

	    OpcUa_ReturnErrorIfNull(a_pCipherText, OpcUa_Bad);

	    OpcUa_P_Memory_Free(pInitalVector);
	    pInitalVector = OpcUa_Null;

	OpcUa_ReturnStatusCode;
	OpcUa_BeginErrorHandling;

	    OpcUa_P_Memory_Free(pInitalVector);
	    pInitalVector = OpcUa_Null;
#endif

	OpcUaStatusCode
	CryptoAES::decryptCBC128(
		char*      encryptedTextBuf,
		uint32_t   encryptedTextLen,
		AESKey&	   aesKey,
		IV&		   iv,
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
			iv,
			plainTextBuf,
			plainTextLen
		);
	}

	OpcUaStatusCode
	CryptoAES::decryptCBC256(
		char*      encryptedTextBuf,
		uint32_t   encryptedTextLen,
		AESKey&	   aesKey,
		IV&		   iv,
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
			iv,
			plainTextBuf,
			plainTextLen
		);
	}

	OpcUaStatusCode
	CryptoAES::decryptCBC(
		char*      encryptedTextBuf,
		uint32_t   encryptedTextLen,
		AESKey&	   aesKey,
		IV&		   iv,
	    char*      plainTextBuf,
	    int32_t*   plainTextLen
	)
	{
		// FIXME: todo
		return Success;
	}

}
