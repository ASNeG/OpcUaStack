/*
    VariableTypeClass: SecurityGroupFolderType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/SecurityGroupFolderType.h"

namespace OpcUaStackServer
{
    
    SecurityGroupFolderType::SecurityGroupFolderType(void)
    : ObjectBase()
    , addSecurityGroup_Method_(boost::make_shared<ServerMethod>("AddSecurityGroup_Method"))
    , removeSecurityGroup_Method_(boost::make_shared<ServerMethod>("RemoveSecurityGroup_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)15452);
        setServerMethod(addSecurityGroup_Method_);
        setServerMethod(removeSecurityGroup_Method_);
        addSecurityGroup_Method_->registerMethod(boost::bind(&SecurityGroupFolderType::call_AddSecurityGroup_Method, this, _1));
        removeSecurityGroup_Method_->registerMethod(boost::bind(&SecurityGroupFolderType::call_RemoveSecurityGroup_Method, this, _1));
    }
    
    SecurityGroupFolderType::SecurityGroupFolderType(const SecurityGroupFolderType& value)
    : ObjectBase()
    , addSecurityGroup_Method_(boost::make_shared<ServerMethod>("AddSecurityGroup_Method"))
    , removeSecurityGroup_Method_(boost::make_shared<ServerMethod>("RemoveSecurityGroup_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)15452);
        setServerMethod(addSecurityGroup_Method_);
        setServerMethod(removeSecurityGroup_Method_);
        addSecurityGroup_Method_->registerMethod(boost::bind(&SecurityGroupFolderType::call_AddSecurityGroup_Method, this, _1));
        removeSecurityGroup_Method_->registerMethod(boost::bind(&SecurityGroupFolderType::call_RemoveSecurityGroup_Method, this, _1));
    }
    
    SecurityGroupFolderType::~SecurityGroupFolderType(void)
    {
    }

    void
    SecurityGroupFolderType::call_AddSecurityGroup_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    SecurityGroupFolderType::call_RemoveSecurityGroup_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

}
