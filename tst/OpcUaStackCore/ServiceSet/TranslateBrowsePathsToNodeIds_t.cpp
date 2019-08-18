#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/ServiceSet/TranslateBrowsePathsToNodeIdsRequest.h"
#include "OpcUaStackCore/ServiceSet/TranslateBrowsePathsToNodeIdsResponse.h"
#include "OpcUaStackCore/SecureChannel/MessageHeader.h"
#include "OpcUaStackCore/SecureChannel/SequenceHeader.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(TranslateBrowsePathsToNodeIds_)

BOOST_AUTO_TEST_CASE(TranslateBrowsePathsToNodeIds_Title)
{
	std::cout << "TranslateBrowsePathsToNodeIds_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(TranslateBrowsePathsToNodeIds_Request)
{
	RequestHeader::SPtr requestHeader = boost::make_shared<RequestHeader>();
	std::string str;
	uint32_t pos;
	OpcUaNodeId typeId;
	OpcUaGuid::SPtr opcUaGuidSPtr;
	RelativePath emptyRelativePath;
	BrowsePath::SPtr browsePathSPtr;
	TranslateBrowsePathsToNodeIdsRequest::SPtr requestSPtr;
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
	typeId.nodeId(OpcUaId_TranslateBrowsePathsToNodeIdsRequest_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// build
	requestSPtr = boost::make_shared<TranslateBrowsePathsToNodeIdsRequest>();

	// build RequestHeader
	opcUaGuidSPtr = boost::make_shared<OpcUaGuid>();
	*opcUaGuidSPtr = "0D4455B2-8D2F-B74F-864F-0AF5945DD833";
	
	requestHeader->sessionAuthenticationToken().namespaceIndex(1);
	requestHeader->sessionAuthenticationToken().nodeId(opcUaGuidSPtr);
	requestHeader->time(ptime);
	requestHeader->requestHandle(0);
	requestHeader->returnDisagnostics(0);
	requestHeader->timeoutHint(300000);

	// build BrowsePath
	browsePathSPtr = boost::make_shared<BrowsePath>();
	browsePathSPtr->startingNode()->namespaceIndex(2);
	browsePathSPtr->startingNode()->nodeId<OpcUaUInt32>(123);
	browsePathSPtr->relativePath(emptyRelativePath);

	requestSPtr->browsePaths()->set(browsePathSPtr);

	// encode 
	requestHeader->opcUaBinaryEncode(ios1);
	requestSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = boost::make_shared<MessageHeader>();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);
	
	std::stringstream ss;
	ss << "4d 53 47 46 56 00 00 00  d9 7a 25 09 01 00 00 00" 
	   << "36 00 00 00 04 00 00 00  01 00 2a 02 04 01 00 0d"
	   << "44 55 b2 8d 2f b7 4f 86  4f 0a f5 94 5d d8 33 00"
	   << "00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 ff"
       << "ff ff ff e0 93 04 00 00  00 00 01 00 00 00 01 02"
       << "7b 00 00 00 00 00";

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
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_TranslateBrowsePathsToNodeIdsRequest_Encoding_DefaultBinary);

	// decode ReadRequest
	requestSPtr = boost::make_shared<TranslateBrowsePathsToNodeIdsRequest>();
	requestHeader->opcUaBinaryDecode(ios);
	requestSPtr->opcUaBinaryDecode(ios);

	str = *requestHeader->sessionAuthenticationToken().nodeId<OpcUaGuid::SPtr>();
	BOOST_REQUIRE(requestHeader->sessionAuthenticationToken().namespaceIndex() == 1);
	BOOST_REQUIRE(str == "0D4455B2-8D2F-B74F-864F-0AF5945DD833");
	BOOST_REQUIRE(requestHeader->time().dateTime() == ptime);
	BOOST_REQUIRE(requestHeader->requestHandle() == 0);
	BOOST_REQUIRE(requestHeader->returnDisagnostics() == 0);
	BOOST_REQUIRE(requestHeader->timeoutHint() == 300000);
	
	BOOST_REQUIRE(requestSPtr->browsePaths()->size() == 1);
	browsePathSPtr = boost::make_shared<BrowsePath>();
	requestSPtr->browsePaths()->get(browsePathSPtr);
	BOOST_REQUIRE(browsePathSPtr->startingNode()->namespaceIndex() == 2);
	BOOST_REQUIRE(browsePathSPtr->startingNode()->nodeId<OpcUaUInt32>() == 123);
	BOOST_REQUIRE(browsePathSPtr->relativePath().elements().size() == 0);
}


BOOST_AUTO_TEST_CASE(TranslateBrowsePathsToNodeIds_Response)
{
	ResponseHeader::SPtr responseHeader = boost::make_shared<ResponseHeader>();
	uint32_t pos;
	std::string str;
	OpcUaNodeId typeId;
	OpcUaQualifiedName browseName;
	OpcUaLocalizedText displayName;
	OpcUaStatusCode statusCode;
	BrowsePathResult::SPtr browsePathResultSPtr;
	TranslateBrowsePathsToNodeIdsResponse::SPtr responseSPtr;
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
	typeId.nodeId(OpcUaId_TranslateBrowsePathsToNodeIdsResponse_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// build 
	responseSPtr = boost::make_shared<TranslateBrowsePathsToNodeIdsResponse>();

	// build ResponseHeader
	statusCode = Success;
	responseHeader->time(ptime);
	responseHeader->requestHandle(0);
	responseHeader->serviceResult(statusCode);
	
	// build BrowsePathResult
	BrowsePathTarget::SPtr browsePathTarget = boost::make_shared<BrowsePathTarget>();
	browsePathTarget->targetId()->namespaceIndex(2);
	browsePathTarget->targetId()->nodeId<OpcUaUInt32>(123);
	browsePathTarget->remainingPathIndex(321);

	browsePathResultSPtr = boost::make_shared<BrowsePathResult>();
	browsePathResultSPtr->statusCode(Success);
	browsePathResultSPtr->targets()->resize(1);
	browsePathResultSPtr->targets()->push_back(browsePathTarget);

	responseSPtr->results()->set(browsePathResultSPtr);

	// encode 
	responseHeader->opcUaBinaryEncode(ios1);
	responseSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = boost::make_shared<MessageHeader>();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);

	std::stringstream ss;
	ss << "4d 53 47 46 4c 00 00 00  d9 7a 25 09 01 00 00 00"
	   << "36 00 00 00 04 00 00 00  01 00 2d 02 00 00 00 00"
	   << "00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00"
	   << "00 00 00 00 01 00 00 00  00 00 00 00 01 00 00 00"
	   << "01 02 7b 00 41 01 00 00  00 00 00 00";

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
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_TranslateBrowsePathsToNodeIdsResponse_Encoding_DefaultBinary);

	// decode 
	responseSPtr = boost::make_shared<TranslateBrowsePathsToNodeIdsResponse>();
	responseHeader->opcUaBinaryDecode(ios);
	responseSPtr->opcUaBinaryDecode(ios);

	BOOST_REQUIRE(responseHeader->time().dateTime() == ptime);
	BOOST_REQUIRE(responseHeader->requestHandle() == 0);
	BOOST_REQUIRE(responseHeader->serviceResult() == Success);

	BOOST_REQUIRE(responseSPtr->results()->size() == 1);
	browsePathResultSPtr = boost::make_shared<BrowsePathResult>();
	responseSPtr->results()->get(browsePathResultSPtr);
	BOOST_REQUIRE(browsePathResultSPtr->statusCode() == Success);

	BOOST_REQUIRE(browsePathResultSPtr->targets()->size() == 1);
	browsePathResultSPtr->targets()->get(0, browsePathTarget);
	BOOST_REQUIRE(browsePathTarget->targetId()->namespaceIndex() == 2);
	BOOST_REQUIRE(browsePathTarget->targetId()->nodeId<OpcUaUInt32>() == 123);
	BOOST_REQUIRE(browsePathTarget->remainingPathIndex() == 321);
}

BOOST_AUTO_TEST_SUITE_END()
