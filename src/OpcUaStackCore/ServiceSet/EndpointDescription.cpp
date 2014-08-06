#include "OpcUaStackCore/ServiceSet/EndpointDescription.h"

namespace OpcUaStackCore
{

	EndpointDescription::EndpointDescription(void)
	: endpointUrl_()
	, applicationDescription_()
	, serverCertificate_()
	, messageSecurityMode_()
	, securityPolicyUri_()
	, userIdentityTokens_()
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
		OpcUaStackCore::opcUaBinaryEncode(os, endpointUrl_);
		applicationDescription_->opcUaBinaryEncode(os);
		OpcUaStackCore::opcUaBinaryEncode(os, serverCertificate_);
		OpcUaStackCore::opcUaBinaryEncode(os, (OpcUaUInt32)messageSecurityMode_);
		OpcUaStackCore::opcUaBinaryEncode(os, securityPolicyUri_);
		userIdentityTokens_->opcUaBinaryEncode(os);
		OpcUaStackCore::opcUaBinaryEncode(os, securityLevel_);
	}
	
	void 
	EndpointDescription::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaUInt32 messageSecurityMode;
		OpcUaStackCore::opcUaBinaryDecode(is, endpointUrl_);
		applicationDescription_->opcUaBinaryDecode(is);
		OpcUaStackCore::opcUaBinaryDecode(is,serverCertificate_);
		OpcUaStackCore::opcUaBinaryDecode(is, messageSecurityMode);
		OpcUaStackCore::opcUaBinaryDecode(is, securityPolicyUri_);
		userIdentityTokens_->opcUaBinaryDecode(is);
		OpcUaStackCore::opcUaBinaryDecode(is, securityLevel_);
		messageSecurityMode_ = (MessageSecurityMode)messageSecurityMode;
	}


	void opcUaBinaryEncode(std::ostream& os, const EndpointDescription& value)
	{
		value.opcUaBinaryEncode(os);
	}

	void opcUaBinaryDecode(std::istream& is, EndpointDescription& value)
	{
		value.opcUaBinaryDecode(is);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// EndpointDescriptionArray
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void opcUaBinaryEncode(std::ostream& os, const EndpointDescriptionArray& value)
	{
		value.opcUaBinaryEncode(os);
	}

	void opcUaBinaryEncode(std::ostream& os, const EndpointDescriptionArray::SPtr& value)
	{
		value->opcUaBinaryEncode(os);
	}

	void opcUaBinaryDecode(std::istream& is, EndpointDescriptionArray& value)
	{
		value.opcUaBinaryDecode(is);
	}

	void opcUaBinaryDecode(std::istream& is, EndpointDescriptionArray::SPtr& value)
	{
		value->opcUaBinaryDecode(is);
	}

}