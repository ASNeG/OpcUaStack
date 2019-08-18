#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/SecureChannel/MessageHeader.h"
#include "OpcUaStackCore/SecureChannel/AcknowledgeMessage.h"
#include "OpcUaStackCore/Base/Utility.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(AcknowledgeMessage_)

BOOST_AUTO_TEST_CASE(AcknowledgeMessage_)
{
	std::cout << "AcknowledgeMessage_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(AcknowledgeMessage_encode_decode)
{
	AcknowledgeMessage::SPtr acknowledgeMessageSPtr;
	MessageHeader::SPtr messageHeaderSPtr;

	// AcknowledgeMessage
	boost::asio::streambuf sb1;
	std::iostream ios1(&sb1);
	acknowledgeMessageSPtr = boost::make_shared<AcknowledgeMessage>();
	acknowledgeMessageSPtr->opcUaBinaryEncode(ios1);

	// MessageHeader
	boost::asio::streambuf sb2;
	std::iostream ios2(&sb2);
	messageHeaderSPtr = boost::make_shared<MessageHeader>();
	messageHeaderSPtr->messageType(MessageType_Acknowledge);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);


	// stream
	boost::asio::streambuf sb3;
	std::iostream ios3(&sb3);
	ios3 << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios3);


	// decode
	messageHeaderSPtr = boost::make_shared<MessageHeader>();
	messageHeaderSPtr->opcUaBinaryDecode(ios3);
	acknowledgeMessageSPtr = boost::make_shared<AcknowledgeMessage>();
	acknowledgeMessageSPtr->opcUaBinaryDecode(ios3);

	BOOST_REQUIRE(messageHeaderSPtr->messageSize() == 28);
}

BOOST_AUTO_TEST_SUITE_END()
