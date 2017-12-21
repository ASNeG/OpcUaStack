/*
    VariableTypeClass: ProgramDiagnosticType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/ProgramDiagnosticType.h"

namespace OpcUaStackServer
{
    
    ProgramDiagnosticType::ProgramDiagnosticType(void)
    : BaseDataVariableType()
    , namespaceName_("http://opcfoundation.org/UA/")
    , namespaceIndex_(0)
    , createSessionId_(constructSPtr<ServerVariable>("CreateSessionId"))
    , createClientName_(constructSPtr<ServerVariable>("CreateClientName"))
    , invocationCreationTime_(constructSPtr<ServerVariable>("InvocationCreationTime"))
    , lastTransitionTime_(constructSPtr<ServerVariable>("LastTransitionTime"))
    , lastMethodCall_(constructSPtr<ServerVariable>("LastMethodCall"))
    , lastMethodSessionId_(constructSPtr<ServerVariable>("LastMethodSessionId"))
    , lastMethodInputArguments_(constructSPtr<ServerVariable>("LastMethodInputArguments"))
    , lastMethodOutputArguments_(constructSPtr<ServerVariable>("LastMethodOutputArguments"))
    , lastMethodCallTime_(constructSPtr<ServerVariable>("LastMethodCallTime"))
    , lastMethodReturnStatus_(constructSPtr<ServerVariable>("LastMethodReturnStatus"))
    {
        variableTypeNamespace(namespaceName_);
        variableType(OpcUaNodeId(2380));
        serverVariables().registerServerVariable(createSessionId_);
        serverVariables().registerServerVariable(createClientName_);
        serverVariables().registerServerVariable(invocationCreationTime_);
        serverVariables().registerServerVariable(lastTransitionTime_);
        serverVariables().registerServerVariable(lastMethodCall_);
        serverVariables().registerServerVariable(lastMethodSessionId_);
        serverVariables().registerServerVariable(lastMethodInputArguments_);
        serverVariables().registerServerVariable(lastMethodOutputArguments_);
        serverVariables().registerServerVariable(lastMethodCallTime_);
        serverVariables().registerServerVariable(lastMethodReturnStatus_);
    }
    
    ProgramDiagnosticType::~ProgramDiagnosticType(void)
    {
    }
    
    bool
    ProgramDiagnosticType::linkInstanceWithModel(const OpcUaNodeId& nodeId)
    {
        if (!getNamespaceIndexFromNamespaceName(namespaceName_, namespaceIndex_)) return false;
        createSessionId_->addBrowsePath(nodeId, OpcUaQualifiedName("CreateSessionId", namespaceIndex_));
        createClientName_->addBrowsePath(nodeId, OpcUaQualifiedName("CreateClientName", namespaceIndex_));
        invocationCreationTime_->addBrowsePath(nodeId, OpcUaQualifiedName("InvocationCreationTime", namespaceIndex_));
        lastTransitionTime_->addBrowsePath(nodeId, OpcUaQualifiedName("LastTransitionTime", namespaceIndex_));
        lastMethodCall_->addBrowsePath(nodeId, OpcUaQualifiedName("LastMethodCall", namespaceIndex_));
        lastMethodSessionId_->addBrowsePath(nodeId, OpcUaQualifiedName("LastMethodSessionId", namespaceIndex_));
        lastMethodInputArguments_->addBrowsePath(nodeId, OpcUaQualifiedName("LastMethodInputArguments", namespaceIndex_));
        lastMethodOutputArguments_->addBrowsePath(nodeId, OpcUaQualifiedName("LastMethodOutputArguments", namespaceIndex_));
        lastMethodCallTime_->addBrowsePath(nodeId, OpcUaQualifiedName("LastMethodCallTime", namespaceIndex_));
        lastMethodReturnStatus_->addBrowsePath(nodeId, OpcUaQualifiedName("LastMethodReturnStatus", namespaceIndex_));
        BaseDataVariableType::linkInstanceWithModel(nodeId);
    }
    
    BaseNodeClass::SPtr
    ProgramDiagnosticType::createSessionId(void)
    {
        return createSessionId_->baseNode().lock();
    }
    
    bool
    ProgramDiagnosticType::setCreateSessionId(const OpcUaDataValue& dataValue)
    {
        return createSessionId_->setDataValue(dataValue);
    }
    
    bool
    ProgramDiagnosticType::getCreateSessionId(OpcUaDataValue& dataValue)
    {
        return createSessionId_->getDataValue(dataValue);
    }
    
    void
    ProgramDiagnosticType::setUpdateCallbackCreateSessionId(Callback::SPtr& callback)
    {
        createSessionId_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    ProgramDiagnosticType::createClientName(void)
    {
        return createClientName_->baseNode().lock();
    }
    
    bool
    ProgramDiagnosticType::setCreateClientName(const OpcUaDataValue& dataValue)
    {
        return createClientName_->setDataValue(dataValue);
    }
    
    bool
    ProgramDiagnosticType::getCreateClientName(OpcUaDataValue& dataValue)
    {
        return createClientName_->getDataValue(dataValue);
    }
    
    void
    ProgramDiagnosticType::setUpdateCallbackCreateClientName(Callback::SPtr& callback)
    {
        createClientName_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    ProgramDiagnosticType::invocationCreationTime(void)
    {
        return invocationCreationTime_->baseNode().lock();
    }
    
    bool
    ProgramDiagnosticType::setInvocationCreationTime(const OpcUaDataValue& dataValue)
    {
        return invocationCreationTime_->setDataValue(dataValue);
    }
    
    bool
    ProgramDiagnosticType::getInvocationCreationTime(OpcUaDataValue& dataValue)
    {
        return invocationCreationTime_->getDataValue(dataValue);
    }
    
    void
    ProgramDiagnosticType::setUpdateCallbackInvocationCreationTime(Callback::SPtr& callback)
    {
        invocationCreationTime_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    ProgramDiagnosticType::lastTransitionTime(void)
    {
        return lastTransitionTime_->baseNode().lock();
    }
    
    bool
    ProgramDiagnosticType::setLastTransitionTime(const OpcUaDataValue& dataValue)
    {
        return lastTransitionTime_->setDataValue(dataValue);
    }
    
    bool
    ProgramDiagnosticType::getLastTransitionTime(OpcUaDataValue& dataValue)
    {
        return lastTransitionTime_->getDataValue(dataValue);
    }
    
    void
    ProgramDiagnosticType::setUpdateCallbackLastTransitionTime(Callback::SPtr& callback)
    {
        lastTransitionTime_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    ProgramDiagnosticType::lastMethodCall(void)
    {
        return lastMethodCall_->baseNode().lock();
    }
    
    bool
    ProgramDiagnosticType::setLastMethodCall(const OpcUaDataValue& dataValue)
    {
        return lastMethodCall_->setDataValue(dataValue);
    }
    
    bool
    ProgramDiagnosticType::getLastMethodCall(OpcUaDataValue& dataValue)
    {
        return lastMethodCall_->getDataValue(dataValue);
    }
    
    void
    ProgramDiagnosticType::setUpdateCallbackLastMethodCall(Callback::SPtr& callback)
    {
        lastMethodCall_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    ProgramDiagnosticType::lastMethodSessionId(void)
    {
        return lastMethodSessionId_->baseNode().lock();
    }
    
    bool
    ProgramDiagnosticType::setLastMethodSessionId(const OpcUaDataValue& dataValue)
    {
        return lastMethodSessionId_->setDataValue(dataValue);
    }
    
    bool
    ProgramDiagnosticType::getLastMethodSessionId(OpcUaDataValue& dataValue)
    {
        return lastMethodSessionId_->getDataValue(dataValue);
    }
    
    void
    ProgramDiagnosticType::setUpdateCallbackLastMethodSessionId(Callback::SPtr& callback)
    {
        lastMethodSessionId_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    ProgramDiagnosticType::lastMethodInputArguments(void)
    {
        return lastMethodInputArguments_->baseNode().lock();
    }
    
    bool
    ProgramDiagnosticType::setLastMethodInputArguments(const OpcUaDataValue& dataValue)
    {
        return lastMethodInputArguments_->setDataValue(dataValue);
    }
    
    bool
    ProgramDiagnosticType::getLastMethodInputArguments(OpcUaDataValue& dataValue)
    {
        return lastMethodInputArguments_->getDataValue(dataValue);
    }
    
    void
    ProgramDiagnosticType::setUpdateCallbackLastMethodInputArguments(Callback::SPtr& callback)
    {
        lastMethodInputArguments_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    ProgramDiagnosticType::lastMethodOutputArguments(void)
    {
        return lastMethodOutputArguments_->baseNode().lock();
    }
    
    bool
    ProgramDiagnosticType::setLastMethodOutputArguments(const OpcUaDataValue& dataValue)
    {
        return lastMethodOutputArguments_->setDataValue(dataValue);
    }
    
    bool
    ProgramDiagnosticType::getLastMethodOutputArguments(OpcUaDataValue& dataValue)
    {
        return lastMethodOutputArguments_->getDataValue(dataValue);
    }
    
    void
    ProgramDiagnosticType::setUpdateCallbackLastMethodOutputArguments(Callback::SPtr& callback)
    {
        lastMethodOutputArguments_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    ProgramDiagnosticType::lastMethodCallTime(void)
    {
        return lastMethodCallTime_->baseNode().lock();
    }
    
    bool
    ProgramDiagnosticType::setLastMethodCallTime(const OpcUaDataValue& dataValue)
    {
        return lastMethodCallTime_->setDataValue(dataValue);
    }
    
    bool
    ProgramDiagnosticType::getLastMethodCallTime(OpcUaDataValue& dataValue)
    {
        return lastMethodCallTime_->getDataValue(dataValue);
    }
    
    void
    ProgramDiagnosticType::setUpdateCallbackLastMethodCallTime(Callback::SPtr& callback)
    {
        lastMethodCallTime_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    ProgramDiagnosticType::lastMethodReturnStatus(void)
    {
        return lastMethodReturnStatus_->baseNode().lock();
    }
    
    bool
    ProgramDiagnosticType::setLastMethodReturnStatus(const OpcUaDataValue& dataValue)
    {
        return lastMethodReturnStatus_->setDataValue(dataValue);
    }
    
    bool
    ProgramDiagnosticType::getLastMethodReturnStatus(OpcUaDataValue& dataValue)
    {
        return lastMethodReturnStatus_->getDataValue(dataValue);
    }
    
    void
    ProgramDiagnosticType::setUpdateCallbackLastMethodReturnStatus(Callback::SPtr& callback)
    {
        lastMethodReturnStatus_->callback(callback);
    }

}
