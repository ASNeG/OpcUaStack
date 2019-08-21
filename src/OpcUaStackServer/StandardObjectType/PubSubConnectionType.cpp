/*
    VariableTypeClass: PubSubConnectionType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/PubSubConnectionType.h"

namespace OpcUaStackServer
{
    
    PubSubConnectionType::PubSubConnectionType(void)
    : ObjectBase()
    , address_NetworkInterface_Variable_(boost::make_shared<ServerVariable>("Address_NetworkInterface_Variable"))
    , connectionProperties_Variable_(boost::make_shared<ServerVariable>("ConnectionProperties_Variable"))
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
    , diagnostics_LiveValues_ResolvedAddress_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_LiveValues_ResolvedAddress_DiagnosticsLevel_Variable"))
    , diagnostics_LiveValues_ResolvedAddress_Variable_(boost::make_shared<ServerVariable>("Diagnostics_LiveValues_ResolvedAddress_Variable"))
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
    , publisherId_Variable_(boost::make_shared<ServerVariable>("PublisherId_Variable"))
    , status_State_Variable_(boost::make_shared<ServerVariable>("Status_State_Variable"))
    , transportProfileUri_Selections_Variable_(boost::make_shared<ServerVariable>("TransportProfileUri_Selections_Variable"))
    , transportProfileUri_Variable_(boost::make_shared<ServerVariable>("TransportProfileUri_Variable"))
    , addReaderGroup_Method_(boost::make_shared<ServerMethod>("AddReaderGroup_Method"))
    , addWriterGroup_Method_(boost::make_shared<ServerMethod>("AddWriterGroup_Method"))
    , diagnostics_Reset_Method_(boost::make_shared<ServerMethod>("Diagnostics_Reset_Method"))
    , removeGroup_Method_(boost::make_shared<ServerMethod>("RemoveGroup_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)14209);
        setServerVariable(address_NetworkInterface_Variable_);
        setServerVariable(connectionProperties_Variable_);
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
        setServerVariable(diagnostics_LiveValues_ResolvedAddress_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_LiveValues_ResolvedAddress_Variable_);
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
        setServerVariable(publisherId_Variable_);
        setServerVariable(status_State_Variable_);
        setServerVariable(transportProfileUri_Selections_Variable_);
        setServerVariable(transportProfileUri_Variable_);
        setServerMethod(addReaderGroup_Method_);
        setServerMethod(addWriterGroup_Method_);
        setServerMethod(diagnostics_Reset_Method_);
        setServerMethod(removeGroup_Method_);
        addReaderGroup_Method_->registerMethod(boost::bind(&PubSubConnectionType::call_AddReaderGroup_Method, this, _1));
        addWriterGroup_Method_->registerMethod(boost::bind(&PubSubConnectionType::call_AddWriterGroup_Method, this, _1));
        diagnostics_Reset_Method_->registerMethod(boost::bind(&PubSubConnectionType::call_Diagnostics_Reset_Method, this, _1));
        removeGroup_Method_->registerMethod(boost::bind(&PubSubConnectionType::call_RemoveGroup_Method, this, _1));
    }
    
    PubSubConnectionType::PubSubConnectionType(const PubSubConnectionType& value)
    : ObjectBase()
    , address_NetworkInterface_Variable_(boost::make_shared<ServerVariable>("Address_NetworkInterface_Variable"))
    , connectionProperties_Variable_(boost::make_shared<ServerVariable>("ConnectionProperties_Variable"))
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
    , diagnostics_LiveValues_ResolvedAddress_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_LiveValues_ResolvedAddress_DiagnosticsLevel_Variable"))
    , diagnostics_LiveValues_ResolvedAddress_Variable_(boost::make_shared<ServerVariable>("Diagnostics_LiveValues_ResolvedAddress_Variable"))
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
    , publisherId_Variable_(boost::make_shared<ServerVariable>("PublisherId_Variable"))
    , status_State_Variable_(boost::make_shared<ServerVariable>("Status_State_Variable"))
    , transportProfileUri_Selections_Variable_(boost::make_shared<ServerVariable>("TransportProfileUri_Selections_Variable"))
    , transportProfileUri_Variable_(boost::make_shared<ServerVariable>("TransportProfileUri_Variable"))
    , addReaderGroup_Method_(boost::make_shared<ServerMethod>("AddReaderGroup_Method"))
    , addWriterGroup_Method_(boost::make_shared<ServerMethod>("AddWriterGroup_Method"))
    , diagnostics_Reset_Method_(boost::make_shared<ServerMethod>("Diagnostics_Reset_Method"))
    , removeGroup_Method_(boost::make_shared<ServerMethod>("RemoveGroup_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)14209);
        setServerVariable(address_NetworkInterface_Variable_);
        setServerVariable(connectionProperties_Variable_);
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
        setServerVariable(diagnostics_LiveValues_ResolvedAddress_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_LiveValues_ResolvedAddress_Variable_);
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
        setServerVariable(publisherId_Variable_);
        setServerVariable(status_State_Variable_);
        setServerVariable(transportProfileUri_Selections_Variable_);
        setServerVariable(transportProfileUri_Variable_);
        setServerMethod(addReaderGroup_Method_);
        setServerMethod(addWriterGroup_Method_);
        setServerMethod(diagnostics_Reset_Method_);
        setServerMethod(removeGroup_Method_);
        addReaderGroup_Method_->registerMethod(boost::bind(&PubSubConnectionType::call_AddReaderGroup_Method, this, _1));
        addWriterGroup_Method_->registerMethod(boost::bind(&PubSubConnectionType::call_AddWriterGroup_Method, this, _1));
        diagnostics_Reset_Method_->registerMethod(boost::bind(&PubSubConnectionType::call_Diagnostics_Reset_Method, this, _1));
        removeGroup_Method_->registerMethod(boost::bind(&PubSubConnectionType::call_RemoveGroup_Method, this, _1));
    }
    
    PubSubConnectionType::~PubSubConnectionType(void)
    {
    }

    ServerVariable::SPtr&
    PubSubConnectionType::address_NetworkInterface_Variable(void)
    {
        return address_NetworkInterface_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::connectionProperties_Variable(void)
    {
        return connectionProperties_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_Counters_StateDisabledByMethod_Active_Variable(void)
    {
        return diagnostics_Counters_StateDisabledByMethod_Active_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_Counters_StateDisabledByMethod_Classification_Variable(void)
    {
        return diagnostics_Counters_StateDisabledByMethod_Classification_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_Counters_StateDisabledByMethod_Variable(void)
    {
        return diagnostics_Counters_StateDisabledByMethod_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_Counters_StateError_Active_Variable(void)
    {
        return diagnostics_Counters_StateError_Active_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_Counters_StateError_Classification_Variable(void)
    {
        return diagnostics_Counters_StateError_Classification_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_Counters_StateError_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_StateError_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_Counters_StateError_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_StateError_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_Counters_StateError_Variable(void)
    {
        return diagnostics_Counters_StateError_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_Counters_StateOperationalByMethod_Active_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByMethod_Active_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_Counters_StateOperationalByMethod_Classification_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByMethod_Classification_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_Counters_StateOperationalByMethod_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByMethod_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_Counters_StateOperationalByParent_Active_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByParent_Active_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_Counters_StateOperationalByParent_Classification_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByParent_Classification_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_Counters_StateOperationalByParent_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByParent_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_Counters_StateOperationalFromError_Active_Variable(void)
    {
        return diagnostics_Counters_StateOperationalFromError_Active_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_Counters_StateOperationalFromError_Classification_Variable(void)
    {
        return diagnostics_Counters_StateOperationalFromError_Classification_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_Counters_StateOperationalFromError_Variable(void)
    {
        return diagnostics_Counters_StateOperationalFromError_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_Counters_StatePausedByParent_Active_Variable(void)
    {
        return diagnostics_Counters_StatePausedByParent_Active_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_Counters_StatePausedByParent_Classification_Variable(void)
    {
        return diagnostics_Counters_StatePausedByParent_Classification_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_Counters_StatePausedByParent_Variable(void)
    {
        return diagnostics_Counters_StatePausedByParent_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_LiveValues_ResolvedAddress_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_LiveValues_ResolvedAddress_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_LiveValues_ResolvedAddress_Variable(void)
    {
        return diagnostics_LiveValues_ResolvedAddress_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_SubError_Variable(void)
    {
        return diagnostics_SubError_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_TotalError_Active_Variable(void)
    {
        return diagnostics_TotalError_Active_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_TotalError_Classification_Variable(void)
    {
        return diagnostics_TotalError_Classification_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_TotalError_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_TotalError_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_TotalError_TimeFirstChange_Variable(void)
    {
        return diagnostics_TotalError_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_TotalError_Variable(void)
    {
        return diagnostics_TotalError_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_TotalInformation_Active_Variable(void)
    {
        return diagnostics_TotalInformation_Active_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_TotalInformation_Classification_Variable(void)
    {
        return diagnostics_TotalInformation_Classification_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_TotalInformation_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_TotalInformation_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_TotalInformation_TimeFirstChange_Variable(void)
    {
        return diagnostics_TotalInformation_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::diagnostics_TotalInformation_Variable(void)
    {
        return diagnostics_TotalInformation_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::publisherId_Variable(void)
    {
        return publisherId_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::status_State_Variable(void)
    {
        return status_State_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::transportProfileUri_Selections_Variable(void)
    {
        return transportProfileUri_Selections_Variable_;
    }

    ServerVariable::SPtr&
    PubSubConnectionType::transportProfileUri_Variable(void)
    {
        return transportProfileUri_Variable_;
    }

    void
    PubSubConnectionType::address_NetworkInterface_Variable(ServerVariable::SPtr& serverVariable)
    {
        address_NetworkInterface_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::connectionProperties_Variable(ServerVariable::SPtr& serverVariable)
    {
        connectionProperties_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_Counters_StateDisabledByMethod_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateDisabledByMethod_Active_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_Counters_StateDisabledByMethod_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateDisabledByMethod_Classification_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_Counters_StateDisabledByMethod_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateDisabledByMethod_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_Counters_StateError_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateError_Active_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_Counters_StateError_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateError_Classification_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_Counters_StateError_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateError_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_Counters_StateError_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateError_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_Counters_StateError_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateError_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_Counters_StateOperationalByMethod_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByMethod_Active_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_Counters_StateOperationalByMethod_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByMethod_Classification_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_Counters_StateOperationalByMethod_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByMethod_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_Counters_StateOperationalByParent_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByParent_Active_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_Counters_StateOperationalByParent_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByParent_Classification_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_Counters_StateOperationalByParent_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByParent_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_Counters_StateOperationalFromError_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalFromError_Active_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_Counters_StateOperationalFromError_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalFromError_Classification_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_Counters_StateOperationalFromError_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalFromError_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_Counters_StatePausedByParent_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StatePausedByParent_Active_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_Counters_StatePausedByParent_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StatePausedByParent_Classification_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_Counters_StatePausedByParent_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StatePausedByParent_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_LiveValues_ResolvedAddress_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_LiveValues_ResolvedAddress_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_LiveValues_ResolvedAddress_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_LiveValues_ResolvedAddress_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_SubError_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_SubError_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_TotalError_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalError_Active_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_TotalError_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalError_Classification_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_TotalError_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalError_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_TotalError_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalError_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_TotalError_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalError_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_TotalInformation_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalInformation_Active_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_TotalInformation_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalInformation_Classification_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_TotalInformation_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalInformation_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_TotalInformation_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalInformation_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::diagnostics_TotalInformation_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalInformation_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::publisherId_Variable(ServerVariable::SPtr& serverVariable)
    {
        publisherId_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::status_State_Variable(ServerVariable::SPtr& serverVariable)
    {
        status_State_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::transportProfileUri_Selections_Variable(ServerVariable::SPtr& serverVariable)
    {
        transportProfileUri_Selections_Variable_ = serverVariable;
    }

    void
    PubSubConnectionType::transportProfileUri_Variable(ServerVariable::SPtr& serverVariable)
    {
        transportProfileUri_Variable_ = serverVariable;
    }

    bool
    PubSubConnectionType::get_Address_NetworkInterface_Variable(OpcUaDataValue& dataValue)
    {
        return address_NetworkInterface_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_ConnectionProperties_Variable(OpcUaDataValue& dataValue)
    {
        return connectionProperties_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_Counters_StateDisabledByMethod_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_Active_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_Counters_StateDisabledByMethod_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_Counters_StateDisabledByMethod_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_Counters_StateError_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_Active_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_Counters_StateError_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_Counters_StateError_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_Counters_StateError_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_Counters_StateError_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_Counters_StateOperationalByMethod_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_Active_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_Counters_StateOperationalByMethod_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_Counters_StateOperationalByMethod_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_Counters_StateOperationalByParent_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_Active_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_Counters_StateOperationalByParent_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_Counters_StateOperationalByParent_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_Counters_StateOperationalFromError_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_Active_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_Counters_StateOperationalFromError_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_Counters_StateOperationalFromError_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_Counters_StatePausedByParent_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_Active_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_Counters_StatePausedByParent_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_Counters_StatePausedByParent_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_LiveValues_ResolvedAddress_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_LiveValues_ResolvedAddress_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_LiveValues_ResolvedAddress_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_LiveValues_ResolvedAddress_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_SubError_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_SubError_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_TotalError_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_Active_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_TotalError_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_TotalError_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_TotalError_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_TotalError_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_TotalInformation_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_Active_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_TotalInformation_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_TotalInformation_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_TotalInformation_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Diagnostics_TotalInformation_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_PublisherId_Variable(OpcUaDataValue& dataValue)
    {
        return publisherId_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_Status_State_Variable(OpcUaDataValue& dataValue)
    {
        return status_State_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_TransportProfileUri_Selections_Variable(OpcUaDataValue& dataValue)
    {
        return transportProfileUri_Selections_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::get_TransportProfileUri_Variable(OpcUaDataValue& dataValue)
    {
        return transportProfileUri_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Address_NetworkInterface_Variable(const OpcUaDataValue& dataValue)
    {
        return address_NetworkInterface_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_ConnectionProperties_Variable(const OpcUaDataValue& dataValue)
    {
        return connectionProperties_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_Counters_StateDisabledByMethod_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_Active_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_Counters_StateDisabledByMethod_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_Counters_StateDisabledByMethod_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_Counters_StateError_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_Active_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_Counters_StateError_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_Counters_StateError_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_Counters_StateError_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_Counters_StateError_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_Counters_StateOperationalByMethod_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_Active_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_Counters_StateOperationalByMethod_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_Counters_StateOperationalByMethod_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_Counters_StateOperationalByParent_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_Active_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_Counters_StateOperationalByParent_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_Counters_StateOperationalByParent_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_Counters_StateOperationalFromError_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_Active_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_Counters_StateOperationalFromError_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_Counters_StateOperationalFromError_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_Counters_StatePausedByParent_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_Active_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_Counters_StatePausedByParent_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_Counters_StatePausedByParent_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_LiveValues_ResolvedAddress_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_LiveValues_ResolvedAddress_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_LiveValues_ResolvedAddress_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_LiveValues_ResolvedAddress_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_SubError_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_SubError_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_TotalError_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_Active_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_TotalError_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_TotalError_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_TotalError_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_TotalError_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_TotalInformation_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_Active_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_TotalInformation_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_TotalInformation_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_TotalInformation_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Diagnostics_TotalInformation_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_PublisherId_Variable(const OpcUaDataValue& dataValue)
    {
        return publisherId_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_Status_State_Variable(const OpcUaDataValue& dataValue)
    {
        return status_State_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_TransportProfileUri_Selections_Variable(const OpcUaDataValue& dataValue)
    {
        return transportProfileUri_Selections_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubConnectionType::set_TransportProfileUri_Variable(const OpcUaDataValue& dataValue)
    {
        return transportProfileUri_Variable_->setDataValue(dataValue);
    }

    void
    PubSubConnectionType::call_AddReaderGroup_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    PubSubConnectionType::call_AddWriterGroup_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    PubSubConnectionType::call_Diagnostics_Reset_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    PubSubConnectionType::call_RemoveGroup_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

}
