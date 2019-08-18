#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/ServiceSet/RegisterServerRequest.h"
#include "OpcUaStackCore/ServiceSet/RegisterServerResponse.h"
#include "OpcUaStackCore/SecureChannel/MessageHeader.h"
#include "OpcUaStackCore/SecureChannel/SequenceHeader.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(RegisterServer_)

BOOST_AUTO_TEST_CASE(RegisterServer_Title)
{
	std::cout << "RegisterServer_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(RegisterServer_Request)
{
	uint32_t pos;
	OpcUaNodeId typeId;
	OpcUaGuid::SPtr opcUaGuidSPtr;
	OpcUaString::SPtr stringSPtr;
	OpcUaLocalizedText::SPtr localizedTextSPtr;
	MessageHeader::SPtr messageHeaderSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
	RegisterServerRequest::SPtr registerServerRequestSPtr;
	boost::posix_time::ptime ptime = boost::posix_time::from_iso_string("16010101T000000.000000000");
	
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
	sequenceHeaderSPtr = boost::make_shared<SequenceHeader>();
	sequenceHeaderSPtr->sequenceNumber(54);
	sequenceHeaderSPtr->requestId(4);
	sequenceHeaderSPtr->opcUaBinaryEncode(ios1);

	// encode TypeId
	typeId.nodeId(OpcUaId_RegisterServerRequest_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// build 
	registerServerRequestSPtr = boost::make_shared<RegisterServerRequest>();

	// build RequestHeader
	opcUaGuidSPtr = boost::make_shared<OpcUaGuid>();
	*opcUaGuidSPtr = "0D4455B2-8D2F-B74F-864F-0AF5945DD833";
	
	// build RegisteredServer
	localizedTextSPtr = boost::make_shared<OpcUaLocalizedText>();
	localizedTextSPtr->set("en", "TestString");

	stringSPtr = boost::make_shared<OpcUaString>();
	stringSPtr->value("TestString");

	registerServerRequestSPtr->server().serverUri() = "Uri1";
	registerServerRequestSPtr->server().productUri() = "Uri2";
	registerServerRequestSPtr->server().serverNames().resize(1);
	registerServerRequestSPtr->server().serverNames().push_back(localizedTextSPtr);
	registerServerRequestSPtr->server().serverType().enumeration(ApplicationType::EnumServer);
	registerServerRequestSPtr->server().gatewayServerUri() = "Uri3";
	registerServerRequestSPtr->server().discoveryUrls().resize(1);
	registerServerRequestSPtr->server().discoveryUrls().push_back(stringSPtr);
	registerServerRequestSPtr->server().semaphoreFilePath() = "Path123";
	registerServerRequestSPtr->server().isOnline() = true;

	// encode
	registerServerRequestSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = boost::make_shared<MessageHeader>();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);
	
	std::stringstream ss;
	ss << "4d 53 47 46 6f 00 00 00  d9 7a 25 09 01 00 00 00"
	   << "36 00 00 00 04 00 00 00  01 00 b5 01 04 00 00 00"
	   << "55 72 69 31 04 00 00 00  55 72 69 32 01 00 00 00"
	   << "03 02 00 00 00 65 6e 0a  00 00 00 54 65 73 74 53"
	   << "74 72 69 6e 67 00 00 00  00 04 00 00 00 55 72 69"
	   << "33 01 00 00 00 0a 00 00  00 54 65 73 74 53 74 72"
	   << "69 6e 67 07 00 00 00 50  61 74 68 31 32 33 01";

	BOOST_REQUIRE(OpcUaStackCore::compare(ios, ss.str(), pos) == true);

	// decode MessageHeader
	messageHeaderSPtr = boost::make_shared<MessageHeader>();
	messageHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(messageHeaderSPtr->messageType() == MessageType_Message);

	// decode security header
	OpcUaNumber::opcUaBinaryDecode(ios, secureChannelId);
	BOOST_REQUIRE(secureChannelId == 153451225);
	OpcUaNumber::opcUaBinaryDecode(ios, secureTokenId);
	BOOST_REQUIRE(secureTokenId == 1);

	// decode sequence header
	sequenceHeaderSPtr = boost::make_shared<SequenceHeader>();
	sequenceHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(sequenceHeaderSPtr->sequenceNumber() == 54);
	BOOST_REQUIRE(sequenceHeaderSPtr->requestId() == 4);

	// decode message type id
	typeId.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(typeId.namespaceIndex() == 0);
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_RegisterServerRequest_Encoding_DefaultBinary);

	// decode
	registerServerRequestSPtr = boost::make_shared<RegisterServerRequest>();
	registerServerRequestSPtr->opcUaBinaryDecode(ios);
	
	BOOST_REQUIRE(registerServerRequestSPtr->server().serverUri().value() == "Uri1");
	BOOST_REQUIRE(registerServerRequestSPtr->server().productUri().value() == "Uri2");

	BOOST_REQUIRE(registerServerRequestSPtr->server().serverNames().size() == 1);
	registerServerRequestSPtr->server().serverNames().get(localizedTextSPtr);
	BOOST_REQUIRE(localizedTextSPtr->text().value() == "TestString");

	BOOST_REQUIRE(registerServerRequestSPtr->server().serverType().enumeration() == ApplicationType::EnumServer);
	BOOST_REQUIRE(registerServerRequestSPtr->server().gatewayServerUri().value() == "Uri3");

	BOOST_REQUIRE(registerServerRequestSPtr->server().discoveryUrls().size() == 1);
	registerServerRequestSPtr->server().discoveryUrls().get(stringSPtr);
	BOOST_REQUIRE(stringSPtr->value() == "TestString");

	BOOST_REQUIRE(registerServerRequestSPtr->server().semaphoreFilePath().value() == "Path123");
	BOOST_REQUIRE(registerServerRequestSPtr->server().isOnline() == true);
}


BOOST_AUTO_TEST_CASE(RegisterServer_Response)
{
	uint32_t pos;
	OpcUaNodeId typeId;
	OpcUaStatusCode statusCode;
	MessageHeader::SPtr messageHeaderSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
	RegisterServerResponse::SPtr registerServerResponseSPtr;
	OpcUaDateTime sourceTimestamp, serverTimestamp;
	OpcUaDataValue::SPtr dataValueSPtr;
	OpcUaVariant::SPtr variantSPtr;
	boost::posix_time::ptime ptime;
	
	// test-time
	ptime = boost::posix_time::from_iso_string("16010101T000000.000000000");

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
	sequenceHeaderSPtr = boost::make_shared<SequenceHeader>();
	sequenceHeaderSPtr->sequenceNumber(54);
	sequenceHeaderSPtr->requestId(4);
	sequenceHeaderSPtr->opcUaBinaryEncode(ios1);

	// encode TypeId
	typeId.nodeId(OpcUaId_RegisterServerResponse_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// build 
	registerServerResponseSPtr = boost::make_shared<RegisterServerResponse>();

	// build ResponseHeader
	statusCode = Success;
	registerServerResponseSPtr->responseHeader()->time(ptime);
	registerServerResponseSPtr->responseHeader()->requestHandle(0);
	registerServerResponseSPtr->responseHeader()->serviceResult(statusCode);

	// encode 
	registerServerResponseSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = boost::make_shared<MessageHeader>();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);

	std::stringstream ss;
	ss << "4d 53 47 46 34 00 00 00  d9 7a 25 09 01 00 00 00"
	   << "36 00 00 00 04 00 00 00  01 00 b8 01 00 00 00 00"
	   << "00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00"
	   << "00 00 00 00";

	BOOST_REQUIRE(OpcUaStackCore::compare(ios, ss.str(), pos) == true);

	// decode MessageHeader
	messageHeaderSPtr = boost::make_shared<MessageHeader>();
	messageHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(messageHeaderSPtr->messageType() == MessageType_Message);

	// decode security header
	OpcUaNumber::opcUaBinaryDecode(ios, secureChannelId);
	BOOST_REQUIRE(secureChannelId == 153451225);
	OpcUaNumber::opcUaBinaryDecode(ios, secureTokenId);
	BOOST_REQUIRE(secureTokenId == 1);

	// decode sequence header
	sequenceHeaderSPtr = boost::make_shared<SequenceHeader>();
	sequenceHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(sequenceHeaderSPtr->sequenceNumber() == 54);
	BOOST_REQUIRE(sequenceHeaderSPtr->requestId() == 4);

	// decode message type id
	typeId.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(typeId.namespaceIndex() == 0);
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_RegisterServerResponse_Encoding_DefaultBinary);

	// decode 
	registerServerResponseSPtr = boost::make_shared<RegisterServerResponse>();
	registerServerResponseSPtr->opcUaBinaryDecode(ios);

	BOOST_REQUIRE(registerServerResponseSPtr->responseHeader()->time().dateTime() == ptime);
	BOOST_REQUIRE(registerServerResponseSPtr->responseHeader()->requestHandle() == 0);
	BOOST_REQUIRE(registerServerResponseSPtr->responseHeader()->serviceResult() == Success);
}

BOOST_AUTO_TEST_SUITE_END()
