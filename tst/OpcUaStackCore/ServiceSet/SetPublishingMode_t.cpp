#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/ServiceSet/SetPublishingModeRequest.h"
#include "OpcUaStackCore/ServiceSet/SetPublishingModeResponse.h"
#include "OpcUaStackCore/SecureChannel/MessageHeader.h"
#include "OpcUaStackCore/SecureChannel/SequenceHeader.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(SetPublishingMode_)

BOOST_AUTO_TEST_CASE(SetPublishingMode_Title)
{
	std::cout << "SetPublishingMode_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(SetPublishingMode_Request)
{
	uint32_t pos;
	OpcUaNodeId typeId;
	OpcUaUInt32 subscriptionId;
	OpcUaGuid::SPtr opcUaGuidSPtr;
	MessageHeader::SPtr messageHeaderSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
	SetPublishingModeRequest::SPtr setPublishingModeRequestSPtr;
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
	typeId.nodeId(OpcUaId_SetPublishingModeRequest_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// build SetPublishingModeRequest
	setPublishingModeRequestSPtr = SetPublishingModeRequest::construct();

	// build RequestHeader
	opcUaGuidSPtr = OpcUaGuid::construct();
	*opcUaGuidSPtr = "0D4455B2-8D2F-B74F-864F-0AF5945DD833";
	
	setPublishingModeRequestSPtr->requestHeader()->sessionAuthenticationToken().namespaceIndex(1);
	setPublishingModeRequestSPtr->requestHeader()->sessionAuthenticationToken().nodeId(opcUaGuidSPtr);
	setPublishingModeRequestSPtr->requestHeader()->time(ptime);
	setPublishingModeRequestSPtr->requestHeader()->requestHandle(0);
	setPublishingModeRequestSPtr->requestHeader()->returnDisagnostics(0);
	setPublishingModeRequestSPtr->requestHeader()->timeoutHint(300000);
	
	// build Parameter
	setPublishingModeRequestSPtr->publishingEnabled(false);
	setPublishingModeRequestSPtr->subscriptionIds()->set((OpcUaUInt32)153451225);

	// encode SetPublishingModeRequest
	setPublishingModeRequestSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = MessageHeader::construct();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);

	std::stringstream ss;
	ss << "4d 53 47 46 53 00 00 00  d9 7a 25 09 01 00 00 00"
	   << "36 00 00 00 04 00 00 00  01 00 1f 03 04 01 00 0d"
	   << "44 55 b2 8d 2f b7 4f 86  4f 0a f5 94 5d d8 33 00"
	   << "00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 ff"
	   << "ff ff ff e0 93 04 00 00  00 00 00 01 00 00 00 d9"
	   << "7a 25 09";

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
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_SetPublishingModeRequest_Encoding_DefaultBinary);

	// decode ReadRequest
	setPublishingModeRequestSPtr = SetPublishingModeRequest::construct();
	setPublishingModeRequestSPtr->opcUaBinaryDecode(ios);

	std::string str;
	str = *setPublishingModeRequestSPtr->requestHeader()->sessionAuthenticationToken().nodeId<OpcUaGuid::SPtr>();
	BOOST_REQUIRE(setPublishingModeRequestSPtr->requestHeader()->sessionAuthenticationToken().namespaceIndex() == 1);
	BOOST_REQUIRE(str == "0D4455B2-8D2F-B74F-864F-0AF5945DD833");
	BOOST_REQUIRE(setPublishingModeRequestSPtr->requestHeader()->time().dateTime() == ptime);
	BOOST_REQUIRE(setPublishingModeRequestSPtr->requestHeader()->requestHandle() == 0);
	BOOST_REQUIRE(setPublishingModeRequestSPtr->requestHeader()->returnDisagnostics() == 0);
	BOOST_REQUIRE(setPublishingModeRequestSPtr->requestHeader()->timeoutHint() == 300000);
	
	BOOST_REQUIRE(setPublishingModeRequestSPtr->publishingEnabled() == false);
	
	BOOST_REQUIRE(setPublishingModeRequestSPtr->subscriptionIds()->size() == 1);
	setPublishingModeRequestSPtr->subscriptionIds()->get(subscriptionId);
	BOOST_REQUIRE(subscriptionId == 153451225);
}


BOOST_AUTO_TEST_CASE(SetPublishingMode_Response)
{
	uint32_t pos;
	OpcUaNodeId typeId;
	OpcUaStatusCode statusCode;
	MessageHeader::SPtr messageHeaderSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
	SetPublishingModeResponse::SPtr setPublishingModeResponseSPtr;

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
	typeId.nodeId(OpcUaId_SetPublishingModeResponse_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// build SetPublishingModeResponse
	setPublishingModeResponseSPtr = SetPublishingModeResponse::construct();
	setPublishingModeResponseSPtr->responseHeader()->time(ptime);
	setPublishingModeResponseSPtr->responseHeader()->requestHandle(133);
	setPublishingModeResponseSPtr->responseHeader()->serviceResult((OpcUaStatusCode)Success);
	setPublishingModeResponseSPtr->results()->set((OpcUaStatusCode)Success);

	// encode SetPublishingModeResponse
	setPublishingModeResponseSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = MessageHeader::construct();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);

	std::stringstream ss;
	ss << "4d 53 47 46 40 00 00 00  d9 7a 25 09 01 00 00 00"
	   << "36 00 00 00 04 00 00 00  01 00 22 03 00 00 00 00"
	   << "00 00 00 00 85 00 00 00  00 00 00 00 00 00 00 00"
	   << "00 00 00 00 01 00 00 00  00 00 00 00 00 00 00 00";

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
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_SetPublishingModeResponse_Encoding_DefaultBinary);

	// decode PublishResponse
	setPublishingModeResponseSPtr = SetPublishingModeResponse::construct();
	setPublishingModeResponseSPtr->opcUaBinaryDecode(ios);

	BOOST_REQUIRE(setPublishingModeResponseSPtr->responseHeader()->time().dateTime() == ptime);
	BOOST_REQUIRE(setPublishingModeResponseSPtr->responseHeader()->requestHandle() == 133);
	BOOST_REQUIRE(setPublishingModeResponseSPtr->responseHeader()->serviceResult() == Success);

	BOOST_REQUIRE(setPublishingModeResponseSPtr->results()->size() == 1);
	setPublishingModeResponseSPtr->results()->get(statusCode);
	BOOST_REQUIRE(statusCode == Success);
}

BOOST_AUTO_TEST_SUITE_END()
