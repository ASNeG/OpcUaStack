/*
    VariableTypeClass: ServerStatusType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_ServerStatusType_h__
#define __OpcUaStackServer_ServerStatusType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT ServerStatusType
   : public VariableBase
   {
     public:
       typedef boost::shared_ptr<ServerStatusType> SPtr;
       typedef std::vector<ServerStatusType::SPtr> Vec;
   
       ServerStatusType(void);
       ServerStatusType(const ServerStatusType& value);
       virtual ~ServerStatusType(void);

        //
        // UtcTime
        //
        void buildInfo_BuildDate_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& buildInfo_BuildDate_Variable(void);
        bool get_BuildInfo_BuildDate_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_BuildInfo_BuildDate_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String
        //
        void buildInfo_BuildNumber_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& buildInfo_BuildNumber_Variable(void);
        bool get_BuildInfo_BuildNumber_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_BuildInfo_BuildNumber_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String
        //
        void buildInfo_ManufacturerName_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& buildInfo_ManufacturerName_Variable(void);
        bool get_BuildInfo_ManufacturerName_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_BuildInfo_ManufacturerName_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String
        //
        void buildInfo_ProductName_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& buildInfo_ProductName_Variable(void);
        bool get_BuildInfo_ProductName_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_BuildInfo_ProductName_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String
        //
        void buildInfo_ProductUri_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& buildInfo_ProductUri_Variable(void);
        bool get_BuildInfo_ProductUri_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_BuildInfo_ProductUri_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String
        //
        void buildInfo_SoftwareVersion_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& buildInfo_SoftwareVersion_Variable(void);
        bool get_BuildInfo_SoftwareVersion_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_BuildInfo_SoftwareVersion_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // BuildInfo
        //
        void buildInfo_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& buildInfo_Variable(void);
        bool get_BuildInfo_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_BuildInfo_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void currentTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& currentTime_Variable(void);
        bool get_CurrentTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_CurrentTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void secondsTillShutdown_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& secondsTillShutdown_Variable(void);
        bool get_SecondsTillShutdown_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SecondsTillShutdown_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void shutdownReason_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& shutdownReason_Variable(void);
        bool get_ShutdownReason_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ShutdownReason_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void startTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& startTime_Variable(void);
        bool get_StartTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_StartTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // ServerState
        //
        void state_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& state_Variable(void);
        bool get_State_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_State_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // ServerStatusDataType (Array)
        //
        void variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& variable(void);
        bool get_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr buildInfo_BuildDate_Variable_;
        ServerVariable::SPtr buildInfo_BuildNumber_Variable_;
        ServerVariable::SPtr buildInfo_ManufacturerName_Variable_;
        ServerVariable::SPtr buildInfo_ProductName_Variable_;
        ServerVariable::SPtr buildInfo_ProductUri_Variable_;
        ServerVariable::SPtr buildInfo_SoftwareVersion_Variable_;
        ServerVariable::SPtr buildInfo_Variable_;
        ServerVariable::SPtr currentTime_Variable_;
        ServerVariable::SPtr secondsTillShutdown_Variable_;
        ServerVariable::SPtr shutdownReason_Variable_;
        ServerVariable::SPtr startTime_Variable_;
        ServerVariable::SPtr state_Variable_;
        ServerVariable::SPtr variable_;
   
   };

}

#endif
