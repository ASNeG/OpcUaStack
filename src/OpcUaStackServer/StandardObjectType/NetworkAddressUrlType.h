/*
    ObjectTypeClass: NetworkAddressUrlType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_NetworkAddressUrlType_h__
#define __OpcUaStackServer_NetworkAddressUrlType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT NetworkAddressUrlType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<NetworkAddressUrlType> SPtr;
       typedef std::vector<NetworkAddressUrlType::SPtr> Vec;
   
       NetworkAddressUrlType(void);
       NetworkAddressUrlType(const NetworkAddressUrlType& value);
       virtual ~NetworkAddressUrlType(void);

        //
        // String
        //
        void networkInterface_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& networkInterface_Variable(void);
        bool get_NetworkInterface_Variable(OpcUaDataValue& dataValue);
        bool set_NetworkInterface_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void url_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& url_Variable(void);
        bool get_Url_Variable(OpcUaDataValue& dataValue);
        bool set_Url_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr networkInterface_Variable_;
        ServerVariable::SPtr url_Variable_;
   
   };

}

#endif
