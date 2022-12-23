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

#include <openssl/rsa.h>
#include "OpcUaStackCore/Certificate/CryptoRSA.h"
#include "OpcUaStackCore/Certificate/OpenSSLCompat.h"

namespace OpcUaStackCore
{

	CryptoRSA::CryptoRSA(void)
	: OpenSSLError()
	, isLogging_(false)
	{
	}

	CryptoRSA::~CryptoRSA(void)
	{
	}

	void
	CryptoRSA::isLogging(bool isLogging)
	{
		isLogging_ = isLogging;
	}

	bool
	CryptoRSA::isLogging(void)
	{
		return isLogging_;
	}

	OpcUaStatusCode
	CryptoRSA::publicEncrypt(
	    char*      plainTextBuf,
	    uint32_t   plainTextLen,
	    PublicKey* publicKey,
	    int16_t    padding,
	    char*      encryptedTextBuf,
	    uint32_t*  encryptedTextLen
	)
	{
		assert(plainTextBuf != nullptr);
		assert(plainTextLen > 0);
		assert(publicKey != nullptr);
		assert(encryptedTextBuf != nullptr);
		assert(encryptedTextLen != nullptr);
		assert(*encryptedTextLen > 0);

		// check public key
		if (publicKey->keyType() != KeyType_RSA) {
			if (isLogging_) {
				Log(Error, "publicEntrypt error - invalid public key type");
			}
			return BadInvalidArgument;
		}

	    // calculate encrypted block size
		uint32_t keyBlockSize = publicKey->keySizeInBytes();
		uint32_t encryptedBlockSize  = 0;
	    switch(padding)
	    {
	    	case RSA_PKCS1_PADDING:
	        {
	        	encryptedBlockSize = keyBlockSize - 11;
	            break;
	        }
	    	case RSA_PKCS1_OAEP_PADDING:
	        {
	        	encryptedBlockSize = keyBlockSize - 42;
	            break;
	        }
	    	case RSA_NO_PADDING:
	        {
	        	encryptedBlockSize = keyBlockSize;
	            break;
	        }
	    	default:
	        {
				if (isLogging_) {
					Log(Error, "publicEntrypt error - invalid padding type");
				}
	            return BadNotSupported;
	        }
	    }

	    // ceck length of encryption buffer
	    // FIXME: todo

		// get key information
		EVP_PKEY* key = *publicKey;
		if (key == nullptr) {
			if (isLogging_) {
				Log(Error, "publicEntrypt error - key is empty");
			}
			return BadUnexpectedError;
		}
		if (EVP_PKEY_get0_RSA(key) == nullptr) {
			if (isLogging_) {
				Log(Error, "publicEntrypt error - invalid rsa key type");
			}
			return BadUnexpectedError;
		}

	    // check bytes to encrypt in one step
	    uint32_t bytesToEncrypt = 0;
	    if(plainTextLen < encryptedBlockSize) {
	    	bytesToEncrypt = plainTextLen;
	    }
	    else {
	    	bytesToEncrypt = encryptedBlockSize;
	    }

	    // encrypt
	    *encryptedTextLen = 0;
	    uint32_t plainTextPosition = 0;
	    uint32_t encryptedTextPosition = 0;
	    while(plainTextPosition < plainTextLen) {

	    	// the last part could be smaller
	    	if((plainTextLen >= encryptedBlockSize) && ((plainTextLen - plainTextPosition) < encryptedBlockSize)) {
	            bytesToEncrypt = plainTextLen - plainTextPosition;
	        }

	    	// encrypt buffer
	    	int32_t encryptedBytes = 0;
	    	encryptedBytes = RSA_public_encrypt(
	    		bytesToEncrypt,      	   										// number bytes to encrypt
	    		(const unsigned char*)(plainTextBuf + plainTextPosition),       // buffer to encrypt
	    		(unsigned char*)(encryptedTextBuf + encryptedTextPosition),  	// where to encrypt
				(RSA*)EVP_PKEY_get0_RSA(key),                              			// public key
	    		padding															// padding mode
			);
	    	if(encryptedBytes < 0) {
	    		addOpenSSLError();

	    		if (isLogging_) {
	    			log(Error, "publicEntrypt error - RSA_public_encrypt");
	    		}
	    		return BadUnexpectedError;
	    	}

	    	*encryptedTextLen = *encryptedTextLen + encryptedBytes;
	    	encryptedTextPosition += encryptedBytes;
	    	plainTextPosition  += bytesToEncrypt;
	    }

		return Success;
	}

	OpcUaStatusCode
	CryptoRSA::privateDecrypt(
		char*       encryptedTextBuf,
		uint32_t    encryptedTextLen,
		PrivateKey* privateKey,
		int16_t     padding,
	    char*       plainTextBuf,
	    uint32_t*   plainTextLen
	)
	{
		*plainTextLen = 0;

		// check public key
		if (privateKey->keyType() != KeyType_RSA) {
			if (isLogging_) {
				Log(Error, "privateDecrypt error - invalid private key type");
			}
			return BadInvalidArgument;
		}

		// get private key
		EVP_PKEY* key = *privateKey;
	    if (key == nullptr) {
			if (isLogging_) {
				Log(Error, "privateDecrypt error - key empty");
			}
	        return BadUnexpectedError;
	    }
		if (EVP_PKEY_get0_RSA(key) == nullptr) {
			if (isLogging_) {
				Log(Error, "privateDecrypt error - private rsa key empty");
			}
			return BadUnexpectedError;
		}

		// get key information
		uint32_t keySize = RSA_size(EVP_PKEY_get0_RSA(key));

		// check encrypted text
		if ((encryptedTextLen == 0) || (encryptedTextLen%keySize != 0)) {
			if (isLogging_) {
				Log(Error, "privateDecrypt error - encrypted text length");
			}
			return BadInvalidArgument;
		}

		// check padding type
		uint32_t decryptedDataSize = 0;
	    switch(padding)
	    {
	    	case RSA_PKCS1_PADDING:
	        {
	        	decryptedDataSize = keySize - 11;
	            break;
	        }
	    	case RSA_PKCS1_OAEP_PADDING:
	        {
	        	decryptedDataSize = keySize - 42;
	            break;
	        }
	    	case RSA_NO_PADDING:
	        {
	        	decryptedDataSize = keySize;
	            break;
	        }
	    	default:
	        {
				if (isLogging_) {
					Log(Error, "privateDecrypt error - invalid padding");
				}
	            return BadNotSupported;
	        }
	    }

	    uint32_t decryptedBytes = 0;
		uint32_t encryptedTextPosition = 0;
		while (encryptedTextPosition < encryptedTextLen) {

			if (plainTextBuf != nullptr) {
				decryptedBytes = RSA_private_decrypt(
					keySize,                            							// how much to decrypt
					(unsigned char*)encryptedTextBuf + encryptedTextPosition,   	// what to decrypt
					(unsigned char*)plainTextBuf + (*plainTextLen),  				// where to decrypt
					(RSA*)EVP_PKEY_get0_RSA(key),                  								// private key
					padding															// padding mode
				);
				if(decryptedBytes == -1) {
					addOpenSSLError();

					if (isLogging_) {
						log(Error, "privateDecrypt error - RSA_private_decrypt");
					}
					return BadUnexpectedError;
				}

			}
			else {
				decryptedBytes = decryptedDataSize;
			}

			*plainTextLen = *plainTextLen + decryptedBytes;
			encryptedTextPosition = encryptedTextPosition + keySize;
		}

		return Success;
	}

	OpcUaStatusCode
	CryptoRSA::privateSign(
		char*       plainTextBuf,
		uint32_t    plainTextLen,
		PrivateKey* privateKey,
	    int32_t     digest,
	    char*       signTextBuf,
	    uint32_t*   signTextLen
	)
	{
		// check public key
		if (privateKey->keyType() != KeyType_RSA) {
			if (isLogging_) {
				Log(Error, "sign error - invalid private key type");
			}
			return BadInvalidArgument;
		}

		// get private key
		EVP_PKEY* key = (*privateKey);
	    if (key == nullptr) {
			if (isLogging_) {
				Log(Error, "sign error - private key empty");
			}
	        return BadUnexpectedError;
	    }
		if (EVP_PKEY_get0_RSA(key) == nullptr) {
			if (isLogging_) {
				Log(Error, "sign error - private rsa key empty");
			}
			return BadUnexpectedError;
		}

		// check sign text length
		uint32_t size =  RSA_size(EVP_PKEY_get0_RSA(key));
		if (size != *signTextLen) {
			if (isLogging_) {
				Log(Error, "sign error - sign text length");
			}
			return BadInvalidArgument;
		}

		// sign plain text
		*signTextLen = 0;
		int32_t result = RSA_sign(
			digest,
			(const unsigned char*)plainTextBuf,
			plainTextLen,
			(unsigned char*)signTextBuf,
			signTextLen,
			(RSA*)EVP_PKEY_get0_RSA(key)
		);
		if (result != 1) {
			addOpenSSLError();

			if (isLogging_) {
				log(Error, "sign error - RSA_sign");
			}
			return BadUnexpectedError;
		}

		return Success;
	}

	OpcUaStatusCode
	CryptoRSA::publicVerify(
		char*       plainTextBuf,
		uint32_t    plainTextLen,
		PublicKey*  publicKey,
	    int32_t     digest,
	    char*       signTextBuf,
	    uint32_t    signTextLen
	)
	{
		// check public key
		if (publicKey->keyType() != KeyType_RSA) {
			if (isLogging_) {
				Log(Error, "sign error - public key type error");
			}
			return BadInvalidArgument;
		}

		// get key information
		EVP_PKEY* key = *publicKey;
		if (key == nullptr) {
			if (isLogging_) {
				Log(Error, "sign error - public key is empty");
			}
			return BadUnexpectedError;
		}

		if (EVP_PKEY_get0_RSA(key) == nullptr) {
			if (isLogging_) {
				Log(Error, "sign error - public rsa key type error");
			}
			return BadUnexpectedError;
		}

		// check sign text length
		uint32_t size =  RSA_size(EVP_PKEY_get0_RSA(key));
		if (signTextLen % size != 0) {
			if (isLogging_) {
				Log(Error, "sign error - sign text length error");
			}
			return BadInvalidArgument;
		}

		int32_t result = RSA_verify(
			digest,
			(const unsigned char*)plainTextBuf,
			plainTextLen, (unsigned char *)signTextBuf,
			signTextLen,
			(RSA*)EVP_PKEY_get0_RSA(key)
		);
		if (result != 1) {
			addOpenSSLError();

			if (isLogging_) {
				log(Error, "sign error - RSA_verify");
			}
		    return BadSignatureInvalid;
		}

		return Success;
	}

}
