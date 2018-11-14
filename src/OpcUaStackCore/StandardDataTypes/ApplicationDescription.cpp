/*
    DataTypeClass: ApplicationDescription

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/ApplicationDescription.h"

namespace OpcUaStackCore
{
    
    /**
     * Describes an application and how to find it.
     */
    ApplicationDescription::ApplicationDescription(void)
    : Object()
    , ExtensionObjectBase()
    , applicationUri_()
    , productUri_()
    , applicationName_()
    , applicationType_()
    , gatewayServerUri_()
    , discoveryProfileUri_()
    , discoveryUrls_()
    {
    }
    
    ApplicationDescription::~ApplicationDescription(void)
    {
    }
    
    OpcUaString&
    ApplicationDescription::applicationUri(void)
    {
        return applicationUri_;
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
    
    ApplicationType&
    ApplicationDescription::applicationType(void)
    {
        return applicationType_;
    }
    
    OpcUaString&
    ApplicationDescription::gatewayServerUri(void)
    {
        return gatewayServerUri_;
    }
    
    OpcUaString&
    ApplicationDescription::discoveryProfileUri(void)
    {
        return discoveryProfileUri_;
    }
    
    OpcUaStringArray&
    ApplicationDescription::discoveryUrls(void)
    {
        return discoveryUrls_;
    }
    
    bool
    ApplicationDescription::operator==(const ApplicationDescription& value)
    {
        ApplicationDescription* dst = const_cast<ApplicationDescription*>(&value);
        if (applicationUri_ != dst->applicationUri()) return false;
        if (productUri_ != dst->productUri()) return false;
        if (applicationName_ != dst->applicationName()) return false;
        if (applicationType_ != dst->applicationType()) return false;
        if (gatewayServerUri_ != dst->gatewayServerUri()) return false;
        if (discoveryProfileUri_ != dst->discoveryProfileUri()) return false;
        if (discoveryUrls_ != dst->discoveryUrls()) return false;
        return true;
    }
    
    bool
    ApplicationDescription::operator!=(const ApplicationDescription& value)
    {
        return !this->operator==(value);
    }
    
    void
    ApplicationDescription::copyTo(ApplicationDescription& value)
    {
        applicationUri_.copyTo(value.applicationUri());
        productUri_.copyTo(value.productUri());
        applicationName_.copyTo(value.applicationName());
        applicationType_.copyTo(value.applicationType());
        gatewayServerUri_.copyTo(value.gatewayServerUri());
        discoveryProfileUri_.copyTo(value.discoveryProfileUri());
        discoveryUrls_.copyTo(value.discoveryUrls());
    }
    
    ApplicationDescription&
    ApplicationDescription::operator=(const ApplicationDescription& value)
    {
        const_cast<ApplicationDescription*>(&value)->copyTo(*this);
        return *this;
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
    
    std::string
    ApplicationDescription::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    ApplicationDescription::typeName(void)
    {
    	return "ApplicationDescription";
    }
    
    OpcUaNodeId
    ApplicationDescription::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)308,0);
    }
    
    OpcUaNodeId
    ApplicationDescription::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)310, 0);
    }
    
    OpcUaNodeId
    ApplicationDescription::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)309, 0);
    }
    
    OpcUaNodeId
    ApplicationDescription::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15087, 0);
    }
    
    void
    ApplicationDescription::opcUaBinaryEncode(std::ostream& os) const
    {
        applicationUri_.opcUaBinaryEncode(os);
        productUri_.opcUaBinaryEncode(os);
        applicationName_.opcUaBinaryEncode(os);
        applicationType_.opcUaBinaryEncode(os);
        gatewayServerUri_.opcUaBinaryEncode(os);
        discoveryProfileUri_.opcUaBinaryEncode(os);
        discoveryUrls_.opcUaBinaryEncode(os);
    }
    
    void
    ApplicationDescription::opcUaBinaryDecode(std::istream& is)
    {
        applicationUri_.opcUaBinaryDecode(is);
        productUri_.opcUaBinaryDecode(is);
        applicationName_.opcUaBinaryDecode(is);
        applicationType_.opcUaBinaryDecode(is);
        gatewayServerUri_.opcUaBinaryDecode(is);
        discoveryProfileUri_.opcUaBinaryDecode(is);
        discoveryUrls_.opcUaBinaryDecode(is);
    }
    
    bool
    ApplicationDescription::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    ApplicationDescription::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    ApplicationDescription::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    ApplicationDescription::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        if (!applicationUri_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("ApplicationUri", elementTree));
    
        if (!productUri_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("ProductUri", elementTree));
    
        if (!applicationName_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("ApplicationName", elementTree));
    
        if (!applicationType_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("ApplicationType", elementTree));
    
        if (!gatewayServerUri_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("GatewayServerUri", elementTree));
    
        if (!discoveryProfileUri_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("DiscoveryProfileUri", elementTree));
    
        if (!discoveryUrls_.xmlEncode(elementTree, "String", xmlns)) return false;
        pt.push_back(std::make_pair("DiscoveryUrls", elementTree));
    
        return true;
    }
    
    bool
    ApplicationDescription::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    ApplicationDescription::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("ApplicationUri");
        if (!tree) return false;
        if (!applicationUri_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("ProductUri");
        if (!tree) return false;
        if (!productUri_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("ApplicationName");
        if (!tree) return false;
        if (!applicationName_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("ApplicationType");
        if (!tree) return false;
        if (!applicationType_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("GatewayServerUri");
        if (!tree) return false;
        if (!gatewayServerUri_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("DiscoveryProfileUri");
        if (!tree) return false;
        if (!discoveryProfileUri_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("DiscoveryUrls");
        if (!tree) return false;
        if (!discoveryUrls_.xmlDecode(*tree, "String", xmlns)) return false;
    
        return true;
    }
    
    bool
    ApplicationDescription::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    ApplicationDescription::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    ApplicationDescription::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    ApplicationDescription::jsonDecode(boost::property_tree::ptree& pt)
    {
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
    	return *const_cast<ApplicationDescription*>(this) == *dst;
    }
    
    void
    ApplicationDescription::out(std::ostream& os)
    {
        os << "ApplicationUri="; applicationUri_.out(os);
        os << ", ProductUri="; productUri_.out(os);
        os << ", ApplicationName="; applicationName_.out(os);
        os << ", ApplicationType="; applicationType_.out(os);
        os << ", GatewayServerUri="; gatewayServerUri_.out(os);
        os << ", DiscoveryProfileUri="; discoveryProfileUri_.out(os);
        os << ", DiscoveryUrls="; discoveryUrls_.out(os);
    }

}
