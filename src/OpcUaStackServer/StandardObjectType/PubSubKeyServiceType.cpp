/*
    VariableTypeClass: PubSubKeyServiceType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/PubSubKeyServiceType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    PubSubKeyServiceType::PubSubKeyServiceType(void)
    : ObjectBase()
    , getSecurityGroup_Method_(boost::make_shared<ServerMethod>("GetSecurityGroup_Method"))
    , getSecurityKeys_Method_(boost::make_shared<ServerMethod>("GetSecurityKeys_Method"))
    , securityGroups_AddSecurityGroup_Method_(boost::make_shared<ServerMethod>("SecurityGroups_AddSecurityGroup_Method"))
    , securityGroups_RemoveSecurityGroup_Method_(boost::make_shared<ServerMethod>("SecurityGroups_RemoveSecurityGroup_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)15906);
        setServerMethod(getSecurityGroup_Method_);
        setServerMethod(getSecurityKeys_Method_);
        setServerMethod(securityGroups_AddSecurityGroup_Method_);
        setServerMethod(securityGroups_RemoveSecurityGroup_Method_);
        getSecurityGroup_Method_->registerMethod(boost::bind(&PubSubKeyServiceType::call_GetSecurityGroup_Method, this, boost::placeholders::_1));
        getSecurityKeys_Method_->registerMethod(boost::bind(&PubSubKeyServiceType::call_GetSecurityKeys_Method, this, boost::placeholders::_1));
        securityGroups_AddSecurityGroup_Method_->registerMethod(boost::bind(&PubSubKeyServiceType::call_SecurityGroups_AddSecurityGroup_Method, this, boost::placeholders::_1));
        securityGroups_RemoveSecurityGroup_Method_->registerMethod(boost::bind(&PubSubKeyServiceType::call_SecurityGroups_RemoveSecurityGroup_Method, this, boost::placeholders::_1));
    }
    
    PubSubKeyServiceType::PubSubKeyServiceType(const PubSubKeyServiceType& value)
    : ObjectBase()
    , getSecurityGroup_Method_(boost::make_shared<ServerMethod>("GetSecurityGroup_Method"))
    , getSecurityKeys_Method_(boost::make_shared<ServerMethod>("GetSecurityKeys_Method"))
    , securityGroups_AddSecurityGroup_Method_(boost::make_shared<ServerMethod>("SecurityGroups_AddSecurityGroup_Method"))
    , securityGroups_RemoveSecurityGroup_Method_(boost::make_shared<ServerMethod>("SecurityGroups_RemoveSecurityGroup_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)15906);
        setServerMethod(getSecurityGroup_Method_);
        setServerMethod(getSecurityKeys_Method_);
        setServerMethod(securityGroups_AddSecurityGroup_Method_);
        setServerMethod(securityGroups_RemoveSecurityGroup_Method_);
        getSecurityGroup_Method_->registerMethod(boost::bind(&PubSubKeyServiceType::call_GetSecurityGroup_Method, this, boost::placeholders::_1));
        getSecurityKeys_Method_->registerMethod(boost::bind(&PubSubKeyServiceType::call_GetSecurityKeys_Method, this, boost::placeholders::_1));
        securityGroups_AddSecurityGroup_Method_->registerMethod(boost::bind(&PubSubKeyServiceType::call_SecurityGroups_AddSecurityGroup_Method, this, boost::placeholders::_1));
        securityGroups_RemoveSecurityGroup_Method_->registerMethod(boost::bind(&PubSubKeyServiceType::call_SecurityGroups_RemoveSecurityGroup_Method, this, boost::placeholders::_1));
    }
    
    PubSubKeyServiceType::~PubSubKeyServiceType(void)
    {
    }

    void
    PubSubKeyServiceType::call_GetSecurityGroup_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    PubSubKeyServiceType::call_GetSecurityKeys_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    PubSubKeyServiceType::call_SecurityGroups_AddSecurityGroup_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    PubSubKeyServiceType::call_SecurityGroups_RemoveSecurityGroup_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

}
