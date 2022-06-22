/*
    ObjectTypeClass: FileTransferStateMachineType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_FileTransferStateMachineType_h__
#define __OpcUaStackServer_FileTransferStateMachineType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT FileTransferStateMachineType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<FileTransferStateMachineType> SPtr;
       typedef std::vector<FileTransferStateMachineType::SPtr> Vec;
   
       FileTransferStateMachineType(void);
       FileTransferStateMachineType(const FileTransferStateMachineType& value);
       virtual ~FileTransferStateMachineType(void);

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
        // LocalizedText
        //
        void currentState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& currentState_Variable(void);
        bool get_CurrentState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_CurrentState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // NodeId
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

        virtual void call_Reset_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);
    
      private:
        ServerVariable::SPtr availableStates_Variable_;
        ServerVariable::SPtr availableTransitions_Variable_;
        ServerVariable::SPtr currentState_Id_Variable_;
        ServerVariable::SPtr currentState_Variable_;
        ServerVariable::SPtr lastTransition_Id_Variable_;
        ServerVariable::SPtr lastTransition_Variable_;
        ServerMethod::SPtr reset_Method_;
   
   };

}

#endif
