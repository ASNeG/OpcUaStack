/*
    VariableTypeClass: TrustListType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/TrustListType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    TrustListType::TrustListType(void)
    : ObjectBase()
    , lastUpdateTime_Variable_(boost::make_shared<ServerVariable>("LastUpdateTime_Variable"))
    , mimeType_Variable_(boost::make_shared<ServerVariable>("MimeType_Variable"))
    , openCount_Variable_(boost::make_shared<ServerVariable>("OpenCount_Variable"))
    , size_Variable_(boost::make_shared<ServerVariable>("Size_Variable"))
    , userWritable_Variable_(boost::make_shared<ServerVariable>("UserWritable_Variable"))
    , writable_Variable_(boost::make_shared<ServerVariable>("Writable_Variable"))
    , addCertificate_Method_(boost::make_shared<ServerMethod>("AddCertificate_Method"))
    , closeAndUpdate_Method_(boost::make_shared<ServerMethod>("CloseAndUpdate_Method"))
    , close_Method_(boost::make_shared<ServerMethod>("Close_Method"))
    , getPosition_Method_(boost::make_shared<ServerMethod>("GetPosition_Method"))
    , openWithMasks_Method_(boost::make_shared<ServerMethod>("OpenWithMasks_Method"))
    , open_Method_(boost::make_shared<ServerMethod>("Open_Method"))
    , read_Method_(boost::make_shared<ServerMethod>("Read_Method"))
    , removeCertificate_Method_(boost::make_shared<ServerMethod>("RemoveCertificate_Method"))
    , setPosition_Method_(boost::make_shared<ServerMethod>("SetPosition_Method"))
    , write_Method_(boost::make_shared<ServerMethod>("Write_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)12522);
        setServerVariable(lastUpdateTime_Variable_);
        setServerVariable(mimeType_Variable_);
        setServerVariable(openCount_Variable_);
        setServerVariable(size_Variable_);
        setServerVariable(userWritable_Variable_);
        setServerVariable(writable_Variable_);
        setServerMethod(addCertificate_Method_);
        setServerMethod(closeAndUpdate_Method_);
        setServerMethod(close_Method_);
        setServerMethod(getPosition_Method_);
        setServerMethod(openWithMasks_Method_);
        setServerMethod(open_Method_);
        setServerMethod(read_Method_);
        setServerMethod(removeCertificate_Method_);
        setServerMethod(setPosition_Method_);
        setServerMethod(write_Method_);
        addCertificate_Method_->registerMethod(boost::bind(&TrustListType::call_AddCertificate_Method, this, boost::placeholders::_1));
        closeAndUpdate_Method_->registerMethod(boost::bind(&TrustListType::call_CloseAndUpdate_Method, this, boost::placeholders::_1));
        close_Method_->registerMethod(boost::bind(&TrustListType::call_Close_Method, this, boost::placeholders::_1));
        getPosition_Method_->registerMethod(boost::bind(&TrustListType::call_GetPosition_Method, this, boost::placeholders::_1));
        openWithMasks_Method_->registerMethod(boost::bind(&TrustListType::call_OpenWithMasks_Method, this, boost::placeholders::_1));
        open_Method_->registerMethod(boost::bind(&TrustListType::call_Open_Method, this, boost::placeholders::_1));
        read_Method_->registerMethod(boost::bind(&TrustListType::call_Read_Method, this, boost::placeholders::_1));
        removeCertificate_Method_->registerMethod(boost::bind(&TrustListType::call_RemoveCertificate_Method, this, boost::placeholders::_1));
        setPosition_Method_->registerMethod(boost::bind(&TrustListType::call_SetPosition_Method, this, boost::placeholders::_1));
        write_Method_->registerMethod(boost::bind(&TrustListType::call_Write_Method, this, boost::placeholders::_1));
    }
    
    TrustListType::TrustListType(const TrustListType& value)
    : ObjectBase()
    , lastUpdateTime_Variable_(boost::make_shared<ServerVariable>("LastUpdateTime_Variable"))
    , mimeType_Variable_(boost::make_shared<ServerVariable>("MimeType_Variable"))
    , openCount_Variable_(boost::make_shared<ServerVariable>("OpenCount_Variable"))
    , size_Variable_(boost::make_shared<ServerVariable>("Size_Variable"))
    , userWritable_Variable_(boost::make_shared<ServerVariable>("UserWritable_Variable"))
    , writable_Variable_(boost::make_shared<ServerVariable>("Writable_Variable"))
    , addCertificate_Method_(boost::make_shared<ServerMethod>("AddCertificate_Method"))
    , closeAndUpdate_Method_(boost::make_shared<ServerMethod>("CloseAndUpdate_Method"))
    , close_Method_(boost::make_shared<ServerMethod>("Close_Method"))
    , getPosition_Method_(boost::make_shared<ServerMethod>("GetPosition_Method"))
    , openWithMasks_Method_(boost::make_shared<ServerMethod>("OpenWithMasks_Method"))
    , open_Method_(boost::make_shared<ServerMethod>("Open_Method"))
    , read_Method_(boost::make_shared<ServerMethod>("Read_Method"))
    , removeCertificate_Method_(boost::make_shared<ServerMethod>("RemoveCertificate_Method"))
    , setPosition_Method_(boost::make_shared<ServerMethod>("SetPosition_Method"))
    , write_Method_(boost::make_shared<ServerMethod>("Write_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)12522);
        setServerVariable(lastUpdateTime_Variable_);
        setServerVariable(mimeType_Variable_);
        setServerVariable(openCount_Variable_);
        setServerVariable(size_Variable_);
        setServerVariable(userWritable_Variable_);
        setServerVariable(writable_Variable_);
        setServerMethod(addCertificate_Method_);
        setServerMethod(closeAndUpdate_Method_);
        setServerMethod(close_Method_);
        setServerMethod(getPosition_Method_);
        setServerMethod(openWithMasks_Method_);
        setServerMethod(open_Method_);
        setServerMethod(read_Method_);
        setServerMethod(removeCertificate_Method_);
        setServerMethod(setPosition_Method_);
        setServerMethod(write_Method_);
        addCertificate_Method_->registerMethod(boost::bind(&TrustListType::call_AddCertificate_Method, this, boost::placeholders::_1));
        closeAndUpdate_Method_->registerMethod(boost::bind(&TrustListType::call_CloseAndUpdate_Method, this, boost::placeholders::_1));
        close_Method_->registerMethod(boost::bind(&TrustListType::call_Close_Method, this, boost::placeholders::_1));
        getPosition_Method_->registerMethod(boost::bind(&TrustListType::call_GetPosition_Method, this, boost::placeholders::_1));
        openWithMasks_Method_->registerMethod(boost::bind(&TrustListType::call_OpenWithMasks_Method, this, boost::placeholders::_1));
        open_Method_->registerMethod(boost::bind(&TrustListType::call_Open_Method, this, boost::placeholders::_1));
        read_Method_->registerMethod(boost::bind(&TrustListType::call_Read_Method, this, boost::placeholders::_1));
        removeCertificate_Method_->registerMethod(boost::bind(&TrustListType::call_RemoveCertificate_Method, this, boost::placeholders::_1));
        setPosition_Method_->registerMethod(boost::bind(&TrustListType::call_SetPosition_Method, this, boost::placeholders::_1));
        write_Method_->registerMethod(boost::bind(&TrustListType::call_Write_Method, this, boost::placeholders::_1));
    }
    
    TrustListType::~TrustListType(void)
    {
    }

    ServerVariable::SPtr&
    TrustListType::lastUpdateTime_Variable(void)
    {
        return lastUpdateTime_Variable_;
    }

    ServerVariable::SPtr&
    TrustListType::mimeType_Variable(void)
    {
        return mimeType_Variable_;
    }

    ServerVariable::SPtr&
    TrustListType::openCount_Variable(void)
    {
        return openCount_Variable_;
    }

    ServerVariable::SPtr&
    TrustListType::size_Variable(void)
    {
        return size_Variable_;
    }

    ServerVariable::SPtr&
    TrustListType::userWritable_Variable(void)
    {
        return userWritable_Variable_;
    }

    ServerVariable::SPtr&
    TrustListType::writable_Variable(void)
    {
        return writable_Variable_;
    }

    void
    TrustListType::lastUpdateTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        lastUpdateTime_Variable_ = serverVariable;
    }

    void
    TrustListType::mimeType_Variable(ServerVariable::SPtr& serverVariable)
    {
        mimeType_Variable_ = serverVariable;
    }

    void
    TrustListType::openCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        openCount_Variable_ = serverVariable;
    }

    void
    TrustListType::size_Variable(ServerVariable::SPtr& serverVariable)
    {
        size_Variable_ = serverVariable;
    }

    void
    TrustListType::userWritable_Variable(ServerVariable::SPtr& serverVariable)
    {
        userWritable_Variable_ = serverVariable;
    }

    void
    TrustListType::writable_Variable(ServerVariable::SPtr& serverVariable)
    {
        writable_Variable_ = serverVariable;
    }

    bool
    TrustListType::get_LastUpdateTime_Variable(OpcUaDataValue& dataValue)
    {
        return lastUpdateTime_Variable_->getDataValue(dataValue);
    }

    bool
    TrustListType::get_MimeType_Variable(OpcUaDataValue& dataValue)
    {
        return mimeType_Variable_->getDataValue(dataValue);
    }

    bool
    TrustListType::get_OpenCount_Variable(OpcUaDataValue& dataValue)
    {
        return openCount_Variable_->getDataValue(dataValue);
    }

    bool
    TrustListType::get_Size_Variable(OpcUaDataValue& dataValue)
    {
        return size_Variable_->getDataValue(dataValue);
    }

    bool
    TrustListType::get_UserWritable_Variable(OpcUaDataValue& dataValue)
    {
        return userWritable_Variable_->getDataValue(dataValue);
    }

    bool
    TrustListType::get_Writable_Variable(OpcUaDataValue& dataValue)
    {
        return writable_Variable_->getDataValue(dataValue);
    }

    bool
    TrustListType::set_LastUpdateTime_Variable(const OpcUaDataValue& dataValue)
    {
        return lastUpdateTime_Variable_->setDataValue(dataValue);
    }

    bool
    TrustListType::set_MimeType_Variable(const OpcUaDataValue& dataValue)
    {
        return mimeType_Variable_->setDataValue(dataValue);
    }

    bool
    TrustListType::set_OpenCount_Variable(const OpcUaDataValue& dataValue)
    {
        return openCount_Variable_->setDataValue(dataValue);
    }

    bool
    TrustListType::set_Size_Variable(const OpcUaDataValue& dataValue)
    {
        return size_Variable_->setDataValue(dataValue);
    }

    bool
    TrustListType::set_UserWritable_Variable(const OpcUaDataValue& dataValue)
    {
        return userWritable_Variable_->setDataValue(dataValue);
    }

    bool
    TrustListType::set_Writable_Variable(const OpcUaDataValue& dataValue)
    {
        return writable_Variable_->setDataValue(dataValue);
    }

    void
    TrustListType::call_AddCertificate_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    TrustListType::call_CloseAndUpdate_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    TrustListType::call_Close_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    TrustListType::call_GetPosition_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    TrustListType::call_OpenWithMasks_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    TrustListType::call_Open_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    TrustListType::call_Read_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    TrustListType::call_RemoveCertificate_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    TrustListType::call_SetPosition_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    TrustListType::call_Write_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

}
