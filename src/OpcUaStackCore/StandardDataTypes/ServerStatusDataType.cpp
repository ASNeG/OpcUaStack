/*
    DataTypeClass: ServerStatusDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/ServerStatusDataType.h"

namespace OpcUaStackCore
{
    
    ServerStatusDataType::ServerStatusDataType(void)
    : Object()
    , ExtensionObjectBase()
    , startTime_()
    , currentTime_()
    , state_()
    , buildInfo_()
    , secondsTillShutdown_()
    , shutdownReason_()
    {
    }
    
    ServerStatusDataType::ServerStatusDataType(const ServerStatusDataType& value)
    : Object()
    , ExtensionObjectBase()
    , startTime_()
    , currentTime_()
    , state_()
    , buildInfo_()
    , secondsTillShutdown_()
    , shutdownReason_()
    {
        const_cast<ServerStatusDataType*>(&value)->copyTo(*this);
    }
    
    ServerStatusDataType::~ServerStatusDataType(void)
    {
    }
    
    OpcUaUtcTime&
    ServerStatusDataType::startTime(void)
    {
        return startTime_;
    }
    
    OpcUaUtcTime&
    ServerStatusDataType::currentTime(void)
    {
        return currentTime_;
    }
    
    ServerState&
    ServerStatusDataType::state(void)
    {
        return state_;
    }
    
    BuildInfo&
    ServerStatusDataType::buildInfo(void)
    {
        return buildInfo_;
    }
    
    OpcUaUInt32&
    ServerStatusDataType::secondsTillShutdown(void)
    {
        return secondsTillShutdown_;
    }
    
    OpcUaLocalizedText&
    ServerStatusDataType::shutdownReason(void)
    {
        return shutdownReason_;
    }
    
    bool
    ServerStatusDataType::operator==(const ServerStatusDataType& value)
    {
        ServerStatusDataType* dst = const_cast<ServerStatusDataType*>(&value);
        if (startTime_ != dst->startTime()) return false;
        if (currentTime_ != dst->currentTime()) return false;
        if (state_ != dst->state()) return false;
        if (buildInfo_ != dst->buildInfo()) return false;
        if (secondsTillShutdown_ != dst->secondsTillShutdown()) return false;
        if (shutdownReason_ != dst->shutdownReason()) return false;
        return true;
    }
    
    bool
    ServerStatusDataType::operator!=(const ServerStatusDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    ServerStatusDataType::copyTo(ServerStatusDataType& value)
    {
        startTime_.copyTo(value.startTime());
        currentTime_.copyTo(value.currentTime());
        state_.copyTo(value.state());
        buildInfo_.copyTo(value.buildInfo());
        value.secondsTillShutdown_ = secondsTillShutdown_;
        shutdownReason_.copyTo(value.shutdownReason());
    }
    
    ServerStatusDataType&
    ServerStatusDataType::operator=(const ServerStatusDataType& value)
    {
        const_cast<ServerStatusDataType*>(&value)->copyTo(*this);
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
    ServerStatusDataType::factory(void)
    {
    	return constructSPtr<ServerStatusDataType>();
    }
    
    std::string
    ServerStatusDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    ServerStatusDataType::typeName(void)
    {
    	return "ServerStatusDataType";
    }
    
    OpcUaNodeId
    ServerStatusDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)862,0);
    }
    
    OpcUaNodeId
    ServerStatusDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)864, 0);
    }
    
    OpcUaNodeId
    ServerStatusDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)863, 0);
    }
    
    OpcUaNodeId
    ServerStatusDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15367, 0);
    }
    
    void
    ServerStatusDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        startTime_.opcUaBinaryEncode(os);
        currentTime_.opcUaBinaryEncode(os);
        state_.opcUaBinaryEncode(os);
        buildInfo_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,secondsTillShutdown_);
        shutdownReason_.opcUaBinaryEncode(os);
    }
    
    void
    ServerStatusDataType::opcUaBinaryDecode(std::istream& is)
    {
        startTime_.opcUaBinaryDecode(is);
        currentTime_.opcUaBinaryDecode(is);
        state_.opcUaBinaryDecode(is);
        buildInfo_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,secondsTillShutdown_);
        shutdownReason_.opcUaBinaryDecode(is);
    }
    
    bool
    ServerStatusDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "ServerStatusDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    ServerStatusDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!startTime_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ServerStatusDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("StartTime", elementTree));
    
        elementTree.clear();
        if (!currentTime_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ServerStatusDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("CurrentTime", elementTree));
    
        elementTree.clear();
        if (!state_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ServerStatusDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("State", elementTree));
    
        elementTree.clear();
        if (!buildInfo_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ServerStatusDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("BuildInfo", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, secondsTillShutdown_))
        {
            Log(Error, "ServerStatusDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SecondsTillShutdown", elementTree));
    
        elementTree.clear();
        if (!shutdownReason_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ServerStatusDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ShutdownReason", elementTree));
    
        return true;
    }
    
    bool
    ServerStatusDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ServerStatusDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    ServerStatusDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("StartTime");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ServerStatusDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!startTime_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ServerStatusDataType decode xml error - decode failed")
                .parameter("Element", "StartTime");
            return false;
        }
    
        elementName = xmlns.addPrefix("CurrentTime");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ServerStatusDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!currentTime_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ServerStatusDataType decode xml error - decode failed")
                .parameter("Element", "CurrentTime");
            return false;
        }
    
        elementName = xmlns.addPrefix("State");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ServerStatusDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!state_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ServerStatusDataType decode xml error - decode failed")
                .parameter("Element", "State");
            return false;
        }
    
        elementName = xmlns.addPrefix("BuildInfo");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ServerStatusDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!buildInfo_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ServerStatusDataType decode xml error - decode failed")
                .parameter("Element", "BuildInfo");
            return false;
        }
    
        elementName = xmlns.addPrefix("SecondsTillShutdown");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ServerStatusDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, secondsTillShutdown_)) {
            Log(Error, "ServerStatusDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("ShutdownReason");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ServerStatusDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!shutdownReason_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ServerStatusDataType decode xml error - decode failed")
                .parameter("Element", "ShutdownReason");
            return false;
        }
    
        return true;
    }
    
    bool
    ServerStatusDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!startTime_.jsonEncode(elementTree))
        {
    	     Log(Error, "ServerStatusDataType json encoder error")
    		     .parameter("Element", "startTime_");
            return false;
        }
        pt.push_back(std::make_pair("StartTime", elementTree));
    
        elementTree.clear();
        if (!currentTime_.jsonEncode(elementTree))
        {
    	     Log(Error, "ServerStatusDataType json encoder error")
    		     .parameter("Element", "currentTime_");
            return false;
        }
        pt.push_back(std::make_pair("CurrentTime", elementTree));
    
        elementTree.clear();
        if (!state_.jsonEncode(elementTree))
        {
    	     Log(Error, "ServerStatusDataType json encoder error")
    		     .parameter("Element", "state_");
            return false;
        }
        pt.push_back(std::make_pair("State", elementTree));
    
        elementTree.clear();
        if (!buildInfo_.jsonEncode(elementTree))
        {
    	     Log(Error, "ServerStatusDataType json encoder error")
    		     .parameter("Element", "buildInfo_");
            return false;
        }
        pt.push_back(std::make_pair("BuildInfo", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, secondsTillShutdown_))
        {
    	     Log(Error, "ServerStatusDataType json encoder error")
    		     .parameter("Element", "secondsTillShutdown_");
           return false;
        }
        pt.push_back(std::make_pair("SecondsTillShutdown", elementTree));
    
        elementTree.clear();
        if (!shutdownReason_.jsonEncode(elementTree))
        {
    	     Log(Error, "ServerStatusDataType json encoder error")
    		     .parameter("Element", "shutdownReason_");
            return false;
        }
        pt.push_back(std::make_pair("ShutdownReason", elementTree));
    
        return true;
    }
    
    bool
    ServerStatusDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "StartTime";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ServerStatusDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!startTime_.jsonDecode(*tree)) {
            Log(Error, "ServerStatusDataType decode json error - decode failed")
                .parameter("Element", "StartTime");
            return false;
        }
    
        elementName = "CurrentTime";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ServerStatusDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!currentTime_.jsonDecode(*tree)) {
            Log(Error, "ServerStatusDataType decode json error - decode failed")
                .parameter("Element", "CurrentTime");
            return false;
        }
    
        elementName = "State";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ServerStatusDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!state_.jsonDecode(*tree)) {
            Log(Error, "ServerStatusDataType decode json error - decode failed")
                .parameter("Element", "State");
            return false;
        }
    
        elementName = "BuildInfo";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ServerStatusDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!buildInfo_.jsonDecode(*tree)) {
            Log(Error, "ServerStatusDataType decode json error - decode failed")
                .parameter("Element", "BuildInfo");
            return false;
        }
    
        elementName = "SecondsTillShutdown";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ServerStatusDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, secondsTillShutdown_)) {
            Log(Error, "ServerStatusDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "ShutdownReason";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ServerStatusDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!shutdownReason_.jsonDecode(*tree)) {
            Log(Error, "ServerStatusDataType decode json error - decode failed")
                .parameter("Element", "ShutdownReason");
            return false;
        }
    
        return true;
    }
    
    void
    ServerStatusDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	ServerStatusDataType* dst = dynamic_cast<ServerStatusDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    ServerStatusDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	ServerStatusDataType* dst = dynamic_cast<ServerStatusDataType*>(&extensionObjectBase);
    	return *const_cast<ServerStatusDataType*>(this) == *dst;
    }
    
    void
    ServerStatusDataType::out(std::ostream& os)
    {
        os << "StartTime="; startTime_.out(os);
        os << ", CurrentTime="; currentTime_.out(os);
        os << ", State="; state_.out(os);
        os << ", BuildInfo="; buildInfo_.out(os);
        os << ", SecondsTillShutdown=" << secondsTillShutdown_;
        os << ", ShutdownReason="; shutdownReason_.out(os);
    }

}
