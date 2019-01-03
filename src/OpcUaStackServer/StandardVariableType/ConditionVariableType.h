/*
    VariableTypeClass: ConditionVariableType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_ConditionVariableType_h__
#define __OpcUaStackServer_ConditionVariableType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackServer/VariableType/VariableBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT ConditionVariableType
   : public VariableBase
   {
     public:
       typedef boost::shared_ptr<ConditionVariableType> SPtr;
       typedef std::vector<ConditionVariableType::SPtr> Vec;
   
       ConditionVariableType(void);
       ConditionVariableType(const ConditionVariableType& value);
       virtual ~ConditionVariableType(void);

        void sourceTimestamp_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sourceTimestamp_Variable(void);
        bool get_SourceTimestamp_Variable(OpcUaDataValue& dataValue);
        bool set_SourceTimestamp_Variable(const OpcUaDataValue& dataValue);

        void variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& variable(void);
        bool get_Variable(OpcUaDataValue& dataValue);
        bool set_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr sourceTimestamp_Variable_;
        ServerVariable::SPtr variable_;
   
   };

}

#endif
