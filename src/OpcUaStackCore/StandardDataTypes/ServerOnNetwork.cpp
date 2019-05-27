/*
    DataTypeClass: ServerOnNetwork

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/ServerOnNetwork.h"

namespace OpcUaStackCore
{
    
    ServerOnNetwork::ServerOnNetwork(void)
    : Object()
    , ExtensionObjectBase()
    , recordId_()
    , serverName_()
    , discoveryUrl_()
    , serverCapabilities_()
    {
    }
    
    ServerOnNetwork::ServerOnNetwork(const ServerOnNetwork& value)
    : Object()
    , ExtensionObjectBase()
    , recordId_()
    , serverName_()
    , discoveryUrl_()
    , serverCapabilities_()
    {
        const_cast<ServerOnNetwork*>(&value)->copyTo(*this);
    }
    
    ServerOnNetwork::~ServerOnNetwork(void)
    {
    }
    
    OpcUaUInt32&
    ServerOnNetwork::recordId(void)
    {
        return recordId_;
    }
    
    OpcUaString&
    ServerOnNetwork::serverName(void)
    {
        return serverName_;
    }
    
    OpcUaString&
    ServerOnNetwork::discoveryUrl(void)
    {
        return discoveryUrl_;
    }
    
    OpcUaStringArray&
    ServerOnNetwork::serverCapabilities(void)
    {
        return serverCapabilities_;
    }
    
    bool
    ServerOnNetwork::operator==(const ServerOnNetwork& value)
    {
        ServerOnNetwork* dst = const_cast<ServerOnNetwork*>(&value);
        if (recordId_ != dst->recordId()) return false;
        if (serverName_ != dst->serverName()) return false;
        if (discoveryUrl_ != dst->discoveryUrl()) return false;
        if (serverCapabilities_ != dst->serverCapabilities()) return false;
        return true;
    }
    
    bool
    ServerOnNetwork::operator!=(const ServerOnNetwork& value)
    {
        return !this->operator==(value);
    }
    
    void
    ServerOnNetwork::copyTo(ServerOnNetwork& value)
    {
        value.recordId_ = recordId_;
        serverName_.copyTo(value.serverName());
        discoveryUrl_.copyTo(value.discoveryUrl());
        serverCapabilities_.copyTo(value.serverCapabilities());
    }
    
    ServerOnNetwork&
    ServerOnNetwork::operator=(const ServerOnNetwork& value)
    {
        const_cast<ServerOnNetwork*>(&value)->copyTo(*this);
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
    ServerOnNetwork::factory(void)
    {
    	return constructSPtr<ServerOnNetwork>();
    }
    
    std::string
    ServerOnNetwork::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    ServerOnNetwork::typeName(void)
    {
    	return "ServerOnNetwork";
    }
    
    OpcUaNodeId
    ServerOnNetwork::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)12189,0);
    }
    
    OpcUaNodeId
    ServerOnNetwork::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)12207, 0);
    }
    
    OpcUaNodeId
    ServerOnNetwork::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)12195, 0);
    }
    
    OpcUaNodeId
    ServerOnNetwork::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15095, 0);
    }
    
    void
    ServerOnNetwork::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os,recordId_);
        serverName_.opcUaBinaryEncode(os);
        discoveryUrl_.opcUaBinaryEncode(os);
        serverCapabilities_.opcUaBinaryEncode(os);
    }
    
    void
    ServerOnNetwork::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is,recordId_);
        serverName_.opcUaBinaryDecode(is);
        discoveryUrl_.opcUaBinaryDecode(is);
        serverCapabilities_.opcUaBinaryDecode(is);
    }
    
    bool
    ServerOnNetwork::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "ServerOnNetwork encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    ServerOnNetwork::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, recordId_))
        {
            Log(Error, "ServerOnNetwork encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("RecordId", elementTree));
    
        elementTree.clear();
        if (!serverName_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ServerOnNetwork encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ServerName", elementTree));
    
        elementTree.clear();
        if (!discoveryUrl_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ServerOnNetwork encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DiscoveryUrl", elementTree));
    
        elementTree.clear();
        if (!serverCapabilities_.xmlEncode(elementTree, "String", xmlns)) {
            Log(Error, "ServerOnNetwork encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ServerCapabilities", elementTree));
    
        return true;
    }
    
    bool
    ServerOnNetwork::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ServerOnNetwork decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    ServerOnNetwork::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("RecordId");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ServerOnNetwork decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, recordId_)) {
            Log(Error, "ServerOnNetwork decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("ServerName");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ServerOnNetwork decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!serverName_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ServerOnNetwork decode xml error - decode failed")
                .parameter("Element", "ServerName");
            return false;
        }
    
        elementName = xmlns.addPrefix("DiscoveryUrl");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ServerOnNetwork decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!discoveryUrl_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ServerOnNetwork decode xml error - decode failed")
                .parameter("Element", "DiscoveryUrl");
            return false;
        }
    
        elementName = xmlns.addPrefix("ServerCapabilities");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ServerOnNetwork decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!serverCapabilities_.xmlDecode(*tree, "String", xmlns)) {
            Log(Error, "ServerOnNetwork decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    ServerOnNetwork::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, recordId_))
        {
    	     Log(Error, "ServerOnNetwork json encoder error")
    		     .parameter("Element", "recordId_");
           return false;
        }
        pt.push_back(std::make_pair("RecordId", elementTree));
    
        elementTree.clear();
        if (!serverName_.jsonEncode(elementTree))
        {
    	     Log(Error, "ServerOnNetwork json encoder error")
    		     .parameter("Element", "serverName_");
            return false;
        }
        pt.push_back(std::make_pair("ServerName", elementTree));
    
        elementTree.clear();
        if (!discoveryUrl_.jsonEncode(elementTree))
        {
    	     Log(Error, "ServerOnNetwork json encoder error")
    		     .parameter("Element", "discoveryUrl_");
            return false;
        }
        pt.push_back(std::make_pair("DiscoveryUrl", elementTree));
    
        elementTree.clear();
        if (!serverCapabilities_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "ServerOnNetwork json encoder error")
    		     .parameter("Element", "serverCapabilities_");
            return false;
        }
        pt.push_back(std::make_pair("ServerCapabilities", elementTree));
    
        return true;
    }
    
    bool
    ServerOnNetwork::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "RecordId";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ServerOnNetwork decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, recordId_)) {
            Log(Error, "ServerOnNetwork decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "ServerName";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ServerOnNetwork decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!serverName_.jsonDecode(*tree)) {
            Log(Error, "ServerOnNetwork decode json error - decode failed")
                .parameter("Element", "ServerName");
            return false;
        }
    
        elementName = "DiscoveryUrl";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ServerOnNetwork decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!discoveryUrl_.jsonDecode(*tree)) {
            Log(Error, "ServerOnNetwork decode json error - decode failed")
                .parameter("Element", "DiscoveryUrl");
            return false;
        }
    
        elementName = "ServerCapabilities";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ServerOnNetwork decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!serverCapabilities_.jsonDecode(*tree, "")) {
            Log(Error, "ServerOnNetwork decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    ServerOnNetwork::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	ServerOnNetwork* dst = dynamic_cast<ServerOnNetwork*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    ServerOnNetwork::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	ServerOnNetwork* dst = dynamic_cast<ServerOnNetwork*>(&extensionObjectBase);
    	return *const_cast<ServerOnNetwork*>(this) == *dst;
    }
    
    void
    ServerOnNetwork::out(std::ostream& os)
    {
        os << "RecordId=" << recordId_;
        os << ", ServerName="; serverName_.out(os);
        os << ", DiscoveryUrl="; discoveryUrl_.out(os);
        os << ", ServerCapabilities="; serverCapabilities_.out(os);
    }

}
