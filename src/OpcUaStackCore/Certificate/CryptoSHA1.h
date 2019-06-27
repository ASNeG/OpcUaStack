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

#ifndef __OpcUaStackCore_CryptoSHA1_h__
#define __OpcUaStackCore_CryptoSHA1_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"
#include "OpcUaStackCore/Certificate/OpenSSLError.h"

namespace OpcUaStackCore
{

	class DLLEXPORT CryptoSHA1
	: public OpenSSLError
	{
	  public:
		CryptoSHA1(void);
		virtual ~CryptoSHA1(void);

		void isLogging(bool isLogging);
		bool isLogging(void);

		OpcUaStatusCode sha1(
		    char*      plainTextBuf,	 	// [in]  plain text to encrypt
		    uint32_t   plainTextLen,   	 	// [in]  length of plain text to encrypt
		    char*      digestTextBuf, 		// [out] digest text
		    uint32_t   digestTextLen  		// [out] length of the digest text - must be 160 Bits
		);

		OpcUaStatusCode sha160(
		    char*      plainTextBuf,	 	// [in]  plain text to encrypt
		    uint32_t   plainTextLen,   	 	// [in]  length of plain text to encrypt
		    char*      digestTextBuf, 		// [out] digest text
		    uint32_t   digestTextLen  		// [out] length of the digest text - must be 160 Bits
		);

		OpcUaStatusCode sha224(
		    char*      plainTextBuf,	 	// [in]  plain text to encrypt
		    uint32_t   plainTextLen,   	 	// [in]  length of plain text to encrypt
		    char*      digestTextBuf, 		// [out] digest text
		    uint32_t   digestTextLen  		// [out] length of the digest text - must be 224 Bits
		);

		OpcUaStatusCode sha256(
		    char*      plainTextBuf,	 	// [in]  plain text to encrypt
		    uint32_t   plainTextLen,   	 	// [in]  length of plain text to encrypt
		    char*      digestTextBuf, 		// [out] digest text
		    uint32_t   digestTextLen  		// [out] length of the digest text - must be 256 Bits
		);

		OpcUaStatusCode sha384(
		    char*      plainTextBuf,	 	// [in]  plain text to encrypt
		    uint32_t   plainTextLen,   	 	// [in]  length of plain text to encrypt
		    char*      digestTextBuf, 		// [out] digest text
		    uint32_t   digestTextLen  		// [out] length of the digest text - must be 384 Bits
		);

		OpcUaStatusCode sha512(
		    char*      plainTextBuf,	 	// [in]  plain text to encrypt
		    uint32_t   plainTextLen,   	 	// [in]  length of plain text to encrypt
		    char*      digestTextBuf, 		// [out] digest text
		    uint32_t   digestTextLen  		// [out] length of the digest text - must be 512 Bits
		);

	  private:
		bool isLogging_;
	};
}

#endif
