/*
    VariableTypeClass: ServerStatusType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/ServerStatusType.h"

namespace OpcUaStackServer
{
    
    ServerStatusType::ServerStatusType(void)
    : VariableBase()
    , buildInfo_BuildDate_Variable_(boost::make_shared<ServerVariable>("BuildInfo_BuildDate_Variable"))
    , buildInfo_BuildNumber_Variable_(boost::make_shared<ServerVariable>("BuildInfo_BuildNumber_Variable"))
    , buildInfo_ManufacturerName_Variable_(boost::make_shared<ServerVariable>("BuildInfo_ManufacturerName_Variable"))
    , buildInfo_ProductName_Variable_(boost::make_shared<ServerVariable>("BuildInfo_ProductName_Variable"))
    , buildInfo_ProductUri_Variable_(boost::make_shared<ServerVariable>("BuildInfo_ProductUri_Variable"))
    , buildInfo_SoftwareVersion_Variable_(boost::make_shared<ServerVariable>("BuildInfo_SoftwareVersion_Variable"))
    , buildInfo_Variable_(boost::make_shared<ServerVariable>("BuildInfo_Variable"))
    , currentTime_Variable_(boost::make_shared<ServerVariable>("CurrentTime_Variable"))
    , secondsTillShutdown_Variable_(boost::make_shared<ServerVariable>("SecondsTillShutdown_Variable"))
    , shutdownReason_Variable_(boost::make_shared<ServerVariable>("ShutdownReason_Variable"))
    , startTime_Variable_(boost::make_shared<ServerVariable>("StartTime_Variable"))
    , state_Variable_(boost::make_shared<ServerVariable>("State_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2138);
        setServerVariable(buildInfo_BuildDate_Variable_);
        setServerVariable(buildInfo_BuildNumber_Variable_);
        setServerVariable(buildInfo_ManufacturerName_Variable_);
        setServerVariable(buildInfo_ProductName_Variable_);
        setServerVariable(buildInfo_ProductUri_Variable_);
        setServerVariable(buildInfo_SoftwareVersion_Variable_);
        setServerVariable(buildInfo_Variable_);
        setServerVariable(currentTime_Variable_);
        setServerVariable(secondsTillShutdown_Variable_);
        setServerVariable(shutdownReason_Variable_);
        setServerVariable(startTime_Variable_);
        setServerVariable(state_Variable_);
        setServerVariable(variable_);
    }
    
    ServerStatusType::ServerStatusType(const ServerStatusType& value)
    : VariableBase()
    , buildInfo_BuildDate_Variable_(boost::make_shared<ServerVariable>("BuildInfo_BuildDate_Variable"))
    , buildInfo_BuildNumber_Variable_(boost::make_shared<ServerVariable>("BuildInfo_BuildNumber_Variable"))
    , buildInfo_ManufacturerName_Variable_(boost::make_shared<ServerVariable>("BuildInfo_ManufacturerName_Variable"))
    , buildInfo_ProductName_Variable_(boost::make_shared<ServerVariable>("BuildInfo_ProductName_Variable"))
    , buildInfo_ProductUri_Variable_(boost::make_shared<ServerVariable>("BuildInfo_ProductUri_Variable"))
    , buildInfo_SoftwareVersion_Variable_(boost::make_shared<ServerVariable>("BuildInfo_SoftwareVersion_Variable"))
    , buildInfo_Variable_(boost::make_shared<ServerVariable>("BuildInfo_Variable"))
    , currentTime_Variable_(boost::make_shared<ServerVariable>("CurrentTime_Variable"))
    , secondsTillShutdown_Variable_(boost::make_shared<ServerVariable>("SecondsTillShutdown_Variable"))
    , shutdownReason_Variable_(boost::make_shared<ServerVariable>("ShutdownReason_Variable"))
    , startTime_Variable_(boost::make_shared<ServerVariable>("StartTime_Variable"))
    , state_Variable_(boost::make_shared<ServerVariable>("State_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2138);
        setServerVariable(buildInfo_BuildDate_Variable_);
        setServerVariable(buildInfo_BuildNumber_Variable_);
        setServerVariable(buildInfo_ManufacturerName_Variable_);
        setServerVariable(buildInfo_ProductName_Variable_);
        setServerVariable(buildInfo_ProductUri_Variable_);
        setServerVariable(buildInfo_SoftwareVersion_Variable_);
        setServerVariable(buildInfo_Variable_);
        setServerVariable(currentTime_Variable_);
        setServerVariable(secondsTillShutdown_Variable_);
        setServerVariable(shutdownReason_Variable_);
        setServerVariable(startTime_Variable_);
        setServerVariable(state_Variable_);
        setServerVariable(variable_);
    }
    
    ServerStatusType::~ServerStatusType(void)
    {
    }

    ServerVariable::SPtr&
    ServerStatusType::buildInfo_BuildDate_Variable(void)
    {
        return buildInfo_BuildDate_Variable_;
    }

    ServerVariable::SPtr&
    ServerStatusType::buildInfo_BuildNumber_Variable(void)
    {
        return buildInfo_BuildNumber_Variable_;
    }

    ServerVariable::SPtr&
    ServerStatusType::buildInfo_ManufacturerName_Variable(void)
    {
        return buildInfo_ManufacturerName_Variable_;
    }

    ServerVariable::SPtr&
    ServerStatusType::buildInfo_ProductName_Variable(void)
    {
        return buildInfo_ProductName_Variable_;
    }

    ServerVariable::SPtr&
    ServerStatusType::buildInfo_ProductUri_Variable(void)
    {
        return buildInfo_ProductUri_Variable_;
    }

    ServerVariable::SPtr&
    ServerStatusType::buildInfo_SoftwareVersion_Variable(void)
    {
        return buildInfo_SoftwareVersion_Variable_;
    }

    ServerVariable::SPtr&
    ServerStatusType::buildInfo_Variable(void)
    {
        return buildInfo_Variable_;
    }

    ServerVariable::SPtr&
    ServerStatusType::currentTime_Variable(void)
    {
        return currentTime_Variable_;
    }

    ServerVariable::SPtr&
    ServerStatusType::secondsTillShutdown_Variable(void)
    {
        return secondsTillShutdown_Variable_;
    }

    ServerVariable::SPtr&
    ServerStatusType::shutdownReason_Variable(void)
    {
        return shutdownReason_Variable_;
    }

    ServerVariable::SPtr&
    ServerStatusType::startTime_Variable(void)
    {
        return startTime_Variable_;
    }

    ServerVariable::SPtr&
    ServerStatusType::state_Variable(void)
    {
        return state_Variable_;
    }

    ServerVariable::SPtr&
    ServerStatusType::variable(void)
    {
        return variable_;
    }

    void
    ServerStatusType::buildInfo_BuildDate_Variable(ServerVariable::SPtr& serverVariable)
    {
        buildInfo_BuildDate_Variable_ = serverVariable;
    }

    void
    ServerStatusType::buildInfo_BuildNumber_Variable(ServerVariable::SPtr& serverVariable)
    {
        buildInfo_BuildNumber_Variable_ = serverVariable;
    }

    void
    ServerStatusType::buildInfo_ManufacturerName_Variable(ServerVariable::SPtr& serverVariable)
    {
        buildInfo_ManufacturerName_Variable_ = serverVariable;
    }

    void
    ServerStatusType::buildInfo_ProductName_Variable(ServerVariable::SPtr& serverVariable)
    {
        buildInfo_ProductName_Variable_ = serverVariable;
    }

    void
    ServerStatusType::buildInfo_ProductUri_Variable(ServerVariable::SPtr& serverVariable)
    {
        buildInfo_ProductUri_Variable_ = serverVariable;
    }

    void
    ServerStatusType::buildInfo_SoftwareVersion_Variable(ServerVariable::SPtr& serverVariable)
    {
        buildInfo_SoftwareVersion_Variable_ = serverVariable;
    }

    void
    ServerStatusType::buildInfo_Variable(ServerVariable::SPtr& serverVariable)
    {
        buildInfo_Variable_ = serverVariable;
    }

    void
    ServerStatusType::currentTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        currentTime_Variable_ = serverVariable;
    }

    void
    ServerStatusType::secondsTillShutdown_Variable(ServerVariable::SPtr& serverVariable)
    {
        secondsTillShutdown_Variable_ = serverVariable;
    }

    void
    ServerStatusType::shutdownReason_Variable(ServerVariable::SPtr& serverVariable)
    {
        shutdownReason_Variable_ = serverVariable;
    }

    void
    ServerStatusType::startTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        startTime_Variable_ = serverVariable;
    }

    void
    ServerStatusType::state_Variable(ServerVariable::SPtr& serverVariable)
    {
        state_Variable_ = serverVariable;
    }

    void
    ServerStatusType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    bool
    ServerStatusType::get_BuildInfo_BuildDate_Variable(OpcUaDataValue& dataValue)
    {
        return buildInfo_BuildDate_Variable_->getDataValue(dataValue);
    }

    bool
    ServerStatusType::get_BuildInfo_BuildNumber_Variable(OpcUaDataValue& dataValue)
    {
        return buildInfo_BuildNumber_Variable_->getDataValue(dataValue);
    }

    bool
    ServerStatusType::get_BuildInfo_ManufacturerName_Variable(OpcUaDataValue& dataValue)
    {
        return buildInfo_ManufacturerName_Variable_->getDataValue(dataValue);
    }

    bool
    ServerStatusType::get_BuildInfo_ProductName_Variable(OpcUaDataValue& dataValue)
    {
        return buildInfo_ProductName_Variable_->getDataValue(dataValue);
    }

    bool
    ServerStatusType::get_BuildInfo_ProductUri_Variable(OpcUaDataValue& dataValue)
    {
        return buildInfo_ProductUri_Variable_->getDataValue(dataValue);
    }

    bool
    ServerStatusType::get_BuildInfo_SoftwareVersion_Variable(OpcUaDataValue& dataValue)
    {
        return buildInfo_SoftwareVersion_Variable_->getDataValue(dataValue);
    }

    bool
    ServerStatusType::get_BuildInfo_Variable(OpcUaDataValue& dataValue)
    {
        return buildInfo_Variable_->getDataValue(dataValue);
    }

    bool
    ServerStatusType::get_CurrentTime_Variable(OpcUaDataValue& dataValue)
    {
        return currentTime_Variable_->getDataValue(dataValue);
    }

    bool
    ServerStatusType::get_SecondsTillShutdown_Variable(OpcUaDataValue& dataValue)
    {
        return secondsTillShutdown_Variable_->getDataValue(dataValue);
    }

    bool
    ServerStatusType::get_ShutdownReason_Variable(OpcUaDataValue& dataValue)
    {
        return shutdownReason_Variable_->getDataValue(dataValue);
    }

    bool
    ServerStatusType::get_StartTime_Variable(OpcUaDataValue& dataValue)
    {
        return startTime_Variable_->getDataValue(dataValue);
    }

    bool
    ServerStatusType::get_State_Variable(OpcUaDataValue& dataValue)
    {
        return state_Variable_->getDataValue(dataValue);
    }

    bool
    ServerStatusType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    ServerStatusType::set_BuildInfo_BuildDate_Variable(const OpcUaDataValue& dataValue)
    {
        return buildInfo_BuildDate_Variable_->setDataValue(dataValue);
    }

    bool
    ServerStatusType::set_BuildInfo_BuildNumber_Variable(const OpcUaDataValue& dataValue)
    {
        return buildInfo_BuildNumber_Variable_->setDataValue(dataValue);
    }

    bool
    ServerStatusType::set_BuildInfo_ManufacturerName_Variable(const OpcUaDataValue& dataValue)
    {
        return buildInfo_ManufacturerName_Variable_->setDataValue(dataValue);
    }

    bool
    ServerStatusType::set_BuildInfo_ProductName_Variable(const OpcUaDataValue& dataValue)
    {
        return buildInfo_ProductName_Variable_->setDataValue(dataValue);
    }

    bool
    ServerStatusType::set_BuildInfo_ProductUri_Variable(const OpcUaDataValue& dataValue)
    {
        return buildInfo_ProductUri_Variable_->setDataValue(dataValue);
    }

    bool
    ServerStatusType::set_BuildInfo_SoftwareVersion_Variable(const OpcUaDataValue& dataValue)
    {
        return buildInfo_SoftwareVersion_Variable_->setDataValue(dataValue);
    }

    bool
    ServerStatusType::set_BuildInfo_Variable(const OpcUaDataValue& dataValue)
    {
        return buildInfo_Variable_->setDataValue(dataValue);
    }

    bool
    ServerStatusType::set_CurrentTime_Variable(const OpcUaDataValue& dataValue)
    {
        return currentTime_Variable_->setDataValue(dataValue);
    }

    bool
    ServerStatusType::set_SecondsTillShutdown_Variable(const OpcUaDataValue& dataValue)
    {
        return secondsTillShutdown_Variable_->setDataValue(dataValue);
    }

    bool
    ServerStatusType::set_ShutdownReason_Variable(const OpcUaDataValue& dataValue)
    {
        return shutdownReason_Variable_->setDataValue(dataValue);
    }

    bool
    ServerStatusType::set_StartTime_Variable(const OpcUaDataValue& dataValue)
    {
        return startTime_Variable_->setDataValue(dataValue);
    }

    bool
    ServerStatusType::set_State_Variable(const OpcUaDataValue& dataValue)
    {
        return state_Variable_->setDataValue(dataValue);
    }

    bool
    ServerStatusType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

}
