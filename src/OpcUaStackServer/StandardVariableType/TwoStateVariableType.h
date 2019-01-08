/*
    VariableTypeClass: TwoStateVariableType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_TwoStateVariableType_h__
#define __OpcUaStackServer_TwoStateVariableType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT TwoStateVariableType
   : public VariableBase
   {
     public:
       typedef boost::shared_ptr<TwoStateVariableType> SPtr;
       typedef std::vector<TwoStateVariableType::SPtr> Vec;
   
       TwoStateVariableType(void);
       TwoStateVariableType(const TwoStateVariableType& value);
       virtual ~TwoStateVariableType(void);

        //
        // LocalizedText
        //
        void effectiveDisplayName_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& effectiveDisplayName_Variable(void);
        bool get_EffectiveDisplayName_Variable(OpcUaDataValue& dataValue);
        bool set_EffectiveDisplayName_Variable(const OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void effectiveTransitionTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& effectiveTransitionTime_Variable(void);
        bool get_EffectiveTransitionTime_Variable(OpcUaDataValue& dataValue);
        bool set_EffectiveTransitionTime_Variable(const OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void falseState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& falseState_Variable(void);
        bool get_FalseState_Variable(OpcUaDataValue& dataValue);
        bool set_FalseState_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void id_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& id_Variable(void);
        bool get_Id_Variable(OpcUaDataValue& dataValue);
        bool set_Id_Variable(const OpcUaDataValue& dataValue);

        //
        // QualifiedName
        //
        void name_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& name_Variable(void);
        bool get_Name_Variable(OpcUaDataValue& dataValue);
        bool set_Name_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void number_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& number_Variable(void);
        bool get_Number_Variable(OpcUaDataValue& dataValue);
        bool set_Number_Variable(const OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void transitionTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& transitionTime_Variable(void);
        bool get_TransitionTime_Variable(OpcUaDataValue& dataValue);
        bool set_TransitionTime_Variable(const OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void trueState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& trueState_Variable(void);
        bool get_TrueState_Variable(OpcUaDataValue& dataValue);
        bool set_TrueState_Variable(const OpcUaDataValue& dataValue);

        //
        // LocalizedText (Array)
        //
        void variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& variable(void);
        bool get_Variable(OpcUaDataValue& dataValue);
        bool set_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr effectiveDisplayName_Variable_;
        ServerVariable::SPtr effectiveTransitionTime_Variable_;
        ServerVariable::SPtr falseState_Variable_;
        ServerVariable::SPtr id_Variable_;
        ServerVariable::SPtr name_Variable_;
        ServerVariable::SPtr number_Variable_;
        ServerVariable::SPtr transitionTime_Variable_;
        ServerVariable::SPtr trueState_Variable_;
        ServerVariable::SPtr variable_;
   
   };

}

#endif
