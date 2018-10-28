/*
    VariableTypeClass: DataTypeDictionaryType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/DataTypeDictionaryType.h"

namespace OpcUaStackServer
{
    
    DataTypeDictionaryType::DataTypeDictionaryType(void)
    : BaseDataVariableType()
    , namespaceName_("http://opcfoundation.org/UA/")
    , namespaceIndex_(0)
    , dataTypeVersion_(constructSPtr<ServerVariable>("DataTypeVersion"))
    , namespaceUri_(constructSPtr<ServerVariable>("NamespaceUri"))
    {
        variableTypeNamespace(namespaceName_);
        variableType(OpcUaNodeId(72));
        serverVariables().registerServerVariable(dataTypeVersion_);
        serverVariables().registerServerVariable(namespaceUri_);
    }
    
    DataTypeDictionaryType::~DataTypeDictionaryType(void)
    {
    }
    
    bool
    DataTypeDictionaryType::linkInstanceWithModel(const OpcUaNodeId& nodeId)
    {
        if (!getNamespaceIndexFromNamespaceName(namespaceName_, namespaceIndex_)) return false;
        dataTypeVersion_->addBrowsePath(nodeId, OpcUaQualifiedName("DataTypeVersion", namespaceIndex_));
        namespaceUri_->addBrowsePath(nodeId, OpcUaQualifiedName("NamespaceUri", namespaceIndex_));
        BaseDataVariableType::linkInstanceWithModel(nodeId);
    }
    
    BaseNodeClass::SPtr
    DataTypeDictionaryType::dataTypeVersion(void)
    {
        return dataTypeVersion_->baseNode().lock();
    }
    
    bool
    DataTypeDictionaryType::setDataTypeVersion(const OpcUaDataValue& dataValue)
    {
        return dataTypeVersion_->setDataValue(dataValue);
    }
    
    bool
    DataTypeDictionaryType::getDataTypeVersion(OpcUaDataValue& dataValue)
    {
        return dataTypeVersion_->getDataValue(dataValue);
    }
    
    void
    DataTypeDictionaryType::setUpdateCallbackDataTypeVersion(Callback::SPtr& callback)
    {
        dataTypeVersion_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    DataTypeDictionaryType::namespaceUri(void)
    {
        return namespaceUri_->baseNode().lock();
    }
    
    bool
    DataTypeDictionaryType::setNamespaceUri(const OpcUaDataValue& dataValue)
    {
        return namespaceUri_->setDataValue(dataValue);
    }
    
    bool
    DataTypeDictionaryType::getNamespaceUri(OpcUaDataValue& dataValue)
    {
        return namespaceUri_->getDataValue(dataValue);
    }
    
    void
    DataTypeDictionaryType::setUpdateCallbackNamespaceUri(Callback::SPtr& callback)
    {
        namespaceUri_->callback(callback);
    }

}
