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
    
    /**
     * Describes an application and how to find it.
     */
    ApplicationDescription::ApplicationDescription(const ApplicationDescription& value)
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
        const_cast<ApplicationDescription*>(&value)->copyTo(*this);
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
    ApplicationDescription::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "ApplicationDescription encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    ApplicationDescription::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!applicationUri_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ApplicationDescription encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ApplicationUri", elementTree));
    
        elementTree.clear();
        if (!productUri_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ApplicationDescription encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ProductUri", elementTree));
    
        elementTree.clear();
        if (!applicationName_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ApplicationDescription encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ApplicationName", elementTree));
    
        elementTree.clear();
        if (!applicationType_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ApplicationDescription encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ApplicationType", elementTree));
    
        elementTree.clear();
        if (!gatewayServerUri_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ApplicationDescription encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("GatewayServerUri", elementTree));
    
        elementTree.clear();
        if (!discoveryProfileUri_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ApplicationDescription encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DiscoveryProfileUri", elementTree));
    
        elementTree.clear();
        if (!discoveryUrls_.xmlEncode(elementTree, "String", xmlns)) {
            Log(Error, "ApplicationDescription encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DiscoveryUrls", elementTree));
    
        return true;
    }
    
    bool
    ApplicationDescription::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ApplicationDescription decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    ApplicationDescription::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("ApplicationUri");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ApplicationDescription decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!applicationUri_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ApplicationDescription decode xml error - decode failed")
                .parameter("Element", "ApplicationUri");
            return false;
        }
    
        elementName = xmlns.addPrefix("ProductUri");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ApplicationDescription decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!productUri_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ApplicationDescription decode xml error - decode failed")
                .parameter("Element", "ProductUri");
            return false;
        }
    
        elementName = xmlns.addPrefix("ApplicationName");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ApplicationDescription decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!applicationName_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ApplicationDescription decode xml error - decode failed")
                .parameter("Element", "ApplicationName");
            return false;
        }
    
        elementName = xmlns.addPrefix("ApplicationType");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ApplicationDescription decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!applicationType_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ApplicationDescription decode xml error - decode failed")
                .parameter("Element", "ApplicationType");
            return false;
        }
    
        elementName = xmlns.addPrefix("GatewayServerUri");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ApplicationDescription decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!gatewayServerUri_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ApplicationDescription decode xml error - decode failed")
                .parameter("Element", "GatewayServerUri");
            return false;
        }
    
        elementName = xmlns.addPrefix("DiscoveryProfileUri");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ApplicationDescription decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!discoveryProfileUri_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ApplicationDescription decode xml error - decode failed")
                .parameter("Element", "DiscoveryProfileUri");
            return false;
        }
    
        elementName = xmlns.addPrefix("DiscoveryUrls");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ApplicationDescription decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!discoveryUrls_.xmlDecode(*tree, "String", xmlns)) {
            Log(Error, "ApplicationDescription decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    ApplicationDescription::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!applicationUri_.jsonEncode(elementTree))
        {
    	     Log(Error, "ApplicationDescription json encoder error")
    		     .parameter("Element", "applicationUri_");
            return false;
        }
        pt.push_back(std::make_pair("ApplicationUri", elementTree));
    
        elementTree.clear();
        if (!productUri_.jsonEncode(elementTree))
        {
    	     Log(Error, "ApplicationDescription json encoder error")
    		     .parameter("Element", "productUri_");
            return false;
        }
        pt.push_back(std::make_pair("ProductUri", elementTree));
    
        elementTree.clear();
        if (!applicationName_.jsonEncode(elementTree))
        {
    	     Log(Error, "ApplicationDescription json encoder error")
    		     .parameter("Element", "applicationName_");
            return false;
        }
        pt.push_back(std::make_pair("ApplicationName", elementTree));
    
        elementTree.clear();
        if (!applicationType_.jsonEncode(elementTree))
        {
    	     Log(Error, "ApplicationDescription json encoder error")
    		     .parameter("Element", "applicationType_");
            return false;
        }
        pt.push_back(std::make_pair("ApplicationType", elementTree));
    
        elementTree.clear();
        if (!gatewayServerUri_.jsonEncode(elementTree))
        {
    	     Log(Error, "ApplicationDescription json encoder error")
    		     .parameter("Element", "gatewayServerUri_");
            return false;
        }
        pt.push_back(std::make_pair("GatewayServerUri", elementTree));
    
        elementTree.clear();
        if (!discoveryProfileUri_.jsonEncode(elementTree))
        {
    	     Log(Error, "ApplicationDescription json encoder error")
    		     .parameter("Element", "discoveryProfileUri_");
            return false;
        }
        pt.push_back(std::make_pair("DiscoveryProfileUri", elementTree));
    
        elementTree.clear();
        if (!discoveryUrls_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "ApplicationDescription json encoder error")
    		     .parameter("Element", "discoveryUrls_");
            return false;
        }
        pt.push_back(std::make_pair("DiscoveryUrls", elementTree));
    
        return true;
    }
    
    bool
    ApplicationDescription::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "ApplicationUri";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ApplicationDescription decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!applicationUri_.jsonDecode(*tree)) {
            Log(Error, "ApplicationDescription decode json error - decode failed")
                .parameter("Element", "ApplicationUri");
            return false;
        }
    
        elementName = "ProductUri";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ApplicationDescription decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!productUri_.jsonDecode(*tree)) {
            Log(Error, "ApplicationDescription decode json error - decode failed")
                .parameter("Element", "ProductUri");
            return false;
        }
    
        elementName = "ApplicationName";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ApplicationDescription decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!applicationName_.jsonDecode(*tree)) {
            Log(Error, "ApplicationDescription decode json error - decode failed")
                .parameter("Element", "ApplicationName");
            return false;
        }
    
        elementName = "ApplicationType";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ApplicationDescription decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!applicationType_.jsonDecode(*tree)) {
            Log(Error, "ApplicationDescription decode json error - decode failed")
                .parameter("Element", "ApplicationType");
            return false;
        }
    
        elementName = "GatewayServerUri";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ApplicationDescription decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!gatewayServerUri_.jsonDecode(*tree)) {
            Log(Error, "ApplicationDescription decode json error - decode failed")
                .parameter("Element", "GatewayServerUri");
            return false;
        }
    
        elementName = "DiscoveryProfileUri";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ApplicationDescription decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!discoveryProfileUri_.jsonDecode(*tree)) {
            Log(Error, "ApplicationDescription decode json error - decode failed")
                .parameter("Element", "DiscoveryProfileUri");
            return false;
        }
    
        elementName = "DiscoveryUrls";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ApplicationDescription decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!discoveryUrls_.jsonDecode(*tree, "")) {
            Log(Error, "ApplicationDescription decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
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
