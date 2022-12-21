/*
    VariableTypeClass: XYArrayItemType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_XYArrayItemType_h__
#define __OpcUaStackServer_XYArrayItemType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT XYArrayItemType
   : public VariableBase
   {
     public:
       typedef boost::shared_ptr<XYArrayItemType> SPtr;
       typedef std::vector<XYArrayItemType::SPtr> Vec;
   
       XYArrayItemType(void);
       XYArrayItemType(const XYArrayItemType& value);
       virtual ~XYArrayItemType(void);

        //
        // AxisScaleEnumeration
        //
        void axisScaleType_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& axisScaleType_Variable(void);
        bool get_AxisScaleType_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_AxisScaleType_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

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
        // LocalizedText
        //
        void title_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& title_Variable(void);
        bool get_Title_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Title_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Double
        //
        void valuePrecision_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& valuePrecision_Variable(void);
        bool get_ValuePrecision_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ValuePrecision_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // XVType (Array)
        //
        void variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& variable(void);
        bool get_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // AxisInformation
        //
        void xAxisDefinition_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& xAxisDefinition_Variable(void);
        bool get_XAxisDefinition_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_XAxisDefinition_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr axisScaleType_Variable_;
        ServerVariable::SPtr definition_Variable_;
        ServerVariable::SPtr eURange_Variable_;
        ServerVariable::SPtr engineeringUnits_Variable_;
        ServerVariable::SPtr instrumentRange_Variable_;
        ServerVariable::SPtr title_Variable_;
        ServerVariable::SPtr valuePrecision_Variable_;
        ServerVariable::SPtr variable_;
        ServerVariable::SPtr xAxisDefinition_Variable_;
   
   };

}

#endif
