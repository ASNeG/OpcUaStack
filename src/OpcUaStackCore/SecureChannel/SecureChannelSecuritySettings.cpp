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

#include "OpcUaStackCore/SecureChannel/SecureChannelSecuritySettings.h"

namespace OpcUaStackCore
{

	SecureChannelSecuritySettings::SecureChannelSecuritySettings(void)
	: cryptoBase_()
	, partnerNonce_()
	, ownNonce_()
	, partnerSecurityKeySet_()
	, ownSecurityKeySet_()
	{
	}

	void
	SecureChannelSecuritySettings::cryptoBase(CryptoBase::SPtr& cryptoBase)
	{
		cryptoBase_ = cryptoBase;
	}

	SecureChannelSecuritySettings::~SecureChannelSecuritySettings(void)
	{
	}

	CryptoBase::SPtr&
	SecureChannelSecuritySettings::cryptoBase(void)
	{
		return cryptoBase_;
	}

	EndpointDescription::SPtr&
	SecureChannelSecuritySettings::endpointDescription(void)
	{
		return endpointDescription_;
	}

	bool
	SecureChannelSecuritySettings::isOwnEncryptionEnabled(void)
	{
		return ownCertificateChain_.size() > 0;

	}

	bool
	SecureChannelSecuritySettings::isOwnSignatureEnabled(void)
	{
		return partnerCertificateThumbprint_.exist();
	}

	OpcUaByteString&
	SecureChannelSecuritySettings::ownCertificateThumbprint(void)
	{
		return ownCertificateThumbprint_;
	}

	OpcUaByteString&
	SecureChannelSecuritySettings::ownSecurityPolicyUri(void)
	{
		return ownSecurityPolicyUri_;
	}

	CertificateChain&
	SecureChannelSecuritySettings::ownCertificateChain(void)
	{
		return ownCertificateChain_;
	}

	MemoryBuffer&
	SecureChannelSecuritySettings::ownNonce(void)
	{
		return ownNonce_;
	}

	SecurityKeySet&
	SecureChannelSecuritySettings::ownSecurityKeySet(void)
	{
		return ownSecurityKeySet_;
	}


	bool
	SecureChannelSecuritySettings::isPartnerEncryptionEnabled(void)
	{
		return ownCertificateThumbprint_.exist();
	}

	bool
	SecureChannelSecuritySettings::isPartnerSignatureEnabled(void)
	{
		return partnerCertificateChain_.size() > 0;
	}

	OpcUaByteString&
	SecureChannelSecuritySettings::partnerCertificateThumbprint(void)
	{
		return partnerCertificateThumbprint_;
	}

	OpcUaByteString&
	SecureChannelSecuritySettings::partnerSecurityPolicyUri(void)
	{
		return partnerSecurityPolicyUri_;
	}

	CertificateChain&
	SecureChannelSecuritySettings::partnerCertificateChain(void)
	{
		return partnerCertificateChain_;
	}

	MemoryBuffer&
	SecureChannelSecuritySettings::partnerNonce(void)
	{
		return partnerNonce_;
	}

	SecurityKeySet&
	SecureChannelSecuritySettings::partnerSecurityKeySet(void)
	{
		return partnerSecurityKeySet_;
	}

}


