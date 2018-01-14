/*
    VariableTypeClass: TwoStateVariableType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/TwoStateVariableType.h"

namespace OpcUaStackServer
{
    
    TwoStateVariableType::TwoStateVariableType(void)
    : StateVariableType()
    , namespaceName_("http://opcfoundation.org/UA/")
    , namespaceIndex_(0)
    , id_(constructSPtr<ServerVariable>("Id"))
    , transitionTime_(constructSPtr<ServerVariable>("TransitionTime"))
    , effectiveTransitionTime_(constructSPtr<ServerVariable>("EffectiveTransitionTime"))
    , trueState_(constructSPtr<ServerVariable>("TrueState"))
    , falseState_(constructSPtr<ServerVariable>("FalseState"))
    {
        variableTypeNamespace(namespaceName_);
        variableType(OpcUaNodeId(8995));
        serverVariables().registerServerVariable(id_);
        serverVariables().registerServerVariable(transitionTime_);
        serverVariables().registerServerVariable(effectiveTransitionTime_);
        serverVariables().registerServerVariable(trueState_);
        serverVariables().registerServerVariable(falseState_);
    }
    
    TwoStateVariableType::~TwoStateVariableType(void)
    {
    }
    
    bool
    TwoStateVariableType::linkInstanceWithModel(const OpcUaNodeId& nodeId)
    {
        if (!getNamespaceIndexFromNamespaceName(namespaceName_, namespaceIndex_)) return false;
        id_->addBrowsePath(nodeId, OpcUaQualifiedName("Id", namespaceIndex_));
        transitionTime_->addBrowsePath(nodeId, OpcUaQualifiedName("TransitionTime", namespaceIndex_));
        effectiveTransitionTime_->addBrowsePath(nodeId, OpcUaQualifiedName("EffectiveTransitionTime", namespaceIndex_));
        trueState_->addBrowsePath(nodeId, OpcUaQualifiedName("TrueState", namespaceIndex_));
        falseState_->addBrowsePath(nodeId, OpcUaQualifiedName("FalseState", namespaceIndex_));
        StateVariableType::linkInstanceWithModel(nodeId);
    }
    
    BaseNodeClass::SPtr
    TwoStateVariableType::id(void)
    {
        return id_->baseNode().lock();
    }
    
    bool
    TwoStateVariableType::setId(const OpcUaDataValue& dataValue)
    {
        return id_->setDataValue(dataValue);
    }
    
    bool
    TwoStateVariableType::getId(OpcUaDataValue& dataValue)
    {
        return id_->getDataValue(dataValue);
    }
    
    void
    TwoStateVariableType::setUpdateCallbackId(Callback::SPtr& callback)
    {
        id_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    TwoStateVariableType::transitionTime(void)
    {
        return transitionTime_->baseNode().lock();
    }
    
    bool
    TwoStateVariableType::setTransitionTime(const OpcUaDataValue& dataValue)
    {
        return transitionTime_->setDataValue(dataValue);
    }
    
    bool
    TwoStateVariableType::getTransitionTime(OpcUaDataValue& dataValue)
    {
        return transitionTime_->getDataValue(dataValue);
    }
    
    void
    TwoStateVariableType::setUpdateCallbackTransitionTime(Callback::SPtr& callback)
    {
        transitionTime_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    TwoStateVariableType::effectiveTransitionTime(void)
    {
        return effectiveTransitionTime_->baseNode().lock();
    }
    
    bool
    TwoStateVariableType::setEffectiveTransitionTime(const OpcUaDataValue& dataValue)
    {
        return effectiveTransitionTime_->setDataValue(dataValue);
    }
    
    bool
    TwoStateVariableType::getEffectiveTransitionTime(OpcUaDataValue& dataValue)
    {
        return effectiveTransitionTime_->getDataValue(dataValue);
    }
    
    void
    TwoStateVariableType::setUpdateCallbackEffectiveTransitionTime(Callback::SPtr& callback)
    {
        effectiveTransitionTime_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    TwoStateVariableType::trueState(void)
    {
        return trueState_->baseNode().lock();
    }
    
    bool
    TwoStateVariableType::setTrueState(const OpcUaDataValue& dataValue)
    {
        return trueState_->setDataValue(dataValue);
    }
    
    bool
    TwoStateVariableType::getTrueState(OpcUaDataValue& dataValue)
    {
        return trueState_->getDataValue(dataValue);
    }
    
    void
    TwoStateVariableType::setUpdateCallbackTrueState(Callback::SPtr& callback)
    {
        trueState_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    TwoStateVariableType::falseState(void)
    {
        return falseState_->baseNode().lock();
    }
    
    bool
    TwoStateVariableType::setFalseState(const OpcUaDataValue& dataValue)
    {
        return falseState_->setDataValue(dataValue);
    }
    
    bool
    TwoStateVariableType::getFalseState(OpcUaDataValue& dataValue)
    {
        return falseState_->getDataValue(dataValue);
    }
    
    void
    TwoStateVariableType::setUpdateCallbackFalseState(Callback::SPtr& callback)
    {
        falseState_->callback(callback);
    }

}
