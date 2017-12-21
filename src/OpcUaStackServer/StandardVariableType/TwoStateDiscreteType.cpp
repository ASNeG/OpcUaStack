/*
    VariableTypeClass: TwoStateDiscreteType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/TwoStateDiscreteType.h"

namespace OpcUaStackServer
{
    
    TwoStateDiscreteType::TwoStateDiscreteType(void)
    : DiscreteItemType()
    , namespaceName_("http://opcfoundation.org/UA/")
    , namespaceIndex_(0)
    , falseState_(constructSPtr<ServerVariable>("FalseState"))
    , trueState_(constructSPtr<ServerVariable>("TrueState"))
    {
        variableTypeNamespace(namespaceName_);
        variableType(OpcUaNodeId(2373));
        serverVariables().registerServerVariable(falseState_);
        serverVariables().registerServerVariable(trueState_);
    }
    
    TwoStateDiscreteType::~TwoStateDiscreteType(void)
    {
    }
    
    bool
    TwoStateDiscreteType::linkInstanceWithModel(const OpcUaNodeId& nodeId)
    {
        if (!getNamespaceIndexFromNamespaceName(namespaceName_, namespaceIndex_)) return false;
        falseState_->addBrowsePath(nodeId, OpcUaQualifiedName("FalseState", namespaceIndex_));
        trueState_->addBrowsePath(nodeId, OpcUaQualifiedName("TrueState", namespaceIndex_));
        DiscreteItemType::linkInstanceWithModel(nodeId);
    }
    
    BaseNodeClass::SPtr
    TwoStateDiscreteType::falseState(void)
    {
        return falseState_->baseNode().lock();
    }
    
    bool
    TwoStateDiscreteType::setFalseState(const OpcUaDataValue& dataValue)
    {
        return falseState_->setDataValue(dataValue);
    }
    
    bool
    TwoStateDiscreteType::getFalseState(OpcUaDataValue& dataValue)
    {
        return falseState_->getDataValue(dataValue);
    }
    
    void
    TwoStateDiscreteType::setUpdateCallbackFalseState(Callback::SPtr& callback)
    {
        falseState_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    TwoStateDiscreteType::trueState(void)
    {
        return trueState_->baseNode().lock();
    }
    
    bool
    TwoStateDiscreteType::setTrueState(const OpcUaDataValue& dataValue)
    {
        return trueState_->setDataValue(dataValue);
    }
    
    bool
    TwoStateDiscreteType::getTrueState(OpcUaDataValue& dataValue)
    {
        return trueState_->getDataValue(dataValue);
    }
    
    void
    TwoStateDiscreteType::setUpdateCallbackTrueState(Callback::SPtr& callback)
    {
        trueState_->callback(callback);
    }

}
