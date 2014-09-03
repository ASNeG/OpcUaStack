#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/ServiceSet/QueryFirstRequest.h"
#include "OpcUaStackCore/ServiceSet/QueryFirstResponse.h"
#include "OpcUaStackCore/SecureChannel/MessageHeader.h"
#include "OpcUaStackCore/SecureChannel/SequenceHeader.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(QueryFirst_)

BOOST_AUTO_TEST_CASE(QueryFirst_Title)
{
	std::cout << "QueryFirst_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(QueryFirst_Request)
{
	std::string str;
	uint32_t pos;
	OpcUaNodeId typeId;
	OpcUaGuid::SPtr opcUaGuidSPtr;
	ContentFilter emptyContentFilter;
	RelativePath emptyRelativePath;
	QueryDataDescription::SPtr queryDataDescriptionSPtr;
	NodeTypeDescription::SPtr nodeTypeDescriptionSPtr;
	QueryFirstRequest::SPtr queryFirstRequestSPtr;
	MessageHeader::SPtr messageHeaderSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
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
	typeId.nodeId(OpcUaId_QueryFirstRequest_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// build
	queryFirstRequestSPtr = QueryFirstRequest::construct();

	// build RequestHeader
	opcUaGuidSPtr = OpcUaGuid::construct();
	*opcUaGuidSPtr = "0D4455B2-8D2F-B74F-864F-0AF5945DD833";
	
	queryFirstRequestSPtr->requestHeader()->sessionAuthenticationToken().namespaceIndex(1);
	queryFirstRequestSPtr->requestHeader()->sessionAuthenticationToken().nodeId(opcUaGuidSPtr);
	queryFirstRequestSPtr->requestHeader()->time(ptime);
	queryFirstRequestSPtr->requestHeader()->requestHandle(0);
	queryFirstRequestSPtr->requestHeader()->returnDisagnostics(0);
	queryFirstRequestSPtr->requestHeader()->timeoutHint(300000);

	// build QueryDataDescription
	queryDataDescriptionSPtr = QueryDataDescription::construct();
	queryDataDescriptionSPtr->relativePath(emptyRelativePath);
	queryDataDescriptionSPtr->attributeId(123);
	queryDataDescriptionSPtr->indexRange("1:3");
	
	// build NodeTypeDefinition
	nodeTypeDescriptionSPtr = NodeTypeDescription::construct();
	nodeTypeDescriptionSPtr->typeDefinitionNode()->namespaceIndex(2);
	nodeTypeDescriptionSPtr->typeDefinitionNode()->nodeId<OpcUaUInt32>(123);
	nodeTypeDescriptionSPtr->includeSubtypes(true);
	nodeTypeDescriptionSPtr->dataToReturn()->set(queryDataDescriptionSPtr);

	// build ViewDescription
	queryFirstRequestSPtr->view().viewId()->namespaceIndex(2);
	queryFirstRequestSPtr->view().viewId()->nodeId<OpcUaUInt32>(123);
	queryFirstRequestSPtr->view().timestamp(ptime);
	queryFirstRequestSPtr->view().viewVersion(2);

	// build Parameter
	queryFirstRequestSPtr->nodeTypes()->set(nodeTypeDescriptionSPtr);
	queryFirstRequestSPtr->filter(emptyContentFilter);
	queryFirstRequestSPtr->maxDataSetsToReturn(2);
	queryFirstRequestSPtr->maxReferencesToReturn(2);

	// encode 
	queryFirstRequestSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = MessageHeader::construct();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);
	
	std::stringstream ss;
	ss << "4d 53 47 46 82 00 00 00  d9 7a 25 09 01 00 00 00" 
	   << "36 00 00 00 04 00 00 00  01 00 67 02 04 01 00 0d"
	   << "44 55 b2 8d 2f b7 4f 86  4f 0a f5 94 5d d8 33 00"
	   << "00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 ff"
       << "ff ff ff e0 93 04 00 00  00 00 01 02 7b 00 00 00"
       << "00 00 00 00 00 00 02 00  00 00 01 00 00 00 01 02"
       << "7b 00 01 01 00 00 00 00  00 00 00 7b 00 00 00 03"
       << "00 00 00 31 3a 33 00 00  00 00 02 00 00 00 02 00"
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
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_QueryFirstRequest_Encoding_DefaultBinary);

	// decode ReadRequest
	queryFirstRequestSPtr = QueryFirstRequest::construct();
	queryFirstRequestSPtr->opcUaBinaryDecode(ios);

	str = *queryFirstRequestSPtr->requestHeader()->sessionAuthenticationToken().nodeId<OpcUaGuid::SPtr>();
	BOOST_REQUIRE(queryFirstRequestSPtr->requestHeader()->sessionAuthenticationToken().namespaceIndex() == 1);
	BOOST_REQUIRE(str == "0D4455B2-8D2F-B74F-864F-0AF5945DD833");
	BOOST_REQUIRE(queryFirstRequestSPtr->requestHeader()->time().dateTime() == ptime);
	BOOST_REQUIRE(queryFirstRequestSPtr->requestHeader()->requestHandle() == 0);
	BOOST_REQUIRE(queryFirstRequestSPtr->requestHeader()->returnDisagnostics() == 0);
	BOOST_REQUIRE(queryFirstRequestSPtr->requestHeader()->timeoutHint() == 300000);
	
	BOOST_REQUIRE(queryFirstRequestSPtr->view().viewId()->namespaceIndex() == 2);
	BOOST_REQUIRE(queryFirstRequestSPtr->view().viewId()->nodeId<OpcUaUInt32>() == 123);
	BOOST_REQUIRE(queryFirstRequestSPtr->view().timestamp().dateTime() == ptime);
	BOOST_REQUIRE(queryFirstRequestSPtr->view().viewVersion() == 2);
	
	BOOST_REQUIRE(queryFirstRequestSPtr->nodeTypes()->size() == 1);
	nodeTypeDescriptionSPtr = NodeTypeDescription::construct();
	queryFirstRequestSPtr->nodeTypes()->get(nodeTypeDescriptionSPtr);
	BOOST_REQUIRE(nodeTypeDescriptionSPtr->typeDefinitionNode()->namespaceIndex() == 2);
	BOOST_REQUIRE(nodeTypeDescriptionSPtr->typeDefinitionNode()->nodeId<OpcUaUInt32>() == 123);
	BOOST_REQUIRE(nodeTypeDescriptionSPtr->includeSubtypes() == true);

	BOOST_REQUIRE(nodeTypeDescriptionSPtr->dataToReturn()->size() == 1);
	queryDataDescriptionSPtr = QueryDataDescription::construct();
	nodeTypeDescriptionSPtr->dataToReturn()->get(queryDataDescriptionSPtr);
	BOOST_REQUIRE(queryDataDescriptionSPtr->relativePath().elements()->size() == 0);
	BOOST_REQUIRE(queryDataDescriptionSPtr->attributeId() == 123);
	BOOST_REQUIRE(queryDataDescriptionSPtr->indexRange().value() == "1:3");

	BOOST_REQUIRE(queryFirstRequestSPtr->filter().elements()->size() == 0);
	BOOST_REQUIRE(queryFirstRequestSPtr->maxDataSetsToReturn() == 2);
	BOOST_REQUIRE(queryFirstRequestSPtr->maxReferencesToReturn() == 2);
}


BOOST_AUTO_TEST_CASE(QueryFirst_Response)
{
	uint32_t pos;
	std::string str;
	OpcUaNodeId typeId;
	OpcUaQualifiedName browseName;
	OpcUaLocalizedText displayName;
	OpcUaStatusCode statusCode;
	ContentFilterResult emptyContentFilterResult;
	QueryDataSet::SPtr queryDataSetSPtr;
	ParsingResult::SPtr parsingResultSPtr;
	QueryFirstResponse::SPtr queryFirstResponseSPtr;
	MessageHeader::SPtr messageHeaderSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
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
	typeId.nodeId(OpcUaId_QueryFirstResponse_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// build 
	queryFirstResponseSPtr = QueryFirstResponse::construct();

	// build ResponseHeader
	statusCode = Success;
	queryFirstResponseSPtr->responseHeader()->time(ptime);
	queryFirstResponseSPtr->responseHeader()->requestHandle(0);
	queryFirstResponseSPtr->responseHeader()->serviceResult(statusCode);
	
	// build QueryDataSet
	queryDataSetSPtr = QueryDataSet::construct();
	queryDataSetSPtr->nodeId()->namespaceIndex(2);
	queryDataSetSPtr->nodeId()->nodeId<OpcUaUInt32>(123);
	queryDataSetSPtr->typeDefinitionNode()->namespaceIndex(2);
	queryDataSetSPtr->typeDefinitionNode()->nodeId<OpcUaUInt32>(123);

	// build ParsingResult
	parsingResultSPtr = ParsingResult::construct();
	parsingResultSPtr->statusCode(Success);
	
	// build Parameter
	queryFirstResponseSPtr->queryDataSets()->set(queryDataSetSPtr);
	queryFirstResponseSPtr->continuationPoint().value("", 0);
	queryFirstResponseSPtr->parsingResults()->set(parsingResultSPtr);;
	queryFirstResponseSPtr->filterResult(emptyContentFilterResult);

	// encode 
	queryFirstResponseSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = MessageHeader::construct();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);

	std::stringstream ss;
	ss << "4d 53 47 46 60 00 00 00  d9 7a 25 09 01 00 00 00"
	   << "36 00 00 00 04 00 00 00  01 00 6a 02 00 00 00 00"
	   << "00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00"
	   << "00 00 00 00 01 00 00 00  01 02 7b 00 01 02 7b 00"
	   << "00 00 00 00 00 00 00 00  01 00 00 00 00 00 00 00"
	   << "00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00";

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
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_QueryFirstResponse_Encoding_DefaultBinary);

	// decode 
	queryFirstResponseSPtr = QueryFirstResponse::construct();
	queryFirstResponseSPtr->opcUaBinaryDecode(ios);

	BOOST_REQUIRE(queryFirstResponseSPtr->responseHeader()->time().dateTime() == ptime);
	BOOST_REQUIRE(queryFirstResponseSPtr->responseHeader()->requestHandle() == 0);
	BOOST_REQUIRE(queryFirstResponseSPtr->responseHeader()->serviceResult() == Success);

	BOOST_REQUIRE(queryFirstResponseSPtr->queryDataSets()->size() == 1);
	queryDataSetSPtr = QueryDataSet::construct();
	queryFirstResponseSPtr->queryDataSets()->get(queryDataSetSPtr);
	BOOST_REQUIRE(queryDataSetSPtr->nodeId()->namespaceIndex() == 2);
	BOOST_REQUIRE(queryDataSetSPtr->nodeId()->nodeId<OpcUaUInt32>() == 123);
	BOOST_REQUIRE(queryDataSetSPtr->typeDefinitionNode()->namespaceIndex() == 2);
	BOOST_REQUIRE(queryDataSetSPtr->typeDefinitionNode()->nodeId<OpcUaUInt32>() == 123);
	BOOST_REQUIRE(queryDataSetSPtr->values()->size() == 0);

	BOOST_REQUIRE(queryFirstResponseSPtr->continuationPoint().size() == 0);

	BOOST_REQUIRE(queryFirstResponseSPtr->parsingResults()->size() == 1);
	parsingResultSPtr = ParsingResult::construct();
	queryFirstResponseSPtr->parsingResults()->get(parsingResultSPtr);
	BOOST_REQUIRE(parsingResultSPtr->statusCode() == Success);
	BOOST_REQUIRE(parsingResultSPtr->dataStatusCodes()->size() == 0);
	BOOST_REQUIRE(parsingResultSPtr->dataDiagnosticInfos()->size() == 0);

	BOOST_REQUIRE(queryFirstResponseSPtr->filterResult().elementResults()->size() == 0);
}

BOOST_AUTO_TEST_SUITE_END()
