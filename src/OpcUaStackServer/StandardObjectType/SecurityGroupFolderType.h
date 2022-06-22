/*
    ObjectTypeClass: SecurityGroupFolderType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_SecurityGroupFolderType_h__
#define __OpcUaStackServer_SecurityGroupFolderType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT SecurityGroupFolderType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<SecurityGroupFolderType> SPtr;
       typedef std::vector<SecurityGroupFolderType::SPtr> Vec;
   
       SecurityGroupFolderType(void);
       SecurityGroupFolderType(const SecurityGroupFolderType& value);
       virtual ~SecurityGroupFolderType(void);

        virtual void call_AddSecurityGroup_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_RemoveSecurityGroup_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);
    
      private:
        ServerMethod::SPtr addSecurityGroup_Method_;
        ServerMethod::SPtr removeSecurityGroup_Method_;
   
   };

}

#endif
