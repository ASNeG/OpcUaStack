/*
    DataTypeClass: RegisteredServer

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/RegisteredServer.h"

namespace OpcUaStackCore
{
    
    /**
     * The information required to register a server with a discovery server.
     */
    RegisteredServer::RegisteredServer(void)
    : Object()
    , ExtensionObjectBase()
    , serverUri_()
    , productUri_()
    , serverNames_()
    , serverType_()
    , gatewayServerUri_()
    , discoveryUrls_()
    , semaphoreFilePath_()
    , isOnline_()
    {
    }
    
    /**
     * The information required to register a server with a discovery server.
     */
    RegisteredServer::RegisteredServer(const RegisteredServer& value)
    : Object()
    , ExtensionObjectBase()
    , serverUri_()
    , productUri_()
    , serverNames_()
    , serverType_()
    , gatewayServerUri_()
    , discoveryUrls_()
    , semaphoreFilePath_()
    , isOnline_()
    {
        const_cast<RegisteredServer*>(&value)->copyTo(*this);
    }
    
    RegisteredServer::~RegisteredServer(void)
    {
    }
    
    OpcUaString&
    RegisteredServer::serverUri(void)
    {
        return serverUri_;
    }
    
    OpcUaString&
    RegisteredServer::productUri(void)
    {
        return productUri_;
    }
    
    OpcUaLocalizedTextArray&
    RegisteredServer::serverNames(void)
    {
        return serverNames_;
    }
    
    ApplicationType&
    RegisteredServer::serverType(void)
    {
        return serverType_;
    }
    
    OpcUaString&
    RegisteredServer::gatewayServerUri(void)
    {
        return gatewayServerUri_;
    }
    
    OpcUaStringArray&
    RegisteredServer::discoveryUrls(void)
    {
        return discoveryUrls_;
    }
    
    OpcUaString&
    RegisteredServer::semaphoreFilePath(void)
    {
        return semaphoreFilePath_;
    }
    
    OpcUaBoolean&
    RegisteredServer::isOnline(void)
    {
        return isOnline_;
    }
    
    bool
    RegisteredServer::operator==(const RegisteredServer& value)
    {
        RegisteredServer* dst = const_cast<RegisteredServer*>(&value);
        if (serverUri_ != dst->serverUri()) return false;
        if (productUri_ != dst->productUri()) return false;
        if (serverNames_ != dst->serverNames()) return false;
        if (serverType_ != dst->serverType()) return false;
        if (gatewayServerUri_ != dst->gatewayServerUri()) return false;
        if (discoveryUrls_ != dst->discoveryUrls()) return false;
        if (semaphoreFilePath_ != dst->semaphoreFilePath()) return false;
        if (isOnline_ != dst->isOnline()) return false;
        return true;
    }
    
    bool
    RegisteredServer::operator!=(const RegisteredServer& value)
    {
        return !this->operator==(value);
    }
    
    void
    RegisteredServer::copyTo(RegisteredServer& value)
    {
        serverUri_.copyTo(value.serverUri());
        productUri_.copyTo(value.productUri());
        serverNames_.copyTo(value.serverNames());
        serverType_.copyTo(value.serverType());
        gatewayServerUri_.copyTo(value.gatewayServerUri());
        discoveryUrls_.copyTo(value.discoveryUrls());
        semaphoreFilePath_.copyTo(value.semaphoreFilePath());
        value.isOnline_ = isOnline_;
    }
    
    RegisteredServer&
    RegisteredServer::operator=(const RegisteredServer& value)
    {
        const_cast<RegisteredServer*>(&value)->copyTo(*this);
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
    RegisteredServer::factory(void)
    {
    	return constructSPtr<RegisteredServer>();
    }
    
    std::string
    RegisteredServer::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    RegisteredServer::typeName(void)
    {
    	return "RegisteredServer";
    }
    
    OpcUaNodeId
    RegisteredServer::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)432,0);
    }
    
    OpcUaNodeId
    RegisteredServer::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)434, 0);
    }
    
    OpcUaNodeId
    RegisteredServer::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)433, 0);
    }
    
    OpcUaNodeId
    RegisteredServer::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15102, 0);
    }
    
    void
    RegisteredServer::opcUaBinaryEncode(std::ostream& os) const
    {
        serverUri_.opcUaBinaryEncode(os);
        productUri_.opcUaBinaryEncode(os);
        serverNames_.opcUaBinaryEncode(os);
        serverType_.opcUaBinaryEncode(os);
        gatewayServerUri_.opcUaBinaryEncode(os);
        discoveryUrls_.opcUaBinaryEncode(os);
        semaphoreFilePath_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,isOnline_);
    }
    
    void
    RegisteredServer::opcUaBinaryDecode(std::istream& is)
    {
        serverUri_.opcUaBinaryDecode(is);
        productUri_.opcUaBinaryDecode(is);
        serverNames_.opcUaBinaryDecode(is);
        serverType_.opcUaBinaryDecode(is);
        gatewayServerUri_.opcUaBinaryDecode(is);
        discoveryUrls_.opcUaBinaryDecode(is);
        semaphoreFilePath_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,isOnline_);
    }
    
    bool
    RegisteredServer::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "RegisteredServer encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    RegisteredServer::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!serverUri_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "RegisteredServer encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ServerUri", elementTree));
    
        elementTree.clear();
        if (!productUri_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "RegisteredServer encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ProductUri", elementTree));
    
        elementTree.clear();
        if (!serverNames_.xmlEncode(elementTree, "LocalizedText", xmlns)) {
            Log(Error, "RegisteredServer encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ServerNames", elementTree));
    
        elementTree.clear();
        if (!serverType_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "RegisteredServer encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ServerType", elementTree));
    
        elementTree.clear();
        if (!gatewayServerUri_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "RegisteredServer encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("GatewayServerUri", elementTree));
    
        elementTree.clear();
        if (!discoveryUrls_.xmlEncode(elementTree, "String", xmlns)) {
            Log(Error, "RegisteredServer encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DiscoveryUrls", elementTree));
    
        elementTree.clear();
        if (!semaphoreFilePath_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "RegisteredServer encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SemaphoreFilePath", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, isOnline_))
        {
            Log(Error, "RegisteredServer encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("IsOnline", elementTree));
    
        return true;
    }
    
    bool
    RegisteredServer::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "RegisteredServer decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    RegisteredServer::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("ServerUri");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "RegisteredServer decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!serverUri_.xmlDecode(*tree, xmlns)) {
            Log(Error, "RegisteredServer decode xml error - decode failed")
                .parameter("Element", "ServerUri");
            return false;
        }
    
        elementName = xmlns.addPrefix("ProductUri");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "RegisteredServer decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!productUri_.xmlDecode(*tree, xmlns)) {
            Log(Error, "RegisteredServer decode xml error - decode failed")
                .parameter("Element", "ProductUri");
            return false;
        }
    
        elementName = xmlns.addPrefix("ServerNames");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "RegisteredServer decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!serverNames_.xmlDecode(*tree, "LocalizedText", xmlns)) {
            Log(Error, "RegisteredServer decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("ServerType");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "RegisteredServer decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!serverType_.xmlDecode(*tree, xmlns)) {
            Log(Error, "RegisteredServer decode xml error - decode failed")
                .parameter("Element", "ServerType");
            return false;
        }
    
        elementName = xmlns.addPrefix("GatewayServerUri");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "RegisteredServer decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!gatewayServerUri_.xmlDecode(*tree, xmlns)) {
            Log(Error, "RegisteredServer decode xml error - decode failed")
                .parameter("Element", "GatewayServerUri");
            return false;
        }
    
        elementName = xmlns.addPrefix("DiscoveryUrls");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "RegisteredServer decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!discoveryUrls_.xmlDecode(*tree, "String", xmlns)) {
            Log(Error, "RegisteredServer decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("SemaphoreFilePath");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "RegisteredServer decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!semaphoreFilePath_.xmlDecode(*tree, xmlns)) {
            Log(Error, "RegisteredServer decode xml error - decode failed")
                .parameter("Element", "SemaphoreFilePath");
            return false;
        }
    
        elementName = xmlns.addPrefix("IsOnline");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "RegisteredServer decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, isOnline_)) {
            Log(Error, "RegisteredServer decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    RegisteredServer::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!serverUri_.jsonEncode(elementTree))
        {
    	     Log(Error, "RegisteredServer json encoder error")
    		     .parameter("Element", "serverUri_");
            return false;
        }
        pt.push_back(std::make_pair("ServerUri", elementTree));
    
        elementTree.clear();
        if (!productUri_.jsonEncode(elementTree))
        {
    	     Log(Error, "RegisteredServer json encoder error")
    		     .parameter("Element", "productUri_");
            return false;
        }
        pt.push_back(std::make_pair("ProductUri", elementTree));
    
        elementTree.clear();
        if (!serverNames_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "RegisteredServer json encoder error")
    		     .parameter("Element", "serverNames_");
            return false;
        }
        pt.push_back(std::make_pair("ServerNames", elementTree));
    
        elementTree.clear();
        if (!serverType_.jsonEncode(elementTree))
        {
    	     Log(Error, "RegisteredServer json encoder error")
    		     .parameter("Element", "serverType_");
            return false;
        }
        pt.push_back(std::make_pair("ServerType", elementTree));
    
        elementTree.clear();
        if (!gatewayServerUri_.jsonEncode(elementTree))
        {
    	     Log(Error, "RegisteredServer json encoder error")
    		     .parameter("Element", "gatewayServerUri_");
            return false;
        }
        pt.push_back(std::make_pair("GatewayServerUri", elementTree));
    
        elementTree.clear();
        if (!discoveryUrls_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "RegisteredServer json encoder error")
    		     .parameter("Element", "discoveryUrls_");
            return false;
        }
        pt.push_back(std::make_pair("DiscoveryUrls", elementTree));
    
        elementTree.clear();
        if (!semaphoreFilePath_.jsonEncode(elementTree))
        {
    	     Log(Error, "RegisteredServer json encoder error")
    		     .parameter("Element", "semaphoreFilePath_");
            return false;
        }
        pt.push_back(std::make_pair("SemaphoreFilePath", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, isOnline_))
        {
    	     Log(Error, "RegisteredServer json encoder error")
    		     .parameter("Element", "isOnline_");
           return false;
        }
        pt.push_back(std::make_pair("IsOnline", elementTree));
    
        return true;
    }
    
    bool
    RegisteredServer::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "ServerUri";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "RegisteredServer decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!serverUri_.jsonDecode(*tree)) {
            Log(Error, "RegisteredServer decode json error - decode failed")
                .parameter("Element", "ServerUri");
            return false;
        }
    
        elementName = "ProductUri";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "RegisteredServer decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!productUri_.jsonDecode(*tree)) {
            Log(Error, "RegisteredServer decode json error - decode failed")
                .parameter("Element", "ProductUri");
            return false;
        }
    
        elementName = "ServerNames";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "RegisteredServer decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!serverNames_.jsonDecode(*tree, "")) {
            Log(Error, "RegisteredServer decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "ServerType";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "RegisteredServer decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!serverType_.jsonDecode(*tree)) {
            Log(Error, "RegisteredServer decode json error - decode failed")
                .parameter("Element", "ServerType");
            return false;
        }
    
        elementName = "GatewayServerUri";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "RegisteredServer decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!gatewayServerUri_.jsonDecode(*tree)) {
            Log(Error, "RegisteredServer decode json error - decode failed")
                .parameter("Element", "GatewayServerUri");
            return false;
        }
    
        elementName = "DiscoveryUrls";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "RegisteredServer decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!discoveryUrls_.jsonDecode(*tree, "")) {
            Log(Error, "RegisteredServer decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "SemaphoreFilePath";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "RegisteredServer decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!semaphoreFilePath_.jsonDecode(*tree)) {
            Log(Error, "RegisteredServer decode json error - decode failed")
                .parameter("Element", "SemaphoreFilePath");
            return false;
        }
    
        elementName = "IsOnline";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "RegisteredServer decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, isOnline_)) {
            Log(Error, "RegisteredServer decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    RegisteredServer::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	RegisteredServer* dst = dynamic_cast<RegisteredServer*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    RegisteredServer::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	RegisteredServer* dst = dynamic_cast<RegisteredServer*>(&extensionObjectBase);
    	return *const_cast<RegisteredServer*>(this) == *dst;
    }
    
    void
    RegisteredServer::out(std::ostream& os)
    {
        os << "ServerUri="; serverUri_.out(os);
        os << ", ProductUri="; productUri_.out(os);
        os << ", ServerNames="; serverNames_.out(os);
        os << ", ServerType="; serverType_.out(os);
        os << ", GatewayServerUri="; gatewayServerUri_.out(os);
        os << ", DiscoveryUrls="; discoveryUrls_.out(os);
        os << ", SemaphoreFilePath="; semaphoreFilePath_.out(os);
        os << ", IsOnline=" << isOnline_;
    }

}
