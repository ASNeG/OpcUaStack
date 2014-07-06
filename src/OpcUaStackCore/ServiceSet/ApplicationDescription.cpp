#include "OpcUaStackCore/ServiceSet/ApplicationDescription.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"

namespace OpcUaStackCore
{

	ApplicationDescription::ApplicationDescription(void)
	: applicationUri_()
	, productUri_()
	, applicationType_(ApplicationType_Server)
	, gatewayServerUri_()
	, discoveryProfileUri_()
	, discoveryUrls_()
	{
	}

	ApplicationDescription::~ApplicationDescription(void)
	{
	}

	void 
	ApplicationDescription::applicationUri(const std::string& applicationUri)
	{
		applicationUri_ = applicationUri;
	}

	std::string 
	ApplicationDescription::applicationUri(void) const
	{
		return applicationUri_.value();
	}

	void 
	ApplicationDescription::productUri(const std::string& productUri)
	{
		productUri_ = productUri;
	}

	std::string 
	ApplicationDescription::productUri(void) const
	{
		return productUri_.value();
	}

	void 
	ApplicationDescription::applicationType(ApplicationType applicationType)
	{
		applicationType_ = applicationType;
	}

	ApplicationType 
	ApplicationDescription::applicationType(void) const
	{
		return applicationType_;
	}

	void 
	ApplicationDescription::gatewayServerUri(const std::string& gatewayServerUri)
	{
		gatewayServerUri_ = gatewayServerUri;
	}

	std::string 
	ApplicationDescription::gatewayServerUri(void) const
	{
		return gatewayServerUri_.value();
	}

	void 
	ApplicationDescription::discoveryProfileUri(const std::string& discoveryProfileUri)
	{
		discoveryProfileUri_ = discoveryProfileUri;
	}

	std::string 
	ApplicationDescription::discoveryProfileUri(void) const
	{
		return discoveryProfileUri_.value();
	}

	void 
	ApplicationDescription::discoveryUrls(OpcUaStringArray::SPtr discoveryUrls)
	{
		discoveryUrls_ = discoveryUrls;
	}

	OpcUaStringArray::SPtr 
	ApplicationDescription::discoveryUrls(void) const
	{
		return discoveryUrls_;
	}

	void 
	ApplicationDescription::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaStackCore::opcUaBinaryEncode(os, applicationUri_);
		OpcUaStackCore::opcUaBinaryEncode(os, productUri_);
		OpcUaStackCore::opcUaBinaryEncode(os, (OpcUaUInt32)applicationType_);
		OpcUaStackCore::opcUaBinaryEncode(os, gatewayServerUri_);
		OpcUaStackCore::opcUaBinaryEncode(os, discoveryProfileUri_);
		OpcUaStackCore::opcUaBinaryEncode(os, discoveryUrls_);
	}

	void 
	ApplicationDescription::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaUInt32 applicationType;
		OpcUaStackCore::opcUaBinaryDecode(is, applicationUri_);
		OpcUaStackCore::opcUaBinaryDecode(is, productUri_);
		OpcUaStackCore::opcUaBinaryDecode(is, applicationType);
		OpcUaStackCore::opcUaBinaryDecode(is, gatewayServerUri_);
		OpcUaStackCore::opcUaBinaryDecode(is, discoveryProfileUri_);
		OpcUaStackCore::opcUaBinaryDecode(is, discoveryUrls_);
		applicationType_ = (ApplicationType)applicationType;
	}

}
