/*
    VariableTypeClass: ArrayItemType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/ArrayItemType.h"

namespace OpcUaStackServer
{
    
    ArrayItemType::ArrayItemType(void)
    : DataItemType()
    , namespaceName_("http://opcfoundation.org/UA/")
    , namespaceIndex_(0)
    , instrumentRange_(constructSPtr<ServerVariable>("InstrumentRange"))
    , eURange_(constructSPtr<ServerVariable>("EURange"))
    , engineeringUnits_(constructSPtr<ServerVariable>("EngineeringUnits"))
    , title_(constructSPtr<ServerVariable>("Title"))
    , axisScaleType_(constructSPtr<ServerVariable>("AxisScaleType"))
    {
        variableTypeNamespace(namespaceName_);
        variableType(OpcUaNodeId(12021));
        serverVariables().registerServerVariable(instrumentRange_);
        serverVariables().registerServerVariable(eURange_);
        serverVariables().registerServerVariable(engineeringUnits_);
        serverVariables().registerServerVariable(title_);
        serverVariables().registerServerVariable(axisScaleType_);
    }
    
    ArrayItemType::~ArrayItemType(void)
    {
    }
    
    bool
    ArrayItemType::linkInstanceWithModel(const OpcUaNodeId& nodeId)
    {
        if (!getNamespaceIndexFromNamespaceName(namespaceName_, namespaceIndex_)) return false;
        instrumentRange_->addBrowsePath(nodeId, OpcUaQualifiedName("InstrumentRange", namespaceIndex_));
        eURange_->addBrowsePath(nodeId, OpcUaQualifiedName("EURange", namespaceIndex_));
        engineeringUnits_->addBrowsePath(nodeId, OpcUaQualifiedName("EngineeringUnits", namespaceIndex_));
        title_->addBrowsePath(nodeId, OpcUaQualifiedName("Title", namespaceIndex_));
        axisScaleType_->addBrowsePath(nodeId, OpcUaQualifiedName("AxisScaleType", namespaceIndex_));
        DataItemType::linkInstanceWithModel(nodeId);
    }
    
    BaseNodeClass::SPtr
    ArrayItemType::instrumentRange(void)
    {
        return instrumentRange_->baseNode().lock();
    }
    
    bool
    ArrayItemType::setInstrumentRange(const OpcUaDataValue& dataValue)
    {
        return instrumentRange_->setDataValue(dataValue);
    }
    
    bool
    ArrayItemType::getInstrumentRange(OpcUaDataValue& dataValue)
    {
        return instrumentRange_->getDataValue(dataValue);
    }
    
    void
    ArrayItemType::setUpdateCallbackInstrumentRange(Callback::SPtr& callback)
    {
        instrumentRange_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    ArrayItemType::eURange(void)
    {
        return eURange_->baseNode().lock();
    }
    
    bool
    ArrayItemType::setEURange(const OpcUaDataValue& dataValue)
    {
        return eURange_->setDataValue(dataValue);
    }
    
    bool
    ArrayItemType::getEURange(OpcUaDataValue& dataValue)
    {
        return eURange_->getDataValue(dataValue);
    }
    
    void
    ArrayItemType::setUpdateCallbackEURange(Callback::SPtr& callback)
    {
        eURange_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    ArrayItemType::engineeringUnits(void)
    {
        return engineeringUnits_->baseNode().lock();
    }
    
    bool
    ArrayItemType::setEngineeringUnits(const OpcUaDataValue& dataValue)
    {
        return engineeringUnits_->setDataValue(dataValue);
    }
    
    bool
    ArrayItemType::getEngineeringUnits(OpcUaDataValue& dataValue)
    {
        return engineeringUnits_->getDataValue(dataValue);
    }
    
    void
    ArrayItemType::setUpdateCallbackEngineeringUnits(Callback::SPtr& callback)
    {
        engineeringUnits_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    ArrayItemType::title(void)
    {
        return title_->baseNode().lock();
    }
    
    bool
    ArrayItemType::setTitle(const OpcUaDataValue& dataValue)
    {
        return title_->setDataValue(dataValue);
    }
    
    bool
    ArrayItemType::getTitle(OpcUaDataValue& dataValue)
    {
        return title_->getDataValue(dataValue);
    }
    
    void
    ArrayItemType::setUpdateCallbackTitle(Callback::SPtr& callback)
    {
        title_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    ArrayItemType::axisScaleType(void)
    {
        return axisScaleType_->baseNode().lock();
    }
    
    bool
    ArrayItemType::setAxisScaleType(const OpcUaDataValue& dataValue)
    {
        return axisScaleType_->setDataValue(dataValue);
    }
    
    bool
    ArrayItemType::getAxisScaleType(OpcUaDataValue& dataValue)
    {
        return axisScaleType_->getDataValue(dataValue);
    }
    
    void
    ArrayItemType::setUpdateCallbackAxisScaleType(Callback::SPtr& callback)
    {
        axisScaleType_->callback(callback);
    }

}
