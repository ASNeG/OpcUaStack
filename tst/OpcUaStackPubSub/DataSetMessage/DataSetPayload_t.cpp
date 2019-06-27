#include "unittest.h"

#include <boost/asio.hpp>
#include <iostream>
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackPubSub/DataSetMessage/DataSetPayload.h"
#include "OpcUaStackPubSub/DataSetMessage/KeepAliveMessage.h"
#include "OpcUaStackPubSub/DataSetMessage/DataKeyFrameDataSetMessage.h"
#include "OpcUaStackPubSub/DataSetMessage/DataDeltaFrameDataSetMessage.h"
#include "OpcUaStackPubSub/DataSetMessage/EventDataSetMessage.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackPubSub;

BOOST_AUTO_TEST_SUITE(DataSetPayload_)

BOOST_AUTO_TEST_CASE(DataSetPayload_)
{
	std::cout << "DataSetPayload_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(DataSetPayload_encode_decode_keepalive)
{
	uint32_t pos;
	DataSetPayload value1, value2;
	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	value1.dataSetMessages()->resize(2);
	for (uint32_t idx=0; idx<2; idx++) {
		KeepAliveMessage::SPtr dataSetMessage = constructSPtr<KeepAliveMessage>();
		dataSetMessage->sequenceNumber(idx);
		value1.dataSetMessages()->push_back(dataSetMessage);
	}

	value1.opcUaBinaryEncode(ios);

	OpcUaStackCore::dumpHex(ios);
	std::stringstream ss;
	ss	<< "04 00 04 00 84 03 00 00  84 03 01 00";
	BOOST_REQUIRE(OpcUaStackCore::compare(ios, ss.str(), pos) == true);

	value2.opcUaBinaryDecode(ios);

	BOOST_REQUIRE(value1.dataSetMessages()->size() == 2);
	for (uint32_t idx=0; idx<value2.count(); idx++) {
		DataSetMessage::SPtr dataSetMessage;
		value2.dataSetMessages()->get(idx, dataSetMessage);

		BOOST_REQUIRE(dataSetMessage->sequenceNumber() == idx);
		BOOST_REQUIRE(dataSetMessage->messageType() == KeepAlive);
	}
}

BOOST_AUTO_TEST_CASE(DataSetPayload_encode_decode_data_key)
{
	uint32_t pos;
	DataSetPayload value1, value2;
	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	value1.dataSetMessages()->resize(2);
	for (uint32_t idx=0; idx<2; idx++) {
		DataKeyFrameDataSetMessage::SPtr dataSetMessage = constructSPtr<DataKeyFrameDataSetMessage>();
		dataSetMessage->sequenceNumber(idx);

		dataSetMessage->dataSetFields()->resize(10);
		for (uint32_t idx=0; idx<10; idx++) {
			OpcUaVariant::SPtr variant = constructSPtr<OpcUaVariant>();
			variant->setValue(OpcUaNodeId(idx));

			DataSetField::SPtr dataSetField = constructSPtr<DataSetField>();
			dataSetField->variant(variant);

			dataSetMessage->dataSetFields()->push_back(dataSetField);
		}

		value1.dataSetMessages()->push_back(dataSetMessage);
	}

	value1.opcUaBinaryEncode(ios);

	OpcUaStackCore::dumpHex(ios);

	value2.opcUaBinaryDecode(ios);

	BOOST_REQUIRE(value1.dataSetMessages()->size() == 2);
	for (uint32_t idx=0; idx<value2.count(); idx++) {
		DataSetMessage::SPtr msg;
		value2.dataSetMessages()->get(idx, msg);

		BOOST_REQUIRE(msg->sequenceNumber() == idx);
		BOOST_REQUIRE(msg->messageType() == DataKeyFrame);

		DataKeyFrameDataSetMessage::SPtr dataSetMessage = boost::static_pointer_cast<DataKeyFrameDataSetMessage>(msg);
		BOOST_REQUIRE(dataSetMessage->dataSetFields()->size() == 10);
		for (uint32_t idx=0; idx<10; idx++) {
			DataSetField::SPtr dataSetField;
			dataSetMessage->dataSetFields()->get(idx, dataSetField);

			OpcUaNodeId nodeId;
			dataSetField->variant()->getValue(nodeId);
			BOOST_REQUIRE(nodeId == OpcUaNodeId(idx));
		}
	}
}

BOOST_AUTO_TEST_CASE(DataSetPayload_encode_decode_data_delta)
{
	uint32_t pos;
	DataSetPayload value1, value2;
	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	value1.dataSetMessages()->resize(2);
	for (uint32_t idx=0; idx<2; idx++) {
		DataDeltaFrameDataSetMessage::SPtr dataSetMessage = constructSPtr<DataDeltaFrameDataSetMessage>();
		dataSetMessage->sequenceNumber(idx);

		dataSetMessage->deltaFrameFields()->resize(10);
		for (uint32_t idx=0; idx<10; idx++) {
			OpcUaVariant::SPtr variant = constructSPtr<OpcUaVariant>();
			variant->setValue(OpcUaNodeId(idx));

			DeltaFrameField::SPtr deltaFrameField = constructSPtr<DeltaFrameField>();
			deltaFrameField->variant(variant);
			deltaFrameField->fieldIndex(idx+10);

			dataSetMessage->deltaFrameFields()->push_back(deltaFrameField);
		}

		value1.dataSetMessages()->push_back(dataSetMessage);
	}

	value1.opcUaBinaryEncode(ios);

	OpcUaStackCore::dumpHex(ios);

	value2.opcUaBinaryDecode(ios);

	BOOST_REQUIRE(value1.dataSetMessages()->size() == 2);
	for (uint32_t idx=0; idx<value2.count(); idx++) {
		DataSetMessage::SPtr msg;
		value2.dataSetMessages()->get(idx, msg);

		BOOST_REQUIRE(msg->sequenceNumber() == idx);
		BOOST_REQUIRE(msg->messageType() == DataKeyFrame);

		DataDeltaFrameDataSetMessage::SPtr dataSetMessage = boost::static_pointer_cast<DataDeltaFrameDataSetMessage>(msg);
		BOOST_REQUIRE(dataSetMessage->deltaFrameFields()->size() == 10);
		for (uint32_t idx=0; idx<10; idx++) {
			DeltaFrameField::SPtr deltaFrameField;
			dataSetMessage->deltaFrameFields()->get(idx, deltaFrameField);

			OpcUaNodeId nodeId;
			deltaFrameField->variant()->getValue(nodeId);
			BOOST_REQUIRE(nodeId == OpcUaNodeId(idx));
			BOOST_REQUIRE(deltaFrameField->fieldIndex() == (idx+10));
		}
	}
}

BOOST_AUTO_TEST_CASE(DataSetPayload_encode_decode_event)
{
	uint32_t pos;
	DataSetPayload value1, value2;
	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	value1.dataSetMessages()->resize(2);
	for (uint32_t idx=0; idx<2; idx++) {
		EventDataSetMessage::SPtr dataSetMessage = constructSPtr<EventDataSetMessage>();
		dataSetMessage->sequenceNumber(idx);

		dataSetMessage->dataSetFields()->resize(10);
		for (uint32_t idx=0; idx<10; idx++) {
			OpcUaVariant::SPtr variant = constructSPtr<OpcUaVariant>();
			variant->setValue(OpcUaNodeId(idx));

			DataSetField::SPtr dataSetField = constructSPtr<DataSetField>();
			dataSetField->variant(variant);

			dataSetMessage->dataSetFields()->push_back(dataSetField);
		}

		value1.dataSetMessages()->push_back(dataSetMessage);
	}

	value1.opcUaBinaryEncode(ios);

	OpcUaStackCore::dumpHex(ios);

	value2.opcUaBinaryDecode(ios);

	BOOST_REQUIRE(value1.dataSetMessages()->size() == 2);
	for (uint32_t idx=0; idx<value2.count(); idx++) {
		DataSetMessage::SPtr msg;
		value2.dataSetMessages()->get(idx, msg);

		BOOST_REQUIRE(msg->sequenceNumber() == idx);
		BOOST_REQUIRE(msg->messageType() == DataKeyFrame);

		EventDataSetMessage::SPtr dataSetMessage = boost::static_pointer_cast<EventDataSetMessage>(msg);
		BOOST_REQUIRE(dataSetMessage->dataSetFields()->size() == 10);
		for (uint32_t idx=0; idx<10; idx++) {
			DataSetField::SPtr dataSetField;
			dataSetMessage->dataSetFields()->get(idx, dataSetField);

			OpcUaNodeId nodeId;
			dataSetField->variant()->getValue(nodeId);
			BOOST_REQUIRE(nodeId == OpcUaNodeId(idx));
		}
	}
}


BOOST_AUTO_TEST_SUITE_END()
