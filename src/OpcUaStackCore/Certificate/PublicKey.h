/*
   Copyright 2018-2019 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/Certificate/OpenSSLError.h"
#include "OpcUaStackCore/Certificate/CertificateEnums.h"

namespace OpcUaStackCore
{

	class DLLEXPORT PublicKey
	: public OpenSSLError
	{
	  public:
		PublicKey(void);
		PublicKey(EVP_PKEY *pKey);
		PublicKey(const PublicKey& copy);
		virtual ~PublicKey(void);

		PublicKey& operator=(const PublicKey& copy);
		operator EVP_PKEY*(void);
		uint32_t keySizeInBytes(void) const;
		uint32_t keySize(void) const;
		KeyType keyType(void) const;

		bool fromDER(const char* buf, uint32_t bufLen);
		bool toDER(char* buf, uint32_t& bufLen);

	  private:
		X509_PUBKEY *publicKey_;
	};

}

#endif
