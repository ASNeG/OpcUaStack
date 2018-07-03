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

#include "OpcUaStackCore/SecureChannel/SecureChannelSecuritySettings.h"

namespace OpcUaStackCore
{

	SecureChannelSecuritySettings::SecureChannelSecuritySettings(void)
	: cryptoBase_()
	, partnerCertificate_()
	, clientNonce_()
	, serverNonce_()
	, securityKeySetClient_()
	, securityKeySetServer_()
	{
	}

	SecureChannelSecuritySettings::~SecureChannelSecuritySettings(void)
	{
	}

	void
	SecureChannelSecuritySettings::cryptoBase(CryptoBase::SPtr& cryptoBase)
	{
		cryptoBase_ = cryptoBase;
	}

	CryptoBase::SPtr&
	SecureChannelSecuritySettings::cryptoBase(void)
	{
		return cryptoBase_;
	}

	void
	SecureChannelSecuritySettings::partnerCertificate(Certificate::SPtr& partnerCertificate)
	{
		partnerCertificate_ = partnerCertificate;
	}

	Certificate::SPtr&
	SecureChannelSecuritySettings::partnerCertificate(void)
	{
		return partnerCertificate_;
	}

	MemoryBuffer&
	SecureChannelSecuritySettings::clientNonce(void)
	{
		return clientNonce_;
	}

	MemoryBuffer&
	SecureChannelSecuritySettings::serverNonce(void)
	{
		return serverNonce_;
	}

	SecurityKeySet&
	SecureChannelSecuritySettings::securityKeySetClient(void)
	{
		return securityKeySetClient_;
	}

	SecurityKeySet&
	SecureChannelSecuritySettings::securityKeySetServer(void)
	{
		return securityKeySetServer_;
	}

}


