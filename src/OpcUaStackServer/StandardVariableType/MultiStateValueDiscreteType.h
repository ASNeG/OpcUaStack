/*
    VariableTypeClass: MultiStateValueDiscreteType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_MultiStateValueDiscreteType_h__
#define __OpcUaStackServer_MultiStateValueDiscreteType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT MultiStateValueDiscreteType
   : public VariableBase
   {
     public:
       typedef boost::shared_ptr<MultiStateValueDiscreteType> SPtr;
       typedef std::vector<MultiStateValueDiscreteType::SPtr> Vec;
   
       MultiStateValueDiscreteType(void);
       MultiStateValueDiscreteType(const MultiStateValueDiscreteType& value);
       virtual ~MultiStateValueDiscreteType(void);

        //
        // String
        //
        void definition_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& definition_Variable(void);
        bool get_Definition_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Definition_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // EnumValueType (Array)
        //
        void enumValues_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& enumValues_Variable(void);
        bool get_EnumValues_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_EnumValues_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void valueAsText_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& valueAsText_Variable(void);
        bool get_ValueAsText_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ValueAsText_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

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
        ServerVariable::SPtr enumValues_Variable_;
        ServerVariable::SPtr valueAsText_Variable_;
        ServerVariable::SPtr valuePrecision_Variable_;
        ServerVariable::SPtr variable_;
   
   };

}

#endif
