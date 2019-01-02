/*
    VariableTypeClass: AnalogItemType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_AnalogItemType_h__
#define __OpcUaStackServer_AnalogItemType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackServer/VariableType/VariableBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT AnalogItemType
   : public VariableBase
   {
     public:
       typedef boost::shared_ptr<AnalogItemType> SPtr;
       typedef std::vector<AnalogItemType::SPtr> Vec;
   
       AnalogItemType(void);
       AnalogItemType(const AnalogItemType& value);
       virtual ~AnalogItemType(void);
    
      private:
        ServerVariable::SPtr definition_Variable_;
        ServerVariable::SPtr eURange_Variable_;
        ServerVariable::SPtr engineeringUnits_Variable_;
        ServerVariable::SPtr instrumentRange_Variable_;
        ServerVariable::SPtr valuePrecision_Variable_;
        ServerVariable::SPtr variable_;
   
   };

}

#endif
