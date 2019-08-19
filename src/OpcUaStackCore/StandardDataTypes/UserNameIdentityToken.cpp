/*
    DataTypeClass: UserNameIdentityToken

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/UserNameIdentityToken.h"

namespace OpcUaStackCore
{
    
    /**
     * A token representing a user identified by a user name and password.
     */
    UserNameIdentityToken::UserNameIdentityToken(void)
    : UserIdentityToken()
    , userName_()
    , password_()
    , encryptionAlgorithm_()
    {
    }
    
    /**
     * A token representing a user identified by a user name and password.
     */
    UserNameIdentityToken::UserNameIdentityToken(const UserNameIdentityToken& value)
    : UserIdentityToken()
    , userName_()
    , password_()
    , encryptionAlgorithm_()
    {
        const_cast<UserNameIdentityToken*>(&value)->copyTo(*this);
    }
    
    UserNameIdentityToken::~UserNameIdentityToken(void)
    {
    }
    
    OpcUaString&
    UserNameIdentityToken::userName(void)
    {
        return userName_;
    }
    
    OpcUaByteString&
    UserNameIdentityToken::password(void)
    {
        return password_;
    }
    
    OpcUaString&
    UserNameIdentityToken::encryptionAlgorithm(void)
    {
        return encryptionAlgorithm_;
    }
    
    bool
    UserNameIdentityToken::operator==(const UserNameIdentityToken& value)
    {
        UserNameIdentityToken* dst = const_cast<UserNameIdentityToken*>(&value);
        if (userName_ != dst->userName()) return false;
        if (password_ != dst->password()) return false;
        if (encryptionAlgorithm_ != dst->encryptionAlgorithm()) return false;
        return true;
    }
    
    bool
    UserNameIdentityToken::operator!=(const UserNameIdentityToken& value)
    {
        return !this->operator==(value);
    }
    
    void
    UserNameIdentityToken::copyTo(UserNameIdentityToken& value)
    {
        userName_.copyTo(value.userName());
        password_.copyTo(value.password());
        encryptionAlgorithm_.copyTo(value.encryptionAlgorithm());
    }
    
    UserNameIdentityToken&
    UserNameIdentityToken::operator=(const UserNameIdentityToken& value)
    {
        const_cast<UserNameIdentityToken*>(&value)->copyTo(*this);
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
    UserNameIdentityToken::factory(void)
    {
    	return boost::make_shared<UserNameIdentityToken>();
    }
    
    std::string
    UserNameIdentityToken::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    UserNameIdentityToken::typeName(void)
    {
    	return "UserNameIdentityToken";
    }
    
    OpcUaNodeId
    UserNameIdentityToken::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)322,0);
    }
    
    OpcUaNodeId
    UserNameIdentityToken::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)324, 0);
    }
    
    OpcUaNodeId
    UserNameIdentityToken::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)323, 0);
    }
    
    OpcUaNodeId
    UserNameIdentityToken::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15142, 0);
    }
    
    void
    UserNameIdentityToken::opcUaBinaryEncode(std::ostream& os) const
    {
        UserIdentityToken::opcUaBinaryEncode(os);
        userName_.opcUaBinaryEncode(os);
        password_.opcUaBinaryEncode(os);
        encryptionAlgorithm_.opcUaBinaryEncode(os);
    }
    
    void
    UserNameIdentityToken::opcUaBinaryDecode(std::istream& is)
    {
        UserIdentityToken::opcUaBinaryDecode(is);
        userName_.opcUaBinaryDecode(is);
        password_.opcUaBinaryDecode(is);
        encryptionAlgorithm_.opcUaBinaryDecode(is);
    }
    
    bool
    UserNameIdentityToken::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "UserNameIdentityToken encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    UserNameIdentityToken::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!userName_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "UserNameIdentityToken encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("UserName", elementTree));
    
        elementTree.clear();
        if (!password_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "UserNameIdentityToken encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Password", elementTree));
    
        elementTree.clear();
        if (!encryptionAlgorithm_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "UserNameIdentityToken encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("EncryptionAlgorithm", elementTree));
    
        return true;
    }
    
    bool
    UserNameIdentityToken::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UserNameIdentityToken decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    UserNameIdentityToken::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("UserName");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UserNameIdentityToken decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!userName_.xmlDecode(*tree, xmlns)) {
            Log(Error, "UserNameIdentityToken decode xml error - decode failed")
                .parameter("Element", "UserName");
            return false;
        }
    
        elementName = xmlns.addPrefix("Password");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UserNameIdentityToken decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!password_.xmlDecode(*tree, xmlns)) {
            Log(Error, "UserNameIdentityToken decode xml error - decode failed")
                .parameter("Element", "Password");
            return false;
        }
    
        elementName = xmlns.addPrefix("EncryptionAlgorithm");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UserNameIdentityToken decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!encryptionAlgorithm_.xmlDecode(*tree, xmlns)) {
            Log(Error, "UserNameIdentityToken decode xml error - decode failed")
                .parameter("Element", "EncryptionAlgorithm");
            return false;
        }
    
        return true;
    }
    
    bool
    UserNameIdentityToken::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        bool rc = true;
    
        rc = rc & jsonObjectEncode(pt, userName_, "UserName", true);
        rc = rc & jsonObjectEncode(pt, password_, "Password", true);
        rc = rc & jsonObjectEncode(pt, encryptionAlgorithm_, "EncryptionAlgorithm", true);
    
        return rc;
    }
    
    bool
    UserNameIdentityToken::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        bool rc = true;
    
        rc = rc & jsonObjectDecode(pt, userName_, "UserName", true);
        rc = rc & jsonObjectDecode(pt, password_, "Password", true);
        rc = rc & jsonObjectDecode(pt, encryptionAlgorithm_, "EncryptionAlgorithm", true);
    
        return rc;
    }
    
    void
    UserNameIdentityToken::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	UserNameIdentityToken* dst = dynamic_cast<UserNameIdentityToken*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    UserNameIdentityToken::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	UserNameIdentityToken* dst = dynamic_cast<UserNameIdentityToken*>(&extensionObjectBase);
    	return *const_cast<UserNameIdentityToken*>(this) == *dst;
    }
    
    void
    UserNameIdentityToken::out(std::ostream& os)
    {
        os << "UserName="; userName_.out(os);
        os << ", Password="; password_.out(os);
        os << ", EncryptionAlgorithm="; encryptionAlgorithm_.out(os);
    }

}
