/*
    VariableTypeClass: AlarmMetricsType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/AlarmMetricsType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    AlarmMetricsType::AlarmMetricsType(void)
    : ObjectBase()
    , alarmCount_Variable_(boost::make_shared<ServerVariable>("AlarmCount_Variable"))
    , averageAlarmRate_Rate_Variable_(boost::make_shared<ServerVariable>("AverageAlarmRate_Rate_Variable"))
    , averageAlarmRate_Variable_(boost::make_shared<ServerVariable>("AverageAlarmRate_Variable"))
    , currentAlarmRate_Rate_Variable_(boost::make_shared<ServerVariable>("CurrentAlarmRate_Rate_Variable"))
    , currentAlarmRate_Variable_(boost::make_shared<ServerVariable>("CurrentAlarmRate_Variable"))
    , maximumActiveState_Variable_(boost::make_shared<ServerVariable>("MaximumActiveState_Variable"))
    , maximumAlarmRate_Rate_Variable_(boost::make_shared<ServerVariable>("MaximumAlarmRate_Rate_Variable"))
    , maximumAlarmRate_Variable_(boost::make_shared<ServerVariable>("MaximumAlarmRate_Variable"))
    , maximumReAlarmCount_Variable_(boost::make_shared<ServerVariable>("MaximumReAlarmCount_Variable"))
    , maximumUnAck_Variable_(boost::make_shared<ServerVariable>("MaximumUnAck_Variable"))
    , startTime_Variable_(boost::make_shared<ServerVariable>("StartTime_Variable"))
    , reset_Method_(boost::make_shared<ServerMethod>("Reset_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)17279);
        setServerVariable(alarmCount_Variable_);
        setServerVariable(averageAlarmRate_Rate_Variable_);
        setServerVariable(averageAlarmRate_Variable_);
        setServerVariable(currentAlarmRate_Rate_Variable_);
        setServerVariable(currentAlarmRate_Variable_);
        setServerVariable(maximumActiveState_Variable_);
        setServerVariable(maximumAlarmRate_Rate_Variable_);
        setServerVariable(maximumAlarmRate_Variable_);
        setServerVariable(maximumReAlarmCount_Variable_);
        setServerVariable(maximumUnAck_Variable_);
        setServerVariable(startTime_Variable_);
        setServerMethod(reset_Method_);
        reset_Method_->registerMethod(boost::bind(&AlarmMetricsType::call_Reset_Method, this, boost::placeholders::_1));
    }
    
    AlarmMetricsType::AlarmMetricsType(const AlarmMetricsType& value)
    : ObjectBase()
    , alarmCount_Variable_(boost::make_shared<ServerVariable>("AlarmCount_Variable"))
    , averageAlarmRate_Rate_Variable_(boost::make_shared<ServerVariable>("AverageAlarmRate_Rate_Variable"))
    , averageAlarmRate_Variable_(boost::make_shared<ServerVariable>("AverageAlarmRate_Variable"))
    , currentAlarmRate_Rate_Variable_(boost::make_shared<ServerVariable>("CurrentAlarmRate_Rate_Variable"))
    , currentAlarmRate_Variable_(boost::make_shared<ServerVariable>("CurrentAlarmRate_Variable"))
    , maximumActiveState_Variable_(boost::make_shared<ServerVariable>("MaximumActiveState_Variable"))
    , maximumAlarmRate_Rate_Variable_(boost::make_shared<ServerVariable>("MaximumAlarmRate_Rate_Variable"))
    , maximumAlarmRate_Variable_(boost::make_shared<ServerVariable>("MaximumAlarmRate_Variable"))
    , maximumReAlarmCount_Variable_(boost::make_shared<ServerVariable>("MaximumReAlarmCount_Variable"))
    , maximumUnAck_Variable_(boost::make_shared<ServerVariable>("MaximumUnAck_Variable"))
    , startTime_Variable_(boost::make_shared<ServerVariable>("StartTime_Variable"))
    , reset_Method_(boost::make_shared<ServerMethod>("Reset_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)17279);
        setServerVariable(alarmCount_Variable_);
        setServerVariable(averageAlarmRate_Rate_Variable_);
        setServerVariable(averageAlarmRate_Variable_);
        setServerVariable(currentAlarmRate_Rate_Variable_);
        setServerVariable(currentAlarmRate_Variable_);
        setServerVariable(maximumActiveState_Variable_);
        setServerVariable(maximumAlarmRate_Rate_Variable_);
        setServerVariable(maximumAlarmRate_Variable_);
        setServerVariable(maximumReAlarmCount_Variable_);
        setServerVariable(maximumUnAck_Variable_);
        setServerVariable(startTime_Variable_);
        setServerMethod(reset_Method_);
        reset_Method_->registerMethod(boost::bind(&AlarmMetricsType::call_Reset_Method, this, boost::placeholders::_1));
    }
    
    AlarmMetricsType::~AlarmMetricsType(void)
    {
    }

    ServerVariable::SPtr&
    AlarmMetricsType::alarmCount_Variable(void)
    {
        return alarmCount_Variable_;
    }

    ServerVariable::SPtr&
    AlarmMetricsType::averageAlarmRate_Rate_Variable(void)
    {
        return averageAlarmRate_Rate_Variable_;
    }

    ServerVariable::SPtr&
    AlarmMetricsType::averageAlarmRate_Variable(void)
    {
        return averageAlarmRate_Variable_;
    }

    ServerVariable::SPtr&
    AlarmMetricsType::currentAlarmRate_Rate_Variable(void)
    {
        return currentAlarmRate_Rate_Variable_;
    }

    ServerVariable::SPtr&
    AlarmMetricsType::currentAlarmRate_Variable(void)
    {
        return currentAlarmRate_Variable_;
    }

    ServerVariable::SPtr&
    AlarmMetricsType::maximumActiveState_Variable(void)
    {
        return maximumActiveState_Variable_;
    }

    ServerVariable::SPtr&
    AlarmMetricsType::maximumAlarmRate_Rate_Variable(void)
    {
        return maximumAlarmRate_Rate_Variable_;
    }

    ServerVariable::SPtr&
    AlarmMetricsType::maximumAlarmRate_Variable(void)
    {
        return maximumAlarmRate_Variable_;
    }

    ServerVariable::SPtr&
    AlarmMetricsType::maximumReAlarmCount_Variable(void)
    {
        return maximumReAlarmCount_Variable_;
    }

    ServerVariable::SPtr&
    AlarmMetricsType::maximumUnAck_Variable(void)
    {
        return maximumUnAck_Variable_;
    }

    ServerVariable::SPtr&
    AlarmMetricsType::startTime_Variable(void)
    {
        return startTime_Variable_;
    }

    void
    AlarmMetricsType::alarmCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        alarmCount_Variable_ = serverVariable;
    }

    void
    AlarmMetricsType::averageAlarmRate_Rate_Variable(ServerVariable::SPtr& serverVariable)
    {
        averageAlarmRate_Rate_Variable_ = serverVariable;
    }

    void
    AlarmMetricsType::averageAlarmRate_Variable(ServerVariable::SPtr& serverVariable)
    {
        averageAlarmRate_Variable_ = serverVariable;
    }

    void
    AlarmMetricsType::currentAlarmRate_Rate_Variable(ServerVariable::SPtr& serverVariable)
    {
        currentAlarmRate_Rate_Variable_ = serverVariable;
    }

    void
    AlarmMetricsType::currentAlarmRate_Variable(ServerVariable::SPtr& serverVariable)
    {
        currentAlarmRate_Variable_ = serverVariable;
    }

    void
    AlarmMetricsType::maximumActiveState_Variable(ServerVariable::SPtr& serverVariable)
    {
        maximumActiveState_Variable_ = serverVariable;
    }

    void
    AlarmMetricsType::maximumAlarmRate_Rate_Variable(ServerVariable::SPtr& serverVariable)
    {
        maximumAlarmRate_Rate_Variable_ = serverVariable;
    }

    void
    AlarmMetricsType::maximumAlarmRate_Variable(ServerVariable::SPtr& serverVariable)
    {
        maximumAlarmRate_Variable_ = serverVariable;
    }

    void
    AlarmMetricsType::maximumReAlarmCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        maximumReAlarmCount_Variable_ = serverVariable;
    }

    void
    AlarmMetricsType::maximumUnAck_Variable(ServerVariable::SPtr& serverVariable)
    {
        maximumUnAck_Variable_ = serverVariable;
    }

    void
    AlarmMetricsType::startTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        startTime_Variable_ = serverVariable;
    }

    bool
    AlarmMetricsType::get_AlarmCount_Variable(OpcUaDataValue& dataValue)
    {
        return alarmCount_Variable_->getDataValue(dataValue);
    }

    bool
    AlarmMetricsType::get_AverageAlarmRate_Rate_Variable(OpcUaDataValue& dataValue)
    {
        return averageAlarmRate_Rate_Variable_->getDataValue(dataValue);
    }

    bool
    AlarmMetricsType::get_AverageAlarmRate_Variable(OpcUaDataValue& dataValue)
    {
        return averageAlarmRate_Variable_->getDataValue(dataValue);
    }

    bool
    AlarmMetricsType::get_CurrentAlarmRate_Rate_Variable(OpcUaDataValue& dataValue)
    {
        return currentAlarmRate_Rate_Variable_->getDataValue(dataValue);
    }

    bool
    AlarmMetricsType::get_CurrentAlarmRate_Variable(OpcUaDataValue& dataValue)
    {
        return currentAlarmRate_Variable_->getDataValue(dataValue);
    }

    bool
    AlarmMetricsType::get_MaximumActiveState_Variable(OpcUaDataValue& dataValue)
    {
        return maximumActiveState_Variable_->getDataValue(dataValue);
    }

    bool
    AlarmMetricsType::get_MaximumAlarmRate_Rate_Variable(OpcUaDataValue& dataValue)
    {
        return maximumAlarmRate_Rate_Variable_->getDataValue(dataValue);
    }

    bool
    AlarmMetricsType::get_MaximumAlarmRate_Variable(OpcUaDataValue& dataValue)
    {
        return maximumAlarmRate_Variable_->getDataValue(dataValue);
    }

    bool
    AlarmMetricsType::get_MaximumReAlarmCount_Variable(OpcUaDataValue& dataValue)
    {
        return maximumReAlarmCount_Variable_->getDataValue(dataValue);
    }

    bool
    AlarmMetricsType::get_MaximumUnAck_Variable(OpcUaDataValue& dataValue)
    {
        return maximumUnAck_Variable_->getDataValue(dataValue);
    }

    bool
    AlarmMetricsType::get_StartTime_Variable(OpcUaDataValue& dataValue)
    {
        return startTime_Variable_->getDataValue(dataValue);
    }

    bool
    AlarmMetricsType::set_AlarmCount_Variable(const OpcUaDataValue& dataValue)
    {
        return alarmCount_Variable_->setDataValue(dataValue);
    }

    bool
    AlarmMetricsType::set_AverageAlarmRate_Rate_Variable(const OpcUaDataValue& dataValue)
    {
        return averageAlarmRate_Rate_Variable_->setDataValue(dataValue);
    }

    bool
    AlarmMetricsType::set_AverageAlarmRate_Variable(const OpcUaDataValue& dataValue)
    {
        return averageAlarmRate_Variable_->setDataValue(dataValue);
    }

    bool
    AlarmMetricsType::set_CurrentAlarmRate_Rate_Variable(const OpcUaDataValue& dataValue)
    {
        return currentAlarmRate_Rate_Variable_->setDataValue(dataValue);
    }

    bool
    AlarmMetricsType::set_CurrentAlarmRate_Variable(const OpcUaDataValue& dataValue)
    {
        return currentAlarmRate_Variable_->setDataValue(dataValue);
    }

    bool
    AlarmMetricsType::set_MaximumActiveState_Variable(const OpcUaDataValue& dataValue)
    {
        return maximumActiveState_Variable_->setDataValue(dataValue);
    }

    bool
    AlarmMetricsType::set_MaximumAlarmRate_Rate_Variable(const OpcUaDataValue& dataValue)
    {
        return maximumAlarmRate_Rate_Variable_->setDataValue(dataValue);
    }

    bool
    AlarmMetricsType::set_MaximumAlarmRate_Variable(const OpcUaDataValue& dataValue)
    {
        return maximumAlarmRate_Variable_->setDataValue(dataValue);
    }

    bool
    AlarmMetricsType::set_MaximumReAlarmCount_Variable(const OpcUaDataValue& dataValue)
    {
        return maximumReAlarmCount_Variable_->setDataValue(dataValue);
    }

    bool
    AlarmMetricsType::set_MaximumUnAck_Variable(const OpcUaDataValue& dataValue)
    {
        return maximumUnAck_Variable_->setDataValue(dataValue);
    }

    bool
    AlarmMetricsType::set_StartTime_Variable(const OpcUaDataValue& dataValue)
    {
        return startTime_Variable_->setDataValue(dataValue);
    }

    void
    AlarmMetricsType::call_Reset_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

}
