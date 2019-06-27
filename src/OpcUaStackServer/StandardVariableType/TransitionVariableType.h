/*
    VariableTypeClass: TransitionVariableType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_TransitionVariableType_h__
#define __OpcUaStackServer_TransitionVariableType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT TransitionVariableType
   : public VariableBase
   {
     public:
       typedef boost::shared_ptr<TransitionVariableType> SPtr;
       typedef std::vector<TransitionVariableType::SPtr> Vec;
   
       TransitionVariableType(void);
       TransitionVariableType(const TransitionVariableType& value);
       virtual ~TransitionVariableType(void);

        //
        // UtcTime
        //
        void effectiveTransitionTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& effectiveTransitionTime_Variable(void);
        bool get_EffectiveTransitionTime_Variable(OpcUaDataValue& dataValue);
        bool set_EffectiveTransitionTime_Variable(const OpcUaDataValue& dataValue);

        //
        // Variant
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
        // LocalizedText (Array)
        //
        void variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& variable(void);
        bool get_Variable(OpcUaDataValue& dataValue);
        bool set_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr effectiveTransitionTime_Variable_;
        ServerVariable::SPtr id_Variable_;
        ServerVariable::SPtr name_Variable_;
        ServerVariable::SPtr number_Variable_;
        ServerVariable::SPtr transitionTime_Variable_;
        ServerVariable::SPtr variable_;
   
   };

}

#endif
