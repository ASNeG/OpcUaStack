/*
    DataTypeClass: IssuedIdentityToken

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/IssuedIdentityToken.h"

namespace OpcUaStackCore
{
    
    /**
     * A token representing a user identified by a WS-Security XML token.
     */
    IssuedIdentityToken::IssuedIdentityToken(void)
    : UserIdentityToken()
    , tokenData_()
    , encryptionAlgorithm_()
    {
    }
    
    IssuedIdentityToken::~IssuedIdentityToken(void)
    {
    }
    
    OpcUaByteString&
    IssuedIdentityToken::tokenData(void)
    {
        return tokenData_;
    }
    
    OpcUaString&
    IssuedIdentityToken::encryptionAlgorithm(void)
    {
        return encryptionAlgorithm_;
    }
    
    bool
    IssuedIdentityToken::operator==(const IssuedIdentityToken& value)
    {
        IssuedIdentityToken* dst = const_cast<IssuedIdentityToken*>(&value);
        if (tokenData_ != dst->tokenData()) return false;
        if (encryptionAlgorithm_ != dst->encryptionAlgorithm()) return false;
        return true;
    }
    
    bool
    IssuedIdentityToken::operator!=(const IssuedIdentityToken& value)
    {
        return !this->operator==(value);
    }
    
    void
    IssuedIdentityToken::copyTo(IssuedIdentityToken& value)
    {
        tokenData_.copyTo(value.tokenData());
        encryptionAlgorithm_.copyTo(value.encryptionAlgorithm());
    }
    
    IssuedIdentityToken&
    IssuedIdentityToken::operator=(const IssuedIdentityToken& value)
    {
        const_cast<IssuedIdentityToken*>(&value)->copyTo(*this);
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
    IssuedIdentityToken::factory(void)
    {
    	return constructSPtr<IssuedIdentityToken>();
    }
    
    std::string
    IssuedIdentityToken::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    IssuedIdentityToken::typeName(void)
    {
    	return "IssuedIdentityToken";
    }
    
    OpcUaNodeId
    IssuedIdentityToken::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)938,0);
    }
    
    OpcUaNodeId
    IssuedIdentityToken::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)940, 0);
    }
    
    OpcUaNodeId
    IssuedIdentityToken::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)939, 0);
    }
    
    OpcUaNodeId
    IssuedIdentityToken::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15144, 0);
    }
    
    void
    IssuedIdentityToken::opcUaBinaryEncode(std::ostream& os) const
    {
       UserIdentityToken::opcUaBinaryEncode(os);
        tokenData_.opcUaBinaryEncode(os);
        encryptionAlgorithm_.opcUaBinaryEncode(os);
    }
    
    void
    IssuedIdentityToken::opcUaBinaryDecode(std::istream& is)
    {
       UserIdentityToken::opcUaBinaryDecode(is);
        tokenData_.opcUaBinaryDecode(is);
        encryptionAlgorithm_.opcUaBinaryDecode(is);
    }
    
    bool
    IssuedIdentityToken::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    IssuedIdentityToken::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    IssuedIdentityToken::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    IssuedIdentityToken::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!tokenData_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("TokenData", elementTree));
    
        elementTree.clear();
        if (!encryptionAlgorithm_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("EncryptionAlgorithm", elementTree));
    
        return true;
    }
    
    bool
    IssuedIdentityToken::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    IssuedIdentityToken::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("TokenData");
        if (!tree) return false;
        if (!tokenData_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("EncryptionAlgorithm");
        if (!tree) return false;
        if (!encryptionAlgorithm_.xmlDecode(*tree, xmlns)) return false;
    
        return true;
    }
    
    bool
    IssuedIdentityToken::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    IssuedIdentityToken::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    IssuedIdentityToken::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    IssuedIdentityToken::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    IssuedIdentityToken::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	IssuedIdentityToken* dst = dynamic_cast<IssuedIdentityToken*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    IssuedIdentityToken::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	IssuedIdentityToken* dst = dynamic_cast<IssuedIdentityToken*>(&extensionObjectBase);
    	return *const_cast<IssuedIdentityToken*>(this) == *dst;
    }
    
    void
    IssuedIdentityToken::out(std::ostream& os)
    {
        os << "TokenData="; tokenData_.out(os);
        os << ", EncryptionAlgorithm="; encryptionAlgorithm_.out(os);
    }

}
