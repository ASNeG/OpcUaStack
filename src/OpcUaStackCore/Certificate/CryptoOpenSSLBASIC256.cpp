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

#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/Certificate/CryptoOpenSSLBASIC256.h"
#include "OpcUaStackCore/Certificate/CryptoRSA.h"
#include "OpcUaStackCore/Certificate/CryptoAES.h"
#include "OpcUaStackCore/Certificate/CryptoSHA1.h"
#include "OpcUaStackCore/Certificate/CryptoHMAC_SHA.h"
#include "OpcUaStackCore/Certificate/Random.h"

namespace OpcUaStackCore
{

	CryptoOpenSSLBASIC256::CryptoOpenSSLBASIC256(void)
	:CryptoBase()
	{
		securityPolicy("http://opcfoundation.org/UA/SecurityPolicy#Basic256");

		nonceLen(32);
		symmetricKeyLen(32);
		minimumAsymmetricKeyLen(128);
		maximumAsymmetricKeyLen(512);
		derivedEncryptionKeyLen(32);
		derivedSignatureKeyLen(24);
		signatureDataLen(20);
		asymmetricSignatureAlgorithmId(SignatureAlgs::RSA_PKCS1_OAEP_SHA1_Id);
		asymmetricEncryptionAlgorithmId(EnryptionAlgs::RSA_OAEP_Id);
		symmetricSignatureAlgorithmId(SignatureAlgs::HMAC_SHA1_Id);
		symmetricEncryptionAlgorithmId(EnryptionAlgs::AES_256_CBC_Id);
	}

	CryptoOpenSSLBASIC256::~CryptoOpenSSLBASIC256(void)
	{
	}

	OpcUaStatusCode
	CryptoOpenSSLBASIC256::getAsymmetricEncryptionBlockSize(
		PublicKey& publicKey,
		uint32_t* plainTextBlockSize,
		uint32_t* cryptTextBlockSize
	)
	{
		*plainTextBlockSize = 0;
		*cryptTextBlockSize = 0;

		OpcUaStatusCode statusCode;
		uint32_t asymmetricKeyLen;
		statusCode = this->asymmetricKeyLen(publicKey, &asymmetricKeyLen);
		if (statusCode != Success) {
			return statusCode;
		}

		*plainTextBlockSize = asymmetricKeyLen/8 -42;
		*cryptTextBlockSize = asymmetricKeyLen/8;

		return Success;
	}

	OpcUaStatusCode
	CryptoOpenSSLBASIC256::getAsymmetricSignatureBlockSize(
		PublicKey& publicKey,
		uint32_t* signTextBlockSize
	)
	{
		OpcUaStatusCode statusCode;
		uint32_t asymmetricKeyLen;
		statusCode = this->asymmetricKeyLen(publicKey, &asymmetricKeyLen);
		if (statusCode != Success) {
			return statusCode;
		}

		*signTextBlockSize = asymmetricKeyLen/8;
		return Success;
	}

	OpcUaStatusCode
	CryptoOpenSSLBASIC256::getSymmetricEncryptionBlockSize(
		uint32_t* plainTextBlockSize,
		uint32_t* cryptTextBlockSize
	)
	{
		*plainTextBlockSize = 16;
		*cryptTextBlockSize = 16;
		return Success;
	}

	OpcUaStatusCode
	CryptoOpenSSLBASIC256::getSymmetricSignatureBlockSize(
		uint32_t* signTextBlockSize
	)
	{
		*signTextBlockSize = 20;
		return Success;
	}

	OpcUaStatusCode
	CryptoOpenSSLBASIC256::asymmetricKeyLen(
		PublicKey& publicKey,
		uint32_t* asymmetricKeyLen
	)
	{
		if (publicKey.keyType() != KeyType_RSA) {
			if (isLogging()) {
				Log(Error, "public key is not from type RSA");
			}
			return BadInvalidArgument;
		}
		*asymmetricKeyLen = publicKey.keySize();
		return Success;
	}

	OpcUaStatusCode
	CryptoOpenSSLBASIC256::asymmetricKeyLen(
		PrivateKey& privateKey,
		uint32_t* asymmetricKeyLen
	)
	{
		if (privateKey.keyType() != KeyType_RSA) {
			if (isLogging()) {
				Log(Error, "public key is not from type RSA");
			}
			return BadInvalidArgument;
		}
		*asymmetricKeyLen = privateKey.keySize();
		return Success;
	}

	OpcUaStatusCode
	CryptoOpenSSLBASIC256::asymmetricDecrypt(
	    char*       	encryptedTextBuf,
		uint32_t		encryptedTextLen,
		PrivateKey&		privateKey,
		char*       	plainTextBuf,
		uint32_t*		plainTextLen
	)
	{
		CryptoRSA cryptoRSA;
		cryptoRSA.isLogging(isLogging());
		return cryptoRSA.privateDecrypt(
			encryptedTextBuf,
			encryptedTextLen,
			&privateKey,
			RSA_PKCS1_OAEP_PADDING,
			plainTextBuf,
			plainTextLen
		);
	}

	OpcUaStatusCode
	CryptoOpenSSLBASIC256::asymmetricEncrypt(
		char*       	plainTextBuf,
		uint32_t		plainTextLen,
		PublicKey&		publicKey,
		char*       	encryptedTextBuf,
		uint32_t*		encryptedTextLen
	)
	{
		CryptoRSA cryptoRSA;
		cryptoRSA.isLogging(isLogging());
		return cryptoRSA.publicEncrypt(
			plainTextBuf,
			plainTextLen,
			&publicKey,
			RSA_PKCS1_OAEP_PADDING,
			encryptedTextBuf,
			encryptedTextLen
		);
	}

	OpcUaStatusCode
	CryptoOpenSSLBASIC256::symmetricDecrypt(
		char*       	encryptedTextBuf,
		uint32_t		encryptedTextLen,
		AESKey&	   		aesKey,
		IV&		   		iv,
		char*      		plainTextBuf,
		uint32_t*   	plainTextLen
	)
	{
		CryptoAES cryptoAES;
		cryptoAES.isLogging(isLogging());
		return cryptoAES.decryptCBC256(
			encryptedTextBuf,
			encryptedTextLen,
			aesKey,
			iv,
			plainTextBuf,
			plainTextLen
		);
	}

	OpcUaStatusCode
	CryptoOpenSSLBASIC256::symmetricEncrypt(
		char*       	plainTextBuf,
		uint32_t		plainTextLen,
		AESKey&	   		aesKey,
		IV&		   		iv,
		char*      		encryptedTextBuf,
		uint32_t*   	encryptedTextLen
	)
	{
		CryptoAES cryptoAES;
		cryptoAES.isLogging(isLogging());
		return cryptoAES.encryptCBC256(
			plainTextBuf,
			plainTextLen,
			aesKey,
			iv,
			encryptedTextBuf,
			encryptedTextLen
		);
	}

	OpcUaStatusCode
	CryptoOpenSSLBASIC256::asymmetricSign(
	    char*       	plainTextBuf,
		uint32_t		plainTextLen,
		PrivateKey&		privateKey,
		char*       	signTextBuf,
		uint32_t*		signTextLen
	)
	{
		OpcUaStatusCode statusCode;

		// create digest
		MemoryBuffer digest(20);
		CryptoSHA1 cryptoSHA1;
		cryptoSHA1.isLogging(isLogging());
		statusCode = cryptoSHA1.sha1(
		    plainTextBuf,
		    plainTextLen,
		    digest.memBuf(),
		    digest.memLen()
		);
		if (statusCode != Success) {
			return statusCode;
		}

		// sign digest
		CryptoRSA cryptoRSA;
		cryptoRSA.isLogging(isLogging());
		return cryptoRSA.privateSign(
			digest.memBuf(),
			digest.memLen(),
			&privateKey,
			NID_sha1,
			signTextBuf,
			signTextLen
		);
	}

	OpcUaStatusCode
	CryptoOpenSSLBASIC256::asymmetricVerify(
	    char*       	plainTextBuf,
		uint32_t		plainTextLen,
		PublicKey&		publicKey,
		char*       	signTextBuf,
		uint32_t		signTextLen
	)
	{
		OpcUaStatusCode statusCode;

		// create digest
		MemoryBuffer digest(20);
		CryptoSHA1 cryptoSHA1;
		cryptoSHA1.isLogging(isLogging());
		statusCode = cryptoSHA1.sha1(
		    plainTextBuf,
		    plainTextLen,
		    digest.memBuf(),
		    digest.memLen()
		);
		if (statusCode != Success) {
			return statusCode;
		}

		// sign digest
		CryptoRSA cryptoRSA;
		cryptoRSA.isLogging(isLogging());
		return cryptoRSA.publicVerify(
			digest.memBuf(),
			digest.memLen(),
			&publicKey,
			NID_sha1,
			signTextBuf,
			signTextLen
		);
	}

	OpcUaStatusCode
	CryptoOpenSSLBASIC256::symmetricSign(
	    char*       	plainTextBuf,
		uint32_t		plainTextLen,
		MemoryBuffer&	key,
		char*       	signTextBuf,
		uint32_t*		signTextLen
	)
	{
		CryptoHMAC_SHA cryptoHMAC_SHA;
		cryptoHMAC_SHA.isLogging(isLogging());

		return cryptoHMAC_SHA.generate_HMAC_SHA1(
			plainTextBuf,
			plainTextLen,
			key,
			signTextBuf,
			signTextLen
		);
	}

	OpcUaStatusCode
	CryptoOpenSSLBASIC256::symmetricVerify(
	    char*       	plainTextBuf,
		uint32_t		plainTextLen,
		MemoryBuffer&	key,
		char*       	signTextBuf,
		uint32_t		signTextLen
	)
	{
		OpcUaStatusCode statusCode;

		MemoryBuffer sigText(signTextLen);
		uint32_t signTextLen2 = sigText.memLen();

		CryptoHMAC_SHA cryptoHMAC_SHA;
		cryptoHMAC_SHA.isLogging(isLogging());

		statusCode =  cryptoHMAC_SHA.generate_HMAC_SHA1(
			plainTextBuf,
			plainTextLen,
			key,
			sigText.memBuf(),
			&signTextLen2
		);

		if (statusCode != Success) {
			return statusCode;
		}

		if (signTextLen2 != signTextLen) {
			if (isLogging()) {
				Log(Error, "check signature length error")
					.parameter("SignLen1", signTextLen)
					.parameter("SignLen2", signTextLen2);
			}
			return BadSignatureInvalid;
		}
		if (memcmp(signTextBuf, sigText.memBuf(), signTextLen) != 0) {
			if (isLogging()) {
				std::string hexString1;
				std::string hexString2;

				byteSequenceToHexString((uint8_t*)signTextBuf, signTextLen2, hexString1);
				sigText.toHexString(hexString2);

				Log(Error, "check signature text not equal")
					.parameter("Sign1", hexString1)
					.parameter("Sign2", hexString2);
			}
			return BadSignatureInvalid;
		}

		return Success;
	}

	OpcUaStatusCode
	CryptoOpenSSLBASIC256::deriveKey(
		MemoryBuffer& secret,			// remote nonce
		MemoryBuffer& seed,				// local nonce
		MemoryBuffer& key				// len = sig key + enc key + iv
	)
	{
		OpcUaStatusCode statusCode;

		Random random;
		statusCode = random.keyDerivePSHA1(secret, seed, key);

		if (statusCode != Success && isLogging()) {
			random.log(Error, "keyDerivePSHA1 error");
		}

		return statusCode;
	}

}
