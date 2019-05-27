/*
    DataTypeClass: SubscriptionDiagnosticsDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/SubscriptionDiagnosticsDataType.h"

namespace OpcUaStackCore
{
    
    SubscriptionDiagnosticsDataType::SubscriptionDiagnosticsDataType(void)
    : Object()
    , ExtensionObjectBase()
    , sessionId_()
    , subscriptionId_()
    , priority_()
    , publishingInterval_()
    , maxKeepAliveCount_()
    , maxLifetimeCount_()
    , maxNotificationsPerPublish_()
    , publishingEnabled_()
    , modifyCount_()
    , enableCount_()
    , disableCount_()
    , republishRequestCount_()
    , republishMessageRequestCount_()
    , republishMessageCount_()
    , transferRequestCount_()
    , transferredToAltClientCount_()
    , transferredToSameClientCount_()
    , publishRequestCount_()
    , dataChangeNotificationsCount_()
    , eventNotificationsCount_()
    , notificationsCount_()
    , latePublishRequestCount_()
    , currentKeepAliveCount_()
    , currentLifetimeCount_()
    , unacknowledgedMessageCount_()
    , discardedMessageCount_()
    , monitoredItemCount_()
    , disabledMonitoredItemCount_()
    , monitoringQueueOverflowCount_()
    , nextSequenceNumber_()
    , eventQueueOverFlowCount_()
    {
    }
    
    SubscriptionDiagnosticsDataType::SubscriptionDiagnosticsDataType(const SubscriptionDiagnosticsDataType& value)
    : Object()
    , ExtensionObjectBase()
    , sessionId_()
    , subscriptionId_()
    , priority_()
    , publishingInterval_()
    , maxKeepAliveCount_()
    , maxLifetimeCount_()
    , maxNotificationsPerPublish_()
    , publishingEnabled_()
    , modifyCount_()
    , enableCount_()
    , disableCount_()
    , republishRequestCount_()
    , republishMessageRequestCount_()
    , republishMessageCount_()
    , transferRequestCount_()
    , transferredToAltClientCount_()
    , transferredToSameClientCount_()
    , publishRequestCount_()
    , dataChangeNotificationsCount_()
    , eventNotificationsCount_()
    , notificationsCount_()
    , latePublishRequestCount_()
    , currentKeepAliveCount_()
    , currentLifetimeCount_()
    , unacknowledgedMessageCount_()
    , discardedMessageCount_()
    , monitoredItemCount_()
    , disabledMonitoredItemCount_()
    , monitoringQueueOverflowCount_()
    , nextSequenceNumber_()
    , eventQueueOverFlowCount_()
    {
        const_cast<SubscriptionDiagnosticsDataType*>(&value)->copyTo(*this);
    }
    
    SubscriptionDiagnosticsDataType::~SubscriptionDiagnosticsDataType(void)
    {
    }
    
    OpcUaNodeId&
    SubscriptionDiagnosticsDataType::sessionId(void)
    {
        return sessionId_;
    }
    
    OpcUaUInt32&
    SubscriptionDiagnosticsDataType::subscriptionId(void)
    {
        return subscriptionId_;
    }
    
    OpcUaByte&
    SubscriptionDiagnosticsDataType::priority(void)
    {
        return priority_;
    }
    
    OpcUaDouble&
    SubscriptionDiagnosticsDataType::publishingInterval(void)
    {
        return publishingInterval_;
    }
    
    OpcUaUInt32&
    SubscriptionDiagnosticsDataType::maxKeepAliveCount(void)
    {
        return maxKeepAliveCount_;
    }
    
    OpcUaUInt32&
    SubscriptionDiagnosticsDataType::maxLifetimeCount(void)
    {
        return maxLifetimeCount_;
    }
    
    OpcUaUInt32&
    SubscriptionDiagnosticsDataType::maxNotificationsPerPublish(void)
    {
        return maxNotificationsPerPublish_;
    }
    
    OpcUaBoolean&
    SubscriptionDiagnosticsDataType::publishingEnabled(void)
    {
        return publishingEnabled_;
    }
    
    OpcUaUInt32&
    SubscriptionDiagnosticsDataType::modifyCount(void)
    {
        return modifyCount_;
    }
    
    OpcUaUInt32&
    SubscriptionDiagnosticsDataType::enableCount(void)
    {
        return enableCount_;
    }
    
    OpcUaUInt32&
    SubscriptionDiagnosticsDataType::disableCount(void)
    {
        return disableCount_;
    }
    
    OpcUaUInt32&
    SubscriptionDiagnosticsDataType::republishRequestCount(void)
    {
        return republishRequestCount_;
    }
    
    OpcUaUInt32&
    SubscriptionDiagnosticsDataType::republishMessageRequestCount(void)
    {
        return republishMessageRequestCount_;
    }
    
    OpcUaUInt32&
    SubscriptionDiagnosticsDataType::republishMessageCount(void)
    {
        return republishMessageCount_;
    }
    
    OpcUaUInt32&
    SubscriptionDiagnosticsDataType::transferRequestCount(void)
    {
        return transferRequestCount_;
    }
    
    OpcUaUInt32&
    SubscriptionDiagnosticsDataType::transferredToAltClientCount(void)
    {
        return transferredToAltClientCount_;
    }
    
    OpcUaUInt32&
    SubscriptionDiagnosticsDataType::transferredToSameClientCount(void)
    {
        return transferredToSameClientCount_;
    }
    
    OpcUaUInt32&
    SubscriptionDiagnosticsDataType::publishRequestCount(void)
    {
        return publishRequestCount_;
    }
    
    OpcUaUInt32&
    SubscriptionDiagnosticsDataType::dataChangeNotificationsCount(void)
    {
        return dataChangeNotificationsCount_;
    }
    
    OpcUaUInt32&
    SubscriptionDiagnosticsDataType::eventNotificationsCount(void)
    {
        return eventNotificationsCount_;
    }
    
    OpcUaUInt32&
    SubscriptionDiagnosticsDataType::notificationsCount(void)
    {
        return notificationsCount_;
    }
    
    OpcUaUInt32&
    SubscriptionDiagnosticsDataType::latePublishRequestCount(void)
    {
        return latePublishRequestCount_;
    }
    
    OpcUaUInt32&
    SubscriptionDiagnosticsDataType::currentKeepAliveCount(void)
    {
        return currentKeepAliveCount_;
    }
    
    OpcUaUInt32&
    SubscriptionDiagnosticsDataType::currentLifetimeCount(void)
    {
        return currentLifetimeCount_;
    }
    
    OpcUaUInt32&
    SubscriptionDiagnosticsDataType::unacknowledgedMessageCount(void)
    {
        return unacknowledgedMessageCount_;
    }
    
    OpcUaUInt32&
    SubscriptionDiagnosticsDataType::discardedMessageCount(void)
    {
        return discardedMessageCount_;
    }
    
    OpcUaUInt32&
    SubscriptionDiagnosticsDataType::monitoredItemCount(void)
    {
        return monitoredItemCount_;
    }
    
    OpcUaUInt32&
    SubscriptionDiagnosticsDataType::disabledMonitoredItemCount(void)
    {
        return disabledMonitoredItemCount_;
    }
    
    OpcUaUInt32&
    SubscriptionDiagnosticsDataType::monitoringQueueOverflowCount(void)
    {
        return monitoringQueueOverflowCount_;
    }
    
    OpcUaUInt32&
    SubscriptionDiagnosticsDataType::nextSequenceNumber(void)
    {
        return nextSequenceNumber_;
    }
    
    OpcUaUInt32&
    SubscriptionDiagnosticsDataType::eventQueueOverFlowCount(void)
    {
        return eventQueueOverFlowCount_;
    }
    
    bool
    SubscriptionDiagnosticsDataType::operator==(const SubscriptionDiagnosticsDataType& value)
    {
        SubscriptionDiagnosticsDataType* dst = const_cast<SubscriptionDiagnosticsDataType*>(&value);
        if (sessionId_ != dst->sessionId()) return false;
        if (subscriptionId_ != dst->subscriptionId()) return false;
        if (priority_ != dst->priority()) return false;
        if (publishingInterval_ != dst->publishingInterval()) return false;
        if (maxKeepAliveCount_ != dst->maxKeepAliveCount()) return false;
        if (maxLifetimeCount_ != dst->maxLifetimeCount()) return false;
        if (maxNotificationsPerPublish_ != dst->maxNotificationsPerPublish()) return false;
        if (publishingEnabled_ != dst->publishingEnabled()) return false;
        if (modifyCount_ != dst->modifyCount()) return false;
        if (enableCount_ != dst->enableCount()) return false;
        if (disableCount_ != dst->disableCount()) return false;
        if (republishRequestCount_ != dst->republishRequestCount()) return false;
        if (republishMessageRequestCount_ != dst->republishMessageRequestCount()) return false;
        if (republishMessageCount_ != dst->republishMessageCount()) return false;
        if (transferRequestCount_ != dst->transferRequestCount()) return false;
        if (transferredToAltClientCount_ != dst->transferredToAltClientCount()) return false;
        if (transferredToSameClientCount_ != dst->transferredToSameClientCount()) return false;
        if (publishRequestCount_ != dst->publishRequestCount()) return false;
        if (dataChangeNotificationsCount_ != dst->dataChangeNotificationsCount()) return false;
        if (eventNotificationsCount_ != dst->eventNotificationsCount()) return false;
        if (notificationsCount_ != dst->notificationsCount()) return false;
        if (latePublishRequestCount_ != dst->latePublishRequestCount()) return false;
        if (currentKeepAliveCount_ != dst->currentKeepAliveCount()) return false;
        if (currentLifetimeCount_ != dst->currentLifetimeCount()) return false;
        if (unacknowledgedMessageCount_ != dst->unacknowledgedMessageCount()) return false;
        if (discardedMessageCount_ != dst->discardedMessageCount()) return false;
        if (monitoredItemCount_ != dst->monitoredItemCount()) return false;
        if (disabledMonitoredItemCount_ != dst->disabledMonitoredItemCount()) return false;
        if (monitoringQueueOverflowCount_ != dst->monitoringQueueOverflowCount()) return false;
        if (nextSequenceNumber_ != dst->nextSequenceNumber()) return false;
        if (eventQueueOverFlowCount_ != dst->eventQueueOverFlowCount()) return false;
        return true;
    }
    
    bool
    SubscriptionDiagnosticsDataType::operator!=(const SubscriptionDiagnosticsDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    SubscriptionDiagnosticsDataType::copyTo(SubscriptionDiagnosticsDataType& value)
    {
        sessionId_.copyTo(value.sessionId());
        value.subscriptionId_ = subscriptionId_;
        value.priority_ = priority_;
        value.publishingInterval_ = publishingInterval_;
        value.maxKeepAliveCount_ = maxKeepAliveCount_;
        value.maxLifetimeCount_ = maxLifetimeCount_;
        value.maxNotificationsPerPublish_ = maxNotificationsPerPublish_;
        value.publishingEnabled_ = publishingEnabled_;
        value.modifyCount_ = modifyCount_;
        value.enableCount_ = enableCount_;
        value.disableCount_ = disableCount_;
        value.republishRequestCount_ = republishRequestCount_;
        value.republishMessageRequestCount_ = republishMessageRequestCount_;
        value.republishMessageCount_ = republishMessageCount_;
        value.transferRequestCount_ = transferRequestCount_;
        value.transferredToAltClientCount_ = transferredToAltClientCount_;
        value.transferredToSameClientCount_ = transferredToSameClientCount_;
        value.publishRequestCount_ = publishRequestCount_;
        value.dataChangeNotificationsCount_ = dataChangeNotificationsCount_;
        value.eventNotificationsCount_ = eventNotificationsCount_;
        value.notificationsCount_ = notificationsCount_;
        value.latePublishRequestCount_ = latePublishRequestCount_;
        value.currentKeepAliveCount_ = currentKeepAliveCount_;
        value.currentLifetimeCount_ = currentLifetimeCount_;
        value.unacknowledgedMessageCount_ = unacknowledgedMessageCount_;
        value.discardedMessageCount_ = discardedMessageCount_;
        value.monitoredItemCount_ = monitoredItemCount_;
        value.disabledMonitoredItemCount_ = disabledMonitoredItemCount_;
        value.monitoringQueueOverflowCount_ = monitoringQueueOverflowCount_;
        value.nextSequenceNumber_ = nextSequenceNumber_;
        value.eventQueueOverFlowCount_ = eventQueueOverFlowCount_;
    }
    
    SubscriptionDiagnosticsDataType&
    SubscriptionDiagnosticsDataType::operator=(const SubscriptionDiagnosticsDataType& value)
    {
        const_cast<SubscriptionDiagnosticsDataType*>(&value)->copyTo(*this);
        return *this;
    }
    
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    //
    // ExtensionObjectBase
    //
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    
    ExtensionObjectBase::SPtr
    SubscriptionDiagnosticsDataType::factory(void)
    {
    	return constructSPtr<SubscriptionDiagnosticsDataType>();
    }
    
    std::string
    SubscriptionDiagnosticsDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    SubscriptionDiagnosticsDataType::typeName(void)
    {
    	return "SubscriptionDiagnosticsDataType";
    }
    
    OpcUaNodeId
    SubscriptionDiagnosticsDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)874,0);
    }
    
    OpcUaNodeId
    SubscriptionDiagnosticsDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)876, 0);
    }
    
    OpcUaNodeId
    SubscriptionDiagnosticsDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)875, 0);
    }
    
    OpcUaNodeId
    SubscriptionDiagnosticsDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15372, 0);
    }
    
    void
    SubscriptionDiagnosticsDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        sessionId_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,subscriptionId_);
        OpcUaNumber::opcUaBinaryEncode(os,priority_);
        OpcUaNumber::opcUaBinaryEncode(os,publishingInterval_);
        OpcUaNumber::opcUaBinaryEncode(os,maxKeepAliveCount_);
        OpcUaNumber::opcUaBinaryEncode(os,maxLifetimeCount_);
        OpcUaNumber::opcUaBinaryEncode(os,maxNotificationsPerPublish_);
        OpcUaNumber::opcUaBinaryEncode(os,publishingEnabled_);
        OpcUaNumber::opcUaBinaryEncode(os,modifyCount_);
        OpcUaNumber::opcUaBinaryEncode(os,enableCount_);
        OpcUaNumber::opcUaBinaryEncode(os,disableCount_);
        OpcUaNumber::opcUaBinaryEncode(os,republishRequestCount_);
        OpcUaNumber::opcUaBinaryEncode(os,republishMessageRequestCount_);
        OpcUaNumber::opcUaBinaryEncode(os,republishMessageCount_);
        OpcUaNumber::opcUaBinaryEncode(os,transferRequestCount_);
        OpcUaNumber::opcUaBinaryEncode(os,transferredToAltClientCount_);
        OpcUaNumber::opcUaBinaryEncode(os,transferredToSameClientCount_);
        OpcUaNumber::opcUaBinaryEncode(os,publishRequestCount_);
        OpcUaNumber::opcUaBinaryEncode(os,dataChangeNotificationsCount_);
        OpcUaNumber::opcUaBinaryEncode(os,eventNotificationsCount_);
        OpcUaNumber::opcUaBinaryEncode(os,notificationsCount_);
        OpcUaNumber::opcUaBinaryEncode(os,latePublishRequestCount_);
        OpcUaNumber::opcUaBinaryEncode(os,currentKeepAliveCount_);
        OpcUaNumber::opcUaBinaryEncode(os,currentLifetimeCount_);
        OpcUaNumber::opcUaBinaryEncode(os,unacknowledgedMessageCount_);
        OpcUaNumber::opcUaBinaryEncode(os,discardedMessageCount_);
        OpcUaNumber::opcUaBinaryEncode(os,monitoredItemCount_);
        OpcUaNumber::opcUaBinaryEncode(os,disabledMonitoredItemCount_);
        OpcUaNumber::opcUaBinaryEncode(os,monitoringQueueOverflowCount_);
        OpcUaNumber::opcUaBinaryEncode(os,nextSequenceNumber_);
        OpcUaNumber::opcUaBinaryEncode(os,eventQueueOverFlowCount_);
    }
    
    void
    SubscriptionDiagnosticsDataType::opcUaBinaryDecode(std::istream& is)
    {
        sessionId_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,subscriptionId_);
        OpcUaNumber::opcUaBinaryDecode(is,priority_);
        OpcUaNumber::opcUaBinaryDecode(is,publishingInterval_);
        OpcUaNumber::opcUaBinaryDecode(is,maxKeepAliveCount_);
        OpcUaNumber::opcUaBinaryDecode(is,maxLifetimeCount_);
        OpcUaNumber::opcUaBinaryDecode(is,maxNotificationsPerPublish_);
        OpcUaNumber::opcUaBinaryDecode(is,publishingEnabled_);
        OpcUaNumber::opcUaBinaryDecode(is,modifyCount_);
        OpcUaNumber::opcUaBinaryDecode(is,enableCount_);
        OpcUaNumber::opcUaBinaryDecode(is,disableCount_);
        OpcUaNumber::opcUaBinaryDecode(is,republishRequestCount_);
        OpcUaNumber::opcUaBinaryDecode(is,republishMessageRequestCount_);
        OpcUaNumber::opcUaBinaryDecode(is,republishMessageCount_);
        OpcUaNumber::opcUaBinaryDecode(is,transferRequestCount_);
        OpcUaNumber::opcUaBinaryDecode(is,transferredToAltClientCount_);
        OpcUaNumber::opcUaBinaryDecode(is,transferredToSameClientCount_);
        OpcUaNumber::opcUaBinaryDecode(is,publishRequestCount_);
        OpcUaNumber::opcUaBinaryDecode(is,dataChangeNotificationsCount_);
        OpcUaNumber::opcUaBinaryDecode(is,eventNotificationsCount_);
        OpcUaNumber::opcUaBinaryDecode(is,notificationsCount_);
        OpcUaNumber::opcUaBinaryDecode(is,latePublishRequestCount_);
        OpcUaNumber::opcUaBinaryDecode(is,currentKeepAliveCount_);
        OpcUaNumber::opcUaBinaryDecode(is,currentLifetimeCount_);
        OpcUaNumber::opcUaBinaryDecode(is,unacknowledgedMessageCount_);
        OpcUaNumber::opcUaBinaryDecode(is,discardedMessageCount_);
        OpcUaNumber::opcUaBinaryDecode(is,monitoredItemCount_);
        OpcUaNumber::opcUaBinaryDecode(is,disabledMonitoredItemCount_);
        OpcUaNumber::opcUaBinaryDecode(is,monitoringQueueOverflowCount_);
        OpcUaNumber::opcUaBinaryDecode(is,nextSequenceNumber_);
        OpcUaNumber::opcUaBinaryDecode(is,eventQueueOverFlowCount_);
    }
    
    bool
    SubscriptionDiagnosticsDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "SubscriptionDiagnosticsDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    SubscriptionDiagnosticsDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!sessionId_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SubscriptionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SessionId", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, subscriptionId_))
        {
            Log(Error, "SubscriptionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SubscriptionId", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, priority_))
        {
            Log(Error, "SubscriptionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Priority", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, publishingInterval_))
        {
            Log(Error, "SubscriptionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("PublishingInterval", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, maxKeepAliveCount_))
        {
            Log(Error, "SubscriptionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("MaxKeepAliveCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, maxLifetimeCount_))
        {
            Log(Error, "SubscriptionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("MaxLifetimeCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, maxNotificationsPerPublish_))
        {
            Log(Error, "SubscriptionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("MaxNotificationsPerPublish", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, publishingEnabled_))
        {
            Log(Error, "SubscriptionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("PublishingEnabled", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, modifyCount_))
        {
            Log(Error, "SubscriptionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ModifyCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, enableCount_))
        {
            Log(Error, "SubscriptionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("EnableCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, disableCount_))
        {
            Log(Error, "SubscriptionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DisableCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, republishRequestCount_))
        {
            Log(Error, "SubscriptionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("RepublishRequestCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, republishMessageRequestCount_))
        {
            Log(Error, "SubscriptionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("RepublishMessageRequestCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, republishMessageCount_))
        {
            Log(Error, "SubscriptionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("RepublishMessageCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, transferRequestCount_))
        {
            Log(Error, "SubscriptionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("TransferRequestCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, transferredToAltClientCount_))
        {
            Log(Error, "SubscriptionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("TransferredToAltClientCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, transferredToSameClientCount_))
        {
            Log(Error, "SubscriptionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("TransferredToSameClientCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, publishRequestCount_))
        {
            Log(Error, "SubscriptionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("PublishRequestCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, dataChangeNotificationsCount_))
        {
            Log(Error, "SubscriptionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DataChangeNotificationsCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, eventNotificationsCount_))
        {
            Log(Error, "SubscriptionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("EventNotificationsCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, notificationsCount_))
        {
            Log(Error, "SubscriptionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("NotificationsCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, latePublishRequestCount_))
        {
            Log(Error, "SubscriptionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("LatePublishRequestCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, currentKeepAliveCount_))
        {
            Log(Error, "SubscriptionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("CurrentKeepAliveCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, currentLifetimeCount_))
        {
            Log(Error, "SubscriptionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("CurrentLifetimeCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, unacknowledgedMessageCount_))
        {
            Log(Error, "SubscriptionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("UnacknowledgedMessageCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, discardedMessageCount_))
        {
            Log(Error, "SubscriptionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DiscardedMessageCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, monitoredItemCount_))
        {
            Log(Error, "SubscriptionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("MonitoredItemCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, disabledMonitoredItemCount_))
        {
            Log(Error, "SubscriptionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DisabledMonitoredItemCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, monitoringQueueOverflowCount_))
        {
            Log(Error, "SubscriptionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("MonitoringQueueOverflowCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, nextSequenceNumber_))
        {
            Log(Error, "SubscriptionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("NextSequenceNumber", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, eventQueueOverFlowCount_))
        {
            Log(Error, "SubscriptionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("EventQueueOverFlowCount", elementTree));
    
        return true;
    }
    
    bool
    SubscriptionDiagnosticsDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    SubscriptionDiagnosticsDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("SessionId");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!sessionId_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "SessionId");
            return false;
        }
    
        elementName = xmlns.addPrefix("SubscriptionId");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, subscriptionId_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("Priority");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, priority_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("PublishingInterval");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, publishingInterval_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("MaxKeepAliveCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, maxKeepAliveCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("MaxLifetimeCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, maxLifetimeCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("MaxNotificationsPerPublish");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, maxNotificationsPerPublish_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("PublishingEnabled");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, publishingEnabled_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("ModifyCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, modifyCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("EnableCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, enableCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("DisableCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, disableCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("RepublishRequestCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, republishRequestCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("RepublishMessageRequestCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, republishMessageRequestCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("RepublishMessageCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, republishMessageCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("TransferRequestCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, transferRequestCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("TransferredToAltClientCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, transferredToAltClientCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("TransferredToSameClientCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, transferredToSameClientCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("PublishRequestCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, publishRequestCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("DataChangeNotificationsCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, dataChangeNotificationsCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("EventNotificationsCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, eventNotificationsCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("NotificationsCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, notificationsCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("LatePublishRequestCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, latePublishRequestCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("CurrentKeepAliveCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, currentKeepAliveCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("CurrentLifetimeCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, currentLifetimeCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("UnacknowledgedMessageCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, unacknowledgedMessageCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("DiscardedMessageCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, discardedMessageCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("MonitoredItemCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, monitoredItemCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("DisabledMonitoredItemCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, disabledMonitoredItemCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("MonitoringQueueOverflowCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, monitoringQueueOverflowCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("NextSequenceNumber");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, nextSequenceNumber_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("EventQueueOverFlowCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, eventQueueOverFlowCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    SubscriptionDiagnosticsDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!sessionId_.jsonEncode(elementTree))
        {
    	     Log(Error, "SubscriptionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "sessionId_");
            return false;
        }
        pt.push_back(std::make_pair("SessionId", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, subscriptionId_))
        {
    	     Log(Error, "SubscriptionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "subscriptionId_");
           return false;
        }
        pt.push_back(std::make_pair("SubscriptionId", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, priority_))
        {
    	     Log(Error, "SubscriptionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "priority_");
           return false;
        }
        pt.push_back(std::make_pair("Priority", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, publishingInterval_))
        {
    	     Log(Error, "SubscriptionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "publishingInterval_");
           return false;
        }
        pt.push_back(std::make_pair("PublishingInterval", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, maxKeepAliveCount_))
        {
    	     Log(Error, "SubscriptionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "maxKeepAliveCount_");
           return false;
        }
        pt.push_back(std::make_pair("MaxKeepAliveCount", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, maxLifetimeCount_))
        {
    	     Log(Error, "SubscriptionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "maxLifetimeCount_");
           return false;
        }
        pt.push_back(std::make_pair("MaxLifetimeCount", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, maxNotificationsPerPublish_))
        {
    	     Log(Error, "SubscriptionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "maxNotificationsPerPublish_");
           return false;
        }
        pt.push_back(std::make_pair("MaxNotificationsPerPublish", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, publishingEnabled_))
        {
    	     Log(Error, "SubscriptionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "publishingEnabled_");
           return false;
        }
        pt.push_back(std::make_pair("PublishingEnabled", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, modifyCount_))
        {
    	     Log(Error, "SubscriptionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "modifyCount_");
           return false;
        }
        pt.push_back(std::make_pair("ModifyCount", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, enableCount_))
        {
    	     Log(Error, "SubscriptionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "enableCount_");
           return false;
        }
        pt.push_back(std::make_pair("EnableCount", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, disableCount_))
        {
    	     Log(Error, "SubscriptionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "disableCount_");
           return false;
        }
        pt.push_back(std::make_pair("DisableCount", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, republishRequestCount_))
        {
    	     Log(Error, "SubscriptionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "republishRequestCount_");
           return false;
        }
        pt.push_back(std::make_pair("RepublishRequestCount", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, republishMessageRequestCount_))
        {
    	     Log(Error, "SubscriptionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "republishMessageRequestCount_");
           return false;
        }
        pt.push_back(std::make_pair("RepublishMessageRequestCount", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, republishMessageCount_))
        {
    	     Log(Error, "SubscriptionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "republishMessageCount_");
           return false;
        }
        pt.push_back(std::make_pair("RepublishMessageCount", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, transferRequestCount_))
        {
    	     Log(Error, "SubscriptionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "transferRequestCount_");
           return false;
        }
        pt.push_back(std::make_pair("TransferRequestCount", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, transferredToAltClientCount_))
        {
    	     Log(Error, "SubscriptionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "transferredToAltClientCount_");
           return false;
        }
        pt.push_back(std::make_pair("TransferredToAltClientCount", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, transferredToSameClientCount_))
        {
    	     Log(Error, "SubscriptionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "transferredToSameClientCount_");
           return false;
        }
        pt.push_back(std::make_pair("TransferredToSameClientCount", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, publishRequestCount_))
        {
    	     Log(Error, "SubscriptionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "publishRequestCount_");
           return false;
        }
        pt.push_back(std::make_pair("PublishRequestCount", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, dataChangeNotificationsCount_))
        {
    	     Log(Error, "SubscriptionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "dataChangeNotificationsCount_");
           return false;
        }
        pt.push_back(std::make_pair("DataChangeNotificationsCount", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, eventNotificationsCount_))
        {
    	     Log(Error, "SubscriptionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "eventNotificationsCount_");
           return false;
        }
        pt.push_back(std::make_pair("EventNotificationsCount", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, notificationsCount_))
        {
    	     Log(Error, "SubscriptionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "notificationsCount_");
           return false;
        }
        pt.push_back(std::make_pair("NotificationsCount", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, latePublishRequestCount_))
        {
    	     Log(Error, "SubscriptionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "latePublishRequestCount_");
           return false;
        }
        pt.push_back(std::make_pair("LatePublishRequestCount", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, currentKeepAliveCount_))
        {
    	     Log(Error, "SubscriptionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "currentKeepAliveCount_");
           return false;
        }
        pt.push_back(std::make_pair("CurrentKeepAliveCount", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, currentLifetimeCount_))
        {
    	     Log(Error, "SubscriptionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "currentLifetimeCount_");
           return false;
        }
        pt.push_back(std::make_pair("CurrentLifetimeCount", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, unacknowledgedMessageCount_))
        {
    	     Log(Error, "SubscriptionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "unacknowledgedMessageCount_");
           return false;
        }
        pt.push_back(std::make_pair("UnacknowledgedMessageCount", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, discardedMessageCount_))
        {
    	     Log(Error, "SubscriptionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "discardedMessageCount_");
           return false;
        }
        pt.push_back(std::make_pair("DiscardedMessageCount", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, monitoredItemCount_))
        {
    	     Log(Error, "SubscriptionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "monitoredItemCount_");
           return false;
        }
        pt.push_back(std::make_pair("MonitoredItemCount", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, disabledMonitoredItemCount_))
        {
    	     Log(Error, "SubscriptionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "disabledMonitoredItemCount_");
           return false;
        }
        pt.push_back(std::make_pair("DisabledMonitoredItemCount", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, monitoringQueueOverflowCount_))
        {
    	     Log(Error, "SubscriptionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "monitoringQueueOverflowCount_");
           return false;
        }
        pt.push_back(std::make_pair("MonitoringQueueOverflowCount", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, nextSequenceNumber_))
        {
    	     Log(Error, "SubscriptionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "nextSequenceNumber_");
           return false;
        }
        pt.push_back(std::make_pair("NextSequenceNumber", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, eventQueueOverFlowCount_))
        {
    	     Log(Error, "SubscriptionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "eventQueueOverFlowCount_");
           return false;
        }
        pt.push_back(std::make_pair("EventQueueOverFlowCount", elementTree));
    
        return true;
    }
    
    bool
    SubscriptionDiagnosticsDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "SessionId";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!sessionId_.jsonDecode(*tree)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "SessionId");
            return false;
        }
    
        elementName = "SubscriptionId";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, subscriptionId_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "Priority";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, priority_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "PublishingInterval";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, publishingInterval_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "MaxKeepAliveCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, maxKeepAliveCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "MaxLifetimeCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, maxLifetimeCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "MaxNotificationsPerPublish";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, maxNotificationsPerPublish_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "PublishingEnabled";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, publishingEnabled_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "ModifyCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, modifyCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "EnableCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, enableCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "DisableCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, disableCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "RepublishRequestCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, republishRequestCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "RepublishMessageRequestCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, republishMessageRequestCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "RepublishMessageCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, republishMessageCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "TransferRequestCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, transferRequestCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "TransferredToAltClientCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, transferredToAltClientCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "TransferredToSameClientCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, transferredToSameClientCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "PublishRequestCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, publishRequestCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "DataChangeNotificationsCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, dataChangeNotificationsCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "EventNotificationsCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, eventNotificationsCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "NotificationsCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, notificationsCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "LatePublishRequestCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, latePublishRequestCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "CurrentKeepAliveCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, currentKeepAliveCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "CurrentLifetimeCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, currentLifetimeCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "UnacknowledgedMessageCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, unacknowledgedMessageCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "DiscardedMessageCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, discardedMessageCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "MonitoredItemCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, monitoredItemCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "DisabledMonitoredItemCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, disabledMonitoredItemCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "MonitoringQueueOverflowCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, monitoringQueueOverflowCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "NextSequenceNumber";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, nextSequenceNumber_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "EventQueueOverFlowCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, eventQueueOverFlowCount_)) {
            Log(Error, "SubscriptionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    SubscriptionDiagnosticsDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	SubscriptionDiagnosticsDataType* dst = dynamic_cast<SubscriptionDiagnosticsDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    SubscriptionDiagnosticsDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	SubscriptionDiagnosticsDataType* dst = dynamic_cast<SubscriptionDiagnosticsDataType*>(&extensionObjectBase);
    	return *const_cast<SubscriptionDiagnosticsDataType*>(this) == *dst;
    }
    
    void
    SubscriptionDiagnosticsDataType::out(std::ostream& os)
    {
        os << "SessionId="; sessionId_.out(os);
        os << ", SubscriptionId=" << subscriptionId_;
        os << ", Priority=" << priority_;
        os << ", PublishingInterval=" << publishingInterval_;
        os << ", MaxKeepAliveCount=" << maxKeepAliveCount_;
        os << ", MaxLifetimeCount=" << maxLifetimeCount_;
        os << ", MaxNotificationsPerPublish=" << maxNotificationsPerPublish_;
        os << ", PublishingEnabled=" << publishingEnabled_;
        os << ", ModifyCount=" << modifyCount_;
        os << ", EnableCount=" << enableCount_;
        os << ", DisableCount=" << disableCount_;
        os << ", RepublishRequestCount=" << republishRequestCount_;
        os << ", RepublishMessageRequestCount=" << republishMessageRequestCount_;
        os << ", RepublishMessageCount=" << republishMessageCount_;
        os << ", TransferRequestCount=" << transferRequestCount_;
        os << ", TransferredToAltClientCount=" << transferredToAltClientCount_;
        os << ", TransferredToSameClientCount=" << transferredToSameClientCount_;
        os << ", PublishRequestCount=" << publishRequestCount_;
        os << ", DataChangeNotificationsCount=" << dataChangeNotificationsCount_;
        os << ", EventNotificationsCount=" << eventNotificationsCount_;
        os << ", NotificationsCount=" << notificationsCount_;
        os << ", LatePublishRequestCount=" << latePublishRequestCount_;
        os << ", CurrentKeepAliveCount=" << currentKeepAliveCount_;
        os << ", CurrentLifetimeCount=" << currentLifetimeCount_;
        os << ", UnacknowledgedMessageCount=" << unacknowledgedMessageCount_;
        os << ", DiscardedMessageCount=" << discardedMessageCount_;
        os << ", MonitoredItemCount=" << monitoredItemCount_;
        os << ", DisabledMonitoredItemCount=" << disabledMonitoredItemCount_;
        os << ", MonitoringQueueOverflowCount=" << monitoringQueueOverflowCount_;
        os << ", NextSequenceNumber=" << nextSequenceNumber_;
        os << ", EventQueueOverFlowCount=" << eventQueueOverFlowCount_;
    }

}
