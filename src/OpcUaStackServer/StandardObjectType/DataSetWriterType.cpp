/*
    VariableTypeClass: DataSetWriterType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/DataSetWriterType.h"

namespace OpcUaStackServer
{
    
    DataSetWriterType::DataSetWriterType(void)
    : ObjectBase()
    , dataSetFieldContentMask_Variable_(boost::make_shared<ServerVariable>("DataSetFieldContentMask_Variable"))
    , dataSetWriterId_Variable_(boost::make_shared<ServerVariable>("DataSetWriterId_Variable"))
    , dataSetWriterProperties_Variable_(boost::make_shared<ServerVariable>("DataSetWriterProperties_Variable"))
    , diagnostics_Counters_FailedDataSetMessages_Active_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_FailedDataSetMessages_Active_Variable"))
    , diagnostics_Counters_FailedDataSetMessages_Classification_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_FailedDataSetMessages_Classification_Variable"))
    , diagnostics_Counters_FailedDataSetMessages_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_FailedDataSetMessages_DiagnosticsLevel_Variable"))
    , diagnostics_Counters_FailedDataSetMessages_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_FailedDataSetMessages_TimeFirstChange_Variable"))
    , diagnostics_Counters_FailedDataSetMessages_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_FailedDataSetMessages_Variable"))
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
    , keyFrameCount_Variable_(boost::make_shared<ServerVariable>("KeyFrameCount_Variable"))
    , status_State_Variable_(boost::make_shared<ServerVariable>("Status_State_Variable"))
    , diagnostics_Reset_Method_(boost::make_shared<ServerMethod>("Diagnostics_Reset_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)15298);
        setServerVariable(dataSetFieldContentMask_Variable_);
        setServerVariable(dataSetWriterId_Variable_);
        setServerVariable(dataSetWriterProperties_Variable_);
        setServerVariable(diagnostics_Counters_FailedDataSetMessages_Active_Variable_);
        setServerVariable(diagnostics_Counters_FailedDataSetMessages_Classification_Variable_);
        setServerVariable(diagnostics_Counters_FailedDataSetMessages_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_Counters_FailedDataSetMessages_TimeFirstChange_Variable_);
        setServerVariable(diagnostics_Counters_FailedDataSetMessages_Variable_);
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
        setServerVariable(keyFrameCount_Variable_);
        setServerVariable(status_State_Variable_);
        setServerMethod(diagnostics_Reset_Method_);
        diagnostics_Reset_Method_->registerMethod(boost::bind(&DataSetWriterType::call_Diagnostics_Reset_Method, this, _1));
    }
    
    DataSetWriterType::DataSetWriterType(const DataSetWriterType& value)
    : ObjectBase()
    , dataSetFieldContentMask_Variable_(boost::make_shared<ServerVariable>("DataSetFieldContentMask_Variable"))
    , dataSetWriterId_Variable_(boost::make_shared<ServerVariable>("DataSetWriterId_Variable"))
    , dataSetWriterProperties_Variable_(boost::make_shared<ServerVariable>("DataSetWriterProperties_Variable"))
    , diagnostics_Counters_FailedDataSetMessages_Active_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_FailedDataSetMessages_Active_Variable"))
    , diagnostics_Counters_FailedDataSetMessages_Classification_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_FailedDataSetMessages_Classification_Variable"))
    , diagnostics_Counters_FailedDataSetMessages_DiagnosticsLevel_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_FailedDataSetMessages_DiagnosticsLevel_Variable"))
    , diagnostics_Counters_FailedDataSetMessages_TimeFirstChange_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_FailedDataSetMessages_TimeFirstChange_Variable"))
    , diagnostics_Counters_FailedDataSetMessages_Variable_(boost::make_shared<ServerVariable>("Diagnostics_Counters_FailedDataSetMessages_Variable"))
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
    , keyFrameCount_Variable_(boost::make_shared<ServerVariable>("KeyFrameCount_Variable"))
    , status_State_Variable_(boost::make_shared<ServerVariable>("Status_State_Variable"))
    , diagnostics_Reset_Method_(boost::make_shared<ServerMethod>("Diagnostics_Reset_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)15298);
        setServerVariable(dataSetFieldContentMask_Variable_);
        setServerVariable(dataSetWriterId_Variable_);
        setServerVariable(dataSetWriterProperties_Variable_);
        setServerVariable(diagnostics_Counters_FailedDataSetMessages_Active_Variable_);
        setServerVariable(diagnostics_Counters_FailedDataSetMessages_Classification_Variable_);
        setServerVariable(diagnostics_Counters_FailedDataSetMessages_DiagnosticsLevel_Variable_);
        setServerVariable(diagnostics_Counters_FailedDataSetMessages_TimeFirstChange_Variable_);
        setServerVariable(diagnostics_Counters_FailedDataSetMessages_Variable_);
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
        setServerVariable(keyFrameCount_Variable_);
        setServerVariable(status_State_Variable_);
        setServerMethod(diagnostics_Reset_Method_);
        diagnostics_Reset_Method_->registerMethod(boost::bind(&DataSetWriterType::call_Diagnostics_Reset_Method, this, _1));
    }
    
    DataSetWriterType::~DataSetWriterType(void)
    {
    }

    ServerVariable::SPtr&
    DataSetWriterType::dataSetFieldContentMask_Variable(void)
    {
        return dataSetFieldContentMask_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::dataSetWriterId_Variable(void)
    {
        return dataSetWriterId_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::dataSetWriterProperties_Variable(void)
    {
        return dataSetWriterProperties_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_Counters_FailedDataSetMessages_Active_Variable(void)
    {
        return diagnostics_Counters_FailedDataSetMessages_Active_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_Counters_FailedDataSetMessages_Classification_Variable(void)
    {
        return diagnostics_Counters_FailedDataSetMessages_Classification_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_Counters_FailedDataSetMessages_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_FailedDataSetMessages_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_Counters_FailedDataSetMessages_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_FailedDataSetMessages_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_Counters_FailedDataSetMessages_Variable(void)
    {
        return diagnostics_Counters_FailedDataSetMessages_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_Counters_StateDisabledByMethod_Active_Variable(void)
    {
        return diagnostics_Counters_StateDisabledByMethod_Active_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_Counters_StateDisabledByMethod_Classification_Variable(void)
    {
        return diagnostics_Counters_StateDisabledByMethod_Classification_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_Counters_StateDisabledByMethod_Variable(void)
    {
        return diagnostics_Counters_StateDisabledByMethod_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_Counters_StateError_Active_Variable(void)
    {
        return diagnostics_Counters_StateError_Active_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_Counters_StateError_Classification_Variable(void)
    {
        return diagnostics_Counters_StateError_Classification_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_Counters_StateError_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_StateError_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_Counters_StateError_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_StateError_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_Counters_StateError_Variable(void)
    {
        return diagnostics_Counters_StateError_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_Counters_StateOperationalByMethod_Active_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByMethod_Active_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_Counters_StateOperationalByMethod_Classification_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByMethod_Classification_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_Counters_StateOperationalByMethod_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByMethod_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_Counters_StateOperationalByParent_Active_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByParent_Active_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_Counters_StateOperationalByParent_Classification_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByParent_Classification_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_Counters_StateOperationalByParent_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByParent_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_Counters_StateOperationalFromError_Active_Variable(void)
    {
        return diagnostics_Counters_StateOperationalFromError_Active_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_Counters_StateOperationalFromError_Classification_Variable(void)
    {
        return diagnostics_Counters_StateOperationalFromError_Classification_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_Counters_StateOperationalFromError_Variable(void)
    {
        return diagnostics_Counters_StateOperationalFromError_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_Counters_StatePausedByParent_Active_Variable(void)
    {
        return diagnostics_Counters_StatePausedByParent_Active_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_Counters_StatePausedByParent_Classification_Variable(void)
    {
        return diagnostics_Counters_StatePausedByParent_Classification_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_Counters_StatePausedByParent_Variable(void)
    {
        return diagnostics_Counters_StatePausedByParent_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_SubError_Variable(void)
    {
        return diagnostics_SubError_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_TotalError_Active_Variable(void)
    {
        return diagnostics_TotalError_Active_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_TotalError_Classification_Variable(void)
    {
        return diagnostics_TotalError_Classification_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_TotalError_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_TotalError_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_TotalError_TimeFirstChange_Variable(void)
    {
        return diagnostics_TotalError_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_TotalError_Variable(void)
    {
        return diagnostics_TotalError_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_TotalInformation_Active_Variable(void)
    {
        return diagnostics_TotalInformation_Active_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_TotalInformation_Classification_Variable(void)
    {
        return diagnostics_TotalInformation_Classification_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_TotalInformation_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_TotalInformation_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_TotalInformation_TimeFirstChange_Variable(void)
    {
        return diagnostics_TotalInformation_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::diagnostics_TotalInformation_Variable(void)
    {
        return diagnostics_TotalInformation_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::keyFrameCount_Variable(void)
    {
        return keyFrameCount_Variable_;
    }

    ServerVariable::SPtr&
    DataSetWriterType::status_State_Variable(void)
    {
        return status_State_Variable_;
    }

    void
    DataSetWriterType::dataSetFieldContentMask_Variable(ServerVariable::SPtr& serverVariable)
    {
        dataSetFieldContentMask_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::dataSetWriterId_Variable(ServerVariable::SPtr& serverVariable)
    {
        dataSetWriterId_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::dataSetWriterProperties_Variable(ServerVariable::SPtr& serverVariable)
    {
        dataSetWriterProperties_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_Counters_FailedDataSetMessages_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_FailedDataSetMessages_Active_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_Counters_FailedDataSetMessages_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_FailedDataSetMessages_Classification_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_Counters_FailedDataSetMessages_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_FailedDataSetMessages_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_Counters_FailedDataSetMessages_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_FailedDataSetMessages_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_Counters_FailedDataSetMessages_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_FailedDataSetMessages_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_Counters_StateDisabledByMethod_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateDisabledByMethod_Active_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_Counters_StateDisabledByMethod_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateDisabledByMethod_Classification_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_Counters_StateDisabledByMethod_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateDisabledByMethod_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_Counters_StateError_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateError_Active_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_Counters_StateError_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateError_Classification_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_Counters_StateError_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateError_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_Counters_StateError_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateError_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_Counters_StateError_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateError_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_Counters_StateOperationalByMethod_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByMethod_Active_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_Counters_StateOperationalByMethod_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByMethod_Classification_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_Counters_StateOperationalByMethod_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByMethod_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_Counters_StateOperationalByParent_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByParent_Active_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_Counters_StateOperationalByParent_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByParent_Classification_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_Counters_StateOperationalByParent_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByParent_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_Counters_StateOperationalFromError_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalFromError_Active_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_Counters_StateOperationalFromError_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalFromError_Classification_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_Counters_StateOperationalFromError_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalFromError_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_Counters_StatePausedByParent_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StatePausedByParent_Active_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_Counters_StatePausedByParent_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StatePausedByParent_Classification_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_Counters_StatePausedByParent_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StatePausedByParent_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_SubError_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_SubError_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_TotalError_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalError_Active_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_TotalError_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalError_Classification_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_TotalError_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalError_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_TotalError_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalError_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_TotalError_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalError_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_TotalInformation_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalInformation_Active_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_TotalInformation_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalInformation_Classification_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_TotalInformation_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalInformation_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_TotalInformation_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalInformation_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::diagnostics_TotalInformation_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalInformation_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::keyFrameCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        keyFrameCount_Variable_ = serverVariable;
    }

    void
    DataSetWriterType::status_State_Variable(ServerVariable::SPtr& serverVariable)
    {
        status_State_Variable_ = serverVariable;
    }

    bool
    DataSetWriterType::get_DataSetFieldContentMask_Variable(OpcUaDataValue& dataValue)
    {
        return dataSetFieldContentMask_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_DataSetWriterId_Variable(OpcUaDataValue& dataValue)
    {
        return dataSetWriterId_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_DataSetWriterProperties_Variable(OpcUaDataValue& dataValue)
    {
        return dataSetWriterProperties_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_Counters_FailedDataSetMessages_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_FailedDataSetMessages_Active_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_Counters_FailedDataSetMessages_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_FailedDataSetMessages_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_Counters_FailedDataSetMessages_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_FailedDataSetMessages_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_Counters_FailedDataSetMessages_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_FailedDataSetMessages_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_Counters_FailedDataSetMessages_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_FailedDataSetMessages_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_Counters_StateDisabledByMethod_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_Active_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_Counters_StateDisabledByMethod_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_Counters_StateDisabledByMethod_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_Counters_StateError_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_Active_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_Counters_StateError_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_Counters_StateError_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_Counters_StateError_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_Counters_StateError_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_Counters_StateOperationalByMethod_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_Active_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_Counters_StateOperationalByMethod_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_Counters_StateOperationalByMethod_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_Counters_StateOperationalByParent_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_Active_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_Counters_StateOperationalByParent_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_Counters_StateOperationalByParent_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_Counters_StateOperationalFromError_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_Active_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_Counters_StateOperationalFromError_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_Counters_StateOperationalFromError_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_Counters_StatePausedByParent_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_Active_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_Counters_StatePausedByParent_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_Counters_StatePausedByParent_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_SubError_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_SubError_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_TotalError_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_Active_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_TotalError_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_TotalError_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_TotalError_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_TotalError_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_TotalInformation_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_Active_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_TotalInformation_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_TotalInformation_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_TotalInformation_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Diagnostics_TotalInformation_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_KeyFrameCount_Variable(OpcUaDataValue& dataValue)
    {
        return keyFrameCount_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::get_Status_State_Variable(OpcUaDataValue& dataValue)
    {
        return status_State_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_DataSetFieldContentMask_Variable(const OpcUaDataValue& dataValue)
    {
        return dataSetFieldContentMask_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_DataSetWriterId_Variable(const OpcUaDataValue& dataValue)
    {
        return dataSetWriterId_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_DataSetWriterProperties_Variable(const OpcUaDataValue& dataValue)
    {
        return dataSetWriterProperties_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_Counters_FailedDataSetMessages_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_FailedDataSetMessages_Active_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_Counters_FailedDataSetMessages_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_FailedDataSetMessages_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_Counters_FailedDataSetMessages_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_FailedDataSetMessages_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_Counters_FailedDataSetMessages_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_FailedDataSetMessages_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_Counters_FailedDataSetMessages_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_FailedDataSetMessages_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_Counters_StateDisabledByMethod_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_Active_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_Counters_StateDisabledByMethod_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_Counters_StateDisabledByMethod_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_Counters_StateError_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_Active_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_Counters_StateError_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_Counters_StateError_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_Counters_StateError_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_Counters_StateError_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_Counters_StateOperationalByMethod_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_Active_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_Counters_StateOperationalByMethod_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_Counters_StateOperationalByMethod_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_Counters_StateOperationalByParent_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_Active_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_Counters_StateOperationalByParent_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_Counters_StateOperationalByParent_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_Counters_StateOperationalFromError_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_Active_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_Counters_StateOperationalFromError_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_Counters_StateOperationalFromError_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_Counters_StatePausedByParent_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_Active_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_Counters_StatePausedByParent_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_Counters_StatePausedByParent_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_SubError_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_SubError_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_TotalError_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_Active_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_TotalError_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_TotalError_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_TotalError_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_TotalError_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_TotalInformation_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_Active_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_TotalInformation_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_TotalInformation_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_TotalInformation_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Diagnostics_TotalInformation_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_KeyFrameCount_Variable(const OpcUaDataValue& dataValue)
    {
        return keyFrameCount_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetWriterType::set_Status_State_Variable(const OpcUaDataValue& dataValue)
    {
        return status_State_Variable_->setDataValue(dataValue);
    }

    void
    DataSetWriterType::call_Diagnostics_Reset_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

}
