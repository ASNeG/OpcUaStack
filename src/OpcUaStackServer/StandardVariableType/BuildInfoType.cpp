/*
    VariableTypeClass: BuildInfoType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/BuildInfoType.h"

namespace OpcUaStackServer
{
    
    BuildInfoType::BuildInfoType(void)
    : VariableBase()
    , buildDate_Variable_(constructSPtr<ServerVariable>("BuildDate_Variable"))
    , buildNumber_Variable_(constructSPtr<ServerVariable>("BuildNumber_Variable"))
    , manufacturerName_Variable_(constructSPtr<ServerVariable>("ManufacturerName_Variable"))
    , productName_Variable_(constructSPtr<ServerVariable>("ProductName_Variable"))
    , productUri_Variable_(constructSPtr<ServerVariable>("ProductUri_Variable"))
    , softwareVersion_Variable_(constructSPtr<ServerVariable>("SoftwareVersion_Variable"))
    , variable_(constructSPtr<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)3051);
        setServerVariable(buildDate_Variable_);
        setServerVariable(buildNumber_Variable_);
        setServerVariable(manufacturerName_Variable_);
        setServerVariable(productName_Variable_);
        setServerVariable(productUri_Variable_);
        setServerVariable(softwareVersion_Variable_);
        setServerVariable(variable_);
    }
    
    BuildInfoType::BuildInfoType(const BuildInfoType& value)
    : VariableBase()
    , buildDate_Variable_(constructSPtr<ServerVariable>("BuildDate_Variable"))
    , buildNumber_Variable_(constructSPtr<ServerVariable>("BuildNumber_Variable"))
    , manufacturerName_Variable_(constructSPtr<ServerVariable>("ManufacturerName_Variable"))
    , productName_Variable_(constructSPtr<ServerVariable>("ProductName_Variable"))
    , productUri_Variable_(constructSPtr<ServerVariable>("ProductUri_Variable"))
    , softwareVersion_Variable_(constructSPtr<ServerVariable>("SoftwareVersion_Variable"))
    , variable_(constructSPtr<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)3051);
        setServerVariable(buildDate_Variable_);
        setServerVariable(buildNumber_Variable_);
        setServerVariable(manufacturerName_Variable_);
        setServerVariable(productName_Variable_);
        setServerVariable(productUri_Variable_);
        setServerVariable(softwareVersion_Variable_);
        setServerVariable(variable_);
    }
    
    BuildInfoType::~BuildInfoType(void)
    {
    }

    ServerVariable::SPtr&
    BuildInfoType::buildDate_Variable(void)
    {
        return buildDate_Variable_;
    }

    ServerVariable::SPtr&
    BuildInfoType::buildNumber_Variable(void)
    {
        return buildNumber_Variable_;
    }

    ServerVariable::SPtr&
    BuildInfoType::manufacturerName_Variable(void)
    {
        return manufacturerName_Variable_;
    }

    ServerVariable::SPtr&
    BuildInfoType::productName_Variable(void)
    {
        return productName_Variable_;
    }

    ServerVariable::SPtr&
    BuildInfoType::productUri_Variable(void)
    {
        return productUri_Variable_;
    }

    ServerVariable::SPtr&
    BuildInfoType::softwareVersion_Variable(void)
    {
        return softwareVersion_Variable_;
    }

    ServerVariable::SPtr&
    BuildInfoType::variable(void)
    {
        return variable_;
    }

    void
    BuildInfoType::buildDate_Variable(ServerVariable::SPtr& serverVariable)
    {
        buildDate_Variable_ = serverVariable;
    }

    void
    BuildInfoType::buildNumber_Variable(ServerVariable::SPtr& serverVariable)
    {
        buildNumber_Variable_ = serverVariable;
    }

    void
    BuildInfoType::manufacturerName_Variable(ServerVariable::SPtr& serverVariable)
    {
        manufacturerName_Variable_ = serverVariable;
    }

    void
    BuildInfoType::productName_Variable(ServerVariable::SPtr& serverVariable)
    {
        productName_Variable_ = serverVariable;
    }

    void
    BuildInfoType::productUri_Variable(ServerVariable::SPtr& serverVariable)
    {
        productUri_Variable_ = serverVariable;
    }

    void
    BuildInfoType::softwareVersion_Variable(ServerVariable::SPtr& serverVariable)
    {
        softwareVersion_Variable_ = serverVariable;
    }

    void
    BuildInfoType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    bool
    BuildInfoType::get_BuildDate_Variable(OpcUaDataValue& dataValue)
    {
        return buildDate_Variable_->getDataValue(dataValue);
    }

    bool
    BuildInfoType::get_BuildNumber_Variable(OpcUaDataValue& dataValue)
    {
        return buildNumber_Variable_->getDataValue(dataValue);
    }

    bool
    BuildInfoType::get_ManufacturerName_Variable(OpcUaDataValue& dataValue)
    {
        return manufacturerName_Variable_->getDataValue(dataValue);
    }

    bool
    BuildInfoType::get_ProductName_Variable(OpcUaDataValue& dataValue)
    {
        return productName_Variable_->getDataValue(dataValue);
    }

    bool
    BuildInfoType::get_ProductUri_Variable(OpcUaDataValue& dataValue)
    {
        return productUri_Variable_->getDataValue(dataValue);
    }

    bool
    BuildInfoType::get_SoftwareVersion_Variable(OpcUaDataValue& dataValue)
    {
        return softwareVersion_Variable_->getDataValue(dataValue);
    }

    bool
    BuildInfoType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    BuildInfoType::set_BuildDate_Variable(const OpcUaDataValue& dataValue)
    {
        return buildDate_Variable_->setDataValue(dataValue);
    }

    bool
    BuildInfoType::set_BuildNumber_Variable(const OpcUaDataValue& dataValue)
    {
        return buildNumber_Variable_->setDataValue(dataValue);
    }

    bool
    BuildInfoType::set_ManufacturerName_Variable(const OpcUaDataValue& dataValue)
    {
        return manufacturerName_Variable_->setDataValue(dataValue);
    }

    bool
    BuildInfoType::set_ProductName_Variable(const OpcUaDataValue& dataValue)
    {
        return productName_Variable_->setDataValue(dataValue);
    }

    bool
    BuildInfoType::set_ProductUri_Variable(const OpcUaDataValue& dataValue)
    {
        return productUri_Variable_->setDataValue(dataValue);
    }

    bool
    BuildInfoType::set_SoftwareVersion_Variable(const OpcUaDataValue& dataValue)
    {
        return softwareVersion_Variable_->setDataValue(dataValue);
    }

    bool
    BuildInfoType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

}
