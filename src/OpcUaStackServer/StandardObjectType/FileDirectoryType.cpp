/*
    VariableTypeClass: FileDirectoryType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/FileDirectoryType.h"

namespace OpcUaStackServer
{
    
    FileDirectoryType::FileDirectoryType(void)
    : ObjectBase()
    , createDirectory_Method_(boost::make_shared<ServerMethod>("CreateDirectory_Method"))
    , createFile_Method_(boost::make_shared<ServerMethod>("CreateFile_Method"))
    , delete_Method_(boost::make_shared<ServerMethod>("Delete_Method"))
    , moveOrCopy_Method_(boost::make_shared<ServerMethod>("MoveOrCopy_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)13353);
        setServerMethod(createDirectory_Method_);
        setServerMethod(createFile_Method_);
        setServerMethod(delete_Method_);
        setServerMethod(moveOrCopy_Method_);
        createDirectory_Method_->registerMethod(boost::bind(&FileDirectoryType::call_CreateDirectory_Method, this, _1));
        createFile_Method_->registerMethod(boost::bind(&FileDirectoryType::call_CreateFile_Method, this, _1));
        delete_Method_->registerMethod(boost::bind(&FileDirectoryType::call_Delete_Method, this, _1));
        moveOrCopy_Method_->registerMethod(boost::bind(&FileDirectoryType::call_MoveOrCopy_Method, this, _1));
    }
    
    FileDirectoryType::FileDirectoryType(const FileDirectoryType& value)
    : ObjectBase()
    , createDirectory_Method_(boost::make_shared<ServerMethod>("CreateDirectory_Method"))
    , createFile_Method_(boost::make_shared<ServerMethod>("CreateFile_Method"))
    , delete_Method_(boost::make_shared<ServerMethod>("Delete_Method"))
    , moveOrCopy_Method_(boost::make_shared<ServerMethod>("MoveOrCopy_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)13353);
        setServerMethod(createDirectory_Method_);
        setServerMethod(createFile_Method_);
        setServerMethod(delete_Method_);
        setServerMethod(moveOrCopy_Method_);
        createDirectory_Method_->registerMethod(boost::bind(&FileDirectoryType::call_CreateDirectory_Method, this, _1));
        createFile_Method_->registerMethod(boost::bind(&FileDirectoryType::call_CreateFile_Method, this, _1));
        delete_Method_->registerMethod(boost::bind(&FileDirectoryType::call_Delete_Method, this, _1));
        moveOrCopy_Method_->registerMethod(boost::bind(&FileDirectoryType::call_MoveOrCopy_Method, this, _1));
    }
    
    FileDirectoryType::~FileDirectoryType(void)
    {
    }

    void
    FileDirectoryType::call_CreateDirectory_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    FileDirectoryType::call_CreateFile_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    FileDirectoryType::call_Delete_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    FileDirectoryType::call_MoveOrCopy_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

}
