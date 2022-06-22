/*
    VariableTypeClass: ConditionVariableType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_ConditionVariableType_h__
#define __OpcUaStackServer_ConditionVariableType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"

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

        //
        // UtcTime
        //
        void sourceTimestamp_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sourceTimestamp_Variable(void);
        bool get_SourceTimestamp_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SourceTimestamp_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Variant
        //
        void variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& variable(void);
        bool get_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr sourceTimestamp_Variable_;
        ServerVariable::SPtr variable_;
   
   };

}

#endif
