/*
    ObjectTypeClass: NetworkAddressType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_NetworkAddressType_h__
#define __OpcUaStackServer_NetworkAddressType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT NetworkAddressType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<NetworkAddressType> SPtr;
       typedef std::vector<NetworkAddressType::SPtr> Vec;
   
       NetworkAddressType(void);
       NetworkAddressType(const NetworkAddressType& value);
       virtual ~NetworkAddressType(void);

        //
        // String
        //
        void networkInterface_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& networkInterface_Variable(void);
        bool get_NetworkInterface_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_NetworkInterface_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr networkInterface_Variable_;
   
   };

}

#endif
