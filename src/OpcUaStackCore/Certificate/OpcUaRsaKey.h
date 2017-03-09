/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_OpcUaRsaKey_h__
#define __OpcUaStackCore_OpcUaRsaKey_h__

#include <openssl/x509.h>
#include <stdint.h>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Certificate/PkiError.h"
#include "OpcUaStackCore/Certificate/PkiPublicKey.h"
#include "OpcUaStackCore/Certificate/PkiPrivateKey.h"

namespace OpcUaStackCore
{

	class DLLEXPORT OpcUaRsaKey
	: public PkiError
	{
	  public:
		OpcUaRsaKey(void);
		~OpcUaRsaKey(void);

		bool createKey(uint32_t bits);
		bool getPublicKey(PkiPublicKey& publicKey);
		bool getPrivateKey(PkiPrivateKey& privateKey);
		bool setPublicKey(PkiPublicKey& publicKey);
		bool setPrivateKey(PkiPrivateKey& privateKey);
		uint32_t keyLength(void);
		bool toHexStringPublicKey(std::string& hexString);

		uint32_t modulus(void);

		bool writePEMFile(const std::string& fileName, const std::string& password);
		bool readPEMFile(const std::string& fileName, const std::string& password);

	  private:
		EVP_PKEY *key_;
	};

}

#endif
