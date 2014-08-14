#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/ServiceSet/DeleteSubscriptionRequest.h"
#include "OpcUaStackCore/ServiceSet/DeleteSubscriptionResponse.h"
#include "OpcUaStackCore/SecureChannel/MessageHeader.h"
#include "OpcUaStackCore/SecureChannel/SequenceHeader.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(DeleteSubscription_)

BOOST_AUTO_TEST_CASE(DeleteSubscription_)
{
	std::cout << "DeleteSubscription_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(DeleteSubscription_Request)
{
	uint32_t pos;
	OpcUaNodeId typeId;
	OpcUaGuid::SPtr opcUaGuidSPtr;
	MessageHeader::SPtr messageHeaderSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
	OpcUaUInt32 subscriptionId, subscriptionId2;
	DeleteSubscriptionRequest::SPtr deleteSubscriptionRequestSPtr;
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
	typeId.nodeId(OpcUaId_DeleteSubscriptionsRequest_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// build CreateSubscriptionRequest
	deleteSubscriptionRequestSPtr = DeleteSubscriptionRequest::construct();

	// build RequestHeader
	opcUaGuidSPtr = OpcUaGuid::construct();
	*opcUaGuidSPtr = "0D4455B2-8D2F-B74F-864F-0AF5945DD833";
	
	deleteSubscriptionRequestSPtr->requestHeader()->sessionAuthenticationToken().namespaceIndex(1);
	deleteSubscriptionRequestSPtr->requestHeader()->sessionAuthenticationToken().nodeId(opcUaGuidSPtr);
	deleteSubscriptionRequestSPtr->requestHeader()->time(ptime);
	deleteSubscriptionRequestSPtr->requestHeader()->requestHandle(0);
	deleteSubscriptionRequestSPtr->requestHeader()->returnDisagnostics(0);
	deleteSubscriptionRequestSPtr->requestHeader()->timeoutHint(300000);
	
	// build SubscriptionIds
	subscriptionId = 153451225;
	deleteSubscriptionRequestSPtr->subscriptionIds()->set(subscriptionId);

	// encode CreateSubscriptionRequest
	deleteSubscriptionRequestSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = MessageHeader::construct();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);
	
	std::stringstream ss;
	ss << "4d 53 47 46 52 00 00 00  d9 7a 25 09 01 00 00 00"
	   << "36 00 00 00 04 00 00 00  01 00 4f 03 04 01 00 0d"
	   << "44 55 b2 8d 2f b7 4f 86  4f 0a f5 94 5d d8 33 00"
	   << "00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 ff"	
	   << "ff ff ff e0 93 04 00 00  00 00 01 00 00 00 d9 7a"
	   << "25 09";

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
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_DeleteSubscriptionsRequest_Encoding_DefaultBinary);

	// decode ReadRequest
	deleteSubscriptionRequestSPtr = DeleteSubscriptionRequest::construct();
	deleteSubscriptionRequestSPtr->opcUaBinaryDecode(ios);

	std::string str;
	str = *deleteSubscriptionRequestSPtr->requestHeader()->sessionAuthenticationToken().nodeId<OpcUaGuid::SPtr>();
	BOOST_REQUIRE(deleteSubscriptionRequestSPtr->requestHeader()->sessionAuthenticationToken().namespaceIndex() == 1);
	BOOST_REQUIRE(str == "0D4455B2-8D2F-B74F-864F-0AF5945DD833");
	BOOST_REQUIRE(deleteSubscriptionRequestSPtr->requestHeader()->time().dateTime() == ptime);
	BOOST_REQUIRE(deleteSubscriptionRequestSPtr->requestHeader()->requestHandle() == 0);
	BOOST_REQUIRE(deleteSubscriptionRequestSPtr->requestHeader()->returnDisagnostics() == 0);
	BOOST_REQUIRE(deleteSubscriptionRequestSPtr->requestHeader()->timeoutHint() == 300000);
	
	BOOST_REQUIRE(deleteSubscriptionRequestSPtr->subscriptionIds()->size() == 1);
	
	deleteSubscriptionRequestSPtr->subscriptionIds()->get(subscriptionId2);
	BOOST_REQUIRE(subscriptionId2 == 153451225);
}


BOOST_AUTO_TEST_CASE(DeleteSubscription_Response)
{
	uint32_t pos;
	OpcUaNodeId typeId;
	OpcUaStatusCode statusCode;
	MessageHeader::SPtr messageHeaderSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
	DeleteSubscriptionResponse::SPtr deleteSubscriptionResponseSPtr;
	OpcUaStatusCode statusCode1, statusCode2;
	OpcUaDateTime sourceTimestamp, serverTimestamp;
	OpcUaDataValue::SPtr dataValueSPtr;
	OpcUaVariant::SPtr variantSPtr;
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
	typeId.nodeId(OpcUaId_DeleteSubscriptionsResponse_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// build ReadResponse
	deleteSubscriptionResponseSPtr = DeleteSubscriptionResponse::construct();

	// build ResponseHeader
	statusCode = Success;
	deleteSubscriptionResponseSPtr->responseHeader()->time(ptime);
	deleteSubscriptionResponseSPtr->responseHeader()->requestHandle(0);
	deleteSubscriptionResponseSPtr->responseHeader()->serviceResult(statusCode);
	
	// build Results
	statusCode1 = Success;
	deleteSubscriptionResponseSPtr->results()->set(statusCode1);

	// encode ReadRequest
	deleteSubscriptionResponseSPtr->opcUaBinaryEncode(ios1);

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
	   << "36 00 00 00 04 00 00 00  01 00 52 03 00 00 00 00"
	   << "00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00"
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
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_DeleteSubscriptionsResponse_Encoding_DefaultBinary);

	// decode ReadResponse
	deleteSubscriptionResponseSPtr = DeleteSubscriptionResponse::construct();
	deleteSubscriptionResponseSPtr->opcUaBinaryDecode(ios);

	BOOST_REQUIRE(deleteSubscriptionResponseSPtr->responseHeader()->time().dateTime() == ptime);
	BOOST_REQUIRE(deleteSubscriptionResponseSPtr->responseHeader()->requestHandle() == 0);
	BOOST_REQUIRE(deleteSubscriptionResponseSPtr->responseHeader()->serviceResult() == Success);

	BOOST_REQUIRE(deleteSubscriptionResponseSPtr->results()->size() == 1);
	
	deleteSubscriptionResponseSPtr->results()->get(statusCode2);
	BOOST_REQUIRE(statusCode == Success);
}

BOOST_AUTO_TEST_SUITE_END()
