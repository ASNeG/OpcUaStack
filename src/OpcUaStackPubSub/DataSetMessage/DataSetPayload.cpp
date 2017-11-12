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
	, dataSetMessageHeaders_(constructSPtr<DataSetMessageHeaderArray>())
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

	void
	DataSetPayload::dataSetMessageHeaders(const DataSetMessageHeaderArray::SPtr& dataSetMessageHeaders)
	{
		dataSetMessageHeaders_ = dataSetMessageHeaders;
	}

	DataSetMessageHeaderArray::SPtr&
	DataSetPayload::dataSetMessageHeaders(void)
	{
		return dataSetMessageHeaders_;
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
			DataSetMessageHeader::SPtr dataSetMessageHeader;
			dataSetMessageHeaders_->get(idx, dataSetMessageHeader);

			DataSetMessage::SPtr dataSetMessage;
			dataSetMessages_->get(idx, dataSetMessage);

			dataSetMessageHeader->opcUaBinaryEncode(ios);
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
		dataSetMessageHeaders_->resize(count_);

		for (uint32_t idx=0; idx<count_; idx++) {
			OpcUaUInt16 size;
			OpcUaNumber::opcUaBinaryDecode(is, size);
			sizeVec.push_back(size);
		}

		for (uint32_t idx=0; idx<count_; idx++) {
			DataSetMessageHeader::SPtr dataSetMessageHeader;
			dataSetMessageHeader = constructSPtr<DataSetMessageHeader>();

			dataSetMessageHeader->opcUaBinaryDecode(is);
			dataSetMessageHeaders_->push_back(dataSetMessageHeader);

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

			dataSetMessage->opcUaBinaryDecode(is);
			dataSetMessages_->push_back(dataSetMessage);
		}
	}

}
