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

#ifndef __OpcUaStackCore_CryptoManager_h__
#define __OpcUaStackCore_CryptoManager_h__

#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT CryptoManager
	{
	  public:
		CryptoManager(void);
		~CryptoManager(void);

	};

#if 0
    OpcUa_StringA                               Name;
    OpcUa_ProviderHandle                        Handle;
    OpcUa_Int32                                 SymmetricKeyLength;
    OpcUa_UInt32                                MinimumAsymmetricKeyLength;
    OpcUa_UInt32                                MaximumAsymmetricKeyLength;
    OpcUa_UInt32                                DerivedEncryptionKeyLength;
    OpcUa_UInt32                                DerivedSignatureKeyLength;
    OpcUa_UInt32                                SignatureDataLength;
    OpcUa_UInt32                                AsymmetricSignatureAlgorithmId;
    OpcUa_UInt32                                AsymmetricEncryptionAlgorithmId;
    OpcUa_UInt32                                SymmetricSignatureAlgorithmId;
    OpcUa_UInt32                                SymmetricEncryptionAlgorithmId;

    OpcUa_Crypto_PfnGenerateKey*                GenerateKey;
    OpcUa_Crypto_PfnDeriveKey*                  DeriveKey;
    OpcUa_Crypto_PfnDeriveChannelKeysets*       DeriveChannelKeysets;
    OpcUa_Crypto_PfnGenerateAsymmetricKeypair*  GenerateAsymmetricKeypair;
    OpcUa_Crypto_PfnGetAsymmetricKeyLength*     GetAsymmetricKeyLength;
    OpcUa_Crypto_PfnCreateCertificate*          CreateCertificate;
    OpcUa_Crypto_PfnGetPrivateKeyFromCert*      GetPrivateKeyFromCert;
    OpcUa_Crypto_PfnGetPublicKeyFromCert*       GetPublicKeyFromCert;
    OpcUa_Crypto_PfnGetSignatureFromCert*       GetSignatureFromCert;
    OpcUa_Crypto_PfnGetCertificateThumbprint*   GetCertificateThumbprint;
    OpcUa_Crypto_PfnSymmetricEncrypt*           SymmetricEncrypt;
    OpcUa_Crypto_PfnSymmetricDecrypt*           SymmetricDecrypt;
    OpcUa_Crypto_PfnAsymmetricEncrypt*          AsymmetricEncrypt;
    OpcUa_Crypto_PfnAsymmetricDecrypt*          AsymmetricDecrypt;
    OpcUa_Crypto_PfnSymmetricSign*              SymmetricSign;
    OpcUa_Crypto_PfnSymmetricVerify*            SymmetricVerify;
    OpcUa_Crypto_PfnAsymmetricSign*             AsymmetricSign;
    OpcUa_Crypto_PfnAsymmetricVerify*           AsymmetricVerify;
#endif

}

#endif
