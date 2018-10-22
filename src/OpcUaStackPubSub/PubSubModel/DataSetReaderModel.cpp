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

#include <OpcUaStackPubSub/PubSubModel/DataSetReaderModel.h>

namespace OpcUaStackPubSub
{

	DataSetReaderModel::DataSetReaderModel(void)
	: PubSubState()
	, name_("")
	, publisherId_()
	, writerGroupId_(0)
	, dataSetWriterId_(0)
	, dataSetMetaData_()
	, dataSetFieldContentMask_()
	, messageReceiveTimeout_(0)
	, securityMode_(Invalid)
	, securityGroupId_("")
	, securityKeyService_(constructSPtr<EndpointDescriptionArray>())
	, dataSetReaderProperties_()
	, transportSettings_()
	, messageSettings_()
	, subscribedDataSet_()
	{
	}

	DataSetReaderModel::~DataSetReaderModel(void)
	{
	}

	void
	DataSetReaderModel::name(const OpcUaString& name)
	{
		name_ = name;
	}

	OpcUaString&
	DataSetReaderModel::name(void)
	{
		return name_;
	}

	void
	DataSetReaderModel::publisherId(const OpcUaString& publisherId)
	{
		publisherId_.setValue(publisherId);
	}

	void
	DataSetReaderModel::publisherId(uint32_t publisherId)
	{
		publisherId_.setValue(publisherId);
	}

	void
	DataSetReaderModel::writerGroupId(uint16_t writerGroupId)
	{
		writerGroupId_ = writerGroupId;
	}

	uint16_t
	DataSetReaderModel::writerGroupId(void)
	{
		return writerGroupId_;
	}

	void
	DataSetReaderModel::dataSetWriterId(uint16_t dataSetWriterId)
	{
		dataSetWriterId_ = dataSetWriterId;
	}

	uint16_t
	DataSetReaderModel::dataSetWriterId(void)
	{
		return dataSetWriterId_;
	}

	void
	DataSetReaderModel::dataSetMetaData(DataSetMetaDataModel::SPtr& dataSetMetaData)
	{
		dataSetMetaData_ = dataSetMetaData;
	}

	DataSetMetaDataModel::SPtr&
	DataSetReaderModel::dataSetMetaData(void)
	{
		return dataSetMetaData_;
	}

	void
	DataSetReaderModel::dataSetFieldContentMask(DataSetFieldContentMask& dataSetFieldContentMask)
	{
		dataSetFieldContentMask_ = dataSetFieldContentMask;
	}

	DataSetFieldContentMask&
	DataSetReaderModel::dataSetFieldContentMask(void)
	{
		return dataSetFieldContentMask_;
	}

	void
	DataSetReaderModel::messageReceiveTimeout(OpcUaDuration messageReceiveTimeout)
	{
		messageReceiveTimeout_ = messageReceiveTimeout;
	}

	OpcUaDuration
	DataSetReaderModel::messageReceiveTimeout(void)
	{
		return messageReceiveTimeout_;
	}

	void
	DataSetReaderModel::securityMode(MessageSecurityMode securityMode)
	{
		securityMode_ = securityMode;
	}

	MessageSecurityMode
	DataSetReaderModel::securityMode(void)
	{
		return securityMode_;
	}

	void
	DataSetReaderModel::securityGroupId(const OpcUaString& securityGroupId)
	{
		securityGroupId_ = securityGroupId;
	}

	OpcUaString&
	DataSetReaderModel::securityGroupId(void)
	{
		return securityGroupId_;
	}

	void
	DataSetReaderModel::securityKeyService(const EndpointDescriptionArray::SPtr& securityKeyService)
	{
		securityKeyService_ = securityKeyService;
	}

	EndpointDescriptionArray::SPtr&
	DataSetReaderModel::securityKeyService(void)
	{
		return securityKeyService_;
	}

	void
	DataSetReaderModel::dataSetReaderProperties(const KeyValuePair::Vec& dataSetReaderProperties)
	{
		dataSetReaderProperties_ = dataSetReaderProperties;
	}

	KeyValuePair::Vec&
	DataSetReaderModel::dataSetReaderProperties(void)
	{
		return dataSetReaderProperties_;
	}

	void
	DataSetReaderModel::transportSettings(DataSetReaderTransportModel::SPtr& transportSettings)
	{
		transportSettings_ = transportSettings;
	}

	DataSetReaderTransportModel::SPtr&
	DataSetReaderModel::transportSettings(void)
	{
		return transportSettings_;
	}

	void
	DataSetReaderModel::messageSettings(DataSetReaderMessageModel::SPtr& messageSettings)
	{
		messageSettings_ = messageSettings;
	}

	DataSetReaderMessageModel::SPtr&
	DataSetReaderModel::messageSettings(void)
	{
		return messageSettings_;
	}

	void
	DataSetReaderModel::subscribedDataSet(SubscribedDataSetModel::SPtr& subscribedDataSet)
	{
		subscribedDataSet_ = subscribedDataSet;
	}

	SubscribedDataSetModel::SPtr&
	DataSetReaderModel::subscribedDataSet(void)
	{
		return subscribedDataSet_;
	}

}
