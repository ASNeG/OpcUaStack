/*
    ObjectTypeClass: SystemConditionClassType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_SystemConditionClassType_h__
#define __OpcUaStackServer_SystemConditionClassType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT SystemConditionClassType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<SystemConditionClassType> SPtr;
       typedef std::vector<SystemConditionClassType::SPtr> Vec;
   
       SystemConditionClassType(void);
       SystemConditionClassType(const SystemConditionClassType& value);
       virtual ~SystemConditionClassType(void);
    
      private:
   
   };

}

#endif
