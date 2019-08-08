/*
    VariableTypeClass: DiscreteItemType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_DiscreteItemType_h__
#define __OpcUaStackServer_DiscreteItemType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT DiscreteItemType
   : public VariableBase
   {
     public:
       typedef boost::shared_ptr<DiscreteItemType> SPtr;
       typedef std::vector<DiscreteItemType::SPtr> Vec;
   
       DiscreteItemType(void);
       DiscreteItemType(const DiscreteItemType& value);
       virtual ~DiscreteItemType(void);

        //
        // String
        //
        void definition_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& definition_Variable(void);
        bool get_Definition_Variable(OpcUaDataValue& dataValue);
        bool set_Definition_Variable(const OpcUaDataValue& dataValue);

        //
        // Double
        //
        void valuePrecision_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& valuePrecision_Variable(void);
        bool get_ValuePrecision_Variable(OpcUaDataValue& dataValue);
        bool set_ValuePrecision_Variable(const OpcUaDataValue& dataValue);

        //
        // Variant
        //
        void variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& variable(void);
        bool get_Variable(OpcUaDataValue& dataValue);
        bool set_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr definition_Variable_;
        ServerVariable::SPtr valuePrecision_Variable_;
        ServerVariable::SPtr variable_;
   
   };

}

#endif
