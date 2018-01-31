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

#ifndef __OpcUaStackCore_PublicKey_h__
#define __OpcUaStackCore_PublicKey_h__

#include <openssl/x509.h>

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Certificate/OpenSSLError.h"

namespace OpcUaStackCore
{

    typedef enum
    {
        KeyType_RSA        = EVP_PKEY_RSA,
        KeyType_DSA        = EVP_PKEY_DSA,
        KeyType_Unknown    = EVP_PKEY_NONE
    } KeyType;

	class DLLEXPORT PublicKey
	: public OpenSSLError
	{
	  public:
		PublicKey(void);
		PublicKey(EVP_PKEY *pKey);
		PublicKey(const PublicKey& copy);
		~PublicKey(void);

		PublicKey& operator=(const PublicKey& copy);
		operator EVP_PKEY*(void) const;
		uint32_t keySize(void) const;
		KeyType keyType(void) const;

		bool fromDER(const char* buf, uint32_t bufLen);
		bool toDER(char* buf, uint32_t& bufLen);

	  private:
		X509_PUBKEY *publicKey_;
	};

}

#endif
