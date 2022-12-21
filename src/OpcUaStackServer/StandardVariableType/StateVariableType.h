/*
    VariableTypeClass: StateVariableType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_StateVariableType_h__
#define __OpcUaStackServer_StateVariableType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT StateVariableType
   : public VariableBase
   {
     public:
       typedef boost::shared_ptr<StateVariableType> SPtr;
       typedef std::vector<StateVariableType::SPtr> Vec;
   
       StateVariableType(void);
       StateVariableType(const StateVariableType& value);
       virtual ~StateVariableType(void);

        //
        // LocalizedText
        //
        void effectiveDisplayName_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& effectiveDisplayName_Variable(void);
        bool get_EffectiveDisplayName_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_EffectiveDisplayName_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Variant
        //
        void id_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& id_Variable(void);
        bool get_Id_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Id_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // QualifiedName
        //
        void name_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& name_Variable(void);
        bool get_Name_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Name_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void number_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& number_Variable(void);
        bool get_Number_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Number_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText (Array)
        //
        void variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& variable(void);
        bool get_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr effectiveDisplayName_Variable_;
        ServerVariable::SPtr id_Variable_;
        ServerVariable::SPtr name_Variable_;
        ServerVariable::SPtr number_Variable_;
        ServerVariable::SPtr variable_;
   
   };

}

#endif
