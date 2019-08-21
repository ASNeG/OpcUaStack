/*
    ObjectTypeClass: AlarmMetricsType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_AlarmMetricsType_h__
#define __OpcUaStackServer_AlarmMetricsType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT AlarmMetricsType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<AlarmMetricsType> SPtr;
       typedef std::vector<AlarmMetricsType::SPtr> Vec;
   
       AlarmMetricsType(void);
       AlarmMetricsType(const AlarmMetricsType& value);
       virtual ~AlarmMetricsType(void);

        //
        // UInt32
        //
        void alarmCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& alarmCount_Variable(void);
        bool get_AlarmCount_Variable(OpcUaDataValue& dataValue);
        bool set_AlarmCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt16
        //
        void averageAlarmRate_Rate_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& averageAlarmRate_Rate_Variable(void);
        bool get_AverageAlarmRate_Rate_Variable(OpcUaDataValue& dataValue);
        bool set_AverageAlarmRate_Rate_Variable(const OpcUaDataValue& dataValue);

        //
        // Double
        //
        void averageAlarmRate_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& averageAlarmRate_Variable(void);
        bool get_AverageAlarmRate_Variable(OpcUaDataValue& dataValue);
        bool set_AverageAlarmRate_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt16
        //
        void currentAlarmRate_Rate_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& currentAlarmRate_Rate_Variable(void);
        bool get_CurrentAlarmRate_Rate_Variable(OpcUaDataValue& dataValue);
        bool set_CurrentAlarmRate_Rate_Variable(const OpcUaDataValue& dataValue);

        //
        // Double
        //
        void currentAlarmRate_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& currentAlarmRate_Variable(void);
        bool get_CurrentAlarmRate_Variable(OpcUaDataValue& dataValue);
        bool set_CurrentAlarmRate_Variable(const OpcUaDataValue& dataValue);

        //
        // Duration
        //
        void maximumActiveState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& maximumActiveState_Variable(void);
        bool get_MaximumActiveState_Variable(OpcUaDataValue& dataValue);
        bool set_MaximumActiveState_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt16
        //
        void maximumAlarmRate_Rate_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& maximumAlarmRate_Rate_Variable(void);
        bool get_MaximumAlarmRate_Rate_Variable(OpcUaDataValue& dataValue);
        bool set_MaximumAlarmRate_Rate_Variable(const OpcUaDataValue& dataValue);

        //
        // Double
        //
        void maximumAlarmRate_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& maximumAlarmRate_Variable(void);
        bool get_MaximumAlarmRate_Variable(OpcUaDataValue& dataValue);
        bool set_MaximumAlarmRate_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void maximumReAlarmCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& maximumReAlarmCount_Variable(void);
        bool get_MaximumReAlarmCount_Variable(OpcUaDataValue& dataValue);
        bool set_MaximumReAlarmCount_Variable(const OpcUaDataValue& dataValue);

        //
        // Duration
        //
        void maximumUnAck_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& maximumUnAck_Variable(void);
        bool get_MaximumUnAck_Variable(OpcUaDataValue& dataValue);
        bool set_MaximumUnAck_Variable(const OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void startTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& startTime_Variable(void);
        bool get_StartTime_Variable(OpcUaDataValue& dataValue);
        bool set_StartTime_Variable(const OpcUaDataValue& dataValue);

        virtual void call_Reset_Method(ApplicationMethodContext* applicationMethodContext);
    
      private:
        ServerVariable::SPtr alarmCount_Variable_;
        ServerVariable::SPtr averageAlarmRate_Rate_Variable_;
        ServerVariable::SPtr averageAlarmRate_Variable_;
        ServerVariable::SPtr currentAlarmRate_Rate_Variable_;
        ServerVariable::SPtr currentAlarmRate_Variable_;
        ServerVariable::SPtr maximumActiveState_Variable_;
        ServerVariable::SPtr maximumAlarmRate_Rate_Variable_;
        ServerVariable::SPtr maximumAlarmRate_Variable_;
        ServerVariable::SPtr maximumReAlarmCount_Variable_;
        ServerVariable::SPtr maximumUnAck_Variable_;
        ServerVariable::SPtr startTime_Variable_;
        ServerMethod::SPtr reset_Method_;
   
   };

}

#endif
