/*
    VariableTypeClass: PublishedEventsType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/PublishedEventsType.h"

namespace OpcUaStackServer
{
    
    PublishedEventsType::PublishedEventsType(void)
    : ObjectBase()
    , configurationVersion_Variable_(boost::make_shared<ServerVariable>("ConfigurationVersion_Variable"))
    , dataSetClassId_Variable_(boost::make_shared<ServerVariable>("DataSetClassId_Variable"))
    , dataSetMetaData_Variable_(boost::make_shared<ServerVariable>("DataSetMetaData_Variable"))
    , eventNotifier_Variable_(boost::make_shared<ServerVariable>("EventNotifier_Variable"))
    , filter_Variable_(boost::make_shared<ServerVariable>("Filter_Variable"))
    , selectedFields_Variable_(boost::make_shared<ServerVariable>("SelectedFields_Variable"))
    , extensionFields_AddExtensionField_Method_(boost::make_shared<ServerMethod>("ExtensionFields_AddExtensionField_Method"))
    , extensionFields_RemoveExtensionField_Method_(boost::make_shared<ServerMethod>("ExtensionFields_RemoveExtensionField_Method"))
    , modifyFieldSelection_Method_(boost::make_shared<ServerMethod>("ModifyFieldSelection_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)14572);
        setServerVariable(configurationVersion_Variable_);
        setServerVariable(dataSetClassId_Variable_);
        setServerVariable(dataSetMetaData_Variable_);
        setServerVariable(eventNotifier_Variable_);
        setServerVariable(filter_Variable_);
        setServerVariable(selectedFields_Variable_);
        setServerMethod(extensionFields_AddExtensionField_Method_);
        setServerMethod(extensionFields_RemoveExtensionField_Method_);
        setServerMethod(modifyFieldSelection_Method_);
        extensionFields_AddExtensionField_Method_->registerMethod(boost::bind(&PublishedEventsType::call_ExtensionFields_AddExtensionField_Method, this, _1));
        extensionFields_RemoveExtensionField_Method_->registerMethod(boost::bind(&PublishedEventsType::call_ExtensionFields_RemoveExtensionField_Method, this, _1));
        modifyFieldSelection_Method_->registerMethod(boost::bind(&PublishedEventsType::call_ModifyFieldSelection_Method, this, _1));
    }
    
    PublishedEventsType::PublishedEventsType(const PublishedEventsType& value)
    : ObjectBase()
    , configurationVersion_Variable_(boost::make_shared<ServerVariable>("ConfigurationVersion_Variable"))
    , dataSetClassId_Variable_(boost::make_shared<ServerVariable>("DataSetClassId_Variable"))
    , dataSetMetaData_Variable_(boost::make_shared<ServerVariable>("DataSetMetaData_Variable"))
    , eventNotifier_Variable_(boost::make_shared<ServerVariable>("EventNotifier_Variable"))
    , filter_Variable_(boost::make_shared<ServerVariable>("Filter_Variable"))
    , selectedFields_Variable_(boost::make_shared<ServerVariable>("SelectedFields_Variable"))
    , extensionFields_AddExtensionField_Method_(boost::make_shared<ServerMethod>("ExtensionFields_AddExtensionField_Method"))
    , extensionFields_RemoveExtensionField_Method_(boost::make_shared<ServerMethod>("ExtensionFields_RemoveExtensionField_Method"))
    , modifyFieldSelection_Method_(boost::make_shared<ServerMethod>("ModifyFieldSelection_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)14572);
        setServerVariable(configurationVersion_Variable_);
        setServerVariable(dataSetClassId_Variable_);
        setServerVariable(dataSetMetaData_Variable_);
        setServerVariable(eventNotifier_Variable_);
        setServerVariable(filter_Variable_);
        setServerVariable(selectedFields_Variable_);
        setServerMethod(extensionFields_AddExtensionField_Method_);
        setServerMethod(extensionFields_RemoveExtensionField_Method_);
        setServerMethod(modifyFieldSelection_Method_);
        extensionFields_AddExtensionField_Method_->registerMethod(boost::bind(&PublishedEventsType::call_ExtensionFields_AddExtensionField_Method, this, _1));
        extensionFields_RemoveExtensionField_Method_->registerMethod(boost::bind(&PublishedEventsType::call_ExtensionFields_RemoveExtensionField_Method, this, _1));
        modifyFieldSelection_Method_->registerMethod(boost::bind(&PublishedEventsType::call_ModifyFieldSelection_Method, this, _1));
    }
    
    PublishedEventsType::~PublishedEventsType(void)
    {
    }

    ServerVariable::SPtr&
    PublishedEventsType::configurationVersion_Variable(void)
    {
        return configurationVersion_Variable_;
    }

    ServerVariable::SPtr&
    PublishedEventsType::dataSetClassId_Variable(void)
    {
        return dataSetClassId_Variable_;
    }

    ServerVariable::SPtr&
    PublishedEventsType::dataSetMetaData_Variable(void)
    {
        return dataSetMetaData_Variable_;
    }

    ServerVariable::SPtr&
    PublishedEventsType::eventNotifier_Variable(void)
    {
        return eventNotifier_Variable_;
    }

    ServerVariable::SPtr&
    PublishedEventsType::filter_Variable(void)
    {
        return filter_Variable_;
    }

    ServerVariable::SPtr&
    PublishedEventsType::selectedFields_Variable(void)
    {
        return selectedFields_Variable_;
    }

    void
    PublishedEventsType::configurationVersion_Variable(ServerVariable::SPtr& serverVariable)
    {
        configurationVersion_Variable_ = serverVariable;
    }

    void
    PublishedEventsType::dataSetClassId_Variable(ServerVariable::SPtr& serverVariable)
    {
        dataSetClassId_Variable_ = serverVariable;
    }

    void
    PublishedEventsType::dataSetMetaData_Variable(ServerVariable::SPtr& serverVariable)
    {
        dataSetMetaData_Variable_ = serverVariable;
    }

    void
    PublishedEventsType::eventNotifier_Variable(ServerVariable::SPtr& serverVariable)
    {
        eventNotifier_Variable_ = serverVariable;
    }

    void
    PublishedEventsType::filter_Variable(ServerVariable::SPtr& serverVariable)
    {
        filter_Variable_ = serverVariable;
    }

    void
    PublishedEventsType::selectedFields_Variable(ServerVariable::SPtr& serverVariable)
    {
        selectedFields_Variable_ = serverVariable;
    }

    bool
    PublishedEventsType::get_ConfigurationVersion_Variable(OpcUaDataValue& dataValue)
    {
        return configurationVersion_Variable_->getDataValue(dataValue);
    }

    bool
    PublishedEventsType::get_DataSetClassId_Variable(OpcUaDataValue& dataValue)
    {
        return dataSetClassId_Variable_->getDataValue(dataValue);
    }

    bool
    PublishedEventsType::get_DataSetMetaData_Variable(OpcUaDataValue& dataValue)
    {
        return dataSetMetaData_Variable_->getDataValue(dataValue);
    }

    bool
    PublishedEventsType::get_EventNotifier_Variable(OpcUaDataValue& dataValue)
    {
        return eventNotifier_Variable_->getDataValue(dataValue);
    }

    bool
    PublishedEventsType::get_Filter_Variable(OpcUaDataValue& dataValue)
    {
        return filter_Variable_->getDataValue(dataValue);
    }

    bool
    PublishedEventsType::get_SelectedFields_Variable(OpcUaDataValue& dataValue)
    {
        return selectedFields_Variable_->getDataValue(dataValue);
    }

    bool
    PublishedEventsType::set_ConfigurationVersion_Variable(const OpcUaDataValue& dataValue)
    {
        return configurationVersion_Variable_->setDataValue(dataValue);
    }

    bool
    PublishedEventsType::set_DataSetClassId_Variable(const OpcUaDataValue& dataValue)
    {
        return dataSetClassId_Variable_->setDataValue(dataValue);
    }

    bool
    PublishedEventsType::set_DataSetMetaData_Variable(const OpcUaDataValue& dataValue)
    {
        return dataSetMetaData_Variable_->setDataValue(dataValue);
    }

    bool
    PublishedEventsType::set_EventNotifier_Variable(const OpcUaDataValue& dataValue)
    {
        return eventNotifier_Variable_->setDataValue(dataValue);
    }

    bool
    PublishedEventsType::set_Filter_Variable(const OpcUaDataValue& dataValue)
    {
        return filter_Variable_->setDataValue(dataValue);
    }

    bool
    PublishedEventsType::set_SelectedFields_Variable(const OpcUaDataValue& dataValue)
    {
        return selectedFields_Variable_->setDataValue(dataValue);
    }

    void
    PublishedEventsType::call_ExtensionFields_AddExtensionField_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    PublishedEventsType::call_ExtensionFields_RemoveExtensionField_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    PublishedEventsType::call_ModifyFieldSelection_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

}
