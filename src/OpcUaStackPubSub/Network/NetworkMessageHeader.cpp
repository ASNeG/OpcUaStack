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
	, extendedFlags1Enabled_(false)
	, publisherIdType_(PublisherIdType::PublisherIdType_Byte)
	, dataSetClassIdEnabled_(false)
	, securityEnabled_(false)
	, timestampEnabled_(false)
	, picosecondsEnabled_(false)
	, extendedFlags2Enabled_(false)
	, networkMessageType_(NetworkMessageType_DataSetMessage)
	, promotedFieldsEnabled_(false)
	, publisherId_(constructSPtr<OpcUaVariant>())
	, dataSetClassId_(constructSPtr<OpcUaGuid>())
	, dataSetPayloadHeader_(constructSPtr<DataSetPayloadHeader>())
	, timestamp_()
	, picoSeconds_(0)
	, promotedFields_(constructSPtr<OpcUaVariantArray>())
	{
	}

	NetworkMessageHeader::~NetworkMessageHeader(void)
	{
	}

	void
	NetworkMessageHeader::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaByte UADPFlags = UADPVersion_;

		if (publisherIdEnabled_) {
			UADPFlags |= 0x10;
		}

		if (dataSetArrayEnabled_) {
			UADPFlags |= 0x20;
		}

		if (dataSetWriterIdEnabled_) {
			UADPFlags |= 0x40;
		}

		if (extendedFlags1Enabled_) {
			UADPFlags |= 0x80;
		}

		OpcUaNumber::opcUaBinaryEncode(os, UADPFlags);

		if (extendedFlags1Enabled_) {
			OpcUaByte extendedFlags1 = publisherIdType_;
			OpcUaNumber::opcUaBinaryEncode(os, extendedFlags1);
		}

		if (publisherIdEnabled_) {
			switch (publisherIdType_)
			{
			case PublisherIdType_UInt16:
				OpcUaNumber::opcUaBinaryEncode(os, publisherId_->get<OpcUaUInt16>());
				break;
			case PublisherIdType_UInt32:
				OpcUaNumber::opcUaBinaryEncode(os, publisherId_->get<OpcUaUInt32>());
				break;
			case PublisherIdType_UInt64:
				OpcUaNumber::opcUaBinaryEncode(os, publisherId_->get<OpcUaUInt64>());
				break;
			case PublisherIdType_Guid:
				publisherId_->getSPtr<OpcUaGuid>()->opcUaBinaryEncode(os);
				break;
			case PublisherIdType_String:
				publisherId_->getSPtr<OpcUaString>()->opcUaBinaryEncode(os);
				break;
			case PublisherIdType_Byte:
			default:
				// FIXME: We should stop where because we can't continue encoding without type.
				OpcUaNumber::opcUaBinaryEncode(os, publisherId_->get<OpcUaByte>());
			}

		}

		if (dataSetWriterIdEnabled_) {
			dataSetPayloadHeader_->dataSetArrayEnabled(dataSetArrayEnabled_);
			dataSetPayloadHeader_->opcUaBinaryEncode(os);
		}
	}

	void
	NetworkMessageHeader::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaByte UADPFlags;
		OpcUaNumber::opcUaBinaryDecode(is, UADPFlags);

		UADPVersion_ = UADPFlags & 0xF;

		publisherIdEnabled_ = UADPFlags & 0x10;
		dataSetArrayEnabled_ = UADPFlags & 0x20;
		dataSetWriterIdEnabled_ = UADPFlags & 0x40;
		extendedFlags1Enabled_ = UADPFlags & 0x80;

		publisherIdType_ = PublisherIdType_Byte;

		if (extendedFlags1Enabled_) {
			OpcUaByte extendedFlags1 = 0;
			OpcUaNumber::opcUaBinaryDecode(is, extendedFlags1);

			publisherIdType_ = ((PublisherIdType)(extendedFlags1 & 0x07));
		}

		if (publisherIdEnabled_) {
			switch (publisherIdType_)
			{
			case PublisherIdType_UInt16:
			{
				OpcUaUInt16 id;
				OpcUaNumber::opcUaBinaryDecode(is, id);
				publisherId_->setValue(id);
				break;
			}
			case PublisherIdType_UInt32:
			{
				OpcUaUInt32 id;
				OpcUaNumber::opcUaBinaryDecode(is, id);
				publisherId_->setValue(id);
				break;
			}
			case PublisherIdType_UInt64:
			{
				OpcUaUInt64 id;
				OpcUaNumber::opcUaBinaryDecode(is, id);
				publisherId_->setValue(id);
				break;
			}
			case PublisherIdType_Guid:
			{
				OpcUaGuid id;
				id.opcUaBinaryDecode(is);
				publisherId_->setValue(id);
				break;
			}
			case PublisherIdType_String:
			{
				OpcUaString id;
				id.opcUaBinaryDecode(is);
				publisherId_->setValue(id);
				break;
			}
			case PublisherIdType_Byte:
			default:
			{
				// FIXME: We should stop where because we can't continue dencoding without type.
				OpcUaByte id;
				OpcUaNumber::opcUaBinaryDecode(is, id);
				publisherId_->setValue(id);
			}
			}
		}

		if (dataSetWriterIdEnabled_) {
			dataSetPayloadHeader_->dataSetArrayEnabled(dataSetArrayEnabled_);
			dataSetPayloadHeader_->opcUaBinaryDecode(is);
		}
	}

	bool
	NetworkMessageHeader::operator==(const NetworkMessageHeader& other) const
	{
		return 	UADPVersion_ == other.UADPVersion_
				&& publisherIdEnabled_ == other.publisherIdEnabled_
				&& dataSetArrayEnabled_ == other.dataSetArrayEnabled_
				&& dataSetWriterIdEnabled_ == other.dataSetWriterIdEnabled_
				&& extendedFlags1Enabled_ == other.extendedFlags1Enabled_
				&& publisherIdType_ == other.publisherIdType_
				&& dataSetClassIdEnabled_ == other.dataSetClassIdEnabled_
				&& securityEnabled_ == other.securityEnabled_
				&& timestampEnabled_ == other.timestampEnabled_
				&& picosecondsEnabled_ == other.picosecondsEnabled_
				&& extendedFlags2Enabled_ == other.extendedFlags2Enabled_
				&& networkMessageType_ == other.networkMessageType_
				&& promotedFieldsEnabled_ == other.promotedFieldsEnabled_
				&& *publisherId_ == *other.publisherId_
				&& *dataSetClassId_ == *other.dataSetClassId_
				&& *dataSetPayloadHeader_ == *other.dataSetPayloadHeader_
				&& timestamp_ == other.timestamp_
				&& picoSeconds_ == other.picoSeconds_
				&& *promotedFields_ == *promotedFields_;
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
	NetworkMessageHeader::extendedFlags1Enabled(bool extendedFlags1Enabled)
	{
		extendedFlags1Enabled_ = extendedFlags1Enabled;
	}

	bool
	NetworkMessageHeader::extendedFlags1Enabled() const
	{
		return extendedFlags1Enabled_;
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
