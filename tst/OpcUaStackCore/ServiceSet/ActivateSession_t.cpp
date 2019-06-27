#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/SecureChannel/MessageHeader.h"
#include "OpcUaStackCore/SecureChannel/SequenceHeader.h"
#include "OpcUaStackCore/ServiceSet/AnonymousIdentityToken.h"
#include "OpcUaStackCore/ServiceSet/ActivateSessionRequest.h"
#include "OpcUaStackCore/ServiceSet/ActivateSessionResponse.h"
#include "OpcUaStackCore/Base/Utility.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(ActivateSession_)

BOOST_AUTO_TEST_CASE(ActivateSession_)
{
	std::cout << "ActivateSession_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(ActivateSession_Request)
{
	ExtensibleParameter ep;
	ep.registerFactoryElement<AnonymousIdentityToken>(OpcUaId_AnonymousIdentityToken_Encoding_DefaultBinary);

	uint32_t pos;
	OpcUaString::SPtr localeIdSPtr;
	MessageHeader::SPtr messageHeaderSPtr;
	boost::posix_time::ptime ptime = boost::posix_time::from_iso_string("16010101T000000.000000000");
	OpcUaGuid::SPtr opcUaGuidSPtr;
	ActivateSessionRequest::SPtr activateSessionRequestSPtr;
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
	sequenceHeaderSPtr->sequenceNumber(53);
	sequenceHeaderSPtr->requestId(3);
	sequenceHeaderSPtr->opcUaBinaryEncode(ios1);

	// encode message type id
	typeId.nodeId(OpcUaId_ActivateSessionRequest_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// encode ActivateSessionRequest
	opcUaGuidSPtr = constructSPtr<OpcUaGuid>();
	*opcUaGuidSPtr = "12345678-9ABC-DEF0-1234-56789ABCDEF0";
	activateSessionRequestSPtr = constructSPtr<ActivateSessionRequest>();

	activateSessionRequestSPtr->localeIds()->resize(1);
	localeIdSPtr = constructSPtr<OpcUaString>();
	*localeIdSPtr = "en";
	activateSessionRequestSPtr->localeIds()->push_back(localeIdSPtr);

	activateSessionRequestSPtr->userIdentityToken()->parameterTypeId().nodeId(OpcUaId_AnonymousIdentityToken_Encoding_DefaultBinary);
	AnonymousIdentityToken::SPtr anonymousIdentityToken = activateSessionRequestSPtr->userIdentityToken()->parameter<AnonymousIdentityToken>();
	anonymousIdentityToken->policyId("OpcUaStack");

	activateSessionRequestSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = constructSPtr<MessageHeader>();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);

	std::stringstream ss;
	ss << "4d 53 47 46 51 00 00 00  d9 7a 25 09 01 00 00 00"
	   << "35 00 00 00 03 00 00 00  01 00 d3 01 ff ff ff ff"
	   << "ff ff ff ff 00 00 00 00  01 00 00 00 02 00 00 00"
	   << "65 6e 01 00 41 01 01 0e  00 00 00 0a 00 00 00 4f"
	   << "70 63 55 61 53 74 61 63  6b ff ff ff ff ff ff ff"
	   << "ff";
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
	BOOST_REQUIRE(sequenceHeaderSPtr->sequenceNumber() == 53);
	BOOST_REQUIRE(sequenceHeaderSPtr->requestId() == 3);

	// decode message type id
	typeId.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(typeId.namespaceIndex() == 0);
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_ActivateSessionRequest_Encoding_DefaultBinary);

	// decode ActivateSessionRequest
	activateSessionRequestSPtr = constructSPtr<ActivateSessionRequest>();
	activateSessionRequestSPtr->opcUaBinaryDecode(ios);

	std::string str;
	str = *localeIdSPtr;
	BOOST_REQUIRE(str == "en");
	BOOST_REQUIRE(activateSessionRequestSPtr->userIdentityToken()->parameterTypeId().nodeId<OpcUaUInt32>() == OpcUaId_AnonymousIdentityToken_Encoding_DefaultBinary);
	anonymousIdentityToken = activateSessionRequestSPtr->userIdentityToken()->parameter<AnonymousIdentityToken>();
	BOOST_REQUIRE(anonymousIdentityToken->policyId() == "OpcUaStack");
}


BOOST_AUTO_TEST_CASE(ActivateSession_Response)
{
	uint32_t pos;
	MessageHeader::SPtr messageHeaderSPtr;
	boost::posix_time::ptime ptime = boost::posix_time::from_iso_string("16010101T000000.000000000");
	OpcUaGuid::SPtr opcUaGuidSPtr;
	ActivateSessionResponse::SPtr activateSessionResponseSPtr;
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
	sequenceHeaderSPtr->sequenceNumber(53);
	sequenceHeaderSPtr->requestId(3);
	sequenceHeaderSPtr->opcUaBinaryEncode(ios1);

	// encode message type id
	typeId.nodeId(OpcUaId_ActivateSessionResponse_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// encode ActivateSessionResponse
	activateSessionResponseSPtr = constructSPtr<ActivateSessionResponse>();

	activateSessionResponseSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = constructSPtr<MessageHeader>();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);

	std::stringstream ss;
	ss << "4d 53 47 46 28 00 00 00  d9 7a 25 09 01 00 00 00"
	   << "35 00 00 00 03 00 00 00  01 00 d6 01 ff ff ff ff"
	   << "00 00 00 00 00 00 00 00";
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
	BOOST_REQUIRE(sequenceHeaderSPtr->sequenceNumber() == 53);
	BOOST_REQUIRE(sequenceHeaderSPtr->requestId() == 3);

	// decode message type id
	typeId.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(typeId.namespaceIndex() == 0);
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_ActivateSessionResponse_Encoding_DefaultBinary);

	//decode ActivateSessionResponse
	activateSessionResponseSPtr = constructSPtr<ActivateSessionResponse>();
	activateSessionResponseSPtr->opcUaBinaryDecode(ios);

	BOOST_REQUIRE(activateSessionResponseSPtr->results()->size() == 0);
	BOOST_REQUIRE(activateSessionResponseSPtr->diagnosticInfos()->size() == 0);
}

BOOST_AUTO_TEST_SUITE_END()
