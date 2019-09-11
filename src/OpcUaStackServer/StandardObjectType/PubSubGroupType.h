/*
    ObjectTypeClass: PubSubGroupType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_PubSubGroupType_h__
#define __OpcUaStackServer_PubSubGroupType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT PubSubGroupType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<PubSubGroupType> SPtr;
       typedef std::vector<PubSubGroupType::SPtr> Vec;
   
       PubSubGroupType(void);
       PubSubGroupType(const PubSubGroupType& value);
       virtual ~PubSubGroupType(void);

        //
        // KeyValuePair (Array)
        //
        void groupProperties_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& groupProperties_Variable(void);
        bool get_GroupProperties_Variable(OpcUaDataValue& dataValue);
        bool set_GroupProperties_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void maxNetworkMessageSize_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& maxNetworkMessageSize_Variable(void);
        bool get_MaxNetworkMessageSize_Variable(OpcUaDataValue& dataValue);
        bool set_MaxNetworkMessageSize_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void securityGroupId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& securityGroupId_Variable(void);
        bool get_SecurityGroupId_Variable(OpcUaDataValue& dataValue);
        bool set_SecurityGroupId_Variable(const OpcUaDataValue& dataValue);

        //
        // EndpointDescription (Array)
        //
        void securityKeyServices_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& securityKeyServices_Variable(void);
        bool get_SecurityKeyServices_Variable(OpcUaDataValue& dataValue);
        bool set_SecurityKeyServices_Variable(const OpcUaDataValue& dataValue);

        //
        // MessageSecurityMode
        //
        void securityMode_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& securityMode_Variable(void);
        bool get_SecurityMode_Variable(OpcUaDataValue& dataValue);
        bool set_SecurityMode_Variable(const OpcUaDataValue& dataValue);

        //
        // PubSubState
        //
        void status_State_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& status_State_Variable(void);
        bool get_Status_State_Variable(OpcUaDataValue& dataValue);
        bool set_Status_State_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr groupProperties_Variable_;
        ServerVariable::SPtr maxNetworkMessageSize_Variable_;
        ServerVariable::SPtr securityGroupId_Variable_;
        ServerVariable::SPtr securityKeyServices_Variable_;
        ServerVariable::SPtr securityMode_Variable_;
        ServerVariable::SPtr status_State_Variable_;
   
   };

}

#endif
