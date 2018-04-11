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
#include "OpcUaStackCore/Certificate/Random.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ContextPSH256
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ContextPSH256::ContextPSH256(void)
	: context_()
	, secretLen_(0)
	, seedLen_(0)
	{
	}

	ContextPSH256::~ContextPSH256(void)
	{
	}

	void
	ContextPSH256::set(MemoryBuffer& secret, MemoryBuffer& seed)
	{
		seedLen_ = seed.memLen();
		secretLen_ = secret.memLen();

		context_.resize(32 + seedLen_ + secretLen_);
		memcpy(context_.memBuf() + 32, seed.memBuf(), seedLen_);
		memcpy(context_.memBuf() + 32 + seedLen_, secret.memBuf(), secretLen_);
	}

	uint32_t
	ContextPSH256::aLen(void)
	{
		return 32;
	}

	uint32_t
	ContextPSH256::seedLen(void)
	{
		return seedLen_;
	}

	uint32_t
	ContextPSH256::secretLen(void)
	{
		return secretLen_;
	}

	char*
	ContextPSH256::a(void)
	{
		return context_.memBuf();
	}

	char*
	ContextPSH256::seed(void)
	{
		return context_.memBuf() + 32;
	}

	char*
	ContextPSH256::secret(void)
	{
		return context_.memBuf() + 32 + seedLen_;
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
	Random::getPSH256Context(
		MemoryBuffer& secret,
		MemoryBuffer& seed,
		ContextPSH256& ctx
	)
	{
		// create context
		ctx.set(secret, seed);

	    // A(0) = seed
	    // A(i) = HMAC_SHA256(secret, A(i-1))
	    // Calculate A(1) = HMAC_SHA256(secret, seed)
		// Calculate A(2) = HMAC_SHA256(secret, A(1))
		// ...
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
	Random::hashGeneratePSH256(
		ContextPSH256& ctx,
		MemoryBuffer& hash
	)
	{

	    /* Calculate P_SHA256(n) = HMAC_SHA256(secret, A(n)+seed) */
	    HMAC(
	        EVP_sha256(),
			(const unsigned char*)ctx.secret(),
			ctx.secretLen(),
	        (const unsigned char*)ctx.a(),
			ctx.aLen() + ctx.seedLen(),
			(unsigned char*)hash.memBuf(),
			(unsigned int*)nullptr
		);

	    /* Calculate A(n) = HMAC_SHA256(secret, A(n-1)) */
	    HMAC(
	        EVP_sha256(),
			(const unsigned char*)ctx.secret(),
			ctx.secretLen(),
	        (const unsigned char*)ctx.a(),
			ctx.aLen() + ctx.seedLen(),
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

		uint32_t iterations = key.memLen()/32 + ((key.memLen()%32)?1:0);
		MemoryBuffer buffer(iterations*32);

		ContextPSH256 ctx;
		statusCode = getPSH256Context(secret, seed, ctx);
		if (statusCode != Success) return statusCode;

		for (uint32_t idx = 0; idx < iterations; idx++) {
			// FIXME: todo
		}

		return Success;
	}

}
