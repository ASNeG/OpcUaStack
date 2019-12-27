/*
    DataTypeClass: SubscriptionDiagnosticsDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_SubscriptionDiagnosticsDataType_h__
#define __OpcUaStackCore_SubscriptionDiagnosticsDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT SubscriptionDiagnosticsDataType
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<SubscriptionDiagnosticsDataType> SPtr;
        typedef std::vector<SubscriptionDiagnosticsDataType::SPtr> Vec;
    
        SubscriptionDiagnosticsDataType(void);
        SubscriptionDiagnosticsDataType(const SubscriptionDiagnosticsDataType& value);
        virtual ~SubscriptionDiagnosticsDataType(void);
        
        OpcUaNodeId& sessionId(void);
        OpcUaUInt32& subscriptionId(void);
        OpcUaByte& priority(void);
        OpcUaDouble& publishingInterval(void);
        OpcUaUInt32& maxKeepAliveCount(void);
        OpcUaUInt32& maxLifetimeCount(void);
        OpcUaUInt32& maxNotificationsPerPublish(void);
        OpcUaBoolean& publishingEnabled(void);
        OpcUaUInt32& modifyCount(void);
        OpcUaUInt32& enableCount(void);
        OpcUaUInt32& disableCount(void);
        OpcUaUInt32& republishRequestCount(void);
        OpcUaUInt32& republishMessageRequestCount(void);
        OpcUaUInt32& republishMessageCount(void);
        OpcUaUInt32& transferRequestCount(void);
        OpcUaUInt32& transferredToAltClientCount(void);
        OpcUaUInt32& transferredToSameClientCount(void);
        OpcUaUInt32& publishRequestCount(void);
        OpcUaUInt32& dataChangeNotificationsCount(void);
        OpcUaUInt32& eventNotificationsCount(void);
        OpcUaUInt32& notificationsCount(void);
        OpcUaUInt32& latePublishRequestCount(void);
        OpcUaUInt32& currentKeepAliveCount(void);
        OpcUaUInt32& currentLifetimeCount(void);
        OpcUaUInt32& unacknowledgedMessageCount(void);
        OpcUaUInt32& discardedMessageCount(void);
        OpcUaUInt32& monitoredItemCount(void);
        OpcUaUInt32& disabledMonitoredItemCount(void);
        OpcUaUInt32& monitoringQueueOverflowCount(void);
        OpcUaUInt32& nextSequenceNumber(void);
        OpcUaUInt32& eventQueueOverFlowCount(void);
        
        //- ExtensionObjectBase -----------------------------------------------
        virtual ExtensionObjectBase::SPtr factory(void) override;
        virtual std::string namespaceName(void) override;
        virtual std::string typeName(void) override;
        virtual OpcUaNodeId typeId(void) override;
        virtual OpcUaNodeId binaryTypeId(void) override;
        virtual OpcUaNodeId xmlTypeId(void) override;
        virtual OpcUaNodeId jsonTypeId(void) override;
        virtual bool opcUaBinaryEncode(std::ostream& os) const override;
        virtual bool opcUaBinaryDecode(std::istream& is) override;
        virtual bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) override;
        virtual bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns) override;
        virtual bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) override;
        virtual bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns) override;
        virtual void copyTo(ExtensionObjectBase& extensionObjectBase) override;
        virtual bool equal(ExtensionObjectBase& extensionObjectBase) const override;
        virtual void out(std::ostream& os) override;
        //- ExtensionObjectBase -----------------------------------------------
        
        virtual bool jsonEncodeImpl(boost::property_tree::ptree& pt) const override;
        virtual bool jsonDecodeImpl(const boost::property_tree::ptree& pt) override;
        
        void copyTo(SubscriptionDiagnosticsDataType& value);
        bool operator==(const SubscriptionDiagnosticsDataType& value);
        bool operator!=(const SubscriptionDiagnosticsDataType& value);
        SubscriptionDiagnosticsDataType& operator=(const SubscriptionDiagnosticsDataType& value);
    
      private:
        OpcUaNodeId sessionId_;
        OpcUaUInt32 subscriptionId_;
        OpcUaByte priority_;
        OpcUaDouble publishingInterval_;
        OpcUaUInt32 maxKeepAliveCount_;
        OpcUaUInt32 maxLifetimeCount_;
        OpcUaUInt32 maxNotificationsPerPublish_;
        OpcUaBoolean publishingEnabled_;
        OpcUaUInt32 modifyCount_;
        OpcUaUInt32 enableCount_;
        OpcUaUInt32 disableCount_;
        OpcUaUInt32 republishRequestCount_;
        OpcUaUInt32 republishMessageRequestCount_;
        OpcUaUInt32 republishMessageCount_;
        OpcUaUInt32 transferRequestCount_;
        OpcUaUInt32 transferredToAltClientCount_;
        OpcUaUInt32 transferredToSameClientCount_;
        OpcUaUInt32 publishRequestCount_;
        OpcUaUInt32 dataChangeNotificationsCount_;
        OpcUaUInt32 eventNotificationsCount_;
        OpcUaUInt32 notificationsCount_;
        OpcUaUInt32 latePublishRequestCount_;
        OpcUaUInt32 currentKeepAliveCount_;
        OpcUaUInt32 currentLifetimeCount_;
        OpcUaUInt32 unacknowledgedMessageCount_;
        OpcUaUInt32 discardedMessageCount_;
        OpcUaUInt32 monitoredItemCount_;
        OpcUaUInt32 disabledMonitoredItemCount_;
        OpcUaUInt32 monitoringQueueOverflowCount_;
        OpcUaUInt32 nextSequenceNumber_;
        OpcUaUInt32 eventQueueOverFlowCount_;
    
    };
    
    class DLLEXPORT SubscriptionDiagnosticsDataTypeArray
    : public OpcUaArray<SubscriptionDiagnosticsDataType::SPtr, SPtrTypeCoder<SubscriptionDiagnosticsDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<SubscriptionDiagnosticsDataTypeArray> SPtr;
    };

}

#endif
