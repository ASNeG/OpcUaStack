/*
    ObjectTypeClass: StateMachineType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_StateMachineType_h__
#define __OpcUaStackServer_StateMachineType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT StateMachineType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<StateMachineType> SPtr;
       typedef std::vector<StateMachineType::SPtr> Vec;
   
       StateMachineType(void);
       StateMachineType(const StateMachineType& value);
       virtual ~StateMachineType(void);

        //
        // Variant
        //
        void currentState_Id_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& currentState_Id_Variable(void);
        bool get_CurrentState_Id_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_CurrentState_Id_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void currentState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& currentState_Variable(void);
        bool get_CurrentState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_CurrentState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Variant
        //
        void lastTransition_Id_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& lastTransition_Id_Variable(void);
        bool get_LastTransition_Id_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LastTransition_Id_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void lastTransition_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& lastTransition_Variable(void);
        bool get_LastTransition_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LastTransition_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr currentState_Id_Variable_;
        ServerVariable::SPtr currentState_Variable_;
        ServerVariable::SPtr lastTransition_Id_Variable_;
        ServerVariable::SPtr lastTransition_Variable_;
   
   };

}

#endif
