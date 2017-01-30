/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSet/EndpointDescription.h"

namespace OpcUaStackCore
{

	EndpointDescription::EndpointDescription(void)
	: endpointUrl_()
	, applicationDescription_(constructSPtr<ApplicationDescription>())
	, serverCertificate_()
	, messageSecurityMode_()
	, securityPolicyUri_()
	, userIdentityTokens_(constructSPtr<UserTokenPolicyArray>())
	, transportProfileUri_()
	, securityLevel_()
	{
	}


	EndpointDescription::~EndpointDescription(void)
	{
	}

	void 
	EndpointDescription::endpointUrl(const std::string& endpointUrl)
	{
		endpointUrl_ = endpointUrl;
	}

	std::string 
	EndpointDescription::endpointUrl(void) const
	{
		return endpointUrl_.value();
	}

	void 
	EndpointDescription::applicationDescription(const ApplicationDescription::SPtr applicationDescription)
	{
		applicationDescription_ = applicationDescription;
	}

	ApplicationDescription::SPtr 
	EndpointDescription::applicationDescription(void) const
	{
		return applicationDescription_;
	}

	void 
	EndpointDescription::serverCertificate(const OpcUaByte* buf, OpcUaInt32 bufLen)
	{
		serverCertificate_.value(buf, bufLen);
	}

	void 
	EndpointDescription::serverCertificate(OpcUaByte** buf, OpcUaInt32* bufLen) const
	{
		serverCertificate_.value(buf, bufLen);
	}

	void 
	EndpointDescription::messageSecurityMode(const MessageSecurityMode messageSecurityMode)
	{
		messageSecurityMode_ = messageSecurityMode;
	}

	MessageSecurityMode 
	EndpointDescription::messageSecurityMode(void) const
	{
		return messageSecurityMode_;
	}

	void 
	EndpointDescription::securityPolicyUri(const std::string& securityPolicyUri)
	{
		securityPolicyUri_ = securityPolicyUri;
	}

	std::string 
	EndpointDescription::securityPolicyUri(void) const
	{
		return securityPolicyUri_.value();
	}

	void 
	EndpointDescription::userIdentityTokens(const UserTokenPolicyArray::SPtr userIdentityTokens)
	{
		userIdentityTokens_ = userIdentityTokens;
	}

	UserTokenPolicyArray::SPtr 
	EndpointDescription::userIdentityTokens(void) const
	{
		return userIdentityTokens_;
	}

	void 
	EndpointDescription::transportProfileUri(const std::string& transportProfileUri)
	{
		transportProfileUri_ = transportProfileUri;
	}

	std::string 
	EndpointDescription::transportProfileUri(void) const
	{
		return transportProfileUri_.value();
	}

	void 
	EndpointDescription::securityLevel(const OpcUaByte securityLevel)
	{
		securityLevel_ = securityLevel;
	}

	OpcUaByte 
	EndpointDescription::securityLevel(void) const
	{
		return securityLevel_;
	}

	void 
	EndpointDescription::opcUaBinaryEncode(std::ostream& os) const
	{
		endpointUrl_.opcUaBinaryEncode(os);
		applicationDescription_->opcUaBinaryEncode(os);
		serverCertificate_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)messageSecurityMode_);
		securityPolicyUri_.opcUaBinaryEncode(os);
		userIdentityTokens_->opcUaBinaryEncode(os);
		transportProfileUri_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, securityLevel_);
	}
	
	void 
	EndpointDescription::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaUInt32 messageSecurityMode;
		endpointUrl_.opcUaBinaryDecode(is);
		applicationDescription_->opcUaBinaryDecode(is);
		serverCertificate_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, messageSecurityMode);
		securityPolicyUri_.opcUaBinaryDecode(is);
		userIdentityTokens_->opcUaBinaryDecode(is);
		transportProfileUri_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, securityLevel_);
		messageSecurityMode_ = (MessageSecurityMode)messageSecurityMode;
	}

	void
	EndpointDescription::out(std::ostream& os)
	{
		os << "EndpointUrl="; endpointUrl_.out(os);
		os << ", ApplicationDescription={";  applicationDescription_->out(os); os << "}";
		os << ", ServerCertificate="; serverCertificate_.out(os);
		os << ", MessageSecurityMode=" << (uint32_t)messageSecurityMode_;
		os << ", SecurityPolicy="; securityPolicyUri_.out(os);
		//os << ", UserIdentityTokens=[" << *userIdentityTokens_ << "]";
		os << ", TransportProfileUri="; transportProfileUri_.out(os);
		os << ", SecurityLevel=" << (uint32_t)securityLevel_;
	}

}
