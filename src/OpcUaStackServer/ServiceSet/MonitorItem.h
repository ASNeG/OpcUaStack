/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	typedef std::list<MonitoredItemNotification::SPtr> MonitorItemList;
	typedef enum
	{
		Ok,
		NodeNoLongerExist,
	} SampleResult;

	class DLLEXPORT MonitorItem
	: public Object
	{
	  public:
		typedef boost::shared_ptr<MonitorItem> SPtr;

		MonitorItem(void);
		~MonitorItem(void);

		OpcUaStatusCode receive(BaseNodeClass::SPtr baseNodeClass, MonitoredItemCreateRequest::SPtr monitoredItemCreateRequest);
		OpcUaStatusCode receive(MonitoredItemNotificationArray& monitoredItemNotificationArray);

		uint32_t monitorItemId(void);
		uint32_t samplingInterval(void);
		uint32_t queSize(void);
		bool discardOldest(void);
		uint32_t size(void);
		BaseNodeClass::SPtr baseNodeClass(void);

		SlotTimerElement::SPtr slotTimerElement(void);
		MonitoredItemCreateRequest::SPtr monitoredItemCreateRequest(void);
		void userContext(UserContext::SPtr& userContext);
		UserContext::SPtr& userContext(void);

		SampleResult sample(void);

	  private:
		void monitorItemListPushBack(MonitoredItemNotification::SPtr monitoredItemNotification);
		bool dataChange(MonitoredItemNotification::SPtr monitoredItemNotiication, Attribute* attribute);

		uint32_t monitorItemId_;
		uint32_t samplingInterval_;
		uint32_t queSize_;
		bool discardOldest_;
		uint32_t clientHandle_;

		MonitoredItemCreateRequest::SPtr monitoredItemCreateRequest_;
		MonitorItemList monitorItemList_;

		UserContext::SPtr userContext_;
		BaseNodeClass::WPtr baseNodeClass_;
		Attribute* attribute_;
		OpcUaDataValue dataValue_;

		SlotTimerElement::SPtr slotTimerElement_;
	};

	typedef std::map<uint32_t, MonitorItem::SPtr> MonitorItemMap;

}

#endif
