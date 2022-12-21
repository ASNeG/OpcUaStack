/*
    ObjectTypeClass: BrokerDataSetWriterTransportType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_BrokerDataSetWriterTransportType_h__
#define __OpcUaStackServer_BrokerDataSetWriterTransportType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT BrokerDataSetWriterTransportType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<BrokerDataSetWriterTransportType> SPtr;
       typedef std::vector<BrokerDataSetWriterTransportType::SPtr> Vec;
   
       BrokerDataSetWriterTransportType(void);
       BrokerDataSetWriterTransportType(const BrokerDataSetWriterTransportType& value);
       virtual ~BrokerDataSetWriterTransportType(void);

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
        void metaDataQueueName_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& metaDataQueueName_Variable(void);
        bool get_MetaDataQueueName_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_MetaDataQueueName_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Duration
        //
        void metaDataUpdateTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& metaDataUpdateTime_Variable(void);
        bool get_MetaDataUpdateTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_MetaDataUpdateTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

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
        ServerVariable::SPtr metaDataQueueName_Variable_;
        ServerVariable::SPtr metaDataUpdateTime_Variable_;
        ServerVariable::SPtr queueName_Variable_;
        ServerVariable::SPtr requestedDeliveryGuarantee_Variable_;
        ServerVariable::SPtr resourceUri_Variable_;
   
   };

}

#endif
