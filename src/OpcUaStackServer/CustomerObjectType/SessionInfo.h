/*
    ObjectTypeClass: SessionInfo

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_SessionInfo_h__
#define __OpcUaStackServer_SessionInfo_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT SessionInfo
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<SessionInfo> SPtr;
       typedef std::vector<SessionInfo::SPtr> Vec;
   
       SessionInfo(void);
       SessionInfo(const SessionInfo& value);
       virtual ~SessionInfo(void);

        //
        // String
        //
        void clientAddress_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& clientAddress_Variable(void);
        bool get_ClientAddress_Variable(OpcUaDataValue& dataValue);
        bool set_ClientAddress_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void endpointUrl_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& endpointUrl_Variable(void);
        bool get_EndpointUrl_Variable(OpcUaDataValue& dataValue);
        bool set_EndpointUrl_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void sessionId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionId_Variable(void);
        bool get_SessionId_Variable(OpcUaDataValue& dataValue);
        bool set_SessionId_Variable(const OpcUaDataValue& dataValue);

        //
        // SessionState
        //
        void sessionState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionState_Variable(void);
        bool get_SessionState_Variable(OpcUaDataValue& dataValue);
        bool set_SessionState_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void sessionTimeout_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionTimeout_Variable(void);
        bool get_SessionTimeout_Variable(OpcUaDataValue& dataValue);
        bool set_SessionTimeout_Variable(const OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void startTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& startTime_Variable(void);
        bool get_StartTime_Variable(OpcUaDataValue& dataValue);
        bool set_StartTime_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr clientAddress_Variable_;
        ServerVariable::SPtr endpointUrl_Variable_;
        ServerVariable::SPtr sessionId_Variable_;
        ServerVariable::SPtr sessionState_Variable_;
        ServerVariable::SPtr sessionTimeout_Variable_;
        ServerVariable::SPtr startTime_Variable_;
   
   };

}

#endif
