/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

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
	, applicationType_(AT_Server)
	, gatewayServerUri_()
	, discoveryProfileUri_()
	, discoveryUrls_(constructSPtr<OpcUaStringArray>())
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
	ApplicationDescription::getApplicationUri(void)
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
	ApplicationDescription::getProductUri(void)
	{
		return productUri_;
	}

	void
	ApplicationDescription::applicationName(OpcUaLocalizedText applicationName)
	{
		applicationName_ = applicationName;
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
	ApplicationDescription::getGatewayServerUri(void)
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
	ApplicationDescription::getDiscoveryProfileUri(void)
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
		applicationUri_.copyTo(applicationDescription.getApplicationUri());
		productUri_.copyTo(applicationDescription.getProductUri());
		applicationName_.copyTo(applicationDescription.applicationName());
		applicationDescription.applicationType(applicationType_);
		gatewayServerUri_.copyTo(applicationDescription.getGatewayServerUri());
		discoveryProfileUri_.copyTo(applicationDescription.getDiscoveryProfileUri());
		discoveryUrls_->copyTo(*applicationDescription.discoveryUrls());
	}

	bool
	ApplicationDescription::operator==(const ApplicationDescription& applicationDescription) const
	{
		ApplicationDescription* dst = const_cast<ApplicationDescription*>(&applicationDescription);
		return
			applicationUri_ == dst->getApplicationUri() &&
			productUri_ == dst->getProductUri() &&
			applicationName_ == dst->applicationName() &&
			applicationType_ == dst->applicationType() &&
			gatewayServerUri_ == dst->getGatewayServerUri() &&
			discoveryProfileUri_ == dst->getDiscoveryProfileUri(); // &&
			// FIXME: discoveryUrls_ == dst->discoveryUrls();
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ExtensionObjectBase
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ExtensionObjectBase::SPtr
	ApplicationDescription::factory(void)
	{
		return constructSPtr<ApplicationDescription>();
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

	bool
	ApplicationDescription::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
	{
		// FIXME: todo
		return false;
	}

	bool
	ApplicationDescription::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return false;
	}

	bool
	ApplicationDescription::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return false;
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
