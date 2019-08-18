#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/SecureChannel/MessageHeader.h"
#include "OpcUaStackCore/SecureChannel/SequenceHeader.h"
#include "OpcUaStackCore/ServiceSet/CancelRequest.h"
#include "OpcUaStackCore/ServiceSet/CancelResponse.h"
#include "OpcUaStackCore/Base/Utility.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(Cancel_)

BOOST_AUTO_TEST_CASE(Cancel_)
{
	std::cout << "Cancel_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(Cancel_Request)
{
	uint32_t pos;
	MessageHeader::SPtr messageHeaderSPtr;
	boost::posix_time::ptime ptime = boost::posix_time::from_iso_string("16010101T000000.000000000");
	OpcUaGuid::SPtr opcUaGuidSPtr;
	CancelRequest::SPtr cancelRequestSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
	OpcUaNodeId typeId;

	// stream
	boost::asio::streambuf sb1;
	std::iostream ios1(&sb1);
	boost::asio::streambuf sb2;
	std::iostream ios2(&sb2);
	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	// encode channel id
	OpcUaUInt32 channelId;
	channelId = 153451225;
	OpcUaNumber::opcUaBinaryEncode(ios1, channelId);

	// encode token id
	OpcUaInt32 tokenId;
	tokenId = 1;
	OpcUaNumber::opcUaBinaryEncode(ios1, tokenId);

	// encode sequence header
	sequenceHeaderSPtr = boost::make_shared<SequenceHeader>();
	sequenceHeaderSPtr->sequenceNumber(140);
	sequenceHeaderSPtr->requestId(90);
	sequenceHeaderSPtr->opcUaBinaryEncode(ios1);

	// encode message type id
	typeId.nodeId((OpcUaUInt32)OpcUaId_CancelRequest_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// encode CancelRequest
	cancelRequestSPtr = boost::make_shared<CancelRequest>();
	cancelRequestSPtr->requestHandle(4711);
	cancelRequestSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = boost::make_shared<MessageHeader>();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);

	std::stringstream ss;
	ss << "4d 53 47 46 20 00 00 00  d9 7a 25 09 01 00 00 00"
	   << "8c 00 00 00 5a 00 00 00  01 00 df 01 67 12 00 00";
	BOOST_REQUIRE(OpcUaStackCore::compare(ios, ss.str(), pos) == true);

	// decode MessageHeader
	messageHeaderSPtr = boost::make_shared<MessageHeader>();
	messageHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(messageHeaderSPtr->messageType() == MessageType_Message);
	
	// decode channel id
	OpcUaNumber::opcUaBinaryDecode(ios, channelId);
	BOOST_REQUIRE(channelId == 153451225);

	// decode token id
	OpcUaNumber::opcUaBinaryDecode(ios, tokenId);
	BOOST_REQUIRE(tokenId == 1);
	
	// decode sequence header
	sequenceHeaderSPtr = boost::make_shared<SequenceHeader>();
	sequenceHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(sequenceHeaderSPtr->sequenceNumber() == 140);
	BOOST_REQUIRE(sequenceHeaderSPtr->requestId() == 90);

	// decode message type id
	typeId.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(typeId.namespaceIndex() == 0);
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_CancelRequest_Encoding_DefaultBinary);

	// decode CancelRequest
	cancelRequestSPtr = boost::make_shared<CancelRequest>();
	cancelRequestSPtr->opcUaBinaryDecode(ios);
}


BOOST_AUTO_TEST_CASE(Cancel_Response)
{
	uint32_t pos;
	MessageHeader::SPtr messageHeaderSPtr;
	boost::posix_time::ptime ptime = boost::posix_time::from_iso_string("16010101T000000.000000000");
	OpcUaGuid::SPtr opcUaGuidSPtr;
	CancelResponse::SPtr cancelResponseSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
	OpcUaNodeId typeId;

	// stream
	boost::asio::streambuf sb1;
	std::iostream ios1(&sb1);
	boost::asio::streambuf sb2;
	std::iostream ios2(&sb2);
	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	// encode channel id
	OpcUaUInt32 channelId;
	channelId = 153451225;
	OpcUaNumber::opcUaBinaryEncode(ios1, channelId);

	// encode token id
	OpcUaInt32 tokenId;
	tokenId = 1;
	OpcUaNumber::opcUaBinaryEncode(ios1, tokenId);

	// encode sequence header
	sequenceHeaderSPtr = boost::make_shared<SequenceHeader>();
	sequenceHeaderSPtr->sequenceNumber(140);
	sequenceHeaderSPtr->requestId(90);
	sequenceHeaderSPtr->opcUaBinaryEncode(ios1);

	// encode message type id
	typeId.nodeId(OpcUaId_CancelResponse_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// encode CancelResponse
	cancelResponseSPtr = boost::make_shared<CancelResponse>();

	cancelResponseSPtr->responseHeader()->time(ptime);
	cancelResponseSPtr->responseHeader()->requestHandle(1);
	cancelResponseSPtr->responseHeader()->serviceResult(Success);
	cancelResponseSPtr->cancelCount(1);

	cancelResponseSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = boost::make_shared<MessageHeader>();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);

	std::stringstream ss;
	ss << "4d 53 47 46 38 00 00 00  d9 7a 25 09 01 00 00 00"
	   << "8c 00 00 00 5a 00 00 00  01 00 e2 01 00 00 00 00"
	   << "00 00 00 00 01 00 00 00  00 00 00 00 00 00 00 00"
	   << "00 00 00 00 01 00 00 00";
	BOOST_REQUIRE(OpcUaStackCore::compare(ios, ss.str(), pos) == true);

	// decode MessageHeader
	messageHeaderSPtr = boost::make_shared<MessageHeader>();
	messageHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(messageHeaderSPtr->messageType() == MessageType_Message);
	
	// decode channel id
	OpcUaNumber::opcUaBinaryDecode(ios, channelId);
	BOOST_REQUIRE(channelId == 153451225);

	// decode token id
	OpcUaNumber::opcUaBinaryDecode(ios, tokenId);
	BOOST_REQUIRE(tokenId == 1);
	
	// decode sequence header
	sequenceHeaderSPtr = boost::make_shared<SequenceHeader>();
	sequenceHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(sequenceHeaderSPtr->sequenceNumber() == 140);
	BOOST_REQUIRE(sequenceHeaderSPtr->requestId() == 90);

	// decode message type id
	typeId.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(typeId.namespaceIndex() == 0);
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_CancelResponse_Encoding_DefaultBinary);

	//decode CancelResponse
	cancelResponseSPtr = boost::make_shared<CancelResponse>();
	cancelResponseSPtr->opcUaBinaryDecode(ios);

	BOOST_REQUIRE(cancelResponseSPtr->responseHeader()->time().dateTime() == ptime);
	BOOST_REQUIRE(cancelResponseSPtr->responseHeader()->requestHandle() == 1);
	BOOST_REQUIRE(cancelResponseSPtr->responseHeader()->serviceResult() == Success);
	BOOST_REQUIRE(cancelResponseSPtr->cancelCount() == 1);
}

BOOST_AUTO_TEST_SUITE_END()
