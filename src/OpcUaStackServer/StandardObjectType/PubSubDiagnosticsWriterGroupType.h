/*
    ObjectTypeClass: PubSubDiagnosticsWriterGroupType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_PubSubDiagnosticsWriterGroupType_h__
#define __OpcUaStackServer_PubSubDiagnosticsWriterGroupType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT PubSubDiagnosticsWriterGroupType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<PubSubDiagnosticsWriterGroupType> SPtr;
       typedef std::vector<PubSubDiagnosticsWriterGroupType::SPtr> Vec;
   
       PubSubDiagnosticsWriterGroupType(void);
       PubSubDiagnosticsWriterGroupType(const PubSubDiagnosticsWriterGroupType& value);
       virtual ~PubSubDiagnosticsWriterGroupType(void);

        //
        // Boolean
        //
        void counters_EncryptionErrors_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_EncryptionErrors_Active_Variable(void);
        bool get_Counters_EncryptionErrors_Active_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_EncryptionErrors_Active_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void counters_EncryptionErrors_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_EncryptionErrors_Classification_Variable(void);
        bool get_Counters_EncryptionErrors_Classification_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_EncryptionErrors_Classification_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void counters_EncryptionErrors_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_EncryptionErrors_DiagnosticsLevel_Variable(void);
        bool get_Counters_EncryptionErrors_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_EncryptionErrors_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void counters_EncryptionErrors_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_EncryptionErrors_TimeFirstChange_Variable(void);
        bool get_Counters_EncryptionErrors_TimeFirstChange_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_EncryptionErrors_TimeFirstChange_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void counters_EncryptionErrors_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_EncryptionErrors_Variable(void);
        bool get_Counters_EncryptionErrors_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_EncryptionErrors_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void counters_FailedTransmissions_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_FailedTransmissions_Active_Variable(void);
        bool get_Counters_FailedTransmissions_Active_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_FailedTransmissions_Active_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void counters_FailedTransmissions_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_FailedTransmissions_Classification_Variable(void);
        bool get_Counters_FailedTransmissions_Classification_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_FailedTransmissions_Classification_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void counters_FailedTransmissions_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_FailedTransmissions_DiagnosticsLevel_Variable(void);
        bool get_Counters_FailedTransmissions_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_FailedTransmissions_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void counters_FailedTransmissions_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_FailedTransmissions_TimeFirstChange_Variable(void);
        bool get_Counters_FailedTransmissions_TimeFirstChange_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_FailedTransmissions_TimeFirstChange_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void counters_FailedTransmissions_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_FailedTransmissions_Variable(void);
        bool get_Counters_FailedTransmissions_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_FailedTransmissions_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void counters_SentNetworkMessages_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_SentNetworkMessages_Active_Variable(void);
        bool get_Counters_SentNetworkMessages_Active_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_SentNetworkMessages_Active_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void counters_SentNetworkMessages_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_SentNetworkMessages_Classification_Variable(void);
        bool get_Counters_SentNetworkMessages_Classification_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_SentNetworkMessages_Classification_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void counters_SentNetworkMessages_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_SentNetworkMessages_DiagnosticsLevel_Variable(void);
        bool get_Counters_SentNetworkMessages_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_SentNetworkMessages_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void counters_SentNetworkMessages_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_SentNetworkMessages_TimeFirstChange_Variable(void);
        bool get_Counters_SentNetworkMessages_TimeFirstChange_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_SentNetworkMessages_TimeFirstChange_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void counters_SentNetworkMessages_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_SentNetworkMessages_Variable(void);
        bool get_Counters_SentNetworkMessages_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_SentNetworkMessages_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void counters_StateDisabledByMethod_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateDisabledByMethod_Active_Variable(void);
        bool get_Counters_StateDisabledByMethod_Active_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateDisabledByMethod_Active_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void counters_StateDisabledByMethod_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateDisabledByMethod_Classification_Variable(void);
        bool get_Counters_StateDisabledByMethod_Classification_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateDisabledByMethod_Classification_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void counters_StateDisabledByMethod_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateDisabledByMethod_DiagnosticsLevel_Variable(void);
        bool get_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void counters_StateDisabledByMethod_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateDisabledByMethod_TimeFirstChange_Variable(void);
        bool get_Counters_StateDisabledByMethod_TimeFirstChange_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateDisabledByMethod_TimeFirstChange_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void counters_StateDisabledByMethod_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateDisabledByMethod_Variable(void);
        bool get_Counters_StateDisabledByMethod_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateDisabledByMethod_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void counters_StateError_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateError_Active_Variable(void);
        bool get_Counters_StateError_Active_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateError_Active_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void counters_StateError_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateError_Classification_Variable(void);
        bool get_Counters_StateError_Classification_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateError_Classification_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void counters_StateError_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateError_DiagnosticsLevel_Variable(void);
        bool get_Counters_StateError_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateError_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void counters_StateError_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateError_TimeFirstChange_Variable(void);
        bool get_Counters_StateError_TimeFirstChange_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateError_TimeFirstChange_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void counters_StateError_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateError_Variable(void);
        bool get_Counters_StateError_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateError_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void counters_StateOperationalByMethod_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalByMethod_Active_Variable(void);
        bool get_Counters_StateOperationalByMethod_Active_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalByMethod_Active_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void counters_StateOperationalByMethod_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalByMethod_Classification_Variable(void);
        bool get_Counters_StateOperationalByMethod_Classification_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalByMethod_Classification_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void counters_StateOperationalByMethod_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalByMethod_DiagnosticsLevel_Variable(void);
        bool get_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void counters_StateOperationalByMethod_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalByMethod_TimeFirstChange_Variable(void);
        bool get_Counters_StateOperationalByMethod_TimeFirstChange_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalByMethod_TimeFirstChange_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void counters_StateOperationalByMethod_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalByMethod_Variable(void);
        bool get_Counters_StateOperationalByMethod_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalByMethod_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void counters_StateOperationalByParent_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalByParent_Active_Variable(void);
        bool get_Counters_StateOperationalByParent_Active_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalByParent_Active_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void counters_StateOperationalByParent_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalByParent_Classification_Variable(void);
        bool get_Counters_StateOperationalByParent_Classification_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalByParent_Classification_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void counters_StateOperationalByParent_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalByParent_DiagnosticsLevel_Variable(void);
        bool get_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void counters_StateOperationalByParent_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalByParent_TimeFirstChange_Variable(void);
        bool get_Counters_StateOperationalByParent_TimeFirstChange_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalByParent_TimeFirstChange_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void counters_StateOperationalByParent_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalByParent_Variable(void);
        bool get_Counters_StateOperationalByParent_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalByParent_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void counters_StateOperationalFromError_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalFromError_Active_Variable(void);
        bool get_Counters_StateOperationalFromError_Active_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalFromError_Active_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void counters_StateOperationalFromError_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalFromError_Classification_Variable(void);
        bool get_Counters_StateOperationalFromError_Classification_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalFromError_Classification_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void counters_StateOperationalFromError_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalFromError_DiagnosticsLevel_Variable(void);
        bool get_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void counters_StateOperationalFromError_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalFromError_TimeFirstChange_Variable(void);
        bool get_Counters_StateOperationalFromError_TimeFirstChange_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalFromError_TimeFirstChange_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void counters_StateOperationalFromError_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalFromError_Variable(void);
        bool get_Counters_StateOperationalFromError_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalFromError_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void counters_StatePausedByParent_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StatePausedByParent_Active_Variable(void);
        bool get_Counters_StatePausedByParent_Active_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StatePausedByParent_Active_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void counters_StatePausedByParent_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StatePausedByParent_Classification_Variable(void);
        bool get_Counters_StatePausedByParent_Classification_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StatePausedByParent_Classification_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void counters_StatePausedByParent_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StatePausedByParent_DiagnosticsLevel_Variable(void);
        bool get_Counters_StatePausedByParent_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StatePausedByParent_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void counters_StatePausedByParent_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StatePausedByParent_TimeFirstChange_Variable(void);
        bool get_Counters_StatePausedByParent_TimeFirstChange_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StatePausedByParent_TimeFirstChange_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void counters_StatePausedByParent_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StatePausedByParent_Variable(void);
        bool get_Counters_StatePausedByParent_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StatePausedByParent_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void diagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnosticsLevel_Variable(void);
        bool get_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void liveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& liveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable(void);
        bool get_LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt16
        //
        void liveValues_ConfiguredDataSetWriters_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& liveValues_ConfiguredDataSetWriters_Variable(void);
        bool get_LiveValues_ConfiguredDataSetWriters_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LiveValues_ConfiguredDataSetWriters_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void liveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& liveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable(void);
        bool get_LiveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LiveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt16
        //
        void liveValues_OperationalDataSetWriters_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& liveValues_OperationalDataSetWriters_Variable(void);
        bool get_LiveValues_OperationalDataSetWriters_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LiveValues_OperationalDataSetWriters_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void liveValues_SecurityTokenID_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& liveValues_SecurityTokenID_DiagnosticsLevel_Variable(void);
        bool get_LiveValues_SecurityTokenID_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LiveValues_SecurityTokenID_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void liveValues_SecurityTokenID_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& liveValues_SecurityTokenID_Variable(void);
        bool get_LiveValues_SecurityTokenID_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LiveValues_SecurityTokenID_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void liveValues_TimeToNextTokenID_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& liveValues_TimeToNextTokenID_DiagnosticsLevel_Variable(void);
        bool get_LiveValues_TimeToNextTokenID_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LiveValues_TimeToNextTokenID_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Duration
        //
        void liveValues_TimeToNextTokenID_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& liveValues_TimeToNextTokenID_Variable(void);
        bool get_LiveValues_TimeToNextTokenID_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LiveValues_TimeToNextTokenID_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void subError_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subError_Variable(void);
        bool get_SubError_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SubError_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void totalError_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalError_Active_Variable(void);
        bool get_TotalError_Active_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_TotalError_Active_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void totalError_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalError_Classification_Variable(void);
        bool get_TotalError_Classification_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_TotalError_Classification_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void totalError_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalError_DiagnosticsLevel_Variable(void);
        bool get_TotalError_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_TotalError_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void totalError_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalError_TimeFirstChange_Variable(void);
        bool get_TotalError_TimeFirstChange_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_TotalError_TimeFirstChange_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void totalError_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalError_Variable(void);
        bool get_TotalError_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_TotalError_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void totalInformation_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalInformation_Active_Variable(void);
        bool get_TotalInformation_Active_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_TotalInformation_Active_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void totalInformation_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalInformation_Classification_Variable(void);
        bool get_TotalInformation_Classification_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_TotalInformation_Classification_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void totalInformation_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalInformation_DiagnosticsLevel_Variable(void);
        bool get_TotalInformation_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_TotalInformation_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void totalInformation_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalInformation_TimeFirstChange_Variable(void);
        bool get_TotalInformation_TimeFirstChange_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_TotalInformation_TimeFirstChange_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void totalInformation_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalInformation_Variable(void);
        bool get_TotalInformation_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_TotalInformation_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        virtual void call_Reset_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);
    
      private:
        ServerVariable::SPtr counters_EncryptionErrors_Active_Variable_;
        ServerVariable::SPtr counters_EncryptionErrors_Classification_Variable_;
        ServerVariable::SPtr counters_EncryptionErrors_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr counters_EncryptionErrors_TimeFirstChange_Variable_;
        ServerVariable::SPtr counters_EncryptionErrors_Variable_;
        ServerVariable::SPtr counters_FailedTransmissions_Active_Variable_;
        ServerVariable::SPtr counters_FailedTransmissions_Classification_Variable_;
        ServerVariable::SPtr counters_FailedTransmissions_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr counters_FailedTransmissions_TimeFirstChange_Variable_;
        ServerVariable::SPtr counters_FailedTransmissions_Variable_;
        ServerVariable::SPtr counters_SentNetworkMessages_Active_Variable_;
        ServerVariable::SPtr counters_SentNetworkMessages_Classification_Variable_;
        ServerVariable::SPtr counters_SentNetworkMessages_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr counters_SentNetworkMessages_TimeFirstChange_Variable_;
        ServerVariable::SPtr counters_SentNetworkMessages_Variable_;
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
        ServerVariable::SPtr liveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr liveValues_ConfiguredDataSetWriters_Variable_;
        ServerVariable::SPtr liveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr liveValues_OperationalDataSetWriters_Variable_;
        ServerVariable::SPtr liveValues_SecurityTokenID_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr liveValues_SecurityTokenID_Variable_;
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
