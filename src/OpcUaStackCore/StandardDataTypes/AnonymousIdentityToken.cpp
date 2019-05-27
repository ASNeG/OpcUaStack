/*
    DataTypeClass: AnonymousIdentityToken

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/AnonymousIdentityToken.h"

namespace OpcUaStackCore
{
    
    /**
     * A token representing an anonymous user.
     */
    AnonymousIdentityToken::AnonymousIdentityToken(void)
    : UserIdentityToken()
    {
    }
    
    /**
     * A token representing an anonymous user.
     */
    AnonymousIdentityToken::AnonymousIdentityToken(const AnonymousIdentityToken& value)
    : UserIdentityToken()
    {
        const_cast<AnonymousIdentityToken*>(&value)->copyTo(*this);
    }
    
    AnonymousIdentityToken::~AnonymousIdentityToken(void)
    {
    }
    
    bool
    AnonymousIdentityToken::operator==(const AnonymousIdentityToken& value)
    {
        AnonymousIdentityToken* dst = const_cast<AnonymousIdentityToken*>(&value);
        return true;
    }
    
    bool
    AnonymousIdentityToken::operator!=(const AnonymousIdentityToken& value)
    {
        return !this->operator==(value);
    }
    
    void
    AnonymousIdentityToken::copyTo(AnonymousIdentityToken& value)
    {
    }
    
    AnonymousIdentityToken&
    AnonymousIdentityToken::operator=(const AnonymousIdentityToken& value)
    {
        const_cast<AnonymousIdentityToken*>(&value)->copyTo(*this);
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
    AnonymousIdentityToken::factory(void)
    {
    	return constructSPtr<AnonymousIdentityToken>();
    }
    
    std::string
    AnonymousIdentityToken::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    AnonymousIdentityToken::typeName(void)
    {
    	return "AnonymousIdentityToken";
    }
    
    OpcUaNodeId
    AnonymousIdentityToken::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)319,0);
    }
    
    OpcUaNodeId
    AnonymousIdentityToken::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)321, 0);
    }
    
    OpcUaNodeId
    AnonymousIdentityToken::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)320, 0);
    }
    
    OpcUaNodeId
    AnonymousIdentityToken::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15141, 0);
    }
    
    void
    AnonymousIdentityToken::opcUaBinaryEncode(std::ostream& os) const
    {
        UserIdentityToken::opcUaBinaryEncode(os);
    }
    
    void
    AnonymousIdentityToken::opcUaBinaryDecode(std::istream& is)
    {
        UserIdentityToken::opcUaBinaryDecode(is);
    }
    
    bool
    AnonymousIdentityToken::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "AnonymousIdentityToken encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    AnonymousIdentityToken::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        return true;
    }
    
    bool
    AnonymousIdentityToken::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AnonymousIdentityToken decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    AnonymousIdentityToken::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        return true;
    }
    
    bool
    AnonymousIdentityToken::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        return true;
    }
    
    bool
    AnonymousIdentityToken::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        return true;
    }
    
    void
    AnonymousIdentityToken::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	AnonymousIdentityToken* dst = dynamic_cast<AnonymousIdentityToken*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    AnonymousIdentityToken::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	AnonymousIdentityToken* dst = dynamic_cast<AnonymousIdentityToken*>(&extensionObjectBase);
    	return *const_cast<AnonymousIdentityToken*>(this) == *dst;
    }
    
    void
    AnonymousIdentityToken::out(std::ostream& os)
    {
    }

}
