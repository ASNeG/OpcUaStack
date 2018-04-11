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

#include "OpcUaStackCore/Certificate/CryptoOpenSSLBASIC128RSA15.h"
#include "OpcUaStackCore/Certificate/CryptoRSA.h"
#include "OpcUaStackCore/Certificate/CryptoAES.h"
#include "OpcUaStackCore/Certificate/CryptoSHA1.h"
#include "OpcUaStackCore/Certificate/CryptoHMAC_SHA.h"

namespace OpcUaStackCore
{

	CryptoOpenSSLBASIC128RSA15::CryptoOpenSSLBASIC128RSA15(void)
	:CryptoBase()
	{
		securityPolicy("http://opcfoundation.org/UA/SecurityPolicy#Basic128Rsa15");

		symmetricKeyLen(16);
		minimumAsymmetricKeyLen(128);
		maximumAsymmetricKeyLen(512);
		derivedEncryptionKeyLen(16);
		derivedSignatureKeyLen(16);
		signatureDataLen(20);
		asymmetricSignatureAlgorithmId(SignatureAlgs::RSA_PKCS1_V15_SHA1_Id);
		asymmetricEncryptionAlgorithmId(EnryptionAlgs::RSA_PKCS1_V15_Id);
		symmetricSignatureAlgorithmId(SignatureAlgs::HMAC_SHA1_Id);
		symmetricEncryptionAlgorithmId(EnryptionAlgs::AES_128_CBC_Id);
	}

	CryptoOpenSSLBASIC128RSA15::~CryptoOpenSSLBASIC128RSA15(void)
	{
	}

	OpcUaStatusCode
	CryptoOpenSSLBASIC128RSA15::getAsymmetricEncryptionBlockSize(
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

		*plainTextBlockSize = asymmetricKeyLen/8 - 11;
		*cryptTextBlockSize = asymmetricKeyLen/8;

		return Success;
	}

	OpcUaStatusCode
	CryptoOpenSSLBASIC128RSA15::getAsymmetricSignatureBlockSize(
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
	CryptoOpenSSLBASIC128RSA15::getSymmetricEncryptionBlockSize(
		uint32_t* plainTextBlockSize,
		uint32_t* cryptTextBlockSize
	)
	{
		*plainTextBlockSize = 16;
		*cryptTextBlockSize = 16;
		return Success;
	}

	OpcUaStatusCode
	CryptoOpenSSLBASIC128RSA15::getSymmetricSignatureBlockSize(
		uint32_t* signTextBlockSize
	)
	{
		*signTextBlockSize = 20;
		return Success;
	}

	OpcUaStatusCode
	CryptoOpenSSLBASIC128RSA15::asymmetricKeyLen(
		PublicKey& publicKey,
		uint32_t* asymmetricKeyLen
	)
	{
		if (publicKey.keyType() != KeyType_RSA) {
			return BadInvalidArgument;
		}
		*asymmetricKeyLen = publicKey.keySize();
		return Success;
	}

	OpcUaStatusCode
	CryptoOpenSSLBASIC128RSA15::asymmetricDecrypt(
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
			RSA_PKCS1_PADDING,
			plainTextBuf,
			plainTextLen
		);
	}

	OpcUaStatusCode
	CryptoOpenSSLBASIC128RSA15::asymmetricEncrypt(
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
			RSA_PKCS1_PADDING,
			encryptedTextBuf,
			encryptedTextLen
		);
	}

	OpcUaStatusCode
	CryptoOpenSSLBASIC128RSA15::symmetricDecrypt(
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
		return cryptoAES.decryptCBC128(
			encryptedTextBuf,
			encryptedTextLen,
			aesKey,
			iv,
			plainTextBuf,
			plainTextLen
		);
	}

	OpcUaStatusCode
	CryptoOpenSSLBASIC128RSA15::symmetricEncrypt(
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
		return cryptoAES.encryptCBC128(
			plainTextBuf,
			plainTextLen,
			aesKey,
			iv,
			encryptedTextBuf,
			encryptedTextLen
		);
	}

	OpcUaStatusCode
	CryptoOpenSSLBASIC128RSA15::asymmetricSign(
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
	CryptoOpenSSLBASIC128RSA15::asymmetricVerify(
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
	CryptoOpenSSLBASIC128RSA15::symmetricSign(
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
	CryptoOpenSSLBASIC128RSA15::symmetricVerify(
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
			return BadSignatureInvalid;
		}
		if (memcmp(signTextBuf, sigText.memBuf(), signTextLen) != 0) {
			return BadSignatureInvalid;
		}

		return Success;
	}

	OpcUaStatusCode
	CryptoOpenSSLBASIC128RSA15::deriveKey(
		MemoryBuffer& secret,			// remote nonce
		MemoryBuffer& seed,				// local nonce
		MemoryBuffer& key				// len = sig key + enc key + iv
	)
	{
		return BadNotSupported;
	}

}
