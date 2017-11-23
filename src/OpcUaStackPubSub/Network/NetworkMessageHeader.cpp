/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackPubSub/Network/NetworkMessageHeader.h"

namespace OpcUaStackPubSub
{

	NetworkMessageHeader::NetworkMessageHeader(void)
	: UADPVersion_(4)
	, publisherIdEnabled_(false)
	, dataSetArrayEnabled_(false)
	, dataSetWriterIdEnabled_(false)
	, publisherIdType_(PublisherIdType::PublisherIdType_Byte)
	, dataSetClassIdEnabled_(false)
	, securityEnabled_(false)
	, timestampEnabled_(false)
	, picosecondsEnabled_(false)
	, extendedFlags2Enabled_(false)
	, networkMessageType_(NetworkMessageType_DataSetMessage)
	, promotedFieldsEnabled_(false)
	, publisherId_()
	, dataSetClassId_()
	, dataSetPayloadHeader_()
	, timestamp_()
	, picoSeconds_(0)
	, promotedFields_()
	{
	}

	NetworkMessageHeader::~NetworkMessageHeader(void)
	{
	}

	void
	NetworkMessageHeader::opcUaBinaryEncode(std::ostream& os) const
	{
		// FIXME: todo
	}

	void
	NetworkMessageHeader::opcUaBinaryDecode(std::istream& is)
	{
		// FIXME: todo
	}

	bool
	NetworkMessageHeader::operator==(const NetworkMessageHeader& other) const
	{
		return true;
	}


	void
	NetworkMessageHeader::UADPVersion(OpcUaByte UADPVersion)
	{
		UADPVersion_ = UADPVersion;
	}

	OpcUaByte
	NetworkMessageHeader::UADPVersion() const
	{
		return UADPVersion_;
	}

	void
	NetworkMessageHeader::publisherIdEnabled(bool publisherIdEnabled)
	{
		publisherIdEnabled_ = publisherIdEnabled;
	}

	bool
	NetworkMessageHeader::publisherIdEnabled() const
	{
		return publisherIdEnabled_;
	}

	void
	NetworkMessageHeader::dataSetArrayEnabled(bool dataSetArrayEnabled)
	{
		dataSetArrayEnabled_ = dataSetArrayEnabled;
	}

	bool
	NetworkMessageHeader::dataSetArrayEnabled() const
	{
		return dataSetArrayEnabled_;
	}

	void
	NetworkMessageHeader::dataSetWriterIdEnabled(bool dataSetWriterIdEnabled)
	{
		dataSetWriterIdEnabled_ = dataSetWriterIdEnabled;
	}

	bool
	NetworkMessageHeader::dataSetWriterIdEnabled() const
	{
		return dataSetWriterIdEnabled_;
	}

	void
	NetworkMessageHeader::publisherIdType(PublisherIdType type)
	{
		publisherIdType_ = type;
	}

	PublisherIdType
	NetworkMessageHeader::publisherIdType() const
	{
		return publisherIdType_;
	}

	void
	NetworkMessageHeader::dataSetClassIdEnabled(bool dataSetClassIdEnabled)
	{
		dataSetClassIdEnabled_ = dataSetClassIdEnabled;
	}

	bool
	NetworkMessageHeader::dataSetClassIdEnabled() const
	{
		return dataSetClassIdEnabled_;
	}

	void
	NetworkMessageHeader::securityEnabled(bool securityEnabled)
	{
		securityEnabled_ = securityEnabled;
	}

	bool
	NetworkMessageHeader::securityEnabled() const
	{
		return securityEnabled_;
	}

	void
	NetworkMessageHeader::timestampEnabled(bool timestampEnabled)
	{
		timestampEnabled_ = timestampEnabled;
	}

	bool
	NetworkMessageHeader::timestampEnabled() const
	{
		return timestampEnabled_;
	}

	void
	NetworkMessageHeader::picosecondsEnabled(bool picosecondsEnabled)
	{
		picosecondsEnabled_ = picosecondsEnabled;
	}

	bool
	NetworkMessageHeader::picosecondsEnabled() const
	{
		return picosecondsEnabled_;
	}

	void
	NetworkMessageHeader::extendedFlags2Enabled(bool extendedFlags2Enabled)
	{
		extendedFlags2Enabled_ = extendedFlags2Enabled;
	}

	bool
	NetworkMessageHeader::extendedFlags2Enabled() const
	{
		return extendedFlags2Enabled_;
	}

	void
	NetworkMessageHeader::networkMessageType(NetworkMessageType type)
	{
		networkMessageType_ = type;
	}

	NetworkMessageType
	NetworkMessageHeader::networkMessageType() const
	{
		return networkMessageType_;
	}

	void
	NetworkMessageHeader::promotedFieldsEnabled(bool promotedFieldsEnabled)
	{
		promotedFieldsEnabled_ = promotedFieldsEnabled;
	}

	bool
	NetworkMessageHeader::promotedFieldsEnabled() const
	{
		return promotedFieldsEnabled_;
	}

	void
	NetworkMessageHeader::dataSetClassId(OpcUaGuid::SPtr dataSetClassId)
	{
		dataSetClassId_ = dataSetClassId;
	}

	OpcUaGuid::SPtr
	NetworkMessageHeader::dataSetClassId() const
	{
		return dataSetClassId_;
	}

	void
	NetworkMessageHeader::publisherId(OpcUaVariant::SPtr publisherId)
	{
		publisherId_ = publisherId;
	}

	OpcUaVariant::SPtr
	NetworkMessageHeader::publisherId() const
	{
		return publisherId_;
	}

	void NetworkMessageHeader::dataSetPayloadHeader(DataSetPayloadHeader::SPtr header)
	{
		dataSetPayloadHeader_ = header;
	}

	DataSetPayloadHeader::SPtr
	NetworkMessageHeader::dataSetPayloadHeader() const
	{
		return dataSetPayloadHeader_;
	}

	void
	NetworkMessageHeader::timestamp(OpcUaDateTime timestamp)
	{
		timestamp_ = timestamp;
	}

	OpcUaDateTime
	NetworkMessageHeader::timestamp() const
	{
		return timestamp_;
	}

	void
	NetworkMessageHeader::picoSeconds(OpcUaInt16 picoSeconds)
	{
		picoSeconds_ = picoSeconds;
	}

	OpcUaInt16
	NetworkMessageHeader::picoSeconds() const
	{
		return picoSeconds_;
	}

	void
	NetworkMessageHeader::promotedFields(OpcUaVariantArray::SPtr promotedFields)
	{
		promotedFields_ = promotedFields;
	}

	OpcUaVariantArray::SPtr
	NetworkMessageHeader::promotedFields() const
	{
		return promotedFields_;
	}

}
