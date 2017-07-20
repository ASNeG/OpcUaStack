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

#include "OpcUaStackCore/StandardDataTypes/ServerDiagnosticsSummaryDataType.h"

namespace OpcUaStackCore
{

	ServerDiagnosticsSummaryDataType::ServerDiagnosticsSummaryDataType(void)
	: Object()
	, serverViewCount_()
	, currentSessionCount_()
	, cumulatedSessionCount_()
	, securityRejectedSessionCount_()
	, rejectedSessionCount_()
	, sessionTimeoutCount_()
	, sessionAbortCount_()
	, samplingRateCount_()
	, publishingIntervalCount_()
	, currentSubscriptionCount_()
	, cumulatedSubscriptionCount_()
	, securityRejectedRequestsCount_()
	, rejectedRequestsCount_()
	{
	}

	ServerDiagnosticsSummaryDataType::~ServerDiagnosticsSummaryDataType(void)
	{
	}

	OpcUaUInt32&
	ServerDiagnosticsSummaryDataType::serverViewCount(void)
	{
		return serverViewCount_;
	}

	void
	ServerDiagnosticsSummaryDataType::serverViewCount(OpcUaUInt32 serverViewCount)
	{
		serverViewCount_ = serverViewCount;
	}

	OpcUaUInt32&
	ServerDiagnosticsSummaryDataType::currentSessionCount(void)
	{
		return currentSessionCount_;
	}

	void
	ServerDiagnosticsSummaryDataType::currentSessionCount(OpcUaUInt32 currentSessionCount)
	{
		currentSessionCount_ = currentSessionCount;
	}

	OpcUaUInt32&
	ServerDiagnosticsSummaryDataType::cumulatedSessionCount(void)
	{
		return cumulatedSessionCount_;
	}

	void
	ServerDiagnosticsSummaryDataType::cumulatedSessionCount(OpcUaUInt32 cumulatedSessionCount)
	{
		cumulatedSessionCount_ = cumulatedSessionCount;
	}

	OpcUaUInt32&
	ServerDiagnosticsSummaryDataType::securityRejectedSessionCount(void)
	{
		return securityRejectedSessionCount_;
	}

	void
	ServerDiagnosticsSummaryDataType::securityRejectedSessionCount(OpcUaUInt32 securityRejectedSessionCount)
	{
		securityRejectedSessionCount_ = securityRejectedSessionCount;
	}

	OpcUaUInt32&
	ServerDiagnosticsSummaryDataType::rejectedSessionCount(void)
	{
		return rejectedSessionCount_;
	}

	void
	ServerDiagnosticsSummaryDataType::rejectedSessionCount(OpcUaUInt32 rejectedSessionCount)
	{
		rejectedSessionCount_ = rejectedSessionCount;
	}

	OpcUaUInt32&
	ServerDiagnosticsSummaryDataType::sessionTimeoutCount(void)
	{
		return sessionTimeoutCount_;
	}

	void
	ServerDiagnosticsSummaryDataType::sessionTimeoutCount(OpcUaUInt32 sessionTimeoutCount)
	{
		sessionTimeoutCount_ = sessionTimeoutCount;
	}

	OpcUaUInt32&
	ServerDiagnosticsSummaryDataType::sessionAbortCount(void)
	{
		return sessionAbortCount_;
	}

	void
	ServerDiagnosticsSummaryDataType::sessionAbortCount(OpcUaUInt32 sessionAbortCount)
	{
		sessionAbortCount_ = sessionAbortCount;
	}

	OpcUaUInt32&
	ServerDiagnosticsSummaryDataType::samplingRateCount(void)
	{
		return samplingRateCount_;
	}

	void
	ServerDiagnosticsSummaryDataType::samplingRateCount(OpcUaUInt32 samplingRateCount)
	{
		samplingRateCount_ = samplingRateCount;
	}

	OpcUaUInt32&
	ServerDiagnosticsSummaryDataType::publishingIntervalCount(void)
	{
		return publishingIntervalCount_;
	}

	void
	ServerDiagnosticsSummaryDataType::publishingIntervalCount(OpcUaUInt32 publishingIntervalCount)
	{
		publishingIntervalCount_ = publishingIntervalCount;
	}

	OpcUaUInt32&
	ServerDiagnosticsSummaryDataType::currentSubscriptionCount(void)
	{
		return currentSubscriptionCount_;
	}

	void
	ServerDiagnosticsSummaryDataType::currentSubscriptionCount(OpcUaUInt32 currentSubscriptionCount)
	{
		currentSubscriptionCount_ = currentSubscriptionCount;
	}

	OpcUaUInt32&
	ServerDiagnosticsSummaryDataType::cumulatedSubscriptionCount(void)
	{
		return cumulatedSubscriptionCount_;
	}

	void
	ServerDiagnosticsSummaryDataType::cumulatedSubscriptionCount(OpcUaUInt32 cumulatedSubscriptionCount)
	{
		cumulatedSubscriptionCount_ = cumulatedSubscriptionCount;
	}

	OpcUaUInt32&
	ServerDiagnosticsSummaryDataType::securityRejectedRequestsCount(void)
	{
		return securityRejectedRequestsCount_;
	}

	void
	ServerDiagnosticsSummaryDataType::securityRejectedRequestsCount(OpcUaUInt32 securityRejectedRequestsCount)
	{
		securityRejectedRequestsCount_ = securityRejectedRequestsCount;
	}

	OpcUaUInt32&
	ServerDiagnosticsSummaryDataType::rejectedRequestsCount(void)
	{
		return rejectedRequestsCount_;
	}

	void
	ServerDiagnosticsSummaryDataType::rejectedRequestsCount(OpcUaUInt32 rejectedRequestsCount)
	{
		rejectedRequestsCount_ = rejectedRequestsCount;
	}

	void
	ServerDiagnosticsSummaryDataType::copyTo(ServerDiagnosticsSummaryDataType& serverDiagnosticsSummaryDataType)
	{
		serverDiagnosticsSummaryDataType.serverViewCount(serverViewCount_);
		serverDiagnosticsSummaryDataType.currentSessionCount(currentSessionCount_);
		serverDiagnosticsSummaryDataType.cumulatedSessionCount(cumulatedSessionCount_);
		serverDiagnosticsSummaryDataType.securityRejectedSessionCount(securityRejectedSessionCount_);
		serverDiagnosticsSummaryDataType.rejectedSessionCount(rejectedSessionCount_);
		serverDiagnosticsSummaryDataType.sessionTimeoutCount(sessionTimeoutCount_);
		serverDiagnosticsSummaryDataType.sessionAbortCount(sessionAbortCount_);
		serverDiagnosticsSummaryDataType.samplingRateCount(samplingRateCount_);
		serverDiagnosticsSummaryDataType.publishingIntervalCount(publishingIntervalCount_);
		serverDiagnosticsSummaryDataType.currentSubscriptionCount(currentSubscriptionCount_);
		serverDiagnosticsSummaryDataType.cumulatedSubscriptionCount(cumulatedSubscriptionCount_);
		serverDiagnosticsSummaryDataType.securityRejectedRequestsCount(securityRejectedRequestsCount_);
		serverDiagnosticsSummaryDataType.rejectedRequestsCount(rejectedRequestsCount_);
	}

	bool
	ServerDiagnosticsSummaryDataType::operator==(const ServerDiagnosticsSummaryDataType& serverDiagnosticsSummaryDataType) const
	{
		ServerDiagnosticsSummaryDataType* dst = const_cast<ServerDiagnosticsSummaryDataType*>(&serverDiagnosticsSummaryDataType);
		return
			serverViewCount_ == dst->serverViewCount() &&
			currentSessionCount_ == dst->currentSessionCount() &&
			cumulatedSessionCount_ == dst->cumulatedSessionCount() &&
			securityRejectedSessionCount_ == dst->securityRejectedSessionCount() &&
			rejectedSessionCount_ == dst->rejectedSessionCount() &&
			sessionTimeoutCount_ == dst->sessionTimeoutCount() &&
			sessionAbortCount_ == dst->sessionAbortCount() &&
			samplingRateCount_ == dst->samplingRateCount() &&
			publishingIntervalCount_ == dst->publishingIntervalCount() &&
			currentSessionCount_ == dst->currentSubscriptionCount() &&
			cumulatedSubscriptionCount_ == dst->cumulatedSubscriptionCount() &&
			securityRejectedRequestsCount_ == dst->securityRejectedRequestsCount() &&
			rejectedRequestsCount_ == dst->rejectedRequestsCount();
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ExtensionObjectBase
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ExtensionObjectBase::SPtr
	ServerDiagnosticsSummaryDataType::factory(void)
	{
		return constructSPtr<ServerDiagnosticsSummaryDataType>();
	}

	void
	ServerDiagnosticsSummaryDataType::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, serverViewCount_);
		OpcUaNumber::opcUaBinaryEncode(os, currentSessionCount_);
		OpcUaNumber::opcUaBinaryEncode(os, cumulatedSessionCount_);
		OpcUaNumber::opcUaBinaryEncode(os, securityRejectedSessionCount_);
		OpcUaNumber::opcUaBinaryEncode(os, rejectedSessionCount_);
		OpcUaNumber::opcUaBinaryEncode(os, sessionTimeoutCount_);
		OpcUaNumber::opcUaBinaryEncode(os, sessionAbortCount_);
		OpcUaNumber::opcUaBinaryEncode(os, samplingRateCount_);
		OpcUaNumber::opcUaBinaryEncode(os, publishingIntervalCount_);
		OpcUaNumber::opcUaBinaryEncode(os, currentSubscriptionCount_);
		OpcUaNumber::opcUaBinaryEncode(os, cumulatedSubscriptionCount_);
		OpcUaNumber::opcUaBinaryEncode(os, securityRejectedRequestsCount_);
		OpcUaNumber::opcUaBinaryEncode(os, rejectedRequestsCount_);
	}

	void
	ServerDiagnosticsSummaryDataType::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, serverViewCount_);
		OpcUaNumber::opcUaBinaryDecode(is, currentSessionCount_);
		OpcUaNumber::opcUaBinaryDecode(is, cumulatedSessionCount_);
		OpcUaNumber::opcUaBinaryDecode(is, securityRejectedSessionCount_);
		OpcUaNumber::opcUaBinaryDecode(is, rejectedSessionCount_);
		OpcUaNumber::opcUaBinaryDecode(is, sessionTimeoutCount_);
		OpcUaNumber::opcUaBinaryDecode(is, sessionAbortCount_);
		OpcUaNumber::opcUaBinaryDecode(is, samplingRateCount_);
		OpcUaNumber::opcUaBinaryDecode(is, publishingIntervalCount_);
		OpcUaNumber::opcUaBinaryDecode(is, currentSubscriptionCount_);
		OpcUaNumber::opcUaBinaryDecode(is, cumulatedSubscriptionCount_);
		OpcUaNumber::opcUaBinaryDecode(is, securityRejectedRequestsCount_);
		OpcUaNumber::opcUaBinaryDecode(is, rejectedRequestsCount_);
	}

	bool
	ServerDiagnosticsSummaryDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
	{
		// FIXME: todo
		return false;
	}

	bool
	ServerDiagnosticsSummaryDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return false;
	}

	bool
	ServerDiagnosticsSummaryDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return false;
	}

	void
	ServerDiagnosticsSummaryDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
	{
		ServerDiagnosticsSummaryDataType* dst = dynamic_cast<ServerDiagnosticsSummaryDataType*>(&extensionObjectBase);
		copyTo(*dst);
	}

	bool
	ServerDiagnosticsSummaryDataType::equal(ExtensionObjectBase& extensionObjectBase) const
	{
		ServerDiagnosticsSummaryDataType* dst = dynamic_cast<ServerDiagnosticsSummaryDataType*>(&extensionObjectBase);
		return *this == *dst;
	}

	void
	ServerDiagnosticsSummaryDataType::out(std::ostream& os)
	{
		os << "ServerViewCount=" << serverViewCount_;
		os << ", CurrentSessionCount=" << currentSessionCount_;
		os << ", CumulatedSessionCount=" << cumulatedSessionCount_;
		os << ", SecurityRejectedSessionCount=" << securityRejectedSessionCount_;
		os << ", RejectedSessionCount=" << rejectedSessionCount_;
		os << ", SessionTimeoutCount=" << sessionTimeoutCount_;
		os << ", SessionAbortCount=" << sessionAbortCount_;
		os << ", SamplingRateCount=" << samplingRateCount_;
		os << ", PublishingIntervalCount=" << publishingIntervalCount_;
		os << ", CurrentSubscriptionCount=" << currentSubscriptionCount_;
		os << ", CumulatedSubscriptionCount=" << cumulatedSubscriptionCount_;
		os << ", SecurityRejectedRequestCount=" << securityRejectedRequestsCount_;
		os << ", RejectedRequestCount=" << rejectedRequestsCount_;
	}

}

