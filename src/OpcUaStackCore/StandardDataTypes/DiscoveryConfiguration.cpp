/*
    DataTypeClass: DiscoveryConfiguration

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/DiscoveryConfiguration.h"

namespace OpcUaStackCore
{
    
    /**
     * A base type for discovery configuration information.
     */
    DiscoveryConfiguration::DiscoveryConfiguration(void)
    : Object()
    , ExtensionObjectBase()
    {
    }
    
    /**
     * A base type for discovery configuration information.
     */
    DiscoveryConfiguration::DiscoveryConfiguration(const DiscoveryConfiguration& value)
    : Object()
    , ExtensionObjectBase()
    {
        const_cast<DiscoveryConfiguration*>(&value)->copyTo(*this);
    }
    
    DiscoveryConfiguration::~DiscoveryConfiguration(void)
    {
    }
    
    bool
    DiscoveryConfiguration::operator==(const DiscoveryConfiguration& value)
    {
        DiscoveryConfiguration* dst = const_cast<DiscoveryConfiguration*>(&value);
        return true;
    }
    
    bool
    DiscoveryConfiguration::operator!=(const DiscoveryConfiguration& value)
    {
        return !this->operator==(value);
    }
    
    void
    DiscoveryConfiguration::copyTo(DiscoveryConfiguration& value)
    {
    }
    
    DiscoveryConfiguration&
    DiscoveryConfiguration::operator=(const DiscoveryConfiguration& value)
    {
        const_cast<DiscoveryConfiguration*>(&value)->copyTo(*this);
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
    DiscoveryConfiguration::factory(void)
    {
    	return constructSPtr<DiscoveryConfiguration>();
    }
    
    std::string
    DiscoveryConfiguration::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    DiscoveryConfiguration::typeName(void)
    {
    	return "DiscoveryConfiguration";
    }
    
    OpcUaNodeId
    DiscoveryConfiguration::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)12890,0);
    }
    
    OpcUaNodeId
    DiscoveryConfiguration::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)12900, 0);
    }
    
    OpcUaNodeId
    DiscoveryConfiguration::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)12892, 0);
    }
    
    OpcUaNodeId
    DiscoveryConfiguration::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15105, 0);
    }
    
    void
    DiscoveryConfiguration::opcUaBinaryEncode(std::ostream& os) const
    {
    }
    
    void
    DiscoveryConfiguration::opcUaBinaryDecode(std::istream& is)
    {
    }
    
    bool
    DiscoveryConfiguration::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "DiscoveryConfiguration encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    DiscoveryConfiguration::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        return true;
    }
    
    bool
    DiscoveryConfiguration::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DiscoveryConfiguration decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    DiscoveryConfiguration::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        return true;
    }
    
    bool
    DiscoveryConfiguration::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        return true;
    }
    
    bool
    DiscoveryConfiguration::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        return true;
    }
    
    void
    DiscoveryConfiguration::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	DiscoveryConfiguration* dst = dynamic_cast<DiscoveryConfiguration*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    DiscoveryConfiguration::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	DiscoveryConfiguration* dst = dynamic_cast<DiscoveryConfiguration*>(&extensionObjectBase);
    	return *const_cast<DiscoveryConfiguration*>(this) == *dst;
    }
    
    void
    DiscoveryConfiguration::out(std::ostream& os)
    {
    }

}
