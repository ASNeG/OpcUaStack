/*
    VariableTypeClass: ServerCapabilitiesType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/ServerCapabilitiesType.h"

namespace OpcUaStackServer
{
    
    /**
     * Describes the capabilities supported by the server.
     */
    ServerCapabilitiesType::ServerCapabilitiesType(void)
    : ObjectBase()
    , localeIdArray_Variable_(boost::make_shared<ServerVariable>("LocaleIdArray_Variable"))
    , maxArrayLength_Variable_(boost::make_shared<ServerVariable>("MaxArrayLength_Variable"))
    , maxBrowseContinuationPoints_Variable_(boost::make_shared<ServerVariable>("MaxBrowseContinuationPoints_Variable"))
    , maxByteStringLength_Variable_(boost::make_shared<ServerVariable>("MaxByteStringLength_Variable"))
    , maxHistoryContinuationPoints_Variable_(boost::make_shared<ServerVariable>("MaxHistoryContinuationPoints_Variable"))
    , maxQueryContinuationPoints_Variable_(boost::make_shared<ServerVariable>("MaxQueryContinuationPoints_Variable"))
    , maxStringLength_Variable_(boost::make_shared<ServerVariable>("MaxStringLength_Variable"))
    , minSupportedSampleRate_Variable_(boost::make_shared<ServerVariable>("MinSupportedSampleRate_Variable"))
    , serverProfileArray_Variable_(boost::make_shared<ServerVariable>("ServerProfileArray_Variable"))
    , softwareCertificates_Variable_(boost::make_shared<ServerVariable>("SoftwareCertificates_Variable"))
    , roleSet_AddRole_Method_(boost::make_shared<ServerMethod>("RoleSet_AddRole_Method"))
    , roleSet_RemoveRole_Method_(boost::make_shared<ServerMethod>("RoleSet_RemoveRole_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2013);
        setServerVariable(localeIdArray_Variable_);
        setServerVariable(maxArrayLength_Variable_);
        setServerVariable(maxBrowseContinuationPoints_Variable_);
        setServerVariable(maxByteStringLength_Variable_);
        setServerVariable(maxHistoryContinuationPoints_Variable_);
        setServerVariable(maxQueryContinuationPoints_Variable_);
        setServerVariable(maxStringLength_Variable_);
        setServerVariable(minSupportedSampleRate_Variable_);
        setServerVariable(serverProfileArray_Variable_);
        setServerVariable(softwareCertificates_Variable_);
        setServerMethod(roleSet_AddRole_Method_);
        setServerMethod(roleSet_RemoveRole_Method_);
        roleSet_AddRole_Method_->registerMethod(boost::bind(&ServerCapabilitiesType::call_RoleSet_AddRole_Method, this, _1));
        roleSet_RemoveRole_Method_->registerMethod(boost::bind(&ServerCapabilitiesType::call_RoleSet_RemoveRole_Method, this, _1));
    }
    
    /**
     * Describes the capabilities supported by the server.
     */
    ServerCapabilitiesType::ServerCapabilitiesType(const ServerCapabilitiesType& value)
    : ObjectBase()
    , localeIdArray_Variable_(boost::make_shared<ServerVariable>("LocaleIdArray_Variable"))
    , maxArrayLength_Variable_(boost::make_shared<ServerVariable>("MaxArrayLength_Variable"))
    , maxBrowseContinuationPoints_Variable_(boost::make_shared<ServerVariable>("MaxBrowseContinuationPoints_Variable"))
    , maxByteStringLength_Variable_(boost::make_shared<ServerVariable>("MaxByteStringLength_Variable"))
    , maxHistoryContinuationPoints_Variable_(boost::make_shared<ServerVariable>("MaxHistoryContinuationPoints_Variable"))
    , maxQueryContinuationPoints_Variable_(boost::make_shared<ServerVariable>("MaxQueryContinuationPoints_Variable"))
    , maxStringLength_Variable_(boost::make_shared<ServerVariable>("MaxStringLength_Variable"))
    , minSupportedSampleRate_Variable_(boost::make_shared<ServerVariable>("MinSupportedSampleRate_Variable"))
    , serverProfileArray_Variable_(boost::make_shared<ServerVariable>("ServerProfileArray_Variable"))
    , softwareCertificates_Variable_(boost::make_shared<ServerVariable>("SoftwareCertificates_Variable"))
    , roleSet_AddRole_Method_(boost::make_shared<ServerMethod>("RoleSet_AddRole_Method"))
    , roleSet_RemoveRole_Method_(boost::make_shared<ServerMethod>("RoleSet_RemoveRole_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2013);
        setServerVariable(localeIdArray_Variable_);
        setServerVariable(maxArrayLength_Variable_);
        setServerVariable(maxBrowseContinuationPoints_Variable_);
        setServerVariable(maxByteStringLength_Variable_);
        setServerVariable(maxHistoryContinuationPoints_Variable_);
        setServerVariable(maxQueryContinuationPoints_Variable_);
        setServerVariable(maxStringLength_Variable_);
        setServerVariable(minSupportedSampleRate_Variable_);
        setServerVariable(serverProfileArray_Variable_);
        setServerVariable(softwareCertificates_Variable_);
        setServerMethod(roleSet_AddRole_Method_);
        setServerMethod(roleSet_RemoveRole_Method_);
        roleSet_AddRole_Method_->registerMethod(boost::bind(&ServerCapabilitiesType::call_RoleSet_AddRole_Method, this, _1));
        roleSet_RemoveRole_Method_->registerMethod(boost::bind(&ServerCapabilitiesType::call_RoleSet_RemoveRole_Method, this, _1));
    }
    
    ServerCapabilitiesType::~ServerCapabilitiesType(void)
    {
    }

    ServerVariable::SPtr&
    ServerCapabilitiesType::localeIdArray_Variable(void)
    {
        return localeIdArray_Variable_;
    }

    ServerVariable::SPtr&
    ServerCapabilitiesType::maxArrayLength_Variable(void)
    {
        return maxArrayLength_Variable_;
    }

    ServerVariable::SPtr&
    ServerCapabilitiesType::maxBrowseContinuationPoints_Variable(void)
    {
        return maxBrowseContinuationPoints_Variable_;
    }

    ServerVariable::SPtr&
    ServerCapabilitiesType::maxByteStringLength_Variable(void)
    {
        return maxByteStringLength_Variable_;
    }

    ServerVariable::SPtr&
    ServerCapabilitiesType::maxHistoryContinuationPoints_Variable(void)
    {
        return maxHistoryContinuationPoints_Variable_;
    }

    ServerVariable::SPtr&
    ServerCapabilitiesType::maxQueryContinuationPoints_Variable(void)
    {
        return maxQueryContinuationPoints_Variable_;
    }

    ServerVariable::SPtr&
    ServerCapabilitiesType::maxStringLength_Variable(void)
    {
        return maxStringLength_Variable_;
    }

    ServerVariable::SPtr&
    ServerCapabilitiesType::minSupportedSampleRate_Variable(void)
    {
        return minSupportedSampleRate_Variable_;
    }

    ServerVariable::SPtr&
    ServerCapabilitiesType::serverProfileArray_Variable(void)
    {
        return serverProfileArray_Variable_;
    }

    ServerVariable::SPtr&
    ServerCapabilitiesType::softwareCertificates_Variable(void)
    {
        return softwareCertificates_Variable_;
    }

    void
    ServerCapabilitiesType::localeIdArray_Variable(ServerVariable::SPtr& serverVariable)
    {
        localeIdArray_Variable_ = serverVariable;
    }

    void
    ServerCapabilitiesType::maxArrayLength_Variable(ServerVariable::SPtr& serverVariable)
    {
        maxArrayLength_Variable_ = serverVariable;
    }

    void
    ServerCapabilitiesType::maxBrowseContinuationPoints_Variable(ServerVariable::SPtr& serverVariable)
    {
        maxBrowseContinuationPoints_Variable_ = serverVariable;
    }

    void
    ServerCapabilitiesType::maxByteStringLength_Variable(ServerVariable::SPtr& serverVariable)
    {
        maxByteStringLength_Variable_ = serverVariable;
    }

    void
    ServerCapabilitiesType::maxHistoryContinuationPoints_Variable(ServerVariable::SPtr& serverVariable)
    {
        maxHistoryContinuationPoints_Variable_ = serverVariable;
    }

    void
    ServerCapabilitiesType::maxQueryContinuationPoints_Variable(ServerVariable::SPtr& serverVariable)
    {
        maxQueryContinuationPoints_Variable_ = serverVariable;
    }

    void
    ServerCapabilitiesType::maxStringLength_Variable(ServerVariable::SPtr& serverVariable)
    {
        maxStringLength_Variable_ = serverVariable;
    }

    void
    ServerCapabilitiesType::minSupportedSampleRate_Variable(ServerVariable::SPtr& serverVariable)
    {
        minSupportedSampleRate_Variable_ = serverVariable;
    }

    void
    ServerCapabilitiesType::serverProfileArray_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverProfileArray_Variable_ = serverVariable;
    }

    void
    ServerCapabilitiesType::softwareCertificates_Variable(ServerVariable::SPtr& serverVariable)
    {
        softwareCertificates_Variable_ = serverVariable;
    }

    bool
    ServerCapabilitiesType::get_LocaleIdArray_Variable(OpcUaDataValue& dataValue)
    {
        return localeIdArray_Variable_->getDataValue(dataValue);
    }

    bool
    ServerCapabilitiesType::get_MaxArrayLength_Variable(OpcUaDataValue& dataValue)
    {
        return maxArrayLength_Variable_->getDataValue(dataValue);
    }

    bool
    ServerCapabilitiesType::get_MaxBrowseContinuationPoints_Variable(OpcUaDataValue& dataValue)
    {
        return maxBrowseContinuationPoints_Variable_->getDataValue(dataValue);
    }

    bool
    ServerCapabilitiesType::get_MaxByteStringLength_Variable(OpcUaDataValue& dataValue)
    {
        return maxByteStringLength_Variable_->getDataValue(dataValue);
    }

    bool
    ServerCapabilitiesType::get_MaxHistoryContinuationPoints_Variable(OpcUaDataValue& dataValue)
    {
        return maxHistoryContinuationPoints_Variable_->getDataValue(dataValue);
    }

    bool
    ServerCapabilitiesType::get_MaxQueryContinuationPoints_Variable(OpcUaDataValue& dataValue)
    {
        return maxQueryContinuationPoints_Variable_->getDataValue(dataValue);
    }

    bool
    ServerCapabilitiesType::get_MaxStringLength_Variable(OpcUaDataValue& dataValue)
    {
        return maxStringLength_Variable_->getDataValue(dataValue);
    }

    bool
    ServerCapabilitiesType::get_MinSupportedSampleRate_Variable(OpcUaDataValue& dataValue)
    {
        return minSupportedSampleRate_Variable_->getDataValue(dataValue);
    }

    bool
    ServerCapabilitiesType::get_ServerProfileArray_Variable(OpcUaDataValue& dataValue)
    {
        return serverProfileArray_Variable_->getDataValue(dataValue);
    }

    bool
    ServerCapabilitiesType::get_SoftwareCertificates_Variable(OpcUaDataValue& dataValue)
    {
        return softwareCertificates_Variable_->getDataValue(dataValue);
    }

    bool
    ServerCapabilitiesType::set_LocaleIdArray_Variable(const OpcUaDataValue& dataValue)
    {
        return localeIdArray_Variable_->setDataValue(dataValue);
    }

    bool
    ServerCapabilitiesType::set_MaxArrayLength_Variable(const OpcUaDataValue& dataValue)
    {
        return maxArrayLength_Variable_->setDataValue(dataValue);
    }

    bool
    ServerCapabilitiesType::set_MaxBrowseContinuationPoints_Variable(const OpcUaDataValue& dataValue)
    {
        return maxBrowseContinuationPoints_Variable_->setDataValue(dataValue);
    }

    bool
    ServerCapabilitiesType::set_MaxByteStringLength_Variable(const OpcUaDataValue& dataValue)
    {
        return maxByteStringLength_Variable_->setDataValue(dataValue);
    }

    bool
    ServerCapabilitiesType::set_MaxHistoryContinuationPoints_Variable(const OpcUaDataValue& dataValue)
    {
        return maxHistoryContinuationPoints_Variable_->setDataValue(dataValue);
    }

    bool
    ServerCapabilitiesType::set_MaxQueryContinuationPoints_Variable(const OpcUaDataValue& dataValue)
    {
        return maxQueryContinuationPoints_Variable_->setDataValue(dataValue);
    }

    bool
    ServerCapabilitiesType::set_MaxStringLength_Variable(const OpcUaDataValue& dataValue)
    {
        return maxStringLength_Variable_->setDataValue(dataValue);
    }

    bool
    ServerCapabilitiesType::set_MinSupportedSampleRate_Variable(const OpcUaDataValue& dataValue)
    {
        return minSupportedSampleRate_Variable_->setDataValue(dataValue);
    }

    bool
    ServerCapabilitiesType::set_ServerProfileArray_Variable(const OpcUaDataValue& dataValue)
    {
        return serverProfileArray_Variable_->setDataValue(dataValue);
    }

    bool
    ServerCapabilitiesType::set_SoftwareCertificates_Variable(const OpcUaDataValue& dataValue)
    {
        return softwareCertificates_Variable_->setDataValue(dataValue);
    }

    void
    ServerCapabilitiesType::call_RoleSet_AddRole_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    ServerCapabilitiesType::call_RoleSet_RemoveRole_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

}
