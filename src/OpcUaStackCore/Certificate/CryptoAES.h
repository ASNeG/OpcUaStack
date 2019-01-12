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

#ifndef __OpcUaStackCore_CryptoAES_h__
#define __OpcUaStackCore_CryptoAES_h__

#include "OpcUaStackCore/Base/MemoryBuffer.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"
#include "OpcUaStackCore/Certificate/OpenSSLError.h"

#define IV_MAX_LENGTH 32

namespace OpcUaStackCore
{

	typedef MemoryBuffer AESKey;
	typedef MemoryBuffer IV;

	class DLLEXPORT CryptoAES
	: public OpenSSLError
	{
	  public:
		CryptoAES(void);
		virtual ~CryptoAES(void);

		void isLogging(bool isLogging);
		bool isLogging(void);

		OpcUaStatusCode encryptCBC128(
		    char*      plainTextBuf,	 	// [in]  plain text to encrypt
		    uint32_t   plainTextLen,   	 	// [in]  length of plain text to encrypt
		    AESKey&	   aesKey,			    // [in]  key used to encrypt the plain text
			IV&		   iv,					// [in]  initial vector
		    char*      encryptedTextBuf, 	// [out] encrypted text
		    uint32_t*  encryptedTextLen  	// [out] length of the encryped text
		);

		OpcUaStatusCode encryptCBC256(
		    char*      plainTextBuf,	 	// [in]  plain text to encrypt
		    uint32_t   plainTextLen,   	 	// [in]  length of plain text to encrypt
		    AESKey&	   aesKey,			    // [in]  key used to encrypt the plain text
			IV&		   iv,					// [in]  initial vector
		    char*      encryptedTextBuf, 	// [out] encrypted text
		    uint32_t*  encryptedTextLen  	// [out] length of the encryped text
		);

		OpcUaStatusCode encryptCBC(
		    char*      plainTextBuf,	 	// [in]  plain text to encrypt
		    uint32_t   plainTextLen,   	 	// [in]  length of plain text to encrypt
		    AESKey&	   aesKey,			    // [in]  key used to encrypt the plain text
			IV&		   iv,					// [in]  initial vector
		    char*      encryptedTextBuf, 	// [out] encrypted text
		    uint32_t*  encryptedTextLen  	// [out] length of the encryped text
		);

		OpcUaStatusCode decryptCBC128(
			char*      encryptedTextBuf, 	// [in]  encrypted text to decrypt
			uint32_t   encryptedTextLen, 	// [in]  length of the encryped text to decrypt
			AESKey&	   aesKey,			    // [in]  key used to decrypt the decrypted text
			IV&		   iv,					// [in]  initial vector
		    char*      plainTextBuf,	 	// [out] plain text
		    uint32_t*  plainTextLen   	 	// [out] length of plain text
		);

		OpcUaStatusCode decryptCBC256(
			char*      encryptedTextBuf, 	// [in]  encrypted text to decrypt
			uint32_t   encryptedTextLen, 	// [in]  length of the encryped text to decrypt
			AESKey&	   aesKey,			    // [in]  key used to decrypt the decrypted text
			IV&		   iv,					// [in]  initial vector
		    char*      plainTextBuf,	 	// [out] plain text
		    uint32_t*  plainTextLen   	 	// [out] length of plain text
		);

		OpcUaStatusCode decryptCBC(
			char*      encryptedTextBuf, 	// [in]  encrypted text to decrypt
			uint32_t   encryptedTextLen, 	// [in]  length of the encryped text to decrypt
			AESKey&	   aesKey,			    // [in]  key used to decrypt the decrypted text
			IV&		   iv,					// [in]  initial vector
		    char*      plainTextBuf,	 	// [out] plain text
		    uint32_t*  plainTextLen   	 	// [out] length of plain text
		);

	  private:
		bool isLogging_;
	};
}

#endif
