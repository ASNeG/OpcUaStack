#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/ServiceSet/RegisterNodesRequest.h"
#include "OpcUaStackCore/ServiceSet/RegisterNodesResponse.h"
#include "OpcUaStackCore/SecureChannel/MessageHeader.h"
#include "OpcUaStackCore/SecureChannel/SequenceHeader.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(RegisterNodes_)

BOOST_AUTO_TEST_CASE(RegisterNodes_Title)
{
	std::cout << "RegisterNodes_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(RegisterNodes_Request)
{
	RequestHeader::SPtr requestHeader = boost::make_shared<RequestHeader>();
	std::string str;
	uint32_t pos;
	OpcUaNodeId typeId;
	OpcUaGuid::SPtr opcUaGuidSPtr;
	OpcUaNodeId::SPtr nodeIdSPtr;
	RegisterNodesRequest::SPtr registerNodesRequestSPtr;
	MessageHeader::SPtr messageHeaderSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
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
	typeId.nodeId(OpcUaId_RegisterNodesRequest_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// build
	registerNodesRequestSPtr = boost::make_shared<RegisterNodesRequest>();

	// build RequestHeader
	opcUaGuidSPtr = boost::make_shared<OpcUaGuid>();
	*opcUaGuidSPtr = "0D4455B2-8D2F-B74F-864F-0AF5945DD833";
	
	requestHeader->sessionAuthenticationToken().namespaceIndex(1);
	requestHeader->sessionAuthenticationToken().nodeId(opcUaGuidSPtr);
	requestHeader->time(ptime);
	requestHeader->requestHandle(0);
	requestHeader->returnDisagnostics(0);
	requestHeader->timeoutHint(300000);

	// build Parameter
	nodeIdSPtr = boost::make_shared<OpcUaNodeId>();
	nodeIdSPtr->namespaceIndex(2);
	nodeIdSPtr->nodeId<OpcUaUInt32>(123);

	registerNodesRequestSPtr->nodesToRegister()->set(nodeIdSPtr);

	// encode 
	requestHeader->opcUaBinaryEncode(ios1);
	registerNodesRequestSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = boost::make_shared<MessageHeader>();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);
	
	std::stringstream ss;
	ss << "4d 53 47 46 52 00 00 00  d9 7a 25 09 01 00 00 00" 
	   << "36 00 00 00 04 00 00 00  01 00 30 02 04 01 00 0d"
	   << "44 55 b2 8d 2f b7 4f 86  4f 0a f5 94 5d d8 33 00"
	   << "00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 ff"
       << "ff ff ff e0 93 04 00 00  00 00 01 00 00 00 01 02"
       << "7b 00";

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
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_RegisterNodesRequest_Encoding_DefaultBinary);

	// decode 
	registerNodesRequestSPtr = boost::make_shared<RegisterNodesRequest>();
	requestHeader->opcUaBinaryDecode(ios);
	registerNodesRequestSPtr->opcUaBinaryDecode(ios);

	str = *requestHeader->sessionAuthenticationToken().nodeId<OpcUaGuid::SPtr>();
	BOOST_REQUIRE(requestHeader->sessionAuthenticationToken().namespaceIndex() == 1);
	BOOST_REQUIRE(str == "0D4455B2-8D2F-B74F-864F-0AF5945DD833");
	BOOST_REQUIRE(requestHeader->time().dateTime() == ptime);
	BOOST_REQUIRE(requestHeader->requestHandle() == 0);
	BOOST_REQUIRE(requestHeader->returnDisagnostics() == 0);
	BOOST_REQUIRE(requestHeader->timeoutHint() == 300000);
	
	BOOST_REQUIRE(registerNodesRequestSPtr->nodesToRegister()->size() == 1);
	nodeIdSPtr = boost::make_shared<OpcUaNodeId>();
	registerNodesRequestSPtr->nodesToRegister()->get(nodeIdSPtr);
	BOOST_REQUIRE(nodeIdSPtr->namespaceIndex() == 2);
	BOOST_REQUIRE(nodeIdSPtr->nodeId<OpcUaUInt32>() == 123);
}


BOOST_AUTO_TEST_CASE(RegisterNodes_Response)
{
	ResponseHeader::SPtr responseHeader = boost::make_shared<ResponseHeader>();
	uint32_t pos;
	std::string str;
	OpcUaNodeId typeId;
	OpcUaQualifiedName browseName;
	OpcUaLocalizedText displayName;
	OpcUaStatusCode statusCode;
	OpcUaNodeId::SPtr nodeIdSPtr;
	RegisterNodesResponse::SPtr registerNodesResponseSPtr;
	MessageHeader::SPtr messageHeaderSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
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
	typeId.nodeId(OpcUaId_RegisterNodesResponse_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// build 
	registerNodesResponseSPtr = boost::make_shared<RegisterNodesResponse>();

	// build ResponseHeader
	statusCode = Success;
	responseHeader->time(ptime);
	responseHeader->requestHandle(0);
	responseHeader->serviceResult(statusCode);
	
	// build Parameter
	nodeIdSPtr = boost::make_shared<OpcUaNodeId>();
	nodeIdSPtr->namespaceIndex(2);
	nodeIdSPtr->nodeId<OpcUaUInt32>(123);

	registerNodesResponseSPtr->registeredNodeIds()->set(nodeIdSPtr);

	// encode 
	responseHeader->opcUaBinaryEncode(ios1);
	registerNodesResponseSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = boost::make_shared<MessageHeader>();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);

	std::stringstream ss;
	ss << "4d 53 47 46 3c 00 00 00  d9 7a 25 09 01 00 00 00"
	   << "36 00 00 00 04 00 00 00  01 00 33 02 00 00 00 00"
	   << "00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00"
	   << "00 00 00 00 01 00 00 00  01 02 7b 00";

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
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_RegisterNodesResponse_Encoding_DefaultBinary);

	// decode 
	registerNodesResponseSPtr = boost::make_shared<RegisterNodesResponse>();
	responseHeader->opcUaBinaryDecode(ios);
	registerNodesResponseSPtr->opcUaBinaryDecode(ios);

	BOOST_REQUIRE(responseHeader->time().dateTime() == ptime);
	BOOST_REQUIRE(responseHeader->requestHandle() == 0);
	BOOST_REQUIRE(responseHeader->serviceResult() == Success);

	BOOST_REQUIRE(registerNodesResponseSPtr->registeredNodeIds()->size() == 1);
	nodeIdSPtr = boost::make_shared<OpcUaNodeId>();
	registerNodesResponseSPtr->registeredNodeIds()->get(nodeIdSPtr);
	BOOST_REQUIRE(nodeIdSPtr->namespaceIndex() == 2);
	BOOST_REQUIRE(nodeIdSPtr->nodeId<OpcUaUInt32>() == 123);
}

BOOST_AUTO_TEST_SUITE_END()
