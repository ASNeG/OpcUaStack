/*
    ObjectTypeClass: PubSubKeyServiceType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_PubSubKeyServiceType_h__
#define __OpcUaStackServer_PubSubKeyServiceType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT PubSubKeyServiceType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<PubSubKeyServiceType> SPtr;
       typedef std::vector<PubSubKeyServiceType::SPtr> Vec;
   
       PubSubKeyServiceType(void);
       PubSubKeyServiceType(const PubSubKeyServiceType& value);
       virtual ~PubSubKeyServiceType(void);

        virtual void call_GetSecurityGroup_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_GetSecurityKeys_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_SecurityGroups_AddSecurityGroup_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_SecurityGroups_RemoveSecurityGroup_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);
    
      private:
        ServerMethod::SPtr getSecurityGroup_Method_;
        ServerMethod::SPtr getSecurityKeys_Method_;
        ServerMethod::SPtr securityGroups_AddSecurityGroup_Method_;
        ServerMethod::SPtr securityGroups_RemoveSecurityGroup_Method_;
   
   };

}

#endif
