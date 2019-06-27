/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Samuel Huebl (samuel.huebl@asneg.de)
 */

#include "OpcUaStackCore/StandardDataTypes/SessionDiagnosticsDataType.h"

namespace OpcUaStackCore
{

	SessionDiagnosticsDataType::SessionDiagnosticsDataType(void)
	: Object()
	, sessionId_()
	, sessionName_()
	, clientDescription_(constructSPtr<ApplicationDescription>())
	, serverUri_()
	, endpointUri_()
	, localeIds_(constructSPtr<OpcUaStringArray>())
	, actualSessionTimeout_()
	, maxResponseMessageSize_()
	, clientConnectionTime_()
	, clientLastContactTime_()
	, currentSubscriptionsCount_()
	, currentMonitoredItemsCount_()
	, currentPublishRequestsInQueue_()
	, currentPublishTimerExpirations_()
	{
	}

	SessionDiagnosticsDataType::~SessionDiagnosticsDataType(void)
	{
	}

	OpcUaNodeId&
	SessionDiagnosticsDataType::sessionId(void)
	{
		return sessionId_;
	}

	void
	SessionDiagnosticsDataType::sessionId(OpcUaNodeId sessionId)
	{
		sessionId_ = sessionId;
	}

	OpcUaString&
	SessionDiagnosticsDataType::sessionName(void)
	{
		return sessionName_;
	}

	void
	SessionDiagnosticsDataType::sessionName(OpcUaString sessionName)
	{
		sessionName_ = sessionName;
	}

	ApplicationDescription::SPtr
	SessionDiagnosticsDataType::clientDescription(void)
	{
		return clientDescription_;
	}

	void
	SessionDiagnosticsDataType::clientDescription(ApplicationDescription::SPtr clientDescription)
	{
		clientDescription_ = clientDescription;
	}

	OpcUaString&
	SessionDiagnosticsDataType::serverUri(void)
	{
		return serverUri_;
	}

	void
	SessionDiagnosticsDataType::serverUri(OpcUaString serverUri)
	{
		serverUri_ = serverUri;
	}

	OpcUaString&
	SessionDiagnosticsDataType::endpointUri(void)
	{
		return endpointUri_;
	}

	void
	SessionDiagnosticsDataType::endpointUri(OpcUaString endpointUri)
	{
		endpointUri_ = endpointUri;
	}

	OpcUaStringArray::SPtr
	SessionDiagnosticsDataType::localeIds(void)
	{
		return localeIds_;
	}

	void
	SessionDiagnosticsDataType::localeIds(OpcUaStringArray::SPtr localeIds)
	{
		localeIds_ = localeIds;
	}

	OpcUaDouble&
	SessionDiagnosticsDataType::actualSessionTimeout(void)
	{
		return actualSessionTimeout_;
	}

	void
	SessionDiagnosticsDataType::actualSessionTimeout(OpcUaDouble actualSessionTimeout)
	{
		actualSessionTimeout_ = actualSessionTimeout;
	}

	OpcUaUInt32&
	SessionDiagnosticsDataType::maxResponseMessageSize(void)
	{
		return maxResponseMessageSize_;
	}

	void
	SessionDiagnosticsDataType::maxResponseMessageSize(OpcUaUInt32 maxResponseMessageSize)
	{
		maxResponseMessageSize_ = maxResponseMessageSize;
	}

	OpcUaDateTime&
	SessionDiagnosticsDataType::clientConnectionTime(void)
	{
		return clientConnectionTime_;
	}

	void
	SessionDiagnosticsDataType::clientConnectionTime(OpcUaDateTime clientConnectionTime)
	{
		clientConnectionTime_ = clientConnectionTime;
	}

	OpcUaDateTime&
	SessionDiagnosticsDataType::clientLastContactTime(void)
	{
		return clientLastContactTime_;
	}

	void
	SessionDiagnosticsDataType::clientLastContactTime(OpcUaDateTime clientLastContactTime)
	{
		clientLastContactTime_ = clientLastContactTime;
	}

	OpcUaUInt32&
	SessionDiagnosticsDataType::currentSubscriptionsCount(void)
	{
		return currentSubscriptionsCount_;
	}

	void
	SessionDiagnosticsDataType::currentSubscriptionsCount(OpcUaUInt32 currentSubscriptionsCount)
	{
		currentSubscriptionsCount_ = currentSubscriptionsCount;
	}

	OpcUaUInt32&
	SessionDiagnosticsDataType::currentMonitoredItemsCount(void)
	{
		return currentMonitoredItemsCount_;
	}

	void
	SessionDiagnosticsDataType::currentMonitoredItemsCount(OpcUaUInt32 currentMonitoredItemsCount)
	{
		currentMonitoredItemsCount_ = currentMonitoredItemsCount;
	}

	OpcUaUInt32&
	SessionDiagnosticsDataType::currentPublishRequestsInQueue(void)
	{
		return currentPublishRequestsInQueue_;
	}

	void
	SessionDiagnosticsDataType::currentPublishRequestsInQueue(OpcUaUInt32 currentPublishRequestsInQueue)
	{
		currentPublishRequestsInQueue_ = currentPublishRequestsInQueue;
	}

	OpcUaUInt32&
	SessionDiagnosticsDataType::currentPublishTimerExpirations(void)
	{
		return currentPublishTimerExpirations_;
	}

	void
	SessionDiagnosticsDataType::currentPublishTimerExpirations(OpcUaUInt32 currentPublishTimerExpirations)
	{
		currentPublishTimerExpirations_ = currentPublishTimerExpirations;
	}

	void
	SessionDiagnosticsDataType::copyTo(SessionDiagnosticsDataType& sessionDiagnosticsDataType)
	{
		sessionId_.copyTo(sessionDiagnosticsDataType.sessionId());
		sessionName_.copyTo(sessionDiagnosticsDataType.sessionName());
		clientDescription_->copyTo(*sessionDiagnosticsDataType.clientDescription());
		serverUri_.copyTo(sessionDiagnosticsDataType.serverUri());
		endpointUri_.copyTo(sessionDiagnosticsDataType.endpointUri());
		localeIds_->copyTo(*sessionDiagnosticsDataType.localeIds());
		sessionDiagnosticsDataType.actualSessionTimeout(actualSessionTimeout_);
		sessionDiagnosticsDataType.maxResponseMessageSize(maxResponseMessageSize_);
		clientConnectionTime_.copyTo(sessionDiagnosticsDataType.clientConnectionTime());
		clientLastContactTime_.copyTo(sessionDiagnosticsDataType.clientLastContactTime());
		sessionDiagnosticsDataType.currentSubscriptionsCount(currentSubscriptionsCount_);
		sessionDiagnosticsDataType.currentMonitoredItemsCount(currentMonitoredItemsCount_);
		sessionDiagnosticsDataType.currentPublishRequestsInQueue(currentPublishRequestsInQueue_);
		sessionDiagnosticsDataType.currentPublishTimerExpirations(currentPublishTimerExpirations_);
	}

	bool
	SessionDiagnosticsDataType::operator==(const SessionDiagnosticsDataType& sessionDiagnosticsDataType) const
	{
		SessionDiagnosticsDataType* dst = const_cast<SessionDiagnosticsDataType*>(&sessionDiagnosticsDataType);
		return
			sessionId_ == dst->sessionId() &&
			sessionName_ == dst->sessionName() &&
			clientDescription_ == dst->clientDescription() &&
			serverUri_ == dst->serverUri() &&
			endpointUri_ == dst->endpointUri() &&
			// FIXME: localeIds_ == dst->localeIds() &&
			actualSessionTimeout_ == dst->actualSessionTimeout() &&
			maxResponseMessageSize_ == dst->maxResponseMessageSize() &&
			clientConnectionTime_ == dst->clientConnectionTime() &&
			clientLastContactTime_ == dst->clientLastContactTime() &&
			currentSubscriptionsCount_ == dst->currentSubscriptionsCount() &&
			currentMonitoredItemsCount_ == dst->currentMonitoredItemsCount() &&
			currentPublishRequestsInQueue_ == dst->currentPublishRequestsInQueue() &&
			currentPublishTimerExpirations_ == dst->currentPublishTimerExpirations();
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

	void
	SessionDiagnosticsDataType::opcUaBinaryEncode(std::ostream& os) const
	{
		sessionId_.opcUaBinaryEncode(os);
		sessionName_.opcUaBinaryEncode(os);
		clientDescription_->opcUaBinaryEncode(os);
		serverUri_.opcUaBinaryEncode(os);
		endpointUri_.opcUaBinaryEncode(os);
		localeIds_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, actualSessionTimeout_);
		OpcUaNumber::opcUaBinaryEncode(os, maxResponseMessageSize_);
		clientConnectionTime_.opcUaBinaryEncode(os);
		clientLastContactTime_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, currentSubscriptionsCount_);
		OpcUaNumber::opcUaBinaryEncode(os, currentMonitoredItemsCount_);
		OpcUaNumber::opcUaBinaryEncode(os, currentPublishRequestsInQueue_);
		OpcUaNumber::opcUaBinaryEncode(os, currentPublishTimerExpirations_);
	}

	void
	SessionDiagnosticsDataType::opcUaBinaryDecode(std::istream& is)
	{
		sessionId_.opcUaBinaryDecode(is);
		sessionName_.opcUaBinaryDecode(is);
		clientDescription_->opcUaBinaryDecode(is);
		serverUri_.opcUaBinaryDecode(is);
		endpointUri_.opcUaBinaryDecode(is);
		localeIds_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, actualSessionTimeout_);
		OpcUaNumber::opcUaBinaryDecode(is, maxResponseMessageSize_);
		clientConnectionTime_.opcUaBinaryDecode(is);
		clientLastContactTime_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, currentSubscriptionsCount_);
		OpcUaNumber::opcUaBinaryDecode(is, currentMonitoredItemsCount_);
		OpcUaNumber::opcUaBinaryDecode(is, currentPublishRequestsInQueue_);
		OpcUaNumber::opcUaBinaryDecode(is, currentPublishTimerExpirations_);
	}

	bool
	SessionDiagnosticsDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
	{
		// FIXME: todo
		return false;
	}

	bool
	SessionDiagnosticsDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return false;
	}

	bool
	SessionDiagnosticsDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return false;
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
		return *this == *dst;
	}

	void
	SessionDiagnosticsDataType::out(std::ostream& os)
	{
		os << "SessionId=" << sessionId_;
		os << ", SessionName="; sessionName_.out(os);
		os << ", ClientDescription="; clientDescription_->out(os);
		os << ", ServerUri="; serverUri_.out(os);
		os << ", EndpointUri="; endpointUri_.out(os);
		os << ", LocaleIds="; localeIds_->out(os);
		os << ", ActualSessionTimeout=" << actualSessionTimeout_;
		os << ", MaxResponseMessageSize=" << maxResponseMessageSize_;
		os << ", ClientConnetionTime="; clientConnectionTime_.out(os);
		os << ", ClientLastContactTime="; clientLastContactTime_.out(os);
		os << ", CurrentSubscriptionsCount=" << currentSubscriptionsCount_;
		os << ", CurrentMonitoredItemsCount=" << currentMonitoredItemsCount_;
		os << ", CurrentPublishRequestsInQueue=" << currentPublishRequestsInQueue_;
		os << ", CurrentPublishTimerExpirations=" << currentPublishTimerExpirations_;
	}

}

