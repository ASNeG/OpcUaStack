/*
    ObjectTypeClass: TestingConditionClassType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_TestingConditionClassType_h__
#define __OpcUaStackServer_TestingConditionClassType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT TestingConditionClassType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<TestingConditionClassType> SPtr;
       typedef std::vector<TestingConditionClassType::SPtr> Vec;
   
       TestingConditionClassType(void);
       TestingConditionClassType(const TestingConditionClassType& value);
       virtual ~TestingConditionClassType(void);
    
      private:
   
   };

}

#endif
