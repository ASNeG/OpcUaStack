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

#ifndef __OpcUaStackCore_CryptoOpenSSLBASIC256_h__
#define __OpcUaStackCore_CryptoOpenSSLBASIC256_h__

#include "OpcUaStackCore/Certificate/CryptoBase.h"

namespace OpcUaStackCore
{

	class DLLEXPORT CryptoOpenSSLBASIC256
	: public CryptoBase
	{
	  public:
		CryptoOpenSSLBASIC256(void);
		virtual ~CryptoOpenSSLBASIC256(void);

		virtual OpcUaStatusCode getAsymmetricEncryptionBlockSize(
			PublicKey& publicKey,
			uint32_t* plainTextBlockSize,
			uint32_t* cryptTextBlockSize
		);

		virtual OpcUaStatusCode getAsymmetricSignatureBlockSize(
			PublicKey& publicKey,
			uint32_t* signTextBlockSize
		);

		virtual OpcUaStatusCode getSymmetricEncryptionBlockSize(
			uint32_t* plainTextBlockSize,
			uint32_t* cryptTextBlockSize
		);

		virtual OpcUaStatusCode getSymmetricSignatureBlockSize(
			uint32_t* signTextBlockSize
		);

		virtual OpcUaStatusCode asymmetricKeyLen(
			PublicKey& publicKey,
			uint32_t* asymmetricKeyLen
		);

		virtual OpcUaStatusCode asymmetricKeyLen(
			PrivateKey& privateKey,
			uint32_t* asymmetricKeyLen
		);

		virtual OpcUaStatusCode asymmetricDecrypt(
		    char*       	encryptedTextBuf,
			uint32_t		encryptedTextLen,
			PrivateKey&		privateKey,
			char*       	plainTextBuf,
			uint32_t*		plainTextLen
		);

		virtual OpcUaStatusCode asymmetricEncrypt(
		    char*       	plainTextBuf,
			uint32_t		plainTextLen,
			PublicKey&		publicKey,
			char*       	encryptedTextBuf,
			uint32_t*		encryptedTextLen
		);

		virtual OpcUaStatusCode symmetricDecrypt(
			char*       	encryptedTextBuf,
			uint32_t		encryptedTextLen,
			AESKey&	   		aesKey,
			IV&		   		iv,
			char*      		plainTextBuf,
			uint32_t*   	plainTextLen
		);

		virtual OpcUaStatusCode symmetricEncrypt(
			char*       	plainTextBuf,
			uint32_t		plainTextLen,
			AESKey&	   		aesKey,
			IV&		   		iv,
			char*      		encryptedTextBuf,
			uint32_t*   	encryptedTextLen
		);

		virtual OpcUaStatusCode asymmetricSign(
		    char*       	plainTextBuf,
			uint32_t		plainTextLen,
			PrivateKey&		privateKey,
			char*       	signTextBuf,
			uint32_t*		signTextLen
		);

		virtual OpcUaStatusCode asymmetricVerify(
		    char*       	plainTextBuf,
			uint32_t		plainTextLen,
			PublicKey&		publicKey,
			char*       	signTextBuf,
			uint32_t		signTextLen
		);

		virtual OpcUaStatusCode symmetricSign(
		    char*       	plainTextBuf,
			uint32_t		plainTextLen,
			MemoryBuffer&	key,
			char*       	signTextBuf,
			uint32_t*		signTextLen
		);

		virtual OpcUaStatusCode symmetricVerify(
		    char*       	plainTextBuf,
			uint32_t		plainTextLen,
			MemoryBuffer&	key,
			char*       	signTextBuf,
			uint32_t		signTextLen
		);

		virtual OpcUaStatusCode deriveKey(
			MemoryBuffer& secret,			// remote nonce
			MemoryBuffer& seed,				// local nonce
			MemoryBuffer& key				// len = sig key + enc key + iv
		);

	};

}

#endif
