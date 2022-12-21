/*
    VariableTypeClass: TargetVariablesType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/TargetVariablesType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    TargetVariablesType::TargetVariablesType(void)
    : ObjectBase()
    , dataSetMetaData_Variable_(boost::make_shared<ServerVariable>("DataSetMetaData_Variable"))
    , messageReceiveTimeout_Variable_(boost::make_shared<ServerVariable>("MessageReceiveTimeout_Variable"))
    , targetVariables_Variable_(boost::make_shared<ServerVariable>("TargetVariables_Variable"))
    , addTargetVariables_Method_(boost::make_shared<ServerMethod>("AddTargetVariables_Method"))
    , removeTargetVariables_Method_(boost::make_shared<ServerMethod>("RemoveTargetVariables_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)15111);
        setServerVariable(dataSetMetaData_Variable_);
        setServerVariable(messageReceiveTimeout_Variable_);
        setServerVariable(targetVariables_Variable_);
        setServerMethod(addTargetVariables_Method_);
        setServerMethod(removeTargetVariables_Method_);
        addTargetVariables_Method_->registerMethod(boost::bind(&TargetVariablesType::call_AddTargetVariables_Method, this, boost::placeholders::_1));
        removeTargetVariables_Method_->registerMethod(boost::bind(&TargetVariablesType::call_RemoveTargetVariables_Method, this, boost::placeholders::_1));
    }
    
    TargetVariablesType::TargetVariablesType(const TargetVariablesType& value)
    : ObjectBase()
    , dataSetMetaData_Variable_(boost::make_shared<ServerVariable>("DataSetMetaData_Variable"))
    , messageReceiveTimeout_Variable_(boost::make_shared<ServerVariable>("MessageReceiveTimeout_Variable"))
    , targetVariables_Variable_(boost::make_shared<ServerVariable>("TargetVariables_Variable"))
    , addTargetVariables_Method_(boost::make_shared<ServerMethod>("AddTargetVariables_Method"))
    , removeTargetVariables_Method_(boost::make_shared<ServerMethod>("RemoveTargetVariables_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)15111);
        setServerVariable(dataSetMetaData_Variable_);
        setServerVariable(messageReceiveTimeout_Variable_);
        setServerVariable(targetVariables_Variable_);
        setServerMethod(addTargetVariables_Method_);
        setServerMethod(removeTargetVariables_Method_);
        addTargetVariables_Method_->registerMethod(boost::bind(&TargetVariablesType::call_AddTargetVariables_Method, this, boost::placeholders::_1));
        removeTargetVariables_Method_->registerMethod(boost::bind(&TargetVariablesType::call_RemoveTargetVariables_Method, this, boost::placeholders::_1));
    }
    
    TargetVariablesType::~TargetVariablesType(void)
    {
    }

    ServerVariable::SPtr&
    TargetVariablesType::dataSetMetaData_Variable(void)
    {
        return dataSetMetaData_Variable_;
    }

    ServerVariable::SPtr&
    TargetVariablesType::messageReceiveTimeout_Variable(void)
    {
        return messageReceiveTimeout_Variable_;
    }

    ServerVariable::SPtr&
    TargetVariablesType::targetVariables_Variable(void)
    {
        return targetVariables_Variable_;
    }

    void
    TargetVariablesType::dataSetMetaData_Variable(ServerVariable::SPtr& serverVariable)
    {
        dataSetMetaData_Variable_ = serverVariable;
    }

    void
    TargetVariablesType::messageReceiveTimeout_Variable(ServerVariable::SPtr& serverVariable)
    {
        messageReceiveTimeout_Variable_ = serverVariable;
    }

    void
    TargetVariablesType::targetVariables_Variable(ServerVariable::SPtr& serverVariable)
    {
        targetVariables_Variable_ = serverVariable;
    }

    bool
    TargetVariablesType::get_DataSetMetaData_Variable(OpcUaDataValue& dataValue)
    {
        return dataSetMetaData_Variable_->getDataValue(dataValue);
    }

    bool
    TargetVariablesType::get_MessageReceiveTimeout_Variable(OpcUaDataValue& dataValue)
    {
        return messageReceiveTimeout_Variable_->getDataValue(dataValue);
    }

    bool
    TargetVariablesType::get_TargetVariables_Variable(OpcUaDataValue& dataValue)
    {
        return targetVariables_Variable_->getDataValue(dataValue);
    }

    bool
    TargetVariablesType::set_DataSetMetaData_Variable(const OpcUaDataValue& dataValue)
    {
        return dataSetMetaData_Variable_->setDataValue(dataValue);
    }

    bool
    TargetVariablesType::set_MessageReceiveTimeout_Variable(const OpcUaDataValue& dataValue)
    {
        return messageReceiveTimeout_Variable_->setDataValue(dataValue);
    }

    bool
    TargetVariablesType::set_TargetVariables_Variable(const OpcUaDataValue& dataValue)
    {
        return targetVariables_Variable_->setDataValue(dataValue);
    }

    void
    TargetVariablesType::call_AddTargetVariables_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    TargetVariablesType::call_RemoveTargetVariables_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

}
