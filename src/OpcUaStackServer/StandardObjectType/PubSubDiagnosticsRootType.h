/*
    ObjectTypeClass: PubSubDiagnosticsRootType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_PubSubDiagnosticsRootType_h__
#define __OpcUaStackServer_PubSubDiagnosticsRootType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT PubSubDiagnosticsRootType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<PubSubDiagnosticsRootType> SPtr;
       typedef std::vector<PubSubDiagnosticsRootType::SPtr> Vec;
   
       PubSubDiagnosticsRootType(void);
       PubSubDiagnosticsRootType(const PubSubDiagnosticsRootType& value);
       virtual ~PubSubDiagnosticsRootType(void);

        //
        // Boolean
        //
        void counters_StateDisabledByMethod_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateDisabledByMethod_Active_Variable(void);
        bool get_Counters_StateDisabledByMethod_Active_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateDisabledByMethod_Active_Variable(const OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void counters_StateDisabledByMethod_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateDisabledByMethod_Classification_Variable(void);
        bool get_Counters_StateDisabledByMethod_Classification_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateDisabledByMethod_Classification_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void counters_StateDisabledByMethod_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateDisabledByMethod_DiagnosticsLevel_Variable(void);
        bool get_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void counters_StateDisabledByMethod_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateDisabledByMethod_TimeFirstChange_Variable(void);
        bool get_Counters_StateDisabledByMethod_TimeFirstChange_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateDisabledByMethod_TimeFirstChange_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void counters_StateDisabledByMethod_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateDisabledByMethod_Variable(void);
        bool get_Counters_StateDisabledByMethod_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateDisabledByMethod_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void counters_StateError_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateError_Active_Variable(void);
        bool get_Counters_StateError_Active_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateError_Active_Variable(const OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void counters_StateError_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateError_Classification_Variable(void);
        bool get_Counters_StateError_Classification_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateError_Classification_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void counters_StateError_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateError_DiagnosticsLevel_Variable(void);
        bool get_Counters_StateError_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateError_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void counters_StateError_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateError_TimeFirstChange_Variable(void);
        bool get_Counters_StateError_TimeFirstChange_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateError_TimeFirstChange_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void counters_StateError_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateError_Variable(void);
        bool get_Counters_StateError_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateError_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void counters_StateOperationalByMethod_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalByMethod_Active_Variable(void);
        bool get_Counters_StateOperationalByMethod_Active_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalByMethod_Active_Variable(const OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void counters_StateOperationalByMethod_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalByMethod_Classification_Variable(void);
        bool get_Counters_StateOperationalByMethod_Classification_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalByMethod_Classification_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void counters_StateOperationalByMethod_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalByMethod_DiagnosticsLevel_Variable(void);
        bool get_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void counters_StateOperationalByMethod_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalByMethod_TimeFirstChange_Variable(void);
        bool get_Counters_StateOperationalByMethod_TimeFirstChange_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalByMethod_TimeFirstChange_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void counters_StateOperationalByMethod_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalByMethod_Variable(void);
        bool get_Counters_StateOperationalByMethod_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalByMethod_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void counters_StateOperationalByParent_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalByParent_Active_Variable(void);
        bool get_Counters_StateOperationalByParent_Active_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalByParent_Active_Variable(const OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void counters_StateOperationalByParent_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalByParent_Classification_Variable(void);
        bool get_Counters_StateOperationalByParent_Classification_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalByParent_Classification_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void counters_StateOperationalByParent_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalByParent_DiagnosticsLevel_Variable(void);
        bool get_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void counters_StateOperationalByParent_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalByParent_TimeFirstChange_Variable(void);
        bool get_Counters_StateOperationalByParent_TimeFirstChange_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalByParent_TimeFirstChange_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void counters_StateOperationalByParent_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalByParent_Variable(void);
        bool get_Counters_StateOperationalByParent_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalByParent_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void counters_StateOperationalFromError_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalFromError_Active_Variable(void);
        bool get_Counters_StateOperationalFromError_Active_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalFromError_Active_Variable(const OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void counters_StateOperationalFromError_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalFromError_Classification_Variable(void);
        bool get_Counters_StateOperationalFromError_Classification_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalFromError_Classification_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void counters_StateOperationalFromError_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalFromError_DiagnosticsLevel_Variable(void);
        bool get_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void counters_StateOperationalFromError_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalFromError_TimeFirstChange_Variable(void);
        bool get_Counters_StateOperationalFromError_TimeFirstChange_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalFromError_TimeFirstChange_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void counters_StateOperationalFromError_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalFromError_Variable(void);
        bool get_Counters_StateOperationalFromError_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalFromError_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void counters_StatePausedByParent_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StatePausedByParent_Active_Variable(void);
        bool get_Counters_StatePausedByParent_Active_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StatePausedByParent_Active_Variable(const OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void counters_StatePausedByParent_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StatePausedByParent_Classification_Variable(void);
        bool get_Counters_StatePausedByParent_Classification_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StatePausedByParent_Classification_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void counters_StatePausedByParent_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StatePausedByParent_DiagnosticsLevel_Variable(void);
        bool get_Counters_StatePausedByParent_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StatePausedByParent_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void counters_StatePausedByParent_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StatePausedByParent_TimeFirstChange_Variable(void);
        bool get_Counters_StatePausedByParent_TimeFirstChange_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StatePausedByParent_TimeFirstChange_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void counters_StatePausedByParent_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StatePausedByParent_Variable(void);
        bool get_Counters_StatePausedByParent_Variable(OpcUaDataValue& dataValue);
        bool set_Counters_StatePausedByParent_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void diagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnosticsLevel_Variable(void);
        bool get_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void liveValues_ConfiguredDataSetReaders_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& liveValues_ConfiguredDataSetReaders_DiagnosticsLevel_Variable(void);
        bool get_LiveValues_ConfiguredDataSetReaders_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_LiveValues_ConfiguredDataSetReaders_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt16
        //
        void liveValues_ConfiguredDataSetReaders_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& liveValues_ConfiguredDataSetReaders_Variable(void);
        bool get_LiveValues_ConfiguredDataSetReaders_Variable(OpcUaDataValue& dataValue);
        bool set_LiveValues_ConfiguredDataSetReaders_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void liveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& liveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable(void);
        bool get_LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_LiveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt16
        //
        void liveValues_ConfiguredDataSetWriters_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& liveValues_ConfiguredDataSetWriters_Variable(void);
        bool get_LiveValues_ConfiguredDataSetWriters_Variable(OpcUaDataValue& dataValue);
        bool set_LiveValues_ConfiguredDataSetWriters_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void liveValues_OperationalDataSetReaders_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& liveValues_OperationalDataSetReaders_DiagnosticsLevel_Variable(void);
        bool get_LiveValues_OperationalDataSetReaders_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_LiveValues_OperationalDataSetReaders_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt16
        //
        void liveValues_OperationalDataSetReaders_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& liveValues_OperationalDataSetReaders_Variable(void);
        bool get_LiveValues_OperationalDataSetReaders_Variable(OpcUaDataValue& dataValue);
        bool set_LiveValues_OperationalDataSetReaders_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void liveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& liveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable(void);
        bool get_LiveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_LiveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt16
        //
        void liveValues_OperationalDataSetWriters_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& liveValues_OperationalDataSetWriters_Variable(void);
        bool get_LiveValues_OperationalDataSetWriters_Variable(OpcUaDataValue& dataValue);
        bool set_LiveValues_OperationalDataSetWriters_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void subError_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subError_Variable(void);
        bool get_SubError_Variable(OpcUaDataValue& dataValue);
        bool set_SubError_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void totalError_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalError_Active_Variable(void);
        bool get_TotalError_Active_Variable(OpcUaDataValue& dataValue);
        bool set_TotalError_Active_Variable(const OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void totalError_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalError_Classification_Variable(void);
        bool get_TotalError_Classification_Variable(OpcUaDataValue& dataValue);
        bool set_TotalError_Classification_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void totalError_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalError_DiagnosticsLevel_Variable(void);
        bool get_TotalError_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_TotalError_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void totalError_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalError_TimeFirstChange_Variable(void);
        bool get_TotalError_TimeFirstChange_Variable(OpcUaDataValue& dataValue);
        bool set_TotalError_TimeFirstChange_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void totalError_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalError_Variable(void);
        bool get_TotalError_Variable(OpcUaDataValue& dataValue);
        bool set_TotalError_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void totalInformation_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalInformation_Active_Variable(void);
        bool get_TotalInformation_Active_Variable(OpcUaDataValue& dataValue);
        bool set_TotalInformation_Active_Variable(const OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void totalInformation_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalInformation_Classification_Variable(void);
        bool get_TotalInformation_Classification_Variable(OpcUaDataValue& dataValue);
        bool set_TotalInformation_Classification_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void totalInformation_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalInformation_DiagnosticsLevel_Variable(void);
        bool get_TotalInformation_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_TotalInformation_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void totalInformation_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalInformation_TimeFirstChange_Variable(void);
        bool get_TotalInformation_TimeFirstChange_Variable(OpcUaDataValue& dataValue);
        bool set_TotalInformation_TimeFirstChange_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void totalInformation_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalInformation_Variable(void);
        bool get_TotalInformation_Variable(OpcUaDataValue& dataValue);
        bool set_TotalInformation_Variable(const OpcUaDataValue& dataValue);

        virtual void call_Reset_Method(ApplicationMethodContext* applicationMethodContext);
    
      private:
        ServerVariable::SPtr counters_StateDisabledByMethod_Active_Variable_;
        ServerVariable::SPtr counters_StateDisabledByMethod_Classification_Variable_;
        ServerVariable::SPtr counters_StateDisabledByMethod_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr counters_StateDisabledByMethod_TimeFirstChange_Variable_;
        ServerVariable::SPtr counters_StateDisabledByMethod_Variable_;
        ServerVariable::SPtr counters_StateError_Active_Variable_;
        ServerVariable::SPtr counters_StateError_Classification_Variable_;
        ServerVariable::SPtr counters_StateError_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr counters_StateError_TimeFirstChange_Variable_;
        ServerVariable::SPtr counters_StateError_Variable_;
        ServerVariable::SPtr counters_StateOperationalByMethod_Active_Variable_;
        ServerVariable::SPtr counters_StateOperationalByMethod_Classification_Variable_;
        ServerVariable::SPtr counters_StateOperationalByMethod_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr counters_StateOperationalByMethod_TimeFirstChange_Variable_;
        ServerVariable::SPtr counters_StateOperationalByMethod_Variable_;
        ServerVariable::SPtr counters_StateOperationalByParent_Active_Variable_;
        ServerVariable::SPtr counters_StateOperationalByParent_Classification_Variable_;
        ServerVariable::SPtr counters_StateOperationalByParent_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr counters_StateOperationalByParent_TimeFirstChange_Variable_;
        ServerVariable::SPtr counters_StateOperationalByParent_Variable_;
        ServerVariable::SPtr counters_StateOperationalFromError_Active_Variable_;
        ServerVariable::SPtr counters_StateOperationalFromError_Classification_Variable_;
        ServerVariable::SPtr counters_StateOperationalFromError_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr counters_StateOperationalFromError_TimeFirstChange_Variable_;
        ServerVariable::SPtr counters_StateOperationalFromError_Variable_;
        ServerVariable::SPtr counters_StatePausedByParent_Active_Variable_;
        ServerVariable::SPtr counters_StatePausedByParent_Classification_Variable_;
        ServerVariable::SPtr counters_StatePausedByParent_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr counters_StatePausedByParent_TimeFirstChange_Variable_;
        ServerVariable::SPtr counters_StatePausedByParent_Variable_;
        ServerVariable::SPtr diagnosticsLevel_Variable_;
        ServerVariable::SPtr liveValues_ConfiguredDataSetReaders_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr liveValues_ConfiguredDataSetReaders_Variable_;
        ServerVariable::SPtr liveValues_ConfiguredDataSetWriters_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr liveValues_ConfiguredDataSetWriters_Variable_;
        ServerVariable::SPtr liveValues_OperationalDataSetReaders_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr liveValues_OperationalDataSetReaders_Variable_;
        ServerVariable::SPtr liveValues_OperationalDataSetWriters_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr liveValues_OperationalDataSetWriters_Variable_;
        ServerVariable::SPtr subError_Variable_;
        ServerVariable::SPtr totalError_Active_Variable_;
        ServerVariable::SPtr totalError_Classification_Variable_;
        ServerVariable::SPtr totalError_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr totalError_TimeFirstChange_Variable_;
        ServerVariable::SPtr totalError_Variable_;
        ServerVariable::SPtr totalInformation_Active_Variable_;
        ServerVariable::SPtr totalInformation_Classification_Variable_;
        ServerVariable::SPtr totalInformation_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr totalInformation_TimeFirstChange_Variable_;
        ServerVariable::SPtr totalInformation_Variable_;
        ServerMethod::SPtr reset_Method_;
   
   };

}

#endif
