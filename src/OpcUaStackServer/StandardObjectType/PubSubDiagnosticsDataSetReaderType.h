/*
    ObjectTypeClass: PubSubDiagnosticsDataSetReaderType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_PubSubDiagnosticsDataSetReaderType_h__
#define __OpcUaStackServer_PubSubDiagnosticsDataSetReaderType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT PubSubDiagnosticsDataSetReaderType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<PubSubDiagnosticsDataSetReaderType> SPtr;
       typedef std::vector<PubSubDiagnosticsDataSetReaderType::SPtr> Vec;
   
       PubSubDiagnosticsDataSetReaderType(void);
       PubSubDiagnosticsDataSetReaderType(const PubSubDiagnosticsDataSetReaderType& value);
       virtual ~PubSubDiagnosticsDataSetReaderType(void);

        //
        // Boolean
        //
        void counters_DecryptionErrors_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_DecryptionErrors_Active_Variable(void);
        bool get_Counters_DecryptionErrors_Active_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_DecryptionErrors_Active_Variable(const OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void counters_DecryptionErrors_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_DecryptionErrors_Classification_Variable(void);
        bool get_Counters_DecryptionErrors_Classification_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_DecryptionErrors_Classification_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void counters_DecryptionErrors_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_DecryptionErrors_DiagnosticsLevel_Variable(void);
        bool get_Counters_DecryptionErrors_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_DecryptionErrors_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void counters_DecryptionErrors_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_DecryptionErrors_TimeFirstChange_Variable(void);
        bool get_Counters_DecryptionErrors_TimeFirstChange_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_DecryptionErrors_TimeFirstChange_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void counters_DecryptionErrors_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_DecryptionErrors_Variable(void);
        bool get_Counters_DecryptionErrors_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_DecryptionErrors_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void counters_FailedDataSetMessages_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_FailedDataSetMessages_Active_Variable(void);
        bool get_Counters_FailedDataSetMessages_Active_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_FailedDataSetMessages_Active_Variable(const OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void counters_FailedDataSetMessages_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_FailedDataSetMessages_Classification_Variable(void);
        bool get_Counters_FailedDataSetMessages_Classification_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_FailedDataSetMessages_Classification_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void counters_FailedDataSetMessages_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_FailedDataSetMessages_DiagnosticsLevel_Variable(void);
        bool get_Counters_FailedDataSetMessages_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_FailedDataSetMessages_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void counters_FailedDataSetMessages_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_FailedDataSetMessages_TimeFirstChange_Variable(void);
        bool get_Counters_FailedDataSetMessages_TimeFirstChange_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_FailedDataSetMessages_TimeFirstChange_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void counters_FailedDataSetMessages_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_FailedDataSetMessages_Variable(void);
        bool get_Counters_FailedDataSetMessages_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_FailedDataSetMessages_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void counters_StateDisabledByMethod_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateDisabledByMethod_Active_Variable(void);
        bool get_Counters_StateDisabledByMethod_Active_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateDisabledByMethod_Active_Variable(const OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void counters_StateDisabledByMethod_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateDisabledByMethod_Classification_Variable(void);
        bool get_Counters_StateDisabledByMethod_Classification_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateDisabledByMethod_Classification_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void counters_StateDisabledByMethod_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateDisabledByMethod_DiagnosticsLevel_Variable(void);
        bool get_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void counters_StateDisabledByMethod_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateDisabledByMethod_TimeFirstChange_Variable(void);
        bool get_Counters_StateDisabledByMethod_TimeFirstChange_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateDisabledByMethod_TimeFirstChange_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void counters_StateDisabledByMethod_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateDisabledByMethod_Variable(void);
        bool get_Counters_StateDisabledByMethod_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateDisabledByMethod_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void counters_StateError_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateError_Active_Variable(void);
        bool get_Counters_StateError_Active_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateError_Active_Variable(const OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void counters_StateError_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateError_Classification_Variable(void);
        bool get_Counters_StateError_Classification_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateError_Classification_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void counters_StateError_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateError_DiagnosticsLevel_Variable(void);
        bool get_Counters_StateError_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateError_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void counters_StateError_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateError_TimeFirstChange_Variable(void);
        bool get_Counters_StateError_TimeFirstChange_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateError_TimeFirstChange_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void counters_StateError_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateError_Variable(void);
        bool get_Counters_StateError_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateError_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void counters_StateOperationalByMethod_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalByMethod_Active_Variable(void);
        bool get_Counters_StateOperationalByMethod_Active_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalByMethod_Active_Variable(const OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void counters_StateOperationalByMethod_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalByMethod_Classification_Variable(void);
        bool get_Counters_StateOperationalByMethod_Classification_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalByMethod_Classification_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void counters_StateOperationalByMethod_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalByMethod_DiagnosticsLevel_Variable(void);
        bool get_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void counters_StateOperationalByMethod_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalByMethod_TimeFirstChange_Variable(void);
        bool get_Counters_StateOperationalByMethod_TimeFirstChange_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalByMethod_TimeFirstChange_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void counters_StateOperationalByMethod_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalByMethod_Variable(void);
        bool get_Counters_StateOperationalByMethod_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalByMethod_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void counters_StateOperationalByParent_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalByParent_Active_Variable(void);
        bool get_Counters_StateOperationalByParent_Active_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalByParent_Active_Variable(const OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void counters_StateOperationalByParent_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalByParent_Classification_Variable(void);
        bool get_Counters_StateOperationalByParent_Classification_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalByParent_Classification_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void counters_StateOperationalByParent_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalByParent_DiagnosticsLevel_Variable(void);
        bool get_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void counters_StateOperationalByParent_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalByParent_TimeFirstChange_Variable(void);
        bool get_Counters_StateOperationalByParent_TimeFirstChange_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalByParent_TimeFirstChange_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void counters_StateOperationalByParent_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalByParent_Variable(void);
        bool get_Counters_StateOperationalByParent_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalByParent_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void counters_StateOperationalFromError_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalFromError_Active_Variable(void);
        bool get_Counters_StateOperationalFromError_Active_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalFromError_Active_Variable(const OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void counters_StateOperationalFromError_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalFromError_Classification_Variable(void);
        bool get_Counters_StateOperationalFromError_Classification_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalFromError_Classification_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void counters_StateOperationalFromError_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalFromError_DiagnosticsLevel_Variable(void);
        bool get_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void counters_StateOperationalFromError_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalFromError_TimeFirstChange_Variable(void);
        bool get_Counters_StateOperationalFromError_TimeFirstChange_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalFromError_TimeFirstChange_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void counters_StateOperationalFromError_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalFromError_Variable(void);
        bool get_Counters_StateOperationalFromError_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalFromError_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void counters_StatePausedByParent_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StatePausedByParent_Active_Variable(void);
        bool get_Counters_StatePausedByParent_Active_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StatePausedByParent_Active_Variable(const OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void counters_StatePausedByParent_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StatePausedByParent_Classification_Variable(void);
        bool get_Counters_StatePausedByParent_Classification_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StatePausedByParent_Classification_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void counters_StatePausedByParent_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StatePausedByParent_DiagnosticsLevel_Variable(void);
        bool get_Counters_StatePausedByParent_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StatePausedByParent_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void counters_StatePausedByParent_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StatePausedByParent_TimeFirstChange_Variable(void);
        bool get_Counters_StatePausedByParent_TimeFirstChange_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StatePausedByParent_TimeFirstChange_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void counters_StatePausedByParent_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StatePausedByParent_Variable(void);
        bool get_Counters_StatePausedByParent_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StatePausedByParent_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void diagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnosticsLevel_Variable(void);
        bool get_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void liveValues_MajorVersion_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& liveValues_MajorVersion_DiagnosticsLevel_Variable(void);
        bool get_LiveValues_MajorVersion_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_LiveValues_MajorVersion_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void liveValues_MajorVersion_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& liveValues_MajorVersion_Variable(void);
        bool get_LiveValues_MajorVersion_Variable(OpcUaDataValue& dataValue);
        bool set_LiveValues_MajorVersion_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void liveValues_MessageSequenceNumber_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& liveValues_MessageSequenceNumber_DiagnosticsLevel_Variable(void);
        bool get_LiveValues_MessageSequenceNumber_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_LiveValues_MessageSequenceNumber_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt16
        //
        void liveValues_MessageSequenceNumber_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& liveValues_MessageSequenceNumber_Variable(void);
        bool get_LiveValues_MessageSequenceNumber_Variable(OpcUaDataValue& dataValue);
        bool set_LiveValues_MessageSequenceNumber_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void liveValues_MinorVersion_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& liveValues_MinorVersion_DiagnosticsLevel_Variable(void);
        bool get_LiveValues_MinorVersion_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_LiveValues_MinorVersion_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void liveValues_MinorVersion_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& liveValues_MinorVersion_Variable(void);
        bool get_LiveValues_MinorVersion_Variable(OpcUaDataValue& dataValue);
        bool set_LiveValues_MinorVersion_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void liveValues_SecurityTokenID_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& liveValues_SecurityTokenID_DiagnosticsLevel_Variable(void);
        bool get_LiveValues_SecurityTokenID_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_LiveValues_SecurityTokenID_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void liveValues_SecurityTokenID_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& liveValues_SecurityTokenID_Variable(void);
        bool get_LiveValues_SecurityTokenID_Variable(OpcUaDataValue& dataValue);
        bool set_LiveValues_SecurityTokenID_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void liveValues_StatusCode_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& liveValues_StatusCode_DiagnosticsLevel_Variable(void);
        bool get_LiveValues_StatusCode_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_LiveValues_StatusCode_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // Status
        //
        void liveValues_StatusCode_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& liveValues_StatusCode_Variable(void);
        bool get_LiveValues_StatusCode_Variable(OpcUaDataValue& dataValue);
        bool set_LiveValues_StatusCode_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void liveValues_TimeToNextTokenID_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& liveValues_TimeToNextTokenID_DiagnosticsLevel_Variable(void);
        bool get_LiveValues_TimeToNextTokenID_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_LiveValues_TimeToNextTokenID_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // Duration
        //
        void liveValues_TimeToNextTokenID_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& liveValues_TimeToNextTokenID_Variable(void);
        bool get_LiveValues_TimeToNextTokenID_Variable(OpcUaDataValue& dataValue);
        bool set_LiveValues_TimeToNextTokenID_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void subError_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subError_Variable(void);
        bool get_SubError_Variable(OpcUaDataValue& dataValue);
        bool set_SubError_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void totalError_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalError_Active_Variable(void);
        bool get_TotalError_Active_Variable(OpcUaDataValue& dataValue);
        bool set_TotalError_Active_Variable(const OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void totalError_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalError_Classification_Variable(void);
        bool get_TotalError_Classification_Variable(OpcUaDataValue& dataValue);
        bool set_TotalError_Classification_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void totalError_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalError_DiagnosticsLevel_Variable(void);
        bool get_TotalError_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_TotalError_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void totalError_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalError_TimeFirstChange_Variable(void);
        bool get_TotalError_TimeFirstChange_Variable(OpcUaDataValue& dataValue);
        bool set_TotalError_TimeFirstChange_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void totalError_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalError_Variable(void);
        bool get_TotalError_Variable(OpcUaDataValue& dataValue);
        bool set_TotalError_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void totalInformation_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalInformation_Active_Variable(void);
        bool get_TotalInformation_Active_Variable(OpcUaDataValue& dataValue);
        bool set_TotalInformation_Active_Variable(const OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void totalInformation_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalInformation_Classification_Variable(void);
        bool get_TotalInformation_Classification_Variable(OpcUaDataValue& dataValue);
        bool set_TotalInformation_Classification_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void totalInformation_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalInformation_DiagnosticsLevel_Variable(void);
        bool get_TotalInformation_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_TotalInformation_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void totalInformation_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalInformation_TimeFirstChange_Variable(void);
        bool get_TotalInformation_TimeFirstChange_Variable(OpcUaDataValue& dataValue);
        bool set_TotalInformation_TimeFirstChange_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void totalInformation_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalInformation_Variable(void);
        bool get_TotalInformation_Variable(OpcUaDataValue& dataValue);
        bool set_TotalInformation_Variable(const OpcUaDataValue& dataValue);

        virtual void call_Reset_Method(ApplicationMethodContext* applicationMethodContext);
    
      private:
        ServerVariable::SPtr counters_DecryptionErrors_Active_Variable_;
        ServerVariable::SPtr counters_DecryptionErrors_Classification_Variable_;
        ServerVariable::SPtr counters_DecryptionErrors_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr counters_DecryptionErrors_TimeFirstChange_Variable_;
        ServerVariable::SPtr counters_DecryptionErrors_Variable_;
        ServerVariable::SPtr counters_FailedDataSetMessages_Active_Variable_;
        ServerVariable::SPtr counters_FailedDataSetMessages_Classification_Variable_;
        ServerVariable::SPtr counters_FailedDataSetMessages_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr counters_FailedDataSetMessages_TimeFirstChange_Variable_;
        ServerVariable::SPtr counters_FailedDataSetMessages_Variable_;
        ServerVariable::SPtr counters_StateDisabledByMethod_Active_Variable_;
        ServerVariable::SPtr counters_StateDisabledByMethod_Classification_Variable_;
        ServerVariable::SPtr counters_StateDisabledByMethod_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr counters_StateDisabledByMethod_TimeFirstChange_Variable_;
        ServerVariable::SPtr counters_StateDisabledByMethod_Variable_;
        ServerVariable::SPtr counters_StateError_Active_Variable_;
        ServerVariable::SPtr counters_StateError_Classification_Variable_;
        ServerVariable::SPtr counters_StateError_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr counters_StateError_TimeFirstChange_Variable_;
        ServerVariable::SPtr counters_StateError_Variable_;
        ServerVariable::SPtr counters_StateOperationalByMethod_Active_Variable_;
        ServerVariable::SPtr counters_StateOperationalByMethod_Classification_Variable_;
        ServerVariable::SPtr counters_StateOperationalByMethod_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr counters_StateOperationalByMethod_TimeFirstChange_Variable_;
        ServerVariable::SPtr counters_StateOperationalByMethod_Variable_;
        ServerVariable::SPtr counters_StateOperationalByParent_Active_Variable_;
        ServerVariable::SPtr counters_StateOperationalByParent_Classification_Variable_;
        ServerVariable::SPtr counters_StateOperationalByParent_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr counters_StateOperationalByParent_TimeFirstChange_Variable_;
        ServerVariable::SPtr counters_StateOperationalByParent_Variable_;
        ServerVariable::SPtr counters_StateOperationalFromError_Active_Variable_;
        ServerVariable::SPtr counters_StateOperationalFromError_Classification_Variable_;
        ServerVariable::SPtr counters_StateOperationalFromError_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr counters_StateOperationalFromError_TimeFirstChange_Variable_;
        ServerVariable::SPtr counters_StateOperationalFromError_Variable_;
        ServerVariable::SPtr counters_StatePausedByParent_Active_Variable_;
        ServerVariable::SPtr counters_StatePausedByParent_Classification_Variable_;
        ServerVariable::SPtr counters_StatePausedByParent_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr counters_StatePausedByParent_TimeFirstChange_Variable_;
        ServerVariable::SPtr counters_StatePausedByParent_Variable_;
        ServerVariable::SPtr diagnosticsLevel_Variable_;
        ServerVariable::SPtr liveValues_MajorVersion_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr liveValues_MajorVersion_Variable_;
        ServerVariable::SPtr liveValues_MessageSequenceNumber_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr liveValues_MessageSequenceNumber_Variable_;
        ServerVariable::SPtr liveValues_MinorVersion_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr liveValues_MinorVersion_Variable_;
        ServerVariable::SPtr liveValues_SecurityTokenID_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr liveValues_SecurityTokenID_Variable_;
        ServerVariable::SPtr liveValues_StatusCode_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr liveValues_StatusCode_Variable_;
        ServerVariable::SPtr liveValues_TimeToNextTokenID_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr liveValues_TimeToNextTokenID_Variable_;
        ServerVariable::SPtr subError_Variable_;
        ServerVariable::SPtr totalError_Active_Variable_;
        ServerVariable::SPtr totalError_Classification_Variable_;
        ServerVariable::SPtr totalError_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr totalError_TimeFirstChange_Variable_;
        ServerVariable::SPtr totalError_Variable_;
        ServerVariable::SPtr totalInformation_Active_Variable_;
        ServerVariable::SPtr totalInformation_Classification_Variable_;
        ServerVariable::SPtr totalInformation_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr totalInformation_TimeFirstChange_Variable_;
        ServerVariable::SPtr totalInformation_Variable_;
        ServerMethod::SPtr reset_Method_;
   
   };

}

#endif
