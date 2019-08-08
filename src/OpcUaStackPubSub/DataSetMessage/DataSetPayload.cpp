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

#include <boost/asio.hpp>
#include "OpcUaStackPubSub/DataSetMessage/DataSetPayload.h"
#include "OpcUaStackPubSub/DataSetMessage/DataKeyFrameDataSetMessage.h"
#include "OpcUaStackPubSub/DataSetMessage/DataDeltaFrameDataSetMessage.h"
#include "OpcUaStackPubSub/DataSetMessage/EventDataSetMessage.h"
#include "OpcUaStackPubSub/DataSetMessage/KeepAliveMessage.h"

namespace OpcUaStackPubSub
{

	DataSetPayload::DataSetPayload(void)
	: count_(0)
	, dataSetMessages_(constructSPtr<DataSetMessageArray>())
	, dataSetArrayEnabled_(false)
	{
	}

	DataSetPayload::~DataSetPayload(void)
	{
	}

	void
	DataSetPayload::count(uint32_t count)
	{
		count_ = count;
	}

	uint32_t
	DataSetPayload::count(void)
	{
		return count_;
	}

	void
	DataSetPayload::dataSetMessages(const DataSetMessageArray::SPtr& dataSetMessages)
	{
		dataSetMessages_ = dataSetMessages;
	}

	DataSetMessageArray::SPtr&
	DataSetPayload::dataSetMessages(void)
	{
		return dataSetMessages_;
	}

	void
	DataSetPayload::opcUaBinaryEncode(std::ostream& os)
	{
		uint32_t actSize = 0;
		std::vector<uint16_t> sizeVec;
		boost::asio::streambuf sb;
		std::iostream ios(&sb);

		for (uint32_t idx = 0; idx < dataSetMessages_->size(); idx++) {
			DataSetMessage::SPtr dataSetMessage;
			dataSetMessages_->get(idx, dataSetMessage);
			dataSetMessage->setFieldEncoding();

			DataSetMessageHeader& hdr = dataSetMessage->dataSetMessageHeader();
			hdr.opcUaBinaryEncode(ios);
			dataSetMessage->opcUaBinaryEncode(ios);

			uint16_t size = sb.size() - actSize;
			actSize = sb.size();
			sizeVec.push_back(size);
		}

		std::vector<uint16_t>::iterator it;
		for (it = sizeVec.begin(); it != sizeVec.end(); it++)
		{
			OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt16)*it);
		}

		char c; while (ios.get(c)) os << c;
	}

	void
	DataSetPayload::opcUaBinaryDecode(std::istream& is)
	{
		if (count_ == 0) return;
		std::vector<uint16_t> sizeVec;
		dataSetMessages_->resize(count_);

		for (uint32_t idx=0; idx<count_; idx++) {
			OpcUaUInt16 size;
			OpcUaNumber::opcUaBinaryDecode(is, size);
			sizeVec.push_back(size);
		}

		for (uint32_t idx=0; idx<count_; idx++) {
			DataSetMessageHeader::SPtr dataSetMessageHeader = constructSPtr<DataSetMessageHeader>();
			dataSetMessageHeader->opcUaBinaryDecode(is);

			DataSetMessage::SPtr dataSetMessage;
			switch (dataSetMessageHeader->messageType())
			{
				case DataKeyFrame:
				{
					dataSetMessage = constructSPtr<DataKeyFrameDataSetMessage>();
					break;
				}
				case DataDeltaFrame:
				{
					dataSetMessage = constructSPtr<DataDeltaFrameDataSetMessage>();
					break;
				}
				case EventData:
				{
					dataSetMessage = constructSPtr<EventDataSetMessage>();
					break;
				}
				case KeepAlive:
				{
					dataSetMessage = constructSPtr<KeepAliveMessage>();
					break;
				}
				default:
				{
					return;
				}
			}

			dataSetMessage->dataSetMessageHeader(dataSetMessageHeader);
			dataSetMessage->opcUaBinaryDecode(is);
			dataSetMessages_->push_back(dataSetMessage);
		}
	}

	bool
	DataSetPayload::operator==(const DataSetPayload& other) const
	{
		if (count_ != other.count_) return false;
		if (dataSetMessages_->isNull() != other.dataSetMessages_->isNull()) return false;
		for (uint32_t pos = 0; pos < dataSetMessages_->size();  pos++) {
			DataSetMessage::SPtr value1, value2;
			dataSetMessages_->get(pos, value1);
			other.dataSetMessages_->get(pos, value2);
			if (!value1 && !value2) continue;
			if ((value1 && !value2) || (!value1 && value2)) return false;
			if (*value1 != *value2) return false;
		}

		return true;
	}

	void
	DataSetPayload::dataSetArrayEnabled(bool dataSetArrayEnabled)
	{
		dataSetArrayEnabled_ = dataSetArrayEnabled;
	}

	bool
	DataSetPayload::dataSetArrayEnabled() const
	{
		return dataSetArrayEnabled_;
	}
}

