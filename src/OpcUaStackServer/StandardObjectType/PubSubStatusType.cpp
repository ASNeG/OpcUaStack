/*
    VariableTypeClass: PubSubStatusType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/PubSubStatusType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    PubSubStatusType::PubSubStatusType(void)
    : ObjectBase()
    , state_Variable_(boost::make_shared<ServerVariable>("State_Variable"))
    , disable_Method_(boost::make_shared<ServerMethod>("Disable_Method"))
    , enable_Method_(boost::make_shared<ServerMethod>("Enable_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)14643);
        setServerVariable(state_Variable_);
        setServerMethod(disable_Method_);
        setServerMethod(enable_Method_);
        disable_Method_->registerMethod(boost::bind(&PubSubStatusType::call_Disable_Method, this, _1));
        enable_Method_->registerMethod(boost::bind(&PubSubStatusType::call_Enable_Method, this, _1));
    }
    
    PubSubStatusType::PubSubStatusType(const PubSubStatusType& value)
    : ObjectBase()
    , state_Variable_(boost::make_shared<ServerVariable>("State_Variable"))
    , disable_Method_(boost::make_shared<ServerMethod>("Disable_Method"))
    , enable_Method_(boost::make_shared<ServerMethod>("Enable_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)14643);
        setServerVariable(state_Variable_);
        setServerMethod(disable_Method_);
        setServerMethod(enable_Method_);
        disable_Method_->registerMethod(boost::bind(&PubSubStatusType::call_Disable_Method, this, _1));
        enable_Method_->registerMethod(boost::bind(&PubSubStatusType::call_Enable_Method, this, _1));
    }
    
    PubSubStatusType::~PubSubStatusType(void)
    {
    }

    ServerVariable::SPtr&
    PubSubStatusType::state_Variable(void)
    {
        return state_Variable_;
    }

    void
    PubSubStatusType::state_Variable(ServerVariable::SPtr& serverVariable)
    {
        state_Variable_ = serverVariable;
    }

    bool
    PubSubStatusType::get_State_Variable(OpcUaDataValue& dataValue)
    {
        return state_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubStatusType::set_State_Variable(const OpcUaDataValue& dataValue)
    {
        return state_Variable_->setDataValue(dataValue);
    }

    void
    PubSubStatusType::call_Disable_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    PubSubStatusType::call_Enable_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

}
