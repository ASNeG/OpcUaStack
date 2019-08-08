/*
    VariableTypeClass: PubSubDiagnosticsCounterType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_PubSubDiagnosticsCounterType_h__
#define __OpcUaStackServer_PubSubDiagnosticsCounterType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT PubSubDiagnosticsCounterType
   : public VariableBase
   {
     public:
       typedef boost::shared_ptr<PubSubDiagnosticsCounterType> SPtr;
       typedef std::vector<PubSubDiagnosticsCounterType::SPtr> Vec;
   
       PubSubDiagnosticsCounterType(void);
       PubSubDiagnosticsCounterType(const PubSubDiagnosticsCounterType& value);
       virtual ~PubSubDiagnosticsCounterType(void);

        //
        // Boolean
        //
        void active_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& active_Variable(void);
        bool get_Active_Variable(OpcUaDataValue& dataValue);
        bool set_Active_Variable(const OpcUaDataValue& dataValue);

        //
        // PubSubDiagnosticsCounterClassification
        //
        void classification_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& classification_Variable(void);
        bool get_Classification_Variable(OpcUaDataValue& dataValue);
        bool set_Classification_Variable(const OpcUaDataValue& dataValue);

        //
        // DiagnosticsLevel
        //
        void diagnosticsLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& diagnosticsLevel_Variable(void);
        bool get_DiagnosticsLevel_Variable(OpcUaDataValue& dataValue);
        bool set_DiagnosticsLevel_Variable(const OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void timeFirstChange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& timeFirstChange_Variable(void);
        bool get_TimeFirstChange_Variable(OpcUaDataValue& dataValue);
        bool set_TimeFirstChange_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32 (Array)
        //
        void variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& variable(void);
        bool get_Variable(OpcUaDataValue& dataValue);
        bool set_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr active_Variable_;
        ServerVariable::SPtr classification_Variable_;
        ServerVariable::SPtr diagnosticsLevel_Variable_;
        ServerVariable::SPtr timeFirstChange_Variable_;
        ServerVariable::SPtr variable_;
   
   };

}

#endif
