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
    , openCount_Variable_(constructSPtr<ServerVariable>("OpenCount_Variable"))
    , size_Variable_(constructSPtr<ServerVariable>("Size_Variable"))
    , userWriteable_Variable_(constructSPtr<ServerVariable>("UserWriteable_Variable"))
    , writeable_Variable_(constructSPtr<ServerVariable>("Writeable_Variable"))
    , close_Method_(constructSPtr<ServerMethod>("Close_Method"))
    , getPosition_Method_(constructSPtr<ServerMethod>("GetPosition_Method"))
    , open_Method_(constructSPtr<ServerMethod>("Open_Method"))
    , read_Method_(constructSPtr<ServerMethod>("Read_Method"))
    , setPosition_Method_(constructSPtr<ServerMethod>("SetPosition_Method"))
    , write_Method_(constructSPtr<ServerMethod>("Write_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)11575);
        setServerVariable(openCount_Variable_);
        setServerVariable(size_Variable_);
        setServerVariable(userWriteable_Variable_);
        setServerVariable(writeable_Variable_);
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
    , openCount_Variable_(constructSPtr<ServerVariable>("OpenCount_Variable"))
    , size_Variable_(constructSPtr<ServerVariable>("Size_Variable"))
    , userWriteable_Variable_(constructSPtr<ServerVariable>("UserWriteable_Variable"))
    , writeable_Variable_(constructSPtr<ServerVariable>("Writeable_Variable"))
    , close_Method_(constructSPtr<ServerMethod>("Close_Method"))
    , getPosition_Method_(constructSPtr<ServerMethod>("GetPosition_Method"))
    , open_Method_(constructSPtr<ServerMethod>("Open_Method"))
    , read_Method_(constructSPtr<ServerMethod>("Read_Method"))
    , setPosition_Method_(constructSPtr<ServerMethod>("SetPosition_Method"))
    , write_Method_(constructSPtr<ServerMethod>("Write_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)11575);
        setServerVariable(openCount_Variable_);
        setServerVariable(size_Variable_);
        setServerVariable(userWriteable_Variable_);
        setServerVariable(writeable_Variable_);
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
    FileType::userWriteable_Variable(void)
    {
        return userWriteable_Variable_;
    }

    ServerVariable::SPtr&
    FileType::writeable_Variable(void)
    {
        return writeable_Variable_;
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
    FileType::userWriteable_Variable(ServerVariable::SPtr& serverVariable)
    {
        userWriteable_Variable_ = serverVariable;
    }

    void
    FileType::writeable_Variable(ServerVariable::SPtr& serverVariable)
    {
        writeable_Variable_ = serverVariable;
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
    FileType::get_UserWriteable_Variable(OpcUaDataValue& dataValue)
    {
        return userWriteable_Variable_->getDataValue(dataValue);
    }

    bool
    FileType::get_Writeable_Variable(OpcUaDataValue& dataValue)
    {
        return writeable_Variable_->getDataValue(dataValue);
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
    FileType::set_UserWriteable_Variable(const OpcUaDataValue& dataValue)
    {
        return userWriteable_Variable_->setDataValue(dataValue);
    }

    bool
    FileType::set_Writeable_Variable(const OpcUaDataValue& dataValue)
    {
        return writeable_Variable_->setDataValue(dataValue);
    }

    void
    FileType::call_Close_Method(ApplicationMethodContext* applicationMethodContext)
    {
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
