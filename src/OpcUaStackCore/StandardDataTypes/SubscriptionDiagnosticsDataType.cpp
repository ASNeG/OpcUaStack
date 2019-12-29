/*
    DataTypeClass: SubscriptionDiagnosticsDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

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
    	return boost::make_shared<SubscriptionDiagnosticsDataType>();
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
    
    bool
    SubscriptionDiagnosticsDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        bool rc = true;
    
        rc &= sessionId_.opcUaBinaryEncode(os);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,subscriptionId_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,priority_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,publishingInterval_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,maxKeepAliveCount_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,maxLifetimeCount_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,maxNotificationsPerPublish_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,publishingEnabled_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,modifyCount_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,enableCount_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,disableCount_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,republishRequestCount_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,republishMessageRequestCount_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,republishMessageCount_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,transferRequestCount_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,transferredToAltClientCount_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,transferredToSameClientCount_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,publishRequestCount_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,dataChangeNotificationsCount_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,eventNotificationsCount_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,notificationsCount_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,latePublishRequestCount_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,currentKeepAliveCount_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,currentLifetimeCount_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,unacknowledgedMessageCount_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,discardedMessageCount_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,monitoredItemCount_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,disabledMonitoredItemCount_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,monitoringQueueOverflowCount_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,nextSequenceNumber_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,eventQueueOverFlowCount_);
        return rc;
    }
    
    bool
    SubscriptionDiagnosticsDataType::opcUaBinaryDecode(std::istream& is)
    {
        bool rc = true;
    
        rc &= sessionId_.opcUaBinaryDecode(is);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,subscriptionId_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,priority_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,publishingInterval_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,maxKeepAliveCount_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,maxLifetimeCount_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,maxNotificationsPerPublish_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,publishingEnabled_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,modifyCount_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,enableCount_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,disableCount_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,republishRequestCount_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,republishMessageRequestCount_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,republishMessageCount_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,transferRequestCount_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,transferredToAltClientCount_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,transferredToSameClientCount_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,publishRequestCount_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,dataChangeNotificationsCount_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,eventNotificationsCount_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,notificationsCount_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,latePublishRequestCount_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,currentKeepAliveCount_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,currentLifetimeCount_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,unacknowledgedMessageCount_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,discardedMessageCount_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,monitoredItemCount_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,disabledMonitoredItemCount_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,monitoringQueueOverflowCount_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,nextSequenceNumber_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,eventQueueOverFlowCount_);
        return rc;
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
        bool rc = true;
    
        rc = rc & jsonObjectEncode(pt, sessionId_, "SessionId", true);
        rc = rc & jsonNumberEncode(pt, subscriptionId_, "SubscriptionId");
        rc = rc & jsonNumberEncode(pt, priority_, "Priority");
        rc = rc & jsonNumberEncode(pt, publishingInterval_, "PublishingInterval");
        rc = rc & jsonNumberEncode(pt, maxKeepAliveCount_, "MaxKeepAliveCount");
        rc = rc & jsonNumberEncode(pt, maxLifetimeCount_, "MaxLifetimeCount");
        rc = rc & jsonNumberEncode(pt, maxNotificationsPerPublish_, "MaxNotificationsPerPublish");
        rc = rc & jsonNumberEncode(pt, publishingEnabled_, "PublishingEnabled");
        rc = rc & jsonNumberEncode(pt, modifyCount_, "ModifyCount");
        rc = rc & jsonNumberEncode(pt, enableCount_, "EnableCount");
        rc = rc & jsonNumberEncode(pt, disableCount_, "DisableCount");
        rc = rc & jsonNumberEncode(pt, republishRequestCount_, "RepublishRequestCount");
        rc = rc & jsonNumberEncode(pt, republishMessageRequestCount_, "RepublishMessageRequestCount");
        rc = rc & jsonNumberEncode(pt, republishMessageCount_, "RepublishMessageCount");
        rc = rc & jsonNumberEncode(pt, transferRequestCount_, "TransferRequestCount");
        rc = rc & jsonNumberEncode(pt, transferredToAltClientCount_, "TransferredToAltClientCount");
        rc = rc & jsonNumberEncode(pt, transferredToSameClientCount_, "TransferredToSameClientCount");
        rc = rc & jsonNumberEncode(pt, publishRequestCount_, "PublishRequestCount");
        rc = rc & jsonNumberEncode(pt, dataChangeNotificationsCount_, "DataChangeNotificationsCount");
        rc = rc & jsonNumberEncode(pt, eventNotificationsCount_, "EventNotificationsCount");
        rc = rc & jsonNumberEncode(pt, notificationsCount_, "NotificationsCount");
        rc = rc & jsonNumberEncode(pt, latePublishRequestCount_, "LatePublishRequestCount");
        rc = rc & jsonNumberEncode(pt, currentKeepAliveCount_, "CurrentKeepAliveCount");
        rc = rc & jsonNumberEncode(pt, currentLifetimeCount_, "CurrentLifetimeCount");
        rc = rc & jsonNumberEncode(pt, unacknowledgedMessageCount_, "UnacknowledgedMessageCount");
        rc = rc & jsonNumberEncode(pt, discardedMessageCount_, "DiscardedMessageCount");
        rc = rc & jsonNumberEncode(pt, monitoredItemCount_, "MonitoredItemCount");
        rc = rc & jsonNumberEncode(pt, disabledMonitoredItemCount_, "DisabledMonitoredItemCount");
        rc = rc & jsonNumberEncode(pt, monitoringQueueOverflowCount_, "MonitoringQueueOverflowCount");
        rc = rc & jsonNumberEncode(pt, nextSequenceNumber_, "NextSequenceNumber");
        rc = rc & jsonNumberEncode(pt, eventQueueOverFlowCount_, "EventQueueOverFlowCount");
    
        return rc;
    }
    
    bool
    SubscriptionDiagnosticsDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        bool rc = true;
    
        rc = rc & jsonObjectDecode(pt, sessionId_, "SessionId", true);
        rc = rc & jsonNumberDecode(pt, subscriptionId_, "SubscriptionId");
        rc = rc & jsonNumberDecode(pt, priority_, "Priority");
        rc = rc & jsonNumberDecode(pt, publishingInterval_, "PublishingInterval");
        rc = rc & jsonNumberDecode(pt, maxKeepAliveCount_, "MaxKeepAliveCount");
        rc = rc & jsonNumberDecode(pt, maxLifetimeCount_, "MaxLifetimeCount");
        rc = rc & jsonNumberDecode(pt, maxNotificationsPerPublish_, "MaxNotificationsPerPublish");
        rc = rc & jsonNumberDecode(pt, publishingEnabled_, "PublishingEnabled");
        rc = rc & jsonNumberDecode(pt, modifyCount_, "ModifyCount");
        rc = rc & jsonNumberDecode(pt, enableCount_, "EnableCount");
        rc = rc & jsonNumberDecode(pt, disableCount_, "DisableCount");
        rc = rc & jsonNumberDecode(pt, republishRequestCount_, "RepublishRequestCount");
        rc = rc & jsonNumberDecode(pt, republishMessageRequestCount_, "RepublishMessageRequestCount");
        rc = rc & jsonNumberDecode(pt, republishMessageCount_, "RepublishMessageCount");
        rc = rc & jsonNumberDecode(pt, transferRequestCount_, "TransferRequestCount");
        rc = rc & jsonNumberDecode(pt, transferredToAltClientCount_, "TransferredToAltClientCount");
        rc = rc & jsonNumberDecode(pt, transferredToSameClientCount_, "TransferredToSameClientCount");
        rc = rc & jsonNumberDecode(pt, publishRequestCount_, "PublishRequestCount");
        rc = rc & jsonNumberDecode(pt, dataChangeNotificationsCount_, "DataChangeNotificationsCount");
        rc = rc & jsonNumberDecode(pt, eventNotificationsCount_, "EventNotificationsCount");
        rc = rc & jsonNumberDecode(pt, notificationsCount_, "NotificationsCount");
        rc = rc & jsonNumberDecode(pt, latePublishRequestCount_, "LatePublishRequestCount");
        rc = rc & jsonNumberDecode(pt, currentKeepAliveCount_, "CurrentKeepAliveCount");
        rc = rc & jsonNumberDecode(pt, currentLifetimeCount_, "CurrentLifetimeCount");
        rc = rc & jsonNumberDecode(pt, unacknowledgedMessageCount_, "UnacknowledgedMessageCount");
        rc = rc & jsonNumberDecode(pt, discardedMessageCount_, "DiscardedMessageCount");
        rc = rc & jsonNumberDecode(pt, monitoredItemCount_, "MonitoredItemCount");
        rc = rc & jsonNumberDecode(pt, disabledMonitoredItemCount_, "DisabledMonitoredItemCount");
        rc = rc & jsonNumberDecode(pt, monitoringQueueOverflowCount_, "MonitoringQueueOverflowCount");
        rc = rc & jsonNumberDecode(pt, nextSequenceNumber_, "NextSequenceNumber");
        rc = rc & jsonNumberDecode(pt, eventQueueOverFlowCount_, "EventQueueOverFlowCount");
    
        return rc;
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
