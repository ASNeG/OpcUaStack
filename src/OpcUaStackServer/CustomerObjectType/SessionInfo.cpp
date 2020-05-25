/*
    VariableTypeClass: SessionInfo

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/CustomerObjectType/SessionInfo.h"

namespace OpcUaStackServer
{
    
    /**
     * Session Info
     */
    SessionInfo::SessionInfo(void)
    : ObjectBase()
    , id_Variable_(boost::make_shared<ServerVariable>("Id_Variable"))
    , timeout_Variable_(boost::make_shared<ServerVariable>("Timeout_Variable"))
    {
        objectTypeNamespaceName("http://ASNeG-Server/");
        objectTypeNodeId((OpcUaUInt32)1002);
        setServerVariable(id_Variable_);
        setServerVariable(timeout_Variable_);
    }
    
    /**
     * Session Info
     */
    SessionInfo::SessionInfo(const SessionInfo& value)
    : ObjectBase()
    , id_Variable_(boost::make_shared<ServerVariable>("Id_Variable"))
    , timeout_Variable_(boost::make_shared<ServerVariable>("Timeout_Variable"))
    {
        objectTypeNamespaceName("http://ASNeG-Server/");
        objectTypeNodeId((OpcUaUInt32)1002);
        setServerVariable(id_Variable_);
        setServerVariable(timeout_Variable_);
    }
    
    SessionInfo::~SessionInfo(void)
    {
    }

    ServerVariable::SPtr&
    SessionInfo::id_Variable(void)
    {
        return id_Variable_;
    }

    ServerVariable::SPtr&
    SessionInfo::timeout_Variable(void)
    {
        return timeout_Variable_;
    }

    void
    SessionInfo::id_Variable(ServerVariable::SPtr& serverVariable)
    {
        id_Variable_ = serverVariable;
    }

    void
    SessionInfo::timeout_Variable(ServerVariable::SPtr& serverVariable)
    {
        timeout_Variable_ = serverVariable;
    }

    bool
    SessionInfo::get_Id_Variable(OpcUaDataValue& dataValue)
    {
        return id_Variable_->getDataValue(dataValue);
    }

    bool
    SessionInfo::get_Timeout_Variable(OpcUaDataValue& dataValue)
    {
        return timeout_Variable_->getDataValue(dataValue);
    }

    bool
    SessionInfo::set_Id_Variable(const OpcUaDataValue& dataValue)
    {
        return id_Variable_->setDataValue(dataValue);
    }

    bool
    SessionInfo::set_Timeout_Variable(const OpcUaDataValue& dataValue)
    {
        return timeout_Variable_->setDataValue(dataValue);
    }

}
