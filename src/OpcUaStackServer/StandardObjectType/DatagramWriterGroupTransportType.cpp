/*
    VariableTypeClass: DatagramWriterGroupTransportType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/DatagramWriterGroupTransportType.h"

namespace OpcUaStackServer
{
    
    DatagramWriterGroupTransportType::DatagramWriterGroupTransportType(void)
    : ObjectBase()
    , messageRepeatCount_Variable_(boost::make_shared<ServerVariable>("MessageRepeatCount_Variable"))
    , messageRepeatDelay_Variable_(boost::make_shared<ServerVariable>("MessageRepeatDelay_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)21133);
        setServerVariable(messageRepeatCount_Variable_);
        setServerVariable(messageRepeatDelay_Variable_);
    }
    
    DatagramWriterGroupTransportType::DatagramWriterGroupTransportType(const DatagramWriterGroupTransportType& value)
    : ObjectBase()
    , messageRepeatCount_Variable_(boost::make_shared<ServerVariable>("MessageRepeatCount_Variable"))
    , messageRepeatDelay_Variable_(boost::make_shared<ServerVariable>("MessageRepeatDelay_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)21133);
        setServerVariable(messageRepeatCount_Variable_);
        setServerVariable(messageRepeatDelay_Variable_);
    }
    
    DatagramWriterGroupTransportType::~DatagramWriterGroupTransportType(void)
    {
    }

    ServerVariable::SPtr&
    DatagramWriterGroupTransportType::messageRepeatCount_Variable(void)
    {
        return messageRepeatCount_Variable_;
    }

    ServerVariable::SPtr&
    DatagramWriterGroupTransportType::messageRepeatDelay_Variable(void)
    {
        return messageRepeatDelay_Variable_;
    }

    void
    DatagramWriterGroupTransportType::messageRepeatCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        messageRepeatCount_Variable_ = serverVariable;
    }

    void
    DatagramWriterGroupTransportType::messageRepeatDelay_Variable(ServerVariable::SPtr& serverVariable)
    {
        messageRepeatDelay_Variable_ = serverVariable;
    }

    bool
    DatagramWriterGroupTransportType::get_MessageRepeatCount_Variable(OpcUaDataValue& dataValue)
    {
        return messageRepeatCount_Variable_->getDataValue(dataValue);
    }

    bool
    DatagramWriterGroupTransportType::get_MessageRepeatDelay_Variable(OpcUaDataValue& dataValue)
    {
        return messageRepeatDelay_Variable_->getDataValue(dataValue);
    }

    bool
    DatagramWriterGroupTransportType::set_MessageRepeatCount_Variable(const OpcUaDataValue& dataValue)
    {
        return messageRepeatCount_Variable_->setDataValue(dataValue);
    }

    bool
    DatagramWriterGroupTransportType::set_MessageRepeatDelay_Variable(const OpcUaDataValue& dataValue)
    {
        return messageRepeatDelay_Variable_->setDataValue(dataValue);
    }

}
