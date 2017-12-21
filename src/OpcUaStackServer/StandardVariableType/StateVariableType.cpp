/*
    VariableTypeClass: StateVariableType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/StateVariableType.h"

namespace OpcUaStackServer
{
    
    StateVariableType::StateVariableType(void)
    : BaseDataVariableType()
    , namespaceName_("http://opcfoundation.org/UA/")
    , namespaceIndex_(0)
    , id_(constructSPtr<ServerVariable>("Id"))
    , name_(constructSPtr<ServerVariable>("Name"))
    , number_(constructSPtr<ServerVariable>("Number"))
    , effectiveDisplayName_(constructSPtr<ServerVariable>("EffectiveDisplayName"))
    {
        variableTypeNamespace(namespaceName_);
        variableType(OpcUaNodeId(2755));
        serverVariables().registerServerVariable(id_);
        serverVariables().registerServerVariable(name_);
        serverVariables().registerServerVariable(number_);
        serverVariables().registerServerVariable(effectiveDisplayName_);
    }
    
    StateVariableType::~StateVariableType(void)
    {
    }
    
    bool
    StateVariableType::linkInstanceWithModel(const OpcUaNodeId& nodeId)
    {
        if (!getNamespaceIndexFromNamespaceName(namespaceName_, namespaceIndex_)) return false;
        id_->addBrowsePath(nodeId, OpcUaQualifiedName("Id", namespaceIndex_));
        name_->addBrowsePath(nodeId, OpcUaQualifiedName("Name", namespaceIndex_));
        number_->addBrowsePath(nodeId, OpcUaQualifiedName("Number", namespaceIndex_));
        effectiveDisplayName_->addBrowsePath(nodeId, OpcUaQualifiedName("EffectiveDisplayName", namespaceIndex_));
        BaseDataVariableType::linkInstanceWithModel(nodeId);
    }
    
    BaseNodeClass::SPtr
    StateVariableType::id(void)
    {
        return id_->baseNode().lock();
    }
    
    bool
    StateVariableType::setId(const OpcUaDataValue& dataValue)
    {
        return id_->setDataValue(dataValue);
    }
    
    bool
    StateVariableType::getId(OpcUaDataValue& dataValue)
    {
        return id_->getDataValue(dataValue);
    }
    
    void
    StateVariableType::setUpdateCallbackId(Callback::SPtr& callback)
    {
        id_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    StateVariableType::name(void)
    {
        return name_->baseNode().lock();
    }
    
    bool
    StateVariableType::setName(const OpcUaDataValue& dataValue)
    {
        return name_->setDataValue(dataValue);
    }
    
    bool
    StateVariableType::getName(OpcUaDataValue& dataValue)
    {
        return name_->getDataValue(dataValue);
    }
    
    void
    StateVariableType::setUpdateCallbackName(Callback::SPtr& callback)
    {
        name_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    StateVariableType::number(void)
    {
        return number_->baseNode().lock();
    }
    
    bool
    StateVariableType::setNumber(const OpcUaDataValue& dataValue)
    {
        return number_->setDataValue(dataValue);
    }
    
    bool
    StateVariableType::getNumber(OpcUaDataValue& dataValue)
    {
        return number_->getDataValue(dataValue);
    }
    
    void
    StateVariableType::setUpdateCallbackNumber(Callback::SPtr& callback)
    {
        number_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    StateVariableType::effectiveDisplayName(void)
    {
        return effectiveDisplayName_->baseNode().lock();
    }
    
    bool
    StateVariableType::setEffectiveDisplayName(const OpcUaDataValue& dataValue)
    {
        return effectiveDisplayName_->setDataValue(dataValue);
    }
    
    bool
    StateVariableType::getEffectiveDisplayName(OpcUaDataValue& dataValue)
    {
        return effectiveDisplayName_->getDataValue(dataValue);
    }
    
    void
    StateVariableType::setUpdateCallbackEffectiveDisplayName(Callback::SPtr& callback)
    {
        effectiveDisplayName_->callback(callback);
    }

}
