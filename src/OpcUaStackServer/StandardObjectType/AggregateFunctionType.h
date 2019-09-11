/*
    ObjectTypeClass: AggregateFunctionType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_AggregateFunctionType_h__
#define __OpcUaStackServer_AggregateFunctionType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT AggregateFunctionType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<AggregateFunctionType> SPtr;
       typedef std::vector<AggregateFunctionType::SPtr> Vec;
   
       AggregateFunctionType(void);
       AggregateFunctionType(const AggregateFunctionType& value);
       virtual ~AggregateFunctionType(void);
    
      private:
   
   };

}

#endif
