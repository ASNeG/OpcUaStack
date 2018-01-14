/*
    VariableTypeClass: TransitionVariableType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/TransitionVariableType.h"

namespace OpcUaStackServer
{
    
    TransitionVariableType::TransitionVariableType(void)
    : BaseDataVariableType()
    , namespaceName_("http://opcfoundation.org/UA/")
    , namespaceIndex_(0)
    , id_(constructSPtr<ServerVariable>("Id"))
    , name_(constructSPtr<ServerVariable>("Name"))
    , number_(constructSPtr<ServerVariable>("Number"))
    , transitionTime_(constructSPtr<ServerVariable>("TransitionTime"))
    , effectiveTransitionTime_(constructSPtr<ServerVariable>("EffectiveTransitionTime"))
    {
        variableTypeNamespace(namespaceName_);
        variableType(OpcUaNodeId(2762));
        serverVariables().registerServerVariable(id_);
        serverVariables().registerServerVariable(name_);
        serverVariables().registerServerVariable(number_);
        serverVariables().registerServerVariable(transitionTime_);
        serverVariables().registerServerVariable(effectiveTransitionTime_);
    }
    
    TransitionVariableType::~TransitionVariableType(void)
    {
    }
    
    bool
    TransitionVariableType::linkInstanceWithModel(const OpcUaNodeId& nodeId)
    {
        if (!getNamespaceIndexFromNamespaceName(namespaceName_, namespaceIndex_)) return false;
        id_->addBrowsePath(nodeId, OpcUaQualifiedName("Id", namespaceIndex_));
        name_->addBrowsePath(nodeId, OpcUaQualifiedName("Name", namespaceIndex_));
        number_->addBrowsePath(nodeId, OpcUaQualifiedName("Number", namespaceIndex_));
        transitionTime_->addBrowsePath(nodeId, OpcUaQualifiedName("TransitionTime", namespaceIndex_));
        effectiveTransitionTime_->addBrowsePath(nodeId, OpcUaQualifiedName("EffectiveTransitionTime", namespaceIndex_));
        BaseDataVariableType::linkInstanceWithModel(nodeId);
    }
    
    BaseNodeClass::SPtr
    TransitionVariableType::id(void)
    {
        return id_->baseNode().lock();
    }
    
    bool
    TransitionVariableType::setId(const OpcUaDataValue& dataValue)
    {
        return id_->setDataValue(dataValue);
    }
    
    bool
    TransitionVariableType::getId(OpcUaDataValue& dataValue)
    {
        return id_->getDataValue(dataValue);
    }
    
    void
    TransitionVariableType::setUpdateCallbackId(Callback::SPtr& callback)
    {
        id_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    TransitionVariableType::name(void)
    {
        return name_->baseNode().lock();
    }
    
    bool
    TransitionVariableType::setName(const OpcUaDataValue& dataValue)
    {
        return name_->setDataValue(dataValue);
    }
    
    bool
    TransitionVariableType::getName(OpcUaDataValue& dataValue)
    {
        return name_->getDataValue(dataValue);
    }
    
    void
    TransitionVariableType::setUpdateCallbackName(Callback::SPtr& callback)
    {
        name_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    TransitionVariableType::number(void)
    {
        return number_->baseNode().lock();
    }
    
    bool
    TransitionVariableType::setNumber(const OpcUaDataValue& dataValue)
    {
        return number_->setDataValue(dataValue);
    }
    
    bool
    TransitionVariableType::getNumber(OpcUaDataValue& dataValue)
    {
        return number_->getDataValue(dataValue);
    }
    
    void
    TransitionVariableType::setUpdateCallbackNumber(Callback::SPtr& callback)
    {
        number_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    TransitionVariableType::transitionTime(void)
    {
        return transitionTime_->baseNode().lock();
    }
    
    bool
    TransitionVariableType::setTransitionTime(const OpcUaDataValue& dataValue)
    {
        return transitionTime_->setDataValue(dataValue);
    }
    
    bool
    TransitionVariableType::getTransitionTime(OpcUaDataValue& dataValue)
    {
        return transitionTime_->getDataValue(dataValue);
    }
    
    void
    TransitionVariableType::setUpdateCallbackTransitionTime(Callback::SPtr& callback)
    {
        transitionTime_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    TransitionVariableType::effectiveTransitionTime(void)
    {
        return effectiveTransitionTime_->baseNode().lock();
    }
    
    bool
    TransitionVariableType::setEffectiveTransitionTime(const OpcUaDataValue& dataValue)
    {
        return effectiveTransitionTime_->setDataValue(dataValue);
    }
    
    bool
    TransitionVariableType::getEffectiveTransitionTime(OpcUaDataValue& dataValue)
    {
        return effectiveTransitionTime_->getDataValue(dataValue);
    }
    
    void
    TransitionVariableType::setUpdateCallbackEffectiveTransitionTime(Callback::SPtr& callback)
    {
        effectiveTransitionTime_->callback(callback);
    }

}
