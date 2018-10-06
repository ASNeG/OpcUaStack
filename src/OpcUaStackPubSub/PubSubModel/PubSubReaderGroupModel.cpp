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

#include <OpcUaStackPubSub/PubSubModel/PubSubReaderGroupModel.h>
#include <OpcUaStackPubSub/PubSubModel/OpcUaNodeIdGenerator.h>

namespace OpcUaStackPubSub
{

	PubSubReaderGroupModel::PubSubReaderGroupModel(void)
	: PubSubGroupModel()
	, transportSettings_()
	, messageSettings_()
	, dataSetReaders_()
	{
	}

	PubSubReaderGroupModel::~PubSubReaderGroupModel(void)
	{
	}

	OpcUaStatusCode
	PubSubReaderGroupModel::addDataSetReader(
	    DataSetReaderModel::SPtr& configuration,
		OpcUaNodeId& dataSetReaderId
	)
	{
		// check if data set reader name already exist
		if (dataSetReaderNames_.find(configuration->name().toStdString()) != dataSetReaderNames_.end()) {
			return BadBrowseNameDuplicated;
		}
		dataSetReaderNames_.insert(configuration->name().toStdString());

		// create new connection identifier and insert new connection
		OpcUaNodeIdGenerator::instance()->createNodeNodeId(dataSetReaderId);
		dataSetReaders_.insert(std::make_pair(dataSetReaderId, configuration));

		return Success;
	}

	DataSetReaderModel::SPtr
	PubSubReaderGroupModel::getDataSetReader(
		const OpcUaNodeId& dataSetReaderId
	)
	{
		DataSetReaderModel::SPtr configuration;

		// find data set reader
		DataSetReaderModel::Map::iterator it;
		it = dataSetReaders_.find(dataSetReaderId);
		if (it == dataSetReaders_.end()) {
			// data set reader not found
			return configuration;
		}

		configuration = it->second;
		return configuration;
	}

	OpcUaStatusCode
	PubSubReaderGroupModel::removeDataSetReader(
		const OpcUaNodeId& dataSetReader
	)
	{
		// find data set reader
		DataSetReaderModel::Map::iterator it;
		it = dataSetReaders_.find(dataSetReader);
		if (it == dataSetReaders_.end()) {
			// data set reader not found
			return BadNodeIdUnknown;
		}
		DataSetReaderModel::SPtr configuration = it->second;

		// disable data set reader
		configuration->disable();

		// remove data set reader
		dataSetReaderNames_.erase(configuration->name().toStdString());
		dataSetReaders_.erase(it);

		return Success;
	}

	void
	PubSubReaderGroupModel::handleStateChange(State state)
	{
		if (state != Disabled && state != Operational && state != Paused) {
			// ignore state change
			return;
		}

		// iterate through data set reader map
		DataSetReaderModel::Map::iterator it;
		for (it = dataSetReaders_.begin(); it != dataSetReaders_.end(); it++) {
			DataSetReaderModel::SPtr configuration = it->second;
			if (state == Disabled || state == Paused) {
				configuration->parentChangedToDisableOrPaused();
			}
			else {
				configuration->parentChangedToOperational();
			}
		}
	}

	void
	PubSubReaderGroupModel::transportSettings(ReaderGroupTransportModel::SPtr& transportSettings)
	{
		transportSettings_ = transportSettings;
	}

	ReaderGroupTransportModel::SPtr&
	PubSubReaderGroupModel::transportSettings(void)
	{
		return transportSettings_;
	}

	void
	PubSubReaderGroupModel::messageSettings(ReaderGroupMessageModel::SPtr& messageSettings)
	{
		messageSettings_ = messageSettings;
	}

	ReaderGroupMessageModel::SPtr&
	PubSubReaderGroupModel::messageSettings(void)
	{
		return messageSettings_;
	}

}
