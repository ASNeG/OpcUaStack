/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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
			openSSLError("cannot write PEM file because key empty");
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

#if 0
        UaPkiRsaKeyPair keyPair;

         RSA *pRSA = 0;

         if (pCallback)
         {
             pRSA = PEM_read_bio_RSAPrivateKey ( bioPem, 0, pCallback, pCBData );
             if (!pRSA) {keyPair.addOpenSSLError();}
         }
         else
         {
             pRSA = c ( bioPem, 0, password_callback, ( void* ) szPassword );
             if (!pRSA) {keyPair.addOpenSSLError();}
         }

         if (pRSA)
         {
             // assign the key pair
             resultCode = EVP_PKEY_assign_RSA ( keyPair.m_pKey, pRSA );
             if (!resultCode) {keyPair.addOpenSSLError();}
         }
#endif

        BIO_free(bioPem);
		return true;
	}

}




