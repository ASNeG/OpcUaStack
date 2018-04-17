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

#include <openssl/rand.h>
#include <openssl/hmac.h>
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/Certificate/Random.h"


//
// P_SHA1(secret, seed) = HMAC_SHA1(secret, A(1) + seed) +
//						  HMAC_SHA1(secret, A(2) + seed) +
//                        HMAC_SHA1(secret, A(3) + seed) +
//                        ...
//
// A(0) = seed
// A(1) = HMAC_SHA1(secret, A(0))
// A(2) = HMAC_SHA1(secret, A(1))
// A(3) = HMAC_SHA1(secret, A(2))
// ...
//


namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ContextPSHA256
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ContextPSHA256::ContextPSHA256(void)
	: context_()
	, secretLen_(0)
	, seedLen_(0)
	{
	}

	ContextPSHA256::~ContextPSHA256(void)
	{
	}

	void
	ContextPSHA256::set(MemoryBuffer& secret, MemoryBuffer& seed)
	{
		seedLen_ = seed.memLen();
		secretLen_ = secret.memLen();

		context_.resize(32 + seedLen_ + secretLen_);
		memcpy(context_.memBuf() + 32, seed.memBuf(), seedLen_);
		memcpy(context_.memBuf() + 32 + seedLen_, secret.memBuf(), secretLen_);
	}

	uint32_t
	ContextPSHA256::aLen(void)
	{
		return 32;
	}

	uint32_t
	ContextPSHA256::seedLen(void)
	{
		return seedLen_;
	}

	uint32_t
	ContextPSHA256::secretLen(void)
	{
		return secretLen_;
	}

	char*
	ContextPSHA256::a(void)
	{
		return context_.memBuf();
	}

	char*
	ContextPSHA256::seed(void)
	{
		return context_.memBuf() + 32;
	}

	char*
	ContextPSHA256::secret(void)
	{
		return context_.memBuf() + 32 + seedLen_;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ContextPSHA1
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ContextPSHA1::ContextPSHA1(void)
	: context_()
	, secretLen_(0)
	, seedLen_(0)
	{
	}

	ContextPSHA1::~ContextPSHA1(void)
	{
	}

	void
	ContextPSHA1::set(MemoryBuffer& secret, MemoryBuffer& seed)
	{
		seedLen_ = seed.memLen();
		secretLen_ = secret.memLen();

		context_.resize(20 + seedLen_ + secretLen_);
		memcpy(context_.memBuf() + 20, seed.memBuf(), seedLen_);
		memcpy(context_.memBuf() + 20 + seedLen_, secret.memBuf(), secretLen_);
	}

	uint32_t
	ContextPSHA1::aLen(void)
	{
		return 20;
	}

	uint32_t
	ContextPSHA1::seedLen(void)
	{
		return seedLen_;
	}

	uint32_t
	ContextPSHA1::secretLen(void)
	{
		return secretLen_;
	}

	char*
	ContextPSHA1::a(void)
	{
		return context_.memBuf();
	}

	char*
	ContextPSHA1::seed(void)
	{
		return context_.memBuf() + 20;
	}

	char*
	ContextPSHA1::secret(void)
	{
		return context_.memBuf() + 20 + seedLen_;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// Random
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	Random::Random(void)
	: OpenSSLError()
	{
	}

	Random::~Random(void)
	{
	}

	OpcUaStatusCode
	Random::getPSHA256Context(
		MemoryBuffer& secret,
		MemoryBuffer& seed,
		ContextPSHA256& ctx
	)
	{
		// create context
		ctx.set(secret, seed);

		HMAC(
		    EVP_sha256(),
			(const unsigned char*)secret.memBuf(),
			secret.memLen(),
			(const unsigned char*)seed.memBuf(),
			seed.memLen(),
			(unsigned char*)ctx.a(),
			(unsigned int*)nullptr
		);

		return Success;
	}

	OpcUaStatusCode
	Random::getPSHA1Context(
		MemoryBuffer& secret,
		MemoryBuffer& seed,
		ContextPSHA1& ctx
	)
	{
		// create context
		ctx.set(secret, seed);

		HMAC(
		    EVP_sha1(),
			(const unsigned char*)secret.memBuf(),
			secret.memLen(),
			(const unsigned char*)seed.memBuf(),
			seed.memLen(),
			(unsigned char*)ctx.a(),
			(unsigned int*)nullptr
		);

		return Success;
	}

	OpcUaStatusCode
	Random::hashGeneratePSHA256(
		ContextPSHA256& ctx,
		char* hash
	)
	{
	    /* Calculate P_SHA256(n) = HMAC_SHA256(secret, A(n) + seed) */
	    HMAC(
	        EVP_sha256(),
			(const unsigned char*)ctx.secret(),
			ctx.secretLen(),
	        (const unsigned char*)ctx.a(),
			ctx.aLen() + ctx.seedLen(),
			(unsigned char*)hash,
			(unsigned int*)nullptr
		);

	    /* Calculate A(n) = HMAC_SHA256(secret, A(n-1)) */
	    HMAC(
	        EVP_sha256(),
			(const unsigned char*)ctx.secret(),
			ctx.secretLen(),
	        (const unsigned char*)ctx.a(),
			ctx.aLen(),
			(unsigned char*)ctx.a(),
			(unsigned int*)nullptr
		);

		return Success;
	}

	OpcUaStatusCode
	Random::hashGeneratePSHA1(
		ContextPSHA1& ctx,
		char* hash
	)
	{
	    /* Calculate P_SHA1(n) = HMAC_SHA1(secret, A(n-1) + seed) */
	    HMAC(
	        EVP_sha1(),
			(const unsigned char*)ctx.secret(),
			ctx.secretLen(),
	        (const unsigned char*)ctx.a(),
			ctx.aLen() + ctx.seedLen(),
			(unsigned char*)hash,
			(unsigned int*)nullptr
		);

	    /* Calculate A(n) = HMAC_SHA1(secret, A(n-1)) */
	    HMAC(
	        EVP_sha1(),
			(const unsigned char*)ctx.secret(),
			ctx.secretLen(),
	        (const unsigned char*)ctx.a(),
			ctx.aLen(),
			(unsigned char*)ctx.a(),
			(unsigned int*)nullptr
		);

		return Success;
	}

	OpcUaStatusCode
	Random::keyDerivePSHA256(
		MemoryBuffer& secret,			// remote nonce
	    MemoryBuffer& seed,				// local nonce
		MemoryBuffer& key				// output len = sig key + enc key + iv
	)
	{
		OpcUaStatusCode statusCode;

		// check parameter
		if (key.memLen() == 0 || key.memLen() > 512) {
			addError("key parameter error in keyDerivePSHA256");
			return BadInvalidArgument;
		}

		MemoryBuffer memoryBuffer;
		uint32_t iterations = key.memLen()/32 + ((key.memLen()%32)?1:0);
		memoryBuffer.resize(iterations*32);

		ContextPSHA256 ctx;
		statusCode = getPSHA256Context(secret, seed, ctx);
		if (statusCode != Success) return statusCode;

		for (uint32_t idx = 0; idx < iterations; idx++) {
			statusCode = hashGeneratePSHA256(ctx, memoryBuffer.memBuf() + (idx*32));
			if (statusCode != Success) return statusCode;
		}

		memcpy(key.memBuf(), memoryBuffer.memBuf(), key.memLen());

		return Success;
	}

	OpcUaStatusCode
	Random::keyDerivePSHA1(
		MemoryBuffer& secret,			// remote nonce
	    MemoryBuffer& seed,				// local nonce
		MemoryBuffer& key				// output len = sig key + enc key + iv
	)
	{
		OpcUaStatusCode statusCode;

		// check parameter
		if (key.memLen() == 0 || key.memLen() > 512) {
			addError("key parameter error in keyDerivePSHA256");
			return BadInvalidArgument;
		}

		MemoryBuffer memoryBuffer;
		uint32_t iterations = key.memLen()/20 + ((key.memLen()%20)?1:0);
		memoryBuffer.resize(iterations*20);

		ContextPSHA1 ctx;
		statusCode = getPSHA1Context(secret, seed, ctx);
		if (statusCode != Success) return statusCode;

		for (uint32_t idx = 0; idx < iterations; idx++) {
			statusCode = hashGeneratePSHA1(ctx, memoryBuffer.memBuf() + (idx*20));
			dumpHex(memoryBuffer);
			if (statusCode != Success) return statusCode;
		}

		std::cout << "..." << std::endl;
		memcpy(key.memBuf(), memoryBuffer.memBuf(), key.memLen());

		return Success;
	}

}
