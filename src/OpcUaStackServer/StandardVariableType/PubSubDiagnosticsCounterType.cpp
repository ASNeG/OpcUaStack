/*
    VariableTypeClass: PubSubDiagnosticsCounterType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/PubSubDiagnosticsCounterType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    PubSubDiagnosticsCounterType::PubSubDiagnosticsCounterType(void)
    : VariableBase()
    , active_Variable_(boost::make_shared<ServerVariable>("Active_Variable"))
    , classification_Variable_(boost::make_shared<ServerVariable>("Classification_Variable"))
    , diagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("DiagnosticsLevel_Variable"))
    , timeFirstChange_Variable_(boost::make_shared<ServerVariable>("TimeFirstChange_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)19725);
        setServerVariable(active_Variable_);
        setServerVariable(classification_Variable_);
        setServerVariable(diagnosticsLevel_Variable_);
        setServerVariable(timeFirstChange_Variable_);
        setServerVariable(variable_);
    }
    
    PubSubDiagnosticsCounterType::PubSubDiagnosticsCounterType(const PubSubDiagnosticsCounterType& value)
    : VariableBase()
    , active_Variable_(boost::make_shared<ServerVariable>("Active_Variable"))
    , classification_Variable_(boost::make_shared<ServerVariable>("Classification_Variable"))
    , diagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("DiagnosticsLevel_Variable"))
    , timeFirstChange_Variable_(boost::make_shared<ServerVariable>("TimeFirstChange_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)19725);
        setServerVariable(active_Variable_);
        setServerVariable(classification_Variable_);
        setServerVariable(diagnosticsLevel_Variable_);
        setServerVariable(timeFirstChange_Variable_);
        setServerVariable(variable_);
    }
    
    PubSubDiagnosticsCounterType::~PubSubDiagnosticsCounterType(void)
    {
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsCounterType::active_Variable(void)
    {
        return active_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsCounterType::classification_Variable(void)
    {
        return classification_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsCounterType::diagnosticsLevel_Variable(void)
    {
        return diagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsCounterType::timeFirstChange_Variable(void)
    {
        return timeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsCounterType::variable(void)
    {
        return variable_;
    }

    void
    PubSubDiagnosticsCounterType::active_Variable(ServerVariable::SPtr& serverVariable)
    {
        active_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsCounterType::classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        classification_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsCounterType::diagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnosticsLevel_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsCounterType::timeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        timeFirstChange_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsCounterType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    bool
    PubSubDiagnosticsCounterType::get_Active_Variable(OpcUaDataValue& dataValue)
    {
        return active_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsCounterType::get_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return classification_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsCounterType::get_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsCounterType::get_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return timeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsCounterType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsCounterType::set_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return active_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsCounterType::set_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return classification_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsCounterType::set_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsCounterType::set_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return timeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsCounterType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

}
