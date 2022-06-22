/*
    VariableTypeClass: ServerConfigurationType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/ServerConfigurationType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    ServerConfigurationType::ServerConfigurationType(void)
    : ObjectBase()
    , certificateGroups_DefaultApplicationGroup_CertificateTypes_Variable_(boost::make_shared<ServerVariable>("CertificateGroups_DefaultApplicationGroup_CertificateTypes_Variable"))
    , certificateGroups_DefaultApplicationGroup_TrustList_LastUpdateTime_Variable_(boost::make_shared<ServerVariable>("CertificateGroups_DefaultApplicationGroup_TrustList_LastUpdateTime_Variable"))
    , certificateGroups_DefaultApplicationGroup_TrustList_OpenCount_Variable_(boost::make_shared<ServerVariable>("CertificateGroups_DefaultApplicationGroup_TrustList_OpenCount_Variable"))
    , certificateGroups_DefaultApplicationGroup_TrustList_Size_Variable_(boost::make_shared<ServerVariable>("CertificateGroups_DefaultApplicationGroup_TrustList_Size_Variable"))
    , certificateGroups_DefaultApplicationGroup_TrustList_UserWritable_Variable_(boost::make_shared<ServerVariable>("CertificateGroups_DefaultApplicationGroup_TrustList_UserWritable_Variable"))
    , certificateGroups_DefaultApplicationGroup_TrustList_Writable_Variable_(boost::make_shared<ServerVariable>("CertificateGroups_DefaultApplicationGroup_TrustList_Writable_Variable"))
    , maxTrustListSize_Variable_(boost::make_shared<ServerVariable>("MaxTrustListSize_Variable"))
    , multicastDnsEnabled_Variable_(boost::make_shared<ServerVariable>("MulticastDnsEnabled_Variable"))
    , serverCapabilities_Variable_(boost::make_shared<ServerVariable>("ServerCapabilities_Variable"))
    , supportedPrivateKeyFormats_Variable_(boost::make_shared<ServerVariable>("SupportedPrivateKeyFormats_Variable"))
    , applyChanges_Method_(boost::make_shared<ServerMethod>("ApplyChanges_Method"))
    , certificateGroups_DefaultApplicationGroup_TrustList_Close_Method_(boost::make_shared<ServerMethod>("CertificateGroups_DefaultApplicationGroup_TrustList_Close_Method"))
    , certificateGroups_DefaultApplicationGroup_TrustList_GetPosition_Method_(boost::make_shared<ServerMethod>("CertificateGroups_DefaultApplicationGroup_TrustList_GetPosition_Method"))
    , certificateGroups_DefaultApplicationGroup_TrustList_OpenWithMasks_Method_(boost::make_shared<ServerMethod>("CertificateGroups_DefaultApplicationGroup_TrustList_OpenWithMasks_Method"))
    , certificateGroups_DefaultApplicationGroup_TrustList_Open_Method_(boost::make_shared<ServerMethod>("CertificateGroups_DefaultApplicationGroup_TrustList_Open_Method"))
    , certificateGroups_DefaultApplicationGroup_TrustList_Read_Method_(boost::make_shared<ServerMethod>("CertificateGroups_DefaultApplicationGroup_TrustList_Read_Method"))
    , certificateGroups_DefaultApplicationGroup_TrustList_SetPosition_Method_(boost::make_shared<ServerMethod>("CertificateGroups_DefaultApplicationGroup_TrustList_SetPosition_Method"))
    , certificateGroups_DefaultApplicationGroup_TrustList_Write_Method_(boost::make_shared<ServerMethod>("CertificateGroups_DefaultApplicationGroup_TrustList_Write_Method"))
    , createSigningRequest_Method_(boost::make_shared<ServerMethod>("CreateSigningRequest_Method"))
    , getRejectedList_Method_(boost::make_shared<ServerMethod>("GetRejectedList_Method"))
    , updateCertificate_Method_(boost::make_shared<ServerMethod>("UpdateCertificate_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)12581);
        setServerVariable(certificateGroups_DefaultApplicationGroup_CertificateTypes_Variable_);
        setServerVariable(certificateGroups_DefaultApplicationGroup_TrustList_LastUpdateTime_Variable_);
        setServerVariable(certificateGroups_DefaultApplicationGroup_TrustList_OpenCount_Variable_);
        setServerVariable(certificateGroups_DefaultApplicationGroup_TrustList_Size_Variable_);
        setServerVariable(certificateGroups_DefaultApplicationGroup_TrustList_UserWritable_Variable_);
        setServerVariable(certificateGroups_DefaultApplicationGroup_TrustList_Writable_Variable_);
        setServerVariable(maxTrustListSize_Variable_);
        setServerVariable(multicastDnsEnabled_Variable_);
        setServerVariable(serverCapabilities_Variable_);
        setServerVariable(supportedPrivateKeyFormats_Variable_);
        setServerMethod(applyChanges_Method_);
        setServerMethod(certificateGroups_DefaultApplicationGroup_TrustList_Close_Method_);
        setServerMethod(certificateGroups_DefaultApplicationGroup_TrustList_GetPosition_Method_);
        setServerMethod(certificateGroups_DefaultApplicationGroup_TrustList_OpenWithMasks_Method_);
        setServerMethod(certificateGroups_DefaultApplicationGroup_TrustList_Open_Method_);
        setServerMethod(certificateGroups_DefaultApplicationGroup_TrustList_Read_Method_);
        setServerMethod(certificateGroups_DefaultApplicationGroup_TrustList_SetPosition_Method_);
        setServerMethod(certificateGroups_DefaultApplicationGroup_TrustList_Write_Method_);
        setServerMethod(createSigningRequest_Method_);
        setServerMethod(getRejectedList_Method_);
        setServerMethod(updateCertificate_Method_);
        applyChanges_Method_->registerMethod(boost::bind(&ServerConfigurationType::call_ApplyChanges_Method, this, _1));
        certificateGroups_DefaultApplicationGroup_TrustList_Close_Method_->registerMethod(boost::bind(&ServerConfigurationType::call_CertificateGroups_DefaultApplicationGroup_TrustList_Close_Method, this, _1));
        certificateGroups_DefaultApplicationGroup_TrustList_GetPosition_Method_->registerMethod(boost::bind(&ServerConfigurationType::call_CertificateGroups_DefaultApplicationGroup_TrustList_GetPosition_Method, this, _1));
        certificateGroups_DefaultApplicationGroup_TrustList_OpenWithMasks_Method_->registerMethod(boost::bind(&ServerConfigurationType::call_CertificateGroups_DefaultApplicationGroup_TrustList_OpenWithMasks_Method, this, _1));
        certificateGroups_DefaultApplicationGroup_TrustList_Open_Method_->registerMethod(boost::bind(&ServerConfigurationType::call_CertificateGroups_DefaultApplicationGroup_TrustList_Open_Method, this, _1));
        certificateGroups_DefaultApplicationGroup_TrustList_Read_Method_->registerMethod(boost::bind(&ServerConfigurationType::call_CertificateGroups_DefaultApplicationGroup_TrustList_Read_Method, this, _1));
        certificateGroups_DefaultApplicationGroup_TrustList_SetPosition_Method_->registerMethod(boost::bind(&ServerConfigurationType::call_CertificateGroups_DefaultApplicationGroup_TrustList_SetPosition_Method, this, _1));
        certificateGroups_DefaultApplicationGroup_TrustList_Write_Method_->registerMethod(boost::bind(&ServerConfigurationType::call_CertificateGroups_DefaultApplicationGroup_TrustList_Write_Method, this, _1));
        createSigningRequest_Method_->registerMethod(boost::bind(&ServerConfigurationType::call_CreateSigningRequest_Method, this, _1));
        getRejectedList_Method_->registerMethod(boost::bind(&ServerConfigurationType::call_GetRejectedList_Method, this, _1));
        updateCertificate_Method_->registerMethod(boost::bind(&ServerConfigurationType::call_UpdateCertificate_Method, this, _1));
    }
    
    ServerConfigurationType::ServerConfigurationType(const ServerConfigurationType& value)
    : ObjectBase()
    , certificateGroups_DefaultApplicationGroup_CertificateTypes_Variable_(boost::make_shared<ServerVariable>("CertificateGroups_DefaultApplicationGroup_CertificateTypes_Variable"))
    , certificateGroups_DefaultApplicationGroup_TrustList_LastUpdateTime_Variable_(boost::make_shared<ServerVariable>("CertificateGroups_DefaultApplicationGroup_TrustList_LastUpdateTime_Variable"))
    , certificateGroups_DefaultApplicationGroup_TrustList_OpenCount_Variable_(boost::make_shared<ServerVariable>("CertificateGroups_DefaultApplicationGroup_TrustList_OpenCount_Variable"))
    , certificateGroups_DefaultApplicationGroup_TrustList_Size_Variable_(boost::make_shared<ServerVariable>("CertificateGroups_DefaultApplicationGroup_TrustList_Size_Variable"))
    , certificateGroups_DefaultApplicationGroup_TrustList_UserWritable_Variable_(boost::make_shared<ServerVariable>("CertificateGroups_DefaultApplicationGroup_TrustList_UserWritable_Variable"))
    , certificateGroups_DefaultApplicationGroup_TrustList_Writable_Variable_(boost::make_shared<ServerVariable>("CertificateGroups_DefaultApplicationGroup_TrustList_Writable_Variable"))
    , maxTrustListSize_Variable_(boost::make_shared<ServerVariable>("MaxTrustListSize_Variable"))
    , multicastDnsEnabled_Variable_(boost::make_shared<ServerVariable>("MulticastDnsEnabled_Variable"))
    , serverCapabilities_Variable_(boost::make_shared<ServerVariable>("ServerCapabilities_Variable"))
    , supportedPrivateKeyFormats_Variable_(boost::make_shared<ServerVariable>("SupportedPrivateKeyFormats_Variable"))
    , applyChanges_Method_(boost::make_shared<ServerMethod>("ApplyChanges_Method"))
    , certificateGroups_DefaultApplicationGroup_TrustList_Close_Method_(boost::make_shared<ServerMethod>("CertificateGroups_DefaultApplicationGroup_TrustList_Close_Method"))
    , certificateGroups_DefaultApplicationGroup_TrustList_GetPosition_Method_(boost::make_shared<ServerMethod>("CertificateGroups_DefaultApplicationGroup_TrustList_GetPosition_Method"))
    , certificateGroups_DefaultApplicationGroup_TrustList_OpenWithMasks_Method_(boost::make_shared<ServerMethod>("CertificateGroups_DefaultApplicationGroup_TrustList_OpenWithMasks_Method"))
    , certificateGroups_DefaultApplicationGroup_TrustList_Open_Method_(boost::make_shared<ServerMethod>("CertificateGroups_DefaultApplicationGroup_TrustList_Open_Method"))
    , certificateGroups_DefaultApplicationGroup_TrustList_Read_Method_(boost::make_shared<ServerMethod>("CertificateGroups_DefaultApplicationGroup_TrustList_Read_Method"))
    , certificateGroups_DefaultApplicationGroup_TrustList_SetPosition_Method_(boost::make_shared<ServerMethod>("CertificateGroups_DefaultApplicationGroup_TrustList_SetPosition_Method"))
    , certificateGroups_DefaultApplicationGroup_TrustList_Write_Method_(boost::make_shared<ServerMethod>("CertificateGroups_DefaultApplicationGroup_TrustList_Write_Method"))
    , createSigningRequest_Method_(boost::make_shared<ServerMethod>("CreateSigningRequest_Method"))
    , getRejectedList_Method_(boost::make_shared<ServerMethod>("GetRejectedList_Method"))
    , updateCertificate_Method_(boost::make_shared<ServerMethod>("UpdateCertificate_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)12581);
        setServerVariable(certificateGroups_DefaultApplicationGroup_CertificateTypes_Variable_);
        setServerVariable(certificateGroups_DefaultApplicationGroup_TrustList_LastUpdateTime_Variable_);
        setServerVariable(certificateGroups_DefaultApplicationGroup_TrustList_OpenCount_Variable_);
        setServerVariable(certificateGroups_DefaultApplicationGroup_TrustList_Size_Variable_);
        setServerVariable(certificateGroups_DefaultApplicationGroup_TrustList_UserWritable_Variable_);
        setServerVariable(certificateGroups_DefaultApplicationGroup_TrustList_Writable_Variable_);
        setServerVariable(maxTrustListSize_Variable_);
        setServerVariable(multicastDnsEnabled_Variable_);
        setServerVariable(serverCapabilities_Variable_);
        setServerVariable(supportedPrivateKeyFormats_Variable_);
        setServerMethod(applyChanges_Method_);
        setServerMethod(certificateGroups_DefaultApplicationGroup_TrustList_Close_Method_);
        setServerMethod(certificateGroups_DefaultApplicationGroup_TrustList_GetPosition_Method_);
        setServerMethod(certificateGroups_DefaultApplicationGroup_TrustList_OpenWithMasks_Method_);
        setServerMethod(certificateGroups_DefaultApplicationGroup_TrustList_Open_Method_);
        setServerMethod(certificateGroups_DefaultApplicationGroup_TrustList_Read_Method_);
        setServerMethod(certificateGroups_DefaultApplicationGroup_TrustList_SetPosition_Method_);
        setServerMethod(certificateGroups_DefaultApplicationGroup_TrustList_Write_Method_);
        setServerMethod(createSigningRequest_Method_);
        setServerMethod(getRejectedList_Method_);
        setServerMethod(updateCertificate_Method_);
        applyChanges_Method_->registerMethod(boost::bind(&ServerConfigurationType::call_ApplyChanges_Method, this, _1));
        certificateGroups_DefaultApplicationGroup_TrustList_Close_Method_->registerMethod(boost::bind(&ServerConfigurationType::call_CertificateGroups_DefaultApplicationGroup_TrustList_Close_Method, this, _1));
        certificateGroups_DefaultApplicationGroup_TrustList_GetPosition_Method_->registerMethod(boost::bind(&ServerConfigurationType::call_CertificateGroups_DefaultApplicationGroup_TrustList_GetPosition_Method, this, _1));
        certificateGroups_DefaultApplicationGroup_TrustList_OpenWithMasks_Method_->registerMethod(boost::bind(&ServerConfigurationType::call_CertificateGroups_DefaultApplicationGroup_TrustList_OpenWithMasks_Method, this, _1));
        certificateGroups_DefaultApplicationGroup_TrustList_Open_Method_->registerMethod(boost::bind(&ServerConfigurationType::call_CertificateGroups_DefaultApplicationGroup_TrustList_Open_Method, this, _1));
        certificateGroups_DefaultApplicationGroup_TrustList_Read_Method_->registerMethod(boost::bind(&ServerConfigurationType::call_CertificateGroups_DefaultApplicationGroup_TrustList_Read_Method, this, _1));
        certificateGroups_DefaultApplicationGroup_TrustList_SetPosition_Method_->registerMethod(boost::bind(&ServerConfigurationType::call_CertificateGroups_DefaultApplicationGroup_TrustList_SetPosition_Method, this, _1));
        certificateGroups_DefaultApplicationGroup_TrustList_Write_Method_->registerMethod(boost::bind(&ServerConfigurationType::call_CertificateGroups_DefaultApplicationGroup_TrustList_Write_Method, this, _1));
        createSigningRequest_Method_->registerMethod(boost::bind(&ServerConfigurationType::call_CreateSigningRequest_Method, this, _1));
        getRejectedList_Method_->registerMethod(boost::bind(&ServerConfigurationType::call_GetRejectedList_Method, this, _1));
        updateCertificate_Method_->registerMethod(boost::bind(&ServerConfigurationType::call_UpdateCertificate_Method, this, _1));
    }
    
    ServerConfigurationType::~ServerConfigurationType(void)
    {
    }

    ServerVariable::SPtr&
    ServerConfigurationType::certificateGroups_DefaultApplicationGroup_CertificateTypes_Variable(void)
    {
        return certificateGroups_DefaultApplicationGroup_CertificateTypes_Variable_;
    }

    ServerVariable::SPtr&
    ServerConfigurationType::certificateGroups_DefaultApplicationGroup_TrustList_LastUpdateTime_Variable(void)
    {
        return certificateGroups_DefaultApplicationGroup_TrustList_LastUpdateTime_Variable_;
    }

    ServerVariable::SPtr&
    ServerConfigurationType::certificateGroups_DefaultApplicationGroup_TrustList_OpenCount_Variable(void)
    {
        return certificateGroups_DefaultApplicationGroup_TrustList_OpenCount_Variable_;
    }

    ServerVariable::SPtr&
    ServerConfigurationType::certificateGroups_DefaultApplicationGroup_TrustList_Size_Variable(void)
    {
        return certificateGroups_DefaultApplicationGroup_TrustList_Size_Variable_;
    }

    ServerVariable::SPtr&
    ServerConfigurationType::certificateGroups_DefaultApplicationGroup_TrustList_UserWritable_Variable(void)
    {
        return certificateGroups_DefaultApplicationGroup_TrustList_UserWritable_Variable_;
    }

    ServerVariable::SPtr&
    ServerConfigurationType::certificateGroups_DefaultApplicationGroup_TrustList_Writable_Variable(void)
    {
        return certificateGroups_DefaultApplicationGroup_TrustList_Writable_Variable_;
    }

    ServerVariable::SPtr&
    ServerConfigurationType::maxTrustListSize_Variable(void)
    {
        return maxTrustListSize_Variable_;
    }

    ServerVariable::SPtr&
    ServerConfigurationType::multicastDnsEnabled_Variable(void)
    {
        return multicastDnsEnabled_Variable_;
    }

    ServerVariable::SPtr&
    ServerConfigurationType::serverCapabilities_Variable(void)
    {
        return serverCapabilities_Variable_;
    }

    ServerVariable::SPtr&
    ServerConfigurationType::supportedPrivateKeyFormats_Variable(void)
    {
        return supportedPrivateKeyFormats_Variable_;
    }

    void
    ServerConfigurationType::certificateGroups_DefaultApplicationGroup_CertificateTypes_Variable(ServerVariable::SPtr& serverVariable)
    {
        certificateGroups_DefaultApplicationGroup_CertificateTypes_Variable_ = serverVariable;
    }

    void
    ServerConfigurationType::certificateGroups_DefaultApplicationGroup_TrustList_LastUpdateTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        certificateGroups_DefaultApplicationGroup_TrustList_LastUpdateTime_Variable_ = serverVariable;
    }

    void
    ServerConfigurationType::certificateGroups_DefaultApplicationGroup_TrustList_OpenCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        certificateGroups_DefaultApplicationGroup_TrustList_OpenCount_Variable_ = serverVariable;
    }

    void
    ServerConfigurationType::certificateGroups_DefaultApplicationGroup_TrustList_Size_Variable(ServerVariable::SPtr& serverVariable)
    {
        certificateGroups_DefaultApplicationGroup_TrustList_Size_Variable_ = serverVariable;
    }

    void
    ServerConfigurationType::certificateGroups_DefaultApplicationGroup_TrustList_UserWritable_Variable(ServerVariable::SPtr& serverVariable)
    {
        certificateGroups_DefaultApplicationGroup_TrustList_UserWritable_Variable_ = serverVariable;
    }

    void
    ServerConfigurationType::certificateGroups_DefaultApplicationGroup_TrustList_Writable_Variable(ServerVariable::SPtr& serverVariable)
    {
        certificateGroups_DefaultApplicationGroup_TrustList_Writable_Variable_ = serverVariable;
    }

    void
    ServerConfigurationType::maxTrustListSize_Variable(ServerVariable::SPtr& serverVariable)
    {
        maxTrustListSize_Variable_ = serverVariable;
    }

    void
    ServerConfigurationType::multicastDnsEnabled_Variable(ServerVariable::SPtr& serverVariable)
    {
        multicastDnsEnabled_Variable_ = serverVariable;
    }

    void
    ServerConfigurationType::serverCapabilities_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverCapabilities_Variable_ = serverVariable;
    }

    void
    ServerConfigurationType::supportedPrivateKeyFormats_Variable(ServerVariable::SPtr& serverVariable)
    {
        supportedPrivateKeyFormats_Variable_ = serverVariable;
    }

    bool
    ServerConfigurationType::get_CertificateGroups_DefaultApplicationGroup_CertificateTypes_Variable(OpcUaDataValue& dataValue)
    {
        return certificateGroups_DefaultApplicationGroup_CertificateTypes_Variable_->getDataValue(dataValue);
    }

    bool
    ServerConfigurationType::get_CertificateGroups_DefaultApplicationGroup_TrustList_LastUpdateTime_Variable(OpcUaDataValue& dataValue)
    {
        return certificateGroups_DefaultApplicationGroup_TrustList_LastUpdateTime_Variable_->getDataValue(dataValue);
    }

    bool
    ServerConfigurationType::get_CertificateGroups_DefaultApplicationGroup_TrustList_OpenCount_Variable(OpcUaDataValue& dataValue)
    {
        return certificateGroups_DefaultApplicationGroup_TrustList_OpenCount_Variable_->getDataValue(dataValue);
    }

    bool
    ServerConfigurationType::get_CertificateGroups_DefaultApplicationGroup_TrustList_Size_Variable(OpcUaDataValue& dataValue)
    {
        return certificateGroups_DefaultApplicationGroup_TrustList_Size_Variable_->getDataValue(dataValue);
    }

    bool
    ServerConfigurationType::get_CertificateGroups_DefaultApplicationGroup_TrustList_UserWritable_Variable(OpcUaDataValue& dataValue)
    {
        return certificateGroups_DefaultApplicationGroup_TrustList_UserWritable_Variable_->getDataValue(dataValue);
    }

    bool
    ServerConfigurationType::get_CertificateGroups_DefaultApplicationGroup_TrustList_Writable_Variable(OpcUaDataValue& dataValue)
    {
        return certificateGroups_DefaultApplicationGroup_TrustList_Writable_Variable_->getDataValue(dataValue);
    }

    bool
    ServerConfigurationType::get_MaxTrustListSize_Variable(OpcUaDataValue& dataValue)
    {
        return maxTrustListSize_Variable_->getDataValue(dataValue);
    }

    bool
    ServerConfigurationType::get_MulticastDnsEnabled_Variable(OpcUaDataValue& dataValue)
    {
        return multicastDnsEnabled_Variable_->getDataValue(dataValue);
    }

    bool
    ServerConfigurationType::get_ServerCapabilities_Variable(OpcUaDataValue& dataValue)
    {
        return serverCapabilities_Variable_->getDataValue(dataValue);
    }

    bool
    ServerConfigurationType::get_SupportedPrivateKeyFormats_Variable(OpcUaDataValue& dataValue)
    {
        return supportedPrivateKeyFormats_Variable_->getDataValue(dataValue);
    }

    bool
    ServerConfigurationType::set_CertificateGroups_DefaultApplicationGroup_CertificateTypes_Variable(const OpcUaDataValue& dataValue)
    {
        return certificateGroups_DefaultApplicationGroup_CertificateTypes_Variable_->setDataValue(dataValue);
    }

    bool
    ServerConfigurationType::set_CertificateGroups_DefaultApplicationGroup_TrustList_LastUpdateTime_Variable(const OpcUaDataValue& dataValue)
    {
        return certificateGroups_DefaultApplicationGroup_TrustList_LastUpdateTime_Variable_->setDataValue(dataValue);
    }

    bool
    ServerConfigurationType::set_CertificateGroups_DefaultApplicationGroup_TrustList_OpenCount_Variable(const OpcUaDataValue& dataValue)
    {
        return certificateGroups_DefaultApplicationGroup_TrustList_OpenCount_Variable_->setDataValue(dataValue);
    }

    bool
    ServerConfigurationType::set_CertificateGroups_DefaultApplicationGroup_TrustList_Size_Variable(const OpcUaDataValue& dataValue)
    {
        return certificateGroups_DefaultApplicationGroup_TrustList_Size_Variable_->setDataValue(dataValue);
    }

    bool
    ServerConfigurationType::set_CertificateGroups_DefaultApplicationGroup_TrustList_UserWritable_Variable(const OpcUaDataValue& dataValue)
    {
        return certificateGroups_DefaultApplicationGroup_TrustList_UserWritable_Variable_->setDataValue(dataValue);
    }

    bool
    ServerConfigurationType::set_CertificateGroups_DefaultApplicationGroup_TrustList_Writable_Variable(const OpcUaDataValue& dataValue)
    {
        return certificateGroups_DefaultApplicationGroup_TrustList_Writable_Variable_->setDataValue(dataValue);
    }

    bool
    ServerConfigurationType::set_MaxTrustListSize_Variable(const OpcUaDataValue& dataValue)
    {
        return maxTrustListSize_Variable_->setDataValue(dataValue);
    }

    bool
    ServerConfigurationType::set_MulticastDnsEnabled_Variable(const OpcUaDataValue& dataValue)
    {
        return multicastDnsEnabled_Variable_->setDataValue(dataValue);
    }

    bool
    ServerConfigurationType::set_ServerCapabilities_Variable(const OpcUaDataValue& dataValue)
    {
        return serverCapabilities_Variable_->setDataValue(dataValue);
    }

    bool
    ServerConfigurationType::set_SupportedPrivateKeyFormats_Variable(const OpcUaDataValue& dataValue)
    {
        return supportedPrivateKeyFormats_Variable_->setDataValue(dataValue);
    }

    void
    ServerConfigurationType::call_ApplyChanges_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    ServerConfigurationType::call_CertificateGroups_DefaultApplicationGroup_TrustList_Close_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    ServerConfigurationType::call_CertificateGroups_DefaultApplicationGroup_TrustList_GetPosition_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    ServerConfigurationType::call_CertificateGroups_DefaultApplicationGroup_TrustList_OpenWithMasks_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    ServerConfigurationType::call_CertificateGroups_DefaultApplicationGroup_TrustList_Open_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    ServerConfigurationType::call_CertificateGroups_DefaultApplicationGroup_TrustList_Read_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    ServerConfigurationType::call_CertificateGroups_DefaultApplicationGroup_TrustList_SetPosition_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    ServerConfigurationType::call_CertificateGroups_DefaultApplicationGroup_TrustList_Write_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    ServerConfigurationType::call_CreateSigningRequest_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    ServerConfigurationType::call_GetRejectedList_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    ServerConfigurationType::call_UpdateCertificate_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

}
