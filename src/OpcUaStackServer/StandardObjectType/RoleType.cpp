/*
    VariableTypeClass: RoleType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/RoleType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    RoleType::RoleType(void)
    : ObjectBase()
    , applicationsExclude_Variable_(boost::make_shared<ServerVariable>("ApplicationsExclude_Variable"))
    , applications_Variable_(boost::make_shared<ServerVariable>("Applications_Variable"))
    , endpointsExclude_Variable_(boost::make_shared<ServerVariable>("EndpointsExclude_Variable"))
    , endpoints_Variable_(boost::make_shared<ServerVariable>("Endpoints_Variable"))
    , identities_Variable_(boost::make_shared<ServerVariable>("Identities_Variable"))
    , addApplication_Method_(boost::make_shared<ServerMethod>("AddApplication_Method"))
    , addEndpoint_Method_(boost::make_shared<ServerMethod>("AddEndpoint_Method"))
    , addIdentity_Method_(boost::make_shared<ServerMethod>("AddIdentity_Method"))
    , removeApplication_Method_(boost::make_shared<ServerMethod>("RemoveApplication_Method"))
    , removeEndpoint_Method_(boost::make_shared<ServerMethod>("RemoveEndpoint_Method"))
    , removeIdentity_Method_(boost::make_shared<ServerMethod>("RemoveIdentity_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)15620);
        setServerVariable(applicationsExclude_Variable_);
        setServerVariable(applications_Variable_);
        setServerVariable(endpointsExclude_Variable_);
        setServerVariable(endpoints_Variable_);
        setServerVariable(identities_Variable_);
        setServerMethod(addApplication_Method_);
        setServerMethod(addEndpoint_Method_);
        setServerMethod(addIdentity_Method_);
        setServerMethod(removeApplication_Method_);
        setServerMethod(removeEndpoint_Method_);
        setServerMethod(removeIdentity_Method_);
        addApplication_Method_->registerMethod(boost::bind(&RoleType::call_AddApplication_Method, this, boost::placeholders::_1));
        addEndpoint_Method_->registerMethod(boost::bind(&RoleType::call_AddEndpoint_Method, this, boost::placeholders::_1));
        addIdentity_Method_->registerMethod(boost::bind(&RoleType::call_AddIdentity_Method, this, boost::placeholders::_1));
        removeApplication_Method_->registerMethod(boost::bind(&RoleType::call_RemoveApplication_Method, this, boost::placeholders::_1));
        removeEndpoint_Method_->registerMethod(boost::bind(&RoleType::call_RemoveEndpoint_Method, this, boost::placeholders::_1));
        removeIdentity_Method_->registerMethod(boost::bind(&RoleType::call_RemoveIdentity_Method, this, boost::placeholders::_1));
    }
    
    RoleType::RoleType(const RoleType& value)
    : ObjectBase()
    , applicationsExclude_Variable_(boost::make_shared<ServerVariable>("ApplicationsExclude_Variable"))
    , applications_Variable_(boost::make_shared<ServerVariable>("Applications_Variable"))
    , endpointsExclude_Variable_(boost::make_shared<ServerVariable>("EndpointsExclude_Variable"))
    , endpoints_Variable_(boost::make_shared<ServerVariable>("Endpoints_Variable"))
    , identities_Variable_(boost::make_shared<ServerVariable>("Identities_Variable"))
    , addApplication_Method_(boost::make_shared<ServerMethod>("AddApplication_Method"))
    , addEndpoint_Method_(boost::make_shared<ServerMethod>("AddEndpoint_Method"))
    , addIdentity_Method_(boost::make_shared<ServerMethod>("AddIdentity_Method"))
    , removeApplication_Method_(boost::make_shared<ServerMethod>("RemoveApplication_Method"))
    , removeEndpoint_Method_(boost::make_shared<ServerMethod>("RemoveEndpoint_Method"))
    , removeIdentity_Method_(boost::make_shared<ServerMethod>("RemoveIdentity_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)15620);
        setServerVariable(applicationsExclude_Variable_);
        setServerVariable(applications_Variable_);
        setServerVariable(endpointsExclude_Variable_);
        setServerVariable(endpoints_Variable_);
        setServerVariable(identities_Variable_);
        setServerMethod(addApplication_Method_);
        setServerMethod(addEndpoint_Method_);
        setServerMethod(addIdentity_Method_);
        setServerMethod(removeApplication_Method_);
        setServerMethod(removeEndpoint_Method_);
        setServerMethod(removeIdentity_Method_);
        addApplication_Method_->registerMethod(boost::bind(&RoleType::call_AddApplication_Method, this, boost::placeholders::_1));
        addEndpoint_Method_->registerMethod(boost::bind(&RoleType::call_AddEndpoint_Method, this, boost::placeholders::_1));
        addIdentity_Method_->registerMethod(boost::bind(&RoleType::call_AddIdentity_Method, this, boost::placeholders::_1));
        removeApplication_Method_->registerMethod(boost::bind(&RoleType::call_RemoveApplication_Method, this, boost::placeholders::_1));
        removeEndpoint_Method_->registerMethod(boost::bind(&RoleType::call_RemoveEndpoint_Method, this, boost::placeholders::_1));
        removeIdentity_Method_->registerMethod(boost::bind(&RoleType::call_RemoveIdentity_Method, this, boost::placeholders::_1));
    }
    
    RoleType::~RoleType(void)
    {
    }

    ServerVariable::SPtr&
    RoleType::applicationsExclude_Variable(void)
    {
        return applicationsExclude_Variable_;
    }

    ServerVariable::SPtr&
    RoleType::applications_Variable(void)
    {
        return applications_Variable_;
    }

    ServerVariable::SPtr&
    RoleType::endpointsExclude_Variable(void)
    {
        return endpointsExclude_Variable_;
    }

    ServerVariable::SPtr&
    RoleType::endpoints_Variable(void)
    {
        return endpoints_Variable_;
    }

    ServerVariable::SPtr&
    RoleType::identities_Variable(void)
    {
        return identities_Variable_;
    }

    void
    RoleType::applicationsExclude_Variable(ServerVariable::SPtr& serverVariable)
    {
        applicationsExclude_Variable_ = serverVariable;
    }

    void
    RoleType::applications_Variable(ServerVariable::SPtr& serverVariable)
    {
        applications_Variable_ = serverVariable;
    }

    void
    RoleType::endpointsExclude_Variable(ServerVariable::SPtr& serverVariable)
    {
        endpointsExclude_Variable_ = serverVariable;
    }

    void
    RoleType::endpoints_Variable(ServerVariable::SPtr& serverVariable)
    {
        endpoints_Variable_ = serverVariable;
    }

    void
    RoleType::identities_Variable(ServerVariable::SPtr& serverVariable)
    {
        identities_Variable_ = serverVariable;
    }

    bool
    RoleType::get_ApplicationsExclude_Variable(OpcUaDataValue& dataValue)
    {
        return applicationsExclude_Variable_->getDataValue(dataValue);
    }

    bool
    RoleType::get_Applications_Variable(OpcUaDataValue& dataValue)
    {
        return applications_Variable_->getDataValue(dataValue);
    }

    bool
    RoleType::get_EndpointsExclude_Variable(OpcUaDataValue& dataValue)
    {
        return endpointsExclude_Variable_->getDataValue(dataValue);
    }

    bool
    RoleType::get_Endpoints_Variable(OpcUaDataValue& dataValue)
    {
        return endpoints_Variable_->getDataValue(dataValue);
    }

    bool
    RoleType::get_Identities_Variable(OpcUaDataValue& dataValue)
    {
        return identities_Variable_->getDataValue(dataValue);
    }

    bool
    RoleType::set_ApplicationsExclude_Variable(const OpcUaDataValue& dataValue)
    {
        return applicationsExclude_Variable_->setDataValue(dataValue);
    }

    bool
    RoleType::set_Applications_Variable(const OpcUaDataValue& dataValue)
    {
        return applications_Variable_->setDataValue(dataValue);
    }

    bool
    RoleType::set_EndpointsExclude_Variable(const OpcUaDataValue& dataValue)
    {
        return endpointsExclude_Variable_->setDataValue(dataValue);
    }

    bool
    RoleType::set_Endpoints_Variable(const OpcUaDataValue& dataValue)
    {
        return endpoints_Variable_->setDataValue(dataValue);
    }

    bool
    RoleType::set_Identities_Variable(const OpcUaDataValue& dataValue)
    {
        return identities_Variable_->setDataValue(dataValue);
    }

    void
    RoleType::call_AddApplication_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    RoleType::call_AddEndpoint_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    RoleType::call_AddIdentity_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    RoleType::call_RemoveApplication_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    RoleType::call_RemoveEndpoint_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    RoleType::call_RemoveIdentity_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

}
