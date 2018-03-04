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

#include <OpcUaStackCore/Certificate/CryptoOpenSSLBASIC256.h>

namespace OpcUaStackCore
{

	CryptoOpenSSLBASIC256::CryptoOpenSSLBASIC256(void)
	:CryptoBase()
	{
		securityPolicy("http://opcfoundation.org/UA/SecurityPolicy#Basic256");

		symmetricKeyLen(32);
		minimumAsymmetricKeyLen(128);
		maximumAsymmetricKeyLen(512);
		derivedEncryptionKeyLen(32);
		derivedSignatureKeyLen(24);
		signatureDataLen(20);
		asymmetricSignatureAlgorithmId(SignatureAlgs::RSA_PKCS1_OAEP_SHA1_Id);
		asymmetricEncryptionAlgorithmId(EnryptionAlgs::RSA_OAEP_Id);
		symmetricSignatureAlgorithmId(SignatureAlgs::HMAC_SHA1_Id);
		symmetricEncryptionAlgorithmId(EnryptionAlgs::AES_256_CBC_Id);
	}

	CryptoOpenSSLBASIC256::~CryptoOpenSSLBASIC256(void)
	{
	}

}
