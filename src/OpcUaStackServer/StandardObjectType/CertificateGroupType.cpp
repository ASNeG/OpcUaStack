/*
    VariableTypeClass: CertificateGroupType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/CertificateGroupType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    CertificateGroupType::CertificateGroupType(void)
    : ObjectBase()
    , certificateTypes_Variable_(boost::make_shared<ServerVariable>("CertificateTypes_Variable"))
    , trustList_LastUpdateTime_Variable_(boost::make_shared<ServerVariable>("TrustList_LastUpdateTime_Variable"))
    , trustList_OpenCount_Variable_(boost::make_shared<ServerVariable>("TrustList_OpenCount_Variable"))
    , trustList_Size_Variable_(boost::make_shared<ServerVariable>("TrustList_Size_Variable"))
    , trustList_UserWritable_Variable_(boost::make_shared<ServerVariable>("TrustList_UserWritable_Variable"))
    , trustList_Writable_Variable_(boost::make_shared<ServerVariable>("TrustList_Writable_Variable"))
    , trustList_Close_Method_(boost::make_shared<ServerMethod>("TrustList_Close_Method"))
    , trustList_GetPosition_Method_(boost::make_shared<ServerMethod>("TrustList_GetPosition_Method"))
    , trustList_OpenWithMasks_Method_(boost::make_shared<ServerMethod>("TrustList_OpenWithMasks_Method"))
    , trustList_Open_Method_(boost::make_shared<ServerMethod>("TrustList_Open_Method"))
    , trustList_Read_Method_(boost::make_shared<ServerMethod>("TrustList_Read_Method"))
    , trustList_SetPosition_Method_(boost::make_shared<ServerMethod>("TrustList_SetPosition_Method"))
    , trustList_Write_Method_(boost::make_shared<ServerMethod>("TrustList_Write_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)12555);
        setServerVariable(certificateTypes_Variable_);
        setServerVariable(trustList_LastUpdateTime_Variable_);
        setServerVariable(trustList_OpenCount_Variable_);
        setServerVariable(trustList_Size_Variable_);
        setServerVariable(trustList_UserWritable_Variable_);
        setServerVariable(trustList_Writable_Variable_);
        setServerMethod(trustList_Close_Method_);
        setServerMethod(trustList_GetPosition_Method_);
        setServerMethod(trustList_OpenWithMasks_Method_);
        setServerMethod(trustList_Open_Method_);
        setServerMethod(trustList_Read_Method_);
        setServerMethod(trustList_SetPosition_Method_);
        setServerMethod(trustList_Write_Method_);
        trustList_Close_Method_->registerMethod(boost::bind(&CertificateGroupType::call_TrustList_Close_Method, this, boost::placeholders::_1));
        trustList_GetPosition_Method_->registerMethod(boost::bind(&CertificateGroupType::call_TrustList_GetPosition_Method, this, boost::placeholders::_1));
        trustList_OpenWithMasks_Method_->registerMethod(boost::bind(&CertificateGroupType::call_TrustList_OpenWithMasks_Method, this, boost::placeholders::_1));
        trustList_Open_Method_->registerMethod(boost::bind(&CertificateGroupType::call_TrustList_Open_Method, this, boost::placeholders::_1));
        trustList_Read_Method_->registerMethod(boost::bind(&CertificateGroupType::call_TrustList_Read_Method, this, boost::placeholders::_1));
        trustList_SetPosition_Method_->registerMethod(boost::bind(&CertificateGroupType::call_TrustList_SetPosition_Method, this, boost::placeholders::_1));
        trustList_Write_Method_->registerMethod(boost::bind(&CertificateGroupType::call_TrustList_Write_Method, this, boost::placeholders::_1));
    }
    
    CertificateGroupType::CertificateGroupType(const CertificateGroupType& value)
    : ObjectBase()
    , certificateTypes_Variable_(boost::make_shared<ServerVariable>("CertificateTypes_Variable"))
    , trustList_LastUpdateTime_Variable_(boost::make_shared<ServerVariable>("TrustList_LastUpdateTime_Variable"))
    , trustList_OpenCount_Variable_(boost::make_shared<ServerVariable>("TrustList_OpenCount_Variable"))
    , trustList_Size_Variable_(boost::make_shared<ServerVariable>("TrustList_Size_Variable"))
    , trustList_UserWritable_Variable_(boost::make_shared<ServerVariable>("TrustList_UserWritable_Variable"))
    , trustList_Writable_Variable_(boost::make_shared<ServerVariable>("TrustList_Writable_Variable"))
    , trustList_Close_Method_(boost::make_shared<ServerMethod>("TrustList_Close_Method"))
    , trustList_GetPosition_Method_(boost::make_shared<ServerMethod>("TrustList_GetPosition_Method"))
    , trustList_OpenWithMasks_Method_(boost::make_shared<ServerMethod>("TrustList_OpenWithMasks_Method"))
    , trustList_Open_Method_(boost::make_shared<ServerMethod>("TrustList_Open_Method"))
    , trustList_Read_Method_(boost::make_shared<ServerMethod>("TrustList_Read_Method"))
    , trustList_SetPosition_Method_(boost::make_shared<ServerMethod>("TrustList_SetPosition_Method"))
    , trustList_Write_Method_(boost::make_shared<ServerMethod>("TrustList_Write_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)12555);
        setServerVariable(certificateTypes_Variable_);
        setServerVariable(trustList_LastUpdateTime_Variable_);
        setServerVariable(trustList_OpenCount_Variable_);
        setServerVariable(trustList_Size_Variable_);
        setServerVariable(trustList_UserWritable_Variable_);
        setServerVariable(trustList_Writable_Variable_);
        setServerMethod(trustList_Close_Method_);
        setServerMethod(trustList_GetPosition_Method_);
        setServerMethod(trustList_OpenWithMasks_Method_);
        setServerMethod(trustList_Open_Method_);
        setServerMethod(trustList_Read_Method_);
        setServerMethod(trustList_SetPosition_Method_);
        setServerMethod(trustList_Write_Method_);
        trustList_Close_Method_->registerMethod(boost::bind(&CertificateGroupType::call_TrustList_Close_Method, this, boost::placeholders::_1));
        trustList_GetPosition_Method_->registerMethod(boost::bind(&CertificateGroupType::call_TrustList_GetPosition_Method, this, boost::placeholders::_1));
        trustList_OpenWithMasks_Method_->registerMethod(boost::bind(&CertificateGroupType::call_TrustList_OpenWithMasks_Method, this, boost::placeholders::_1));
        trustList_Open_Method_->registerMethod(boost::bind(&CertificateGroupType::call_TrustList_Open_Method, this, boost::placeholders::_1));
        trustList_Read_Method_->registerMethod(boost::bind(&CertificateGroupType::call_TrustList_Read_Method, this, boost::placeholders::_1));
        trustList_SetPosition_Method_->registerMethod(boost::bind(&CertificateGroupType::call_TrustList_SetPosition_Method, this, boost::placeholders::_1));
        trustList_Write_Method_->registerMethod(boost::bind(&CertificateGroupType::call_TrustList_Write_Method, this, boost::placeholders::_1));
    }
    
    CertificateGroupType::~CertificateGroupType(void)
    {
    }

    ServerVariable::SPtr&
    CertificateGroupType::certificateTypes_Variable(void)
    {
        return certificateTypes_Variable_;
    }

    ServerVariable::SPtr&
    CertificateGroupType::trustList_LastUpdateTime_Variable(void)
    {
        return trustList_LastUpdateTime_Variable_;
    }

    ServerVariable::SPtr&
    CertificateGroupType::trustList_OpenCount_Variable(void)
    {
        return trustList_OpenCount_Variable_;
    }

    ServerVariable::SPtr&
    CertificateGroupType::trustList_Size_Variable(void)
    {
        return trustList_Size_Variable_;
    }

    ServerVariable::SPtr&
    CertificateGroupType::trustList_UserWritable_Variable(void)
    {
        return trustList_UserWritable_Variable_;
    }

    ServerVariable::SPtr&
    CertificateGroupType::trustList_Writable_Variable(void)
    {
        return trustList_Writable_Variable_;
    }

    void
    CertificateGroupType::certificateTypes_Variable(ServerVariable::SPtr& serverVariable)
    {
        certificateTypes_Variable_ = serverVariable;
    }

    void
    CertificateGroupType::trustList_LastUpdateTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        trustList_LastUpdateTime_Variable_ = serverVariable;
    }

    void
    CertificateGroupType::trustList_OpenCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        trustList_OpenCount_Variable_ = serverVariable;
    }

    void
    CertificateGroupType::trustList_Size_Variable(ServerVariable::SPtr& serverVariable)
    {
        trustList_Size_Variable_ = serverVariable;
    }

    void
    CertificateGroupType::trustList_UserWritable_Variable(ServerVariable::SPtr& serverVariable)
    {
        trustList_UserWritable_Variable_ = serverVariable;
    }

    void
    CertificateGroupType::trustList_Writable_Variable(ServerVariable::SPtr& serverVariable)
    {
        trustList_Writable_Variable_ = serverVariable;
    }

    bool
    CertificateGroupType::get_CertificateTypes_Variable(OpcUaDataValue& dataValue)
    {
        return certificateTypes_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateGroupType::get_TrustList_LastUpdateTime_Variable(OpcUaDataValue& dataValue)
    {
        return trustList_LastUpdateTime_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateGroupType::get_TrustList_OpenCount_Variable(OpcUaDataValue& dataValue)
    {
        return trustList_OpenCount_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateGroupType::get_TrustList_Size_Variable(OpcUaDataValue& dataValue)
    {
        return trustList_Size_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateGroupType::get_TrustList_UserWritable_Variable(OpcUaDataValue& dataValue)
    {
        return trustList_UserWritable_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateGroupType::get_TrustList_Writable_Variable(OpcUaDataValue& dataValue)
    {
        return trustList_Writable_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateGroupType::set_CertificateTypes_Variable(const OpcUaDataValue& dataValue)
    {
        return certificateTypes_Variable_->setDataValue(dataValue);
    }

    bool
    CertificateGroupType::set_TrustList_LastUpdateTime_Variable(const OpcUaDataValue& dataValue)
    {
        return trustList_LastUpdateTime_Variable_->setDataValue(dataValue);
    }

    bool
    CertificateGroupType::set_TrustList_OpenCount_Variable(const OpcUaDataValue& dataValue)
    {
        return trustList_OpenCount_Variable_->setDataValue(dataValue);
    }

    bool
    CertificateGroupType::set_TrustList_Size_Variable(const OpcUaDataValue& dataValue)
    {
        return trustList_Size_Variable_->setDataValue(dataValue);
    }

    bool
    CertificateGroupType::set_TrustList_UserWritable_Variable(const OpcUaDataValue& dataValue)
    {
        return trustList_UserWritable_Variable_->setDataValue(dataValue);
    }

    bool
    CertificateGroupType::set_TrustList_Writable_Variable(const OpcUaDataValue& dataValue)
    {
        return trustList_Writable_Variable_->setDataValue(dataValue);
    }

    void
    CertificateGroupType::call_TrustList_Close_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    CertificateGroupType::call_TrustList_GetPosition_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    CertificateGroupType::call_TrustList_OpenWithMasks_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    CertificateGroupType::call_TrustList_Open_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    CertificateGroupType::call_TrustList_Read_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    CertificateGroupType::call_TrustList_SetPosition_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    CertificateGroupType::call_TrustList_Write_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

}
