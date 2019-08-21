/*
    ObjectTypeClass: DataSetWriterType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_DataSetWriterType_h__
#define __OpcUaStackServer_DataSetWriterType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT DataSetWriterType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<DataSetWriterType> SPtr;
       typedef std::vector<DataSetWriterType::SPtr> Vec;
   
       DataSetWriterType(void);
       DataSetWriterType(const DataSetWriterType& value);
       virtual ~DataSetWriterType(void);

        //
        // DataSetFieldContentMask
        //
        void dataSetFieldContentMask_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& dataSetFieldContentMask_Variable(void);
        bool get_DataSetFieldContentMask_Variable(OpcUaDataValue& dataValue);
        bool set_DataSetFieldContentMask_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt16
        //
        void dataSetWriterId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& dataSetWriterId_Variable(void);
        bool get_DataSetWriterId_Variable(OpcUaDataValue& dataValue);
        bool set_DataSetWriterId_Variable(const OpcUaDataValue& dataValue);

        //
        // KeyValuePair (Array)
        //
        void dataSetWriterProperties_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& dataSetWriterProperties_Variable(void);
        bool get_DataSetWriterProperties_Variable(OpcUaDataValue& dataValue);
        bool set_DataSetWriterProperties_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void diagnostics_Counters_FailedDataSetMessages_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_FailedDataSetMessages_Active_Variable(void);
        bool get_Diagnostics_Counters_FailedDataSetMessages_Active_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_FailedDataSetMessages_Active_Variable(const OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void diagnostics_Counters_FailedDataSetMessages_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_FailedDataSetMessages_Classification_Variable(void);
        bool get_Diagnostics_Counters_FailedDataSetMessages_Classification_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_FailedDataSetMessages_Classification_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void diagnostics_Counters_FailedDataSetMessages_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_FailedDataSetMessages_DiagnosticsLevel_Variable(void);
        bool get_Diagnostics_Counters_FailedDataSetMessages_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_FailedDataSetMessages_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void diagnostics_Counters_FailedDataSetMessages_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_FailedDataSetMessages_TimeFirstChange_Variable(void);
        bool get_Diagnostics_Counters_FailedDataSetMessages_TimeFirstChange_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_FailedDataSetMessages_TimeFirstChange_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void diagnostics_Counters_FailedDataSetMessages_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_FailedDataSetMessages_Variable(void);
        bool get_Diagnostics_Counters_FailedDataSetMessages_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_FailedDataSetMessages_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void diagnostics_Counters_StateDisabledByMethod_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateDisabledByMethod_Active_Variable(void);
        bool get_Diagnostics_Counters_StateDisabledByMethod_Active_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateDisabledByMethod_Active_Variable(const OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void diagnostics_Counters_StateDisabledByMethod_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateDisabledByMethod_Classification_Variable(void);
        bool get_Diagnostics_Counters_StateDisabledByMethod_Classification_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateDisabledByMethod_Classification_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(void);
        bool get_Diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable(void);
        bool get_Diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void diagnostics_Counters_StateDisabledByMethod_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateDisabledByMethod_Variable(void);
        bool get_Diagnostics_Counters_StateDisabledByMethod_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateDisabledByMethod_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void diagnostics_Counters_StateError_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateError_Active_Variable(void);
        bool get_Diagnostics_Counters_StateError_Active_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateError_Active_Variable(const OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void diagnostics_Counters_StateError_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateError_Classification_Variable(void);
        bool get_Diagnostics_Counters_StateError_Classification_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateError_Classification_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void diagnostics_Counters_StateError_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateError_DiagnosticsLevel_Variable(void);
        bool get_Diagnostics_Counters_StateError_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateError_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void diagnostics_Counters_StateError_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateError_TimeFirstChange_Variable(void);
        bool get_Diagnostics_Counters_StateError_TimeFirstChange_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateError_TimeFirstChange_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void diagnostics_Counters_StateError_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateError_Variable(void);
        bool get_Diagnostics_Counters_StateError_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateError_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void diagnostics_Counters_StateOperationalByMethod_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateOperationalByMethod_Active_Variable(void);
        bool get_Diagnostics_Counters_StateOperationalByMethod_Active_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateOperationalByMethod_Active_Variable(const OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void diagnostics_Counters_StateOperationalByMethod_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateOperationalByMethod_Classification_Variable(void);
        bool get_Diagnostics_Counters_StateOperationalByMethod_Classification_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateOperationalByMethod_Classification_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(void);
        bool get_Diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable(void);
        bool get_Diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void diagnostics_Counters_StateOperationalByMethod_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateOperationalByMethod_Variable(void);
        bool get_Diagnostics_Counters_StateOperationalByMethod_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateOperationalByMethod_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void diagnostics_Counters_StateOperationalByParent_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateOperationalByParent_Active_Variable(void);
        bool get_Diagnostics_Counters_StateOperationalByParent_Active_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateOperationalByParent_Active_Variable(const OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void diagnostics_Counters_StateOperationalByParent_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateOperationalByParent_Classification_Variable(void);
        bool get_Diagnostics_Counters_StateOperationalByParent_Classification_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateOperationalByParent_Classification_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(void);
        bool get_Diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable(void);
        bool get_Diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void diagnostics_Counters_StateOperationalByParent_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateOperationalByParent_Variable(void);
        bool get_Diagnostics_Counters_StateOperationalByParent_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateOperationalByParent_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void diagnostics_Counters_StateOperationalFromError_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateOperationalFromError_Active_Variable(void);
        bool get_Diagnostics_Counters_StateOperationalFromError_Active_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateOperationalFromError_Active_Variable(const OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void diagnostics_Counters_StateOperationalFromError_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateOperationalFromError_Classification_Variable(void);
        bool get_Diagnostics_Counters_StateOperationalFromError_Classification_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateOperationalFromError_Classification_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(void);
        bool get_Diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable(void);
        bool get_Diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void diagnostics_Counters_StateOperationalFromError_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateOperationalFromError_Variable(void);
        bool get_Diagnostics_Counters_StateOperationalFromError_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateOperationalFromError_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void diagnostics_Counters_StatePausedByParent_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StatePausedByParent_Active_Variable(void);
        bool get_Diagnostics_Counters_StatePausedByParent_Active_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StatePausedByParent_Active_Variable(const OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void diagnostics_Counters_StatePausedByParent_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StatePausedByParent_Classification_Variable(void);
        bool get_Diagnostics_Counters_StatePausedByParent_Classification_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StatePausedByParent_Classification_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable(void);
        bool get_Diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable(void);
        bool get_Diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void diagnostics_Counters_StatePausedByParent_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StatePausedByParent_Variable(void);
        bool get_Diagnostics_Counters_StatePausedByParent_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StatePausedByParent_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void diagnostics_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_DiagnosticsLevel_Variable(void);
        bool get_Diagnostics_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void diagnostics_SubError_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_SubError_Variable(void);
        bool get_Diagnostics_SubError_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_SubError_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void diagnostics_TotalError_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_TotalError_Active_Variable(void);
        bool get_Diagnostics_TotalError_Active_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_TotalError_Active_Variable(const OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void diagnostics_TotalError_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_TotalError_Classification_Variable(void);
        bool get_Diagnostics_TotalError_Classification_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_TotalError_Classification_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void diagnostics_TotalError_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_TotalError_DiagnosticsLevel_Variable(void);
        bool get_Diagnostics_TotalError_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_TotalError_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void diagnostics_TotalError_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_TotalError_TimeFirstChange_Variable(void);
        bool get_Diagnostics_TotalError_TimeFirstChange_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_TotalError_TimeFirstChange_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void diagnostics_TotalError_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_TotalError_Variable(void);
        bool get_Diagnostics_TotalError_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_TotalError_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void diagnostics_TotalInformation_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_TotalInformation_Active_Variable(void);
        bool get_Diagnostics_TotalInformation_Active_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_TotalInformation_Active_Variable(const OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void diagnostics_TotalInformation_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_TotalInformation_Classification_Variable(void);
        bool get_Diagnostics_TotalInformation_Classification_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_TotalInformation_Classification_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void diagnostics_TotalInformation_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_TotalInformation_DiagnosticsLevel_Variable(void);
        bool get_Diagnostics_TotalInformation_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_TotalInformation_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void diagnostics_TotalInformation_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_TotalInformation_TimeFirstChange_Variable(void);
        bool get_Diagnostics_TotalInformation_TimeFirstChange_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_TotalInformation_TimeFirstChange_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void diagnostics_TotalInformation_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_TotalInformation_Variable(void);
        bool get_Diagnostics_TotalInformation_Variable(OpcUaDataValue& dataValue);
        bool set_Diagnostics_TotalInformation_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void keyFrameCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& keyFrameCount_Variable(void);
        bool get_KeyFrameCount_Variable(OpcUaDataValue& dataValue);
        bool set_KeyFrameCount_Variable(const OpcUaDataValue& dataValue);

        //
        // PubSubState
        //
        void status_State_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& status_State_Variable(void);
        bool get_Status_State_Variable(OpcUaDataValue& dataValue);
        bool set_Status_State_Variable(const OpcUaDataValue& dataValue);

        virtual void call_Diagnostics_Reset_Method(ApplicationMethodContext* applicationMethodContext);
    
      private:
        ServerVariable::SPtr dataSetFieldContentMask_Variable_;
        ServerVariable::SPtr dataSetWriterId_Variable_;
        ServerVariable::SPtr dataSetWriterProperties_Variable_;
        ServerVariable::SPtr diagnostics_Counters_FailedDataSetMessages_Active_Variable_;
        ServerVariable::SPtr diagnostics_Counters_FailedDataSetMessages_Classification_Variable_;
        ServerVariable::SPtr diagnostics_Counters_FailedDataSetMessages_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr diagnostics_Counters_FailedDataSetMessages_TimeFirstChange_Variable_;
        ServerVariable::SPtr diagnostics_Counters_FailedDataSetMessages_Variable_;
        ServerVariable::SPtr diagnostics_Counters_StateDisabledByMethod_Active_Variable_;
        ServerVariable::SPtr diagnostics_Counters_StateDisabledByMethod_Classification_Variable_;
        ServerVariable::SPtr diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable_;
        ServerVariable::SPtr diagnostics_Counters_StateDisabledByMethod_Variable_;
        ServerVariable::SPtr diagnostics_Counters_StateError_Active_Variable_;
        ServerVariable::SPtr diagnostics_Counters_StateError_Classification_Variable_;
        ServerVariable::SPtr diagnostics_Counters_StateError_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr diagnostics_Counters_StateError_TimeFirstChange_Variable_;
        ServerVariable::SPtr diagnostics_Counters_StateError_Variable_;
        ServerVariable::SPtr diagnostics_Counters_StateOperationalByMethod_Active_Variable_;
        ServerVariable::SPtr diagnostics_Counters_StateOperationalByMethod_Classification_Variable_;
        ServerVariable::SPtr diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable_;
        ServerVariable::SPtr diagnostics_Counters_StateOperationalByMethod_Variable_;
        ServerVariable::SPtr diagnostics_Counters_StateOperationalByParent_Active_Variable_;
        ServerVariable::SPtr diagnostics_Counters_StateOperationalByParent_Classification_Variable_;
        ServerVariable::SPtr diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable_;
        ServerVariable::SPtr diagnostics_Counters_StateOperationalByParent_Variable_;
        ServerVariable::SPtr diagnostics_Counters_StateOperationalFromError_Active_Variable_;
        ServerVariable::SPtr diagnostics_Counters_StateOperationalFromError_Classification_Variable_;
        ServerVariable::SPtr diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable_;
        ServerVariable::SPtr diagnostics_Counters_StateOperationalFromError_Variable_;
        ServerVariable::SPtr diagnostics_Counters_StatePausedByParent_Active_Variable_;
        ServerVariable::SPtr diagnostics_Counters_StatePausedByParent_Classification_Variable_;
        ServerVariable::SPtr diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable_;
        ServerVariable::SPtr diagnostics_Counters_StatePausedByParent_Variable_;
        ServerVariable::SPtr diagnostics_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr diagnostics_SubError_Variable_;
        ServerVariable::SPtr diagnostics_TotalError_Active_Variable_;
        ServerVariable::SPtr diagnostics_TotalError_Classification_Variable_;
        ServerVariable::SPtr diagnostics_TotalError_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr diagnostics_TotalError_TimeFirstChange_Variable_;
        ServerVariable::SPtr diagnostics_TotalError_Variable_;
        ServerVariable::SPtr diagnostics_TotalInformation_Active_Variable_;
        ServerVariable::SPtr diagnostics_TotalInformation_Classification_Variable_;
        ServerVariable::SPtr diagnostics_TotalInformation_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr diagnostics_TotalInformation_TimeFirstChange_Variable_;
        ServerVariable::SPtr diagnostics_TotalInformation_Variable_;
        ServerVariable::SPtr keyFrameCount_Variable_;
        ServerVariable::SPtr status_State_Variable_;
        ServerMethod::SPtr diagnostics_Reset_Method_;
   
   };

}

#endif
