/*
    DataTypeClass: MdnsDiscoveryConfiguration

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/MdnsDiscoveryConfiguration.h"

namespace OpcUaStackCore
{
    
    /**
     * The discovery information needed for mDNS registration.
     */
    MdnsDiscoveryConfiguration::MdnsDiscoveryConfiguration(void)
    : DiscoveryConfiguration()
    , mdnsServerName_()
    , serverCapabilities_()
    {
    }
    
    /**
     * The discovery information needed for mDNS registration.
     */
    MdnsDiscoveryConfiguration::MdnsDiscoveryConfiguration(const MdnsDiscoveryConfiguration& value)
    : DiscoveryConfiguration()
    , mdnsServerName_()
    , serverCapabilities_()
    {
        const_cast<MdnsDiscoveryConfiguration*>(&value)->copyTo(*this);
    }
    
    MdnsDiscoveryConfiguration::~MdnsDiscoveryConfiguration(void)
    {
    }
    
    OpcUaString&
    MdnsDiscoveryConfiguration::mdnsServerName(void)
    {
        return mdnsServerName_;
    }
    
    OpcUaStringArray&
    MdnsDiscoveryConfiguration::serverCapabilities(void)
    {
        return serverCapabilities_;
    }
    
    bool
    MdnsDiscoveryConfiguration::operator==(const MdnsDiscoveryConfiguration& value)
    {
        MdnsDiscoveryConfiguration* dst = const_cast<MdnsDiscoveryConfiguration*>(&value);
        if (mdnsServerName_ != dst->mdnsServerName()) return false;
        if (serverCapabilities_ != dst->serverCapabilities()) return false;
        return true;
    }
    
    bool
    MdnsDiscoveryConfiguration::operator!=(const MdnsDiscoveryConfiguration& value)
    {
        return !this->operator==(value);
    }
    
    void
    MdnsDiscoveryConfiguration::copyTo(MdnsDiscoveryConfiguration& value)
    {
        mdnsServerName_.copyTo(value.mdnsServerName());
        serverCapabilities_.copyTo(value.serverCapabilities());
    }
    
    MdnsDiscoveryConfiguration&
    MdnsDiscoveryConfiguration::operator=(const MdnsDiscoveryConfiguration& value)
    {
        const_cast<MdnsDiscoveryConfiguration*>(&value)->copyTo(*this);
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
    MdnsDiscoveryConfiguration::factory(void)
    {
    	return constructSPtr<MdnsDiscoveryConfiguration>();
    }
    
    std::string
    MdnsDiscoveryConfiguration::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    MdnsDiscoveryConfiguration::typeName(void)
    {
    	return "MdnsDiscoveryConfiguration";
    }
    
    OpcUaNodeId
    MdnsDiscoveryConfiguration::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)12891,0);
    }
    
    OpcUaNodeId
    MdnsDiscoveryConfiguration::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)12901, 0);
    }
    
    OpcUaNodeId
    MdnsDiscoveryConfiguration::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)12893, 0);
    }
    
    OpcUaNodeId
    MdnsDiscoveryConfiguration::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15106, 0);
    }
    
    void
    MdnsDiscoveryConfiguration::opcUaBinaryEncode(std::ostream& os) const
    {
        DiscoveryConfiguration::opcUaBinaryEncode(os);
        mdnsServerName_.opcUaBinaryEncode(os);
        serverCapabilities_.opcUaBinaryEncode(os);
    }
    
    void
    MdnsDiscoveryConfiguration::opcUaBinaryDecode(std::istream& is)
    {
        DiscoveryConfiguration::opcUaBinaryDecode(is);
        mdnsServerName_.opcUaBinaryDecode(is);
        serverCapabilities_.opcUaBinaryDecode(is);
    }
    
    bool
    MdnsDiscoveryConfiguration::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "MdnsDiscoveryConfiguration encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    MdnsDiscoveryConfiguration::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!mdnsServerName_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "MdnsDiscoveryConfiguration encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("MdnsServerName", elementTree));
    
        elementTree.clear();
        if (!serverCapabilities_.xmlEncode(elementTree, "String", xmlns)) {
            Log(Error, "MdnsDiscoveryConfiguration encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ServerCapabilities", elementTree));
    
        return true;
    }
    
    bool
    MdnsDiscoveryConfiguration::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "MdnsDiscoveryConfiguration decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    MdnsDiscoveryConfiguration::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("MdnsServerName");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "MdnsDiscoveryConfiguration decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!mdnsServerName_.xmlDecode(*tree, xmlns)) {
            Log(Error, "MdnsDiscoveryConfiguration decode xml error - decode failed")
                .parameter("Element", "MdnsServerName");
            return false;
        }
    
        elementName = xmlns.addPrefix("ServerCapabilities");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "MdnsDiscoveryConfiguration decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!serverCapabilities_.xmlDecode(*tree, "String", xmlns)) {
            Log(Error, "MdnsDiscoveryConfiguration decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    MdnsDiscoveryConfiguration::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!mdnsServerName_.jsonEncode(elementTree))
        {
    	     Log(Error, "MdnsDiscoveryConfiguration json encoder error")
    		     .parameter("Element", "mdnsServerName_");
            return false;
        }
        pt.push_back(std::make_pair("MdnsServerName", elementTree));
    
        elementTree.clear();
        if (!serverCapabilities_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "MdnsDiscoveryConfiguration json encoder error")
    		     .parameter("Element", "serverCapabilities_");
            return false;
        }
        pt.push_back(std::make_pair("ServerCapabilities", elementTree));
    
        return true;
    }
    
    bool
    MdnsDiscoveryConfiguration::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "MdnsServerName";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "MdnsDiscoveryConfiguration decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!mdnsServerName_.jsonDecode(*tree)) {
            Log(Error, "MdnsDiscoveryConfiguration decode json error - decode failed")
                .parameter("Element", "MdnsServerName");
            return false;
        }
    
        elementName = "ServerCapabilities";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "MdnsDiscoveryConfiguration decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!serverCapabilities_.jsonDecode(*tree, "")) {
            Log(Error, "MdnsDiscoveryConfiguration decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    MdnsDiscoveryConfiguration::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	MdnsDiscoveryConfiguration* dst = dynamic_cast<MdnsDiscoveryConfiguration*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    MdnsDiscoveryConfiguration::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	MdnsDiscoveryConfiguration* dst = dynamic_cast<MdnsDiscoveryConfiguration*>(&extensionObjectBase);
    	return *const_cast<MdnsDiscoveryConfiguration*>(this) == *dst;
    }
    
    void
    MdnsDiscoveryConfiguration::out(std::ostream& os)
    {
        os << "MdnsServerName="; mdnsServerName_.out(os);
        os << ", ServerCapabilities="; serverCapabilities_.out(os);
    }

}
