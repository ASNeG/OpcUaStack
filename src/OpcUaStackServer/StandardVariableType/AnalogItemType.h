/*
    VariableTypeClass: AnalogItemType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_AnalogItemType_h__
#define __OpcUaStackServer_AnalogItemType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"

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

        //
        // String
        //
        void definition_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& definition_Variable(void);
        bool get_Definition_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Definition_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Range
        //
        void eURange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& eURange_Variable(void);
        bool get_EURange_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_EURange_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // EUInformation
        //
        void engineeringUnits_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& engineeringUnits_Variable(void);
        bool get_EngineeringUnits_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_EngineeringUnits_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Range
        //
        void instrumentRange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& instrumentRange_Variable(void);
        bool get_InstrumentRange_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_InstrumentRange_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Double
        //
        void valuePrecision_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& valuePrecision_Variable(void);
        bool get_ValuePrecision_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ValuePrecision_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Number
        //
        void variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& variable(void);
        bool get_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);
    
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
