/*
    ObjectTypeClass: AuditUrlMismatchEventType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_AuditUrlMismatchEventType_h__
#define __OpcUaStackServer_AuditUrlMismatchEventType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT AuditUrlMismatchEventType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<AuditUrlMismatchEventType> SPtr;
       typedef std::vector<AuditUrlMismatchEventType::SPtr> Vec;
   
       AuditUrlMismatchEventType(void);
       AuditUrlMismatchEventType(const AuditUrlMismatchEventType& value);
       virtual ~AuditUrlMismatchEventType(void);

        //
        // UtcTime
        //
        void actionTimeStamp_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& actionTimeStamp_Variable(void);
        bool get_ActionTimeStamp_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ActionTimeStamp_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String
        //
        void clientAuditEntryId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& clientAuditEntryId_Variable(void);
        bool get_ClientAuditEntryId_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ClientAuditEntryId_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String
        //
        void clientCertificateThumbprint_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& clientCertificateThumbprint_Variable(void);
        bool get_ClientCertificateThumbprint_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ClientCertificateThumbprint_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // ByteString
        //
        void clientCertificate_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& clientCertificate_Variable(void);
        bool get_ClientCertificate_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ClientCertificate_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String
        //
        void clientUserId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& clientUserId_Variable(void);
        bool get_ClientUserId_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ClientUserId_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String
        //
        void endpointUrl_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& endpointUrl_Variable(void);
        bool get_EndpointUrl_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_EndpointUrl_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // ByteString
        //
        void eventId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& eventId_Variable(void);
        bool get_EventId_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_EventId_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // NodeId
        //
        void eventType_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& eventType_Variable(void);
        bool get_EventType_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_EventType_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // TimeZoneDataType
        //
        void localTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& localTime_Variable(void);
        bool get_LocalTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LocalTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void message_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& message_Variable(void);
        bool get_Message_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Message_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void receiveTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& receiveTime_Variable(void);
        bool get_ReceiveTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ReceiveTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Duration
        //
        void revisedSessionTimeout_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& revisedSessionTimeout_Variable(void);
        bool get_RevisedSessionTimeout_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_RevisedSessionTimeout_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String
        //
        void secureChannelId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& secureChannelId_Variable(void);
        bool get_SecureChannelId_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SecureChannelId_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String
        //
        void serverId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverId_Variable(void);
        bool get_ServerId_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerId_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // NodeId
        //
        void sessionId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionId_Variable(void);
        bool get_SessionId_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SessionId_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt16
        //
        void severity_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& severity_Variable(void);
        bool get_Severity_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Severity_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String
        //
        void sourceName_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sourceName_Variable(void);
        bool get_SourceName_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SourceName_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // NodeId
        //
        void sourceNode_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sourceNode_Variable(void);
        bool get_SourceNode_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SourceNode_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Status
        //
        void statusCodeId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& statusCodeId_Variable(void);
        bool get_StatusCodeId_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_StatusCodeId_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void status_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& status_Variable(void);
        bool get_Status_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Status_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void time_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& time_Variable(void);
        bool get_Time_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Time_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr actionTimeStamp_Variable_;
        ServerVariable::SPtr clientAuditEntryId_Variable_;
        ServerVariable::SPtr clientCertificateThumbprint_Variable_;
        ServerVariable::SPtr clientCertificate_Variable_;
        ServerVariable::SPtr clientUserId_Variable_;
        ServerVariable::SPtr endpointUrl_Variable_;
        ServerVariable::SPtr eventId_Variable_;
        ServerVariable::SPtr eventType_Variable_;
        ServerVariable::SPtr localTime_Variable_;
        ServerVariable::SPtr message_Variable_;
        ServerVariable::SPtr receiveTime_Variable_;
        ServerVariable::SPtr revisedSessionTimeout_Variable_;
        ServerVariable::SPtr secureChannelId_Variable_;
        ServerVariable::SPtr serverId_Variable_;
        ServerVariable::SPtr sessionId_Variable_;
        ServerVariable::SPtr severity_Variable_;
        ServerVariable::SPtr sourceName_Variable_;
        ServerVariable::SPtr sourceNode_Variable_;
        ServerVariable::SPtr statusCodeId_Variable_;
        ServerVariable::SPtr status_Variable_;
        ServerVariable::SPtr time_Variable_;
   
   };

}

#endif
