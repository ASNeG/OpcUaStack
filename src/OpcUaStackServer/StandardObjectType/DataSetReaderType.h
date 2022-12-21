/*
    ObjectTypeClass: DataSetReaderType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_DataSetReaderType_h__
#define __OpcUaStackServer_DataSetReaderType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT DataSetReaderType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<DataSetReaderType> SPtr;
       typedef std::vector<DataSetReaderType::SPtr> Vec;
   
       DataSetReaderType(void);
       DataSetReaderType(const DataSetReaderType& value);
       virtual ~DataSetReaderType(void);

        //
        // DataSetFieldContentMask
        //
        void dataSetFieldContentMask_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& dataSetFieldContentMask_Variable(void);
        bool get_DataSetFieldContentMask_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_DataSetFieldContentMask_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DataSetMetaDataType
        //
        void dataSetMetaData_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& dataSetMetaData_Variable(void);
        bool get_DataSetMetaData_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_DataSetMetaData_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // KeyValuePair (Array)
        //
        void dataSetReaderProperties_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& dataSetReaderProperties_Variable(void);
        bool get_DataSetReaderProperties_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_DataSetReaderProperties_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt16
        //
        void dataSetWriterId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& dataSetWriterId_Variable(void);
        bool get_DataSetWriterId_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_DataSetWriterId_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void diagnostics_Counters_FailedDataSetMessages_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_FailedDataSetMessages_Active_Variable(void);
        bool get_Diagnostics_Counters_FailedDataSetMessages_Active_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_FailedDataSetMessages_Active_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void diagnostics_Counters_FailedDataSetMessages_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_FailedDataSetMessages_Classification_Variable(void);
        bool get_Diagnostics_Counters_FailedDataSetMessages_Classification_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_FailedDataSetMessages_Classification_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void diagnostics_Counters_FailedDataSetMessages_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_FailedDataSetMessages_DiagnosticsLevel_Variable(void);
        bool get_Diagnostics_Counters_FailedDataSetMessages_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_FailedDataSetMessages_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void diagnostics_Counters_FailedDataSetMessages_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_FailedDataSetMessages_TimeFirstChange_Variable(void);
        bool get_Diagnostics_Counters_FailedDataSetMessages_TimeFirstChange_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_FailedDataSetMessages_TimeFirstChange_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void diagnostics_Counters_FailedDataSetMessages_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_FailedDataSetMessages_Variable(void);
        bool get_Diagnostics_Counters_FailedDataSetMessages_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_FailedDataSetMessages_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

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
        // UInt16
        //
        void messageReceiveTimeout_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& messageReceiveTimeout_Variable(void);
        bool get_MessageReceiveTimeout_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_MessageReceiveTimeout_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Variant
        //
        void publisherId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& publisherId_Variable(void);
        bool get_PublisherId_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_PublisherId_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

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
        // DataSetMetaDataType
        //
        void subscribedDataSet_DataSetMetaData_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subscribedDataSet_DataSetMetaData_Variable(void);
        bool get_SubscribedDataSet_DataSetMetaData_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SubscribedDataSet_DataSetMetaData_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Duration
        //
        void subscribedDataSet_MessageReceiveTimeout_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subscribedDataSet_MessageReceiveTimeout_Variable(void);
        bool get_SubscribedDataSet_MessageReceiveTimeout_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SubscribedDataSet_MessageReceiveTimeout_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt16
        //
        void writerGroupId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& writerGroupId_Variable(void);
        bool get_WriterGroupId_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_WriterGroupId_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        virtual void call_CreateDataSetMirror_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_CreateTargetVariables_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_Diagnostics_Reset_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);
    
      private:
        ServerVariable::SPtr dataSetFieldContentMask_Variable_;
        ServerVariable::SPtr dataSetMetaData_Variable_;
        ServerVariable::SPtr dataSetReaderProperties_Variable_;
        ServerVariable::SPtr dataSetWriterId_Variable_;
        ServerVariable::SPtr diagnostics_Counters_FailedDataSetMessages_Active_Variable_;
        ServerVariable::SPtr diagnostics_Counters_FailedDataSetMessages_Classification_Variable_;
        ServerVariable::SPtr diagnostics_Counters_FailedDataSetMessages_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr diagnostics_Counters_FailedDataSetMessages_TimeFirstChange_Variable_;
        ServerVariable::SPtr diagnostics_Counters_FailedDataSetMessages_Variable_;
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
        ServerVariable::SPtr messageReceiveTimeout_Variable_;
        ServerVariable::SPtr publisherId_Variable_;
        ServerVariable::SPtr securityGroupId_Variable_;
        ServerVariable::SPtr securityKeyServices_Variable_;
        ServerVariable::SPtr securityMode_Variable_;
        ServerVariable::SPtr status_State_Variable_;
        ServerVariable::SPtr subscribedDataSet_DataSetMetaData_Variable_;
        ServerVariable::SPtr subscribedDataSet_MessageReceiveTimeout_Variable_;
        ServerVariable::SPtr writerGroupId_Variable_;
        ServerMethod::SPtr createDataSetMirror_Method_;
        ServerMethod::SPtr createTargetVariables_Method_;
        ServerMethod::SPtr diagnostics_Reset_Method_;
   
   };

}

#endif
