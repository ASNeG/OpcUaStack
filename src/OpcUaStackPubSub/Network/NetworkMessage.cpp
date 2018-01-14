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

   Autor: Aleksey Timin (atimin@gmail.com)
 */

#include "OpcUaStackPubSub/Network/NetworkMessage.h"

namespace OpcUaStackPubSub
{

	NetworkMessage::NetworkMessage(void)
	: networkMessageHeader_(constructSPtr<NetworkMessageHeader>())
	, dataSetPayloadHeader_(constructSPtr<DataSetPayloadHeader>())
	, dataSetPayload_(constructSPtr<DataSetPayload>())
	{
	}

	NetworkMessage::~NetworkMessage(void)
	{
	}

	void
	NetworkMessage::networkMessageHeader(NetworkMessageHeader::SPtr networkMessageHeader)
	{
		networkMessageHeader_ = networkMessageHeader;
	}

	NetworkMessageHeader::SPtr
	NetworkMessage::networkMessageHeader() const
	{
		return networkMessageHeader_;
	}

	void
	NetworkMessage::dataSetPayloadHeader(DataSetPayloadHeader::SPtr dataSetPayloadHeader)
	{
		dataSetPayloadHeader_ = dataSetPayloadHeader;
	}

	DataSetPayloadHeader::SPtr
	NetworkMessage::dataSetPayloadHeader() const
	{
		return dataSetPayloadHeader_;
	}

	void
	NetworkMessage::dataSetPayload(DataSetPayload::SPtr dataSetPayload)
	{
		dataSetPayload_ = dataSetPayload;
	}

	DataSetPayload::SPtr
	NetworkMessage::dataSetPayload() const
	{
		return dataSetPayload_;
	}

	void NetworkMessage::opcUaBinaryEncode(std::ostream& os) const
	{
		networkMessageHeader_->opcUaBinaryEncode(os);
		dataSetPayloadHeader_->opcUaBinaryEncode(os);
		dataSetPayload_->opcUaBinaryEncode(os);
	}

	void NetworkMessage::opcUaBinaryDecode(std::istream& is)
	{
		networkMessageHeader_->opcUaBinaryDecode(is);

		dataSetPayloadHeader_->dataSetArrayEnabled(networkMessageHeader_->dataSetArrayEnabled());
		dataSetPayloadHeader_->opcUaBinaryDecode(is);

		dataSetPayload_->count(dataSetPayloadHeader()->dataSetWriterIds()->size());
		dataSetPayload_->opcUaBinaryDecode(is);
	}

	bool OpcUaStackPubSub::NetworkMessage::operator ==(const NetworkMessage& other) const
	{
		return *networkMessageHeader_ == *other.networkMessageHeader_
				&& *dataSetPayloadHeader_ == *other.dataSetPayloadHeader_
				&& *dataSetPayload_ == *other.dataSetPayload_;
	}
}

