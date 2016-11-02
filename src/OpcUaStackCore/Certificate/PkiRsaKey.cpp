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

#include <openssl/err.h>
#include <openssl/x509.h>
#include <openssl/pem.h>
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Certificate/PkiRsaKey.h"

namespace OpcUaStackCore
{

	int passwordCallback(char* buf, int size, int rwflag, void* u)
	{
		if (u == nullptr) return 0;
		return sprintf(buf, "%s", (char*)u);
	}


	PkiRsaKey::PkiRsaKey(void)
	: PkiError()
	, key_(nullptr)
	{
		key_ = EVP_PKEY_new();
	}

	PkiRsaKey::~PkiRsaKey(void)
	{
		if (key_ == nullptr) {
			EVP_PKEY_free (key_);
			key_ = nullptr;
		}
	}

	bool
	PkiRsaKey::createKey(uint32_t bits)
	{
	    RSA *rsaKey = RSA_generate_key(bits, 0x10001, 0, 0);
	    if (!rsaKey) {
	    	openSSLError();
	    	return false;
	    }

	    int resultCode = EVP_PKEY_assign_RSA(key_, rsaKey);
	    if (!resultCode) {
	    	openSSLError();
	    	return false;
	    }

	    return true;
	}

	bool
	PkiRsaKey::getPublicKey(PkiPublicKey& publicKey)
	{
		return publicKey.publicKey(key_);
	}

	bool
	PkiRsaKey::getPrivateKey(PkiPrivateKey& privateKey)
	{
		privateKey.privateKey(key_);
		return true;
	}

	bool
	PkiRsaKey::setPublicKey(PkiPublicKey& publicKey)
	{
		key_ = publicKey.publicKey();
		return true;
	}

	bool
	PkiRsaKey::setPrivateKey(PkiPrivateKey& privateKey)
	{
		key_ = privateKey.privateKey();
		return true;
	}

	uint32_t
	PkiRsaKey::keyLength(void)
	{
		int32_t size = EVP_PKEY_bits (key_);
	    if (size < 0) {
	    	openSSLError();
	    	return 0;
	    }
		return size;
	}

	bool
	PkiRsaKey::toHexStringPublicKey(std::string& hexString)
	{
		hexString = "";

		BIO* bio = BIO_new(BIO_s_mem());
		if (bio == nullptr) {
			openSSLError("bio memory allocation error");
			return false;
		}

		EVP_PKEY_print_public(bio, key_, 0, NULL);

		BUF_MEM* mem = NULL;
		BIO_get_mem_ptr(bio, &mem);
		hexString.assign(mem->data, mem->length);

		BIO_free(bio);
		return true;
	}

	uint32_t
	PkiRsaKey::modulus(void)
	{
		RSA *rsa = EVP_PKEY_get1_RSA(key_);
		if (!rsa) {
		    openSSLError();
		    return 0;
		}

		//BN_print(out, rsa->n);

		return 0; //rsa->n;
	}

	bool
	PkiRsaKey::writePEMFile(const std::string& fileName, const std::string& password)
	{
		if (key_ == nullptr) {
			openSSLError("cannot write PEM file because key empty");
			return false;
		}

        BIO *bioPem = BIO_new(BIO_s_file());
        if (!bioPem) {
        	openSSLError();
        	return false;
        }

        int resultCode = BIO_write_filename(bioPem, (void*)fileName.c_str());
        if (!resultCode) {
        	openSSLError();
        	BIO_free (bioPem);
        	return false;
        }

        RSA *rsaKey = EVP_PKEY_get1_RSA(key_);
        if (!rsaKey) {
        	openSSLError();
        	BIO_free (bioPem);
        	return false;
        }

        if (password.empty()) {
            // store private key unencrypted
            resultCode = PEM_write_bio_RSAPrivateKey(bioPem, rsaKey, 0, 0, 0, 0, 0);
            if (!resultCode) {
                openSSLError();
                RSA_free(rsaKey);
                BIO_free (bioPem);
                return false;
            }
        }
        else {
            // store private key encrypted
            resultCode = PEM_write_bio_RSAPrivateKey(bioPem, rsaKey, EVP_des_ede3_cbc(), 0, 0, 0, (void*)password.c_str());
            if (!resultCode) {
            	openSSLError();
            	RSA_free(rsaKey);
            	BIO_free (bioPem);
            	return false;
            }
        }

        RSA_free(rsaKey);
        BIO_free(bioPem);
		return true;
	}

	bool
	PkiRsaKey::readPEMFile(const std::string& fileName, const std::string& password)
	{
		if (key_ == nullptr) {
			openSSLError("cannot read PEM file because key empty");
			return false;
		}

        BIO *bioPem = BIO_new(BIO_s_file());
        if (!bioPem) {
        	openSSLError();
        	return false;
        }

        int resultCode = BIO_read_filename(bioPem, (void*)fileName.c_str());
        if (!resultCode) {
        	openSSLError();
        	BIO_free (bioPem);
        	return false;
        }

        RSA* rsaKey = nullptr;
        if (password.empty()) {
        	// load private key unencrypted
        	rsaKey = PEM_read_bio_RSAPrivateKey(bioPem, 0, passwordCallback, nullptr);
            if (rsaKey == nullptr) {
            	openSSLError();
            	BIO_free (bioPem);
            	return false;
            }
        }
        else {
        	// load private key encrypted
        	rsaKey = PEM_read_bio_RSAPrivateKey(bioPem, 0, passwordCallback, (void*)password.c_str());
            if (rsaKey == nullptr) {
            	openSSLError();
            	BIO_free (bioPem);
            	return false;
            }
        }

        resultCode = EVP_PKEY_assign_RSA(key_, rsaKey);
        if (!resultCode) {
        	openSSLError();
        	BIO_free (bioPem);
        	return false;
        }

        BIO_free(bioPem);
		return true;
	}

}




