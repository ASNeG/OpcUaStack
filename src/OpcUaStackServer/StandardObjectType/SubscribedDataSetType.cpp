/*
    VariableTypeClass: SubscribedDataSetType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/SubscribedDataSetType.h"

namespace OpcUaStackServer
{
    
    SubscribedDataSetType::SubscribedDataSetType(void)
    : ObjectBase()
    , dataSetMetaData_Variable_(boost::make_shared<ServerVariable>("DataSetMetaData_Variable"))
    , messageReceiveTimeout_Variable_(boost::make_shared<ServerVariable>("MessageReceiveTimeout_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)15108);
        setServerVariable(dataSetMetaData_Variable_);
        setServerVariable(messageReceiveTimeout_Variable_);
    }
    
    SubscribedDataSetType::SubscribedDataSetType(const SubscribedDataSetType& value)
    : ObjectBase()
    , dataSetMetaData_Variable_(boost::make_shared<ServerVariable>("DataSetMetaData_Variable"))
    , messageReceiveTimeout_Variable_(boost::make_shared<ServerVariable>("MessageReceiveTimeout_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)15108);
        setServerVariable(dataSetMetaData_Variable_);
        setServerVariable(messageReceiveTimeout_Variable_);
    }
    
    SubscribedDataSetType::~SubscribedDataSetType(void)
    {
    }

    ServerVariable::SPtr&
    SubscribedDataSetType::dataSetMetaData_Variable(void)
    {
        return dataSetMetaData_Variable_;
    }

    ServerVariable::SPtr&
    SubscribedDataSetType::messageReceiveTimeout_Variable(void)
    {
        return messageReceiveTimeout_Variable_;
    }

    void
    SubscribedDataSetType::dataSetMetaData_Variable(ServerVariable::SPtr& serverVariable)
    {
        dataSetMetaData_Variable_ = serverVariable;
    }

    void
    SubscribedDataSetType::messageReceiveTimeout_Variable(ServerVariable::SPtr& serverVariable)
    {
        messageReceiveTimeout_Variable_ = serverVariable;
    }

    bool
    SubscribedDataSetType::get_DataSetMetaData_Variable(OpcUaDataValue& dataValue)
    {
        return dataSetMetaData_Variable_->getDataValue(dataValue);
    }

    bool
    SubscribedDataSetType::get_MessageReceiveTimeout_Variable(OpcUaDataValue& dataValue)
    {
        return messageReceiveTimeout_Variable_->getDataValue(dataValue);
    }

    bool
    SubscribedDataSetType::set_DataSetMetaData_Variable(const OpcUaDataValue& dataValue)
    {
        return dataSetMetaData_Variable_->setDataValue(dataValue);
    }

    bool
    SubscribedDataSetType::set_MessageReceiveTimeout_Variable(const OpcUaDataValue& dataValue)
    {
        return messageReceiveTimeout_Variable_->setDataValue(dataValue);
    }

}
