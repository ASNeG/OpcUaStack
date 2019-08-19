/*
    VariableTypeClass: SessionSecurityDiagnosticsArrayType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_SessionSecurityDiagnosticsArrayType_h__
#define __OpcUaStackServer_SessionSecurityDiagnosticsArrayType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
   
   class DLLEXPORT SessionSecurityDiagnosticsArrayType
   : public VariableBase
   {
     public:
       typedef boost::shared_ptr<SessionSecurityDiagnosticsArrayType> SPtr;
       typedef std::vector<SessionSecurityDiagnosticsArrayType::SPtr> Vec;
   
       SessionSecurityDiagnosticsArrayType(void);
       SessionSecurityDiagnosticsArrayType(const SessionSecurityDiagnosticsArrayType& value);
       virtual ~SessionSecurityDiagnosticsArrayType(void);

        //
        // String
        //
        void sessionSecurityDiagnostics_AuthenticationMechanism_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionSecurityDiagnostics_AuthenticationMechanism_Variable(void);
        bool get_SessionSecurityDiagnostics_AuthenticationMechanism_Variable(OpcUaDataValue& dataValue);
        bool set_SessionSecurityDiagnostics_AuthenticationMechanism_Variable(const OpcUaDataValue& dataValue);

        //
        // ByteString
        //
        void sessionSecurityDiagnostics_ClientCertificate_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionSecurityDiagnostics_ClientCertificate_Variable(void);
        bool get_SessionSecurityDiagnostics_ClientCertificate_Variable(OpcUaDataValue& dataValue);
        bool set_SessionSecurityDiagnostics_ClientCertificate_Variable(const OpcUaDataValue& dataValue);

        //
        // String (Array)
        //
        void sessionSecurityDiagnostics_ClientUserIdHistory_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionSecurityDiagnostics_ClientUserIdHistory_Variable(void);
        bool get_SessionSecurityDiagnostics_ClientUserIdHistory_Variable(OpcUaDataValue& dataValue);
        bool set_SessionSecurityDiagnostics_ClientUserIdHistory_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void sessionSecurityDiagnostics_ClientUserIdOfSession_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionSecurityDiagnostics_ClientUserIdOfSession_Variable(void);
        bool get_SessionSecurityDiagnostics_ClientUserIdOfSession_Variable(OpcUaDataValue& dataValue);
        bool set_SessionSecurityDiagnostics_ClientUserIdOfSession_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void sessionSecurityDiagnostics_Encoding_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionSecurityDiagnostics_Encoding_Variable(void);
        bool get_SessionSecurityDiagnostics_Encoding_Variable(OpcUaDataValue& dataValue);
        bool set_SessionSecurityDiagnostics_Encoding_Variable(const OpcUaDataValue& dataValue);

        //
        // MessageSecurityMode
        //
        void sessionSecurityDiagnostics_SecurityMode_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionSecurityDiagnostics_SecurityMode_Variable(void);
        bool get_SessionSecurityDiagnostics_SecurityMode_Variable(OpcUaDataValue& dataValue);
        bool set_SessionSecurityDiagnostics_SecurityMode_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void sessionSecurityDiagnostics_SecurityPolicyUri_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionSecurityDiagnostics_SecurityPolicyUri_Variable(void);
        bool get_SessionSecurityDiagnostics_SecurityPolicyUri_Variable(OpcUaDataValue& dataValue);
        bool set_SessionSecurityDiagnostics_SecurityPolicyUri_Variable(const OpcUaDataValue& dataValue);

        //
        // NodeId
        //
        void sessionSecurityDiagnostics_SessionId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionSecurityDiagnostics_SessionId_Variable(void);
        bool get_SessionSecurityDiagnostics_SessionId_Variable(OpcUaDataValue& dataValue);
        bool set_SessionSecurityDiagnostics_SessionId_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void sessionSecurityDiagnostics_TransportProtocol_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionSecurityDiagnostics_TransportProtocol_Variable(void);
        bool get_SessionSecurityDiagnostics_TransportProtocol_Variable(OpcUaDataValue& dataValue);
        bool set_SessionSecurityDiagnostics_TransportProtocol_Variable(const OpcUaDataValue& dataValue);

        //
        // SessionSecurityDiagnosticsDataType
        //
        void sessionSecurityDiagnostics_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionSecurityDiagnostics_Variable(void);
        bool get_SessionSecurityDiagnostics_Variable(OpcUaDataValue& dataValue);
        bool set_SessionSecurityDiagnostics_Variable(const OpcUaDataValue& dataValue);

        //
        // SessionSecurityDiagnosticsDataType (Array)
        //
        void variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& variable(void);
        bool get_Variable(OpcUaDataValue& dataValue);
        bool set_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr sessionSecurityDiagnostics_AuthenticationMechanism_Variable_;
        ServerVariable::SPtr sessionSecurityDiagnostics_ClientCertificate_Variable_;
        ServerVariable::SPtr sessionSecurityDiagnostics_ClientUserIdHistory_Variable_;
        ServerVariable::SPtr sessionSecurityDiagnostics_ClientUserIdOfSession_Variable_;
        ServerVariable::SPtr sessionSecurityDiagnostics_Encoding_Variable_;
        ServerVariable::SPtr sessionSecurityDiagnostics_SecurityMode_Variable_;
        ServerVariable::SPtr sessionSecurityDiagnostics_SecurityPolicyUri_Variable_;
        ServerVariable::SPtr sessionSecurityDiagnostics_SessionId_Variable_;
        ServerVariable::SPtr sessionSecurityDiagnostics_TransportProtocol_Variable_;
        ServerVariable::SPtr sessionSecurityDiagnostics_Variable_;
        ServerVariable::SPtr variable_;
   
   };

}

#endif
