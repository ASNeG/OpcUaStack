/*
    ObjectTypeClass: BrokerWriterGroupTransportType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_BrokerWriterGroupTransportType_h__
#define __OpcUaStackServer_BrokerWriterGroupTransportType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT BrokerWriterGroupTransportType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<BrokerWriterGroupTransportType> SPtr;
       typedef std::vector<BrokerWriterGroupTransportType::SPtr> Vec;
   
       BrokerWriterGroupTransportType(void);
       BrokerWriterGroupTransportType(const BrokerWriterGroupTransportType& value);
       virtual ~BrokerWriterGroupTransportType(void);

        //
        // String
        //
        void authenticationProfileUri_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& authenticationProfileUri_Variable(void);
        bool get_AuthenticationProfileUri_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_AuthenticationProfileUri_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String
        //
        void queueName_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& queueName_Variable(void);
        bool get_QueueName_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_QueueName_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // BrokerTransportQualityOfService
        //
        void requestedDeliveryGuarantee_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& requestedDeliveryGuarantee_Variable(void);
        bool get_RequestedDeliveryGuarantee_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_RequestedDeliveryGuarantee_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String
        //
        void resourceUri_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& resourceUri_Variable(void);
        bool get_ResourceUri_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ResourceUri_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr authenticationProfileUri_Variable_;
        ServerVariable::SPtr queueName_Variable_;
        ServerVariable::SPtr requestedDeliveryGuarantee_Variable_;
        ServerVariable::SPtr resourceUri_Variable_;
   
   };

}

#endif
