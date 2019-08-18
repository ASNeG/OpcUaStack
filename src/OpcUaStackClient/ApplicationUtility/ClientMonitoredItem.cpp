/*
   Copyright 2016-2018 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackClient/ApplicationUtility/ClientMonitoredItem.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	ClientMonitoredItem::ClientMonitoredItem(void)
	: state_(S_Close)
	, reconnectTime_(boost::posix_time::microsec_clock::local_time())
	, monitoredItemId_(0)

	, samplingInterval_(250)
	, queueSize_(1)
	, nodeId_()
	, dataChangeFilter_(DataChangeTrigger::EnumStatusValue)
	, clientHandle_(0)
	, context_()
	{
	}

	ClientMonitoredItem::~ClientMonitoredItem(void)
	{
	}

	uint32_t
	ClientMonitoredItem::samplingInterval(void)
	{
		return samplingInterval_;
	}

	void
	ClientMonitoredItem::samplingInterval(uint32_t samplingInterval)
	{
		samplingInterval_ = samplingInterval;
	}

	uint32_t
	ClientMonitoredItem::queueSize(void)
	{
		return queueSize_;
	}

	void
	ClientMonitoredItem::queueSize(uint32_t queueSize)
	{
		queueSize_ = queueSize;
	}

	OpcUaNodeId&
	ClientMonitoredItem::nodeId(void)
	{
		return nodeId_;
	}

	void
	ClientMonitoredItem::nodeId(OpcUaNodeId& nodeId)
	{
		nodeId_ = nodeId;
	}

	void
	ClientMonitoredItem::clientHandle(uint32_t clientHandle)
	{
		clientHandle_ = clientHandle;
	}

	uint32_t
	ClientMonitoredItem::clientHandle(void)
	{
		return clientHandle_;
	}

	void
	ClientMonitoredItem::state(State state)
	{
		state_ = state;
	}

	ClientMonitoredItem::State
	ClientMonitoredItem::state(void)
	{
		return state_;
	}

	void
	ClientMonitoredItem::reconnectTime(boost::posix_time::ptime reconnectTime)
	{
		reconnectTime_ = reconnectTime;
	}

	boost::posix_time::ptime
	ClientMonitoredItem::reconnectTime(void)
	{
		return reconnectTime_;
	}

	void
	ClientMonitoredItem::monitoredItemId(uint32_t monitoredItemId)
	{
		monitoredItemId_ = monitoredItemId;
	}

	uint32_t
	ClientMonitoredItem::monitoredItemId(void)
	{
		return monitoredItemId_;
	}

	void
	ClientMonitoredItem::context(Object::SPtr& context)
	{
		context_ = context;
	}

	Object::SPtr&
	ClientMonitoredItem::context(void)
	{
		return context_;
	}

	DataChangeTrigger
	ClientMonitoredItem::dataChangeFilter(void)
	{
		return dataChangeFilter_;
	}

	void
	ClientMonitoredItem::dataChangeFilter(DataChangeTrigger dataChangeFilter)
	{
		dataChangeFilter_ = dataChangeFilter;
	}

}
