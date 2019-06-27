#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/ServiceSet/PublishRequest.h"
#include "OpcUaStackCore/ServiceSet/PublishResponse.h"
#include "OpcUaStackCore/SecureChannel/MessageHeader.h"
#include "OpcUaStackCore/SecureChannel/SequenceHeader.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(Publish_)

BOOST_AUTO_TEST_CASE(Publish_Title)
{
	std::cout << "Publish_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(Publish_Request)
{
	RequestHeader::SPtr requestHeader = constructSPtr<RequestHeader>();
	uint32_t pos;
	OpcUaNodeId typeId;
	OpcUaGuid::SPtr opcUaGuidSPtr;
	MessageHeader::SPtr messageHeaderSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
	PublishRequest::SPtr publishRequestSPtr;
	SubscriptionAcknowledgement::SPtr subscriptionAcknowledgementSPtr;
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
	sequenceHeaderSPtr = constructSPtr<SequenceHeader>();
	sequenceHeaderSPtr->sequenceNumber(54);
	sequenceHeaderSPtr->requestId(4);
	sequenceHeaderSPtr->opcUaBinaryEncode(ios1);

	// encode TypeId
	typeId.nodeId(OpcUaId_PublishRequest_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// build PublishRequest
	publishRequestSPtr = constructSPtr<PublishRequest>();

	// build RequestHeader
	opcUaGuidSPtr = constructSPtr<OpcUaGuid>();
	*opcUaGuidSPtr = "0D4455B2-8D2F-B74F-864F-0AF5945DD833";
	
	requestHeader->sessionAuthenticationToken().namespaceIndex(1);
	requestHeader->sessionAuthenticationToken().nodeId(opcUaGuidSPtr);
	requestHeader->time(ptime);
	requestHeader->requestHandle(0);
	requestHeader->returnDisagnostics(0);
	requestHeader->timeoutHint(300000);
	
	// build SubscriptionAcknowledgements
	subscriptionAcknowledgementSPtr = constructSPtr<SubscriptionAcknowledgement>();
	subscriptionAcknowledgementSPtr->subscriptionId(153451225);
	subscriptionAcknowledgementSPtr->sequenceNumber(2);
	publishRequestSPtr->subscriptionAcknowledgements()->set(subscriptionAcknowledgementSPtr);

	// encode PublishRequest
	requestHeader->opcUaBinaryEncode(ios1);
	publishRequestSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = constructSPtr<MessageHeader>();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);

	std::stringstream ss;
	ss << "4d 53 47 46 56 00 00 00  d9 7a 25 09 01 00 00 00"
	   << "36 00 00 00 04 00 00 00  01 00 3a 03 04 01 00 0d"
	   << "44 55 b2 8d 2f b7 4f 86  4f 0a f5 94 5d d8 33 00"
	   << "00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 ff"
	   << "ff ff ff e0 93 04 00 00  00 00 01 00 00 00 d9 7a"
	   << "25 09 02 00 00 00";

	BOOST_REQUIRE(OpcUaStackCore::compare(ios, ss.str(), pos) == true);

	// decode MessageHeader
	messageHeaderSPtr = constructSPtr<MessageHeader>();
	messageHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(messageHeaderSPtr->messageType() == MessageType_Message);

	// decode security header
	OpcUaNumber::opcUaBinaryDecode(ios, secureChannelId);
	BOOST_REQUIRE(secureChannelId == 153451225);
	OpcUaNumber::opcUaBinaryDecode(ios, secureTokenId);
	BOOST_REQUIRE(secureTokenId == 1);

	// decode sequence header
	sequenceHeaderSPtr = constructSPtr<SequenceHeader>();
	sequenceHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(sequenceHeaderSPtr->sequenceNumber() == 54);
	BOOST_REQUIRE(sequenceHeaderSPtr->requestId() == 4);

	// decode message type id
	typeId.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(typeId.namespaceIndex() == 0);
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_PublishRequest_Encoding_DefaultBinary);

	// decode ReadRequest
	publishRequestSPtr = constructSPtr<PublishRequest>();
	requestHeader->opcUaBinaryDecode(ios);
	publishRequestSPtr->opcUaBinaryDecode(ios);

	std::string str;
	str = *requestHeader->sessionAuthenticationToken().nodeId<OpcUaGuid::SPtr>();
	BOOST_REQUIRE(requestHeader->sessionAuthenticationToken().namespaceIndex() == 1);
	BOOST_REQUIRE(str == "0D4455B2-8D2F-B74F-864F-0AF5945DD833");
	BOOST_REQUIRE(requestHeader->time().dateTime() == ptime);
	BOOST_REQUIRE(requestHeader->requestHandle() == 0);
	BOOST_REQUIRE(requestHeader->returnDisagnostics() == 0);
	BOOST_REQUIRE(requestHeader->timeoutHint() == 300000);
	
	BOOST_REQUIRE(publishRequestSPtr->subscriptionAcknowledgements()->size() == 1);
	
	subscriptionAcknowledgementSPtr = constructSPtr<SubscriptionAcknowledgement>();
	publishRequestSPtr->subscriptionAcknowledgements()->get(subscriptionAcknowledgementSPtr);
	BOOST_REQUIRE(subscriptionAcknowledgementSPtr->subscriptionId() == 153451225);
	BOOST_REQUIRE(subscriptionAcknowledgementSPtr->sequenceNumber() == 2);
}


BOOST_AUTO_TEST_CASE(Publish_Response)
{
	ResponseHeader::SPtr responseHeader = constructSPtr<ResponseHeader>();
	uint32_t pos;
	OpcUaNodeId typeId;
	MessageHeader::SPtr messageHeaderSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
	PublishResponse::SPtr publishResponseSPtr;
	NotificationMessage::SPtr notificationMessageSPtr;

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
	sequenceHeaderSPtr = constructSPtr<SequenceHeader>();
	sequenceHeaderSPtr->sequenceNumber(54);
	sequenceHeaderSPtr->requestId(4);
	sequenceHeaderSPtr->opcUaBinaryEncode(ios1);

	// encode TypeId
	typeId.nodeId(OpcUaId_PublishResponse_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// build PublishResponse
	publishResponseSPtr = constructSPtr<PublishResponse>();
	responseHeader->time(ptime);
	responseHeader->requestHandle(133);
	responseHeader->serviceResult((OpcUaStatusCode)Success);
	publishResponseSPtr->subscriptionId(1);
	publishResponseSPtr->moreNotifications(false);

	// build NotificationMessage (empty NotificationData)
	notificationMessageSPtr = publishResponseSPtr->notificationMessage();
	notificationMessageSPtr->sequenceNumber() = 1;
	notificationMessageSPtr->publishTime() = ptime;

	// encode PublishResponse
	responseHeader->opcUaBinaryEncode(ios1);
	publishResponseSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = constructSPtr<MessageHeader>();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);

	std::stringstream ss;
	ss << "4d 53 47 46 55 00 00 00  d9 7a 25 09 01 00 00 00"
	   << "36 00 00 00 04 00 00 00  01 00 3d 03 00 00 00 00"
	   << "00 00 00 00 85 00 00 00  00 00 00 00 00 00 00 00"
	   << "00 00 00 00 01 00 00 00  00 00 00 00 00 01 00 00"
	   << "00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00"
	   << "00 00 00 00 00";

	BOOST_REQUIRE(OpcUaStackCore::compare(ios, ss.str(), pos) == true);

	// decode MessageHeader
	messageHeaderSPtr = constructSPtr<MessageHeader>();
	messageHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(messageHeaderSPtr->messageType() == MessageType_Message);

	// decode security header
	OpcUaNumber::opcUaBinaryDecode(ios, secureChannelId);
	BOOST_REQUIRE(secureChannelId == 153451225);
	OpcUaNumber::opcUaBinaryDecode(ios, secureTokenId);
	BOOST_REQUIRE(secureTokenId == 1);

	// decode sequence header
	sequenceHeaderSPtr = constructSPtr<SequenceHeader>();
	sequenceHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(sequenceHeaderSPtr->sequenceNumber() == 54);
	BOOST_REQUIRE(sequenceHeaderSPtr->requestId() == 4);

	// decode message type id
	typeId.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(typeId.namespaceIndex() == 0);
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_PublishResponse_Encoding_DefaultBinary);

	// decode PublishResponse
	publishResponseSPtr = constructSPtr<PublishResponse>();
	responseHeader->opcUaBinaryDecode(ios);
	publishResponseSPtr->opcUaBinaryDecode(ios);

	BOOST_REQUIRE(responseHeader->time().dateTime() == ptime);
	BOOST_REQUIRE(responseHeader->requestHandle() == 133);
	BOOST_REQUIRE(responseHeader->serviceResult() == Success);
	BOOST_REQUIRE(publishResponseSPtr->subscriptionId() == 1);
	BOOST_REQUIRE(publishResponseSPtr->moreNotifications() == false);

	notificationMessageSPtr = publishResponseSPtr->notificationMessage();
	BOOST_REQUIRE(notificationMessageSPtr->sequenceNumber() == 1);
	BOOST_REQUIRE(notificationMessageSPtr->publishTime().dateTime() == ptime);
}

BOOST_AUTO_TEST_SUITE_END()
