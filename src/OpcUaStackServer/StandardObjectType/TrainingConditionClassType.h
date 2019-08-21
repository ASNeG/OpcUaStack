/*
    ObjectTypeClass: TrainingConditionClassType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_TrainingConditionClassType_h__
#define __OpcUaStackServer_TrainingConditionClassType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT TrainingConditionClassType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<TrainingConditionClassType> SPtr;
       typedef std::vector<TrainingConditionClassType::SPtr> Vec;
   
       TrainingConditionClassType(void);
       TrainingConditionClassType(const TrainingConditionClassType& value);
       virtual ~TrainingConditionClassType(void);
    
      private:
   
   };

}

#endif
