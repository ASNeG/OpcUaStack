/*
    DataTypeClass: RedundantServerDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

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
    
    RedundantServerDataType::RedundantServerDataType(const RedundantServerDataType& value)
    : Object()
    , ExtensionObjectBase()
    , serverId_()
    , serviceLevel_()
    , serverState_()
    {
        const_cast<RedundantServerDataType*>(&value)->copyTo(*this);
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
    	return boost::make_shared<RedundantServerDataType>();
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
    
    bool
    RedundantServerDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        bool rc = true;
    
        rc &= serverId_.opcUaBinaryEncode(os);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,serviceLevel_);
        rc &= serverState_.opcUaBinaryEncode(os);
        return rc;
    }
    
    bool
    RedundantServerDataType::opcUaBinaryDecode(std::istream& is)
    {
        bool rc = true;
    
        rc &= serverId_.opcUaBinaryDecode(is);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,serviceLevel_);
        rc &= serverState_.opcUaBinaryDecode(is);
        return rc;
    }
    
    bool
    RedundantServerDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "RedundantServerDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    RedundantServerDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!serverId_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "RedundantServerDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ServerId", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, serviceLevel_))
        {
            Log(Error, "RedundantServerDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ServiceLevel", elementTree));
    
        elementTree.clear();
        if (!serverState_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "RedundantServerDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ServerState", elementTree));
    
        return true;
    }
    
    bool
    RedundantServerDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "RedundantServerDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    RedundantServerDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("ServerId");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "RedundantServerDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!serverId_.xmlDecode(*tree, xmlns)) {
            Log(Error, "RedundantServerDataType decode xml error - decode failed")
                .parameter("Element", "ServerId");
            return false;
        }
    
        elementName = xmlns.addPrefix("ServiceLevel");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "RedundantServerDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, serviceLevel_)) {
            Log(Error, "RedundantServerDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("ServerState");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "RedundantServerDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!serverState_.xmlDecode(*tree, xmlns)) {
            Log(Error, "RedundantServerDataType decode xml error - decode failed")
                .parameter("Element", "ServerState");
            return false;
        }
    
        return true;
    }
    
    bool
    RedundantServerDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        bool rc = true;
    
        rc = rc & jsonObjectEncode(pt, serverId_, "ServerId", true);
        rc = rc & jsonNumberEncode(pt, serviceLevel_, "ServiceLevel");
        rc = rc & jsonObjectEncode(pt, serverState_, "ServerState", true);
    
        return rc;
    }
    
    bool
    RedundantServerDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        bool rc = true;
    
        rc = rc & jsonObjectDecode(pt, serverId_, "ServerId", true);
        rc = rc & jsonNumberDecode(pt, serviceLevel_, "ServiceLevel");
        rc = rc & jsonObjectDecode(pt, serverState_, "ServerState", true);
    
        return rc;
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
