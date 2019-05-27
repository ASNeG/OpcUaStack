/*
    DataTypeClass: SessionDiagnosticsDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/SessionDiagnosticsDataType.h"

namespace OpcUaStackCore
{
    
    SessionDiagnosticsDataType::SessionDiagnosticsDataType(void)
    : Object()
    , ExtensionObjectBase()
    , sessionId_()
    , sessionName_()
    , clientDescription_()
    , serverUri_()
    , endpointUrl_()
    , localeIds_()
    , actualSessionTimeout_()
    , maxResponseMessageSize_()
    , clientConnectionTime_()
    , clientLastContactTime_()
    , currentSubscriptionsCount_()
    , currentMonitoredItemsCount_()
    , currentPublishRequestsInQueue_()
    , totalRequestCount_()
    , unauthorizedRequestCount_()
    , readCount_()
    , historyReadCount_()
    , writeCount_()
    , historyUpdateCount_()
    , callCount_()
    , createMonitoredItemsCount_()
    , modifyMonitoredItemsCount_()
    , setMonitoringModeCount_()
    , setTriggeringCount_()
    , deleteMonitoredItemsCount_()
    , createSubscriptionCount_()
    , modifySubscriptionCount_()
    , setPublishingModeCount_()
    , publishCount_()
    , republishCount_()
    , transferSubscriptionsCount_()
    , deleteSubscriptionsCount_()
    , addNodesCount_()
    , addReferencesCount_()
    , deleteNodesCount_()
    , deleteReferencesCount_()
    , browseCount_()
    , browseNextCount_()
    , translateBrowsePathsToNodeIdsCount_()
    , queryFirstCount_()
    , queryNextCount_()
    , registerNodesCount_()
    , unregisterNodesCount_()
    {
    }
    
    SessionDiagnosticsDataType::SessionDiagnosticsDataType(const SessionDiagnosticsDataType& value)
    : Object()
    , ExtensionObjectBase()
    , sessionId_()
    , sessionName_()
    , clientDescription_()
    , serverUri_()
    , endpointUrl_()
    , localeIds_()
    , actualSessionTimeout_()
    , maxResponseMessageSize_()
    , clientConnectionTime_()
    , clientLastContactTime_()
    , currentSubscriptionsCount_()
    , currentMonitoredItemsCount_()
    , currentPublishRequestsInQueue_()
    , totalRequestCount_()
    , unauthorizedRequestCount_()
    , readCount_()
    , historyReadCount_()
    , writeCount_()
    , historyUpdateCount_()
    , callCount_()
    , createMonitoredItemsCount_()
    , modifyMonitoredItemsCount_()
    , setMonitoringModeCount_()
    , setTriggeringCount_()
    , deleteMonitoredItemsCount_()
    , createSubscriptionCount_()
    , modifySubscriptionCount_()
    , setPublishingModeCount_()
    , publishCount_()
    , republishCount_()
    , transferSubscriptionsCount_()
    , deleteSubscriptionsCount_()
    , addNodesCount_()
    , addReferencesCount_()
    , deleteNodesCount_()
    , deleteReferencesCount_()
    , browseCount_()
    , browseNextCount_()
    , translateBrowsePathsToNodeIdsCount_()
    , queryFirstCount_()
    , queryNextCount_()
    , registerNodesCount_()
    , unregisterNodesCount_()
    {
        const_cast<SessionDiagnosticsDataType*>(&value)->copyTo(*this);
    }
    
    SessionDiagnosticsDataType::~SessionDiagnosticsDataType(void)
    {
    }
    
    OpcUaNodeId&
    SessionDiagnosticsDataType::sessionId(void)
    {
        return sessionId_;
    }
    
    OpcUaString&
    SessionDiagnosticsDataType::sessionName(void)
    {
        return sessionName_;
    }
    
    ApplicationDescription&
    SessionDiagnosticsDataType::clientDescription(void)
    {
        return clientDescription_;
    }
    
    OpcUaString&
    SessionDiagnosticsDataType::serverUri(void)
    {
        return serverUri_;
    }
    
    OpcUaString&
    SessionDiagnosticsDataType::endpointUrl(void)
    {
        return endpointUrl_;
    }
    
    OpcUaLocaleIdArray&
    SessionDiagnosticsDataType::localeIds(void)
    {
        return localeIds_;
    }
    
    OpcUaDuration&
    SessionDiagnosticsDataType::actualSessionTimeout(void)
    {
        return actualSessionTimeout_;
    }
    
    OpcUaUInt32&
    SessionDiagnosticsDataType::maxResponseMessageSize(void)
    {
        return maxResponseMessageSize_;
    }
    
    OpcUaUtcTime&
    SessionDiagnosticsDataType::clientConnectionTime(void)
    {
        return clientConnectionTime_;
    }
    
    OpcUaUtcTime&
    SessionDiagnosticsDataType::clientLastContactTime(void)
    {
        return clientLastContactTime_;
    }
    
    OpcUaUInt32&
    SessionDiagnosticsDataType::currentSubscriptionsCount(void)
    {
        return currentSubscriptionsCount_;
    }
    
    OpcUaUInt32&
    SessionDiagnosticsDataType::currentMonitoredItemsCount(void)
    {
        return currentMonitoredItemsCount_;
    }
    
    OpcUaUInt32&
    SessionDiagnosticsDataType::currentPublishRequestsInQueue(void)
    {
        return currentPublishRequestsInQueue_;
    }
    
    ServiceCounterDataType&
    SessionDiagnosticsDataType::totalRequestCount(void)
    {
        return totalRequestCount_;
    }
    
    OpcUaUInt32&
    SessionDiagnosticsDataType::unauthorizedRequestCount(void)
    {
        return unauthorizedRequestCount_;
    }
    
    ServiceCounterDataType&
    SessionDiagnosticsDataType::readCount(void)
    {
        return readCount_;
    }
    
    ServiceCounterDataType&
    SessionDiagnosticsDataType::historyReadCount(void)
    {
        return historyReadCount_;
    }
    
    ServiceCounterDataType&
    SessionDiagnosticsDataType::writeCount(void)
    {
        return writeCount_;
    }
    
    ServiceCounterDataType&
    SessionDiagnosticsDataType::historyUpdateCount(void)
    {
        return historyUpdateCount_;
    }
    
    ServiceCounterDataType&
    SessionDiagnosticsDataType::callCount(void)
    {
        return callCount_;
    }
    
    ServiceCounterDataType&
    SessionDiagnosticsDataType::createMonitoredItemsCount(void)
    {
        return createMonitoredItemsCount_;
    }
    
    ServiceCounterDataType&
    SessionDiagnosticsDataType::modifyMonitoredItemsCount(void)
    {
        return modifyMonitoredItemsCount_;
    }
    
    ServiceCounterDataType&
    SessionDiagnosticsDataType::setMonitoringModeCount(void)
    {
        return setMonitoringModeCount_;
    }
    
    ServiceCounterDataType&
    SessionDiagnosticsDataType::setTriggeringCount(void)
    {
        return setTriggeringCount_;
    }
    
    ServiceCounterDataType&
    SessionDiagnosticsDataType::deleteMonitoredItemsCount(void)
    {
        return deleteMonitoredItemsCount_;
    }
    
    ServiceCounterDataType&
    SessionDiagnosticsDataType::createSubscriptionCount(void)
    {
        return createSubscriptionCount_;
    }
    
    ServiceCounterDataType&
    SessionDiagnosticsDataType::modifySubscriptionCount(void)
    {
        return modifySubscriptionCount_;
    }
    
    ServiceCounterDataType&
    SessionDiagnosticsDataType::setPublishingModeCount(void)
    {
        return setPublishingModeCount_;
    }
    
    ServiceCounterDataType&
    SessionDiagnosticsDataType::publishCount(void)
    {
        return publishCount_;
    }
    
    ServiceCounterDataType&
    SessionDiagnosticsDataType::republishCount(void)
    {
        return republishCount_;
    }
    
    ServiceCounterDataType&
    SessionDiagnosticsDataType::transferSubscriptionsCount(void)
    {
        return transferSubscriptionsCount_;
    }
    
    ServiceCounterDataType&
    SessionDiagnosticsDataType::deleteSubscriptionsCount(void)
    {
        return deleteSubscriptionsCount_;
    }
    
    ServiceCounterDataType&
    SessionDiagnosticsDataType::addNodesCount(void)
    {
        return addNodesCount_;
    }
    
    ServiceCounterDataType&
    SessionDiagnosticsDataType::addReferencesCount(void)
    {
        return addReferencesCount_;
    }
    
    ServiceCounterDataType&
    SessionDiagnosticsDataType::deleteNodesCount(void)
    {
        return deleteNodesCount_;
    }
    
    ServiceCounterDataType&
    SessionDiagnosticsDataType::deleteReferencesCount(void)
    {
        return deleteReferencesCount_;
    }
    
    ServiceCounterDataType&
    SessionDiagnosticsDataType::browseCount(void)
    {
        return browseCount_;
    }
    
    ServiceCounterDataType&
    SessionDiagnosticsDataType::browseNextCount(void)
    {
        return browseNextCount_;
    }
    
    ServiceCounterDataType&
    SessionDiagnosticsDataType::translateBrowsePathsToNodeIdsCount(void)
    {
        return translateBrowsePathsToNodeIdsCount_;
    }
    
    ServiceCounterDataType&
    SessionDiagnosticsDataType::queryFirstCount(void)
    {
        return queryFirstCount_;
    }
    
    ServiceCounterDataType&
    SessionDiagnosticsDataType::queryNextCount(void)
    {
        return queryNextCount_;
    }
    
    ServiceCounterDataType&
    SessionDiagnosticsDataType::registerNodesCount(void)
    {
        return registerNodesCount_;
    }
    
    ServiceCounterDataType&
    SessionDiagnosticsDataType::unregisterNodesCount(void)
    {
        return unregisterNodesCount_;
    }
    
    bool
    SessionDiagnosticsDataType::operator==(const SessionDiagnosticsDataType& value)
    {
        SessionDiagnosticsDataType* dst = const_cast<SessionDiagnosticsDataType*>(&value);
        if (sessionId_ != dst->sessionId()) return false;
        if (sessionName_ != dst->sessionName()) return false;
        if (clientDescription_ != dst->clientDescription()) return false;
        if (serverUri_ != dst->serverUri()) return false;
        if (endpointUrl_ != dst->endpointUrl()) return false;
        if (localeIds_ != dst->localeIds()) return false;
        if (actualSessionTimeout_ != dst->actualSessionTimeout()) return false;
        if (maxResponseMessageSize_ != dst->maxResponseMessageSize()) return false;
        if (clientConnectionTime_ != dst->clientConnectionTime()) return false;
        if (clientLastContactTime_ != dst->clientLastContactTime()) return false;
        if (currentSubscriptionsCount_ != dst->currentSubscriptionsCount()) return false;
        if (currentMonitoredItemsCount_ != dst->currentMonitoredItemsCount()) return false;
        if (currentPublishRequestsInQueue_ != dst->currentPublishRequestsInQueue()) return false;
        if (totalRequestCount_ != dst->totalRequestCount()) return false;
        if (unauthorizedRequestCount_ != dst->unauthorizedRequestCount()) return false;
        if (readCount_ != dst->readCount()) return false;
        if (historyReadCount_ != dst->historyReadCount()) return false;
        if (writeCount_ != dst->writeCount()) return false;
        if (historyUpdateCount_ != dst->historyUpdateCount()) return false;
        if (callCount_ != dst->callCount()) return false;
        if (createMonitoredItemsCount_ != dst->createMonitoredItemsCount()) return false;
        if (modifyMonitoredItemsCount_ != dst->modifyMonitoredItemsCount()) return false;
        if (setMonitoringModeCount_ != dst->setMonitoringModeCount()) return false;
        if (setTriggeringCount_ != dst->setTriggeringCount()) return false;
        if (deleteMonitoredItemsCount_ != dst->deleteMonitoredItemsCount()) return false;
        if (createSubscriptionCount_ != dst->createSubscriptionCount()) return false;
        if (modifySubscriptionCount_ != dst->modifySubscriptionCount()) return false;
        if (setPublishingModeCount_ != dst->setPublishingModeCount()) return false;
        if (publishCount_ != dst->publishCount()) return false;
        if (republishCount_ != dst->republishCount()) return false;
        if (transferSubscriptionsCount_ != dst->transferSubscriptionsCount()) return false;
        if (deleteSubscriptionsCount_ != dst->deleteSubscriptionsCount()) return false;
        if (addNodesCount_ != dst->addNodesCount()) return false;
        if (addReferencesCount_ != dst->addReferencesCount()) return false;
        if (deleteNodesCount_ != dst->deleteNodesCount()) return false;
        if (deleteReferencesCount_ != dst->deleteReferencesCount()) return false;
        if (browseCount_ != dst->browseCount()) return false;
        if (browseNextCount_ != dst->browseNextCount()) return false;
        if (translateBrowsePathsToNodeIdsCount_ != dst->translateBrowsePathsToNodeIdsCount()) return false;
        if (queryFirstCount_ != dst->queryFirstCount()) return false;
        if (queryNextCount_ != dst->queryNextCount()) return false;
        if (registerNodesCount_ != dst->registerNodesCount()) return false;
        if (unregisterNodesCount_ != dst->unregisterNodesCount()) return false;
        return true;
    }
    
    bool
    SessionDiagnosticsDataType::operator!=(const SessionDiagnosticsDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    SessionDiagnosticsDataType::copyTo(SessionDiagnosticsDataType& value)
    {
        sessionId_.copyTo(value.sessionId());
        sessionName_.copyTo(value.sessionName());
        clientDescription_.copyTo(value.clientDescription());
        serverUri_.copyTo(value.serverUri());
        endpointUrl_.copyTo(value.endpointUrl());
        localeIds_.copyTo(value.localeIds());
        value.actualSessionTimeout_ = actualSessionTimeout_;
        value.maxResponseMessageSize_ = maxResponseMessageSize_;
        clientConnectionTime_.copyTo(value.clientConnectionTime());
        clientLastContactTime_.copyTo(value.clientLastContactTime());
        value.currentSubscriptionsCount_ = currentSubscriptionsCount_;
        value.currentMonitoredItemsCount_ = currentMonitoredItemsCount_;
        value.currentPublishRequestsInQueue_ = currentPublishRequestsInQueue_;
        totalRequestCount_.copyTo(value.totalRequestCount());
        value.unauthorizedRequestCount_ = unauthorizedRequestCount_;
        readCount_.copyTo(value.readCount());
        historyReadCount_.copyTo(value.historyReadCount());
        writeCount_.copyTo(value.writeCount());
        historyUpdateCount_.copyTo(value.historyUpdateCount());
        callCount_.copyTo(value.callCount());
        createMonitoredItemsCount_.copyTo(value.createMonitoredItemsCount());
        modifyMonitoredItemsCount_.copyTo(value.modifyMonitoredItemsCount());
        setMonitoringModeCount_.copyTo(value.setMonitoringModeCount());
        setTriggeringCount_.copyTo(value.setTriggeringCount());
        deleteMonitoredItemsCount_.copyTo(value.deleteMonitoredItemsCount());
        createSubscriptionCount_.copyTo(value.createSubscriptionCount());
        modifySubscriptionCount_.copyTo(value.modifySubscriptionCount());
        setPublishingModeCount_.copyTo(value.setPublishingModeCount());
        publishCount_.copyTo(value.publishCount());
        republishCount_.copyTo(value.republishCount());
        transferSubscriptionsCount_.copyTo(value.transferSubscriptionsCount());
        deleteSubscriptionsCount_.copyTo(value.deleteSubscriptionsCount());
        addNodesCount_.copyTo(value.addNodesCount());
        addReferencesCount_.copyTo(value.addReferencesCount());
        deleteNodesCount_.copyTo(value.deleteNodesCount());
        deleteReferencesCount_.copyTo(value.deleteReferencesCount());
        browseCount_.copyTo(value.browseCount());
        browseNextCount_.copyTo(value.browseNextCount());
        translateBrowsePathsToNodeIdsCount_.copyTo(value.translateBrowsePathsToNodeIdsCount());
        queryFirstCount_.copyTo(value.queryFirstCount());
        queryNextCount_.copyTo(value.queryNextCount());
        registerNodesCount_.copyTo(value.registerNodesCount());
        unregisterNodesCount_.copyTo(value.unregisterNodesCount());
    }
    
    SessionDiagnosticsDataType&
    SessionDiagnosticsDataType::operator=(const SessionDiagnosticsDataType& value)
    {
        const_cast<SessionDiagnosticsDataType*>(&value)->copyTo(*this);
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
    SessionDiagnosticsDataType::factory(void)
    {
    	return constructSPtr<SessionDiagnosticsDataType>();
    }
    
    std::string
    SessionDiagnosticsDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    SessionDiagnosticsDataType::typeName(void)
    {
    	return "SessionDiagnosticsDataType";
    }
    
    OpcUaNodeId
    SessionDiagnosticsDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)865,0);
    }
    
    OpcUaNodeId
    SessionDiagnosticsDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)867, 0);
    }
    
    OpcUaNodeId
    SessionDiagnosticsDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)866, 0);
    }
    
    OpcUaNodeId
    SessionDiagnosticsDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15368, 0);
    }
    
    void
    SessionDiagnosticsDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        sessionId_.opcUaBinaryEncode(os);
        sessionName_.opcUaBinaryEncode(os);
        clientDescription_.opcUaBinaryEncode(os);
        serverUri_.opcUaBinaryEncode(os);
        endpointUrl_.opcUaBinaryEncode(os);
        localeIds_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,actualSessionTimeout_);
        OpcUaNumber::opcUaBinaryEncode(os,maxResponseMessageSize_);
        clientConnectionTime_.opcUaBinaryEncode(os);
        clientLastContactTime_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,currentSubscriptionsCount_);
        OpcUaNumber::opcUaBinaryEncode(os,currentMonitoredItemsCount_);
        OpcUaNumber::opcUaBinaryEncode(os,currentPublishRequestsInQueue_);
        totalRequestCount_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,unauthorizedRequestCount_);
        readCount_.opcUaBinaryEncode(os);
        historyReadCount_.opcUaBinaryEncode(os);
        writeCount_.opcUaBinaryEncode(os);
        historyUpdateCount_.opcUaBinaryEncode(os);
        callCount_.opcUaBinaryEncode(os);
        createMonitoredItemsCount_.opcUaBinaryEncode(os);
        modifyMonitoredItemsCount_.opcUaBinaryEncode(os);
        setMonitoringModeCount_.opcUaBinaryEncode(os);
        setTriggeringCount_.opcUaBinaryEncode(os);
        deleteMonitoredItemsCount_.opcUaBinaryEncode(os);
        createSubscriptionCount_.opcUaBinaryEncode(os);
        modifySubscriptionCount_.opcUaBinaryEncode(os);
        setPublishingModeCount_.opcUaBinaryEncode(os);
        publishCount_.opcUaBinaryEncode(os);
        republishCount_.opcUaBinaryEncode(os);
        transferSubscriptionsCount_.opcUaBinaryEncode(os);
        deleteSubscriptionsCount_.opcUaBinaryEncode(os);
        addNodesCount_.opcUaBinaryEncode(os);
        addReferencesCount_.opcUaBinaryEncode(os);
        deleteNodesCount_.opcUaBinaryEncode(os);
        deleteReferencesCount_.opcUaBinaryEncode(os);
        browseCount_.opcUaBinaryEncode(os);
        browseNextCount_.opcUaBinaryEncode(os);
        translateBrowsePathsToNodeIdsCount_.opcUaBinaryEncode(os);
        queryFirstCount_.opcUaBinaryEncode(os);
        queryNextCount_.opcUaBinaryEncode(os);
        registerNodesCount_.opcUaBinaryEncode(os);
        unregisterNodesCount_.opcUaBinaryEncode(os);
    }
    
    void
    SessionDiagnosticsDataType::opcUaBinaryDecode(std::istream& is)
    {
        sessionId_.opcUaBinaryDecode(is);
        sessionName_.opcUaBinaryDecode(is);
        clientDescription_.opcUaBinaryDecode(is);
        serverUri_.opcUaBinaryDecode(is);
        endpointUrl_.opcUaBinaryDecode(is);
        localeIds_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,actualSessionTimeout_);
        OpcUaNumber::opcUaBinaryDecode(is,maxResponseMessageSize_);
        clientConnectionTime_.opcUaBinaryDecode(is);
        clientLastContactTime_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,currentSubscriptionsCount_);
        OpcUaNumber::opcUaBinaryDecode(is,currentMonitoredItemsCount_);
        OpcUaNumber::opcUaBinaryDecode(is,currentPublishRequestsInQueue_);
        totalRequestCount_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,unauthorizedRequestCount_);
        readCount_.opcUaBinaryDecode(is);
        historyReadCount_.opcUaBinaryDecode(is);
        writeCount_.opcUaBinaryDecode(is);
        historyUpdateCount_.opcUaBinaryDecode(is);
        callCount_.opcUaBinaryDecode(is);
        createMonitoredItemsCount_.opcUaBinaryDecode(is);
        modifyMonitoredItemsCount_.opcUaBinaryDecode(is);
        setMonitoringModeCount_.opcUaBinaryDecode(is);
        setTriggeringCount_.opcUaBinaryDecode(is);
        deleteMonitoredItemsCount_.opcUaBinaryDecode(is);
        createSubscriptionCount_.opcUaBinaryDecode(is);
        modifySubscriptionCount_.opcUaBinaryDecode(is);
        setPublishingModeCount_.opcUaBinaryDecode(is);
        publishCount_.opcUaBinaryDecode(is);
        republishCount_.opcUaBinaryDecode(is);
        transferSubscriptionsCount_.opcUaBinaryDecode(is);
        deleteSubscriptionsCount_.opcUaBinaryDecode(is);
        addNodesCount_.opcUaBinaryDecode(is);
        addReferencesCount_.opcUaBinaryDecode(is);
        deleteNodesCount_.opcUaBinaryDecode(is);
        deleteReferencesCount_.opcUaBinaryDecode(is);
        browseCount_.opcUaBinaryDecode(is);
        browseNextCount_.opcUaBinaryDecode(is);
        translateBrowsePathsToNodeIdsCount_.opcUaBinaryDecode(is);
        queryFirstCount_.opcUaBinaryDecode(is);
        queryNextCount_.opcUaBinaryDecode(is);
        registerNodesCount_.opcUaBinaryDecode(is);
        unregisterNodesCount_.opcUaBinaryDecode(is);
    }
    
    bool
    SessionDiagnosticsDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    SessionDiagnosticsDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!sessionId_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SessionId", elementTree));
    
        elementTree.clear();
        if (!sessionName_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SessionName", elementTree));
    
        elementTree.clear();
        if (!clientDescription_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ClientDescription", elementTree));
    
        elementTree.clear();
        if (!serverUri_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ServerUri", elementTree));
    
        elementTree.clear();
        if (!endpointUrl_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("EndpointUrl", elementTree));
    
        elementTree.clear();
        if (!localeIds_.xmlEncode(elementTree, "LocaleId", xmlns)) {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("LocaleIds", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, actualSessionTimeout_))
        {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ActualSessionTimeout", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, maxResponseMessageSize_))
        {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("MaxResponseMessageSize", elementTree));
    
        elementTree.clear();
        if (!clientConnectionTime_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ClientConnectionTime", elementTree));
    
        elementTree.clear();
        if (!clientLastContactTime_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ClientLastContactTime", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, currentSubscriptionsCount_))
        {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("CurrentSubscriptionsCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, currentMonitoredItemsCount_))
        {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("CurrentMonitoredItemsCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, currentPublishRequestsInQueue_))
        {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("CurrentPublishRequestsInQueue", elementTree));
    
        elementTree.clear();
        if (!totalRequestCount_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("TotalRequestCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, unauthorizedRequestCount_))
        {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("UnauthorizedRequestCount", elementTree));
    
        elementTree.clear();
        if (!readCount_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ReadCount", elementTree));
    
        elementTree.clear();
        if (!historyReadCount_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("HistoryReadCount", elementTree));
    
        elementTree.clear();
        if (!writeCount_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("WriteCount", elementTree));
    
        elementTree.clear();
        if (!historyUpdateCount_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("HistoryUpdateCount", elementTree));
    
        elementTree.clear();
        if (!callCount_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("CallCount", elementTree));
    
        elementTree.clear();
        if (!createMonitoredItemsCount_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("CreateMonitoredItemsCount", elementTree));
    
        elementTree.clear();
        if (!modifyMonitoredItemsCount_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ModifyMonitoredItemsCount", elementTree));
    
        elementTree.clear();
        if (!setMonitoringModeCount_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SetMonitoringModeCount", elementTree));
    
        elementTree.clear();
        if (!setTriggeringCount_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SetTriggeringCount", elementTree));
    
        elementTree.clear();
        if (!deleteMonitoredItemsCount_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DeleteMonitoredItemsCount", elementTree));
    
        elementTree.clear();
        if (!createSubscriptionCount_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("CreateSubscriptionCount", elementTree));
    
        elementTree.clear();
        if (!modifySubscriptionCount_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ModifySubscriptionCount", elementTree));
    
        elementTree.clear();
        if (!setPublishingModeCount_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SetPublishingModeCount", elementTree));
    
        elementTree.clear();
        if (!publishCount_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("PublishCount", elementTree));
    
        elementTree.clear();
        if (!republishCount_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("RepublishCount", elementTree));
    
        elementTree.clear();
        if (!transferSubscriptionsCount_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("TransferSubscriptionsCount", elementTree));
    
        elementTree.clear();
        if (!deleteSubscriptionsCount_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DeleteSubscriptionsCount", elementTree));
    
        elementTree.clear();
        if (!addNodesCount_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("AddNodesCount", elementTree));
    
        elementTree.clear();
        if (!addReferencesCount_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("AddReferencesCount", elementTree));
    
        elementTree.clear();
        if (!deleteNodesCount_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DeleteNodesCount", elementTree));
    
        elementTree.clear();
        if (!deleteReferencesCount_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DeleteReferencesCount", elementTree));
    
        elementTree.clear();
        if (!browseCount_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("BrowseCount", elementTree));
    
        elementTree.clear();
        if (!browseNextCount_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("BrowseNextCount", elementTree));
    
        elementTree.clear();
        if (!translateBrowsePathsToNodeIdsCount_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("TranslateBrowsePathsToNodeIdsCount", elementTree));
    
        elementTree.clear();
        if (!queryFirstCount_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("QueryFirstCount", elementTree));
    
        elementTree.clear();
        if (!queryNextCount_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("QueryNextCount", elementTree));
    
        elementTree.clear();
        if (!registerNodesCount_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("RegisterNodesCount", elementTree));
    
        elementTree.clear();
        if (!unregisterNodesCount_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("UnregisterNodesCount", elementTree));
    
        return true;
    }
    
    bool
    SessionDiagnosticsDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    SessionDiagnosticsDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("SessionId");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!sessionId_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "SessionId");
            return false;
        }
    
        elementName = xmlns.addPrefix("SessionName");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!sessionName_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "SessionName");
            return false;
        }
    
        elementName = xmlns.addPrefix("ClientDescription");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!clientDescription_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "ClientDescription");
            return false;
        }
    
        elementName = xmlns.addPrefix("ServerUri");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!serverUri_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "ServerUri");
            return false;
        }
    
        elementName = xmlns.addPrefix("EndpointUrl");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!endpointUrl_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "EndpointUrl");
            return false;
        }
    
        elementName = xmlns.addPrefix("LocaleIds");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!localeIds_.xmlDecode(*tree, "LocaleId", xmlns)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("ActualSessionTimeout");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, actualSessionTimeout_)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("MaxResponseMessageSize");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, maxResponseMessageSize_)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("ClientConnectionTime");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!clientConnectionTime_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "ClientConnectionTime");
            return false;
        }
    
        elementName = xmlns.addPrefix("ClientLastContactTime");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!clientLastContactTime_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "ClientLastContactTime");
            return false;
        }
    
        elementName = xmlns.addPrefix("CurrentSubscriptionsCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, currentSubscriptionsCount_)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("CurrentMonitoredItemsCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, currentMonitoredItemsCount_)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("CurrentPublishRequestsInQueue");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, currentPublishRequestsInQueue_)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("TotalRequestCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!totalRequestCount_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "TotalRequestCount");
            return false;
        }
    
        elementName = xmlns.addPrefix("UnauthorizedRequestCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, unauthorizedRequestCount_)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("ReadCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!readCount_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "ReadCount");
            return false;
        }
    
        elementName = xmlns.addPrefix("HistoryReadCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!historyReadCount_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "HistoryReadCount");
            return false;
        }
    
        elementName = xmlns.addPrefix("WriteCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!writeCount_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "WriteCount");
            return false;
        }
    
        elementName = xmlns.addPrefix("HistoryUpdateCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!historyUpdateCount_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "HistoryUpdateCount");
            return false;
        }
    
        elementName = xmlns.addPrefix("CallCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!callCount_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "CallCount");
            return false;
        }
    
        elementName = xmlns.addPrefix("CreateMonitoredItemsCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!createMonitoredItemsCount_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "CreateMonitoredItemsCount");
            return false;
        }
    
        elementName = xmlns.addPrefix("ModifyMonitoredItemsCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!modifyMonitoredItemsCount_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "ModifyMonitoredItemsCount");
            return false;
        }
    
        elementName = xmlns.addPrefix("SetMonitoringModeCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!setMonitoringModeCount_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "SetMonitoringModeCount");
            return false;
        }
    
        elementName = xmlns.addPrefix("SetTriggeringCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!setTriggeringCount_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "SetTriggeringCount");
            return false;
        }
    
        elementName = xmlns.addPrefix("DeleteMonitoredItemsCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!deleteMonitoredItemsCount_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "DeleteMonitoredItemsCount");
            return false;
        }
    
        elementName = xmlns.addPrefix("CreateSubscriptionCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!createSubscriptionCount_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "CreateSubscriptionCount");
            return false;
        }
    
        elementName = xmlns.addPrefix("ModifySubscriptionCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!modifySubscriptionCount_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "ModifySubscriptionCount");
            return false;
        }
    
        elementName = xmlns.addPrefix("SetPublishingModeCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!setPublishingModeCount_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "SetPublishingModeCount");
            return false;
        }
    
        elementName = xmlns.addPrefix("PublishCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!publishCount_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "PublishCount");
            return false;
        }
    
        elementName = xmlns.addPrefix("RepublishCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!republishCount_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "RepublishCount");
            return false;
        }
    
        elementName = xmlns.addPrefix("TransferSubscriptionsCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!transferSubscriptionsCount_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "TransferSubscriptionsCount");
            return false;
        }
    
        elementName = xmlns.addPrefix("DeleteSubscriptionsCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!deleteSubscriptionsCount_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "DeleteSubscriptionsCount");
            return false;
        }
    
        elementName = xmlns.addPrefix("AddNodesCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!addNodesCount_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "AddNodesCount");
            return false;
        }
    
        elementName = xmlns.addPrefix("AddReferencesCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!addReferencesCount_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "AddReferencesCount");
            return false;
        }
    
        elementName = xmlns.addPrefix("DeleteNodesCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!deleteNodesCount_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "DeleteNodesCount");
            return false;
        }
    
        elementName = xmlns.addPrefix("DeleteReferencesCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!deleteReferencesCount_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "DeleteReferencesCount");
            return false;
        }
    
        elementName = xmlns.addPrefix("BrowseCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!browseCount_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "BrowseCount");
            return false;
        }
    
        elementName = xmlns.addPrefix("BrowseNextCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!browseNextCount_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "BrowseNextCount");
            return false;
        }
    
        elementName = xmlns.addPrefix("TranslateBrowsePathsToNodeIdsCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!translateBrowsePathsToNodeIdsCount_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "TranslateBrowsePathsToNodeIdsCount");
            return false;
        }
    
        elementName = xmlns.addPrefix("QueryFirstCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!queryFirstCount_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "QueryFirstCount");
            return false;
        }
    
        elementName = xmlns.addPrefix("QueryNextCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!queryNextCount_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "QueryNextCount");
            return false;
        }
    
        elementName = xmlns.addPrefix("RegisterNodesCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!registerNodesCount_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "RegisterNodesCount");
            return false;
        }
    
        elementName = xmlns.addPrefix("UnregisterNodesCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!unregisterNodesCount_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "UnregisterNodesCount");
            return false;
        }
    
        return true;
    }
    
    bool
    SessionDiagnosticsDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!sessionId_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "sessionId_");
            return false;
        }
        pt.push_back(std::make_pair("SessionId", elementTree));
    
        elementTree.clear();
        if (!sessionName_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "sessionName_");
            return false;
        }
        pt.push_back(std::make_pair("SessionName", elementTree));
    
        elementTree.clear();
        if (!clientDescription_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "clientDescription_");
            return false;
        }
        pt.push_back(std::make_pair("ClientDescription", elementTree));
    
        elementTree.clear();
        if (!serverUri_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "serverUri_");
            return false;
        }
        pt.push_back(std::make_pair("ServerUri", elementTree));
    
        elementTree.clear();
        if (!endpointUrl_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "endpointUrl_");
            return false;
        }
        pt.push_back(std::make_pair("EndpointUrl", elementTree));
    
        elementTree.clear();
        if (!localeIds_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "localeIds_");
            return false;
        }
        pt.push_back(std::make_pair("LocaleIds", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, actualSessionTimeout_))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "actualSessionTimeout_");
           return false;
        }
        pt.push_back(std::make_pair("ActualSessionTimeout", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, maxResponseMessageSize_))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "maxResponseMessageSize_");
           return false;
        }
        pt.push_back(std::make_pair("MaxResponseMessageSize", elementTree));
    
        elementTree.clear();
        if (!clientConnectionTime_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "clientConnectionTime_");
            return false;
        }
        pt.push_back(std::make_pair("ClientConnectionTime", elementTree));
    
        elementTree.clear();
        if (!clientLastContactTime_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "clientLastContactTime_");
            return false;
        }
        pt.push_back(std::make_pair("ClientLastContactTime", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, currentSubscriptionsCount_))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "currentSubscriptionsCount_");
           return false;
        }
        pt.push_back(std::make_pair("CurrentSubscriptionsCount", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, currentMonitoredItemsCount_))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "currentMonitoredItemsCount_");
           return false;
        }
        pt.push_back(std::make_pair("CurrentMonitoredItemsCount", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, currentPublishRequestsInQueue_))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "currentPublishRequestsInQueue_");
           return false;
        }
        pt.push_back(std::make_pair("CurrentPublishRequestsInQueue", elementTree));
    
        elementTree.clear();
        if (!totalRequestCount_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "totalRequestCount_");
            return false;
        }
        pt.push_back(std::make_pair("TotalRequestCount", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, unauthorizedRequestCount_))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "unauthorizedRequestCount_");
           return false;
        }
        pt.push_back(std::make_pair("UnauthorizedRequestCount", elementTree));
    
        elementTree.clear();
        if (!readCount_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "readCount_");
            return false;
        }
        pt.push_back(std::make_pair("ReadCount", elementTree));
    
        elementTree.clear();
        if (!historyReadCount_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "historyReadCount_");
            return false;
        }
        pt.push_back(std::make_pair("HistoryReadCount", elementTree));
    
        elementTree.clear();
        if (!writeCount_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "writeCount_");
            return false;
        }
        pt.push_back(std::make_pair("WriteCount", elementTree));
    
        elementTree.clear();
        if (!historyUpdateCount_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "historyUpdateCount_");
            return false;
        }
        pt.push_back(std::make_pair("HistoryUpdateCount", elementTree));
    
        elementTree.clear();
        if (!callCount_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "callCount_");
            return false;
        }
        pt.push_back(std::make_pair("CallCount", elementTree));
    
        elementTree.clear();
        if (!createMonitoredItemsCount_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "createMonitoredItemsCount_");
            return false;
        }
        pt.push_back(std::make_pair("CreateMonitoredItemsCount", elementTree));
    
        elementTree.clear();
        if (!modifyMonitoredItemsCount_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "modifyMonitoredItemsCount_");
            return false;
        }
        pt.push_back(std::make_pair("ModifyMonitoredItemsCount", elementTree));
    
        elementTree.clear();
        if (!setMonitoringModeCount_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "setMonitoringModeCount_");
            return false;
        }
        pt.push_back(std::make_pair("SetMonitoringModeCount", elementTree));
    
        elementTree.clear();
        if (!setTriggeringCount_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "setTriggeringCount_");
            return false;
        }
        pt.push_back(std::make_pair("SetTriggeringCount", elementTree));
    
        elementTree.clear();
        if (!deleteMonitoredItemsCount_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "deleteMonitoredItemsCount_");
            return false;
        }
        pt.push_back(std::make_pair("DeleteMonitoredItemsCount", elementTree));
    
        elementTree.clear();
        if (!createSubscriptionCount_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "createSubscriptionCount_");
            return false;
        }
        pt.push_back(std::make_pair("CreateSubscriptionCount", elementTree));
    
        elementTree.clear();
        if (!modifySubscriptionCount_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "modifySubscriptionCount_");
            return false;
        }
        pt.push_back(std::make_pair("ModifySubscriptionCount", elementTree));
    
        elementTree.clear();
        if (!setPublishingModeCount_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "setPublishingModeCount_");
            return false;
        }
        pt.push_back(std::make_pair("SetPublishingModeCount", elementTree));
    
        elementTree.clear();
        if (!publishCount_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "publishCount_");
            return false;
        }
        pt.push_back(std::make_pair("PublishCount", elementTree));
    
        elementTree.clear();
        if (!republishCount_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "republishCount_");
            return false;
        }
        pt.push_back(std::make_pair("RepublishCount", elementTree));
    
        elementTree.clear();
        if (!transferSubscriptionsCount_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "transferSubscriptionsCount_");
            return false;
        }
        pt.push_back(std::make_pair("TransferSubscriptionsCount", elementTree));
    
        elementTree.clear();
        if (!deleteSubscriptionsCount_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "deleteSubscriptionsCount_");
            return false;
        }
        pt.push_back(std::make_pair("DeleteSubscriptionsCount", elementTree));
    
        elementTree.clear();
        if (!addNodesCount_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "addNodesCount_");
            return false;
        }
        pt.push_back(std::make_pair("AddNodesCount", elementTree));
    
        elementTree.clear();
        if (!addReferencesCount_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "addReferencesCount_");
            return false;
        }
        pt.push_back(std::make_pair("AddReferencesCount", elementTree));
    
        elementTree.clear();
        if (!deleteNodesCount_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "deleteNodesCount_");
            return false;
        }
        pt.push_back(std::make_pair("DeleteNodesCount", elementTree));
    
        elementTree.clear();
        if (!deleteReferencesCount_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "deleteReferencesCount_");
            return false;
        }
        pt.push_back(std::make_pair("DeleteReferencesCount", elementTree));
    
        elementTree.clear();
        if (!browseCount_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "browseCount_");
            return false;
        }
        pt.push_back(std::make_pair("BrowseCount", elementTree));
    
        elementTree.clear();
        if (!browseNextCount_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "browseNextCount_");
            return false;
        }
        pt.push_back(std::make_pair("BrowseNextCount", elementTree));
    
        elementTree.clear();
        if (!translateBrowsePathsToNodeIdsCount_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "translateBrowsePathsToNodeIdsCount_");
            return false;
        }
        pt.push_back(std::make_pair("TranslateBrowsePathsToNodeIdsCount", elementTree));
    
        elementTree.clear();
        if (!queryFirstCount_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "queryFirstCount_");
            return false;
        }
        pt.push_back(std::make_pair("QueryFirstCount", elementTree));
    
        elementTree.clear();
        if (!queryNextCount_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "queryNextCount_");
            return false;
        }
        pt.push_back(std::make_pair("QueryNextCount", elementTree));
    
        elementTree.clear();
        if (!registerNodesCount_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "registerNodesCount_");
            return false;
        }
        pt.push_back(std::make_pair("RegisterNodesCount", elementTree));
    
        elementTree.clear();
        if (!unregisterNodesCount_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionDiagnosticsDataType json encoder error")
    		     .parameter("Element", "unregisterNodesCount_");
            return false;
        }
        pt.push_back(std::make_pair("UnregisterNodesCount", elementTree));
    
        return true;
    }
    
    bool
    SessionDiagnosticsDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "SessionId";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!sessionId_.jsonDecode(*tree)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "SessionId");
            return false;
        }
    
        elementName = "SessionName";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!sessionName_.jsonDecode(*tree)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "SessionName");
            return false;
        }
    
        elementName = "ClientDescription";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!clientDescription_.jsonDecode(*tree)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "ClientDescription");
            return false;
        }
    
        elementName = "ServerUri";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!serverUri_.jsonDecode(*tree)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "ServerUri");
            return false;
        }
    
        elementName = "EndpointUrl";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!endpointUrl_.jsonDecode(*tree)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "EndpointUrl");
            return false;
        }
    
        elementName = "LocaleIds";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!localeIds_.jsonDecode(*tree, "")) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "ActualSessionTimeout";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, actualSessionTimeout_)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "MaxResponseMessageSize";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, maxResponseMessageSize_)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "ClientConnectionTime";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!clientConnectionTime_.jsonDecode(*tree)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "ClientConnectionTime");
            return false;
        }
    
        elementName = "ClientLastContactTime";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!clientLastContactTime_.jsonDecode(*tree)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "ClientLastContactTime");
            return false;
        }
    
        elementName = "CurrentSubscriptionsCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, currentSubscriptionsCount_)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "CurrentMonitoredItemsCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, currentMonitoredItemsCount_)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "CurrentPublishRequestsInQueue";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, currentPublishRequestsInQueue_)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "TotalRequestCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!totalRequestCount_.jsonDecode(*tree)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "TotalRequestCount");
            return false;
        }
    
        elementName = "UnauthorizedRequestCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, unauthorizedRequestCount_)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "ReadCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!readCount_.jsonDecode(*tree)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "ReadCount");
            return false;
        }
    
        elementName = "HistoryReadCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!historyReadCount_.jsonDecode(*tree)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "HistoryReadCount");
            return false;
        }
    
        elementName = "WriteCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!writeCount_.jsonDecode(*tree)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "WriteCount");
            return false;
        }
    
        elementName = "HistoryUpdateCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!historyUpdateCount_.jsonDecode(*tree)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "HistoryUpdateCount");
            return false;
        }
    
        elementName = "CallCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!callCount_.jsonDecode(*tree)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "CallCount");
            return false;
        }
    
        elementName = "CreateMonitoredItemsCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!createMonitoredItemsCount_.jsonDecode(*tree)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "CreateMonitoredItemsCount");
            return false;
        }
    
        elementName = "ModifyMonitoredItemsCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!modifyMonitoredItemsCount_.jsonDecode(*tree)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "ModifyMonitoredItemsCount");
            return false;
        }
    
        elementName = "SetMonitoringModeCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!setMonitoringModeCount_.jsonDecode(*tree)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "SetMonitoringModeCount");
            return false;
        }
    
        elementName = "SetTriggeringCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!setTriggeringCount_.jsonDecode(*tree)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "SetTriggeringCount");
            return false;
        }
    
        elementName = "DeleteMonitoredItemsCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!deleteMonitoredItemsCount_.jsonDecode(*tree)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "DeleteMonitoredItemsCount");
            return false;
        }
    
        elementName = "CreateSubscriptionCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!createSubscriptionCount_.jsonDecode(*tree)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "CreateSubscriptionCount");
            return false;
        }
    
        elementName = "ModifySubscriptionCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!modifySubscriptionCount_.jsonDecode(*tree)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "ModifySubscriptionCount");
            return false;
        }
    
        elementName = "SetPublishingModeCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!setPublishingModeCount_.jsonDecode(*tree)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "SetPublishingModeCount");
            return false;
        }
    
        elementName = "PublishCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!publishCount_.jsonDecode(*tree)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "PublishCount");
            return false;
        }
    
        elementName = "RepublishCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!republishCount_.jsonDecode(*tree)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "RepublishCount");
            return false;
        }
    
        elementName = "TransferSubscriptionsCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!transferSubscriptionsCount_.jsonDecode(*tree)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "TransferSubscriptionsCount");
            return false;
        }
    
        elementName = "DeleteSubscriptionsCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!deleteSubscriptionsCount_.jsonDecode(*tree)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "DeleteSubscriptionsCount");
            return false;
        }
    
        elementName = "AddNodesCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!addNodesCount_.jsonDecode(*tree)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "AddNodesCount");
            return false;
        }
    
        elementName = "AddReferencesCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!addReferencesCount_.jsonDecode(*tree)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "AddReferencesCount");
            return false;
        }
    
        elementName = "DeleteNodesCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!deleteNodesCount_.jsonDecode(*tree)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "DeleteNodesCount");
            return false;
        }
    
        elementName = "DeleteReferencesCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!deleteReferencesCount_.jsonDecode(*tree)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "DeleteReferencesCount");
            return false;
        }
    
        elementName = "BrowseCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!browseCount_.jsonDecode(*tree)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "BrowseCount");
            return false;
        }
    
        elementName = "BrowseNextCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!browseNextCount_.jsonDecode(*tree)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "BrowseNextCount");
            return false;
        }
    
        elementName = "TranslateBrowsePathsToNodeIdsCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!translateBrowsePathsToNodeIdsCount_.jsonDecode(*tree)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "TranslateBrowsePathsToNodeIdsCount");
            return false;
        }
    
        elementName = "QueryFirstCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!queryFirstCount_.jsonDecode(*tree)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "QueryFirstCount");
            return false;
        }
    
        elementName = "QueryNextCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!queryNextCount_.jsonDecode(*tree)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "QueryNextCount");
            return false;
        }
    
        elementName = "RegisterNodesCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!registerNodesCount_.jsonDecode(*tree)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "RegisterNodesCount");
            return false;
        }
    
        elementName = "UnregisterNodesCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!unregisterNodesCount_.jsonDecode(*tree)) {
            Log(Error, "SessionDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "UnregisterNodesCount");
            return false;
        }
    
        return true;
    }
    
    void
    SessionDiagnosticsDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	SessionDiagnosticsDataType* dst = dynamic_cast<SessionDiagnosticsDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    SessionDiagnosticsDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	SessionDiagnosticsDataType* dst = dynamic_cast<SessionDiagnosticsDataType*>(&extensionObjectBase);
    	return *const_cast<SessionDiagnosticsDataType*>(this) == *dst;
    }
    
    void
    SessionDiagnosticsDataType::out(std::ostream& os)
    {
        os << "SessionId="; sessionId_.out(os);
        os << ", SessionName="; sessionName_.out(os);
        os << ", ClientDescription="; clientDescription_.out(os);
        os << ", ServerUri="; serverUri_.out(os);
        os << ", EndpointUrl="; endpointUrl_.out(os);
        os << ", LocaleIds="; localeIds_.out(os);
        os << ", ActualSessionTimeout=" << actualSessionTimeout_;
        os << ", MaxResponseMessageSize=" << maxResponseMessageSize_;
        os << ", ClientConnectionTime="; clientConnectionTime_.out(os);
        os << ", ClientLastContactTime="; clientLastContactTime_.out(os);
        os << ", CurrentSubscriptionsCount=" << currentSubscriptionsCount_;
        os << ", CurrentMonitoredItemsCount=" << currentMonitoredItemsCount_;
        os << ", CurrentPublishRequestsInQueue=" << currentPublishRequestsInQueue_;
        os << ", TotalRequestCount="; totalRequestCount_.out(os);
        os << ", UnauthorizedRequestCount=" << unauthorizedRequestCount_;
        os << ", ReadCount="; readCount_.out(os);
        os << ", HistoryReadCount="; historyReadCount_.out(os);
        os << ", WriteCount="; writeCount_.out(os);
        os << ", HistoryUpdateCount="; historyUpdateCount_.out(os);
        os << ", CallCount="; callCount_.out(os);
        os << ", CreateMonitoredItemsCount="; createMonitoredItemsCount_.out(os);
        os << ", ModifyMonitoredItemsCount="; modifyMonitoredItemsCount_.out(os);
        os << ", SetMonitoringModeCount="; setMonitoringModeCount_.out(os);
        os << ", SetTriggeringCount="; setTriggeringCount_.out(os);
        os << ", DeleteMonitoredItemsCount="; deleteMonitoredItemsCount_.out(os);
        os << ", CreateSubscriptionCount="; createSubscriptionCount_.out(os);
        os << ", ModifySubscriptionCount="; modifySubscriptionCount_.out(os);
        os << ", SetPublishingModeCount="; setPublishingModeCount_.out(os);
        os << ", PublishCount="; publishCount_.out(os);
        os << ", RepublishCount="; republishCount_.out(os);
        os << ", TransferSubscriptionsCount="; transferSubscriptionsCount_.out(os);
        os << ", DeleteSubscriptionsCount="; deleteSubscriptionsCount_.out(os);
        os << ", AddNodesCount="; addNodesCount_.out(os);
        os << ", AddReferencesCount="; addReferencesCount_.out(os);
        os << ", DeleteNodesCount="; deleteNodesCount_.out(os);
        os << ", DeleteReferencesCount="; deleteReferencesCount_.out(os);
        os << ", BrowseCount="; browseCount_.out(os);
        os << ", BrowseNextCount="; browseNextCount_.out(os);
        os << ", TranslateBrowsePathsToNodeIdsCount="; translateBrowsePathsToNodeIdsCount_.out(os);
        os << ", QueryFirstCount="; queryFirstCount_.out(os);
        os << ", QueryNextCount="; queryNextCount_.out(os);
        os << ", RegisterNodesCount="; registerNodesCount_.out(os);
        os << ", UnregisterNodesCount="; unregisterNodesCount_.out(os);
    }

}
