/*
    VariableTypeClass: SessionSecurityDiagnosticsType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_SessionSecurityDiagnosticsType_h__
#define __OpcUaStackServer_SessionSecurityDiagnosticsType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT SessionSecurityDiagnosticsType
   : public VariableBase
   {
     public:
       typedef boost::shared_ptr<SessionSecurityDiagnosticsType> SPtr;
       typedef std::vector<SessionSecurityDiagnosticsType::SPtr> Vec;
   
       SessionSecurityDiagnosticsType(void);
       SessionSecurityDiagnosticsType(const SessionSecurityDiagnosticsType& value);
       virtual ~SessionSecurityDiagnosticsType(void);

        //
        // String
        //
        void authenticationMechanism_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& authenticationMechanism_Variable(void);
        bool get_AuthenticationMechanism_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_AuthenticationMechanism_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // ByteString
        //
        void clientCertificate_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& clientCertificate_Variable(void);
        bool get_ClientCertificate_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ClientCertificate_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String (Array)
        //
        void clientUserIdHistory_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& clientUserIdHistory_Variable(void);
        bool get_ClientUserIdHistory_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ClientUserIdHistory_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String
        //
        void clientUserIdOfSession_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& clientUserIdOfSession_Variable(void);
        bool get_ClientUserIdOfSession_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ClientUserIdOfSession_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String
        //
        void encoding_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& encoding_Variable(void);
        bool get_Encoding_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Encoding_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // MessageSecurityMode
        //
        void securityMode_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& securityMode_Variable(void);
        bool get_SecurityMode_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SecurityMode_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String
        //
        void securityPolicyUri_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& securityPolicyUri_Variable(void);
        bool get_SecurityPolicyUri_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SecurityPolicyUri_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // NodeId
        //
        void sessionId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionId_Variable(void);
        bool get_SessionId_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SessionId_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String
        //
        void transportProtocol_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& transportProtocol_Variable(void);
        bool get_TransportProtocol_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_TransportProtocol_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // SessionSecurityDiagnosticsDataType (Array)
        //
        void variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& variable(void);
        bool get_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr authenticationMechanism_Variable_;
        ServerVariable::SPtr clientCertificate_Variable_;
        ServerVariable::SPtr clientUserIdHistory_Variable_;
        ServerVariable::SPtr clientUserIdOfSession_Variable_;
        ServerVariable::SPtr encoding_Variable_;
        ServerVariable::SPtr securityMode_Variable_;
        ServerVariable::SPtr securityPolicyUri_Variable_;
        ServerVariable::SPtr sessionId_Variable_;
        ServerVariable::SPtr transportProtocol_Variable_;
        ServerVariable::SPtr variable_;
   
   };

}

#endif
