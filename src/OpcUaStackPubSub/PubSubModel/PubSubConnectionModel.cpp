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

#include <OpcUaStackPubSub/PubSubModel/PubSubConnectionModel.h>
#include <OpcUaStackPubSub/PubSubModel/OpcUaNodeIdGenerator.h>

namespace OpcUaStackPubSub
{

	PubSubConnectionModel::PubSubConnectionModel(void)
	: PubSubState()
	, name_("")
	, publisherId_()
	, transportProfileUri_()
	, address_()
	, connectionProperties_()
	, writerGroups_()
	, readerGroups_()
	, groupNames_()
	{
	}

	PubSubConnectionModel::~PubSubConnectionModel(void)
	{
		disable();
		groupNames_.clear();
		writerGroups_.clear();
		readerGroups_.clear();
	}

	OpcUaStatusCode
	PubSubConnectionModel::addWriterGroup(
		PubSubWriterGroupModel::SPtr& configuration,
		OpcUaNodeId& groupId
	)
	{
		// check if writer group name already exist
		if (groupNames_.find(configuration->name().toStdString()) != groupNames_.end()) {
			return BadBrowseNameDuplicated;
		}
		groupNames_.insert(configuration->name().toStdString());

		// create new writer group identifier and insert new writer group
		OpcUaNodeIdGenerator::instance()->createNodeNodeId(groupId);
		writerGroups_.insert(std::make_pair(groupId, configuration));

		return Success;
	}

	OpcUaStatusCode
	PubSubConnectionModel::addReaderGroup(
		PubSubReaderGroupModel::SPtr& configuration,
		OpcUaNodeId& groupId
	)
	{
		// check if reader group name already exist
		if (groupNames_.find(configuration->name().toStdString()) != groupNames_.end()) {
			return BadBrowseNameDuplicated;
		}
		groupNames_.insert(configuration->name().toStdString());

		// create new reader group identifier and insert new writer group
		OpcUaNodeIdGenerator::instance()->createNodeNodeId(groupId);
		readerGroups_.insert(std::make_pair(groupId, configuration));

		return Success;
	}

	PubSubWriterGroupModel::SPtr
	PubSubConnectionModel::getWriterGroup(
		const OpcUaNodeId& groupId
	)
	{
		PubSubWriterGroupModel::SPtr configuration;

		// find writer group
		PubSubWriterGroupModel::Map::iterator it;
		it = writerGroups_.find(groupId);
		if (it == writerGroups_.end()) {
			// writer group not found
			return configuration;
		}

		configuration = it->second;
		return configuration;
	}

	PubSubReaderGroupModel::SPtr
	PubSubConnectionModel::getReaderGroup(
		const OpcUaNodeId& groupId
	)
	{
		PubSubReaderGroupModel::SPtr configuration;

		// find reader group
		PubSubReaderGroupModel::Map::iterator it;
		if (it == readerGroups_.find(groupId)) {
			// reader group not found
			return configuration;
		}

		configuration = it->second;
		return configuration;
	}

	OpcUaStatusCode
	PubSubConnectionModel::removeGroup(
		OpcUaNodeId& groupId
	)
	{
		// find writer groups
		PubSubWriterGroupModel::Map::iterator it1;
		it1 = writerGroups_.find(groupId);
		if (it1 != writerGroups_.end()) {
			PubSubWriterGroupModel::SPtr configuration = it1->second;

			// disable writer group
			configuration->disable();

			// remove writer group
			groupNames_.erase(configuration->name().toStdString());
			writerGroups_.erase(it1);

			return Success;
		}


		// find reader groups
		PubSubReaderGroupModel::Map::iterator it2;
		it2 = readerGroups_.find(groupId);
		if (it2 != readerGroups_.end()) {
			PubSubReaderGroupModel::SPtr configuration = it2->second;

			// disable reader group
			configuration->disable();

			// remove reader group
			groupNames_.erase(configuration->name().toStdString());
			readerGroups_.erase(it2);

			return Success;
		}

		// no writer group and no reader group found
		return BadNodeIdUnknown;


	}

	void
	PubSubConnectionModel::name(const OpcUaString& name)
	{
		name_ = name;
	}

	OpcUaString&
	PubSubConnectionModel::name(void)
	{
		return name_;
	}

	void
	PubSubConnectionModel::publisherId(const OpcUaString& publisherId)
	{
		publisherId_.setValue(publisherId);
	}

	void
	PubSubConnectionModel::publisherId(uint32_t publisherId)
	{
		publisherId_.setValue(publisherId);
	}

	OpcUaVariant&
	PubSubConnectionModel::publisherId(void)
	{
		return publisherId_;
	}

	void
	PubSubConnectionModel::transportProfileUri(const OpcUaString& transportProfileUri)
	{
		transportProfileUri_ = transportProfileUri;
	}

	OpcUaString&
	PubSubConnectionModel::transportProfileUri(void)
	{
		return transportProfileUri_;
	}

	void
	PubSubConnectionModel::address(const OpcUaString& address)
	{
		address_ = address;
	}

	OpcUaString&
	PubSubConnectionModel::address(void)
	{
		return address_;
	}

	void
	PubSubConnectionModel::connectionProperties(const KeyValuePair::Vec& connectionProperties)
	{
		connectionProperties_ = connectionProperties;
	}

	KeyValuePair::Vec&
	PubSubConnectionModel::connectionProperties(void)
	{
		return connectionProperties_;
	}

	void
	PubSubConnectionModel::handleStateChange(State state)
	{
		if (state != Disabled && state != Operational && state != Paused) {
			// ignore state change
			return;
		}

		// iterate through writer map
		PubSubWriterGroupModel::Map::iterator it1;
		for (it1 = writerGroups_.begin(); it1 != writerGroups_.end(); it1++) {
			PubSubWriterGroupModel::SPtr configuration = it1->second;
			if (state == Disabled || state == Paused) {
				configuration->parentChangedToDisableOrPaused();
			}
			else {
				configuration->parentChangedToOperational();
			}
		}

		// iterate through reader map
		PubSubReaderGroupModel::Map::iterator it2;
		for (it2 = readerGroups_.begin(); it2 != readerGroups_.end(); it2++) {
			PubSubReaderGroupModel::SPtr configuration = it2->second;
			if (state == Disabled || state == Paused) {
				configuration->parentChangedToDisableOrPaused();
			}
			else {
				configuration->parentChangedToOperational();
			}
		}
	}

}
