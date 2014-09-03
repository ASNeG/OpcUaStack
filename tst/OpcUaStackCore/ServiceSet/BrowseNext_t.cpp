#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/ServiceSet/BrowseNextRequest.h"
#include "OpcUaStackCore/ServiceSet/BrowseNextResponse.h"
#include "OpcUaStackCore/SecureChannel/MessageHeader.h"
#include "OpcUaStackCore/SecureChannel/SequenceHeader.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(BrowseNext_)

BOOST_AUTO_TEST_CASE(BrowseNext_Title)
{
	std::cout << "BrowseNext_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(BrowseNext_Request)
{
	std::string str;
	uint32_t pos;
	OpcUaNodeId typeId;
	OpcUaGuid::SPtr opcUaGuidSPtr;
	OpcUaByteString::SPtr continuationPointSPtr;
	BrowseNextRequest::SPtr browseNextRequestSPtr;
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
	typeId.nodeId(OpcUaId_BrowseNextRequest_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// build
	browseNextRequestSPtr = BrowseNextRequest::construct();

	// build RequestHeader
	opcUaGuidSPtr = OpcUaGuid::construct();
	*opcUaGuidSPtr = "0D4455B2-8D2F-B74F-864F-0AF5945DD833";
	
	browseNextRequestSPtr->requestHeader()->sessionAuthenticationToken().namespaceIndex(1);
	browseNextRequestSPtr->requestHeader()->sessionAuthenticationToken().nodeId(opcUaGuidSPtr);
	browseNextRequestSPtr->requestHeader()->time(ptime);
	browseNextRequestSPtr->requestHeader()->requestHandle(0);
	browseNextRequestSPtr->requestHeader()->returnDisagnostics(0);
	browseNextRequestSPtr->requestHeader()->timeoutHint(300000);

	// build Parameters
	continuationPointSPtr = OpcUaByteString::construct();
	continuationPointSPtr->value("", 0);
	browseNextRequestSPtr->releaseContinuationPoints(true);
	browseNextRequestSPtr->continuationPoints()->set(continuationPointSPtr);

	// encode 
	browseNextRequestSPtr->opcUaBinaryEncode(ios1);

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
	   << "36 00 00 00 04 00 00 00  01 00 15 02 04 01 00 0d"
	   << "44 55 b2 8d 2f b7 4f 86  4f 0a f5 94 5d d8 33 00"
	   << "00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 ff"
       << "ff ff ff e0 93 04 00 00  00 00 01 01 00 00 00 00"
       << "00 00 00";

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
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_BrowseNextRequest_Encoding_DefaultBinary);

	// decode ReadRequest
	browseNextRequestSPtr = BrowseNextRequest::construct();
	browseNextRequestSPtr->opcUaBinaryDecode(ios);

	str = *browseNextRequestSPtr->requestHeader()->sessionAuthenticationToken().nodeId<OpcUaGuid::SPtr>();
	BOOST_REQUIRE(browseNextRequestSPtr->requestHeader()->sessionAuthenticationToken().namespaceIndex() == 1);
	BOOST_REQUIRE(str == "0D4455B2-8D2F-B74F-864F-0AF5945DD833");
	BOOST_REQUIRE(browseNextRequestSPtr->requestHeader()->time().dateTime() == ptime);
	BOOST_REQUIRE(browseNextRequestSPtr->requestHeader()->requestHandle() == 0);
	BOOST_REQUIRE(browseNextRequestSPtr->requestHeader()->returnDisagnostics() == 0);
	BOOST_REQUIRE(browseNextRequestSPtr->requestHeader()->timeoutHint() == 300000);
	
	BOOST_REQUIRE(browseNextRequestSPtr->releaseContinuationPoints() == true);
	BOOST_REQUIRE(browseNextRequestSPtr->continuationPoints()->size() == 1);
	continuationPointSPtr = OpcUaByteString::construct();
	browseNextRequestSPtr->continuationPoints()->get(continuationPointSPtr);
	BOOST_REQUIRE(continuationPointSPtr->size() == 0);
}


BOOST_AUTO_TEST_CASE(BrowseNext_Response)
{
	uint32_t pos;
	std::string str;
	OpcUaNodeId typeId;
	OpcUaQualifiedName browseName;
	OpcUaLocalizedText displayName;
	OpcUaStatusCode statusCode;
	ReferenceDescription::SPtr referenceDescriptionSPtr;
	BrowseResult::SPtr browseResultSPtr;
	BrowseNextResponse::SPtr browseNextResponseSPtr;
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
	typeId.nodeId(OpcUaId_BrowseNextResponse_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// build 
	browseNextResponseSPtr = BrowseNextResponse::construct();

	// build ResponseHeader
	statusCode = Success;
	browseNextResponseSPtr->responseHeader()->time(ptime);
	browseNextResponseSPtr->responseHeader()->requestHandle(0);
	browseNextResponseSPtr->responseHeader()->serviceResult(statusCode);
	
	// build ReferenceDescription
	referenceDescriptionSPtr = ReferenceDescription::construct();
	referenceDescriptionSPtr->referenceTypeId()->namespaceIndex(2);
	referenceDescriptionSPtr->referenceTypeId()->nodeId<OpcUaUInt32>(123);
	referenceDescriptionSPtr->isForward(true);
	referenceDescriptionSPtr->nodeId()->namespaceIndex(2);
	referenceDescriptionSPtr->nodeId()->nodeId<OpcUaUInt32>(123);
	browseName = "ABC"; browseName = 2;
	referenceDescriptionSPtr->browseName(browseName);
	displayName.locale("local");
	referenceDescriptionSPtr->displayName(displayName);
	referenceDescriptionSPtr->nodeClass(NodeClass_Data_Type);
	referenceDescriptionSPtr->typeDefinition()->namespaceIndex(2);
	referenceDescriptionSPtr->typeDefinition()->nodeId<OpcUaUInt32>(123);
	
	// build BrowseResult
	browseResultSPtr = BrowseResult::construct();
	browseResultSPtr->statusCode(Success);
	browseResultSPtr->continuationPoint().value("", 0);;
	browseResultSPtr->references()->set(referenceDescriptionSPtr);

	browseNextResponseSPtr->results()->set(browseResultSPtr);

	// encode 
	browseNextResponseSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = MessageHeader::construct();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);

	std::stringstream ss;
	ss << "4d 53 47 46 6c 00 00 00  d9 7a 25 09 01 00 00 00"
	   << "36 00 00 00 04 00 00 00  01 00 18 02 00 00 00 00"
	   << "00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00"
	   << "00 00 00 00 01 00 00 00  00 00 00 00 00 00 00 00"
	   << "01 00 00 00 01 02 7b 00  01 01 02 7b 00 02 00 03"
	   << "00 00 00 41 42 43 01 05  00 00 00 6c 6f 63 61 6c"
	   << "40 00 00 00 01 02 7b 00  00 00 00 00 ";

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
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_BrowseNextResponse_Encoding_DefaultBinary);

	// decode 
	browseNextResponseSPtr = BrowseNextResponse::construct();
	browseNextResponseSPtr->opcUaBinaryDecode(ios);

	BOOST_REQUIRE(browseNextResponseSPtr->responseHeader()->time().dateTime() == ptime);
	BOOST_REQUIRE(browseNextResponseSPtr->responseHeader()->requestHandle() == 0);
	BOOST_REQUIRE(browseNextResponseSPtr->responseHeader()->serviceResult() == Success);

	BOOST_REQUIRE(browseNextResponseSPtr->results()->size() == 1);
	browseResultSPtr = BrowseResult::construct();
	browseNextResponseSPtr->results()->get(browseResultSPtr);
	BOOST_REQUIRE(browseResultSPtr->statusCode() == Success);
	BOOST_REQUIRE(browseResultSPtr->continuationPoint().size() == 0);
	
	BOOST_REQUIRE(browseResultSPtr->references()->size() == 1);
	referenceDescriptionSPtr = ReferenceDescription::construct();
	browseResultSPtr->references()->get(referenceDescriptionSPtr);
	BOOST_REQUIRE(referenceDescriptionSPtr->referenceTypeId()->namespaceIndex() == 2);
	BOOST_REQUIRE(referenceDescriptionSPtr->referenceTypeId()->nodeId<OpcUaUInt32>() == 123);
	BOOST_REQUIRE(referenceDescriptionSPtr->isForward() == true);
	BOOST_REQUIRE(referenceDescriptionSPtr->nodeId()->namespaceIndex() == 2);
	BOOST_REQUIRE(referenceDescriptionSPtr->nodeId()->nodeId<OpcUaUInt32>() == 123);
	BOOST_REQUIRE(referenceDescriptionSPtr->browseName().name().value() == "ABC");
	BOOST_REQUIRE(referenceDescriptionSPtr->browseName().namespaceIndex() == 2);
	BOOST_REQUIRE(referenceDescriptionSPtr->displayName().locale().value() == "local");
	BOOST_REQUIRE(referenceDescriptionSPtr->nodeClass() == NodeClass_Data_Type);
	BOOST_REQUIRE(referenceDescriptionSPtr->typeDefinition()->namespaceIndex() == 2);
	BOOST_REQUIRE(referenceDescriptionSPtr->typeDefinition()->nodeId<OpcUaUInt32>() == 123);
}

BOOST_AUTO_TEST_SUITE_END()
