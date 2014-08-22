#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/ServiceSet/SetTriggeringRequest.h"
#include "OpcUaStackCore/ServiceSet/SetTriggeringResponse.h"
#include "OpcUaStackCore/SecureChannel/MessageHeader.h"
#include "OpcUaStackCore/SecureChannel/SequenceHeader.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(SetTriggering_)

BOOST_AUTO_TEST_CASE(SetTriggering_Title)
{
	std::cout << "SetTriggering_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(SetTriggering_Request)
{
	uint32_t pos;
	OpcUaNodeId typeId;
	OpcUaUInt32 link1, link2;
	OpcUaGuid::SPtr opcUaGuidSPtr;
	MessageHeader::SPtr messageHeaderSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
	SetTriggeringRequest::SPtr setTriggeringRequestSPtr;
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
	typeId.nodeId(OpcUaId_SetTriggeringRequest_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// build SetTriggeringRequest
	setTriggeringRequestSPtr = SetTriggeringRequest::construct();

	// build RequestHeader
	opcUaGuidSPtr = OpcUaGuid::construct();
	*opcUaGuidSPtr = "0D4455B2-8D2F-B74F-864F-0AF5945DD833";
	
	setTriggeringRequestSPtr->requestHeader()->sessionAuthenticationToken().namespaceIndex(1);
	setTriggeringRequestSPtr->requestHeader()->sessionAuthenticationToken().nodeId(opcUaGuidSPtr);
	setTriggeringRequestSPtr->requestHeader()->time(ptime);
	setTriggeringRequestSPtr->requestHeader()->requestHandle(0);
	setTriggeringRequestSPtr->requestHeader()->returnDisagnostics(0);
	setTriggeringRequestSPtr->requestHeader()->timeoutHint(300000);

	// build SetTriggeringRequest
	setTriggeringRequestSPtr->subscriptionId(4);
	setTriggeringRequestSPtr->triggeringItemId(8);
	setTriggeringRequestSPtr->linksToAdd()->set(2);
	setTriggeringRequestSPtr->linksToRemove()->set(3);

	// encode 
	setTriggeringRequestSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = MessageHeader::construct();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);
	
	std::stringstream ss;
	ss << "4d 53 47 46 62 00 00 00  d9 7a 25 09 01 00 00 00"
	   << "36 00 00 00 04 00 00 00  01 00 07 03 04 01 00 0d"
	   << "44 55 b2 8d 2f b7 4f 86  4f 0a f5 94 5d d8 33 00"
	   << "00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 ff"	
	   << "ff ff ff e0 93 04 00 00  00 00 04 00 00 00 08 00"
	   << "00 00 01 00 00 00 02 00  00 00 01 00 00 00 03 00"
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
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_SetTriggeringRequest_Encoding_DefaultBinary);

	// decode
	setTriggeringRequestSPtr = SetTriggeringRequest::construct();
	setTriggeringRequestSPtr->opcUaBinaryDecode(ios);
	
	std::string str;
	str = *setTriggeringRequestSPtr->requestHeader()->sessionAuthenticationToken().nodeId<OpcUaGuid::SPtr>();
	BOOST_REQUIRE(setTriggeringRequestSPtr->requestHeader()->sessionAuthenticationToken().namespaceIndex() == 1);
	BOOST_REQUIRE(str == "0D4455B2-8D2F-B74F-864F-0AF5945DD833");
	BOOST_REQUIRE(setTriggeringRequestSPtr->requestHeader()->time().dateTime() == ptime);
	BOOST_REQUIRE(setTriggeringRequestSPtr->requestHeader()->requestHandle() == 0);
	BOOST_REQUIRE(setTriggeringRequestSPtr->requestHeader()->returnDisagnostics() == 0);
	BOOST_REQUIRE(setTriggeringRequestSPtr->requestHeader()->timeoutHint() == 300000);
	
	BOOST_REQUIRE(setTriggeringRequestSPtr->subscriptionId() == 4);
	BOOST_REQUIRE(setTriggeringRequestSPtr->triggeringItemId() == 8);

	BOOST_REQUIRE(setTriggeringRequestSPtr->linksToAdd()->size() == 1);
	setTriggeringRequestSPtr->linksToAdd()->get(link1);
	BOOST_REQUIRE(link1 == 2);

	BOOST_REQUIRE(setTriggeringRequestSPtr->linksToRemove()->size() == 1);
	setTriggeringRequestSPtr->linksToRemove()->get(link2);
	BOOST_REQUIRE(link2 == 3);
}


BOOST_AUTO_TEST_CASE(SetTriggering_Response)
{
	uint32_t pos;
	OpcUaNodeId typeId;
	OpcUaStatusCode statusCode;
	MessageHeader::SPtr messageHeaderSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
	SetTriggeringResponse::SPtr setTriggeringResponseSPtr;
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
	typeId.nodeId(OpcUaId_SetTriggeringResponse_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// build SetTriggeringResponse
	setTriggeringResponseSPtr = SetTriggeringResponse::construct();

	// build ResponseHeader
	statusCode = Success;
	setTriggeringResponseSPtr->responseHeader()->time(ptime);
	setTriggeringResponseSPtr->responseHeader()->requestHandle(0);
	setTriggeringResponseSPtr->responseHeader()->serviceResult(statusCode);
	
	// build Parameters
	setTriggeringResponseSPtr->addResults()->set((OpcUaStatusCode)Success);
	setTriggeringResponseSPtr->removeResults()->set((OpcUaStatusCode)Success);

	// encode DeleteMonitoredItemsResponse
	setTriggeringResponseSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = MessageHeader::construct();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);

	std::stringstream ss;
	ss << "4d 53 47 46 4c 00 00 00  d9 7a 25 09 01 00 00 00"
	   << "36 00 00 00 04 00 00 00  01 00 0a 03 00 00 00 00"
	   << "00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00"
	   << "00 00 00 00 01 00 00 00  00 00 00 00 00 00 00 00"
	   << "01 00 00 00 00 00 00 00  00 00 00 00";

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
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_SetTriggeringResponse_Encoding_DefaultBinary);

	// decode 
	setTriggeringResponseSPtr = SetTriggeringResponse::construct();
	setTriggeringResponseSPtr->opcUaBinaryDecode(ios);

	BOOST_REQUIRE(setTriggeringResponseSPtr->responseHeader()->time().dateTime() == ptime);
	BOOST_REQUIRE(setTriggeringResponseSPtr->responseHeader()->requestHandle() == 0);
	BOOST_REQUIRE(setTriggeringResponseSPtr->responseHeader()->serviceResult() == Success);

	BOOST_REQUIRE(setTriggeringResponseSPtr->addResults()->size() == 1);
	setTriggeringResponseSPtr->addResults()->get(statusCode);
	BOOST_REQUIRE(statusCode == Success);

	BOOST_REQUIRE(setTriggeringResponseSPtr->removeResults()->size() == 1);
	setTriggeringResponseSPtr->removeResults()->get(statusCode);
	BOOST_REQUIRE(statusCode == Success);
}

BOOST_AUTO_TEST_SUITE_END()
