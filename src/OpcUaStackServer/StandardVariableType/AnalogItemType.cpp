/*
    VariableTypeClass: AnalogItemType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/AnalogItemType.h"

namespace OpcUaStackServer
{
    
    AnalogItemType::AnalogItemType(void)
    : DataItemType()
    , namespaceName_("http://opcfoundation.org/UA/")
    , namespaceIndex_(0)
    , instrumentRange_(constructSPtr<ServerVariable>("InstrumentRange"))
    , eURange_(constructSPtr<ServerVariable>("EURange"))
    , engineeringUnits_(constructSPtr<ServerVariable>("EngineeringUnits"))
    {
        variableTypeNamespace(namespaceName_);
        variableType(OpcUaNodeId(2368));
        serverVariables().registerServerVariable(instrumentRange_);
        serverVariables().registerServerVariable(eURange_);
        serverVariables().registerServerVariable(engineeringUnits_);
    }
    
    AnalogItemType::~AnalogItemType(void)
    {
    }
    
    bool
    AnalogItemType::linkInstanceWithModel(const OpcUaNodeId& nodeId)
    {
        if (!getNamespaceIndexFromNamespaceName(namespaceName_, namespaceIndex_)) return false;
        instrumentRange_->addBrowsePath(nodeId, OpcUaQualifiedName("InstrumentRange", namespaceIndex_));
        eURange_->addBrowsePath(nodeId, OpcUaQualifiedName("EURange", namespaceIndex_));
        engineeringUnits_->addBrowsePath(nodeId, OpcUaQualifiedName("EngineeringUnits", namespaceIndex_));
        DataItemType::linkInstanceWithModel(nodeId);
    }
    
    BaseNodeClass::SPtr
    AnalogItemType::instrumentRange(void)
    {
        return instrumentRange_->baseNode().lock();
    }
    
    bool
    AnalogItemType::setInstrumentRange(const OpcUaDataValue& dataValue)
    {
        return instrumentRange_->setDataValue(dataValue);
    }
    
    bool
    AnalogItemType::getInstrumentRange(OpcUaDataValue& dataValue)
    {
        return instrumentRange_->getDataValue(dataValue);
    }
    
    void
    AnalogItemType::setUpdateCallbackInstrumentRange(Callback::SPtr& callback)
    {
        instrumentRange_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    AnalogItemType::eURange(void)
    {
        return eURange_->baseNode().lock();
    }
    
    bool
    AnalogItemType::setEURange(const OpcUaDataValue& dataValue)
    {
        return eURange_->setDataValue(dataValue);
    }
    
    bool
    AnalogItemType::getEURange(OpcUaDataValue& dataValue)
    {
        return eURange_->getDataValue(dataValue);
    }
    
    void
    AnalogItemType::setUpdateCallbackEURange(Callback::SPtr& callback)
    {
        eURange_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    AnalogItemType::engineeringUnits(void)
    {
        return engineeringUnits_->baseNode().lock();
    }
    
    bool
    AnalogItemType::setEngineeringUnits(const OpcUaDataValue& dataValue)
    {
        return engineeringUnits_->setDataValue(dataValue);
    }
    
    bool
    AnalogItemType::getEngineeringUnits(OpcUaDataValue& dataValue)
    {
        return engineeringUnits_->getDataValue(dataValue);
    }
    
    void
    AnalogItemType::setUpdateCallbackEngineeringUnits(Callback::SPtr& callback)
    {
        engineeringUnits_->callback(callback);
    }

}
