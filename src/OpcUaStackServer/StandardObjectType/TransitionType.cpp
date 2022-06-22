/*
    VariableTypeClass: TransitionType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/TransitionType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    TransitionType::TransitionType(void)
    : ObjectBase()
    , transitionNumber_Variable_(boost::make_shared<ServerVariable>("TransitionNumber_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2310);
        setServerVariable(transitionNumber_Variable_);
    }
    
    TransitionType::TransitionType(const TransitionType& value)
    : ObjectBase()
    , transitionNumber_Variable_(boost::make_shared<ServerVariable>("TransitionNumber_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2310);
        setServerVariable(transitionNumber_Variable_);
    }
    
    TransitionType::~TransitionType(void)
    {
    }

    ServerVariable::SPtr&
    TransitionType::transitionNumber_Variable(void)
    {
        return transitionNumber_Variable_;
    }

    void
    TransitionType::transitionNumber_Variable(ServerVariable::SPtr& serverVariable)
    {
        transitionNumber_Variable_ = serverVariable;
    }

    bool
    TransitionType::get_TransitionNumber_Variable(OpcUaDataValue& dataValue)
    {
        return transitionNumber_Variable_->getDataValue(dataValue);
    }

    bool
    TransitionType::set_TransitionNumber_Variable(const OpcUaDataValue& dataValue)
    {
        return transitionNumber_Variable_->setDataValue(dataValue);
    }

}
