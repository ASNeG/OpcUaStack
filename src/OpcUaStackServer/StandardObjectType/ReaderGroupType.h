/*
    ObjectTypeClass: ReaderGroupType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_ReaderGroupType_h__
#define __OpcUaStackServer_ReaderGroupType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT ReaderGroupType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<ReaderGroupType> SPtr;
       typedef std::vector<ReaderGroupType::SPtr> Vec;
   
       ReaderGroupType(void);
       ReaderGroupType(const ReaderGroupType& value);
       virtual ~ReaderGroupType(void);

        //
        // Boolean
        //
        void diagnostics_Counters_ReceivedNetworkMessages_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_ReceivedNetworkMessages_Active_Variable(void);
        bool get_Diagnostics_Counters_ReceivedNetworkMessages_Active_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_ReceivedNetworkMessages_Active_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void diagnostics_Counters_ReceivedNetworkMessages_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_ReceivedNetworkMessages_Classification_Variable(void);
        bool get_Diagnostics_Counters_ReceivedNetworkMessages_Classification_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_ReceivedNetworkMessages_Classification_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void diagnostics_Counters_ReceivedNetworkMessages_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_ReceivedNetworkMessages_DiagnosticsLevel_Variable(void);
        bool get_Diagnostics_Counters_ReceivedNetworkMessages_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_ReceivedNetworkMessages_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void diagnostics_Counters_ReceivedNetworkMessages_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_ReceivedNetworkMessages_TimeFirstChange_Variable(void);
        bool get_Diagnostics_Counters_ReceivedNetworkMessages_TimeFirstChange_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_ReceivedNetworkMessages_TimeFirstChange_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void diagnostics_Counters_ReceivedNetworkMessages_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_Counters_ReceivedNetworkMessages_Variable(void);
        bool get_Diagnostics_Counters_ReceivedNetworkMessages_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_Counters_ReceivedNetworkMessages_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

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
        void diagnostics_LiveValues_ConfiguredDataSetReaders_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_LiveValues_ConfiguredDataSetReaders_DiagnosticsLevel_Variable(void);
        bool get_Diagnostics_LiveValues_ConfiguredDataSetReaders_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_LiveValues_ConfiguredDataSetReaders_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt16
        //
        void diagnostics_LiveValues_ConfiguredDataSetReaders_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_LiveValues_ConfiguredDataSetReaders_Variable(void);
        bool get_Diagnostics_LiveValues_ConfiguredDataSetReaders_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_LiveValues_ConfiguredDataSetReaders_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void diagnostics_LiveValues_OperationalDataSetReaders_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_LiveValues_OperationalDataSetReaders_DiagnosticsLevel_Variable(void);
        bool get_Diagnostics_LiveValues_OperationalDataSetReaders_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_LiveValues_OperationalDataSetReaders_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt16
        //
        void diagnostics_LiveValues_OperationalDataSetReaders_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnostics_LiveValues_OperationalDataSetReaders_Variable(void);
        bool get_Diagnostics_LiveValues_OperationalDataSetReaders_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Diagnostics_LiveValues_OperationalDataSetReaders_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

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
        // UInt32
        //
        void maxNetworkMessageSize_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& maxNetworkMessageSize_Variable(void);
        bool get_MaxNetworkMessageSize_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_MaxNetworkMessageSize_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

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

        virtual void call_AddDataSetReader_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_Diagnostics_Reset_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_RemoveDataSetReader_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);
    
      private:
        ServerVariable::SPtr diagnostics_Counters_ReceivedNetworkMessages_Active_Variable_;
        ServerVariable::SPtr diagnostics_Counters_ReceivedNetworkMessages_Classification_Variable_;
        ServerVariable::SPtr diagnostics_Counters_ReceivedNetworkMessages_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr diagnostics_Counters_ReceivedNetworkMessages_TimeFirstChange_Variable_;
        ServerVariable::SPtr diagnostics_Counters_ReceivedNetworkMessages_Variable_;
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
        ServerVariable::SPtr diagnostics_LiveValues_ConfiguredDataSetReaders_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr diagnostics_LiveValues_ConfiguredDataSetReaders_Variable_;
        ServerVariable::SPtr diagnostics_LiveValues_OperationalDataSetReaders_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr diagnostics_LiveValues_OperationalDataSetReaders_Variable_;
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
        ServerVariable::SPtr maxNetworkMessageSize_Variable_;
        ServerVariable::SPtr securityGroupId_Variable_;
        ServerVariable::SPtr securityKeyServices_Variable_;
        ServerVariable::SPtr securityMode_Variable_;
        ServerVariable::SPtr status_State_Variable_;
        ServerMethod::SPtr addDataSetReader_Method_;
        ServerMethod::SPtr diagnostics_Reset_Method_;
        ServerMethod::SPtr removeDataSetReader_Method_;
   
   };

}

#endif
