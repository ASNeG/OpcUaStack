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
    
    NetworkGroupDataType::NetworkGroupDataType(const NetworkGroupDataType& value)
    : Object()
    , ExtensionObjectBase()
    , serverUri_()
    , networkPaths_()
    {
        const_cast<NetworkGroupDataType*>(&value)->copyTo(*this);
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
    NetworkGroupDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "NetworkGroupDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    NetworkGroupDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!serverUri_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "NetworkGroupDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ServerUri", elementTree));
    
        elementTree.clear();
        if (!networkPaths_.xmlEncode(elementTree, "EndpointUrlListDataType", xmlns)) {
            Log(Error, "NetworkGroupDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("NetworkPaths", elementTree));
    
        return true;
    }
    
    bool
    NetworkGroupDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "NetworkGroupDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    NetworkGroupDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("ServerUri");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "NetworkGroupDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!serverUri_.xmlDecode(*tree, xmlns)) {
            Log(Error, "NetworkGroupDataType decode xml error - decode failed")
                .parameter("Element", "ServerUri");
            return false;
        }
    
        elementName = xmlns.addPrefix("NetworkPaths");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "NetworkGroupDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!networkPaths_.xmlDecode(*tree, "EndpointUrlListDataType", xmlns)) {
            Log(Error, "NetworkGroupDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    NetworkGroupDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!serverUri_.jsonEncode(elementTree))
        {
    	     Log(Error, "NetworkGroupDataType json encoder error")
    		     .parameter("Element", "serverUri_");
            return false;
        }
        pt.push_back(std::make_pair("ServerUri", elementTree));
    
        elementTree.clear();
        if (!networkPaths_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "NetworkGroupDataType json encoder error")
    		     .parameter("Element", "networkPaths_");
            return false;
        }
        pt.push_back(std::make_pair("NetworkPaths", elementTree));
    
        return true;
    }
    
    bool
    NetworkGroupDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "ServerUri";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "NetworkGroupDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!serverUri_.jsonDecode(*tree)) {
            Log(Error, "NetworkGroupDataType decode json error - decode failed")
                .parameter("Element", "ServerUri");
            return false;
        }
    
        elementName = "NetworkPaths";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "NetworkGroupDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!networkPaths_.jsonDecode(*tree, "")) {
            Log(Error, "NetworkGroupDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
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
