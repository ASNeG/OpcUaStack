/*
    VariableTypeClass: BaseVariableType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_BaseVariableType_h__
#define __OpcUaStackServer_BaseVariableType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
   
   class DLLEXPORT BaseVariableType
   : public VariableBase
   {
     public:
       typedef boost::shared_ptr<BaseVariableType> SPtr;
       typedef std::vector<BaseVariableType::SPtr> Vec;
   
       BaseVariableType(void);
       BaseVariableType(const BaseVariableType& value);
       virtual ~BaseVariableType(void);

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
