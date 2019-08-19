/*
    VariableTypeClass: ServerVendorCapabilityType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_ServerVendorCapabilityType_h__
#define __OpcUaStackServer_ServerVendorCapabilityType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
   
   class DLLEXPORT ServerVendorCapabilityType
   : public VariableBase
   {
     public:
       typedef boost::shared_ptr<ServerVendorCapabilityType> SPtr;
       typedef std::vector<ServerVendorCapabilityType::SPtr> Vec;
   
       ServerVendorCapabilityType(void);
       ServerVendorCapabilityType(const ServerVendorCapabilityType& value);
       virtual ~ServerVendorCapabilityType(void);

        //
        // Variant (Array)
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
