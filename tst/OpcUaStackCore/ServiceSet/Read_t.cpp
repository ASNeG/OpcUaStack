#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/ServiceSet/ReadRequest.h"
#include "OpcUaStackCore/ServiceSet/ReadResponse.h"
#include "OpcUaStackCore/SecureChannel/MessageHeader.h"
#include "OpcUaStackCore/SecureChannel/SequenceHeader.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(Read_)

BOOST_AUTO_TEST_CASE(Read_Title)
{
	std::cout << "Read_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(Read_Request)
{
	RequestHeader::SPtr requestHeader(boost::make_shared<RequestHeader>());
	uint32_t pos;
	OpcUaNodeId typeId;
	OpcUaGuid::SPtr opcUaGuidSPtr;
	ReadValueId::SPtr readValueIdSPtr;
	ReadRequest::SPtr readRequestSPtr;
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
	typeId.nodeId(OpcUaId_ReadRequest_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// build ReadRequest
	readRequestSPtr = boost::make_shared<ReadRequest>();

	// encode RequestHeader
	opcUaGuidSPtr = boost::make_shared<OpcUaGuid>();
	*opcUaGuidSPtr = "0D4455B2-8D2F-B74F-864F-0AF5945DD833";
	
	requestHeader->sessionAuthenticationToken().namespaceIndex(1);
	requestHeader->sessionAuthenticationToken().nodeId(opcUaGuidSPtr);
	requestHeader->time(ptime);
	requestHeader->requestHandle(0);
	requestHeader->returnDisagnostics(0);
	requestHeader->timeoutHint(300000);

	// encode maxAge
	readRequestSPtr->maxAge(0);

	// encode timestampeToReturn
	readRequestSPtr->timestampsToReturn(2);

	// encode ReadValueId
	readValueIdSPtr = boost::make_shared<ReadValueId>();
	readValueIdSPtr->nodeId((OpcUaInt16) 2, (OpcUaInt32) 9);
	readValueIdSPtr->attributeId((OpcUaInt32) 13);
	readValueIdSPtr->dataEncoding().namespaceIndex((OpcUaInt16) 0);

	readRequestSPtr->readValueIdArray()->set(readValueIdSPtr);

	// encode ReadRequest
	requestHeader->opcUaBinaryEncode(ios1);
	readRequestSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = boost::make_shared<MessageHeader>();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);
	
	std::stringstream ss;
	ss << "4d 53 47 46 6c 00 00 00  d9 7a 25 09 01 00 00 00" 
	   << "36 00 00 00 04 00 00 00  01 00 77 02 04 01 00 0d"
	   << "44 55 b2 8d 2f b7 4f 86  4f 0a f5 94 5d d8 33 00"
	   << "00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 ff"
       << "ff ff ff e0 93 04 00 00  00 00 00 00 00 00 00 00"
       << "00 00 02 00 00 00 01 00  00 00 01 02 09 00 0d 00"
       << "00 00 ff ff ff ff 00 00  ff ff ff ff";

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
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_ReadRequest_Encoding_DefaultBinary);

	// decode ReadRequest
	readRequestSPtr = boost::make_shared<ReadRequest>();
	requestHeader->opcUaBinaryDecode(ios);
	readRequestSPtr->opcUaBinaryDecode(ios);

	std::string str;
	str = *requestHeader->sessionAuthenticationToken().nodeId<OpcUaGuid::SPtr>();
	BOOST_REQUIRE(requestHeader->sessionAuthenticationToken().namespaceIndex() == 1);
	BOOST_REQUIRE(str == "0D4455B2-8D2F-B74F-864F-0AF5945DD833");
	BOOST_REQUIRE(requestHeader->time().dateTime() == ptime);
	BOOST_REQUIRE(requestHeader->requestHandle() == 0);
	BOOST_REQUIRE(requestHeader->returnDisagnostics() == 0);
	BOOST_REQUIRE(requestHeader->timeoutHint() == 300000);
	BOOST_REQUIRE(readRequestSPtr->maxAge() == 0);
	BOOST_REQUIRE(readRequestSPtr->timestampsToReturn() == 2);

	BOOST_REQUIRE(readRequestSPtr->readValueIdArray()->size() == 1);

	readValueIdSPtr = boost::make_shared<ReadValueId>();
	readRequestSPtr->readValueIdArray()->get(readValueIdSPtr);
	BOOST_REQUIRE(readValueIdSPtr->nodeId()->namespaceIndex() == 2);
	BOOST_REQUIRE(readValueIdSPtr->nodeId()->nodeId<OpcUaUInt32>() == 9);
	BOOST_REQUIRE(readValueIdSPtr->dataEncoding().namespaceIndex() == 0);
}


BOOST_AUTO_TEST_CASE(Read_Response)
{
	ResponseHeader::SPtr responseHeader(boost::make_shared<ResponseHeader>());
	uint32_t pos;
	OpcUaNodeId typeId;
	OpcUaStatusCode statusCode;
	ReadResponse::SPtr readResponseSPtr;
	MessageHeader::SPtr messageHeaderSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
	OpcUaDateTime sourceTimestamp, serverTimestamp;
	OpcUaDataValue::SPtr dataValueSPtr;
	OpcUaVariant::SPtr variantSPtr;
	boost::posix_time::ptime ptime, ptime1, ptime2;
	
	// test-time
	ptime = boost::posix_time::from_iso_string("16010101T000000.000000000");
	ptime1 = boost::posix_time::from_iso_string("20020131T100001,123456789");
	ptime2 = boost::posix_time::from_iso_string("20020131T100001,123456789");

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
	typeId.nodeId(OpcUaId_ReadResponse_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// build ReadResponse
	readResponseSPtr = boost::make_shared<ReadResponse>();

	// encode ResponseHeader
	statusCode = Success;
	responseHeader->time(ptime);
	responseHeader->requestHandle(0);
	responseHeader->serviceResult(statusCode);
	
	// encode DataValue
	sourceTimestamp.dateTime(ptime1);
	serverTimestamp.dateTime(ptime2);

	dataValueSPtr = boost::make_shared<OpcUaDataValue>();
	dataValueSPtr->variant()->variant((OpcUaFloat)321);
	dataValueSPtr->sourceTimestamp(sourceTimestamp);
	dataValueSPtr->serverTimestamp(serverTimestamp);

	readResponseSPtr->dataValueArray()->set(dataValueSPtr);

	// encode ReadRequest
	responseHeader->opcUaBinaryEncode(ios1);
	readResponseSPtr->opcUaBinaryEncode(ios1);

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
	   << "36 00 00 00 04 00 00 00  01 00 7a 02 00 00 00 00"
	   << "00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00"
	   << "00 00 00 00 01 00 00 00  0d 0a 00 80 a0 43 00 7d"
	   << "20 0c 3e aa c1 01 00 7d  20 0c 3e aa c1 01 00 00"
	   << "00 00";

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
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_ReadResponse_Encoding_DefaultBinary);

	// decode ReadResponse
	readResponseSPtr = boost::make_shared<ReadResponse>();
	responseHeader->opcUaBinaryDecode(ios);
	readResponseSPtr->opcUaBinaryDecode(ios);

	BOOST_REQUIRE(responseHeader->time().dateTime() == ptime);
	BOOST_REQUIRE(responseHeader->requestHandle() == 0);
	BOOST_REQUIRE(responseHeader->serviceResult() == Success);

	BOOST_REQUIRE(readResponseSPtr->dataValueArray()->size() == 1);

	dataValueSPtr = boost::make_shared<OpcUaDataValue>();
	readResponseSPtr->dataValueArray()->get(dataValueSPtr);
	BOOST_REQUIRE(dataValueSPtr->variant()->variantType() == OpcUaBuildInType_OpcUaFloat);
	BOOST_REQUIRE(dataValueSPtr->variant()->variant<OpcUaFloat>() == 321);
	BOOST_REQUIRE(dataValueSPtr->sourceTimestamp().dateTime() == ptime1);
	BOOST_REQUIRE(dataValueSPtr->serverTimestamp().dateTime() == ptime2);
}

BOOST_AUTO_TEST_SUITE_END()
