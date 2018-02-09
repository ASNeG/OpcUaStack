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

#ifndef __OpcUaStackCore_PrivateKey_h__
#define __OpcUaStackCore_PrivateKey_h__

#include <openssl/x509.h>

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Certificate/OpenSSLError.h"
#include "OpcUaStackCore/Certificate/KeyType.h"

namespace OpcUaStackCore
{

    typedef int PasswordCallback(char *buf, int size, int rwflag, void *u);

	class DLLEXPORT PrivateKey
	: public OpenSSLError
	{
	  public:
		PrivateKey(void);
		PrivateKey(EVP_PKEY *pKey);
		PrivateKey(const PrivateKey& copy);
		~PrivateKey(void);

		PrivateKey& operator=(const PrivateKey& copy);
		operator const EVP_PKEY*() const;
		bool toDER(char* buf, uint32_t& bufLen) const;
		bool fromDER (char* buf, uint32_t bufLen, KeyType keyType);
		bool fromPEM (char* buf, uint32_t bufLen, const char *password, PasswordCallback* passwordCallback = nullptr, void *data = nullptr);

	  private:
		EVP_PKEY *privateKey_;
	};

}

#endif
