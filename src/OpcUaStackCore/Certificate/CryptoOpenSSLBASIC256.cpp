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

#include <OpcUaStackCore/Certificate/CryptoOpenSSLBASIC256.h>
#include <OpcUaStackCore/Certificate/CryptoRSA.h>
#include <OpcUaStackCore/Certificate/CryptoAES.h>

namespace OpcUaStackCore
{

	CryptoOpenSSLBASIC256::CryptoOpenSSLBASIC256(void)
	:CryptoBase()
	{
		securityPolicy("http://opcfoundation.org/UA/SecurityPolicy#Basic256");

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
	    char*       	dataTextBuf,
		uint32_t		dataTextLen,
		PrivateKey&		privateKey,
		char*       	signatureTextBuf,
		uint32_t*		signatureTextLen
	)
	{
		return BadNotSupported;
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
		return BadNotSupported;
	}

	OpcUaStatusCode
	CryptoOpenSSLBASIC256::symmetricSign(
	    char*       	dataTextBuf,
		uint32_t		dataTextLen,
		MemoryBuffer&	key,
		char*       	signatureTextBuf,
		uint32_t*		signatureTextLen
	)
	{
		return BadNotSupported;
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
		return BadNotSupported;
	}

}
