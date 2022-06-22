/*
    ObjectTypeClass: RoleSetType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_RoleSetType_h__
#define __OpcUaStackServer_RoleSetType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT RoleSetType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<RoleSetType> SPtr;
       typedef std::vector<RoleSetType::SPtr> Vec;
   
       RoleSetType(void);
       RoleSetType(const RoleSetType& value);
       virtual ~RoleSetType(void);

        virtual void call_AddRole_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_RemoveRole_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);
    
      private:
        ServerMethod::SPtr addRole_Method_;
        ServerMethod::SPtr removeRole_Method_;
   
   };

}

#endif
