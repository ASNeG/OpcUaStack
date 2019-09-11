/*
    VariableTypeClass: RoleSetType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/RoleSetType.h"

namespace OpcUaStackServer
{
    
    /**
     * A container for the roles supported by the server.
     */
    RoleSetType::RoleSetType(void)
    : ObjectBase()
    , addRole_Method_(boost::make_shared<ServerMethod>("AddRole_Method"))
    , removeRole_Method_(boost::make_shared<ServerMethod>("RemoveRole_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)15607);
        setServerMethod(addRole_Method_);
        setServerMethod(removeRole_Method_);
        addRole_Method_->registerMethod(boost::bind(&RoleSetType::call_AddRole_Method, this, _1));
        removeRole_Method_->registerMethod(boost::bind(&RoleSetType::call_RemoveRole_Method, this, _1));
    }
    
    /**
     * A container for the roles supported by the server.
     */
    RoleSetType::RoleSetType(const RoleSetType& value)
    : ObjectBase()
    , addRole_Method_(boost::make_shared<ServerMethod>("AddRole_Method"))
    , removeRole_Method_(boost::make_shared<ServerMethod>("RemoveRole_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)15607);
        setServerMethod(addRole_Method_);
        setServerMethod(removeRole_Method_);
        addRole_Method_->registerMethod(boost::bind(&RoleSetType::call_AddRole_Method, this, _1));
        removeRole_Method_->registerMethod(boost::bind(&RoleSetType::call_RemoveRole_Method, this, _1));
    }
    
    RoleSetType::~RoleSetType(void)
    {
    }

    void
    RoleSetType::call_AddRole_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    RoleSetType::call_RemoveRole_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

}
