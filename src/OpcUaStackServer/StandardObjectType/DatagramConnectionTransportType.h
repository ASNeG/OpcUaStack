/*
    ObjectTypeClass: DatagramConnectionTransportType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_DatagramConnectionTransportType_h__
#define __OpcUaStackServer_DatagramConnectionTransportType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT DatagramConnectionTransportType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<DatagramConnectionTransportType> SPtr;
       typedef std::vector<DatagramConnectionTransportType::SPtr> Vec;
   
       DatagramConnectionTransportType(void);
       DatagramConnectionTransportType(const DatagramConnectionTransportType& value);
       virtual ~DatagramConnectionTransportType(void);

        //
        // String
        //
        void discoveryAddress_NetworkInterface_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& discoveryAddress_NetworkInterface_Variable(void);
        bool get_DiscoveryAddress_NetworkInterface_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_DiscoveryAddress_NetworkInterface_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr discoveryAddress_NetworkInterface_Variable_;
   
   };

}

#endif
