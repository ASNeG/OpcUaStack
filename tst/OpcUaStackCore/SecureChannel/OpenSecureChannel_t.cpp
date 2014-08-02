#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/SecureChannel/MessageHeader.h"
#include "OpcUaStackCore/SecureChannel/OpenSecureChannelRequest.h"
#include "OpcUaStackCore/SecureChannel/SecurityHeader.h"
#include "OpcUaStackCore/SecureChannel/SequenceHeader.h"
#include "OpcUaStackCore/Base/Utility.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(OpenSecureChannel_)

BOOST_AUTO_TEST_CASE(OpenSecureChannel_)
{
	std::cout << "OpenSecureChannel_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(OpenSecureChannel_encode_decode)
{
	OpenSecureChannelRequest::SPtr openSecureChannelRequestSPtr;
	MessageHeader::SPtr messageHeaderSPtr;
	SecurityHeader::SPtr securityHeaderSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
	RequestHeader::SPtr requestHeaderSPtr;

	// stream
	boost::asio::streambuf sb1;
	std::iostream ios1(&sb1);
	boost::asio::streambuf sb2;
	std::iostream ios2(&sb2);

	// channel id
	OpcUaUInt32 channelId;
	channelId = 0;
	OpcUaStackCore::opcUaBinaryEncode(ios1, channelId);

	// security header
	securityHeaderSPtr = SecurityHeader::construct();
	securityHeaderSPtr->securityPolicyUri((OpcUaByte*)"http://opcfoundation.org/UA/SecurityPolicy#None", (OpcUaInt32)strlen("http://opcfoundation.org/UA/SecurityPolicy#None"));
	securityHeaderSPtr->opcUaBinaryEncode(ios1);

	// sequence header
	sequenceHeaderSPtr = SequenceHeader::construct();
	sequenceHeaderSPtr->sequenceNumber(51);
	sequenceHeaderSPtr->requestId(1);
	sequenceHeaderSPtr->opcUaBinaryEncode(ios1);

	// message type id
	OpcUaNodeId typeId;
	typeId.nodeId(OpcUaId_OpenSecureChannelRequest_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// RequestHeader
	requestHeaderSPtr = RequestHeader::construct();

	// OpenSecureChannel
	OpcUaByte clientNonce[1];
	clientNonce[0] = 0x00;
	openSecureChannelRequestSPtr = OpenSecureChannelRequest::construct();
	openSecureChannelRequestSPtr->requestHeader(requestHeaderSPtr);
	openSecureChannelRequestSPtr->securityMode(SecurityMode::None);
	openSecureChannelRequestSPtr->clientNonce( clientNonce, 1);
	openSecureChannelRequestSPtr->requestedLifetime(300000);
	openSecureChannelRequestSPtr->opcUaBinaryEncode(ios1);

	// MessageHeader
	messageHeaderSPtr = MessageHeader::construct();
	messageHeaderSPtr->messageType(MessageType::MessageType_OpenSecureChannel);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	boost::asio::streambuf sb3;
	std::iostream ios3(&sb3);
	ios3 << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios3);

#if 0
	// decode
	messageHeaderSPtr = MessageHeader::construct();
	messageHeaderSPtr->opcUaBinaryDecode(ios3);
	OpenSecureChannelRequestSPtr = OpenSecureChannelRequest::construct();
	OpenSecureChannelRequestSPtr->opcUaBinaryDecode(ios3);
#endif
}

BOOST_AUTO_TEST_SUITE_END()