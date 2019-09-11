/*
    ObjectTypeClass: OperationLimitsType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_OperationLimitsType_h__
#define __OpcUaStackServer_OperationLimitsType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT OperationLimitsType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<OperationLimitsType> SPtr;
       typedef std::vector<OperationLimitsType::SPtr> Vec;
   
       OperationLimitsType(void);
       OperationLimitsType(const OperationLimitsType& value);
       virtual ~OperationLimitsType(void);

        //
        // UInt32
        //
        void maxMonitoredItemsPerCall_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& maxMonitoredItemsPerCall_Variable(void);
        bool get_MaxMonitoredItemsPerCall_Variable(OpcUaDataValue& dataValue);
        bool set_MaxMonitoredItemsPerCall_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void maxNodesPerBrowse_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& maxNodesPerBrowse_Variable(void);
        bool get_MaxNodesPerBrowse_Variable(OpcUaDataValue& dataValue);
        bool set_MaxNodesPerBrowse_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void maxNodesPerHistoryReadData_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& maxNodesPerHistoryReadData_Variable(void);
        bool get_MaxNodesPerHistoryReadData_Variable(OpcUaDataValue& dataValue);
        bool set_MaxNodesPerHistoryReadData_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void maxNodesPerHistoryReadEvents_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& maxNodesPerHistoryReadEvents_Variable(void);
        bool get_MaxNodesPerHistoryReadEvents_Variable(OpcUaDataValue& dataValue);
        bool set_MaxNodesPerHistoryReadEvents_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void maxNodesPerHistoryUpdateData_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& maxNodesPerHistoryUpdateData_Variable(void);
        bool get_MaxNodesPerHistoryUpdateData_Variable(OpcUaDataValue& dataValue);
        bool set_MaxNodesPerHistoryUpdateData_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void maxNodesPerHistoryUpdateEvents_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& maxNodesPerHistoryUpdateEvents_Variable(void);
        bool get_MaxNodesPerHistoryUpdateEvents_Variable(OpcUaDataValue& dataValue);
        bool set_MaxNodesPerHistoryUpdateEvents_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void maxNodesPerMethodCall_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& maxNodesPerMethodCall_Variable(void);
        bool get_MaxNodesPerMethodCall_Variable(OpcUaDataValue& dataValue);
        bool set_MaxNodesPerMethodCall_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void maxNodesPerNodeManagement_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& maxNodesPerNodeManagement_Variable(void);
        bool get_MaxNodesPerNodeManagement_Variable(OpcUaDataValue& dataValue);
        bool set_MaxNodesPerNodeManagement_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void maxNodesPerRead_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& maxNodesPerRead_Variable(void);
        bool get_MaxNodesPerRead_Variable(OpcUaDataValue& dataValue);
        bool set_MaxNodesPerRead_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void maxNodesPerRegisterNodes_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& maxNodesPerRegisterNodes_Variable(void);
        bool get_MaxNodesPerRegisterNodes_Variable(OpcUaDataValue& dataValue);
        bool set_MaxNodesPerRegisterNodes_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void maxNodesPerTranslateBrowsePathsToNodeIds_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& maxNodesPerTranslateBrowsePathsToNodeIds_Variable(void);
        bool get_MaxNodesPerTranslateBrowsePathsToNodeIds_Variable(OpcUaDataValue& dataValue);
        bool set_MaxNodesPerTranslateBrowsePathsToNodeIds_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void maxNodesPerWrite_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& maxNodesPerWrite_Variable(void);
        bool get_MaxNodesPerWrite_Variable(OpcUaDataValue& dataValue);
        bool set_MaxNodesPerWrite_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr maxMonitoredItemsPerCall_Variable_;
        ServerVariable::SPtr maxNodesPerBrowse_Variable_;
        ServerVariable::SPtr maxNodesPerHistoryReadData_Variable_;
        ServerVariable::SPtr maxNodesPerHistoryReadEvents_Variable_;
        ServerVariable::SPtr maxNodesPerHistoryUpdateData_Variable_;
        ServerVariable::SPtr maxNodesPerHistoryUpdateEvents_Variable_;
        ServerVariable::SPtr maxNodesPerMethodCall_Variable_;
        ServerVariable::SPtr maxNodesPerNodeManagement_Variable_;
        ServerVariable::SPtr maxNodesPerRead_Variable_;
        ServerVariable::SPtr maxNodesPerRegisterNodes_Variable_;
        ServerVariable::SPtr maxNodesPerTranslateBrowsePathsToNodeIds_Variable_;
        ServerVariable::SPtr maxNodesPerWrite_Variable_;
   
   };

}

#endif
