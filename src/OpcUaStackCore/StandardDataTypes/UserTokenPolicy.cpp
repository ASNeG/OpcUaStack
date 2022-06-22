/*
    DataTypeClass: UserTokenPolicy

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/UserTokenPolicy.h"
#include "OpcUaStackCore/Base/Log.h"

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
    
    /**
     * Describes a user token that can be used with a server.
     */
    UserTokenPolicy::UserTokenPolicy(const UserTokenPolicy& value)
    : Object()
    , ExtensionObjectBase()
    , policyId_()
    , tokenType_()
    , issuedTokenType_()
    , issuerEndpointUrl_()
    , securityPolicyUri_()
    {
        const_cast<UserTokenPolicy*>(&value)->copyTo(*this);
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
    	return boost::make_shared<UserTokenPolicy>();
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
    
    bool
    UserTokenPolicy::opcUaBinaryEncode(std::ostream& os) const
    {
        bool rc = true;
    
        rc &= policyId_.opcUaBinaryEncode(os);
        rc &= tokenType_.opcUaBinaryEncode(os);
        rc &= binaryEncodeOptional(issuedTokenType_, os);
        rc &= binaryEncodeOptional(issuerEndpointUrl_, os);
        rc &= binaryEncodeOptional(securityPolicyUri_, os);
        return rc;
    }
    
    bool
    UserTokenPolicy::binaryEncodeOptional(OpcUaString str, std::ostream& os) const
    {
        if (str.value().empty()) {
            return OpcUaNumber::opcUaBinaryEncode(os, (const OpcUaInt32)-1);
        }
        return str.opcUaBinaryEncode(os);
    }

    bool
    UserTokenPolicy::opcUaBinaryDecode(std::istream& is)
    {
        bool rc = true;
    
        rc &= policyId_.opcUaBinaryDecode(is);
        rc &= tokenType_.opcUaBinaryDecode(is);
        rc &= issuedTokenType_.opcUaBinaryDecode(is);
        rc &= issuerEndpointUrl_.opcUaBinaryDecode(is);
        rc &= securityPolicyUri_.opcUaBinaryDecode(is);
        return rc;
    }
    
    bool
    UserTokenPolicy::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "UserTokenPolicy encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    UserTokenPolicy::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!policyId_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "UserTokenPolicy encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("PolicyId", elementTree));
    
        elementTree.clear();
        if (!tokenType_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "UserTokenPolicy encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("TokenType", elementTree));
    
        elementTree.clear();
        if (!issuedTokenType_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "UserTokenPolicy encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("IssuedTokenType", elementTree));
    
        elementTree.clear();
        if (!issuerEndpointUrl_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "UserTokenPolicy encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("IssuerEndpointUrl", elementTree));
    
        elementTree.clear();
        if (!securityPolicyUri_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "UserTokenPolicy encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SecurityPolicyUri", elementTree));
    
        return true;
    }
    
    bool
    UserTokenPolicy::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UserTokenPolicy decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    UserTokenPolicy::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("PolicyId");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UserTokenPolicy decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!policyId_.xmlDecode(*tree, xmlns)) {
            Log(Error, "UserTokenPolicy decode xml error - decode failed")
                .parameter("Element", "PolicyId");
            return false;
        }
    
        elementName = xmlns.addPrefix("TokenType");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UserTokenPolicy decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!tokenType_.xmlDecode(*tree, xmlns)) {
            Log(Error, "UserTokenPolicy decode xml error - decode failed")
                .parameter("Element", "TokenType");
            return false;
        }
    
        elementName = xmlns.addPrefix("IssuedTokenType");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UserTokenPolicy decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!issuedTokenType_.xmlDecode(*tree, xmlns)) {
            Log(Error, "UserTokenPolicy decode xml error - decode failed")
                .parameter("Element", "IssuedTokenType");
            return false;
        }
    
        elementName = xmlns.addPrefix("IssuerEndpointUrl");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UserTokenPolicy decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!issuerEndpointUrl_.xmlDecode(*tree, xmlns)) {
            Log(Error, "UserTokenPolicy decode xml error - decode failed")
                .parameter("Element", "IssuerEndpointUrl");
            return false;
        }
    
        elementName = xmlns.addPrefix("SecurityPolicyUri");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UserTokenPolicy decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!securityPolicyUri_.xmlDecode(*tree, xmlns)) {
            Log(Error, "UserTokenPolicy decode xml error - decode failed")
                .parameter("Element", "SecurityPolicyUri");
            return false;
        }
    
        return true;
    }
    
    bool
    UserTokenPolicy::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        bool rc = true;
    
        rc = rc & jsonObjectEncode(pt, policyId_, "PolicyId", true);
        rc = rc & jsonObjectEncode(pt, tokenType_, "TokenType", true);
        rc = rc & jsonObjectEncode(pt, issuedTokenType_, "IssuedTokenType", true);
        rc = rc & jsonObjectEncode(pt, issuerEndpointUrl_, "IssuerEndpointUrl", true);
        rc = rc & jsonObjectEncode(pt, securityPolicyUri_, "SecurityPolicyUri", true);
    
        return rc;
    }
    
    bool
    UserTokenPolicy::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        bool rc = true;
    
        rc = rc & jsonObjectDecode(pt, policyId_, "PolicyId", true);
        rc = rc & jsonObjectDecode(pt, tokenType_, "TokenType", true);
        rc = rc & jsonObjectDecode(pt, issuedTokenType_, "IssuedTokenType", true);
        rc = rc & jsonObjectDecode(pt, issuerEndpointUrl_, "IssuerEndpointUrl", true);
        rc = rc & jsonObjectDecode(pt, securityPolicyUri_, "SecurityPolicyUri", true);
    
        return rc;
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
