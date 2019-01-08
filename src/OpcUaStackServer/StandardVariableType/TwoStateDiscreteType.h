/*
    VariableTypeClass: TwoStateDiscreteType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_TwoStateDiscreteType_h__
#define __OpcUaStackServer_TwoStateDiscreteType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT TwoStateDiscreteType
   : public VariableBase
   {
     public:
       typedef boost::shared_ptr<TwoStateDiscreteType> SPtr;
       typedef std::vector<TwoStateDiscreteType::SPtr> Vec;
   
       TwoStateDiscreteType(void);
       TwoStateDiscreteType(const TwoStateDiscreteType& value);
       virtual ~TwoStateDiscreteType(void);

        //
        // String
        //
        void definition_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& definition_Variable(void);
        bool get_Definition_Variable(OpcUaDataValue& dataValue);
        bool set_Definition_Variable(const OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void falseState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& falseState_Variable(void);
        bool get_FalseState_Variable(OpcUaDataValue& dataValue);
        bool set_FalseState_Variable(const OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void trueState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& trueState_Variable(void);
        bool get_TrueState_Variable(OpcUaDataValue& dataValue);
        bool set_TrueState_Variable(const OpcUaDataValue& dataValue);

        //
        // Double
        //
        void valuePrecision_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& valuePrecision_Variable(void);
        bool get_ValuePrecision_Variable(OpcUaDataValue& dataValue);
        bool set_ValuePrecision_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& variable(void);
        bool get_Variable(OpcUaDataValue& dataValue);
        bool set_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr definition_Variable_;
        ServerVariable::SPtr falseState_Variable_;
        ServerVariable::SPtr trueState_Variable_;
        ServerVariable::SPtr valuePrecision_Variable_;
        ServerVariable::SPtr variable_;
   
   };

}

#endif
