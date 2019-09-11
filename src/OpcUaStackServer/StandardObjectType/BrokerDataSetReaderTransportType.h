/*
    ObjectTypeClass: BrokerDataSetReaderTransportType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_BrokerDataSetReaderTransportType_h__
#define __OpcUaStackServer_BrokerDataSetReaderTransportType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT BrokerDataSetReaderTransportType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<BrokerDataSetReaderTransportType> SPtr;
       typedef std::vector<BrokerDataSetReaderTransportType::SPtr> Vec;
   
       BrokerDataSetReaderTransportType(void);
       BrokerDataSetReaderTransportType(const BrokerDataSetReaderTransportType& value);
       virtual ~BrokerDataSetReaderTransportType(void);

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
        void metaDataQueueName_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& metaDataQueueName_Variable(void);
        bool get_MetaDataQueueName_Variable(OpcUaDataValue& dataValue);
        bool set_MetaDataQueueName_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void queueName_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& queueName_Variable(void);
        bool get_QueueName_Variable(OpcUaDataValue& dataValue);
        bool set_QueueName_Variable(const OpcUaDataValue& dataValue);

        //
        // BrokerTransportQualityOfService
        //
        void requestedDeliveryGuarantee_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& requestedDeliveryGuarantee_Variable(void);
        bool get_RequestedDeliveryGuarantee_Variable(OpcUaDataValue& dataValue);
        bool set_RequestedDeliveryGuarantee_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void resourceUri_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& resourceUri_Variable(void);
        bool get_ResourceUri_Variable(OpcUaDataValue& dataValue);
        bool set_ResourceUri_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr authenticationProfileUri_Variable_;
        ServerVariable::SPtr metaDataQueueName_Variable_;
        ServerVariable::SPtr queueName_Variable_;
        ServerVariable::SPtr requestedDeliveryGuarantee_Variable_;
        ServerVariable::SPtr resourceUri_Variable_;
   
   };

}

#endif
