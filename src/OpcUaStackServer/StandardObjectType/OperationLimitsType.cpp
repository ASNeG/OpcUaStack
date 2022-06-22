/*
    VariableTypeClass: OperationLimitsType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/OperationLimitsType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    /**
     * Identifies the operation limits imposed by the server.
     */
    OperationLimitsType::OperationLimitsType(void)
    : ObjectBase()
    , maxMonitoredItemsPerCall_Variable_(boost::make_shared<ServerVariable>("MaxMonitoredItemsPerCall_Variable"))
    , maxNodesPerBrowse_Variable_(boost::make_shared<ServerVariable>("MaxNodesPerBrowse_Variable"))
    , maxNodesPerHistoryReadData_Variable_(boost::make_shared<ServerVariable>("MaxNodesPerHistoryReadData_Variable"))
    , maxNodesPerHistoryReadEvents_Variable_(boost::make_shared<ServerVariable>("MaxNodesPerHistoryReadEvents_Variable"))
    , maxNodesPerHistoryUpdateData_Variable_(boost::make_shared<ServerVariable>("MaxNodesPerHistoryUpdateData_Variable"))
    , maxNodesPerHistoryUpdateEvents_Variable_(boost::make_shared<ServerVariable>("MaxNodesPerHistoryUpdateEvents_Variable"))
    , maxNodesPerMethodCall_Variable_(boost::make_shared<ServerVariable>("MaxNodesPerMethodCall_Variable"))
    , maxNodesPerNodeManagement_Variable_(boost::make_shared<ServerVariable>("MaxNodesPerNodeManagement_Variable"))
    , maxNodesPerRead_Variable_(boost::make_shared<ServerVariable>("MaxNodesPerRead_Variable"))
    , maxNodesPerRegisterNodes_Variable_(boost::make_shared<ServerVariable>("MaxNodesPerRegisterNodes_Variable"))
    , maxNodesPerTranslateBrowsePathsToNodeIds_Variable_(boost::make_shared<ServerVariable>("MaxNodesPerTranslateBrowsePathsToNodeIds_Variable"))
    , maxNodesPerWrite_Variable_(boost::make_shared<ServerVariable>("MaxNodesPerWrite_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)11564);
        setServerVariable(maxMonitoredItemsPerCall_Variable_);
        setServerVariable(maxNodesPerBrowse_Variable_);
        setServerVariable(maxNodesPerHistoryReadData_Variable_);
        setServerVariable(maxNodesPerHistoryReadEvents_Variable_);
        setServerVariable(maxNodesPerHistoryUpdateData_Variable_);
        setServerVariable(maxNodesPerHistoryUpdateEvents_Variable_);
        setServerVariable(maxNodesPerMethodCall_Variable_);
        setServerVariable(maxNodesPerNodeManagement_Variable_);
        setServerVariable(maxNodesPerRead_Variable_);
        setServerVariable(maxNodesPerRegisterNodes_Variable_);
        setServerVariable(maxNodesPerTranslateBrowsePathsToNodeIds_Variable_);
        setServerVariable(maxNodesPerWrite_Variable_);
    }
    
    /**
     * Identifies the operation limits imposed by the server.
     */
    OperationLimitsType::OperationLimitsType(const OperationLimitsType& value)
    : ObjectBase()
    , maxMonitoredItemsPerCall_Variable_(boost::make_shared<ServerVariable>("MaxMonitoredItemsPerCall_Variable"))
    , maxNodesPerBrowse_Variable_(boost::make_shared<ServerVariable>("MaxNodesPerBrowse_Variable"))
    , maxNodesPerHistoryReadData_Variable_(boost::make_shared<ServerVariable>("MaxNodesPerHistoryReadData_Variable"))
    , maxNodesPerHistoryReadEvents_Variable_(boost::make_shared<ServerVariable>("MaxNodesPerHistoryReadEvents_Variable"))
    , maxNodesPerHistoryUpdateData_Variable_(boost::make_shared<ServerVariable>("MaxNodesPerHistoryUpdateData_Variable"))
    , maxNodesPerHistoryUpdateEvents_Variable_(boost::make_shared<ServerVariable>("MaxNodesPerHistoryUpdateEvents_Variable"))
    , maxNodesPerMethodCall_Variable_(boost::make_shared<ServerVariable>("MaxNodesPerMethodCall_Variable"))
    , maxNodesPerNodeManagement_Variable_(boost::make_shared<ServerVariable>("MaxNodesPerNodeManagement_Variable"))
    , maxNodesPerRead_Variable_(boost::make_shared<ServerVariable>("MaxNodesPerRead_Variable"))
    , maxNodesPerRegisterNodes_Variable_(boost::make_shared<ServerVariable>("MaxNodesPerRegisterNodes_Variable"))
    , maxNodesPerTranslateBrowsePathsToNodeIds_Variable_(boost::make_shared<ServerVariable>("MaxNodesPerTranslateBrowsePathsToNodeIds_Variable"))
    , maxNodesPerWrite_Variable_(boost::make_shared<ServerVariable>("MaxNodesPerWrite_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)11564);
        setServerVariable(maxMonitoredItemsPerCall_Variable_);
        setServerVariable(maxNodesPerBrowse_Variable_);
        setServerVariable(maxNodesPerHistoryReadData_Variable_);
        setServerVariable(maxNodesPerHistoryReadEvents_Variable_);
        setServerVariable(maxNodesPerHistoryUpdateData_Variable_);
        setServerVariable(maxNodesPerHistoryUpdateEvents_Variable_);
        setServerVariable(maxNodesPerMethodCall_Variable_);
        setServerVariable(maxNodesPerNodeManagement_Variable_);
        setServerVariable(maxNodesPerRead_Variable_);
        setServerVariable(maxNodesPerRegisterNodes_Variable_);
        setServerVariable(maxNodesPerTranslateBrowsePathsToNodeIds_Variable_);
        setServerVariable(maxNodesPerWrite_Variable_);
    }
    
    OperationLimitsType::~OperationLimitsType(void)
    {
    }

    ServerVariable::SPtr&
    OperationLimitsType::maxMonitoredItemsPerCall_Variable(void)
    {
        return maxMonitoredItemsPerCall_Variable_;
    }

    ServerVariable::SPtr&
    OperationLimitsType::maxNodesPerBrowse_Variable(void)
    {
        return maxNodesPerBrowse_Variable_;
    }

    ServerVariable::SPtr&
    OperationLimitsType::maxNodesPerHistoryReadData_Variable(void)
    {
        return maxNodesPerHistoryReadData_Variable_;
    }

    ServerVariable::SPtr&
    OperationLimitsType::maxNodesPerHistoryReadEvents_Variable(void)
    {
        return maxNodesPerHistoryReadEvents_Variable_;
    }

    ServerVariable::SPtr&
    OperationLimitsType::maxNodesPerHistoryUpdateData_Variable(void)
    {
        return maxNodesPerHistoryUpdateData_Variable_;
    }

    ServerVariable::SPtr&
    OperationLimitsType::maxNodesPerHistoryUpdateEvents_Variable(void)
    {
        return maxNodesPerHistoryUpdateEvents_Variable_;
    }

    ServerVariable::SPtr&
    OperationLimitsType::maxNodesPerMethodCall_Variable(void)
    {
        return maxNodesPerMethodCall_Variable_;
    }

    ServerVariable::SPtr&
    OperationLimitsType::maxNodesPerNodeManagement_Variable(void)
    {
        return maxNodesPerNodeManagement_Variable_;
    }

    ServerVariable::SPtr&
    OperationLimitsType::maxNodesPerRead_Variable(void)
    {
        return maxNodesPerRead_Variable_;
    }

    ServerVariable::SPtr&
    OperationLimitsType::maxNodesPerRegisterNodes_Variable(void)
    {
        return maxNodesPerRegisterNodes_Variable_;
    }

    ServerVariable::SPtr&
    OperationLimitsType::maxNodesPerTranslateBrowsePathsToNodeIds_Variable(void)
    {
        return maxNodesPerTranslateBrowsePathsToNodeIds_Variable_;
    }

    ServerVariable::SPtr&
    OperationLimitsType::maxNodesPerWrite_Variable(void)
    {
        return maxNodesPerWrite_Variable_;
    }

    void
    OperationLimitsType::maxMonitoredItemsPerCall_Variable(ServerVariable::SPtr& serverVariable)
    {
        maxMonitoredItemsPerCall_Variable_ = serverVariable;
    }

    void
    OperationLimitsType::maxNodesPerBrowse_Variable(ServerVariable::SPtr& serverVariable)
    {
        maxNodesPerBrowse_Variable_ = serverVariable;
    }

    void
    OperationLimitsType::maxNodesPerHistoryReadData_Variable(ServerVariable::SPtr& serverVariable)
    {
        maxNodesPerHistoryReadData_Variable_ = serverVariable;
    }

    void
    OperationLimitsType::maxNodesPerHistoryReadEvents_Variable(ServerVariable::SPtr& serverVariable)
    {
        maxNodesPerHistoryReadEvents_Variable_ = serverVariable;
    }

    void
    OperationLimitsType::maxNodesPerHistoryUpdateData_Variable(ServerVariable::SPtr& serverVariable)
    {
        maxNodesPerHistoryUpdateData_Variable_ = serverVariable;
    }

    void
    OperationLimitsType::maxNodesPerHistoryUpdateEvents_Variable(ServerVariable::SPtr& serverVariable)
    {
        maxNodesPerHistoryUpdateEvents_Variable_ = serverVariable;
    }

    void
    OperationLimitsType::maxNodesPerMethodCall_Variable(ServerVariable::SPtr& serverVariable)
    {
        maxNodesPerMethodCall_Variable_ = serverVariable;
    }

    void
    OperationLimitsType::maxNodesPerNodeManagement_Variable(ServerVariable::SPtr& serverVariable)
    {
        maxNodesPerNodeManagement_Variable_ = serverVariable;
    }

    void
    OperationLimitsType::maxNodesPerRead_Variable(ServerVariable::SPtr& serverVariable)
    {
        maxNodesPerRead_Variable_ = serverVariable;
    }

    void
    OperationLimitsType::maxNodesPerRegisterNodes_Variable(ServerVariable::SPtr& serverVariable)
    {
        maxNodesPerRegisterNodes_Variable_ = serverVariable;
    }

    void
    OperationLimitsType::maxNodesPerTranslateBrowsePathsToNodeIds_Variable(ServerVariable::SPtr& serverVariable)
    {
        maxNodesPerTranslateBrowsePathsToNodeIds_Variable_ = serverVariable;
    }

    void
    OperationLimitsType::maxNodesPerWrite_Variable(ServerVariable::SPtr& serverVariable)
    {
        maxNodesPerWrite_Variable_ = serverVariable;
    }

    bool
    OperationLimitsType::get_MaxMonitoredItemsPerCall_Variable(OpcUaDataValue& dataValue)
    {
        return maxMonitoredItemsPerCall_Variable_->getDataValue(dataValue);
    }

    bool
    OperationLimitsType::get_MaxNodesPerBrowse_Variable(OpcUaDataValue& dataValue)
    {
        return maxNodesPerBrowse_Variable_->getDataValue(dataValue);
    }

    bool
    OperationLimitsType::get_MaxNodesPerHistoryReadData_Variable(OpcUaDataValue& dataValue)
    {
        return maxNodesPerHistoryReadData_Variable_->getDataValue(dataValue);
    }

    bool
    OperationLimitsType::get_MaxNodesPerHistoryReadEvents_Variable(OpcUaDataValue& dataValue)
    {
        return maxNodesPerHistoryReadEvents_Variable_->getDataValue(dataValue);
    }

    bool
    OperationLimitsType::get_MaxNodesPerHistoryUpdateData_Variable(OpcUaDataValue& dataValue)
    {
        return maxNodesPerHistoryUpdateData_Variable_->getDataValue(dataValue);
    }

    bool
    OperationLimitsType::get_MaxNodesPerHistoryUpdateEvents_Variable(OpcUaDataValue& dataValue)
    {
        return maxNodesPerHistoryUpdateEvents_Variable_->getDataValue(dataValue);
    }

    bool
    OperationLimitsType::get_MaxNodesPerMethodCall_Variable(OpcUaDataValue& dataValue)
    {
        return maxNodesPerMethodCall_Variable_->getDataValue(dataValue);
    }

    bool
    OperationLimitsType::get_MaxNodesPerNodeManagement_Variable(OpcUaDataValue& dataValue)
    {
        return maxNodesPerNodeManagement_Variable_->getDataValue(dataValue);
    }

    bool
    OperationLimitsType::get_MaxNodesPerRead_Variable(OpcUaDataValue& dataValue)
    {
        return maxNodesPerRead_Variable_->getDataValue(dataValue);
    }

    bool
    OperationLimitsType::get_MaxNodesPerRegisterNodes_Variable(OpcUaDataValue& dataValue)
    {
        return maxNodesPerRegisterNodes_Variable_->getDataValue(dataValue);
    }

    bool
    OperationLimitsType::get_MaxNodesPerTranslateBrowsePathsToNodeIds_Variable(OpcUaDataValue& dataValue)
    {
        return maxNodesPerTranslateBrowsePathsToNodeIds_Variable_->getDataValue(dataValue);
    }

    bool
    OperationLimitsType::get_MaxNodesPerWrite_Variable(OpcUaDataValue& dataValue)
    {
        return maxNodesPerWrite_Variable_->getDataValue(dataValue);
    }

    bool
    OperationLimitsType::set_MaxMonitoredItemsPerCall_Variable(const OpcUaDataValue& dataValue)
    {
        return maxMonitoredItemsPerCall_Variable_->setDataValue(dataValue);
    }

    bool
    OperationLimitsType::set_MaxNodesPerBrowse_Variable(const OpcUaDataValue& dataValue)
    {
        return maxNodesPerBrowse_Variable_->setDataValue(dataValue);
    }

    bool
    OperationLimitsType::set_MaxNodesPerHistoryReadData_Variable(const OpcUaDataValue& dataValue)
    {
        return maxNodesPerHistoryReadData_Variable_->setDataValue(dataValue);
    }

    bool
    OperationLimitsType::set_MaxNodesPerHistoryReadEvents_Variable(const OpcUaDataValue& dataValue)
    {
        return maxNodesPerHistoryReadEvents_Variable_->setDataValue(dataValue);
    }

    bool
    OperationLimitsType::set_MaxNodesPerHistoryUpdateData_Variable(const OpcUaDataValue& dataValue)
    {
        return maxNodesPerHistoryUpdateData_Variable_->setDataValue(dataValue);
    }

    bool
    OperationLimitsType::set_MaxNodesPerHistoryUpdateEvents_Variable(const OpcUaDataValue& dataValue)
    {
        return maxNodesPerHistoryUpdateEvents_Variable_->setDataValue(dataValue);
    }

    bool
    OperationLimitsType::set_MaxNodesPerMethodCall_Variable(const OpcUaDataValue& dataValue)
    {
        return maxNodesPerMethodCall_Variable_->setDataValue(dataValue);
    }

    bool
    OperationLimitsType::set_MaxNodesPerNodeManagement_Variable(const OpcUaDataValue& dataValue)
    {
        return maxNodesPerNodeManagement_Variable_->setDataValue(dataValue);
    }

    bool
    OperationLimitsType::set_MaxNodesPerRead_Variable(const OpcUaDataValue& dataValue)
    {
        return maxNodesPerRead_Variable_->setDataValue(dataValue);
    }

    bool
    OperationLimitsType::set_MaxNodesPerRegisterNodes_Variable(const OpcUaDataValue& dataValue)
    {
        return maxNodesPerRegisterNodes_Variable_->setDataValue(dataValue);
    }

    bool
    OperationLimitsType::set_MaxNodesPerTranslateBrowsePathsToNodeIds_Variable(const OpcUaDataValue& dataValue)
    {
        return maxNodesPerTranslateBrowsePathsToNodeIds_Variable_->setDataValue(dataValue);
    }

    bool
    OperationLimitsType::set_MaxNodesPerWrite_Variable(const OpcUaDataValue& dataValue)
    {
        return maxNodesPerWrite_Variable_->setDataValue(dataValue);
    }

}
