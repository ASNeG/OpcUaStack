/*
    VariableTypeClass: AddressSpaceFileType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/AddressSpaceFileType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    /**
     * A file used to store a namespace exported from the server.
     */
    AddressSpaceFileType::AddressSpaceFileType(void)
    : ObjectBase()
    , mimeType_Variable_(boost::make_shared<ServerVariable>("MimeType_Variable"))
    , openCount_Variable_(boost::make_shared<ServerVariable>("OpenCount_Variable"))
    , size_Variable_(boost::make_shared<ServerVariable>("Size_Variable"))
    , userWritable_Variable_(boost::make_shared<ServerVariable>("UserWritable_Variable"))
    , writable_Variable_(boost::make_shared<ServerVariable>("Writable_Variable"))
    , close_Method_(boost::make_shared<ServerMethod>("Close_Method"))
    , exportNamespace_Method_(boost::make_shared<ServerMethod>("ExportNamespace_Method"))
    , getPosition_Method_(boost::make_shared<ServerMethod>("GetPosition_Method"))
    , open_Method_(boost::make_shared<ServerMethod>("Open_Method"))
    , read_Method_(boost::make_shared<ServerMethod>("Read_Method"))
    , setPosition_Method_(boost::make_shared<ServerMethod>("SetPosition_Method"))
    , write_Method_(boost::make_shared<ServerMethod>("Write_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)11595);
        setServerVariable(mimeType_Variable_);
        setServerVariable(openCount_Variable_);
        setServerVariable(size_Variable_);
        setServerVariable(userWritable_Variable_);
        setServerVariable(writable_Variable_);
        setServerMethod(close_Method_);
        setServerMethod(exportNamespace_Method_);
        setServerMethod(getPosition_Method_);
        setServerMethod(open_Method_);
        setServerMethod(read_Method_);
        setServerMethod(setPosition_Method_);
        setServerMethod(write_Method_);
        close_Method_->registerMethod(boost::bind(&AddressSpaceFileType::call_Close_Method, this, boost::placeholders::_1));
        exportNamespace_Method_->registerMethod(boost::bind(&AddressSpaceFileType::call_ExportNamespace_Method, this, boost::placeholders::_1));
        getPosition_Method_->registerMethod(boost::bind(&AddressSpaceFileType::call_GetPosition_Method, this, boost::placeholders::_1));
        open_Method_->registerMethod(boost::bind(&AddressSpaceFileType::call_Open_Method, this, boost::placeholders::_1));
        read_Method_->registerMethod(boost::bind(&AddressSpaceFileType::call_Read_Method, this, boost::placeholders::_1));
        setPosition_Method_->registerMethod(boost::bind(&AddressSpaceFileType::call_SetPosition_Method, this, boost::placeholders::_1));
        write_Method_->registerMethod(boost::bind(&AddressSpaceFileType::call_Write_Method, this, boost::placeholders::_1));
    }
    
    /**
     * A file used to store a namespace exported from the server.
     */
    AddressSpaceFileType::AddressSpaceFileType(const AddressSpaceFileType& value)
    : ObjectBase()
    , mimeType_Variable_(boost::make_shared<ServerVariable>("MimeType_Variable"))
    , openCount_Variable_(boost::make_shared<ServerVariable>("OpenCount_Variable"))
    , size_Variable_(boost::make_shared<ServerVariable>("Size_Variable"))
    , userWritable_Variable_(boost::make_shared<ServerVariable>("UserWritable_Variable"))
    , writable_Variable_(boost::make_shared<ServerVariable>("Writable_Variable"))
    , close_Method_(boost::make_shared<ServerMethod>("Close_Method"))
    , exportNamespace_Method_(boost::make_shared<ServerMethod>("ExportNamespace_Method"))
    , getPosition_Method_(boost::make_shared<ServerMethod>("GetPosition_Method"))
    , open_Method_(boost::make_shared<ServerMethod>("Open_Method"))
    , read_Method_(boost::make_shared<ServerMethod>("Read_Method"))
    , setPosition_Method_(boost::make_shared<ServerMethod>("SetPosition_Method"))
    , write_Method_(boost::make_shared<ServerMethod>("Write_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)11595);
        setServerVariable(mimeType_Variable_);
        setServerVariable(openCount_Variable_);
        setServerVariable(size_Variable_);
        setServerVariable(userWritable_Variable_);
        setServerVariable(writable_Variable_);
        setServerMethod(close_Method_);
        setServerMethod(exportNamespace_Method_);
        setServerMethod(getPosition_Method_);
        setServerMethod(open_Method_);
        setServerMethod(read_Method_);
        setServerMethod(setPosition_Method_);
        setServerMethod(write_Method_);
        close_Method_->registerMethod(boost::bind(&AddressSpaceFileType::call_Close_Method, this, boost::placeholders::_1));
        exportNamespace_Method_->registerMethod(boost::bind(&AddressSpaceFileType::call_ExportNamespace_Method, this, boost::placeholders::_1));
        getPosition_Method_->registerMethod(boost::bind(&AddressSpaceFileType::call_GetPosition_Method, this, boost::placeholders::_1));
        open_Method_->registerMethod(boost::bind(&AddressSpaceFileType::call_Open_Method, this, boost::placeholders::_1));
        read_Method_->registerMethod(boost::bind(&AddressSpaceFileType::call_Read_Method, this, boost::placeholders::_1));
        setPosition_Method_->registerMethod(boost::bind(&AddressSpaceFileType::call_SetPosition_Method, this, boost::placeholders::_1));
        write_Method_->registerMethod(boost::bind(&AddressSpaceFileType::call_Write_Method, this, boost::placeholders::_1));
    }
    
    AddressSpaceFileType::~AddressSpaceFileType(void)
    {
    }

    ServerVariable::SPtr&
    AddressSpaceFileType::mimeType_Variable(void)
    {
        return mimeType_Variable_;
    }

    ServerVariable::SPtr&
    AddressSpaceFileType::openCount_Variable(void)
    {
        return openCount_Variable_;
    }

    ServerVariable::SPtr&
    AddressSpaceFileType::size_Variable(void)
    {
        return size_Variable_;
    }

    ServerVariable::SPtr&
    AddressSpaceFileType::userWritable_Variable(void)
    {
        return userWritable_Variable_;
    }

    ServerVariable::SPtr&
    AddressSpaceFileType::writable_Variable(void)
    {
        return writable_Variable_;
    }

    void
    AddressSpaceFileType::mimeType_Variable(ServerVariable::SPtr& serverVariable)
    {
        mimeType_Variable_ = serverVariable;
    }

    void
    AddressSpaceFileType::openCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        openCount_Variable_ = serverVariable;
    }

    void
    AddressSpaceFileType::size_Variable(ServerVariable::SPtr& serverVariable)
    {
        size_Variable_ = serverVariable;
    }

    void
    AddressSpaceFileType::userWritable_Variable(ServerVariable::SPtr& serverVariable)
    {
        userWritable_Variable_ = serverVariable;
    }

    void
    AddressSpaceFileType::writable_Variable(ServerVariable::SPtr& serverVariable)
    {
        writable_Variable_ = serverVariable;
    }

    bool
    AddressSpaceFileType::get_MimeType_Variable(OpcUaDataValue& dataValue)
    {
        return mimeType_Variable_->getDataValue(dataValue);
    }

    bool
    AddressSpaceFileType::get_OpenCount_Variable(OpcUaDataValue& dataValue)
    {
        return openCount_Variable_->getDataValue(dataValue);
    }

    bool
    AddressSpaceFileType::get_Size_Variable(OpcUaDataValue& dataValue)
    {
        return size_Variable_->getDataValue(dataValue);
    }

    bool
    AddressSpaceFileType::get_UserWritable_Variable(OpcUaDataValue& dataValue)
    {
        return userWritable_Variable_->getDataValue(dataValue);
    }

    bool
    AddressSpaceFileType::get_Writable_Variable(OpcUaDataValue& dataValue)
    {
        return writable_Variable_->getDataValue(dataValue);
    }

    bool
    AddressSpaceFileType::set_MimeType_Variable(const OpcUaDataValue& dataValue)
    {
        return mimeType_Variable_->setDataValue(dataValue);
    }

    bool
    AddressSpaceFileType::set_OpenCount_Variable(const OpcUaDataValue& dataValue)
    {
        return openCount_Variable_->setDataValue(dataValue);
    }

    bool
    AddressSpaceFileType::set_Size_Variable(const OpcUaDataValue& dataValue)
    {
        return size_Variable_->setDataValue(dataValue);
    }

    bool
    AddressSpaceFileType::set_UserWritable_Variable(const OpcUaDataValue& dataValue)
    {
        return userWritable_Variable_->setDataValue(dataValue);
    }

    bool
    AddressSpaceFileType::set_Writable_Variable(const OpcUaDataValue& dataValue)
    {
        return writable_Variable_->setDataValue(dataValue);
    }

    void
    AddressSpaceFileType::call_Close_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    AddressSpaceFileType::call_ExportNamespace_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    AddressSpaceFileType::call_GetPosition_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    AddressSpaceFileType::call_Open_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    AddressSpaceFileType::call_Read_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    AddressSpaceFileType::call_SetPosition_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    AddressSpaceFileType::call_Write_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

}
