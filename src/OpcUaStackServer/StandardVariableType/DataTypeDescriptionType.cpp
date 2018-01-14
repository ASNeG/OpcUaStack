/*
    VariableTypeClass: DataTypeDescriptionType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/DataTypeDescriptionType.h"

namespace OpcUaStackServer
{
    
    DataTypeDescriptionType::DataTypeDescriptionType(void)
    : BaseDataVariableType()
    , namespaceName_("http://opcfoundation.org/UA/")
    , namespaceIndex_(0)
    , dataTypeVersion_(constructSPtr<ServerVariable>("DataTypeVersion"))
    , dictionaryFragment_(constructSPtr<ServerVariable>("DictionaryFragment"))
    {
        variableTypeNamespace(namespaceName_);
        variableType(OpcUaNodeId(69));
        serverVariables().registerServerVariable(dataTypeVersion_);
        serverVariables().registerServerVariable(dictionaryFragment_);
    }
    
    DataTypeDescriptionType::~DataTypeDescriptionType(void)
    {
    }
    
    bool
    DataTypeDescriptionType::linkInstanceWithModel(const OpcUaNodeId& nodeId)
    {
        if (!getNamespaceIndexFromNamespaceName(namespaceName_, namespaceIndex_)) return false;
        dataTypeVersion_->addBrowsePath(nodeId, OpcUaQualifiedName("DataTypeVersion", namespaceIndex_));
        dictionaryFragment_->addBrowsePath(nodeId, OpcUaQualifiedName("DictionaryFragment", namespaceIndex_));
        BaseDataVariableType::linkInstanceWithModel(nodeId);
    }
    
    BaseNodeClass::SPtr
    DataTypeDescriptionType::dataTypeVersion(void)
    {
        return dataTypeVersion_->baseNode().lock();
    }
    
    bool
    DataTypeDescriptionType::setDataTypeVersion(const OpcUaDataValue& dataValue)
    {
        return dataTypeVersion_->setDataValue(dataValue);
    }
    
    bool
    DataTypeDescriptionType::getDataTypeVersion(OpcUaDataValue& dataValue)
    {
        return dataTypeVersion_->getDataValue(dataValue);
    }
    
    void
    DataTypeDescriptionType::setUpdateCallbackDataTypeVersion(Callback::SPtr& callback)
    {
        dataTypeVersion_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    DataTypeDescriptionType::dictionaryFragment(void)
    {
        return dictionaryFragment_->baseNode().lock();
    }
    
    bool
    DataTypeDescriptionType::setDictionaryFragment(const OpcUaDataValue& dataValue)
    {
        return dictionaryFragment_->setDataValue(dataValue);
    }
    
    bool
    DataTypeDescriptionType::getDictionaryFragment(OpcUaDataValue& dataValue)
    {
        return dictionaryFragment_->getDataValue(dataValue);
    }
    
    void
    DataTypeDescriptionType::setUpdateCallbackDictionaryFragment(Callback::SPtr& callback)
    {
        dictionaryFragment_->callback(callback);
    }

}
