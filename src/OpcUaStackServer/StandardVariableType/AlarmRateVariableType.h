/*
    VariableTypeClass: AlarmRateVariableType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_AlarmRateVariableType_h__
#define __OpcUaStackServer_AlarmRateVariableType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
   
   class DLLEXPORT AlarmRateVariableType
   : public VariableBase
   {
     public:
       typedef boost::shared_ptr<AlarmRateVariableType> SPtr;
       typedef std::vector<AlarmRateVariableType::SPtr> Vec;
   
       AlarmRateVariableType(void);
       AlarmRateVariableType(const AlarmRateVariableType& value);
       virtual ~AlarmRateVariableType(void);

        //
        // UInt16
        //
        void rate_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& rate_Variable(void);
        bool get_Rate_Variable(OpcUaDataValue& dataValue);
        bool set_Rate_Variable(const OpcUaDataValue& dataValue);

        //
        // Double (Array)
        //
        void variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& variable(void);
        bool get_Variable(OpcUaDataValue& dataValue);
        bool set_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr rate_Variable_;
        ServerVariable::SPtr variable_;
   
   };

}

#endif
