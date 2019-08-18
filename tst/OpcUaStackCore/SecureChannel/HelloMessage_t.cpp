#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/SecureChannel/MessageHeader.h"
#include "OpcUaStackCore/SecureChannel/HelloMessage.h"
#include "OpcUaStackCore/Base/Utility.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(HelloMessage_)

BOOST_AUTO_TEST_CASE(HelloMessage_)
{
	std::cout << "HelloMessage_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(HelloMessage_encode_decode)
{
	HelloMessage::SPtr helloMessageSPtr;
	MessageHeader::SPtr messageHeaderSPtr;

	// HelloMessage
	boost::asio::streambuf sb1;
	std::iostream ios1(&sb1);
	helloMessageSPtr = boost::make_shared<HelloMessage>();
	helloMessageSPtr->endpointUrl("opc.tcp://localhost:4841");
	helloMessageSPtr->opcUaBinaryEncode(ios1);

	// MessageHeader
	boost::asio::streambuf sb2;
	std::iostream ios2(&sb2);
	messageHeaderSPtr = boost::make_shared<MessageHeader>();
	messageHeaderSPtr->messageType(MessageType_Hello);
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
	helloMessageSPtr = boost::make_shared<HelloMessage>();
	helloMessageSPtr->opcUaBinaryDecode(ios3);

	BOOST_REQUIRE(messageHeaderSPtr->messageSize() == 56);
	BOOST_REQUIRE(helloMessageSPtr->endpointUrl() == "opc.tcp://localhost:4841");
}

BOOST_AUTO_TEST_SUITE_END()
