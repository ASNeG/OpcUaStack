/*
    DataTypeClass: ConfigurationVersionDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/ConfigurationVersionDataType.h"

namespace OpcUaStackCore
{
    
    ConfigurationVersionDataType::ConfigurationVersionDataType(void)
    : Object()
    , ExtensionObjectBase()
    , majorVersion_()
    , minorVersion_()
    {
    }
    
    ConfigurationVersionDataType::ConfigurationVersionDataType(const ConfigurationVersionDataType& value)
    : Object()
    , ExtensionObjectBase()
    , majorVersion_()
    , minorVersion_()
    {
        const_cast<ConfigurationVersionDataType*>(&value)->copyTo(*this);
    }
    
    ConfigurationVersionDataType::~ConfigurationVersionDataType(void)
    {
    }
    
    OpcUaVersionTime&
    ConfigurationVersionDataType::majorVersion(void)
    {
        return majorVersion_;
    }
    
    OpcUaVersionTime&
    ConfigurationVersionDataType::minorVersion(void)
    {
        return minorVersion_;
    }
    
    bool
    ConfigurationVersionDataType::operator==(const ConfigurationVersionDataType& value)
    {
        ConfigurationVersionDataType* dst = const_cast<ConfigurationVersionDataType*>(&value);
        if (majorVersion_ != dst->majorVersion()) return false;
        if (minorVersion_ != dst->minorVersion()) return false;
        return true;
    }
    
    bool
    ConfigurationVersionDataType::operator!=(const ConfigurationVersionDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    ConfigurationVersionDataType::copyTo(ConfigurationVersionDataType& value)
    {
        value.majorVersion_ = majorVersion_;
        value.minorVersion_ = minorVersion_;
    }
    
    ConfigurationVersionDataType&
    ConfigurationVersionDataType::operator=(const ConfigurationVersionDataType& value)
    {
        const_cast<ConfigurationVersionDataType*>(&value)->copyTo(*this);
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
    ConfigurationVersionDataType::factory(void)
    {
    	return constructSPtr<ConfigurationVersionDataType>();
    }
    
    std::string
    ConfigurationVersionDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    ConfigurationVersionDataType::typeName(void)
    {
    	return "ConfigurationVersionDataType";
    }
    
    OpcUaNodeId
    ConfigurationVersionDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)14593,0);
    }
    
    OpcUaNodeId
    ConfigurationVersionDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)14847, 0);
    }
    
    OpcUaNodeId
    ConfigurationVersionDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)14803, 0);
    }
    
    OpcUaNodeId
    ConfigurationVersionDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15049, 0);
    }
    
    void
    ConfigurationVersionDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os,majorVersion_);
        OpcUaNumber::opcUaBinaryEncode(os,minorVersion_);
    }
    
    void
    ConfigurationVersionDataType::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is,majorVersion_);
        OpcUaNumber::opcUaBinaryDecode(is,minorVersion_);
    }
    
    bool
    ConfigurationVersionDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "ConfigurationVersionDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    ConfigurationVersionDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, majorVersion_))
        {
            Log(Error, "ConfigurationVersionDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("MajorVersion", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, minorVersion_))
        {
            Log(Error, "ConfigurationVersionDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("MinorVersion", elementTree));
    
        return true;
    }
    
    bool
    ConfigurationVersionDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ConfigurationVersionDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    ConfigurationVersionDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("MajorVersion");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ConfigurationVersionDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, majorVersion_)) {
            Log(Error, "ConfigurationVersionDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("MinorVersion");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ConfigurationVersionDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, minorVersion_)) {
            Log(Error, "ConfigurationVersionDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    ConfigurationVersionDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, majorVersion_))
        {
    	     Log(Error, "ConfigurationVersionDataType json encoder error")
    		     .parameter("Element", "majorVersion_");
           return false;
        }
        pt.push_back(std::make_pair("MajorVersion", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, minorVersion_))
        {
    	     Log(Error, "ConfigurationVersionDataType json encoder error")
    		     .parameter("Element", "minorVersion_");
           return false;
        }
        pt.push_back(std::make_pair("MinorVersion", elementTree));
    
        return true;
    }
    
    bool
    ConfigurationVersionDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "MajorVersion";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ConfigurationVersionDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, majorVersion_)) {
            Log(Error, "ConfigurationVersionDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "MinorVersion";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ConfigurationVersionDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, minorVersion_)) {
            Log(Error, "ConfigurationVersionDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    ConfigurationVersionDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	ConfigurationVersionDataType* dst = dynamic_cast<ConfigurationVersionDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    ConfigurationVersionDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	ConfigurationVersionDataType* dst = dynamic_cast<ConfigurationVersionDataType*>(&extensionObjectBase);
    	return *const_cast<ConfigurationVersionDataType*>(this) == *dst;
    }
    
    void
    ConfigurationVersionDataType::out(std::ostream& os)
    {
        os << "MajorVersion=" << majorVersion_;
        os << ", MinorVersion=" << minorVersion_;
    }

}
