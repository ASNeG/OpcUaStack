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

#include <OpcUaStackPubSub/PubSubModel/DataSetWriterModel.h>
#include <OpcUaStackPubSub/PubSubModel/OpcUaNodeIdGenerator.h>

namespace OpcUaStackPubSub
{

	DataSetWriterModel::DataSetWriterModel(void)
	: PubSubState()
	, name_("")
	, dataSetWriterId_(0)
	, dataSetFieldContentMask_()
	, keyFrameCount_(0)
	, dataSetName_("")
	, dataSetWriterProperties_()
	, transportSettings_()
	, messageSettings_()
	{
	}

	DataSetWriterModel::~DataSetWriterModel(void)
	{
	}

	void
	DataSetWriterModel::name(const OpcUaString& name)
	{
		name_ = name;
	}

	OpcUaString&
	DataSetWriterModel::name(void)
	{
		return name_;
	}

	void
	DataSetWriterModel::dataSetWriterId(uint16_t dataSetWriterId)
	{
		dataSetWriterId_ = dataSetWriterId;
	}

	uint16_t
	DataSetWriterModel::dataSetWriterId(void)
	{
		return dataSetWriterId_;
	}

	void
	DataSetWriterModel::dataSetFieldContentMask(DataSetFieldContentMask& dataSetFieldContentMask)
	{
		dataSetFieldContentMask_ = dataSetFieldContentMask;
	}

	DataSetFieldContentMask&
	DataSetWriterModel::dataSetFieldContentMask(void)
	{
		return dataSetFieldContentMask_;
	}

	void
	DataSetWriterModel::keyFrameCount(uint32_t keyFrameCount)
	{
		keyFrameCount_ = keyFrameCount;
	}

	uint32_t&
	DataSetWriterModel::keyFrameCount(void)
	{
		return keyFrameCount_;
	}

	void
	DataSetWriterModel::keyFrameCount(const OpcUaString& dataSetName)
	{
		dataSetName_ = dataSetName;
	}

	OpcUaString&
	DataSetWriterModel::dataSetName(void)
	{
		return dataSetName_;
	}

	void
	DataSetWriterModel::dataSetWriterProperties(const KeyValuePair::Vec& dataSetWriterProperties)
	{
		dataSetWriterProperties_ = dataSetWriterProperties;
	}

	KeyValuePair::Vec&
	DataSetWriterModel::dataSetWriterProperties(void)
	{
		return dataSetWriterProperties_;
	}

	void
	DataSetWriterModel::transportSettings(DataSetWriterTransportModel::SPtr& transportSettings)
	{
		transportSettings_ = transportSettings;
	}

	DataSetWriterTransportModel::SPtr&
	DataSetWriterModel::transportSettings(void)
	{
		return transportSettings_;
	}

	void
	DataSetWriterModel::messageSettings(DataSetWriterMessageModel::SPtr& messageSettings)
	{
		messageSettings_ = messageSettings;
	}

	DataSetWriterMessageModel::SPtr&
	DataSetWriterModel::messageSettings(void)
	{
		return messageSettings_;
	}
}
