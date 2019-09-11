/*
    VariableTypeClass: PropertyType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_PropertyType_h__
#define __OpcUaStackServer_PropertyType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT PropertyType
   : public VariableBase
   {
     public:
       typedef boost::shared_ptr<PropertyType> SPtr;
       typedef std::vector<PropertyType::SPtr> Vec;
   
       PropertyType(void);
       PropertyType(const PropertyType& value);
       virtual ~PropertyType(void);

        //
        // Variant
        //
        void variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& variable(void);
        bool get_Variable(OpcUaDataValue& dataValue);
        bool set_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr variable_;
   
   };

}

#endif
