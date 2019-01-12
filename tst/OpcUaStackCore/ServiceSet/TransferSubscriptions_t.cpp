#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/ServiceSet/TransferSubscriptionsRequest.h"
#include "OpcUaStackCore/ServiceSet/TransferSubscriptionsResponse.h"
#include "OpcUaStackCore/SecureChannel/MessageHeader.h"
#include "OpcUaStackCore/SecureChannel/SequenceHeader.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(TransferSubscriptions_)

BOOST_AUTO_TEST_CASE(TransferSubscriptions_TransferResult)
{
	std::cout << "TransferResult_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(TransferSubscriptions_TransferResult_encode_decode)
{
	OpcUaUInt32 sequenceNumber;
	TransferResult transferResult1, transferResult2;

	// stream
	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	// encode
	transferResult1.statusCode((OpcUaStatusCode)Success);
	transferResult1.availableSequenceNumbers()->set((OpcUaUInt32)123);
	transferResult1.opcUaBinaryEncode(ios);

	// decode
	transferResult2.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(transferResult1.statusCode() == Success);
	BOOST_REQUIRE(transferResult1.availableSequenceNumbers()->size() == 1);
	transferResult1.availableSequenceNumbers()->get(sequenceNumber);
	BOOST_REQUIRE(sequenceNumber == 123);
}

BOOST_AUTO_TEST_CASE(TransferSubscriptions_Title)
{
	std::cout << "TransferSubscriptions_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(SetPublishingMode_Request)
{
	RequestHeader::SPtr requestHeader = constructSPtr<RequestHeader>();
	uint32_t pos;
	OpcUaNodeId typeId;
	OpcUaUInt32 subscriptionId;
	OpcUaGuid::SPtr opcUaGuidSPtr;
	MessageHeader::SPtr messageHeaderSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
	TransferSubscriptionsRequest::SPtr transferSubscriptionsRequestSPtr;
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
	typeId.nodeId(OpcUaId_TransferSubscriptionsRequest_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// build TransferSubscriptionsRequest
	transferSubscriptionsRequestSPtr = constructSPtr<TransferSubscriptionsRequest>();

	// build RequestHeader
	opcUaGuidSPtr = constructSPtr<OpcUaGuid>();
	*opcUaGuidSPtr = "0D4455B2-8D2F-B74F-864F-0AF5945DD833";
	
	requestHeader->sessionAuthenticationToken().namespaceIndex(1);
	requestHeader->sessionAuthenticationToken().nodeId(opcUaGuidSPtr);
	requestHeader->time(ptime);
	requestHeader->requestHandle(0);
	requestHeader->returnDisagnostics(0);
	requestHeader->timeoutHint(300000);
	
	// build Parameter
	transferSubscriptionsRequestSPtr->subscriptionIds()->set((OpcUaUInt32)153451225);
	transferSubscriptionsRequestSPtr->sendInitialValues(false);

	// encode TransferSubscriptionsRequest
	requestHeader->opcUaBinaryEncode(ios1);
	transferSubscriptionsRequestSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = constructSPtr<MessageHeader>();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);

	std::stringstream ss;
	ss << "4d 53 47 46 53 00 00 00  d9 7a 25 09 01 00 00 00"
	   << "36 00 00 00 04 00 00 00  01 00 49 03 04 01 00 0d"
	   << "44 55 b2 8d 2f b7 4f 86  4f 0a f5 94 5d d8 33 00"
	   << "00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 ff"
	   << "ff ff ff e0 93 04 00 00  00 00 01 00 00 00 d9 7a"
	   << "25 09 00";

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
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_TransferSubscriptionsRequest_Encoding_DefaultBinary);

	// decode TransferSubscriptionsRequest
	transferSubscriptionsRequestSPtr = constructSPtr<TransferSubscriptionsRequest>();
	requestHeader->opcUaBinaryDecode(ios);
	transferSubscriptionsRequestSPtr->opcUaBinaryDecode(ios);

	std::string str;
	str = *requestHeader->sessionAuthenticationToken().nodeId<OpcUaGuid::SPtr>();
	BOOST_REQUIRE(requestHeader->sessionAuthenticationToken().namespaceIndex() == 1);
	BOOST_REQUIRE(str == "0D4455B2-8D2F-B74F-864F-0AF5945DD833");
	BOOST_REQUIRE(requestHeader->time().dateTime() == ptime);
	BOOST_REQUIRE(requestHeader->requestHandle() == 0);
	BOOST_REQUIRE(requestHeader->returnDisagnostics() == 0);
	BOOST_REQUIRE(requestHeader->timeoutHint() == 300000);
	
	BOOST_REQUIRE(transferSubscriptionsRequestSPtr->sendInitialValues() == false);
	
	BOOST_REQUIRE(transferSubscriptionsRequestSPtr->subscriptionIds()->size() == 1);
	transferSubscriptionsRequestSPtr->subscriptionIds()->get(subscriptionId);
	BOOST_REQUIRE(subscriptionId == 153451225);
}


BOOST_AUTO_TEST_CASE(TransferSubscriptions_Response)
{
	ResponseHeader::SPtr responseHeader = constructSPtr<ResponseHeader>();
	uint32_t pos;
	OpcUaNodeId typeId;
	OpcUaUInt32 sequenceNumber;
	MessageHeader::SPtr messageHeaderSPtr;
	TransferResult::SPtr transferResultSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
	TransferSubscriptionsResponse::SPtr transferSubscriptionsResponseSPtr;

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
	typeId.nodeId(OpcUaId_TransferSubscriptionsResponse_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// build TransferSubscriptionsResponse
	transferSubscriptionsResponseSPtr = constructSPtr<TransferSubscriptionsResponse>();
	responseHeader->time(ptime);
	responseHeader->requestHandle(133);
	responseHeader->serviceResult((OpcUaStatusCode)Success);

	// build TransferResult
	transferResultSPtr = constructSPtr<TransferResult>();
	transferResultSPtr->statusCode((OpcUaStatusCode)Success);
	transferResultSPtr->availableSequenceNumbers()->set((OpcUaUInt32)123);
	transferSubscriptionsResponseSPtr->results()->set(transferResultSPtr);

	// encode SetPublishingModeResponse
	responseHeader->opcUaBinaryEncode(ios1);
	transferSubscriptionsResponseSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = constructSPtr<MessageHeader>();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);

	std::stringstream ss;
	ss << "4d 53 47 46 48 00 00 00  d9 7a 25 09 01 00 00 00"
	   << "36 00 00 00 04 00 00 00  01 00 4c 03 00 00 00 00"
	   << "00 00 00 00 85 00 00 00  00 00 00 00 00 00 00 00"
	   << "00 00 00 00 01 00 00 00  00 00 00 00 01 00 00 00"
	   << "7b 00 00 00 00 00 00 00";

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
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_TransferSubscriptionsResponse_Encoding_DefaultBinary);

	// decode TransferSubscriptionsResponse
	transferSubscriptionsResponseSPtr = constructSPtr<TransferSubscriptionsResponse>();
	responseHeader->opcUaBinaryDecode(ios);
	transferSubscriptionsResponseSPtr->opcUaBinaryDecode(ios);

	BOOST_REQUIRE(responseHeader->time().dateTime() == ptime);
	BOOST_REQUIRE(responseHeader->requestHandle() == 133);
	BOOST_REQUIRE(responseHeader->serviceResult() == Success);

	BOOST_REQUIRE(transferSubscriptionsResponseSPtr->results()->size() == 1);
	transferSubscriptionsResponseSPtr->results()->get(transferResultSPtr);
	BOOST_REQUIRE(transferResultSPtr->statusCode() == Success);
	BOOST_REQUIRE(transferResultSPtr->availableSequenceNumbers()->size() == 1);
	transferResultSPtr->availableSequenceNumbers()->get(sequenceNumber);
	BOOST_REQUIRE(sequenceNumber == 123);
}

BOOST_AUTO_TEST_SUITE_END()
