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
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Certificate/PkiPublicKey.h"

namespace OpcUaStackCore
{

	PkiPublicKey::PkiPublicKey(void)
	: PkiError()
	, publicKey_(nullptr)
	{
		publicKey_ = X509_PUBKEY_new();
	}

	PkiPublicKey::~PkiPublicKey(void)
	{
		if (publicKey_ != nullptr) {
			X509_PUBKEY_free(publicKey_);
			publicKey_ = nullptr;
		}
	}

	PkiPublicKey::KeyType
	PkiPublicKey::keyType(void)
	{
	    EVP_PKEY *key = nullptr;
	    key = X509_PUBKEY_get (publicKey_);
	    if (!key) {
	    	openSSLError();
	    	return KT_None;
	    }
	    uint32_t keyType = key->type;
	    EVP_PKEY_free(key);

	    switch(key->type)
	    {
	        case EVP_PKEY_RSA: return KT_RSA;
	        case EVP_PKEY_DSA: return KT_DSA;
	        default: return KT_None;
	    }
	}

	EVP_PKEY*
	PkiPublicKey::publicKey(void)
	{
	    EVP_PKEY *key = 0;
	    key = X509_PUBKEY_get(publicKey_);
	    if (!key) {
	    	openSSLError();
	    	return nullptr;
	    }
	    return key;
	}

	bool
	PkiPublicKey::publicKey(EVP_PKEY* publicKey)
	{
	    int resultCode = X509_PUBKEY_set(&publicKey_, publicKey);
	    if (!resultCode) {
	    	openSSLError();
	    	return false;
	    }
	    return true;
	}

	bool
	PkiPublicKey::toDER(char* bufDER, uint32_t* lengthDER)
	{
		int length = i2d_X509_PUBKEY(publicKey_, 0);
		if (length < 0) {
			openSSLError();
			return false;
		}
		if ((uint32_t)length > *lengthDER) {
			openSSLError("external DER buffer to small");
			return false;
		}

		i2d_X509_PUBKEY(publicKey_, (unsigned char**)&bufDER);
		*lengthDER = length;

		return true;
	}

	bool
	PkiPublicKey::fromDER(char* bufDER, uint32_t lengthDER)
	{
		publicKey_ = d2i_X509_PUBKEY ( 0, ( const unsigned char** ) &bufDER, lengthDER );
		if (!publicKey_) {
			openSSLError();
		    return false;
		}

		return true;
	}

}

