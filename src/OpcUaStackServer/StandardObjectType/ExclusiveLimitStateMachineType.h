/*
    ObjectTypeClass: ExclusiveLimitStateMachineType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_ExclusiveLimitStateMachineType_h__
#define __OpcUaStackServer_ExclusiveLimitStateMachineType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT ExclusiveLimitStateMachineType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<ExclusiveLimitStateMachineType> SPtr;
       typedef std::vector<ExclusiveLimitStateMachineType::SPtr> Vec;
   
       ExclusiveLimitStateMachineType(void);
       ExclusiveLimitStateMachineType(const ExclusiveLimitStateMachineType& value);
       virtual ~ExclusiveLimitStateMachineType(void);

        //
        // NodeId (Array)
        //
        void availableStates_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& availableStates_Variable(void);
        bool get_AvailableStates_Variable(OpcUaDataValue& dataValue);
        bool set_AvailableStates_Variable(const OpcUaDataValue& dataValue);

        //
        // NodeId (Array)
        //
        void availableTransitions_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& availableTransitions_Variable(void);
        bool get_AvailableTransitions_Variable(OpcUaDataValue& dataValue);
        bool set_AvailableTransitions_Variable(const OpcUaDataValue& dataValue);

        //
        // NodeId
        //
        void currentState_Id_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& currentState_Id_Variable(void);
        bool get_CurrentState_Id_Variable(OpcUaDataValue& dataValue);
        bool set_CurrentState_Id_Variable(const OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void currentState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& currentState_Variable(void);
        bool get_CurrentState_Variable(OpcUaDataValue& dataValue);
        bool set_CurrentState_Variable(const OpcUaDataValue& dataValue);

        //
        // NodeId
        //
        void lastTransition_Id_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& lastTransition_Id_Variable(void);
        bool get_LastTransition_Id_Variable(OpcUaDataValue& dataValue);
        bool set_LastTransition_Id_Variable(const OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void lastTransition_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& lastTransition_Variable(void);
        bool get_LastTransition_Variable(OpcUaDataValue& dataValue);
        bool set_LastTransition_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr availableStates_Variable_;
        ServerVariable::SPtr availableTransitions_Variable_;
        ServerVariable::SPtr currentState_Id_Variable_;
        ServerVariable::SPtr currentState_Variable_;
        ServerVariable::SPtr lastTransition_Id_Variable_;
        ServerVariable::SPtr lastTransition_Variable_;
   
   };

}

#endif
