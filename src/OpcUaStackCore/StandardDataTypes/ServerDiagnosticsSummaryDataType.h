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

#ifndef __OpcUaStackCore_ServerDiagnosticsSummaryDataType_h__
#define __OpcUaStackCore_ServerDiagnosticsSummaryDataType_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/Xmlns.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensionObjectBase.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ServerDiagnosticsSummaryDataType
	: public Object
	, public ExtensionObjectBase
	{
	  public:
		typedef boost::shared_ptr<ServerDiagnosticsSummaryDataType> SPtr;

		ServerDiagnosticsSummaryDataType(void);
		virtual ~ServerDiagnosticsSummaryDataType(void);

		OpcUaUInt32& serverViewCount(void);
		void serverViewCount(OpcUaUInt32 serverViewCount);
		OpcUaUInt32& currentSessionCount(void);
		void currentSessionCount(OpcUaUInt32 currentSessionCount);
		OpcUaUInt32& cumulatedSessionCount(void);
		void cumulatedSessionCount(OpcUaUInt32 cumulatedSessionCount);
		OpcUaUInt32& securityRejectedSessionCount(void);
		void securityRejectedSessionCount(OpcUaUInt32 securityRejectedSessionCount);
		OpcUaUInt32& rejectedSessionCount(void);
		void rejectedSessionCount(OpcUaUInt32 rejectedSessionCount);
		OpcUaUInt32& sessionTimeoutCount(void);
		void sessionTimeoutCount(OpcUaUInt32 sessionTimeoutCount);
		OpcUaUInt32& sessionAbortCount(void);
		void sessionAbortCount(OpcUaUInt32 sessionAbortCount);
		OpcUaUInt32& samplingRateCount(void);
		void samplingRateCount(OpcUaUInt32 samplingRateCount);
		OpcUaUInt32& publishingIntervalCount(void);
		void publishingIntervalCount(OpcUaUInt32 publishingIntervalCount);
		OpcUaUInt32& currentSubscriptionCount(void);
		void currentSubscriptionCount(OpcUaUInt32 currentSubscriptionCount);
		OpcUaUInt32& cumulatedSubscriptionCount(void);
		void cumulatedSubscriptionCount(OpcUaUInt32 cumulatedSubscriptionCount);
		OpcUaUInt32& securityRejectedRequestsCount(void);
		void securityRejectedRequestsCount(OpcUaUInt32 securityRejectedRequestsCount);
		OpcUaUInt32& rejectedRequestsCount(void);
		void rejectedRequestsCount(OpcUaUInt32 rejectedRequestsCount);

		void copyTo(ServerDiagnosticsSummaryDataType& serverDiagnosticsSummaryDataType);
		bool operator==(const ServerDiagnosticsSummaryDataType& serverDiagnosticsSummaryDataType) const;

		//- ExtensionObjectBase -----------------------------------------------
		ExtensionObjectBase::SPtr factory(void);
		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);
		bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
		bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);
		void copyTo(ExtensionObjectBase& extensionObjectBase);
		bool equal(ExtensionObjectBase& extensionObjectBase) const;
		void out(std::ostream& os);
		//- ExtensionObjectBase -----------------------------------------------

	  private:
		OpcUaUInt32 serverViewCount_;
		OpcUaUInt32 currentSessionCount_;
		OpcUaUInt32 cumulatedSessionCount_;
		OpcUaUInt32 securityRejectedSessionCount_;
		OpcUaUInt32 rejectedSessionCount_;
		OpcUaUInt32 sessionTimeoutCount_;
		OpcUaUInt32 sessionAbortCount_;
		OpcUaUInt32 samplingRateCount_;
		OpcUaUInt32 publishingIntervalCount_;
		OpcUaUInt32 currentSubscriptionCount_;
		OpcUaUInt32 cumulatedSubscriptionCount_;
		OpcUaUInt32 securityRejectedRequestsCount_;
		OpcUaUInt32 rejectedRequestsCount_;
	};

}

#endif
