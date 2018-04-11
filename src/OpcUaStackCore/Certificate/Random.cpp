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

	Random::Random(void)
	: OpenSSLError()
	{
	}

	Random::~Random(void)
	{
	}

	OpcUaStatusCode getPSH256Context(
		MemoryBuffer& secret,
		MemoryBuffer& seed,
		MemoryBuffer& ctx
	)
	{
		// create context
		ctx.resize(32 + seed.memLen() + secret.memLen());
		memcpy(ctx.memBuf() + 32, seed.memBuf(), seed.memLen());
		memcpy(ctx.memBuf() + 32 + seed.memLen(), secret.memBuf(), secret.memLen());

	    // A(0) = seed
	    // A(i) = HMAC_SHA256(secret, A(i-1))
	    // Calculate A(1) = HMAC_SHA256(secret, seed)
		HMAC(
		    EVP_sha256(),
			(const unsigned char*)secret.memBuf(),
			secret.memLen(),
			(const unsigned char*)seed.memBuf(),
			seed.memLen(),
			(unsigned char*)ctx.memBuf(),
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
		// check parameter
		if (key.memLen() == 0 || key.memLen() > 512) {
			addError("key parameter error in keyDerivePSHA256");
			return BadInvalidArgument;
		}

		return Success;
	}

}
