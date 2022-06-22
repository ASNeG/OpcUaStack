/*
    VariableTypeClass: PublishedDataItemsType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/PublishedDataItemsType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    PublishedDataItemsType::PublishedDataItemsType(void)
    : ObjectBase()
    , configurationVersion_Variable_(boost::make_shared<ServerVariable>("ConfigurationVersion_Variable"))
    , dataSetClassId_Variable_(boost::make_shared<ServerVariable>("DataSetClassId_Variable"))
    , dataSetMetaData_Variable_(boost::make_shared<ServerVariable>("DataSetMetaData_Variable"))
    , publishedData_Variable_(boost::make_shared<ServerVariable>("PublishedData_Variable"))
    , addVariables_Method_(boost::make_shared<ServerMethod>("AddVariables_Method"))
    , extensionFields_AddExtensionField_Method_(boost::make_shared<ServerMethod>("ExtensionFields_AddExtensionField_Method"))
    , extensionFields_RemoveExtensionField_Method_(boost::make_shared<ServerMethod>("ExtensionFields_RemoveExtensionField_Method"))
    , removeVariables_Method_(boost::make_shared<ServerMethod>("RemoveVariables_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)14534);
        setServerVariable(configurationVersion_Variable_);
        setServerVariable(dataSetClassId_Variable_);
        setServerVariable(dataSetMetaData_Variable_);
        setServerVariable(publishedData_Variable_);
        setServerMethod(addVariables_Method_);
        setServerMethod(extensionFields_AddExtensionField_Method_);
        setServerMethod(extensionFields_RemoveExtensionField_Method_);
        setServerMethod(removeVariables_Method_);
        addVariables_Method_->registerMethod(boost::bind(&PublishedDataItemsType::call_AddVariables_Method, this, _1));
        extensionFields_AddExtensionField_Method_->registerMethod(boost::bind(&PublishedDataItemsType::call_ExtensionFields_AddExtensionField_Method, this, _1));
        extensionFields_RemoveExtensionField_Method_->registerMethod(boost::bind(&PublishedDataItemsType::call_ExtensionFields_RemoveExtensionField_Method, this, _1));
        removeVariables_Method_->registerMethod(boost::bind(&PublishedDataItemsType::call_RemoveVariables_Method, this, _1));
    }
    
    PublishedDataItemsType::PublishedDataItemsType(const PublishedDataItemsType& value)
    : ObjectBase()
    , configurationVersion_Variable_(boost::make_shared<ServerVariable>("ConfigurationVersion_Variable"))
    , dataSetClassId_Variable_(boost::make_shared<ServerVariable>("DataSetClassId_Variable"))
    , dataSetMetaData_Variable_(boost::make_shared<ServerVariable>("DataSetMetaData_Variable"))
    , publishedData_Variable_(boost::make_shared<ServerVariable>("PublishedData_Variable"))
    , addVariables_Method_(boost::make_shared<ServerMethod>("AddVariables_Method"))
    , extensionFields_AddExtensionField_Method_(boost::make_shared<ServerMethod>("ExtensionFields_AddExtensionField_Method"))
    , extensionFields_RemoveExtensionField_Method_(boost::make_shared<ServerMethod>("ExtensionFields_RemoveExtensionField_Method"))
    , removeVariables_Method_(boost::make_shared<ServerMethod>("RemoveVariables_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)14534);
        setServerVariable(configurationVersion_Variable_);
        setServerVariable(dataSetClassId_Variable_);
        setServerVariable(dataSetMetaData_Variable_);
        setServerVariable(publishedData_Variable_);
        setServerMethod(addVariables_Method_);
        setServerMethod(extensionFields_AddExtensionField_Method_);
        setServerMethod(extensionFields_RemoveExtensionField_Method_);
        setServerMethod(removeVariables_Method_);
        addVariables_Method_->registerMethod(boost::bind(&PublishedDataItemsType::call_AddVariables_Method, this, _1));
        extensionFields_AddExtensionField_Method_->registerMethod(boost::bind(&PublishedDataItemsType::call_ExtensionFields_AddExtensionField_Method, this, _1));
        extensionFields_RemoveExtensionField_Method_->registerMethod(boost::bind(&PublishedDataItemsType::call_ExtensionFields_RemoveExtensionField_Method, this, _1));
        removeVariables_Method_->registerMethod(boost::bind(&PublishedDataItemsType::call_RemoveVariables_Method, this, _1));
    }
    
    PublishedDataItemsType::~PublishedDataItemsType(void)
    {
    }

    ServerVariable::SPtr&
    PublishedDataItemsType::configurationVersion_Variable(void)
    {
        return configurationVersion_Variable_;
    }

    ServerVariable::SPtr&
    PublishedDataItemsType::dataSetClassId_Variable(void)
    {
        return dataSetClassId_Variable_;
    }

    ServerVariable::SPtr&
    PublishedDataItemsType::dataSetMetaData_Variable(void)
    {
        return dataSetMetaData_Variable_;
    }

    ServerVariable::SPtr&
    PublishedDataItemsType::publishedData_Variable(void)
    {
        return publishedData_Variable_;
    }

    void
    PublishedDataItemsType::configurationVersion_Variable(ServerVariable::SPtr& serverVariable)
    {
        configurationVersion_Variable_ = serverVariable;
    }

    void
    PublishedDataItemsType::dataSetClassId_Variable(ServerVariable::SPtr& serverVariable)
    {
        dataSetClassId_Variable_ = serverVariable;
    }

    void
    PublishedDataItemsType::dataSetMetaData_Variable(ServerVariable::SPtr& serverVariable)
    {
        dataSetMetaData_Variable_ = serverVariable;
    }

    void
    PublishedDataItemsType::publishedData_Variable(ServerVariable::SPtr& serverVariable)
    {
        publishedData_Variable_ = serverVariable;
    }

    bool
    PublishedDataItemsType::get_ConfigurationVersion_Variable(OpcUaDataValue& dataValue)
    {
        return configurationVersion_Variable_->getDataValue(dataValue);
    }

    bool
    PublishedDataItemsType::get_DataSetClassId_Variable(OpcUaDataValue& dataValue)
    {
        return dataSetClassId_Variable_->getDataValue(dataValue);
    }

    bool
    PublishedDataItemsType::get_DataSetMetaData_Variable(OpcUaDataValue& dataValue)
    {
        return dataSetMetaData_Variable_->getDataValue(dataValue);
    }

    bool
    PublishedDataItemsType::get_PublishedData_Variable(OpcUaDataValue& dataValue)
    {
        return publishedData_Variable_->getDataValue(dataValue);
    }

    bool
    PublishedDataItemsType::set_ConfigurationVersion_Variable(const OpcUaDataValue& dataValue)
    {
        return configurationVersion_Variable_->setDataValue(dataValue);
    }

    bool
    PublishedDataItemsType::set_DataSetClassId_Variable(const OpcUaDataValue& dataValue)
    {
        return dataSetClassId_Variable_->setDataValue(dataValue);
    }

    bool
    PublishedDataItemsType::set_DataSetMetaData_Variable(const OpcUaDataValue& dataValue)
    {
        return dataSetMetaData_Variable_->setDataValue(dataValue);
    }

    bool
    PublishedDataItemsType::set_PublishedData_Variable(const OpcUaDataValue& dataValue)
    {
        return publishedData_Variable_->setDataValue(dataValue);
    }

    void
    PublishedDataItemsType::call_AddVariables_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    PublishedDataItemsType::call_ExtensionFields_AddExtensionField_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    PublishedDataItemsType::call_ExtensionFields_RemoveExtensionField_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    PublishedDataItemsType::call_RemoveVariables_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

}
