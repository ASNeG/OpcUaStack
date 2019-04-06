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

#ifndef __OpcUaStackCore_CryptoBase_h__
#define __OpcUaStackCore_CryptoBase_h__

#include <boost/shared_ptr.hpp>
#include <map>
#include <string>
#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaBaseEnums.h"
#include "OpcUaStackCore/BuildInTypes/SecurityPolicy.h"
#include "OpcUaStackCore/Certificate/PrivateKey.h"
#include "OpcUaStackCore/Certificate/PublicKey.h"
#include "OpcUaStackCore/Certificate/CryptoAES.h"
#include "OpcUaStackCore/Certificate/SecurityKeySet.h"

namespace OpcUaStackCore
{

	class DLLEXPORT EnryptionAlgs
	{
	  public:
		static const uint32_t AES_128_CBC_Id;
		static const uint32_t AES_256_CBC_Id;
		static const uint32_t RSA_PKCS1_V15_Id;
		static const uint32_t RSA_OAEP_Id;
		static const uint32_t DES3_Id;

		static std::string AES_128_CBC_Name;
		static std::string AES_256_CBC_Name;
		static std::string RSA_PKCS1_V15_Name;
		static std::string RSA_OAEP_Name;
		static std::string DES3_Name;

		static uint32_t uriToEncryptionAlg(const std::string& uri);
		static std::string encryptAlgToUri(uint32_t encryptAlg);
	};

	class DLLEXPORT SignatureAlgs
	{
	  public:
		static const uint32_t RSA_PKCS1_V15_SHA1_Id;
		static const uint32_t RSA_PKCS1_V15_SHA256_Id;
		static const uint32_t HMAC_SHA1_Id;
		static const uint32_t HMAC_SHA256_Id;
		static const uint32_t RSA_PKCS1_OAEP_SHA1_Id;
		static const uint32_t RSA_PKCS1_OAEP_SHA256_Id;

		static std::string RSA_PKCS1_V15_SHA1_Name;
		static std::string RSA_PKCS1_V15_SHA256_Name;
		static std::string HMAC_SHA1_Name;
		static std::string HMAC_SHA256_Name;
		static std::string RSA_PKCS1_OAEP_SHA1_Name;
		static std::string RSA_PKCS1_OAEP_SHA256_Name;

		static uint32_t uriToSignatureAlg(const std::string& uri);
		static std::string signatureAlgToUri(uint32_t signatureAlg);
	};

	class DLLEXPORT CryptoBase
	{
	  public:
		typedef boost::shared_ptr<CryptoBase> SPtr;
		typedef std::map<SecurityPolicy::Enum, CryptoBase::SPtr> Map;

		CryptoBase(void);
		virtual ~CryptoBase(void);

		void securityPolicy(const std::string& securityPolicy);
		std::string& securityPolicy(void);
		void isLogging(bool isLogging);
		bool isLogging(void);

		void nonceLen(uint32_t nonceLen);
		uint32_t nonceLen(void);
		void symmetricKeyLen(int32_t symmetricKeyLen);
		int32_t symmetricKeyLen(void);
		void asymmetricKeyLen(int32_t asymmetricKeyLen);
		int32_t asymmetricKeyLen(void);
		void minimumAsymmetricKeyLen(uint32_t minimumAsymmetricKeyLen);
		uint32_t minimumAsymmetricKeyLen(void);
		void maximumAsymmetricKeyLen(uint32_t maximumAsymmetricKeyLen);
		uint32_t maximumAsymmetricKeyLen(void);
		void derivedEncryptionKeyLen(uint32_t derivedEncryptionKeyLen);
		uint32_t derivedEncryptionKeyLen(void);
		void derivedSignatureKeyLen(uint32_t derivedSignatureKeyLen);
		uint32_t derivedSignatureKeyLen(void);
		void signatureDataLen(uint32_t signatureDataLen);
		uint32_t signatureDataLen(void);
		void asymmetricSignatureAlgorithmId(uint32_t asymmetricSignatureAlgorithmId);
		uint32_t asymmetricSignatureAlgorithmId(void);
		void asymmetricEncryptionAlgorithmId(uint32_t asymmetricEncryptionAlgorithmId);
		uint32_t asymmetricEncryptionAlgorithmId(void);
		void symmetricSignatureAlgorithmId(uint32_t symmetricSignatureAlgorithmId);
		uint32_t symmetricSignatureAlgorithmId(void);
		void symmetricEncryptionAlgorithmId(uint32_t symmetricEncryptionAlgorithmId);
		uint32_t symmetricEncryptionAlgorithmId(void);

		virtual OpcUaStatusCode getAsymmetricEncryptionBlockSize(
			PublicKey& publicKey,
			uint32_t* plainTextBlockSize,
			uint32_t* cryptTextBlockSize
		) = 0;

		virtual OpcUaStatusCode getAsymmetricSignatureBlockSize(
			PublicKey& publicKey,
			uint32_t* signTextBlockSize
		) = 0;

		virtual OpcUaStatusCode getSymmetricEncryptionBlockSize(
			uint32_t* plainTextBlockSize,
			uint32_t* cryptTextBlockSize
		) = 0;

		virtual OpcUaStatusCode getSymmetricSignatureBlockSize(
			uint32_t* signTextBlockSize
		) = 0;

		virtual OpcUaStatusCode asymmetricKeyLen(
			PublicKey& publicKey,
			uint32_t* asymmetricKeyLen
		) = 0;

		virtual OpcUaStatusCode asymmetricKeyLen(
			PrivateKey& privateKey,
			uint32_t* asymmetricKeyLen
		) = 0;

		virtual OpcUaStatusCode asymmetricDecrypt(
		    char*       	encryptedTextBuf,
			uint32_t		encryptedTextLen,
			PrivateKey&		privateKey,
			char*       	plainTextBuf,
			uint32_t*		plainTextLen
		) = 0;

		virtual OpcUaStatusCode asymmetricEncrypt(
		    char*       	plainTextBuf,
			uint32_t		plainTextLen,
			PublicKey&		publicKey,
			char*       	encryptedTextBuf,
			uint32_t*		encryptedTextLen
		) = 0;

		virtual OpcUaStatusCode symmetricDecrypt(
			char*       	encryptedTextBuf,
			uint32_t		encryptedTextLen,
			AESKey&	   		aesKey,
			IV&		   		iv,
			char*      		plainTextBuf,
			uint32_t*   	plainTextLen
		) = 0;

		virtual OpcUaStatusCode symmetricEncrypt(
			char*       	plainTextBuf,
			uint32_t		plainTextLen,
			AESKey&	   		aesKey,
			IV&		   		iv,
			char*      		encryptedTextBuf,
			uint32_t*   	encryptedTextLen
		) = 0;

		virtual OpcUaStatusCode asymmetricSign(
		    char*       	plainTextBuf,
			uint32_t		plainTextLen,
			PrivateKey&		privateKey,
			char*       	signTextBuf,
			uint32_t*		signTextLen
		) = 0;

		virtual OpcUaStatusCode asymmetricVerify(
		    char*       	plainTextBuf,
			uint32_t		plainTextLen,
			PublicKey&		publicKey,
			char*       	signTextBuf,
			uint32_t		signTextLen
		) = 0;

		virtual OpcUaStatusCode symmetricSign(
		    char*       	plainTextBuf,
			uint32_t		plainTextLen,
			MemoryBuffer&	key,
			char*       	signTextBuf,
			uint32_t*		signTextLen
		) = 0;

		virtual OpcUaStatusCode symmetricVerify(
		    char*       	plainTextBuf,
			uint32_t		plainTextLen,
			MemoryBuffer&	key,
			char*       	signTextBuf,
			uint32_t		signTextLen
		) = 0;

		virtual OpcUaStatusCode deriveKey(
			MemoryBuffer& secret,			// remote nonce
			MemoryBuffer& seed,				// local nonce
			MemoryBuffer& key				// len = sig key + enc key + iv
		) = 0;

		OpcUaStatusCode deriveChannelKeyset(
		    MemoryBuffer& clientNonce,
			MemoryBuffer& serverNonce,
		    SecurityKeySet& clientSecurityKeySet,
		    SecurityKeySet& serverSecurityKeySet
		);

		OpcUaStatusCode deriveChannelKeyset(
		    MemoryBuffer& remoteNonce,
			MemoryBuffer& localNonce,
		    SecurityKeySet& securityKeySet
		);

	  private:
		std::string securityPolicy_;
		bool isLogging_;

		uint32_t nonceLen_;
		int32_t symmetricKeyLen_;
		int32_t asymmetricKeyLen_;
		uint32_t minimumAsymmetricKeyLen_;
		uint32_t maximumAsymmetricKeyLen_;
		uint32_t derivedEncryptionKeyLen_;
		uint32_t derivedSignatureKeyLen_;
		uint32_t signatureDataLen_;
		uint32_t asymmetricSignatureAlgorithmId_;
		uint32_t asymmetricEncryptionAlgorithmId_;
		uint32_t symmetricSignatureAlgorithmId_;
		uint32_t symmetricEncryptionAlgorithmId_;

	};

}

#endif
