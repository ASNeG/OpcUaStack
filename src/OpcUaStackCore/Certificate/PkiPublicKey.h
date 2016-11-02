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

#ifndef __OpcUaStackCore_PkiPublicKey_h__
#define __OpcUaStackCore_PkiPublicKey_h__

#include <openssl/x509.h>
#include <stdint.h>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Certificate/PkiError.h"


namespace OpcUaStackCore
{

	class DLLEXPORT PkiPublicKey
	: public PkiError
	{
	  public:
		typedef enum {
			KT_None,
			KT_RSA,
			KT_DSA
		} KeyType;

		PkiPublicKey(void);
		~PkiPublicKey(void);

		KeyType keyType(void);
		EVP_PKEY* publicKey(void);
		bool publicKey(EVP_PKEY* publicKey);
		bool toDER(char* bufDER, uint32_t* lengthDER);
		bool fromDER(char* bufDER, uint32_t lengthDER);
		bool getPublicKeyAlgorithm(std::string& publicKeyAlgorithm);

		bool toHexStringPublicKey(std::string& hexString);

	  private:
		X509_PUBKEY* publicKey_;
	};

}

#endif
