#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/ServiceSet/CreateMonitoredItemsRequest.h"
#include "OpcUaStackCore/ServiceSet/CreateMonitoredItemsResponse.h"
#include "OpcUaStackCore/SecureChannel/MessageHeader.h"
#include "OpcUaStackCore/SecureChannel/SequenceHeader.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(CreateMonitoredItems_)

BOOST_AUTO_TEST_CASE(CreateMonitoredItems_Title)
{
	std::cout << "CreateMonitoredItems_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(CreateMonitoredItems_Request)
{
	RequestHeader::SPtr requestHeader = boost::make_shared<RequestHeader>();
	uint32_t pos;
	OpcUaNodeId typeId;
	OpcUaGuid::SPtr opcUaGuidSPtr;
	MessageHeader::SPtr messageHeaderSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
	MonitoredItemCreateRequest::SPtr monitoredItemCreateRequestSPtr;
	MonitoringParameters monitoringParameters;
	OpcUaString::SPtr opcUaStringSPtr;
	CreateMonitoredItemsRequest::SPtr createMonitoredItemsRequestSPtr;
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
	typeId.nodeId(OpcUaId_CreateMonitoredItemsRequest_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// build CreateMonitoredItemsRequest
	createMonitoredItemsRequestSPtr = boost::make_shared<CreateMonitoredItemsRequest>();

	// build RequestHeader
	opcUaGuidSPtr = boost::make_shared<OpcUaGuid>();
	*opcUaGuidSPtr = "0D4455B2-8D2F-B74F-864F-0AF5945DD833";
	
	requestHeader->sessionAuthenticationToken().namespaceIndex(1);
	requestHeader->sessionAuthenticationToken().nodeId(opcUaGuidSPtr);
	requestHeader->time(ptime);
	requestHeader->requestHandle(0);
	requestHeader->returnDisagnostics(0);
	requestHeader->timeoutHint(300000);

	// build MonitoringParameters
	OpcUaNodeId parameterTypeId;
	parameterTypeId.namespaceIndex(0);
	parameterTypeId.nodeId(0);

	monitoringParameters.clientHandle((OpcUaUInt32)3);
	monitoringParameters.samplingInterval((OpcUaDouble)-1);
	monitoringParameters.queueSize((OpcUaUInt32)1);
	monitoringParameters.discardOldest(true);

	// build MonitoredItemCreateRequest
	opcUaStringSPtr = boost::make_shared<OpcUaString>();
	opcUaStringSPtr->value("AllDataTypesStatic/StaticInt32");

	monitoredItemCreateRequestSPtr = boost::make_shared<MonitoredItemCreateRequest>();
	monitoredItemCreateRequestSPtr->monitoringMode(MonitoringMode_Reporting);
	monitoredItemCreateRequestSPtr->itemToMonitor().nodeId()->namespaceIndex(4);
	monitoredItemCreateRequestSPtr->itemToMonitor().nodeId()->nodeId(opcUaStringSPtr);
	monitoredItemCreateRequestSPtr->itemToMonitor().attributeId((OpcUaInt32) 13);
	monitoredItemCreateRequestSPtr->itemToMonitor().dataEncoding().namespaceIndex(0);
	monitoredItemCreateRequestSPtr->requestedParameters(monitoringParameters);

	// build CreateMonitoredItemsRequest
	createMonitoredItemsRequestSPtr->subscriptionId(4);
	createMonitoredItemsRequestSPtr->timestampsToReturn(TimestampsToReturn_Both);
	createMonitoredItemsRequestSPtr->itemsToCreate()->set(monitoredItemCreateRequestSPtr);

	// encode 
	requestHeader->opcUaBinaryEncode(ios1);
	createMonitoredItemsRequestSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = boost::make_shared<MessageHeader>();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);
	
	std::stringstream ss;
	ss << "4d 53 47 46 a1 00 00 00  d9 7a 25 09 01 00 00 00"
	   << "36 00 00 00 04 00 00 00  01 00 ef 02 04 01 00 0d"
	   << "44 55 b2 8d 2f b7 4f 86  4f 0a f5 94 5d d8 33 00"
	   << "00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 ff"	
	   << "ff ff ff e0 93 04 00 00  00 00 04 00 00 00 02 00"
	   << "00 00 01 00 00 00 03 04  00 1e 00 00 00 41 6c 6c"
	   << "44 61 74 61 54 79 70 65  73 53 74 61 74 69 63 2f"
	   << "53 74 61 74 69 63 49 6e  74 33 32 0d 00 00 00 ff"
	   << "ff ff ff 00 00 ff ff ff  ff 02 00 00 00 03 00 00"
	   << "00 00 00 00 00 00 00 f0  bf 00 00 00 01 00 00 00"
	   << "01";

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
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_CreateMonitoredItemsRequest_Encoding_DefaultBinary);

	// decode
	requestHeader->opcUaBinaryDecode(ios);
	createMonitoredItemsRequestSPtr->opcUaBinaryDecode(ios);
	
	std::string str;
	str = *requestHeader->sessionAuthenticationToken().nodeId<OpcUaGuid::SPtr>();
	BOOST_REQUIRE(requestHeader->sessionAuthenticationToken().namespaceIndex() == 1);
	BOOST_REQUIRE(str == "0D4455B2-8D2F-B74F-864F-0AF5945DD833");
	BOOST_REQUIRE(requestHeader->time().dateTime() == ptime);
	BOOST_REQUIRE(requestHeader->requestHandle() == 0);
	BOOST_REQUIRE(requestHeader->returnDisagnostics() == 0);
	BOOST_REQUIRE(requestHeader->timeoutHint() == 300000);
	BOOST_REQUIRE(createMonitoredItemsRequestSPtr->timestampsToReturn() == TimestampsToReturn_Both);
	
	BOOST_REQUIRE(createMonitoredItemsRequestSPtr->itemsToCreate()->size() == 1);
	createMonitoredItemsRequestSPtr->itemsToCreate()->get(monitoredItemCreateRequestSPtr);
	BOOST_REQUIRE(monitoredItemCreateRequestSPtr->monitoringMode() == MonitoringMode_Reporting);
	BOOST_REQUIRE(monitoredItemCreateRequestSPtr->itemToMonitor().nodeId()->namespaceIndex() == 4);
	BOOST_REQUIRE(monitoredItemCreateRequestSPtr->itemToMonitor().attributeId() == 13);
	BOOST_REQUIRE(monitoredItemCreateRequestSPtr->itemToMonitor().dataEncoding().namespaceIndex() == 0);

	monitoringParameters = monitoredItemCreateRequestSPtr->requestedParameters();
	BOOST_REQUIRE(monitoringParameters.clientHandle() == 3);
	BOOST_REQUIRE(monitoringParameters.samplingInterval() == -1);
	BOOST_REQUIRE(monitoringParameters.queueSize() == 1);
	BOOST_REQUIRE(monitoringParameters.discardOldest() == true);
}


BOOST_AUTO_TEST_CASE(CreateMonitoredItems_Response)
{
	ResponseHeader::SPtr responseHeader = boost::make_shared<ResponseHeader>();
	uint32_t pos;
	OpcUaNodeId typeId;
	OpcUaStatusCode statusCode;
	MessageHeader::SPtr messageHeaderSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
	MonitoredItemCreateResult::SPtr monitoredItemCreateResultSPtr;
	CreateMonitoredItemsResponse::SPtr createMonitoredItemsResponseSPtr;
	OpcUaDateTime sourceTimestamp, serverTimestamp;
	OpcUaDataValue::SPtr dataValueSPtr;
	OpcUaVariant::SPtr variantSPtr;
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
	typeId.nodeId(OpcUaId_CreateMonitoredItemsResponse_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// build CreateMonitoredItemsResponse
	createMonitoredItemsResponseSPtr = boost::make_shared<CreateMonitoredItemsResponse>();

	// build ResponseHeader
	statusCode = Success;
	responseHeader->time(ptime);
	responseHeader->requestHandle(0);
	responseHeader->serviceResult(statusCode);
	
	// build MonitoredItemCreateResult
	monitoredItemCreateResultSPtr = boost::make_shared<MonitoredItemCreateResult>();
	monitoredItemCreateResultSPtr->statusCode().enumeration(Success);
	monitoredItemCreateResultSPtr->monitoredItemId() = 1;
	monitoredItemCreateResultSPtr->revisedSamplingInterval() = 500;
	monitoredItemCreateResultSPtr->revisedQueueSize() = 1;
	createMonitoredItemsResponseSPtr->results()->set(monitoredItemCreateResultSPtr);

	// encode CreateMonitoredItemsResponse
	responseHeader->opcUaBinaryEncode(ios1);
	createMonitoredItemsResponseSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = boost::make_shared<MessageHeader>();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);

	std::stringstream ss;
	ss << "4d 53 47 46 53 00 00 00  d9 7a 25 09 01 00 00 00"
	   << "36 00 00 00 04 00 00 00  01 00 f2 02 00 00 00 00"
	   << "00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00"
	   << "00 00 00 00 01 00 00 00  00 00 00 00 01 00 00 00"
	   << "00 00 00 00 00 40 7f 40  01 00 00 00 00 00 00 00"
	   << "00 00 00";

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
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_CreateMonitoredItemsResponse_Encoding_DefaultBinary);

	// decode ReadResponse
	createMonitoredItemsResponseSPtr = boost::make_shared<CreateMonitoredItemsResponse>();
	responseHeader->opcUaBinaryDecode(ios);
	createMonitoredItemsResponseSPtr->opcUaBinaryDecode(ios);

	BOOST_REQUIRE(responseHeader->time().dateTime() == ptime);
	BOOST_REQUIRE(responseHeader->requestHandle() == 0);
	BOOST_REQUIRE(responseHeader->serviceResult() == Success);

	BOOST_REQUIRE(createMonitoredItemsResponseSPtr->results()->size() == 1);
	createMonitoredItemsResponseSPtr->results()->get(monitoredItemCreateResultSPtr);
	BOOST_REQUIRE(monitoredItemCreateResultSPtr->monitoredItemId() == 1);
	BOOST_REQUIRE(monitoredItemCreateResultSPtr->revisedSamplingInterval() == 500);
	BOOST_REQUIRE(monitoredItemCreateResultSPtr->revisedQueueSize() == 1);
}

BOOST_AUTO_TEST_SUITE_END()
