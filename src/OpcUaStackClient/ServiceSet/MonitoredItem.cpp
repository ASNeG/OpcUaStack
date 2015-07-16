#include "OpcUaStackCore/BuildInTypes/OpcUaAttributeId.h"
#include "OpcUaStackClient/ServiceSet/MonitoredItem.h"

namespace OpcUaStackClient
{

	MonitoredItem::MonitoredItem(void)
	: timestampsToReturn_(TimestampsToReturn_Both)
	, nodeId_()
	, attributeId_(AttributeId_Value)
	, indexRange_()
	, dataEncoding_()
	, monitoringMode_(MonitoringMode_Sampling)
	, clientHandle_(0)
	, samplingInterval_(500)
	, filter_()
	, queueSize_(1)
	, discardOldest_(true)
	{
	}

	MonitoredItem::~MonitoredItem(void)
	{
	}

	void
	MonitoredItem::nodeId(const OpcUaNodeId& nodeId)
	{
		nodeId_ = nodeId;
	}

	OpcUaNodeId&
	MonitoredItem::nodeId(void)
	{
		return nodeId_;
	}

	void
	MonitoredItem::clientHandle(const uint32_t clientHandle)
	{
		clientHandle_ = clientHandle;
	}

	uint32_t
	MonitoredItem::clientHandle(void)
	{
		return clientHandle_;
	}

	void
	MonitoredItem::samplingInterval(const double samplingInterval)
	{
		samplingInterval_ = samplingInterval;
	}

	double
	MonitoredItem::damplingInterval(void)
	{
		return samplingInterval_;
	}

}


