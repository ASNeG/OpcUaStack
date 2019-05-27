/*
    DataTypeClass: EnumDescription

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/EnumDescription.h"

namespace OpcUaStackCore
{
    
    EnumDescription::EnumDescription(void)
    : DataTypeDescription()
    , enumDefinition_()
    , builtInType_()
    {
    }
    
    EnumDescription::EnumDescription(const EnumDescription& value)
    : DataTypeDescription()
    , enumDefinition_()
    , builtInType_()
    {
        const_cast<EnumDescription*>(&value)->copyTo(*this);
    }
    
    EnumDescription::~EnumDescription(void)
    {
    }
    
    EnumDefinition&
    EnumDescription::enumDefinition(void)
    {
        return enumDefinition_;
    }
    
    OpcUaByte&
    EnumDescription::builtInType(void)
    {
        return builtInType_;
    }
    
    bool
    EnumDescription::operator==(const EnumDescription& value)
    {
        EnumDescription* dst = const_cast<EnumDescription*>(&value);
        if (enumDefinition_ != dst->enumDefinition()) return false;
        if (builtInType_ != dst->builtInType()) return false;
        return true;
    }
    
    bool
    EnumDescription::operator!=(const EnumDescription& value)
    {
        return !this->operator==(value);
    }
    
    void
    EnumDescription::copyTo(EnumDescription& value)
    {
        enumDefinition_.copyTo(value.enumDefinition());
        value.builtInType_ = builtInType_;
    }
    
    EnumDescription&
    EnumDescription::operator=(const EnumDescription& value)
    {
        const_cast<EnumDescription*>(&value)->copyTo(*this);
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
    EnumDescription::factory(void)
    {
    	return constructSPtr<EnumDescription>();
    }
    
    std::string
    EnumDescription::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    EnumDescription::typeName(void)
    {
    	return "EnumDescription";
    }
    
    OpcUaNodeId
    EnumDescription::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15488,0);
    }
    
    OpcUaNodeId
    EnumDescription::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)127, 0);
    }
    
    OpcUaNodeId
    EnumDescription::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15590, 0);
    }
    
    OpcUaNodeId
    EnumDescription::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15059, 0);
    }
    
    void
    EnumDescription::opcUaBinaryEncode(std::ostream& os) const
    {
        DataTypeDescription::opcUaBinaryEncode(os);
        enumDefinition_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,builtInType_);
    }
    
    void
    EnumDescription::opcUaBinaryDecode(std::istream& is)
    {
        DataTypeDescription::opcUaBinaryDecode(is);
        enumDefinition_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,builtInType_);
    }
    
    bool
    EnumDescription::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "EnumDescription encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    EnumDescription::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!enumDefinition_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "EnumDescription encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("EnumDefinition", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, builtInType_))
        {
            Log(Error, "EnumDescription encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("BuiltInType", elementTree));
    
        return true;
    }
    
    bool
    EnumDescription::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EnumDescription decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    EnumDescription::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("EnumDefinition");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EnumDescription decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!enumDefinition_.xmlDecode(*tree, xmlns)) {
            Log(Error, "EnumDescription decode xml error - decode failed")
                .parameter("Element", "EnumDefinition");
            return false;
        }
    
        elementName = xmlns.addPrefix("BuiltInType");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EnumDescription decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, builtInType_)) {
            Log(Error, "EnumDescription decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    EnumDescription::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!enumDefinition_.jsonEncode(elementTree))
        {
    	     Log(Error, "EnumDescription json encoder error")
    		     .parameter("Element", "enumDefinition_");
            return false;
        }
        pt.push_back(std::make_pair("EnumDefinition", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, builtInType_))
        {
    	     Log(Error, "EnumDescription json encoder error")
    		     .parameter("Element", "builtInType_");
           return false;
        }
        pt.push_back(std::make_pair("BuiltInType", elementTree));
    
        return true;
    }
    
    bool
    EnumDescription::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "EnumDefinition";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EnumDescription decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!enumDefinition_.jsonDecode(*tree)) {
            Log(Error, "EnumDescription decode json error - decode failed")
                .parameter("Element", "EnumDefinition");
            return false;
        }
    
        elementName = "BuiltInType";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EnumDescription decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, builtInType_)) {
            Log(Error, "EnumDescription decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    EnumDescription::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	EnumDescription* dst = dynamic_cast<EnumDescription*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    EnumDescription::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	EnumDescription* dst = dynamic_cast<EnumDescription*>(&extensionObjectBase);
    	return *const_cast<EnumDescription*>(this) == *dst;
    }
    
    void
    EnumDescription::out(std::ostream& os)
    {
        os << "EnumDefinition="; enumDefinition_.out(os);
        os << ", BuiltInType=" << builtInType_;
    }

}
