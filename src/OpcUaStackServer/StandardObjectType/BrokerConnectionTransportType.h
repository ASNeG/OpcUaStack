/*
    ObjectTypeClass: BrokerConnectionTransportType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_BrokerConnectionTransportType_h__
#define __OpcUaStackServer_BrokerConnectionTransportType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT BrokerConnectionTransportType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<BrokerConnectionTransportType> SPtr;
       typedef std::vector<BrokerConnectionTransportType::SPtr> Vec;
   
       BrokerConnectionTransportType(void);
       BrokerConnectionTransportType(const BrokerConnectionTransportType& value);
       virtual ~BrokerConnectionTransportType(void);

        //
        // String
        //
        void authenticationProfileUri_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& authenticationProfileUri_Variable(void);
        bool get_AuthenticationProfileUri_Variable(OpcUaDataValue& dataValue);
        bool set_AuthenticationProfileUri_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void resourceUri_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& resourceUri_Variable(void);
        bool get_ResourceUri_Variable(OpcUaDataValue& dataValue);
        bool set_ResourceUri_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr authenticationProfileUri_Variable_;
        ServerVariable::SPtr resourceUri_Variable_;
   
   };

}

#endif
