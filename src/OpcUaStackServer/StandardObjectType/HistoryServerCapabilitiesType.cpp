/*
    VariableTypeClass: HistoryServerCapabilitiesType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/HistoryServerCapabilitiesType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    HistoryServerCapabilitiesType::HistoryServerCapabilitiesType(void)
    : ObjectBase()
    , accessHistoryDataCapability_Variable_(boost::make_shared<ServerVariable>("AccessHistoryDataCapability_Variable"))
    , accessHistoryEventsCapability_Variable_(boost::make_shared<ServerVariable>("AccessHistoryEventsCapability_Variable"))
    , deleteAtTimeCapability_Variable_(boost::make_shared<ServerVariable>("DeleteAtTimeCapability_Variable"))
    , deleteEventCapability_Variable_(boost::make_shared<ServerVariable>("DeleteEventCapability_Variable"))
    , deleteRawCapability_Variable_(boost::make_shared<ServerVariable>("DeleteRawCapability_Variable"))
    , insertAnnotationCapability_Variable_(boost::make_shared<ServerVariable>("InsertAnnotationCapability_Variable"))
    , insertDataCapability_Variable_(boost::make_shared<ServerVariable>("InsertDataCapability_Variable"))
    , insertEventCapability_Variable_(boost::make_shared<ServerVariable>("InsertEventCapability_Variable"))
    , maxReturnDataValues_Variable_(boost::make_shared<ServerVariable>("MaxReturnDataValues_Variable"))
    , maxReturnEventValues_Variable_(boost::make_shared<ServerVariable>("MaxReturnEventValues_Variable"))
    , replaceDataCapability_Variable_(boost::make_shared<ServerVariable>("ReplaceDataCapability_Variable"))
    , replaceEventCapability_Variable_(boost::make_shared<ServerVariable>("ReplaceEventCapability_Variable"))
    , updateDataCapability_Variable_(boost::make_shared<ServerVariable>("UpdateDataCapability_Variable"))
    , updateEventCapability_Variable_(boost::make_shared<ServerVariable>("UpdateEventCapability_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2330);
        setServerVariable(accessHistoryDataCapability_Variable_);
        setServerVariable(accessHistoryEventsCapability_Variable_);
        setServerVariable(deleteAtTimeCapability_Variable_);
        setServerVariable(deleteEventCapability_Variable_);
        setServerVariable(deleteRawCapability_Variable_);
        setServerVariable(insertAnnotationCapability_Variable_);
        setServerVariable(insertDataCapability_Variable_);
        setServerVariable(insertEventCapability_Variable_);
        setServerVariable(maxReturnDataValues_Variable_);
        setServerVariable(maxReturnEventValues_Variable_);
        setServerVariable(replaceDataCapability_Variable_);
        setServerVariable(replaceEventCapability_Variable_);
        setServerVariable(updateDataCapability_Variable_);
        setServerVariable(updateEventCapability_Variable_);
    }
    
    HistoryServerCapabilitiesType::HistoryServerCapabilitiesType(const HistoryServerCapabilitiesType& value)
    : ObjectBase()
    , accessHistoryDataCapability_Variable_(boost::make_shared<ServerVariable>("AccessHistoryDataCapability_Variable"))
    , accessHistoryEventsCapability_Variable_(boost::make_shared<ServerVariable>("AccessHistoryEventsCapability_Variable"))
    , deleteAtTimeCapability_Variable_(boost::make_shared<ServerVariable>("DeleteAtTimeCapability_Variable"))
    , deleteEventCapability_Variable_(boost::make_shared<ServerVariable>("DeleteEventCapability_Variable"))
    , deleteRawCapability_Variable_(boost::make_shared<ServerVariable>("DeleteRawCapability_Variable"))
    , insertAnnotationCapability_Variable_(boost::make_shared<ServerVariable>("InsertAnnotationCapability_Variable"))
    , insertDataCapability_Variable_(boost::make_shared<ServerVariable>("InsertDataCapability_Variable"))
    , insertEventCapability_Variable_(boost::make_shared<ServerVariable>("InsertEventCapability_Variable"))
    , maxReturnDataValues_Variable_(boost::make_shared<ServerVariable>("MaxReturnDataValues_Variable"))
    , maxReturnEventValues_Variable_(boost::make_shared<ServerVariable>("MaxReturnEventValues_Variable"))
    , replaceDataCapability_Variable_(boost::make_shared<ServerVariable>("ReplaceDataCapability_Variable"))
    , replaceEventCapability_Variable_(boost::make_shared<ServerVariable>("ReplaceEventCapability_Variable"))
    , updateDataCapability_Variable_(boost::make_shared<ServerVariable>("UpdateDataCapability_Variable"))
    , updateEventCapability_Variable_(boost::make_shared<ServerVariable>("UpdateEventCapability_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2330);
        setServerVariable(accessHistoryDataCapability_Variable_);
        setServerVariable(accessHistoryEventsCapability_Variable_);
        setServerVariable(deleteAtTimeCapability_Variable_);
        setServerVariable(deleteEventCapability_Variable_);
        setServerVariable(deleteRawCapability_Variable_);
        setServerVariable(insertAnnotationCapability_Variable_);
        setServerVariable(insertDataCapability_Variable_);
        setServerVariable(insertEventCapability_Variable_);
        setServerVariable(maxReturnDataValues_Variable_);
        setServerVariable(maxReturnEventValues_Variable_);
        setServerVariable(replaceDataCapability_Variable_);
        setServerVariable(replaceEventCapability_Variable_);
        setServerVariable(updateDataCapability_Variable_);
        setServerVariable(updateEventCapability_Variable_);
    }
    
    HistoryServerCapabilitiesType::~HistoryServerCapabilitiesType(void)
    {
    }

    ServerVariable::SPtr&
    HistoryServerCapabilitiesType::accessHistoryDataCapability_Variable(void)
    {
        return accessHistoryDataCapability_Variable_;
    }

    ServerVariable::SPtr&
    HistoryServerCapabilitiesType::accessHistoryEventsCapability_Variable(void)
    {
        return accessHistoryEventsCapability_Variable_;
    }

    ServerVariable::SPtr&
    HistoryServerCapabilitiesType::deleteAtTimeCapability_Variable(void)
    {
        return deleteAtTimeCapability_Variable_;
    }

    ServerVariable::SPtr&
    HistoryServerCapabilitiesType::deleteEventCapability_Variable(void)
    {
        return deleteEventCapability_Variable_;
    }

    ServerVariable::SPtr&
    HistoryServerCapabilitiesType::deleteRawCapability_Variable(void)
    {
        return deleteRawCapability_Variable_;
    }

    ServerVariable::SPtr&
    HistoryServerCapabilitiesType::insertAnnotationCapability_Variable(void)
    {
        return insertAnnotationCapability_Variable_;
    }

    ServerVariable::SPtr&
    HistoryServerCapabilitiesType::insertDataCapability_Variable(void)
    {
        return insertDataCapability_Variable_;
    }

    ServerVariable::SPtr&
    HistoryServerCapabilitiesType::insertEventCapability_Variable(void)
    {
        return insertEventCapability_Variable_;
    }

    ServerVariable::SPtr&
    HistoryServerCapabilitiesType::maxReturnDataValues_Variable(void)
    {
        return maxReturnDataValues_Variable_;
    }

    ServerVariable::SPtr&
    HistoryServerCapabilitiesType::maxReturnEventValues_Variable(void)
    {
        return maxReturnEventValues_Variable_;
    }

    ServerVariable::SPtr&
    HistoryServerCapabilitiesType::replaceDataCapability_Variable(void)
    {
        return replaceDataCapability_Variable_;
    }

    ServerVariable::SPtr&
    HistoryServerCapabilitiesType::replaceEventCapability_Variable(void)
    {
        return replaceEventCapability_Variable_;
    }

    ServerVariable::SPtr&
    HistoryServerCapabilitiesType::updateDataCapability_Variable(void)
    {
        return updateDataCapability_Variable_;
    }

    ServerVariable::SPtr&
    HistoryServerCapabilitiesType::updateEventCapability_Variable(void)
    {
        return updateEventCapability_Variable_;
    }

    void
    HistoryServerCapabilitiesType::accessHistoryDataCapability_Variable(ServerVariable::SPtr& serverVariable)
    {
        accessHistoryDataCapability_Variable_ = serverVariable;
    }

    void
    HistoryServerCapabilitiesType::accessHistoryEventsCapability_Variable(ServerVariable::SPtr& serverVariable)
    {
        accessHistoryEventsCapability_Variable_ = serverVariable;
    }

    void
    HistoryServerCapabilitiesType::deleteAtTimeCapability_Variable(ServerVariable::SPtr& serverVariable)
    {
        deleteAtTimeCapability_Variable_ = serverVariable;
    }

    void
    HistoryServerCapabilitiesType::deleteEventCapability_Variable(ServerVariable::SPtr& serverVariable)
    {
        deleteEventCapability_Variable_ = serverVariable;
    }

    void
    HistoryServerCapabilitiesType::deleteRawCapability_Variable(ServerVariable::SPtr& serverVariable)
    {
        deleteRawCapability_Variable_ = serverVariable;
    }

    void
    HistoryServerCapabilitiesType::insertAnnotationCapability_Variable(ServerVariable::SPtr& serverVariable)
    {
        insertAnnotationCapability_Variable_ = serverVariable;
    }

    void
    HistoryServerCapabilitiesType::insertDataCapability_Variable(ServerVariable::SPtr& serverVariable)
    {
        insertDataCapability_Variable_ = serverVariable;
    }

    void
    HistoryServerCapabilitiesType::insertEventCapability_Variable(ServerVariable::SPtr& serverVariable)
    {
        insertEventCapability_Variable_ = serverVariable;
    }

    void
    HistoryServerCapabilitiesType::maxReturnDataValues_Variable(ServerVariable::SPtr& serverVariable)
    {
        maxReturnDataValues_Variable_ = serverVariable;
    }

    void
    HistoryServerCapabilitiesType::maxReturnEventValues_Variable(ServerVariable::SPtr& serverVariable)
    {
        maxReturnEventValues_Variable_ = serverVariable;
    }

    void
    HistoryServerCapabilitiesType::replaceDataCapability_Variable(ServerVariable::SPtr& serverVariable)
    {
        replaceDataCapability_Variable_ = serverVariable;
    }

    void
    HistoryServerCapabilitiesType::replaceEventCapability_Variable(ServerVariable::SPtr& serverVariable)
    {
        replaceEventCapability_Variable_ = serverVariable;
    }

    void
    HistoryServerCapabilitiesType::updateDataCapability_Variable(ServerVariable::SPtr& serverVariable)
    {
        updateDataCapability_Variable_ = serverVariable;
    }

    void
    HistoryServerCapabilitiesType::updateEventCapability_Variable(ServerVariable::SPtr& serverVariable)
    {
        updateEventCapability_Variable_ = serverVariable;
    }

    bool
    HistoryServerCapabilitiesType::get_AccessHistoryDataCapability_Variable(OpcUaDataValue& dataValue)
    {
        return accessHistoryDataCapability_Variable_->getDataValue(dataValue);
    }

    bool
    HistoryServerCapabilitiesType::get_AccessHistoryEventsCapability_Variable(OpcUaDataValue& dataValue)
    {
        return accessHistoryEventsCapability_Variable_->getDataValue(dataValue);
    }

    bool
    HistoryServerCapabilitiesType::get_DeleteAtTimeCapability_Variable(OpcUaDataValue& dataValue)
    {
        return deleteAtTimeCapability_Variable_->getDataValue(dataValue);
    }

    bool
    HistoryServerCapabilitiesType::get_DeleteEventCapability_Variable(OpcUaDataValue& dataValue)
    {
        return deleteEventCapability_Variable_->getDataValue(dataValue);
    }

    bool
    HistoryServerCapabilitiesType::get_DeleteRawCapability_Variable(OpcUaDataValue& dataValue)
    {
        return deleteRawCapability_Variable_->getDataValue(dataValue);
    }

    bool
    HistoryServerCapabilitiesType::get_InsertAnnotationCapability_Variable(OpcUaDataValue& dataValue)
    {
        return insertAnnotationCapability_Variable_->getDataValue(dataValue);
    }

    bool
    HistoryServerCapabilitiesType::get_InsertDataCapability_Variable(OpcUaDataValue& dataValue)
    {
        return insertDataCapability_Variable_->getDataValue(dataValue);
    }

    bool
    HistoryServerCapabilitiesType::get_InsertEventCapability_Variable(OpcUaDataValue& dataValue)
    {
        return insertEventCapability_Variable_->getDataValue(dataValue);
    }

    bool
    HistoryServerCapabilitiesType::get_MaxReturnDataValues_Variable(OpcUaDataValue& dataValue)
    {
        return maxReturnDataValues_Variable_->getDataValue(dataValue);
    }

    bool
    HistoryServerCapabilitiesType::get_MaxReturnEventValues_Variable(OpcUaDataValue& dataValue)
    {
        return maxReturnEventValues_Variable_->getDataValue(dataValue);
    }

    bool
    HistoryServerCapabilitiesType::get_ReplaceDataCapability_Variable(OpcUaDataValue& dataValue)
    {
        return replaceDataCapability_Variable_->getDataValue(dataValue);
    }

    bool
    HistoryServerCapabilitiesType::get_ReplaceEventCapability_Variable(OpcUaDataValue& dataValue)
    {
        return replaceEventCapability_Variable_->getDataValue(dataValue);
    }

    bool
    HistoryServerCapabilitiesType::get_UpdateDataCapability_Variable(OpcUaDataValue& dataValue)
    {
        return updateDataCapability_Variable_->getDataValue(dataValue);
    }

    bool
    HistoryServerCapabilitiesType::get_UpdateEventCapability_Variable(OpcUaDataValue& dataValue)
    {
        return updateEventCapability_Variable_->getDataValue(dataValue);
    }

    bool
    HistoryServerCapabilitiesType::set_AccessHistoryDataCapability_Variable(const OpcUaDataValue& dataValue)
    {
        return accessHistoryDataCapability_Variable_->setDataValue(dataValue);
    }

    bool
    HistoryServerCapabilitiesType::set_AccessHistoryEventsCapability_Variable(const OpcUaDataValue& dataValue)
    {
        return accessHistoryEventsCapability_Variable_->setDataValue(dataValue);
    }

    bool
    HistoryServerCapabilitiesType::set_DeleteAtTimeCapability_Variable(const OpcUaDataValue& dataValue)
    {
        return deleteAtTimeCapability_Variable_->setDataValue(dataValue);
    }

    bool
    HistoryServerCapabilitiesType::set_DeleteEventCapability_Variable(const OpcUaDataValue& dataValue)
    {
        return deleteEventCapability_Variable_->setDataValue(dataValue);
    }

    bool
    HistoryServerCapabilitiesType::set_DeleteRawCapability_Variable(const OpcUaDataValue& dataValue)
    {
        return deleteRawCapability_Variable_->setDataValue(dataValue);
    }

    bool
    HistoryServerCapabilitiesType::set_InsertAnnotationCapability_Variable(const OpcUaDataValue& dataValue)
    {
        return insertAnnotationCapability_Variable_->setDataValue(dataValue);
    }

    bool
    HistoryServerCapabilitiesType::set_InsertDataCapability_Variable(const OpcUaDataValue& dataValue)
    {
        return insertDataCapability_Variable_->setDataValue(dataValue);
    }

    bool
    HistoryServerCapabilitiesType::set_InsertEventCapability_Variable(const OpcUaDataValue& dataValue)
    {
        return insertEventCapability_Variable_->setDataValue(dataValue);
    }

    bool
    HistoryServerCapabilitiesType::set_MaxReturnDataValues_Variable(const OpcUaDataValue& dataValue)
    {
        return maxReturnDataValues_Variable_->setDataValue(dataValue);
    }

    bool
    HistoryServerCapabilitiesType::set_MaxReturnEventValues_Variable(const OpcUaDataValue& dataValue)
    {
        return maxReturnEventValues_Variable_->setDataValue(dataValue);
    }

    bool
    HistoryServerCapabilitiesType::set_ReplaceDataCapability_Variable(const OpcUaDataValue& dataValue)
    {
        return replaceDataCapability_Variable_->setDataValue(dataValue);
    }

    bool
    HistoryServerCapabilitiesType::set_ReplaceEventCapability_Variable(const OpcUaDataValue& dataValue)
    {
        return replaceEventCapability_Variable_->setDataValue(dataValue);
    }

    bool
    HistoryServerCapabilitiesType::set_UpdateDataCapability_Variable(const OpcUaDataValue& dataValue)
    {
        return updateDataCapability_Variable_->setDataValue(dataValue);
    }

    bool
    HistoryServerCapabilitiesType::set_UpdateEventCapability_Variable(const OpcUaDataValue& dataValue)
    {
        return updateEventCapability_Variable_->setDataValue(dataValue);
    }

}
