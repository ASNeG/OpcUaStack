/*
   Copyright 2018-2021 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/SecureChannel/SecureChannelKeys.h"
#include "OpcUaStackCore/StandardDataTypes/EndpointDescription.h"

namespace OpcUaStackCore
{

	class DLLEXPORT SecureChannelSecuritySettings
	{
	  public:
		SecureChannelSecuritySettings(void);
		~SecureChannelSecuritySettings(void);

		void cryptoBase(CryptoBase::SPtr& cryptoBase);
		CryptoBase::SPtr& cryptoBase(void);
		EndpointDescription::SPtr& endpointDescription(void);

		SecureChannelKeys& secureChannelKeys(void);

		OpcUaByteString& ownCertificateThumbprint(void);
		void ownSecurityPolicyUri(const OpcUaByteString& ownSecurityPolicyUri);
		const OpcUaByteString& ownSecurityPolicyUri(void);
		void ownSecurityPolicy(SecurityPolicy::Enum ownSecurityPolicy);
		SecurityPolicy::Enum ownSecurityPolicy(void);
		void ownSecurityMode(MessageSecurityMode::Enum ownSecurityMode);
		MessageSecurityMode::Enum ownSecurityMode(void);
		CertificateChain& ownCertificateChain(void);
		MemoryBuffer& ownNonce(void);
		//SecurityKeySet& ownSecurityKeySet(void);

		OpcUaByteString& partnerCertificateThumbprint(void);
		void partnerSecurityPolicyUri(const OpcUaByteString& partnerSecurityPolicyUri);
		const OpcUaByteString& partnerSecurityPolicyUri(void);
		void partnerSecurityPolicy(SecurityPolicy::Enum ownSecurityPolicy);
		SecurityPolicy::Enum partnerSecurityPolicy(void);
		void partnerSecurityMode(MessageSecurityMode::Enum partnerSecurityMode);
		MessageSecurityMode::Enum partnerSecurityMode(void);
		CertificateChain& partnerCertificateChain(void);
		MemoryBuffer& partnerNonce(void);
		//SecurityKeySet& partnerSecurityKeySet(void);

	  private:
		CryptoBase::SPtr cryptoBase_;
		EndpointDescription::SPtr endpointDescription_;

		SecureChannelKeys secureChannelKeys_;

		OpcUaByteString ownCertificateThumbprint_;
		OpcUaByteString ownSecurityPolicyUri_;
		MessageSecurityMode::Enum ownSecurityMode_ = MessageSecurityMode::EnumNone;
		CertificateChain ownCertificateChain_;
		MemoryBuffer ownNonce_;

		OpcUaByteString partnerCertificateThumbprint_;
		OpcUaByteString partnerSecurityPolicyUri_;
		MessageSecurityMode::Enum partnerSecurityMode_ = MessageSecurityMode::EnumNone;
		CertificateChain partnerCertificateChain_;
		MemoryBuffer partnerNonce_;
	};

}

#endif
