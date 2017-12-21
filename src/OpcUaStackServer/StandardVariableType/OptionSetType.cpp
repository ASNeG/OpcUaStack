/*
    VariableTypeClass: OptionSetType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/OptionSetType.h"

namespace OpcUaStackServer
{
    
    OptionSetType::OptionSetType(void)
    : BaseDataVariableType()
    , namespaceName_("http://opcfoundation.org/UA/")
    , namespaceIndex_(0)
    , optionSetValues_(constructSPtr<ServerVariable>("OptionSetValues"))
    , bitMask_(constructSPtr<ServerVariable>("BitMask"))
    {
        variableTypeNamespace(namespaceName_);
        variableType(OpcUaNodeId(11487));
        serverVariables().registerServerVariable(optionSetValues_);
        serverVariables().registerServerVariable(bitMask_);
    }
    
    OptionSetType::~OptionSetType(void)
    {
    }
    
    bool
    OptionSetType::linkInstanceWithModel(const OpcUaNodeId& nodeId)
    {
        if (!getNamespaceIndexFromNamespaceName(namespaceName_, namespaceIndex_)) return false;
        optionSetValues_->addBrowsePath(nodeId, OpcUaQualifiedName("OptionSetValues", namespaceIndex_));
        bitMask_->addBrowsePath(nodeId, OpcUaQualifiedName("BitMask", namespaceIndex_));
        BaseDataVariableType::linkInstanceWithModel(nodeId);
    }
    
    BaseNodeClass::SPtr
    OptionSetType::optionSetValues(void)
    {
        return optionSetValues_->baseNode().lock();
    }
    
    bool
    OptionSetType::setOptionSetValues(const OpcUaDataValue& dataValue)
    {
        return optionSetValues_->setDataValue(dataValue);
    }
    
    bool
    OptionSetType::getOptionSetValues(OpcUaDataValue& dataValue)
    {
        return optionSetValues_->getDataValue(dataValue);
    }
    
    void
    OptionSetType::setUpdateCallbackOptionSetValues(Callback::SPtr& callback)
    {
        optionSetValues_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    OptionSetType::bitMask(void)
    {
        return bitMask_->baseNode().lock();
    }
    
    bool
    OptionSetType::setBitMask(const OpcUaDataValue& dataValue)
    {
        return bitMask_->setDataValue(dataValue);
    }
    
    bool
    OptionSetType::getBitMask(OpcUaDataValue& dataValue)
    {
        return bitMask_->getDataValue(dataValue);
    }
    
    void
    OptionSetType::setUpdateCallbackBitMask(Callback::SPtr& callback)
    {
        bitMask_->callback(callback);
    }

}
