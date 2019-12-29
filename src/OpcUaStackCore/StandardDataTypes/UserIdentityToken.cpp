/*
    DataTypeClass: UserIdentityToken

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/UserIdentityToken.h"

namespace OpcUaStackCore
{
    
    /**
     * A base type for a user identity token.
     */
    UserIdentityToken::UserIdentityToken(void)
    : Object()
    , ExtensionObjectBase()
    , policyId_()
    {
    }
    
    /**
     * A base type for a user identity token.
     */
    UserIdentityToken::UserIdentityToken(const UserIdentityToken& value)
    : Object()
    , ExtensionObjectBase()
    , policyId_()
    {
        const_cast<UserIdentityToken*>(&value)->copyTo(*this);
    }
    
    UserIdentityToken::~UserIdentityToken(void)
    {
    }
    
    OpcUaString&
    UserIdentityToken::policyId(void)
    {
        return policyId_;
    }
    
    bool
    UserIdentityToken::operator==(const UserIdentityToken& value)
    {
        UserIdentityToken* dst = const_cast<UserIdentityToken*>(&value);
        if (policyId_ != dst->policyId()) return false;
        return true;
    }
    
    bool
    UserIdentityToken::operator!=(const UserIdentityToken& value)
    {
        return !this->operator==(value);
    }
    
    void
    UserIdentityToken::copyTo(UserIdentityToken& value)
    {
        policyId_.copyTo(value.policyId());
    }
    
    UserIdentityToken&
    UserIdentityToken::operator=(const UserIdentityToken& value)
    {
        const_cast<UserIdentityToken*>(&value)->copyTo(*this);
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
    UserIdentityToken::factory(void)
    {
    	return boost::make_shared<UserIdentityToken>();
    }
    
    std::string
    UserIdentityToken::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    UserIdentityToken::typeName(void)
    {
    	return "UserIdentityToken";
    }
    
    OpcUaNodeId
    UserIdentityToken::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)316,0);
    }
    
    OpcUaNodeId
    UserIdentityToken::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)318, 0);
    }
    
    OpcUaNodeId
    UserIdentityToken::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)317, 0);
    }
    
    OpcUaNodeId
    UserIdentityToken::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15140, 0);
    }
    
    bool
    UserIdentityToken::opcUaBinaryEncode(std::ostream& os) const
    {
        bool rc = true;
    
        rc &= policyId_.opcUaBinaryEncode(os);
        return rc;
    }
    
    bool
    UserIdentityToken::opcUaBinaryDecode(std::istream& is)
    {
        bool rc = true;
    
        rc &= policyId_.opcUaBinaryDecode(is);
        return rc;
    }
    
    bool
    UserIdentityToken::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "UserIdentityToken encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    UserIdentityToken::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!policyId_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "UserIdentityToken encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("PolicyId", elementTree));
    
        return true;
    }
    
    bool
    UserIdentityToken::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UserIdentityToken decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    UserIdentityToken::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("PolicyId");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UserIdentityToken decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!policyId_.xmlDecode(*tree, xmlns)) {
            Log(Error, "UserIdentityToken decode xml error - decode failed")
                .parameter("Element", "PolicyId");
            return false;
        }
    
        return true;
    }
    
    bool
    UserIdentityToken::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        bool rc = true;
    
        rc = rc & jsonObjectEncode(pt, policyId_, "PolicyId", true);
    
        return rc;
    }
    
    bool
    UserIdentityToken::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        bool rc = true;
    
        rc = rc & jsonObjectDecode(pt, policyId_, "PolicyId", true);
    
        return rc;
    }
    
    void
    UserIdentityToken::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	UserIdentityToken* dst = dynamic_cast<UserIdentityToken*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    UserIdentityToken::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	UserIdentityToken* dst = dynamic_cast<UserIdentityToken*>(&extensionObjectBase);
    	return *const_cast<UserIdentityToken*>(this) == *dst;
    }
    
    void
    UserIdentityToken::out(std::ostream& os)
    {
        os << "PolicyId="; policyId_.out(os);
    }

}
