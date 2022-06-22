/*
    VariableTypeClass: PublishSubscribeType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/PublishSubscribeType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    PublishSubscribeType::PublishSubscribeType(void)
    : ObjectBase()
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
    , diagnostics_LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable"))
    , diagnostics_LiveValues_ConfiguredDataSetWriters_Variable_(boost::make_shared<ServerVariable>("Diagnostics_LiveValues_ConfiguredDataSetWriters_Variable"))
    , diagnostics_LiveValues_OperationalDataSetReaders_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_LiveValues_OperationalDataSetReaders_DiagnosticsLevel_Variable"))
    , diagnostics_LiveValues_OperationalDataSetReaders_Variable_(boost::make_shared<ServerVariable>("Diagnostics_LiveValues_OperationalDataSetReaders_Variable"))
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
    , status_State_Variable_(boost::make_shared<ServerVariable>("Status_State_Variable"))
    , supportedTransportProfiles_Variable_(boost::make_shared<ServerVariable>("SupportedTransportProfiles_Variable"))
    , addConnection_Method_(boost::make_shared<ServerMethod>("AddConnection_Method"))
    , diagnostics_Reset_Method_(boost::make_shared<ServerMethod>("Diagnostics_Reset_Method"))
    , getSecurityGroup_Method_(boost::make_shared<ServerMethod>("GetSecurityGroup_Method"))
    , getSecurityKeys_Method_(boost::make_shared<ServerMethod>("GetSecurityKeys_Method"))
    , removeConnection_Method_(boost::make_shared<ServerMethod>("RemoveConnection_Method"))
    , securityGroups_AddSecurityGroup_Method_(boost::make_shared<ServerMethod>("SecurityGroups_AddSecurityGroup_Method"))
    , securityGroups_RemoveSecurityGroup_Method_(boost::make_shared<ServerMethod>("SecurityGroups_RemoveSecurityGroup_Method"))
    , setSecurityKeys_Method_(boost::make_shared<ServerMethod>("SetSecurityKeys_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)14416);
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
        setServerVariable(diagnostics_LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_LiveValues_ConfiguredDataSetWriters_Variable_);
        setServerVariable(diagnostics_LiveValues_OperationalDataSetReaders_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_LiveValues_OperationalDataSetReaders_Variable_);
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
        setServerVariable(status_State_Variable_);
        setServerVariable(supportedTransportProfiles_Variable_);
        setServerMethod(addConnection_Method_);
        setServerMethod(diagnostics_Reset_Method_);
        setServerMethod(getSecurityGroup_Method_);
        setServerMethod(getSecurityKeys_Method_);
        setServerMethod(removeConnection_Method_);
        setServerMethod(securityGroups_AddSecurityGroup_Method_);
        setServerMethod(securityGroups_RemoveSecurityGroup_Method_);
        setServerMethod(setSecurityKeys_Method_);
        addConnection_Method_->registerMethod(boost::bind(&PublishSubscribeType::call_AddConnection_Method, this, _1));
        diagnostics_Reset_Method_->registerMethod(boost::bind(&PublishSubscribeType::call_Diagnostics_Reset_Method, this, _1));
        getSecurityGroup_Method_->registerMethod(boost::bind(&PublishSubscribeType::call_GetSecurityGroup_Method, this, _1));
        getSecurityKeys_Method_->registerMethod(boost::bind(&PublishSubscribeType::call_GetSecurityKeys_Method, this, _1));
        removeConnection_Method_->registerMethod(boost::bind(&PublishSubscribeType::call_RemoveConnection_Method, this, _1));
        securityGroups_AddSecurityGroup_Method_->registerMethod(boost::bind(&PublishSubscribeType::call_SecurityGroups_AddSecurityGroup_Method, this, _1));
        securityGroups_RemoveSecurityGroup_Method_->registerMethod(boost::bind(&PublishSubscribeType::call_SecurityGroups_RemoveSecurityGroup_Method, this, _1));
        setSecurityKeys_Method_->registerMethod(boost::bind(&PublishSubscribeType::call_SetSecurityKeys_Method, this, _1));
    }
    
    PublishSubscribeType::PublishSubscribeType(const PublishSubscribeType& value)
    : ObjectBase()
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
    , diagnostics_LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable"))
    , diagnostics_LiveValues_ConfiguredDataSetWriters_Variable_(boost::make_shared<ServerVariable>("Diagnostics_LiveValues_ConfiguredDataSetWriters_Variable"))
    , diagnostics_LiveValues_OperationalDataSetReaders_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_LiveValues_OperationalDataSetReaders_DiagnosticsLevel_Variable"))
    , diagnostics_LiveValues_OperationalDataSetReaders_Variable_(boost::make_shared<ServerVariable>("Diagnostics_LiveValues_OperationalDataSetReaders_Variable"))
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
    , status_State_Variable_(boost::make_shared<ServerVariable>("Status_State_Variable"))
    , supportedTransportProfiles_Variable_(boost::make_shared<ServerVariable>("SupportedTransportProfiles_Variable"))
    , addConnection_Method_(boost::make_shared<ServerMethod>("AddConnection_Method"))
    , diagnostics_Reset_Method_(boost::make_shared<ServerMethod>("Diagnostics_Reset_Method"))
    , getSecurityGroup_Method_(boost::make_shared<ServerMethod>("GetSecurityGroup_Method"))
    , getSecurityKeys_Method_(boost::make_shared<ServerMethod>("GetSecurityKeys_Method"))
    , removeConnection_Method_(boost::make_shared<ServerMethod>("RemoveConnection_Method"))
    , securityGroups_AddSecurityGroup_Method_(boost::make_shared<ServerMethod>("SecurityGroups_AddSecurityGroup_Method"))
    , securityGroups_RemoveSecurityGroup_Method_(boost::make_shared<ServerMethod>("SecurityGroups_RemoveSecurityGroup_Method"))
    , setSecurityKeys_Method_(boost::make_shared<ServerMethod>("SetSecurityKeys_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)14416);
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
        setServerVariable(diagnostics_LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_LiveValues_ConfiguredDataSetWriters_Variable_);
        setServerVariable(diagnostics_LiveValues_OperationalDataSetReaders_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_LiveValues_OperationalDataSetReaders_Variable_);
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
        setServerVariable(status_State_Variable_);
        setServerVariable(supportedTransportProfiles_Variable_);
        setServerMethod(addConnection_Method_);
        setServerMethod(diagnostics_Reset_Method_);
        setServerMethod(getSecurityGroup_Method_);
        setServerMethod(getSecurityKeys_Method_);
        setServerMethod(removeConnection_Method_);
        setServerMethod(securityGroups_AddSecurityGroup_Method_);
        setServerMethod(securityGroups_RemoveSecurityGroup_Method_);
        setServerMethod(setSecurityKeys_Method_);
        addConnection_Method_->registerMethod(boost::bind(&PublishSubscribeType::call_AddConnection_Method, this, _1));
        diagnostics_Reset_Method_->registerMethod(boost::bind(&PublishSubscribeType::call_Diagnostics_Reset_Method, this, _1));
        getSecurityGroup_Method_->registerMethod(boost::bind(&PublishSubscribeType::call_GetSecurityGroup_Method, this, _1));
        getSecurityKeys_Method_->registerMethod(boost::bind(&PublishSubscribeType::call_GetSecurityKeys_Method, this, _1));
        removeConnection_Method_->registerMethod(boost::bind(&PublishSubscribeType::call_RemoveConnection_Method, this, _1));
        securityGroups_AddSecurityGroup_Method_->registerMethod(boost::bind(&PublishSubscribeType::call_SecurityGroups_AddSecurityGroup_Method, this, _1));
        securityGroups_RemoveSecurityGroup_Method_->registerMethod(boost::bind(&PublishSubscribeType::call_SecurityGroups_RemoveSecurityGroup_Method, this, _1));
        setSecurityKeys_Method_->registerMethod(boost::bind(&PublishSubscribeType::call_SetSecurityKeys_Method, this, _1));
    }
    
    PublishSubscribeType::~PublishSubscribeType(void)
    {
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_Counters_StateDisabledByMethod_Active_Variable(void)
    {
        return diagnostics_Counters_StateDisabledByMethod_Active_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_Counters_StateDisabledByMethod_Classification_Variable(void)
    {
        return diagnostics_Counters_StateDisabledByMethod_Classification_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_Counters_StateDisabledByMethod_Variable(void)
    {
        return diagnostics_Counters_StateDisabledByMethod_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_Counters_StateError_Active_Variable(void)
    {
        return diagnostics_Counters_StateError_Active_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_Counters_StateError_Classification_Variable(void)
    {
        return diagnostics_Counters_StateError_Classification_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_Counters_StateError_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_StateError_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_Counters_StateError_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_StateError_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_Counters_StateError_Variable(void)
    {
        return diagnostics_Counters_StateError_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_Counters_StateOperationalByMethod_Active_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByMethod_Active_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_Counters_StateOperationalByMethod_Classification_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByMethod_Classification_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_Counters_StateOperationalByMethod_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByMethod_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_Counters_StateOperationalByParent_Active_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByParent_Active_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_Counters_StateOperationalByParent_Classification_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByParent_Classification_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_Counters_StateOperationalByParent_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByParent_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_Counters_StateOperationalFromError_Active_Variable(void)
    {
        return diagnostics_Counters_StateOperationalFromError_Active_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_Counters_StateOperationalFromError_Classification_Variable(void)
    {
        return diagnostics_Counters_StateOperationalFromError_Classification_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_Counters_StateOperationalFromError_Variable(void)
    {
        return diagnostics_Counters_StateOperationalFromError_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_Counters_StatePausedByParent_Active_Variable(void)
    {
        return diagnostics_Counters_StatePausedByParent_Active_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_Counters_StatePausedByParent_Classification_Variable(void)
    {
        return diagnostics_Counters_StatePausedByParent_Classification_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_Counters_StatePausedByParent_Variable(void)
    {
        return diagnostics_Counters_StatePausedByParent_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_LiveValues_ConfiguredDataSetReaders_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_LiveValues_ConfiguredDataSetReaders_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_LiveValues_ConfiguredDataSetReaders_Variable(void)
    {
        return diagnostics_LiveValues_ConfiguredDataSetReaders_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_LiveValues_ConfiguredDataSetWriters_Variable(void)
    {
        return diagnostics_LiveValues_ConfiguredDataSetWriters_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_LiveValues_OperationalDataSetReaders_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_LiveValues_OperationalDataSetReaders_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_LiveValues_OperationalDataSetReaders_Variable(void)
    {
        return diagnostics_LiveValues_OperationalDataSetReaders_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_LiveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_LiveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_LiveValues_OperationalDataSetWriters_Variable(void)
    {
        return diagnostics_LiveValues_OperationalDataSetWriters_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_SubError_Variable(void)
    {
        return diagnostics_SubError_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_TotalError_Active_Variable(void)
    {
        return diagnostics_TotalError_Active_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_TotalError_Classification_Variable(void)
    {
        return diagnostics_TotalError_Classification_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_TotalError_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_TotalError_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_TotalError_TimeFirstChange_Variable(void)
    {
        return diagnostics_TotalError_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_TotalError_Variable(void)
    {
        return diagnostics_TotalError_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_TotalInformation_Active_Variable(void)
    {
        return diagnostics_TotalInformation_Active_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_TotalInformation_Classification_Variable(void)
    {
        return diagnostics_TotalInformation_Classification_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_TotalInformation_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_TotalInformation_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_TotalInformation_TimeFirstChange_Variable(void)
    {
        return diagnostics_TotalInformation_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::diagnostics_TotalInformation_Variable(void)
    {
        return diagnostics_TotalInformation_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::status_State_Variable(void)
    {
        return status_State_Variable_;
    }

    ServerVariable::SPtr&
    PublishSubscribeType::supportedTransportProfiles_Variable(void)
    {
        return supportedTransportProfiles_Variable_;
    }

    void
    PublishSubscribeType::diagnostics_Counters_StateDisabledByMethod_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateDisabledByMethod_Active_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_Counters_StateDisabledByMethod_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateDisabledByMethod_Classification_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_Counters_StateDisabledByMethod_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateDisabledByMethod_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_Counters_StateError_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateError_Active_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_Counters_StateError_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateError_Classification_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_Counters_StateError_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateError_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_Counters_StateError_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateError_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_Counters_StateError_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateError_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_Counters_StateOperationalByMethod_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByMethod_Active_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_Counters_StateOperationalByMethod_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByMethod_Classification_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_Counters_StateOperationalByMethod_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByMethod_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_Counters_StateOperationalByParent_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByParent_Active_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_Counters_StateOperationalByParent_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByParent_Classification_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_Counters_StateOperationalByParent_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByParent_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_Counters_StateOperationalFromError_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalFromError_Active_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_Counters_StateOperationalFromError_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalFromError_Classification_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_Counters_StateOperationalFromError_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalFromError_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_Counters_StatePausedByParent_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StatePausedByParent_Active_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_Counters_StatePausedByParent_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StatePausedByParent_Classification_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_Counters_StatePausedByParent_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StatePausedByParent_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_LiveValues_ConfiguredDataSetReaders_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_LiveValues_ConfiguredDataSetReaders_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_LiveValues_ConfiguredDataSetReaders_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_LiveValues_ConfiguredDataSetReaders_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_LiveValues_ConfiguredDataSetWriters_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_LiveValues_ConfiguredDataSetWriters_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_LiveValues_OperationalDataSetReaders_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_LiveValues_OperationalDataSetReaders_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_LiveValues_OperationalDataSetReaders_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_LiveValues_OperationalDataSetReaders_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_LiveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_LiveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_LiveValues_OperationalDataSetWriters_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_LiveValues_OperationalDataSetWriters_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_SubError_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_SubError_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_TotalError_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalError_Active_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_TotalError_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalError_Classification_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_TotalError_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalError_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_TotalError_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalError_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_TotalError_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalError_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_TotalInformation_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalInformation_Active_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_TotalInformation_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalInformation_Classification_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_TotalInformation_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalInformation_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_TotalInformation_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalInformation_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::diagnostics_TotalInformation_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalInformation_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::status_State_Variable(ServerVariable::SPtr& serverVariable)
    {
        status_State_Variable_ = serverVariable;
    }

    void
    PublishSubscribeType::supportedTransportProfiles_Variable(ServerVariable::SPtr& serverVariable)
    {
        supportedTransportProfiles_Variable_ = serverVariable;
    }

    bool
    PublishSubscribeType::get_Diagnostics_Counters_StateDisabledByMethod_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_Active_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_Counters_StateDisabledByMethod_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_Counters_StateDisabledByMethod_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_Counters_StateError_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_Active_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_Counters_StateError_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_Counters_StateError_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_Counters_StateError_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_Counters_StateError_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_Counters_StateOperationalByMethod_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_Active_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_Counters_StateOperationalByMethod_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_Counters_StateOperationalByMethod_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_Counters_StateOperationalByParent_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_Active_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_Counters_StateOperationalByParent_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_Counters_StateOperationalByParent_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_Counters_StateOperationalFromError_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_Active_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_Counters_StateOperationalFromError_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_Counters_StateOperationalFromError_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_Counters_StatePausedByParent_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_Active_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_Counters_StatePausedByParent_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_Counters_StatePausedByParent_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_LiveValues_ConfiguredDataSetReaders_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_LiveValues_ConfiguredDataSetReaders_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_LiveValues_ConfiguredDataSetReaders_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_LiveValues_ConfiguredDataSetReaders_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_LiveValues_ConfiguredDataSetWriters_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_LiveValues_ConfiguredDataSetWriters_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_LiveValues_OperationalDataSetReaders_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_LiveValues_OperationalDataSetReaders_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_LiveValues_OperationalDataSetReaders_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_LiveValues_OperationalDataSetReaders_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_LiveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_LiveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_LiveValues_OperationalDataSetWriters_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_LiveValues_OperationalDataSetWriters_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_SubError_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_SubError_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_TotalError_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_Active_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_TotalError_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_TotalError_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_TotalError_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_TotalError_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_TotalInformation_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_Active_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_TotalInformation_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_TotalInformation_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_TotalInformation_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Diagnostics_TotalInformation_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_Status_State_Variable(OpcUaDataValue& dataValue)
    {
        return status_State_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::get_SupportedTransportProfiles_Variable(OpcUaDataValue& dataValue)
    {
        return supportedTransportProfiles_Variable_->getDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_Counters_StateDisabledByMethod_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_Active_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_Counters_StateDisabledByMethod_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_Counters_StateDisabledByMethod_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_Counters_StateError_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_Active_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_Counters_StateError_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_Counters_StateError_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_Counters_StateError_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_Counters_StateError_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_Counters_StateOperationalByMethod_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_Active_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_Counters_StateOperationalByMethod_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_Counters_StateOperationalByMethod_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_Counters_StateOperationalByParent_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_Active_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_Counters_StateOperationalByParent_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_Counters_StateOperationalByParent_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_Counters_StateOperationalFromError_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_Active_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_Counters_StateOperationalFromError_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_Counters_StateOperationalFromError_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_Counters_StatePausedByParent_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_Active_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_Counters_StatePausedByParent_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_Counters_StatePausedByParent_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_LiveValues_ConfiguredDataSetReaders_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_LiveValues_ConfiguredDataSetReaders_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_LiveValues_ConfiguredDataSetReaders_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_LiveValues_ConfiguredDataSetReaders_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_LiveValues_ConfiguredDataSetWriters_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_LiveValues_ConfiguredDataSetWriters_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_LiveValues_OperationalDataSetReaders_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_LiveValues_OperationalDataSetReaders_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_LiveValues_OperationalDataSetReaders_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_LiveValues_OperationalDataSetReaders_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_LiveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_LiveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_LiveValues_OperationalDataSetWriters_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_LiveValues_OperationalDataSetWriters_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_SubError_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_SubError_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_TotalError_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_Active_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_TotalError_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_TotalError_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_TotalError_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_TotalError_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_TotalInformation_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_Active_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_TotalInformation_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_TotalInformation_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_TotalInformation_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Diagnostics_TotalInformation_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_Status_State_Variable(const OpcUaDataValue& dataValue)
    {
        return status_State_Variable_->setDataValue(dataValue);
    }

    bool
    PublishSubscribeType::set_SupportedTransportProfiles_Variable(const OpcUaDataValue& dataValue)
    {
        return supportedTransportProfiles_Variable_->setDataValue(dataValue);
    }

    void
    PublishSubscribeType::call_AddConnection_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    PublishSubscribeType::call_Diagnostics_Reset_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    PublishSubscribeType::call_GetSecurityGroup_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    PublishSubscribeType::call_GetSecurityKeys_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    PublishSubscribeType::call_RemoveConnection_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    PublishSubscribeType::call_SecurityGroups_AddSecurityGroup_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    PublishSubscribeType::call_SecurityGroups_RemoveSecurityGroup_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    PublishSubscribeType::call_SetSecurityKeys_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

}
