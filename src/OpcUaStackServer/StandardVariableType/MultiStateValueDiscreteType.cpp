/*
    VariableTypeClass: MultiStateValueDiscreteType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/MultiStateValueDiscreteType.h"

namespace OpcUaStackServer
{
    
    MultiStateValueDiscreteType::MultiStateValueDiscreteType(void)
    : DiscreteItemType()
    , namespaceName_("http://opcfoundation.org/UA/")
    , namespaceIndex_(0)
    , enumValues_(constructSPtr<ServerVariable>("EnumValues"))
    , valueAsText_(constructSPtr<ServerVariable>("ValueAsText"))
    {
        variableTypeNamespace(namespaceName_);
        variableType(OpcUaNodeId(11238));
        serverVariables().registerServerVariable(enumValues_);
        serverVariables().registerServerVariable(valueAsText_);
    }
    
    MultiStateValueDiscreteType::~MultiStateValueDiscreteType(void)
    {
    }
    
    bool
    MultiStateValueDiscreteType::linkInstanceWithModel(const OpcUaNodeId& nodeId)
    {
        if (!getNamespaceIndexFromNamespaceName(namespaceName_, namespaceIndex_)) return false;
        enumValues_->addBrowsePath(nodeId, OpcUaQualifiedName("EnumValues", namespaceIndex_));
        valueAsText_->addBrowsePath(nodeId, OpcUaQualifiedName("ValueAsText", namespaceIndex_));
        DiscreteItemType::linkInstanceWithModel(nodeId);
    }
    
    BaseNodeClass::SPtr
    MultiStateValueDiscreteType::enumValues(void)
    {
        return enumValues_->baseNode().lock();
    }
    
    bool
    MultiStateValueDiscreteType::setEnumValues(const OpcUaDataValue& dataValue)
    {
        return enumValues_->setDataValue(dataValue);
    }
    
    bool
    MultiStateValueDiscreteType::getEnumValues(OpcUaDataValue& dataValue)
    {
        return enumValues_->getDataValue(dataValue);
    }
    
    void
    MultiStateValueDiscreteType::setUpdateCallbackEnumValues(Callback::SPtr& callback)
    {
        enumValues_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    MultiStateValueDiscreteType::valueAsText(void)
    {
        return valueAsText_->baseNode().lock();
    }
    
    bool
    MultiStateValueDiscreteType::setValueAsText(const OpcUaDataValue& dataValue)
    {
        return valueAsText_->setDataValue(dataValue);
    }
    
    bool
    MultiStateValueDiscreteType::getValueAsText(OpcUaDataValue& dataValue)
    {
        return valueAsText_->getDataValue(dataValue);
    }
    
    void
    MultiStateValueDiscreteType::setUpdateCallbackValueAsText(Callback::SPtr& callback)
    {
        valueAsText_->callback(callback);
    }

}
