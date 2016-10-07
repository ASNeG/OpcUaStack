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
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Certificate/PkiPrivateKey.h"

namespace OpcUaStackCore
{

	PkiPrivateKey::PkiPrivateKey(void)
	: PkiError()
	, privateKey_(nullptr)
	{
		privateKey_ = EVP_PKEY_new();
	}

	PkiPrivateKey::~PkiPrivateKey(void)
	{
		if (privateKey_ != nullptr) {
			EVP_PKEY_free(privateKey_);
		}
	}

	void
	PkiPrivateKey::privateKey(EVP_PKEY* privateKey)
	{
	    CRYPTO_add(&privateKey->references, 1, CRYPTO_LOCK_EVP_PKEY);
	    privateKey_ = privateKey;
	}

	EVP_PKEY*
	PkiPrivateKey::privateKey(void)
	{
	    return privateKey_;
	}

}

