/*
    VariableTypeClass: NDimensionArrayItemType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_NDimensionArrayItemType_h__
#define __OpcUaStackServer_NDimensionArrayItemType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT NDimensionArrayItemType
   : public VariableBase
   {
     public:
       typedef boost::shared_ptr<NDimensionArrayItemType> SPtr;
       typedef std::vector<NDimensionArrayItemType::SPtr> Vec;
   
       NDimensionArrayItemType(void);
       NDimensionArrayItemType(const NDimensionArrayItemType& value);
       virtual ~NDimensionArrayItemType(void);

        //
        // AxisInformation (Array)
        //
        void axisDefinition_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& axisDefinition_Variable(void);
        bool get_AxisDefinition_Variable(OpcUaDataValue& dataValue);
        bool set_AxisDefinition_Variable(const OpcUaDataValue& dataValue);

        //
        // AxisScaleEnumeration
        //
        void axisScaleType_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& axisScaleType_Variable(void);
        bool get_AxisScaleType_Variable(OpcUaDataValue& dataValue);
        bool set_AxisScaleType_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void definition_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& definition_Variable(void);
        bool get_Definition_Variable(OpcUaDataValue& dataValue);
        bool set_Definition_Variable(const OpcUaDataValue& dataValue);

        //
        // Range
        //
        void eURange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& eURange_Variable(void);
        bool get_EURange_Variable(OpcUaDataValue& dataValue);
        bool set_EURange_Variable(const OpcUaDataValue& dataValue);

        //
        // EUInformation
        //
        void engineeringUnits_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& engineeringUnits_Variable(void);
        bool get_EngineeringUnits_Variable(OpcUaDataValue& dataValue);
        bool set_EngineeringUnits_Variable(const OpcUaDataValue& dataValue);

        //
        // Range
        //
        void instrumentRange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& instrumentRange_Variable(void);
        bool get_InstrumentRange_Variable(OpcUaDataValue& dataValue);
        bool set_InstrumentRange_Variable(const OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void title_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& title_Variable(void);
        bool get_Title_Variable(OpcUaDataValue& dataValue);
        bool set_Title_Variable(const OpcUaDataValue& dataValue);

        //
        // Double
        //
        void valuePrecision_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& valuePrecision_Variable(void);
        bool get_ValuePrecision_Variable(OpcUaDataValue& dataValue);
        bool set_ValuePrecision_Variable(const OpcUaDataValue& dataValue);

        //
        // Variant (Array)
        //
        void variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& variable(void);
        bool get_Variable(OpcUaDataValue& dataValue);
        bool set_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr axisDefinition_Variable_;
        ServerVariable::SPtr axisScaleType_Variable_;
        ServerVariable::SPtr definition_Variable_;
        ServerVariable::SPtr eURange_Variable_;
        ServerVariable::SPtr engineeringUnits_Variable_;
        ServerVariable::SPtr instrumentRange_Variable_;
        ServerVariable::SPtr title_Variable_;
        ServerVariable::SPtr valuePrecision_Variable_;
        ServerVariable::SPtr variable_;
   
   };

}

#endif
