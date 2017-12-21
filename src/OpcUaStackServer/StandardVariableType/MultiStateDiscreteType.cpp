/*
    VariableTypeClass: MultiStateDiscreteType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/MultiStateDiscreteType.h"

namespace OpcUaStackServer
{
    
    MultiStateDiscreteType::MultiStateDiscreteType(void)
    : DiscreteItemType()
    , namespaceName_("http://opcfoundation.org/UA/")
    , namespaceIndex_(0)
    , enumStrings_(constructSPtr<ServerVariable>("EnumStrings"))
    {
        variableTypeNamespace(namespaceName_);
        variableType(OpcUaNodeId(2376));
        serverVariables().registerServerVariable(enumStrings_);
    }
    
    MultiStateDiscreteType::~MultiStateDiscreteType(void)
    {
    }
    
    bool
    MultiStateDiscreteType::linkInstanceWithModel(const OpcUaNodeId& nodeId)
    {
        if (!getNamespaceIndexFromNamespaceName(namespaceName_, namespaceIndex_)) return false;
        enumStrings_->addBrowsePath(nodeId, OpcUaQualifiedName("EnumStrings", namespaceIndex_));
        DiscreteItemType::linkInstanceWithModel(nodeId);
    }
    
    BaseNodeClass::SPtr
    MultiStateDiscreteType::enumStrings(void)
    {
        return enumStrings_->baseNode().lock();
    }
    
    bool
    MultiStateDiscreteType::setEnumStrings(const OpcUaDataValue& dataValue)
    {
        return enumStrings_->setDataValue(dataValue);
    }
    
    bool
    MultiStateDiscreteType::getEnumStrings(OpcUaDataValue& dataValue)
    {
        return enumStrings_->getDataValue(dataValue);
    }
    
    void
    MultiStateDiscreteType::setUpdateCallbackEnumStrings(Callback::SPtr& callback)
    {
        enumStrings_->callback(callback);
    }

}
