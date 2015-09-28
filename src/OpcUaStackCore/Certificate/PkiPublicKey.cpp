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
#include "OpcUaStackCore/Certificate/PkiPublicKey.h"

namespace OpcUaStackCore
{

	PkiPublicKey::PkiPublicKey(void)
	: publicKey_(nullptr)
	{
	}

	PkiPublicKey::~PkiPublicKey(void)
	{
	}

	EVP_PKEY*
	PkiPublicKey::publicKey(void)
	{
	    EVP_PKEY *pKey = 0;
	    pKey = X509_PUBKEY_get(publicKey_);
	    if (!pKey) {
	    	// FIXME: error handling
	    }
	    return pKey;
	}

}

