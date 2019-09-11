/*
    VariableTypeClass: WriterGroupType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/WriterGroupType.h"

namespace OpcUaStackServer
{
    
    WriterGroupType::WriterGroupType(void)
    : ObjectBase()
    , diagnostics_Counters_EncryptionErrors_Active_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_EncryptionErrors_Active_Variable"))
    , diagnostics_Counters_EncryptionErrors_Classification_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_EncryptionErrors_Classification_Variable"))
    , diagnostics_Counters_EncryptionErrors_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_EncryptionErrors_DiagnosticsLevel_Variable"))
    , diagnostics_Counters_EncryptionErrors_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_EncryptionErrors_TimeFirstChange_Variable"))
    , diagnostics_Counters_EncryptionErrors_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_EncryptionErrors_Variable"))
    , diagnostics_Counters_FailedTransmissions_Active_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_FailedTransmissions_Active_Variable"))
    , diagnostics_Counters_FailedTransmissions_Classification_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_FailedTransmissions_Classification_Variable"))
    , diagnostics_Counters_FailedTransmissions_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_FailedTransmissions_DiagnosticsLevel_Variable"))
    , diagnostics_Counters_FailedTransmissions_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_FailedTransmissions_TimeFirstChange_Variable"))
    , diagnostics_Counters_FailedTransmissions_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_FailedTransmissions_Variable"))
    , diagnostics_Counters_SentNetworkMessages_Active_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_SentNetworkMessages_Active_Variable"))
    , diagnostics_Counters_SentNetworkMessages_Classification_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_SentNetworkMessages_Classification_Variable"))
    , diagnostics_Counters_SentNetworkMessages_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_SentNetworkMessages_DiagnosticsLevel_Variable"))
    , diagnostics_Counters_SentNetworkMessages_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_SentNetworkMessages_TimeFirstChange_Variable"))
    , diagnostics_Counters_SentNetworkMessages_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_SentNetworkMessages_Variable"))
    , diagnostics_Counters_StateDisabledByMethod_Active_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateDisabledByMethod_Active_Variable"))
    , diagnostics_Counters_StateDisabledByMethod_Classification_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateDisabledByMethod_Classification_Variable"))
    , diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable"))
    , diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable"))
    , diagnostics_Counters_StateDisabledByMethod_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateDisabledByMethod_Variable"))
    , diagnostics_Counters_StateError_Active_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateError_Active_Variable"))
    , diagnostics_Counters_StateError_Classification_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateError_Classification_Variable"))
    , diagnostics_Counters_StateError_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateError_DiagnosticsLevel_Variable"))
    , diagnostics_Counters_StateError_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateError_TimeFirstChange_Variable"))
    , diagnostics_Counters_StateError_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateError_Variable"))
    , diagnostics_Counters_StateOperationalByMethod_Active_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateOperationalByMethod_Active_Variable"))
    , diagnostics_Counters_StateOperationalByMethod_Classification_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateOperationalByMethod_Classification_Variable"))
    , diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable"))
    , diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable"))
    , diagnostics_Counters_StateOperationalByMethod_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateOperationalByMethod_Variable"))
    , diagnostics_Counters_StateOperationalByParent_Active_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateOperationalByParent_Active_Variable"))
    , diagnostics_Counters_StateOperationalByParent_Classification_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateOperationalByParent_Classification_Variable"))
    , diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable"))
    , diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable"))
    , diagnostics_Counters_StateOperationalByParent_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateOperationalByParent_Variable"))
    , diagnostics_Counters_StateOperationalFromError_Active_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateOperationalFromError_Active_Variable"))
    , diagnostics_Counters_StateOperationalFromError_Classification_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateOperationalFromError_Classification_Variable"))
    , diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable"))
    , diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable"))
    , diagnostics_Counters_StateOperationalFromError_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateOperationalFromError_Variable"))
    , diagnostics_Counters_StatePausedByParent_Active_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StatePausedByParent_Active_Variable"))
    , diagnostics_Counters_StatePausedByParent_Classification_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StatePausedByParent_Classification_Variable"))
    , diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable"))
    , diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable"))
    , diagnostics_Counters_StatePausedByParent_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StatePausedByParent_Variable"))
    , diagnostics_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_DiagnosticsLevel_Variable"))
    , diagnostics_LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable"))
    , diagnostics_LiveValues_ConfiguredDataSetWriters_Variable_(boost::make_shared<ServerVariable>("Diagnostics_LiveValues_ConfiguredDataSetWriters_Variable"))
    , diagnostics_LiveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_LiveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable"))
    , diagnostics_LiveValues_OperationalDataSetWriters_Variable_(boost::make_shared<ServerVariable>("Diagnostics_LiveValues_OperationalDataSetWriters_Variable"))
    , diagnostics_SubError_Variable_(boost::make_shared<ServerVariable>("Diagnostics_SubError_Variable"))
    , diagnostics_TotalError_Active_Variable_(boost::make_shared<ServerVariable>("Diagnostics_TotalError_Active_Variable"))
    , diagnostics_TotalError_Classification_Variable_(boost::make_shared<ServerVariable>("Diagnostics_TotalError_Classification_Variable"))
    , diagnostics_TotalError_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_TotalError_DiagnosticsLevel_Variable"))
    , diagnostics_TotalError_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Diagnostics_TotalError_TimeFirstChange_Variable"))
    , diagnostics_TotalError_Variable_(boost::make_shared<ServerVariable>("Diagnostics_TotalError_Variable"))
    , diagnostics_TotalInformation_Active_Variable_(boost::make_shared<ServerVariable>("Diagnostics_TotalInformation_Active_Variable"))
    , diagnostics_TotalInformation_Classification_Variable_(boost::make_shared<ServerVariable>("Diagnostics_TotalInformation_Classification_Variable"))
    , diagnostics_TotalInformation_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_TotalInformation_DiagnosticsLevel_Variable"))
    , diagnostics_TotalInformation_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Diagnostics_TotalInformation_TimeFirstChange_Variable"))
    , diagnostics_TotalInformation_Variable_(boost::make_shared<ServerVariable>("Diagnostics_TotalInformation_Variable"))
    , groupProperties_Variable_(boost::make_shared<ServerVariable>("GroupProperties_Variable"))
    , keepAliveTime_Variable_(boost::make_shared<ServerVariable>("KeepAliveTime_Variable"))
    , localeIds_Variable_(boost::make_shared<ServerVariable>("LocaleIds_Variable"))
    , maxNetworkMessageSize_Variable_(boost::make_shared<ServerVariable>("MaxNetworkMessageSize_Variable"))
    , priority_Variable_(boost::make_shared<ServerVariable>("Priority_Variable"))
    , publishingInterval_Variable_(boost::make_shared<ServerVariable>("PublishingInterval_Variable"))
    , securityGroupId_Variable_(boost::make_shared<ServerVariable>("SecurityGroupId_Variable"))
    , securityKeyServices_Variable_(boost::make_shared<ServerVariable>("SecurityKeyServices_Variable"))
    , securityMode_Variable_(boost::make_shared<ServerVariable>("SecurityMode_Variable"))
    , status_State_Variable_(boost::make_shared<ServerVariable>("Status_State_Variable"))
    , writerGroupId_Variable_(boost::make_shared<ServerVariable>("WriterGroupId_Variable"))
    , addDataSetWriter_Method_(boost::make_shared<ServerMethod>("AddDataSetWriter_Method"))
    , diagnostics_Reset_Method_(boost::make_shared<ServerMethod>("Diagnostics_Reset_Method"))
    , removeDataSetWriter_Method_(boost::make_shared<ServerMethod>("RemoveDataSetWriter_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)17725);
        setServerVariable(diagnostics_Counters_EncryptionErrors_Active_Variable_);
        setServerVariable(diagnostics_Counters_EncryptionErrors_Classification_Variable_);
        setServerVariable(diagnostics_Counters_EncryptionErrors_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_Counters_EncryptionErrors_TimeFirstChange_Variable_);
        setServerVariable(diagnostics_Counters_EncryptionErrors_Variable_);
        setServerVariable(diagnostics_Counters_FailedTransmissions_Active_Variable_);
        setServerVariable(diagnostics_Counters_FailedTransmissions_Classification_Variable_);
        setServerVariable(diagnostics_Counters_FailedTransmissions_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_Counters_FailedTransmissions_TimeFirstChange_Variable_);
        setServerVariable(diagnostics_Counters_FailedTransmissions_Variable_);
        setServerVariable(diagnostics_Counters_SentNetworkMessages_Active_Variable_);
        setServerVariable(diagnostics_Counters_SentNetworkMessages_Classification_Variable_);
        setServerVariable(diagnostics_Counters_SentNetworkMessages_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_Counters_SentNetworkMessages_TimeFirstChange_Variable_);
        setServerVariable(diagnostics_Counters_SentNetworkMessages_Variable_);
        setServerVariable(diagnostics_Counters_StateDisabledByMethod_Active_Variable_);
        setServerVariable(diagnostics_Counters_StateDisabledByMethod_Classification_Variable_);
        setServerVariable(diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable_);
        setServerVariable(diagnostics_Counters_StateDisabledByMethod_Variable_);
        setServerVariable(diagnostics_Counters_StateError_Active_Variable_);
        setServerVariable(diagnostics_Counters_StateError_Classification_Variable_);
        setServerVariable(diagnostics_Counters_StateError_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_Counters_StateError_TimeFirstChange_Variable_);
        setServerVariable(diagnostics_Counters_StateError_Variable_);
        setServerVariable(diagnostics_Counters_StateOperationalByMethod_Active_Variable_);
        setServerVariable(diagnostics_Counters_StateOperationalByMethod_Classification_Variable_);
        setServerVariable(diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable_);
        setServerVariable(diagnostics_Counters_StateOperationalByMethod_Variable_);
        setServerVariable(diagnostics_Counters_StateOperationalByParent_Active_Variable_);
        setServerVariable(diagnostics_Counters_StateOperationalByParent_Classification_Variable_);
        setServerVariable(diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable_);
        setServerVariable(diagnostics_Counters_StateOperationalByParent_Variable_);
        setServerVariable(diagnostics_Counters_StateOperationalFromError_Active_Variable_);
        setServerVariable(diagnostics_Counters_StateOperationalFromError_Classification_Variable_);
        setServerVariable(diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable_);
        setServerVariable(diagnostics_Counters_StateOperationalFromError_Variable_);
        setServerVariable(diagnostics_Counters_StatePausedByParent_Active_Variable_);
        setServerVariable(diagnostics_Counters_StatePausedByParent_Classification_Variable_);
        setServerVariable(diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable_);
        setServerVariable(diagnostics_Counters_StatePausedByParent_Variable_);
        setServerVariable(diagnostics_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_LiveValues_ConfiguredDataSetWriters_Variable_);
        setServerVariable(diagnostics_LiveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_LiveValues_OperationalDataSetWriters_Variable_);
        setServerVariable(diagnostics_SubError_Variable_);
        setServerVariable(diagnostics_TotalError_Active_Variable_);
        setServerVariable(diagnostics_TotalError_Classification_Variable_);
        setServerVariable(diagnostics_TotalError_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_TotalError_TimeFirstChange_Variable_);
        setServerVariable(diagnostics_TotalError_Variable_);
        setServerVariable(diagnostics_TotalInformation_Active_Variable_);
        setServerVariable(diagnostics_TotalInformation_Classification_Variable_);
        setServerVariable(diagnostics_TotalInformation_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_TotalInformation_TimeFirstChange_Variable_);
        setServerVariable(diagnostics_TotalInformation_Variable_);
        setServerVariable(groupProperties_Variable_);
        setServerVariable(keepAliveTime_Variable_);
        setServerVariable(localeIds_Variable_);
        setServerVariable(maxNetworkMessageSize_Variable_);
        setServerVariable(priority_Variable_);
        setServerVariable(publishingInterval_Variable_);
        setServerVariable(securityGroupId_Variable_);
        setServerVariable(securityKeyServices_Variable_);
        setServerVariable(securityMode_Variable_);
        setServerVariable(status_State_Variable_);
        setServerVariable(writerGroupId_Variable_);
        setServerMethod(addDataSetWriter_Method_);
        setServerMethod(diagnostics_Reset_Method_);
        setServerMethod(removeDataSetWriter_Method_);
        addDataSetWriter_Method_->registerMethod(boost::bind(&WriterGroupType::call_AddDataSetWriter_Method, this, _1));
        diagnostics_Reset_Method_->registerMethod(boost::bind(&WriterGroupType::call_Diagnostics_Reset_Method, this, _1));
        removeDataSetWriter_Method_->registerMethod(boost::bind(&WriterGroupType::call_RemoveDataSetWriter_Method, this, _1));
    }
    
    WriterGroupType::WriterGroupType(const WriterGroupType& value)
    : ObjectBase()
    , diagnostics_Counters_EncryptionErrors_Active_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_EncryptionErrors_Active_Variable"))
    , diagnostics_Counters_EncryptionErrors_Classification_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_EncryptionErrors_Classification_Variable"))
    , diagnostics_Counters_EncryptionErrors_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_EncryptionErrors_DiagnosticsLevel_Variable"))
    , diagnostics_Counters_EncryptionErrors_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_EncryptionErrors_TimeFirstChange_Variable"))
    , diagnostics_Counters_EncryptionErrors_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_EncryptionErrors_Variable"))
    , diagnostics_Counters_FailedTransmissions_Active_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_FailedTransmissions_Active_Variable"))
    , diagnostics_Counters_FailedTransmissions_Classification_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_FailedTransmissions_Classification_Variable"))
    , diagnostics_Counters_FailedTransmissions_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_FailedTransmissions_DiagnosticsLevel_Variable"))
    , diagnostics_Counters_FailedTransmissions_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_FailedTransmissions_TimeFirstChange_Variable"))
    , diagnostics_Counters_FailedTransmissions_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_FailedTransmissions_Variable"))
    , diagnostics_Counters_SentNetworkMessages_Active_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_SentNetworkMessages_Active_Variable"))
    , diagnostics_Counters_SentNetworkMessages_Classification_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_SentNetworkMessages_Classification_Variable"))
    , diagnostics_Counters_SentNetworkMessages_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_SentNetworkMessages_DiagnosticsLevel_Variable"))
    , diagnostics_Counters_SentNetworkMessages_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_SentNetworkMessages_TimeFirstChange_Variable"))
    , diagnostics_Counters_SentNetworkMessages_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_SentNetworkMessages_Variable"))
    , diagnostics_Counters_StateDisabledByMethod_Active_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateDisabledByMethod_Active_Variable"))
    , diagnostics_Counters_StateDisabledByMethod_Classification_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateDisabledByMethod_Classification_Variable"))
    , diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable"))
    , diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable"))
    , diagnostics_Counters_StateDisabledByMethod_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateDisabledByMethod_Variable"))
    , diagnostics_Counters_StateError_Active_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateError_Active_Variable"))
    , diagnostics_Counters_StateError_Classification_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateError_Classification_Variable"))
    , diagnostics_Counters_StateError_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateError_DiagnosticsLevel_Variable"))
    , diagnostics_Counters_StateError_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateError_TimeFirstChange_Variable"))
    , diagnostics_Counters_StateError_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateError_Variable"))
    , diagnostics_Counters_StateOperationalByMethod_Active_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateOperationalByMethod_Active_Variable"))
    , diagnostics_Counters_StateOperationalByMethod_Classification_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateOperationalByMethod_Classification_Variable"))
    , diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable"))
    , diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable"))
    , diagnostics_Counters_StateOperationalByMethod_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateOperationalByMethod_Variable"))
    , diagnostics_Counters_StateOperationalByParent_Active_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateOperationalByParent_Active_Variable"))
    , diagnostics_Counters_StateOperationalByParent_Classification_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateOperationalByParent_Classification_Variable"))
    , diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable"))
    , diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable"))
    , diagnostics_Counters_StateOperationalByParent_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateOperationalByParent_Variable"))
    , diagnostics_Counters_StateOperationalFromError_Active_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateOperationalFromError_Active_Variable"))
    , diagnostics_Counters_StateOperationalFromError_Classification_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateOperationalFromError_Classification_Variable"))
    , diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable"))
    , diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable"))
    , diagnostics_Counters_StateOperationalFromError_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StateOperationalFromError_Variable"))
    , diagnostics_Counters_StatePausedByParent_Active_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StatePausedByParent_Active_Variable"))
    , diagnostics_Counters_StatePausedByParent_Classification_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StatePausedByParent_Classification_Variable"))
    , diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable"))
    , diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable"))
    , diagnostics_Counters_StatePausedByParent_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_StatePausedByParent_Variable"))
    , diagnostics_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_DiagnosticsLevel_Variable"))
    , diagnostics_LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable"))
    , diagnostics_LiveValues_ConfiguredDataSetWriters_Variable_(boost::make_shared<ServerVariable>("Diagnostics_LiveValues_ConfiguredDataSetWriters_Variable"))
    , diagnostics_LiveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_LiveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable"))
    , diagnostics_LiveValues_OperationalDataSetWriters_Variable_(boost::make_shared<ServerVariable>("Diagnostics_LiveValues_OperationalDataSetWriters_Variable"))
    , diagnostics_SubError_Variable_(boost::make_shared<ServerVariable>("Diagnostics_SubError_Variable"))
    , diagnostics_TotalError_Active_Variable_(boost::make_shared<ServerVariable>("Diagnostics_TotalError_Active_Variable"))
    , diagnostics_TotalError_Classification_Variable_(boost::make_shared<ServerVariable>("Diagnostics_TotalError_Classification_Variable"))
    , diagnostics_TotalError_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_TotalError_DiagnosticsLevel_Variable"))
    , diagnostics_TotalError_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Diagnostics_TotalError_TimeFirstChange_Variable"))
    , diagnostics_TotalError_Variable_(boost::make_shared<ServerVariable>("Diagnostics_TotalError_Variable"))
    , diagnostics_TotalInformation_Active_Variable_(boost::make_shared<ServerVariable>("Diagnostics_TotalInformation_Active_Variable"))
    , diagnostics_TotalInformation_Classification_Variable_(boost::make_shared<ServerVariable>("Diagnostics_TotalInformation_Classification_Variable"))
    , diagnostics_TotalInformation_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_TotalInformation_DiagnosticsLevel_Variable"))
    , diagnostics_TotalInformation_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Diagnostics_TotalInformation_TimeFirstChange_Variable"))
    , diagnostics_TotalInformation_Variable_(boost::make_shared<ServerVariable>("Diagnostics_TotalInformation_Variable"))
    , groupProperties_Variable_(boost::make_shared<ServerVariable>("GroupProperties_Variable"))
    , keepAliveTime_Variable_(boost::make_shared<ServerVariable>("KeepAliveTime_Variable"))
    , localeIds_Variable_(boost::make_shared<ServerVariable>("LocaleIds_Variable"))
    , maxNetworkMessageSize_Variable_(boost::make_shared<ServerVariable>("MaxNetworkMessageSize_Variable"))
    , priority_Variable_(boost::make_shared<ServerVariable>("Priority_Variable"))
    , publishingInterval_Variable_(boost::make_shared<ServerVariable>("PublishingInterval_Variable"))
    , securityGroupId_Variable_(boost::make_shared<ServerVariable>("SecurityGroupId_Variable"))
    , securityKeyServices_Variable_(boost::make_shared<ServerVariable>("SecurityKeyServices_Variable"))
    , securityMode_Variable_(boost::make_shared<ServerVariable>("SecurityMode_Variable"))
    , status_State_Variable_(boost::make_shared<ServerVariable>("Status_State_Variable"))
    , writerGroupId_Variable_(boost::make_shared<ServerVariable>("WriterGroupId_Variable"))
    , addDataSetWriter_Method_(boost::make_shared<ServerMethod>("AddDataSetWriter_Method"))
    , diagnostics_Reset_Method_(boost::make_shared<ServerMethod>("Diagnostics_Reset_Method"))
    , removeDataSetWriter_Method_(boost::make_shared<ServerMethod>("RemoveDataSetWriter_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)17725);
        setServerVariable(diagnostics_Counters_EncryptionErrors_Active_Variable_);
        setServerVariable(diagnostics_Counters_EncryptionErrors_Classification_Variable_);
        setServerVariable(diagnostics_Counters_EncryptionErrors_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_Counters_EncryptionErrors_TimeFirstChange_Variable_);
        setServerVariable(diagnostics_Counters_EncryptionErrors_Variable_);
        setServerVariable(diagnostics_Counters_FailedTransmissions_Active_Variable_);
        setServerVariable(diagnostics_Counters_FailedTransmissions_Classification_Variable_);
        setServerVariable(diagnostics_Counters_FailedTransmissions_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_Counters_FailedTransmissions_TimeFirstChange_Variable_);
        setServerVariable(diagnostics_Counters_FailedTransmissions_Variable_);
        setServerVariable(diagnostics_Counters_SentNetworkMessages_Active_Variable_);
        setServerVariable(diagnostics_Counters_SentNetworkMessages_Classification_Variable_);
        setServerVariable(diagnostics_Counters_SentNetworkMessages_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_Counters_SentNetworkMessages_TimeFirstChange_Variable_);
        setServerVariable(diagnostics_Counters_SentNetworkMessages_Variable_);
        setServerVariable(diagnostics_Counters_StateDisabledByMethod_Active_Variable_);
        setServerVariable(diagnostics_Counters_StateDisabledByMethod_Classification_Variable_);
        setServerVariable(diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable_);
        setServerVariable(diagnostics_Counters_StateDisabledByMethod_Variable_);
        setServerVariable(diagnostics_Counters_StateError_Active_Variable_);
        setServerVariable(diagnostics_Counters_StateError_Classification_Variable_);
        setServerVariable(diagnostics_Counters_StateError_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_Counters_StateError_TimeFirstChange_Variable_);
        setServerVariable(diagnostics_Counters_StateError_Variable_);
        setServerVariable(diagnostics_Counters_StateOperationalByMethod_Active_Variable_);
        setServerVariable(diagnostics_Counters_StateOperationalByMethod_Classification_Variable_);
        setServerVariable(diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable_);
        setServerVariable(diagnostics_Counters_StateOperationalByMethod_Variable_);
        setServerVariable(diagnostics_Counters_StateOperationalByParent_Active_Variable_);
        setServerVariable(diagnostics_Counters_StateOperationalByParent_Classification_Variable_);
        setServerVariable(diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable_);
        setServerVariable(diagnostics_Counters_StateOperationalByParent_Variable_);
        setServerVariable(diagnostics_Counters_StateOperationalFromError_Active_Variable_);
        setServerVariable(diagnostics_Counters_StateOperationalFromError_Classification_Variable_);
        setServerVariable(diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable_);
        setServerVariable(diagnostics_Counters_StateOperationalFromError_Variable_);
        setServerVariable(diagnostics_Counters_StatePausedByParent_Active_Variable_);
        setServerVariable(diagnostics_Counters_StatePausedByParent_Classification_Variable_);
        setServerVariable(diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable_);
        setServerVariable(diagnostics_Counters_StatePausedByParent_Variable_);
        setServerVariable(diagnostics_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_LiveValues_ConfiguredDataSetWriters_Variable_);
        setServerVariable(diagnostics_LiveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_LiveValues_OperationalDataSetWriters_Variable_);
        setServerVariable(diagnostics_SubError_Variable_);
        setServerVariable(diagnostics_TotalError_Active_Variable_);
        setServerVariable(diagnostics_TotalError_Classification_Variable_);
        setServerVariable(diagnostics_TotalError_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_TotalError_TimeFirstChange_Variable_);
        setServerVariable(diagnostics_TotalError_Variable_);
        setServerVariable(diagnostics_TotalInformation_Active_Variable_);
        setServerVariable(diagnostics_TotalInformation_Classification_Variable_);
        setServerVariable(diagnostics_TotalInformation_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_TotalInformation_TimeFirstChange_Variable_);
        setServerVariable(diagnostics_TotalInformation_Variable_);
        setServerVariable(groupProperties_Variable_);
        setServerVariable(keepAliveTime_Variable_);
        setServerVariable(localeIds_Variable_);
        setServerVariable(maxNetworkMessageSize_Variable_);
        setServerVariable(priority_Variable_);
        setServerVariable(publishingInterval_Variable_);
        setServerVariable(securityGroupId_Variable_);
        setServerVariable(securityKeyServices_Variable_);
        setServerVariable(securityMode_Variable_);
        setServerVariable(status_State_Variable_);
        setServerVariable(writerGroupId_Variable_);
        setServerMethod(addDataSetWriter_Method_);
        setServerMethod(diagnostics_Reset_Method_);
        setServerMethod(removeDataSetWriter_Method_);
        addDataSetWriter_Method_->registerMethod(boost::bind(&WriterGroupType::call_AddDataSetWriter_Method, this, _1));
        diagnostics_Reset_Method_->registerMethod(boost::bind(&WriterGroupType::call_Diagnostics_Reset_Method, this, _1));
        removeDataSetWriter_Method_->registerMethod(boost::bind(&WriterGroupType::call_RemoveDataSetWriter_Method, this, _1));
    }
    
    WriterGroupType::~WriterGroupType(void)
    {
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_EncryptionErrors_Active_Variable(void)
    {
        return diagnostics_Counters_EncryptionErrors_Active_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_EncryptionErrors_Classification_Variable(void)
    {
        return diagnostics_Counters_EncryptionErrors_Classification_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_EncryptionErrors_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_EncryptionErrors_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_EncryptionErrors_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_EncryptionErrors_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_EncryptionErrors_Variable(void)
    {
        return diagnostics_Counters_EncryptionErrors_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_FailedTransmissions_Active_Variable(void)
    {
        return diagnostics_Counters_FailedTransmissions_Active_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_FailedTransmissions_Classification_Variable(void)
    {
        return diagnostics_Counters_FailedTransmissions_Classification_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_FailedTransmissions_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_FailedTransmissions_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_FailedTransmissions_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_FailedTransmissions_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_FailedTransmissions_Variable(void)
    {
        return diagnostics_Counters_FailedTransmissions_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_SentNetworkMessages_Active_Variable(void)
    {
        return diagnostics_Counters_SentNetworkMessages_Active_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_SentNetworkMessages_Classification_Variable(void)
    {
        return diagnostics_Counters_SentNetworkMessages_Classification_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_SentNetworkMessages_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_SentNetworkMessages_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_SentNetworkMessages_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_SentNetworkMessages_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_SentNetworkMessages_Variable(void)
    {
        return diagnostics_Counters_SentNetworkMessages_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_StateDisabledByMethod_Active_Variable(void)
    {
        return diagnostics_Counters_StateDisabledByMethod_Active_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_StateDisabledByMethod_Classification_Variable(void)
    {
        return diagnostics_Counters_StateDisabledByMethod_Classification_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_StateDisabledByMethod_Variable(void)
    {
        return diagnostics_Counters_StateDisabledByMethod_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_StateError_Active_Variable(void)
    {
        return diagnostics_Counters_StateError_Active_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_StateError_Classification_Variable(void)
    {
        return diagnostics_Counters_StateError_Classification_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_StateError_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_StateError_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_StateError_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_StateError_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_StateError_Variable(void)
    {
        return diagnostics_Counters_StateError_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_StateOperationalByMethod_Active_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByMethod_Active_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_StateOperationalByMethod_Classification_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByMethod_Classification_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_StateOperationalByMethod_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByMethod_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_StateOperationalByParent_Active_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByParent_Active_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_StateOperationalByParent_Classification_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByParent_Classification_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_StateOperationalByParent_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByParent_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_StateOperationalFromError_Active_Variable(void)
    {
        return diagnostics_Counters_StateOperationalFromError_Active_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_StateOperationalFromError_Classification_Variable(void)
    {
        return diagnostics_Counters_StateOperationalFromError_Classification_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_StateOperationalFromError_Variable(void)
    {
        return diagnostics_Counters_StateOperationalFromError_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_StatePausedByParent_Active_Variable(void)
    {
        return diagnostics_Counters_StatePausedByParent_Active_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_StatePausedByParent_Classification_Variable(void)
    {
        return diagnostics_Counters_StatePausedByParent_Classification_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_Counters_StatePausedByParent_Variable(void)
    {
        return diagnostics_Counters_StatePausedByParent_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_LiveValues_ConfiguredDataSetWriters_Variable(void)
    {
        return diagnostics_LiveValues_ConfiguredDataSetWriters_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_LiveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_LiveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_LiveValues_OperationalDataSetWriters_Variable(void)
    {
        return diagnostics_LiveValues_OperationalDataSetWriters_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_SubError_Variable(void)
    {
        return diagnostics_SubError_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_TotalError_Active_Variable(void)
    {
        return diagnostics_TotalError_Active_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_TotalError_Classification_Variable(void)
    {
        return diagnostics_TotalError_Classification_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_TotalError_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_TotalError_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_TotalError_TimeFirstChange_Variable(void)
    {
        return diagnostics_TotalError_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_TotalError_Variable(void)
    {
        return diagnostics_TotalError_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_TotalInformation_Active_Variable(void)
    {
        return diagnostics_TotalInformation_Active_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_TotalInformation_Classification_Variable(void)
    {
        return diagnostics_TotalInformation_Classification_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_TotalInformation_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_TotalInformation_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_TotalInformation_TimeFirstChange_Variable(void)
    {
        return diagnostics_TotalInformation_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::diagnostics_TotalInformation_Variable(void)
    {
        return diagnostics_TotalInformation_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::groupProperties_Variable(void)
    {
        return groupProperties_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::keepAliveTime_Variable(void)
    {
        return keepAliveTime_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::localeIds_Variable(void)
    {
        return localeIds_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::maxNetworkMessageSize_Variable(void)
    {
        return maxNetworkMessageSize_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::priority_Variable(void)
    {
        return priority_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::publishingInterval_Variable(void)
    {
        return publishingInterval_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::securityGroupId_Variable(void)
    {
        return securityGroupId_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::securityKeyServices_Variable(void)
    {
        return securityKeyServices_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::securityMode_Variable(void)
    {
        return securityMode_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::status_State_Variable(void)
    {
        return status_State_Variable_;
    }

    ServerVariable::SPtr&
    WriterGroupType::writerGroupId_Variable(void)
    {
        return writerGroupId_Variable_;
    }

    void
    WriterGroupType::diagnostics_Counters_EncryptionErrors_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_EncryptionErrors_Active_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_EncryptionErrors_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_EncryptionErrors_Classification_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_EncryptionErrors_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_EncryptionErrors_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_EncryptionErrors_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_EncryptionErrors_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_EncryptionErrors_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_EncryptionErrors_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_FailedTransmissions_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_FailedTransmissions_Active_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_FailedTransmissions_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_FailedTransmissions_Classification_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_FailedTransmissions_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_FailedTransmissions_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_FailedTransmissions_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_FailedTransmissions_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_FailedTransmissions_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_FailedTransmissions_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_SentNetworkMessages_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_SentNetworkMessages_Active_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_SentNetworkMessages_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_SentNetworkMessages_Classification_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_SentNetworkMessages_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_SentNetworkMessages_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_SentNetworkMessages_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_SentNetworkMessages_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_SentNetworkMessages_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_SentNetworkMessages_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_StateDisabledByMethod_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateDisabledByMethod_Active_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_StateDisabledByMethod_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateDisabledByMethod_Classification_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_StateDisabledByMethod_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateDisabledByMethod_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_StateError_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateError_Active_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_StateError_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateError_Classification_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_StateError_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateError_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_StateError_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateError_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_StateError_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateError_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_StateOperationalByMethod_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByMethod_Active_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_StateOperationalByMethod_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByMethod_Classification_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_StateOperationalByMethod_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByMethod_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_StateOperationalByParent_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByParent_Active_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_StateOperationalByParent_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByParent_Classification_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_StateOperationalByParent_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByParent_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_StateOperationalFromError_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalFromError_Active_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_StateOperationalFromError_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalFromError_Classification_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_StateOperationalFromError_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalFromError_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_StatePausedByParent_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StatePausedByParent_Active_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_StatePausedByParent_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StatePausedByParent_Classification_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_Counters_StatePausedByParent_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StatePausedByParent_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_LiveValues_ConfiguredDataSetWriters_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_LiveValues_ConfiguredDataSetWriters_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_LiveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_LiveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_LiveValues_OperationalDataSetWriters_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_LiveValues_OperationalDataSetWriters_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_SubError_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_SubError_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_TotalError_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalError_Active_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_TotalError_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalError_Classification_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_TotalError_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalError_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_TotalError_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalError_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_TotalError_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalError_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_TotalInformation_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalInformation_Active_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_TotalInformation_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalInformation_Classification_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_TotalInformation_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalInformation_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_TotalInformation_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalInformation_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    WriterGroupType::diagnostics_TotalInformation_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalInformation_Variable_ = serverVariable;
    }

    void
    WriterGroupType::groupProperties_Variable(ServerVariable::SPtr& serverVariable)
    {
        groupProperties_Variable_ = serverVariable;
    }

    void
    WriterGroupType::keepAliveTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        keepAliveTime_Variable_ = serverVariable;
    }

    void
    WriterGroupType::localeIds_Variable(ServerVariable::SPtr& serverVariable)
    {
        localeIds_Variable_ = serverVariable;
    }

    void
    WriterGroupType::maxNetworkMessageSize_Variable(ServerVariable::SPtr& serverVariable)
    {
        maxNetworkMessageSize_Variable_ = serverVariable;
    }

    void
    WriterGroupType::priority_Variable(ServerVariable::SPtr& serverVariable)
    {
        priority_Variable_ = serverVariable;
    }

    void
    WriterGroupType::publishingInterval_Variable(ServerVariable::SPtr& serverVariable)
    {
        publishingInterval_Variable_ = serverVariable;
    }

    void
    WriterGroupType::securityGroupId_Variable(ServerVariable::SPtr& serverVariable)
    {
        securityGroupId_Variable_ = serverVariable;
    }

    void
    WriterGroupType::securityKeyServices_Variable(ServerVariable::SPtr& serverVariable)
    {
        securityKeyServices_Variable_ = serverVariable;
    }

    void
    WriterGroupType::securityMode_Variable(ServerVariable::SPtr& serverVariable)
    {
        securityMode_Variable_ = serverVariable;
    }

    void
    WriterGroupType::status_State_Variable(ServerVariable::SPtr& serverVariable)
    {
        status_State_Variable_ = serverVariable;
    }

    void
    WriterGroupType::writerGroupId_Variable(ServerVariable::SPtr& serverVariable)
    {
        writerGroupId_Variable_ = serverVariable;
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_EncryptionErrors_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_EncryptionErrors_Active_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_EncryptionErrors_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_EncryptionErrors_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_EncryptionErrors_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_EncryptionErrors_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_EncryptionErrors_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_EncryptionErrors_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_EncryptionErrors_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_EncryptionErrors_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_FailedTransmissions_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_FailedTransmissions_Active_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_FailedTransmissions_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_FailedTransmissions_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_FailedTransmissions_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_FailedTransmissions_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_FailedTransmissions_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_FailedTransmissions_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_FailedTransmissions_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_FailedTransmissions_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_SentNetworkMessages_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_SentNetworkMessages_Active_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_SentNetworkMessages_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_SentNetworkMessages_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_SentNetworkMessages_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_SentNetworkMessages_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_SentNetworkMessages_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_SentNetworkMessages_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_SentNetworkMessages_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_SentNetworkMessages_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_StateDisabledByMethod_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_Active_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_StateDisabledByMethod_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_StateDisabledByMethod_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_StateError_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_Active_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_StateError_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_StateError_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_StateError_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_StateError_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_StateOperationalByMethod_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_Active_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_StateOperationalByMethod_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_StateOperationalByMethod_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_StateOperationalByParent_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_Active_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_StateOperationalByParent_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_StateOperationalByParent_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_StateOperationalFromError_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_Active_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_StateOperationalFromError_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_StateOperationalFromError_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_StatePausedByParent_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_Active_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_StatePausedByParent_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_Counters_StatePausedByParent_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_LiveValues_ConfiguredDataSetWriters_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_LiveValues_ConfiguredDataSetWriters_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_LiveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_LiveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_LiveValues_OperationalDataSetWriters_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_LiveValues_OperationalDataSetWriters_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_SubError_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_SubError_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_TotalError_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_Active_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_TotalError_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_TotalError_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_TotalError_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_TotalError_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_TotalInformation_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_Active_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_TotalInformation_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_TotalInformation_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_TotalInformation_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Diagnostics_TotalInformation_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_GroupProperties_Variable(OpcUaDataValue& dataValue)
    {
        return groupProperties_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_KeepAliveTime_Variable(OpcUaDataValue& dataValue)
    {
        return keepAliveTime_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_LocaleIds_Variable(OpcUaDataValue& dataValue)
    {
        return localeIds_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_MaxNetworkMessageSize_Variable(OpcUaDataValue& dataValue)
    {
        return maxNetworkMessageSize_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Priority_Variable(OpcUaDataValue& dataValue)
    {
        return priority_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_PublishingInterval_Variable(OpcUaDataValue& dataValue)
    {
        return publishingInterval_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_SecurityGroupId_Variable(OpcUaDataValue& dataValue)
    {
        return securityGroupId_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_SecurityKeyServices_Variable(OpcUaDataValue& dataValue)
    {
        return securityKeyServices_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_SecurityMode_Variable(OpcUaDataValue& dataValue)
    {
        return securityMode_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_Status_State_Variable(OpcUaDataValue& dataValue)
    {
        return status_State_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::get_WriterGroupId_Variable(OpcUaDataValue& dataValue)
    {
        return writerGroupId_Variable_->getDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_EncryptionErrors_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_EncryptionErrors_Active_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_EncryptionErrors_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_EncryptionErrors_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_EncryptionErrors_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_EncryptionErrors_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_EncryptionErrors_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_EncryptionErrors_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_EncryptionErrors_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_EncryptionErrors_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_FailedTransmissions_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_FailedTransmissions_Active_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_FailedTransmissions_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_FailedTransmissions_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_FailedTransmissions_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_FailedTransmissions_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_FailedTransmissions_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_FailedTransmissions_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_FailedTransmissions_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_FailedTransmissions_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_SentNetworkMessages_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_SentNetworkMessages_Active_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_SentNetworkMessages_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_SentNetworkMessages_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_SentNetworkMessages_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_SentNetworkMessages_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_SentNetworkMessages_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_SentNetworkMessages_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_SentNetworkMessages_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_SentNetworkMessages_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_StateDisabledByMethod_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_Active_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_StateDisabledByMethod_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_StateDisabledByMethod_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_StateError_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_Active_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_StateError_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_StateError_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_StateError_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_StateError_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_StateOperationalByMethod_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_Active_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_StateOperationalByMethod_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_StateOperationalByMethod_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_StateOperationalByParent_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_Active_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_StateOperationalByParent_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_StateOperationalByParent_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_StateOperationalFromError_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_Active_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_StateOperationalFromError_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_StateOperationalFromError_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_StatePausedByParent_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_Active_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_StatePausedByParent_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_Counters_StatePausedByParent_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_LiveValues_ConfiguredDataSetWriters_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_LiveValues_ConfiguredDataSetWriters_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_LiveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_LiveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_LiveValues_OperationalDataSetWriters_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_LiveValues_OperationalDataSetWriters_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_SubError_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_SubError_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_TotalError_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_Active_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_TotalError_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_TotalError_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_TotalError_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_TotalError_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_TotalInformation_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_Active_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_TotalInformation_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_TotalInformation_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_TotalInformation_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Diagnostics_TotalInformation_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_GroupProperties_Variable(const OpcUaDataValue& dataValue)
    {
        return groupProperties_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_KeepAliveTime_Variable(const OpcUaDataValue& dataValue)
    {
        return keepAliveTime_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_LocaleIds_Variable(const OpcUaDataValue& dataValue)
    {
        return localeIds_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_MaxNetworkMessageSize_Variable(const OpcUaDataValue& dataValue)
    {
        return maxNetworkMessageSize_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Priority_Variable(const OpcUaDataValue& dataValue)
    {
        return priority_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_PublishingInterval_Variable(const OpcUaDataValue& dataValue)
    {
        return publishingInterval_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_SecurityGroupId_Variable(const OpcUaDataValue& dataValue)
    {
        return securityGroupId_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_SecurityKeyServices_Variable(const OpcUaDataValue& dataValue)
    {
        return securityKeyServices_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_SecurityMode_Variable(const OpcUaDataValue& dataValue)
    {
        return securityMode_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_Status_State_Variable(const OpcUaDataValue& dataValue)
    {
        return status_State_Variable_->setDataValue(dataValue);
    }

    bool
    WriterGroupType::set_WriterGroupId_Variable(const OpcUaDataValue& dataValue)
    {
        return writerGroupId_Variable_->setDataValue(dataValue);
    }

    void
    WriterGroupType::call_AddDataSetWriter_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    WriterGroupType::call_Diagnostics_Reset_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    WriterGroupType::call_RemoveDataSetWriter_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

}
