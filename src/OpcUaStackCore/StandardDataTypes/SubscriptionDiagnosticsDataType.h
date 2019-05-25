/*
    DataTypeClass: SubscriptionDiagnosticsDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_SubscriptionDiagnosticsDataType_h__
#define __OpcUaStackCore_SubscriptionDiagnosticsDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonFormatter.h"

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
        virtual ExtensionObjectBase::SPtr factory(void);
        virtual std::string namespaceName(void);
        virtual std::string typeName(void);
        virtual OpcUaNodeId typeId(void);
        virtual OpcUaNodeId binaryTypeId(void);
        virtual OpcUaNodeId xmlTypeId(void);
        virtual OpcUaNodeId jsonTypeId(void);
        virtual void opcUaBinaryEncode(std::ostream& os) const;
        virtual void opcUaBinaryDecode(std::istream& is);
        virtual bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
        virtual bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
        virtual bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual bool jsonEncode(boost::property_tree::ptree& pt, const std::string& element);
        virtual bool jsonEncode(boost::property_tree::ptree& pt);
        virtual bool jsonDecode(boost::property_tree::ptree& pt, const std::string& element);
        virtual bool jsonDecode(boost::property_tree::ptree& pt);
        virtual void copyTo(ExtensionObjectBase& extensionObjectBase);
        virtual bool equal(ExtensionObjectBase& extensionObjectBase) const;
        virtual void out(std::ostream& os);
        //- ExtensionObjectBase -----------------------------------------------
        
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
