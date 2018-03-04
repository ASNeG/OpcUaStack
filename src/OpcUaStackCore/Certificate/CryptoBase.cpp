/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/Certificate/CryptoBase.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// EncryptionAlgs
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
    uint32_t EnryptionAlgs::AES_128_CBC_Id = 1;
    uint32_t EnryptionAlgs::AES_256_CBC_Id = 2;
    uint32_t EnryptionAlgs::RSA_PKCS1_V15_Id = 3;
    uint32_t EnryptionAlgs::RSA_OAEP_Id = 4;
    uint32_t EnryptionAlgs::DES3_Id = 5;

    std::string EnryptionAlgs::AES_128_CBC_Name = "AES-128-CBC";
    std::string EnryptionAlgs::AES_256_CBC_Name = "AES-256-CBC";
    std::string EnryptionAlgs::RSA_PKCS1_V15_Name = "RSA-PKCS-#1-V1.5";
    std::string EnryptionAlgs::RSA_OAEP_Name = "RSA-OAEP";
    std::string EnryptionAlgs::DES3_Name = "3DES";

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SignatureAlgs
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	uint32_t SignatureAlgs::RSA_PKCS1_V15_SHA1_Id = 6;
	uint32_t SignatureAlgs::RSA_PKCS1_V15_SHA256_Id = 7;
	uint32_t SignatureAlgs::HMAC_SHA1_Id = 8;
	uint32_t SignatureAlgs::HMAC_SHA256_Id = 9;
	uint32_t SignatureAlgs::RSA_PKCS1_OAEP_SHA1_Id = 10;
	uint32_t SignatureAlgs::RSA_PKCS1_OAEP_SHA256_Id = 11;

	std::string SignatureAlgs::RSA_PKCS1_V15_SHA1_Name = "RSA-PKCS-#1-V1.5-SHA1";
	std::string SignatureAlgs::RSA_PKCS1_V15_SHA256_Name = "RSA-PKCS-#1-V1.5-SHA256";
	std::string SignatureAlgs::HMAC_SHA1_Name = "HMAC-SHA1";
	std::string SignatureAlgs::HMAC_SHA256_Name = "HMAC-SHA256";
	std::string SignatureAlgs::RSA_PKCS1_OAEP_SHA1_Name = "RSA-PKCS-#1-OAEP-SHA1";
	std::string SignatureAlgs::RSA_PKCS1_OAEP_SHA256_Name = "RSA-PKCS-#1-OAEP-SHA256";

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// CryptoBase
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	CryptoBase::CryptoBase(void)
	: securityPolicy_("")
	, symmetricKeyLen_(-1)
	, minimumAsymmetricKeyLen_(0)
	, maximumAsymmetricKeyLen_(0)
	, derivedEncryptionKeyLen_(0)
	, derivedSignatureKeyLen_(0)
	, signatureDataLen_(0)
	, asymmetricSignatureAlgorithmId_(0)
	, asymmetricEncryptionAlgorithmId_(0)
	, symmetricSignatureAlgorithmId_(0)
	, symmetricEncryptionAlgorithmId_(0)
	{
	}

	CryptoBase::~CryptoBase(void)
	{
	}

	void
	CryptoBase::securityPolicy(const std::string& securityPolicy)
	{
		securityPolicy_ = securityPolicy;
	}

	std::string&
	CryptoBase::securityPolicy(void)
	{
		return securityPolicy_;
	}

	void
	CryptoBase::symmetricKeyLen(int32_t symmetricKeyLen)
	{
		symmetricKeyLen_ = symmetricKeyLen;
	}

	int32_t
	CryptoBase::symmetricKeyLen(void)
	{
		return symmetricKeyLen_;
	}

	void
	CryptoBase::minimumAsymmetricKeyLen(uint32_t minimumAsymmetricKeyLen)
	{
		minimumAsymmetricKeyLen_ = minimumAsymmetricKeyLen;
	}

	uint32_t
	CryptoBase::minimumAsymmetricKeyLen(void)
	{
		return minimumAsymmetricKeyLen_;
	}

	void
	CryptoBase::maximumAsymmetricKeyLen(uint32_t maximumAsymmetricKeyLen)
	{
		maximumAsymmetricKeyLen_ = maximumAsymmetricKeyLen;
	}

	uint32_t
	CryptoBase::maximumAsymmetricKeyLen(void)
	{
		return maximumAsymmetricKeyLen_;
	}

	void
	CryptoBase::derivedEncryptionKeyLen(uint32_t derivedEncryptionKeyLen)
	{
		derivedEncryptionKeyLen_ = derivedEncryptionKeyLen;
	}

	uint32_t
	CryptoBase::derivedEncryptionKeyLen(void)
	{
		return derivedEncryptionKeyLen_;
	}

	void
	CryptoBase::derivedSignatureKeyLen(uint32_t derivedSignatureKeyLen)
	{
		derivedSignatureKeyLen_ = derivedSignatureKeyLen;
	}

	uint32_t
	CryptoBase::derivedSignatureKeyLen(void)
	{
		return derivedSignatureKeyLen_;
	}

	void
	CryptoBase::signatureDataLen(uint32_t signatureDataLen)
	{
		signatureDataLen_ = signatureDataLen;
	}

	uint32_t
	CryptoBase::signatureDataLen(void)
	{
		return signatureDataLen_;
	}

	void
	CryptoBase::asymmetricSignatureAlgorithmId(uint32_t asymmetricSignatureAlgorithmId)
	{
		asymmetricSignatureAlgorithmId_ = asymmetricSignatureAlgorithmId;
	}

	uint32_t
	CryptoBase::asymmetricSignatureAlgorithmId(void)
	{
		return asymmetricSignatureAlgorithmId_;
	}

	void
	CryptoBase::asymmetricEncryptionAlgorithmId(uint32_t asymmetricEncryptionAlgorithmId)
	{
		asymmetricEncryptionAlgorithmId_ = asymmetricEncryptionAlgorithmId;
	}

	uint32_t
	CryptoBase::asymmetricEncryptionAlgorithmId(void)
	{
		return asymmetricEncryptionAlgorithmId_;
	}

	void
	CryptoBase::symmetricSignatureAlgorithmId(uint32_t symmetricSignatureAlgorithmId)
	{
		symmetricSignatureAlgorithmId_ = symmetricSignatureAlgorithmId;
	}

	uint32_t
	CryptoBase::symmetricSignatureAlgorithmId(void)
	{
		return symmetricSignatureAlgorithmId_;
	}

	void
	CryptoBase::symmetricEncryptionAlgorithmId(uint32_t symmetricEncryptionAlgorithmId)
	{
		symmetricEncryptionAlgorithmId_ = symmetricEncryptionAlgorithmId;
	}

	uint32_t
	CryptoBase::symmetricEncryptionAlgorithmId(void)
	{
		return symmetricEncryptionAlgorithmId_;
	}

}
