/*
    ObjectTypeClass: StatisticalConditionClassType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_StatisticalConditionClassType_h__
#define __OpcUaStackServer_StatisticalConditionClassType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT StatisticalConditionClassType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<StatisticalConditionClassType> SPtr;
       typedef std::vector<StatisticalConditionClassType::SPtr> Vec;
   
       StatisticalConditionClassType(void);
       StatisticalConditionClassType(const StatisticalConditionClassType& value);
       virtual ~StatisticalConditionClassType(void);
    
      private:
   
   };

}

#endif
