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
    ServerStatusDataType::operator==(const ServerStatusDataType& value) const
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
    ServerStatusDataType::operator!=(const ServerStatusDataType& value) const
    {
        return !this->operator==(value);
    }
    
    void
    ServerStatusDataType::copyTo(ServerStatusDataType& value)
    {
        value.startTime_ = startTime_;
        value.currentTime_ = currentTime_;
        value.state_ = state_;
        value.buildInfo_ = buildInfo_;
        value.secondsTillShutdown_ = secondsTillShutdown_;
        value.shutdownReason_ = shutdownReason_;
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
    
    OpcUaNodeId
    ServerStatusDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    ServerStatusDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
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
    ServerStatusDataType::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    ServerStatusDataType::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    ServerStatusDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    ServerStatusDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        if (!startTime_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("StartTime", elementTree));
    
        if (!currentTime_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("CurrentTime", elementTree));
    
        if (!state_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("State", elementTree));
    
        if (!buildInfo_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("BuildInfo", elementTree));
    
        if(!XmlNumber::xmlEncode(elementTree, secondsTillShutdown_)) return false;
        pt.push_back(std::make_pair("SecondsTillShutdown", elementTree));
    
        if (!shutdownReason_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("ShutdownReason", elementTree));
    
        return true;
    }
    
    bool
    ServerStatusDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
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
    	return *this == *dst;
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
