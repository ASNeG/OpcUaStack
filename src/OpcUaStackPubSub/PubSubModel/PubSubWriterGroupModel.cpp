/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Aleksey Timin (atimin@gmail.com)
 */

#include <OpcUaStackPubSub/PubSubModel/PubSubWriterGroupModel.h>
#include <OpcUaStackPubSub/PubSubModel/OpcUaNodeIdGenerator.h>

namespace OpcUaStackPubSub
{

	PubSubWriterGroupModel::PubSubWriterGroupModel(void)
	: PubSubGroupModel()
	, writerGroupId_(0)
	, publishingInterval_(0)
	, keepAliveTime_(0)
	, priority_(0)
	, localeIds_()
	, transportSettings_()
	, messageSettings_()
	, dataSetWriters_()
	{
	}

	PubSubWriterGroupModel::~PubSubWriterGroupModel(void)
	{
	}

	OpcUaStatusCode
	PubSubWriterGroupModel::addDataSetWriter(
	    DataSetWriterModel::SPtr& configuration,
		OpcUaNodeId& dataSetWriterId
	)
	{
		// check if data set writer name already exist
		if (dataSetWriterNames_.find(configuration->name().toStdString()) != dataSetWriterNames_.end()) {
			return BadBrowseNameDuplicated;
		}
		dataSetWriterNames_.insert(configuration->name().toStdString());

		// create new connection identifier and insert new connection
		OpcUaNodeIdGenerator::instance()->createNodeNodeId(dataSetWriterId);
		dataSetWriters_.insert(std::make_pair(dataSetWriterId, configuration));

		return Success;
	}

	DataSetWriterModel::SPtr
	PubSubWriterGroupModel::getDataSetWriter(
		const OpcUaNodeId& dataSetWriterId
	)
	{
		DataSetWriterModel::SPtr configuration;

		// find data set writer
		DataSetWriterModel::Map::iterator it;
		it = dataSetWriters_.find(dataSetWriterId);
		if (it == dataSetWriters_.end()) {
			// data set writer not found
			return configuration;
		}

		configuration = it->second;
		return configuration;
	}

	OpcUaStatusCode
	PubSubWriterGroupModel::removeDataSetWriter(
		const OpcUaNodeId& dataSetWriter
	)
	{
		// find data set writer
		DataSetWriterModel::Map::iterator it;
		it = dataSetWriters_.find(dataSetWriter);
		if (it == dataSetWriters_.end()) {
			// data set writer not found
			return BadNodeIdUnknown;
		}
		DataSetWriterModel::SPtr configuration = it->second;

		// disable data set writer
		configuration->disable();

		// remove data set writer
		dataSetWriterNames_.erase(configuration->name().toStdString());
		dataSetWriters_.erase(it);

		return Success;
	}

	void
	PubSubWriterGroupModel::handleStateChange(State state)
	{
		if (state != Disabled && state != Operational && state != Paused) {
			// ignore state change
			return;
		}

		// iterate through data set writer map
		DataSetWriterModel::Map::iterator it;
		for (it = dataSetWriters_.begin(); it != dataSetWriters_.end(); it++) {
			DataSetWriterModel::SPtr configuration = it->second;
			if (state == Disabled || state == Paused) {
				configuration->parentChangedToDisableOrPaused();
			}
			else {
				configuration->parentChangedToOperational();
			}
		}
	}

	void
	PubSubWriterGroupModel::writerGroupId(uint16_t writerGroupId)
	{
		writerGroupId_ = writerGroupId;
	}

	uint16_t
	PubSubWriterGroupModel::writerGroupId(void)
	{
		return writerGroupId_;
	}

	void
	PubSubWriterGroupModel::publishingInterval(OpcUaDuration publishingInterval)
	{
		publishingInterval_ = publishingInterval;
	}

	OpcUaDuration
	PubSubWriterGroupModel::publishingInterval(void)
	{
		return publishingInterval_;
	}

	void
	PubSubWriterGroupModel::keepAliveTime(OpcUaDuration keepAliveTime)
	{
		keepAliveTime_ = keepAliveTime;
	}

	OpcUaDuration
	PubSubWriterGroupModel::keepAliveTime(void)
	{
		return keepAliveTime_;
	}

	void
	PubSubWriterGroupModel::priority(OpcUaByte priority)
	{
		priority_ = priority;
	}

	OpcUaByte
	PubSubWriterGroupModel::priority(void)
	{
		return priority_;
	}

	void
	PubSubWriterGroupModel::localeIds(OpcUaStringArray::SPtr& localeIds)
	{
		localeIds_ = localeIds;
	}

	OpcUaStringArray::SPtr&
	PubSubWriterGroupModel::localeIds(void)
	{
		return localeIds_;
	}

	void
	PubSubWriterGroupModel::transportSettings(WriterGroupTransportModel::SPtr& transportSettings)
	{
		transportSettings_ = transportSettings;
	}

	WriterGroupTransportModel::SPtr&
	PubSubWriterGroupModel::transportSettings(void)
	{
		return transportSettings_;
	}

	void
	PubSubWriterGroupModel::messageSettings(WriterGroupMessageModel::SPtr& messageSettings)
	{
		messageSettings_ = messageSettings;
	}

	WriterGroupMessageModel::SPtr&
	PubSubWriterGroupModel::messageSettings(void)
	{
		return messageSettings_;
	}

}
