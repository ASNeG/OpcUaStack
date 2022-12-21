/*
    ObjectTypeClass: ProgramStateMachineType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_ProgramStateMachineType_h__
#define __OpcUaStackServer_ProgramStateMachineType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT ProgramStateMachineType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<ProgramStateMachineType> SPtr;
       typedef std::vector<ProgramStateMachineType::SPtr> Vec;
   
       ProgramStateMachineType(void);
       ProgramStateMachineType(const ProgramStateMachineType& value);
       virtual ~ProgramStateMachineType(void);

        //
        // Boolean
        //
        void autoDelete_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& autoDelete_Variable(void);
        bool get_AutoDelete_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_AutoDelete_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // NodeId (Array)
        //
        void availableStates_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& availableStates_Variable(void);
        bool get_AvailableStates_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_AvailableStates_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // NodeId (Array)
        //
        void availableTransitions_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& availableTransitions_Variable(void);
        bool get_AvailableTransitions_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_AvailableTransitions_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // NodeId
        //
        void currentState_Id_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& currentState_Id_Variable(void);
        bool get_CurrentState_Id_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_CurrentState_Id_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void currentState_Number_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& currentState_Number_Variable(void);
        bool get_CurrentState_Number_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_CurrentState_Number_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void currentState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& currentState_Variable(void);
        bool get_CurrentState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_CurrentState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void deletable_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& deletable_Variable(void);
        bool get_Deletable_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Deletable_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // NodeId
        //
        void lastTransition_Id_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& lastTransition_Id_Variable(void);
        bool get_LastTransition_Id_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LastTransition_Id_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void lastTransition_Number_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& lastTransition_Number_Variable(void);
        bool get_LastTransition_Number_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LastTransition_Number_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void lastTransition_TransitionTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& lastTransition_TransitionTime_Variable(void);
        bool get_LastTransition_TransitionTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LastTransition_TransitionTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void lastTransition_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& lastTransition_Variable(void);
        bool get_LastTransition_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LastTransition_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String
        //
        void programDiagnostics_CreateClientName_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& programDiagnostics_CreateClientName_Variable(void);
        bool get_ProgramDiagnostics_CreateClientName_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ProgramDiagnostics_CreateClientName_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // NodeId
        //
        void programDiagnostics_CreateSessionId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& programDiagnostics_CreateSessionId_Variable(void);
        bool get_ProgramDiagnostics_CreateSessionId_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ProgramDiagnostics_CreateSessionId_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void programDiagnostics_InvocationCreationTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& programDiagnostics_InvocationCreationTime_Variable(void);
        bool get_ProgramDiagnostics_InvocationCreationTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ProgramDiagnostics_InvocationCreationTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void programDiagnostics_LastMethodCallTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& programDiagnostics_LastMethodCallTime_Variable(void);
        bool get_ProgramDiagnostics_LastMethodCallTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ProgramDiagnostics_LastMethodCallTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String
        //
        void programDiagnostics_LastMethodCall_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& programDiagnostics_LastMethodCall_Variable(void);
        bool get_ProgramDiagnostics_LastMethodCall_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ProgramDiagnostics_LastMethodCall_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Argument (Array)
        //
        void programDiagnostics_LastMethodInputArguments_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& programDiagnostics_LastMethodInputArguments_Variable(void);
        bool get_ProgramDiagnostics_LastMethodInputArguments_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ProgramDiagnostics_LastMethodInputArguments_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Variant (Array)
        //
        void programDiagnostics_LastMethodInputValues_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& programDiagnostics_LastMethodInputValues_Variable(void);
        bool get_ProgramDiagnostics_LastMethodInputValues_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ProgramDiagnostics_LastMethodInputValues_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Argument (Array)
        //
        void programDiagnostics_LastMethodOutputArguments_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& programDiagnostics_LastMethodOutputArguments_Variable(void);
        bool get_ProgramDiagnostics_LastMethodOutputArguments_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ProgramDiagnostics_LastMethodOutputArguments_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Variant (Array)
        //
        void programDiagnostics_LastMethodOutputValues_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& programDiagnostics_LastMethodOutputValues_Variable(void);
        bool get_ProgramDiagnostics_LastMethodOutputValues_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ProgramDiagnostics_LastMethodOutputValues_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Status
        //
        void programDiagnostics_LastMethodReturnStatus_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& programDiagnostics_LastMethodReturnStatus_Variable(void);
        bool get_ProgramDiagnostics_LastMethodReturnStatus_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ProgramDiagnostics_LastMethodReturnStatus_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // NodeId
        //
        void programDiagnostics_LastMethodSessionId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& programDiagnostics_LastMethodSessionId_Variable(void);
        bool get_ProgramDiagnostics_LastMethodSessionId_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ProgramDiagnostics_LastMethodSessionId_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void programDiagnostics_LastTransitionTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& programDiagnostics_LastTransitionTime_Variable(void);
        bool get_ProgramDiagnostics_LastTransitionTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ProgramDiagnostics_LastTransitionTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // ProgramDiagnostic2DataType
        //
        void programDiagnostics_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& programDiagnostics_Variable(void);
        bool get_ProgramDiagnostics_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ProgramDiagnostics_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Int32
        //
        void recycleCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& recycleCount_Variable(void);
        bool get_RecycleCount_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_RecycleCount_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr autoDelete_Variable_;
        ServerVariable::SPtr availableStates_Variable_;
        ServerVariable::SPtr availableTransitions_Variable_;
        ServerVariable::SPtr currentState_Id_Variable_;
        ServerVariable::SPtr currentState_Number_Variable_;
        ServerVariable::SPtr currentState_Variable_;
        ServerVariable::SPtr deletable_Variable_;
        ServerVariable::SPtr lastTransition_Id_Variable_;
        ServerVariable::SPtr lastTransition_Number_Variable_;
        ServerVariable::SPtr lastTransition_TransitionTime_Variable_;
        ServerVariable::SPtr lastTransition_Variable_;
        ServerVariable::SPtr programDiagnostics_CreateClientName_Variable_;
        ServerVariable::SPtr programDiagnostics_CreateSessionId_Variable_;
        ServerVariable::SPtr programDiagnostics_InvocationCreationTime_Variable_;
        ServerVariable::SPtr programDiagnostics_LastMethodCallTime_Variable_;
        ServerVariable::SPtr programDiagnostics_LastMethodCall_Variable_;
        ServerVariable::SPtr programDiagnostics_LastMethodInputArguments_Variable_;
        ServerVariable::SPtr programDiagnostics_LastMethodInputValues_Variable_;
        ServerVariable::SPtr programDiagnostics_LastMethodOutputArguments_Variable_;
        ServerVariable::SPtr programDiagnostics_LastMethodOutputValues_Variable_;
        ServerVariable::SPtr programDiagnostics_LastMethodReturnStatus_Variable_;
        ServerVariable::SPtr programDiagnostics_LastMethodSessionId_Variable_;
        ServerVariable::SPtr programDiagnostics_LastTransitionTime_Variable_;
        ServerVariable::SPtr programDiagnostics_Variable_;
        ServerVariable::SPtr recycleCount_Variable_;
   
   };

}

#endif
