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
    
    KeyValuePair::KeyValuePair(const KeyValuePair& value)
    : Object()
    , ExtensionObjectBase()
    , key_()
    , value_()
    {
        const_cast<KeyValuePair*>(&value)->copyTo(*this);
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
    KeyValuePair::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "KeyValuePair encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    KeyValuePair::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!key_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "KeyValuePair encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Key", elementTree));
    
        elementTree.clear();
        if (!value_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "KeyValuePair encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Value", elementTree));
    
        return true;
    }
    
    bool
    KeyValuePair::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "KeyValuePair decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    KeyValuePair::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("Key");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "KeyValuePair decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!key_.xmlDecode(*tree, xmlns)) {
            Log(Error, "KeyValuePair decode xml error - decode failed")
                .parameter("Element", "Key");
            return false;
        }
    
        elementName = xmlns.addPrefix("Value");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "KeyValuePair decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!value_.xmlDecode(*tree, xmlns)) {
            Log(Error, "KeyValuePair decode xml error - decode failed")
                .parameter("Element", "Value");
            return false;
        }
    
        return true;
    }
    
    bool
    KeyValuePair::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!key_.jsonEncode(elementTree))
        {
    	     Log(Error, "KeyValuePair json encoder error")
    		     .parameter("Element", "key_");
            return false;
        }
        pt.push_back(std::make_pair("Key", elementTree));
    
        elementTree.clear();
        if (!value_.jsonEncode(elementTree))
        {
    	     Log(Error, "KeyValuePair json encoder error")
    		     .parameter("Element", "value_");
            return false;
        }
        pt.push_back(std::make_pair("Value", elementTree));
    
        return true;
    }
    
    bool
    KeyValuePair::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "Key";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "KeyValuePair decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!key_.jsonDecode(*tree)) {
            Log(Error, "KeyValuePair decode json error - decode failed")
                .parameter("Element", "Key");
            return false;
        }
    
        elementName = "Value";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "KeyValuePair decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!value_.jsonDecode(*tree)) {
            Log(Error, "KeyValuePair decode json error - decode failed")
                .parameter("Element", "Value");
            return false;
        }
    
        return true;
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
