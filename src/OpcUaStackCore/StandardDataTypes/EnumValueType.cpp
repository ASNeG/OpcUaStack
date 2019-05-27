/*
    DataTypeClass: EnumValueType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/EnumValueType.h"

namespace OpcUaStackCore
{
    
    /**
     * A mapping between a value of an enumerated type and a name and description.
     */
    EnumValueType::EnumValueType(void)
    : Object()
    , ExtensionObjectBase()
    , value_()
    , displayName_()
    , description_()
    {
    }
    
    /**
     * A mapping between a value of an enumerated type and a name and description.
     */
    EnumValueType::EnumValueType(const EnumValueType& value)
    : Object()
    , ExtensionObjectBase()
    , value_()
    , displayName_()
    , description_()
    {
        const_cast<EnumValueType*>(&value)->copyTo(*this);
    }
    
    EnumValueType::~EnumValueType(void)
    {
    }
    
    OpcUaInt64&
    EnumValueType::value(void)
    {
        return value_;
    }
    
    OpcUaLocalizedText&
    EnumValueType::displayName(void)
    {
        return displayName_;
    }
    
    OpcUaLocalizedText&
    EnumValueType::description(void)
    {
        return description_;
    }
    
    bool
    EnumValueType::operator==(const EnumValueType& value)
    {
        EnumValueType* dst = const_cast<EnumValueType*>(&value);
        if (value_ != dst->value()) return false;
        if (displayName_ != dst->displayName()) return false;
        if (description_ != dst->description()) return false;
        return true;
    }
    
    bool
    EnumValueType::operator!=(const EnumValueType& value)
    {
        return !this->operator==(value);
    }
    
    void
    EnumValueType::copyTo(EnumValueType& value)
    {
        value.value_ = value_;
        displayName_.copyTo(value.displayName());
        description_.copyTo(value.description());
    }
    
    EnumValueType&
    EnumValueType::operator=(const EnumValueType& value)
    {
        const_cast<EnumValueType*>(&value)->copyTo(*this);
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
    EnumValueType::factory(void)
    {
    	return constructSPtr<EnumValueType>();
    }
    
    std::string
    EnumValueType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    EnumValueType::typeName(void)
    {
    	return "EnumValueType";
    }
    
    OpcUaNodeId
    EnumValueType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)7594,0);
    }
    
    OpcUaNodeId
    EnumValueType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)8251, 0);
    }
    
    OpcUaNodeId
    EnumValueType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)7616, 0);
    }
    
    OpcUaNodeId
    EnumValueType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15082, 0);
    }
    
    void
    EnumValueType::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os,value_);
        displayName_.opcUaBinaryEncode(os);
        description_.opcUaBinaryEncode(os);
    }
    
    void
    EnumValueType::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is,value_);
        displayName_.opcUaBinaryDecode(is);
        description_.opcUaBinaryDecode(is);
    }
    
    bool
    EnumValueType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "EnumValueType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    EnumValueType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, value_))
        {
            Log(Error, "EnumValueType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Value", elementTree));
    
        elementTree.clear();
        if (!displayName_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "EnumValueType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DisplayName", elementTree));
    
        elementTree.clear();
        if (!description_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "EnumValueType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Description", elementTree));
    
        return true;
    }
    
    bool
    EnumValueType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EnumValueType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    EnumValueType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("Value");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EnumValueType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, value_)) {
            Log(Error, "EnumValueType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("DisplayName");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EnumValueType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!displayName_.xmlDecode(*tree, xmlns)) {
            Log(Error, "EnumValueType decode xml error - decode failed")
                .parameter("Element", "DisplayName");
            return false;
        }
    
        elementName = xmlns.addPrefix("Description");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EnumValueType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!description_.xmlDecode(*tree, xmlns)) {
            Log(Error, "EnumValueType decode xml error - decode failed")
                .parameter("Element", "Description");
            return false;
        }
    
        return true;
    }
    
    bool
    EnumValueType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, value_))
        {
    	     Log(Error, "EnumValueType json encoder error")
    		     .parameter("Element", "value_");
           return false;
        }
        pt.push_back(std::make_pair("Value", elementTree));
    
        elementTree.clear();
        if (!displayName_.jsonEncode(elementTree))
        {
    	     Log(Error, "EnumValueType json encoder error")
    		     .parameter("Element", "displayName_");
            return false;
        }
        pt.push_back(std::make_pair("DisplayName", elementTree));
    
        elementTree.clear();
        if (!description_.jsonEncode(elementTree))
        {
    	     Log(Error, "EnumValueType json encoder error")
    		     .parameter("Element", "description_");
            return false;
        }
        pt.push_back(std::make_pair("Description", elementTree));
    
        return true;
    }
    
    bool
    EnumValueType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "Value";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EnumValueType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, value_)) {
            Log(Error, "EnumValueType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "DisplayName";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EnumValueType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!displayName_.jsonDecode(*tree)) {
            Log(Error, "EnumValueType decode json error - decode failed")
                .parameter("Element", "DisplayName");
            return false;
        }
    
        elementName = "Description";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EnumValueType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!description_.jsonDecode(*tree)) {
            Log(Error, "EnumValueType decode json error - decode failed")
                .parameter("Element", "Description");
            return false;
        }
    
        return true;
    }
    
    void
    EnumValueType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	EnumValueType* dst = dynamic_cast<EnumValueType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    EnumValueType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	EnumValueType* dst = dynamic_cast<EnumValueType*>(&extensionObjectBase);
    	return *const_cast<EnumValueType*>(this) == *dst;
    }
    
    void
    EnumValueType::out(std::ostream& os)
    {
        os << "Value=" << value_;
        os << ", DisplayName="; displayName_.out(os);
        os << ", Description="; description_.out(os);
    }

}
