#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/SecureChannel/MessageHeader.h"
#include "OpcUaStackCore/SecureChannel/SequenceHeader.h"
#include "OpcUaStackCore/ServiceSet/CloseSessionRequest.h"
#include "OpcUaStackCore/ServiceSet/CloseSessionResponse.h"
#include "OpcUaStackCore/Base/Utility.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(CloseSession_)

BOOST_AUTO_TEST_CASE(CloseSession_)
{
	std::cout << "CloseSession_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(CloseSession_Request)
{
	uint32_t pos;
	MessageHeader::SPtr messageHeaderSPtr;
	boost::posix_time::ptime ptime = boost::posix_time::from_iso_string("16010101T000000.000000000");
	OpcUaGuid::SPtr opcUaGuidSPtr;
	CloseSessionRequest::SPtr closeSessionRequestSPtr;
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
	sequenceHeaderSPtr = constructSPtr<SequenceHeader>();
	sequenceHeaderSPtr->sequenceNumber(140);
	sequenceHeaderSPtr->requestId(90);
	sequenceHeaderSPtr->opcUaBinaryEncode(ios1);

	// encode message type id
	typeId.nodeId(OpcUaId_CloseSessionRequest_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// encode CloseSessionRequest
	opcUaGuidSPtr = constructSPtr<OpcUaGuid>();
	*opcUaGuidSPtr = "12345678-9ABC-DEF0-1234-56789ABCDEF0";
	closeSessionRequestSPtr = constructSPtr<CloseSessionRequest>();

	closeSessionRequestSPtr->requestHeader()->sessionAuthenticationToken().namespaceIndex(1);
	closeSessionRequestSPtr->requestHeader()->sessionAuthenticationToken().nodeId(opcUaGuidSPtr);
	closeSessionRequestSPtr->requestHeader()->time(ptime);
	closeSessionRequestSPtr->requestHeader()->requestHandle(2);
	closeSessionRequestSPtr->requestHeader()->returnDisagnostics(0);
	closeSessionRequestSPtr->requestHeader()->timeoutHint(10000);

	closeSessionRequestSPtr->deleteSubscriptions(true);

	closeSessionRequestSPtr->requestHeader()->opcUaBinaryEncode(ios1);
	closeSessionRequestSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = constructSPtr<MessageHeader>();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);

	std::stringstream ss;
	ss	<< "4d 53 47 46 4b 00 00 00  d9 7a 25 09 01 00 00 00"
		<< "8c 00 00 00 5a 00 00 00  01 00 d9 01 04 01 00 12"
		<< "34 56 78 9a bc de f0 12  34 56 78 9a bc de f0 00"
		<< "00 00 00 00 00 00 00 02  00 00 00 00 00 00 00 ff"
		<< "ff ff ff 10 27 00 00 00  00 00 01";
	BOOST_REQUIRE(OpcUaStackCore::compare(ios, ss.str(), pos) == true);

	// decode MessageHeader
	messageHeaderSPtr = constructSPtr<MessageHeader>();
	messageHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(messageHeaderSPtr->messageType() == MessageType_Message);
	
	// decode channel id
	OpcUaNumber::opcUaBinaryDecode(ios, channelId);
	BOOST_REQUIRE(channelId == 153451225);

	// decode token id
	OpcUaNumber::opcUaBinaryDecode(ios, tokenId);
	BOOST_REQUIRE(tokenId == 1);
	
	// decode sequence header
	sequenceHeaderSPtr = constructSPtr<SequenceHeader>();
	sequenceHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(sequenceHeaderSPtr->sequenceNumber() == 140);
	BOOST_REQUIRE(sequenceHeaderSPtr->requestId() == 90);

	// decode message type id
	typeId.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(typeId.namespaceIndex() == 0);
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_CloseSessionRequest_Encoding_DefaultBinary);

	// decode CloseSessionRequest
	closeSessionRequestSPtr = constructSPtr<CloseSessionRequest>();
	closeSessionRequestSPtr->requestHeader()->opcUaBinaryDecode(ios);
	closeSessionRequestSPtr->opcUaBinaryDecode(ios);

	std::string str;
	str = *closeSessionRequestSPtr->requestHeader()->sessionAuthenticationToken().nodeId<OpcUaGuid::SPtr>();
	BOOST_REQUIRE(closeSessionRequestSPtr->requestHeader()->sessionAuthenticationToken().namespaceIndex() == 1);
	BOOST_REQUIRE(str == "12345678-9ABC-DEF0-1234-56789ABCDEF0");
	BOOST_REQUIRE(closeSessionRequestSPtr->requestHeader()->time().dateTime() == ptime);
	BOOST_REQUIRE(closeSessionRequestSPtr->requestHeader()->requestHandle() == 2);
	BOOST_REQUIRE(closeSessionRequestSPtr->requestHeader()->returnDisagnostics() == 0);
	BOOST_REQUIRE(closeSessionRequestSPtr->requestHeader()->timeoutHint() == 10000);
	BOOST_REQUIRE(closeSessionRequestSPtr->deleteSubscriptions() == true);
}


BOOST_AUTO_TEST_CASE(CloseSession_Response)
{
	uint32_t pos;
	MessageHeader::SPtr messageHeaderSPtr;
	boost::posix_time::ptime ptime = boost::posix_time::from_iso_string("16010101T000000.000000000");
	OpcUaGuid::SPtr opcUaGuidSPtr;
	CloseSessionResponse::SPtr closeSessionResponseSPtr;
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
	sequenceHeaderSPtr = constructSPtr<SequenceHeader>();
	sequenceHeaderSPtr->sequenceNumber(140);
	sequenceHeaderSPtr->requestId(90);
	sequenceHeaderSPtr->opcUaBinaryEncode(ios1);

	// encode message type id
	typeId.nodeId(OpcUaId_CloseSessionResponse_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// encode CloseSessionResponse
	closeSessionResponseSPtr = constructSPtr<CloseSessionResponse>();

	closeSessionResponseSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = constructSPtr<MessageHeader>();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);

	std::stringstream ss;
	ss << "4d 53 47 46 1c 00 00 00  d9 7a 25 09 01 00 00 00"
	   << "8c 00 00 00 5a 00 00 00  01 00 dc 01";
	BOOST_REQUIRE(OpcUaStackCore::compare(ios, ss.str(), pos) == true);

	// decode MessageHeader
	messageHeaderSPtr = constructSPtr<MessageHeader>();
	messageHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(messageHeaderSPtr->messageType() == MessageType_Message);
	
	// decode channel id
	OpcUaNumber::opcUaBinaryDecode(ios, channelId);
	BOOST_REQUIRE(channelId == 153451225);

	// decode token id
	OpcUaNumber::opcUaBinaryDecode(ios, tokenId);
	BOOST_REQUIRE(tokenId == 1);
	
	// decode sequence header
	sequenceHeaderSPtr = constructSPtr<SequenceHeader>();
	sequenceHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(sequenceHeaderSPtr->sequenceNumber() == 140);
	BOOST_REQUIRE(sequenceHeaderSPtr->requestId() == 90);

	// decode message type id
	typeId.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(typeId.namespaceIndex() == 0);
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_CloseSessionResponse_Encoding_DefaultBinary);

	//decode CloseSessionResponse
	closeSessionResponseSPtr = constructSPtr<CloseSessionResponse>();
	closeSessionResponseSPtr->opcUaBinaryDecode(ios);
}

BOOST_AUTO_TEST_SUITE_END()
