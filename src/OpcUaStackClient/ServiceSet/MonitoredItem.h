#ifndef __OpcUaStackClient_MonitoredItem_h__
#define __OpcUaStackClient_MonitoredItem_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackClient/ServiceSet/MonitoredItemService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	class DLLEXPORT MonitoredItem
	: public OpcUaStackCore::ObjectPool<MonitoredItem>
	{
	  public:
		typedef boost::shared_ptr<MonitoredItem> SPtr;

		MonitoredItem(void);
		~MonitoredItem(void);

		void nodeId(const OpcUaNodeId& nodeId);
		OpcUaNodeId& nodeId(void);
		void clientHandle(const uint32_t clientHandle);
		uint32_t clientHandle(void);
		void samplingInterval(const double samplingInterval);
		double damplingInterval(void);

	  private:

		// monitoring parameter
		TimestampsToReturn timestampsToReturn_;
		OpcUaInt32 attributeId_;

		// node parameters
		OpcUaNodeId nodeId_;
		OpcUaString indexRange_;
		OpcUaQualifiedName dataEncoding_;

		// Monitoring mode
		MonitoringMode monitoringMode_;

		// requested parameter
		OpcUaUInt32 clientHandle_;
		OpcUaDouble samplingInterval_;
		ExtensibleParameter filter_;
		OpcUaUInt32 queueSize_;
		OpcUaBoolean discardOldest_;
	};

}

#endif
