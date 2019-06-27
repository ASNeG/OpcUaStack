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

#ifndef __OpcUaStackCore_SubscriptionDiagnosticsDataType_h__
#define __OpcUaStackCore_SubscriptionDiagnosticsDataType_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/Xmlns.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{

	class DLLEXPORT SubscriptionDiagnosticsDataType
	: public Object
	, public ExtensionObjectBase
	{
	  public:
		typedef boost::shared_ptr<SubscriptionDiagnosticsDataType> SPtr;

		SubscriptionDiagnosticsDataType(void);
		virtual ~SubscriptionDiagnosticsDataType(void);

		OpcUaNodeId& sessionId(void);
		void sessionId(OpcUaNodeId sessionId);
		OpcUaUInt32& subscriptionId(void);
		void subscriptionId(OpcUaUInt32 subscriptionId);
		OpcUaByte& priority(void);
		void priority(OpcUaByte priority);
		OpcUaDouble& publishingInterval(void);
		void publishingInterval(OpcUaDouble publishingInterval);

		OpcUaUInt32& maxKeepAliveCount(void);
		void maxKeepAliveCount(OpcUaUInt32 maxKeepAliveCount);
		OpcUaUInt32& maxLifetimeCount(void);
		void maxLifetimeCount(OpcUaUInt32 maxLifetimeCount);
		OpcUaUInt32& maxNotificationsPerPublish(void);
		void maxNotificationsPerPublish(OpcUaUInt32 maxNotificationsPerPublish);
		OpcUaBoolean& publishingEnabled(void);
		void publishingEnabled(OpcUaBoolean publishingEnabled);
		OpcUaUInt32& modifiyCount(void);
		void modifiyCount(OpcUaUInt32 modifiyCount);

		OpcUaUInt32& enableCount(void);
		void enableCount(OpcUaUInt32 enableCount);
		OpcUaUInt32& disableCount(void);
		void disableCount(OpcUaUInt32 disableCount);
		OpcUaUInt32& republishRequestCount(void);
		void republishRequestCount(OpcUaUInt32 republishRequestCount);
		OpcUaUInt32& republishMessageRequestCount(void);
		void republishMessageRequestCount(OpcUaUInt32 republishMessageRequestCount);
		OpcUaUInt32& republishMessageCount(void);
		void republishMessageCount(OpcUaUInt32 republishMessageCount);
		OpcUaUInt32& transferRequestCount(void);
		void transferRequestCount(OpcUaUInt32 transferRequestCount);
		OpcUaUInt32& transferredToAltClientCount(void);
		void transferredToAltClientCount(OpcUaUInt32 transferredToAltClientCount);
		OpcUaUInt32& transferredToSameClientCount(void);
		void transferredToSameClientCount(OpcUaUInt32 transferredToSameClientCount);
		OpcUaUInt32& publishRequestCount(void);
		void publishRequestCount(OpcUaUInt32 publishRequestCount);
		OpcUaUInt32& dataChangeNotificationsCount(void);
		void dataChangeNotificationsCount(OpcUaUInt32 dataChangeNotificationsCount);
		OpcUaUInt32& eventNotificationsCount(void);
		void eventNotificationsCount(OpcUaUInt32 eventNotificationsCount);
		OpcUaUInt32& notificationsCount(void);
		void notificationsCount(OpcUaUInt32 notificationsCount);

		OpcUaUInt32& latePublishRequestCount(void);
		void latePublishRequestCount(OpcUaUInt32 latePublishRequestCount);
		OpcUaUInt32& currentKeepAliveCount(void);
		void currentKeepAliveCount(OpcUaUInt32 currentKeepAliveCount);
		OpcUaUInt32& currentLifetimeCount(void);
		void currentLifetimeCount(OpcUaUInt32 currentLifetimeCount);
		OpcUaUInt32& unacknowledgedMessageCount(void);
		void unacknowledgedMessageCount(OpcUaUInt32 unacknowledgedMessageCount);
		OpcUaUInt32& discardedMessageCount(void);
		void discardedMessageCount(OpcUaUInt32 discardedMessageCount);

		OpcUaUInt32& monitoredItemCount(void);
		void monitoredItemCount(OpcUaUInt32 monitoredItemCount);

		OpcUaUInt32& disabledMonitoredItemCount(void);
		void disabledMonitoredItemCount(OpcUaUInt32 disabledMonitoredItemCount);
		OpcUaUInt32& monitoringQueueOverflowCount(void);
		void monitoringQueueOverflowCount(OpcUaUInt32 monitoringQueueOverflowCount);
		OpcUaUInt32& nextSequenceNumber(void);
		void nextSequenceNumber(OpcUaUInt32 nextSequenceNumber);
		OpcUaUInt32& eventQueueOverflowCount(void);
		void eventQueueOverflowCount(OpcUaUInt32 eventQueueOverflowCount);

		void copyTo(SubscriptionDiagnosticsDataType& subscriptionDiagnosticsDataType);
		bool operator==(const SubscriptionDiagnosticsDataType& subscriptionDiagnosticsDataType) const;

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
		OpcUaUInt32 subscriptionId_;
		OpcUaByte priority_;
		OpcUaDouble publishingInterval_;

		OpcUaUInt32 maxKeepAliveCount_;
		OpcUaUInt32 maxLifetimeCount_;
		OpcUaUInt32 maxNotificationsPerPublish_;
		OpcUaBoolean publishingEnabled_;
		OpcUaUInt32 modifiyCount_;

		OpcUaUInt32 enableCount_;
		OpcUaUInt32 disableCount_;
		OpcUaUInt32 republishRequestCount_;
		OpcUaUInt32 republishMessageRequestCount_;
		OpcUaUInt32	republishMessageCount_;
		OpcUaUInt32	transferRequestCount_;
		OpcUaUInt32	transferredToAltClientCount_;
		OpcUaUInt32	transferredToSameClientCount_;
		OpcUaUInt32	publishRequestCount_;
		OpcUaUInt32	dataChangeNotificationsCount_;
		OpcUaUInt32	eventNotificationsCount_;
		OpcUaUInt32	notificationsCount_;

		OpcUaUInt32 latePublishRequestCount_;
		OpcUaUInt32 currentKeepAliveCount_;
		OpcUaUInt32	currentLifetimeCount_;
		OpcUaUInt32	unacknowledgedMessageCount_;
		OpcUaUInt32	discardedMessageCount_;

		OpcUaUInt32 monitoredItemCount_;

		OpcUaUInt32 disabledMonitoredItemCount_;
		OpcUaUInt32 monitoringQueueOverflowCount_;
		OpcUaUInt32 nextSequenceNumber_;
		OpcUaUInt32 eventQueueOverflowCount_;
	};

}

#endif



