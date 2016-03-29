/*
   Copyright 2016 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Certificate/PkiAesCrypt.h"

namespace OpcUaStackCore
{

	PkiAesCrypt::PkiAesCrypt(void)
	: ctx_(nullptr)
	{
	}

	PkiAesCrypt::~PkiAesCrypt(void)
	{
	}

	bool
	PkiAesCrypt::encrypt(
		const unsigned char* data,
		uint32_t dataLen,
		const unsigned char* key,
		uint32_t keyLen,
		const unsigned char* iv,
		uint32_t ivLen,
		unsigned char *encryptData,
		int32_t& encryptDataLen
	)
	{
		int resultCode;

		// check parameter
		if (keyLen != 32) {
			openSSLError("key len error");
			return false;
		}
		if (ivLen != 16) {
			openSSLError("iv len error");
			return false;
		}

		// create and initialise the context
		ctx_ = EVP_CIPHER_CTX_new();
		if (ctx_ == nullptr) {
			openSSLError();
			return false;
		}

		// initialise the encryption operation.
		resultCode = EVP_EncryptInit_ex(ctx_, EVP_aes_256_cbc(), nullptr, key, iv);
		if (resultCode != 1) {
			openSSLError();
			EVP_CIPHER_CTX_free(ctx_);
			return false;
		}

		// encrypt
		resultCode = EVP_EncryptUpdate(ctx_, encryptData, &encryptDataLen, data, dataLen);
		if (resultCode != 1) {
			openSSLError();
			EVP_CIPHER_CTX_free(ctx_);
			return false;
		}

		// finalise encrypt
		int len;
		resultCode =  EVP_EncryptFinal_ex(ctx_, encryptData + encryptDataLen, &len);
		if (resultCode != 1) {
			openSSLError();
			EVP_CIPHER_CTX_free(ctx_);
			return false;
		}
		encryptDataLen += len;

		EVP_CIPHER_CTX_free(ctx_);

		return true;
	}

	bool
	PkiAesCrypt::decrypt(
		const unsigned char* encryptData,
		uint32_t encryptDataLen,
		const unsigned char* key,
		uint32_t keyLen,
		const unsigned char* iv,
		uint32_t ivLen,
		unsigned char *data,
		int32_t& dataLen
	)
	{
		int resultCode;

		// check parameter
		if (keyLen != 32) {
			openSSLError("key len error");
			return false;
		}
		if (ivLen != 16) {
			openSSLError("iv len error");
			return false;
		}

		// create and initialise the context
		ctx_ = EVP_CIPHER_CTX_new();
		if (ctx_ == nullptr) {
			openSSLError();
			return false;
		}

		// initialise the decryption operation.
		resultCode = EVP_DecryptInit_ex(ctx_, EVP_aes_256_cbc(), nullptr, key, iv);
		if (resultCode != 1) {
			openSSLError();
			EVP_CIPHER_CTX_free(ctx_);
			return false;
		}

		// decrypt
		resultCode = EVP_DecryptUpdate(ctx_, data, &dataLen, encryptData, encryptDataLen);
		if (resultCode != 1) {
			openSSLError();
			EVP_CIPHER_CTX_free(ctx_);
			return false;
		}

		// finalise encrypt
		int len;
		resultCode =  EVP_DecryptFinal_ex(ctx_, data + dataLen, &len);
		if (resultCode != 1) {
			openSSLError();
			EVP_CIPHER_CTX_free(ctx_);
			return false;
		}
		dataLen += len;

		EVP_CIPHER_CTX_free(ctx_);

		return true;
	}

}




