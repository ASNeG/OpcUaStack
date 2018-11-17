/*
    DataTypeClass: UserTokenPolicy

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/UserTokenPolicy.h"

namespace OpcUaStackCore
{
    
    /**
     * Describes a user token that can be used with a server.
     */
    UserTokenPolicy::UserTokenPolicy(void)
    : Object()
    , ExtensionObjectBase()
    , policyId_()
    , tokenType_()
    , issuedTokenType_()
    , issuerEndpointUrl_()
    , securityPolicyUri_()
    {
    }
    
    UserTokenPolicy::~UserTokenPolicy(void)
    {
    }
    
    OpcUaString&
    UserTokenPolicy::policyId(void)
    {
        return policyId_;
    }
    
    UserTokenType&
    UserTokenPolicy::tokenType(void)
    {
        return tokenType_;
    }
    
    OpcUaString&
    UserTokenPolicy::issuedTokenType(void)
    {
        return issuedTokenType_;
    }
    
    OpcUaString&
    UserTokenPolicy::issuerEndpointUrl(void)
    {
        return issuerEndpointUrl_;
    }
    
    OpcUaString&
    UserTokenPolicy::securityPolicyUri(void)
    {
        return securityPolicyUri_;
    }
    
    bool
    UserTokenPolicy::operator==(const UserTokenPolicy& value)
    {
        UserTokenPolicy* dst = const_cast<UserTokenPolicy*>(&value);
        if (policyId_ != dst->policyId()) return false;
        if (tokenType_ != dst->tokenType()) return false;
        if (issuedTokenType_ != dst->issuedTokenType()) return false;
        if (issuerEndpointUrl_ != dst->issuerEndpointUrl()) return false;
        if (securityPolicyUri_ != dst->securityPolicyUri()) return false;
        return true;
    }
    
    bool
    UserTokenPolicy::operator!=(const UserTokenPolicy& value)
    {
        return !this->operator==(value);
    }
    
    void
    UserTokenPolicy::copyTo(UserTokenPolicy& value)
    {
        policyId_.copyTo(value.policyId());
        tokenType_.copyTo(value.tokenType());
        issuedTokenType_.copyTo(value.issuedTokenType());
        issuerEndpointUrl_.copyTo(value.issuerEndpointUrl());
        securityPolicyUri_.copyTo(value.securityPolicyUri());
    }
    
    UserTokenPolicy&
    UserTokenPolicy::operator=(const UserTokenPolicy& value)
    {
        const_cast<UserTokenPolicy*>(&value)->copyTo(*this);
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
    UserTokenPolicy::factory(void)
    {
    	return constructSPtr<UserTokenPolicy>();
    }
    
    std::string
    UserTokenPolicy::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    UserTokenPolicy::typeName(void)
    {
    	return "UserTokenPolicy";
    }
    
    OpcUaNodeId
    UserTokenPolicy::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)304,0);
    }
    
    OpcUaNodeId
    UserTokenPolicy::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)306, 0);
    }
    
    OpcUaNodeId
    UserTokenPolicy::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)305, 0);
    }
    
    OpcUaNodeId
    UserTokenPolicy::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15098, 0);
    }
    
    void
    UserTokenPolicy::opcUaBinaryEncode(std::ostream& os) const
    {
        policyId_.opcUaBinaryEncode(os);
        tokenType_.opcUaBinaryEncode(os);
        issuedTokenType_.opcUaBinaryEncode(os);
        issuerEndpointUrl_.opcUaBinaryEncode(os);
        securityPolicyUri_.opcUaBinaryEncode(os);
    }
    
    void
    UserTokenPolicy::opcUaBinaryDecode(std::istream& is)
    {
        policyId_.opcUaBinaryDecode(is);
        tokenType_.opcUaBinaryDecode(is);
        issuedTokenType_.opcUaBinaryDecode(is);
        issuerEndpointUrl_.opcUaBinaryDecode(is);
        securityPolicyUri_.opcUaBinaryDecode(is);
    }
    
    bool
    UserTokenPolicy::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    UserTokenPolicy::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    UserTokenPolicy::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    UserTokenPolicy::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!policyId_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("PolicyId", elementTree));
    
        elementTree.clear();
        if (!tokenType_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("TokenType", elementTree));
    
        elementTree.clear();
        if (!issuedTokenType_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("IssuedTokenType", elementTree));
    
        elementTree.clear();
        if (!issuerEndpointUrl_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("IssuerEndpointUrl", elementTree));
    
        elementTree.clear();
        if (!securityPolicyUri_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("SecurityPolicyUri", elementTree));
    
        return true;
    }
    
    bool
    UserTokenPolicy::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    UserTokenPolicy::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("PolicyId");
        if (!tree) return false;
        if (!policyId_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("TokenType");
        if (!tree) return false;
        if (!tokenType_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("IssuedTokenType");
        if (!tree) return false;
        if (!issuedTokenType_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("IssuerEndpointUrl");
        if (!tree) return false;
        if (!issuerEndpointUrl_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("SecurityPolicyUri");
        if (!tree) return false;
        if (!securityPolicyUri_.xmlDecode(*tree, xmlns)) return false;
    
        return true;
    }
    
    bool
    UserTokenPolicy::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    UserTokenPolicy::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    UserTokenPolicy::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    UserTokenPolicy::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    UserTokenPolicy::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	UserTokenPolicy* dst = dynamic_cast<UserTokenPolicy*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    UserTokenPolicy::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	UserTokenPolicy* dst = dynamic_cast<UserTokenPolicy*>(&extensionObjectBase);
    	return *const_cast<UserTokenPolicy*>(this) == *dst;
    }
    
    void
    UserTokenPolicy::out(std::ostream& os)
    {
        os << "PolicyId="; policyId_.out(os);
        os << ", TokenType="; tokenType_.out(os);
        os << ", IssuedTokenType="; issuedTokenType_.out(os);
        os << ", IssuerEndpointUrl="; issuerEndpointUrl_.out(os);
        os << ", SecurityPolicyUri="; securityPolicyUri_.out(os);
    }

}
