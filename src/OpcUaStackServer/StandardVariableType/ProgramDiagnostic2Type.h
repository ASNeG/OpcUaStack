/*
    VariableTypeClass: ProgramDiagnostic2Type

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_ProgramDiagnostic2Type_h__
#define __OpcUaStackServer_ProgramDiagnostic2Type_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT ProgramDiagnostic2Type
   : public VariableBase
   {
     public:
       typedef boost::shared_ptr<ProgramDiagnostic2Type> SPtr;
       typedef std::vector<ProgramDiagnostic2Type::SPtr> Vec;
   
       ProgramDiagnostic2Type(void);
       ProgramDiagnostic2Type(const ProgramDiagnostic2Type& value);
       virtual ~ProgramDiagnostic2Type(void);

        //
        // String
        //
        void createClientName_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& createClientName_Variable(void);
        bool get_CreateClientName_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_CreateClientName_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // NodeId
        //
        void createSessionId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& createSessionId_Variable(void);
        bool get_CreateSessionId_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_CreateSessionId_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void invocationCreationTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& invocationCreationTime_Variable(void);
        bool get_InvocationCreationTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_InvocationCreationTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void lastMethodCallTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& lastMethodCallTime_Variable(void);
        bool get_LastMethodCallTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LastMethodCallTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String
        //
        void lastMethodCall_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& lastMethodCall_Variable(void);
        bool get_LastMethodCall_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LastMethodCall_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Argument (Array)
        //
        void lastMethodInputArguments_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& lastMethodInputArguments_Variable(void);
        bool get_LastMethodInputArguments_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LastMethodInputArguments_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Variant (Array)
        //
        void lastMethodInputValues_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& lastMethodInputValues_Variable(void);
        bool get_LastMethodInputValues_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LastMethodInputValues_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Argument (Array)
        //
        void lastMethodOutputArguments_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& lastMethodOutputArguments_Variable(void);
        bool get_LastMethodOutputArguments_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LastMethodOutputArguments_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Variant (Array)
        //
        void lastMethodOutputValues_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& lastMethodOutputValues_Variable(void);
        bool get_LastMethodOutputValues_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LastMethodOutputValues_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Status
        //
        void lastMethodReturnStatus_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& lastMethodReturnStatus_Variable(void);
        bool get_LastMethodReturnStatus_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LastMethodReturnStatus_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // NodeId
        //
        void lastMethodSessionId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& lastMethodSessionId_Variable(void);
        bool get_LastMethodSessionId_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LastMethodSessionId_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void lastTransitionTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& lastTransitionTime_Variable(void);
        bool get_LastTransitionTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LastTransitionTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // ProgramDiagnostic2DataType (Array)
        //
        void variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& variable(void);
        bool get_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr createClientName_Variable_;
        ServerVariable::SPtr createSessionId_Variable_;
        ServerVariable::SPtr invocationCreationTime_Variable_;
        ServerVariable::SPtr lastMethodCallTime_Variable_;
        ServerVariable::SPtr lastMethodCall_Variable_;
        ServerVariable::SPtr lastMethodInputArguments_Variable_;
        ServerVariable::SPtr lastMethodInputValues_Variable_;
        ServerVariable::SPtr lastMethodOutputArguments_Variable_;
        ServerVariable::SPtr lastMethodOutputValues_Variable_;
        ServerVariable::SPtr lastMethodReturnStatus_Variable_;
        ServerVariable::SPtr lastMethodSessionId_Variable_;
        ServerVariable::SPtr lastTransitionTime_Variable_;
        ServerVariable::SPtr variable_;
   
   };

}

#endif
