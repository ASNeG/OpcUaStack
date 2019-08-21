/*
    VariableTypeClass: PubSubDiagnosticsWriterGroupType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/PubSubDiagnosticsWriterGroupType.h"

namespace OpcUaStackServer
{
    
    PubSubDiagnosticsWriterGroupType::PubSubDiagnosticsWriterGroupType(void)
    : ObjectBase()
    , counters_EncryptionErrors_Active_Variable_(boost::make_shared<ServerVariable>("Counters_EncryptionErrors_Active_Variable"))
    , counters_EncryptionErrors_Classification_Variable_(boost::make_shared<ServerVariable>("Counters_EncryptionErrors_Classification_Variable"))
    , counters_EncryptionErrors_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Counters_EncryptionErrors_DiagnosticsLevel_Variable"))
    , counters_EncryptionErrors_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Counters_EncryptionErrors_TimeFirstChange_Variable"))
    , counters_EncryptionErrors_Variable_(boost::make_shared<ServerVariable>("Counters_EncryptionErrors_Variable"))
    , counters_FailedTransmissions_Active_Variable_(boost::make_shared<ServerVariable>("Counters_FailedTransmissions_Active_Variable"))
    , counters_FailedTransmissions_Classification_Variable_(boost::make_shared<ServerVariable>("Counters_FailedTransmissions_Classification_Variable"))
    , counters_FailedTransmissions_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Counters_FailedTransmissions_DiagnosticsLevel_Variable"))
    , counters_FailedTransmissions_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Counters_FailedTransmissions_TimeFirstChange_Variable"))
    , counters_FailedTransmissions_Variable_(boost::make_shared<ServerVariable>("Counters_FailedTransmissions_Variable"))
    , counters_SentNetworkMessages_Active_Variable_(boost::make_shared<ServerVariable>("Counters_SentNetworkMessages_Active_Variable"))
    , counters_SentNetworkMessages_Classification_Variable_(boost::make_shared<ServerVariable>("Counters_SentNetworkMessages_Classification_Variable"))
    , counters_SentNetworkMessages_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Counters_SentNetworkMessages_DiagnosticsLevel_Variable"))
    , counters_SentNetworkMessages_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Counters_SentNetworkMessages_TimeFirstChange_Variable"))
    , counters_SentNetworkMessages_Variable_(boost::make_shared<ServerVariable>("Counters_SentNetworkMessages_Variable"))
    , counters_StateDisabledByMethod_Active_Variable_(boost::make_shared<ServerVariable>("Counters_StateDisabledByMethod_Active_Variable"))
    , counters_StateDisabledByMethod_Classification_Variable_(boost::make_shared<ServerVariable>("Counters_StateDisabledByMethod_Classification_Variable"))
    , counters_StateDisabledByMethod_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Counters_StateDisabledByMethod_DiagnosticsLevel_Variable"))
    , counters_StateDisabledByMethod_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Counters_StateDisabledByMethod_TimeFirstChange_Variable"))
    , counters_StateDisabledByMethod_Variable_(boost::make_shared<ServerVariable>("Counters_StateDisabledByMethod_Variable"))
    , counters_StateError_Active_Variable_(boost::make_shared<ServerVariable>("Counters_StateError_Active_Variable"))
    , counters_StateError_Classification_Variable_(boost::make_shared<ServerVariable>("Counters_StateError_Classification_Variable"))
    , counters_StateError_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Counters_StateError_DiagnosticsLevel_Variable"))
    , counters_StateError_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Counters_StateError_TimeFirstChange_Variable"))
    , counters_StateError_Variable_(boost::make_shared<ServerVariable>("Counters_StateError_Variable"))
    , counters_StateOperationalByMethod_Active_Variable_(boost::make_shared<ServerVariable>("Counters_StateOperationalByMethod_Active_Variable"))
    , counters_StateOperationalByMethod_Classification_Variable_(boost::make_shared<ServerVariable>("Counters_StateOperationalByMethod_Classification_Variable"))
    , counters_StateOperationalByMethod_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Counters_StateOperationalByMethod_DiagnosticsLevel_Variable"))
    , counters_StateOperationalByMethod_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Counters_StateOperationalByMethod_TimeFirstChange_Variable"))
    , counters_StateOperationalByMethod_Variable_(boost::make_shared<ServerVariable>("Counters_StateOperationalByMethod_Variable"))
    , counters_StateOperationalByParent_Active_Variable_(boost::make_shared<ServerVariable>("Counters_StateOperationalByParent_Active_Variable"))
    , counters_StateOperationalByParent_Classification_Variable_(boost::make_shared<ServerVariable>("Counters_StateOperationalByParent_Classification_Variable"))
    , counters_StateOperationalByParent_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Counters_StateOperationalByParent_DiagnosticsLevel_Variable"))
    , counters_StateOperationalByParent_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Counters_StateOperationalByParent_TimeFirstChange_Variable"))
    , counters_StateOperationalByParent_Variable_(boost::make_shared<ServerVariable>("Counters_StateOperationalByParent_Variable"))
    , counters_StateOperationalFromError_Active_Variable_(boost::make_shared<ServerVariable>("Counters_StateOperationalFromError_Active_Variable"))
    , counters_StateOperationalFromError_Classification_Variable_(boost::make_shared<ServerVariable>("Counters_StateOperationalFromError_Classification_Variable"))
    , counters_StateOperationalFromError_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Counters_StateOperationalFromError_DiagnosticsLevel_Variable"))
    , counters_StateOperationalFromError_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Counters_StateOperationalFromError_TimeFirstChange_Variable"))
    , counters_StateOperationalFromError_Variable_(boost::make_shared<ServerVariable>("Counters_StateOperationalFromError_Variable"))
    , counters_StatePausedByParent_Active_Variable_(boost::make_shared<ServerVariable>("Counters_StatePausedByParent_Active_Variable"))
    , counters_StatePausedByParent_Classification_Variable_(boost::make_shared<ServerVariable>("Counters_StatePausedByParent_Classification_Variable"))
    , counters_StatePausedByParent_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Counters_StatePausedByParent_DiagnosticsLevel_Variable"))
    , counters_StatePausedByParent_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Counters_StatePausedByParent_TimeFirstChange_Variable"))
    , counters_StatePausedByParent_Variable_(boost::make_shared<ServerVariable>("Counters_StatePausedByParent_Variable"))
    , diagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("DiagnosticsLevel_Variable"))
    , liveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable"))
    , liveValues_ConfiguredDataSetWriters_Variable_(boost::make_shared<ServerVariable>("LiveValues_ConfiguredDataSetWriters_Variable"))
    , liveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("LiveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable"))
    , liveValues_OperationalDataSetWriters_Variable_(boost::make_shared<ServerVariable>("LiveValues_OperationalDataSetWriters_Variable"))
    , liveValues_SecurityTokenID_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("LiveValues_SecurityTokenID_DiagnosticsLevel_Variable"))
    , liveValues_SecurityTokenID_Variable_(boost::make_shared<ServerVariable>("LiveValues_SecurityTokenID_Variable"))
    , liveValues_TimeToNextTokenID_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("LiveValues_TimeToNextTokenID_DiagnosticsLevel_Variable"))
    , liveValues_TimeToNextTokenID_Variable_(boost::make_shared<ServerVariable>("LiveValues_TimeToNextTokenID_Variable"))
    , subError_Variable_(boost::make_shared<ServerVariable>("SubError_Variable"))
    , totalError_Active_Variable_(boost::make_shared<ServerVariable>("TotalError_Active_Variable"))
    , totalError_Classification_Variable_(boost::make_shared<ServerVariable>("TotalError_Classification_Variable"))
    , totalError_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("TotalError_DiagnosticsLevel_Variable"))
    , totalError_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("TotalError_TimeFirstChange_Variable"))
    , totalError_Variable_(boost::make_shared<ServerVariable>("TotalError_Variable"))
    , totalInformation_Active_Variable_(boost::make_shared<ServerVariable>("TotalInformation_Active_Variable"))
    , totalInformation_Classification_Variable_(boost::make_shared<ServerVariable>("TotalInformation_Classification_Variable"))
    , totalInformation_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("TotalInformation_DiagnosticsLevel_Variable"))
    , totalInformation_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("TotalInformation_TimeFirstChange_Variable"))
    , totalInformation_Variable_(boost::make_shared<ServerVariable>("TotalInformation_Variable"))
    , reset_Method_(boost::make_shared<ServerMethod>("Reset_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)19834);
        setServerVariable(counters_EncryptionErrors_Active_Variable_);
        setServerVariable(counters_EncryptionErrors_Classification_Variable_);
        setServerVariable(counters_EncryptionErrors_DiagnosticsLevel_Variable_);
        setServerVariable(counters_EncryptionErrors_TimeFirstChange_Variable_);
        setServerVariable(counters_EncryptionErrors_Variable_);
        setServerVariable(counters_FailedTransmissions_Active_Variable_);
        setServerVariable(counters_FailedTransmissions_Classification_Variable_);
        setServerVariable(counters_FailedTransmissions_DiagnosticsLevel_Variable_);
        setServerVariable(counters_FailedTransmissions_TimeFirstChange_Variable_);
        setServerVariable(counters_FailedTransmissions_Variable_);
        setServerVariable(counters_SentNetworkMessages_Active_Variable_);
        setServerVariable(counters_SentNetworkMessages_Classification_Variable_);
        setServerVariable(counters_SentNetworkMessages_DiagnosticsLevel_Variable_);
        setServerVariable(counters_SentNetworkMessages_TimeFirstChange_Variable_);
        setServerVariable(counters_SentNetworkMessages_Variable_);
        setServerVariable(counters_StateDisabledByMethod_Active_Variable_);
        setServerVariable(counters_StateDisabledByMethod_Classification_Variable_);
        setServerVariable(counters_StateDisabledByMethod_DiagnosticsLevel_Variable_);
        setServerVariable(counters_StateDisabledByMethod_TimeFirstChange_Variable_);
        setServerVariable(counters_StateDisabledByMethod_Variable_);
        setServerVariable(counters_StateError_Active_Variable_);
        setServerVariable(counters_StateError_Classification_Variable_);
        setServerVariable(counters_StateError_DiagnosticsLevel_Variable_);
        setServerVariable(counters_StateError_TimeFirstChange_Variable_);
        setServerVariable(counters_StateError_Variable_);
        setServerVariable(counters_StateOperationalByMethod_Active_Variable_);
        setServerVariable(counters_StateOperationalByMethod_Classification_Variable_);
        setServerVariable(counters_StateOperationalByMethod_DiagnosticsLevel_Variable_);
        setServerVariable(counters_StateOperationalByMethod_TimeFirstChange_Variable_);
        setServerVariable(counters_StateOperationalByMethod_Variable_);
        setServerVariable(counters_StateOperationalByParent_Active_Variable_);
        setServerVariable(counters_StateOperationalByParent_Classification_Variable_);
        setServerVariable(counters_StateOperationalByParent_DiagnosticsLevel_Variable_);
        setServerVariable(counters_StateOperationalByParent_TimeFirstChange_Variable_);
        setServerVariable(counters_StateOperationalByParent_Variable_);
        setServerVariable(counters_StateOperationalFromError_Active_Variable_);
        setServerVariable(counters_StateOperationalFromError_Classification_Variable_);
        setServerVariable(counters_StateOperationalFromError_DiagnosticsLevel_Variable_);
        setServerVariable(counters_StateOperationalFromError_TimeFirstChange_Variable_);
        setServerVariable(counters_StateOperationalFromError_Variable_);
        setServerVariable(counters_StatePausedByParent_Active_Variable_);
        setServerVariable(counters_StatePausedByParent_Classification_Variable_);
        setServerVariable(counters_StatePausedByParent_DiagnosticsLevel_Variable_);
        setServerVariable(counters_StatePausedByParent_TimeFirstChange_Variable_);
        setServerVariable(counters_StatePausedByParent_Variable_);
        setServerVariable(diagnosticsLevel_Variable_);
        setServerVariable(liveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable_);
        setServerVariable(liveValues_ConfiguredDataSetWriters_Variable_);
        setServerVariable(liveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable_);
        setServerVariable(liveValues_OperationalDataSetWriters_Variable_);
        setServerVariable(liveValues_SecurityTokenID_DiagnosticsLevel_Variable_);
        setServerVariable(liveValues_SecurityTokenID_Variable_);
        setServerVariable(liveValues_TimeToNextTokenID_DiagnosticsLevel_Variable_);
        setServerVariable(liveValues_TimeToNextTokenID_Variable_);
        setServerVariable(subError_Variable_);
        setServerVariable(totalError_Active_Variable_);
        setServerVariable(totalError_Classification_Variable_);
        setServerVariable(totalError_DiagnosticsLevel_Variable_);
        setServerVariable(totalError_TimeFirstChange_Variable_);
        setServerVariable(totalError_Variable_);
        setServerVariable(totalInformation_Active_Variable_);
        setServerVariable(totalInformation_Classification_Variable_);
        setServerVariable(totalInformation_DiagnosticsLevel_Variable_);
        setServerVariable(totalInformation_TimeFirstChange_Variable_);
        setServerVariable(totalInformation_Variable_);
        setServerMethod(reset_Method_);
        reset_Method_->registerMethod(boost::bind(&PubSubDiagnosticsWriterGroupType::call_Reset_Method, this, _1));
    }
    
    PubSubDiagnosticsWriterGroupType::PubSubDiagnosticsWriterGroupType(const PubSubDiagnosticsWriterGroupType& value)
    : ObjectBase()
    , counters_EncryptionErrors_Active_Variable_(boost::make_shared<ServerVariable>("Counters_EncryptionErrors_Active_Variable"))
    , counters_EncryptionErrors_Classification_Variable_(boost::make_shared<ServerVariable>("Counters_EncryptionErrors_Classification_Variable"))
    , counters_EncryptionErrors_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Counters_EncryptionErrors_DiagnosticsLevel_Variable"))
    , counters_EncryptionErrors_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Counters_EncryptionErrors_TimeFirstChange_Variable"))
    , counters_EncryptionErrors_Variable_(boost::make_shared<ServerVariable>("Counters_EncryptionErrors_Variable"))
    , counters_FailedTransmissions_Active_Variable_(boost::make_shared<ServerVariable>("Counters_FailedTransmissions_Active_Variable"))
    , counters_FailedTransmissions_Classification_Variable_(boost::make_shared<ServerVariable>("Counters_FailedTransmissions_Classification_Variable"))
    , counters_FailedTransmissions_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Counters_FailedTransmissions_DiagnosticsLevel_Variable"))
    , counters_FailedTransmissions_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Counters_FailedTransmissions_TimeFirstChange_Variable"))
    , counters_FailedTransmissions_Variable_(boost::make_shared<ServerVariable>("Counters_FailedTransmissions_Variable"))
    , counters_SentNetworkMessages_Active_Variable_(boost::make_shared<ServerVariable>("Counters_SentNetworkMessages_Active_Variable"))
    , counters_SentNetworkMessages_Classification_Variable_(boost::make_shared<ServerVariable>("Counters_SentNetworkMessages_Classification_Variable"))
    , counters_SentNetworkMessages_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Counters_SentNetworkMessages_DiagnosticsLevel_Variable"))
    , counters_SentNetworkMessages_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Counters_SentNetworkMessages_TimeFirstChange_Variable"))
    , counters_SentNetworkMessages_Variable_(boost::make_shared<ServerVariable>("Counters_SentNetworkMessages_Variable"))
    , counters_StateDisabledByMethod_Active_Variable_(boost::make_shared<ServerVariable>("Counters_StateDisabledByMethod_Active_Variable"))
    , counters_StateDisabledByMethod_Classification_Variable_(boost::make_shared<ServerVariable>("Counters_StateDisabledByMethod_Classification_Variable"))
    , counters_StateDisabledByMethod_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Counters_StateDisabledByMethod_DiagnosticsLevel_Variable"))
    , counters_StateDisabledByMethod_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Counters_StateDisabledByMethod_TimeFirstChange_Variable"))
    , counters_StateDisabledByMethod_Variable_(boost::make_shared<ServerVariable>("Counters_StateDisabledByMethod_Variable"))
    , counters_StateError_Active_Variable_(boost::make_shared<ServerVariable>("Counters_StateError_Active_Variable"))
    , counters_StateError_Classification_Variable_(boost::make_shared<ServerVariable>("Counters_StateError_Classification_Variable"))
    , counters_StateError_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Counters_StateError_DiagnosticsLevel_Variable"))
    , counters_StateError_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Counters_StateError_TimeFirstChange_Variable"))
    , counters_StateError_Variable_(boost::make_shared<ServerVariable>("Counters_StateError_Variable"))
    , counters_StateOperationalByMethod_Active_Variable_(boost::make_shared<ServerVariable>("Counters_StateOperationalByMethod_Active_Variable"))
    , counters_StateOperationalByMethod_Classification_Variable_(boost::make_shared<ServerVariable>("Counters_StateOperationalByMethod_Classification_Variable"))
    , counters_StateOperationalByMethod_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Counters_StateOperationalByMethod_DiagnosticsLevel_Variable"))
    , counters_StateOperationalByMethod_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Counters_StateOperationalByMethod_TimeFirstChange_Variable"))
    , counters_StateOperationalByMethod_Variable_(boost::make_shared<ServerVariable>("Counters_StateOperationalByMethod_Variable"))
    , counters_StateOperationalByParent_Active_Variable_(boost::make_shared<ServerVariable>("Counters_StateOperationalByParent_Active_Variable"))
    , counters_StateOperationalByParent_Classification_Variable_(boost::make_shared<ServerVariable>("Counters_StateOperationalByParent_Classification_Variable"))
    , counters_StateOperationalByParent_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Counters_StateOperationalByParent_DiagnosticsLevel_Variable"))
    , counters_StateOperationalByParent_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Counters_StateOperationalByParent_TimeFirstChange_Variable"))
    , counters_StateOperationalByParent_Variable_(boost::make_shared<ServerVariable>("Counters_StateOperationalByParent_Variable"))
    , counters_StateOperationalFromError_Active_Variable_(boost::make_shared<ServerVariable>("Counters_StateOperationalFromError_Active_Variable"))
    , counters_StateOperationalFromError_Classification_Variable_(boost::make_shared<ServerVariable>("Counters_StateOperationalFromError_Classification_Variable"))
    , counters_StateOperationalFromError_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Counters_StateOperationalFromError_DiagnosticsLevel_Variable"))
    , counters_StateOperationalFromError_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Counters_StateOperationalFromError_TimeFirstChange_Variable"))
    , counters_StateOperationalFromError_Variable_(boost::make_shared<ServerVariable>("Counters_StateOperationalFromError_Variable"))
    , counters_StatePausedByParent_Active_Variable_(boost::make_shared<ServerVariable>("Counters_StatePausedByParent_Active_Variable"))
    , counters_StatePausedByParent_Classification_Variable_(boost::make_shared<ServerVariable>("Counters_StatePausedByParent_Classification_Variable"))
    , counters_StatePausedByParent_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Counters_StatePausedByParent_DiagnosticsLevel_Variable"))
    , counters_StatePausedByParent_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Counters_StatePausedByParent_TimeFirstChange_Variable"))
    , counters_StatePausedByParent_Variable_(boost::make_shared<ServerVariable>("Counters_StatePausedByParent_Variable"))
    , diagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("DiagnosticsLevel_Variable"))
    , liveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable"))
    , liveValues_ConfiguredDataSetWriters_Variable_(boost::make_shared<ServerVariable>("LiveValues_ConfiguredDataSetWriters_Variable"))
    , liveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("LiveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable"))
    , liveValues_OperationalDataSetWriters_Variable_(boost::make_shared<ServerVariable>("LiveValues_OperationalDataSetWriters_Variable"))
    , liveValues_SecurityTokenID_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("LiveValues_SecurityTokenID_DiagnosticsLevel_Variable"))
    , liveValues_SecurityTokenID_Variable_(boost::make_shared<ServerVariable>("LiveValues_SecurityTokenID_Variable"))
    , liveValues_TimeToNextTokenID_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("LiveValues_TimeToNextTokenID_DiagnosticsLevel_Variable"))
    , liveValues_TimeToNextTokenID_Variable_(boost::make_shared<ServerVariable>("LiveValues_TimeToNextTokenID_Variable"))
    , subError_Variable_(boost::make_shared<ServerVariable>("SubError_Variable"))
    , totalError_Active_Variable_(boost::make_shared<ServerVariable>("TotalError_Active_Variable"))
    , totalError_Classification_Variable_(boost::make_shared<ServerVariable>("TotalError_Classification_Variable"))
    , totalError_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("TotalError_DiagnosticsLevel_Variable"))
    , totalError_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("TotalError_TimeFirstChange_Variable"))
    , totalError_Variable_(boost::make_shared<ServerVariable>("TotalError_Variable"))
    , totalInformation_Active_Variable_(boost::make_shared<ServerVariable>("TotalInformation_Active_Variable"))
    , totalInformation_Classification_Variable_(boost::make_shared<ServerVariable>("TotalInformation_Classification_Variable"))
    , totalInformation_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("TotalInformation_DiagnosticsLevel_Variable"))
    , totalInformation_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("TotalInformation_TimeFirstChange_Variable"))
    , totalInformation_Variable_(boost::make_shared<ServerVariable>("TotalInformation_Variable"))
    , reset_Method_(boost::make_shared<ServerMethod>("Reset_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)19834);
        setServerVariable(counters_EncryptionErrors_Active_Variable_);
        setServerVariable(counters_EncryptionErrors_Classification_Variable_);
        setServerVariable(counters_EncryptionErrors_DiagnosticsLevel_Variable_);
        setServerVariable(counters_EncryptionErrors_TimeFirstChange_Variable_);
        setServerVariable(counters_EncryptionErrors_Variable_);
        setServerVariable(counters_FailedTransmissions_Active_Variable_);
        setServerVariable(counters_FailedTransmissions_Classification_Variable_);
        setServerVariable(counters_FailedTransmissions_DiagnosticsLevel_Variable_);
        setServerVariable(counters_FailedTransmissions_TimeFirstChange_Variable_);
        setServerVariable(counters_FailedTransmissions_Variable_);
        setServerVariable(counters_SentNetworkMessages_Active_Variable_);
        setServerVariable(counters_SentNetworkMessages_Classification_Variable_);
        setServerVariable(counters_SentNetworkMessages_DiagnosticsLevel_Variable_);
        setServerVariable(counters_SentNetworkMessages_TimeFirstChange_Variable_);
        setServerVariable(counters_SentNetworkMessages_Variable_);
        setServerVariable(counters_StateDisabledByMethod_Active_Variable_);
        setServerVariable(counters_StateDisabledByMethod_Classification_Variable_);
        setServerVariable(counters_StateDisabledByMethod_DiagnosticsLevel_Variable_);
        setServerVariable(counters_StateDisabledByMethod_TimeFirstChange_Variable_);
        setServerVariable(counters_StateDisabledByMethod_Variable_);
        setServerVariable(counters_StateError_Active_Variable_);
        setServerVariable(counters_StateError_Classification_Variable_);
        setServerVariable(counters_StateError_DiagnosticsLevel_Variable_);
        setServerVariable(counters_StateError_TimeFirstChange_Variable_);
        setServerVariable(counters_StateError_Variable_);
        setServerVariable(counters_StateOperationalByMethod_Active_Variable_);
        setServerVariable(counters_StateOperationalByMethod_Classification_Variable_);
        setServerVariable(counters_StateOperationalByMethod_DiagnosticsLevel_Variable_);
        setServerVariable(counters_StateOperationalByMethod_TimeFirstChange_Variable_);
        setServerVariable(counters_StateOperationalByMethod_Variable_);
        setServerVariable(counters_StateOperationalByParent_Active_Variable_);
        setServerVariable(counters_StateOperationalByParent_Classification_Variable_);
        setServerVariable(counters_StateOperationalByParent_DiagnosticsLevel_Variable_);
        setServerVariable(counters_StateOperationalByParent_TimeFirstChange_Variable_);
        setServerVariable(counters_StateOperationalByParent_Variable_);
        setServerVariable(counters_StateOperationalFromError_Active_Variable_);
        setServerVariable(counters_StateOperationalFromError_Classification_Variable_);
        setServerVariable(counters_StateOperationalFromError_DiagnosticsLevel_Variable_);
        setServerVariable(counters_StateOperationalFromError_TimeFirstChange_Variable_);
        setServerVariable(counters_StateOperationalFromError_Variable_);
        setServerVariable(counters_StatePausedByParent_Active_Variable_);
        setServerVariable(counters_StatePausedByParent_Classification_Variable_);
        setServerVariable(counters_StatePausedByParent_DiagnosticsLevel_Variable_);
        setServerVariable(counters_StatePausedByParent_TimeFirstChange_Variable_);
        setServerVariable(counters_StatePausedByParent_Variable_);
        setServerVariable(diagnosticsLevel_Variable_);
        setServerVariable(liveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable_);
        setServerVariable(liveValues_ConfiguredDataSetWriters_Variable_);
        setServerVariable(liveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable_);
        setServerVariable(liveValues_OperationalDataSetWriters_Variable_);
        setServerVariable(liveValues_SecurityTokenID_DiagnosticsLevel_Variable_);
        setServerVariable(liveValues_SecurityTokenID_Variable_);
        setServerVariable(liveValues_TimeToNextTokenID_DiagnosticsLevel_Variable_);
        setServerVariable(liveValues_TimeToNextTokenID_Variable_);
        setServerVariable(subError_Variable_);
        setServerVariable(totalError_Active_Variable_);
        setServerVariable(totalError_Classification_Variable_);
        setServerVariable(totalError_DiagnosticsLevel_Variable_);
        setServerVariable(totalError_TimeFirstChange_Variable_);
        setServerVariable(totalError_Variable_);
        setServerVariable(totalInformation_Active_Variable_);
        setServerVariable(totalInformation_Classification_Variable_);
        setServerVariable(totalInformation_DiagnosticsLevel_Variable_);
        setServerVariable(totalInformation_TimeFirstChange_Variable_);
        setServerVariable(totalInformation_Variable_);
        setServerMethod(reset_Method_);
        reset_Method_->registerMethod(boost::bind(&PubSubDiagnosticsWriterGroupType::call_Reset_Method, this, _1));
    }
    
    PubSubDiagnosticsWriterGroupType::~PubSubDiagnosticsWriterGroupType(void)
    {
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_EncryptionErrors_Active_Variable(void)
    {
        return counters_EncryptionErrors_Active_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_EncryptionErrors_Classification_Variable(void)
    {
        return counters_EncryptionErrors_Classification_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_EncryptionErrors_DiagnosticsLevel_Variable(void)
    {
        return counters_EncryptionErrors_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_EncryptionErrors_TimeFirstChange_Variable(void)
    {
        return counters_EncryptionErrors_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_EncryptionErrors_Variable(void)
    {
        return counters_EncryptionErrors_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_FailedTransmissions_Active_Variable(void)
    {
        return counters_FailedTransmissions_Active_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_FailedTransmissions_Classification_Variable(void)
    {
        return counters_FailedTransmissions_Classification_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_FailedTransmissions_DiagnosticsLevel_Variable(void)
    {
        return counters_FailedTransmissions_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_FailedTransmissions_TimeFirstChange_Variable(void)
    {
        return counters_FailedTransmissions_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_FailedTransmissions_Variable(void)
    {
        return counters_FailedTransmissions_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_SentNetworkMessages_Active_Variable(void)
    {
        return counters_SentNetworkMessages_Active_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_SentNetworkMessages_Classification_Variable(void)
    {
        return counters_SentNetworkMessages_Classification_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_SentNetworkMessages_DiagnosticsLevel_Variable(void)
    {
        return counters_SentNetworkMessages_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_SentNetworkMessages_TimeFirstChange_Variable(void)
    {
        return counters_SentNetworkMessages_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_SentNetworkMessages_Variable(void)
    {
        return counters_SentNetworkMessages_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_StateDisabledByMethod_Active_Variable(void)
    {
        return counters_StateDisabledByMethod_Active_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_StateDisabledByMethod_Classification_Variable(void)
    {
        return counters_StateDisabledByMethod_Classification_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_StateDisabledByMethod_DiagnosticsLevel_Variable(void)
    {
        return counters_StateDisabledByMethod_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_StateDisabledByMethod_TimeFirstChange_Variable(void)
    {
        return counters_StateDisabledByMethod_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_StateDisabledByMethod_Variable(void)
    {
        return counters_StateDisabledByMethod_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_StateError_Active_Variable(void)
    {
        return counters_StateError_Active_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_StateError_Classification_Variable(void)
    {
        return counters_StateError_Classification_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_StateError_DiagnosticsLevel_Variable(void)
    {
        return counters_StateError_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_StateError_TimeFirstChange_Variable(void)
    {
        return counters_StateError_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_StateError_Variable(void)
    {
        return counters_StateError_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_StateOperationalByMethod_Active_Variable(void)
    {
        return counters_StateOperationalByMethod_Active_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_StateOperationalByMethod_Classification_Variable(void)
    {
        return counters_StateOperationalByMethod_Classification_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_StateOperationalByMethod_DiagnosticsLevel_Variable(void)
    {
        return counters_StateOperationalByMethod_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_StateOperationalByMethod_TimeFirstChange_Variable(void)
    {
        return counters_StateOperationalByMethod_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_StateOperationalByMethod_Variable(void)
    {
        return counters_StateOperationalByMethod_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_StateOperationalByParent_Active_Variable(void)
    {
        return counters_StateOperationalByParent_Active_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_StateOperationalByParent_Classification_Variable(void)
    {
        return counters_StateOperationalByParent_Classification_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_StateOperationalByParent_DiagnosticsLevel_Variable(void)
    {
        return counters_StateOperationalByParent_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_StateOperationalByParent_TimeFirstChange_Variable(void)
    {
        return counters_StateOperationalByParent_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_StateOperationalByParent_Variable(void)
    {
        return counters_StateOperationalByParent_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_StateOperationalFromError_Active_Variable(void)
    {
        return counters_StateOperationalFromError_Active_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_StateOperationalFromError_Classification_Variable(void)
    {
        return counters_StateOperationalFromError_Classification_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_StateOperationalFromError_DiagnosticsLevel_Variable(void)
    {
        return counters_StateOperationalFromError_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_StateOperationalFromError_TimeFirstChange_Variable(void)
    {
        return counters_StateOperationalFromError_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_StateOperationalFromError_Variable(void)
    {
        return counters_StateOperationalFromError_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_StatePausedByParent_Active_Variable(void)
    {
        return counters_StatePausedByParent_Active_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_StatePausedByParent_Classification_Variable(void)
    {
        return counters_StatePausedByParent_Classification_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_StatePausedByParent_DiagnosticsLevel_Variable(void)
    {
        return counters_StatePausedByParent_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_StatePausedByParent_TimeFirstChange_Variable(void)
    {
        return counters_StatePausedByParent_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::counters_StatePausedByParent_Variable(void)
    {
        return counters_StatePausedByParent_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::diagnosticsLevel_Variable(void)
    {
        return diagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::liveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable(void)
    {
        return liveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::liveValues_ConfiguredDataSetWriters_Variable(void)
    {
        return liveValues_ConfiguredDataSetWriters_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::liveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable(void)
    {
        return liveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::liveValues_OperationalDataSetWriters_Variable(void)
    {
        return liveValues_OperationalDataSetWriters_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::liveValues_SecurityTokenID_DiagnosticsLevel_Variable(void)
    {
        return liveValues_SecurityTokenID_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::liveValues_SecurityTokenID_Variable(void)
    {
        return liveValues_SecurityTokenID_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::liveValues_TimeToNextTokenID_DiagnosticsLevel_Variable(void)
    {
        return liveValues_TimeToNextTokenID_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::liveValues_TimeToNextTokenID_Variable(void)
    {
        return liveValues_TimeToNextTokenID_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::subError_Variable(void)
    {
        return subError_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::totalError_Active_Variable(void)
    {
        return totalError_Active_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::totalError_Classification_Variable(void)
    {
        return totalError_Classification_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::totalError_DiagnosticsLevel_Variable(void)
    {
        return totalError_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::totalError_TimeFirstChange_Variable(void)
    {
        return totalError_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::totalError_Variable(void)
    {
        return totalError_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::totalInformation_Active_Variable(void)
    {
        return totalInformation_Active_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::totalInformation_Classification_Variable(void)
    {
        return totalInformation_Classification_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::totalInformation_DiagnosticsLevel_Variable(void)
    {
        return totalInformation_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::totalInformation_TimeFirstChange_Variable(void)
    {
        return totalInformation_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    PubSubDiagnosticsWriterGroupType::totalInformation_Variable(void)
    {
        return totalInformation_Variable_;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_EncryptionErrors_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_EncryptionErrors_Active_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_EncryptionErrors_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_EncryptionErrors_Classification_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_EncryptionErrors_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_EncryptionErrors_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_EncryptionErrors_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_EncryptionErrors_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_EncryptionErrors_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_EncryptionErrors_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_FailedTransmissions_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_FailedTransmissions_Active_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_FailedTransmissions_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_FailedTransmissions_Classification_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_FailedTransmissions_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_FailedTransmissions_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_FailedTransmissions_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_FailedTransmissions_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_FailedTransmissions_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_FailedTransmissions_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_SentNetworkMessages_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_SentNetworkMessages_Active_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_SentNetworkMessages_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_SentNetworkMessages_Classification_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_SentNetworkMessages_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_SentNetworkMessages_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_SentNetworkMessages_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_SentNetworkMessages_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_SentNetworkMessages_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_SentNetworkMessages_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_StateDisabledByMethod_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_StateDisabledByMethod_Active_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_StateDisabledByMethod_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_StateDisabledByMethod_Classification_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_StateDisabledByMethod_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_StateDisabledByMethod_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_StateDisabledByMethod_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_StateDisabledByMethod_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_StateDisabledByMethod_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_StateDisabledByMethod_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_StateError_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_StateError_Active_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_StateError_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_StateError_Classification_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_StateError_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_StateError_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_StateError_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_StateError_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_StateError_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_StateError_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_StateOperationalByMethod_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_StateOperationalByMethod_Active_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_StateOperationalByMethod_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_StateOperationalByMethod_Classification_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_StateOperationalByMethod_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_StateOperationalByMethod_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_StateOperationalByMethod_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_StateOperationalByMethod_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_StateOperationalByMethod_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_StateOperationalByMethod_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_StateOperationalByParent_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_StateOperationalByParent_Active_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_StateOperationalByParent_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_StateOperationalByParent_Classification_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_StateOperationalByParent_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_StateOperationalByParent_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_StateOperationalByParent_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_StateOperationalByParent_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_StateOperationalByParent_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_StateOperationalByParent_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_StateOperationalFromError_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_StateOperationalFromError_Active_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_StateOperationalFromError_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_StateOperationalFromError_Classification_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_StateOperationalFromError_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_StateOperationalFromError_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_StateOperationalFromError_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_StateOperationalFromError_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_StateOperationalFromError_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_StateOperationalFromError_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_StatePausedByParent_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_StatePausedByParent_Active_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_StatePausedByParent_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_StatePausedByParent_Classification_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_StatePausedByParent_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_StatePausedByParent_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_StatePausedByParent_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_StatePausedByParent_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::counters_StatePausedByParent_Variable(ServerVariable::SPtr& serverVariable)
    {
        counters_StatePausedByParent_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::diagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnosticsLevel_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::liveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        liveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::liveValues_ConfiguredDataSetWriters_Variable(ServerVariable::SPtr& serverVariable)
    {
        liveValues_ConfiguredDataSetWriters_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::liveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        liveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::liveValues_OperationalDataSetWriters_Variable(ServerVariable::SPtr& serverVariable)
    {
        liveValues_OperationalDataSetWriters_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::liveValues_SecurityTokenID_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        liveValues_SecurityTokenID_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::liveValues_SecurityTokenID_Variable(ServerVariable::SPtr& serverVariable)
    {
        liveValues_SecurityTokenID_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::liveValues_TimeToNextTokenID_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        liveValues_TimeToNextTokenID_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::liveValues_TimeToNextTokenID_Variable(ServerVariable::SPtr& serverVariable)
    {
        liveValues_TimeToNextTokenID_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::subError_Variable(ServerVariable::SPtr& serverVariable)
    {
        subError_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::totalError_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        totalError_Active_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::totalError_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        totalError_Classification_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::totalError_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        totalError_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::totalError_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        totalError_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::totalError_Variable(ServerVariable::SPtr& serverVariable)
    {
        totalError_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::totalInformation_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        totalInformation_Active_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::totalInformation_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        totalInformation_Classification_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::totalInformation_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        totalInformation_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::totalInformation_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        totalInformation_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    PubSubDiagnosticsWriterGroupType::totalInformation_Variable(ServerVariable::SPtr& serverVariable)
    {
        totalInformation_Variable_ = serverVariable;
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_EncryptionErrors_Active_Variable(OpcUaDataValue& dataValue)
    {
        return counters_EncryptionErrors_Active_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_EncryptionErrors_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return counters_EncryptionErrors_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_EncryptionErrors_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return counters_EncryptionErrors_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_EncryptionErrors_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return counters_EncryptionErrors_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_EncryptionErrors_Variable(OpcUaDataValue& dataValue)
    {
        return counters_EncryptionErrors_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_FailedTransmissions_Active_Variable(OpcUaDataValue& dataValue)
    {
        return counters_FailedTransmissions_Active_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_FailedTransmissions_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return counters_FailedTransmissions_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_FailedTransmissions_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return counters_FailedTransmissions_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_FailedTransmissions_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return counters_FailedTransmissions_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_FailedTransmissions_Variable(OpcUaDataValue& dataValue)
    {
        return counters_FailedTransmissions_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_SentNetworkMessages_Active_Variable(OpcUaDataValue& dataValue)
    {
        return counters_SentNetworkMessages_Active_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_SentNetworkMessages_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return counters_SentNetworkMessages_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_SentNetworkMessages_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return counters_SentNetworkMessages_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_SentNetworkMessages_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return counters_SentNetworkMessages_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_SentNetworkMessages_Variable(OpcUaDataValue& dataValue)
    {
        return counters_SentNetworkMessages_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_StateDisabledByMethod_Active_Variable(OpcUaDataValue& dataValue)
    {
        return counters_StateDisabledByMethod_Active_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_StateDisabledByMethod_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return counters_StateDisabledByMethod_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return counters_StateDisabledByMethod_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_StateDisabledByMethod_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return counters_StateDisabledByMethod_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_StateDisabledByMethod_Variable(OpcUaDataValue& dataValue)
    {
        return counters_StateDisabledByMethod_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_StateError_Active_Variable(OpcUaDataValue& dataValue)
    {
        return counters_StateError_Active_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_StateError_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return counters_StateError_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_StateError_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return counters_StateError_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_StateError_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return counters_StateError_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_StateError_Variable(OpcUaDataValue& dataValue)
    {
        return counters_StateError_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_StateOperationalByMethod_Active_Variable(OpcUaDataValue& dataValue)
    {
        return counters_StateOperationalByMethod_Active_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_StateOperationalByMethod_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return counters_StateOperationalByMethod_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return counters_StateOperationalByMethod_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_StateOperationalByMethod_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return counters_StateOperationalByMethod_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_StateOperationalByMethod_Variable(OpcUaDataValue& dataValue)
    {
        return counters_StateOperationalByMethod_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_StateOperationalByParent_Active_Variable(OpcUaDataValue& dataValue)
    {
        return counters_StateOperationalByParent_Active_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_StateOperationalByParent_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return counters_StateOperationalByParent_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return counters_StateOperationalByParent_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_StateOperationalByParent_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return counters_StateOperationalByParent_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_StateOperationalByParent_Variable(OpcUaDataValue& dataValue)
    {
        return counters_StateOperationalByParent_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_StateOperationalFromError_Active_Variable(OpcUaDataValue& dataValue)
    {
        return counters_StateOperationalFromError_Active_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_StateOperationalFromError_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return counters_StateOperationalFromError_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return counters_StateOperationalFromError_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_StateOperationalFromError_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return counters_StateOperationalFromError_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_StateOperationalFromError_Variable(OpcUaDataValue& dataValue)
    {
        return counters_StateOperationalFromError_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_StatePausedByParent_Active_Variable(OpcUaDataValue& dataValue)
    {
        return counters_StatePausedByParent_Active_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_StatePausedByParent_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return counters_StatePausedByParent_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_StatePausedByParent_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return counters_StatePausedByParent_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_StatePausedByParent_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return counters_StatePausedByParent_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_Counters_StatePausedByParent_Variable(OpcUaDataValue& dataValue)
    {
        return counters_StatePausedByParent_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return liveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_LiveValues_ConfiguredDataSetWriters_Variable(OpcUaDataValue& dataValue)
    {
        return liveValues_ConfiguredDataSetWriters_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_LiveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return liveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_LiveValues_OperationalDataSetWriters_Variable(OpcUaDataValue& dataValue)
    {
        return liveValues_OperationalDataSetWriters_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_LiveValues_SecurityTokenID_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return liveValues_SecurityTokenID_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_LiveValues_SecurityTokenID_Variable(OpcUaDataValue& dataValue)
    {
        return liveValues_SecurityTokenID_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_LiveValues_TimeToNextTokenID_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return liveValues_TimeToNextTokenID_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_LiveValues_TimeToNextTokenID_Variable(OpcUaDataValue& dataValue)
    {
        return liveValues_TimeToNextTokenID_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_SubError_Variable(OpcUaDataValue& dataValue)
    {
        return subError_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_TotalError_Active_Variable(OpcUaDataValue& dataValue)
    {
        return totalError_Active_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_TotalError_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return totalError_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_TotalError_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return totalError_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_TotalError_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return totalError_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_TotalError_Variable(OpcUaDataValue& dataValue)
    {
        return totalError_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_TotalInformation_Active_Variable(OpcUaDataValue& dataValue)
    {
        return totalInformation_Active_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_TotalInformation_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return totalInformation_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_TotalInformation_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return totalInformation_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_TotalInformation_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return totalInformation_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::get_TotalInformation_Variable(OpcUaDataValue& dataValue)
    {
        return totalInformation_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_EncryptionErrors_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_EncryptionErrors_Active_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_EncryptionErrors_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_EncryptionErrors_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_EncryptionErrors_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_EncryptionErrors_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_EncryptionErrors_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_EncryptionErrors_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_EncryptionErrors_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_EncryptionErrors_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_FailedTransmissions_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_FailedTransmissions_Active_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_FailedTransmissions_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_FailedTransmissions_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_FailedTransmissions_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_FailedTransmissions_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_FailedTransmissions_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_FailedTransmissions_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_FailedTransmissions_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_FailedTransmissions_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_SentNetworkMessages_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_SentNetworkMessages_Active_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_SentNetworkMessages_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_SentNetworkMessages_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_SentNetworkMessages_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_SentNetworkMessages_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_SentNetworkMessages_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_SentNetworkMessages_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_SentNetworkMessages_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_SentNetworkMessages_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_StateDisabledByMethod_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_StateDisabledByMethod_Active_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_StateDisabledByMethod_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_StateDisabledByMethod_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_StateDisabledByMethod_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_StateDisabledByMethod_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_StateDisabledByMethod_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_StateDisabledByMethod_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_StateDisabledByMethod_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_StateError_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_StateError_Active_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_StateError_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_StateError_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_StateError_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_StateError_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_StateError_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_StateError_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_StateError_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_StateError_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_StateOperationalByMethod_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_StateOperationalByMethod_Active_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_StateOperationalByMethod_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_StateOperationalByMethod_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_StateOperationalByMethod_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_StateOperationalByMethod_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_StateOperationalByMethod_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_StateOperationalByMethod_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_StateOperationalByMethod_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_StateOperationalByParent_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_StateOperationalByParent_Active_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_StateOperationalByParent_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_StateOperationalByParent_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_StateOperationalByParent_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_StateOperationalByParent_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_StateOperationalByParent_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_StateOperationalByParent_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_StateOperationalByParent_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_StateOperationalFromError_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_StateOperationalFromError_Active_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_StateOperationalFromError_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_StateOperationalFromError_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_StateOperationalFromError_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_StateOperationalFromError_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_StateOperationalFromError_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_StateOperationalFromError_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_StateOperationalFromError_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_StatePausedByParent_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_StatePausedByParent_Active_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_StatePausedByParent_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_StatePausedByParent_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_StatePausedByParent_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_StatePausedByParent_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_StatePausedByParent_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_StatePausedByParent_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_Counters_StatePausedByParent_Variable(const OpcUaDataValue& dataValue)
    {
        return counters_StatePausedByParent_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return liveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_LiveValues_ConfiguredDataSetWriters_Variable(const OpcUaDataValue& dataValue)
    {
        return liveValues_ConfiguredDataSetWriters_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_LiveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return liveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_LiveValues_OperationalDataSetWriters_Variable(const OpcUaDataValue& dataValue)
    {
        return liveValues_OperationalDataSetWriters_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_LiveValues_SecurityTokenID_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return liveValues_SecurityTokenID_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_LiveValues_SecurityTokenID_Variable(const OpcUaDataValue& dataValue)
    {
        return liveValues_SecurityTokenID_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_LiveValues_TimeToNextTokenID_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return liveValues_TimeToNextTokenID_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_LiveValues_TimeToNextTokenID_Variable(const OpcUaDataValue& dataValue)
    {
        return liveValues_TimeToNextTokenID_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_SubError_Variable(const OpcUaDataValue& dataValue)
    {
        return subError_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_TotalError_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return totalError_Active_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_TotalError_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return totalError_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_TotalError_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return totalError_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_TotalError_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return totalError_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_TotalError_Variable(const OpcUaDataValue& dataValue)
    {
        return totalError_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_TotalInformation_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return totalInformation_Active_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_TotalInformation_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return totalInformation_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_TotalInformation_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return totalInformation_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_TotalInformation_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return totalInformation_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubDiagnosticsWriterGroupType::set_TotalInformation_Variable(const OpcUaDataValue& dataValue)
    {
        return totalInformation_Variable_->setDataValue(dataValue);
    }

    void
    PubSubDiagnosticsWriterGroupType::call_Reset_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

}
