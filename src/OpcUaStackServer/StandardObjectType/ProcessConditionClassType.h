/*
    ObjectTypeClass: ProcessConditionClassType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_ProcessConditionClassType_h__
#define __OpcUaStackServer_ProcessConditionClassType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT ProcessConditionClassType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<ProcessConditionClassType> SPtr;
       typedef std::vector<ProcessConditionClassType::SPtr> Vec;
   
       ProcessConditionClassType(void);
       ProcessConditionClassType(const ProcessConditionClassType& value);
       virtual ~ProcessConditionClassType(void);
    
      private:
   
   };

}

#endif
