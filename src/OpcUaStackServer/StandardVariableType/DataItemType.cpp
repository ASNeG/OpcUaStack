/*
    VariableTypeClass: DataItemType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/DataItemType.h"

namespace OpcUaStackServer
{
    
    DataItemType::DataItemType(void)
    : BaseDataVariableType()
    , namespaceName_("http://opcfoundation.org/UA/")
    , namespaceIndex_(0)
    , definition_(constructSPtr<ServerVariable>("Definition"))
    , valuePrecision_(constructSPtr<ServerVariable>("ValuePrecision"))
    {
        variableTypeNamespace(namespaceName_);
        variableType(OpcUaNodeId(2365));
        serverVariables().registerServerVariable(definition_);
        serverVariables().registerServerVariable(valuePrecision_);
    }
    
    DataItemType::~DataItemType(void)
    {
    }
    
    bool
    DataItemType::linkInstanceWithModel(const OpcUaNodeId& nodeId)
    {
        if (!getNamespaceIndexFromNamespaceName(namespaceName_, namespaceIndex_)) return false;
        definition_->addBrowsePath(nodeId, OpcUaQualifiedName("Definition", namespaceIndex_));
        valuePrecision_->addBrowsePath(nodeId, OpcUaQualifiedName("ValuePrecision", namespaceIndex_));
        BaseDataVariableType::linkInstanceWithModel(nodeId);
    }
    
    BaseNodeClass::SPtr
    DataItemType::definition(void)
    {
        return definition_->baseNode().lock();
    }
    
    bool
    DataItemType::setDefinition(const OpcUaDataValue& dataValue)
    {
        return definition_->setDataValue(dataValue);
    }
    
    bool
    DataItemType::getDefinition(OpcUaDataValue& dataValue)
    {
        return definition_->getDataValue(dataValue);
    }
    
    void
    DataItemType::setUpdateCallbackDefinition(Callback::SPtr& callback)
    {
        definition_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    DataItemType::valuePrecision(void)
    {
        return valuePrecision_->baseNode().lock();
    }
    
    bool
    DataItemType::setValuePrecision(const OpcUaDataValue& dataValue)
    {
        return valuePrecision_->setDataValue(dataValue);
    }
    
    bool
    DataItemType::getValuePrecision(OpcUaDataValue& dataValue)
    {
        return valuePrecision_->getDataValue(dataValue);
    }
    
    void
    DataItemType::setUpdateCallbackValuePrecision(Callback::SPtr& callback)
    {
        valuePrecision_->callback(callback);
    }

}
