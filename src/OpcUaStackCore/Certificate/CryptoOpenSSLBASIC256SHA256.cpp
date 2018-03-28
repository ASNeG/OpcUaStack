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

#include <OpcUaStackCore/Certificate/CryptoOpenSSLBASIC256SHA256.h>
#include <OpcUaStackCore/Certificate/CryptoRSA.h>
#include <OpcUaStackCore/Certificate/CryptoAES.h>

namespace OpcUaStackCore
{

	CryptoOpenSSLBASIC256SHA256::CryptoOpenSSLBASIC256SHA256(void)
	:CryptoBase()
	{
		securityPolicy("http://opcfoundation.org/UA/SecurityPolicy#Basic256Sha256");

		symmetricKeyLen(32);
		minimumAsymmetricKeyLen(256);
		maximumAsymmetricKeyLen(512);
		derivedEncryptionKeyLen(32);
		derivedSignatureKeyLen(32);
		signatureDataLen(32);
		asymmetricSignatureAlgorithmId(SignatureAlgs::RSA_PKCS1_OAEP_SHA256_Id);
		asymmetricEncryptionAlgorithmId(EnryptionAlgs::RSA_OAEP_Id);
		symmetricSignatureAlgorithmId(SignatureAlgs::HMAC_SHA256_Id);
		symmetricEncryptionAlgorithmId(EnryptionAlgs::AES_256_CBC_Id);
	}

	CryptoOpenSSLBASIC256SHA256::~CryptoOpenSSLBASIC256SHA256(void)
	{
	}

	OpcUaStatusCode
	CryptoOpenSSLBASIC256SHA256::asymmetricDecrypt(
	    char*       	encryptedTextBuf,
		uint32_t		encryptedTextLen,
		PrivateKey&		privateKey,
		char*       	plainTextBuf,
		uint32_t*		plainTextLen
	)
	{
		CryptoRSA cryptoRSA;
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
	CryptoOpenSSLBASIC256SHA256::asymmetricEncrypt(
	    char*       	plainTextBuf,
		uint32_t		plainTextLen,
		PublicKey&		publicKey,
		char*       	encryptedTextBuf,
		uint32_t*		encryptedTextLen
	)
	{
		CryptoRSA cryptoRSA;
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
	CryptoOpenSSLBASIC256SHA256::symmetricDecrypt(
		char*       	encryptedTextBuf,
		uint32_t		encryptedTextLen,
		AESKey&	   		aesKey,
		IV&		   		iv,
		char*      		plainTextBuf,
		int32_t*   		plainTextLen
	)
	{
		CryptoAES cryptoAES;
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
	CryptoOpenSSLBASIC256SHA256::symmetricEncrypt(
		char*       	plainTextBuf,
		uint32_t		plainTextLen,
		AESKey&	   		aesKey,
		IV&		   		iv,
		char*      		encryptedTextBuf,
		int32_t*   		encryptedTextLen
	)
	{
		CryptoAES cryptoAES;
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
	CryptoOpenSSLBASIC256SHA256::asymmetricSign(
	    char*       	dataTextBuf,
		uint32_t		dataTextLen,
		PrivateKey&		privateKey,
		char*       	signatureTextBuf,
		uint32_t*		signatureTextLen
	)
	{
		return BadNotSupported;
	}

}
