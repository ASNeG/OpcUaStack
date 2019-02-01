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

#ifndef __OpcUaStackCore_SecureChannelSecuritySettings_h__
#define __OpcUaStackCore_SecureChannelSecuritySettings_h__

#include "OpcUaStackCore/Certificate/CryptoBase.h"
#include "OpcUaStackCore/Certificate/SecurityKeySet.h"
#include "OpcUaStackCore/Certificate/CertificateChain.h"

namespace OpcUaStackCore
{

	class DLLEXPORT SecureChannelSecuritySettings
	{
	  public:
		SecureChannelSecuritySettings(void);
		~SecureChannelSecuritySettings(void);

		bool isOwnEncryptionEnabled(void);
		bool isOwnSignatureEnabled(void);
		OpcUaByteString& ownCertificateThumbprint(void);
		OpcUaByteString& ownSecurityPolicyUri(void);
		CertificateChain& ownCertificateChain(void);
		MemoryBuffer& ownNonce(void);

		bool isPartnerEncryptionEnabled(void);
		bool isPartnerSignatureEnabled(void);
		OpcUaByteString& partnerCertificateThumbprint(void);
		OpcUaByteString& partnerSecurityPolicyUri(void);
		CertificateChain& partnerCertificateChain(void);
		MemoryBuffer& partnerNonce(void);

		// *************************************************************
		void cryptoBase(CryptoBase::SPtr& cryptoBase);
		CryptoBase::SPtr& cryptoBase(void);

		SecurityKeySet& securityKeySetClient(void);
		SecurityKeySet& securityKeySetServer(void);

	  private:
		OpcUaByteString ownCertificateThumbprint_;
		OpcUaByteString ownSecurityPolicyUri_;
		CertificateChain ownCertificateChain_;
		MemoryBuffer ownNonce_;

		OpcUaByteString partnerCertificateThumbprint_;
		OpcUaByteString partnerSecurityPolicyUri_;
		CertificateChain partnerCertificateChain_;
		MemoryBuffer partnerNonce_;




		// *************************************************************
		CryptoBase::SPtr cryptoBase_;

		SecurityKeySet securityKeySetClient_;
		SecurityKeySet securityKeySetServer_;
	};

}

#endif
