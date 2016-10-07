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
#include <openssl/dsa.h>
#include <openssl/pem.h>
#include <openssl/rand.h>
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Certificate/PkiDsaKey.h"

namespace OpcUaStackCore
{

	PkiDsaKey::PkiDsaKey(void)
	: PkiError()
	, key_(nullptr)
	{
		key_ = EVP_PKEY_new();
	}

	PkiDsaKey::~PkiDsaKey(void)
	{
		if (key_ == nullptr) {
			EVP_PKEY_free (key_);
			key_ = nullptr;
		}
	}

	bool
	PkiDsaKey::createKey(uint32_t bits)
	{
		int resultCode;

		// create random buffer
		unsigned char buffer[32];
		resultCode = RAND_bytes(buffer, 32);
		if (resultCode != 1) {
			openSSLError();
			return false;
		}

		// added random buffer to DSA key
		DSA dsaKey;
		resultCode = DSA_generate_parameters_ex(&dsaKey, bits, buffer, 32, nullptr, nullptr, nullptr);
		if (resultCode != 1) {
			openSSLError();
			return false;
		}

		// generate DSA key
		resultCode = DSA_generate_key(&dsaKey);
		if (resultCode != 1) {
			openSSLError();
			return false;
		}

	    resultCode = EVP_PKEY_set1_DSA(key_, &dsaKey);
	    if (resultCode != 1) {
	    	openSSLError();
	    	return false;
	    }

	    return true;
	}

	bool
	PkiDsaKey::getPublicKey(PkiPublicKey& publicKey)
	{
		return publicKey.publicKey(key_);
	}

	bool
	PkiDsaKey::getPrivateKey(PkiPrivateKey& privateKey)
	{
		privateKey.privateKey(key_);
		return true;
	}

	bool
	PkiDsaKey::setPublicKey(PkiPublicKey& publicKey)
	{
		key_ = publicKey.publicKey();
		return true;
	}

	bool
	PkiDsaKey::setPrivateKey(PkiPrivateKey& privateKey)
	{
		key_ = privateKey.privateKey();
		return true;
	}

	bool
	PkiDsaKey::writePEMFile(const std::string& fileName, const std::string& password)
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

        DSA *dsaKey = EVP_PKEY_get1_DSA(key_);
        if (!dsaKey) {
        	openSSLError();
        	BIO_free (bioPem);
        	return false;
        }

        // store private key
        resultCode = PEM_write_bio_DSAPrivateKey(bioPem, dsaKey, 0, 0, 0, 0, 0);
        if (!resultCode) {
            openSSLError();
            DSA_free(dsaKey);
            BIO_free (bioPem);
            return false;
        }

        DSA_free(dsaKey);
        BIO_free(bioPem);
		return true;
	}

	bool
	PkiDsaKey::readPEMFile(const std::string& fileName, const std::string& password)
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

        DSA* dsaKey = nullptr;
        // load private key unencrypted
        dsaKey = PEM_read_bio_DSAPrivateKey(bioPem, 0, nullptr, nullptr);
        if (dsaKey == nullptr) {
            openSSLError();
            BIO_free (bioPem);
            return false;
        }

        resultCode = EVP_PKEY_assign_RSA(key_, dsaKey);
        if (!resultCode) {
        	openSSLError();
        	BIO_free (bioPem);
        	return false;
        }

        BIO_free(bioPem);
		return true;
	}

}




