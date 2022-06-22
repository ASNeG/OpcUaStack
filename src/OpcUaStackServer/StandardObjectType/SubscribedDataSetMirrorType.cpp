/*
    VariableTypeClass: SubscribedDataSetMirrorType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/SubscribedDataSetMirrorType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    SubscribedDataSetMirrorType::SubscribedDataSetMirrorType(void)
    : ObjectBase()
    , dataSetMetaData_Variable_(boost::make_shared<ServerVariable>("DataSetMetaData_Variable"))
    , messageReceiveTimeout_Variable_(boost::make_shared<ServerVariable>("MessageReceiveTimeout_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)15127);
        setServerVariable(dataSetMetaData_Variable_);
        setServerVariable(messageReceiveTimeout_Variable_);
    }
    
    SubscribedDataSetMirrorType::SubscribedDataSetMirrorType(const SubscribedDataSetMirrorType& value)
    : ObjectBase()
    , dataSetMetaData_Variable_(boost::make_shared<ServerVariable>("DataSetMetaData_Variable"))
    , messageReceiveTimeout_Variable_(boost::make_shared<ServerVariable>("MessageReceiveTimeout_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)15127);
        setServerVariable(dataSetMetaData_Variable_);
        setServerVariable(messageReceiveTimeout_Variable_);
    }
    
    SubscribedDataSetMirrorType::~SubscribedDataSetMirrorType(void)
    {
    }

    ServerVariable::SPtr&
    SubscribedDataSetMirrorType::dataSetMetaData_Variable(void)
    {
        return dataSetMetaData_Variable_;
    }

    ServerVariable::SPtr&
    SubscribedDataSetMirrorType::messageReceiveTimeout_Variable(void)
    {
        return messageReceiveTimeout_Variable_;
    }

    void
    SubscribedDataSetMirrorType::dataSetMetaData_Variable(ServerVariable::SPtr& serverVariable)
    {
        dataSetMetaData_Variable_ = serverVariable;
    }

    void
    SubscribedDataSetMirrorType::messageReceiveTimeout_Variable(ServerVariable::SPtr& serverVariable)
    {
        messageReceiveTimeout_Variable_ = serverVariable;
    }

    bool
    SubscribedDataSetMirrorType::get_DataSetMetaData_Variable(OpcUaDataValue& dataValue)
    {
        return dataSetMetaData_Variable_->getDataValue(dataValue);
    }

    bool
    SubscribedDataSetMirrorType::get_MessageReceiveTimeout_Variable(OpcUaDataValue& dataValue)
    {
        return messageReceiveTimeout_Variable_->getDataValue(dataValue);
    }

    bool
    SubscribedDataSetMirrorType::set_DataSetMetaData_Variable(const OpcUaDataValue& dataValue)
    {
        return dataSetMetaData_Variable_->setDataValue(dataValue);
    }

    bool
    SubscribedDataSetMirrorType::set_MessageReceiveTimeout_Variable(const OpcUaDataValue& dataValue)
    {
        return messageReceiveTimeout_Variable_->setDataValue(dataValue);
    }

}
