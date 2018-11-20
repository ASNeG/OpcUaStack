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
    	return constructSPtr<UserNameIdentityToken>();
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
    UserNameIdentityToken::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    UserNameIdentityToken::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    UserNameIdentityToken::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    UserNameIdentityToken::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!userName_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("UserName", elementTree));
    
        elementTree.clear();
        if (!password_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("Password", elementTree));
    
        elementTree.clear();
        if (!encryptionAlgorithm_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("EncryptionAlgorithm", elementTree));
    
        return true;
    }
    
    bool
    UserNameIdentityToken::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    UserNameIdentityToken::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("UserName");
        if (!tree) return false;
        if (!userName_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("Password");
        if (!tree) return false;
        if (!password_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("EncryptionAlgorithm");
        if (!tree) return false;
        if (!encryptionAlgorithm_.xmlDecode(*tree, xmlns)) return false;
    
        return true;
    }
    
    bool
    UserNameIdentityToken::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    UserNameIdentityToken::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    UserNameIdentityToken::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    UserNameIdentityToken::jsonDecode(boost::property_tree::ptree& pt)
    {
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
