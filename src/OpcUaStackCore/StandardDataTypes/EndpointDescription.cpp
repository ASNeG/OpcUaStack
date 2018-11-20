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
    EndpointDescription::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    EndpointDescription::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    EndpointDescription::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    EndpointDescription::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!endpointUrl_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("EndpointUrl", elementTree));
    
        elementTree.clear();
        if (!server_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("Server", elementTree));
    
        elementTree.clear();
        if (!serverCertificate_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("ServerCertificate", elementTree));
    
        elementTree.clear();
        if (!securityMode_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("SecurityMode", elementTree));
    
        elementTree.clear();
        if (!securityPolicyUri_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("SecurityPolicyUri", elementTree));
    
        elementTree.clear();
        if (!userIdentityTokens_.xmlEncode(elementTree, "UserTokenPolicy", xmlns)) return false;
        pt.push_back(std::make_pair("UserIdentityTokens", elementTree));
    
        elementTree.clear();
        if (!transportProfileUri_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("TransportProfileUri", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, securityLevel_)) return false;
        pt.push_back(std::make_pair("SecurityLevel", elementTree));
    
        return true;
    }
    
    bool
    EndpointDescription::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    EndpointDescription::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("EndpointUrl");
        if (!tree) return false;
        if (!endpointUrl_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("Server");
        if (!tree) return false;
        if (!server_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("ServerCertificate");
        if (!tree) return false;
        if (!serverCertificate_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("SecurityMode");
        if (!tree) return false;
        if (!securityMode_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("SecurityPolicyUri");
        if (!tree) return false;
        if (!securityPolicyUri_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("UserIdentityTokens");
        if (!tree) return false;
        if (!userIdentityTokens_.xmlDecode(*tree, "UserTokenPolicy", xmlns)) return false;
    
        tree = pt.get_child_optional("TransportProfileUri");
        if (!tree) return false;
        if (!transportProfileUri_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("SecurityLevel");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, securityLevel_)) return false;
    
        return true;
    }
    
    bool
    EndpointDescription::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    EndpointDescription::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    EndpointDescription::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    EndpointDescription::jsonDecode(boost::property_tree::ptree& pt)
    {
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
