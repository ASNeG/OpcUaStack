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

#include <openssl/evp.h>
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Certificate/PkiRsaCrypt.h"

namespace OpcUaStackCore
{

	PkiRsaCrypt::PkiRsaCrypt(void)
	: padding_(RSA_PKCS1_PADDING)
	, pkiRsaKey_(nullptr)
	{
	}

	PkiRsaCrypt::~PkiRsaCrypt(void)
	{
	}

	void
	PkiRsaCrypt::padding(int padding)
	{
		padding_ = padding;
	}

	int
	PkiRsaCrypt::padding(void)
	{
		return padding_;
	}

	void
	PkiRsaCrypt::pkiRsaKey(PkiRsaKey* pkiRsaKey)
	{
		pkiRsaKey_ = pkiRsaKey;
	}

	PkiRsaKey*
	PkiRsaCrypt::pkiRsaKey(void)
	{
		return pkiRsaKey_;
	}

	bool
	PkiRsaCrypt::publicEncrypt(
		const char* data,
		uint32_t dataLen,
		char* encryptedData,
		int32_t& encryptedDataLen
	)
	{
		int resultCode;

		// get public key
		PkiPublicKey pkiPublicKey;
		if (!pkiRsaKey_->getPublicKey(pkiPublicKey)) {
        	openSSLError("rsa public key error (1)");
        	return false;
		}

		// get rsa
		RSA* rsa;
		rsa = EVP_PKEY_get1_RSA(pkiPublicKey.publicKey());
        if (rsa == nullptr) {
        	openSSLError("rsa public key error (2)");
        	return false;
        }

		// encrypt data
		resultCode = RSA_public_encrypt(
			dataLen,
			(const unsigned char*)data,
			(unsigned char*)encryptedData,
			rsa,
			padding_
		);
		encryptedDataLen = resultCode;
        if (!resultCode) {
        	openSSLError();
        	return false;
        }

		return true;
	}

	bool
	PkiRsaCrypt::privateDecrypt(
		const char* encryptedData,
		uint32_t encryptedDataLen,
		char* data,
		int32_t& dataLen
	)
	{
		int resultCode;

		// get private key
		PkiPrivateKey pkiPrivateKey;
		if (!pkiRsaKey_->getPrivateKey(pkiPrivateKey)) {
        	openSSLError("rsa private key error (1)");
        	return false;
		}

		// get rsa
		RSA* rsa;
		rsa = EVP_PKEY_get1_RSA(pkiPrivateKey.privateKey());
        if (rsa == nullptr) {
        	openSSLError("rsa private key error (2)");
        	return false;
        }

		// encrypt data
		resultCode = RSA_private_decrypt(
			encryptedDataLen,
			(const unsigned char*)encryptedData,
			(unsigned char*)data,
			rsa,
			padding_
		);
		dataLen = resultCode;
        if (!resultCode) {
        	openSSLError();
        	return false;
        }

		return true;
	}

}




