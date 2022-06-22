/*
    ObjectTypeClass: WriterGroupType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_WriterGroupType_h__
#define __OpcUaStackServer_WriterGroupType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT WriterGroupType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<WriterGroupType> SPtr;
       typedef std::vector<WriterGroupType::SPtr> Vec;
   
       WriterGroupType(void);
       WriterGroupType(const WriterGroupType& value);
       virtual ~WriterGroupType(void);

        //
        // Boolean
        //
        void diagnostics_Counters_EncryptionErrors_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_EncryptionErrors_Active_Variable(void);
        bool get_Diagnostics_Counters_EncryptionErrors_Active_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_EncryptionErrors_Active_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void diagnostics_Counters_EncryptionErrors_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_EncryptionErrors_Classification_Variable(void);
        bool get_Diagnostics_Counters_EncryptionErrors_Classification_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_EncryptionErrors_Classification_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void diagnostics_Counters_EncryptionErrors_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_EncryptionErrors_DiagnosticsLevel_Variable(void);
        bool get_Diagnostics_Counters_EncryptionErrors_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_EncryptionErrors_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void diagnostics_Counters_EncryptionErrors_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_EncryptionErrors_TimeFirstChange_Variable(void);
        bool get_Diagnostics_Counters_EncryptionErrors_TimeFirstChange_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_EncryptionErrors_TimeFirstChange_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void diagnostics_Counters_EncryptionErrors_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_EncryptionErrors_Variable(void);
        bool get_Diagnostics_Counters_EncryptionErrors_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_EncryptionErrors_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void diagnostics_Counters_FailedTransmissions_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_FailedTransmissions_Active_Variable(void);
        bool get_Diagnostics_Counters_FailedTransmissions_Active_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_FailedTransmissions_Active_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void diagnostics_Counters_FailedTransmissions_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_FailedTransmissions_Classification_Variable(void);
        bool get_Diagnostics_Counters_FailedTransmissions_Classification_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_FailedTransmissions_Classification_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void diagnostics_Counters_FailedTransmissions_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_FailedTransmissions_DiagnosticsLevel_Variable(void);
        bool get_Diagnostics_Counters_FailedTransmissions_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_FailedTransmissions_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void diagnostics_Counters_FailedTransmissions_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_FailedTransmissions_TimeFirstChange_Variable(void);
        bool get_Diagnostics_Counters_FailedTransmissions_TimeFirstChange_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_FailedTransmissions_TimeFirstChange_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void diagnostics_Counters_FailedTransmissions_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_FailedTransmissions_Variable(void);
        bool get_Diagnostics_Counters_FailedTransmissions_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_FailedTransmissions_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void diagnostics_Counters_SentNetworkMessages_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_SentNetworkMessages_Active_Variable(void);
        bool get_Diagnostics_Counters_SentNetworkMessages_Active_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_SentNetworkMessages_Active_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void diagnostics_Counters_SentNetworkMessages_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_SentNetworkMessages_Classification_Variable(void);
        bool get_Diagnostics_Counters_SentNetworkMessages_Classification_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_SentNetworkMessages_Classification_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void diagnostics_Counters_SentNetworkMessages_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_SentNetworkMessages_DiagnosticsLevel_Variable(void);
        bool get_Diagnostics_Counters_SentNetworkMessages_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_SentNetworkMessages_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void diagnostics_Counters_SentNetworkMessages_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_SentNetworkMessages_TimeFirstChange_Variable(void);
        bool get_Diagnostics_Counters_SentNetworkMessages_TimeFirstChange_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_SentNetworkMessages_TimeFirstChange_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void diagnostics_Counters_SentNetworkMessages_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_SentNetworkMessages_Variable(void);
        bool get_Diagnostics_Counters_SentNetworkMessages_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_SentNetworkMessages_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void diagnostics_Counters_StateDisabledByMethod_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateDisabledByMethod_Active_Variable(void);
        bool get_Diagnostics_Counters_StateDisabledByMethod_Active_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateDisabledByMethod_Active_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void diagnostics_Counters_StateDisabledByMethod_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateDisabledByMethod_Classification_Variable(void);
        bool get_Diagnostics_Counters_StateDisabledByMethod_Classification_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateDisabledByMethod_Classification_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(void);
        bool get_Diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable(void);
        bool get_Diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void diagnostics_Counters_StateDisabledByMethod_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateDisabledByMethod_Variable(void);
        bool get_Diagnostics_Counters_StateDisabledByMethod_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateDisabledByMethod_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void diagnostics_Counters_StateError_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateError_Active_Variable(void);
        bool get_Diagnostics_Counters_StateError_Active_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateError_Active_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void diagnostics_Counters_StateError_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateError_Classification_Variable(void);
        bool get_Diagnostics_Counters_StateError_Classification_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateError_Classification_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void diagnostics_Counters_StateError_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateError_DiagnosticsLevel_Variable(void);
        bool get_Diagnostics_Counters_StateError_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateError_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void diagnostics_Counters_StateError_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateError_TimeFirstChange_Variable(void);
        bool get_Diagnostics_Counters_StateError_TimeFirstChange_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateError_TimeFirstChange_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void diagnostics_Counters_StateError_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateError_Variable(void);
        bool get_Diagnostics_Counters_StateError_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateError_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void diagnostics_Counters_StateOperationalByMethod_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateOperationalByMethod_Active_Variable(void);
        bool get_Diagnostics_Counters_StateOperationalByMethod_Active_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateOperationalByMethod_Active_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void diagnostics_Counters_StateOperationalByMethod_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateOperationalByMethod_Classification_Variable(void);
        bool get_Diagnostics_Counters_StateOperationalByMethod_Classification_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateOperationalByMethod_Classification_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(void);
        bool get_Diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable(void);
        bool get_Diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void diagnostics_Counters_StateOperationalByMethod_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateOperationalByMethod_Variable(void);
        bool get_Diagnostics_Counters_StateOperationalByMethod_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateOperationalByMethod_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void diagnostics_Counters_StateOperationalByParent_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateOperationalByParent_Active_Variable(void);
        bool get_Diagnostics_Counters_StateOperationalByParent_Active_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateOperationalByParent_Active_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void diagnostics_Counters_StateOperationalByParent_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateOperationalByParent_Classification_Variable(void);
        bool get_Diagnostics_Counters_StateOperationalByParent_Classification_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateOperationalByParent_Classification_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(void);
        bool get_Diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable(void);
        bool get_Diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void diagnostics_Counters_StateOperationalByParent_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateOperationalByParent_Variable(void);
        bool get_Diagnostics_Counters_StateOperationalByParent_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateOperationalByParent_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void diagnostics_Counters_StateOperationalFromError_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateOperationalFromError_Active_Variable(void);
        bool get_Diagnostics_Counters_StateOperationalFromError_Active_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateOperationalFromError_Active_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void diagnostics_Counters_StateOperationalFromError_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateOperationalFromError_Classification_Variable(void);
        bool get_Diagnostics_Counters_StateOperationalFromError_Classification_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateOperationalFromError_Classification_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(void);
        bool get_Diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable(void);
        bool get_Diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void diagnostics_Counters_StateOperationalFromError_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StateOperationalFromError_Variable(void);
        bool get_Diagnostics_Counters_StateOperationalFromError_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StateOperationalFromError_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void diagnostics_Counters_StatePausedByParent_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StatePausedByParent_Active_Variable(void);
        bool get_Diagnostics_Counters_StatePausedByParent_Active_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StatePausedByParent_Active_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void diagnostics_Counters_StatePausedByParent_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StatePausedByParent_Classification_Variable(void);
        bool get_Diagnostics_Counters_StatePausedByParent_Classification_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StatePausedByParent_Classification_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable(void);
        bool get_Diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable(void);
        bool get_Diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void diagnostics_Counters_StatePausedByParent_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_StatePausedByParent_Variable(void);
        bool get_Diagnostics_Counters_StatePausedByParent_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_StatePausedByParent_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void diagnostics_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_DiagnosticsLevel_Variable(void);
        bool get_Diagnostics_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void diagnostics_LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable(void);
        bool get_Diagnostics_LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt16
        //
        void diagnostics_LiveValues_ConfiguredDataSetWriters_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_LiveValues_ConfiguredDataSetWriters_Variable(void);
        bool get_Diagnostics_LiveValues_ConfiguredDataSetWriters_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_LiveValues_ConfiguredDataSetWriters_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void diagnostics_LiveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_LiveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable(void);
        bool get_Diagnostics_LiveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_LiveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt16
        //
        void diagnostics_LiveValues_OperationalDataSetWriters_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_LiveValues_OperationalDataSetWriters_Variable(void);
        bool get_Diagnostics_LiveValues_OperationalDataSetWriters_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_LiveValues_OperationalDataSetWriters_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void diagnostics_SubError_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_SubError_Variable(void);
        bool get_Diagnostics_SubError_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_SubError_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void diagnostics_TotalError_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_TotalError_Active_Variable(void);
        bool get_Diagnostics_TotalError_Active_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_TotalError_Active_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void diagnostics_TotalError_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_TotalError_Classification_Variable(void);
        bool get_Diagnostics_TotalError_Classification_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_TotalError_Classification_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void diagnostics_TotalError_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_TotalError_DiagnosticsLevel_Variable(void);
        bool get_Diagnostics_TotalError_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_TotalError_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void diagnostics_TotalError_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_TotalError_TimeFirstChange_Variable(void);
        bool get_Diagnostics_TotalError_TimeFirstChange_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_TotalError_TimeFirstChange_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void diagnostics_TotalError_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_TotalError_Variable(void);
        bool get_Diagnostics_TotalError_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_TotalError_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void diagnostics_TotalInformation_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_TotalInformation_Active_Variable(void);
        bool get_Diagnostics_TotalInformation_Active_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_TotalInformation_Active_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void diagnostics_TotalInformation_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_TotalInformation_Classification_Variable(void);
        bool get_Diagnostics_TotalInformation_Classification_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_TotalInformation_Classification_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void diagnostics_TotalInformation_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_TotalInformation_DiagnosticsLevel_Variable(void);
        bool get_Diagnostics_TotalInformation_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_TotalInformation_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void diagnostics_TotalInformation_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_TotalInformation_TimeFirstChange_Variable(void);
        bool get_Diagnostics_TotalInformation_TimeFirstChange_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_TotalInformation_TimeFirstChange_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void diagnostics_TotalInformation_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_TotalInformation_Variable(void);
        bool get_Diagnostics_TotalInformation_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_TotalInformation_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // KeyValuePair (Array)
        //
        void groupProperties_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& groupProperties_Variable(void);
        bool get_GroupProperties_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_GroupProperties_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Duration
        //
        void keepAliveTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& keepAliveTime_Variable(void);
        bool get_KeepAliveTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_KeepAliveTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocaleId (Array)
        //
        void localeIds_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& localeIds_Variable(void);
        bool get_LocaleIds_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LocaleIds_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void maxNetworkMessageSize_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& maxNetworkMessageSize_Variable(void);
        bool get_MaxNetworkMessageSize_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_MaxNetworkMessageSize_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Byte
        //
        void priority_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& priority_Variable(void);
        bool get_Priority_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Priority_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Duration
        //
        void publishingInterval_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& publishingInterval_Variable(void);
        bool get_PublishingInterval_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_PublishingInterval_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String
        //
        void securityGroupId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& securityGroupId_Variable(void);
        bool get_SecurityGroupId_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SecurityGroupId_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // EndpointDescription (Array)
        //
        void securityKeyServices_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& securityKeyServices_Variable(void);
        bool get_SecurityKeyServices_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SecurityKeyServices_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // MessageSecurityMode
        //
        void securityMode_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& securityMode_Variable(void);
        bool get_SecurityMode_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SecurityMode_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // PubSubState
        //
        void status_State_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& status_State_Variable(void);
        bool get_Status_State_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Status_State_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt16
        //
        void writerGroupId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& writerGroupId_Variable(void);
        bool get_WriterGroupId_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_WriterGroupId_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        virtual void call_AddDataSetWriter_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_Diagnostics_Reset_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_RemoveDataSetWriter_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);
    
      private:
        ServerVariable::SPtr diagnostics_Counters_EncryptionErrors_Active_Variable_;
        ServerVariable::SPtr diagnostics_Counters_EncryptionErrors_Classification_Variable_;
        ServerVariable::SPtr diagnostics_Counters_EncryptionErrors_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr diagnostics_Counters_EncryptionErrors_TimeFirstChange_Variable_;
        ServerVariable::SPtr diagnostics_Counters_EncryptionErrors_Variable_;
        ServerVariable::SPtr diagnostics_Counters_FailedTransmissions_Active_Variable_;
        ServerVariable::SPtr diagnostics_Counters_FailedTransmissions_Classification_Variable_;
        ServerVariable::SPtr diagnostics_Counters_FailedTransmissions_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr diagnostics_Counters_FailedTransmissions_TimeFirstChange_Variable_;
        ServerVariable::SPtr diagnostics_Counters_FailedTransmissions_Variable_;
        ServerVariable::SPtr diagnostics_Counters_SentNetworkMessages_Active_Variable_;
        ServerVariable::SPtr diagnostics_Counters_SentNetworkMessages_Classification_Variable_;
        ServerVariable::SPtr diagnostics_Counters_SentNetworkMessages_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr diagnostics_Counters_SentNetworkMessages_TimeFirstChange_Variable_;
        ServerVariable::SPtr diagnostics_Counters_SentNetworkMessages_Variable_;
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
        ServerVariable::SPtr diagnostics_LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr diagnostics_LiveValues_ConfiguredDataSetWriters_Variable_;
        ServerVariable::SPtr diagnostics_LiveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr diagnostics_LiveValues_OperationalDataSetWriters_Variable_;
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
        ServerVariable::SPtr groupProperties_Variable_;
        ServerVariable::SPtr keepAliveTime_Variable_;
        ServerVariable::SPtr localeIds_Variable_;
        ServerVariable::SPtr maxNetworkMessageSize_Variable_;
        ServerVariable::SPtr priority_Variable_;
        ServerVariable::SPtr publishingInterval_Variable_;
        ServerVariable::SPtr securityGroupId_Variable_;
        ServerVariable::SPtr securityKeyServices_Variable_;
        ServerVariable::SPtr securityMode_Variable_;
        ServerVariable::SPtr status_State_Variable_;
        ServerVariable::SPtr writerGroupId_Variable_;
        ServerMethod::SPtr addDataSetWriter_Method_;
        ServerMethod::SPtr diagnostics_Reset_Method_;
        ServerMethod::SPtr removeDataSetWriter_Method_;
   
   };

}

#endif
