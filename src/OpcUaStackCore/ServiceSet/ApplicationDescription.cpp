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
	, discoveryUrls_(OpcUaStringArray::construct())
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

	OpcUaString&
	ApplicationDescription::applicationUri(void)
	{
		return applicationUri_;
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

	OpcUaString&
	ApplicationDescription::productUri(void)
	{
		return productUri_;
	}

	OpcUaLocalizedText& 
	ApplicationDescription::applicationName(void)
	{
		return applicationName_;
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

	OpcUaString&
	ApplicationDescription::gatewayServerUri(void)
	{
		return gatewayServerUri_;
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

	OpcUaString&
	ApplicationDescription::discoveryProfileUri(void)
	{
		return discoveryProfileUri_;
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
	ApplicationDescription::copyTo(ApplicationDescription& applicationDescription)
	{
		applicationUri_.copyTo(applicationDescription.applicationUri());
		productUri_.copyTo(applicationDescription.productUri());
		applicationName_.copyTo(applicationDescription.applicationName());
		applicationDescription.applicationType(applicationType_);
		gatewayServerUri_.copyTo(applicationDescription.gatewayServerUri());
		discoveryProfileUri_.copyTo(applicationDescription.discoveryProfileUri());
		discoveryUrls_->copyTo(*applicationDescription.discoveryUrls());
	}

	bool
	ApplicationDescription::operator==(const ApplicationDescription& applicationDescription) const
	{
		ApplicationDescription* dst = const_cast<ApplicationDescription*>(&applicationDescription);
		return
			applicationUri_ == dst->applicationUri() &&
			productUri_ == dst->productUri() &&
			applicationName_ == dst->applicationName() &&
			applicationType_ == dst->applicationType() &&
			gatewayServerUri_ == dst->gatewayServerUri() &&
			discoveryProfileUri_ == dst->discoveryProfileUri(); // &&
			// FIXME: discoveryUrls_ == dst->discoveryUrls();
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ExtensionObjectBase
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ExtensionObjectBase::BSPtr
	ApplicationDescription::factory(void)
	{
		return ApplicationDescription::construct();
	}

	void 
	ApplicationDescription::opcUaBinaryEncode(std::ostream& os) const
	{
		applicationUri_.opcUaBinaryEncode(os);
		productUri_.opcUaBinaryEncode(os);
		applicationName_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)applicationType_);
		gatewayServerUri_.opcUaBinaryEncode(os);
		discoveryProfileUri_.opcUaBinaryEncode(os);
		discoveryUrls_->opcUaBinaryEncode(os);
	}

	void 
	ApplicationDescription::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaUInt32 applicationType;
		applicationUri_.opcUaBinaryDecode(is);
		productUri_.opcUaBinaryDecode(is);
		applicationName_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, applicationType);
		gatewayServerUri_.opcUaBinaryDecode(is);
		discoveryProfileUri_.opcUaBinaryDecode(is);
		discoveryUrls_->opcUaBinaryDecode(is);
		applicationType_ = (ApplicationType)applicationType;
	}

	void
	ApplicationDescription::copyTo(ExtensionObjectBase& extensionObjectBase)
	{
		ApplicationDescription* dst = dynamic_cast<ApplicationDescription*>(&extensionObjectBase);
		copyTo(*dst);
	}

	bool
	ApplicationDescription::equal(ExtensionObjectBase& extensionObjectBase) const
	{
		ApplicationDescription* dst = dynamic_cast<ApplicationDescription*>(&extensionObjectBase);
		return *this == *dst;
	}

	void
	ApplicationDescription::out(std::ostream& os)
	{
		os << "ApplicationUri="; applicationUri_.out(os);
		os << ", ProductUri="; productUri_.out(os);
		os << ", ApplicationName="; applicationName_.out(os);
		os << ", ApplicationType=" << applicationType_;
		os << ", GatewayServerUri="; gatewayServerUri_.out(os);
		os << ", DiscoveryProfileUri="; discoveryProfileUri_.out(os);
		os << ", DiscoveryUrls="; discoveryUrls_->out(os);
	}






}
