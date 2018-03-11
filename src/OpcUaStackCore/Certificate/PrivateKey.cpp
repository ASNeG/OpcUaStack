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

#include <openssl/pem.h>

#include "OpcUaStackCore/Certificate/PrivateKey.h"

namespace OpcUaStackCore
{

	PrivateKey::PrivateKey(void)
	: OpenSSLError()
	, privateKey_(nullptr)
	{
		privateKey_ = EVP_PKEY_new();
	}

	PrivateKey::PrivateKey(EVP_PKEY *pKey)
	: OpenSSLError()
	, privateKey_(nullptr)
	{
	    CRYPTO_add(&pKey->references, 1, CRYPTO_LOCK_EVP_PKEY);
	    privateKey_ = pKey;
	}

	PrivateKey::PrivateKey(const PrivateKey& copy)
	: OpenSSLError()
	, privateKey_(nullptr)
	{
		if (const_cast<PrivateKey*>(&copy)->isError()) {
			addError("create ptivate key error in copy constructor - source key error");
			return;
		}

	    if (copy.privateKey_) {
	        CRYPTO_add(&copy.privateKey_->references, 1, CRYPTO_LOCK_EVP_PKEY);
	        privateKey_ = copy.privateKey_;
	    }
	    else
	    {
	        privateKey_ = EVP_PKEY_new();
	    }
	}

	PrivateKey::~PrivateKey(void)
	{
		EVP_PKEY_free (privateKey_);
	}

	uint32_t
	PrivateKey::keySize(void) const
	{
	    return EVP_PKEY_bits(privateKey_);
	}

	KeyType
	PrivateKey::keyType(void) const
	{
		KeyType keyType = KeyType_Unknown;
        switch(privateKey_->type)
        {
            case EVP_PKEY_RSA: keyType = KeyType_RSA; break;
            case EVP_PKEY_DSA: keyType = KeyType_DSA; break;
            default: break;
        }
        return keyType;
	}

	PrivateKey&
	PrivateKey::operator=(const PrivateKey& copy)
	{
		if (const_cast<PrivateKey*>(&copy)->isError()) {
			addError("private key error in assign operator - source key error");
			return *this;
		}

	    EVP_PKEY_free (privateKey_);
	    if (copy.privateKey_) {
	        CRYPTO_add(&copy.privateKey_->references, 1, CRYPTO_LOCK_EVP_PKEY);
	        privateKey_ = copy.privateKey_;
	    }
	    else {
	        privateKey_ = EVP_PKEY_new();
	    }
	    return *this;
	}

	PrivateKey::operator EVP_PKEY*(void)
	{
		return privateKey_;
	}

	bool
	PrivateKey::toDER(char* buf, uint32_t& bufLen) const
	{
		if (!privateKey_) {
			const_cast<PrivateKey*>(this)->addError("private key is empty");
			return false;
		}

		int length = i2d_PrivateKey(privateKey_, 0);
		if (length < 0) {
		    const_cast<PrivateKey*>(this)->addOpenSSLError();
		    return false;
		}

	    if (length > bufLen) {
	    	const_cast<PrivateKey*>(this)->addError("buffer length is too short");
	    	return false;
	    }

	    bufLen = length;
		i2d_PrivateKey(privateKey_, (unsigned char**)&buf);
		return true;
	}

	bool
	PrivateKey::fromDER (char* buf, uint32_t bufLen, KeyType keyType)
	{
	    privateKey_ = d2i_PrivateKey(keyType, 0, (const unsigned char**)&buf, bufLen);
	    if (!privateKey_) {
	    	const_cast<PrivateKey*>(this)->addOpenSSLError();
	    	return false;
	    }

	    return true;
	}

	bool
	PrivateKey::fromPEM (char* buf, uint32_t bufLen, const char *password, PasswordCallback* passwordCallback, void *data)
	{
	    BIO* bio = BIO_new_mem_buf((void*)buf, bufLen);

		if (passwordCallback) {
		    privateKey_ = PEM_read_bio_PrivateKey(bio, 0, passwordCallback, data);
		}
		else {
		    privateKey_ = PEM_read_bio_PrivateKey(bio, 0, 0, (void*)password);
		}

		if (!privateKey_) {
			addOpenSSLError();
			BIO_free(bio);
			return false;
		}

		BIO_free(bio);
		return true;
	}

	bool
	PrivateKey::toPEMFile(const std::string& fileName, const char* password)
	{
		if (!privateKey_) {
			addError("private key is empty");
			return false;
		}

		BIO* bio = BIO_new_file(fileName.c_str(), "w");
	    if (!bio) {
	    	addOpenSSLError();
	    	return false;
	    }

	    RSA* rsa = EVP_PKEY_get1_RSA(privateKey_);
	    if (!rsa) {
	    	addOpenSSLError();
	    	BIO_free(bio);
	    	return false;
	    }

	    if (password != nullptr) {
            // encrypt private key
            int32_t result = PEM_write_bio_RSAPrivateKey(bio, rsa, EVP_aes_256_cbc(), 0, 0, 0, (void*)password);
            if (!result) {
             	addOpenSSLError();
         	    RSA_free(rsa);
         	    BIO_free(bio);
             	return false;
             }
	    }
	    else {
            // store private key unencrypted
            int32_t result = PEM_write_bio_RSAPrivateKey(bio, rsa, 0, 0, 0, 0, 0);
            if (!result) {
            	addOpenSSLError();
        	    RSA_free(rsa);
        	    BIO_free(bio);
            	return false;
            }
	    }

	    RSA_free(rsa);
	    BIO_free(bio);

        return true;
	}

	bool
	PrivateKey::fromPEMFile(const std::string& fileName, const char* password, PasswordCallback* passwordCallback, void *data)
	{
	    BIO* bio = BIO_new_file(fileName.c_str(), "r");

		if (passwordCallback != nullptr) {
		    privateKey_ = PEM_read_bio_PrivateKey(bio, 0, passwordCallback, data);
		}
		else {
		    privateKey_ = PEM_read_bio_PrivateKey(bio, 0, 0, (void*)password);
		}

		if (!privateKey_) {
			addOpenSSLError();
			BIO_free(bio);
			return false;
		}

		BIO_free(bio);
	}

}
