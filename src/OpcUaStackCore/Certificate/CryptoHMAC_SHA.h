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

#ifndef __OpcUaStackCore_CryptoHMAC_SHA_h__
#define __OpcUaStackCore_CryptoHMAC_SHA_h__

#include "OpcUaStackCore/Base/MemoryBuffer.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"
#include "OpcUaStackCore/Certificate/OpenSSLError.h"

namespace OpcUaStackCore
{

	class DLLEXPORT CryptoHMAC_SHA
	: public OpenSSLError
	{
	  public:
		CryptoHMAC_SHA(void);
		virtual ~CryptoHMAC_SHA(void);

		void isLogging(bool isLogging);
		bool isLogging(void);

		OpcUaStatusCode generate_HMAC_SHA1(
			char*       	plainTextBuf,	 	// [in]  plain text to sign
			uint32_t    	plainTextLen,  	 	// [in]  length of plain text to sign
			MemoryBuffer& 	key,		 		// [in]  key
		    char*       	signTextBuf,	 	// [out] sign text
		    uint32_t*   	signTextLen   	 	// [out] length of sign text
		);

		OpcUaStatusCode generate_HMAC_SHA1_160(
			char*       	plainTextBuf,	 	// [in]  plain text to sign
			uint32_t    	plainTextLen,  	 	// [in]  length of plain text to sign
			MemoryBuffer& 	key,		 		// [in]  key
		    char*       	signTextBuf,	 	// [out] sign text
		    uint32_t*   	signTextLen   	 	// [out] length of sign text
		);

		OpcUaStatusCode generate_HMAC_SHA2_224(
			char*       	plainTextBuf,	 	// [in]  plain text to sign
			uint32_t    	plainTextLen,  	 	// [in]  length of plain text to sign
			MemoryBuffer& 	key,		 		// [in]  key
		    char*       	signTextBuf,	 	// [out] sign text
		    uint32_t*   	signTextLen   	 	// [out] length of sign text
		);

		OpcUaStatusCode generate_HMAC_SHA2_256(
			char*       	plainTextBuf,	 	// [in]  plain text to sign
			uint32_t    	plainTextLen,  	 	// [in]  length of plain text to sign
			MemoryBuffer& 	key,		 		// [in]  key
		    char*       	signTextBuf,	 	// [out] sign text
		    uint32_t*   	signTextLen   	 	// [out] length of sign text
		);

		OpcUaStatusCode generate_HMAC_SHA2_384(
			char*       	plainTextBuf,	 	// [in]  plain text to sign
			uint32_t    	plainTextLen,  	 	// [in]  length of plain text to sign
			MemoryBuffer& 	key,		 		// [in]  key
		    char*       	signTextBuf,	 	// [out] sign text
		    uint32_t*   	signTextLen   	 	// [out] length of sign text
		);

		OpcUaStatusCode generate_HMAC_SHA2_512(
			char*       	plainTextBuf,	 	// [in]  plain text to sign
			uint32_t    	plainTextLen,  	 	// [in]  length of plain text to sign
			MemoryBuffer& 	key,		 		// [in]  key
		    char*       	signTextBuf,	 	// [out] sign text
		    uint32_t*   	signTextLen   	 	// [out] length of sign text
		);

	  private:
		bool isLogging_;
	};
}

#endif
