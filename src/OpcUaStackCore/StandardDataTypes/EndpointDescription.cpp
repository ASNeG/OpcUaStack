/*
    DataTypeClass: EndpointDescription

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/EndpointDescription.h"

namespace OpcUaStackCore
{
    
    /**
     * The description of a endpoint that can be used to access a server.
     */
    EndpointDescription::EndpointDescription(void)
    : Object()
    , ExtensionObjectBase()
    , endpointUrl_()
    , server_()
    , serverCertificate_()
    , securityMode_()
    , securityPolicyUri_()
    , userIdentityTokens_()
    , transportProfileUri_()
    , securityLevel_()
    {
    }
    
    /**
     * The description of a endpoint that can be used to access a server.
     */
    EndpointDescription::EndpointDescription(const EndpointDescription& value)
    : Object()
    , ExtensionObjectBase()
    , endpointUrl_()
    , server_()
    , serverCertificate_()
    , securityMode_()
    , securityPolicyUri_()
    , userIdentityTokens_()
    , transportProfileUri_()
    , securityLevel_()
    {
        const_cast<EndpointDescription*>(&value)->copyTo(*this);
    }
    
    EndpointDescription::~EndpointDescription(void)
    {
    }
    
    OpcUaString&
    EndpointDescription::endpointUrl(void)
    {
        return endpointUrl_;
    }
    
    ApplicationDescription&
    EndpointDescription::server(void)
    {
        return server_;
    }
    
    OpcUaApplicationInstanceCertificate&
    EndpointDescription::serverCertificate(void)
    {
        return serverCertificate_;
    }
    
    MessageSecurityMode&
    EndpointDescription::securityMode(void)
    {
        return securityMode_;
    }
    
    OpcUaString&
    EndpointDescription::securityPolicyUri(void)
    {
        return securityPolicyUri_;
    }
    
    UserTokenPolicyArray&
    EndpointDescription::userIdentityTokens(void)
    {
        return userIdentityTokens_;
    }
    
    OpcUaString&
    EndpointDescription::transportProfileUri(void)
    {
        return transportProfileUri_;
    }
    
    OpcUaByte&
    EndpointDescription::securityLevel(void)
    {
        return securityLevel_;
    }
    
    bool
    EndpointDescription::operator==(const EndpointDescription& value)
    {
        EndpointDescription* dst = const_cast<EndpointDescription*>(&value);
        if (endpointUrl_ != dst->endpointUrl()) return false;
        if (server_ != dst->server()) return false;
        if (serverCertificate_ != dst->serverCertificate()) return false;
        if (securityMode_ != dst->securityMode()) return false;
        if (securityPolicyUri_ != dst->securityPolicyUri()) return false;
        if (userIdentityTokens_ != dst->userIdentityTokens()) return false;
        if (transportProfileUri_ != dst->transportProfileUri()) return false;
        if (securityLevel_ != dst->securityLevel()) return false;
        return true;
    }
    
    bool
    EndpointDescription::operator!=(const EndpointDescription& value)
    {
        return !this->operator==(value);
    }
    
    void
    EndpointDescription::copyTo(EndpointDescription& value)
    {
        endpointUrl_.copyTo(value.endpointUrl());
        server_.copyTo(value.server());
        serverCertificate_.copyTo(value.serverCertificate());
        securityMode_.copyTo(value.securityMode());
        securityPolicyUri_.copyTo(value.securityPolicyUri());
        userIdentityTokens_.copyTo(value.userIdentityTokens());
        transportProfileUri_.copyTo(value.transportProfileUri());
        value.securityLevel_ = securityLevel_;
    }
    
    EndpointDescription&
    EndpointDescription::operator=(const EndpointDescription& value)
    {
        const_cast<EndpointDescription*>(&value)->copyTo(*this);
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
    EndpointDescription::factory(void)
    {
    	return constructSPtr<EndpointDescription>();
    }
    
    std::string
    EndpointDescription::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    EndpointDescription::typeName(void)
    {
    	return "EndpointDescription";
    }
    
    OpcUaNodeId
    EndpointDescription::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)312,0);
    }
    
    OpcUaNodeId
    EndpointDescription::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)314, 0);
    }
    
    OpcUaNodeId
    EndpointDescription::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)313, 0);
    }
    
    OpcUaNodeId
    EndpointDescription::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15099, 0);
    }
    
    void
    EndpointDescription::opcUaBinaryEncode(std::ostream& os) const
    {
        endpointUrl_.opcUaBinaryEncode(os);
        server_.opcUaBinaryEncode(os);
        serverCertificate_.opcUaBinaryEncode(os);
        securityMode_.opcUaBinaryEncode(os);
        securityPolicyUri_.opcUaBinaryEncode(os);
        userIdentityTokens_.opcUaBinaryEncode(os);
        transportProfileUri_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,securityLevel_);
    }
    
    void
    EndpointDescription::opcUaBinaryDecode(std::istream& is)
    {
        endpointUrl_.opcUaBinaryDecode(is);
        server_.opcUaBinaryDecode(is);
        serverCertificate_.opcUaBinaryDecode(is);
        securityMode_.opcUaBinaryDecode(is);
        securityPolicyUri_.opcUaBinaryDecode(is);
        userIdentityTokens_.opcUaBinaryDecode(is);
        transportProfileUri_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,securityLevel_);
    }
    
    bool
    EndpointDescription::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "EndpointDescription encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    EndpointDescription::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!endpointUrl_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "EndpointDescription encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("EndpointUrl", elementTree));
    
        elementTree.clear();
        if (!server_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "EndpointDescription encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Server", elementTree));
    
        elementTree.clear();
        if (!serverCertificate_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "EndpointDescription encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ServerCertificate", elementTree));
    
        elementTree.clear();
        if (!securityMode_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "EndpointDescription encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SecurityMode", elementTree));
    
        elementTree.clear();
        if (!securityPolicyUri_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "EndpointDescription encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SecurityPolicyUri", elementTree));
    
        elementTree.clear();
        if (!userIdentityTokens_.xmlEncode(elementTree, "UserTokenPolicy", xmlns)) {
            Log(Error, "EndpointDescription encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("UserIdentityTokens", elementTree));
    
        elementTree.clear();
        if (!transportProfileUri_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "EndpointDescription encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("TransportProfileUri", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, securityLevel_))
        {
            Log(Error, "EndpointDescription encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SecurityLevel", elementTree));
    
        return true;
    }
    
    bool
    EndpointDescription::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointDescription decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    EndpointDescription::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("EndpointUrl");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointDescription decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!endpointUrl_.xmlDecode(*tree, xmlns)) {
            Log(Error, "EndpointDescription decode xml error - decode failed")
                .parameter("Element", "EndpointUrl");
            return false;
        }
    
        elementName = xmlns.addPrefix("Server");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointDescription decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!server_.xmlDecode(*tree, xmlns)) {
            Log(Error, "EndpointDescription decode xml error - decode failed")
                .parameter("Element", "Server");
            return false;
        }
    
        elementName = xmlns.addPrefix("ServerCertificate");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointDescription decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!serverCertificate_.xmlDecode(*tree, xmlns)) {
            Log(Error, "EndpointDescription decode xml error - decode failed")
                .parameter("Element", "ServerCertificate");
            return false;
        }
    
        elementName = xmlns.addPrefix("SecurityMode");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointDescription decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!securityMode_.xmlDecode(*tree, xmlns)) {
            Log(Error, "EndpointDescription decode xml error - decode failed")
                .parameter("Element", "SecurityMode");
            return false;
        }
    
        elementName = xmlns.addPrefix("SecurityPolicyUri");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointDescription decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!securityPolicyUri_.xmlDecode(*tree, xmlns)) {
            Log(Error, "EndpointDescription decode xml error - decode failed")
                .parameter("Element", "SecurityPolicyUri");
            return false;
        }
    
        elementName = xmlns.addPrefix("UserIdentityTokens");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointDescription decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!userIdentityTokens_.xmlDecode(*tree, "UserTokenPolicy", xmlns)) {
            Log(Error, "EndpointDescription decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("TransportProfileUri");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointDescription decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!transportProfileUri_.xmlDecode(*tree, xmlns)) {
            Log(Error, "EndpointDescription decode xml error - decode failed")
                .parameter("Element", "TransportProfileUri");
            return false;
        }
    
        elementName = xmlns.addPrefix("SecurityLevel");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointDescription decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, securityLevel_)) {
            Log(Error, "EndpointDescription decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    EndpointDescription::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!endpointUrl_.jsonEncode(elementTree))
        {
    	     Log(Error, "EndpointDescription json encoder error")
    		     .parameter("Element", "endpointUrl_");
            return false;
        }
        pt.push_back(std::make_pair("EndpointUrl", elementTree));
    
        elementTree.clear();
        if (!server_.jsonEncode(elementTree))
        {
    	     Log(Error, "EndpointDescription json encoder error")
    		     .parameter("Element", "server_");
            return false;
        }
        pt.push_back(std::make_pair("Server", elementTree));
    
        elementTree.clear();
        if (!serverCertificate_.jsonEncode(elementTree))
        {
    	     Log(Error, "EndpointDescription json encoder error")
    		     .parameter("Element", "serverCertificate_");
            return false;
        }
        pt.push_back(std::make_pair("ServerCertificate", elementTree));
    
        elementTree.clear();
        if (!securityMode_.jsonEncode(elementTree))
        {
    	     Log(Error, "EndpointDescription json encoder error")
    		     .parameter("Element", "securityMode_");
            return false;
        }
        pt.push_back(std::make_pair("SecurityMode", elementTree));
    
        elementTree.clear();
        if (!securityPolicyUri_.jsonEncode(elementTree))
        {
    	     Log(Error, "EndpointDescription json encoder error")
    		     .parameter("Element", "securityPolicyUri_");
            return false;
        }
        pt.push_back(std::make_pair("SecurityPolicyUri", elementTree));
    
        elementTree.clear();
        if (!userIdentityTokens_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "EndpointDescription json encoder error")
    		     .parameter("Element", "userIdentityTokens_");
            return false;
        }
        pt.push_back(std::make_pair("UserIdentityTokens", elementTree));
    
        elementTree.clear();
        if (!transportProfileUri_.jsonEncode(elementTree))
        {
    	     Log(Error, "EndpointDescription json encoder error")
    		     .parameter("Element", "transportProfileUri_");
            return false;
        }
        pt.push_back(std::make_pair("TransportProfileUri", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, securityLevel_))
        {
    	     Log(Error, "EndpointDescription json encoder error")
    		     .parameter("Element", "securityLevel_");
           return false;
        }
        pt.push_back(std::make_pair("SecurityLevel", elementTree));
    
        return true;
    }
    
    bool
    EndpointDescription::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "EndpointUrl";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointDescription decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!endpointUrl_.jsonDecode(*tree)) {
            Log(Error, "EndpointDescription decode json error - decode failed")
                .parameter("Element", "EndpointUrl");
            return false;
        }
    
        elementName = "Server";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointDescription decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!server_.jsonDecode(*tree)) {
            Log(Error, "EndpointDescription decode json error - decode failed")
                .parameter("Element", "Server");
            return false;
        }
    
        elementName = "ServerCertificate";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointDescription decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!serverCertificate_.jsonDecode(*tree)) {
            Log(Error, "EndpointDescription decode json error - decode failed")
                .parameter("Element", "ServerCertificate");
            return false;
        }
    
        elementName = "SecurityMode";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointDescription decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!securityMode_.jsonDecode(*tree)) {
            Log(Error, "EndpointDescription decode json error - decode failed")
                .parameter("Element", "SecurityMode");
            return false;
        }
    
        elementName = "SecurityPolicyUri";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointDescription decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!securityPolicyUri_.jsonDecode(*tree)) {
            Log(Error, "EndpointDescription decode json error - decode failed")
                .parameter("Element", "SecurityPolicyUri");
            return false;
        }
    
        elementName = "UserIdentityTokens";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointDescription decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!userIdentityTokens_.jsonDecode(*tree, "")) {
            Log(Error, "EndpointDescription decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "TransportProfileUri";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointDescription decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!transportProfileUri_.jsonDecode(*tree)) {
            Log(Error, "EndpointDescription decode json error - decode failed")
                .parameter("Element", "TransportProfileUri");
            return false;
        }
    
        elementName = "SecurityLevel";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointDescription decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, securityLevel_)) {
            Log(Error, "EndpointDescription decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    EndpointDescription::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	EndpointDescription* dst = dynamic_cast<EndpointDescription*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    EndpointDescription::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	EndpointDescription* dst = dynamic_cast<EndpointDescription*>(&extensionObjectBase);
    	return *const_cast<EndpointDescription*>(this) == *dst;
    }
    
    void
    EndpointDescription::out(std::ostream& os)
    {
        os << "EndpointUrl="; endpointUrl_.out(os);
        os << ", Server="; server_.out(os);
        os << ", ServerCertificate="; serverCertificate_.out(os);
        os << ", SecurityMode="; securityMode_.out(os);
        os << ", SecurityPolicyUri="; securityPolicyUri_.out(os);
        os << ", UserIdentityTokens="; userIdentityTokens_.out(os);
        os << ", TransportProfileUri="; transportProfileUri_.out(os);
        os << ", SecurityLevel=" << securityLevel_;
    }

}
