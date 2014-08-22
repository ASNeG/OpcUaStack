#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/ServiceSet/ModifyMonitoredItemsRequest.h"
#include "OpcUaStackCore/ServiceSet/ModifyMonitoredItemsResponse.h"
#include "OpcUaStackCore/SecureChannel/MessageHeader.h"
#include "OpcUaStackCore/SecureChannel/SequenceHeader.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(ModifyMonitoredItems_)

BOOST_AUTO_TEST_CASE(ModifyMonitoredItems_Title)
{
	std::cout << "ModifyMonitoredItems_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(ModifyMonitoredItems_Request)
{
	uint32_t pos;
	OpcUaNodeId typeId;
	OpcUaGuid::SPtr opcUaGuidSPtr;
	MessageHeader::SPtr messageHeaderSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
	MonitoredItemModifyRequest::SPtr monitoredItemModifyRequestSPtr;
	MonitoringParameters monitoringParameters;
	OpcUaString::SPtr opcUaStringSPtr;
	ModifyMonitoredItemsRequest::SPtr modifyMonitoredItemsRequestSPtr;
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
	typeId.nodeId(OpcUaId_ModifyMonitoredItemsRequest_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// build ModifyMonitoredItemsRequest
	modifyMonitoredItemsRequestSPtr = ModifyMonitoredItemsRequest::construct();

	// build RequestHeader
	opcUaGuidSPtr = OpcUaGuid::construct();
	*opcUaGuidSPtr = "0D4455B2-8D2F-B74F-864F-0AF5945DD833";
	
	modifyMonitoredItemsRequestSPtr->requestHeader()->sessionAuthenticationToken().namespaceIndex(1);
	modifyMonitoredItemsRequestSPtr->requestHeader()->sessionAuthenticationToken().nodeId(opcUaGuidSPtr);
	modifyMonitoredItemsRequestSPtr->requestHeader()->time(ptime);
	modifyMonitoredItemsRequestSPtr->requestHeader()->requestHandle(0);
	modifyMonitoredItemsRequestSPtr->requestHeader()->returnDisagnostics(0);
	modifyMonitoredItemsRequestSPtr->requestHeader()->timeoutHint(300000);

	// build MonitoringParameters
	OpcUaNodeId parameterTypeId;
	parameterTypeId.namespaceIndex(0);
	parameterTypeId.nodeId(0);

	monitoringParameters.clientHandle((OpcUaUInt32)3);
	monitoringParameters.samplingInterval((OpcUaDouble)-1);
	monitoringParameters.queueSize((OpcUaUInt32)1);
	monitoringParameters.discardOldest(true);

	// build MonitoredItemModifyRequest
	monitoredItemModifyRequestSPtr = MonitoredItemModifyRequest::construct();
	monitoredItemModifyRequestSPtr->monitoredItemId(123);
	monitoredItemModifyRequestSPtr->requestedParameters(monitoringParameters);

	// build ModifyMonitoredItemsRequest
	modifyMonitoredItemsRequestSPtr->subscriptionId(4);
	modifyMonitoredItemsRequestSPtr->timestampsToReturn(TimestampsToReturn_Both);
	modifyMonitoredItemsRequestSPtr->itemsToModify()->set(monitoredItemModifyRequestSPtr);

	// encode 
	modifyMonitoredItemsRequestSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = MessageHeader::construct();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);
	
	std::stringstream ss;
	ss << "4d 53 47 46 6e 00 00 00  d9 7a 25 09 01 00 00 00"
	   << "36 00 00 00 04 00 00 00  01 00 fb 02 04 01 00 0d"
	   << "44 55 b2 8d 2f b7 4f 86  4f 0a f5 94 5d d8 33 00"
	   << "00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 ff"	
	   << "ff ff ff e0 93 04 00 00  00 00 04 00 00 00 02 00"
	   << "00 00 01 00 00 00 7b 00  00 00 03 00 00 00 00 00"
	   << "00 00 00 00 f0 bf 00 00  00 01 00 00 00 01";

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
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_ModifyMonitoredItemsRequest_Encoding_DefaultBinary);

	// decode
	modifyMonitoredItemsRequestSPtr = ModifyMonitoredItemsRequest::construct();
	modifyMonitoredItemsRequestSPtr->opcUaBinaryDecode(ios);
	
	std::string str;
	str = *modifyMonitoredItemsRequestSPtr->requestHeader()->sessionAuthenticationToken().nodeId<OpcUaGuid::SPtr>();
	BOOST_REQUIRE(modifyMonitoredItemsRequestSPtr->requestHeader()->sessionAuthenticationToken().namespaceIndex() == 1);
	BOOST_REQUIRE(str == "0D4455B2-8D2F-B74F-864F-0AF5945DD833");
	BOOST_REQUIRE(modifyMonitoredItemsRequestSPtr->requestHeader()->time().dateTime() == ptime);
	BOOST_REQUIRE(modifyMonitoredItemsRequestSPtr->requestHeader()->requestHandle() == 0);
	BOOST_REQUIRE(modifyMonitoredItemsRequestSPtr->requestHeader()->returnDisagnostics() == 0);
	BOOST_REQUIRE(modifyMonitoredItemsRequestSPtr->requestHeader()->timeoutHint() == 300000);
	BOOST_REQUIRE(modifyMonitoredItemsRequestSPtr->timestampsToReturn() == TimestampsToReturn_Both);
	
	BOOST_REQUIRE(modifyMonitoredItemsRequestSPtr->itemsToModify()->size() == 1);
	modifyMonitoredItemsRequestSPtr->itemsToModify()->get(monitoredItemModifyRequestSPtr);
	BOOST_REQUIRE(monitoredItemModifyRequestSPtr->monitoredItemId() == 123);

	monitoringParameters = monitoredItemModifyRequestSPtr->requestedParameters();
	BOOST_REQUIRE(monitoringParameters.clientHandle() == 3);
	BOOST_REQUIRE(monitoringParameters.samplingInterval() == -1);
	BOOST_REQUIRE(monitoringParameters.queueSize() == 1);
	BOOST_REQUIRE(monitoringParameters.discardOldest() == true);
}


BOOST_AUTO_TEST_CASE(ModifyMonitoredItems_Response)
{
	uint32_t pos;
	OpcUaNodeId typeId;
	OpcUaStatusCode statusCode;
	MessageHeader::SPtr messageHeaderSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
	MonitoredItemModifyResult::SPtr monitoredItemModifyResultSPtr;
	ModifyMonitoredItemsResponse::SPtr modifyMonitoredItemsResponseSPtr;
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
	typeId.nodeId(OpcUaId_ModifyMonitoredItemsResponse_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// build ModifyMonitoredItemsResponse
	modifyMonitoredItemsResponseSPtr = ModifyMonitoredItemsResponse::construct();

	// build ResponseHeader
	statusCode = Success;
	modifyMonitoredItemsResponseSPtr->responseHeader()->time(ptime);
	modifyMonitoredItemsResponseSPtr->responseHeader()->requestHandle(0);
	modifyMonitoredItemsResponseSPtr->responseHeader()->serviceResult(statusCode);
	
	// build MonitoredItemModifyResult
	monitoredItemModifyResultSPtr = MonitoredItemModifyResult::construct();
	monitoredItemModifyResultSPtr->statusCode((OpcUaStatusCode)Success);
	monitoredItemModifyResultSPtr->revisedSamplingInterval(500);
	monitoredItemModifyResultSPtr->revisedQueueSize(1);
	modifyMonitoredItemsResponseSPtr->results()->set(monitoredItemModifyResultSPtr);

	// encode ModifyMonitoredItemsResponse
	modifyMonitoredItemsResponseSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = MessageHeader::construct();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);

	std::stringstream ss;
	ss << "4d 53 47 46 4f 00 00 00  d9 7a 25 09 01 00 00 00"
	   << "36 00 00 00 04 00 00 00  01 00 fe 02 00 00 00 00"
	   << "00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00"
	   << "00 00 00 00 01 00 00 00  00 00 00 00 00 00 00 00"
	   << "00 40 7f 40 01 00 00 00  00 00 00 00 00 00 00";

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
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_ModifyMonitoredItemsResponse_Encoding_DefaultBinary);

	// decode ModifyMonitoredItemsResponse
	modifyMonitoredItemsResponseSPtr = ModifyMonitoredItemsResponse::construct();
	modifyMonitoredItemsResponseSPtr->opcUaBinaryDecode(ios);

	BOOST_REQUIRE(modifyMonitoredItemsResponseSPtr->responseHeader()->time().dateTime() == ptime);
	BOOST_REQUIRE(modifyMonitoredItemsResponseSPtr->responseHeader()->requestHandle() == 0);
	BOOST_REQUIRE(modifyMonitoredItemsResponseSPtr->responseHeader()->serviceResult() == Success);

	BOOST_REQUIRE(modifyMonitoredItemsResponseSPtr->results()->size() == 1);
	modifyMonitoredItemsResponseSPtr->results()->get(monitoredItemModifyResultSPtr);
	BOOST_REQUIRE(monitoredItemModifyResultSPtr->statusCode() == Success);
	BOOST_REQUIRE(monitoredItemModifyResultSPtr->revisedSamplingInterval() == 500);
	BOOST_REQUIRE(monitoredItemModifyResultSPtr->revisedQueueSize() == 1);
}

BOOST_AUTO_TEST_SUITE_END()
