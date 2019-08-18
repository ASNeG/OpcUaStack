#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/ServiceSet/CallRequest.h"
#include "OpcUaStackCore/ServiceSet/CallResponse.h"
#include "OpcUaStackCore/SecureChannel/MessageHeader.h"
#include "OpcUaStackCore/SecureChannel/SequenceHeader.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(Call_)

BOOST_AUTO_TEST_CASE(Call_Title)
{
	std::cout << "Call_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(Call_Request)
{
	uint32_t pos;
	OpcUaNodeId typeId;
	OpcUaNodeId::SPtr objectIdSPtr, methodIdSPtr;
	OpcUaVariant::SPtr variantSPtr;
	OpcUaGuid::SPtr opcUaGuidSPtr;
	MessageHeader::SPtr messageHeaderSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
	CallRequest::SPtr callRequestSPtr;
	CallMethodRequest::SPtr callMethodRequestSPtr;
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
	typeId.nodeId((OpcUaUInt32)OpcUaId_CallRequest_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// build CallRequest
	callRequestSPtr = boost::make_shared<CallRequest>();
	
	// build CallMethodRequest
	variantSPtr = boost::make_shared<OpcUaVariant>();
	variantSPtr->variant((OpcUaUInt32)2);

	objectIdSPtr = boost::make_shared<OpcUaNodeId>();
	objectIdSPtr->namespaceIndex(0);
	objectIdSPtr->nodeId((OpcUaUInt32)2782);

	methodIdSPtr = boost::make_shared<OpcUaNodeId>();
	methodIdSPtr->namespaceIndex(0);
	methodIdSPtr->nodeId((OpcUaUInt32)3875);
	
	callMethodRequestSPtr = boost::make_shared<CallMethodRequest>();
	callMethodRequestSPtr->objectId(objectIdSPtr);
	callMethodRequestSPtr->methodId(methodIdSPtr);
	callMethodRequestSPtr->inputArguments()->set(variantSPtr);
	
	callRequestSPtr->methodsToCall()->set(callMethodRequestSPtr);

	// encode CallRequest
	callRequestSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = boost::make_shared<MessageHeader>();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);

	std::stringstream ss;

	ss << "4d 53 47 46 31 00 00 00  d9 7a 25 09 01 00 00 00"
	   << "36 00 00 00 04 00 00 00  01 00 c8 02 01 00 00 00"
	   << "01 00 de 0a 01 00 23 0f  01 00 00 00 07 02 00 00"
	   << "00";
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
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_CallRequest_Encoding_DefaultBinary);

	// decode CallRequest
	callRequestSPtr = boost::make_shared<CallRequest>();
	callRequestSPtr->opcUaBinaryDecode(ios);
	
	BOOST_REQUIRE(callRequestSPtr->methodsToCall()->size() == 1);
	callMethodRequestSPtr = boost::make_shared<CallMethodRequest>();
	callRequestSPtr->methodsToCall()->get(callMethodRequestSPtr);
	BOOST_REQUIRE(callMethodRequestSPtr->objectId()->nodeId<OpcUaUInt32>() == 2782);
	BOOST_REQUIRE(callMethodRequestSPtr->methodId()->nodeId<OpcUaUInt32>() == 3875);
	
	BOOST_REQUIRE(callMethodRequestSPtr->inputArguments()->size() == 1);
	variantSPtr = boost::make_shared<OpcUaVariant>();
	callMethodRequestSPtr->inputArguments()->get(variantSPtr);
	BOOST_REQUIRE(variantSPtr->variant<OpcUaUInt32>() == 2);
}


BOOST_AUTO_TEST_CASE(Call_Response)
{
	uint32_t pos;
	OpcUaNodeId typeId;
	OpcUaStatusCode statusCode;
	OpcUaVariant::SPtr variantSPtr;
	MessageHeader::SPtr messageHeaderSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
	CallResponse::SPtr callResponseSPtr;
	CallMethodResult::SPtr callMethodResultSPtr;

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
	typeId.nodeId(OpcUaId_CallResponse_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// build CallResponse
	callResponseSPtr = boost::make_shared<CallResponse>();

	// build CallMethodResult
	variantSPtr = boost::make_shared<OpcUaVariant>();
	variantSPtr->variant((OpcUaFloat)321);

	callMethodResultSPtr = boost::make_shared<CallMethodResult>();
	callMethodResultSPtr->statusCode((OpcUaStatusCode) Success);
	callMethodResultSPtr->inputArgumentResults()->set((OpcUaStatusCode) Success);
	callMethodResultSPtr->outputArguments()->set(variantSPtr);

	callResponseSPtr->results()->set(callMethodResultSPtr);

	// encode CallResponse
	callResponseSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = boost::make_shared<MessageHeader>();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);

	std::stringstream ss;
	ss << "4d 53 47 46 3d 00 00 00  d9 7a 25 09 01 00 00 00"
	   << "36 00 00 00 04 00 00 00  01 00 cb 02 01 00 00 00"
	   << "00 00 00 00 01 00 00 00  00 00 00 00 00 00 00 00"
	   << "01 00 00 00 0a 00 80 a0  43 00 00 00 00";
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
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_CallResponse_Encoding_DefaultBinary);

	// decode CallResponse
	callResponseSPtr = boost::make_shared<CallResponse>();
	callResponseSPtr->opcUaBinaryDecode(ios);
	
	BOOST_REQUIRE(callResponseSPtr->results()->size() == 1);
	callMethodResultSPtr = boost::make_shared<CallMethodResult>();
	callResponseSPtr->results()->get(callMethodResultSPtr);

	BOOST_REQUIRE(callMethodResultSPtr->statusCode() ==  Success);
	
	BOOST_REQUIRE(callMethodResultSPtr->inputArgumentResults()->size() == 1);
	callMethodResultSPtr->inputArgumentResults()->get(statusCode);
	BOOST_REQUIRE(statusCode == Success);

	BOOST_REQUIRE(callMethodResultSPtr->outputArguments()->size() == 1);
	variantSPtr = boost::make_shared<OpcUaVariant>();
	callMethodResultSPtr->outputArguments()->get(variantSPtr);
	BOOST_REQUIRE(variantSPtr->variant<OpcUaFloat>() == 321);
}

BOOST_AUTO_TEST_SUITE_END()
