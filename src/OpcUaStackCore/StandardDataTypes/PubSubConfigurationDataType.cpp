/*
    DataTypeClass: PubSubConfigurationDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/PubSubConfigurationDataType.h"

namespace OpcUaStackCore
{
    
    PubSubConfigurationDataType::PubSubConfigurationDataType(void)
    : Object()
    , ExtensionObjectBase()
    , publishedDataSets_()
    , connections_()
    , enabled_()
    {
    }
    
    PubSubConfigurationDataType::PubSubConfigurationDataType(const PubSubConfigurationDataType& value)
    : Object()
    , ExtensionObjectBase()
    , publishedDataSets_()
    , connections_()
    , enabled_()
    {
        const_cast<PubSubConfigurationDataType*>(&value)->copyTo(*this);
    }
    
    PubSubConfigurationDataType::~PubSubConfigurationDataType(void)
    {
    }
    
    PublishedDataSetDataTypeArray&
    PubSubConfigurationDataType::publishedDataSets(void)
    {
        return publishedDataSets_;
    }
    
    PubSubConnectionDataTypeArray&
    PubSubConfigurationDataType::connections(void)
    {
        return connections_;
    }
    
    OpcUaBoolean&
    PubSubConfigurationDataType::enabled(void)
    {
        return enabled_;
    }
    
    bool
    PubSubConfigurationDataType::operator==(const PubSubConfigurationDataType& value)
    {
        PubSubConfigurationDataType* dst = const_cast<PubSubConfigurationDataType*>(&value);
        if (publishedDataSets_ != dst->publishedDataSets()) return false;
        if (connections_ != dst->connections()) return false;
        if (enabled_ != dst->enabled()) return false;
        return true;
    }
    
    bool
    PubSubConfigurationDataType::operator!=(const PubSubConfigurationDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    PubSubConfigurationDataType::copyTo(PubSubConfigurationDataType& value)
    {
        publishedDataSets_.copyTo(value.publishedDataSets());
        connections_.copyTo(value.connections());
        value.enabled_ = enabled_;
    }
    
    PubSubConfigurationDataType&
    PubSubConfigurationDataType::operator=(const PubSubConfigurationDataType& value)
    {
        const_cast<PubSubConfigurationDataType*>(&value)->copyTo(*this);
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
    PubSubConfigurationDataType::factory(void)
    {
    	return constructSPtr<PubSubConfigurationDataType>();
    }
    
    std::string
    PubSubConfigurationDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    PubSubConfigurationDataType::typeName(void)
    {
    	return "PubSubConfigurationDataType";
    }
    
    OpcUaNodeId
    PubSubConfigurationDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15530,0);
    }
    
    OpcUaNodeId
    PubSubConfigurationDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)21154, 0);
    }
    
    OpcUaNodeId
    PubSubConfigurationDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)21178, 0);
    }
    
    OpcUaNodeId
    PubSubConfigurationDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)21202, 0);
    }
    
    void
    PubSubConfigurationDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        publishedDataSets_.opcUaBinaryEncode(os);
        connections_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,enabled_);
    }
    
    void
    PubSubConfigurationDataType::opcUaBinaryDecode(std::istream& is)
    {
        publishedDataSets_.opcUaBinaryDecode(is);
        connections_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,enabled_);
    }
    
    bool
    PubSubConfigurationDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "PubSubConfigurationDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    PubSubConfigurationDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!publishedDataSets_.xmlEncode(elementTree, "PublishedDataSetDataType", xmlns)) {
            Log(Error, "PubSubConfigurationDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("PublishedDataSets", elementTree));
    
        elementTree.clear();
        if (!connections_.xmlEncode(elementTree, "PubSubConnectionDataType", xmlns)) {
            Log(Error, "PubSubConfigurationDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Connections", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, enabled_))
        {
            Log(Error, "PubSubConfigurationDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Enabled", elementTree));
    
        return true;
    }
    
    bool
    PubSubConfigurationDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PubSubConfigurationDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    PubSubConfigurationDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("PublishedDataSets");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PubSubConfigurationDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!publishedDataSets_.xmlDecode(*tree, "PublishedDataSetDataType", xmlns)) {
            Log(Error, "PubSubConfigurationDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("Connections");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PubSubConfigurationDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!connections_.xmlDecode(*tree, "PubSubConnectionDataType", xmlns)) {
            Log(Error, "PubSubConfigurationDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("Enabled");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PubSubConfigurationDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, enabled_)) {
            Log(Error, "PubSubConfigurationDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    PubSubConfigurationDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!publishedDataSets_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "PubSubConfigurationDataType json encoder error")
    		     .parameter("Element", "publishedDataSets_");
            return false;
        }
        pt.push_back(std::make_pair("PublishedDataSets", elementTree));
    
        elementTree.clear();
        if (!connections_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "PubSubConfigurationDataType json encoder error")
    		     .parameter("Element", "connections_");
            return false;
        }
        pt.push_back(std::make_pair("Connections", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, enabled_))
        {
    	     Log(Error, "PubSubConfigurationDataType json encoder error")
    		     .parameter("Element", "enabled_");
           return false;
        }
        pt.push_back(std::make_pair("Enabled", elementTree));
    
        return true;
    }
    
    bool
    PubSubConfigurationDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "PublishedDataSets";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PubSubConfigurationDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!publishedDataSets_.jsonDecode(*tree, "")) {
            Log(Error, "PubSubConfigurationDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "Connections";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PubSubConfigurationDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!connections_.jsonDecode(*tree, "")) {
            Log(Error, "PubSubConfigurationDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "Enabled";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PubSubConfigurationDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, enabled_)) {
            Log(Error, "PubSubConfigurationDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    PubSubConfigurationDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	PubSubConfigurationDataType* dst = dynamic_cast<PubSubConfigurationDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    PubSubConfigurationDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	PubSubConfigurationDataType* dst = dynamic_cast<PubSubConfigurationDataType*>(&extensionObjectBase);
    	return *const_cast<PubSubConfigurationDataType*>(this) == *dst;
    }
    
    void
    PubSubConfigurationDataType::out(std::ostream& os)
    {
        os << "PublishedDataSets="; publishedDataSets_.out(os);
        os << ", Connections="; connections_.out(os);
        os << ", Enabled=" << enabled_;
    }

}
