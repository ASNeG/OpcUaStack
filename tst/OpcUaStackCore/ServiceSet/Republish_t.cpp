#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/ServiceSet/RepublishRequest.h"
#include "OpcUaStackCore/ServiceSet/RepublishResponse.h"
#include "OpcUaStackCore/SecureChannel/MessageHeader.h"
#include "OpcUaStackCore/SecureChannel/SequenceHeader.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(Republish_)

BOOST_AUTO_TEST_CASE(Republish_Title)
{
	std::cout << "Republish_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(Republish_Request)
{
	uint32_t pos;
	OpcUaNodeId typeId;
	OpcUaGuid::SPtr opcUaGuidSPtr;
	MessageHeader::SPtr messageHeaderSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
	RepublishRequest::SPtr republishRequestSPtr;
	boost::posix_time::ptime ptime = boost::posix_time::from_iso_string("16010101T120000.000000000");
	
	// stream
	boost::asio::streambuf sb1;
	std::iostream ios1(&sb1);
	boost::asio::streambuf sb2;
	std::iostream ios2(&sb2);
	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	// encode security header
	OpcUaInt32 secureChannelId;
	OpcUaInt32 secureTokenId;

	secureChannelId = 153451225;
	secureTokenId = 1;

	OpcUaNumber::opcUaBinaryEncode(ios1, secureChannelId);
	OpcUaNumber::opcUaBinaryEncode(ios1, secureTokenId);

	// encode sequence header
	sequenceHeaderSPtr = SequenceHeader::construct();
	sequenceHeaderSPtr->sequenceNumber(54);
	sequenceHeaderSPtr->requestId(4);
	sequenceHeaderSPtr->opcUaBinaryEncode(ios1);

	// encode TypeId
	typeId.nodeId(OpcUaId_RepublishRequest_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// build RepublishRequest
	republishRequestSPtr = RepublishRequest::construct();

	// build RequestHeader
	opcUaGuidSPtr = OpcUaGuid::construct();
	*opcUaGuidSPtr = "0D4455B2-8D2F-B74F-864F-0AF5945DD833";
	
	republishRequestSPtr->requestHeader()->sessionAuthenticationToken().namespaceIndex(1);
	republishRequestSPtr->requestHeader()->sessionAuthenticationToken().nodeId(opcUaGuidSPtr);
	republishRequestSPtr->requestHeader()->time(ptime);
	republishRequestSPtr->requestHeader()->requestHandle(0);
	republishRequestSPtr->requestHeader()->returnDisagnostics(0);
	republishRequestSPtr->requestHeader()->timeoutHint(300000);
	
	republishRequestSPtr->subscriptionId(153451225);
	republishRequestSPtr->retransmitSequenceNumber((OpcUaUInt32)123);

	// encode PublishRequest
	republishRequestSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = MessageHeader::construct();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);

	std::stringstream ss;
	ss << "4d 53 47 46 52 00 00 00  d9 7a 25 09 01 00 00 00"
	   << "36 00 00 00 04 00 00 00  01 00 40 03 04 01 00 0d"
	   << "44 55 b2 8d 2f b7 4f 86  4f 0a f5 94 5d d8 33 00"
	   << "00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 ff"
	   << "ff ff ff e0 93 04 00 00  00 00 d9 7a 25 09 7b 00"
	   << "00 00";

	BOOST_REQUIRE(OpcUaStackCore::compare(ios, ss.str(), pos) == true);

	// decode MessageHeader
	messageHeaderSPtr = MessageHeader::construct();
	messageHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(messageHeaderSPtr->messageType() == MessageType_Message);

	// decode security header
	OpcUaNumber::opcUaBinaryDecode(ios, secureChannelId);
	BOOST_REQUIRE(secureChannelId == 153451225);
	OpcUaNumber::opcUaBinaryDecode(ios, secureTokenId);
	BOOST_REQUIRE(secureTokenId == 1);

	// decode sequence header
	sequenceHeaderSPtr = SequenceHeader::construct();
	sequenceHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(sequenceHeaderSPtr->sequenceNumber() == 54);
	BOOST_REQUIRE(sequenceHeaderSPtr->requestId() == 4);

	// decode message type id
	typeId.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(typeId.namespaceIndex() == 0);
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_RepublishRequest_Encoding_DefaultBinary);

	// decode RepublishRequest
	republishRequestSPtr = RepublishRequest::construct();
	republishRequestSPtr->opcUaBinaryDecode(ios);

	std::string str;
	str = *republishRequestSPtr->requestHeader()->sessionAuthenticationToken().nodeId<OpcUaGuid::SPtr>();
	BOOST_REQUIRE(republishRequestSPtr->requestHeader()->sessionAuthenticationToken().namespaceIndex() == 1);
	BOOST_REQUIRE(str == "0D4455B2-8D2F-B74F-864F-0AF5945DD833");
	BOOST_REQUIRE(republishRequestSPtr->requestHeader()->time().dateTime() == ptime);
	BOOST_REQUIRE(republishRequestSPtr->requestHeader()->requestHandle() == 0);
	BOOST_REQUIRE(republishRequestSPtr->requestHeader()->returnDisagnostics() == 0);
	BOOST_REQUIRE(republishRequestSPtr->requestHeader()->timeoutHint() == 300000);
	BOOST_REQUIRE(republishRequestSPtr->subscriptionId() == 153451225);
	BOOST_REQUIRE(republishRequestSPtr->retransmitSequenceNumber() == 123);
}


BOOST_AUTO_TEST_CASE(Republish_Response)
{
	uint32_t pos;
	OpcUaNodeId typeId;
	MessageHeader::SPtr messageHeaderSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
	RepublishResponse::SPtr republishResponseSPtr;
	NotificationMessage::SPtr notificationMessageSPtr;

	boost::posix_time::ptime ptime;
	
	// test-time
	ptime = boost::posix_time::from_iso_string("16010101T120000.000000000");

	// stream
	boost::asio::streambuf sb1;
	std::iostream ios1(&sb1);
	boost::asio::streambuf sb2;
	std::iostream ios2(&sb2);
	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	// encode security header
	OpcUaInt32 secureChannelId;
	OpcUaInt32 secureTokenId;

	secureChannelId = 153451225;
	secureTokenId = 1;

	OpcUaNumber::opcUaBinaryEncode(ios1, secureChannelId);
	OpcUaNumber::opcUaBinaryEncode(ios1, secureTokenId);

	// encode sequence header
	sequenceHeaderSPtr = SequenceHeader::construct();
	sequenceHeaderSPtr->sequenceNumber(54);
	sequenceHeaderSPtr->requestId(4);
	sequenceHeaderSPtr->opcUaBinaryEncode(ios1);

	// encode TypeId
	typeId.nodeId(OpcUaId_RepublishResponse_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// build RepublishResponse
	republishResponseSPtr = RepublishResponse::construct();
	republishResponseSPtr->responseHeader()->time(ptime);
	republishResponseSPtr->responseHeader()->requestHandle(133);
	republishResponseSPtr->responseHeader()->serviceResult((OpcUaStatusCode)Success);

	// build NotificationMessage (empty NotificationData)
	notificationMessageSPtr = republishResponseSPtr->notificationMessage();
	notificationMessageSPtr->sequenceNumber(1);
	notificationMessageSPtr->publishTime(ptime);

	// encode PublishResponse
	republishResponseSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = MessageHeader::construct();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);

	std::stringstream ss;
	ss << "4d 53 47 46 44 00 00 00  d9 7a 25 09 01 00 00 00"
	   << "36 00 00 00 04 00 00 00  01 00 43 03 00 00 00 00"
	   << "00 00 00 00 85 00 00 00  00 00 00 00 00 00 00 00"
	   << "00 00 00 00 01 00 00 00  00 00 00 00 00 00 00 00"
	   << "00 00 00 00"; 

	BOOST_REQUIRE(OpcUaStackCore::compare(ios, ss.str(), pos) == true);

	// decode MessageHeader
	messageHeaderSPtr = MessageHeader::construct();
	messageHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(messageHeaderSPtr->messageType() == MessageType_Message);

	// decode security header
	OpcUaNumber::opcUaBinaryDecode(ios, secureChannelId);
	BOOST_REQUIRE(secureChannelId == 153451225);
	OpcUaNumber::opcUaBinaryDecode(ios, secureTokenId);
	BOOST_REQUIRE(secureTokenId == 1);

	// decode sequence header
	sequenceHeaderSPtr = SequenceHeader::construct();
	sequenceHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(sequenceHeaderSPtr->sequenceNumber() == 54);
	BOOST_REQUIRE(sequenceHeaderSPtr->requestId() == 4);

	// decode message type id
	typeId.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(typeId.namespaceIndex() == 0);
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_RepublishResponse_Encoding_DefaultBinary);

	// decode PublishResponse
	republishResponseSPtr = RepublishResponse::construct();
	republishResponseSPtr->opcUaBinaryDecode(ios);

	BOOST_REQUIRE(republishResponseSPtr->responseHeader()->time().dateTime() == ptime);
	BOOST_REQUIRE(republishResponseSPtr->responseHeader()->requestHandle() == 133);
	BOOST_REQUIRE(republishResponseSPtr->responseHeader()->serviceResult() == Success);

	notificationMessageSPtr = republishResponseSPtr->notificationMessage();
	BOOST_REQUIRE(notificationMessageSPtr->sequenceNumber() == 1);
	BOOST_REQUIRE(notificationMessageSPtr->publishTime().dateTime() == ptime);
}

BOOST_AUTO_TEST_SUITE_END()
