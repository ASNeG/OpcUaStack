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
    EnumValueType::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    EnumValueType::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    EnumValueType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    EnumValueType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, value_)) return false;
        pt.push_back(std::make_pair("Value", elementTree));
    
        elementTree.clear();
        if (!displayName_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("DisplayName", elementTree));
    
        elementTree.clear();
        if (!description_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("Description", elementTree));
    
        return true;
    }
    
    bool
    EnumValueType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    EnumValueType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("Value");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, value_)) return false;
    
        tree = pt.get_child_optional("DisplayName");
        if (!tree) return false;
        if (!displayName_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("Description");
        if (!tree) return false;
        if (!description_.xmlDecode(*tree, xmlns)) return false;
    
        return true;
    }
    
    bool
    EnumValueType::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    EnumValueType::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    EnumValueType::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    EnumValueType::jsonDecode(boost::property_tree::ptree& pt)
    {
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
