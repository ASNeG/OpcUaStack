#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/ServiceSet/ReadRequest.h"
#include "OpcUaStackCore/SecureChannel/MessageHeader.h"
#include "OpcUaStackCore/SecureChannel/SequenceHeader.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(ReadService_)

BOOST_AUTO_TEST_CASE(ReadService_)
{
	std::cout << "ReadService_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(ReadService_Request)
{
	uint32_t pos;
	OpcUaNodeId typeId;
	OpcUaGuid::SPtr opcUaGuidSPtr;
	ReadRequest::SPtr readRequestSPtr;
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

	secureChannelId = 2967593273;
	secureTokenId = 1;

	OpcUaNumber::opcUaBinaryEncode(ios1, secureChannelId);
	OpcUaNumber::opcUaBinaryEncode(ios1, secureTokenId);

	// encode sequence header
	sequenceHeaderSPtr = SequenceHeader::construct();
	sequenceHeaderSPtr->sequenceNumber(54);
	sequenceHeaderSPtr->requestId(4);
	sequenceHeaderSPtr->opcUaBinaryEncode(ios1);

	// encode TypeId
	typeId.nodeId(OpcUaId_ReadRequest_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// build ReadRequest
	readRequestSPtr = ReadRequest::construct();

	// encode RequestHeader
	opcUaGuidSPtr = OpcUaGuid::construct();
	*opcUaGuidSPtr = "0D4455B2-8D2F-B74F-864F-0AF5945DD833";
	
	readRequestSPtr->requestHeader(RequestHeader::construct());
	readRequestSPtr->requestHeader()->sessionAuthenticationToken().namespaceIndex(1);
	readRequestSPtr->requestHeader()->sessionAuthenticationToken().nodeId(opcUaGuidSPtr);
	readRequestSPtr->requestHeader()->time(ptime);
	readRequestSPtr->requestHeader()->requestHandle(0);
	readRequestSPtr->requestHeader()->returnDisagnostics(0);
	/* readRequestSPtr->requestHeader()->auditEntryId("") is null */
	readRequestSPtr->requestHeader()->timeoutHint(300000);

	// encode maxAge
	readRequestSPtr->maxAge(0);

	// encode timestampeToReturn
	readRequestSPtr->timestampsToReturn(2);

	// encode ReadValueId
	OpcUaReadValueId::SPtr readValueIdSPtr;
	readValueIdSPtr = OpcUaReadValueId::construct();
	readValueIdSPtr->nodeId((OpcUaInt16) 2, (OpcUaInt32) 9);
	readValueIdSPtr->attributeId((OpcUaInt32) 13);
	/* readValueIdSPtr->indexRange("") is null */
	readValueIdSPtr->dataEncoding().namespaceIndex((OpcUaInt16) 0);
	/* readValueIdSPtr->dataEncoding().name("") is null */

	readRequestSPtr->readValueIdArray(OpcUaReadValueIdArray::construct());
	readRequestSPtr->readValueIdArray()->set(readValueIdSPtr);

	// encode ReadRequest
	readRequestSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = MessageHeader::construct();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);
	
	std::stringstream ss;
	ss << "4d 53 47 46 6c 00 00 00  39 e1 e1 b0 01 00 00 00"
	   << "36 00 00 00 04 00 00 00  01 00 77 02 04 01 00 0d"
	   << "44 55 b2 8d 2f b7 4f 86  4f 0a f5 94 5d d8 33 00"
	   << "00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 ff"
       << "ff ff ff e0 93 04 00 00  00 00 00 00 00 00 00 00"
       << "00 00 02 00 00 00 01 00  00 00 01 02 09 00 0d 00"
       << "00 00 ff ff ff ff 00 00  ff ff ff ff";

	BOOST_REQUIRE(OpcUaStackCore::compare(ios, ss.str(), pos) == true);

	// decode MessageHeader
	messageHeaderSPtr = MessageHeader::construct();
	messageHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(messageHeaderSPtr->messageType() == MessageType_Message);

	// decode security header
	OpcUaNumber::opcUaBinaryDecode(ios, secureChannelId);
	BOOST_REQUIRE(secureChannelId == 2967593273);
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
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_ReadRequest_Encoding_DefaultBinary);

	// decode ReadRequest
	readRequestSPtr = ReadRequest::construct();
	readRequestSPtr->requestHeader(RequestHeader::construct());
	readRequestSPtr->readValueIdArray(OpcUaReadValueIdArray::construct());
	readRequestSPtr->opcUaBinaryDecode(ios);

	std::string str;
	str = *readRequestSPtr->requestHeader()->sessionAuthenticationToken().nodeId<OpcUaGuid::SPtr>();
	BOOST_REQUIRE(readRequestSPtr->requestHeader()->sessionAuthenticationToken().namespaceIndex() == 1);
	BOOST_REQUIRE(str == "0D4455B2-8D2F-B74F-864F-0AF5945DD833");
	BOOST_REQUIRE(readRequestSPtr->requestHeader()->time().dateTime() == ptime);
	BOOST_REQUIRE(readRequestSPtr->requestHeader()->requestHandle() == 0);
	BOOST_REQUIRE(readRequestSPtr->requestHeader()->returnDisagnostics() == 0);
	BOOST_REQUIRE(readRequestSPtr->requestHeader()->timeoutHint() == 300000);
	BOOST_REQUIRE(readRequestSPtr->maxAge() == 0);
	BOOST_REQUIRE(readRequestSPtr->timestampsToReturn() == 2);

	BOOST_REQUIRE(readRequestSPtr->readValueIdArray()->size() == 1);

	OpcUaReadValueId::SPtr readValueIdSPtr2;
	readRequestSPtr->readValueIdArray()->get(readValueIdSPtr2);
	BOOST_REQUIRE(readValueIdSPtr2->nodeId().namespaceIndex() == 2);
	BOOST_REQUIRE(readValueIdSPtr2->nodeId().nodeId<OpcUaUInt32>() == 9);
	BOOST_REQUIRE(readValueIdSPtr2->dataEncoding().namespaceIndex() == 0);
}


BOOST_AUTO_TEST_CASE(ReadService_Response)
{

}

BOOST_AUTO_TEST_SUITE_END()
