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

#ifndef __OpcUaStackCore_SessionDiagnosticsDataType_h__
#define __OpcUaStackCore_SessionDiagnosticsDataType_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/Xmlns.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/ApplicationDescription.h"

namespace OpcUaStackCore
{

	class DLLEXPORT SessionDiagnosticsDataType
	: public Object
	, public ExtensionObjectBase
	{
	  public:
		typedef boost::shared_ptr<SessionDiagnosticsDataType> SPtr;

		SessionDiagnosticsDataType(void);
		virtual ~SessionDiagnosticsDataType(void);

		OpcUaNodeId& sessionId(void);
		void sessionId(OpcUaNodeId sessionId);
		OpcUaString& sessionName(void);
		void sessionName(OpcUaString sessionName);
		ApplicationDescription::SPtr clientDescription(void);
		void clientDescription(ApplicationDescription::SPtr clientDescription);
		OpcUaString& serverUri(void);
		void serverUri(OpcUaString serverUri);
		OpcUaString& endpointUri(void);
		void endpointUri(OpcUaString endpointUri);
		OpcUaStringArray::SPtr localeIds(void);
		void localeIds(OpcUaStringArray::SPtr localeIds);
		OpcUaDouble& actualSessionTimeout(void);
		void actualSessionTimeout(OpcUaDouble actualSessionTimeout);
		OpcUaUInt32& maxResponseMessageSize(void);
		void maxResponseMessageSize(OpcUaUInt32 maxResponseMessageSize);
		OpcUaDateTime& clientConnectionTime(void);
		void clientConnectionTime(OpcUaDateTime clientConnectionTime);
		OpcUaDateTime& clientLastContactTime(void);
		void clientLastContactTime(OpcUaDateTime clientLastContactTime);
		OpcUaUInt32& currentSubscriptionsCount(void);
		void currentSubscriptionsCount(OpcUaUInt32 currentSubscriptionsCount);
		OpcUaUInt32& currentMonitoredItemsCount(void);
		void currentMonitoredItemsCount(OpcUaUInt32 currentMonitoredItemsCount);
		OpcUaUInt32& currentPublishRequestsInQueue(void);
		void currentPublishRequestsInQueue(OpcUaUInt32 currentPublishRequestsInQueue);
		OpcUaUInt32& currentPublishTimerExpirations(void);
		void currentPublishTimerExpirations(OpcUaUInt32 currentPublishTimerExpirations);

		void copyTo(SessionDiagnosticsDataType& sessionDiagnosticsDataType);
		bool operator==(const SessionDiagnosticsDataType& sessionDiagnosticsDataType) const;

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
		OpcUaNodeId sessionId_;
		OpcUaString sessionName_;
		ApplicationDescription::SPtr clientDescription_;
		OpcUaString serverUri_;
		OpcUaString endpointUri_;
		OpcUaStringArray::SPtr localeIds_;
		OpcUaDouble actualSessionTimeout_;
		OpcUaUInt32 maxResponseMessageSize_;
		OpcUaDateTime clientConnectionTime_;
		OpcUaDateTime clientLastContactTime_;
		OpcUaUInt32 currentSubscriptionsCount_;
		OpcUaUInt32 currentMonitoredItemsCount_;
		OpcUaUInt32 currentPublishRequestsInQueue_;
		OpcUaUInt32 currentPublishTimerExpirations_;
	};

}

#endif
