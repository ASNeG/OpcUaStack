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

#ifndef __OpcUaStackCore_CryptoRSA_h__
#define __OpcUaStackCore_CryptoRSA_h__

#include "OpcUaStackCore/Certificate/OpenSSLError.h"
#include "OpcUaStackCore/Certificate/PublicKey.h"
#include "OpcUaStackCore/Certificate/PrivateKey.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"

namespace OpcUaStackCore
{

	class DLLEXPORT CryptoRSA
	: public OpenSSLError
	{
	  public:
		CryptoRSA(void);
		virtual ~CryptoRSA(void);

		void isLogging(bool isLogging);
		bool isLogging(void);

		OpcUaStatusCode publicEncrypt(
		    char*      plainTextBuf,	 	// [in]  plain text to encrypt
		    uint32_t   plainTextLen,   	 	// [in]  length of plain text to encrypt
		    PublicKey* publicKey,		 	// [in]  public key used to encrypt the plain text
		    int16_t    padding,          	// [in]  padding scheme used for filling empty bytes after encryption
		    char*      encryptedTextBuf, 	// [out] encrypted text
		    uint32_t*  encryptedTextLen  	// [out] length of the encryped text
		);

		OpcUaStatusCode privateDecrypt(
			char*       encryptedTextBuf, 	// [in]  encrypted text to decrypt
			uint32_t    encryptedTextLen, 	// [in]  length of the encryped text to decrypt
			PrivateKey* privateKey,		 	// [in]  private key used to decrypt the decrypted text
			int16_t     padding,          	// [in]  padding scheme used for filling empty bytes after encryption
		    char*       plainTextBuf,	 	// [out] plain text
		    uint32_t*   plainTextLen   	 	// [out] length of plain text
		);

		OpcUaStatusCode privateSign(
			char*       plainTextBuf,	 	// [in]  plain text to sign
			uint32_t    plainTextLen,  	 	// [in]  length of plain text to sign
			PrivateKey* privateKey,		 	// [in]  private key used to sign the plain text
		    int32_t     digest,				// [in]  ...
		    char*       signTextBuf,	 	// [out] sign text
		    uint32_t*   signTextLen   	 	// [out] length of sign text
		);

		OpcUaStatusCode publicVerify(
			char*       plainTextBuf,	 	// [in]  plain text to verify
			uint32_t    plainTextLen,  	 	// [in]  length of plain text to verify
			PublicKey*  publicKey,		 	// [in]  public key used to verify the plain text
		    int32_t     digest,				// [in]  ...
		    char*       signTextBuf,	 	// [out] verify text
		    uint32_t    signTextLen   	 	// [out] length of verify text
		);

	  private:
		bool isLogging_;

	};
}

#endif
