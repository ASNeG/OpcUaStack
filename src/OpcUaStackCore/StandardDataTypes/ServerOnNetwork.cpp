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
    ServerOnNetwork::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    ServerOnNetwork::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    ServerOnNetwork::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    ServerOnNetwork::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, recordId_)) return false;
        pt.push_back(std::make_pair("RecordId", elementTree));
    
        elementTree.clear();
        if (!serverName_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("ServerName", elementTree));
    
        elementTree.clear();
        if (!discoveryUrl_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("DiscoveryUrl", elementTree));
    
        elementTree.clear();
        if (!serverCapabilities_.xmlEncode(elementTree, "String", xmlns)) return false;
        pt.push_back(std::make_pair("ServerCapabilities", elementTree));
    
        return true;
    }
    
    bool
    ServerOnNetwork::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    ServerOnNetwork::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("RecordId");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, recordId_)) return false;
    
        tree = pt.get_child_optional("ServerName");
        if (!tree) return false;
        if (!serverName_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("DiscoveryUrl");
        if (!tree) return false;
        if (!discoveryUrl_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("ServerCapabilities");
        if (!tree) return false;
        if (!serverCapabilities_.xmlDecode(*tree, "String", xmlns)) return false;
    
        return true;
    }
    
    bool
    ServerOnNetwork::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    ServerOnNetwork::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    ServerOnNetwork::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    ServerOnNetwork::jsonDecode(boost::property_tree::ptree& pt)
    {
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