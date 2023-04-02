/*
   Copyright 2018-2023 Kai Huebl (kai@huebl-sgh.de)

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

#include <iostream>
#include "OpcUaStackCore/Certificate/PublicKey.h"

namespace OpcUaStackCore
{

	PublicKey::PublicKey(void)
	: OpenSSLError()
	, publicKey_(nullptr)
	{
		publicKey_ = X509_PUBKEY_new();
		if (publicKey_ == nullptr) {
			addError("create public key error in constructor");
			return;
		}
	}

	PublicKey::PublicKey(EVP_PKEY *pKey)
	: OpenSSLError()
	, publicKey_(nullptr)
	{
		assert(pKey != nullptr);

		publicKey_ = X509_PUBKEY_new();
		if (publicKey_ == nullptr) {
			addError("create public key error in key constructor");
			return;
		}

		int result = X509_PUBKEY_set(&publicKey_, pKey);
		if (!result) {
			addOpenSSLError();
		}
	}

	PublicKey::PublicKey(const PublicKey& copy)
	: OpenSSLError()
	, publicKey_(nullptr)
	{
		if (const_cast<PublicKey*>(&copy)->isError()) {
			addError("create public key error in copy constructor - source key error");
			return;
		}

		publicKey_ = X509_PUBKEY_new();
		if (publicKey_ == nullptr) {
			addError("create public key error in copy constructor - allocate memory error");
			return;
		}

		EVP_PKEY *pKey = X509_PUBKEY_get(copy.publicKey_);
		if (pKey==NULL) {
		    addOpenSSLError();
		    return;
		}

		int result = X509_PUBKEY_set(&publicKey_, pKey);
		if (!result) {
			addOpenSSLError();
		}

		EVP_PKEY_free(pKey);
	}

	PublicKey::~PublicKey(void)
	{
		if (publicKey_ != nullptr) {
			X509_PUBKEY_free(publicKey_);
			publicKey_ = nullptr;
		}
	}

	PublicKey&
	PublicKey::operator=(const PublicKey& copy)
	{
		if (const_cast<PublicKey*>(&copy)->isError()) {
			addError("public key error in assign operator - source key error");
			return *this;
		}

		EVP_PKEY *pKey = X509_PUBKEY_get(copy.publicKey_);
		if (pKey == nullptr) {
		   addOpenSSLError();
		   return *this;
		}

		int result = X509_PUBKEY_set(&publicKey_, pKey);
		if (!result) {
		    addOpenSSLError();
		}

		EVP_PKEY_free(pKey);

		return *this;
	}

	PublicKey::operator EVP_PKEY*(void)
	{
	    EVP_PKEY* key = nullptr;

	    key = X509_PUBKEY_get(publicKey_);
	    if (!key) {
	    	const_cast<PublicKey*>(this)->addOpenSSLError();
	    }

	    return key;
	}

	uint32_t
	PublicKey::keySizeInBytes(void) const
	{
		return keySize() / 8;
	}

	uint32_t
	PublicKey::keySize(void) const
	{
	    int32_t result = -1;

	    EVP_PKEY* pKey = X509_PUBKEY_get(publicKey_);
	    if (!pKey) {
	    	const_cast<PublicKey*>(this)->addOpenSSLError();
	    	return result;
	    }

	    result = EVP_PKEY_bits(pKey);

	    EVP_PKEY_free(pKey);

	    return result;
	}

	KeyType
	PublicKey::keyType(void) const
	{
	    KeyType keyType = KeyType_Unknown;

	    EVP_PKEY* pKey = X509_PUBKEY_get(publicKey_);
	    if (!pKey) {
	    	const_cast<PublicKey*>(this)->addOpenSSLError();
	    	return keyType;
	    }

	    switch(EVP_PKEY_id(pKey))
	    {
	        case EVP_PKEY_RSA: keyType = KeyType_RSA; break;
	        case EVP_PKEY_DSA: keyType = KeyType_DSA; break;
	        default: break;
	    }

	    EVP_PKEY_free(pKey);

	    return keyType;
	}

	bool
	PublicKey::fromDER(const char* buf, uint32_t bufLen)
	{
		const char* ptr = buf;
	    publicKey_ = d2i_X509_PUBKEY(0, (const unsigned char**)&ptr, bufLen);
	    if (publicKey_  == nullptr) {
	        addOpenSSLError();
	    	return false;
	    }

	    return true;
	}

	bool
	PublicKey::toDER(char* buf, uint32_t& bufLen)
	{
	    int32_t length = i2d_X509_PUBKEY(publicKey_, 0);
	    if (length < 0) {
	    	addOpenSSLError();
	    	return false;
	    }

	    if (length > bufLen) {
	    	addError("buffer length is too short");
	    	return false;
	    }

	    bufLen = length;
	    char* ptr = buf;
	    i2d_X509_PUBKEY(publicKey_, (unsigned char**)&ptr);

	    return true;
	}

	bool
	PublicKey::toPEMBuf(MemoryBuffer& memoryBuffer)
	{
		BIOCtx bioCtx;
		if (!toPEMBuf(bioCtx)) {
			addError("call toPEMBuf error");
			return false;
		}

		// Get data length and data pointer
	    char* data = nullptr;
	    uint32_t length = BIO_get_mem_data(bioCtx.bio(), &data);

		// Create certificate data buffer
	    memoryBuffer.resize(length);
		if (memoryBuffer.memLen() <= 0) {
			addError("PEM buffer empty");
			return false;
		}
	    memcpy(memoryBuffer.memBuf(), data, memoryBuffer.memLen());

	    return true;
	}

	bool
	PublicKey::toPEMBuf(BIOCtx& bioCtx)
	{
		// Check parameter
		if (publicKey_ == nullptr) {
			addError("csertificate is empty");
			return false;
		}

	    int result = PEM_write_bio_PUBKEY(bioCtx.bio(), X509_PUBKEY_get(publicKey_));
	    if (result == 0) {
	        addOpenSSLError();
	        addError("call PEM_write_bio_PUBKEY error");
	        return false;
	    }

		return true;
	}

	bool
	PublicKey::fromPEMBuf(MemoryBuffer& memoryBuffer)
	{
		BIOCtx bioCtx(memoryBuffer);
		return fromPEMBuf(bioCtx);
	}

	bool
	PublicKey::fromPEMBuf(BIOCtx& bioCtx)
	{
		if (publicKey_ != nullptr) {
			X509_PUBKEY_free(publicKey_);
			publicKey_ = nullptr;
		}

	    // Create certificate
		EVP_PKEY* evp_pkey = PEM_read_bio_PUBKEY(bioCtx.bio(), 0, 0, 0);
		if (evp_pkey == nullptr) {
			addOpenSSLError();
			addError("call PEM_read_bio_PUBKEY error");
			return false;
		}

		int result = X509_PUBKEY_set(&publicKey_, evp_pkey);
		if (!result) {
		    addOpenSSLError();
		}

		EVP_PKEY_free(evp_pkey);

		return true;
	}

}
