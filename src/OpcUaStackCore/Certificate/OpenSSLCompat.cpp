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

#include "OpcUaStackCore/Certificate/OpenSSLCompat.h"

namespace OpcUaStackCore
{
	RSA *EVP_PKEY_get0_RSA(EVP_PKEY *pkey)
	{
		if (pkey->type != EVP_PKEY_RSA) {
			return NULL;
		}
		return pkey->pkey.rsa;
	}

	int EVP_PKEY_up_ref(EVP_PKEY *pkey)
	{
		CRYPTO_add (&pkey->references, 1, CRYPTO_LOCK_EVP_PKEY);
		return 1;
	}
}
