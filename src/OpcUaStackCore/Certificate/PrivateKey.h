/*
   Copyright 2018-2023 Kai Huebl (kai@huebl-sgh.de)

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

#include <boost/shared_ptr.hpp>

#include <openssl/x509.h>

#include "OpcUaStackCore/Base/MemoryBuffer.h"
#include "OpcUaStackCore/Certificate/BIOCtx.h"
#include "OpcUaStackCore/Certificate/OpenSSLError.h"
#include "OpcUaStackCore/Certificate/CertificateEnums.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaByteString.h"

namespace OpcUaStackCore
{

    typedef int PasswordCallback(char *buf, int size, int rwflag, void *u);

	class DLLEXPORT PrivateKey
	: public OpenSSLError
	{
	  public:
    	typedef boost::shared_ptr<PrivateKey> SPtr;

		PrivateKey(void);
		PrivateKey(EVP_PKEY *pKey);
		PrivateKey(const PrivateKey& copy);
		~PrivateKey(void);

		uint32_t keySizeInBytes(void) const;
		uint32_t keySize(void) const;
		KeyType keyType(void) const;

		PrivateKey& operator=(const PrivateKey& copy);
		operator EVP_PKEY*(void);
		bool toDER(char* buf, uint32_t& bufLen) const;
		bool toDERBuf(OpcUaByteString& byteString) const;
		bool fromDER(char* buf, uint32_t bufLen, KeyType keyType);

		bool fromPEM(
			BIOCtx& bioCtx,
			const char *password,
			PasswordCallback* passwordCallback = nullptr,
			void *data = nullptr
		);
		bool fromPEM(
			MemoryBuffer& pemBuf,
			const char *password,
			PasswordCallback* passwordCallback = nullptr,
			void *data = nullptr
		);
		bool toPEM(
			BIOCtx& bioCtx,
			const char* password
		);
	    bool toPEM(
	    	MemoryBuffer& pemBuf,
			const char* password
		);

		bool toPEMFile(const std::string& fileName, const char* password);
		bool fromPEMFile(const std::string& fileName, const char* password, PasswordCallback* passwordCallback = nullptr, void *data = nullptr);

	  private:
		EVP_PKEY *privateKey_;
	};

}

#endif
