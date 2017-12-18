#include "unittest.h"

#include <iostream>
#include <boost/asio.hpp>

#include "OpcUaStackPubSub/DataSetMessage/KeepAliveMessage.h"
#include "OpcUaStackPubSub/Network/NetworkMessage.h"
#include "OpcUaStackCore/Base/Utility.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackPubSub;



BOOST_AUTO_TEST_SUITE(NetworkMessage_)

BOOST_AUTO_TEST_CASE(NetworkMessage_)
{
	std::cout << "NetworkMessage_t" << std::endl;
}

#define ENCODE_DECODE(msg, hexString, restoredMsg) {\
	boost::asio::streambuf sb;\
	std::iostream ios(&sb);\
	uint32_t pos;\
                 \
	msg.opcUaBinaryEncode(ios);\
                               \
	OpcUaStackCore::dumpHex(ios);\
	std::stringstream ss;\
	ss	<< hexString;\
                     \
	BOOST_REQUIRE(OpcUaStackCore::compare(ios, ss.str(), pos));\
                                                               \
	restoredMsg.opcUaBinaryDecode(ios);\
} while(0)


#define SHOULD_ENCODE_DECODE(msg, hexString) {\
	NetworkMessage restoredMsg;\
	ENCODE_DECODE(msg, hexString, restoredMsg);\
                                               \
	BOOST_REQUIRE(restoredMsg == msg);\
} while(0)


BOOST_AUTO_TEST_CASE(NetworkMessage_encode_decode_1dataSetMessage)
{
	NetworkMessage message;
	OpcUaUInt16 writerId = 0x100;
	DataSetMessageArray::SPtr dataSetMessages = constructSPtr<DataSetMessageArray>();
	dataSetMessages->resize(1);
	dataSetMessages->push_back(constructSPtr<KeepAliveMessage>());

	message.dataSetPayloadHeader()->dataSetWriterIds()->resize(1);
	message.dataSetPayloadHeader()->dataSetWriterIds()->push_back(writerId);
	message.dataSetPayload()->count(1);
	message.dataSetPayload()->dataSetMessages(dataSetMessages);

	SHOULD_ENCODE_DECODE(message, "04 00 01 04 00 84 03 00 00");
}

BOOST_AUTO_TEST_CASE(NetworkMessage_encode_decode_2dataSetMessage)
{
	NetworkMessage message;
	OpcUaUInt16 writerId = 0x100;
	DataSetMessageArray::SPtr dataSetMessages = constructSPtr<DataSetMessageArray>();
	dataSetMessages->resize(2);
	dataSetMessages->push_back(constructSPtr<KeepAliveMessage>());
	dataSetMessages->push_back(constructSPtr<KeepAliveMessage>());

	message.dataSetPayloadHeader()->dataSetWriterIds()->resize(2);
	message.dataSetPayloadHeader()->dataSetWriterIds()->push_back(writerId);
	message.dataSetPayloadHeader()->dataSetWriterIds()->push_back(writerId+2);
	message.dataSetPayload()->count(2);
	message.dataSetPayload()->dataSetMessages(dataSetMessages);

	message.networkMessageHeader()->dataSetArrayEnabled(true);
	message.dataSetPayloadHeader()->dataSetArrayEnabled(true);

	SHOULD_ENCODE_DECODE(message, "24 02 00 01 02 01 04 00 04 00 84 03 00 00 84 03 00 00");
}

BOOST_AUTO_TEST_SUITE_END()


