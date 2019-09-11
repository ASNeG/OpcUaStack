/*
    VariableTypeClass: DataSetReaderType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/DataSetReaderType.h"

namespace OpcUaStackServer
{
    
    DataSetReaderType::DataSetReaderType(void)
    : ObjectBase()
    , dataSetFieldContentMask_Variable_(boost::make_shared<ServerVariable>("DataSetFieldContentMask_Variable"))
    , dataSetMetaData_Variable_(boost::make_shared<ServerVariable>("DataSetMetaData_Variable"))
    , dataSetReaderProperties_Variable_(boost::make_shared<ServerVariable>("DataSetReaderProperties_Variable"))
    , dataSetWriterId_Variable_(boost::make_shared<ServerVariable>("DataSetWriterId_Variable"))
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
    , messageReceiveTimeout_Variable_(boost::make_shared<ServerVariable>("MessageReceiveTimeout_Variable"))
    , publisherId_Variable_(boost::make_shared<ServerVariable>("PublisherId_Variable"))
    , securityGroupId_Variable_(boost::make_shared<ServerVariable>("SecurityGroupId_Variable"))
    , securityKeyServices_Variable_(boost::make_shared<ServerVariable>("SecurityKeyServices_Variable"))
    , securityMode_Variable_(boost::make_shared<ServerVariable>("SecurityMode_Variable"))
    , status_State_Variable_(boost::make_shared<ServerVariable>("Status_State_Variable"))
    , subscribedDataSet_DataSetMetaData_Variable_(boost::make_shared<ServerVariable>("SubscribedDataSet_DataSetMetaData_Variable"))
    , subscribedDataSet_MessageReceiveTimeout_Variable_(boost::make_shared<ServerVariable>("SubscribedDataSet_MessageReceiveTimeout_Variable"))
    , writerGroupId_Variable_(boost::make_shared<ServerVariable>("WriterGroupId_Variable"))
    , createDataSetMirror_Method_(boost::make_shared<ServerMethod>("CreateDataSetMirror_Method"))
    , createTargetVariables_Method_(boost::make_shared<ServerMethod>("CreateTargetVariables_Method"))
    , diagnostics_Reset_Method_(boost::make_shared<ServerMethod>("Diagnostics_Reset_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)15306);
        setServerVariable(dataSetFieldContentMask_Variable_);
        setServerVariable(dataSetMetaData_Variable_);
        setServerVariable(dataSetReaderProperties_Variable_);
        setServerVariable(dataSetWriterId_Variable_);
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
        setServerVariable(messageReceiveTimeout_Variable_);
        setServerVariable(publisherId_Variable_);
        setServerVariable(securityGroupId_Variable_);
        setServerVariable(securityKeyServices_Variable_);
        setServerVariable(securityMode_Variable_);
        setServerVariable(status_State_Variable_);
        setServerVariable(subscribedDataSet_DataSetMetaData_Variable_);
        setServerVariable(subscribedDataSet_MessageReceiveTimeout_Variable_);
        setServerVariable(writerGroupId_Variable_);
        setServerMethod(createDataSetMirror_Method_);
        setServerMethod(createTargetVariables_Method_);
        setServerMethod(diagnostics_Reset_Method_);
        createDataSetMirror_Method_->registerMethod(boost::bind(&DataSetReaderType::call_CreateDataSetMirror_Method, this, _1));
        createTargetVariables_Method_->registerMethod(boost::bind(&DataSetReaderType::call_CreateTargetVariables_Method, this, _1));
        diagnostics_Reset_Method_->registerMethod(boost::bind(&DataSetReaderType::call_Diagnostics_Reset_Method, this, _1));
    }
    
    DataSetReaderType::DataSetReaderType(const DataSetReaderType& value)
    : ObjectBase()
    , dataSetFieldContentMask_Variable_(boost::make_shared<ServerVariable>("DataSetFieldContentMask_Variable"))
    , dataSetMetaData_Variable_(boost::make_shared<ServerVariable>("DataSetMetaData_Variable"))
    , dataSetReaderProperties_Variable_(boost::make_shared<ServerVariable>("DataSetReaderProperties_Variable"))
    , dataSetWriterId_Variable_(boost::make_shared<ServerVariable>("DataSetWriterId_Variable"))
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
    , messageReceiveTimeout_Variable_(boost::make_shared<ServerVariable>("MessageReceiveTimeout_Variable"))
    , publisherId_Variable_(boost::make_shared<ServerVariable>("PublisherId_Variable"))
    , securityGroupId_Variable_(boost::make_shared<ServerVariable>("SecurityGroupId_Variable"))
    , securityKeyServices_Variable_(boost::make_shared<ServerVariable>("SecurityKeyServices_Variable"))
    , securityMode_Variable_(boost::make_shared<ServerVariable>("SecurityMode_Variable"))
    , status_State_Variable_(boost::make_shared<ServerVariable>("Status_State_Variable"))
    , subscribedDataSet_DataSetMetaData_Variable_(boost::make_shared<ServerVariable>("SubscribedDataSet_DataSetMetaData_Variable"))
    , subscribedDataSet_MessageReceiveTimeout_Variable_(boost::make_shared<ServerVariable>("SubscribedDataSet_MessageReceiveTimeout_Variable"))
    , writerGroupId_Variable_(boost::make_shared<ServerVariable>("WriterGroupId_Variable"))
    , createDataSetMirror_Method_(boost::make_shared<ServerMethod>("CreateDataSetMirror_Method"))
    , createTargetVariables_Method_(boost::make_shared<ServerMethod>("CreateTargetVariables_Method"))
    , diagnostics_Reset_Method_(boost::make_shared<ServerMethod>("Diagnostics_Reset_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)15306);
        setServerVariable(dataSetFieldContentMask_Variable_);
        setServerVariable(dataSetMetaData_Variable_);
        setServerVariable(dataSetReaderProperties_Variable_);
        setServerVariable(dataSetWriterId_Variable_);
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
        setServerVariable(messageReceiveTimeout_Variable_);
        setServerVariable(publisherId_Variable_);
        setServerVariable(securityGroupId_Variable_);
        setServerVariable(securityKeyServices_Variable_);
        setServerVariable(securityMode_Variable_);
        setServerVariable(status_State_Variable_);
        setServerVariable(subscribedDataSet_DataSetMetaData_Variable_);
        setServerVariable(subscribedDataSet_MessageReceiveTimeout_Variable_);
        setServerVariable(writerGroupId_Variable_);
        setServerMethod(createDataSetMirror_Method_);
        setServerMethod(createTargetVariables_Method_);
        setServerMethod(diagnostics_Reset_Method_);
        createDataSetMirror_Method_->registerMethod(boost::bind(&DataSetReaderType::call_CreateDataSetMirror_Method, this, _1));
        createTargetVariables_Method_->registerMethod(boost::bind(&DataSetReaderType::call_CreateTargetVariables_Method, this, _1));
        diagnostics_Reset_Method_->registerMethod(boost::bind(&DataSetReaderType::call_Diagnostics_Reset_Method, this, _1));
    }
    
    DataSetReaderType::~DataSetReaderType(void)
    {
    }

    ServerVariable::SPtr&
    DataSetReaderType::dataSetFieldContentMask_Variable(void)
    {
        return dataSetFieldContentMask_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::dataSetMetaData_Variable(void)
    {
        return dataSetMetaData_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::dataSetReaderProperties_Variable(void)
    {
        return dataSetReaderProperties_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::dataSetWriterId_Variable(void)
    {
        return dataSetWriterId_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_Counters_FailedDataSetMessages_Active_Variable(void)
    {
        return diagnostics_Counters_FailedDataSetMessages_Active_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_Counters_FailedDataSetMessages_Classification_Variable(void)
    {
        return diagnostics_Counters_FailedDataSetMessages_Classification_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_Counters_FailedDataSetMessages_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_FailedDataSetMessages_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_Counters_FailedDataSetMessages_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_FailedDataSetMessages_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_Counters_FailedDataSetMessages_Variable(void)
    {
        return diagnostics_Counters_FailedDataSetMessages_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_Counters_StateDisabledByMethod_Active_Variable(void)
    {
        return diagnostics_Counters_StateDisabledByMethod_Active_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_Counters_StateDisabledByMethod_Classification_Variable(void)
    {
        return diagnostics_Counters_StateDisabledByMethod_Classification_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_Counters_StateDisabledByMethod_Variable(void)
    {
        return diagnostics_Counters_StateDisabledByMethod_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_Counters_StateError_Active_Variable(void)
    {
        return diagnostics_Counters_StateError_Active_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_Counters_StateError_Classification_Variable(void)
    {
        return diagnostics_Counters_StateError_Classification_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_Counters_StateError_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_StateError_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_Counters_StateError_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_StateError_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_Counters_StateError_Variable(void)
    {
        return diagnostics_Counters_StateError_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_Counters_StateOperationalByMethod_Active_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByMethod_Active_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_Counters_StateOperationalByMethod_Classification_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByMethod_Classification_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_Counters_StateOperationalByMethod_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByMethod_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_Counters_StateOperationalByParent_Active_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByParent_Active_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_Counters_StateOperationalByParent_Classification_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByParent_Classification_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_Counters_StateOperationalByParent_Variable(void)
    {
        return diagnostics_Counters_StateOperationalByParent_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_Counters_StateOperationalFromError_Active_Variable(void)
    {
        return diagnostics_Counters_StateOperationalFromError_Active_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_Counters_StateOperationalFromError_Classification_Variable(void)
    {
        return diagnostics_Counters_StateOperationalFromError_Classification_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_Counters_StateOperationalFromError_Variable(void)
    {
        return diagnostics_Counters_StateOperationalFromError_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_Counters_StatePausedByParent_Active_Variable(void)
    {
        return diagnostics_Counters_StatePausedByParent_Active_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_Counters_StatePausedByParent_Classification_Variable(void)
    {
        return diagnostics_Counters_StatePausedByParent_Classification_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable(void)
    {
        return diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_Counters_StatePausedByParent_Variable(void)
    {
        return diagnostics_Counters_StatePausedByParent_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_SubError_Variable(void)
    {
        return diagnostics_SubError_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_TotalError_Active_Variable(void)
    {
        return diagnostics_TotalError_Active_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_TotalError_Classification_Variable(void)
    {
        return diagnostics_TotalError_Classification_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_TotalError_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_TotalError_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_TotalError_TimeFirstChange_Variable(void)
    {
        return diagnostics_TotalError_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_TotalError_Variable(void)
    {
        return diagnostics_TotalError_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_TotalInformation_Active_Variable(void)
    {
        return diagnostics_TotalInformation_Active_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_TotalInformation_Classification_Variable(void)
    {
        return diagnostics_TotalInformation_Classification_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_TotalInformation_DiagnosticsLevel_Variable(void)
    {
        return diagnostics_TotalInformation_DiagnosticsLevel_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_TotalInformation_TimeFirstChange_Variable(void)
    {
        return diagnostics_TotalInformation_TimeFirstChange_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::diagnostics_TotalInformation_Variable(void)
    {
        return diagnostics_TotalInformation_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::messageReceiveTimeout_Variable(void)
    {
        return messageReceiveTimeout_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::publisherId_Variable(void)
    {
        return publisherId_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::securityGroupId_Variable(void)
    {
        return securityGroupId_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::securityKeyServices_Variable(void)
    {
        return securityKeyServices_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::securityMode_Variable(void)
    {
        return securityMode_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::status_State_Variable(void)
    {
        return status_State_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::subscribedDataSet_DataSetMetaData_Variable(void)
    {
        return subscribedDataSet_DataSetMetaData_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::subscribedDataSet_MessageReceiveTimeout_Variable(void)
    {
        return subscribedDataSet_MessageReceiveTimeout_Variable_;
    }

    ServerVariable::SPtr&
    DataSetReaderType::writerGroupId_Variable(void)
    {
        return writerGroupId_Variable_;
    }

    void
    DataSetReaderType::dataSetFieldContentMask_Variable(ServerVariable::SPtr& serverVariable)
    {
        dataSetFieldContentMask_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::dataSetMetaData_Variable(ServerVariable::SPtr& serverVariable)
    {
        dataSetMetaData_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::dataSetReaderProperties_Variable(ServerVariable::SPtr& serverVariable)
    {
        dataSetReaderProperties_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::dataSetWriterId_Variable(ServerVariable::SPtr& serverVariable)
    {
        dataSetWriterId_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_Counters_FailedDataSetMessages_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_FailedDataSetMessages_Active_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_Counters_FailedDataSetMessages_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_FailedDataSetMessages_Classification_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_Counters_FailedDataSetMessages_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_FailedDataSetMessages_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_Counters_FailedDataSetMessages_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_FailedDataSetMessages_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_Counters_FailedDataSetMessages_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_FailedDataSetMessages_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_Counters_StateDisabledByMethod_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateDisabledByMethod_Active_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_Counters_StateDisabledByMethod_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateDisabledByMethod_Classification_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_Counters_StateDisabledByMethod_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateDisabledByMethod_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_Counters_StateError_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateError_Active_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_Counters_StateError_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateError_Classification_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_Counters_StateError_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateError_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_Counters_StateError_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateError_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_Counters_StateError_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateError_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_Counters_StateOperationalByMethod_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByMethod_Active_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_Counters_StateOperationalByMethod_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByMethod_Classification_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_Counters_StateOperationalByMethod_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByMethod_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_Counters_StateOperationalByParent_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByParent_Active_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_Counters_StateOperationalByParent_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByParent_Classification_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_Counters_StateOperationalByParent_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalByParent_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_Counters_StateOperationalFromError_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalFromError_Active_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_Counters_StateOperationalFromError_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalFromError_Classification_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_Counters_StateOperationalFromError_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StateOperationalFromError_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_Counters_StatePausedByParent_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StatePausedByParent_Active_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_Counters_StatePausedByParent_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StatePausedByParent_Classification_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_Counters_StatePausedByParent_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_Counters_StatePausedByParent_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_SubError_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_SubError_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_TotalError_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalError_Active_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_TotalError_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalError_Classification_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_TotalError_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalError_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_TotalError_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalError_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_TotalError_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalError_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_TotalInformation_Active_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalInformation_Active_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_TotalInformation_Classification_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalInformation_Classification_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_TotalInformation_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalInformation_DiagnosticsLevel_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_TotalInformation_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalInformation_TimeFirstChange_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::diagnostics_TotalInformation_Variable(ServerVariable::SPtr& serverVariable)
    {
        diagnostics_TotalInformation_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::messageReceiveTimeout_Variable(ServerVariable::SPtr& serverVariable)
    {
        messageReceiveTimeout_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::publisherId_Variable(ServerVariable::SPtr& serverVariable)
    {
        publisherId_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::securityGroupId_Variable(ServerVariable::SPtr& serverVariable)
    {
        securityGroupId_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::securityKeyServices_Variable(ServerVariable::SPtr& serverVariable)
    {
        securityKeyServices_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::securityMode_Variable(ServerVariable::SPtr& serverVariable)
    {
        securityMode_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::status_State_Variable(ServerVariable::SPtr& serverVariable)
    {
        status_State_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::subscribedDataSet_DataSetMetaData_Variable(ServerVariable::SPtr& serverVariable)
    {
        subscribedDataSet_DataSetMetaData_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::subscribedDataSet_MessageReceiveTimeout_Variable(ServerVariable::SPtr& serverVariable)
    {
        subscribedDataSet_MessageReceiveTimeout_Variable_ = serverVariable;
    }

    void
    DataSetReaderType::writerGroupId_Variable(ServerVariable::SPtr& serverVariable)
    {
        writerGroupId_Variable_ = serverVariable;
    }

    bool
    DataSetReaderType::get_DataSetFieldContentMask_Variable(OpcUaDataValue& dataValue)
    {
        return dataSetFieldContentMask_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_DataSetMetaData_Variable(OpcUaDataValue& dataValue)
    {
        return dataSetMetaData_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_DataSetReaderProperties_Variable(OpcUaDataValue& dataValue)
    {
        return dataSetReaderProperties_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_DataSetWriterId_Variable(OpcUaDataValue& dataValue)
    {
        return dataSetWriterId_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_Counters_FailedDataSetMessages_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_FailedDataSetMessages_Active_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_Counters_FailedDataSetMessages_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_FailedDataSetMessages_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_Counters_FailedDataSetMessages_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_FailedDataSetMessages_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_Counters_FailedDataSetMessages_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_FailedDataSetMessages_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_Counters_FailedDataSetMessages_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_FailedDataSetMessages_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_Counters_StateDisabledByMethod_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_Active_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_Counters_StateDisabledByMethod_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_Counters_StateDisabledByMethod_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_Counters_StateError_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_Active_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_Counters_StateError_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_Counters_StateError_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_Counters_StateError_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_Counters_StateError_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_Counters_StateOperationalByMethod_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_Active_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_Counters_StateOperationalByMethod_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_Counters_StateOperationalByMethod_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_Counters_StateOperationalByParent_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_Active_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_Counters_StateOperationalByParent_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_Counters_StateOperationalByParent_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_Counters_StateOperationalFromError_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_Active_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_Counters_StateOperationalFromError_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_Counters_StateOperationalFromError_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_Counters_StatePausedByParent_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_Active_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_Counters_StatePausedByParent_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_Counters_StatePausedByParent_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_SubError_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_SubError_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_TotalError_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_Active_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_TotalError_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_TotalError_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_TotalError_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_TotalError_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_TotalInformation_Active_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_Active_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_TotalInformation_Classification_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_Classification_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_TotalInformation_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_DiagnosticsLevel_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_TotalInformation_TimeFirstChange_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_TimeFirstChange_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Diagnostics_TotalInformation_Variable(OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_MessageReceiveTimeout_Variable(OpcUaDataValue& dataValue)
    {
        return messageReceiveTimeout_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_PublisherId_Variable(OpcUaDataValue& dataValue)
    {
        return publisherId_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_SecurityGroupId_Variable(OpcUaDataValue& dataValue)
    {
        return securityGroupId_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_SecurityKeyServices_Variable(OpcUaDataValue& dataValue)
    {
        return securityKeyServices_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_SecurityMode_Variable(OpcUaDataValue& dataValue)
    {
        return securityMode_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_Status_State_Variable(OpcUaDataValue& dataValue)
    {
        return status_State_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_SubscribedDataSet_DataSetMetaData_Variable(OpcUaDataValue& dataValue)
    {
        return subscribedDataSet_DataSetMetaData_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_SubscribedDataSet_MessageReceiveTimeout_Variable(OpcUaDataValue& dataValue)
    {
        return subscribedDataSet_MessageReceiveTimeout_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::get_WriterGroupId_Variable(OpcUaDataValue& dataValue)
    {
        return writerGroupId_Variable_->getDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_DataSetFieldContentMask_Variable(const OpcUaDataValue& dataValue)
    {
        return dataSetFieldContentMask_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_DataSetMetaData_Variable(const OpcUaDataValue& dataValue)
    {
        return dataSetMetaData_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_DataSetReaderProperties_Variable(const OpcUaDataValue& dataValue)
    {
        return dataSetReaderProperties_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_DataSetWriterId_Variable(const OpcUaDataValue& dataValue)
    {
        return dataSetWriterId_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_Counters_FailedDataSetMessages_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_FailedDataSetMessages_Active_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_Counters_FailedDataSetMessages_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_FailedDataSetMessages_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_Counters_FailedDataSetMessages_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_FailedDataSetMessages_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_Counters_FailedDataSetMessages_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_FailedDataSetMessages_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_Counters_FailedDataSetMessages_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_FailedDataSetMessages_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_Counters_StateDisabledByMethod_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_Active_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_Counters_StateDisabledByMethod_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_Counters_StateDisabledByMethod_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateDisabledByMethod_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_Counters_StateError_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_Active_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_Counters_StateError_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_Counters_StateError_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_Counters_StateError_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_Counters_StateError_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateError_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_Counters_StateOperationalByMethod_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_Active_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_Counters_StateOperationalByMethod_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_Counters_StateOperationalByMethod_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByMethod_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_Counters_StateOperationalByParent_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_Active_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_Counters_StateOperationalByParent_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_Counters_StateOperationalByParent_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalByParent_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_Counters_StateOperationalFromError_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_Active_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_Counters_StateOperationalFromError_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_Counters_StateOperationalFromError_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StateOperationalFromError_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_Counters_StatePausedByParent_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_Active_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_Counters_StatePausedByParent_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_Counters_StatePausedByParent_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_Counters_StatePausedByParent_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_SubError_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_SubError_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_TotalError_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_Active_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_TotalError_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_TotalError_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_TotalError_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_TotalError_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalError_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_TotalInformation_Active_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_Active_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_TotalInformation_Classification_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_Classification_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_TotalInformation_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_DiagnosticsLevel_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_TotalInformation_TimeFirstChange_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_TimeFirstChange_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Diagnostics_TotalInformation_Variable(const OpcUaDataValue& dataValue)
    {
        return diagnostics_TotalInformation_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_MessageReceiveTimeout_Variable(const OpcUaDataValue& dataValue)
    {
        return messageReceiveTimeout_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_PublisherId_Variable(const OpcUaDataValue& dataValue)
    {
        return publisherId_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_SecurityGroupId_Variable(const OpcUaDataValue& dataValue)
    {
        return securityGroupId_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_SecurityKeyServices_Variable(const OpcUaDataValue& dataValue)
    {
        return securityKeyServices_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_SecurityMode_Variable(const OpcUaDataValue& dataValue)
    {
        return securityMode_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_Status_State_Variable(const OpcUaDataValue& dataValue)
    {
        return status_State_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_SubscribedDataSet_DataSetMetaData_Variable(const OpcUaDataValue& dataValue)
    {
        return subscribedDataSet_DataSetMetaData_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_SubscribedDataSet_MessageReceiveTimeout_Variable(const OpcUaDataValue& dataValue)
    {
        return subscribedDataSet_MessageReceiveTimeout_Variable_->setDataValue(dataValue);
    }

    bool
    DataSetReaderType::set_WriterGroupId_Variable(const OpcUaDataValue& dataValue)
    {
        return writerGroupId_Variable_->setDataValue(dataValue);
    }

    void
    DataSetReaderType::call_CreateDataSetMirror_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    DataSetReaderType::call_CreateTargetVariables_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    DataSetReaderType::call_Diagnostics_Reset_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

}
