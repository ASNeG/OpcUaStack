/*
   Copyright 2015-2021 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#ifndef __OpcUaStackServer_MonitorItem_h__
#define __OpcUaStackServer_MonitorItem_h__

#include <boost/thread/mutex.hpp>
#include "OpcUaStackCore/Base/UserContext.h"
#include "OpcUaStackCore/Utility/SlotTimer.h"
#include "OpcUaStackCore/ServiceSet/MonitoredItemServiceTransaction.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"
#include "OpcUaStackCore/StandardDataTypes/MonitoredItemNotification.h"
#include <list>

namespace OpcUaStackServer
{

	typedef std::list<OpcUaStackCore::MonitoredItemNotification::SPtr> MonitorItemList;
	typedef enum
	{
		Ok,
		NodeNoLongerExist,
	} SampleResult;

	class DLLEXPORT MonitorItem
	: public OpcUaStackCore::Object
	{
	  public:
		using SPtr = boost::shared_ptr<MonitorItem>;

		MonitorItem(void);
		~MonitorItem(void);

		OpcUaStackCore::OpcUaStatusCode receive(
			BaseNodeClass::SPtr& baseNodeClass,
			OpcUaStackCore::MonitoredItemCreateRequest::SPtr& monitoredItemCreateRequest
		);
		OpcUaStackCore::OpcUaStatusCode receive(
			OpcUaStackCore::MonitoredItemNotificationArray& monitoredItemNotificationArray
		);

		uint32_t monitorItemId(void);
		uint32_t samplingInterval(void);
		uint32_t queSize(void);
		bool discardOldest(void);
		uint32_t size(void);
		BaseNodeClass::SPtr baseNodeClass(void);

		OpcUaStackCore::SlotTimerElement::SPtr slotTimerElement(void);
		OpcUaStackCore::MonitoredItemCreateRequest::SPtr monitoredItemCreateRequest(void);
		void userContext(OpcUaStackCore::UserContext::SPtr& userContext);
		OpcUaStackCore::UserContext::SPtr& userContext(void);

		SampleResult sample(void);

	  private:
		void monitorItemListPushBack(
			OpcUaStackCore::MonitoredItemNotification::SPtr& monitoredItemNotification
		);

		uint32_t monitorItemId_;
		uint32_t samplingInterval_ = 100;
		uint32_t queSize_ = 0;
		bool discardOldest_ = false;
		uint32_t clientHandle_ = 0;

		OpcUaStackCore::MonitoredItemCreateRequest::SPtr monitoredItemCreateRequest_;
		MonitorItemList monitorItemList_;

		OpcUaStackCore::UserContext::SPtr userContext_;
		BaseNodeClass::WPtr baseNodeClass_;
		Attribute* attribute_;
		OpcUaStackCore::OpcUaDataValue dataValue_;

		OpcUaStackCore::SlotTimerElement::SPtr slotTimerElement_;
	};

	typedef std::map<uint32_t, MonitorItem::SPtr> MonitorItemMap;

}

#endif
