/*
    VariableTypeClass: FileType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/FileType.h"

namespace OpcUaStackServer
{
    
    /**
     * An object that represents a file that can be accessed via the server.
     */
    FileType::FileType(void)
    : ObjectBase()
    , mimeType_Variable_(constructSPtr<ServerVariable>("MimeType_Variable"))
    , openCount_Variable_(constructSPtr<ServerVariable>("OpenCount_Variable"))
    , size_Variable_(constructSPtr<ServerVariable>("Size_Variable"))
    , userWritable_Variable_(constructSPtr<ServerVariable>("UserWritable_Variable"))
    , writable_Variable_(constructSPtr<ServerVariable>("Writable_Variable"))
    , close_Method_(constructSPtr<ServerMethod>("Close_Method"))
    , getPosition_Method_(constructSPtr<ServerMethod>("GetPosition_Method"))
    , open_Method_(constructSPtr<ServerMethod>("Open_Method"))
    , read_Method_(constructSPtr<ServerMethod>("Read_Method"))
    , setPosition_Method_(constructSPtr<ServerMethod>("SetPosition_Method"))
    , write_Method_(constructSPtr<ServerMethod>("Write_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)11575);
        setServerVariable(mimeType_Variable_);
        setServerVariable(openCount_Variable_);
        setServerVariable(size_Variable_);
        setServerVariable(userWritable_Variable_);
        setServerVariable(writable_Variable_);
        setServerMethod(close_Method_);
        setServerMethod(getPosition_Method_);
        setServerMethod(open_Method_);
        setServerMethod(read_Method_);
        setServerMethod(setPosition_Method_);
        setServerMethod(write_Method_);

        close_Method_->registerMethod(boost::bind(&FileType::call_Close_Method, this, _1));
        getPosition_Method_->registerMethod(boost::bind(&FileType::call_GetPosition_Method, this, _1));
        open_Method_->registerMethod(boost::bind(&FileType::call_Open_Method, this, _1));
        read_Method_->registerMethod(boost::bind(&FileType::call_Read_Method, this, _1));
        setPosition_Method_->registerMethod(boost::bind(&FileType::call_SetPosition_Method, this, _1));
        write_Method_->registerMethod(boost::bind(&FileType::call_Write_Method, this, _1));
    }

    /**
     * An object that represents a file that can be accessed via the server.
     */
    FileType::FileType(const FileType& value)
    : ObjectBase()
    , mimeType_Variable_(constructSPtr<ServerVariable>("MimeType_Variable"))
    , openCount_Variable_(constructSPtr<ServerVariable>("OpenCount_Variable"))
    , size_Variable_(constructSPtr<ServerVariable>("Size_Variable"))
    , userWritable_Variable_(constructSPtr<ServerVariable>("UserWritable_Variable"))
    , writable_Variable_(constructSPtr<ServerVariable>("Writable_Variable"))
    , close_Method_(constructSPtr<ServerMethod>("Close_Method"))
    , getPosition_Method_(constructSPtr<ServerMethod>("GetPosition_Method"))
    , open_Method_(constructSPtr<ServerMethod>("Open_Method"))
    , read_Method_(constructSPtr<ServerMethod>("Read_Method"))
    , setPosition_Method_(constructSPtr<ServerMethod>("SetPosition_Method"))
    , write_Method_(constructSPtr<ServerMethod>("Write_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)11575);
        setServerVariable(mimeType_Variable_);
        setServerVariable(openCount_Variable_);
        setServerVariable(size_Variable_);
        setServerVariable(userWritable_Variable_);
        setServerVariable(writable_Variable_);
        setServerMethod(close_Method_);
        setServerMethod(getPosition_Method_);
        setServerMethod(open_Method_);
        setServerMethod(read_Method_);
        setServerMethod(setPosition_Method_);
        setServerMethod(write_Method_);
    }
    
    FileType::~FileType(void)
    {
    }

    ServerVariable::SPtr&
    FileType::mimeType_Variable(void)
    {
        return mimeType_Variable_;
    }

    ServerVariable::SPtr&
    FileType::openCount_Variable(void)
    {
        return openCount_Variable_;
    }

    ServerVariable::SPtr&
    FileType::size_Variable(void)
    {
        return size_Variable_;
    }

    ServerVariable::SPtr&
    FileType::userWritable_Variable(void)
    {
        return userWritable_Variable_;
    }

    ServerVariable::SPtr&
    FileType::writable_Variable(void)
    {
        return writable_Variable_;
    }

    void
    FileType::mimeType_Variable(ServerVariable::SPtr& serverVariable)
    {
        mimeType_Variable_ = serverVariable;
    }

    void
    FileType::openCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        openCount_Variable_ = serverVariable;
    }

    void
    FileType::size_Variable(ServerVariable::SPtr& serverVariable)
    {
        size_Variable_ = serverVariable;
    }

    void
    FileType::userWritable_Variable(ServerVariable::SPtr& serverVariable)
    {
        userWritable_Variable_ = serverVariable;
    }

    void
    FileType::writable_Variable(ServerVariable::SPtr& serverVariable)
    {
        writable_Variable_ = serverVariable;
    }

    bool
    FileType::get_MimeType_Variable(OpcUaDataValue& dataValue)
    {
        return mimeType_Variable_->getDataValue(dataValue);
    }

    bool
    FileType::get_OpenCount_Variable(OpcUaDataValue& dataValue)
    {
        return openCount_Variable_->getDataValue(dataValue);
    }

    bool
    FileType::get_Size_Variable(OpcUaDataValue& dataValue)
    {
        return size_Variable_->getDataValue(dataValue);
    }

    bool
    FileType::get_UserWritable_Variable(OpcUaDataValue& dataValue)
    {
        return userWritable_Variable_->getDataValue(dataValue);
    }

    bool
    FileType::get_Writable_Variable(OpcUaDataValue& dataValue)
    {
        return writable_Variable_->getDataValue(dataValue);
    }

    bool
    FileType::set_MimeType_Variable(const OpcUaDataValue& dataValue)
    {
        return mimeType_Variable_->setDataValue(dataValue);
    }

    bool
    FileType::set_OpenCount_Variable(const OpcUaDataValue& dataValue)
    {
        return openCount_Variable_->setDataValue(dataValue);
    }

    bool
    FileType::set_Size_Variable(const OpcUaDataValue& dataValue)
    {
        return size_Variable_->setDataValue(dataValue);
    }

    bool
    FileType::set_UserWritable_Variable(const OpcUaDataValue& dataValue)
    {
        return userWritable_Variable_->setDataValue(dataValue);
    }

    bool
    FileType::set_Writable_Variable(const OpcUaDataValue& dataValue)
    {
        return writable_Variable_->setDataValue(dataValue);
    }

    void
    FileType::call_Close_Method(ApplicationMethodContext* applicationMethodContext)
    {
    	std::cout << "FileType::call_Close_Method" << std::endl;
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    FileType::call_GetPosition_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    FileType::call_Open_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    FileType::call_Read_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    FileType::call_SetPosition_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    FileType::call_Write_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

}
