/*
    ObjectTypeClass: ConnectionTransportType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_ConnectionTransportType_h__
#define __OpcUaStackServer_ConnectionTransportType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT ConnectionTransportType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<ConnectionTransportType> SPtr;
       typedef std::vector<ConnectionTransportType::SPtr> Vec;
   
       ConnectionTransportType(void);
       ConnectionTransportType(const ConnectionTransportType& value);
       virtual ~ConnectionTransportType(void);
    
      private:
   
   };

}

#endif
