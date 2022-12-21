/*
    VariableTypeClass: SessionInfo

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/CustomerObjectType/SessionInfo.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    /**
     * Session Info
     */
    SessionInfo::SessionInfo(void)
    : ObjectBase()
    , clientAddress_Variable_(boost::make_shared<ServerVariable>("ClientAddress_Variable"))
    , endpointUrl_Variable_(boost::make_shared<ServerVariable>("EndpointUrl_Variable"))
    , sessionId_Variable_(boost::make_shared<ServerVariable>("SessionId_Variable"))
    , sessionState_Variable_(boost::make_shared<ServerVariable>("SessionState_Variable"))
    , sessionTimeout_Variable_(boost::make_shared<ServerVariable>("SessionTimeout_Variable"))
    , startTime_Variable_(boost::make_shared<ServerVariable>("StartTime_Variable"))
    {
        objectTypeNamespaceName("http://ASNeG-Server/");
        objectTypeNodeId((OpcUaUInt32)1002);
        setServerVariable(clientAddress_Variable_);
        setServerVariable(endpointUrl_Variable_);
        setServerVariable(sessionId_Variable_);
        setServerVariable(sessionState_Variable_);
        setServerVariable(sessionTimeout_Variable_);
        setServerVariable(startTime_Variable_);
    }
    
    /**
     * Session Info
     */
    SessionInfo::SessionInfo(const SessionInfo& value)
    : ObjectBase()
    , clientAddress_Variable_(boost::make_shared<ServerVariable>("ClientAddress_Variable"))
    , endpointUrl_Variable_(boost::make_shared<ServerVariable>("EndpointUrl_Variable"))
    , sessionId_Variable_(boost::make_shared<ServerVariable>("SessionId_Variable"))
    , sessionState_Variable_(boost::make_shared<ServerVariable>("SessionState_Variable"))
    , sessionTimeout_Variable_(boost::make_shared<ServerVariable>("SessionTimeout_Variable"))
    , startTime_Variable_(boost::make_shared<ServerVariable>("StartTime_Variable"))
    {
        objectTypeNamespaceName("http://ASNeG-Server/");
        objectTypeNodeId((OpcUaUInt32)1002);
        setServerVariable(clientAddress_Variable_);
        setServerVariable(endpointUrl_Variable_);
        setServerVariable(sessionId_Variable_);
        setServerVariable(sessionState_Variable_);
        setServerVariable(sessionTimeout_Variable_);
        setServerVariable(startTime_Variable_);
    }
    
    SessionInfo::~SessionInfo(void)
    {
    }

    ServerVariable::SPtr&
    SessionInfo::clientAddress_Variable(void)
    {
        return clientAddress_Variable_;
    }

    ServerVariable::SPtr&
    SessionInfo::endpointUrl_Variable(void)
    {
        return endpointUrl_Variable_;
    }

    ServerVariable::SPtr&
    SessionInfo::sessionId_Variable(void)
    {
        return sessionId_Variable_;
    }

    ServerVariable::SPtr&
    SessionInfo::sessionState_Variable(void)
    {
        return sessionState_Variable_;
    }

    ServerVariable::SPtr&
    SessionInfo::sessionTimeout_Variable(void)
    {
        return sessionTimeout_Variable_;
    }

    ServerVariable::SPtr&
    SessionInfo::startTime_Variable(void)
    {
        return startTime_Variable_;
    }

    void
    SessionInfo::clientAddress_Variable(ServerVariable::SPtr& serverVariable)
    {
        clientAddress_Variable_ = serverVariable;
    }

    void
    SessionInfo::endpointUrl_Variable(ServerVariable::SPtr& serverVariable)
    {
        endpointUrl_Variable_ = serverVariable;
    }

    void
    SessionInfo::sessionId_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionId_Variable_ = serverVariable;
    }

    void
    SessionInfo::sessionState_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionState_Variable_ = serverVariable;
    }

    void
    SessionInfo::sessionTimeout_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionTimeout_Variable_ = serverVariable;
    }

    void
    SessionInfo::startTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        startTime_Variable_ = serverVariable;
    }

    bool
    SessionInfo::get_ClientAddress_Variable(OpcUaDataValue& dataValue)
    {
        return clientAddress_Variable_->getDataValue(dataValue);
    }

    bool
    SessionInfo::get_EndpointUrl_Variable(OpcUaDataValue& dataValue)
    {
        return endpointUrl_Variable_->getDataValue(dataValue);
    }

    bool
    SessionInfo::get_SessionId_Variable(OpcUaDataValue& dataValue)
    {
        return sessionId_Variable_->getDataValue(dataValue);
    }

    bool
    SessionInfo::get_SessionState_Variable(OpcUaDataValue& dataValue)
    {
        return sessionState_Variable_->getDataValue(dataValue);
    }

    bool
    SessionInfo::get_SessionTimeout_Variable(OpcUaDataValue& dataValue)
    {
        return sessionTimeout_Variable_->getDataValue(dataValue);
    }

    bool
    SessionInfo::get_StartTime_Variable(OpcUaDataValue& dataValue)
    {
        return startTime_Variable_->getDataValue(dataValue);
    }

    bool
    SessionInfo::set_ClientAddress_Variable(const OpcUaDataValue& dataValue)
    {
        return clientAddress_Variable_->setDataValue(dataValue);
    }

    bool
    SessionInfo::set_EndpointUrl_Variable(const OpcUaDataValue& dataValue)
    {
        return endpointUrl_Variable_->setDataValue(dataValue);
    }

    bool
    SessionInfo::set_SessionId_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionId_Variable_->setDataValue(dataValue);
    }

    bool
    SessionInfo::set_SessionState_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionState_Variable_->setDataValue(dataValue);
    }

    bool
    SessionInfo::set_SessionTimeout_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionTimeout_Variable_->setDataValue(dataValue);
    }

    bool
    SessionInfo::set_StartTime_Variable(const OpcUaDataValue& dataValue)
    {
        return startTime_Variable_->setDataValue(dataValue);
    }

}
