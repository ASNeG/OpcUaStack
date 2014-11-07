#ifndef __OpcUaStackServer_MonitorItem_h__
#define __OpcUaStackServer_MonitorItem_h__

#include <boost/thread/mutex.hpp>
#include "OpcUaStackCore/Utility/SlotTimer.h"
#include "OpcUaStackCore/ServiceSet/MonitoredItemServiceTransaction.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeCLass.h"
#include <list>

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	typedef std::list<OpcUaDataValue::SPtr> MonitorItemList;
	typedef enum
	{
		Ok,
		NodeNoLongerExist,
	} SampleResult;

	class MonitorItem : public ObjectPool<MonitorItem>
	{
	  public:
		MonitorItem(void);
		~MonitorItem(void);

		OpcUaStatusCode receive(BaseNodeClass::SPtr baseNodeClass, MonitoredItemCreateRequest::SPtr monitoredItemCreateRequest);

		uint32_t monitorItemId(void);
		uint32_t samplingInterval(void);
		uint32_t queSize(void);

		SlotTimerElement::SPtr slotTimerElement(void);
		MonitoredItemCreateRequest::SPtr monitoredItemCreateRequest(void);

		SampleResult sample(void);

	  private:
		void monitorItemListPushBack(OpcUaDataValue::SPtr dataValue);
		void monitorItemListPushBack(OpcUaDataValue& dataValue);
		bool dataChange(OpcUaDataValue& oldDataValue, OpcUaDataValue& newDataValue);

		static uint32_t uniqueMonitorItemId(void);
		static boost::mutex mutex_;
		static uint32_t uniqueMonitorItemId_;

		uint32_t monitorItemId_;
		uint32_t samplingInterval_;
		uint32_t queSize_;

		MonitoredItemCreateRequest::SPtr monitoredItemCreateRequest_;
		MonitorItemList monitorItemList_;

		BaseNodeClass::WPtr baseNodeClass_;
		Attribute* attribute_;
		OpcUaDataValue dataValue_;

		SlotTimerElement::SPtr slotTimerElement_;
	};

	typedef std::map<uint32_t, MonitorItem::SPtr> MonitorItemMap;

}

#endif