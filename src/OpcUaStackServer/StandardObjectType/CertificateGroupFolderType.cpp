/*
    VariableTypeClass: CertificateGroupFolderType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/CertificateGroupFolderType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    CertificateGroupFolderType::CertificateGroupFolderType(void)
    : ObjectBase()
    , defaultApplicationGroup_CertificateTypes_Variable_(boost::make_shared<ServerVariable>("DefaultApplicationGroup_CertificateTypes_Variable"))
    , defaultApplicationGroup_TrustList_LastUpdateTime_Variable_(boost::make_shared<ServerVariable>("DefaultApplicationGroup_TrustList_LastUpdateTime_Variable"))
    , defaultApplicationGroup_TrustList_OpenCount_Variable_(boost::make_shared<ServerVariable>("DefaultApplicationGroup_TrustList_OpenCount_Variable"))
    , defaultApplicationGroup_TrustList_Size_Variable_(boost::make_shared<ServerVariable>("DefaultApplicationGroup_TrustList_Size_Variable"))
    , defaultApplicationGroup_TrustList_UserWritable_Variable_(boost::make_shared<ServerVariable>("DefaultApplicationGroup_TrustList_UserWritable_Variable"))
    , defaultApplicationGroup_TrustList_Writable_Variable_(boost::make_shared<ServerVariable>("DefaultApplicationGroup_TrustList_Writable_Variable"))
    , defaultHttpsGroup_CertificateTypes_Variable_(boost::make_shared<ServerVariable>("DefaultHttpsGroup_CertificateTypes_Variable"))
    , defaultHttpsGroup_TrustList_LastUpdateTime_Variable_(boost::make_shared<ServerVariable>("DefaultHttpsGroup_TrustList_LastUpdateTime_Variable"))
    , defaultHttpsGroup_TrustList_OpenCount_Variable_(boost::make_shared<ServerVariable>("DefaultHttpsGroup_TrustList_OpenCount_Variable"))
    , defaultHttpsGroup_TrustList_Size_Variable_(boost::make_shared<ServerVariable>("DefaultHttpsGroup_TrustList_Size_Variable"))
    , defaultHttpsGroup_TrustList_UserWritable_Variable_(boost::make_shared<ServerVariable>("DefaultHttpsGroup_TrustList_UserWritable_Variable"))
    , defaultHttpsGroup_TrustList_Writable_Variable_(boost::make_shared<ServerVariable>("DefaultHttpsGroup_TrustList_Writable_Variable"))
    , defaultUserTokenGroup_CertificateTypes_Variable_(boost::make_shared<ServerVariable>("DefaultUserTokenGroup_CertificateTypes_Variable"))
    , defaultUserTokenGroup_TrustList_LastUpdateTime_Variable_(boost::make_shared<ServerVariable>("DefaultUserTokenGroup_TrustList_LastUpdateTime_Variable"))
    , defaultUserTokenGroup_TrustList_OpenCount_Variable_(boost::make_shared<ServerVariable>("DefaultUserTokenGroup_TrustList_OpenCount_Variable"))
    , defaultUserTokenGroup_TrustList_Size_Variable_(boost::make_shared<ServerVariable>("DefaultUserTokenGroup_TrustList_Size_Variable"))
    , defaultUserTokenGroup_TrustList_UserWritable_Variable_(boost::make_shared<ServerVariable>("DefaultUserTokenGroup_TrustList_UserWritable_Variable"))
    , defaultUserTokenGroup_TrustList_Writable_Variable_(boost::make_shared<ServerVariable>("DefaultUserTokenGroup_TrustList_Writable_Variable"))
    , defaultApplicationGroup_TrustList_Close_Method_(boost::make_shared<ServerMethod>("DefaultApplicationGroup_TrustList_Close_Method"))
    , defaultApplicationGroup_TrustList_GetPosition_Method_(boost::make_shared<ServerMethod>("DefaultApplicationGroup_TrustList_GetPosition_Method"))
    , defaultApplicationGroup_TrustList_OpenWithMasks_Method_(boost::make_shared<ServerMethod>("DefaultApplicationGroup_TrustList_OpenWithMasks_Method"))
    , defaultApplicationGroup_TrustList_Open_Method_(boost::make_shared<ServerMethod>("DefaultApplicationGroup_TrustList_Open_Method"))
    , defaultApplicationGroup_TrustList_Read_Method_(boost::make_shared<ServerMethod>("DefaultApplicationGroup_TrustList_Read_Method"))
    , defaultApplicationGroup_TrustList_SetPosition_Method_(boost::make_shared<ServerMethod>("DefaultApplicationGroup_TrustList_SetPosition_Method"))
    , defaultApplicationGroup_TrustList_Write_Method_(boost::make_shared<ServerMethod>("DefaultApplicationGroup_TrustList_Write_Method"))
    , defaultHttpsGroup_TrustList_Close_Method_(boost::make_shared<ServerMethod>("DefaultHttpsGroup_TrustList_Close_Method"))
    , defaultHttpsGroup_TrustList_GetPosition_Method_(boost::make_shared<ServerMethod>("DefaultHttpsGroup_TrustList_GetPosition_Method"))
    , defaultHttpsGroup_TrustList_OpenWithMasks_Method_(boost::make_shared<ServerMethod>("DefaultHttpsGroup_TrustList_OpenWithMasks_Method"))
    , defaultHttpsGroup_TrustList_Open_Method_(boost::make_shared<ServerMethod>("DefaultHttpsGroup_TrustList_Open_Method"))
    , defaultHttpsGroup_TrustList_Read_Method_(boost::make_shared<ServerMethod>("DefaultHttpsGroup_TrustList_Read_Method"))
    , defaultHttpsGroup_TrustList_SetPosition_Method_(boost::make_shared<ServerMethod>("DefaultHttpsGroup_TrustList_SetPosition_Method"))
    , defaultHttpsGroup_TrustList_Write_Method_(boost::make_shared<ServerMethod>("DefaultHttpsGroup_TrustList_Write_Method"))
    , defaultUserTokenGroup_TrustList_Close_Method_(boost::make_shared<ServerMethod>("DefaultUserTokenGroup_TrustList_Close_Method"))
    , defaultUserTokenGroup_TrustList_GetPosition_Method_(boost::make_shared<ServerMethod>("DefaultUserTokenGroup_TrustList_GetPosition_Method"))
    , defaultUserTokenGroup_TrustList_OpenWithMasks_Method_(boost::make_shared<ServerMethod>("DefaultUserTokenGroup_TrustList_OpenWithMasks_Method"))
    , defaultUserTokenGroup_TrustList_Open_Method_(boost::make_shared<ServerMethod>("DefaultUserTokenGroup_TrustList_Open_Method"))
    , defaultUserTokenGroup_TrustList_Read_Method_(boost::make_shared<ServerMethod>("DefaultUserTokenGroup_TrustList_Read_Method"))
    , defaultUserTokenGroup_TrustList_SetPosition_Method_(boost::make_shared<ServerMethod>("DefaultUserTokenGroup_TrustList_SetPosition_Method"))
    , defaultUserTokenGroup_TrustList_Write_Method_(boost::make_shared<ServerMethod>("DefaultUserTokenGroup_TrustList_Write_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)13813);
        setServerVariable(defaultApplicationGroup_CertificateTypes_Variable_);
        setServerVariable(defaultApplicationGroup_TrustList_LastUpdateTime_Variable_);
        setServerVariable(defaultApplicationGroup_TrustList_OpenCount_Variable_);
        setServerVariable(defaultApplicationGroup_TrustList_Size_Variable_);
        setServerVariable(defaultApplicationGroup_TrustList_UserWritable_Variable_);
        setServerVariable(defaultApplicationGroup_TrustList_Writable_Variable_);
        setServerVariable(defaultHttpsGroup_CertificateTypes_Variable_);
        setServerVariable(defaultHttpsGroup_TrustList_LastUpdateTime_Variable_);
        setServerVariable(defaultHttpsGroup_TrustList_OpenCount_Variable_);
        setServerVariable(defaultHttpsGroup_TrustList_Size_Variable_);
        setServerVariable(defaultHttpsGroup_TrustList_UserWritable_Variable_);
        setServerVariable(defaultHttpsGroup_TrustList_Writable_Variable_);
        setServerVariable(defaultUserTokenGroup_CertificateTypes_Variable_);
        setServerVariable(defaultUserTokenGroup_TrustList_LastUpdateTime_Variable_);
        setServerVariable(defaultUserTokenGroup_TrustList_OpenCount_Variable_);
        setServerVariable(defaultUserTokenGroup_TrustList_Size_Variable_);
        setServerVariable(defaultUserTokenGroup_TrustList_UserWritable_Variable_);
        setServerVariable(defaultUserTokenGroup_TrustList_Writable_Variable_);
        setServerMethod(defaultApplicationGroup_TrustList_Close_Method_);
        setServerMethod(defaultApplicationGroup_TrustList_GetPosition_Method_);
        setServerMethod(defaultApplicationGroup_TrustList_OpenWithMasks_Method_);
        setServerMethod(defaultApplicationGroup_TrustList_Open_Method_);
        setServerMethod(defaultApplicationGroup_TrustList_Read_Method_);
        setServerMethod(defaultApplicationGroup_TrustList_SetPosition_Method_);
        setServerMethod(defaultApplicationGroup_TrustList_Write_Method_);
        setServerMethod(defaultHttpsGroup_TrustList_Close_Method_);
        setServerMethod(defaultHttpsGroup_TrustList_GetPosition_Method_);
        setServerMethod(defaultHttpsGroup_TrustList_OpenWithMasks_Method_);
        setServerMethod(defaultHttpsGroup_TrustList_Open_Method_);
        setServerMethod(defaultHttpsGroup_TrustList_Read_Method_);
        setServerMethod(defaultHttpsGroup_TrustList_SetPosition_Method_);
        setServerMethod(defaultHttpsGroup_TrustList_Write_Method_);
        setServerMethod(defaultUserTokenGroup_TrustList_Close_Method_);
        setServerMethod(defaultUserTokenGroup_TrustList_GetPosition_Method_);
        setServerMethod(defaultUserTokenGroup_TrustList_OpenWithMasks_Method_);
        setServerMethod(defaultUserTokenGroup_TrustList_Open_Method_);
        setServerMethod(defaultUserTokenGroup_TrustList_Read_Method_);
        setServerMethod(defaultUserTokenGroup_TrustList_SetPosition_Method_);
        setServerMethod(defaultUserTokenGroup_TrustList_Write_Method_);
        defaultApplicationGroup_TrustList_Close_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultApplicationGroup_TrustList_Close_Method, this, _1));
        defaultApplicationGroup_TrustList_GetPosition_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultApplicationGroup_TrustList_GetPosition_Method, this, _1));
        defaultApplicationGroup_TrustList_OpenWithMasks_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultApplicationGroup_TrustList_OpenWithMasks_Method, this, _1));
        defaultApplicationGroup_TrustList_Open_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultApplicationGroup_TrustList_Open_Method, this, _1));
        defaultApplicationGroup_TrustList_Read_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultApplicationGroup_TrustList_Read_Method, this, _1));
        defaultApplicationGroup_TrustList_SetPosition_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultApplicationGroup_TrustList_SetPosition_Method, this, _1));
        defaultApplicationGroup_TrustList_Write_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultApplicationGroup_TrustList_Write_Method, this, _1));
        defaultHttpsGroup_TrustList_Close_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultHttpsGroup_TrustList_Close_Method, this, _1));
        defaultHttpsGroup_TrustList_GetPosition_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultHttpsGroup_TrustList_GetPosition_Method, this, _1));
        defaultHttpsGroup_TrustList_OpenWithMasks_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultHttpsGroup_TrustList_OpenWithMasks_Method, this, _1));
        defaultHttpsGroup_TrustList_Open_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultHttpsGroup_TrustList_Open_Method, this, _1));
        defaultHttpsGroup_TrustList_Read_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultHttpsGroup_TrustList_Read_Method, this, _1));
        defaultHttpsGroup_TrustList_SetPosition_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultHttpsGroup_TrustList_SetPosition_Method, this, _1));
        defaultHttpsGroup_TrustList_Write_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultHttpsGroup_TrustList_Write_Method, this, _1));
        defaultUserTokenGroup_TrustList_Close_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultUserTokenGroup_TrustList_Close_Method, this, _1));
        defaultUserTokenGroup_TrustList_GetPosition_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultUserTokenGroup_TrustList_GetPosition_Method, this, _1));
        defaultUserTokenGroup_TrustList_OpenWithMasks_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultUserTokenGroup_TrustList_OpenWithMasks_Method, this, _1));
        defaultUserTokenGroup_TrustList_Open_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultUserTokenGroup_TrustList_Open_Method, this, _1));
        defaultUserTokenGroup_TrustList_Read_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultUserTokenGroup_TrustList_Read_Method, this, _1));
        defaultUserTokenGroup_TrustList_SetPosition_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultUserTokenGroup_TrustList_SetPosition_Method, this, _1));
        defaultUserTokenGroup_TrustList_Write_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultUserTokenGroup_TrustList_Write_Method, this, _1));
    }
    
    CertificateGroupFolderType::CertificateGroupFolderType(const CertificateGroupFolderType& value)
    : ObjectBase()
    , defaultApplicationGroup_CertificateTypes_Variable_(boost::make_shared<ServerVariable>("DefaultApplicationGroup_CertificateTypes_Variable"))
    , defaultApplicationGroup_TrustList_LastUpdateTime_Variable_(boost::make_shared<ServerVariable>("DefaultApplicationGroup_TrustList_LastUpdateTime_Variable"))
    , defaultApplicationGroup_TrustList_OpenCount_Variable_(boost::make_shared<ServerVariable>("DefaultApplicationGroup_TrustList_OpenCount_Variable"))
    , defaultApplicationGroup_TrustList_Size_Variable_(boost::make_shared<ServerVariable>("DefaultApplicationGroup_TrustList_Size_Variable"))
    , defaultApplicationGroup_TrustList_UserWritable_Variable_(boost::make_shared<ServerVariable>("DefaultApplicationGroup_TrustList_UserWritable_Variable"))
    , defaultApplicationGroup_TrustList_Writable_Variable_(boost::make_shared<ServerVariable>("DefaultApplicationGroup_TrustList_Writable_Variable"))
    , defaultHttpsGroup_CertificateTypes_Variable_(boost::make_shared<ServerVariable>("DefaultHttpsGroup_CertificateTypes_Variable"))
    , defaultHttpsGroup_TrustList_LastUpdateTime_Variable_(boost::make_shared<ServerVariable>("DefaultHttpsGroup_TrustList_LastUpdateTime_Variable"))
    , defaultHttpsGroup_TrustList_OpenCount_Variable_(boost::make_shared<ServerVariable>("DefaultHttpsGroup_TrustList_OpenCount_Variable"))
    , defaultHttpsGroup_TrustList_Size_Variable_(boost::make_shared<ServerVariable>("DefaultHttpsGroup_TrustList_Size_Variable"))
    , defaultHttpsGroup_TrustList_UserWritable_Variable_(boost::make_shared<ServerVariable>("DefaultHttpsGroup_TrustList_UserWritable_Variable"))
    , defaultHttpsGroup_TrustList_Writable_Variable_(boost::make_shared<ServerVariable>("DefaultHttpsGroup_TrustList_Writable_Variable"))
    , defaultUserTokenGroup_CertificateTypes_Variable_(boost::make_shared<ServerVariable>("DefaultUserTokenGroup_CertificateTypes_Variable"))
    , defaultUserTokenGroup_TrustList_LastUpdateTime_Variable_(boost::make_shared<ServerVariable>("DefaultUserTokenGroup_TrustList_LastUpdateTime_Variable"))
    , defaultUserTokenGroup_TrustList_OpenCount_Variable_(boost::make_shared<ServerVariable>("DefaultUserTokenGroup_TrustList_OpenCount_Variable"))
    , defaultUserTokenGroup_TrustList_Size_Variable_(boost::make_shared<ServerVariable>("DefaultUserTokenGroup_TrustList_Size_Variable"))
    , defaultUserTokenGroup_TrustList_UserWritable_Variable_(boost::make_shared<ServerVariable>("DefaultUserTokenGroup_TrustList_UserWritable_Variable"))
    , defaultUserTokenGroup_TrustList_Writable_Variable_(boost::make_shared<ServerVariable>("DefaultUserTokenGroup_TrustList_Writable_Variable"))
    , defaultApplicationGroup_TrustList_Close_Method_(boost::make_shared<ServerMethod>("DefaultApplicationGroup_TrustList_Close_Method"))
    , defaultApplicationGroup_TrustList_GetPosition_Method_(boost::make_shared<ServerMethod>("DefaultApplicationGroup_TrustList_GetPosition_Method"))
    , defaultApplicationGroup_TrustList_OpenWithMasks_Method_(boost::make_shared<ServerMethod>("DefaultApplicationGroup_TrustList_OpenWithMasks_Method"))
    , defaultApplicationGroup_TrustList_Open_Method_(boost::make_shared<ServerMethod>("DefaultApplicationGroup_TrustList_Open_Method"))
    , defaultApplicationGroup_TrustList_Read_Method_(boost::make_shared<ServerMethod>("DefaultApplicationGroup_TrustList_Read_Method"))
    , defaultApplicationGroup_TrustList_SetPosition_Method_(boost::make_shared<ServerMethod>("DefaultApplicationGroup_TrustList_SetPosition_Method"))
    , defaultApplicationGroup_TrustList_Write_Method_(boost::make_shared<ServerMethod>("DefaultApplicationGroup_TrustList_Write_Method"))
    , defaultHttpsGroup_TrustList_Close_Method_(boost::make_shared<ServerMethod>("DefaultHttpsGroup_TrustList_Close_Method"))
    , defaultHttpsGroup_TrustList_GetPosition_Method_(boost::make_shared<ServerMethod>("DefaultHttpsGroup_TrustList_GetPosition_Method"))
    , defaultHttpsGroup_TrustList_OpenWithMasks_Method_(boost::make_shared<ServerMethod>("DefaultHttpsGroup_TrustList_OpenWithMasks_Method"))
    , defaultHttpsGroup_TrustList_Open_Method_(boost::make_shared<ServerMethod>("DefaultHttpsGroup_TrustList_Open_Method"))
    , defaultHttpsGroup_TrustList_Read_Method_(boost::make_shared<ServerMethod>("DefaultHttpsGroup_TrustList_Read_Method"))
    , defaultHttpsGroup_TrustList_SetPosition_Method_(boost::make_shared<ServerMethod>("DefaultHttpsGroup_TrustList_SetPosition_Method"))
    , defaultHttpsGroup_TrustList_Write_Method_(boost::make_shared<ServerMethod>("DefaultHttpsGroup_TrustList_Write_Method"))
    , defaultUserTokenGroup_TrustList_Close_Method_(boost::make_shared<ServerMethod>("DefaultUserTokenGroup_TrustList_Close_Method"))
    , defaultUserTokenGroup_TrustList_GetPosition_Method_(boost::make_shared<ServerMethod>("DefaultUserTokenGroup_TrustList_GetPosition_Method"))
    , defaultUserTokenGroup_TrustList_OpenWithMasks_Method_(boost::make_shared<ServerMethod>("DefaultUserTokenGroup_TrustList_OpenWithMasks_Method"))
    , defaultUserTokenGroup_TrustList_Open_Method_(boost::make_shared<ServerMethod>("DefaultUserTokenGroup_TrustList_Open_Method"))
    , defaultUserTokenGroup_TrustList_Read_Method_(boost::make_shared<ServerMethod>("DefaultUserTokenGroup_TrustList_Read_Method"))
    , defaultUserTokenGroup_TrustList_SetPosition_Method_(boost::make_shared<ServerMethod>("DefaultUserTokenGroup_TrustList_SetPosition_Method"))
    , defaultUserTokenGroup_TrustList_Write_Method_(boost::make_shared<ServerMethod>("DefaultUserTokenGroup_TrustList_Write_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)13813);
        setServerVariable(defaultApplicationGroup_CertificateTypes_Variable_);
        setServerVariable(defaultApplicationGroup_TrustList_LastUpdateTime_Variable_);
        setServerVariable(defaultApplicationGroup_TrustList_OpenCount_Variable_);
        setServerVariable(defaultApplicationGroup_TrustList_Size_Variable_);
        setServerVariable(defaultApplicationGroup_TrustList_UserWritable_Variable_);
        setServerVariable(defaultApplicationGroup_TrustList_Writable_Variable_);
        setServerVariable(defaultHttpsGroup_CertificateTypes_Variable_);
        setServerVariable(defaultHttpsGroup_TrustList_LastUpdateTime_Variable_);
        setServerVariable(defaultHttpsGroup_TrustList_OpenCount_Variable_);
        setServerVariable(defaultHttpsGroup_TrustList_Size_Variable_);
        setServerVariable(defaultHttpsGroup_TrustList_UserWritable_Variable_);
        setServerVariable(defaultHttpsGroup_TrustList_Writable_Variable_);
        setServerVariable(defaultUserTokenGroup_CertificateTypes_Variable_);
        setServerVariable(defaultUserTokenGroup_TrustList_LastUpdateTime_Variable_);
        setServerVariable(defaultUserTokenGroup_TrustList_OpenCount_Variable_);
        setServerVariable(defaultUserTokenGroup_TrustList_Size_Variable_);
        setServerVariable(defaultUserTokenGroup_TrustList_UserWritable_Variable_);
        setServerVariable(defaultUserTokenGroup_TrustList_Writable_Variable_);
        setServerMethod(defaultApplicationGroup_TrustList_Close_Method_);
        setServerMethod(defaultApplicationGroup_TrustList_GetPosition_Method_);
        setServerMethod(defaultApplicationGroup_TrustList_OpenWithMasks_Method_);
        setServerMethod(defaultApplicationGroup_TrustList_Open_Method_);
        setServerMethod(defaultApplicationGroup_TrustList_Read_Method_);
        setServerMethod(defaultApplicationGroup_TrustList_SetPosition_Method_);
        setServerMethod(defaultApplicationGroup_TrustList_Write_Method_);
        setServerMethod(defaultHttpsGroup_TrustList_Close_Method_);
        setServerMethod(defaultHttpsGroup_TrustList_GetPosition_Method_);
        setServerMethod(defaultHttpsGroup_TrustList_OpenWithMasks_Method_);
        setServerMethod(defaultHttpsGroup_TrustList_Open_Method_);
        setServerMethod(defaultHttpsGroup_TrustList_Read_Method_);
        setServerMethod(defaultHttpsGroup_TrustList_SetPosition_Method_);
        setServerMethod(defaultHttpsGroup_TrustList_Write_Method_);
        setServerMethod(defaultUserTokenGroup_TrustList_Close_Method_);
        setServerMethod(defaultUserTokenGroup_TrustList_GetPosition_Method_);
        setServerMethod(defaultUserTokenGroup_TrustList_OpenWithMasks_Method_);
        setServerMethod(defaultUserTokenGroup_TrustList_Open_Method_);
        setServerMethod(defaultUserTokenGroup_TrustList_Read_Method_);
        setServerMethod(defaultUserTokenGroup_TrustList_SetPosition_Method_);
        setServerMethod(defaultUserTokenGroup_TrustList_Write_Method_);
        defaultApplicationGroup_TrustList_Close_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultApplicationGroup_TrustList_Close_Method, this, _1));
        defaultApplicationGroup_TrustList_GetPosition_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultApplicationGroup_TrustList_GetPosition_Method, this, _1));
        defaultApplicationGroup_TrustList_OpenWithMasks_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultApplicationGroup_TrustList_OpenWithMasks_Method, this, _1));
        defaultApplicationGroup_TrustList_Open_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultApplicationGroup_TrustList_Open_Method, this, _1));
        defaultApplicationGroup_TrustList_Read_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultApplicationGroup_TrustList_Read_Method, this, _1));
        defaultApplicationGroup_TrustList_SetPosition_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultApplicationGroup_TrustList_SetPosition_Method, this, _1));
        defaultApplicationGroup_TrustList_Write_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultApplicationGroup_TrustList_Write_Method, this, _1));
        defaultHttpsGroup_TrustList_Close_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultHttpsGroup_TrustList_Close_Method, this, _1));
        defaultHttpsGroup_TrustList_GetPosition_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultHttpsGroup_TrustList_GetPosition_Method, this, _1));
        defaultHttpsGroup_TrustList_OpenWithMasks_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultHttpsGroup_TrustList_OpenWithMasks_Method, this, _1));
        defaultHttpsGroup_TrustList_Open_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultHttpsGroup_TrustList_Open_Method, this, _1));
        defaultHttpsGroup_TrustList_Read_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultHttpsGroup_TrustList_Read_Method, this, _1));
        defaultHttpsGroup_TrustList_SetPosition_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultHttpsGroup_TrustList_SetPosition_Method, this, _1));
        defaultHttpsGroup_TrustList_Write_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultHttpsGroup_TrustList_Write_Method, this, _1));
        defaultUserTokenGroup_TrustList_Close_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultUserTokenGroup_TrustList_Close_Method, this, _1));
        defaultUserTokenGroup_TrustList_GetPosition_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultUserTokenGroup_TrustList_GetPosition_Method, this, _1));
        defaultUserTokenGroup_TrustList_OpenWithMasks_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultUserTokenGroup_TrustList_OpenWithMasks_Method, this, _1));
        defaultUserTokenGroup_TrustList_Open_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultUserTokenGroup_TrustList_Open_Method, this, _1));
        defaultUserTokenGroup_TrustList_Read_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultUserTokenGroup_TrustList_Read_Method, this, _1));
        defaultUserTokenGroup_TrustList_SetPosition_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultUserTokenGroup_TrustList_SetPosition_Method, this, _1));
        defaultUserTokenGroup_TrustList_Write_Method_->registerMethod(boost::bind(&CertificateGroupFolderType::call_DefaultUserTokenGroup_TrustList_Write_Method, this, _1));
    }
    
    CertificateGroupFolderType::~CertificateGroupFolderType(void)
    {
    }

    ServerVariable::SPtr&
    CertificateGroupFolderType::defaultApplicationGroup_CertificateTypes_Variable(void)
    {
        return defaultApplicationGroup_CertificateTypes_Variable_;
    }

    ServerVariable::SPtr&
    CertificateGroupFolderType::defaultApplicationGroup_TrustList_LastUpdateTime_Variable(void)
    {
        return defaultApplicationGroup_TrustList_LastUpdateTime_Variable_;
    }

    ServerVariable::SPtr&
    CertificateGroupFolderType::defaultApplicationGroup_TrustList_OpenCount_Variable(void)
    {
        return defaultApplicationGroup_TrustList_OpenCount_Variable_;
    }

    ServerVariable::SPtr&
    CertificateGroupFolderType::defaultApplicationGroup_TrustList_Size_Variable(void)
    {
        return defaultApplicationGroup_TrustList_Size_Variable_;
    }

    ServerVariable::SPtr&
    CertificateGroupFolderType::defaultApplicationGroup_TrustList_UserWritable_Variable(void)
    {
        return defaultApplicationGroup_TrustList_UserWritable_Variable_;
    }

    ServerVariable::SPtr&
    CertificateGroupFolderType::defaultApplicationGroup_TrustList_Writable_Variable(void)
    {
        return defaultApplicationGroup_TrustList_Writable_Variable_;
    }

    ServerVariable::SPtr&
    CertificateGroupFolderType::defaultHttpsGroup_CertificateTypes_Variable(void)
    {
        return defaultHttpsGroup_CertificateTypes_Variable_;
    }

    ServerVariable::SPtr&
    CertificateGroupFolderType::defaultHttpsGroup_TrustList_LastUpdateTime_Variable(void)
    {
        return defaultHttpsGroup_TrustList_LastUpdateTime_Variable_;
    }

    ServerVariable::SPtr&
    CertificateGroupFolderType::defaultHttpsGroup_TrustList_OpenCount_Variable(void)
    {
        return defaultHttpsGroup_TrustList_OpenCount_Variable_;
    }

    ServerVariable::SPtr&
    CertificateGroupFolderType::defaultHttpsGroup_TrustList_Size_Variable(void)
    {
        return defaultHttpsGroup_TrustList_Size_Variable_;
    }

    ServerVariable::SPtr&
    CertificateGroupFolderType::defaultHttpsGroup_TrustList_UserWritable_Variable(void)
    {
        return defaultHttpsGroup_TrustList_UserWritable_Variable_;
    }

    ServerVariable::SPtr&
    CertificateGroupFolderType::defaultHttpsGroup_TrustList_Writable_Variable(void)
    {
        return defaultHttpsGroup_TrustList_Writable_Variable_;
    }

    ServerVariable::SPtr&
    CertificateGroupFolderType::defaultUserTokenGroup_CertificateTypes_Variable(void)
    {
        return defaultUserTokenGroup_CertificateTypes_Variable_;
    }

    ServerVariable::SPtr&
    CertificateGroupFolderType::defaultUserTokenGroup_TrustList_LastUpdateTime_Variable(void)
    {
        return defaultUserTokenGroup_TrustList_LastUpdateTime_Variable_;
    }

    ServerVariable::SPtr&
    CertificateGroupFolderType::defaultUserTokenGroup_TrustList_OpenCount_Variable(void)
    {
        return defaultUserTokenGroup_TrustList_OpenCount_Variable_;
    }

    ServerVariable::SPtr&
    CertificateGroupFolderType::defaultUserTokenGroup_TrustList_Size_Variable(void)
    {
        return defaultUserTokenGroup_TrustList_Size_Variable_;
    }

    ServerVariable::SPtr&
    CertificateGroupFolderType::defaultUserTokenGroup_TrustList_UserWritable_Variable(void)
    {
        return defaultUserTokenGroup_TrustList_UserWritable_Variable_;
    }

    ServerVariable::SPtr&
    CertificateGroupFolderType::defaultUserTokenGroup_TrustList_Writable_Variable(void)
    {
        return defaultUserTokenGroup_TrustList_Writable_Variable_;
    }

    void
    CertificateGroupFolderType::defaultApplicationGroup_CertificateTypes_Variable(ServerVariable::SPtr& serverVariable)
    {
        defaultApplicationGroup_CertificateTypes_Variable_ = serverVariable;
    }

    void
    CertificateGroupFolderType::defaultApplicationGroup_TrustList_LastUpdateTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        defaultApplicationGroup_TrustList_LastUpdateTime_Variable_ = serverVariable;
    }

    void
    CertificateGroupFolderType::defaultApplicationGroup_TrustList_OpenCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        defaultApplicationGroup_TrustList_OpenCount_Variable_ = serverVariable;
    }

    void
    CertificateGroupFolderType::defaultApplicationGroup_TrustList_Size_Variable(ServerVariable::SPtr& serverVariable)
    {
        defaultApplicationGroup_TrustList_Size_Variable_ = serverVariable;
    }

    void
    CertificateGroupFolderType::defaultApplicationGroup_TrustList_UserWritable_Variable(ServerVariable::SPtr& serverVariable)
    {
        defaultApplicationGroup_TrustList_UserWritable_Variable_ = serverVariable;
    }

    void
    CertificateGroupFolderType::defaultApplicationGroup_TrustList_Writable_Variable(ServerVariable::SPtr& serverVariable)
    {
        defaultApplicationGroup_TrustList_Writable_Variable_ = serverVariable;
    }

    void
    CertificateGroupFolderType::defaultHttpsGroup_CertificateTypes_Variable(ServerVariable::SPtr& serverVariable)
    {
        defaultHttpsGroup_CertificateTypes_Variable_ = serverVariable;
    }

    void
    CertificateGroupFolderType::defaultHttpsGroup_TrustList_LastUpdateTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        defaultHttpsGroup_TrustList_LastUpdateTime_Variable_ = serverVariable;
    }

    void
    CertificateGroupFolderType::defaultHttpsGroup_TrustList_OpenCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        defaultHttpsGroup_TrustList_OpenCount_Variable_ = serverVariable;
    }

    void
    CertificateGroupFolderType::defaultHttpsGroup_TrustList_Size_Variable(ServerVariable::SPtr& serverVariable)
    {
        defaultHttpsGroup_TrustList_Size_Variable_ = serverVariable;
    }

    void
    CertificateGroupFolderType::defaultHttpsGroup_TrustList_UserWritable_Variable(ServerVariable::SPtr& serverVariable)
    {
        defaultHttpsGroup_TrustList_UserWritable_Variable_ = serverVariable;
    }

    void
    CertificateGroupFolderType::defaultHttpsGroup_TrustList_Writable_Variable(ServerVariable::SPtr& serverVariable)
    {
        defaultHttpsGroup_TrustList_Writable_Variable_ = serverVariable;
    }

    void
    CertificateGroupFolderType::defaultUserTokenGroup_CertificateTypes_Variable(ServerVariable::SPtr& serverVariable)
    {
        defaultUserTokenGroup_CertificateTypes_Variable_ = serverVariable;
    }

    void
    CertificateGroupFolderType::defaultUserTokenGroup_TrustList_LastUpdateTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        defaultUserTokenGroup_TrustList_LastUpdateTime_Variable_ = serverVariable;
    }

    void
    CertificateGroupFolderType::defaultUserTokenGroup_TrustList_OpenCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        defaultUserTokenGroup_TrustList_OpenCount_Variable_ = serverVariable;
    }

    void
    CertificateGroupFolderType::defaultUserTokenGroup_TrustList_Size_Variable(ServerVariable::SPtr& serverVariable)
    {
        defaultUserTokenGroup_TrustList_Size_Variable_ = serverVariable;
    }

    void
    CertificateGroupFolderType::defaultUserTokenGroup_TrustList_UserWritable_Variable(ServerVariable::SPtr& serverVariable)
    {
        defaultUserTokenGroup_TrustList_UserWritable_Variable_ = serverVariable;
    }

    void
    CertificateGroupFolderType::defaultUserTokenGroup_TrustList_Writable_Variable(ServerVariable::SPtr& serverVariable)
    {
        defaultUserTokenGroup_TrustList_Writable_Variable_ = serverVariable;
    }

    bool
    CertificateGroupFolderType::get_DefaultApplicationGroup_CertificateTypes_Variable(OpcUaDataValue& dataValue)
    {
        return defaultApplicationGroup_CertificateTypes_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateGroupFolderType::get_DefaultApplicationGroup_TrustList_LastUpdateTime_Variable(OpcUaDataValue& dataValue)
    {
        return defaultApplicationGroup_TrustList_LastUpdateTime_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateGroupFolderType::get_DefaultApplicationGroup_TrustList_OpenCount_Variable(OpcUaDataValue& dataValue)
    {
        return defaultApplicationGroup_TrustList_OpenCount_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateGroupFolderType::get_DefaultApplicationGroup_TrustList_Size_Variable(OpcUaDataValue& dataValue)
    {
        return defaultApplicationGroup_TrustList_Size_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateGroupFolderType::get_DefaultApplicationGroup_TrustList_UserWritable_Variable(OpcUaDataValue& dataValue)
    {
        return defaultApplicationGroup_TrustList_UserWritable_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateGroupFolderType::get_DefaultApplicationGroup_TrustList_Writable_Variable(OpcUaDataValue& dataValue)
    {
        return defaultApplicationGroup_TrustList_Writable_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateGroupFolderType::get_DefaultHttpsGroup_CertificateTypes_Variable(OpcUaDataValue& dataValue)
    {
        return defaultHttpsGroup_CertificateTypes_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateGroupFolderType::get_DefaultHttpsGroup_TrustList_LastUpdateTime_Variable(OpcUaDataValue& dataValue)
    {
        return defaultHttpsGroup_TrustList_LastUpdateTime_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateGroupFolderType::get_DefaultHttpsGroup_TrustList_OpenCount_Variable(OpcUaDataValue& dataValue)
    {
        return defaultHttpsGroup_TrustList_OpenCount_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateGroupFolderType::get_DefaultHttpsGroup_TrustList_Size_Variable(OpcUaDataValue& dataValue)
    {
        return defaultHttpsGroup_TrustList_Size_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateGroupFolderType::get_DefaultHttpsGroup_TrustList_UserWritable_Variable(OpcUaDataValue& dataValue)
    {
        return defaultHttpsGroup_TrustList_UserWritable_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateGroupFolderType::get_DefaultHttpsGroup_TrustList_Writable_Variable(OpcUaDataValue& dataValue)
    {
        return defaultHttpsGroup_TrustList_Writable_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateGroupFolderType::get_DefaultUserTokenGroup_CertificateTypes_Variable(OpcUaDataValue& dataValue)
    {
        return defaultUserTokenGroup_CertificateTypes_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateGroupFolderType::get_DefaultUserTokenGroup_TrustList_LastUpdateTime_Variable(OpcUaDataValue& dataValue)
    {
        return defaultUserTokenGroup_TrustList_LastUpdateTime_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateGroupFolderType::get_DefaultUserTokenGroup_TrustList_OpenCount_Variable(OpcUaDataValue& dataValue)
    {
        return defaultUserTokenGroup_TrustList_OpenCount_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateGroupFolderType::get_DefaultUserTokenGroup_TrustList_Size_Variable(OpcUaDataValue& dataValue)
    {
        return defaultUserTokenGroup_TrustList_Size_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateGroupFolderType::get_DefaultUserTokenGroup_TrustList_UserWritable_Variable(OpcUaDataValue& dataValue)
    {
        return defaultUserTokenGroup_TrustList_UserWritable_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateGroupFolderType::get_DefaultUserTokenGroup_TrustList_Writable_Variable(OpcUaDataValue& dataValue)
    {
        return defaultUserTokenGroup_TrustList_Writable_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateGroupFolderType::set_DefaultApplicationGroup_CertificateTypes_Variable(const OpcUaDataValue& dataValue)
    {
        return defaultApplicationGroup_CertificateTypes_Variable_->setDataValue(dataValue);
    }

    bool
    CertificateGroupFolderType::set_DefaultApplicationGroup_TrustList_LastUpdateTime_Variable(const OpcUaDataValue& dataValue)
    {
        return defaultApplicationGroup_TrustList_LastUpdateTime_Variable_->setDataValue(dataValue);
    }

    bool
    CertificateGroupFolderType::set_DefaultApplicationGroup_TrustList_OpenCount_Variable(const OpcUaDataValue& dataValue)
    {
        return defaultApplicationGroup_TrustList_OpenCount_Variable_->setDataValue(dataValue);
    }

    bool
    CertificateGroupFolderType::set_DefaultApplicationGroup_TrustList_Size_Variable(const OpcUaDataValue& dataValue)
    {
        return defaultApplicationGroup_TrustList_Size_Variable_->setDataValue(dataValue);
    }

    bool
    CertificateGroupFolderType::set_DefaultApplicationGroup_TrustList_UserWritable_Variable(const OpcUaDataValue& dataValue)
    {
        return defaultApplicationGroup_TrustList_UserWritable_Variable_->setDataValue(dataValue);
    }

    bool
    CertificateGroupFolderType::set_DefaultApplicationGroup_TrustList_Writable_Variable(const OpcUaDataValue& dataValue)
    {
        return defaultApplicationGroup_TrustList_Writable_Variable_->setDataValue(dataValue);
    }

    bool
    CertificateGroupFolderType::set_DefaultHttpsGroup_CertificateTypes_Variable(const OpcUaDataValue& dataValue)
    {
        return defaultHttpsGroup_CertificateTypes_Variable_->setDataValue(dataValue);
    }

    bool
    CertificateGroupFolderType::set_DefaultHttpsGroup_TrustList_LastUpdateTime_Variable(const OpcUaDataValue& dataValue)
    {
        return defaultHttpsGroup_TrustList_LastUpdateTime_Variable_->setDataValue(dataValue);
    }

    bool
    CertificateGroupFolderType::set_DefaultHttpsGroup_TrustList_OpenCount_Variable(const OpcUaDataValue& dataValue)
    {
        return defaultHttpsGroup_TrustList_OpenCount_Variable_->setDataValue(dataValue);
    }

    bool
    CertificateGroupFolderType::set_DefaultHttpsGroup_TrustList_Size_Variable(const OpcUaDataValue& dataValue)
    {
        return defaultHttpsGroup_TrustList_Size_Variable_->setDataValue(dataValue);
    }

    bool
    CertificateGroupFolderType::set_DefaultHttpsGroup_TrustList_UserWritable_Variable(const OpcUaDataValue& dataValue)
    {
        return defaultHttpsGroup_TrustList_UserWritable_Variable_->setDataValue(dataValue);
    }

    bool
    CertificateGroupFolderType::set_DefaultHttpsGroup_TrustList_Writable_Variable(const OpcUaDataValue& dataValue)
    {
        return defaultHttpsGroup_TrustList_Writable_Variable_->setDataValue(dataValue);
    }

    bool
    CertificateGroupFolderType::set_DefaultUserTokenGroup_CertificateTypes_Variable(const OpcUaDataValue& dataValue)
    {
        return defaultUserTokenGroup_CertificateTypes_Variable_->setDataValue(dataValue);
    }

    bool
    CertificateGroupFolderType::set_DefaultUserTokenGroup_TrustList_LastUpdateTime_Variable(const OpcUaDataValue& dataValue)
    {
        return defaultUserTokenGroup_TrustList_LastUpdateTime_Variable_->setDataValue(dataValue);
    }

    bool
    CertificateGroupFolderType::set_DefaultUserTokenGroup_TrustList_OpenCount_Variable(const OpcUaDataValue& dataValue)
    {
        return defaultUserTokenGroup_TrustList_OpenCount_Variable_->setDataValue(dataValue);
    }

    bool
    CertificateGroupFolderType::set_DefaultUserTokenGroup_TrustList_Size_Variable(const OpcUaDataValue& dataValue)
    {
        return defaultUserTokenGroup_TrustList_Size_Variable_->setDataValue(dataValue);
    }

    bool
    CertificateGroupFolderType::set_DefaultUserTokenGroup_TrustList_UserWritable_Variable(const OpcUaDataValue& dataValue)
    {
        return defaultUserTokenGroup_TrustList_UserWritable_Variable_->setDataValue(dataValue);
    }

    bool
    CertificateGroupFolderType::set_DefaultUserTokenGroup_TrustList_Writable_Variable(const OpcUaDataValue& dataValue)
    {
        return defaultUserTokenGroup_TrustList_Writable_Variable_->setDataValue(dataValue);
    }

    void
    CertificateGroupFolderType::call_DefaultApplicationGroup_TrustList_Close_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    CertificateGroupFolderType::call_DefaultApplicationGroup_TrustList_GetPosition_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    CertificateGroupFolderType::call_DefaultApplicationGroup_TrustList_OpenWithMasks_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    CertificateGroupFolderType::call_DefaultApplicationGroup_TrustList_Open_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    CertificateGroupFolderType::call_DefaultApplicationGroup_TrustList_Read_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    CertificateGroupFolderType::call_DefaultApplicationGroup_TrustList_SetPosition_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    CertificateGroupFolderType::call_DefaultApplicationGroup_TrustList_Write_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    CertificateGroupFolderType::call_DefaultHttpsGroup_TrustList_Close_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    CertificateGroupFolderType::call_DefaultHttpsGroup_TrustList_GetPosition_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    CertificateGroupFolderType::call_DefaultHttpsGroup_TrustList_OpenWithMasks_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    CertificateGroupFolderType::call_DefaultHttpsGroup_TrustList_Open_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    CertificateGroupFolderType::call_DefaultHttpsGroup_TrustList_Read_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    CertificateGroupFolderType::call_DefaultHttpsGroup_TrustList_SetPosition_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    CertificateGroupFolderType::call_DefaultHttpsGroup_TrustList_Write_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    CertificateGroupFolderType::call_DefaultUserTokenGroup_TrustList_Close_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    CertificateGroupFolderType::call_DefaultUserTokenGroup_TrustList_GetPosition_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    CertificateGroupFolderType::call_DefaultUserTokenGroup_TrustList_OpenWithMasks_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    CertificateGroupFolderType::call_DefaultUserTokenGroup_TrustList_Open_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    CertificateGroupFolderType::call_DefaultUserTokenGroup_TrustList_Read_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    CertificateGroupFolderType::call_DefaultUserTokenGroup_TrustList_SetPosition_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    CertificateGroupFolderType::call_DefaultUserTokenGroup_TrustList_Write_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

}
