/*
    DataTypeClass: SimpleTypeDescription

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/SimpleTypeDescription.h"

namespace OpcUaStackCore
{
    
    SimpleTypeDescription::SimpleTypeDescription(void)
    : DataTypeDescription()
    , baseDataType_()
    , builtInType_()
    {
    }
    
    SimpleTypeDescription::SimpleTypeDescription(const SimpleTypeDescription& value)
    : DataTypeDescription()
    , baseDataType_()
    , builtInType_()
    {
        const_cast<SimpleTypeDescription*>(&value)->copyTo(*this);
    }
    
    SimpleTypeDescription::~SimpleTypeDescription(void)
    {
    }
    
    OpcUaNodeId&
    SimpleTypeDescription::baseDataType(void)
    {
        return baseDataType_;
    }
    
    OpcUaByte&
    SimpleTypeDescription::builtInType(void)
    {
        return builtInType_;
    }
    
    bool
    SimpleTypeDescription::operator==(const SimpleTypeDescription& value)
    {
        SimpleTypeDescription* dst = const_cast<SimpleTypeDescription*>(&value);
        if (baseDataType_ != dst->baseDataType()) return false;
        if (builtInType_ != dst->builtInType()) return false;
        return true;
    }
    
    bool
    SimpleTypeDescription::operator!=(const SimpleTypeDescription& value)
    {
        return !this->operator==(value);
    }
    
    void
    SimpleTypeDescription::copyTo(SimpleTypeDescription& value)
    {
        baseDataType_.copyTo(value.baseDataType());
        value.builtInType_ = builtInType_;
    }
    
    SimpleTypeDescription&
    SimpleTypeDescription::operator=(const SimpleTypeDescription& value)
    {
        const_cast<SimpleTypeDescription*>(&value)->copyTo(*this);
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
    SimpleTypeDescription::factory(void)
    {
    	return constructSPtr<SimpleTypeDescription>();
    }
    
    std::string
    SimpleTypeDescription::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    SimpleTypeDescription::typeName(void)
    {
    	return "SimpleTypeDescription";
    }
    
    OpcUaNodeId
    SimpleTypeDescription::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15005,0);
    }
    
    OpcUaNodeId
    SimpleTypeDescription::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15421, 0);
    }
    
    OpcUaNodeId
    SimpleTypeDescription::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15529, 0);
    }
    
    OpcUaNodeId
    SimpleTypeDescription::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15700, 0);
    }
    
    void
    SimpleTypeDescription::opcUaBinaryEncode(std::ostream& os) const
    {
        DataTypeDescription::opcUaBinaryEncode(os);
        baseDataType_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,builtInType_);
    }
    
    void
    SimpleTypeDescription::opcUaBinaryDecode(std::istream& is)
    {
        DataTypeDescription::opcUaBinaryDecode(is);
        baseDataType_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,builtInType_);
    }
    
    bool
    SimpleTypeDescription::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "SimpleTypeDescription encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    SimpleTypeDescription::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!baseDataType_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SimpleTypeDescription encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("BaseDataType", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, builtInType_))
        {
            Log(Error, "SimpleTypeDescription encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("BuiltInType", elementTree));
    
        return true;
    }
    
    bool
    SimpleTypeDescription::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SimpleTypeDescription decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    SimpleTypeDescription::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("BaseDataType");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SimpleTypeDescription decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!baseDataType_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SimpleTypeDescription decode xml error - decode failed")
                .parameter("Element", "BaseDataType");
            return false;
        }
    
        elementName = xmlns.addPrefix("BuiltInType");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SimpleTypeDescription decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, builtInType_)) {
            Log(Error, "SimpleTypeDescription decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    SimpleTypeDescription::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!baseDataType_.jsonEncode(elementTree))
        {
    	     Log(Error, "SimpleTypeDescription json encoder error")
    		     .parameter("Element", "baseDataType_");
            return false;
        }
        pt.push_back(std::make_pair("BaseDataType", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, builtInType_))
        {
    	     Log(Error, "SimpleTypeDescription json encoder error")
    		     .parameter("Element", "builtInType_");
           return false;
        }
        pt.push_back(std::make_pair("BuiltInType", elementTree));
    
        return true;
    }
    
    bool
    SimpleTypeDescription::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "BaseDataType";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SimpleTypeDescription decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!baseDataType_.jsonDecode(*tree)) {
            Log(Error, "SimpleTypeDescription decode json error - decode failed")
                .parameter("Element", "BaseDataType");
            return false;
        }
    
        elementName = "BuiltInType";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SimpleTypeDescription decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, builtInType_)) {
            Log(Error, "SimpleTypeDescription decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    SimpleTypeDescription::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	SimpleTypeDescription* dst = dynamic_cast<SimpleTypeDescription*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    SimpleTypeDescription::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	SimpleTypeDescription* dst = dynamic_cast<SimpleTypeDescription*>(&extensionObjectBase);
    	return *const_cast<SimpleTypeDescription*>(this) == *dst;
    }
    
    void
    SimpleTypeDescription::out(std::ostream& os)
    {
        os << "BaseDataType="; baseDataType_.out(os);
        os << ", BuiltInType=" << builtInType_;
    }

}
