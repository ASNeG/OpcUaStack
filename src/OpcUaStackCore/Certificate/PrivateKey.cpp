/*
   Copyright 2018-2020 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/Certificate/OpenSSLCompat.h"
#include "OpcUaStackCore/Certificate/PrivateKey.h"

namespace OpcUaStackCore
{

	PrivateKey::PrivateKey(void)
	: OpenSSLError()
	, privateKey_(nullptr)
	{
		privateKey_ = EVP_PKEY_new();
		if (privateKey_ == nullptr) {
			addError("create private key error in copy constructor - empty");
			return;
		}
	}

	PrivateKey::PrivateKey(EVP_PKEY *pKey)
	: OpenSSLError()
	, privateKey_(nullptr)
	{
		assert(pKey != nullptr);

	    privateKey_ = pKey;
	    EVP_PKEY_up_ref(privateKey_);
	}

	PrivateKey::PrivateKey(const PrivateKey& copy)
	: OpenSSLError()
	, privateKey_(nullptr)
	{
		if (const_cast<PrivateKey*>(&copy)->isError()) {
			addError("create private key error in copy constructor - source key error");
			return;
		}

	    if (copy.privateKey_ != nullptr) {
	        privateKey_ = copy.privateKey_;
	        EVP_PKEY_up_ref(privateKey_);
	    }
	    else
	    {
	        privateKey_ = EVP_PKEY_new();
	    }
	}

	PrivateKey::~PrivateKey(void)
	{
		if (privateKey_ != nullptr) {
			EVP_PKEY_free(privateKey_);
			privateKey_ = nullptr;
		}
	}

	uint32_t
	PrivateKey::keySizeInBytes(void) const
	{
		return keySize() / 8;
	}

	uint32_t
	PrivateKey::keySize(void) const
	{
		if (privateKey_ == nullptr) {
			return 0;
		}

	    return EVP_PKEY_bits(privateKey_);
	}

	KeyType
	PrivateKey::keyType(void) const
	{
		KeyType keyType = KeyType_Unknown;

		if (privateKey_ == nullptr) {
			return keyType;
		}

        switch(EVP_PKEY_id(privateKey_))
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

		if (privateKey_ != nullptr) {
			EVP_PKEY_free(privateKey_);
			privateKey_ = nullptr;
		}

	    if (copy.privateKey_ != nullptr) {
	        privateKey_ = copy.privateKey_;
	        EVP_PKEY_up_ref(privateKey_);
	    }
	    else {
	        privateKey_ = EVP_PKEY_new();
	    }

	    return *this;
	}

	PrivateKey::operator EVP_PKEY*(void)
	{
		if (privateKey_ != nullptr) {
			EVP_PKEY_up_ref(privateKey_);
		}
		return privateKey_;
	}

	bool
	PrivateKey::toDER(char* buf, uint32_t& bufLen) const
	{
		if (privateKey_ == nullptr) {
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
	    char* ptr = buf;
		i2d_PrivateKey(privateKey_, (unsigned char**)&ptr);
		return true;
	}

	bool
	PrivateKey::fromDER (char* buf, uint32_t bufLen, KeyType keyType)
	{
		if (privateKey_ != nullptr) {
			EVP_PKEY_free(privateKey_);
			privateKey_ = nullptr;
		}

		char* ptr = buf;
	    privateKey_ = d2i_PrivateKey(keyType, 0, (const unsigned char**)&ptr, bufLen);
	    if (privateKey_ == nullptr) {
	    	const_cast<PrivateKey*>(this)->addOpenSSLError();
	    	return false;
	    }

	    return true;
	}

	bool
	PrivateKey::fromPEM(char* buf, uint32_t bufLen, const char *password, PasswordCallback* passwordCallback, void *data)
	{
		if (privateKey_ != nullptr) {
			EVP_PKEY_free(privateKey_);
			privateKey_ = nullptr;
		}

	    BIO* bio = BIO_new_mem_buf((void*)buf, bufLen);

		if (passwordCallback) {
		    privateKey_ = PEM_read_bio_PrivateKey(bio, 0, passwordCallback, data);
		}
		else {
		    privateKey_ = PEM_read_bio_PrivateKey(bio, 0, 0, (void*)password);
		}

		if (privateKey_ == nullptr) {
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
		if (privateKey_ == nullptr) {
			addError("private key is empty");
			return false;
		}

		BIO* bio = BIO_new_file(fileName.c_str(), "w");
	    if (!bio) {
	    	addOpenSSLError();
	    	return false;
	    }

	    RSA* rsa = EVP_PKEY_get1_RSA(privateKey_);
	    if (rsa == nullptr) {
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
		if (privateKey_ != nullptr) {
			EVP_PKEY_free(privateKey_);
			privateKey_ = nullptr;
		}

	    BIO* bio = BIO_new_file(fileName.c_str(), "r");

		if (passwordCallback != nullptr) {
		    privateKey_ = PEM_read_bio_PrivateKey(bio, 0, passwordCallback, data);
		}
		else {
		    privateKey_ = PEM_read_bio_PrivateKey(bio, 0, 0, (void*)password);
		}

		if (privateKey_ == nullptr) {
			addOpenSSLError();
			BIO_free(bio);
			return false;
		}

		BIO_free(bio);
		return true;
	}

}
