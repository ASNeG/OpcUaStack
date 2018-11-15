/*
    DataTypeClass: KeyValuePair

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/KeyValuePair.h"

namespace OpcUaStackCore
{
    
    KeyValuePair::KeyValuePair(void)
    : Object()
    , ExtensionObjectBase()
    , key_()
    , value_()
    {
    }
    
    KeyValuePair::~KeyValuePair(void)
    {
    }
    
    OpcUaQualifiedName&
    KeyValuePair::key(void)
    {
        return key_;
    }
    
    OpcUaVariant&
    KeyValuePair::value(void)
    {
        return value_;
    }
    
    bool
    KeyValuePair::operator==(const KeyValuePair& value)
    {
        KeyValuePair* dst = const_cast<KeyValuePair*>(&value);
        if (key_ != dst->key()) return false;
        if (value_ != dst->value()) return false;
        return true;
    }
    
    bool
    KeyValuePair::operator!=(const KeyValuePair& value)
    {
        return !this->operator==(value);
    }
    
    void
    KeyValuePair::copyTo(KeyValuePair& value)
    {
        key_.copyTo(value.key());
        value_.copyTo(value.value());
    }
    
    KeyValuePair&
    KeyValuePair::operator=(const KeyValuePair& value)
    {
        const_cast<KeyValuePair*>(&value)->copyTo(*this);
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
    KeyValuePair::factory(void)
    {
    	return constructSPtr<KeyValuePair>();
    }
    
    std::string
    KeyValuePair::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    KeyValuePair::typeName(void)
    {
    	return "KeyValuePair";
    }
    
    OpcUaNodeId
    KeyValuePair::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)14533,0);
    }
    
    OpcUaNodeId
    KeyValuePair::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)14846, 0);
    }
    
    OpcUaNodeId
    KeyValuePair::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)14802, 0);
    }
    
    OpcUaNodeId
    KeyValuePair::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15041, 0);
    }
    
    void
    KeyValuePair::opcUaBinaryEncode(std::ostream& os) const
    {
        key_.opcUaBinaryEncode(os);
        value_.opcUaBinaryEncode(os);
    }
    
    void
    KeyValuePair::opcUaBinaryDecode(std::istream& is)
    {
        key_.opcUaBinaryDecode(is);
        value_.opcUaBinaryDecode(is);
    }
    
    bool
    KeyValuePair::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    KeyValuePair::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    KeyValuePair::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    KeyValuePair::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!key_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("Key", elementTree));
    
        elementTree.clear();
        if (!value_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("Value", elementTree));
    
        return true;
    }
    
    bool
    KeyValuePair::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    KeyValuePair::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("Key");
        if (!tree) return false;
        if (!key_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("Value");
        if (!tree) return false;
        if (!value_.xmlDecode(*tree, xmlns)) return false;
    
        return true;
    }
    
    bool
    KeyValuePair::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    KeyValuePair::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    KeyValuePair::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    KeyValuePair::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    KeyValuePair::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	KeyValuePair* dst = dynamic_cast<KeyValuePair*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    KeyValuePair::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	KeyValuePair* dst = dynamic_cast<KeyValuePair*>(&extensionObjectBase);
    	return *const_cast<KeyValuePair*>(this) == *dst;
    }
    
    void
    KeyValuePair::out(std::ostream& os)
    {
        os << "Key="; key_.out(os);
        os << ", Value="; value_.out(os);
    }

}
