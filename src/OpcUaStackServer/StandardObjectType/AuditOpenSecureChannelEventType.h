/*
    ObjectTypeClass: AuditOpenSecureChannelEventType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_AuditOpenSecureChannelEventType_h__
#define __OpcUaStackServer_AuditOpenSecureChannelEventType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT AuditOpenSecureChannelEventType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<AuditOpenSecureChannelEventType> SPtr;
       typedef std::vector<AuditOpenSecureChannelEventType::SPtr> Vec;
   
       AuditOpenSecureChannelEventType(void);
       AuditOpenSecureChannelEventType(const AuditOpenSecureChannelEventType& value);
       virtual ~AuditOpenSecureChannelEventType(void);

        //
        // UtcTime
        //
        void actionTimeStamp_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& actionTimeStamp_Variable(void);
        bool get_ActionTimeStamp_Variable(OpcUaDataValue& dataValue);
        bool set_ActionTimeStamp_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void clientAuditEntryId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& clientAuditEntryId_Variable(void);
        bool get_ClientAuditEntryId_Variable(OpcUaDataValue& dataValue);
        bool set_ClientAuditEntryId_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void clientCertificateThumbprint_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& clientCertificateThumbprint_Variable(void);
        bool get_ClientCertificateThumbprint_Variable(OpcUaDataValue& dataValue);
        bool set_ClientCertificateThumbprint_Variable(const OpcUaDataValue& dataValue);

        //
        // ByteString
        //
        void clientCertificate_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& clientCertificate_Variable(void);
        bool get_ClientCertificate_Variable(OpcUaDataValue& dataValue);
        bool set_ClientCertificate_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void clientUserId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& clientUserId_Variable(void);
        bool get_ClientUserId_Variable(OpcUaDataValue& dataValue);
        bool set_ClientUserId_Variable(const OpcUaDataValue& dataValue);

        //
        // ByteString
        //
        void eventId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& eventId_Variable(void);
        bool get_EventId_Variable(OpcUaDataValue& dataValue);
        bool set_EventId_Variable(const OpcUaDataValue& dataValue);

        //
        // NodeId
        //
        void eventType_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& eventType_Variable(void);
        bool get_EventType_Variable(OpcUaDataValue& dataValue);
        bool set_EventType_Variable(const OpcUaDataValue& dataValue);

        //
        // TimeZoneDataType
        //
        void localTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& localTime_Variable(void);
        bool get_LocalTime_Variable(OpcUaDataValue& dataValue);
        bool set_LocalTime_Variable(const OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void message_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& message_Variable(void);
        bool get_Message_Variable(OpcUaDataValue& dataValue);
        bool set_Message_Variable(const OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void receiveTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& receiveTime_Variable(void);
        bool get_ReceiveTime_Variable(OpcUaDataValue& dataValue);
        bool set_ReceiveTime_Variable(const OpcUaDataValue& dataValue);

        //
        // SecurityTokenRequestType
        //
        void requestType_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& requestType_Variable(void);
        bool get_RequestType_Variable(OpcUaDataValue& dataValue);
        bool set_RequestType_Variable(const OpcUaDataValue& dataValue);

        //
        // Duration
        //
        void requestedLifetime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& requestedLifetime_Variable(void);
        bool get_RequestedLifetime_Variable(OpcUaDataValue& dataValue);
        bool set_RequestedLifetime_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void secureChannelId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& secureChannelId_Variable(void);
        bool get_SecureChannelId_Variable(OpcUaDataValue& dataValue);
        bool set_SecureChannelId_Variable(const OpcUaDataValue& dataValue);

        //
        // MessageSecurityMode
        //
        void securityMode_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& securityMode_Variable(void);
        bool get_SecurityMode_Variable(OpcUaDataValue& dataValue);
        bool set_SecurityMode_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void securityPolicyUri_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& securityPolicyUri_Variable(void);
        bool get_SecurityPolicyUri_Variable(OpcUaDataValue& dataValue);
        bool set_SecurityPolicyUri_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void serverId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverId_Variable(void);
        bool get_ServerId_Variable(OpcUaDataValue& dataValue);
        bool set_ServerId_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt16
        //
        void severity_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& severity_Variable(void);
        bool get_Severity_Variable(OpcUaDataValue& dataValue);
        bool set_Severity_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void sourceName_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sourceName_Variable(void);
        bool get_SourceName_Variable(OpcUaDataValue& dataValue);
        bool set_SourceName_Variable(const OpcUaDataValue& dataValue);

        //
        // NodeId
        //
        void sourceNode_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sourceNode_Variable(void);
        bool get_SourceNode_Variable(OpcUaDataValue& dataValue);
        bool set_SourceNode_Variable(const OpcUaDataValue& dataValue);

        //
        // Status
        //
        void statusCodeId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& statusCodeId_Variable(void);
        bool get_StatusCodeId_Variable(OpcUaDataValue& dataValue);
        bool set_StatusCodeId_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void status_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& status_Variable(void);
        bool get_Status_Variable(OpcUaDataValue& dataValue);
        bool set_Status_Variable(const OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void time_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& time_Variable(void);
        bool get_Time_Variable(OpcUaDataValue& dataValue);
        bool set_Time_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr actionTimeStamp_Variable_;
        ServerVariable::SPtr clientAuditEntryId_Variable_;
        ServerVariable::SPtr clientCertificateThumbprint_Variable_;
        ServerVariable::SPtr clientCertificate_Variable_;
        ServerVariable::SPtr clientUserId_Variable_;
        ServerVariable::SPtr eventId_Variable_;
        ServerVariable::SPtr eventType_Variable_;
        ServerVariable::SPtr localTime_Variable_;
        ServerVariable::SPtr message_Variable_;
        ServerVariable::SPtr receiveTime_Variable_;
        ServerVariable::SPtr requestType_Variable_;
        ServerVariable::SPtr requestedLifetime_Variable_;
        ServerVariable::SPtr secureChannelId_Variable_;
        ServerVariable::SPtr securityMode_Variable_;
        ServerVariable::SPtr securityPolicyUri_Variable_;
        ServerVariable::SPtr serverId_Variable_;
        ServerVariable::SPtr severity_Variable_;
        ServerVariable::SPtr sourceName_Variable_;
        ServerVariable::SPtr sourceNode_Variable_;
        ServerVariable::SPtr statusCodeId_Variable_;
        ServerVariable::SPtr status_Variable_;
        ServerVariable::SPtr time_Variable_;
   
   };

}

#endif
