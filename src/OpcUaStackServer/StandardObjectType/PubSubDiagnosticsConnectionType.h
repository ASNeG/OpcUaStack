/*
    ObjectTypeClass: PubSubDiagnosticsConnectionType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_PubSubDiagnosticsConnectionType_h__
#define __OpcUaStackServer_PubSubDiagnosticsConnectionType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT PubSubDiagnosticsConnectionType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<PubSubDiagnosticsConnectionType> SPtr;
       typedef std::vector<PubSubDiagnosticsConnectionType::SPtr> Vec;
   
       PubSubDiagnosticsConnectionType(void);
       PubSubDiagnosticsConnectionType(const PubSubDiagnosticsConnectionType& value);
       virtual ~PubSubDiagnosticsConnectionType(void);

        //
        // Boolean
        //
        void counters_StateDisabledByMethod_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateDisabledByMethod_Active_Variable(void);
        bool get_Counters_StateDisabledByMethod_Active_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateDisabledByMethod_Active_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void counters_StateDisabledByMethod_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateDisabledByMethod_Classification_Variable(void);
        bool get_Counters_StateDisabledByMethod_Classification_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateDisabledByMethod_Classification_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void counters_StateDisabledByMethod_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateDisabledByMethod_DiagnosticsLevel_Variable(void);
        bool get_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateDisabledByMethod_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void counters_StateDisabledByMethod_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateDisabledByMethod_TimeFirstChange_Variable(void);
        bool get_Counters_StateDisabledByMethod_TimeFirstChange_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateDisabledByMethod_TimeFirstChange_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void counters_StateDisabledByMethod_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateDisabledByMethod_Variable(void);
        bool get_Counters_StateDisabledByMethod_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateDisabledByMethod_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void counters_StateError_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateError_Active_Variable(void);
        bool get_Counters_StateError_Active_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateError_Active_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void counters_StateError_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateError_Classification_Variable(void);
        bool get_Counters_StateError_Classification_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateError_Classification_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void counters_StateError_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateError_DiagnosticsLevel_Variable(void);
        bool get_Counters_StateError_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateError_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void counters_StateError_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateError_TimeFirstChange_Variable(void);
        bool get_Counters_StateError_TimeFirstChange_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateError_TimeFirstChange_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void counters_StateError_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateError_Variable(void);
        bool get_Counters_StateError_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateError_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void counters_StateOperationalByMethod_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalByMethod_Active_Variable(void);
        bool get_Counters_StateOperationalByMethod_Active_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalByMethod_Active_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void counters_StateOperationalByMethod_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalByMethod_Classification_Variable(void);
        bool get_Counters_StateOperationalByMethod_Classification_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalByMethod_Classification_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void counters_StateOperationalByMethod_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalByMethod_DiagnosticsLevel_Variable(void);
        bool get_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalByMethod_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void counters_StateOperationalByMethod_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalByMethod_TimeFirstChange_Variable(void);
        bool get_Counters_StateOperationalByMethod_TimeFirstChange_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalByMethod_TimeFirstChange_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void counters_StateOperationalByMethod_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalByMethod_Variable(void);
        bool get_Counters_StateOperationalByMethod_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalByMethod_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void counters_StateOperationalByParent_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalByParent_Active_Variable(void);
        bool get_Counters_StateOperationalByParent_Active_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalByParent_Active_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void counters_StateOperationalByParent_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalByParent_Classification_Variable(void);
        bool get_Counters_StateOperationalByParent_Classification_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalByParent_Classification_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void counters_StateOperationalByParent_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalByParent_DiagnosticsLevel_Variable(void);
        bool get_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalByParent_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void counters_StateOperationalByParent_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalByParent_TimeFirstChange_Variable(void);
        bool get_Counters_StateOperationalByParent_TimeFirstChange_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalByParent_TimeFirstChange_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void counters_StateOperationalByParent_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalByParent_Variable(void);
        bool get_Counters_StateOperationalByParent_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalByParent_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void counters_StateOperationalFromError_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalFromError_Active_Variable(void);
        bool get_Counters_StateOperationalFromError_Active_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalFromError_Active_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void counters_StateOperationalFromError_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalFromError_Classification_Variable(void);
        bool get_Counters_StateOperationalFromError_Classification_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalFromError_Classification_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void counters_StateOperationalFromError_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalFromError_DiagnosticsLevel_Variable(void);
        bool get_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalFromError_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void counters_StateOperationalFromError_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalFromError_TimeFirstChange_Variable(void);
        bool get_Counters_StateOperationalFromError_TimeFirstChange_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalFromError_TimeFirstChange_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void counters_StateOperationalFromError_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StateOperationalFromError_Variable(void);
        bool get_Counters_StateOperationalFromError_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StateOperationalFromError_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void counters_StatePausedByParent_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StatePausedByParent_Active_Variable(void);
        bool get_Counters_StatePausedByParent_Active_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StatePausedByParent_Active_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void counters_StatePausedByParent_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StatePausedByParent_Classification_Variable(void);
        bool get_Counters_StatePausedByParent_Classification_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StatePausedByParent_Classification_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void counters_StatePausedByParent_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StatePausedByParent_DiagnosticsLevel_Variable(void);
        bool get_Counters_StatePausedByParent_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StatePausedByParent_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void counters_StatePausedByParent_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StatePausedByParent_TimeFirstChange_Variable(void);
        bool get_Counters_StatePausedByParent_TimeFirstChange_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StatePausedByParent_TimeFirstChange_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void counters_StatePausedByParent_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& counters_StatePausedByParent_Variable(void);
        bool get_Counters_StatePausedByParent_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Counters_StatePausedByParent_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void diagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnosticsLevel_Variable(void);
        bool get_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void liveValues_ResolvedAddress_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& liveValues_ResolvedAddress_DiagnosticsLevel_Variable(void);
        bool get_LiveValues_ResolvedAddress_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LiveValues_ResolvedAddress_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String
        //
        void liveValues_ResolvedAddress_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& liveValues_ResolvedAddress_Variable(void);
        bool get_LiveValues_ResolvedAddress_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LiveValues_ResolvedAddress_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void subError_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subError_Variable(void);
        bool get_SubError_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SubError_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void totalError_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalError_Active_Variable(void);
        bool get_TotalError_Active_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_TotalError_Active_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void totalError_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalError_Classification_Variable(void);
        bool get_TotalError_Classification_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_TotalError_Classification_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void totalError_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalError_DiagnosticsLevel_Variable(void);
        bool get_TotalError_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_TotalError_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void totalError_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalError_TimeFirstChange_Variable(void);
        bool get_TotalError_TimeFirstChange_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_TotalError_TimeFirstChange_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void totalError_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalError_Variable(void);
        bool get_TotalError_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_TotalError_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void totalInformation_Active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalInformation_Active_Variable(void);
        bool get_TotalInformation_Active_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_TotalInformation_Active_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void totalInformation_Classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalInformation_Classification_Variable(void);
        bool get_TotalInformation_Classification_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_TotalInformation_Classification_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void totalInformation_DiagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalInformation_DiagnosticsLevel_Variable(void);
        bool get_TotalInformation_DiagnosticsLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_TotalInformation_DiagnosticsLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void totalInformation_TimeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalInformation_TimeFirstChange_Variable(void);
        bool get_TotalInformation_TimeFirstChange_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_TotalInformation_TimeFirstChange_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void totalInformation_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalInformation_Variable(void);
        bool get_TotalInformation_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_TotalInformation_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        virtual void call_Reset_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);
    
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
        ServerVariable::SPtr liveValues_ResolvedAddress_DiagnosticsLevel_Variable_;
        ServerVariable::SPtr liveValues_ResolvedAddress_Variable_;
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
