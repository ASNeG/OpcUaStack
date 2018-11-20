/*
    DataTypeClass: RedundantServerDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/RedundantServerDataType.h"

namespace OpcUaStackCore
{
    
    RedundantServerDataType::RedundantServerDataType(void)
    : Object()
    , ExtensionObjectBase()
    , serverId_()
    , serviceLevel_()
    , serverState_()
    {
    }
    
    RedundantServerDataType::~RedundantServerDataType(void)
    {
    }
    
    OpcUaString&
    RedundantServerDataType::serverId(void)
    {
        return serverId_;
    }
    
    OpcUaByte&
    RedundantServerDataType::serviceLevel(void)
    {
        return serviceLevel_;
    }
    
    ServerState&
    RedundantServerDataType::serverState(void)
    {
        return serverState_;
    }
    
    bool
    RedundantServerDataType::operator==(const RedundantServerDataType& value)
    {
        RedundantServerDataType* dst = const_cast<RedundantServerDataType*>(&value);
        if (serverId_ != dst->serverId()) return false;
        if (serviceLevel_ != dst->serviceLevel()) return false;
        if (serverState_ != dst->serverState()) return false;
        return true;
    }
    
    bool
    RedundantServerDataType::operator!=(const RedundantServerDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    RedundantServerDataType::copyTo(RedundantServerDataType& value)
    {
        serverId_.copyTo(value.serverId());
        value.serviceLevel_ = serviceLevel_;
        serverState_.copyTo(value.serverState());
    }
    
    RedundantServerDataType&
    RedundantServerDataType::operator=(const RedundantServerDataType& value)
    {
        const_cast<RedundantServerDataType*>(&value)->copyTo(*this);
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
    RedundantServerDataType::factory(void)
    {
    	return constructSPtr<RedundantServerDataType>();
    }
    
    std::string
    RedundantServerDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    RedundantServerDataType::typeName(void)
    {
    	return "RedundantServerDataType";
    }
    
    OpcUaNodeId
    RedundantServerDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)853,0);
    }
    
    OpcUaNodeId
    RedundantServerDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)855, 0);
    }
    
    OpcUaNodeId
    RedundantServerDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)854, 0);
    }
    
    OpcUaNodeId
    RedundantServerDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15362, 0);
    }
    
    void
    RedundantServerDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        serverId_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,serviceLevel_);
        serverState_.opcUaBinaryEncode(os);
    }
    
    void
    RedundantServerDataType::opcUaBinaryDecode(std::istream& is)
    {
        serverId_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,serviceLevel_);
        serverState_.opcUaBinaryDecode(is);
    }
    
    bool
    RedundantServerDataType::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    RedundantServerDataType::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    RedundantServerDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    RedundantServerDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!serverId_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("ServerId", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, serviceLevel_)) return false;
        pt.push_back(std::make_pair("ServiceLevel", elementTree));
    
        elementTree.clear();
        if (!serverState_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("ServerState", elementTree));
    
        return true;
    }
    
    bool
    RedundantServerDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    RedundantServerDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("ServerId");
        if (!tree) return false;
        if (!serverId_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("ServiceLevel");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, serviceLevel_)) return false;
    
        tree = pt.get_child_optional("ServerState");
        if (!tree) return false;
        if (!serverState_.xmlDecode(*tree, xmlns)) return false;
    
        return true;
    }
    
    bool
    RedundantServerDataType::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    RedundantServerDataType::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    RedundantServerDataType::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    RedundantServerDataType::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    RedundantServerDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	RedundantServerDataType* dst = dynamic_cast<RedundantServerDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    RedundantServerDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	RedundantServerDataType* dst = dynamic_cast<RedundantServerDataType*>(&extensionObjectBase);
    	return *const_cast<RedundantServerDataType*>(this) == *dst;
    }
    
    void
    RedundantServerDataType::out(std::ostream& os)
    {
        os << "ServerId="; serverId_.out(os);
        os << ", ServiceLevel=" << serviceLevel_;
        os << ", ServerState="; serverState_.out(os);
    }

}
