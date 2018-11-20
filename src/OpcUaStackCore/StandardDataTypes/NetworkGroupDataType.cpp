/*
    DataTypeClass: NetworkGroupDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/NetworkGroupDataType.h"

namespace OpcUaStackCore
{
    
    NetworkGroupDataType::NetworkGroupDataType(void)
    : Object()
    , ExtensionObjectBase()
    , serverUri_()
    , networkPaths_()
    {
    }
    
    NetworkGroupDataType::~NetworkGroupDataType(void)
    {
    }
    
    OpcUaString&
    NetworkGroupDataType::serverUri(void)
    {
        return serverUri_;
    }
    
    EndpointUrlListDataTypeArray&
    NetworkGroupDataType::networkPaths(void)
    {
        return networkPaths_;
    }
    
    bool
    NetworkGroupDataType::operator==(const NetworkGroupDataType& value)
    {
        NetworkGroupDataType* dst = const_cast<NetworkGroupDataType*>(&value);
        if (serverUri_ != dst->serverUri()) return false;
        if (networkPaths_ != dst->networkPaths()) return false;
        return true;
    }
    
    bool
    NetworkGroupDataType::operator!=(const NetworkGroupDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    NetworkGroupDataType::copyTo(NetworkGroupDataType& value)
    {
        serverUri_.copyTo(value.serverUri());
        networkPaths_.copyTo(value.networkPaths());
    }
    
    NetworkGroupDataType&
    NetworkGroupDataType::operator=(const NetworkGroupDataType& value)
    {
        const_cast<NetworkGroupDataType*>(&value)->copyTo(*this);
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
    NetworkGroupDataType::factory(void)
    {
    	return constructSPtr<NetworkGroupDataType>();
    }
    
    std::string
    NetworkGroupDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    NetworkGroupDataType::typeName(void)
    {
    	return "NetworkGroupDataType";
    }
    
    OpcUaNodeId
    NetworkGroupDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)11944,0);
    }
    
    OpcUaNodeId
    NetworkGroupDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)11958, 0);
    }
    
    OpcUaNodeId
    NetworkGroupDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)11950, 0);
    }
    
    OpcUaNodeId
    NetworkGroupDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15364, 0);
    }
    
    void
    NetworkGroupDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        serverUri_.opcUaBinaryEncode(os);
        networkPaths_.opcUaBinaryEncode(os);
    }
    
    void
    NetworkGroupDataType::opcUaBinaryDecode(std::istream& is)
    {
        serverUri_.opcUaBinaryDecode(is);
        networkPaths_.opcUaBinaryDecode(is);
    }
    
    bool
    NetworkGroupDataType::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    NetworkGroupDataType::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    NetworkGroupDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    NetworkGroupDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!serverUri_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("ServerUri", elementTree));
    
        elementTree.clear();
        if (!networkPaths_.xmlEncode(elementTree, "EndpointUrlListDataType", xmlns)) return false;
        pt.push_back(std::make_pair("NetworkPaths", elementTree));
    
        return true;
    }
    
    bool
    NetworkGroupDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    NetworkGroupDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("ServerUri");
        if (!tree) return false;
        if (!serverUri_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("NetworkPaths");
        if (!tree) return false;
        if (!networkPaths_.xmlDecode(*tree, "EndpointUrlListDataType", xmlns)) return false;
    
        return true;
    }
    
    bool
    NetworkGroupDataType::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    NetworkGroupDataType::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    NetworkGroupDataType::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    NetworkGroupDataType::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    NetworkGroupDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	NetworkGroupDataType* dst = dynamic_cast<NetworkGroupDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    NetworkGroupDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	NetworkGroupDataType* dst = dynamic_cast<NetworkGroupDataType*>(&extensionObjectBase);
    	return *const_cast<NetworkGroupDataType*>(this) == *dst;
    }
    
    void
    NetworkGroupDataType::out(std::ostream& os)
    {
        os << "ServerUri="; serverUri_.out(os);
        os << ", NetworkPaths="; networkPaths_.out(os);
    }

}
