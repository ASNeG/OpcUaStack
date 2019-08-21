/*
    VariableTypeClass: BaseDataVariableType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_BaseDataVariableType_h__
#define __OpcUaStackServer_BaseDataVariableType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT BaseDataVariableType
   : public VariableBase
   {
     public:
       typedef boost::shared_ptr<BaseDataVariableType> SPtr;
       typedef std::vector<BaseDataVariableType::SPtr> Vec;
   
       BaseDataVariableType(void);
       BaseDataVariableType(const BaseDataVariableType& value);
       virtual ~BaseDataVariableType(void);

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
