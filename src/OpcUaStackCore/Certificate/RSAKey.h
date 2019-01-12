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

#ifndef __OpcUaStackCore_RSAKey_h__
#define __OpcUaStackCore_RSAKey_h__

#include "OpcUaStackCore/Certificate/OpenSSLError.h"
#include "OpcUaStackCore/Certificate/PrivateKey.h"
#include "OpcUaStackCore/Certificate/PublicKey.h"

#include <openssl/x509.h>

namespace OpcUaStackCore
{

	typedef int PasswordCallback(char *buf, int size, int rwflag, void *u);

	class DLLEXPORT RSAKey
	: public OpenSSLError
	{
	  public:
		RSAKey(void);
		RSAKey(EVP_PKEY *pKey);
		RSAKey(uint32_t bits);
		RSAKey(const RSAKey &copy);
		virtual ~RSAKey(void);

		RSAKey& operator=(const RSAKey &copy);

	    PrivateKey privateKey(void) const;
	    PublicKey publicKey(void) const;

	    bool toDER(char* buf, uint32_t& bufLen) const;
	    bool toPEM(char* buf, uint32_t& bufLen, const char* password) const;

	    bool fromPEM(char* buf, uint32_t bufLen, const char* password, PasswordCallback *passwordCallback = 0, void *data = 0);

	    bool isValid(void);
	    bool checkKeyPair(void);
	    bool checkKeyPair(const PublicKey& publicKey, const PrivateKey& privateKey);

	  private:
		EVP_PKEY *pKey_;
	};

}

#endif
