/*
    VariableTypeClass: ReaderGroupType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/ReaderGroupType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    ReaderGroupType::ReaderGroupType(void)
    : ObjectBase()
    , diagnostics_Counters_ReceivedNetworkMessages_Active_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_ReceivedNetworkMessages_Active_Variable"))
    , diagnostics_Counters_ReceivedNetworkMessages_Classification_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_ReceivedNetworkMessages_Classification_Variable"))
    , diagnostics_Counters_ReceivedNetworkMessages_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_ReceivedNetworkMessages_DiagnosticsLevel_Variable"))
    , diagnostics_Counters_ReceivedNetworkMessages_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_ReceivedNetworkMessages_TimeFirstChange_Variable"))
    , diagnostics_Counters_ReceivedNetworkMessages_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_ReceivedNetworkMessages_Variable"))
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
    , diagnostics_LiveValues_ConfiguredDataSetReaders_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_LiveValues_ConfiguredDataSetReaders_DiagnosticsLevel_Variable"))
    , diagnostics_LiveValues_ConfiguredDataSetReaders_Variable_(boost::make_shared<ServerVariable>("Diagnostics_LiveValues_ConfiguredDataSetReaders_Variable"))
    , diagnostics_LiveValues_OperationalDataSetReaders_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_LiveValues_OperationalDataSetReaders_DiagnosticsLevel_Variable"))
    , diagnostics_LiveValues_OperationalDataSetReaders_Variable_(boost::make_shared<ServerVariable>("Diagnostics_LiveValues_OperationalDataSetReaders_Variable"))
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
    , maxNetworkMessageSize_Variable_(boost::make_shared<ServerVariable>("MaxNetworkMessageSize_Variable"))
    , securityGroupId_Variable_(boost::make_shared<ServerVariable>("SecurityGroupId_Variable"))
    , securityKeyServices_Variable_(boost::make_shared<ServerVariable>("SecurityKeyServices_Variable"))
    , securityMode_Variable_(boost::make_shared<ServerVariable>("SecurityMode_Variable"))
    , status_State_Variable_(boost::make_shared<ServerVariable>("Status_State_Variable"))
    , addDataSetReader_Method_(boost::make_shared<ServerMethod>("AddDataSetReader_Method"))
    , diagnostics_Reset_Method_(boost::make_shared<ServerMethod>("Diagnostics_Reset_Method"))
    , removeDataSetReader_Method_(boost::make_shared<ServerMethod>("RemoveDataSetReader_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)17999);
        setServerVariable(diagnostics_Counters_ReceivedNetworkMessages_Active_Variable_);
        setServerVariable(diagnostics_Counters_ReceivedNetworkMessages_Classification_Variable_);
        setServerVariable(diagnostics_Counters_ReceivedNetworkMessages_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_Counters_ReceivedNetworkMessages_TimeFirstChange_Variable_);
        setServerVariable(diagnostics_Counters_ReceivedNetworkMessages_Variable_);
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
        setServerVariable(diagnostics_LiveValues_ConfiguredDataSetReaders_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_LiveValues_ConfiguredDataSetReaders_Variable_);
        setServerVariable(diagnostics_LiveValues_OperationalDataSetReaders_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_LiveValues_OperationalDataSetReaders_Variable_);
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
        setServerVariable(maxNetworkMessageSize_Variable_);
        setServerVariable(securityGroupId_Variable_);
        setServerVariable(securityKeyServices_Variable_);
        setServerVariable(securityMode_Variable_);
        setServerVariable(status_State_Variable_);
        setServerMethod(addDataSetReader_Method_);
        setServerMethod(diagnostics_Reset_Method_);
        setServerMethod(removeDataSetReader_Method_);
        addDataSetReader_Method_->registerMethod(boost::bind(&ReaderGroupType::call_AddDataSetReader_Method, this, boost::placeholders::_1));
        diagnostics_Reset_Method_->registerMethod(boost::bind(&ReaderGroupType::call_Diagnostics_Reset_Method, this, boost::placeholders::_1));
        removeDataSetReader_Method_->registerMethod(boost::bind(&ReaderGroupType::call_RemoveDataSetReader_Method, this, boost::placeholders::_1));
    }
    
    ReaderGroupType::ReaderGroupType(const ReaderGroupType& value)
    : ObjectBase()
    , diagnostics_Counters_ReceivedNetworkMessages_Active_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_ReceivedNetworkMessages_Active_Variable"))
    , diagnostics_Counters_ReceivedNetworkMessages_Classification_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_ReceivedNetworkMessages_Classification_Variable"))
    , diagnostics_Counters_ReceivedNetworkMessages_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_ReceivedNetworkMessages_DiagnosticsLevel_Variable"))
    , diagnostics_Counters_ReceivedNetworkMessages_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_ReceivedNetworkMessages_TimeFirstChange_Variable"))
    , diagnostics_Counters_ReceivedNetworkMessages_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_ReceivedNetworkMessages_Variable"))
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
    , diagnostics_LiveValues_ConfiguredDataSetReaders_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_LiveValues_ConfiguredDataSetReaders_DiagnosticsLevel_Variable"))
    , diagnostics_LiveValues_ConfiguredDataSetReaders_Variable_(boost::make_shared<ServerVariable>("Diagnostics_LiveValues_ConfiguredDataSetReaders_Variable"))
    , diagnostics_LiveValues_OperationalDataSetReaders_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_LiveValues_OperationalDataSetReaders_DiagnosticsLevel_Variable"))
    , diagnostics_LiveValues_OperationalDataSetReaders_Variable_(boost::make_shared<ServerVariable>("Diagnostics_LiveValues_OperationalDataSetReaders_Variable"))
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
    , maxNetworkMessageSize_Variable_(boost::make_shared<ServerVariable>("MaxNetworkMessageSize_Variable"))
    , securityGroupId_Variable_(boost::make_shared<ServerVariable>("SecurityGroupId_Variable"))
    , securityKeyServices_Variable_(boost::make_shared<ServerVariable>("SecurityKeyServices_Variable"))
    , securityMode_Variable_(boost::make_shared<ServerVariable>("SecurityMode_Variable"))
    , status_State_Variable_(boost::make_shared<ServerVariable>("Status_State_Variable"))
    , addDataSetReader_Method_(boost::make_shared<ServerMethod>("AddDataSetReader_Method"))
    , diagnostics_Reset_Method_(boost::make_shared<ServerMethod>("Diagnostics_Reset_Method"))
    , removeDataSetReader_Method_(boost::make_shared<ServerMethod>("RemoveDataSetReader_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)17999);
        setServerVariable(diagnostics_Counters_ReceivedNetworkMessages_Active_Variable_);
        setServerVariable(diagnostics_Counters_ReceivedNetworkMessages_Classification_Variable_);
        setServerVariable(diagnostics_Counters_ReceivedNetworkMessages_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_Counters_ReceivedNetworkMessages_TimeFirstChange_Variable_);
        setServerVariable(diagnostics_Counters_ReceivedNetworkMessages_Variable_);
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
        setServerVariable(diagnostics_LiveValues_ConfiguredDataSetReaders_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_LiveValues_ConfiguredDataSetReaders_Variable_);
        setServerVariable(diagnostics_LiveValues_OperationalDataSetReaders_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_LiveValues_OperationalDataSetReaders_Variable_);
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
        setServerVariable(maxNetworkMessageSize_Variable_);
        setServerVariable(securityGroupId_Variable_);
        setServerVariable(securityKeyServices_Variable_);
        setServerVariable(securityMode_Variable_);
        setServerVariable(status_State_Variable_);
        setServerMethod(addDataSetReader_Method_);
        setServerMethod(diagnostics_Reset_Method_);
        setServerMethod(removeDataSetReader_Method_);
        addDataSetReader_Method_->registerMethod(boost::bind(&ReaderGroupType::call_AddDataSetReader_Method, this, boost::placeholders::_1));
        diagnostics_Reset_Method_->registerMethod(boost::bind(&ReaderGroupType::call_Diagnostics_Reset_Method, this, boost::placeholders::_1));
        removeDataSetReader_Method_->registerMethod(boost::bind(&ReaderGroupType::call_RemoveDataSetReader_Method, this, boost::placeholders::_1));
    }
    
    ReaderGroupType::~ReaderGroupType(void)
    {
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_Counters_ReceivedNetworkMessages_Active_Variable(void)
    {
        return diagnostics_Counters_ReceivedNetworkMessages_Active_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_Counters_ReceivedNetworkMessages_Classification_Variable(void)
    {
        return diagnostics_Counters_ReceivedNetworkMessages_Classification_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_Counters_ReceivedNetworkMessages_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_ReceivedNetworkMessages_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_Counters_ReceivedNetworkMessages_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_ReceivedNetworkMessages_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_Counters_ReceivedNetworkMessages_Variable(void)
    {
        return diagnostics_Counters_ReceivedNetworkMessages_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_Counters_StateDisabledByMethod_Active_Variable(void)
    {
        return diagnostics_Counters_StateDisabledByMethod_Active_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_Counters_StateDisabledByMethod_Classification_Variable(void)
    {
        return diagnostics_Counters_StateDisabledByMethod_Classification_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_Counters_StateDisabledByMethod_Variable(void)
    {
        return diagnostics_Counters_StateDisabledByMethod_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_Counters_StateError_Active_Variable(void)
    {
        return diagnostics_Counters_StateError_Active_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_Counters_StateError_Classification_Variable(void)
    {
        return diagnostics_Counters_StateError_Classification_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_Counters_StateError_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_StateError_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_Counters_StateError_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_StateError_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_Counters_StateError_Variable(void)
    {
        return diagnostics_Counters_StateError_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_Counters_StateOperationalByMethod_Active_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByMethod_Active_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_Counters_StateOperationalByMethod_Classification_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByMethod_Classification_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_Counters_StateOperationalByMethod_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByMethod_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_Counters_StateOperationalByParent_Active_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByParent_Active_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_Counters_StateOperationalByParent_Classification_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByParent_Classification_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_Counters_StateOperationalByParent_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByParent_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_Counters_StateOperationalFromError_Active_Variable(void)
    {
        return diagnostics_Counters_StateOperationalFromError_Active_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_Counters_StateOperationalFromError_Classification_Variable(void)
    {
        return diagnostics_Counters_StateOperationalFromError_Classification_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_Counters_StateOperationalFromError_Variable(void)
    {
        return diagnostics_Counters_StateOperationalFromError_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_Counters_StatePausedByParent_Active_Variable(void)
    {
        return diagnostics_Counters_StatePausedByParent_Active_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_Counters_StatePausedByParent_Classification_Variable(void)
    {
        return diagnostics_Counters_StatePausedByParent_Classification_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_Counters_StatePausedByParent_Variable(void)
    {
        return diagnostics_Counters_StatePausedByParent_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_LiveValues_ConfiguredDataSetReaders_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_LiveValues_ConfiguredDataSetReaders_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_LiveValues_ConfiguredDataSetReaders_Variable(void)
    {
        return diagnostics_LiveValues_ConfiguredDataSetReaders_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_LiveValues_OperationalDataSetReaders_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_LiveValues_OperationalDataSetReaders_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_LiveValues_OperationalDataSetReaders_Variable(void)
    {
        return diagnostics_LiveValues_OperationalDataSetReaders_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_SubError_Variable(void)
    {
        return diagnostics_SubError_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_TotalError_Active_Variable(void)
    {
        return diagnostics_TotalError_Active_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_TotalError_Classification_Variable(void)
    {
        return diagnostics_TotalError_Classification_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_TotalError_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_TotalError_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_TotalError_TimeFirstChange_Variable(void)
    {
        return diagnostics_TotalError_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_TotalError_Variable(void)
    {
        return diagnostics_TotalError_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_TotalInformation_Active_Variable(void)
    {
        return diagnostics_TotalInformation_Active_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_TotalInformation_Classification_Variable(void)
    {
        return diagnostics_TotalInformation_Classification_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_TotalInformation_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_TotalInformation_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_TotalInformation_TimeFirstChange_Variable(void)
    {
        return diagnostics_TotalInformation_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::diagnostics_TotalInformation_Variable(void)
    {
        return diagnostics_TotalInformation_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::groupProperties_Variable(void)
    {
        return groupProperties_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::maxNetworkMessageSize_Variable(void)
    {
        return maxNetworkMessageSize_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::securityGroupId_Variable(void)
    {
        return securityGroupId_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::securityKeyServices_Variable(void)
    {
        return securityKeyServices_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::securityMode_Variable(void)
    {
        return securityMode_Variable_;
    }

    ServerVariable::SPtr&
    ReaderGroupType::status_State_Variable(void)
    {
        return status_State_Variable_;
    }

    void
    ReaderGroupType::diagnostics_Counters_ReceivedNetworkMessages_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_ReceivedNetworkMessages_Active_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_Counters_ReceivedNetworkMessages_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_ReceivedNetworkMessages_Classification_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_Counters_ReceivedNetworkMessages_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_ReceivedNetworkMessages_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_Counters_ReceivedNetworkMessages_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_ReceivedNetworkMessages_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_Counters_ReceivedNetworkMessages_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_ReceivedNetworkMessages_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_Counters_StateDisabledByMethod_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateDisabledByMethod_Active_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_Counters_StateDisabledByMethod_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateDisabledByMethod_Classification_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_Counters_StateDisabledByMethod_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateDisabledByMethod_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_Counters_StateError_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateError_Active_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_Counters_StateError_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateError_Classification_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_Counters_StateError_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateError_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_Counters_StateError_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateError_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_Counters_StateError_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateError_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_Counters_StateOperationalByMethod_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByMethod_Active_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_Counters_StateOperationalByMethod_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByMethod_Classification_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_Counters_StateOperationalByMethod_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByMethod_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_Counters_StateOperationalByParent_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByParent_Active_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_Counters_StateOperationalByParent_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByParent_Classification_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_Counters_StateOperationalByParent_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByParent_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_Counters_StateOperationalFromError_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalFromError_Active_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_Counters_StateOperationalFromError_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalFromError_Classification_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_Counters_StateOperationalFromError_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalFromError_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_Counters_StatePausedByParent_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StatePausedByParent_Active_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_Counters_StatePausedByParent_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StatePausedByParent_Classification_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_Counters_StatePausedByParent_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StatePausedByParent_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_LiveValues_ConfiguredDataSetReaders_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_LiveValues_ConfiguredDataSetReaders_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_LiveValues_ConfiguredDataSetReaders_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_LiveValues_ConfiguredDataSetReaders_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_LiveValues_OperationalDataSetReaders_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_LiveValues_OperationalDataSetReaders_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_LiveValues_OperationalDataSetReaders_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_LiveValues_OperationalDataSetReaders_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_SubError_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_SubError_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_TotalError_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalError_Active_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_TotalError_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalError_Classification_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_TotalError_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalError_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_TotalError_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalError_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_TotalError_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalError_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_TotalInformation_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalInformation_Active_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_TotalInformation_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalInformation_Classification_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_TotalInformation_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalInformation_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_TotalInformation_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalInformation_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::diagnostics_TotalInformation_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalInformation_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::groupProperties_Variable(ServerVariable::SPtr& serverVariable)
    {
        groupProperties_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::maxNetworkMessageSize_Variable(ServerVariable::SPtr& serverVariable)
    {
        maxNetworkMessageSize_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::securityGroupId_Variable(ServerVariable::SPtr& serverVariable)
    {
        securityGroupId_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::securityKeyServices_Variable(ServerVariable::SPtr& serverVariable)
    {
        securityKeyServices_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::securityMode_Variable(ServerVariable::SPtr& serverVariable)
    {
        securityMode_Variable_ = serverVariable;
    }

    void
    ReaderGroupType::status_State_Variable(ServerVariable::SPtr& serverVariable)
    {
        status_State_Variable_ = serverVariable;
    }

    bool
    ReaderGroupType::get_Diagnostics_Counters_ReceivedNetworkMessages_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_ReceivedNetworkMessages_Active_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_Counters_ReceivedNetworkMessages_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_ReceivedNetworkMessages_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_Counters_ReceivedNetworkMessages_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_ReceivedNetworkMessages_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_Counters_ReceivedNetworkMessages_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_ReceivedNetworkMessages_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_Counters_ReceivedNetworkMessages_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_ReceivedNetworkMessages_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_Counters_StateDisabledByMethod_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_Active_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_Counters_StateDisabledByMethod_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_Counters_StateDisabledByMethod_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_Counters_StateError_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_Active_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_Counters_StateError_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_Counters_StateError_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_Counters_StateError_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_Counters_StateError_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_Counters_StateOperationalByMethod_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_Active_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_Counters_StateOperationalByMethod_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_Counters_StateOperationalByMethod_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_Counters_StateOperationalByParent_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_Active_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_Counters_StateOperationalByParent_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_Counters_StateOperationalByParent_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_Counters_StateOperationalFromError_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_Active_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_Counters_StateOperationalFromError_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_Counters_StateOperationalFromError_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_Counters_StatePausedByParent_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_Active_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_Counters_StatePausedByParent_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_Counters_StatePausedByParent_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_LiveValues_ConfiguredDataSetReaders_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_LiveValues_ConfiguredDataSetReaders_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_LiveValues_ConfiguredDataSetReaders_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_LiveValues_ConfiguredDataSetReaders_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_LiveValues_OperationalDataSetReaders_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_LiveValues_OperationalDataSetReaders_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_LiveValues_OperationalDataSetReaders_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_LiveValues_OperationalDataSetReaders_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_SubError_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_SubError_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_TotalError_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_Active_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_TotalError_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_TotalError_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_TotalError_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_TotalError_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_TotalInformation_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_Active_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_TotalInformation_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_TotalInformation_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_TotalInformation_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Diagnostics_TotalInformation_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_GroupProperties_Variable(OpcUaDataValue& dataValue)
    {
        return groupProperties_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_MaxNetworkMessageSize_Variable(OpcUaDataValue& dataValue)
    {
        return maxNetworkMessageSize_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_SecurityGroupId_Variable(OpcUaDataValue& dataValue)
    {
        return securityGroupId_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_SecurityKeyServices_Variable(OpcUaDataValue& dataValue)
    {
        return securityKeyServices_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_SecurityMode_Variable(OpcUaDataValue& dataValue)
    {
        return securityMode_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::get_Status_State_Variable(OpcUaDataValue& dataValue)
    {
        return status_State_Variable_->getDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_Counters_ReceivedNetworkMessages_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_ReceivedNetworkMessages_Active_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_Counters_ReceivedNetworkMessages_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_ReceivedNetworkMessages_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_Counters_ReceivedNetworkMessages_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_ReceivedNetworkMessages_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_Counters_ReceivedNetworkMessages_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_ReceivedNetworkMessages_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_Counters_ReceivedNetworkMessages_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_ReceivedNetworkMessages_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_Counters_StateDisabledByMethod_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_Active_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_Counters_StateDisabledByMethod_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_Counters_StateDisabledByMethod_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_Counters_StateError_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_Active_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_Counters_StateError_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_Counters_StateError_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_Counters_StateError_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_Counters_StateError_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_Counters_StateOperationalByMethod_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_Active_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_Counters_StateOperationalByMethod_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_Counters_StateOperationalByMethod_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_Counters_StateOperationalByParent_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_Active_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_Counters_StateOperationalByParent_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_Counters_StateOperationalByParent_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_Counters_StateOperationalFromError_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_Active_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_Counters_StateOperationalFromError_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_Counters_StateOperationalFromError_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_Counters_StatePausedByParent_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_Active_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_Counters_StatePausedByParent_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_Counters_StatePausedByParent_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_LiveValues_ConfiguredDataSetReaders_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_LiveValues_ConfiguredDataSetReaders_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_LiveValues_ConfiguredDataSetReaders_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_LiveValues_ConfiguredDataSetReaders_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_LiveValues_OperationalDataSetReaders_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_LiveValues_OperationalDataSetReaders_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_LiveValues_OperationalDataSetReaders_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_LiveValues_OperationalDataSetReaders_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_SubError_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_SubError_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_TotalError_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_Active_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_TotalError_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_TotalError_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_TotalError_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_TotalError_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_TotalInformation_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_Active_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_TotalInformation_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_TotalInformation_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_TotalInformation_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Diagnostics_TotalInformation_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_GroupProperties_Variable(const OpcUaDataValue& dataValue)
    {
        return groupProperties_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_MaxNetworkMessageSize_Variable(const OpcUaDataValue& dataValue)
    {
        return maxNetworkMessageSize_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_SecurityGroupId_Variable(const OpcUaDataValue& dataValue)
    {
        return securityGroupId_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_SecurityKeyServices_Variable(const OpcUaDataValue& dataValue)
    {
        return securityKeyServices_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_SecurityMode_Variable(const OpcUaDataValue& dataValue)
    {
        return securityMode_Variable_->setDataValue(dataValue);
    }

    bool
    ReaderGroupType::set_Status_State_Variable(const OpcUaDataValue& dataValue)
    {
        return status_State_Variable_->setDataValue(dataValue);
    }

    void
    ReaderGroupType::call_AddDataSetReader_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    ReaderGroupType::call_Diagnostics_Reset_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    ReaderGroupType::call_RemoveDataSetReader_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

}
