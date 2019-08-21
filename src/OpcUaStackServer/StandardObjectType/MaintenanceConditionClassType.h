/*
    ObjectTypeClass: MaintenanceConditionClassType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_MaintenanceConditionClassType_h__
#define __OpcUaStackServer_MaintenanceConditionClassType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT MaintenanceConditionClassType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<MaintenanceConditionClassType> SPtr;
       typedef std::vector<MaintenanceConditionClassType::SPtr> Vec;
   
       MaintenanceConditionClassType(void);
       MaintenanceConditionClassType(const MaintenanceConditionClassType& value);
       virtual ~MaintenanceConditionClassType(void);
    
      private:
   
   };

}

#endif
