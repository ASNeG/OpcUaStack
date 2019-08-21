/*
    VariableTypeClass: PublishedDataSetType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/PublishedDataSetType.h"

namespace OpcUaStackServer
{
    
    PublishedDataSetType::PublishedDataSetType(void)
    : ObjectBase()
    , configurationVersion_Variable_(boost::make_shared<ServerVariable>("ConfigurationVersion_Variable"))
    , dataSetClassId_Variable_(boost::make_shared<ServerVariable>("DataSetClassId_Variable"))
    , dataSetMetaData_Variable_(boost::make_shared<ServerVariable>("DataSetMetaData_Variable"))
    , extensionFields_AddExtensionField_Method_(boost::make_shared<ServerMethod>("ExtensionFields_AddExtensionField_Method"))
    , extensionFields_RemoveExtensionField_Method_(boost::make_shared<ServerMethod>("ExtensionFields_RemoveExtensionField_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)14509);
        setServerVariable(configurationVersion_Variable_);
        setServerVariable(dataSetClassId_Variable_);
        setServerVariable(dataSetMetaData_Variable_);
        setServerMethod(extensionFields_AddExtensionField_Method_);
        setServerMethod(extensionFields_RemoveExtensionField_Method_);
        extensionFields_AddExtensionField_Method_->registerMethod(boost::bind(&PublishedDataSetType::call_ExtensionFields_AddExtensionField_Method, this, _1));
        extensionFields_RemoveExtensionField_Method_->registerMethod(boost::bind(&PublishedDataSetType::call_ExtensionFields_RemoveExtensionField_Method, this, _1));
    }
    
    PublishedDataSetType::PublishedDataSetType(const PublishedDataSetType& value)
    : ObjectBase()
    , configurationVersion_Variable_(boost::make_shared<ServerVariable>("ConfigurationVersion_Variable"))
    , dataSetClassId_Variable_(boost::make_shared<ServerVariable>("DataSetClassId_Variable"))
    , dataSetMetaData_Variable_(boost::make_shared<ServerVariable>("DataSetMetaData_Variable"))
    , extensionFields_AddExtensionField_Method_(boost::make_shared<ServerMethod>("ExtensionFields_AddExtensionField_Method"))
    , extensionFields_RemoveExtensionField_Method_(boost::make_shared<ServerMethod>("ExtensionFields_RemoveExtensionField_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)14509);
        setServerVariable(configurationVersion_Variable_);
        setServerVariable(dataSetClassId_Variable_);
        setServerVariable(dataSetMetaData_Variable_);
        setServerMethod(extensionFields_AddExtensionField_Method_);
        setServerMethod(extensionFields_RemoveExtensionField_Method_);
        extensionFields_AddExtensionField_Method_->registerMethod(boost::bind(&PublishedDataSetType::call_ExtensionFields_AddExtensionField_Method, this, _1));
        extensionFields_RemoveExtensionField_Method_->registerMethod(boost::bind(&PublishedDataSetType::call_ExtensionFields_RemoveExtensionField_Method, this, _1));
    }
    
    PublishedDataSetType::~PublishedDataSetType(void)
    {
    }

    ServerVariable::SPtr&
    PublishedDataSetType::configurationVersion_Variable(void)
    {
        return configurationVersion_Variable_;
    }

    ServerVariable::SPtr&
    PublishedDataSetType::dataSetClassId_Variable(void)
    {
        return dataSetClassId_Variable_;
    }

    ServerVariable::SPtr&
    PublishedDataSetType::dataSetMetaData_Variable(void)
    {
        return dataSetMetaData_Variable_;
    }

    void
    PublishedDataSetType::configurationVersion_Variable(ServerVariable::SPtr& serverVariable)
    {
        configurationVersion_Variable_ = serverVariable;
    }

    void
    PublishedDataSetType::dataSetClassId_Variable(ServerVariable::SPtr& serverVariable)
    {
        dataSetClassId_Variable_ = serverVariable;
    }

    void
    PublishedDataSetType::dataSetMetaData_Variable(ServerVariable::SPtr& serverVariable)
    {
        dataSetMetaData_Variable_ = serverVariable;
    }

    bool
    PublishedDataSetType::get_ConfigurationVersion_Variable(OpcUaDataValue& dataValue)
    {
        return configurationVersion_Variable_->getDataValue(dataValue);
    }

    bool
    PublishedDataSetType::get_DataSetClassId_Variable(OpcUaDataValue& dataValue)
    {
        return dataSetClassId_Variable_->getDataValue(dataValue);
    }

    bool
    PublishedDataSetType::get_DataSetMetaData_Variable(OpcUaDataValue& dataValue)
    {
        return dataSetMetaData_Variable_->getDataValue(dataValue);
    }

    bool
    PublishedDataSetType::set_ConfigurationVersion_Variable(const OpcUaDataValue& dataValue)
    {
        return configurationVersion_Variable_->setDataValue(dataValue);
    }

    bool
    PublishedDataSetType::set_DataSetClassId_Variable(const OpcUaDataValue& dataValue)
    {
        return dataSetClassId_Variable_->setDataValue(dataValue);
    }

    bool
    PublishedDataSetType::set_DataSetMetaData_Variable(const OpcUaDataValue& dataValue)
    {
        return dataSetMetaData_Variable_->setDataValue(dataValue);
    }

    void
    PublishedDataSetType::call_ExtensionFields_AddExtensionField_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    PublishedDataSetType::call_ExtensionFields_RemoveExtensionField_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

}
